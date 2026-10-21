#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_00387268(void);
extern void func_00387F68(void);
extern void func_00388138(void);
/* --- end of declarations from other files --- */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_37E0F0;
typedef int Q_37E0F0 __attribute__((mode(TI)));
extern u8 *D_001D9A20;
extern void func_0038D000_00382380(void *, void *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_00382380);

/* localdecomp:start func_00382468 */
extern s32 func_0013D3E0(void);
s32 func_00382468(s32 a) {
    return func_0013D3E0() % a;
}
/* localdecomp:end func_00382468 */

/* localdecomp:start func_00382498 */
extern s32 func_0013D3E0(void);
s32 func_00382498(s32 lo, s32 hi) {
    return func_0013D3E0() % (hi - lo + 1) + lo;
}
/* localdecomp:end func_00382498 */

/* localdecomp:start func_003824E0 */
extern s32 func_13D3E0(void);
f32 func_003824E0(f32 a, f32 b) {
    return a + (f32)func_13D3E0() * (b - a) * (1.0f / 32768.0f);
}
/* localdecomp:end func_003824E0 */

extern s32 func_0013D3E0(void);
INCLUDE_ASM("asm/nonmatchings/text", func_00382538);

/* localdecomp:start func_00382580 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
void func_00382580(s32 a, f32 x, f32 y) {
    f32 p = func_00382538();
    f32 q = func_00382538();
    func_00382760(a, func_003824E0(x, y), p, q);
}
/* localdecomp:end func_00382580 */

INCLUDE_ASM("asm/nonmatchings/text", func_003825F8);

extern s32 D_001D9A28_0037E368[2];
extern s32 D_001D9A30_0037E368[2];
extern s32 D_001D9D08_0037E368;
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);

/* localdecomp:start func_00382760 */
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_00382760(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = func_0038D098(fparg2);
    (*(f32 *)((u8 *)(arg0) + 0)) = (f32) (func_0038D098(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 4)) = (f32) (func_0038D0B0(fparg1) * fparg0 * temp_f22);
    (*(f32 *)((u8 *)(arg0) + 8)) = (f32) (func_0038D0B0(fparg2) * fparg0);
}
/* localdecomp:end func_00382760 */

LINKER_REMNANT("asm/remnants", func_003827F0);

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; u16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E568;
extern E_0037E568 D_00222480_00382810[];
INCLUDE_ASM("asm/nonmatchings/text", func_00382810);

typedef struct { u8 pad[0x424]; f32 f424; f32 f428; f32 f42C; f32 f430; f32 f434; u8 b438; u8 b439; s16 h43A; f32 f43C; f32 f440; u8 pad2[0x1C]; } E_0037E630;
extern E_0037E630 D_00222480_003828D8[];
extern f32 D_002259B0[];
extern s32 func_0038CB00(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003873C0();
INCLUDE_ASM("asm/nonmatchings/text", func_003828D8);

LINKER_REMNANT("asm/remnants", func_00382A70);

/* localdecomp:start func_00382A80 */
void func_0038CD28(void *, void *, s32);
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_0037E7D8;
extern S_00222500_0037E7D8 D_00222480[];
extern u8 D_00224B10[];
extern u8 D_00225450[];

void func_00382A80(s32 arg0) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s2;

    temp_s2 = (arg0 * 0xB0) + D_00224B10;
    { S_00222500_0037E7D8 *p = &D_00222480[arg0]; func_0038CD28(temp_s2, p->f50, 0xB0); }
    temp_s1 = arg0 * 0x780;
    temp_s0 = temp_s1 + D_00225450;
    func_0038CD28(temp_s0, temp_s1 + (D_00225450 - 0x500), 0x280);
    (*(void **)((u8 *)(temp_s2) + 0x70)) = temp_s0;
}
/* localdecomp:end func_00382A80 */
TEXT_PADDING(2);

extern s32 D_001D9A80[2];
extern void (*D_001D9A40[2])(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00382B20);

INCLUDE_ASM("asm/nonmatchings/text", func_00382BC8);

/* localdecomp:start func_00382C58 */
extern void func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
void func_00382C58(f32 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f0;
    f32 var_f16;

    var_f16 = fparg4;
    temp_f0 = func_0038DB00(fparg1, fparg0);
    temp_f1 = *arg0;
    temp_f1_2 = temp_f1 + ((fparg2 * temp_f0) - (fparg3 * temp_f1));
    *arg0 = temp_f1_2;
    if (var_f16 != 0.0f) {
        if (var_f16 < temp_f1_2) {
            *arg0 = var_f16;
        } else {
            f32 n = -var_f16;
            if (temp_f1_2 < n) {
                *arg0 = n;
            }
        }
    }
    temp_f1_3 = *arg0;
    __asm__("abs.s %0, %1" : "=f"(var_f0) : "f"(temp_f0));
    if ((var_f0 < temp_f1_3) || (var_f0 = -var_f0, (temp_f1_3 < var_f0))) {
        *arg0 = var_f0;
    }
    func_0038DAB8(fparg0, *arg0);
}
/* localdecomp:end func_00382C58 */

LINKER_REMNANT("asm/remnants", func_00382D40);

/* localdecomp:start func_00382D48 */
s32 func_00381D78(void *, s32, s32, s32);           /* extern */
extern void func_003C2880(s32 p);
extern u8 D_002224E0[];

void func_00382D48(s32 arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_a2;
    void *temp_s0;

    temp_a2 = arg0 * 0x460;
    temp_s0 = temp_a2 + D_002224E0;
    if ((*(s16 *)((u8 *)(arg1) + 0x86)) == 0) {
        if ((*(s32 *)((u8 *)(temp_s0) + 0xC4)) == 0) {
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = func_00381D78(temp_a2 + (D_002224E0 - 0x60), arg0, temp_a2, arg0);
        }
    } else {
        temp_a0 = (*(s32 *)((u8 *)(temp_s0) + 0xC4));
        if (temp_a0 != 0) {
            func_003C2880(temp_a0);
            (*(s32 *)((u8 *)(temp_s0) + 0xC4)) = 0;
        }
    }
}
/* localdecomp:end func_00382D48 */
TEXT_PADDING(2);

/* localdecomp:start func_00382DC8 */
typedef struct { s32 a, b, c, d, e; } S_37D000;
extern S_37D000 D_00380F80[];
void func_00382DC8(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].c;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_00382DC8 */

typedef int u128_37EB68 __attribute__((mode(TI)));
typedef struct { u8 p0[0x2B8]; f32 f2B8; u8 p2BC[0xC]; f32 f2C8; u8 p2CC[0x58]; s32 f324; u8 p328[0x138]; } E_37EB68;
extern E_37EB68 D_00222480_00382E10[];
extern u8 *D_001D9A84;
extern u8 D_002251D0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00382E10);

typedef struct { u8 p0[0xC]; s32 fC; u8 p10[0x24 - 0x10]; s32 f24; } T_37EE80;
typedef struct { u8 p0[0x1C]; T_37EE80 *f1C; } R_37EE80;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0x5E0 - 0x5D4]; s32 f5E0; u8 p5E4[0x690 - 0x5E4]; s32 f690; u8 p694[0x6A0 - 0x694]; s32 f6A0; u8 p6A4[0x25CC - 0x6A4]; s32 f25CC; } A_37EE80;
typedef struct { u8 p0[0x24C]; s32 f24C; u8 p250[0x460 - 0x250]; } E_37EE80;
extern u8 *D_001D9A84_00383128;
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } G2_37EE80;
extern G2_37EE80 *D_001D9E50;
extern A_37EE80 D_001A4BE0_00383128;
extern E_37EE80 D_00222480_00383128[];
extern u8 D_002225D0[];
extern s32 func_00382380(void *, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00383128);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C000);

/* localdecomp:start func_00383338 */
extern S_37D000 D_00380F80[];
void func_00383338(u8 *p) {
    void (*f)(u8 *) = (void (*)(u8 *))D_00380F80[*(s16 *)(p + 0x8C)].e;
    if (f != 0) {
        f(p);
    }
}
/* localdecomp:end func_00383338 */

extern u8 D_00222A10_00383380[];
extern u8 D_001D9B10_00383380[8];
extern s32 func_00383128(s32, u8 *, u8 *);
extern void func_00382E10(u8 *, s32);
extern void func_00382B20(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00383380);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F228;
typedef int Q_37F228 __attribute__((mode(TI)));
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D0C8(f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(s32 a, s32 b, f32 x);
INCLUDE_ASM("asm/nonmatchings/text", func_003834D0);

/* localdecomp:start func_003836C8 */
typedef int u128_37F420 __attribute__((mode(TI)));
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern void func_003834D0();
extern u8 D_00222480_003836C8[];
void func_003836C8(s32 idx) {
    u128_37F420 v[3];
    u8 *p = D_00222480_003836C8 + idx * 0x460;
    u8 *q = p + 0x150;
    func_0038CF68((s32)&v[0], *(s32 *)(q + 0xF0) + 0xC0, 1.0f);
    func_0038CF68((s32)&v[1], *(s32 *)(q + 0xF0) + 0xD0, 1.0f);
    func_0038CF68((s32)&v[2], *(s32 *)(q + 0xF0) + 0xE0, 1.0f);
    *(u128_37F420 *)(p + 0x330) = v[0];
    *(u128_37F420 *)(p + 0x340) = v[2];
    func_003834D0(p + 0x310, p + 0x360, p + 0x190, &v[0], &v[1], &v[2]);
    *(u128_37F420 *)(p + 0x350) = *(u128_37F420 *)(p + 0x370);
}
/* localdecomp:end func_003836C8 */

/* localdecomp:start func_003837A0 */
typedef int u128_37F4F8 __attribute__((mode(TI)));
typedef struct { u8 p0[2]; u8 b2; u8 b3; u8 p4[0x50 - 4]; u128_37F4F8 q50; u128_37F4F8 q60; u8 p70[0xC0 - 0x70]; u128_37F4F8 qC0; u128_37F4F8 qD0; u8 pE0[0x460 - 0xE0]; } E_37F4F8;
extern E_37F4F8 D_00222720_003837A0[];
void func_003837A0(s32 idx) {
    s32 off = idx * 0x460;
    E_37F4F8 *e = (E_37F4F8 *)((u8 *)D_00222720_003837A0 + off);
    u8 *b;
    if (e->b2 == 0) {
        e->qC0 = e->q50;
        if (e->b3 == 2) {
            b = (u8 *)D_00222720_003837A0 - 0xE0;
            __asm__ __volatile__("lqc2 $vf2, 0xC0(%0)" : : "r"(e));
            __asm__ __volatile__("lqc2 $vf1, 0(%0)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0xC0(%1)" : : "r"((u8 *)(off + (s32)b)), "r"(e) : "memory");
        }
        e->qD0 = e->q60;
    }
}
/* localdecomp:end func_003837A0 */

/* localdecomp:start func_003837F8 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_00222720[];
void func_003837F8(s32 arg0) {
    u8 *p = D_00222720 + arg0 * 0x460;
    if (p[2] != 0) {
        *(u128_t *)(p + 0x50) = *(u128_t *)(p + 0xC0);
        *(u128_t *)(p + 0x60) = *(u128_t *)(p + 0xD0);
    }
}
/* localdecomp:end func_003837F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_00383830);

INCLUDE_ASM("asm/nonmatchings/text", func_00383A68);

typedef struct { f32 f0, f4, f8, fC, f10, f14, f18, f1C; } A_37F588;
typedef struct { s32 p0[3]; s32 fC; f32 f10; s32 f14; } R_37F588;
typedef struct {
    s16 f0; u8 b2; u8 b3; u8 p4[0xC]; A_37F588 a; u128_t q30; u128_t q40; u128_t q50; u128_t q60; R_37F588 r;
} E_37F588;
extern u8 D_00222480_0037F588[];
extern void func_003C47E8();
typedef int Q_37F7A8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_37F7A8;
typedef struct { f32 f0, f4; u8 p8[8]; f32 f10, f14; u8 p18[8]; V_37F7A8 v20; V_37F7A8 v30; u128_t q40; u8 m50[0x40]; } B_37F7A8;
typedef struct { u8 p0[0x30]; f32 f30, f34, f38; u8 p3C[0x94 - 0x3C]; s32 f94; } O_37F7A8;
typedef struct { u128_t q0; u8 p10[0x1C0 - 0x10]; V_37F7A8 v1C0; u8 p1D0[0x380 - 0x1D0]; u8 m380[0x40]; u8 p3C0[0x460 - 0x3C0]; } E_37F7A8;
extern E_37F7A8 D_00222480_0037F7A8[];
extern void func_003C47E8(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_0038D6C8_0037F7A8(void *, void *, void *, f32);
extern void func_0038D830_0037F7A8(void *, void *);
extern f32 func_003C3BE8(f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00383C48);

extern u8 D_00222720[];
extern u8 D_00222480_003841B8[];
extern s32 func_00383C48();
INCLUDE_ASM("asm/nonmatchings/text", func_003841B8);

INCLUDE_ASM("asm/nonmatchings/text", func_00384260);

typedef struct { u8 p0[0x86]; s16 h86; } P_37FF90;
typedef struct { u8 p0[0x50]; P_37FF90 *p50; u8 p54[0x380 - 0x54]; u8 v380[0x20]; u8 v3A0[0x460 - 0x3A0]; } E_37FF90;
typedef struct { f32 f0, f4; s32 f8, fC; } A_37FF90;
extern E_37FF90 D_00222480_0037FF90[];
extern f32 D_001D57B4;
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4CE8_0037FF90(void *, void *, f32);
extern void func_0038D810_0037FF90(void *, void *);
extern void func_0038D5F0_0037FF90(void *, void *, void *);
typedef int Q_3801C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3801C0;
typedef union { V_3801C0 v; u128_t q; f32 f[4]; } U_3801C0;
typedef struct { u8 p0[0x86]; s16 h86; } P_3801C0;
typedef struct {
    f32 f0, f4, f8, fC;
    f32 f10[4];
    U_3801C0 u20;
    u128_t q30;
    u128_t q40;
    U_3801C0 u50;
    U_3801C0 u60;
    V_3801C0 v70;
    V_3801C0 v80;
    u128_t q90;
    f32 fA0, fA4, fA8;
    f32 fAC[5];
    u8 pC0[0x30];
} B_3801C0;
typedef struct {
    u8 p0[0x40];
    U_3801C0 u40;
    u8 p50[8];
    f32 f58;
    u8 p5C[0x24];
    V_3801C0 v80;
    u8 p90[0x6C];
    s32 iFC;
    s32 i100;
    u8 p104[0x460 - 0x150 - 0x104];
} A_3801C0;
typedef struct {
    u8 p0[0x50];
    P_3801C0 *f50;
    u8 p54[0xC];
    B_3801C0 b;
    A_3801C0 a;
} E_3801C0;
extern f32 D_001D57B8, D_001D57BC, D_001D57C4;
extern E_3801C0 D_00222480_00384498[];
extern void func_0038CE20(f32 *, void *, f32);
extern f32 func_00382BC8(f32 *, f32, f32, f32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00384498);

typedef struct { f32 x, y, z, w; } V_3804A0;
typedef union { u128_t q; V_3804A0 v; } Q_3804A0;
typedef struct { Q_3804A0 q0; u8 pad10[0x40]; u8 *f50; u8 pad54[0x3FC]; s32 f450; u8 pad454[0xC]; } E_3804A0;
extern E_3804A0 D_00222480_00384778[];
extern s32 D_001D5B94;
extern u128_t D_00227660[];
extern s32 func_003D3CB0();
extern s32 func_003D5630(void);
extern f32 func_003C3EC8_00384778(void *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00384778);

typedef struct { u8 p0[8]; f32 f8; u8 pC[0x460 - 0xC]; } E_00380600;
typedef struct { u8 p0[0x40]; f32 f40, f44; u8 p48[0x100 - 0x48]; s32 f100, f104; u8 p108[0x118 - 0x108]; f32 f118; u8 p11C[0x12E - 0x11C]; u8 b12E, b12F, b130, b131, b132; } R_00380600;
typedef struct { u8 p0[0xC0]; s32 fC0; } Q_00380600;
extern E_00380600 D_00222480_003848D8[];
extern s32 D_001D9A90_003848D8[2];
extern s32 D_001D9A98_003848D8[2];
extern s32 D_001D9AA0_003848D8[2];
INCLUDE_ASM("asm/nonmatchings/text", func_003848D8);
TEXT_PADDING(2);

/* localdecomp:start func_00384AC8 */
extern f32 D_001D9BD0_00384AC8; __asm__(".extern D_001D9BD0_00384AC8, 16");
typedef struct { u8 pad[0xC8]; f32 fC8; f32 fCC; u8 fD0[0x460 - 0xD0]; } S_3807F0;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CAD0(void *);
void func_00384AC8(s32 a) {
    S_3807F0 *s = (S_3807F0 *)(D_002224E0 + a * 0x460);
    if (s->fC8 != 0.0f) {
        func_003C4138(&D_001D9BD0_00384AC8 + a, s->fCC, s->fC8);
        if ((&D_001D9BD0_00384AC8)[a] == s->fCC) {
            if (func_0038CAD0(s->fD0) == 1) {
                s->fCC = 0.0f;
            }
        }
        if (s->fCC <= 0.0f && (&D_001D9BD0_00384AC8)[a] <= 0.0f) {
            s->fC8 = 0.0f;
        }
    }
}
/* localdecomp:end func_00384AC8 */
TEXT_PADDING(2);

/* localdecomp:start func_00384BB8 */
extern f32 D_001D9BD8_00384BB8; __asm__(".extern D_001D9BD8_00384BB8, 16");
typedef struct { u8 pad[0xD4]; f32 fD4; f32 fD8; f32 fDC; u8 fE0[0x460 - 0xE0]; } S_3808E0;
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_0038CAD0(void *);
void func_00384BB8(s32 a) {
    S_3808E0 *s = (S_3808E0 *)(D_002224E0 + a * 0x460);
    if (s->fD4 != 0.0f) {
        if (s->fDC != 0.0f) {
            func_003C4138(&D_001D9BD8_00384BB8 + a, s->fDC, s->fD4);
        } else {
            func_003C4138(&D_001D9BD8_00384BB8 + a, s->fDC, s->fD8);
        }
        if ((&D_001D9BD8_00384BB8)[a] == s->fDC) {
            if (func_0038CAD0(s->fE0) == 1) {
                s->fDC = 0.0f;
            }
        }
        if (s->fDC <= 0.0f && (&D_001D9BD8_00384BB8)[a] <= 0.0f) {
            s->fD4 = 0.0f;
        }
    }
}
/* localdecomp:end func_00384BB8 */

/* localdecomp:start func_00384CC8 */
typedef struct { u128_t q0; u128_t q1; u8 pad[0x360]; f32 f380[4]; f32 f390[4]; f32 f3a0[4]; f32 f3b0[4]; f32 f3c0[4]; f32 f3d0[4]; u128_t q3e0; u8 pad2[0x70]; } E_003809F0;
extern E_003809F0 D_00222480_00384CC8[];
extern u128_t D_00222400[];
extern void func_0038CD28();
void func_00384CC8(s32 idx) {
    E_003809F0 *e = &D_00222480_00384CC8[idx];
    u128_t v;
    e->f3b0[0] = -e->f390[0];
    e->f3c0[0] = -e->f390[1];
    e->f3d0[0] = -e->f390[2];
    e->f3b0[1] = -e->f3a0[0];
    e->f3c0[1] = -e->f3a0[1];
    e->f3d0[1] = -e->f3a0[2];
    e->f3b0[2] = e->f380[0];
    e->f3c0[2] = e->f380[1];
    e->f3d0[2] = e->f380[2];
    v = e->q0;
    e->q3e0 = v;
    D_00222400[0] = v;
    D_00222400[1] = D_00222480_00384CC8[idx].q1;
    func_0038CD28(&D_00222400[2], D_00222480_00384CC8[idx].f380, 0x30);
}
/* localdecomp:end func_00384CC8 */

extern u8 D_00222480_0037F588[];
extern u8 *D_001D9B40[2];
extern s32 D_001D9B00[2];
extern s32 D_001D5B98;
extern s32 D_001D90B8;
extern s32 D_001D90B0;
extern void func_003848D8(s32);
extern void func_00384498(s32, s32);
extern void func_00383380(s32);
extern void func_003C48A8();
extern void func_00385EF0();
extern void func_003828D8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00384D88);
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_00385000);

typedef struct { u8 p0[0x10]; u8 pos[0x10]; u8 b20; } O_380D48;
typedef struct {
    O_380D48 *obj; s32 state; f32 f8; s32 pC;
    s16 h10[16]; s16 h30[16]; s32 c50[16]; f32 f90[16]; f32 fD0[16];
} S_380D48;
extern S_380D48 D_00222900;
extern s32 D_001D4BC8_00385020, D_001D4BCC_00385020, D_001D4BD0_00385020, D_001D4BD4_00385020;
extern f32 func_0038CF00(void *, void *);
extern void func_003860A8(f32 *, void *);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
INCLUDE_ASM("asm/nonmatchings/text", func_00385020);

typedef struct {
    u8 p0[0x10]; f32 f10; s32 f14; s32 f18; f32 f1C; u8 p20[6]; s16 h26; f32 f28; s32 f2C;
    u8 p30[8]; f32 f38; f32 f3C;
} S_3810C0;
extern void func_0038BCD8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
/* localdecomp:start func_00385398 */
void func_00385398(S_3810C0 *o, f32 x, f32 y) {
    long tex;
    f32 w, h, a;
    f32 p[4], q[4];
    s32 i;
    if (o == 0) return;
    w = o->f38;
    h = o->f3C;
    tex = func_00389598(o->f18);
    a = o->f1C;
    switch (o->f2C) {
    case 0:
        for (i = 0; i < o->h26; i++) {
            func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
            a = ((f32 (*)(f32, f32))func_0038DAB8)(a, o->f28);
        }
        break;
    case 1:
        p[0] = h * func_0038D0B0(a) * o->f10;
        p[1] = h * func_0038D098(a) * o->f10;
        q[0] = w * func_0038D098(a) * o->f10;
        q[1] = -w * func_0038D0B0(a) * o->f10;
        func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.0f, 0.0f);
        func_0038BCD8(x + q[0], y + q[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 0, 0.0f, 0.0f);
        func_0038BCD8(x - p[0], y - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 1, 0.0f, 0.0f);
        func_0038BCD8(x + q[0] - p[0], y + q[1] - p[1], w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 1, 1, 0.0f, 0.0f);
        break;
    case 2:
        func_0038BCD8(x, y, w * o->f10, h * o->f10, a, 0x3F, 0x3F, tex, 0xFFFFF3, o->f14, 0, 0, 0.5f, 0.5f);
        break;
    }
}
/* localdecomp:end func_00385398 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3813E0;
typedef int Q_3813E0 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0x1430];
    s32 f1430;
    u8 p1434[0x2C];
    u8 *f1460;
    f32 f1464;
    f32 f1468;
} S_3813E0;
typedef struct { f32 f0; s16 h4; u8 p6[0xA]; f32 f10; } P_3813E0;
extern S_3813E0 D_001A4BE0;
extern f32 D_001D57C8, D_001D57CC, D_001D57D0, D_001D57D4, D_001D5804, D_001D5808, D_001D5830, D_001D5834;
extern s32 D_001D57D8, D_001D57E8;
extern f32 D_001D57F8;
extern s32 D_001D580C, D_001D5810, D_001D5814, D_001D5818, D_001D581C, D_001D5820, D_001D5824, D_001D5828, D_001D582C;
extern s32 D_001D4BD0_003856B8, D_001D4BD4_003856B8;
extern P_3813E0 *func_00382348(u8 *);
extern void func_003860A8(f32 *, void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038BCD8(f32, f32, f32, f32, f32, s32, s32, long, s32, s32, s32, s32, f32, f32);
extern void func_0038C500(s32, s32, s32, s32, s32 *, s32 *, s32, s32, f32, f32);
extern long func_00389598(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003856B8);

LINKER_REMNANT("asm/remnants", func_00385D20);

typedef struct { u8 p0[0x20]; u8 b20; } H_381A50;
typedef struct { u8 p0[0x10]; f32 f10; u8 p14[0xC]; H_381A50 *f20; u8 b24; u8 b25; u8 p26[0xA]; f32 f30, f34; u8 p38[8]; } E_381A50;
typedef struct { E_381A50 e[14]; s32 n; } T_381A50;
extern T_381A50 D_00224BC0_00385D28;
extern s32 D_001A71A4_00385D28[];
extern s32 D_001D5B98;
extern s32 D_001D4BC0_00385D28, D_001D4BC4_00385D28, D_001D4BD0_00385D28, D_001D4BD4_00385D28;
extern void func_003856B8(void);
extern void func_003860A8(f32 *, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_00385D28);

/* PAL candidate for func_00385EF0 (frontbin).
 *
 * Started from the US draft (rac3-uya-decomp func_00381C18, commit 13cf5c5). The US
 * matched it only with @ps2as; here the file's own flags must produce the retail bytes.
 *
 * The seven globals are written through literal addresses: retail reaches them with
 * `lui`/`%lo` (they are not small data, so a sized `extern u8`/`extern f32` would give
 * gcc's `$gp` form), and a constant address is rematerialised at each store
 * (`lui $at, %hi(addr)` + `sb`/`swc1` `%lo(addr)($at)`), which is exactly retail's shape.
 */

/* localdecomp:start func_00385EF0 */
typedef struct {
    u8 p0[0x50];
    s32 f50;
    s32 c0;
    s32 c1;
    f32 f5C, f60, f64, f68;
    f32 f6C, f70, f74, f78;
    u8 p7C[4];
} R_381C18;
extern R_381C18 D_002FE200[];
extern s32 func_003CCE20_00385EF0(void *, f32 *, s32 *);

void func_00385EF0(void *pos) {
    f32 t;
    s32 idx;
    R_381C18 *r;
    u32 w1, w0;
    s32 c0, c1;
    f32 u;
    u32 a, b;
    u32 r1, r0, g1, g0, b1, b0;
    f32 p6C, p5C, p74, p64, p70, p60, p78, p68;

    if (func_003CCE20_00385EF0(pos, &t, &idx) == 0) {
        return;
    }
    r = &D_002FE200[idx];
    if (!(r->f50 & 2)) {
        return;
    }
    w1 = (s32)(t * 255.0f);
    w0 = 255 - w1;
    u = 1.0f - t;
    c1 = r->c1;
    c0 = r->c0;
    r1 = (c1 & 0xFF) * w1;
    g1 = ((c1 >> 8) & 0xFF) * w1;
    b1 = (c1 >> 16) & 0xFF;
    r0 = (c0 & 0xFF) * w0;
    g0 = ((c0 >> 8) & 0xFF) * w0;
    b0 = (c0 >> 16) & 0xFF;
    p6C = r->f6C * t;
    p5C = r->f5C * u;
    p74 = r->f74 * t;
    p64 = r->f64 * u;
    p70 = r->f70 * t;
    p60 = r->f60 * u;
    p78 = r->f78 * t;
    p68 = r->f68 * u;
    a = (s32)(r1 + r0) >> 8;
    b = (s32)(g1 + g0) >> 8;
    *(u8 *)0x001D9C46 = (s32)(b1 * w1 + b0 * w0) >> 8;
    *(u8 *)0x001D9C44 = a;
    *(u8 *)0x001D9C45 = b;
    *(f32 *)0x001D9C48 = (p6C + p5C) * 1024.0f;
    *(f32 *)0x001D9C4C = (p74 + p64) * 1024.0f;
    *(f32 *)0x001D9C50 = 255.0f - (p70 + p60) * 255.0f;
    *(f32 *)0x001D9C54 = 255.0f - (p78 + p68) * 255.0f;
}
/* localdecomp:end func_00385EF0 */

LINKER_REMNANT("asm/remnants", func_00386068);

typedef struct { u8 p0[0x140]; f32 f140, f144, f148; } S_222340_381DD0;
typedef struct { u8 p0[0x1A0]; f32 f1A0, f1A4; u8 p1A8[0x220 - 0x1A8]; f32 f220; } S_225980_381DD0;
extern S_222340_381DD0 D_002222C0_003860A8;
extern S_225980_381DD0 D_00225900_003860A8;
extern void func_0038D2A0();
extern void func_0038D640();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028();
INCLUDE_ASM("asm/nonmatchings/text", func_003860A8);

LINKER_REMNANT("asm/remnants", func_003861E8);

typedef struct { f32 x, y, z, w; } V_381F18;
typedef union { u128_t q; V_381F18 v; } Q_381F18;
extern u8 D_002222C0_003861F0[];
extern u8 D_00225900_003861F0[];
extern u8 D_00225B80[];
extern u8 D_001D5477_003861F0;
extern void func_0038CE90();
extern void func_0038CE50_003861F0(void *, void *, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003861F0);

typedef struct { u8 pad[0x450]; s32 f450; } E_3821E8;
extern u8 D_00222480_003864C0[];
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_3821E8;
extern S_3821E8 D_00225900;
extern u8 D_001D99AC, D_001D99AD, D_001D99AE, D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D99C4, D_001D99C8, D_001D99CC, D_001D99D0, D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 D_001DA5D0, D_001D9C58;
extern void func_003873C0();
INCLUDE_ASM("asm/nonmatchings/text", func_003864C0);

extern u8 *D_001D9D40[];
INCLUDE_ASM("asm/nonmatchings/text", func_003865A0);

/* localdecomp:start func_00386678 */
extern s32 func_003865A0();
void func_00386678(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 fparg0) {
    s32 var_4;
    s32 var_5;
    s32 var_6;

    if (fparg0 < 0.5f) {
        if (((s32 (*)())func_003865A0)() == 0) {
            var_4 = arg3;
            var_5 = arg4;
            var_6 = arg5;
            goto block_5;
        }
    } else if (((s32 (*)())func_003865A0)(arg3, arg4, arg5) == 0) {
        var_4 = arg0;
        var_5 = arg1;
        var_6 = arg2;
block_5:
        ((s32 (*)())func_003865A0)(var_4, var_5, var_6);
    }
}
/* localdecomp:end func_00386678 */

typedef struct { u8 pad[0x140]; f32 x, y, z; } S_382458;
typedef struct { f32 x, y, z, w; u8 d[1][0x80]; } G_382458;
extern S_382458 D_002222C0;
extern G_382458 *D_001D9D44, *D_001D9D48, *D_001D9D4C;
extern u8 *D_001D9D60[2];
extern s32 D_001D9D58;
extern s32 D_001D9D50_00386730;
extern s32 D_001D52F0;
extern u8 D_00227500[];
extern s32 D_00227480[];
extern void func_0038CB78();
extern void func_0038CBA0();
extern void func_0038CD50();
extern f32 func_0038CF38();
extern f32 func_0038D160(f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_00386730);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C020);

extern s32 func_00386730();
extern void func_0038CB78();
extern s32 D_001D9D54;
extern s32 D_00227480[];
INCLUDE_ASM("asm/nonmatchings/text", func_00387218);

typedef struct { u8 p0[0x150]; u16 f150, f152; } C_00382F90;
extern C_00382F90 D_001CFEC0_00387268;
typedef struct {
    u8 p0[0xA0]; f32 fA0; f32 fA4; u8 pA8[8]; f32 fB0;
    u8 pB4[0x1A0 - 0xB4]; f32 f1A0; f32 f1A4;
    u8 p1A8[0x210 - 0x1A8]; f32 f210; f32 f214; f32 f218; f32 f21C;
    u8 p220[8]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C;
    s32 f240; s32 f244; s32 f248; s32 f24C; u8 p250[0x18]; s32 f268;
} S_00382F90;
extern S_00382F90 D_00225900_00387268;
extern s32 D_001D4BC0_00387268, D_001D4BC4_00387268, D_001D4BC8_00387268, D_001D4BCC_00387268;
extern s32 D_001D4BD0_00387268, D_001D4BD4_00387268, D_001D4BD8_00387268, D_001D4BDC_00387268;
INCLUDE_ASM("asm/nonmatchings/text", func_00387268);

INCLUDE_ASM("asm/nonmatchings/text", func_003873C0);

INCLUDE_ASM("asm/nonmatchings/text", func_00387B18);

LINKER_REMNANT("asm/remnants", func_00387EE8);

/* PAL: func_00387EF0 zeroes a set of globals.  Retail reaches the twelve
   word-sized ones through an absolute address (lui $at, %hi(X) +
   sw $zero, %lo(X)($at)), which is what gcc emits for a literal address
   (the assembler expands it); a named symbol would be split by gcc itself
   into lui $reg / sw %lo($reg) with a register of its own.  The three bytes
   and the last word are small data and go through $gp. */

extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern s32 D_001D99A8;

/* localdecomp:start func_00387EF0 */
extern u8 D_001D5884, D_001D58C0, D_001D58D0;
extern s32 D_001D99A8;
void func_00387EF0(void) {
    *(s32 *)0x001D9C08 = 0;
    *(s32 *)0x001D9C10 = 0;
    *(s32 *)0x001D9C14 = 0;
    *(s32 *)0x001D9C0C = 0;
    *(s32 *)0x001D9C38 = 0;
    *(s32 *)0x001D9C40 = 0;
    *(s32 *)0x001D9BDC = 0;
    *(s32 *)0x001D9BE0 = 0;
    D_001D5884 = 0;
    D_001D58C0 = 0;
    D_001D58D0 = 0;
    *(s32 *)0x001D9D50 = 0;
    *(s32 *)0x001D99D4 = 0;
    *(s32 *)0x001D99D8 = 0;
    *(s32 *)0x001D99C0 = 0;
    D_001D99A8 = 0;
}
/* localdecomp:end func_00387EF0 */

extern u32 *D_001DA050_00387F68;
extern u32 *D_001DA050_g;
extern u8 D_001421B0[];
extern u8 D_00142120[];
extern long D_001D5330_00387F68[];
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C, f250, f254, f258; } S_225980_3838C0;
extern S_225980_3838C0 D_00225900_00387F68;
extern void func_0038CC88();
extern void func_003A9440(s32, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_00387F68);

/* localdecomp:start func_00388138 */
extern unsigned long D_001CFEC8[];
void func_00388138(void) {
    *(volatile unsigned long *)0x120000E0 = 0;
    *(volatile unsigned long *)0x12000000 = 0xFFA1;
    *(volatile unsigned long *)0x12000020 = D_001CFEC8[0];
    *(volatile unsigned long *)0x12000070 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000090 = D_001CFEC8[1];
    *(volatile unsigned long *)0x12000080 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000A0 = D_001CFEC8[2];
    *(volatile unsigned long *)0x120000D0 = 0;
}
/* localdecomp:end func_00388138 */

extern void func_00392440(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_00392868(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003881B0);

/* localdecomp:start func_00388238 */
extern void func_003922B8(void);
void func_00388238(void) {
    func_003922B8();
}
/* localdecomp:end func_00388238 */

INCLUDE_ASM("asm/nonmatchings/text", func_00388258);

typedef int Q_383BB0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_383BB0;
typedef struct { V_383BB0 pos[4]; s32 rgba[4]; f32 uv[4][2]; long a, tex, c, d; } P_383BB0;
typedef struct { u8 p0[0x24]; f32 f24, f28; u8 p2C[8]; f32 f34, f38; s32 f3C; } O_383BB0;
extern f32 D_001D59B0_00383BB0, D_001D59B4_00383BB0, D_001D59BC_00383BB0;
extern s32 D_001D59B8_00383BB0;
extern f32 D_001D5948_00383BB0, D_001D594C_00383BB0, D_001D5950_00383BB0, D_001D5954_00383BB0;
extern f32 D_001D5958_00383BB0, D_001D595C_00383BB0, D_001D5960_00383BB0, D_001D5964_00383BB0;
extern V_383BB0 D_00222480_00383BB0;
extern s32 func_0038CAD0(void *);
extern void func_003C4098_00383BB0(V_383BB0 *, V_383BB0, V_383BB0, f32);
extern void func_0038CE90_00383BB0(V_383BB0 *, V_383BB0, V_383BB0);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(s32 a, s32 b, f32 x);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D2DA0();
INCLUDE_ASM("asm/nonmatchings/text", func_003886B0);

LINKER_REMNANT("asm/remnants", func_00388AF0);

typedef int u128_00384420 __attribute__((mode(TI)));
typedef struct { u8 pad[0x450]; s32 x450; u8 pad454[0xC]; } P_00384420;
typedef struct { u8 pad0[4]; s16 x4; } C_00384420;
typedef struct { u128_00384420 q[4]; } Q_00384420;
extern C_00384420 *D_001DA5F0;
extern s32 D_001D9BC4;
extern s32 D_001D9D1C;
extern s32 D_001D9348;
extern s32 D_001D934C;
extern s32 D_001D9C10_00388AF8;
extern s32 D_001D9C14_00388AF8;
extern u8 D_001D58D0;
extern s32 D_001D5B94;
extern s32 D_001D9C08_00388AF8;
extern s32 D_001D9C0C_00388AF8;
extern s32 D_001D9364;
extern s32 D_001D9368;
extern s32 D_001D9C38_00388AF8;
extern volatile s32 D_001D9EC0;
extern s32 D_001D52F0;
extern P_00384420 D_00222480_00388AF8[];
extern u8 D_001D5780;
extern u8 D_001D5781;
extern u8 D_001D5782;
extern u8 D_001D5783;
extern f32 D_001D9BD0;
extern f32 D_001D9BD8[2];
extern s32 D_001D5B98;
extern u8 D_001D5884;
extern s32 D_001D58B8;
extern u8 D_100AE0[];
extern s32 D_00143950[];
extern f32 D_001D9D10;
extern s32 D_001D9D50_00388AF8;
extern u8 D_002FDC00[];
extern u8 D_003064C0[];
extern Q_00384420 D_00225AA0;
extern Q_00384420 D_00334EC0;
extern void func_00392350(s32);
extern void func_003861F0(void);
extern void func_003C2DC0(void);
extern void func_00387218(void);
extern void func_00387F68(void);
extern void func_003CF0F0(void);
extern void func_003A9C70_00388AF8(s32);
extern void func_003D9CF0(void);
extern void func_003A96D8(void);
extern void func_00389240(s32);
extern void func_00389E28(void);
extern void func_00389370(void);
extern void func_003A9678(void);
extern void func_003DEF28(void);
extern void func_0038AD40_00388AF8(u8 *);
extern void func_00389EA0(void);
extern void func_003886B0(void);
extern void func_003C3860(void);
extern void func_00389DB0(void);
extern void func_003A9440(s32, unsigned long);
extern void func_00385020(void);
extern void func_0038A058(void);
extern void func_11F0A0(s32);
extern void func_003CD3D8(void);
extern void func_00389F68(void);
extern void func_003D85C0_00388AF8(s32);
extern void func_003D8640(void);
extern void func_003D9260_00388AF8(s32);
extern void func_00389FE0(void);
extern void func_00385D28(s32);
extern void func_003926E8(void);
extern s32 func_003A0EA8(s32);
extern void func_0038A948(void);
extern void func_003A9CA8_00388AF8(s32);
extern void func_003AF660(void);
extern void func_00396838(void);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern void func_00381D60(void);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_0038ABC0(void);
extern void func_003A8F90_00388AF8(void *);
extern void func_003A92F0(s32);
extern void func_003D0180(void *);
extern void func_003CF050(void);
extern void func_003DD768(void);
extern void func_003D9C30(void);
extern void func_003E0B10(void *);
extern void func_003DEE20(void);
extern void func_003C31B0(void);
extern void func_003864C0(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00388AF8);

LINKER_REMNANT("asm/remnants", func_00389220);

extern s32 D_001D9BF4_00389240;
extern s32 D_001DA050_00389240;
extern s32 D_001D9C00;
extern long D_00226000_00389240[];
extern s32 D_001D9EA0_00389240;
extern s32 D_001D9EAC_00389240;
extern volatile s32 D_001D9EB0_00389240;
extern s32 D_001D9BFC;
extern s32 D_001D4BB4_00389240;
extern s32 D_001D4BB0_00389240;
extern unsigned long D_001D58E0, D_001D58E8;
extern s32 D_001D58F0;
extern s32 D_001A1ED0_00389240[];
extern void func_0038E138(void);
INCLUDE_ASM("asm/nonmatchings/text", func_00389240);

extern u32 *D_001DA050_00389370;
extern u32 *D_001D9BF4_00389370;
extern u32 *D_001D9BF8_00389370;
extern void func_003A02E8();
extern s32 func_003A9618_00389370();
INCLUDE_ASM("asm/nonmatchings/text", func_00389370);

INCLUDE_ASM("asm/nonmatchings/text", func_00389478);
TEXT_PADDING(2);

typedef int Q_384DA0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_384DA0;
typedef struct { u8 p0[0x220]; f32 f220; } S_225980_384DA0;
extern V4_384DA0 D_00222400_00384DA0;
extern S_225980_384DA0 D_00225900_00384DA0;
extern s32 D_001D4BC0_00384DA0, D_001D4BC4_00384DA0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D028();

LINKER_REMNANT("asm/remnants", func_00389588);

typedef struct { unsigned long v; u16 h8; u16 hA; u8 bC; u8 bD; s16 hE; } T_384EC0;
typedef struct { s32 w0; s16 h4; s16 h6; s32 w8; u8 bC; u8 bD; s16 hE; } C_384EC0;
extern T_384EC0 D_00226000[];
extern C_384EC0 D_00225C00[];
extern s32 D_001A1ED0[];
extern s32 D_001D4BB0;
extern s32 D_001D9BFC;
extern s32 D_001D9C04;
extern unsigned long D_001D58E0;
extern unsigned long D_001D58E8;
extern s32 D_001D58F0;
extern u32 *D_001DA050_00389598[1];
extern u8 D_141AD0[];
extern u8 D_141DC0[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389598);

extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003353C0[];
extern u8 D_00335430[];
extern void func_0038CC88();
extern void func_003A9618();
INCLUDE_ASM("asm/nonmatchings/text", func_00389B10);

extern s32 D_001D4BB0;
extern s32 D_001DA050;
extern u8 D_003354A0[];
extern u8 D_00335510[];
extern void func_0038CC88();
extern void func_003A9618();
INCLUDE_ASM("asm/nonmatchings/text", func_00389C48);

INCLUDE_ASM("asm/nonmatchings/text", func_00389D00);

extern s32 D_001D9C08_00389D60;
extern s32 D_00226800_00389D60[];
extern s32 D_00226900[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389D60);

extern s32 D_001D9C08_00389DB0;
extern void (*D_00226800[])(s32);
extern s32 D_00226900[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389DB0);

extern s32 D_001D9C10_00389E28;
extern void (*D_00226C00[])(s32);
extern s32 D_00226D00[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389E28);

extern s32 D_001D9C14_00389EA0;
extern void (*D_00226E00[])(s32);
extern s32 D_00226F00[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389EA0);

extern s32 D_001D9C0C_00389F18;
extern s32 D_00226B00[];
extern s32 D_00226A00_00389F18[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389F18);

/* PAL candidate for func_00389F68 (frontbin).
   Retail reaches the counter global D_001D9C0C through lui/lw, not through $gp.
   The counter is a small scalar, so gcc addresses it gp-relative; the .extern
   size hint (16 bytes) tells the assembler the global is not small data, so the
   gp-relative macro expands to retail's lui/lw pair (the same pattern the
   matched func_003932C0 uses for D_001D9E98). */

/* localdecomp:start func_00389F68 */
__asm__(".extern D_001D9C0C_00389F68, 16");
extern s32 D_001D9C0C_00389F68;
extern void (*D_00226A00[])(s32);
extern s32 D_00226B00[];
void func_00389F68(void) {
    s32 i;
    for (i = 0; i < D_001D9C0C_00389F68; i++) D_00226A00[i](D_00226B00[i]);
}
/* localdecomp:end func_00389F68 */

extern int D_001D9C38_00389FE0;
extern void (*D_001D9C18[])(int);
extern int D_001D9C28[];
INCLUDE_ASM("asm/nonmatchings/text", func_00389FE0);

typedef struct { f32 x, y, z, w; } V_385980;
typedef union { u128_t q; V_385980 v; } Q_385980;
typedef struct { f32 x, y, u, v; } T_385980;
typedef struct { Q_385980 v[4]; s32 col[4]; f32 uv[4][2]; long f70, f78, f80, f88; } S_385980;
extern long func_00389598(s32);
extern void func_003D2DA0();
extern s32 D_001D5900[2];
extern s32 D_001D9C40_0038A058;
extern Q_385980 D_00227010[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038A058);

extern u32 *D_001DA050_0038A238;
extern u32 *D_001DA050_g;
extern s32 D_001D9BC8_g;
extern s32 D_001D9BC8_0038A238;
extern u8 D_00141990[];
extern void func_003A92F0(s32);
extern s32 func_12C908(s32);
extern void func_003A9108(void);
extern void func_003A91D0(void);
extern void func_003A9150();
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_003A9440(s32, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_0038A238);

extern s32 D_001D4D40_0038A3B8;
extern s32 D_00225734_0038A3B8[];
extern s32 D_001D55E8_0038A3B8;
extern s32 D_00143950[];
extern f32 func_0038D098(f32);
extern void func_0038DBD8(s32, s32, f32);
extern void func_0038E150(s32);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0038A3B8(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038A3B8);

INCLUDE_ASM("asm/nonmatchings/text", func_0038A518);

extern s32 D_001D9BE0_0038A948;
extern s32 D_001D9BDC_0038A948;
extern s32 D_001D4BD0_0038A948;
extern s32 D_001D4BD4_0038A948;
extern s32 D_001D4BD8;
extern s32 D_001D4BDC;
extern u8 D_001439FD[];
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038A948);

typedef struct { s32 f0; u32 f4; unsigned long f8; s32 f10; u32 f14; unsigned long f18; s32 f20; u32 f24; unsigned long f28; } P_00386488;
extern P_00386488 *D_001D58B8_0038ABC0;
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
typedef struct { u8 p0[0x150]; s16 f150, f152; } C_00386488;
extern C_00386488 D_001CFEC0_0038ABC0;
INCLUDE_ASM("asm/nonmatchings/text", func_0038ABC0);

extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern s32 D_001A1ED0[];
extern s16 D_001CFEC0[];
typedef struct { s32 f0; u32 f4; unsigned long f8; } S;
INCLUDE_ASM("asm/nonmatchings/text", func_0038AD40);

extern u32 *D_001DA050_0038AE20;
extern u8 D_00141850[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038AE20);

extern s32 D_001D4BD0_0038AF30;
extern s32 D_001D4BD4_0038AF30;
extern u8 D_001D76A0[];
extern u8 D_001D76B0[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038AF30);

LINKER_REMNANT("asm/remnants", func_0038B118);

typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA050;
extern Q_3869E8 D_001D76C0_0038B120[];
extern s32 D_001D4BD0_0038B120, D_001D4BD4_0038B120;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038B120);

extern s32 D_001D4BD0_0038B4D0;
extern s32 D_001D4BD4_0038B4D0;
extern u8 D_001D76C0[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038B4D0);

LINKER_REMNANT("asm/remnants", func_0038B660);

extern s32 D_001D4BD0_0038B670, D_001D4BD4_0038B670;
extern s32 D_001DA050;
INCLUDE_ASM("asm/nonmatchings/text", func_0038B670);

extern s32 D_001D4BD0_0038B850, D_001D4BD4_0038B850;
extern s32 D_001DA050;
INCLUDE_ASM("asm/nonmatchings/text", func_0038B850);

extern s32 D_001D4BD0_0038BA30;
extern s32 D_001D4BD4_0038BA30;
INCLUDE_ASM("asm/nonmatchings/text", func_0038BA30);

typedef int Q_3875A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3875A0;
extern s32 D_001D4BD0_0038BCD8;
extern s32 D_001D4BD4_0038BCD8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(f32 *, void *, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038BCD8);

typedef int u128_387A00 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7770[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038C138);

typedef int u128_387B10 __attribute__((mode(TI)));
extern s32 D_001DA050;
extern u8 D_001D7740[];
INCLUDE_ASM("asm/nonmatchings/text", func_0038C248);

extern s32 D_001D4BD0[];
extern s32 D_001D4BD4[];
extern void func_0038C248(unsigned long *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038C310);

/* localdecomp:start func_0038C3B0 */
void func_0038C3B0(s32 x, s32 y, s32 w, s32 z, s32 a, s32 b) {
    s32 c = (a << 24) | b;
    func_0038AF30(x, y, w, z, c);
    func_0038AF30(x + 1, y - 1, w - 2, w, c);
    func_0038AF30(x + 2, y - 2, w - 3, w - 2, c);
    func_0038AF30(x + 4, y - 4, w - 4, w - 3, c);
    func_0038AF30(x + 1, y - 1, z, z + 2, c);
    func_0038AF30(x + 2, y - 2, z + 2, z + 3, c);
    func_0038AF30(x + 4, y - 4, z + 3, z + 4, c);
}
/* localdecomp:end func_0038C3B0 */

LINKER_REMNANT("asm/remnants", func_0038C4F0);

typedef struct { f32 x, y, z, w; } V_387DC8;
extern void func_0038C138(long *, s32 *, s32 *, long, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038C500);
TEXT_PADDING(2);

typedef struct { u8 p0[0x190]; u128_t q190; u128_t q1A0; u8 p1B0[0x70]; f32 f220; u8 p224[0x14]; f32 f238; f32 f23C; s32 f240; s32 f244; s32 f248; s32 f24C; } S_388018;
extern f32 D_001D5880;
extern s32 D_001D9D1C;
extern S_388018 D_00225900_0038C750;
extern long D_001D5330[];
extern u8 D_0010F500[];
extern void func_0038D2D0_0038C750(f32 *, f32);
extern u16 D_0010F4F0[];
extern void func_003A9338(s32, u32);
extern void func_003A9740(void);
INCLUDE_ASM("asm/nonmatchings/text", func_0038C750);

LINKER_REMNANT("asm/remnants", func_0038C990);

/* localdecomp:start func_0038C9B0 */
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);
extern s32 D_001A1ED8[];
void func_0038C9B0(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_0038C9B0 */
