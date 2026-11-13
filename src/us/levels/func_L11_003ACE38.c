#include "common.h"

/* NTSC-U counterpart of func_L11_003AEBE8 (src/levels/11_obani_moons/L11_003AE1B0.c) */
#include "vu0.h"

/* localdecomp:start func_L11_003ACE38 */
typedef struct { u8 pad0[0x20]; } M2_3AEBE8;
typedef struct {
    vu0_v4 f0;
    s32 f10;
    s32 f14;
    s32 f18;
    u8 pad1C[0x2C - 0x1C];
    s32 f2C;
    u8 pad30[0x40 - 0x30];
    s32 f40;
} V_3AEBE8;
extern vu0_v4 D_L11_001E84E0_003ACE38;
extern s32 D_L11_001E1020_003ACE38[12] __attribute__((section(".sdata")));
__asm__(".extern D_L11_001DE190_003ACE38, 4");
extern s32 D_L11_001DE190_003ACE38;
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_0044E010(void *, void *, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern s32 func_L01_004C4A18(void *, s32, f32, f32, f32);
extern void func_L11_003AD8F0(u8 *);

u8 *func_L11_003ACE38(vu0_v4 *pos, s32 a1, vu0_v4 *a2)
{
    vu0_v4 s0[2];
    vu0_v4 mtx;
    vu0_v4 a;
    vu0_v4 b;
    u8 *m;
    V_3AEBE8 *v;
    s32 i;

    s0[0] = *a2;
    m = func_003BCFB0(0x1C55, 0x80);
    if (m != 0) {
        *(s32 *)(m + 0xB8) = a1;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        v = *(V_3AEBE8 **)(m + 0x68);
        *(vu0_v4 *)(m + 0x10) = *pos;
        func_L01_0044E010(m, &mtx, 1);
        func_00388830(&a, &mtx, 3.0f);
        func_00388830(&b, &mtx, -3.0f);
        vec_add_ba(&a, &a, m + 0x10);
        vec_add_ab(&b, &b, m + 0x10);
        if (func_003CE740(&a, &b, 2, *(s32 *)(m + 0xB8), 0) != 0) {
            *(vu0_v4 *)(m + 0x10) = D_L11_001E84E0_003ACE38;
            func_00388830(&a, &mtx, 0.75f);
            vec_add_ab(m + 0x10, m + 0x10, &a);
        }
        v->f14 = D_L11_001DE190_003ACE38;
        v->f0 = s0[0];
        v->f10 = func_L01_004C4A18(m, 0, 1.0f, 1.0f, 1.0f);
        m[0x20] = 0;
        v->f18 = 0;
        func_L11_003AD8F0(m);
        v->f2C = 5;
        for (i = 0; i < 12; i++) {
            if (D_L11_001E1020_003ACE38[i] == 0) {
                D_L11_001E1020_003ACE38[i] = 1;
                v->f40 = i;
                break;
            }
        }
    }
    return m;
}
/* localdecomp:end func_L11_003ACE38 */
