#include <ultra64.h>

#include "config.h"
#include "emutest.h"
#include "game_init.h"
#include "hud.h"
#include "memory.h"
#include "print.h"
#include "segment2.h"

/**
 * This file handles printing and formatting the colorful text that
 * appears when printing things such as "PRESS START".
 */

ColorRGBA gClownFontColor = {0xFF, 0xFF, 0xFF, 0xFF};

// left kerning, right kerning
const s8 clownFontKerning[][2] = {
    {1, 14}, // 0
    {2, 13}, // 1
    {1, 14}, // 2
    {1, 13}, // 3
    {1, 14}, // 4
    {1, 13}, // 5
    {1, 14}, // 6
    {1, 14}, // 7
    {1, 14}, // 8
    {1, 13}, // 9
    {1, 15}, // A
    {0, 14}, // B
    {0, 13}, // C
    {0, 15}, // D
    {0, 12}, // E
    {0, 12}, // F
    {0, 14}, // G
    {0, 14}, // H
    {1, 11}, // I
    {0, 11}, // J
    {0, 14}, // K
    {0, 12}, // L
    {0, 15}, // M
    {0, 14}, // N
    {0, 15}, // O
    {0, 13}, // P
    {0, 15}, // Q
    {0, 14}, // R
    {0, 13}, // S
    {0, 14}, // T
    {0, 14}, // U
    {0, 15}, // V
    {0, 15}, // W
    {0, 15}, // X
    {0, 15}, // Y
    {0, 13}, // Z
    {2,  9}, // !
    {1, 12}, // !!
    {1, 12}, // ?
    {0, 15}, // &
    {0, 15}, // %
    {0, 15}, // A Button
    {1, 15}, // D-Pad Button
    {2, 14}, // C Button
    {-1,  8}, // :
    {0,  0}, // [NULL]
    {1, 11}, // /
    {2, 13}, // -
    {0, 15}, // x
    {0, 14}, // Coin
    {0, 14}, // Red Coin
    {0, 14}, // Silver Coin
    {0, 14}, // Mario Head
    {0, 14}, // Star
    {4, 10}, // .
    {0, 14}, // Beta Key
    {3,  9}, // '
    {1, 11}, // "
    {0, 14}, // Umlaut
    {1, 14}, // BSM Balloon
    {1, 13}, // BSM Key
    {1, 13}, // BSM Key Invis
    {0, 15}, // BSM TCS Token
    {0, 15}, // BSM TCS Token Invis
    {0,  0}, // BSM Score (DO NOT USE)
    {0,  0}, // BSM TIME (DO NOT USE)
};

struct TextLabel {
    u32 x;
    u32 y;
    s16 length;
    char buffer[50];
};

/**
 * Stores the text to be rendered on screen
 * and how they are to be rendered.
 */
struct TextLabel *sTextLabels[52];
s16 sTextLabelsCount = 0;

s32 get_clown_font_right_kerning(s32 c) {
    if (c >= 0 && c < ARRAY_COUNT(clownFontKerning)) {
        return clownFontKerning[c][1];
    }

    if (c == GLYPH_SPACE) {
        return 10;
    }

    return 14;
}

s32 get_clown_font_left_kerning(s32 c) {
    if (c >= 0 && c < ARRAY_COUNT(clownFontKerning)) {
        return clownFontKerning[c][0];
    }

    return 0;
}

/**
 * Returns n to the exponent power, only for non-negative powers.
 */
s32 int_pow(s32 n, s32 exponent) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < exponent; i++) {
        result = n * result;
    }

    return result;
}

/**
 * Formats an integer n for print by fitting it to width, prefixing with a negative,
 * and converting the base.
 */
void format_integer(s32 n, s32 base, char *dest, s32 *totalLength, u8 width, s8 zeroPad) {
    u32 powBase;
    s32 numDigits = 0;
    s32 i;
    s32 len = 0;
    s8 digit;
    s8 negative = FALSE;
    char pad;

    if (zeroPad) {
        pad = '0';
    } else {
        pad = -1;
    }

    if (n != 0) {
        // Formats a negative number for negative prefix.
        if (n < 0) {
            n = -n;
            negative = TRUE;
        }

        // Increments the number of digits until length is long enough.
        while (TRUE) {
            powBase = int_pow(base, numDigits);

            if (powBase > (u32) n) {
                break;
            }

            numDigits++;
        }

        // Add leading pad to fit width.
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;

            // Needs 1 length to print negative prefix.
            if (negative == TRUE) {
                len--;
            }
        }

        // Use 'M' prefix to indicate negative numbers.
        if (negative == TRUE) {
            dest[len] = 'M';
            len++;
        }

        // Transfer the digits into the proper base.
        for (i = numDigits - 1; i >= 0; i--) {
            powBase = int_pow(base, i);
            digit = n / powBase;

            // FIXME: Why doesn't [] match?
            if (digit < 10) {
                *(dest + len + numDigits - 1 - i) = digit + '0';
            } else {
                *(dest + len + numDigits - 1 - i) = digit + '7';
            }

            n -= digit * powBase;
        }
    } else { // n is zero.
        numDigits = 1;
        if (width > numDigits) {
            for (len = 0; len < width - numDigits; len++) dest[len] = pad;
        }
        dest[len] = '0';
    }

    *totalLength += numDigits + len;
}

/**
 * Determines the width of the number for printing, writing to 'width'.
 * Additionally, this determines if a number should be zero-padded,
 * writing to 'zeroPad'.
 */
void parse_width_field(const char *str, s32 *srcIndex, u8 *width, s8 *zeroPad) {
    s8 digits[12]; // unknown length
    s8 digitsLen = 0;
    s16 i;

    // If first character is 0, then the string should be zero padded.
    if (str[*srcIndex] == '0') {
        *zeroPad = TRUE;
    }

    // Read width digits up until the 'd' or 'x' format specifier.
    while (str[*srcIndex] != 'b'
        && str[*srcIndex] != 'o'
        && str[*srcIndex] != 'd'
        && str[*srcIndex] != 'x') {
        digits[digitsLen] = str[*srcIndex] - '0';

        if (digits[digitsLen] < 0 || digits[digitsLen] >= 10) { // not a valid digit
            *width = 0;
            return;
        }

        digitsLen++;
        (*srcIndex)++;
    }

    // No digits
    if (digitsLen == 0) {
        return;
    }

    // Sum the digits to calculate the total width.
    for (i = 0; i < digitsLen - 1; i++) {
        *width = *width + digits[i] * ((digitsLen - i - 1) * 10);
    }

    *width = *width + digits[digitsLen - 1];
}

/**
 * Takes a number, finds the intended base, formats the number, and prints it
 * at the given X & Y coordinates.
 *
 * Warning: this fails on too large numbers, because format_integer has bugs
 * related to overflow. For romhacks, prefer sprintf + print_text.
 */
void print_text_fmt_int(s32 x, s32 y, const char *str, s32 n) {
    char c = 0;
    s8 zeroPad = FALSE;
    u8 width = 0;
    s32 base = 0;
    s32 len = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    while (c != 0) {
        if (c == '%') {
            srcIndex++;

            parse_width_field(str, &srcIndex, &width, &zeroPad);

            if (str[srcIndex] != 'b'
                && str[srcIndex] != 'o'
                && str[srcIndex] != 'd'
                && str[srcIndex] != 'x') {
                break;
            }
            if (str[srcIndex] == 'b') base =  2;
            if (str[srcIndex] == 'o') base =  8;
            if (str[srcIndex] == 'd') base = 10;
            if (str[srcIndex] == 'x') base = 16;

            srcIndex++;

            format_integer(n, base, sTextLabels[sTextLabelsCount]->buffer + len, &len, width, zeroPad);
        } else { // straight copy
            sTextLabels[sTextLabelsCount]->buffer[len] = c;
            len++;
            srcIndex++;
        }
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = len;
    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering at given X, Y coordinates.
 */
void print_text(s32 x, s32 y, const char *str) {
    char c = 0;
    s32 length = 0;
    s32 srcIndex = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    sTextLabels[sTextLabelsCount]->x = x;
    sTextLabels[sTextLabelsCount]->y = y;

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabelsCount++;
}

/**
 * Prints text in the colorful lettering centered at given X, Y coordinates.
 */
void print_text_centered(s32 x, s32 y, const char *str) {
    char c = 0;
    s32 length = 0;
    s32 srcIndex = 0;
    s32 xOffset = 0;

    // Don't continue if there is no memory to do so.
    if ((sTextLabels[sTextLabelsCount] = mem_pool_alloc(gEffectsMemoryPool,
                                                        sizeof(struct TextLabel))) == NULL) {
        return;
    }

    c = str[srcIndex];

    // Set the array with the text to print while finding length.
    while (c != 0) {
        sTextLabels[sTextLabelsCount]->buffer[length] = c;
        xOffset -= get_clown_font_left_kerning(char_to_glyph_index(c));
        xOffset += get_clown_font_right_kerning(char_to_glyph_index(c));
        length++;
        srcIndex++;
        c = str[srcIndex];
    }

    sTextLabels[sTextLabelsCount]->length = length;
    sTextLabels[sTextLabelsCount]->x = x - (xOffset / 2);
    sTextLabels[sTextLabelsCount]->y = y;
    sTextLabelsCount++;
}

/**
 * Converts a char into the proper colorful glyph for the char.
 */
s32 char_to_glyph_index(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 55;
    }

    if (c >= 'a' && c <= 'z') {
        return c - 87;
    }

    if (c >= '0' && c <= '9') {
        return c - 48;
    }

    if (c == ' ') {
        return GLYPH_SPACE;
    }

    if (c == '!') {
        return GLYPH_EXCLAMATION_PNT; // !, JP only
    }

    if (c == '#') {
        return GLYPH_TWO_EXCLAMATION; // !!, JP only
    }

    if (c == '$') {
        return GLYPH_COIN; // coin
    }

    if (c == '&') {
        return GLYPH_AMPERSAND; // &, JP only
    }

    if (c == '*') {
        return GLYPH_MULTIPLY; // x
    }

    if (c == '+') {
        return GLYPH_SILVER_COIN; // silver coin
    }

    if (c == ',') {
        return GLYPH_MARIO_HEAD; // Imagine I drew Mario's head
    }

    if (c == '-') {
        return GLYPH_MINUS; // minus
    }

    if (c == '.') {
        return GLYPH_PERIOD; // large shaded dot, JP only
    }

    if (c == '/') {
        return GLYPH_PERCENT; // %, JP only
    }

    if (c == ':') {
        return GLYPH_COLON; // :
    }

    if (c == ';') {
        return GLYPH_BSM_ELISE; // Elise face
    }

    if (c == '?') {
        return GLYPH_QUESTION_MARK; // ?, JP only
    }

    if (c == '@') {
        return GLYPH_RED_COIN; // red coin
    }

    if (c == '^') {
        return GLYPH_STAR; // star
    }

    if (c == '|') {
        return GLYPH_BETA_KEY; // beta key, JP only. Reused for Ü in EU.
    }

    return GLYPH_SPACE;
}

/**
 * Adds an individual glyph to be rendered.
 */
void add_glyph_texture(s8 glyphIndex) {
    const Texture *const *glyphs = segmented_to_virtual(main_hud_lut);

    gDPPipeSync(gDisplayListHead++);
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, glyphs[glyphIndex]);
    gSPDisplayList(gDisplayListHead++, dl_hud_img_load_tex_block);
}

#ifndef WIDESCREEN
/**
 * Clips textrect into the boundaries defined.
 */
void clip_to_bounds(s32 *x, s32 *y) {
    if (*x < TEXRECT_MIN_X) {
        *x = TEXRECT_MIN_X;
    }

    if (*x > TEXRECT_MAX_X) {
        *x = TEXRECT_MAX_X;
    }

    if (*y < TEXRECT_MIN_Y) {
        *y = TEXRECT_MIN_Y;
    }

    if (*y > TEXRECT_MAX_Y) {
        *y = TEXRECT_MAX_Y;
    }
}
#endif

/**
 * Renders the glyph that's set at the given position.
 */
void render_textrect(s32 x, s32 y, s32 pos) {
    s32 rectBaseX = x + pos * 12;
    s32 rectBaseY = 224 - y;
    s32 rectX;
    s32 rectY;

#ifndef WIDESCREEN
    // For widescreen we must allow drawing outside the usual area
    clip_to_bounds(&rectBaseX, &rectBaseY);
#endif
    rectX = rectBaseX;
    rectY = rectBaseY;
    gSPTextureRectangle(gDisplayListHead++, rectX << 2, rectY << 2, (rectX + 15) << 2,
                        (rectY + 15) << 2, G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
}

/**
 * Renders the text in sTextLabels on screen at the proper locations by iterating
 * a for loop.
 */
void render_text_labels(void) {
    s32 i;
    s32 j;
    s32 glyphIndex;
    Mtx *mtx;
    Texture **glyphs = segmented_to_virtual(main_hud_lut);

    if (sTextLabelsCount == 0) {
        return;
    }

    mtx = alloc_display_list(sizeof(*mtx));

    if (mtx == NULL) {
        sTextLabelsCount = 0;
        return;
    }

    guOrtho(mtx, 0.0f, SCREEN_WIDTH, 0.0f, SCREEN_HEIGHT, -10.0f, 10.0f, 1.0f);
    gSPPerspNormalize((Gfx *) (gDisplayListHead++), 0xFFFF);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_begin);

    for (s32 renderWithShadow = 0; renderWithShadow < 2; renderWithShadow++) {
        if (renderWithShadow == 0) {
            if (gEmulator & EMU_CONSOLE) {
                continue;
            }
            gDPSetEnvColor(gDisplayListHead++, 0, 0, 0, (gClownFontColor[3] * 95) >> 8);
        } else {
            gDPSetEnvColor(gDisplayListHead++, gClownFontColor[0], gClownFontColor[1], gClownFontColor[2], gClownFontColor[3]);
        }

        for (i = 0; i < sTextLabelsCount; i++) {
            s32 x = sTextLabels[i]->x;
            s32 y = (SCREEN_HEIGHT - 16) - sTextLabels[i]->y;

            if (renderWithShadow == 0) {
                x -= 2;
                y += 2;
            }
    
            for (j = 0; j < sTextLabels[i]->length; j++) {
                glyphIndex = char_to_glyph_index(sTextLabels[i]->buffer[j]);

                x -= get_clown_font_left_kerning(glyphIndex);

                if (glyphIndex != GLYPH_SPACE) {
                    render_rgba16_tex_lut(x, y, glyphs[glyphIndex]);
                }

                x += get_clown_font_right_kerning(glyphIndex);
            }

            if (renderWithShadow != 0) {
                mem_pool_free(gEffectsMemoryPool, sTextLabels[i]);
            }
        }
    }

    gSPDisplayList(gDisplayListHead++, dl_rgba16_text_end);

    sTextLabelsCount = 0;
}
