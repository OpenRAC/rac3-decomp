/* US draft of func_003A1F30 (rac3-uya-decomp func_0039CEA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003A1F30 */
/* func_003A1F30: MATCH (try_func.py and try_in_context.py), src/frontbin/39BC00.c, 0x624, switch.
 * Flags: the file range's flags (S mode, default assembler); no text_parts override needed
 *   (also matches with @ps2as). Delete the INCLUDE_RODATA jtbl_0031C4B0 line when inserting (the
 *   jump table is emitted by the C). D is reached through D_1CCFD0_003A1838 (already declared earlier in
 *   39BC00.c and in symbol_addrs_resolved.txt), so no new symbol line is needed; the alternative is a new
 *   alias line D_1CCFD0_003A1F30 = 0x1CCFD0 with `extern S_39CEA8 D_1CCFD0_003A1F30;` (also matches).
 * Fix (agent, 2026-10-17): the two volume helpers are open-coded with ONE pointer variable `e`
 *   reused for &D.e[0] and &D.e[1]. Being referenced in several blocks makes `e` a global pseudo, so
 *   local-alloc no longer ties it to the dying %hi of &D.e[0] (that tie put e in $v0 and moved the
 *   gcse copy `move $s0` ahead of the lo_sum); global alloc gives retail's $a0 in both helpers.
 * Earlier notes follow. */
typedef struct {
    u32 h; s16 a; s16 b; s16 c; s16 st; s16 fl; u8 pE[2]; s16 f10; u8 p12[2]; s32 f14; s32 f18; u8 p1C[4]; s32 f20; s32 f24;
} E_39CEA8;
typedef struct {
    u8 p0[4]; s16 h4; u8 b6; u8 b7; s32 f8; u8 pC[4]; s32 f10; s32 f14;
    void (*f18)(s32, s32); s32 f1C; u8 p20[4]; s32 f24; s32 f28; s16 f2C; u8 p2E[2];
    s32 f30; s32 f34; s32 f38; s16 f3C; s16 f3E; u8 p40[4];
    E_39CEA8 e[4];
} S_39CEA8;
/* D_1CCFD0_003A1838 (0x1CCFD0) is declared earlier in 39BC00.c; reuse it so no new symbol line is needed */
#define D (*(S_39CEA8 *)&D_1CCFD0_003A1838)
__asm__(".extern D_001D6DB0, 4");
__asm__(".extern D_001D6DB4, 4");
extern f32 D_001D6DB0;
extern f32 D_001D6DB4;
extern s32 func_0038CAD0(void *);
extern void func_003A15D0(s32, s32, s32, s32 *, s32);
extern void func_003A1A28(s32, s32, s32);
extern s32 func_003A1B40(s32, s32, s32, s32);
extern void func_13C2C0(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_13C2A0(s32, s32, s32, s32, s32, s32);
extern void func_13CC40(s32);
extern s32 func_003A53E8(u32, s32);
/* func_003A1D20 declared by file context */
extern void func_003A2A90(s32, long);
extern void func_003A1930(s32, s32, s32);
extern void func_003A1838(s32, s32, s32);
extern void func_13CDF0(s32);
void func_003A1F30(void) {
    s32 x;
    s16 h;
    if (D.b7 != 0) return;
    if (!(D.e[0].fl & 0x8000) && !(D.e[0].st & 0x8000)) {
        if (D.e[0].h == 0 && (D.e[0].c & 1) && D.f3C == -1) {
            func_003A1930(D.e[0].a, D.e[0].c, D.e[0].b);
        } else if (D.e[0].h != 0 && D.e[0].h != 0xFFFFFFFF && D.e[0].st == 8) {
            func_003A1A28(D.e[0].a, D.e[0].c, D.e[0].b);
        }
    }
    if (func_0038CAD0(&D.f38) != 0 && D.f3C != -1 && D.f2C == 0) {
        if (D.e[0].a != D.f3C) {
        if (D.f3E == -1) {
            if (D.e[0].st & 0x8000) {
                D.f2C = 3;
                D.e[0].st = 5;
            } else {
                D.f34 = 15;
                D.e[3].f18 = 15;
                D.f2C = 6;
            }
            D.f38 = 300;
        } else if (func_003A1B40(D.f3C, D.f3E, D.e[0].c, D.e[0].b) != 0) {
            D.f38 = 0x1A4;
        }
        } else D.f3C = -1;
    }
    if (D.f24 >= 0) {
        if (D.e[2].h == 0) {
            func_003A15D0(D.f24, 0, D.f28, &D.e[2].h, 0x400);
            D.f28 = 0;
            D.f24 = -1;
        } else if (D.e[2].st != 6 && D.e[2].st != 7) {
            D.e[2].st = 5;
        }
    }
    if (D.e[0].st != 9 && D.e[0].h != 0xFFFFFFFF && !(D.e[0].fl & 0x8000) && !(D.e[0].st & 0x8000)
        && (D.f3E == -1 || (!(D.e[3].fl & 0x8000) && !(D.e[3].st & 0x8000)))) {
        switch (D.f2C) {
        case 6: {
            u32 old = D.e[0].h;
            D.e[0].h = 0xFFFFFFFF;
            func_13C2C0(old, 5, D.e[0].b * D.e[3].f18 / D.f34, 0, 0, 0, func_003A2A90, (long)&D.e[0].h);
            if (func_0038CAD0(&D.e[3].f18) != 0) {
                D.f2C = 3;
                D.e[0].st = 5;
            }
            break;
        }
        case 2: {
            s32 v = D.e[0].b * (D.f34 - (D.f30 - D.e[3].f18)) / D.f34;
            if (v <= 0 || !((D.e[3].st == 4 && D.e[3].f10 != 0) || D.e[3].h != 0) || D.e[0].h == 0) {
                D.f2C = 3;
                D.e[0].st = 5;
            } else if (D.e[0].st != 9) {
                u32 old = D.e[0].h;
                D.e[0].h = 0xFFFFFFFF;
                func_13C2C0(old, 5, v, 0, 0, 0, func_003A2A90, (long)&D.e[0].h);
            }
            break;
        }
        case 3:
            if (D.e[0].st == 0 && (D.e[3].f10 != 0 || D.e[3].h == 0)) {
                func_003A1838(D.f3C, D.e[0].c, D.e[0].b);
                D.f3C = -1;
                D.f2C = 4;
            }
            break;
        case 4:
            if (D.e[0].st == 3 && (D.e[3].f18 < D.f34 || D.e[3].st != 4 || (D.e[3].f10 == 0 && D.e[3].h == 0))) {
                func_13CC40(D.e[0].h);
                D.e[0].st = 8;
                D.f2C = 5;
            }
            break;
        case 5:
            if (D.e[3].st != 4 || D.e[3].f10 == 0) D.f2C = 0;
            break;
        }
    }
    {
        E_39CEA8 *e;
        x = D_001D6DB0 * 1024.0f;
        e = &D.e[0];
        if (e->st == 4 && D.e->h != 0xFFFFFFFF) func_13C2A0(D.e->h, 1, x, 0, 0, 0);
        x = D_001D6DB4 * 1024.0f;
        e = &D.e[1];
        if (e->st == 4 && e->h != 0xFFFFFFFF && e->f20 != -1) func_003A53E8(e->f20, x);
    }
    func_003A1D20((void *)&D.e[0].h);
    func_003A1D20((void *)&D.e[3].h);
    func_003A1D20((void *)&D.e[1].h);
    func_003A1D20((void *)&D.e[2].h);
    if (D.e[2].st == 2 && D.e[2].f24 < 0) {
        if (D.e[1].st != 6 && D.e[1].st != 7) D.e[1].st = 5;
        if (D.e[2].st != 6 && D.e[2].st != 7) D.e[2].st = 5;
    } else {
        D.e[2].f24--;
    }
    if (D.b6 != 0) {
        if (((s32 (*)(s32))func_13CDF0)(1) == 0) {
            D.h4 = 0;
            D.b6 = 0;
            if (D.f18 != 0) {
                void (*fn)(s32, s32) = D.f18;
                s32 a = D.f1C;
                D.f18 = 0;
                D.f1C = 0;
                fn(a, 0);
            }
        }
    } else {
        h = D.h4;
        if (h == 2) {
            D.h4 = 0;
            func_003A2598(D.f14, D.f8, D.f10);
            if (D.h4 == 0) D.h4 = h;
        }
    }
}
#undef D
/* localdecomp:end func_003A1F30 */
