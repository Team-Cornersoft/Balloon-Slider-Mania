#ifndef INTRO_HEADER_H
#define INTRO_HEADER_H

#include "types.h"

// geo
extern const GeoLayout intro_scam_screen[];
extern const GeoLayout intro_retry_menu[];
extern const GeoLayout intro_elise_message[];
extern const GeoLayout intro_gold_mario_message[];
extern const GeoLayout intro_wing_mario_message[];
extern const GeoLayout intro_geo_splash_screen[];
extern const GeoLayout intro_geo_mario_head_regular[];
extern const GeoLayout intro_geo_mario_head_dizzy[];
extern const GeoLayout intro_geo_debug_level_select[];

// texture
extern const Texture scam_warning[];

// leveldata
extern const Gfx intro_seg7_dl_main_logo[];
extern const Gfx intro_seg7_dl_copyright_trademark[];
extern const f32 intro_seg7_table_scale_1[];
extern const f32 intro_seg7_table_scale_2[];

// script
extern const LevelScript level_scam_warning_screen[];
extern const LevelScript level_intro_retry_menu[];
extern const LevelScript level_intro_elise_message[];
extern const LevelScript level_intro_gold_mario_message[];
extern const LevelScript level_intro_wing_mario_message[];
extern const LevelScript level_intro_splash_screen[];
extern const LevelScript level_intro_mario_head_regular[];
extern const LevelScript level_intro_mario_head_dizzy[];
extern const LevelScript level_intro_entry_level_select[];
extern const LevelScript script_intro_file_select[];
extern const LevelScript script_intro_level_select[];
extern const LevelScript script_intro_main_level_entry_stop_music[];
extern const LevelScript script_intro_main_level_entry[];
extern const LevelScript script_intro_splash_screen[];

#include "levels/intro/custom_retry_button/geo_header.h"

#include "levels/intro/custom_quit_button/geo_header.h"

#endif
