/* func_L04_00325C08: Promises (task 2790, 2026-11-21; retried in task 2907, 2026-11-22), from upstream's
 * nonmatching/functional/func_L04_00325C08.c.
 * Near miss: 381 differences (tools/check.py), level 04, with -mvu0-use-vf0-vf2 @ps2as on L04_00325C08.c
 * (the file has neither yet; it has no other function). The file's own line does not compile it (VU0
 * "vf17 spilled"). NM-R5's line for L04_00325460.c (without -fopt-stack) is worse here: retail saves with
 * sd in a 0xF0 frame, so -fopt-stack stays.
 * Task 2790's changes from the functional draft: the 210000.0f constant written at each use, each spawned
 * particle in its own block-scoped pointer, the `v += off` / `pos += off` triples as vec_add_ab().
 * Task 2907's changes (544 -> 381):
 * - the player table as an array of 0x460-byte records indexed by a plain `extern s32 D_001D52F0`, as
 *   NM-R5's sibling func_L04_00325460 has it (544 -> 390);
 * - func_L01_0046FB40 declared with its eighth integer argument after the three floats, an
 *   EABI-equivalent order that upstream's C also uses for this callee: retail moves $t3 last, into the
 *   jal delay slot (390 -> 381).
 * Left:
 * - register roles swap throughout: $s1/$s2 for the hoisted divisor 6 and the vars pointer (the RTL
 *   dump's global allocation takes the vars pointer before the 6), $s6/$s7 for 0xF4 and `off`,
 *   $f20/$f21, and the loop counter of the two opening loops ($s4 here, $s0 in retail);
 * - burst loop 1 computes &D_L04_001E2840[D_001D52F0] with mtlo + madd, ours with mult + addu, which
 *   shifts that loop by a word. Loops 2 and 3 have mult + addu in retail too, with the table's base
 *   hoisted into $s5 (ours reloads it). No tried shape produces madd, not even L01_003041A0.c's matched
 *   `(D_L01_002C5600 + D_001425C0[0x11])` compiled on its own.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_00325C08 */
__asm__(".extern D_L04_001DC7B0, 4");
__asm__(".extern D_L04_001DC7A8, 4");
__asm__(".extern D_L04_001DC7AC, 4");
typedef int u128_00325C08 __attribute__((mode(TI)));
extern s32 D_L04_001DC7B0;
extern f32 D_L04_001DC7A8;
extern f32 D_L04_001DC7AC;
typedef struct {
    f32 x, y, z, w;
    u8 pad10[0x460 - 0x10];
} Pl_325C08;
extern s32 D_001D52F0;
extern Pl_325C08 D_L04_001E2840[];
extern u8 D_001D66B0[];
extern u8 *D_L04_0021FD88[];
extern u8 *D_L04_0021FC18[];
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00470668(void *, void *, s32, f32);
extern void func_L01_002F9578(void *, void *, void *, s32, s32, s32, s32, s32, f32);
extern void func_L01_0044AF78(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_00382760(void *, f32, f32, f32);
void func_L04_00325C08(u8 *m, void *basis, f32 *off, f32 extra) {
    u8 *vars = *(u8 **)(m + 0x68);
    f32 pos[4] __attribute__((aligned(16)));
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 fa, fb, scale;
    f32 ang, spd, up, r;
    s32 i, n, rs, sgn;
    u8 *p;
    Pl_325C08 *pl;

    scale = *(f32 *)(vars + 0x14);
    fa = D_L04_001DC7A8 * scale * 210000.0f;
    fb = D_L04_001DC7AC * scale * 210000.0f;
    {
        u8 *q1 = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 100, 0, fa, fb, 0.0f, 0);
        if (q1) {
            q1[2] = *D_L04_0021FD88[0];
            q1[9] = 0xF0;
        }
    }
    {
        u8 *q2 = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x63F7, 0, 100, 0, fa, fb, 0.0f, 0);
        if (q2) {
            q2[2] = *D_L04_0021FD88[0];
            q2[9] = 0xF0;
        }
    }
    for (i = 1; i >= 0; i--) {
        {
            u8 *q3 = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, fa, fb, 0.0f, 0);
            if (q3) {
                q3[2] = D_L04_0021FC18[0x170 / 4][5];
                q3[9] = 0xF0;
            }
        }
    }
    for (i = 1; i >= 0; i--) {
        {
            u8 *q4 = func_L01_0046FB40(m + 0x10, off, (D_L04_001DC7B0 * 5 + 2) / 6, 0x388EF7, 0, 0x7F, 0, fa, fb, 0.0f, 0);
            if (q4) {
                q4[2] = D_L04_0021FC18[0x170 / 4][6];
                q4[9] = 0xF0;
            }
        }
    }

    /* burst type 1 (count at +0x20): two particles per round */
    for (i = 0; i < *(s32 *)(vars + 0x20); i++) {
        pl = &D_L04_001E2840[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            u8 *q5 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x407FFF, rs, 0x7F, 0x7F, 1, up * 210000.0f, *(f32 *)(vars + 0x14) * 0.01f * 210000.0f, 0.00584f);
            if (q5) {
                q5[9] = 0xF4;
            }
        }
        {
            u8 *q6 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x20FF, -(rs * 2), 0x30, 0x30, 0, up * 6.0f * 210000.0f, *(f32 *)(vars + 0x14) * 0.02f * 210000.0f, 0.00584f);
            if (q6) {
                q6[2] = *D_L04_0021FC18[0xD4 / 4];
                q6[9] = 0xF4;
            }
        }
    }

    /* burst type 2 (count at +0x24) */
    for (i = 0; i < *(s32 *)(vars + 0x24); i++) {
        pl = &D_L04_001E2840[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.75f, 1.5f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            u8 *q7 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x8FFF, rs, 0x7F, 0x7F, 5, up * 210000.0f, *(f32 *)(vars + 0x14) * 0.01f * 210000.0f, 0.00584f);
            if (q7) {
                q7[9] = 0xF4;
            }
        }
    }

    /* burst type 3 (count at +0x28) */
    for (i = 0; i < *(s32 *)(vars + 0x28); i++) {
        pl = &D_L04_001E2840[D_001D52F0];
        ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
        rs = (s32)func_L01_00443A18(2.0f, 5.0f);
        n = func_00382498(30, 50);
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.1f) * *(f32 *)(vars + 0x14);
        up = func_003824E0(0.6f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(9.0f, 12.0f) * *(f32 *)(vars + 0x14);
        ang = func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.3962634f));
        spd = spd * 0.020000001f;
        v[0] = func_0038D098(ang) * spd;
        v[1] = func_0038D0B0(ang) * spd;
        v[2] = 0.0f;
        spd = func_003824E0(0.0f, 12.0f) * *(f32 *)(vars + 0x14);
        v[2] = spd * 0.020000001f;
        vec_add_ab(v, v, off);
        {
            u8 *q8 = func_L01_004713C8(pos, v, (n * 5 + 2) / 6, 0x3064FF, rs, 0x7F, 0x7F, 3, up * 210000.0f, *(f32 *)(vars + 0x14) * 2100.0f, 0.00584f);
            if (q8) {
                q8[9] = 0xF4;
            }
        }
    }

    /* burst type 4 (count at +0x30): sparks along the basis vectors at m+0xC0 / m+0xD0 */
    for (i = 0; i < *(s32 *)(vars + 0x30); i++) {
        r = func_003824E0(15.0f, 20.0f) * *(f32 *)(vars + 0x14);
        func_0038CE20(pos, m + 0xC0, r * 0.020000001f);
        spd = func_L01_00443A18(0.2617994f, 1.3962634f);
        up = func_L01_00443A18(0.2617994f, 1.3962634f);
        func_003C4840(w, m + 0xD0, spd);
        func_0038D850(v, pos, w);
        func_003C4840(w, m + 0xC0, up);
        func_0038D850(v, v, w);
        vec_add_ab(v, v, off);
        n = func_00382498(20, 35);
        {
            u8 *q9 = func_L01_00470668(m + 0x10, v, (n * 5 + 2) / 6, 0.00584f);
            if (q9) {
                q9[9] = 0xF4;
            }
        }
    }

    if (*(s32 *)(vars + 0x34) != 0) {
        *(u128_00325C08 *)v = 0;
        v[2] = *(f32 *)(vars + 0x14) * 8.0f * 0.020000001f;
        *(u128_00325C08 *)pos = *(u128_00325C08 *)v;
        vec_add_ab(pos, pos, off);
        func_L01_002F9578(m, m + 0x10, pos, 0xD, 0xFF, 0, 0, 0x28, *(f32 *)(vars + 0x14) * 3.5f);
    }

    func_L01_0044AF78(m, D_001D66B0, m + 0x10, 0, 0, 0, -1, 0, 0, -1, 0, 0x1010001, 0.0f, 0.0f, 0.0f, 0.0f, 9.0f, 0.0f, extra * *(f32 *)(vars + 0x14));

    sgn = 1;
    pl = &D_L04_001E2840[D_001D52F0];
    ang = func_0038D160(pl->x - *(f32 *)(m + 0x10), pl->y - *(f32 *)(m + 0x14));
    for (i = 0; i < *(s32 *)(vars + 0x2C); i++) {
        sgn = -sgn;
        pos[0] = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[1] = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        pos[2] = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 1.0f) * *(f32 *)(vars + 0x14);
        spd = func_003824E0(0.020000001f, 0.040000003f) * *(f32 *)(vars + 0x14);
        up = func_L01_00443A18(0.0f, 1.3962634f);
        r = func_L01_00443A18(0.0f, 1.5707964f);
        func_00382760(v, spd, func_0038DAB8(ang, r), up);
        vec_add_ab(v, v, off);
        {
            u8 *q10 = func_L01_004669B0(pos, 0.0f, 1.0f, 1.01f, *(f32 *)(vars + 0x14) * 1.5f * 210000.0f, sgn, v, 0x7F60A0FF, 0);
            if (q10) {
                n = func_00382498(40, 70);
                q10[9] = 0xF4;
                *(s16 *)(q10 + 0xA) = (n * 5 + 2) / 6;
                *(s32 *)(q10 + 0x20 + 4) = 3;
                n = func_00382498(1, 10);
                *(u8 *)(q10 + 0x20 + 0xA) = 0x40;
                *(f32 *)(q10 + 0x20 + 0x1C) = (f32)((n * 5 + 2) / 6);
                *(u8 *)(q10 + 0x20 + 0xB) = *(u8 *)(q10 + 0xA);
            }
        }
    }
}
/* localdecomp:end func_L04_00325C08 */
