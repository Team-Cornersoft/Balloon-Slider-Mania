#include <PR/ultratypes.h>

#include "config.h"
#include "area.h"
#include "bsm_level_select_menu.h"
#include "emutest.h"
#include "lib/libpl/libpl-emu.h"
#include "sm64.h"
#include "gfx_dimensions.h"
#include "behavior_data.h"
#include "debug.h"
#include "game_init.h"
#include "object_list_processor.h"
#include "engine/surface_load.h"
#include "ingame_menu.h"
#include "screen_transition.h"
#include "mario.h"
#include "mario_actions_cutscene.h"
#include "print.h"
#include "hud.h"
#include "audio/external.h"
#include "area.h"
#include "rendering_graph_node.h"
#include "level_update.h"
#include "engine/geo_layout.h"
#include "save_file.h"
#include "level_table.h"
#include "dialog_ids.h"
#include "puppyprint.h"
#include "debug_box.h"
#include "engine/colors.h"
#include "profiling.h"
#ifdef S2DEX_TEXT_ENGINE
#include "s2d_engine/init.h"
#endif
#include "actors/custom_menu_rank/geo_header.h"

struct SpawnInfo gPlayerSpawnInfos[1];
struct GraphNode *gGraphNodePointers[MODEL_ID_COUNT];
struct Area gAreaData[AREA_COUNT];

struct WarpTransition gWarpTransition;

s16 gCurrCourseNum;
s16 gCurrActNum = 1;
s16 gCurrAreaIndex;
s16 gSavedCourseNum;
s16 gMenuOptSelectIndex;
s16 gSaveOptSelectIndex;

struct SpawnInfo *gMarioSpawnInfo = &gPlayerSpawnInfos[0];
struct GraphNode **gLoadedGraphNodes = gGraphNodePointers;
struct Area *gAreas = gAreaData;
struct Area *gCurrentArea = NULL;
struct CreditsEntry *gCurrCreditsEntry = NULL;

Vp *gViewportOverride = NULL;
Vp *gViewportClip = NULL;
s16 gWarpTransDelay = 0;
RGBA16FILL gFBSetColor = 0;
RGBA16FILL gWarpTransFBSetColor = 0;
Color gWarpTransRed= 0;
Color gWarpTransGreen = 0;
Color gWarpTransBlue = 0;
s16 gCurrSaveFileNum = 1;
s16 gCurrLevelNum = LEVEL_MIN;

u8 gRenderBSMSuccessMenu = FALSE;
static char strBuf[128];

// NOTE: Puppyprint only supports 12 lines total (I think), with deferred prints only supporting under 254 characters (excluding newline)
static char creditsStr[] = {
"\
<COL_5FFF5FFF> Mel<COL_--------> \n\
Courses, Models & Artwork,\n\
Original Soundtrack\n\
\n\
<COL_FF5F5FFF> ArcticJaguar725<COL_--------> \n\
Programming, Sound Design,\n\
Original Soundtrack\n\
\n\
<COL_5F5FFFFF> Tools Used<COL_--------> \n\
HackerSM64, fast64\
"
};

/*
 * The following two tables are used in get_mario_spawn_type() to determine spawn type
 * from warp behavior.
 * When looping through sWarpBhvSpawnTable, if the behavior function in the table matches
 * the spawn behavior executed, the index of that behavior is used with sSpawnTypeFromWarpBhv
*/

const BehaviorScript *sWarpBhvSpawnTable[] = {
    bhvDoorWarp,                bhvStar,                   bhvExitPodiumWarp,          bhvWarp,
    bhvWarpPipe,                bhvFadingWarp,             bhvInstantActiveWarp,       bhvAirborneWarp,
    bhvHardAirKnockBackWarp,    bhvSpinAirborneCircleWarp, bhvDeathWarp,               bhvSpinAirborneWarp,
    bhvFlyingWarp,              bhvSwimmingWarp,           bhvPaintingStarCollectWarp, bhvPaintingDeathWarp,
    bhvAirborneStarCollectWarp, bhvAirborneDeathWarp,      bhvLaunchStarCollectWarp,   bhvLaunchDeathWarp,
    bhvBSMCelebrationWarp,
};

u8 sSpawnTypeFromWarpBhv[] = {
    MARIO_SPAWN_DOOR_WARP,             MARIO_SPAWN_IDLE,                 MARIO_SPAWN_PIPE,                  MARIO_SPAWN_PIPE,
    MARIO_SPAWN_PIPE,                  MARIO_SPAWN_TELEPORT,             MARIO_SPAWN_INSTANT_ACTIVE,        MARIO_SPAWN_AIRBORNE,
    MARIO_SPAWN_HARD_AIR_KNOCKBACK,    MARIO_SPAWN_SPIN_AIRBORNE_CIRCLE, MARIO_SPAWN_DEATH,                 MARIO_SPAWN_SPIN_AIRBORNE,
    MARIO_SPAWN_FLYING,                MARIO_SPAWN_SWIMMING,             MARIO_SPAWN_PAINTING_STAR_COLLECT, MARIO_SPAWN_PAINTING_DEATH,
    MARIO_SPAWN_AIRBORNE_STAR_COLLECT, MARIO_SPAWN_AIRBORNE_DEATH,       MARIO_SPAWN_LAUNCH_STAR_COLLECT,   MARIO_SPAWN_LAUNCH_DEATH,
    MARIO_SPAWN_BSM_CELEBRATION,
};

Vp gViewport = { {
    { 640, 480, 511, 0 },
    { 640, 480, 511, 0 },
} };

#if MULTILANG
const char *gNoControllerMsg[] = {
    "NO CONTROLLER",
    "MANETTE DEBRANCHEE",
    "CONTROLLER FEHLT",
};
#endif

void override_viewport_and_clip(Vp *vpOverride, Vp *vpClip, Color red, Color green, Color blue) {
    RGBA16 color = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gFBSetColor = (color << 16) | color;
    gViewportOverride = vpOverride;
    gViewportClip = vpClip;
}

void set_warp_transition_rgb(Color red, Color green, Color blue) {
    RGBA16 warpTransitionRGBA16 = ((red >> 3) << IDX_RGBA16_R) | ((green >> 3) << IDX_RGBA16_G) | ((blue >> 3) << IDX_RGBA16_B) | MSK_RGBA16_A;

    gWarpTransFBSetColor = (warpTransitionRGBA16 << 16) | warpTransitionRGBA16;
    gWarpTransRed = red;
    gWarpTransGreen = green;
    gWarpTransBlue = blue;
}

void print_intro_text(void) {
#if MULTILANG
    s32 language = eu_get_language();
#endif
    if ((gGlobalTimer & 31) < 20) {
        if (gControllerBits == 0) {
#if MULTILANG
            print_text_centered(SCREEN_CENTER_X, 20, gNoControllerMsg[language]);
#else
            print_text_centered(SCREEN_CENTER_X, 20, "NO CONTROLLER");
#endif
        } else {
#ifdef VERSION_EU
            print_text(20, 20, "START");
#else
            print_text_centered(60, 38, "PRESS");
            print_text_centered(60, 20, "START");
#endif
        }
    }
}

u32 get_mario_spawn_type(struct Object *obj) {
    s32 i;
    const BehaviorScript *behavior = virtual_to_segmented(SEGMENT_BEHAVIOR_DATA, obj->behavior);

    for (i = 0; i < ARRAY_COUNT(sSpawnTypeFromWarpBhv); i++) {
        if (sWarpBhvSpawnTable[i] == behavior) {
            return sSpawnTypeFromWarpBhv[i];
        }
    }
    return MARIO_SPAWN_NONE;
}

struct ObjectWarpNode *area_get_warp_node(u8 id) {
    struct ObjectWarpNode *node = NULL;

    for (node = gCurrentArea->warpNodes; node != NULL; node = node->next) {
        if (node->node.id == id) {
            break;
        }
    }
    return node;
}

struct ObjectWarpNode *area_get_warp_node_from_params(struct Object *obj) {
    return area_get_warp_node(GET_BPARAM2(obj->oBehParams));
}

void load_obj_warp_nodes(void) {
    struct ObjectWarpNode *warpNode;
    struct Object *children = (struct Object *) gObjParentGraphNode.children;

    do {
        struct Object *obj = children;

        if (obj->activeFlags != ACTIVE_FLAG_DEACTIVATED && get_mario_spawn_type(obj) != 0) {
            warpNode = area_get_warp_node_from_params(obj);
            if (warpNode != NULL) {
                warpNode->object = obj;
            }
        }
    } while ((children = (struct Object *) children->header.gfx.node.next)
             != (struct Object *) gObjParentGraphNode.children);
}

void clear_areas(void) {
    s32 i, j;

    gCurrentArea = NULL;
    gWarpTransition.isActive = FALSE;
    gWarpTransition.pauseRendering = FALSE;
    gMarioSpawnInfo->areaIndex = -1;

    for (i = 0; i < AREA_COUNT; i++) {
        gAreaData[i].index = i;
        gAreaData[i].flags = AREA_FLAG_UNLOAD;
        gAreaData[i].terrainType = TERRAIN_GRASS;
        gAreaData[i].graphNode = NULL;
        gAreaData[i].terrainData = NULL;
        gAreaData[i].surfaceRooms = NULL;
        gAreaData[i].macroObjects = NULL;
        gAreaData[i].warpNodes = NULL;
        gAreaData[i].paintingWarpNodes = NULL;
        gAreaData[i].instantWarps = NULL;
        gAreaData[i].objectSpawnInfos = NULL;
        gAreaData[i].camera = NULL;
        gAreaData[i].unused = NULL;
        for (j = 0; j < ARRAY_COUNT(gAreaData[i].whirlpools); j++) {
            gAreaData[i].whirlpools[j] = NULL;
        }
        gAreaData[i].dialog[0] = DIALOG_NONE;
        gAreaData[i].dialog[1] = DIALOG_NONE;
        gAreaData[i].musicParam = 0;
        gAreaData[i].musicParam2 = 0;
        gAreaData[i].useEchoOverride = FALSE;
        gAreaData[i].echoOverride = 0;
#ifdef BETTER_REVERB
        gAreaData[i].betterReverbPreset = 0;
#endif
    }
}

void clear_area_graph_nodes(void) {
    s32 i;

    if (gCurrentArea != NULL) {
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }

    for (i = 0; i < AREA_COUNT; i++) {
        if (gAreaData[i].graphNode != NULL) {
            geo_call_global_function_nodes(&gAreaData[i].graphNode->node, GEO_CONTEXT_AREA_INIT);
            gAreaData[i].graphNode = NULL;
        }
    }
}

void load_area(s32 index) {
    if (gCurrentArea == NULL && gAreaData[index].graphNode != NULL) {
        gCurrentArea = &gAreaData[index];
        gMarioState->area = gCurrentArea;
        gCurrAreaIndex = gCurrentArea->index;
        main_pool_pop_state();
        main_pool_push_state();

        gMarioCurrentRoom = 0;

        if (gCurrentArea->terrainData != NULL) {
            load_area_terrain(index, gCurrentArea->terrainData, gCurrentArea->surfaceRooms,
                              gCurrentArea->macroObjects);
        }

        if (gCurrentArea->objectSpawnInfos != NULL) {
            spawn_objects_from_info(0, gCurrentArea->objectSpawnInfos);
        }

        load_obj_warp_nodes();
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_LOAD);
    }
}

void unload_area(void) {
    if (gCurrentArea != NULL) {
        unload_objects_from_area(0, gCurrentArea->index);
        geo_call_global_function_nodes(&gCurrentArea->graphNode->node, GEO_CONTEXT_AREA_UNLOAD);

        gCurrentArea->flags = AREA_FLAG_UNLOAD;
        gCurrentArea = NULL;
        gWarpTransition.isActive = FALSE;
    }
}

void load_mario_area(void) {
    stop_sounds_in_continuous_banks();
    load_area(gMarioSpawnInfo->areaIndex);

    if (gCurrentArea->index == gMarioSpawnInfo->areaIndex) {
        gCurrentArea->flags |= AREA_FLAG_LOAD;
        spawn_objects_from_info(0, gMarioSpawnInfo);
    }

    if (gAreaSkyboxStart[gCurrAreaIndex - 1]) {
        load_segment_decompress(SEGMENT_SKYBOX, gAreaSkyboxStart[gCurrAreaIndex - 1], gAreaSkyboxEnd[gCurrAreaIndex - 1]);
    }
}

void unload_mario_area(void) {
    if ((gCurrentArea != NULL) && (gCurrentArea->flags & AREA_FLAG_LOAD)) {
        unload_objects_from_area(0, gMarioSpawnInfo->activeAreaIndex);

        gCurrentArea->flags &= ~AREA_FLAG_LOAD;
        if (gCurrentArea->flags == AREA_FLAG_UNLOAD) {
            unload_area();
        }
    }
}

void change_area(s32 index) {
    s32 areaFlags = gCurrentArea->flags;

    if (gCurrAreaIndex != index) {
        unload_area();
        load_area(index);

        gCurrentArea->flags = areaFlags;
        gMarioObject->oActiveParticleFlags = ACTIVE_PARTICLE_NONE;
    }

    if (areaFlags & AREA_FLAG_LOAD) {
        gMarioObject->header.gfx.areaIndex = index, gMarioSpawnInfo->areaIndex = index;
    }
}

void area_update_objects(void) {
    gAreaUpdateCounter++;
    update_objects(0);
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 */
void play_transition(s16 transType, s16 time, Color red, Color green, Color blue) {
#ifndef L3DEX2_ALONE
    gWarpTransition.isActive = TRUE;
    gWarpTransition.type = transType;
    gWarpTransition.time = time;
    gWarpTransition.pauseRendering = FALSE;

    // The lowest bit of transType determines if the transition is fading in or out.
    if (transType & WARP_TRANSITION_FADE_INTO) {
        set_warp_transition_rgb(red, green, blue);
    } else {
        red = gWarpTransRed, green = gWarpTransGreen, blue = gWarpTransBlue;
    }

    if (transType & WARP_TRANSITION_TYPE_COLOR) {
        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;
    } else { // if transition is textured
        set_and_reset_transition_fade_timer(0); // Reset transition timers by passing in 0 for time

        gWarpTransition.data.red = red;
        gWarpTransition.data.green = green;
        gWarpTransition.data.blue = blue;

        // Both the start and end textured transition are always located in the middle of the screen.
        // If you really wanted to, you could place the start at one corner and the end at
        // the opposite corner. This will make the transition image look like it is moving
        // across the screen.
        gWarpTransition.data.startTexX = SCREEN_CENTER_X;
        gWarpTransition.data.startTexY = SCREEN_CENTER_Y;
        gWarpTransition.data.endTexX = SCREEN_CENTER_X;
        gWarpTransition.data.endTexY = SCREEN_CENTER_Y;

        gWarpTransition.data.angleSpeed = DEGREES(0);

        s16 fullRadius = GFX_DIMENSIONS_FULL_RADIUS;

#ifdef POLISHED_TRANSITIONS
        switch (transType){
            case WARP_TRANSITION_TYPE_BOWSER:
            case WARP_TRANSITION_FADE_INTO_BOWSER:
                fullRadius *= 4;
            break;

            case WARP_TRANSITION_FADE_FROM_MARIO:
            case WARP_TRANSITION_FADE_INTO_MARIO:

            case WARP_TRANSITION_FADE_FROM_STAR:
            case WARP_TRANSITION_FADE_INTO_STAR:
                fullRadius *= 1.5f;
            break;
        }
#endif

        if (transType & WARP_TRANSITION_FADE_INTO) { // Is the image fading in?
            gWarpTransition.data.startTexRadius = fullRadius;
            gWarpTransition.data.endTexRadius = 0;

        } else { // The image is fading out. (Reverses start & end circles)
            gWarpTransition.data.startTexRadius = 0;
            gWarpTransition.data.endTexRadius = fullRadius;
        }
    }
#endif
}

static s32 successMenuTimer = 0;
static s32 successMenuAction = 0;

#define SUCCESS_BLANK_BOX_X ((3 * SCREEN_CENTER_X / 4) + 4)
#define SUCCESS_BLANK_BOX_Y ((3 * SCREEN_CENTER_Y / 4) + 16)
#define PRINT_X_BASE (SCREEN_CENTER_X - SUCCESS_BLANK_BOX_X + 24)
#define PRINT_Y_BASE (SCREEN_CENTER_Y - SUCCESS_BLANK_BOX_Y + 8)
static void bsm_render_success_black_box(f32 alpha) {
    if (alpha <= 0.0f){
        gClownFontColor[3] = 0;
        return;
    }
    
    if (alpha > 1.0f) {
        alpha = 1.0f;
    }

    prepare_blank_box();
    bzero(gCurrEnvCol, sizeof(gCurrEnvCol));
    render_blank_box_rounded(SCREEN_CENTER_X - SUCCESS_BLANK_BOX_X, SCREEN_CENTER_Y - SUCCESS_BLANK_BOX_Y, SCREEN_CENTER_X + SUCCESS_BLANK_BOX_X, SCREEN_CENTER_Y + SUCCESS_BLANK_BOX_Y, 0, 0, 0, (u8) (159.0f * alpha));
    finish_blank_box();

    gClownFontColor[3] = (u8) (255.0f * alpha);
}

static void bsm_print_if_time_allows(s32 requiredTime, s32 fadeDuration, char *str, s16 x, s16 y, u8 isPuppyprint, u8 centered) {
    f32 alpha = 1.0f;

    if (successMenuTimer < requiredTime) {
        return;
    }

    if (requiredTime + fadeDuration > successMenuTimer) {
        alpha = (f32) (successMenuTimer - requiredTime + 1) / (fadeDuration + 1);
    }

    if (isPuppyprint) {
        print_set_envcolour(255, 255, 255, alpha * gClownFontColor[3]);
        print_small_text(x, y, str, centered ? PRINT_TEXT_ALIGN_CENTER : PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    } else {
        gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
        bzero(gCurrEnvCol, sizeof(gCurrEnvCol));
        if (!(gEmulator & EMU_CONSOLE)) {
            print_set_envcolour(0, 0, 0, (95 * (u32) (alpha * gClownFontColor[3])) >> 8);
            print_hud_lut_string_translated(x - 2, y + 2, str, centered);
        }
        print_set_envcolour(255, 255, 255, alpha * gClownFontColor[3]);
        print_hud_lut_string_translated(x, y, str, centered);
        gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
    }
}

#define POINTS_FOR_BASELINE 400
#define POINT_PER_FRAMES 30
static s32 bsm_get_time_bonus(s32 courseId, s32 frameTime) {
    s32 baselineTime = gBSMStageProperties[courseId].baselineTime;

    s32 timediff = baselineTime - frameTime;
    s32 absoluteBonus = timediff / POINT_PER_FRAMES;

    f32 fracTime = 2.0f - ((f32) frameTime / baselineTime);
    s32 relativeBonus = POINTS_FOR_BASELINE * fracTime;

    s32 finalBonus = relativeBonus + absoluteBonus;
    return finalBonus >= 0 ? finalBonus : 0;
}

static s32 bsm_get_red_balloon_bonus(void) {
    const s16 gRedBalloonPointTable[] = {
        0,   // 0
        5,   // 1
        15,  // 2
        30,  // 3
        50,  // 4
        75,  // 5
        125, // 6
        200, // 7
        300  // 8
    };

    return gRedBalloonPointTable[gBSMRedBalloonsPopped];
}

static void success_render_tcs_and_key(void) {
    void **hudLUT = segmented_to_virtual(main_hud_lut);
    s32 x1 = (SCREEN_CENTER_X - 80) - 8;
    s32 x2 = (SCREEN_CENTER_X + 80) - 8;
    s32 y = (SCREEN_CENTER_Y - 60) - 8;

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);
    gDPPipeSync(gDisplayListHead++);
    bzero(gCurrEnvCol, sizeof(gCurrEnvCol));

    if (gBSMKeyCollected) {
        gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_KEY]);
        if (!(gEmulator & EMU_CONSOLE)) {
            print_set_envcolour(0, 0, 0, (95 * gClownFontColor[3]) >> 8);
            gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
            gSPTextureRectangle(gDisplayListHead++, (x1 - 1) << 2, (y + 1) << 2, ((x1 - 1) + 16) << 2,
                                ((y + 1) + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
            gDPPipeSync(gDisplayListHead++);
        }
        print_set_envcolour(255, 255, 255, gClownFontColor[3]);
    } else {
        gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_KEY_NA]);
        print_set_envcolour(255, 255, 255, (95 * gClownFontColor[3]) >> 8);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x1 << 2, y << 2, (x1 + 16) << 2,
                        (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gDisplayListHead++);

    if (gBSMTCSTokenCollected) {
        gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_TCS]);
        if (!(gEmulator & EMU_CONSOLE)) {
            print_set_envcolour(0, 0, 0, (95 * gClownFontColor[3]) >> 8);
            gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
            gSPTextureRectangle(gDisplayListHead++, (x2 - 1) << 2, (y + 1) << 2, ((x2 - 1) + 16) << 2,
                                ((y + 1) + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
            gDPPipeSync(gDisplayListHead++);
        }
        print_set_envcolour(255, 255, 255, gClownFontColor[3]);
    } else {
        gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, hudLUT[GLYPH_BSM_TCS_NA]);
        print_set_envcolour(255, 255, 255, (95 * gClownFontColor[3]) >> 8);
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_load_tex_block);
    gSPTextureRectangle(gDisplayListHead++, x2 << 2, y << 2, (x2 + 16) << 2,
                        (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    gDPPipeSync(gDisplayListHead++);

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);
}

// NOTE: Adding new ranks isn't exactly safe without changing this...
// Also: This assumes common1 is loaded!
u8 *bsmRankTextures[] = {
    custom_menu_rank_rank_f_rgba32_rgba32,
    custom_menu_rank_rank_d_rgba32_rgba32,
    custom_menu_rank_rank_c_rgba32_rgba32,
    custom_menu_rank_rank_b_rgba32_rgba32,
    custom_menu_rank_rank_a_rgba32_rgba32,
    custom_menu_rank_rank_s_rgba32_rgba32,
    custom_menu_rank_rank_g_rgba32_rgba32,
};

void bsm_render_success_menu(void) {
    f32 alpha = 1.0f;
    u8 isTimePB = FALSE;
    struct BSMCourseData *bsmData = save_file_get_bsm_data(gCurrSaveFileNum - 1);

    s32 timeBonus = bsm_get_time_bonus(gBSMLastCourse, gBSMFrameTimer);
    s32 redBalloonBonus = bsm_get_red_balloon_bonus();
    s32 tcsTokenBonus = gBSMTCSTokenCollected ? 125 : 0;

    gBSMFinalScoreCount = gBSMScoreCount + timeBonus + redBalloonBonus + tcsTokenBonus;

    if (bsmData[gBSMLastCourse].bestTimeInFrames > gBSMFrameTimer || bsmData[gBSMLastCourse].bestTimeInFrames == 0) {
        isTimePB = TRUE;
    }

    gClownFontColor[0] = 255;
    gClownFontColor[1] = 255;
    gClownFontColor[2] = 255;
    gClownFontColor[3] = 0;

    if (successMenuTimer < 0x7FFF) {
        successMenuTimer++;
    }

    switch (successMenuAction) {
        case 0:
            alpha = (f32) successMenuTimer / 15;
            bsm_render_success_black_box(alpha);

            if (successMenuTimer >= 25) {
                successMenuAction++;
                successMenuTimer = 0;
            }
            break;
        case 1:
            bsm_render_success_black_box(alpha);
            
            bsm_print_if_time_allows(10, 15, "BONUSES", SCREEN_CENTER_X, PRINT_Y_BASE + 52, FALSE, TRUE);

            sprintf(strBuf, "Base Score:  <COL_%s-->%d<COL_-------->", gBSMScoreCount > 0 ? "3FFF3F" : "FF3F3F", gBSMScoreCount);
            bsm_print_if_time_allows(30, 10, strBuf, PRINT_X_BASE, PRINT_Y_BASE + 76, TRUE, FALSE);

            sprintf(strBuf, "Time Bonus:  <COL_%s-->%d<COL_-------->", timeBonus > 0 ? "3FFF3F" : "FF3F3F", timeBonus);
            bsm_print_if_time_allows(45, 10, strBuf, PRINT_X_BASE, PRINT_Y_BASE + 92, TRUE, FALSE);

            sprintf(strBuf, "Red Balloon Bonus:  <COL_%s-->%d<COL_-------->", redBalloonBonus > 0 ? "3FFF3F" : "FF3F3F", redBalloonBonus);
            bsm_print_if_time_allows(60, 10, strBuf, PRINT_X_BASE, PRINT_Y_BASE + 108, TRUE, FALSE);

            sprintf(strBuf, "TCS Token Bonus:  <COL_%s-->%d<COL_-------->", tcsTokenBonus > 0 ? "3FFF3F" : "FF3F3F", tcsTokenBonus);
            bsm_print_if_time_allows(75, 10, strBuf, PRINT_X_BASE, PRINT_Y_BASE + 124, TRUE, FALSE);

            sprintf(strBuf, "SCORE: %d", gBSMFinalScoreCount);
            bsm_print_if_time_allows(105, 15, strBuf, SCREEN_CENTER_X, PRINT_Y_BASE + 150, FALSE, TRUE);

            bsm_print_if_time_allows(140, 15, "RANK: ", SCREEN_CENTER_X - 12, PRINT_Y_BASE + 178, FALSE, TRUE);

            #define FADE_ALPHA_RANK_FRAMES 20
            #define FADE_ALPHA_RANK_START 180
            if (successMenuTimer >= FADE_ALPHA_RANK_START) {
                f32 rankAlpha = 1.0f;
                f32 rankAlphaSqr = 1.0f;
                s32 rank = calculate_bsm_rank(gBSMLastCourse, gBSMFinalScoreCount);
                if (rank < 0) {
                    assert(FALSE, "Rank cannot be negative!");
                    rank = 0;
                }

                if (FADE_ALPHA_RANK_START + FADE_ALPHA_RANK_FRAMES > successMenuTimer) {
                    rankAlpha = (f32) (successMenuTimer - FADE_ALPHA_RANK_START + 1) / (FADE_ALPHA_RANK_FRAMES + 1);
                    rankAlphaSqr = sqr(rankAlpha);
                } else if (FADE_ALPHA_RANK_START + FADE_ALPHA_RANK_FRAMES == successMenuTimer) {
                    play_narrator_sound_at_random_by_rank_id(rank);
                }

                f32 x = (SCREEN_CENTER_X + 32) - 12;
                f32 y = (PRINT_Y_BASE + 178) + 8;

                x += (1.0f - rankAlpha) * 6.0f;
                y += (1.0f - rankAlpha) * 3.0f;
                
                gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_text_begin);
                bzero(gCurrEnvCol, sizeof(gCurrEnvCol));
                print_set_envcolour(255, 255, 255, rankAlphaSqr * gClownFontColor[3]);

                create_dl_ortho_matrix();
                create_dl_translation_matrix(MENU_MTX_NOPUSH, x, (SCREEN_HEIGHT - 16) - y, 0.0f);
                create_dl_scale_matrix(MENU_MTX_NOPUSH, 1.40f - (0.40f * rankAlphaSqr), 1.40f - (0.40f * rankAlphaSqr), 1.0f);

                gDPPipeSync(gDisplayListHead++);
                gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, VIRTUAL_TO_PHYSICAL(bsmRankTextures[rank]));
                gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_load_tex_block);
                gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_load_vert);

                gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_text_end);

            }

            if (successMenuTimer >= 220) {
                if (successMenuTimer == 220) {
                    init_image_screen_press_button(0, 0);
                }

                if (sDelayedWarpOp == WARP_OP_NONE) {
                    if (image_screen_press_button(-1, 0)) {
                        // TODO: Play Sound Effect
                        level_trigger_warp(gMarioState, WARP_OP_STAR_EXIT);
                        image_screen_cannot_press_button(-1, 0);
                    }
                } else {
                    image_screen_cannot_press_button(-1, 0);
                }
            }

            break;
    }

    success_render_tcs_and_key();

    bsm_print_if_time_allows(-1, 0, "TRACK CLEAR!", SCREEN_CENTER_X, PRINT_Y_BASE + 0, FALSE, TRUE);

    sprintf(strBuf, "<COL_FFFF00-->Time:<COL_--------> %d:%02d.%02d%s", gBSMFrameTimer / (30 * 60), (gBSMFrameTimer / 30) % 60, (gBSMFrameTimer % 30) * 100 / 30, isTimePB ? " <RAINBOW>(Record!)<RAINBOW>" : "");
    bsm_print_if_time_allows(-1, 0, strBuf, SCREEN_CENTER_X, PRINT_Y_BASE + 24, TRUE, TRUE);
}

/*
 * Sets up the information needed to play a warp transition, including the
 * transition type, time in frames, and the RGB color that will fill the screen.
 * The transition will play only after a number of frames specified by 'delay'
 */
void play_transition_after_delay(s16 transType, s16 time, u8 red, u8 green, u8 blue, s16 delay) {
    gWarpTransDelay = delay; // Number of frames to delay playing the transition.
    play_transition(transType, time, red, green, blue);
}

void process_bsm_actions(void) {
    if (gRenderBSMSuccessMenu) {
        bsm_render_success_menu();
    } else {
        successMenuTimer = 0;
        successMenuAction = 0;
    }

    if (gBSMNarratorItemTimer > 0) {
        gBSMNarratorItemTimer--;
        if (gBSMNarratorItemTimer == 0) {
            play_narrator_sound_at_random(&gBSMNarratorItem);
        }
    }

    if (gSelectionShown == BSM_SELECTION_CREDITS) {
        prepare_blank_box();
        render_blank_box_rounded(SCREEN_CENTER_X - 100, SCREEN_CENTER_Y - 75, SCREEN_CENTER_X + 100, SCREEN_CENTER_Y + 75, 0, 0, 0, 191);
        finish_blank_box();
        print_set_envcolour(255, 255, 255, 255);
        print_small_text(SCREEN_CENTER_X, SCREEN_HEIGHT * 1 / 4 + 0, creditsStr, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    } else if (gSelectionShown == BSM_SELECTION_DETAILED_STATS) {
        s32 xBase = 60;
        s32 yBase = (SCREEN_HEIGHT - 16) - 84;

        bzero(gCurrEnvCol, sizeof(gCurrEnvCol));
        print_set_envcolour(255, 255, 255, 255);
        prepare_blank_box();
        render_blank_box_rounded(xBase - 12, 32, SCREEN_WIDTH - (xBase - 12), SCREEN_HEIGHT - 32, 0, 0, 0, 191);
        finish_blank_box();
    
        sprintf(strBuf, "Track %d", gBSMSelectedButton + 1);
        print_set_envcolour(127, 255, 127, 255);
        print_small_text(SCREEN_CENTER_X, 44, strBuf, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
    
        print_set_envcolour(191, 223, 255, 255);
        print_small_text(SCREEN_CENTER_X, 58, gBSMStageProperties[gBSMSelectedButton].courseNameNoNewline, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);

        print_set_envcolour(255, 159, 31, 255);
        print_small_text(SCREEN_CENTER_X, 172, "Fastest Developer Time", PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);

        sprintf(strBuf, "%d:%02d.%02d",
            gBSMStageProperties[gBSMSelectedButton].developerTime / (30 * 60),
            (gBSMStageProperties[gBSMSelectedButton].developerTime / 30) % 60,
            (gBSMStageProperties[gBSMSelectedButton].developerTime % 30) * 100 / 30);
        print_set_envcolour(223, 159, 255, 255);
        print_small_text(SCREEN_CENTER_X, 186, strBuf, PRINT_TEXT_ALIGN_CENTER, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);

        create_dl_ortho_matrix();
        create_dl_translation_matrix(MENU_MTX_NOPUSH, xBase, yBase, 0.0f);
        gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_text_begin);
        for (s32 rank = ARRAY_COUNT(bsmRankTextures) - 1, i = 0; rank > 0; rank--, i++) {
            s32 x = (i % 2) * (SCREEN_CENTER_X - (xBase - (12 / 2)));
            s32 y = (i / 2) * -32.0f;

            create_dl_translation_matrix(MENU_MTX_PUSH, x, y, 0.0f);
            create_dl_scale_matrix(MENU_MTX_PUSH, 0.75f, 0.75f, 0.75f);

            gDPPipeSync(gDisplayListHead++);
            gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_32b, 1, VIRTUAL_TO_PHYSICAL(bsmRankTextures[rank]));
            gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_load_tex_block);
            gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_load_vert);

            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
            gSPPopMatrix(gDisplayListHead++, G_MTX_MODELVIEW);
        }
        gSPDisplayList(gDisplayListHead++, dl_rgba32_32x32_text_end);

        bzero(gCurrEnvCol, sizeof(gCurrEnvCol));
        print_set_envcolour(255, 255, 255, 255);
        for (s32 rank = ARRAY_COUNT(bsmRankTextures) - 1, i = 0; rank > 0; rank--, i++) {
            s32 x = (i % 2) * (SCREEN_CENTER_X - (xBase - (12 / 2)));
            s32 y = (i / 2) * -32.0f;

            sprintf(strBuf, "<COL_FFFF3F-->%d <COL_BFBFBF-->Pts.<COL_-------->", get_bsm_rank_requirement(gBSMSelectedButton, rank));
            print_small_text(xBase + x + 28, SCREEN_HEIGHT - (yBase + y + 17), strBuf, PRINT_TEXT_ALIGN_LEFT, PRINT_ALL, FONT_BALLOON_SLIDER_MANIA);
        }
    }
}

void render_game(void) {
    PROFILER_GET_SNAPSHOT_TYPE(PROFILER_DELTA_COLLISION);
    if (gCurrentArea != NULL && !gWarpTransition.pauseRendering) {
        if (gCurrentArea->graphNode) {
            geo_process_root(gCurrentArea->graphNode, gViewportOverride, gViewportClip, gFBSetColor);
        }
#ifdef PUPPYPRINT
        bzero(gCurrEnvCol, sizeof(ColorRGBA));
#endif

        gSPViewport(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gViewport));

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - gBorderHeight);
        render_hud();

        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

        process_bsm_actions();

        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        do_cutscene_handler();
        print_displaying_credits_entry();
        gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                      SCREEN_HEIGHT - gBorderHeight);
        gMenuOptSelectIndex = render_menus_and_dialogs();

        if (gMenuOptSelectIndex != 0) {
            gSaveOptSelectIndex = gMenuOptSelectIndex;
        }

        if (gViewportClip != NULL) {
            make_viewport_clip_rect(gViewportClip);
        } else
            gDPSetScissor(gDisplayListHead++, G_SC_NON_INTERLACE, 0, gBorderHeight, SCREEN_WIDTH,
                          SCREEN_HEIGHT - gBorderHeight);

        if (gWarpTransition.isActive) {
            if (gWarpTransDelay == 0) {
                gWarpTransition.isActive = !render_screen_transition(gWarpTransition.type, gWarpTransition.time,
                                                                     &gWarpTransition.data);
                if (!gWarpTransition.isActive) {
                    if (gWarpTransition.type & WARP_TRANSITION_FADE_INTO) {
                        gWarpTransition.pauseRendering = TRUE;
                    } else {
                        set_warp_transition_rgb(0, 0, 0);
                    }
                }
            } else {
                gWarpTransDelay--;
            }
        }
#ifdef S2DEX_TEXT_ENGINE
        s2d_init();

        // place any custom text engine code here if not using deferred prints

        s2d_handle_deferred();
        s2d_stop();
#endif
    } else {
        render_text_labels();
#ifdef PUPPYPRINT
        puppyprint_print_deferred();
#endif
        if (gViewportClip != NULL) {
            clear_viewport(gViewportClip, gWarpTransFBSetColor);
        } else {
            clear_framebuffer(gWarpTransFBSetColor);
        }
    }

    gViewportOverride = NULL;
    gViewportClip     = NULL;

    profiler_update(PROFILER_TIME_GFX, profiler_get_delta(PROFILER_DELTA_COLLISION) - first);
    profiler_print_times();
#ifdef PUPPYPRINT_DEBUG
    puppyprint_render_profiler();
#endif
}

STATIC_ASSERT(sizeof(creditsStr) <= 0xFF, "creditsStr exceeds deferred print maximum length!");
