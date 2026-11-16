#include "common.h"

/* NTSC-U counterpart of func_L35_003A4EA8 (src/levels/35_vidcomic_5/L35_003A4EA8.c) */
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L35_003A3590 */
#include "vu0.h"

typedef struct V_003A4EA8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A4EA8;

extern u8 *D_L35_0021F4D4[];
extern void func_0037E2F0(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L35_003A3590(s32 arg0) {
    u8 *a0 = (u8 *)arg0;
    V_003A4EA8 pos;
    V_003A4EA8 vel;
    s32 col;
    s32 idx;
    f32 s;
    u8 *p;

    col = 0xFFE361;
    func_0037E2F0(&pos, 0.0f, 0.25f);
    vec_add_ba(&pos, &pos, a0 + 0x10);
    func_0037E2F0(&vel, 0.0f, 0.00833333377f);
    if (func_0037E1D8(3)) {
        col = 0xFFF2B3;
    }
    s = func_0037E250(0.5f, 0.7f);
    p = func_L01_00472438(&pos, &vel, 100, func_0037E208(-2, 2), col | 0x7F000000, col & 0xFFFFFF, s * 210000.0f,
                          42000.0f, func_0037E250(0.25f, 3.0f), 0);
    idx = func_0037E208(1, 3);
    if (p != 0) {
        p[2] = D_L35_0021F4D4[0][idx];
        p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
    }
    if (func_0037E1D8(8) == 0) {
        col = 0xFFE361;
        if (func_0037E1D8(3)) {
            col = 0xFFF2B3;
        }
        s = s + s;
        p = func_L01_00472438(&pos, &vel, 0x96, func_0037E208(0, 1), col | 0x20000000, col & 0xFFFFFF, s * 210000.0f,
                              (s - 0.1f) * 210000.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L35_0021F4D4[0][idx];
            p[3] = func_0037E1D8(2) ? 0x44 : 0x48;
        }
    }
}
/* localdecomp:end func_L35_003A3590 */
