/* c3 (Opus, 2026-11-14): 618 -> 334 aligned rows (333 with registers ignored), checked with
   --as ps2as and -mvu0-use-vf0-vf2 (the file needs @ps2as). What moved it: the D_L33_001DDAF8 speed
   read inline at both arguments of every func_L30_0034D1E8 call (no shared `f`); &o->x inline instead
   of the `pos` local (GCSE keeps it in $s6 as retail does); `idx == 2` written as `aaflag` (idx then
   spills to 0x44 and the frame becomes 0xD0, as in retail); the float `f` split per case; float
   params moved within the func_L30_0034D1E8 prototype; return types flipped by the checker
   (func_003C4098 void, func_L31_00346B10 s32, ...); three independent stores reordered.
   Left: per-case scheduling and branch shapes across all 16 states (near/free4C/side50 store order
   at the top, the per-case func_L30_0034D1E8 argument set-up), not register numbering. */
/* s1 (Opus, 2026-11-13), parked after a 45-minute time box. Findings:
   - Retail builds its float literals inline (lui/ori/mtc1, e.g. 0.8f/1.2f/0.4f/0.6f for rand_range),
     so the file needs @ps2as (and so does func_L02_003A3988's file, which matched that way).
   - Under @ps2as the 15 difficulty tables (D_L33_001DD888.. [2]) lose their gp addressing unless they also get
     __asm__(".extern D_L33_..., 8"); with that, the structural diff (registers ignored) goes from 334 to 300 rows.
   - The rest is register allocation and the 0xD0 frame (idx/near/free4C/side50 spilled in retail), plus per-case
     scheduling. The fixes that closed L02_003A3988 should apply: one C variable per lifetime (block-local loop
     counters and float temps in each case), the exact retail float bit patterns, and stale-register float args
     (a callee taking an f14 that is never set means one more float param).
   - Check it one function at a time (check.py FILE func_L33_00350818 --as ps2as); a whole-file run trips over
     the file's own context.
   The draft below is the w6 Sonnet draft plus the .extern lines (1756 rows with --as ps2as). */
/* func_L33_00350818: Opus handoff (prep by Sonnet worker w6, 2026-11-08)
   Size: 7076 bytes, places: 1 level (33, Vidcomic 2), file: src/levels/33_vidcomic_2/L33_0034FC00.c
   flags: the file's own line (-O2 -G8 -fopt-stack -mno-check-zero-division, NO @ps2as); retail has 76 mtc1 (inline float constants) and 26 lq/sq:
     a file with an estimated flag line and no C yet: try --as ps2as first (Ps2EeAs inline constants), then check with --all-modes.
   Step 0: one function; 1 jump table (jtbl_002BE8A0), 16 cases. a Vidcomic-2 moby update (L33_00352ED0 x17, L30_0034D1E8 x17 [a level-30 routine!], L01_004561B8 x11, rand_range, angle_sub, timer_tick).
   rac2 twin: none: best opcode 0.215 (func_L17_003E7068); no rac3 sibling above 0.07-0.17; it calls level-30 code (func_L30_0034D1E8, func_L30_0034C8A8), so levels 30-33 (the Vidcomic set) are the family to read first.
   Mapping / identical / changed: no twin to map. Hot callees have names in config/names.tsv (moby_set_state, moby_anim_blend,
     vec_set_length, angle_add/sub, atan2, rand_*), so the m2c is readable as moby-AI code.
   No COP2 instructions: a plain-C MATCH is possible in principle.
   Draft: no compiling draft (m2c converted (924 lines): two classes of errors left: `*(void *)expr` dereferences (give the pointers types; lines 331-391) and callee arity (func_L33_00352ED0 takes more args than m2c guessed).). The fenced block is the mechanically converted m2c (M2C_FIELD ->
     byte-offset casts, M2C_UNK -> s32, s128 -> u128_t TI typedef). Not measured.
   Left for Opus: (1) type the object (moby: pos +0x10, state +0x20 u8, class ptr +0x24, flags +0x34 u16; the +0x68 pointer is the
     per-moby vars block); (2) turn float-hex arguments back into f32; (3) get it to compile, measure, then register/scheduling work.
   Tool note: tools in out/tools-w6/ (m2c2.py: restores the `.word`-hidden lq/sq and appends the jump tables so m2c runs at all;
     conv.py: M2C_FIELD -> casts; iter.py: compile loop dropping conflicting prototypes).
*/
#include "vu0.h"

typedef int u128_00350818 __attribute__((mode(TI)));

typedef struct Cls_00350818 {
    u8 p00[0x10];
    s32 s10;
    u8 p14[0x30];
    u16 u44;
} Cls_00350818;

typedef struct V_00350818 {
    /* 00 */ u8 p00[0x14];
    /* 14 */ u8 b14;
    /* 15 */ u8 p15[0x3B];
    /* 50 */ f32 f50;
    /* 54 */ f32 f54;
    /* 58 */ u8 p58[8];
    /* 60 */ f32 f60;
    /* 64 */ u8 p64[4];
    /* 68 */ f32 f68;
    /* 6C */ u8 p6C[0xC];
    /* 78 */ s32 t78;
    /* 7C */ u8 p7C[4];
    /* 80 */ f32 f80;
    /* 84 */ u8 p84[0xC];
    /* 90 */ f32 f90;
    /* 94 */ s32 s94;
    /* 98 */ s32 s98;
    /* 9C */ s32 s9C;
    /* A0 */ s32 sA0;
    /* A4 */ u8 pA4[8];
    /* AC */ s32 sAC;
    /* B0 */ s32 sB0;
    /* B4 */ f32 fB4;
    /* B8 */ f32 fB8;
    /* BC */ f32 fBC;
    /* C0 */ f32 fC0;
} V_00350818;

typedef struct O_00350818 {
    /* 00 */ u8 p00[0x10];
    /* 10 */ f32 x;
    /* 14 */ f32 y;
    /* 18 */ f32 z;
    /* 1C */ u8 p1C[4];
    /* 20 */ u8 state;
    /* 21 */ u8 p21[2];
    /* 23 */ s8 b23;
    /* 24 */ Cls_00350818 *cls;
    /* 28 */ u8 p28[0xC];
    /* 34 */ u16 flags;
    /* 36 */ u8 p36[0xC];
    /* 42 */ u8 b42;
    /* 43 */ u8 b43;
    /* 44 */ u8 p44[4];
    /* 48 */ f32 f48;
    /* 4C */ u8 p4C[0x14];
    /* 60 */ u8 b60;
    /* 61 */ u8 p61[7];
    /* 68 */ V_00350818 *vars;
    /* 6C */ u8 p6C[0x2A];
    /* 96 */ u16 t96;
    /* 98 */ s32 s98;
    /* 9C */ u8 p9C[0xE];
    /* AA */ s16 aa;
    /* AC */ u8 pAC[0x4C];
    /* F8 */ f32 f8;
} O_00350818;

typedef struct P_00350818 {
    u8 p00[0x80];
    f32 x80;
    f32 y84;
    f32 z88;
    u8 p8C[0x25C0 - 0x8C];
    O_00350818 *p25C0;
} P_00350818;

extern P_00350818 D_1A4BE0;
extern u8 D_1A4C60[];

extern s32 func_L31_00346798(void *, f32, f32, f32);
extern void func_L31_00346B10(void *, void *, f32, f32, f32, f32, f32);
extern s32  func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_L30_0034CB68(void *, void *, s32, s32, s32, s32, f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034CDC0(f32 *, f32 *, f32 *, f32 *, f32);
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L32_00349630(void *, void *, f32 *, f32, f32, f32, f32, f32, f32, f32);
extern void func_L33_00352ED0(void *, s32);
extern s32 func_L33_00352E08(void *, s32, s32, s32);
extern void func_L33_00353800(void *, void *, s32, s32, s32, s32, s32);
extern f32 func_L33_003527C0(void *);
extern void func_L33_00352760(s32, s32, s32);
extern void func_L33_00352908(void *);
extern void func_L33_00352A08(void *);
extern void func_L33_003532D8(void *);
extern s32 func_L33_003534E0(u8 *);
extern s32 func_L01_004561B8(void *);
extern f32 func_L01_004395E0(void *);
extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0034B248(void *, void *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038CAD0(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DB48(f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);

extern f32 D_L33_001DD8E4;
extern f32 D_L33_001DD968;
extern f32 D_L33_001DD970;
extern f32 D_L33_001DD974;
extern f32 D_L33_001DD978;
extern f32 D_L33_001DD97C;
extern f32 D_L33_001DD980;
extern f32 D_L33_001DD9A4;
extern s32 D_L33_001DD9A8;
extern f32 D_L33_001DDA3C;
extern f32 D_L33_001DDA74;
extern f32 D_L33_001DDA78;
extern f32 D_L33_001DDA7C;
extern f32 D_L33_001DDA80;
extern f32 D_L33_001DDA88;
extern f32 D_L33_001DDAAC;
extern f32 D_L33_001DDAEC;
extern f32 D_L33_001DDAF0;
extern f32 D_L33_001DDB38;
extern f32 D_L33_001DDB40;
extern s32 D_L33_001DDB48;
extern f32 D_L33_001DDB70;
extern f32 D_L33_001DDB74;
extern s32 D_L33_001DDC90;
extern u8 D_L33_001DCFDC;
extern s32 D_L33_001DD85C;
__asm__(".extern D_L33_001DD8E4, 4");
__asm__(".extern D_L33_001DD968, 4");
__asm__(".extern D_L33_001DD970, 4");
__asm__(".extern D_L33_001DD974, 4");
__asm__(".extern D_L33_001DD978, 4");
__asm__(".extern D_L33_001DD97C, 4");
__asm__(".extern D_L33_001DD980, 4");
__asm__(".extern D_L33_001DD9A4, 4");
__asm__(".extern D_L33_001DD9A8, 4");
__asm__(".extern D_L33_001DDA3C, 4");
__asm__(".extern D_L33_001DDA74, 4");
__asm__(".extern D_L33_001DDA78, 4");
__asm__(".extern D_L33_001DDA7C, 4");
__asm__(".extern D_L33_001DDA80, 4");
__asm__(".extern D_L33_001DDA88, 4");
__asm__(".extern D_L33_001DDAAC, 4");
__asm__(".extern D_L33_001DDAEC, 4");
__asm__(".extern D_L33_001DDAF0, 4");
__asm__(".extern D_L33_001DDB38, 4");
__asm__(".extern D_L33_001DDB40, 4");
__asm__(".extern D_L33_001DDB48, 4");
__asm__(".extern D_L33_001DDB70, 4");
__asm__(".extern D_L33_001DDB74, 4");
__asm__(".extern D_L33_001DDC90, 4");
__asm__(".extern D_L33_001DCFDC, 1");
__asm__(".extern D_L33_001DD85C, 4");

extern f32 D_L33_001DD888[2];
extern f32 D_L33_001DD8A8[2];
extern f32 D_L33_001DD8B8[2];
extern f32 D_L33_001DD8C8[2];
extern f32 D_L33_001DD8D8[2];
extern f32 D_L33_001DD900[2];
extern f32 D_L33_001DD938[2];
extern f32 D_L33_001DD948[2];
extern f32 D_L33_001DD998[2];
extern f32 D_L33_001DD9E0[2];
extern f32 D_L33_001DDA10[2];
extern f32 D_L33_001DDA50[2];
extern f32 D_L33_001DDAC0[2];
extern s32 D_L33_001DDAD0[2];
extern f32 D_L33_001DDAF8[2];

__asm__(".extern D_L33_001DD888, 8");
__asm__(".extern D_L33_001DD8A8, 8");
__asm__(".extern D_L33_001DD8B8, 8");
__asm__(".extern D_L33_001DD8C8, 8");
__asm__(".extern D_L33_001DD8D8, 8");
__asm__(".extern D_L33_001DD900, 8");
__asm__(".extern D_L33_001DD938, 8");
__asm__(".extern D_L33_001DD948, 8");
__asm__(".extern D_L33_001DD998, 8");
__asm__(".extern D_L33_001DD9E0, 8");
__asm__(".extern D_L33_001DDA10, 8");
__asm__(".extern D_L33_001DDA50, 8");
__asm__(".extern D_L33_001DDAC0, 8");
__asm__(".extern D_L33_001DDAD0, 8");
__asm__(".extern D_L33_001DDAF8, 8");
extern f32 D_L33_001DD950;
extern u8 D_L33_001E9620[];
extern u8 *D_L33_001DFC00;
extern u8 *D_L33_001DFB1C;
extern u8 D_L33_001E1858[];
extern u8 D_L33_001E1898[];
extern u8 D_L33_001E18B8[];

void func_L33_00350818(O_00350818 *o) {
    s32 fp = 0;
    V_00350818 *v = o->vars;
    vu0_v4 vel;
    vu0_v4 sv;
    vu0_v4 sa;
    vu0_v4 sb;
    f32 sf40;
    s32 idx = 0x1761 - o->aa;
    s32 idx4;
    s32 blocked = func_L31_00346798(o, D_L33_001DD97C, D_L33_001DD980, D_L33_001DD978) != 0;
    s32 near;
    s32 free4C;
    s32 side50;
    s32 aaflag;
    s32 ok;
    s32 a2;
    s32 s20;
    s32 n;
    f32 dist;
    f32 ang;
    f32 f;
    f32 f_4;
    f32 f_3;
    f32 f_2;
    f32 f20;
    f32 f15;
    f32 f13;
    f32 f12;
    f32 len;

    if (D_1A4BE0.z88 < D_L33_001DD8E4 + o->z) {
        if (o->z - D_L33_001DD8E4 < D_1A4BE0.z88) {
            fp = 1;
        }
    }
    idx4 = idx << 2;
    near = 1;
    if (!(fabs_asm(D_1A4BE0.x80 - o->x) < *(f32 *)((u8 *)D_L33_001DD8D8 + idx4))) {
        near = 0;
    }
    free4C = 0;
    if (v->sA0 == -1 || func_00382380(&D_1A4BE0.x80, v->sA0, 0) != 0) {
        free4C = v->sB0 == 0;
    }
    side50 = 1;
    ang = fabs_asm(func_0038DB00(D_L33_001DD97C, o->f8));
    if (!(ang < fabs_asm(func_0038DB00(D_L33_001DD980, o->f8)))) {
        side50 = 0;
    }
    dist = func_L01_004395E0(o);
    aaflag = o->aa == 0x175F;
    qzero(&vel);
    vel.z = *(f32 *)((u8 *)D_L33_001DD998 + idx4);
    if (o->state == 0) {
        func_L33_003532D8(o);
        if (v->s9C != -1) {
            func_L33_00352ED0(o, 0xF);
        } else {
            func_L33_00352ED0(o, 5);
        }
    }
    func_L33_00352A08(o);

    switch (o->state) {
    case 1:
        if (func_L01_004561B8(o)) {
            *(u128_00350818 *)&v->f80 = *(u128_00350818 *)D_1A4C60;
            v->f60 = 0.0f;
            o->t96 = 0;
        }
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, D_L33_001DD968, 1, 1, 1, 0);
        if (*(f32 *)((u8 *)D_L33_001DD8A8 + idx4) <= dist && dist <= *(f32 *)((u8 *)D_L33_001DD8B8 + idx4)) {
            func_L30_0034CB68(o, &v->f60, 1, 1, 0, 0, (f32)v->b14, *(f32 *)((u8 *)D_L33_001DD8C8 + idx4));
        }
        o->t96++;
        if (o->t96 < 0x15) {
            break;
        }
        if (!(o->b60 & 2) && !(*(f32 *)((u8 *)D_L33_001DD888 + idx4) <= dist)) {
            break;
        }
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (func_00382498(0, 1) == 0) {
            goto go_D;
        }
        if (!free4C) {
            goto go_5;
        }
        goto L350B68;
    case 0x42:
        if (func_L01_004561B8(o)) {
            v->t78 = *(s32 *)((u8 *)D_L33_001DDAD0 + idx4);
            D_L33_001DD85C = D_L33_001DD85C + 3 - idx;
        }
        if (func_0038CAD0(&v->t78) == 0) {
            func_L30_0034C8A8(D_L33_001E1858, o);
            func_L30_0034C8A8(D_L33_001E1898, o);
            o->b23 = (s32)((f32)v->t78 * 128.0f / (f32)*(s32 *)((u8 *)D_L33_001DDAD0 + idx4));
            func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, *(f32 *)((u8 *)D_L33_001DD900 + idx4), 1, 1, 1, 0);
        } else {
            sv.z = D_L33_001DDB38;
            sv.x = *(f32 *)((u8 *)D_L33_001DD998 + idx4) * 5.0f / (2.0f * D_L33_001DDB38);
            s20 = (o->aa ^ 0x1761) == 0 ? 1 : 2;
            if (D_1A4BE0.x80 < o->x) {
                sv.x = -sv.x;
            }
            if (o->aa != 0x175F) {
                if (o->aa == 0x1760) {
                    func_003A52A0(6, 0, o);
                } else {
                    func_003A52A0(7, 0, o);
                }
                sv.x *= func_003824E0(0.8f, 1.2f);
                func_L33_00353800(&o->x, &sv, s20, -1, -1, -1, 1);
                sv.x *= func_003824E0(0.4f, 0.6f);
                func_L33_00353800(&o->x, &sv, s20, -1, -1, -1, 1);
            }
            qzero(&v->f60);
            func_L33_00352760(0, o->aa, 0);
            func_003C2880(o);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            v->t78 = *(s32 *)((u8 *)D_L33_001DDAD0 + idx4);
            func_003A52A0(aaflag + 5, 0, o);
            func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, *(f32 *)((u8 *)D_L33_001DD900 + idx4), 1, 1, 1, 1);
        }
        if (o->b42 == o->b43) {
            func_L32_00349630(o, &o->x, &*(f32 *)((u8 *)D_L33_001DD938 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), v->f68, *(f32 *)((u8 *)D_L33_001DD998 + idx4),
                              *(f32 *)((u8 *)D_L33_001DD948 + idx4), *(f32 *)((u8 *)D_L33_001DD938 + idx4), 0.0f, -1.0f);
        } else {
            o->f48 = 1.0f;
        }
        if (func_0038CAD0(&v->t78) == 0) {
            func_L30_0034C8A8(D_L33_001E1858, o);
            func_L30_0034C8A8(D_L33_001E1898, o);
        }
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, *(f32 *)((u8 *)D_L33_001DD900 + idx4), 1, 1, 1, 1);
        if (!(o->b60 & 2)) {
            if (aaflag) {
                if (v->f68 <= 0.0f && D_L33_001DD950 <= dist) {
                    goto go_42;
                }
            }
            if (idx < 2) {
                if (v->f68 <= 0.0f && *(f32 *)((u8 *)D_L33_001DD948 + idx4) <= dist && ok) {
                    goto go_42;
                }
            }
            break;
        }
    go_42:
        func_L33_00352ED0(o, 0x42);
        break;
    case 3:
        if (func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 100.0f, 0.0f, D_L33_001DD968, 1, 1, 1, 0)) {
            func_L33_00352ED0(o, 0xB);
        }
        break;
    case 4:
        if (func_L01_004561B8(o)) {
            v->t78 = *(s32 *)((u8 *)D_L33_001DDAD0 + idx4);
            func_003A52A0(aaflag + 3, 0, o);
            func_003A52A0(aaflag | 4, 0, o);
            func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, *(f32 *)((u8 *)D_L33_001DD9E0 + idx4), 1, 1, 1, 0);
        }
        if (func_0038CAD0(&v->t78) == 0) {
            func_L30_0034C8A8(D_L33_001E1858, o);
        }
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, 0.0f, *(f32 *)((u8 *)D_L33_001DD9E0 + idx4), 1, 1, 1, 0);
        if (!(o->b60 & 2)) {
            if (!(*(f32 *)((u8 *)D_L33_001DDA10 + idx4) < dist)) {
                break;
            }
            if (o->b42 != o->b43) {
                break;
            }
        }
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (!free4C) {
            goto go_5;
        }
        if (!fp) {
            goto go_6;
        }
        goto L350B70;
    case 5:
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, D_L33_001DDB40, v->fB4, 1, 1, 1, 0);
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (free4C && fp) {
            goto L350B70;
        }
        if (!(o->b60 & 2)) {
            break;
        }
        *(u128_00350818 *)&v->f80 = *(u128_00350818 *)&o->x;
        f20 = v->f80;
        f = -4.0f;
        if (func_L33_003534E0((u8 *)o)) {
            f = 4.0f;
        }
        v->f80 = f20 + f;
        goto go_E;
    case 6:
        if (func_L01_004561B8(o)) {
            func_L33_00352908(o);
            v->t78 = 0;
        }
        *(u128_00350818 *)&sv = *(u128_00350818 *)&v->f80;
        sv.x = func_L33_003527C0(o);
        func_L31_00346B10(o, &v->f60, sv.x, D_L33_001DD970, v->fB8, v->fB4, v->fB4);
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, v->fB8, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        f_2 = D_L33_001DDA3C * func_0038CEA8(&v->f60) / *(f32 *)((u8 *)D_L33_001DDAC0 + idx4);
        o->f48 = f_2;
        if (5.0f < f_2) {
            o->f48 = 5.0f;
        } else if (f_2 < 0.5f) {
            o->f48 = 0.5f;
        }
        if (func_0038CAD0(&v->t78)) {
            if (D_L33_001DCFDC == 0) {
                func_L03_0034B248(D_L33_001E18B8, o);
            }
            v->t78 = D_L33_001DDC90;
        }
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (free4C && fp) {
            goto L350B70;
        }
        if (func_0038CF00(&v->f80, &o->x) < D_L33_001DD970) {
            goto go_5;
        }
        if (func_L33_00352E08(o, side50, blocked, 0)) {
            goto go_5;
        }
        break;
    case 7:
        if (func_L01_004561B8(o)) {
            qzero(&v->f60);
        }
        if (D_L33_001DDAF0 < dist && dist < D_L33_001DDAEC) {
            *(u128_00350818 *)&sv = *(u128_00350818 *)&v->f50;
            *(u128_00350818 *)&sb = *(u128_00350818 *)(D_L33_001DFC00 + (v->s9C << 7) + 0x30);
            func_003C4098(&o->x, &sv, &sb, (dist - D_L33_001DDAF0) / (D_L33_001DDAEC - D_L33_001DDAF0));
            if (D_L33_001DDAF0 + D_L33_001DDAEC < dist + dist) {
                if (v->s98 != -1) {
                    func_L01_00456230(D_L33_001DFB1C + (v->s98 << 8), 1);
                }
            }
        } else if (D_L33_001DDAEC < dist) {
            func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        }
        if (o->b60 & 2) {
            goto go_copyE;
        }
        break;
    case 8:
        if (func_L01_004561B8(o)) {
            func_L30_0034CDC0(0, 0, 0, &sf40, 1.0f);
            *(u128_00350818 *)&sa = *(u128_00350818 *)&o->x;
            *(u128_00350818 *)&sb = *(u128_00350818 *)&o->x;
            f_3 = *(f32 *)(D_L33_001DFC00 + (v->s9C << 7) + 0x30);
            sa.y = D_1A4BE0.y84;
            sa.x = f_3;
            sa.z = sf40;
            sb.x = f_3;
            sb.y = D_1A4BE0.y84;
            if (func_003D3CB0(&sa, &sb, 2, 0, 0) == 0) {
                goto go_42;
            }
            sf40 = *(f32 *)(D_L33_001E9620 + 8) + D_L33_001DDA88;
            qzero(&v->f60);
            v->f68 = sqrt_asm(fabs_asm(2.0f * D_L33_001DD9A4 * (sf40 - o->z)));
            o->t96 = (s32)sqrt_asm(fabs_asm((sf40 - o->z) * 2.0f / D_L33_001DD9A4));
            v->t78 = o->t96;
            v->f60 = (*(f32 *)(D_L33_001DFC00 + (v->s9C << 7) + 0x30) - v->f50) / (f32)o->t96;
            v->s94 = 0;
            if (o->x < D_1A4BE0.p25C0->x) {
                f12 = D_L33_001DD980;
            } else {
                f12 = D_L33_001DD97C;
            }
            o->f8 = func_0038DB48(f12);
        }
        n = o->t96 - 1;
        if (n < 0) {
            n = 0;
        }
        o->t96 = n;
        o->y = func_003C4088(v->f54, D_1A4BE0.y84, 1.0f - (f32)o->t96 / (f32)v->t78);
        if (v->f68 < 0.0f) {
            o->s98 = o->cls->s10;
        }
        func_L32_00349630(o, &o->x, D_L33_001DDAF8, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), v->f68, D_L33_001DD9A4, D_L33_001DDA78,
                          D_L33_001DDA7C, 0.0f, -1.0f);
        qzero(&sv);
        sv.z = D_L33_001DD9A4;
        if (D_L33_001DDA7C <= dist) {
            v->f90 = o->x < D_1A4BE0.x80 ? D_L33_001DD980 : D_L33_001DD97C;
            if (D_L33_001DD978 < fabs_asm(func_0038DB00(v->f90, o->f8))) {
                f13 = v->fBC * D_L33_001DDB70;
                f15 = v->fC0 * D_L33_001DDB70;
                a2 = 1;
                if (v->f90 == 0.0f) {
                    a2 = -1;
                }
                func_L01_00448890(&o->f8, &v->s94, a2, v->f90, f13, f13, f15);
            }
            f15 = 0.0f;
        } else {
            f15 = 100.0f;
        }
        func_L30_0034D1E8(o, &o->x, &v->f60, &sv, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, f15, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        if (D_L33_001DDA80 <= dist) {
            goto go_copyE;
        }
        if (o->b60 & 2) {
            goto go_copyE;
        }
        break;
    case 9:
        func_L01_004561B8(o);
        if (func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, v->fB8, D_L33_001DDB40, 0.0f, 1, 1, 1, 0)) {
            func_L33_00352ED0(o, 0xA);
        }
        break;
    case 0xA:
    case 0xB:
        if (func_L01_004561B8(o)) {
            v->s94 = 0;
        }
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        v->f90 = o->x < D_1A4BE0.x80 ? D_L33_001DD980 : D_L33_001DD97C;
        if (D_L33_001DD978 < fabs_asm(func_0038DB00(v->f90, o->f8))) {
            f13 = v->fBC * D_L33_001DDB70;
            f15 = v->fC0 * D_L33_001DDB70;
            a2 = 1;
            if (v->f90 == 0.0f) {
                a2 = -1;
            }
            func_L01_00448890(&o->f8, &v->s94, a2, v->f90, f13, f13, f15);
        }
        if (!ok) {
            func_L33_00352ED0(o, 3);
        }
        if (!(o->b60 & 2)) {
            if (o->state == 0xB && *(f32 *)((u8 *)D_L33_001DDA50 + idx4) <= dist) {
                goto LA34;
            }
            if (o->state != 0xA) {
                break;
            }
            if (!(D_L33_001DDA74 <= dist)) {
                break;
            }
        }
    LA34:
        if (blocked && near && fp) {
            goto go_1;
        }
        if (!free4C) {
            goto go_5;
        }
        goto L350B68;
    case 0xC:
        if (func_L01_004561B8(o)) {
            v->t78 = 0;
        }
        *(u128_00350818 *)&v->f80 = *(u128_00350818 *)D_1A4C60;
        *(u128_00350818 *)&sv = *(u128_00350818 *)D_1A4C60;
        sv.x = func_L33_003527C0(o);
        f20 = v->fB8;
        f15 = v->fB4;
        {
            O_00350818 *pl = *(O_00350818 **)(D_1A4C60 + 0x2540);
            if ((pl->f8 < 1.5707964f && o->x < pl->x) || (1.5707964f <= pl->f8 && pl->x < o->x)) {
                f20 *= D_L33_001DDAAC;
                f15 *= D_L33_001DDAAC;
            }
        }
        func_L31_00346B10(o, &v->f60, sv.x, D_L33_001DD970, f20, f15, f15);
        f12 = *(f32 *)((u8 *)D_L33_001DDAF8 + idx4);
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, f12, f12, 100.0f, f20, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        if (func_0038CEA8(&v->f60) < D_L33_001DD974 && fabs_asm(sv.x - o->x) < *(f32 *)((u8 *)D_L33_001DDAF8 + idx4)) {
            if ((o->b43 - 1 >= 2U && o->b43 != 9) || (o->b60 & 2)) {
                if (func_00382498(0, 2) == 0) {
                    if (o->b43 != 1) {
                        func_003C3A10(o, 1, (s32)func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                    }
                } else if (func_00382498(0, 1) == 0) {
                    if (o->b43 != 2) {
                        func_003C3A10(o, 2, (s32)func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                    }
                } else if (o->b43 != 9) {
                    func_003C3A10(o, 9, (s32)func_003824E0(0.0f, 4.0f), D_L33_001DDB48);
                }
                o->f48 = 1.0f;
            }
        } else {
            if (o->b43 != 3) {
                func_003C3A10(o, 3, 0, (D_L33_001DDB48 * 5 + 2) / 6);
            }
            f_4 = D_L33_001DDA3C * func_0038CEA8(&v->f60) / *(f32 *)((u8 *)D_L33_001DDAC0 + idx4);
            o->f48 = f_4;
            if (5.0f < f_4) {
                o->f48 = 5.0f;
            } else if (f_4 < 0.5f) {
                o->f48 = 0.5f;
            }
        }
        if (func_0038CAD0(&v->t78)) {
            if (D_L33_001DCFDC == 0) {
                func_L03_0034B248(D_L33_001E18B8, o);
            }
            v->t78 = D_L33_001DDC90;
        }
        if (func_L33_00352E08(o, side50, blocked, 1)) {
            v->sB0 = D_L33_001DD9A8;
        }
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (!free4C) {
            goto go_5;
        }
        if (near && !fp) {
            goto go_5;
        }
        if (blocked) {
            break;
        }
        goto go_E;
    case 0xD:
        ok = func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, 0.0f, D_L33_001DDB40, 0.0f, 1, 1, 1, 0);
        if (!ok) {
            goto go_3;
        }
        if (blocked && near && fp) {
            goto go_1;
        }
        if (!(o->b60 & 2)) {
            break;
        }
        if (!free4C) {
            goto go_5;
        }
        goto L350B68;
    case 0xE:
        if (func_L01_004561B8(o)) {
            v->f90 = o->x < v->f80 ? D_L33_001DD980 : D_L33_001DD97C;
            v->f60 = 0.0f;
            v->s94 = 0;
        }
        f = func_0038DB00(v->f90, o->f8);
        f15 = v->fC0;
        if (near) {
            f15 *= D_L33_001DDB70;
        }
        f13 = v->fBC;
        if (near) {
            f13 *= D_L33_001DDB70;
        }
        if (D_L33_001DD978 < fabs_asm(f)) {
            a2 = 1;
            if (v->f90 == 0.0f) {
                a2 = -1;
            }
            func_L01_00448890(&o->f8, &v->s94, a2, v->f90, f13, f13, f15);
            if (2.0943952f < f) {
                f = 2.0943952f;
            } else if (f < -2.0943952f) {
                f = -2.0943952f;
            }
            len = func_0038CEA8(&v->f60) / *(f32 *)((u8 *)D_L33_001DDAC0 + idx4);
            f20 = func_0038D098(func_0038DB48(f));
            if (f20 < 0.0f) {
                f20 = 0.0f;
            }
            o->f48 = func_003C4088(len, D_L33_001DDB70, fabs_asm(f) / 2.0943952f);
            f20 = v->fB8 * fabs_asm(f20);
            if (func_L33_00352E08(o, side50, blocked, 0)) {
                f20 = 0.0f;
            }
            *(u128_00350818 *)&sv = *(u128_00350818 *)&v->f80;
            sv.x = func_L33_003527C0(o);
            func_L31_00346B10(o, &v->f60, sv.x, *(f32 *)((u8 *)D_L33_001DD8D8 + idx4), v->fB8, v->fB4, v->fB4);
            f = v->f60;
            if (f20 < f) {
                v->f60 = f20;
            } else if (f < -f20) {
                v->f60 = -f20;
            }
            if (func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, f20, D_L33_001DDB40, v->fB4, 1, 1, 1, 0)) {
                break;
            }
            goto go_3;
        } else {
            if (blocked && near && fp) {
                goto go_1;
            }
            if (func_003824E0(0.0f, 1.0f) < D_L33_001DDB74) {
                goto go_D;
            }
            if (!free4C) {
                goto go_5;
            }
            if (!fp) {
                goto go_6;
            }
            goto L350B70;
        }
    case 0xF:
        if (!func_L30_0034D1E8(o, &o->x, &v->f60, &vel, *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), *(f32 *)((u8 *)D_L33_001DDAF8 + idx4), 100.0f, v->fB8, D_L33_001DDB40, 0.0f, 0, 0, 0, 0)) {
            o->s98 = 0;
            o->flags = (o->flags | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
        }
        if (func_L01_00456250(o) == 0) {
            if (v->sAC != -1) {
                if (func_00382380(D_1A4C60, v->sAC, 0) == 0) {
                    if (v->sAC != -1) {
                        break;
                    }
                    goto LF65;
                }
                goto LF70;
            }
        LF65:
            if (v->sA0 == -1 || func_00382380(D_1A4C60, v->sA0, 0) == 0) {
                if (v->sAC != -1) {
                    break;
                }
                if (v->sA0 != v->sAC) {
                    break;
                }
                if (func_L30_0034D8D8(D_1A4C60, 1.5f) == 0) {
                    break;
                }
            }
        }
    LF70:
        {
            Cls_00350818 *cl = o->cls;
            o->flags = o->flags & 0xFFBE;
            o->flags = o->flags | (cl->u44 & 0x1000);
            o->s98 = cl->s10;
        }
        if (o->aa == 0x1761) {
            if (v->s98 != -1) {
                func_L33_00352ED0(o, 7);
                break;
            }
            goto go_3;
        } else if (o->aa == 0x1760) {
            func_L33_00352ED0(o, 8);
        } else {
            f12 = o->x < D_1A4BE0.p25C0->x ? D_L33_001DD980 : D_L33_001DD97C;
            o->f8 = func_0038DB48(f12);
            func_L01_00456230(D_L33_001DFB1C + (v->s98 << 8), 1);
            func_L33_00352ED0(o, 9);
        }
        break;
    default:
        break;
    }
    return;

L350B68:
    if (!fp) {
        goto go_5;
    }
L350B70:
    if (!blocked) {
        goto go_copyE;
    }
    func_L33_00352ED0(o, 0xC);
    return;
go_copyE:
    *(u128_00350818 *)&v->f80 = *(u128_00350818 *)D_1A4C60;
go_E:
    func_L33_00352ED0(o, 0xE);
    return;
go_3:
    func_L33_00352ED0(o, 3);
    return;
go_5:
    func_L33_00352ED0(o, 5);
    return;
go_6:
    func_L33_00352ED0(o, 6);
    return;
go_1:
    func_L33_00352ED0(o, 1);
    return;
go_D:
    func_L33_00352ED0(o, 0xD);
}
