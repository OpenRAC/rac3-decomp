/* near miss (level 3, Starship Phoenix): 24 differences with the file's flags (check.py --no-context at level 3; 74 at the start of round 12, 240 in the first note). Round 12 (2026-11-18): the byte D_001D5590[0] read as `(&D_001D5588)[8]` from a scalar with `.extern D_001D5588, 16`: gcc emits the assembler macro `lbu $v0,D_001D5588+8`, expanded in place (`lui $v0; lbu $v0,lo($v0)`) like retail, with the previous block's `addiu $v0,$s7,lo(D_001426E0)` in the beqz delay slot (74 -> 24). Left: ONLY the register order of p and the loop pointer q (retail: q = $s2, p = $s3, `lui/addiu $s2` for the pointer after the loop constants 1 and 2; here p = $s2, q = $s3 and the pointer is built before `i = 0`). Cause (-dg dump): the global allocator takes p (13 uses over 240 insns) just ahead of q (7 uses over 41 insns); dropping ONE use of p puts p behind q and behind the constants' pseudos (q $s2, then $s3 for the &D_001426E0 pseudo, p $s4), so q > p > &D_001426E0 needs a margin of one reference. Tried: array indexing D_001D5550[i] (111: no pointer giv is made, `addu` per read), i = 0 and q = ... in either order, q declared first, a sized D_001D5550[16], `++p->f68` in the condition, `q[0]`, `*q && *q`. */
#include "common.h"

/* localdecomp:start func_L03_00322160 */
typedef struct S_00322160 {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 pad20[0x24];
    s32 f44;
    s32 f48;
    s32 f4C;
    s32 f50;
    u8 pad54[0x10];
    s32 f64;
    u16 f68;
} S_00322160;

typedef struct A_00322160 {
    u8 pad0[0x68];
    S_00322160 *f68;
} A_00322160;

extern s32 D_00142C10[];
__asm__(".extern D_00142C10, 16");
extern u8 D_001426E0[];
__asm__(".extern D_001426E0, 16");
extern s16 D_001426A0[];
__asm__(".extern D_001426A0, 16");
typedef struct G_00322160 {
    u8 pad0[0x30]; u16 f30; u8 pad32[0x16]; u16 f48; u8 pad4A[0xA]; u16 f54;
    u8 pad56[0xA]; u16 f60; u8 pad62[0x2E]; u16 f90; u8 pad92[0xA]; u16 f9C; u8 pad9E[0xA]; u16 fA8;
    u8 padAA[0x156]; u32 f200; u8 pad204[0x630]; u16 f834;
} G_00322160;
extern G_00322160 D_001A7E18;
extern u16 D_001A7D00[];
__asm__(".extern D_001A7D00, 16");
extern u8 D_001A4C60[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001D554F;
__asm__(".extern D_001D554F, 16");
extern u8 D_001D5550[];
__asm__(".extern D_001D5550, 16");
extern u8 D_001D5588;
__asm__(".extern D_001D5588, 16");
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_0041BE28(s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_0039EF28(void);

void func_L03_00322160(void *arg) {
    A_00322160 *a = arg;
    S_00322160 *p = a->f68;
    s32 i;
    u8 *q;

    if (D_00142C10[0] & 0x10000) {
        p->f68++;
        if ((s16)p->f68 >= 0x2EF) {
            if (!(D_001A7E18.f200 & (1 << D_001D545C)) && D_001A7D00[0] == 0) {
                func_L01_0041A5B0(0xB87, 0x2A);
            }
        }
        if (D_001A7E18.f90 == 0 && D_001D554F == 0) {
            if (func_00382380(D_001A4C60, p->f10, 0)) func_L01_0041A5B0(0xA1F, 0xC);
        }
        if (D_001A7E18.fA8 == 0) {
            if (func_00382380(D_001A4C60, p->f48, 0)) func_L01_0041A5B0(0xA21, 0xE);
        }
    }
    if (D_001A7E18.f834 == 0) {
        if (func_00382380(D_001A4C60, p->f44, 0)) func_L01_0041A5B0(0xEF5, 0xAF);
    }
    if (D_001A7E18.f9C == 0) {
        if (func_00382380(D_001A4C60, p->f8, 0)) func_L01_0041A5B0(0xA20, 0xD);
    }
    if (D_001A7E18.f54 == 0) {
        if (func_00382380(D_001A4C60, p->f14, 0)) func_L01_0041A5B0(0xA1A, 7);
    }
    if (D_001A7E18.f48 == 0) {
        if (func_00382380(D_001A4C60, p->f18, 0)) func_L01_0041A5B0(0xA19, 6);
    }
    if (D_001A7E18.f30 == 0) {
        if (func_00382380(D_001A4C60, p->f1C, 0)) func_L01_0041A5B0(0xA17, 4);
    }
    if (func_00382380(D_001A4C60, p->f50, 0)) {
        q = D_001D5550;
        for (i = 0; i < 3; i++, q++) {
            s32 u = (u32)i < 8;
            if ((!u || (((D_001426E0[0x76] >> i) ^ 1) & 1)) && *q) {
                switch (i) {
                case 0:
                    break;
                case 1:
                    func_L01_0041A5B0(0x1602, 0x136);
                    break;
                case 2:
                    func_L01_0041A5B0(0x1603, 0x137);
                    break;
                }
                if (u) D_001426E0[0x76] |= 1 << i;
                func_0039EF28();
            }
        }
    }
    if ((D_001426E0[0x3E] & 8) && !(D_001426E0[0x75] & 8) && D_001426A0[0] < 3) {
        if ((&D_001D5588)[8]) {
            if (func_00382380(D_001A4C60, p->f4C, 0)) {
                D_001426E0[0x75] |= 8;
                func_0039EF28();
                func_L01_0041A5B0(0xC9A, 0x5D);
                func_L01_0041BE28(0x15FB, 0x132);
            }
        }
    }
    if (D_001426E0[9]) {
        if (D_001A7E18.f60 == 0) {
            if (func_00382380(D_001A4C60, p->f64, 0)) func_L01_0041A5B0(0xA1B, 8);
        }
    }
}
/* localdecomp:end func_L03_00322160 */
