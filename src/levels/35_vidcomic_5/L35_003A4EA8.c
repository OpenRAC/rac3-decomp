#include "common.h"

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern s32 func_00382498(s32, s32);
extern u8 D_L35_001D66B0[8];
extern f32 func_003824E0(f32, f32);

/* localdecomp:start func_L35_003A4EA8 */
#include "vu0.h"

typedef struct V_003A4EA8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003A4EA8;

extern u8 *D_L35_0021F454[];
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L35_003A4EA8(s32 arg0) {
    u8 *a0 = (u8 *)arg0;
    V_003A4EA8 pos;
    V_003A4EA8 vel;
    s32 col;
    s32 idx;
    f32 s;
    u8 *p;

    col = 0xFFE361;
    func_00382580(&pos, 0.0f, 0.25f);
    vec_add_ba(&pos, &pos, a0 + 0x10);
    func_00382580(&vel, 0.0f, 0.010000001f);
    if (func_00382468(3)) {
        col = 0xFFF2B3;
    }
    s = func_003824E0(0.5f, 0.7f);
    p = func_L01_00475C60(&pos, &vel, 100, func_00382498(-2, 2), col | 0x7F000000, col & 0xFFFFFF, s * 210000.0f,
                          42000.0f, func_003824E0(0.25f, 3.0f), 0);
    idx = func_00382498(1, 3);
    if (p != 0) {
        p[2] = D_L35_0021F454[0][idx];
        p[3] = func_00382468(2) ? 0x44 : 0x48;
    }
    if (func_00382468(8) == 0) {
        col = 0xFFE361;
        if (func_00382468(3)) {
            col = 0xFFF2B3;
        }
        s = s + s;
        p = func_L01_00475C60(&pos, &vel, 0x96, func_00382498(0, 1), col | 0x20000000, col & 0xFFFFFF, s * 210000.0f,
                              (s - 0.1f) * 210000.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L35_0021F454[0][idx];
            p[3] = func_00382468(2) ? 0x44 : 0x48;
        }
    }
}
/* localdecomp:end func_L35_003A4EA8 */

/* localdecomp:start func_L35_003A5100 */
#include "vu0.h"
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_L35_0021F3C4[];

void func_L35_003A5100(s32 arg0) {
    u8 *o = (u8 *)arg0;
    vu0_v4 pos;
    vu0_v4 vel;
    s32 color;
    f32 r;
    u8 *p;

    func_00382580(&pos, 0.0f, 0.25f);
    vec_add_ba(&pos, &pos, o + 0x10);
    func_00382580(&vel, 0.0f, 0.010000001f);
    color = func_00382468(3) ? 0xFFED74 : 0x59F9FF;
    r = func_003824E0(0.8f, 1.2f);
    p = func_L01_00475C60(&pos, &vel, 0x46, func_00382498(-2, 2), color | 0x50000000, color,
                          r * 210000.0f, 105000.0f, -1.0f, 0);
    if (p != 0) {
        p[2] = D_L35_0021F3C4[0][2];
        p[3] = func_00382468(2) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_L35_003A5100 */

/* localdecomp:start func_L35_003A5238 */
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_L35_0021F32C[];

void func_L35_003A5238(u8 *o) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u8 *q;
    s32 col;

    func_00382580(a, 0.0f, 0.25f);
    col = 0x00FFE69B;
    vec_add_ab(a, a, o + 0x10);
    func_00382580(b, 0.0f, 0.0050000004f);
    if (func_00382468(3) != 0) {
        col = 0x00FFCD36;
    }
    q = func_L01_00475C60(a, b, 0x19, func_00382498(-2, 2), col | 0x7F000000, col, 210000.0f, 105000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F3C4[0][1];
        q[3] = (func_00382468(2) != 0) ? 0x44 : 0x48;
    }
    q = func_L01_00475C60(o + 0x10, D_L35_001D66B0, 2, 1, 0x7FFFCD36, 0x7FFFCD36, 630000.0f, 630000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F32C[0][0];
        q[3] = (func_00382468(2) != 0) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_L35_003A5238 */
