/* PAL draft (2026-11-21, Promises fleet rac3-w2; retried 2026-11-22 by NM-R10, rac3-w3, and 2026-11-23 by RT-G,
 * rac3-w3): func_L04_0035BC10 (1444 B; levels 04 06 11 16 19 22), written from retail. check.py at level 04 with
 * its file's line (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as): 84 diff (was 130;
 * 210 before NM-R10). The same count with --no-context.
 * The 2026-11-23 retry, each step measured on top of the one before:
 *  - q = s + 0xB0 assigned just before `if (*(s + 4) != 0)`, used only by the else branch (w = q), with the tail's
 *    second func_L04_0035B908 call keeping its plain s + 0xB0: gcse then reuses q's value for the tail, retail's
 *    single s + 0xB0 spilled to 0x34($sp), and s + 0x80/0x40/0xE0/0x44 get $s5/$s6/$s7/$fp. That also cures the
 *    s/p ($s1/$s2) swap and the else branch's vf1/vf2 roles: 130 -> 86;
 *  - the loop's increments in the for header (`i++, p += 0x30, r += 0x10`), retail's order: 86 -> 84.
 * What still differs (one block, the rest is a one-instruction shift): retail computes s + 0xB0 into $v0, stores
 * it to 0x34($sp) and reloads it into $s1 (`lw $s1, 0x34($sp)` in the delay slot of the branch to the else
 * branch); this C keeps q in $s1 from its assignment (`addiu $s1, $s2, 0xb0`, then the 0x34 store is a copy), so
 * the reload is missing and reorg copies the addiu into an earlier beql's delay slot.
 * Tried on 2026-11-23 without gain: vec_add_ba in the else branch (130, no change); q used by both the else branch
 * and the tail (187; q then takes $s5 and s + 0x44 is spilled); q assigned earlier (before the s + 4 test 188,
 * after i = -1 322, before p = s + 0x50 316, before func_L04_0035A6E0 280, before the func_L04_0035B838 test 280;
 * with the tail's plain s + 0xB0: 213, 213, 291) or inside the s + 4 block (86-87); the else branch using
 * s + 0xB0 with the tail using q (157-158); the else branch using q directly (84, no change) or a separate
 * w + 0x10 pointer (144); the loop with the increments in the body in either order (130-131), as a do-while
 * counting down (89 with q) or a for counting down (130).
 * The 2026-11-22 retry found, each measured alone on top of the one before:
 *  - the loop's r is a copy of an s + 0x110 pointer taken early (r0; retail `move $s0, $s7` before the loop): 210 -> 183;
 *  - the -1 of the 0x4C/0x20 tests lives in the loop counter i (`i = -1`; retail keeps it in $s3, the counter's
 *    register), and p + 0x10 is its own pointer p2: m + 0xC0, -1, p + 0x10 and m + 0x10 get retail's
 *    $s0/$s3/$s3/$s5 and the first 40/80 select loads D_001D545C before the 0xB as retail does: 183 -> 168;
 *  - the last block reads *(s + 4) once into o and dereferences +0x24 in each branch, so the two stores cross-jump
 *    as in retail: 168 -> 130.
 * Tried then without gain: a separate m + 0xC0 pointer, an m + 0x10 pointer, the declaration order, p0 copies of
 * s + 0x50 (294 when the top uses it), p = s + 0xB0 reused in the else branch (130), p2 = s + 0x60 (266), the
 * 40/80 select as a call argument (168) or if/else (183), a fresh temporary for D_001D545C (182).
 * Older notes (2026-11-21): s + 0x110 hoisted (229 -> 211), s + 0xB0 hoisted (312), a separate pointer for the
 * 0x35A4F8 loop (329), an indexed loop (298).
 */
#include "common.h"
#include "vu0.h"

extern void func_L01_00367260(void *, s32, s32, void *, void *, s32);
extern void func_L01_00367430(void *, f32);
extern void func_L04_0037A5B8(void *, void *, s32);
extern s32 func_L04_0035BA58(void *, void *);
extern void func_L04_0035B908(void *, void *, void *, void *);
extern s32 func_L04_003796E0(u8 *);
extern void func_L01_0038B988(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040BE10(void *, void *);
extern void func_L04_0035A6E0(void *, void *, s32, s32);
extern s32 func_L04_0035B838(void *, void *, s32);
extern u8 *func_L04_003776D8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L04_0035B5D8(void *, void *, void *);
extern void func_L04_00377720(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L04_00379CC0(u8 *a0, void *out);
extern s32 func_L04_0035A5B8(void *, void *, void *);
extern void func_L04_003796C8(u8 *);
extern u8 *func_L04_00379410(void *);
extern void func_L04_003776F8(void *, void *);
extern void func_L04_0035A4F8(void *, void *);
extern void func_L04_0035B430(void *, u8 *);
extern void func_L04_0035C1B8(void *, void *);
extern s32 D_001D545C;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
extern u8 *D_L04_001DFE80;
extern s32 D_L04_001DF940;
extern f32 D_L04_001DD50C;

void func_L04_0035BC10(u8 *m, u8 *s) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *p;
    u8 *t;
    u8 *r;
    u8 *r0;
    u8 *o;
    s32 hit;
    s32 chk;
    s32 i;
    f32 f;
    u8 *p2;
    u8 *q;

    if (*(s32 *)s != 0) {
        func_L01_00367260(m, -1, 0, m + 0x10, m + 0x10, -1);
        func_L01_00367430(m, 0.0f);
        *(s32 *)s = 0;
    }
    if (*(u8 **)(s + 8) != 0) {
        func_L04_0037A5B8(*(u8 **)(s + 8), m, 0);
        *(s32 *)(s + 8) = 0;
    }
    if (func_L04_0035BA58(m, s) == 0) {
        func_L04_0035B908(m, s + 0x50, s + 0x80, s + 0x40);
        func_L04_0035B908(m, s + 0xB0, s + 0xE0, s + 0x44);
        return;
    }
    if (*(u8 **)(s + 4) != 0 && func_L04_003796E0(*(u8 **)(s + 4)) != 0) {
        func_L01_0038B988(*(u8 **)(s + 4));
        *(s32 *)(s + 4) = 0;
    }
    i = -1;
    if (*(s32 *)(s + 0x4C) == i) {
        func_0038D308(m + 0xC0, m + 0xF0);
    }
    p = s + 0x50;
    r0 = s + 0x110;
    if (*(s32 *)(s + 0x20) == i) {
        func_0038CE20(p, m + 0xC0, 0.33f);
    } else if (*(s32 *)(s + 0x20) != 0) {
        func_0038CE20(p, m + 0xC0, 0.23f);
    } else {
        func_0038CE20(p, m + 0xC0, 0.33f);
    }
    vec_add_ab(p, p, m + 0x10);
    p2 = p + 0x10;
    f = D_001D545C == 0xB ? 80.0f : 40.0f;
    func_0038CE20(p2, m + 0xC0, f);
    vec_add_ba(p2, p2, m + 0x10);
    func_L01_0040BE10(m + 0x10, p2);
    func_L04_0035A6E0(m, s, 0, 0);
    if (func_L04_0035B838(m, s, 0) != 0) {
        hit = 0;
        t = func_L04_003776D8(m);
        if (t != 0 && *(s16 *)(t + 0xAA) == 0x1860 && t != *(u8 **)(s + 8)) {
            if (*(s32 *)(*(u8 **)(t + 0x68) + 4) != -1) {
                hit = 1;
            } else {
                o = *(u8 **)(*(u8 **)(t + 0xB8) + 0x68);
                if (func_L01_0040E548(o + 0x2C0, D_L04_001DFE80 + (*(s32 *)(o + 0x13C) << 7) + 0x30) < 0.25f) {
                    hit = 1;
                }
            }
        }
        chk = hit != 0;
        if (hit != 0) {
            func_L04_0035B5D8(m, s, &a);
            func_L04_00377720(&b);
            vec_sub_ab(&c, &b, &a);
            func_0038CF68(&c, &c, 1.0f);
            if (t != 0) {
                func_L04_00379CC0(t, &b);
                vec_sub_ab(&c, &b, &a);
                func_0038CF68(&c, &c, 1.0f);
            }
            if (chk) {
                if (func_L04_0035A5B8(&a, &b, &b) == 0) {
                    hit = 0;
                }
            }
            if (hit != 0) {
                if (*(u8 **)(s + 4) != 0) {
                    func_L04_003796C8(*(u8 **)(s + 4));
                }
                *(u8 **)(s + 4) = func_L04_00379410(&a);
                *(vu0_q *)(s + 0x150) = *(vu0_q *)&c;
                if (t != 0 && *(s32 *)(*(u8 **)(t + 0x68) + 4) == -1) {
                    *(u8 **)(s + 0x30) = t;
                }
                *(s32 *)(s + 0x110) = 4;
                func_L04_003776F8(m, &a);
                if (*(u8 **)(s + 8) != 0) {
                    func_L04_0037A5B8(*(u8 **)(s + 8), m, 0);
                    *(s32 *)(s + 8) = 0;
                }
            }
        }
    }
    q = s + 0xB0;
    if (*(u8 **)(s + 4) != 0) {
        if (*(s32 *)(s + 0x110) != 4 && *(s32 *)(s + 0x120) != 4) {
            if (*(s32 *)(s + 0x1C) == 0
               || ((m[0xB0] == 0xFF || (D_001BBC40[m[0xB0] + (D_001D545C_sda << 4)] & 0x80) == 0)
                   && (*(s32 *)(s + 0x34) == -1 || D_001BBB18[*(s32 *)(s + 0x34) + (D_001D545C_sda << 3)] == 0))) {
                func_L04_003796C8(*(u8 **)(s + 4));
            }
        } else {
            u8 *w = q;
            *(vu0_q *)w = *(vu0_q *)(*(u8 **)(s + 4) + 0x10);
            f = 40.0f;
            if (D_001D545C == 0xB) {
                f = 80.0f;
            }
            func_0038CE20(w + 0x10, s + 0x150, f);
            vec_add_ab(w + 0x10, w + 0x10, w);
            func_L01_0040BE10(w, w + 0x10);
            func_L04_0035A6E0(m, s, 2, 0);
        }
    }
    p = s + 0x50;
    r = r0;
    for (i = 0; i < 4; i++, p += 0x30, r += 0x10) {
        if (*(s32 *)(r + 4) < D_L04_001DF940) {
            func_L04_0035A4F8(p, r);
        }
    }
    func_L04_0035B908(m, s + 0x50, s + 0x80, s + 0x40);
    func_L04_0035B908(m, s + 0xB0, s + 0xE0, s + 0x44);
    if (*(u8 **)(s + 4) != 0) {
        o = *(u8 **)(s + 4);
        if (*(s32 *)(s + 0xA0) == 1) {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.5f * D_L04_001DD50C;
        } else {
            *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 1.5f;
        }
    }
    func_L04_0035B430(m, s);
    func_L04_0035C1B8(m, s);
}
