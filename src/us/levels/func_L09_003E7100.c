#include "common.h"

/* NTSC-U counterpart of func_L09_003E8DF8 (src/levels/09_tyhrranosis/L09_003E8DF8.c) */
/* localdecomp:start func_L09_003E7100 */
#include "vu0.h"

extern u8 *D_L09_001E011C;
extern void func_L09_003E74C0(u8 *);
extern void func_L09_003E75A0(void *, s32);
extern void func_L01_00441FB8(s32, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003BD360(void *);

void func_L09_003E7100(u8 *a0) {
    u8 *st;
    vu0_v4 tmp;
    u8 *m;

    st = *(u8 **)(a0 + 0x68);
    func_L09_003E74C0(a0);
    switch (a0[0x20]) {
    case 0:
        *(s16 *)(a0 + 0x32) = 200;
        a0[0x30] = 200;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        *(s32 *)(st + 0x70) = 0x96;
        func_L01_00441FB8((s32)a0, 1, -1);
        break;
    case 2:
        if (func_L01_00452EC8(a0)) {
            *(s32 *)(st + 0x68) = *(s32 *)(st + 0x70);
        }
        if (func_00388398(st + 0x68)) {
            func_L01_00441FB8((s32)a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_00452EC8(a0)) {
            s32 i;
            for (i = 0; i < 4; i++) {
                s32 h = *(s32 *)(st + 0x40 + i * 4);
                if (h != -1) {
                    func_L09_003E75A0(D_L09_001E011C + (h << 8), *(s32 *)(st + 0x70) - 10);
                }
            }
            if (*(s32 *)(st + 0x60) != -1) {
                u8 *e = D_L09_001E011C + (*(s32 *)(st + 0x60) << 8);
                u8 *e2 = D_L09_001E011C + (**(s32 **)(e + 0x68) << 8);
                *(s32 *)(*(u8 **)(e2 + 0x68) + 0xDC) = 8;
            }
            *(s32 *)(st + 0x68) = 0x5A;
        }
        if (func_00388398(st + 0x68)) {
            func_L01_00441FB8((s32)a0, 4, -1);
            break;
        }
        if (*(s16 *)(st + 0x66) != 0) {
            *(vu0_q *)(st + 0x50) = *(vu0_q *)(a0 + 0x10);
            func_L01_00440A88(&tmp, 0.0f, 0.1f);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &tmp);
            if (*(s32 *)(st + 0x60) != -1) {
                m = D_L09_001E011C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(m + 0x10, m + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 0;
        } else {
            vec_sub_ab(&tmp, st + 0x50, a0 + 0x10);
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(st + 0x50);
            if (*(s32 *)(st + 0x60) != -1) {
                m = D_L09_001E011C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(m + 0x10, m + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 1;
        }
        break;
    case 4:
        if (func_L01_00452EC8(a0)) {
            vec_sub_ab(&tmp, st + 0x50, a0 + 0x10);
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(st + 0x50);
            if (*(s32 *)(st + 0x60) != -1) {
                u8 *o = D_L09_001E011C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(o + 0x10, o + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 1;
            *(f32 *)(st + 0x74) = func_L01_00440918(0.1f, 0.5f) * 0.017453292f;
            *(f32 *)(st + 0x78) = func_L01_00440918(0.1f, 0.5f) * 0.017453292f;
            *(s32 *)(st + 0x68) = 240;
        }
        {
            f32 lim = -0.16333334147930145f;
            *(f32 *)(st + 0x6C) = *(f32 *)(st + 0x6C) + -0.0027222223579883575f;
            if (lim < *(f32 *)(st + 0x6C)) {
                *(f32 *)(st + 0x6C) = lim;
            }
        }
        *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(st + 0x6C);
        *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), *(f32 *)(st + 0x74));
        *(f32 *)(a0 + 0xF4) = func_00389380(*(f32 *)(a0 + 0xF4), *(f32 *)(st + 0x78));
        if (*(s32 *)(st + 0x60) != -1) {
            u8 *o = D_L09_001E011C + (*(s32 *)(st + 0x60) << 8);
            *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + *(f32 *)(st + 0x6C);
        }
        if (func_00388398(st + 0x68)) {
            func_003BD360(a0);
        }
        break;
    }
}
/* localdecomp:end func_L09_003E7100 */
