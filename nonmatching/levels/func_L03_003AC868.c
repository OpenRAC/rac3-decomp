/* func_L03_003AC868: near miss (file L03_003AAD60.c). 44 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): the stores and the saved registers are retail's (the 0x38 copy after the vars stores, stores 0x30, 0x32, 0x31 as in its siblings); retail anchors the four D_L03_001F02C0 quadword stores at +0x10 (two of them qzero), gcc computes a second base for the qzero pair, and retail schedules the 0x38 ld before the position copies; all orders of the five setup groups and of the four global stores tried */
#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C6F90(void *, s32, s32, s32, s32);
extern void func_003C7C38(void *);
extern u8 D_L03_001E24C0[];
__asm__(".extern D_L03_001DE5E0, 8");
extern u8 D_L03_001DE5E0[8];
__asm__(".extern D_L03_001DE5F0, 8");
extern u8 D_L03_001DE5F0[8];
extern u8 D_L03_001F02C0[];

u8 *func_L03_003AC868(u8 *a0, f32 t) {
    u8 *m = func_003C24B0(0x1C01, 0x80);
    u8 *v;
    vu0_v4 d;
    u8 *mat;
    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        v = *(u8 **)(m + 0x68);
        mat = m + 0xC0;
        *(u128_t *)(m + 0x10) = *(u128_t *)(D_L03_001E24C0 + 0x00);
        *(u128_t *)(m + 0xF0) = *(u128_t *)(D_L03_001E24C0 + 0x10);
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(s32 *)(m + 0xF0) = 0;
        *(s32 *)(v + 8) = 4;
        *(f32 *)(v + 4) = *(f32 *)(v + 0) = *(f32 *)(m + 0xF0);
        func_0038D308(mat, m + 0xF0);
        func_0038CF68(&d, mat, t);
        vec_add_ba(m + 0x10, &d, m + 0x10);
        *(u128_t *)(D_L03_001F02C0 + 0x10) = *(u128_t *)D_L03_001DE5E0;
        *(u128_t *)(D_L03_001F02C0 + 0x00) = *(u128_t *)D_L03_001DE5F0;
        qzero(D_L03_001F02C0 + 0x20);
        qzero(D_L03_001F02C0 + 0x30);
        func_003C6F90(m, 0x604040, 0xE, 0xE, 0xE);
        *(u16 *)(m + 0x34) &= 0xFF7F;
        func_003C7C38(m);
    }
    return m;
}
