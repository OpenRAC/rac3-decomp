/* functional: medium. Same flow, stores and calls as retail; the COP2 vsub/vadd.xyz are scalar xyz ops (w taken from the first operand as retail) and lq/sq copies are struct copies; schedule differs (checker shows a longer function). */
#include "vu0.h"
__asm__(".extern D_L30_001DDB08, 4");
extern f32 D_L30_001DDB08;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_359A08;
typedef struct {
    u8 p0[0xC]; s32 iC; s32 i10;
    u8 p14[0x40 - 0x14]; s32 i40; s32 i44;
    u8 p48[0xA4 - 0x48]; s32 fA4; s32 fA8; s32 fAC;
    u8 pB0[0xC0 - 0xB0]; f32 fC0; f32 fC4; f32 fC8; f32 fCC;
    f32 fD0; u8 pD4[4]; s32 fD8; s32 fDC;
} V_359A08;
extern Q_359A08 D_L30_001E1440;
extern Q_359A08 D_L30_001E1450;
extern u8 D_L30_001E2240[];
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF800;
extern u8 D_001A4BE0[];
extern u8 D_00142660[];
extern void func_L30_00359D78(void *);
extern void func_L30_00358A18(void *);
extern void func_L01_00404A10(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00456230(void *, s32);

void func_L30_00359A08(u8 *self) {
    V_359A08 *v = *(V_359A08 **)(self + 0x68);
    s32 doit;

    if (v->fAC != 0) {
        func_L30_00359D78(self);
        return;
    }
    D_L30_001E1440 = *(Q_359A08 *)D_L30_001E2240;
    D_L30_001E1440.y = *(f32 *)(D_001A4BE0 + 0x84);
    if (v->fA4 == 1 || v->fA8 == 1) {
        func_L01_00404A10(func_L30_00358A18);
        v->fD0 = 1.2f - fabs_asm((f32)(v->fD8 / 2 - v->fDC)) / 150.0f;
        D_L30_001E1440 = *(Q_359A08 *)(D_001A4BE0 + 0x80);
        if (v->fD0 > 1.0f) {
            v->fD0 = 1.0f;
        } else if (v->fD0 < 0.0f) {
            v->fD0 = 0.0f;
        }
        if (v->fDC < (s32)((f32)v->fD8 * 0.5f)) {
            Q_359A08 tmp;
            u8 *e;
            f32 h, d0, d1;

            tmp.x = D_L30_001E1450.x - v->fC0;
            tmp.y = D_L30_001E1450.y - v->fC4;
            tmp.z = D_L30_001E1450.z - v->fC8;
            tmp.w = D_L30_001E1450.w;
            e = D_L30_001DF800 + (v->i44 << 7);
            h = *(f32 *)(D_001A4BE0 + 0x84);
            d0 = fabs_asm((v->fC4 - h) + D_L30_001DDB08);
            d1 = fabs_asm((*(f32 *)(e + 0x34) - h) + D_L30_001DDB08);
            func_0038CE20(&tmp, &tmp, d1 / d0);
            e = D_L30_001DF800 + (v->i44 << 7);
            D_L30_001E1450.x = *(f32 *)(e + 0x30) + tmp.x;
            D_L30_001E1450.y = *(f32 *)(e + 0x34) + tmp.y;
            D_L30_001E1450.z = *(f32 *)(e + 0x38) + tmp.z;
            D_L30_001E1450.w = *(f32 *)(e + 0x3C);
            *(Q_359A08 *)&v->fC0 = *(Q_359A08 *)(D_L30_001DF800 + (v->i44 << 7) + 0x30);
            if (v->fA4 == 1) {
                v->fA4 = 2;
                func_L01_00456230(D_L30_001DF71C + (v->iC << 8), 1);
                D_00142660[0x77] |= 2;
            }
            if (v->fA8 == 1) {
                v->fA8 = 2;
                func_L01_00456230(D_L30_001DF71C + (v->i10 << 8), 1);
                D_00142660[0x77] |= 4;
            }
            *(Q_359A08 *)(D_001A4BE0 + 0x80) = *(Q_359A08 *)(D_L30_001DF800 + (v->i40 << 7) + 0x30);
        }
    } else if (v->fA4 == 2 || v->fA8 == 2) {
        if (v->fDC >= 3) {
            func_L01_00404A10(func_L30_00358A18);
        }
        v->fD0 = 1.2f - fabs_asm((f32)(v->fD8 / 2 - v->fDC)) / 150.0f;
        if (v->fD0 > 1.0f) {
            v->fD0 = 1.0f;
        } else if (v->fD0 < 0.0f) {
            v->fD0 = 0.0f;
        }
    }
}
