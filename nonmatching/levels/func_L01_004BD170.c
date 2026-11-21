/* PAL near miss (sonnet-b30-j1, round 19): 12 words differ with the file's flags plus `@ps2as` (the function builds 1.0f / 1.1f with
 * lui/mtc1, so it also needs a cut: a file of its own at 0x4BD170 with `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as`, 8-aligned).
 * What differs: (1) the three quad loads of `D_L01_001E29D0.rest = D_L01_001E0FA0` come in another register order (ours: src base $v1,
 * dst base $a0, first `lq $a2, 0xe0($s0)`; retail: src $a0, dst $v1, first `lq $v0, 0($a0)`), 10 words, all register names; (2) one word: at
 * the `D_001D54D0` compare retail has `beq ...; nop` where the copy of the join's first insn (`lhu` of D_001D54D2) fills the slot in mine
 * (as `lui` with an array declaration, as a $gp `lhu` with `.extern X, 16`). Things that fixed 201 -> 12: the gp size hints on
 * every $gp slot, `tbl` as a struct of `s32 v[5]` (alignment 4: ldl/ldr + lw), the destination of the 3-quad copy written as
 * `*(Q3 *)(&D.q + 1) = ...` (retail's `addiu $t0, $v1, 0x10`), and a fresh `u8 *p = D_00142660;` pointer at each of the three uses (retail keeps
 * `addiu x, $s0, 0x2660` + displacement 0x40/0x78 instead of folding 0x40 into the address).
 * Check: python tools/check.py nonmatching/levels/func_L01_004BD170.c func_L01_004BD170 --as ps2as
 */
#include "common.h"
/* localdecomp:start func_L01_004BD170 */
typedef int u128_004BD170 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x34]; u16 h34; } Obj_004BD170;
typedef struct {
    s32 f0;
    u8 p4[0x24];
    Obj_004BD170 *f28;
    u8 p2C[0x24];
    s32 f50;
    u8 p54[0xC];
    s32 f60;
    u8 p64[4];
    s32 f68;
    u8 p6C[0x20];
    s32 f8C;
    s32 f90;
    u8 p94[0x4C];
    u128_004BD170 qE0;
    u8 pF0[0x678];
    s32 f768;
    s32 f76C;
} G_004BD170;
typedef struct { u128_004BD170 q0; u128_004BD170 q1; u128_004BD170 q2; } Q3_004BD170;
typedef struct { u128_004BD170 q; Q3_004BD170 rest; } Q4_004BD170;
typedef struct { s32 v[5]; } Tbl_004BD170;
typedef struct { u8 p0[0x10]; s32 f10; } In_004BD170;
typedef struct { u8 p0[0x24]; In_004BD170 *f24; u8 p28[0x70]; s32 f98; } Obj2_004BD170;
typedef struct { Obj2_004BD170 *f0; u8 p4[0x14]; s32 f18; u8 p1C[0x14]; s32 f30; } Hit_004BD170;
extern G_004BD170 D_L01_002446C0_004BD170;
extern u8 D_L01_001DABA4;
extern u8 D_001D5477;
extern s32 D_L01_001E0F80;
extern s32 D_L01_001E0F7C;
extern Q3_004BD170 D_L01_001E0FA0;
extern Q4_004BD170 D_L01_001E29D0;
extern s32 D_L01_001E0FD4;
extern s32 D_L01_001E0FD8;
extern s32 D_L01_001E0FDC;
extern s32 D_L01_001E0FE0;
extern s32 D_L01_001E0FE4;
extern s32 D_L01_001E0FE8;
extern f32 D_L01_001DAC54;
extern f32 D_L01_001DAC58;
extern s32 D_L01_001DAC50;
extern s32 D_L01_001D7BE0;
extern s32 D_L01_001DABA8;
extern s32 D_L01_001DABCC;
extern u8 D_L01_001DABC8;
extern s32 D_L01_001DABD0;
extern s32 D_L01_001DABD4;
extern Tbl_004BD170 D_L01_001DAD18;
extern u8 D_00142660[];
extern s16 D_001426A0[];
extern Hit_004BD170 D_L01_0016C580;
extern u32 D_001D54D0;
extern u16 D_001D54D2;
__asm__(".extern D_001D54D2, 16");
extern void func_L01_004BF980(void);
extern void func_L01_00479280(void);
extern s32 func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern void func_003A9050(void);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern s32 func_00381FF0(s32);
extern void func_L01_00436660(s32, s32, s32);
extern void func_00398BB8(s32);
extern void func_00398C80(s32);
extern void func_003A56F8(s32);
extern void func_0039EC28(s32, s32);
__asm__(".extern D_L01_001DABA4, 1");
__asm__(".extern D_L01_001DAC54, 4");
__asm__(".extern D_L01_001DAC58, 4");
__asm__(".extern D_L01_001DAC50, 4");
__asm__(".extern D_L01_001D7BE0, 4");
__asm__(".extern D_L01_001DABA8, 4");
__asm__(".extern D_L01_001DABCC, 4");
__asm__(".extern D_L01_001DABC8, 1");
__asm__(".extern D_L01_001DABD0, 4");
__asm__(".extern D_L01_001DABD4, 4");
__asm__(".extern D_L01_001E0FE8, 4");

void func_L01_004BD170(void) {
    Tbl_004BD170 tbl;
    s32 n;
    s32 k;

    D_001D5477 = D_L01_001DABA4;
    D_L01_002446C0_004BD170.f8C = 0;
    D_L01_002446C0_004BD170.f90 = 0;
    func_L01_004BF980();
    if (D_L01_001E0F80 != 0) {
        return;
    }
    func_L01_00479280();
    func_L01_0047B420();
    func_L01_0047B990();
    func_003A9050();
    D_L01_001E0F7C = 0;
    func_003A52A0(5, 0x11, D_L01_002446C0_004BD170.f28);
    if (D_L01_002446C0_004BD170.f60 != 0) {
        D_L01_001E29D0.q = D_L01_002446C0_004BD170.qE0;
        *(Q3_004BD170 *)(&D_L01_001E29D0.q + 1) = D_L01_001E0FA0;
    }
    D_L01_002446C0_004BD170.f28->h34 |= 0x100;
    D_L01_002446C0_004BD170.f0 = 2;
    D_L01_001DAC54 = 1.0f;
    D_L01_001DAC58 = 1.1f;
    D_L01_001E0FD4 = 0x41;
    D_L01_001E0FD8 = 0x60;
    D_L01_001E0FDC = 0x46;
    D_L01_001DAC50 = 0;
    D_L01_001E0FE0 = 0;
    D_L01_001E0FE4 = 0;
    D_L01_001E0FE8 = 0;
    if (D_L01_002446C0_004BD170.f50 == 5) {
        D_L01_001D7BE0 = D_L01_001DABA8;
        func_L01_005147A8(D_L01_001DABCC);
        func_L01_00425978(D_001426A0[0]);
    } else if (D_L01_002446C0_004BD170.f50 == 3) {
        {
            u8 *p1 = D_00142660;
            *(u16 *)(p1 + 0x40) = D_L01_001DABC8 ? *(u16 *)&D_L01_001DABD0 : *(u16 *)&D_L01_001DABD4;
        }
        {
            u8 *p2 = D_00142660;
            *(s32 *)(p2 + 0x78) = D_L01_001DABC8 ? D_L01_001DABD0 : D_L01_001DABD4;
        }
        D_L01_002446C0_004BD170.f768 = D_L01_001DABC8 ? D_L01_001DABD0 : 0;
        func_L01_00425978(D_L01_001DABD4);
        tbl = D_L01_001DAD18;
        if (D_L01_001DABC8 != 0) {
            {
                u8 *p3 = D_00142660;
                func_L01_00436660(func_00381FF0(tbl.v[*(s16 *)(p3 + 0x40)]), -1, 0);
            }
        }
    }
    if (D_L01_002446C0_004BD170.f50 == 2) {
        n = D_001D54D0;
        if (D_L01_0016C580.f18 != n) {
            func_00398BB8(n & 3);
        }
        k = D_001D54D2 & 0x1F;
        if (D_L01_0016C580.f30 != k) {
            func_00398C80(k);
        }
        if (D_L01_0016C580.f0 != 0 && D_L01_0016C580.f0->f98 != 0) {
            D_L01_0016C580.f0->f98 = D_L01_0016C580.f0->f24->f10;
        }
        func_003A56F8(0);
    }
    if ((D_L01_002446C0_004BD170.f50 == 2 && D_L01_002446C0_004BD170.f76C > 0) || (D_L01_002446C0_004BD170.f50 == 3 && D_L01_002446C0_004BD170.f768 > 0) || (D_L01_002446C0_004BD170.f50 == 0 && D_L01_002446C0_004BD170.f68 > 0) || (D_L01_002446C0_004BD170.f50 == 5 && D_L01_001DABC8 != 0)) {
        func_0039EC28(0, -1);
    }
}
/* localdecomp:end func_L01_004BD170 */
