#include "common.h"

/* NTSC-U counterpart of func_L40_003DA9A0 (src/levels/shared/L40_003DA9A0.c): 75 -> 90 */
/* localdecomp:start func_L40_003DA778 */
#include "vu0.h"

typedef int q_003DA9A0 __attribute__((mode(TI)));

typedef struct {
    f32 f0;
    f32 f4;
    s16 s8;
    s16 pad_A;
    f32 fC;
    vu0_v4 pos;
    f32 dir[3];
    f32 f2C;
    u8 *p[4];
    u8 pad_40[2];
    u8 b42;
    u8 b43;
    s16 s44[4];
    u8 pad_4C[4];
    f32 f50[4];
} S_003DA9A0;

extern void *D_L40_002497C0_003DA778;
extern vu0_v4 D_L40_002497D0[8] __attribute__((section(".sdata")));
extern const f32 D_L40_00246B20[] __attribute__((section(".sdata")));
extern vu0_v4 D_L40_0024A140;

extern void func_00388830(void *, void *, f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_00388BD0(void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern void func_003BFD10(void *, void *, void *, f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern void func_L40_003DA0C8(void);
extern s32 func_L39_005BC958(void *, s32, f32);
extern void func_L01_00402498(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_0039CAE0(void *, void *, s32);
extern void func_L40_003DA6B0(void *, void *, s32);
extern void func_L40_003DA188(void *);
extern void func_L40_003DAC28(u8 *);

void func_L40_003DA778(u8 *m) {
    S_003DA9A0 *d = *(S_003DA9A0 **)(m + 0x68);
    u8 *t;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    f32 f;
    f32 a;
    vu0_v4 v;
    u8 buf[16];

    switch (m[0x20]) {
    case 0:
        m[0x20] = 1;
        *(u16 *)(m + 0x34) |= 0x41;
        *(void **)(m + 0x98) = 0;
        m[0xBC] = 0;
        *(q_003DA9A0 *)(m + 0x10) = *(q_003DA9A0 *)(*(u8 **)(m + 0xB8) + 0x10);
        *(q_003DA9A0 *)(m + 0xF0) = *(q_003DA9A0 *)(*(u8 **)(m + 0xB8) + 0xF0);
        func_00388830(&d->pos, m + 0xE0, 0.5f);
        vec_add_ab(&d->pos, &d->pos, m + 0x10);
        *(s32 *)&d->f0 = 0;
        d->s8 = 0;
        f = d->f0;
        d->f4 = func_L39_005B2510(f, 3.1415927f);
        d->fC = f;
        d->b42 = 0;
        for (i = 0; i < 4; i++) {
            d->f50[i] = func_L39_005B2498(0xFF);
            d->s44[i] = 0x5A;
        }
        for (j = 3; j >= 0; j--) {
            d->p[j] = 0;
        }
        if (D_L40_002497C0_003DA778 == 0) {
            func_00388BD0(m + 0xC0, m + 0xF0);
            D_L40_002497C0_003DA778 = m;
            m[0x30] = 0xFF;
            func_00388830(&D_L40_002497D0[0], m + 0xC0, 0.25f);
            D_L40_002497D0[4] = *(vu0_v4 *)(m + 0xE0);
            func_00388830(&D_L40_002497D0[1], m + 0xD0, 0.25f);
            D_L40_002497D0[5] = *(vu0_v4 *)(m + 0xC0);
            func_00388830(&D_L40_002497D0[2], m + 0xE0, 0.25f);
            D_L40_002497D0[6] = *(vu0_v4 *)(m + 0xD0);
            vec_add_ab(&D_L40_002497D0[3], m + 0xC0, m + 0xE0);
            func_00388830(&D_L40_002497D0[3], &D_L40_002497D0[3], 0.25f);
            func_00388758(&D_L40_002497D0[7], &D_L40_002497D0[3], m + 0xD0);
        }
        a = func_L39_005B2510(0.0f, 6.2831855f);
        func_0037E4B8(d->dir, 1.0f, a, func_L39_005B2510(-1.5707964f, 1.5707964f));
        d->f2C = func_L39_005B2568(0.785398f, 1.5707964f);
    case 1:
        t = *(u8 **)(m + 0xB8);
        *(q_003DA9A0 *)(m + 0x10) = *(q_003DA9A0 *)(t + 0x10);
        *(q_003DA9A0 *)(&d->pos) = *(q_003DA9A0 *)(t + 0x10);
        func_003BFD10(m + 0x10, &d->pos, &d->pos, -0.5f);
        m[0x20] = 2;
    case 2:
        *(q_003DA9A0 *)(&d->pos) = *(q_003DA9A0 *)(m + 0x10);
        d->pos.z += 0.5f;
        for (k = 0; k < 4; k++) {
            u8 *p = d->p[k];
            if (p != 0) {
                p += 0x20;
                *(f32 *)(p + 8) = func_00388978(*(f32 *)(p + 0xC)) * 0.15f + 0.25f;
                *(f32 *)(p + 0xC) = func_00389380(*(f32 *)(p + 0xC), D_L40_00246B20[k]);
            }
        }
        d->f0 = func_00388978(d->f4) * 0.06f;
        d->f4 = func_00389380(d->f4, 0.034906585f);
        if (D_L40_002497C0_003DA778 == m) {
            func_L40_003DA0C8();
        }
        *(q_003DA9A0 *)&v = *(q_003DA9A0 *)(m + 0x10);
        func_003BFD10(m + 0x10, &v, &v, -0.5f);
        v.w = 1.0f;
        if (func_L39_005BC958(&v, 0, 48.0f) >= 0) {
            func_L01_00402498(func_L40_003DAC28, m);
            func_00388800(m + 0x10, &D_L40_0024A140);
            for (n = 0; n < 4; n++) {
                func_L01_0039CAE0(m, buf, n);
                func_L40_003DA6B0(m, buf, n);
            }
        }
        do {
        } while (0); /* an empty macro: its loop note aligns the case 3 label (retail's nop) */
        break;
    case 3:
        func_L40_003DA188(m);
        break;
    case 4:
        if (D_L40_002497C0_003DA778 == m) {
            func_L40_003DA0C8();
        }
        break;
    }
}
/* localdecomp:end func_L40_003DA778 */
