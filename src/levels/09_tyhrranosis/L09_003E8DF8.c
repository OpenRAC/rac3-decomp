#include "common.h"

/* localdecomp:start func_L09_003E8DF8 */
#include "vu0.h"

extern u8 *D_L09_001E009C;
extern void func_L09_003E91B8(u8 *);
extern void func_L09_003E9298(void *, s32);
extern void func_L01_004450F0(s32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C2880(void *);

void func_L09_003E8DF8(u8 *a0) {
    u8 *st;
    vu0_v4 tmp;
    u8 *m;

    st = *(u8 **)(a0 + 0x68);
    func_L09_003E91B8(a0);
    switch (a0[0x20]) {
    case 0:
        *(s16 *)(a0 + 0x32) = 200;
        a0[0x30] = 200;
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        *(s32 *)(st + 0x70) = 0x7D;
        func_L01_004450F0((s32)a0, 1, -1);
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(st + 0x68) = *(s32 *)(st + 0x70);
        }
        if (func_0038CAD0(st + 0x68)) {
            func_L01_004450F0((s32)a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            s32 i;
            for (i = 0; i < 4; i++) {
                s32 h = *(s32 *)(st + 0x40 + i * 4);
                if (h != -1) {
                    func_L09_003E9298(D_L09_001E009C + (h << 8), *(s32 *)(st + 0x70) - 8);
                }
            }
            if (*(s32 *)(st + 0x60) != -1) {
                u8 *e = D_L09_001E009C + (*(s32 *)(st + 0x60) << 8);
                u8 *e2 = D_L09_001E009C + (**(s32 **)(e + 0x68) << 8);
                *(s32 *)(*(u8 **)(e2 + 0x68) + 0xDC) = 8;
            }
            *(s32 *)(st + 0x68) = 0x4B;
        }
        if (func_0038CAD0(st + 0x68)) {
            func_L01_004450F0((s32)a0, 4, -1);
            break;
        }
        if (*(s16 *)(st + 0x66) != 0) {
            *(vu0_q *)(st + 0x50) = *(vu0_q *)(a0 + 0x10);
            func_L01_00443B88(&tmp, 0.0f, 0.1f);
            vec_add_ab(a0 + 0x10, a0 + 0x10, &tmp);
            if (*(s32 *)(st + 0x60) != -1) {
                m = D_L09_001E009C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(m + 0x10, m + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 0;
        } else {
            vec_sub_ab(&tmp, st + 0x50, a0 + 0x10);
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(st + 0x50);
            if (*(s32 *)(st + 0x60) != -1) {
                m = D_L09_001E009C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(m + 0x10, m + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 1;
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            vec_sub_ab(&tmp, st + 0x50, a0 + 0x10);
            *(vu0_q *)(a0 + 0x10) = *(vu0_q *)(st + 0x50);
            if (*(s32 *)(st + 0x60) != -1) {
                u8 *o = D_L09_001E009C + (*(s32 *)(st + 0x60) << 8);
                vec_add_ba(o + 0x10, o + 0x10, &tmp);
            }
            *(s16 *)(st + 0x66) = 1;
            *(f32 *)(st + 0x74) = func_L01_00443A18(0.1f, 0.5f) * 0.017453292f;
            *(f32 *)(st + 0x78) = func_L01_00443A18(0.1f, 0.5f) * 0.017453292f;
            *(s32 *)(st + 0x68) = 200;
        }
        {
            f32 lim = -0.19600002f;
            *(f32 *)(st + 0x6C) = *(f32 *)(st + 0x6C) + -0.00392f;
            if (lim < *(f32 *)(st + 0x6C)) {
                *(f32 *)(st + 0x6C) = lim;
            }
        }
        *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(st + 0x6C);
        *(f32 *)(a0 + 0xF0) = func_0038DAB8(*(f32 *)(a0 + 0xF0), *(f32 *)(st + 0x74));
        *(f32 *)(a0 + 0xF4) = func_0038DAB8(*(f32 *)(a0 + 0xF4), *(f32 *)(st + 0x78));
        if (*(s32 *)(st + 0x60) != -1) {
            u8 *o = D_L09_001E009C + (*(s32 *)(st + 0x60) << 8);
            *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + *(f32 *)(st + 0x6C);
        }
        if (func_0038CAD0(st + 0x68)) {
            func_003C2880(a0);
        }
        break;
    }
}
/* localdecomp:end func_L09_003E8DF8 */
