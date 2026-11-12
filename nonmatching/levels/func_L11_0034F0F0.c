/* near miss (level 11, Obani Moons): draft, 174 differences counted (measured with --flags=-mvu0-use-vf0-vf2 for the VU0 helpers; the file has no other function): retail saves $s0-$s7, $fp and $ra with sq in 16-byte ascending slots (frame 0x110), the sq_ra class levels have no table for, so every stack offset and the schedule differ. Not tuned further */
#include "common.h"

/* localdecomp:start func_L11_0034F0F0 */
#include "vu0.h"
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
    u8 pad6[2];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} V_34F0F0;
typedef struct { u8 pad0[0x20]; f32 f20; u8 pad24[4]; s32 f28; s32 f2C; } P_34F0F0;
extern vu0_v4 D_L11_001E1700;
extern P_34F0F0 D_L11_001E1780;
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_0038DC20(void *, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L11_0034F5E0(u8 *, void *);

u8 *func_L11_0034F0F0(vu0_v4 *pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 size, s32 a8, s32 a9, s32 a10)
{
    vu0_v4 d;
    vu0_v4 m[1];
    vu0_v4 p;
    vu0_v4 e;
    u8 *mb;
    V_34F0F0 *v;
    P_34F0F0 *pl;

    mb = func_003C24B0(0x11E5, 0x80);
    if (mb != 0) {
        *(s16 *)(mb + 0x32) = 0xFF;
        mb[0x30] = 0xFF;
        mb[0x20] = 0;
        pl = &D_L11_001E1780;
        *(vu0_v4 *)(mb + 0x10) = *pos;
        v = *(V_34F0F0 **)(mb + 0x68);
        *(f32 *)(mb + 0x1C) = 1.0f;
        vec_sub_ba(&d, pl, mb + 0x10);
        func_0038CF68(&d, &d, 1.0f);
        func_003C5180(mb + 0x10, m, 1);
        *(vu0_v4 *)(mb + 0xC0) = d;
        func_0038CE90(mb + 0xD0, mb + 0xC0, m);
        func_0038CF68(mb + 0xD0, mb + 0xD0, 1.0f);
        func_0038CE90(mb + 0xE0, mb + 0xD0, mb + 0xC0);
        *(f32 *)(mb + 0xCC) = 0.0f;
        *(f32 *)(mb + 0xEC) = 0.0f;
        *(f32 *)(mb + 0xDC) = 0.0f;
        v->f20 = a2;
        v->f24 = a3;
        v->f28 = a4;
        v->f2C = a5;
        v->f30 = a6;
        v->f2 = 0x32;
        v->f8 = size + size;
        v->fC = size * 4.0f;
        v->f34 = a8;
        v->f1C = a9;
        v->f18 = a7;
        v->f0 = 0x32;
        v->f38 = a10;
        v->f14 = size;
        p = *(vu0_v4 *)(mb + 0x10);
        p.w = size * 3.0f;
        if (func_0038DC20(&p, 128.0f) == 1) {
            v->f4 = 8;
            v->f10 = 0.125f;
            if (a1 != 0 && func_0038CF00(pos, &D_L11_001E1700) < 48.0f) {
                pl->f28 = 0x21;
                pl->f20 = 0.075f;
                pl->f2C = 0;
            }
            if (v->f18 != 0) {
                vec_sub_ab(&e, mb + 0x10, &D_L11_001E1700);
                func_0038CF68(&e, &e, 1.0f);
                if (1.5707964f - func_0038D0C8(func_0038CE68(&e, (u8 *)&D_L11_001E1700 + 0x20)) < 0.4537856f) {
                    v->f18 = 1;
                } else {
                    v->f18 = 0;
                }
            }
        } else {
            v->f18 = 0;
            v->f4 = 0;
        }
        func_L11_0034F5E0(mb, m);
    }
    return mb;
}
/* localdecomp:end func_L11_0034F0F0 */
