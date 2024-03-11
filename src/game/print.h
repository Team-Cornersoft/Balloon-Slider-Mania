#ifndef PRINT_H
#define PRINT_H

#include <PR/ultratypes.h>

#define TEXRECT_MIN_X 10
#define TEXRECT_MAX_X 300
#define TEXRECT_MIN_Y 5
#define TEXRECT_MAX_Y 220

enum PrintfGlyphs {
    GLYPH_SPACE           = -1,
    GLYPH_U               = 30,
    GLYPH_EXCLAMATION_PNT = 36,
    GLYPH_TWO_EXCLAMATION = 37,
    GLYPH_QUESTION_MARK   = 38,
    GLYPH_AMPERSAND       = 39,
    GLYPH_PERCENT         = 40,
    GLYPH_A_BUTTON        = 41,
    GLYPH_DPAD_BUTTON     = 42,
    GLYPH_C_BUTTON        = 43,
    GLYPH_SLASH           = 46,
    GLYPH_MINUS           = 47,
    GLYPH_MULTIPLY        = 48,
    GLYPH_COIN            = 49,
    GLYPH_RED_COIN        = 50,
    GLYPH_SILVER_COIN     = 51,
    GLYPH_MARIO_HEAD      = 52,
    GLYPH_STAR            = 53,
    GLYPH_PERIOD          = 54,
    GLYPH_BETA_KEY        = 55,
    GLYPH_APOSTROPHE      = 56,
    GLYPH_DOUBLE_QUOTE    = 57,
    GLYPH_UMLAUT          = 58,
    GLYPH_BSM_RED_BALLOON = 59,
    GLYPH_BSM_KEY         = 60,
    GLYPH_BSM_KEY_NA      = 61,
    GLYPH_BSM_TCS         = 62,
    GLYPH_BSM_TCS_NA      = 63,
    GLYPH_BSM_SCORE       = 64,
    GLYPH_BSM_TIME        = 65,
};

void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n);
void print_text(s32 x, s32 y, const char *str);
void print_text_centered(s32 x, s32 y, const char *str);
void render_text_labels(void);
s32 char_to_glyph_index(char c);
void add_glyph_texture(s8 glyphIndex);
void render_textrect(s32 x, s32 y, s32 pos);

#endif // PRINT_H
