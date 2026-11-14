#include "common.h"

/* NTSC-U counterpart of func_L30_00359418 (src/levels/shared/L30_00359418.c): 101 -> 121 */
/* localdecomp:start func_L30_00358310 */
typedef struct { s32 f0; s32 f4; char p8[0x3C]; s32 f44; s32 f48; char p4C[0x54]; s32 fA0; char pA4[0x18]; s32 fBC; } S_00359418;
extern u8 *D_L30_001DF71C_00358310;
extern s32 D_L30_001DF2C0_00358310;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern void func_L01_00452F40(void *, s32);
extern s32 func_0037E0F0(void *, s32, s32);
extern void func_L30_003571D8(int, int);
extern s32 func_L01_004A73F8(s32, s32, void *, s32);
extern void func_0039FB08(s32);
void func_L30_00358310(u8 *moby) {
    S_00359418 *v = *(S_00359418 **)(moby + 0x68);
    u8 *h;
    s32 id;
    if (v->f0 != 0) {
        if (v->f4 != 0 && D_L30_001DF71C_00358310[(v->f4 << 8) + 0x20] >= 0xFD) {
            if (v->fA0 < 0x79) {
                v->fA0++;
            }
        }
        if (v->fA0 >= 0x79) {
            func_L01_00452F40(D_L30_001DF71C_00358310 + (v->f0 << 8), 1);
        } else {
            func_L01_00452F40(D_L30_001DF71C_00358310 + (v->f0 << 8), 0);
        }
    }
    if (func_0037E0F0(D_001A4C60, v->f44, 0)) {
        func_L30_003571D8(0xCA3, 0x66);
    }
    h = D_001A4C60 - 0x80;
    if (*(s32 *)(h + 0x25C4) == 0xAD) {
        if (v->fBC == -1 || D_001A30B0[v->fBC * 0x80 + 0xD0] == 0) {
            v->fBC = func_L01_004A73F8(0x11, 4, *(void **)(h + 0x25C0), 0);
        }
    } else {
        id = v->fBC;
        if (id != -1 && D_001A30B0[id * 0x80 + 0xD0] != 0) {
            func_0039FB08(id);
            v->fBC = -1;
        }
    }
    if (func_0037E0F0(D_001A4C60, v->f48, 0) && D_L30_001DF2C0_00358310 < 0x1E) {
        u8 *g = D_001A4C60 - 0x80;
        *(s32 *)(g + 0x1B04) = 3;
        *(s32 *)(g + 0x1B08) = 0x14;
    }
}
/* localdecomp:end func_L30_00358310 */
