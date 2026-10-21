#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C4C18(f32 *v, f32 r);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003C4B40 */
s32 func_003C4B40(s32 arg0) {
    return (u32)(arg0 - 500) < 41;
}
/* localdecomp:end func_003C4B40 */

/* localdecomp:start func_003C4B50 */
extern s32 func_003C4B40_003C4B50(s16);
extern u32 D_001DA49C[];
extern u32 D_001DA4A4[];
s32 func_003C4B50(u32 arg0) {
    if (arg0 == 0) return 0;
    if (arg0 < D_001DA49C[0]) return 0;
    if (D_001DA4A4[0] >= arg0) {
        return func_003C4B40_003C4B50(*(s16 *)((u8 *)arg0 + 0xAA)) != 0;
    }
    return 0;
}
/* localdecomp:end func_003C4B50 */

LINKER_REMNANT("asm/remnants", func_003C4BA0);

/* localdecomp:start func_003C4BB0 */
extern f32 func_0038CEA8(s32 a);
extern void func_0038CF68(s32 a, s32 b, f32 x);
void func_003C4BB0(s32 a, f32 x) {
    if (x < func_0038CEA8(a)) func_0038CF68(a, a, x);
}
/* localdecomp:end func_003C4BB0 */

LINKER_REMNANT("asm/remnants", func_003C4C00);

/* localdecomp:start func_003C4C18 */
extern f32 func_003824E0(f32, f32);
void func_003C4C18(f32 *v, f32 r) {
    v[0] += func_003824E0(-r, r);
    v[1] += func_003824E0(-r, r);
    v[2] += func_003824E0(-r, r);
}
/* localdecomp:end func_003C4C18 */

LINKER_REMNANT("asm/remnants", func_003C4C98);

/* localdecomp:start func_003C4CE8 */
extern void func_0038CF68(s32 a, s32 b, f32 x);
void func_003C4CE8(void *a, f32 f) {
    f32 r;
    ((void (*)(void *, f32))func_0038CF68)(a, f);
    r = 1.0f - f * f;
    __asm__("nop\n\tnop\n\tsqrt.s %0, %1" : "=f"(r) : "f"(r));
    *(f32*)((u8*)a + 0xC) = r;
}
/* localdecomp:end func_003C4CE8 */

LINKER_REMNANT("asm/remnants", func_003C4D38);

/* localdecomp:start func_003C4D58 */
int func_003C4D58(unsigned char *object) {
    unsigned char *link;
    int flags;

    if (object != 0)
        goto check_flags;
failure:
    return 0;
check_flags:
    flags = *(unsigned short *)(object + 0x34) & 0x20;
    __asm__ volatile(".word 0");
    if (flags == 0)
        goto failure;
    link = *(unsigned char **)(object + 0x68);
    if (link == 0)
        goto failure;
    return *(int *)(link + 8);
}
/* localdecomp:end func_003C4D58 */

LINKER_REMNANT("asm/remnants", func_003C4D90);

/* localdecomp:start func_003C4DA8 */
typedef int u128_3BF838 __attribute__((mode(TI)));
typedef struct { u128_3BF838 r[4]; } M_3BF838;
extern void func_0038D328();
extern void func_0038D5B0();
extern void func_0038D640();
extern void func_003C48A8();
void func_003C4DA8(u8 *p, u128_3BF838 *a1, u128_3BF838 *a2, void *a3) {
    M_3BF838 m0, m1, m2, m3;
    func_0038D328(&m0, a2);
    func_0038D5B0(&m1, &m0);
    func_0038D328(&m2, a3);
    func_0038D640(&m3, &m1, &m2);
    func_003C48A8(&m3, p);
    if (*(s32 *)(p + 0x3C) & 2) {
        *(u128_3BF838 *)(p + 0x20) = *a2;
    }
    *(u128_3BF838 *)(p + 0x10) = *a1;
}
/* localdecomp:end func_003C4DA8 */

LINKER_REMNANT("asm/remnants", func_003C4E68);

extern s32 func_0038D058(f32 *);
INCLUDE_ASM("asm/nonmatchings/text", func_003C4E80);

INCLUDE_ASM("asm/nonmatchings/text", func_003C4F88);

/* localdecomp:start func_003C5060 */
typedef struct { u8 pad[0x40]; } M_3BFAF8;
void func_0038D5B0(M_3BFAF8 *, void *);
void func_0038D000(void *, void *, M_3BFAF8 *);
void func_003C5060(u8 *a, void *b, void *c, M_3BFAF8 *d) {
M_3BFAF8 m; if (d == 0) { func_0038D5B0(&m, a + 0xC0); func_0038D000(b, c, &m); } else { func_0038D000(b, c, d); }
}
/* localdecomp:end func_003C5060 */

LINKER_REMNANT("asm/remnants", func_003C50C8);

/* localdecomp:start func_003C50E8 */
f32 func_003C50E8(s32 a, s32 b, s32 c) {
    f32 v[4];
    func_003C5060(a, v, b, c);
    return v[2];
}
/* localdecomp:end func_003C50E8 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038CE20(f32 *, void *, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C5110);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5180;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *, void *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C5180);

/* localdecomp:start func_003C5250 */
extern void func_003C5180(void *);
 
void func_003C5250(void *p) {
    func_003C5180((u8 *)p + 0x10);
}
/* localdecomp:end func_003C5250 */

LINKER_REMNANT("asm/remnants", func_003C5270);

/* localdecomp:start func_003C5278 */
extern s32 D_001D5BEC[];
extern void func_003C5180_003C5278();
extern void func_0038CF68(s32, s32, f32);
void func_003C5278(void *a0, f32 *out, f32 *in, f32 f) {
    f32 v[4];
    if (D_001D5BEC[0] == 0) {
        out[2] = in[2] - f;
    } else {
        func_003C5180_003C5278(a0, v, 0);
        func_0038CF68((s32)v, (s32)v, f);
        __asm__ __volatile__(
            "lqc2 $vf1, 0(%1)\n"
            "lqc2 $vf2, 0(%2)\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, 0(%0)\n"
            : : "r"(out), "r"(in), "r"(v) : "memory");
    }
}
/* localdecomp:end func_003C5278 */

/* localdecomp:start func_003C52F8 */
extern void func_003C5278_003C52F8(void *);
 
void func_003C52F8(void *p) {
    func_003C5278_003C52F8((u8 *)p + 0x10);
}
/* localdecomp:end func_003C52F8 */

LINKER_REMNANT("asm/remnants", func_003C5318);

/* localdecomp:start func_003C5320 */
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5370(s32, f32 *, s32);
void func_003C5320(s32 a, s32 b, s32 c) {
    f32 buf[4];
    ((void (*)(f32 *, f32))func_0038CE20)(buf, -1.0f);
    func_003C5370(a, buf, c);
}
/* localdecomp:end func_003C5320 */

extern void func_0038CE90(f32 *, f32 *, s32);
extern void func_0038D810(f32 *, f32 *);
extern void func_0038D5F0(s32, f32 *, s32);
extern void func_0038CC88(s32, f32 *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C5370);

LINKER_REMNANT("asm/remnants", func_003C5448);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5458);

INCLUDE_ASM("asm/nonmatchings/text", func_003C5620);

typedef int Q_3BFEF0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BFEF0;
typedef struct { f32 m[4][4]; s32 c[4]; f32 uv[8]; long gs[4]; } P_3BFEF0;
extern V_3BFEF0 D_00222400;
extern f32 D_001D9180[2];
extern void func_0038D028();
extern void func_003D2DA0();
typedef struct {
    u8 p0[7]; u8 f7; u8 p8[9]; u8 f11; u8 f12; u8 p13; u8 f14; u8 p15; u8 f16; u8 f17; u8 p18[4];
    f32 f1C; f32 f20; f32 f24; f32 f28; f32 f2C; f32 f30; f32 f34; u16 f38; u8 p3A[0x12];
    f32 f4C; f32 f50; f32 f54; u8 p58[8]; f32 f60; f32 f64; u8 p68[4]; s8 f6C; s8 f6D; s8 f6E; s8 f6F;
    u8 p70[2]; s8 f72; s8 f73; u8 p74[2]; u8 f76; u8 p77; u8 f78; u8 f79; u8 f7A; u8 p7B[5];
    f32 f80; f32 f84; f32 f88; u8 p8C[4]; f32 f90; f32 f94;
} E_3C0188;
typedef struct { u8 p0[0x1C]; f32 *f1C; } T_3C0188;
typedef struct {
    u8 p0[0x34]; u16 f34; u8 p36[0xE]; f32 f44; u8 p48[4]; f32 f4C; u8 p50[0x18]; T_3C0188 *f68; u8 p6C[0x2C]; s32 f98;
} O_3C0188;
extern s32 D_001D5BEC_003C56E0;
extern void func_003C4E80(void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003C6368(void *, f32 *, f32 *, f32, f32, f32);
extern f32 func_0038CED8(f32 *);
extern s32 func_003C6068();
extern void func_003C62C8();
extern f32 func_0038D160(f32, f32);
extern void func_0038DAB8(f32, f32);
extern void func_0038CFB8(void);
typedef struct { f32 x, y, z, w; } V4_3C0188;
typedef int Q_3C0188 __attribute__((mode(TI)));
INCLUDE_ASM("asm/nonmatchings/text", func_003C56E0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CA60);

typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_00382468();
extern f32 func_003824E0(f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003C6068);

typedef struct { u8 pad[0x48]; void *a[1]; } S_3C0D70;
INCLUDE_ASM("asm/nonmatchings/text", func_003C62C8);
