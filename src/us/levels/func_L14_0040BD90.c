#include "common.h"

/* NTSC-U counterpart of func_L14_0040EC48 (src/levels/14_koros/L14_0040E918.c) */
#include "vu0.h"

/* localdecomp:start func_L14_0040BD90 */
typedef struct {
    u8 pad[0x184];
    u8 *p184;
} S_40EC48;
extern S_40EC48 D_L14_0021F958_0040BD90;
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_0044C900(void *, void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, u32, u32, s32, f32, f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern f32 func_L01_00440918(f32, f32);
void func_L14_0040BD90(void *pos) {
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 d;
    s32 r;
    s32 n;
    s32 life;
    s32 life2;
    s32 k;
    s32 c;
    f32 spd;
    f32 sz;
    f32 rad;
    f32 a;
    u8 *e;
    vu0_v4 *pp;
    f32 sz2;
    p = *(vu0_v4 *)pos;
    pp = &p;
    r = func_0037E208(15, 20);
    spd = func_0037E250(0.0f, 0.035f);
    for (n = 0; n < r; n++) {
        life = func_0037E208(100, 150);
        sz = func_0037E250(1.0f, 2.0f);
        sz2 = sz + sz;
        q = *pp;
        rad = func_0037E250(0.6f, 3.0f);
        a = func_0037E250(-3.1415927f, 3.1415927f);
        func_L01_0044C900(&q, &q, rad, a, func_0037E250(-3.1415927f, 3.1415927f));
        vec_sub_ab(&d, &q, pp);
        func_00388830(&d, &d, spd);
        k = func_0037E208(-1, 1);
        e = func_L01_00472438(&q, &d, life, k, 0x7F407FFF, 0x001020FF, 0, sz * 210000.0f, sz2 * 210000.0f, 0.0f);
        if (e != 0) {
            e[9] = 0xF2;
            e[2] = D_L14_0021F958_0040BD90.p184[3];
            if (func_0037E1D8(2) == 0) {
                e[3] = 0x44;
            }
        }
        if (func_0037E1D8(2) == 0) {
            func_00388830(&d, &d, func_0037E250(0.1f, 0.3f));
            c = (s32)func_L01_00440918(2.0f, 5.0f);
            life2 = func_0037E208(40, 65);
            e = func_L01_0046DCB8(&q, &d, life2, 0x7F407FFF, c, 0x7F, 0x7F, func_0037E250(0.5f, 1.0f) * 210000.0f, 0.0f, 0.0f, 1);
            if (e != 0) {
                e[9] = 0xF2;
                if (func_0037E1D8(2) == 0) {
                    e[3] = 0x44;
                }
            }
        }
    }
}
/* localdecomp:end func_L14_0040BD90 */
