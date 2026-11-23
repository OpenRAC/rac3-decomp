#include "common.h"

/* NTSC-U counterpart of func_L05_003619F0 (src/levels/05_daxx/L05_003619F0.c) */
/* localdecomp:start func_L05_00360748 */
#include "vu0.h"
__asm__(".extern D_L05_001DDA04_00360748, 4");
__asm__(".extern D_L05_001DDA08_00360748, 4");
__asm__(".extern D_L05_001DDA10_00360748, 4");
__asm__(".extern D_L05_001DDA20_00360748, 4");
__asm__(".extern D_L05_001DDA24_00360748, 4");
__asm__(".extern D_L05_001DDA28_00360748, 4");
__asm__(".extern D_L05_001DDA2C_00360748, 4");
__asm__(".extern D_L05_001DDA30_00360748, 1");
__asm__(".extern D_L05_001DDA34_00360748, 4");
__asm__(".extern D_L05_001DDA38, 4");
__asm__(".extern D_L05_001DDA3C, 4");
__asm__(".extern D_L05_001DDA40, 4");
__asm__(".extern D_L05_001DDA44, 4");
__asm__(".extern D_L05_001DDA48, 4");
__asm__(".extern D_L05_001DDA4C, 4");
__asm__(".extern D_L05_001DDA50, 4");
__asm__(".extern D_L05_001DDA54, 4");
__asm__(".extern D_L05_001DDA58, 4");
__asm__(".extern D_L05_001DDA5C, 4");
__asm__(".extern D_L05_001DDA60, 4");
__asm__(".extern D_L05_001DDA64, 4");
extern f32 D_L05_001DDA04_00360748;
extern f32 D_L05_001DDA08_00360748;
extern f32 D_L05_001DDA10_00360748;
extern f32 D_L05_001DDA20_00360748;
extern s32 D_L05_001DDA24_00360748;
extern s32 D_L05_001DDA28_00360748;
extern s32 D_L05_001DDA2C_00360748;
extern u8 D_L05_001DDA30_00360748;
extern s32 D_L05_001DDA34_00360748;
extern f32 D_L05_001DDA38;
extern f32 D_L05_001DDA3C;
extern f32 D_L05_001DDA40;
extern f32 D_L05_001DDA44;
extern f32 D_L05_001DDA48;
extern f32 D_L05_001DDA4C;
extern f32 D_L05_001DDA50;
extern s32 D_L05_001DDA54;
extern f32 D_L05_001DDA58;
extern f32 D_L05_001DDA5C;
extern f32 D_L05_001DDA60;
extern f32 D_L05_001DDA64;
extern u8 *D_L05_001EA758 __attribute__((section(".data")));
extern u8 D_L05_001D66B0_00360748[8];

extern void func_L01_00441FB8(s32, s32, s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_003BD360(void *);
extern void func_003BF6A8(void *, f32);
extern void func_L01_00452F40(void *, s32);
extern void func_L01_004420D0(void *, void *, void *, void *, void *, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00388800(void *, void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, s32, s32);
extern void func_L01_004026A0(void *, void *);
extern void func_L05_00360FB8(u8 *);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00443648(void *, void *, s32, f32, f32, f32, s32, s32, s32);

typedef struct {
    s32 id;
    u8 *target;
    s16 timer;
    s16 pad_a;
    f32 scale;
    vu0_v4 p10;
    vu0_v4 p20;
    vu0_v4 p30;
    vu0_v4 p40;
    f32 spin;
    s32 x54;
    f32 x58;
} V_3619F0;

void func_L05_00360748(u8 *o) {
    vu0_v4 p;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 vel; /* never written: retail reads its stack slot (sp+0x30) uninitialised too */
    vu0_v4 b;
    vu0_v4 r;
    V_3619F0 *v;
    u8 *t;
    s32 id;
    s32 hit;
    s32 i;
    s32 j;

    v = *(V_3619F0 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        func_L01_00441FB8((s32)o, 1, -1);
        func_L01_004A72A8(0, 4, o, 0x169C);
        break;
    case 1:
        if (*(f32 *)(o + 0x18) < 0.0f) {
            func_003BD360(o);
        }
        if (--v->timer <= 0 && (v->target != 0 || v->x54 == 1)) {
            *(vu0_q *)&p = *(vu0_q *)&v->p10;
            func_003BF6A8(&p, 0.045f);
            if (v->target != 0) {
                func_L01_00452F40(v->target, 1);
            }
            func_L01_00441FB8((s32)o, 2, -1);
            break;
        }
        *(vu0_q *)&p = *(vu0_q *)(o + 0x10);
        func_L01_004420D0(o + 0x10, &v->p10, &v->p20, &v->p30, &v->p40,
                          (f32)v->timer * v->scale);
        vec_sub_ba(&d, o + 0x10, &p);
        v->spin = func_00389380(v->spin, D_L05_001DDA08_00360748 * 0.017453292f * 0.016666668f);
        *(f32 *)(o + 0xF0) = func_00389380(*(f32 *)(o + 0xF0), D_L05_001DDA04_00360748 * 0.017453292f * 0.016666668f);
        *(f32 *)(o + 0xF8) = func_00388A28(d.x, d.y);
        *(f32 *)(o + 0xF4) = -func_00388A28(func_00388800(&p, o + 0x10), d.z);
        *(vu0_q *)&r = 0;
        r.x = func_0037E250(-1.0f, 1.0f);
        r.y = func_0037E250(-1.0f, 1.0f);
        r.z = func_0037E250(-1.0f, 1.0f);
        *(vu0_q *)&b = *(vu0_q *)&r;
        func_00388830(&b, &b, func_0037E250(0.1f, 0.2f) * 0.016666668f);
        func_00388830(&a, &vel, -func_0037E250(0.0016666668f, 0.016666668f));
        vec_add_ba(&b, &b, &a);
        func_00388830(&a, &vel, func_0037E250(0.0f, 1.0f) * func_00388770(&d));
        vec_add_ab(&a, &a, o + 0x10);
        func_L01_00460318(&a, &b, 0x6F00AFFF, 0x100000FF, func_0037E208(0x1C, 0x28), 0x28, func_0037E208(0x28, 0x46), 1);
        id = v->id;
        func_L01_004C76B8();
        hit = func_003CE740(&p, o + 0x10, 0, id, 0);
        if (hit != 0) {
            t = D_L05_001EA758;
            if (t != 0 && *(s16 *)(t + 0xAA) == 0x186D && t[0x20] != 2 && t[0x20] != 5) {
                t[0x20] = 4;
            }
        }
        func_L01_004C76F0();
        if (hit != 0) {
            if (v->target != 0 && D_L05_001EA758 == v->target) {
                func_L01_00452F40(D_L05_001EA758, 1);
            }
            func_L01_00441FB8((s32)o, 2, -1);
        } else if (v->target != 0 || v->x54 == 1) {
            func_L01_004026A0(func_L05_00360FB8, o);
        }
        break;
    case 2:
        func_L01_004A72A8(1, 0, o, 0x169C);
        *(vu0_q *)&p = *(vu0_q *)(o + 0x10);
        p.z += D_L05_001DDA20_00360748;
        func_L01_00466F98(&p, D_L05_001D66B0_00360748, D_L05_001DDA24_00360748, D_L05_001DDA30_00360748, D_L05_001DDA34_00360748, 0,
                          D_L05_001DDA38 * 210000.0f, D_L05_001DDA38 * D_L05_001DDA3C, 0.0f,
                          D_L05_001DDA44 * 0.00027777778f, 0.0f);
        for (i = 0; i < D_L05_001DDA28_00360748; i++) {
            *(vu0_q *)&d = *(vu0_q *)&p;
            func_003BF6A8(&d, D_L05_001DDA60);
            func_0037E4B8(&a, D_L05_001DDA4C * 0.016666668f, func_0037E2A8(), func_0037E250(D_L05_001DDA64 * 3.1415927f, 3.1415927f));
            func_L01_00466F98(&d, &a, D_L05_001DDA54, D_L05_001DDA30_00360748, D_L05_001DDA34_00360748, func_0037E1D8(2) ? -1 : 1,
                              D_L05_001DDA58 * 210000.0f, 0.0f, D_L05_001DDA40, D_L05_001DDA44 * 0.00027777778f, 0.0f);
        }
        for (j = 0; j < D_L05_001DDA2C_00360748; j++) {
            *(vu0_q *)&d = *(vu0_q *)&p;
            func_003BF6A8(&d, D_L05_001DDA60);
            func_0037E4B8(&a, D_L05_001DDA50 * 0.016666668f, func_0037E2A8(), func_0037E250(D_L05_001DDA64 * 3.1415927f, 3.1415927f));
            func_L01_0046DCB8(&d, &a, D_L05_001DDA54, D_L05_001DDA34_00360748, func_0037E1D8(2) ? -1 : 1, D_L05_001DDA30_00360748, 0, 0,
                              D_L05_001DDA5C * 210000.0f, D_L05_001DDA5C * 0.5f * 210000.0f, D_L05_001DDA48 * 0.00027777778f);
        }
        func_L01_00443648(o, o + 0x10, 0x08000001, D_L05_001DDA10_00360748, v->x58, 1.0f, 0, 1, 0);
        func_003BD360(o);
        break;
    }
}
/* localdecomp:end func_L05_00360748 */
