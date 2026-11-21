#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_00406208);

/* localdecomp:start func_L01_00406210 */
extern long *D_L01_001E1068;
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
__asm__(".extern D_001D4BD0, 16");
__asm__(".extern D_001D4BD4, 16");

s32 func_L01_00406210(f32 x, f32 y, f32 w, f32 h, s32 u, s32 v, s32 tw, s32 th, u32 *col, long tex0) {
    s32 x0, x1, y0, y1;
    s32 uv0, uv1, uv2, uv3;
    long *p;

    x0 = (s32)(x * 16.0f) + D_001D4BD0 - 8;
    x1 = (s32)((x + w) * 16.0f) + D_001D4BD0 - 9;
    y0 = (s32)(y * 16.0f) + D_001D4BD4 - 8;
    y1 = (s32)((y + h) * 16.0f) + D_001D4BD4 - 9;
    if (x0 > 0x9000 || x1 < 0x7000 || y0 > 0x9000 || y1 < 0x7000) {
        return 0;
    }
    uv0 = (v << 20) + (u << 4);
    uv1 = (v << 20) + ((u + tw) << 4);
    uv2 = ((v + th) << 20) + (u << 4);
    uv3 = ((v + th) << 20) + ((u + tw) << 4);
    *(s32 *)((u8 *)D_L01_001E1068 + 0) = 0x10000009;
    *(s32 *)((u8 *)D_L01_001E1068 + 4) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 8) = 0;
    *(s32 *)((u8 *)D_L01_001E1068 + 12) = 0x50000009;
    D_L01_001E1068 += 2;
    D_L01_001E1068[0] = 0x0400000000008001L;
    D_L01_001E1068[1] = 0x8531531531531068L;
    D_L01_001E1068 += 2;
    p = D_L01_001E1068;
    p[0] = 2 | (2 << 2) | ((long)u << 4) | ((long)(u + tw - 1) << 14) | ((long)v << 24) | ((long)(v + th - 1) << 34);
    p[1] = tex0;
    p[2] = 0x15C;
    p[3] = col[0];
    p[4] = uv0;
    p[5] = x0 | ((long)y0 << 16) | 0xFFFFF000000000L;
    p[6] = col[1];
    p[7] = uv1;
    p[8] = x1 | ((long)y0 << 16) | 0xFFFFF000000000L;
    p[9] = col[2];
    p[10] = uv2;
    p[11] = x0 | ((long)y1 << 16) | 0xFFFFF000000000L;
    p[12] = col[3];
    p[13] = uv3;
    p[14] = x1 | ((long)y1 << 16) | 0xFFFFF000000000L;
    p[15] = 5;
    D_L01_001E1068 = D_L01_001E1068 + 16;
    return 1;
}
/* localdecomp:end func_L01_00406210 */

LINKER_REMNANT("asm/levels", func_L01_004064A0);
