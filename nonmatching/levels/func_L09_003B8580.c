/* func_L09_003B8580: near miss (Opus, 2026-11-08, two passes). Tyhrranosis boss update: a phase switch on +0x95
   (10 cases), the moby state switch on +0x20 (states 2-23) and a sub-state switch on +0xBC (1-14),
   13,784 bytes, one place (level 09), file src/levels/09_tyhrranosis/L09_003B8580.c. No rac1/rac2/rac4
   twin; written from retail (replaces the Sonnet m2c draft that was here).
   Needs `-mvu0-use-vf0-vf2 ... @ps2as` on the file's line (vec_add/vec_sub from include/vu0.h; the
   float constants are built inline); the file's two C functions (func_L09_003BD860, func_L09_003BF2F8)
   still match with it.
   Measured with the stock checker: 3446 of 3446 instructions; aligned, 98.4% of opcodes equal retail
   (93.6% of lines, relocated immediates counted as different). The frame (0x120) and every stack slot
   match.
   Solved (2026-11-08, second Opus pass): the %hi of D_L09_0021CDA0 that retail keeps in $s6 across the
   moby-group loops. GCSE gives every (high sym) one function-wide pseudo; ours lost $s6 to the
   function-wide (high D_L09_001D66B0) pseudo, which retail never has: retail passes D_L09_001D66B0 as
   one la (adjacent lui/addiu in the argument register), so its declaration is section(".sdata")
   (docs/build/globals.md). The four .lit floats D_L09_001DE6E0..EC are read through $gp once their
   .extern sizes come first.
   What still differs, in order of effect:
   1. The .lit vectors D_L09_001DE6A0/6B0/6D0 (16 bytes) are addressed through $gp in retail
      (addiu $r, $gp, 0x1DF0/0x1E00/0x1E20, lqc2 $vf2, 0x1E00($gp)), seven places. Neither assembler uses
      $gp for a 16-byte symbol under -G8 (Ps2EeAs and both GNU as give lui/addiu with section(".sdata"),
      with or without an early .extern), and stating a size of 8 would misstate the data
      (docs/build/globals.md). A literal or a static would be data in level C, which is not allowed. This
      is the blocker; each site is one instruction longer here, offset by the others below.
   2. The func_L01_00448890 calls (seven): retail loads a2's 0 last (delay slot) and mov.s $f14 before
      the jal; here mov.s $f14 fills the slot. Neither block-local pointer arguments (which fixed the
      same pattern in func_L02_003484D8) nor the int-first prototype other files use reproduces it.
   3. A few v0/v1/a0 choices (the 1 << n bit tests of D_001D545C, state 5's movz/movn pair) and the
      phase-0 loop's nop/delay-slot placement.
   What got it here: one function-level union per 16-byte stack slot (retail's vector and 8-byte
   array temporaries share slots 0x00-0x60; block-local vectors never reuse slots in this compiler);
   the 8-byte phase arrays copied from the level's .lit through `*(I2_T *)D_L09_001DE748` (gives
   retail's ldl/ldr); `(u32)(1 << n) & mask` (otherwise folded to a shift); `(u32)i < 8` inside an
   `i < 7` loop; the hD38/hD30 timers are `rand * 50.0f`; callees that return a value
   (func_L01_00448890 f32, func_L09_003CD9F0/func_L09_003CD998 s32); state 12's if/else order so
   state 11 cross-jumps into it.
   Next: casediff2.py FILE func_L09_003B8580 --jt 09_tyhrranosis:jtbl_002BF690 --cases (and
   jtbl_002BF660 / jtbl_002BF6F0). */
#include "vu0.h"


typedef struct Vec_T {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_T;

typedef union PathEnt_T {
    s32 n;
    Vec_T v;
} PathEnt_T;

typedef struct I2_T {
    s32 a;
    s32 b;
} I2_T;

typedef union VI_T {
    Vec_T v;
    I2_T i;
} VI_T;

typedef struct Moby_T Moby_T;
typedef struct Pv_T Pv_T;

typedef struct Cls_T {
    u8 pad0[0x10];
    s32 i010;
    u8 pad14[0x44 - 0x14];
    u16 H044;
} Cls_T;

struct Moby_T {
    u8 pad0[8];
    f32 f008;
    u8 padC[4];
    Vec_T pos;
    u8 b020;
    u8 pad21[2];
    u8 b023;
    Cls_T *cls;
    u8 pad28[0x34 - 0x28];
    u16 H034;
    u8 pad36[0x42 - 0x36];
    u8 b042;
    u8 b043;
    u8 pad44[0x48 - 0x44];
    f32 f048;
    u8 pad4C[0x60 - 0x4C];
    u8 b060;
    u8 pad61[0x68 - 0x61];
    Pv_T *pv;
    u8 pad6C[0x94 - 0x6C];
    u8 b094;
    u8 b095;
    u8 pad96[2];
    s32 i098;
    u8 pad9C[0xBC - 0x9C];
    u8 bBC;
    u8 padBD;
    u8 bBE;
    u8 padBF;
    u8 padC0[0xD0 - 0xC0];
    Vec_T vD0;
    u8 padE0[0x10];
    Vec_T vF0;
};

struct Pv_T {
    u8 pad0[0x30 - 0x0];
    /* 0x030 */ f32 f030;
    u8 pad34[0xD0 - 0x34];
    u8 x0D0[1];
    u8 padD1[0x12C - 0xD1];
    /* 0x12C */ f32 f12C;
    u8 pad130[0x1B4 - 0x130];
    /* 0x1B4 */ f32 f1B4;
    u8 pad1B8[0x1C4 - 0x1B8];
    /* 0x1C4 */ f32 f1C4;
    /* 0x1C8 */ s32 i1C8;
    u8 pad1CC[0x254 - 0x1CC];
    /* 0x254 */ PathEnt_T * P254;
    /* 0x258 */ s16 h258;
    /* 0x25A */ s16 h25A;
    /* 0x25C */ f32 f25C;
    u8 pad260[0xBE8 - 0x260];
    /* 0xBE8 */ f32 fBE8;
    u8 padBEC[0xC30 - 0xBEC];
    /* 0xC30 */ f32 fC30;
    u8 padC34[0xC50 - 0xC34];
    u8 xC50[1];
    u8 padC51[0xC80 - 0xC51];
    u8 xC80[1];
    u8 padC81[0xC98 - 0xC81];
    /* 0xC98 */ s32 iC98;
    u8 xC9C[1];
    u8 padC9D[0xCC8 - 0xC9D];
    /* 0xCC8 */ f32 fCC8;
    /* 0xCCC */ f32 fCCC;
    /* 0xCD0 */ s32 iCD0;
    /* 0xCD4 */ s32 iCD4;
    u8 xCD8[1];
    u8 padCD9[0xCDC - 0xCD9];
    /* 0xCDC */ f32 fCDC;
    /* 0xCE0 */ s32 iCE0;
    /* 0xCE4 */ s32 iCE4;
    /* 0xCE8 */ s32 iCE8;
    /* 0xCEC */ s32 iCEC;
    /* 0xCF0 */ s32 iCF0;
    /* 0xCF4 */ s32 iCF4;
    /* 0xCF8 */ s32 iCF8;
    /* 0xCFC */ s32 iCFC;
    /* 0xD00 */ s32 iD00;
    /* 0xD04 */ s32 iD04;
    /* 0xD08 */ s32 iD08;
    /* 0xD0C */ s32 iD0C;
    /* 0xD10 */ s32 iD10;
    /* 0xD14 */ s32 iD14;
    /* 0xD18 */ s32 iD18;
    /* 0xD1C */ s32 iD1C;
    /* 0xD20 */ s32 iD20;
    u8 padD24[0xD28 - 0xD24];
    /* 0xD28 */ s32 iD28;
    /* 0xD2C */ s8 cD2C;
    /* 0xD2D */ u8 bD2D;
    /* 0xD2E */ u8 bD2E;
    /* 0xD2F */ s8 cD2F;
    /* 0xD30 */ s16 hD30;
    u8 padD32[0xD34 - 0xD32];
    /* 0xD34 */ s16 hD34;
    /* 0xD36 */ s16 hD36;
    /* 0xD38 */ s16 hD38;
    u8 padD3A[0xD3C - 0xD3A];
    /* 0xD3C */ f32 fD3C;
    /* 0xD40 */ u8 bD40;
    /* 0xD41 */ u8 bD41;
    /* 0xD42 */ u8 bD42;
    u8 padD43[0xD4C - 0xD43];
    /* 0xD4C */ f32 fD4C;
    /* 0xD50 */ s32 iD50;
    /* 0xD54 */ s32 iD54;
    u8 padD58[0xD5A - 0xD58];
    /* 0xD5A */ s16 hD5A;
    u8 padD5C[0xD60 - 0xD5C];
    /* 0xD60 */ Vec_T vD60;
};

typedef struct Hero_T {
    u8 pad0[0x80];
    f32 f080;
    f32 f084;
    u8 pad88[0x238 - 0x88];
    s32 i238;
    u8 pad23C[0x25C4 - 0x23C];
    s32 i25C4;
    u8 pad25C8[0x2850 - 0x25C8];
    s32 i2850;
} Hero_T;

typedef struct Rec80_T {
    u8 pad0[0x30];
    Vec_T v30;
    u8 pad40[0x30];
    Vec_T v70;
} Rec80_T;

typedef struct Ctl_T {
    u8 pad0[0x144];
    Moby_T *m144;
    s32 i148;
} Ctl_T;

typedef struct Snd_T {
    u8 pad0[0x1034];
    s32 i1034;
    u8 pad1038[0x1040 - 0x1038];
    s32 i1040;
    u8 pad1044[0x104C - 0x1044];
    s32 i104C;
    u8 pad1050[0x12480 - 0x1050];
    u16 H12480;
    u8 pad12482[0x1248C - 0x12482];
    u16 H1248C;
    u8 pad1248E[0x12498 - 0x1248E];
    u16 H12498;
} Snd_T;

typedef struct Ptr_T {
    u8 pad0[0xAA];
    s16 hAA;
} Ptr_T;

extern Hero_T D_1A4BE0;
extern u8 D_1A4C60[];
extern Snd_T D_1A7E18;
extern s32 D_142660[];
extern u8 D_1426E0[];
extern s32 D_00142C38[];
extern Ptr_T *D_001A73E8[];
extern s32 D_001A4E18[];
extern s32 D_001D545C[];
extern Moby_T *D_L09_001E009C;
extern s32 D_L09_001E00D8;
extern Rec80_T *D_L09_001E0180;
extern Ctl_T D_L09_001E2B80;
extern u16 *D_L09_0021CDA0[];
extern PathEnt_T *D_L09_0021E640[];
extern u8 D_L09_002BB230[];
extern u8 D_L09_002BB280[];
extern Vec_T D_L09_001D66B0 __attribute__((section(".sdata")));
extern s32 D_L09_001DE748[];
extern s32 D_L09_001DE750[];
extern Vec_T D_L09_001DE6A0;
extern Vec_T D_L09_001DE6B0;
extern Vec_T D_L09_001DE6D0;
extern f32 D_L09_001DE6E0;
__asm__(".extern D_L09_001DE6E0, 4");
extern f32 D_L09_001DE6E4;
__asm__(".extern D_L09_001DE6E4, 4");
extern f32 D_L09_001DE6E8;
__asm__(".extern D_L09_001DE6E8, 4");
extern f32 D_L09_001DE6EC;
__asm__(".extern D_L09_001DE6EC, 4");

extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_0038CB00(void *);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0039EF28(void);
extern void func_003A4F28(s32);
extern s16 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_003C3FC0(void *, void *);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C7C38(void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EC9E0(s32);
extern s32 func_L01_003ECA10(s32);
extern void func_L01_0041A5B0(s32, s32);
extern f32 func_L01_004395E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00445170(void *, s32);
extern void func_L01_00445188(void *, s32);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_004561E0(void *);
extern s32 func_L01_00456208(void *);
extern s32 func_L01_00456500(void *, s32);
extern s32 func_L01_0045A748(void *, void *);
extern void func_L01_0045A9F0(void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern s32 func_L01_0045BE38(void *, void *);
extern void func_L01_0045C150(void *, void *, s32, s32);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_00511A40(void *, s32, f32);
extern void func_L01_00511AE8(void);
extern void func_L02_003A0200(void *);
extern void func_L02_003A02D8(void *, s32);
extern void func_L02_003C5DC0(s32);
extern s32 func_L08_003D0D08(s32);
extern s32 func_L09_003BBF10(void *);
extern void func_L09_003BC288(void *);
extern void func_L09_003BC450(void *, void *, s32, void *, s32);
extern s32 func_L09_003BD860(void *);
extern void func_L09_003BDB90(void *, void *, s32, void *);
extern void func_L09_003BDED0(void *);
extern void func_L09_003BE168(void *);
extern void func_L09_003BE228(void *);
extern s32 func_L09_003BE330(void *, void *);
extern s32 func_L09_003BE450(void *);
extern void func_L09_003BE5D0(void *, s32, s32, s32, s32);
extern void func_L09_003BE910(void *, s32, s32);
extern s32 func_L09_003BEB30(void *, void *, s32, void *);
extern void func_L09_003BEC20(void *, void *, s32, void *, s32);
extern s32 func_L09_003BED10(void *);
extern s32 func_L09_003BF038(void *, void *, s32, void *, s32);
extern void func_L09_003BF0E0(void *, void *, s32, void *, void *, void *, s32);
extern void func_L09_003BF3E0(void *);
extern void func_L09_003BF5F0(void *, void *);
extern void func_L09_003BF890(void *);
extern s32 func_L09_003BF9B8(void *);
extern void func_L09_003BFA48(void *);
extern void func_L09_003BFC90(void *, s32, f32, f32);
extern s32 func_L09_003CD998(void *, s32);
extern s32 func_L09_003CD9F0(void *);
extern void func_L09_003CDA30(void *);
extern void func_L09_00403E40(s32, s32);

void func_L09_003B8580(Moby_T *s) {
    VI_T a;
    VI_T b;
    VI_T c;
    VI_T d;
    VI_T e;
    VI_T f;
    VI_T g;
    Pv_T *v;
    Moby_T *bm;

    if (func_L09_003BBF10(s)) {
        return;
    }
    v = s->pv;
    bm = &D_L09_001E009C[v->iCD0];
    switch (s->b095) {
    case 0:
        if (func_L01_004561E0(s)) {
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD28];
                while ((v->iD28 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD28 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD28])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    lp++;
                    func_L02_003A02D8(m, 0);
                }
            }
            v->f12C = 1.5f;
            s->pos.z = 340.0f;
            func_L09_003CD998(&D_L09_001E009C[v->iCF0], 1);
            func_L09_003CD998(&D_L09_001E009C[v->iCE8], 1);
            s->H034 |= 0x41;
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD20])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                    m->H034 |= 2;
                }
            }
            D_1A4BE0.i2850 = D_142660[2];
            func_L01_004450F0(s, 2, -1);
            func_L01_00445188(s, 0);
        }
        break;
    case 1: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
            v->fD4C = 0.85f;
            func_L01_004450F0(s, 0xD, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BEB30(s, v->xC80, 5, D_L09_002BB230)) {
                func_L01_004450F0(s, 0xE, -1);
                func_L01_00445188(s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC80, 5, D_L09_002BB230, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BED10(s) && !func_L09_003BF038(s, v->xC80, 5, D_L09_002BB230, 6)) {
            func_L09_003BF0E0(s, v->xC80, 5, D_L09_002BB230, &t0, &t1, 1);
        }
        if (func_0038CB00(&v->hD30) ||
            (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
            func_L09_003BD860(s)) {
            v->bD42 |= 1;
        }
        if (func_L09_003BD860(s)) {
            func_L01_00445170(s, 2);
            v->fD4C = 0.65f;
        }
        break;
    }
    case 2: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BEB30(s, v->xC80, 5, D_L09_002BB230)) {
                func_L01_004450F0(s, 0xF, -1);
                func_L01_00445188(s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC80, 5, D_L09_002BB230, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BED10(s) && !func_L09_003BF038(s, v->xC80, 5, D_L09_002BB230, 5)) {
            func_L09_003BF0E0(s, v->xC80, 5, D_L09_002BB230, &t0, &t1, 1);
        }
        if (s->bBC != 5 &&
            (func_0038CB00(&v->hD30) ||
             (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
             func_L09_003BD860(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BD860(s)) {
            func_L01_00445170(s, 3);
            v->fD4C = 0.5f;
        }
        break;
    }
    case 3: {
        s32 t0 = 3;
        s32 t1 = 4;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BEB30(s, v->xC80, 5, D_L09_002BB230)) {
                func_L01_004450F0(s, 0xF, -1);
                func_L01_00445188(s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC80, 5, D_L09_002BB230, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BED10(s) && !func_L09_003BF038(s, v->xC80, 5, D_L09_002BB230, 4)) {
            func_L09_003BF0E0(s, v->xC80, 5, D_L09_002BB230, &t0, &t1, 1);
        }
        if (s->bBC != 5 &&
            (func_0038CB00(&v->hD30) ||
             (D_001A73E8[0] != 0 && (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33)) ||
             func_L09_003BD860(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BD860(s) && D_1A4BE0.i2850 > 0 && D_1A4BE0.i25C4 != 0x6A && D_1A4BE0.i25C4 != 0x7D) {
            func_L01_004450F0(s, 1, 4);
            func_L01_00445188(s, 0);
        }
        break;
    }
    case 4:
        if (func_L01_004561E0(s)) {
            if (v->hD5A != -1) {
                func_003A4F28(v->hD5A);
                v->hD5A = -1;
            }
            func_L01_004450F0(s, 5, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 5 && func_L01_003ECA10(v->iD00)) {
            v->bD42 &= 0xFE;
            func_L01_004450F0(s, 6, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 6 && s->bBC == 0xB && func_L01_003ECA10(v->iD04)) {
            v->bD42 &= 0xFE;
            func_L01_004450F0(s, 7, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 7 && func_L01_003ECA10(v->iD08)) {
            func_L01_00511AE8();
            v->bD42 &= 0xFE;
            func_L01_004450F0(s, 0x14, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 0x14 && ((v->bD42 & 2) || func_00382380(D_1A4C60, v->iD14, 0))) {
            func_L01_004AA760(8, s);
            func_L01_004450F0(s, 8, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 8 && func_L01_003ECA10(v->iD18)) {
            Rec80_T *r;

            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD50];
                while ((v->iD50 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD50 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD50])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                    m->i098 = 0;
                    m->H034 |= 2;
                }
            }
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iD1C << 7));
            func_L01_00511AE8();
            func_L01_004F50C8(&r->v30, &r->v70, 0, 0);
            v->fC30 = 0.0f;
            func_003C3FC0(v->xC50, &D_L09_001D66B0);
            func_L01_004450F0(s, 1, 5);
            func_L01_00445188(s, 0);
            v->fD4C = 0.35f;
        }
        break;
    case 5: {
        a.i = *(I2_T *)D_L09_001DE748;
        b.i = *(I2_T *)D_L09_001DE750;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
            func_L01_004450F0(s, 0xD, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BEB30(s, v->xC9C, 10, D_L09_002BB280)) {
                func_L01_004450F0(s, 0xF, -1);
                func_L01_00445188(s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC9C, 10, D_L09_002BB280, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BED10(s) && !func_L09_003BF038(s, v->xC9C, 10, D_L09_002BB280, 3)) {
            func_L09_003BF0E0(s, v->xC9C, 10, D_L09_002BB280, &a.i, &b.i, 2);
        }
        if (s->bBC != 6 &&
            (func_0038CB00(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BD860(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BD860(s)) {
            func_L01_00445170(s, 6);
            v->fD4C = 0.15f;
        }
        break;
    }
    case 6: {
        a.i = *(I2_T *)D_L09_001DE748;
        c.i = *(I2_T *)D_L09_001DE750;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            if (func_L09_003BEB30(s, v->xC9C, 10, D_L09_002BB280)) {
                func_L01_004450F0(s, 0xF, -1);
                func_L01_00445188(s, 1);
            }
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC9C, 10, D_L09_002BB280, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BED10(s) && !func_L09_003BF038(s, v->xC9C, 10, D_L09_002BB280, 2)) {
            func_L09_003BF0E0(s, v->xC9C, 10, D_L09_002BB280, &a.i, &c.i, 2);
        }
        if (s->bBC != 6 &&
            (func_0038CB00(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BD860(s))) {
            v->bD42 |= 1;
        }
        if (func_L09_003BD860(s)) {
            func_L01_00445170(s, 7);
            v->fD4C = 0.0f;
        }
        break;
    }
    case 7: {
        a.i = *(I2_T *)D_L09_001DE748;
        d.i = *(I2_T *)D_L09_001DE750;

        if (func_L01_004561E0(s)) {
            v->bD42 &= 0xFE;
        } else if (s->b020 == 0xD && (v->bD42 & 2)) {
            func_L09_003BC450(s, v->xC9C, 10, D_L09_002BB280, 0);
            v->hD38 = func_00382498(5, 10) * 50.0f;
            v->hD34 = 0;
            v->bD40 = 0;
            v->hD30 = func_00382498(15, 25) * 50.0f;
            if (D_L09_001E2B80.m144 == bm) {
                D_L09_001E2B80.m144 = 0;
            }
            if (D_L09_001E2B80.m144 == 0) {
                D_L09_001E2B80.m144 = s;
                D_L09_001E2B80.i148 = 0;
            }
            func_L01_004450F0(s, 0xE, -1);
            func_L01_00445188(s, 1);
        } else if (s->b020 == 0xC && (v->bD42 & 2)) {
            func_L09_003BEC20(s, v->xC9C, 10, D_L09_002BB280, 1);
            func_L01_004450F0(s, 0x10, -1);
            func_L01_00445188(s, 1);
        } else if (!func_L09_003BF038(s, v->xC9C, 10, D_L09_002BB280, 1)) {
            func_L09_003BF0E0(s, v->xC9C, 10, D_L09_002BB280, &a.i, &d.i, 2);
        }
        if (s->bBC != 6 &&
            (func_0038CB00(&v->hD30) ||
             (D_001A73E8[0] != 0 &&
              (D_001A73E8[0]->hAA == 0x19DF || D_001A73E8[0]->hAA == 0x1B33 || D_001A73E8[0]->hAA == 0x1C0C)) ||
             func_L09_003BD860(s))) {
            v->bD42 |= 1;
        }
        break;
    }
    case 9:
        if (func_L01_004561E0(s)) {
            if (v->bD40 == 0) {
                func_003C3A10(s, 4, 0, 4);
            } else {
                func_003C3A10(s, 5, 0, 4);
            }
            func_003C3A10(bm, 0, 0, 4);
        }
        s->bBC = 0;
        s->b020 = 1;
        if (D_00142C38[0] & 0x01000000) {
            func_L09_003CDA30(&D_L09_001E009C[v->iCE0]);
            func_L09_003CDA30(&D_L09_001E009C[v->iCE4]);
            func_L09_003CD9F0(&D_L09_001E009C[v->iCE0]);
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD28];
                while ((v->iD28 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD28 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD28])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    lp++;
                    func_L02_003A0200(m);
                    m->i098 = 0;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                }
            }
            func_003C2880(s);
            return;
        }
        break;
    }

    v->bD42 &= 0xF9;
    switch (s->b020) {
    case 2:
        if (v->iCD4 != -1 && func_L01_00456500(D_1A4C60, v->iCD4)) {
            s32 i;

            if (D_1426E0[0x3C] & 1) {
                func_L01_003EC9E0(v->iCF4);
                func_L01_004450F0(s, 3, -1);
            } else {
                func_L02_003C5DC0(v->iCF8);
                func_L01_003EC9E0(v->iCF8);
                func_L01_004450F0(s, 4, -1);
            }
            for (i = 0; i < 7; i++) {
                if ((u32)i < 8 && ((D_1426E0[0x3C] >> i) & 1)) {
                    D_1426E0[0x3C] &= ~(1 << i);
                    func_0039EF28();
                    if ((u32)(i + 1) < 8) {
                        D_1426E0[0x3C] |= 1 << (i + 1);
                    }
                    func_0039EF28();
                    break;
                }
            }
        }
        break;
    case 3:
        if (((s->bBE ^ 1) & 1) && func_L08_003D0D08(v->iCF4)) {
            Rec80_T *r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iCFC << 7));

            func_L01_004F50C8(&r->v30, &r->v70, 0x74, 0);
            func_003A52A0(8, 4, s);
            func_L01_004561B8(s);
        } else if (func_L01_003ECA10(v->iCF4)) {
            func_L09_003CD9F0(&D_L09_001E009C[v->iCF0]);
            func_L09_003CD9F0(&D_L09_001E009C[v->iCE8]);
            s->H034 &= 0xFFBE;
            func_L01_004AA760(8, s);
            if (D_L09_001E2B80.m144 == 0) {
                D_L09_001E2B80.m144 = s;
                D_L09_001E2B80.i148 = 0;
            }
            func_L01_004450F0(s, 1, 1);
            func_L01_00445188(s, 0);
        }
        break;
    case 4:
        if (func_L08_003D0D08(v->iCF8)) {
            Rec80_T *r;

            func_L09_003CD9F0(&D_L09_001E009C[v->iCF0]);
            func_L09_003CD9F0(&D_L09_001E009C[v->iCE8]);
            s->H034 &= 0xFFBE;
            if (D_L09_001E2B80.m144 == 0) {
                D_L09_001E2B80.m144 = s;
                D_L09_001E2B80.i148 = 0;
            }
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iCFC << 7));
            func_L01_004F50C8(&r->v30, &r->v70, 0x74, 0);
            func_L01_004450F0(s, 1, 1);
            func_L01_00445188(s, 0);
        }
        break;
    case 5:
        if (func_L01_004561B8(s)) {
            v->bD42 &= 0xFE;
            func_L02_003C5DC0(v->iD00);
            func_L01_003EC9E0(v->iD00);
            v->hD36 = 0x32;
            v->fD4C = 0.5f;
        } else if (func_0038CB00(&v->hD36)) {
            func_L09_003CD998(&D_L09_001E009C[v->iCE8], 0);
            func_L09_003CD998(&D_L09_001E009C[v->iCEC], 0);
        } else if (((v->bD42 ^ 1) & 1) && func_L08_003D0D08(v->iD00)) {
            Rec80_T *r;

            func_L01_004AA7E8(s, 1);
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iD0C << 7));
            func_L01_004F50C8(&r->v30, &r->v70, 0x74, 0);
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iD10 << 7));
            s->pos = r->v30;
            s->vF0 = r->v70;
            func_003C3A10(s, 8, 0, 0);
            v->bD41 = 0;
            v->fC30 = 0.0f;
            v->bD40 = 1;
            func_003C3FC0(v->xC50, &D_L09_001D66B0);
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD20])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    lp++;
                    if (m == 0) {
                        break;
                    }
                    m->H034 &= 0xFFBE;
                    m->H034 |= m->cls->H044 & 0x1000;
                    m->H034 &= 0xFFFD;
                    m->i098 = m->cls->i010;
                }
            }
            v->bD42 |= 1;
        }
        break;
    case 6:
        if (func_L01_004561B8(s)) {
            func_003C3A10(s, 8, 0, 0);
        } else if (s->bBC == 1) {
            v->fBE8 = 1.5707964f;
            if (func_0038CB00(&v->hD36)) {
                v->hD36 = 0x96;
                func_L01_00445188(s, 0xB);
            }
        }
        break;
    case 7:
        if (func_L01_004561B8(s)) {
            bm->vF0.z = 0.0f;
            func_L01_00511A40(&D_L09_001DE6D0, 0, -3.1400917f);
            v->fC30 = 0.0f;
            func_003C3FC0(v->xC50, &D_L09_001D66B0);
            v->hD34 = 0x166;
            v->hD36 = 0x11;
            v->hD30 = 0x34;
            v->bD42 |= 1;
        }
        func_L09_003BE5D0(s, 0, 0, 0, 1);
        D_001A4E18[0] = 3;
        break;
    case 8:
        if (func_L01_004561B8(s)) {
            v->bD42 &= 0xFE;
            func_L02_003C5DC0(v->iD18);
            func_L01_003EC9E0(v->iD18);
        } else if (((v->bD42 ^ 1) & 1) && func_L08_003D0D08(v->iD18)) {
            Rec80_T *r;
            PathEnt_T *pa;

            bm->vF0.z = 0.0f;
            func_L09_003CD9F0(&D_L09_001E009C[v->iCEC]);
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iD14 << 7));
            func_L01_004F50C8(&r->v30, &r->v70, 0, 0);
            r = (Rec80_T *)((u8 *)D_L09_001E0180 + (v->iD1C << 7));
            func_L01_00511A40(&r->v30, 0, r->v70.z);
            pa = D_L09_0021E640[v->iC98];
            s->vF0.z = 4.712389f;
            s->pos = pa[pa[0].n].v;
            v->hD34 = 0x25;
            s->H034 &= 0xFFBE;
            v->cD2C = 1;
            v->fCDC = 0.0f;
            {
                u16 *lp;
                Moby_T *m;

                lp = D_L09_0021CDA0[v->iD20];
                while ((v->iD20 & 0xFF) != 0xFF && D_L09_001E00D8 >= v->iD20 && lp != 0 &&
                       ((s16)lp[-1] >= 0 || lp == D_L09_0021CDA0[v->iD20])) {
                    m = &D_L09_001E009C[*lp & 0x7FFF];
                    if (m == 0) {
                        break;
                    }
                    m->i098 = 0;
                    lp++;
                    m->H034 = (m->H034 | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                    m->H034 |= 2;
                }
            }
            v->P254 = 0;
            func_003C3A10(s, 8, 0, 0);
            v->fC30 = 0.0f;
            func_003C3FC0(v->xC50, &D_L09_001D66B0);
            v->bD42 |= 1;
        } else if ((v->bD42 & 1) && s->bBC == 1) {

            v->fBE8 = 0.43633232f;
            a.v = D_L09_001D66B0;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_0038DB00(s->vF0.z, 1.701696f);

                func_L01_00448890(&a.v, func_0038DB00(func_0038D160(D_1A4BE0.f080 - bm->pos.x, D_1A4BE0.f084 - bm->pos.y), t),
                              v->xCD8, 0, 0.0050265486f, 0.0050265486f, 0.50265485f);
            }
            v->fCDC = a.v.x;
            func_003C3FC0(v->xC50, &a.v);
            D_1A4BE0.i238 = 3;
            if (func_0038CB00(&v->hD34)) {
                func_L01_00445188(s, 0xC);
            }
        }
        break;
    case 9:
        if (func_L01_004561B8(s) || (s->b060 & 2)) {
            func_003C3A10(s, 0, 0, 8);
            s->f048 = 1.0f;
            if (s->b060 & 2) {
                v->bD42 |= 2;
            }
        }
        break;
    case 10:
        if (func_L01_004561B8(s) || (s->b060 & 2)) {
            func_003C3A10(s, 8, 0, 8);
            s->f048 = 0.5f;
            if (s->b060 & 2) {
                v->bD42 |= 2;
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(s)) {
            func_003C3A10(s, 1, 0, 8);
            s->f048 = 1.0f;
        }
        func_L01_0045A9F0(s);
        if (func_L01_0044E1B8(s, 12.833333f)) {
            func_003A52A0(1, 4, s);
        }
        if (s->b060 & 2) {
            func_L01_004AA760(1, s);
            v->bD42 |= 2;
        }
    case 12:
        if (func_L01_004561B8(s)) {
            func_003C3A10(s, 1, 0, 8);
            s->f048 = 1.0f;
        }
        if (s->b043 == 1) {
            func_L01_0045A9F0(s);
            if (func_L01_0044E1B8(s, 12.833333f)) {
                func_003A52A0(1, 4, s);
            }
            if (s->b060 & 2) {
                v->i1C8 &= ~0x404;
                func_L01_004AA760(1, s);
                func_003C3A10(s, 0xA, 0, 8);
                s->f048 = 1.0f;
            }
        } else if (s->b043 == 0xA) {
            f32 t = func_L01_004395E0(s);

            if (t >= 14.0f && t <= 22.0f) {
                s->pos.z += 0.6f;
            }
            if (s->b060 & 2) {
                func_003C3A10(s, 8, 0, 0);
                s->pos.z = 340.0f;
                v->bD42 |= 2;
            }
        }
        break;
    case 13:
        if (func_L01_004561B8(s)) {
            v->i1C8 &= ~0x404;
            s->pos.z = 340.0f;
            func_003C3A10(s, 6, 0, 8);
            s->f048 = 1.0f;
        }
        if (s->b043 == 6) {
            f32 t = func_L01_004395E0(s);

            if (t >= 9.0f && t <= 17.0f) {
                s->pos.z -= 0.6f;
            }
            func_L09_003BFA48(s);
            func_L09_003BE228(s);
            if (s->b060 & 2) {
                func_003C3A10(s, 1, 0, 8);
                s->f048 = 1.0f;
            }
        } else if (s->b043 == 1) {
            func_L01_0045A9F0(s);
            if (func_L01_0044E1B8(s, 12.833333f)) {
                func_003A52A0(1, 4, s);
            }
            if (s->b060 & 2) {
                func_L01_004AA760(1, s);
                v->bD42 |= 2;
            }
        }
        break;
    case 14:
        if (func_L01_004561B8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_0045BD78(s, 0.007f, 0.11000001f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 2, 0, 8);
            s->f048 = 1.0f;
        }
        func_L09_003BE168(s);
        func_L09_003BFC90(s, 0, D_L09_001DE6E4, D_L09_001DE6E0);
        v->f1C4 = 4.0f;
        if (func_L01_0045BE38(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 15:
        if (func_L01_004561B8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_0045BD78(s, 0.014400001f, 0.24000001f, 0.010053097f, 0.08377581f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 3, 0, 8);
            s->f048 = 1.0f;
        }
        func_L09_003BE168(s);
        func_L09_003BFC90(s, 1, D_L09_001DE6EC, D_L09_001DE6E8);
        v->f1C4 = 4.0f;
        if (func_L01_0045BE38(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 16:
        if (func_L01_004561B8(s)) {
            v->i1C8 |= 0x404;
            func_L01_0045BD78(s, 0.0216f, 0.36f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 7, 0, 8);
            s->f048 = 1.0f;
        }
        v->f1C4 = 4.0f;
        if (func_L01_0045BE38(s, v->P254)) {
            v->bD42 |= 2;
        }
        v->f1C4 = 1.0f;
        break;
    case 17:
        if (func_L01_004561B8(s)) {
            v->i1C8 |= 0x404;
            func_L01_0045BD78(s, 0.0216f, 0.36f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 7, 0, 8);
            s->f048 = 1.0f;
        }
        if (v->P254 != 0) {
            v->f1C4 = 4.0f;
            if (func_L01_0045BE38(s, v->P254)) {
                v->bD42 |= 2;
            }
            v->f1C4 = 1.0f;
        } else if (v->bD41 != 2) {

            a.v.x = v->fCC8;
            a.v.y = v->fCCC;
            a.v.z = 340.0f;
            a.v.w = 0.0f;
            if (func_L01_0045A748(s, &a.v)) {
                v->bD42 |= 2;
            }
        }
        break;
    case 18: {

        if (func_L01_004561B8(s)) {
            v->i1C8 |= 0x404;
            func_L01_0045BD78(s, 0.0216f, 0.36f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 7, 0, 8);
            s->f048 = 1.0f;
            v->fCC8 = s->pos.x;
            v->fCCC = s->pos.y;
        }
        a.v.x = v->fCC8;
        a.v.y = v->fCCC;
        a.v.z = 340.0f;
        a.v.w = 0.0f;
        if (func_0038CF38(&s->pos, &a.v) < v->f1C4) {
            f32 ang = func_00382538();
            f32 r = func_003824E0(5.0f, 10.0f);

            a.v.x = func_0038D098(ang) * r;
            a.v.y = func_0038D0B0(ang) * r;
            vec_add_ab(&a.v, &a.v, &D_L09_001DE6B0);
            if (!func_L01_00456500(&a.v, v->iD54)) {
                a.v = D_L09_001DE6B0;
            }
            v->fCC8 = a.v.x;
            v->fCCC = a.v.y;
        }
        func_L01_0045A748(s, &a.v);
        break;
    }
    case 19:
        if (func_L01_004561B8(s)) {
            v->i1C8 |= 0x404;
            func_L01_0045BD78(s, 0.0216f, 0.36f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 7, 0, 8);
            s->f048 = 1.0f;
            func_L01_0045C150(s, v->P254, v->h258, v->h258);
            func_L01_0045BE38(s, v->P254);
            v->hD36 = 8;
            v->fD3C = 0.125f;
        }
        if (v->f1C4 < v->f25C) {
            func_L01_0045BE38(s, v->P254);
        } else if (!func_0038CB00(&v->hD36)) {

            a.v = v->P254[v->h25A + 1].v;
            b.v = s->pos;
            func_003C4098(&s->pos, &a.v, &b.v, (f32)v->hD36 * v->fD3C);
        } else {
            v->bD42 |= 2;
        }
        break;
    case 20:
        if (func_L01_004561B8(s)) {
            PathEnt_T *pa;

            s->b023 = 0x80;
            pa = D_L09_0021E640[v->iC98];
            func_L01_0045C150(s, pa, pa[0].n - 1, 0);
            func_L01_003EB438(0, &s->pos, &s->vF0, 1, 0, 0);
            func_L09_00403E40(0, 1);
            s->H034 |= 0x41;
            v->cD2C = 0;
            v->i1C8 |= 0x404;
            func_L01_0045BD78(s, 0.007f, 0.11000001f, 0.0050265486f, 0.041887905f);
            v->hD34 = 0x64;
            v->bD2D = 0;
            v->hD30 = 0;
            D_1A7E18.H1248C = 0;
            D_1A7E18.H12498 = 0;
            D_1A7E18.H12480 = 0;
            func_003A52A0(1, 4, s);
            v->hD5A = -1;
            v->vD60 = s->vF0;
        }
        D_1A4BE0.i238 = 3;
        func_L09_003BF5F0(s, &D_1A4BE0);
        func_L09_003BF890(s);
        if (s->bBC != 0xA) {
            func_L01_00445188(s, 0xA);
        }
        if (func_0038CB00(&v->hD34) && v->hD5A == -1) {
            func_L01_004AA760(1, s);
            v->hD5A = func_003A52A0(8, 4, s);
        }
        if (D_1A4BE0.f080 > 265.0f && func_0038CB00(&v->hD30)) {
            if (D_1A7E18.H1248C == 0) {
                if (!((1 << D_001D545C[0]) & (u32)D_1A7E18.i1040)) {
                    func_L01_0041A5B0(0x1861, 0x15A);
                }
            } else if (D_1A7E18.H12498 == 0) {
                if (!((1 << D_001D545C[0]) & (u32)D_1A7E18.i104C)) {
                    func_L01_0041A5B0(0x1862, 0x15B);
                }
            } else if (D_1A7E18.H12480 == 0 && !((1 << D_001D545C[0]) & (u32)D_1A7E18.i1034)) {
                func_L01_0041A5B0(0x1860, 0x159);
            }
            v->hD30 = 0x96;
        }
        if (func_L01_0045BE38(s, v->P254)) {
            v->bD42 |= 2;
        }
        break;
    case 21: {
        s32 n = 0;
        f32 t;

        if (func_L01_004561B8(s)) {
            v->i1C8 &= ~0x404;
            func_L01_0045BD78(s, 0.008400001f, 0.14000002f, 0.0050265486f, 0.041887905f);
            v->f1B4 = 1.0f;
            func_003C3A10(s, 9, 0, 8);
            s->f048 = 0.75f;
        }
        t = func_L01_004395E0(s);
        v->f1C4 = 4.0f;
        if (t > 0.0f && t < 31.0f) {
            n = func_L01_0045BE38(s, v->P254);
            func_L09_003BE168(s);
        } else if (t > 31.0f && t < 40.0f) {
            func_L01_0045A9F0(s);
            func_L09_003BDED0(s);
            func_L09_003BE168(s);
        } else if (t > 40.0f && t < 54.0f) {
            n = func_L01_0045BE38(s, v->P254);
            func_L09_003BE168(s);
        } else if (t > 54.0f && t < 71.0f) {
            func_L01_0045A9F0(s);
            func_L09_003BDED0(s);
            func_L09_003BE168(s);
        } else if (t > 71.0f) {
            n = func_L01_0045BE38(s, v->P254);
            func_L09_003BE168(s);
        }
        if (n) {
            func_L09_003BDB90(s, s->b095 < 4 ? v->xC80 : v->xC9C, s->b095 > 3 ? 10 : 5,
                              s->b095 < 4 ? D_L09_002BB230 : D_L09_002BB280);
        }
        v->f1C4 = 1.0f;
        if (s->b060 & 2) {
            v->bD42 |= 2;
        }
        break;
    }
    case 22: {
        s32 n;

        if (func_L01_004561B8(s)) {
            v->f12C = 1.5f;
        }
        n = func_L01_00454370(s, v->x0D0);
        if (((n & 1) || v->f030 <= 0.0f) && D_1A4BE0.i2850 > 0 && D_1A4BE0.i25C4 != 0x6A && D_1A4BE0.i25C4 != 0x7D) {
            func_L09_003BC288(s);
        } else if (n & 2) {
            v->f12C = 0.05f;
            func_L01_004450F0(s, s->b094, -1);
        }
        break;
    }
    case 23: {
        s32 n;

        if (func_L01_004561B8(s)) {
            v->f12C = 1.5f;
        }
        n = func_L01_00454370(s, v->x0D0);
        if ((n & 1) || v->f030 <= 0.0f) {
            func_L09_003BC288(s);
        } else if (n & 2) {
            v->f12C = 0.05f;
            func_L01_004450F0(s, s->b094, -1);
        }
        break;
    }
    }

    switch (s->bBC) {
    case 1:
        if (func_L01_00456208(s) || (bm->b060 & 2)) {
            func_003C3A10(bm, 0, 0, 4);
        }
        break;
    case 2:
        if (func_L01_00456208(s) || (bm->b060 & 2)) {
            func_003C3A10(bm, 0, 0, 4);
        }
        if (func_L09_003BE450(s)) {
            v->bD42 |= 4;
            func_L01_00445188(s, 1);
        }
        break;
    case 3:
    case 4: {
        Vec_T *p;

        if (func_L01_00456208(s)) {
            v->hD36 = 2;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            vec_sub_ab(&a.v, &bm->pos, D_1A4C60);
            v->cD2F = func_0038CE68(&bm->vD0, &a.v) > 0.0f ? -1 : 1;
            func_003C3A10(bm, 0, 0, 8);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_0038DB00(s->vF0.z, 1.5707964f);

                func_L01_00448890(&a.v, func_0038DB00(func_0038D160(D_1A4BE0.f080 - bm->pos.x, D_1A4BE0.f084 - bm->pos.y), t),
                              v->xCD8, 0, 0.0050265486f, 0.0050265486f, 0.50265485f);
            }
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BE330(s, p)) {
            func_L09_003BF3E0(s);
            func_L09_003BE910(s, s->bBC == 4, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 5:
    case 6: {
        Vec_T *p;
        s32 i;
        f32 ang;
        f32 r0;
        f32 r1;
        f32 best;

        if (func_L01_00456208(s)) {
            v->hD36 = 2;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003C3A10(bm, 0, 0, 8);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0;
            b.v = s->b095 < 4 ? D_L09_001DE6A0 : D_L09_001DE6B0;
            vec_sub_ab(&e.v, &bm->pos, &b.v);
            best = 0.0f;
            f.v.x = v->fCC8;
            f.v.y = v->fCCC;
            f.v.z = 340.0f;
            f.v.w = 0.0f;
            vec_sub_ab(&f.v, &f.v, &b.v);
            for (i = 0; i < 4; i++) {
                ang = (f32)i * 90.0f * 0.017453292f;
                g.v.x = func_0038D098(ang);
                g.v.y = func_0038D0B0(ang);
                g.v.z = 0.0f;
                r0 = func_0038CE68(&g.v, &e.v);
                r1 = func_0038CE68(&g.v, &f.v);
                if (r0 > 0.0f && r1 > 0.0f) {
                    best = ang;
                    break;
                }
                if (r0 < 0.0f && r1 < 0.0f) {
                    best = func_0038DAB8((f32)i * 90.0f * 0.017453292f, 3.1415927f);
                    break;
                }
            }
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            func_L01_00448890(&a.v, func_0038DB00(s->vF0.z, best), v->xCD8, 0, 0.0050265486f, 0.0050265486f,
                              0.50265485f);
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BE330(s, p)) {
            func_L09_003BE910(s, s->bBC == 6, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 7: {

        if (func_L01_00456208(s)) {
            v->hD36 = 0x25;
            v->bD2D = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003C3A10(bm, 0, 0, 8);
        }
        a.v = D_L09_001D66B0;
        a.v.y = -0.017453292f;
        a.v.x = v->fCDC;
        func_L01_00448890(&a.v,
                          func_0038DB00(func_0038D160(D_1A4BE0.f080 - bm->pos.x, D_1A4BE0.f084 - bm->pos.y), s->vF0.z),
                          v->xCD8, 0, 0.0050265486f, 0.0050265486f, 0.50265485f);
        v->fCDC = a.v.x;
        if (func_L09_003BE330(s, &a.v)) {
            func_003C3FC0(v->xC50, &a.v);
            func_L09_003BE5D0(s, 0, 0, 0, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 8: {
        Vec_T *p;

        if (func_L01_00456208(s)) {
            v->hD36 = 0x25;
            v->bD2E = 0;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            vec_sub_ab(&a.v, &bm->pos, D_1A4C60);
            v->cD2F = func_0038CE68(&bm->vD0, &a.v) > 0.0f ? -1 : 1;
            func_003C3A10(bm, 0, 0, 8);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0;
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            {
                f32 t = func_0038DB00(s->vF0.z, 1.5707964f);

                func_L01_00448890(&a.v, func_0038DB00(func_0038D160(D_1A4BE0.f080 - bm->pos.x, D_1A4BE0.f084 - bm->pos.y), t),
                              v->xCD8, 0, 0.0050265486f, 0.0050265486f, 0.50265485f);
            }
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BE330(s, p)) {
            func_L09_003BF3E0(s);
            func_L09_003BE5D0(s, 0, 0, 0, 1);
            v->bD42 |= 4;
        }
        break;
    }
    case 9: {
        Vec_T *p;
        s32 i;
        f32 ang;
        f32 r0;
        f32 r1;
        f32 best;

        if (func_L01_00456208(s)) {
            v->hD36 = 0x25;
            if (v->bD41 == 0) {
                v->fCDC = 0.0f;
            }
            func_003C3A10(bm, 0, 0, 8);
        }
        p = 0;
        if (v->bD41 == 2) {
            a.v = D_L09_001D66B0;
            b.v = s->b095 < 4 ? D_L09_001DE6A0 : D_L09_001DE6B0;
            vec_sub_ab(&c.v, &bm->pos, &b.v);
            best = 0.0f;
            d.v.x = v->fCC8;
            d.v.y = v->fCCC;
            d.v.z = 340.0f;
            d.v.w = 0.0f;
            vec_sub_ab(&d.v, &d.v, &b.v);
            for (i = 0; i < 4; i++) {
                ang = (f32)i * 90.0f * 0.017453292f;
                e.v.x = func_0038D098(ang);
                e.v.y = func_0038D0B0(ang);
                e.v.z = 0.0f;
                r0 = func_0038CE68(&e.v, &c.v);
                r1 = func_0038CE68(&e.v, &d.v);
                if (r0 > 0.0f && r1 > 0.0f) {
                    best = ang;
                    break;
                }
                if (r0 < 0.0f && r1 < 0.0f) {
                    best = func_0038DAB8((f32)i * 90.0f * 0.017453292f, 3.1415927f);
                    break;
                }
            }
            a.v.y = -0.017453292f;
            a.v.x = v->fCDC;
            func_L01_00448890(&a.v, func_0038DB00(s->vF0.z, best), v->xCD8, 0, 0.0050265486f, 0.0050265486f,
                              0.50265485f);
            p = &a.v;
            v->fCDC = a.v.x;
        }
        if (func_L09_003BE330(s, p)) {
            func_L09_003BE5D0(s, 0, 0, 0, 0);
            v->bD42 |= 4;
        }
        break;
    }
    case 10:
        if (func_L01_00456208(s)) {
            v->bD2D = 0;
            v->hD36 = 0x25;
            func_003C3A10(bm, 4, 0, 0);
        }
        if (v->bD2D >= 2) {
            s32 n = func_L09_003BF9B8(s);

            if (func_00382468(5) || n) {
                func_L09_003BE5D0(s, 0, (n ^ 1) & 0xFF, n, 0);
                break;
            }
        }
        func_L09_003BE5D0(s, 0, 0, 0, 1);
        break;
    case 11:
        if (func_L01_00456208(s)) {
            func_003C3A10(bm, 0, 0, 8);
        }
        v->fBE8 = 1.5707964f;
        if (func_L01_0044E1B8(bm, 2.0f)) {
            func_L09_003BE5D0(s, 1, 0, 0, 0);
        } else if (func_L01_0044E1B8(bm, 10.0f)) {
            func_003C3A10(bm, (bm->b042 ^ 3) ? 3 : 4, 0, 8);
        }
        break;
    case 12:
        if (func_L01_00456208(s)) {
            v->bD2E = 0;
            v->cD2F = -1;
            func_003C3A10(bm, 3, 0, 8);
        }
        if (v->bD2E == 0) {
            v->fBE8 = 0.43633232f;
            func_L09_003BF3E0(s);
            if (func_L01_0044E1B8(bm, 2.0f)) {
                func_L09_003BE5D0(s, 0, 0, 0, 1);
            } else if (func_L01_0044E1B8(bm, 10.0f)) {
                func_003C3A10(bm, (bm->b042 ^ 3) ? 3 : 4, 0, 8);
            }
        } else {

            a.v = D_L09_001D66B0;
            a.v.y = 0.0f;
            a.v.x = v->fCDC;
            func_L01_00448890(&a.v, a.v.y, v->xCD8, 0, 0.0050265486f, 0.0050265486f, 0.50265485f);
            v->fCDC = a.v.x;
            func_003C3FC0(v->xC50, &a.v);
        }
        break;
    case 14:
        break;
    }

    if (v->f030 <= 0.0f && D_1A4BE0.i2850 > 0 && D_1A4BE0.i25C4 != 0x6A && D_1A4BE0.i25C4 != 0x7D) {
        func_L09_003BC288(s);
    }
    func_003C7C38(s);
    if (v->bD41 == 1) {
        s->f008 += v->fC30 * 0.5f;
    }
}
