/* PAL draft (2026-11-21, Promises fleet rac3-w2): func_L04_0035BC10 (1444 B; levels 04 06 11 16 19 22),
 * written from retail. check.py at level 04 with its file's line (-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 * -mno-check-zero-division @ps2as): 210 diff. Control flow, calls, constants and the VU0 sequences line up;
 * what differs is register allocation: retail keeps s in $s2, m in $s4, m + 0xC0 in $s0 and the -1 in $s3
 * and spills both s + 0x50 (0x30($sp)) and s + 0xB0 (0x34($sp)); this C gives s $s1, m $s3, -1 $s0, spills only
 * s + 0x50 (to 0x34) and keeps s + 0xB0 in $s4, so it is two words short. Tried: s + 0x110 hoisted (229 -> 211,
 * kept), branch order of the 0x110/0x120 test (kept), `none = -1` local (no change), 40/80 select as if/else or
 * ?: (210), s + 0xB0 hoisted (312), a separate pointer for the 0x35A4F8 loop (329, the three 0x38CE20 calls get
 * cross-jumped), an indexed loop (298). Also open: retail's third vadd has vf2 = vf2 + vf1 where this C gets
 * vf1 = vf1 + vf2, and the first 40/80 select loads D_001D545C before the 0xB.
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
    u8 *q;
    u8 *t;
    u8 *r;
    u8 *o;
    s32 hit;
    s32 chk;
    s32 i;
    f32 f;
    s32 none;

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
    none = -1;
    if (*(s32 *)(s + 0x4C) == none) {
        func_0038D308(m + 0xC0, m + 0xF0);
    }
    p = s + 0x50;
    r = s + 0x110;
    if (*(s32 *)(s + 0x20) == none) {
        func_0038CE20(p, m + 0xC0, 0.33f);
    } else if (*(s32 *)(s + 0x20) != 0) {
        func_0038CE20(p, m + 0xC0, 0.23f);
    } else {
        func_0038CE20(p, m + 0xC0, 0.33f);
    }
    vec_add_ab(p, p, m + 0x10);
    f = D_001D545C == 0xB ? 80.0f : 40.0f;
    func_0038CE20(p + 0x10, m + 0xC0, f);
    vec_add_ba(p + 0x10, p + 0x10, m + 0x10);
    func_L01_0040BE10(m + 0x10, p + 0x10);
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
            *(vu0_q *)q = *(vu0_q *)(*(u8 **)(s + 4) + 0x10);
            f = 40.0f;
            if (D_001D545C == 0xB) {
                f = 80.0f;
            }
            func_0038CE20(q + 0x10, s + 0x150, f);
            vec_add_ab(q + 0x10, q + 0x10, q);
            func_L01_0040BE10(q, q + 0x10);
            func_L04_0035A6E0(m, s, 2, 0);
        }
    }
    p = s + 0x50;
    for (i = 0; i < 4; i++) {
        if (*(s32 *)(r + 4) < D_L04_001DF940) {
            func_L04_0035A4F8(p, r);
        }
        p += 0x30;
        r += 0x10;
    }
    func_L04_0035B908(m, s + 0x50, s + 0x80, s + 0x40);
    func_L04_0035B908(m, q, s + 0xE0, s + 0x44);
    if (*(u8 **)(s + 4) != 0) {
        o = *(u8 **)(*(u8 **)(s + 4) + 0x24);
        if (*(s32 *)(s + 0xA0) == 1) {
            *(f32 *)(*(u8 **)(s + 4) + 0x2C) = *(f32 *)(o + 0x24) * 1.5f * D_L04_001DD50C;
        } else {
            *(f32 *)(*(u8 **)(s + 4) + 0x2C) = *(f32 *)(o + 0x24) * 1.5f;
        }
    }
    func_L04_0035B430(m, s);
    func_L04_0035C1B8(m, s);
}
