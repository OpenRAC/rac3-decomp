/*
 * PAL near miss, P02 wave 1, 2026-11-16.
 * Owning file: src/levels/20_final_boss/L20_003D61B8.c.
 * Exact file flags: -O2 -G8 -fopt-stack -mno-check-zero-division.
 * Stock check.py: 252 differences on the final candidate (attempt 2).
 * The default assembler emits literal-pool loads where retail has inline float
 * constants. A whole-file @ps2as decision is needed before pursuing that path;
 * no alternative flags were tested and the owning file's existing C is unchanged.
 * Other differences include store scheduling and global address forms.
 * Uses the owning file's earlier declarations through check.py's normal context.
 * The contiguous VU0 add is one block with real operands and clobbers.
 */
#include "common.h"
#include "vu0.h"
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0045BD78(void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0041A4F0(void);
extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;
extern s32 D_L20_001DEBF4;
extern f32 D_L20_001DEBF8;
extern f32 D_L20_001DEBBC;
extern f32 D_L20_001DEBC0;
extern s32 D_L20_001E2640[];
extern vu0_v4 D_L20_002A2940[][20];
extern vu0_v4 D_L20_001E2600[] __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2610 __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2620 __attribute__((section(".sdata")));
extern vu0_v4 D_L20_001E2630 __attribute__((section(".sdata")));
extern u8 *D_L20_001E029C;

s32 func_L20_003D65D0(void *arg) {
    u8 *obj = arg;
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    u8 *m;
    *(u16 *)(obj + 0x34) |= 0x800;
    *(vu0_v4 *)(v + 0x5B0) = *(vu0_v4 *)(obj + 0x10);
    *(u8 **)(v + 0x2F8) = func_003C24B0(0x1CB4, 0x80);
    *(u8 **)(v + 0x2FC) = func_003C24B0(0x1CB4, 0x80);
    func_L01_00456160(*(u8 **)(v + 0x2F8), obj);
    func_L01_00456160(*(u8 **)(v + 0x2FC), obj);
    obj[0x30] = 255;
    *(u16 *)(obj + 0x32) = 255;
    D_L20_001DEBEC = 0;
    D_L20_001DEBF0 = 0;
    D_L20_001DEBF4 = 0;
    *(u16 *)(*(u8 **)(v + 0x2F8) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(v + 0x2F8) + 0x34) &= ~0x1000;
    *(s32 *)(*(u8 **)(v + 0x2F8) + 0x98) = 0;
    func_L01_004AA7E8(*(u8 **)(v + 0x2F8), 1);
    *(u16 *)(*(u8 **)(v + 0x2FC) + 0x34) |= 0x41;
    *(u16 *)(*(u8 **)(v + 0x2FC) + 0x34) &= ~0x1000;
    *(s32 *)(*(u8 **)(v + 0x2FC) + 0x98) = 0;
    func_L01_004AA7E8(*(u8 **)(v + 0x2FC), 1);
    for (i = 3; i >= 0; i--) {
        D_L20_001E2640[i] = 0;
    }
    func_0038CF68(&D_L20_002A2940[0][0], obj + 0xC0, D_L20_001DEBF8);
    D_L20_001E2600[0] = *(vu0_v4 *)(obj + 0xE0);
    func_0038CF68(&D_L20_002A2940[1][0], obj + 0xD0, D_L20_001DEBF8);
    D_L20_001E2610 = *(vu0_v4 *)(obj + 0xC0);
    func_0038CF68(&D_L20_002A2940[2][0], obj + 0xE0, D_L20_001DEBF8);
    D_L20_001E2620 = *(vu0_v4 *)(obj + 0xD0);
    __asm__ __volatile__(
        "lqc2 $vf2, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, 0(%0)\n\t"
        : : "r"(&D_L20_002A2940[3][0]), "r"(obj + 0xC0), "r"(obj + 0xD0)
        : "vf1", "vf2", "memory");
    func_0038CF68(&D_L20_002A2940[3][0], &D_L20_002A2940[3][0], D_L20_001DEBF8);
    func_0038CE90(&D_L20_001E2630, &D_L20_002A2940[3][0], obj + 0xD0);
    if (*(s32 *)(v + 0x614) != -1) {
        m = D_L20_001E029C + (*(s32 *)(v + 0x614) << 8);
        *(u8 **)(v + 0x618) = m;
        *(u16 *)(m + 0x34) |= 0x41;
    }
    if (*(s32 *)(v + 0x678) != -1) {
        m = D_L20_001E029C + (*(s32 *)(v + 0x678) << 8);
        *(u8 **)(v + 0x67C) = m;
        *(u16 *)(m + 0x34) |= 0x41;
    }
    v[0x170] = 0x23;
    v[0x1A8] = 3;
    v[0x1D7] = 1;
    v[0x1DB] = 255;
    v[0x1D8] = 0;
    v[0x1D9] = 0;
    v[0x1DA] = 0;
    *(f32 *)(v + 0x190) = 0.5f;
    *(f32 *)(v + 0x194) = 0.5f;
    *(f32 *)(v + 0x74) = 0.5f;
    *(f32 *)(v + 0x19C) = 0.15f;
    *(s32 *)(v + 0x218) = 1;
    *(f32 *)(v + 0x70) = 0.7f;
    *(f32 *)(v + 0x78) = 1.0f;
    *(f32 *)(v + 0x7C) = 2.0f;
    *(f32 *)(v + 0x80) = 1.5533431f;
    *(f32 *)(v + 0xA0) = 0.34906584f;
    *(f32 *)(v + 0x9C) = 0.00392f;
    func_L01_0045BD78(obj, 1, 255, 1, D_L20_001DEBC0 * 0.00040000002f,
        D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
    v[0x58] = 20;
    v[0x5A] = 14;
    if (*(s16 *)(v + 0x34) == 0) {
        *(s16 *)(v + 0x34) = 2000;
        *(f32 *)(v + 0x30) = 2000.0f;
    }
    if (v[0x44] == 0) {
        v[0x46] = 60;
        v[0x44] = 60;
        v[0x45] = 60;
    }
    if (func_L01_0041A4F0() != 0) {
        *(s16 *)(v + 0x34) = 32000;
        *(f32 *)(v + 0x30) = 32000.0f;
    }
    if (D_L20_001D67A8 == 5 || D_L20_001D67A8 == 6) {
        *(s16 *)(v + 0x34) = (s32)(*(s16 *)(v + 0x34) * 0.9f);
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
    } else if (D_L20_001D67A8 == 7) {
        *(s16 *)(v + 0x34) = (s32)(*(s16 *)(v + 0x34) * 0.8f);
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
    } else if (D_L20_001D67A8 == 8) {
        *(s16 *)(v + 0x34) = (s32)(*(s16 *)(v + 0x34) * 0.75f);
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
    } else if (D_L20_001D67A8 >= 9) {
        *(s16 *)(v + 0x34) = (s32)(*(s16 *)(v + 0x34) * 0.5f);
        *(f32 *)(v + 0x30) = *(s16 *)(v + 0x34);
    }
    *(s32 *)(v + 0x650) = *(s16 *)(v + 0x34);
    *(s32 *)(v + 0x620) = (s32)(*(s16 *)(v + 0x34) * 0.75f);
    *(s32 *)(v + 0x628) = (s32)(*(s16 *)(v + 0x34) * 0.25f);
    *(s32 *)(v + 0x624) = (s32)(*(s16 *)(v + 0x34) * 0.5f);
    *(f32 *)(v + 0x40) = 2.0f;
    v[0x3F] = 0;
    v[0x64] = 0;
    v[0x39] = 1;
    v[0x3E] = 3;
    *(s32 *)(v + 0x5CC) = 1;
    func_L01_004450F0(obj, 2, 0);
    if (obj[0x43] != 0) {
        func_003C3A10(obj, 0, 0, 0);
    }
    return 0;
}
