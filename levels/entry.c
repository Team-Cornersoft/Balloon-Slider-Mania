#include <ultra64.h>
#include "sm64.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/game_init.h"
#include "levels/castle_grounds/header.h"

#include "levels/intro/header.h"

#include "make_const_nonconst.h"

#include "config.h"

extern const LevelScript level_main_scripts_entry[];
const LevelScript level_script_entry[] = {
    INIT_LEVEL(),
    SLEEP(/*frames*/ 2),
    CALL_LOOP(/*arg*/ 0, /*func*/ check_fbe),
    BLACKOUT(/*active*/ FALSE),
#if defined(TEST_LEVEL)
    SET_REG(/*value*/ TEST_LEVEL),
    EXECUTE(/*seg*/ SEGMENT_GLOBAL_LEVEL_SCRIPT, /*script*/ _scriptsSegmentRomStart, /*scriptEnd*/ _scriptsSegmentRomEnd, /*entry*/ level_main_scripts_entry),
#elif defined(DEBUG_LEVEL_SELECT)
    SET_REG(/*value*/ LEVEL_CASTLE_GROUNDS),
    EXECUTE_WITH_CODE(/*seg*/ SEGMENT_LEVEL_SCRIPT, _castle_groundsSegmentRomStart, _castle_groundsSegmentRomEnd, level_cgds_menu_select, _castle_groundsSegmentBssStart, _castle_groundsSegmentBssEnd),
#else
    SET_REG(/*value*/ 0),
    EXECUTE(/*seg*/ SEGMENT_MENU_INTRO, /*script*/ _introSegmentRomStart, /*scriptEnd*/ _introSegmentRomEnd, /*entry*/ level_scam_warning_screen),
#endif
    JUMP(/*target*/ level_script_entry),
};
