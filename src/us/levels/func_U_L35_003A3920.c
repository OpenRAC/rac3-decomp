#include "common.h"
#include "vu0.h"
extern u8 *D_L35_0021F444[];

/* declared by functions of L35_003A29A8.c, which this file was cut from */
extern s32 func_U_L35_00418370(s32, s32);
extern f32 D_L35_001D66B0[4] __attribute__((section(".sdata")));

/* localdecomp:start func_U_L35_003A3920 */
extern void func_U_L35_00418628(void *, f32, f32);
extern s32 func_U_L35_00418340(s32);
extern u8 *func_U_L35_004410B0(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *D_L35_0021F3AC[];

void func_U_L35_003A3920(u8 *o) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u8 *q;
    s32 col;

    func_U_L35_00418628(a, 0.0f, 0.25f);
    col = 0x00FFE69B;
    vec_add_ab(a, a, o + 0x10);
    func_U_L35_00418628(b, 0.0f, 0.00416666688f);
    if (func_U_L35_00418340(3) != 0) {
        col = 0x00FFCD36;
    }
    q = func_U_L35_004410B0(a, b, 0x19, func_U_L35_00418370(-2, 2), col | 0x7F000000, col, 210000.0f, 105000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F444[0][1];
        q[3] = (func_U_L35_00418340(2) != 0) ? 0x44 : 0x48;
    }
    q = func_U_L35_004410B0(o + 0x10, D_L35_001D66B0, 2, 1, 0x7FFFCD36, 0x7FFFCD36, 630000.0f, 630000.0f, 0.0f, 0);
    if (q != 0) {
        q[2] = D_L35_0021F3AC[0][0];
        q[3] = (func_U_L35_00418340(2) != 0) ? 0x44 : 0x48;
    }
}
/* localdecomp:end func_U_L35_003A3920 */
