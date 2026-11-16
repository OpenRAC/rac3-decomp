#include "common.h"

/* NTSC-U counterpart of func_L39_004F1230 (src/levels/39_multiplayer_menu/L39_004ECE38.c) */
typedef struct {
    s32 val;
    s32 width;
    s8 sep;
} F_004F0A78;
extern u8 D_001B34B1[];
extern s32 func_L39_004F1030(u8 *, u32, F_004F0A78 *, s32);

/* localdecomp:start func_L39_004F1030 */
s32 func_L39_004F1030(u8 *data, u32 len, F_004F0A78 *f, s32 n) {
    s32 i;
    s32 pos;
    s32 c;
    s32 k;

    pos = 0;
    for (i = 0; i < n && pos < (s32)len && (c = (s8)data[pos++]) != 0; i++) {
        if (!(D_001B34B1[c] & 4)) {
            if (f[i].sep != 0 && f[i].sep != c) {
                goto end;
            }
            f[i].sep = c;
            k = 0;
            f[i].val = 0;
        } else {
            f[i].val = c - '0';
            k = 1;
        }
        while (k < f[i].width) {
            if (pos >= (s32)len) {
                goto end;
            }
            c = (s8)data[pos++];
            if (c == 0) {
                goto end;
            }
            if (!(D_001B34B1[c] & 4)) {
                goto end;
            }
            k++;
            f[i].val = f[i].val * 10 + (c - '0');
        }
    }
end:
    return i;
}
/* localdecomp:end func_L39_004F1030 */
