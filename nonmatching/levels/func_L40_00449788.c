/* PAL near miss (Claude wave S/pal): near miss: 35 words differ with the file's flags.
 * Worker's note: 35 diff (best, near/ file): semantics decoded (i = key & 0x3F; rows of 0x14 bytes {b1, h2, w4, w8, wC, w10}; i >= 16 -> D_L40_00257E00[i-16] compares w4 with wC, i < 16 -> D_L40_00257CC0[i] compares w4 with b1 ? w8 : wC; h2 must equal key; *out = w10; returns ...
 */
#include "common.h"

/* localdecomp:start func_L40_00449788 */
typedef struct Row_00449788 {
    u8 b0;
    u8 b1;
    u16 h2;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} Row_00449788;

extern Row_00449788 D_L40_00257CC0[];
extern Row_00449788 D_L40_00257E00[];

s32 func_L40_00449788(s32 key, s32 *out) {
    s32 i = key & 0x3F;
    u8 *tab;
    s32 off;
    Row_00449788 *r;
    s32 cmp;

    if (i >= 16) {
        tab = (u8 *)D_L40_00257E00;
        off = (i - 16) * 0x14;
        if (*(u16 *)(tab + off + 2) != key) {
            return 0;
        }
        goto use_wC;
    }
    tab = (u8 *)D_L40_00257CC0;
    off = i * 0x14;
    if (*(u16 *)(tab + off + 2) != key) {
        return 0;
    }
    if (tab[off + 1] == 0) {
use_wC:
        r = (Row_00449788 *)(tab + off);
        cmp = r->wC;
    } else {
        r = (Row_00449788 *)(tab + off);
        cmp = r->w8;
    }
    if (r->w4 != cmp) {
        return 0;
    }
    *out = r->w10;
    return 1;
}
/* localdecomp:end func_L40_00449788 */
