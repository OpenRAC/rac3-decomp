/* func_L20_003D65D0: near miss, 218 diff (was 252 / 302 under @ps2as) in src/levels/20_final_boss/L20_003D61B8.c, the boss's
   init. Needs the file's line to gain `-mvu0-use-vf0-vf2` and `@ps2as` (retail builds every float constant inline with
   lui/ori/mtc1; the default assembler loads them from the literal pool) and the file's first block
   (func_L20_003D61B8) to be rechecked with them. Under @ps2as every small-data scalar needs
   `__asm__(".extern X, 4");` BEFORE its first use, including D_L20_001DEBEC (declared in the first block) and
   D_L20_001E029C, D_L20_001DEBB0/B4/B8/BC/C0/F0/F4/F8 here; measured with those hints in front of the file.
   What took it from 302 to 218 (round 12):
   - the VU0 add as `vec_add_ab(&D_L20_002A2940[3][0], obj + 0xC0, obj + 0xE0)` (a hand-written asm block used
     "r" operands and the wrong vector: retail's lqc2 are $vf2 <- obj+0xE0, $vf1 <- obj+0xC0 with $s5 as the base);
   - obj + 0xD0 and obj + 0xE0 as named locals set right after the first func_0038CF68 call (vb, vc): retail keeps
     them in $s3/$s1 across the next calls, which also gives its 6 saved registers (frame 0x50; without them 0x40);
   - the D_L20_001E2640 clear as a pointer loop (`zp = &D_L20_001E2640[3]; for (i = 3; ...) *zp-- = 0;`), retail's
     lui + addiu 0x264c.
   Left (218, mostly two groups): (1) the three `sw $zero, ...($gp)` stores (D_L20_001DEBEC/F0/F4) are interleaved with
   the following `lw 0x2f8($s4)` / `lhu` chain in retail and sit together here; (2) the long run of constant stores
   after the 0x614/0x678 blocks: retail keeps them in source order (sb stores, then the float stores) and builds the
   call arguments of func_L01_0045BD78 first; here the scheduler reorders them (0.5f hoisted first, sb stores
   scattered); also the two `lw 0x614/0x678($s4)` blocks have $v0/$v1 swapped. Measured with check.py --as ps2as
   --flags=-mvu0-use-vf0-vf2 and a scratch file made of the real file's block plus this one. */
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
    s32 *zp;
    u8 *m;
    u8 *vb;
    u8 *vc;
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
    zp = &D_L20_001E2640[3];
    for (i = 3; i >= 0; i--) {
        *zp-- = 0;
    }
    func_0038CF68(&D_L20_002A2940[0][0], obj + 0xC0, D_L20_001DEBF8);
    vb = obj + 0xD0;
    vc = obj + 0xE0;
    D_L20_001E2600[0] = *(vu0_v4 *)(obj + 0xE0);
    func_0038CF68(&D_L20_002A2940[1][0], vb, D_L20_001DEBF8);
    D_L20_001E2610 = *(vu0_v4 *)(obj + 0xC0);
    func_0038CF68(&D_L20_002A2940[2][0], vc, D_L20_001DEBF8);
    D_L20_001E2620 = *(vu0_v4 *)(obj + 0xD0);
    vec_add_ab(&D_L20_002A2940[3][0], obj + 0xC0, obj + 0xE0);
    func_0038CF68(&D_L20_002A2940[3][0], &D_L20_002A2940[3][0], D_L20_001DEBF8);
    func_0038CE90(&D_L20_001E2630, &D_L20_002A2940[3][0], vb);
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

INCLUDE_ASM("asm/levels", func_L20_003D65D0);
