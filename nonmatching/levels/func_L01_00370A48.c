/* func_L01_00370A48 (Claude wave 14 r69, 2026-11-28). First draft kept here. */
/* func_L01_00370A48 (4684 B, 34 places): first PAL draft, wave 14 worker r69 (2026-11-28), written from
 * the retail assembly alone (no functional draft). 1065 diff at level 01 under the file's line, but the
 * checker compares row by row and this draft is 1175 instructions against retail's 1171, so most rows are
 * shifted copies of the same instructions: the control flow, callees, constants and the frame (0x1F0)
 * follow retail. Read with an aligning diff (build/codex/wr69/align.py on the check log) the
 * remaining hunks are small: callee-saved allocation (m is $s3 in retail, $s4 here), the 2D4 >= 2
 * path's func_00382348 result chain (retail cross-jumps the 3/2 calls of func_003A52A0 and keeps the
 * result in $v0), the hit-moby type test (retail re-tests hit != 0 and reloads hit through
 * D_L01_001EAA00.pos - 8), a few delay-slot fills and the size limit at 0x98 (retail keeps both
 * li.s arms with a b/nop; every spelling tried here becomes a default + conditional set).
 * Found: retail reads D_L01_001DFB40 once $gp-relative and twice with lui, so a per-function alias
 * D_L01_001DFB40_00370A48 (no .extern) carries the lui reads; the two frame-counter checks share one
 * tail (a local k plus a goto gives retail's single compare); func_003A52A0's result is stored once
 * (0x2D0), but the file declares it void in a later block, so that call goes through the alias
 * func_003A52A0_00370A48 (s32); the callbacks func_L01_00372240/00372128 take later-block struct
 * types, so they are passed through _00370A48 aliases as func_L01_003068B8.c does for its callback;
 * D_001A4BE0 is typed by a later block, hence Hero_00370A48. A `switch (m[0x20])` gives retail's
 * state dispatch (beqz / beq 1 / b) and a boolean k for the 168/334 limit gives retail's slti pair, but
 * both raise the row-by-row count here (1095-1100), so they are left out of this draft. */
#include "common.h"

/* localdecomp:start func_L01_00370A48 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x80];
    u8 x80[0x368 - 0x80];
    s16 h368;
    u8 pad36A[0x16B0 - 0x36A];
    s32 i16B0;
    u8 pad16B4[0x25C0 - 0x16B4];
    u8 *p25C0;
    s32 i25C4;
} Hero_00370A48;
typedef struct {
    u8 pad0[0x6C];
    f32 damage;
    u8 pad70[0xF0 - 0x70];
} Row_00370A48;
typedef struct {
    vu0_v4 v;
    u8 pad10[8];
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[0x14];
} Probe_00370A48;
extern Hero_00370A48 D_001A4BE0_00370A48;
extern Row_00370A48 D_L01_002C5600_00370A48[];
__asm__(".extern D_L01_001DFB40, 4");
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DFB40_00370A48;
extern u8 D_001A30B0[];
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern f32 func_0038CEA8(void *);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_004CB2D8(void);
extern void func_L01_004CAB30(void *a, void *b);
extern void func_L01_004C7D98(void *a, void *b);
extern f32 func_0038CE68(void *a, void *b);
void func_L01_00371CA8(u8 *self, vu0_v4 *source);
void func_L01_00372430(u8 *p, vu0_v4 *from_ptr, vu0_v4 *to_ptr);

void func_L01_00370A48(u8 *m) {
    extern void func_0038D570(void *, void *);
    extern void func_003C48A8(void *, void *);
    extern void func_L01_0044E468(void *, s32);
    extern u8 *func_00382348(void *);
    extern s32 func_L01_004AA710(u8 *, s32);
    extern s32 func_003A52A0_00370A48(s32, s32, void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004CB128(void *, void *, s32);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_004450F0(void *, s32, s32);
    extern void func_L01_004C84D8(s32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_003C4B50(void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern s32 func_003D4D00(void *, s32, void *, void *, f32);
    extern s32 func_L01_004C8258(s32, void *);
    extern void func_L01_004C81F0(s32, void *, s32);
    extern s32 func_00382468(s32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_L01_00446760(void *, void *, s32, void *, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_00372240_00370A48(void);
    extern void func_L01_00372128_00370A48(void);
    extern void func_L01_0044E740(void *);
    extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                                  s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32,
                                  s32, s32, s32, s32, s32);
    extern void func_L01_004C8598(s32);
    extern void func_003A4F28(s32);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(u8 *);
    vu0_v4 q90;
    vu0_v4 rot;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 pd0;
    vu0_v4 pe0;
    vu0_v4 w;
    vu0_v4 d100;
    vu0_v4 d110;
    vu0_v4 d120;
    Probe_00370A48 probe;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *t;
    u8 *r;
    u8 *hit;
    u8 *e;
    s32 state;
    s32 n;
    s32 i;
    s32 bit;
    s32 k;
    f32 s;
    f32 lim;
    f32 x;
    f32 len;
    f32 f;

    if (*(s32 *)(v + 0x184) == *(s32 *)(v + 0x2DC)) {
        *(s32 *)(v + 0x184) = 0;
    }
    func_0038D890(m + 0xC0, m + 0xC0, m + 0xE0, 1.0471976f);
    func_0038D890(m + 0xD0, m + 0xD0, m + 0xE0, 1.0471976f);
    if (*(s32 *)(v + 0x2D4) > 0) {
        lim = 0.035f;
    } else {
        lim = 0.0225f;
    }
    x = *(f32 *)(m + 0x2C);
    if (x <= lim) {
        *(f32 *)(m + 0x2C) = x + 0.001f;
    }
    s = 2.0f;
    if (*(s16 *)(v + 0x188) != 0) {
        s = -2.0f;
    }
    func_003C4840(&rot, v + 0x10, s * 0.017453292f);
    func_0038D850(m + 0xC0, m + 0xC0, &rot);
    func_0038D850(m + 0xD0, m + 0xD0, &rot);
    func_0038D850(m + 0xE0, m + 0xE0, &rot);
    state = m[0x20];
    if (state == 0) {
        func_0038D570(&b, m + 0xC0);
        func_003C48A8(&b, m + 0xF0);
        func_L01_0044E468(v + 0x20, 0);
        if (*(u8 **)(v + 0x184) != 0) {
            r = func_00382348(*(u8 **)(v + 0x184));
            t = *(u8 **)(v + 0x184);
            if (t == 0 || t[0x20] == 0xFE || t[0x20] == 0xFD || *(u8 **)(t + 0x24) == 0 ||
                (*(u8 **)(t + 0x24))[0x46] != 5 ||
                (*(unsigned long *)(t + 0x30) & ((unsigned long)0x8010 << 29)) != ((unsigned long)0x8000 << 29) || r == 0 ||
                *(f32 *)r <= 0.0f) {
                *(u8 **)(v + 0x184) = 0;
            }
        }
        if (func_L01_004AA710(m, *(s32 *)(v + 0x2D0)) == 0) {
            *(s32 *)(v + 0x2D0) = func_003A52A0_00370A48(0, 4, m);
        }
        q90 = *(vu0_v4 *)(m + 0x10);
        func_L01_004C8688(*(s32 *)(v + 0x2D8), v, 0);
        vec_add_ab(m + 0x10, v, m + 0x10);
        if (func_L01_004CB2D8() != 0) {
            func_L01_004CAB30(m + 0x10, m + 0x10);
        }
        if (*(u8 **)(v + 0x184) != 0) {
            func_L01_004CB128(&w, *(u8 **)(v + 0x184), 0);
            vec_sub_ab(&d100, &w, m + 0x10);
            func_0038CF68(&d100, &d100, 0.1f);
            vec_add_ab(v, &d100, v);
            func_0038CF68(v, v, 0.35f);
        }
        if (*(u8 **)(v + 0x184) == 0 && *(s32 *)(v + 0x2D4) < 4 && D_001A4BE0_00370A48.i25C4 != 0x1D &&
            D_001A4BE0_00370A48.i16B0 == 0 && *(s32 *)(v + 0x170) < 0x20) {
            func_L01_004C7D40(m + 0x10, v, 0.0064f);
        }
        if (*(f32 *)(m + 0x10) < 2.0f || 1021.0f < *(f32 *)(m + 0x10) || *(f32 *)(m + 0x14) < 2.0f ||
            1021.0f < *(f32 *)(m + 0x14) || *(f32 *)(m + 0x18) < 2.0f || 1021.0f < *(f32 *)(m + 0x18) ||
            6561.0f < func_L01_0040E548(D_001A4C60, m + 0x10)) {
            func_L01_004450F0(m, 1, -1);
        }
        if (*(s16 *)(v + 0x18A) >= 4 && *(s32 *)(v + 0x2D4) < 5) {
            k = D_L01_001DFB40;
        } else {
            if (D_L01_001DD9A0 < 15) {
                goto count;
            }
            k = D_L01_001DFB40_00370A48;
        }
        if ((k & 0xF) == (((s32)m >> 8) & 0xF)) {
            if (2500.0f < func_L01_0040E548(D_001A4C60, m + 0x10)) {
                func_L01_004450F0(m, 1, -1);
            }
        }
    count:
        *(s32 *)(v + 0x170) = *(s32 *)(v + 0x170) + 1;
        func_L01_004C84D8(*(s32 *)(v + 0x174));
        if (func_003D3CB0(&q90, m + 0x10, 0, *(u8 **)(v + 0x2DC), 0) != 0) {
            w = D_L01_001EAA00.pos;
            hit = D_L01_001EAA00.hit;
            if (*(s32 *)(v + 0x2D4) < 2 && hit != 0 && hit != *(u8 **)(v + 0x174) &&
                hit != D_001A4BE0_00370A48.p25C0 &&
                ((hit != 0 && *(u8 **)(hit + 0x24) != 0 && (*(u8 **)(hit + 0x24))[0x46] == 5) ||
                 func_003C4B50(D_L01_001EAA00.hit) != 0)) {
                m[0x20] = 1;
                *(vu0_v4 *)(m + 0x10) = D_L01_001EAA00.pos;
            } else {
                if (*(s32 *)(v + 0x2D4) == 0) {
                    func_003A52A0(1, 0, m);
                    func_L01_0040E790(v, v, (u8 *)&D_L01_001EAA00 + 0x40);
                } else if (*(s32 *)(v + 0x2D4) == 1) {
                    func_003A52A0(1, 0, m);
                    func_L01_0040E790(v, v, (u8 *)&D_L01_001EAA00 + 0x40);
                    len = func_0038CEA8(v);
                    n = func_003D4D00(m + 0x10, 1, D_001A4BE0_00370A48.p25C0, 0, 10.0f);
                    for (i = 0; i < n; i++) {
                        t = D_L01_001EEA80[i];
                        r = func_00382348(t);
                        if (t != D_001A4BE0_00370A48.p25C0 && t != 0 && t[0x20] != 0xFE && t[0x20] != 0xFD &&
                            *(u8 **)(t + 0x24) != 0 && (*(u8 **)(t + 0x24))[0x46] == 5 &&
                            (*(u16 *)(t + 0x34) & 0x1000) && r != 0 && 0.0f < *(f32 *)r &&
                            !(*(u16 *)(t + 0x34) & 2)) {
                            func_L01_004CB128(&d100, t, 0);
                            vec_sub_ab(&d110, &d100, m + 0x10);
                            func_0038CF68(v, &d110, len);
                            break;
                        }
                    }
                } else if (*(s32 *)(v + 0x2D4) >= 2) {
                    hit = D_L01_001EAA00.hit;
                    if (hit == 0 || *(u8 **)(hit + 0x24) == 0 || (*(u8 **)(hit + 0x24))[0x46] != 5) {
                        func_003A52A0(1, 0, m);
                        func_L01_0040E790(v, v, (u8 *)&D_L01_001EAA00 + 0x40);
                    } else {
                        r = func_00382348(hit);
                        if (r == 0) {
                            func_003A52A0(1, 0, m);
                        } else if (r[9] == 0) {
                            func_003A52A0(3, 0, m);
                        } else if (r[9] == 1) {
                            func_003A52A0(2, 0, m);
                        }
                    }
                    *(u8 **)(v + 0x2DC) = D_L01_001EAA00.hit;
                    if (*(s32 *)(v + 0x2D4) >= 4 && D_L01_001DD9A0 < 15) {
                        d100 = *(vu0_v4 *)v;
                        len = func_0038CEA8(v);
                        d100.x = d100.x + func_003824E0(0.1f, 0.2f);
                        d100.y = d100.y + func_003824E0(0.1f, 0.2f);
                        d100.z = d100.z + func_003824E0(0.1f, 0.2f);
                        func_0038CF68(&d100, &d100, len);
                        *(s16 *)(v + 0x18A) = *(s16 *)(v + 0x18A) + 1;
                        bit = 1 << ((*(s16 *)(v + 0x18A) - 1) >> 1);
                        if (func_00382468(bit) == 0) {
                            func_L01_003706F0(*(void **)(v + 0x174), (Q_003706F0 *)(m + 0x10), (Q_003706F0 *)&d100,
                                              D_L01_002C5600_00370A48[D_0014260F[0]].damage, 0x10000, 0,
                                              *(s16 *)(v + 0x18A), (s32)D_L01_001EAA00.hit);
                        }
                        if (func_00382468(bit) != 0) {
                            func_L01_004450F0(m, 1, -1);
                        }
                    }
                    len = func_0038CEA8(v);
                    n = func_003D4D00(m + 0x10, 1, D_001A4BE0_00370A48.p25C0, 0, 10.0f);
                    for (i = 0; i < n; i++) {
                        t = D_L01_001EEA80[i];
                        r = func_00382348(t);
                        if (t != D_001A4BE0_00370A48.p25C0 && t != 0 && t[0x20] != 0xFE && t[0x20] != 0xFD &&
                            *(u8 **)(t + 0x24) != 0 && (*(u8 **)(t + 0x24))[0x46] == 5 &&
                            (*(u16 *)(t + 0x34) & 0x1000) &&
                            func_L01_004C8258(*(s32 *)(v + 0x174), t) != 0 && r != 0 && 0.0f < *(f32 *)r &&
                            !(*(u16 *)(t + 0x34) & 2)) {
                            func_L01_004C81F0(*(s32 *)(v + 0x174), t, 500);
                            func_L01_004CB128(&d100, t, 0);
                            vec_sub_ab(&d110, &d100, m + 0x10);
                            func_0038CF68(v, &d110, len);
                            *(s32 *)(v + 0x184) = 0;
                            break;
                        }
                    }
                }
                d100 = D_L01_001EAA00.pos;
                func_L01_00371CA8(m, &d100);
                *(vu0_v4 *)(m + 0xC0) = *(vu0_v4 *)v;
                func_0038CF68(m + 0xC0, m + 0xC0, 1.0f);
                func_0038CE90(m + 0xE0, D_001A4BE0_00370A48.p25C0 + 0xD0, m + 0xC0);
                func_0038CE90(m + 0xD0, m + 0xC0, m + 0xE0);
                *(vu0_v4 *)(v + 0x10) = *(vu0_v4 *)v;
                if (D_L01_001D673C != 0 || D_001A4BE0_00370A48.h368 != 0) {
                    func_L01_004C7D98(D_001A4BE0_00370A48.x80, &d110);
                    f = func_0038CE68(v, &d110);
                    func_0038CE20(&d120, &d110, f);
                    vec_sub_ab(v + 0x10, v, &d120);
                } else {
                    *(s32 *)(v + 0x18) = 0;
                    func_0038CF68(v + 0x10, v + 0x10, 1.0f);
                }
            }
            if (*(s32 *)(v + 0x2D4) >= 2) {
                d100 = *(vu0_v4 *)v;
                func_0038CE20(&d100, &d100, 3.0f);
                d100.w = 5627.9248f;
                func_L01_00446760(&probe, m, *(s32 *)(v + 0x17C), &d100, *(f32 *)(v + 0x178));
                probe.b18 = 0;
                probe.b19 = 1;
                probe.h1A = *(u16 *)(m + 0xAA);
                func_003D4D00(m + 0x10, 0, m, &probe, 1.0f);
            } else {
                d100 = *(vu0_v4 *)v;
                func_0038CE20(&d100, &d100, 3.0f);
                d100.w = 5627.9248f;
                func_L01_00446760(&probe, m, *(s32 *)(v + 0x17C), &d100, *(f32 *)(v + 0x178));
                probe.b18 = 0;
                probe.b19 = 1;
                probe.h1A = *(u16 *)(m + 0xAA);
                if (func_003D3CB0(&q90, m + 0x10, 2, *(u8 **)(v + 0x2DC), 0) != 0) {
                    func_L01_0040E790(v, v, (u8 *)&D_L01_001EAA00 + 0x40);
                } else if (func_003D4D00(m + 0x10, 0, m, &probe, 1.0f) != 0) {
                    m[0x20] = 1;
                }
            }
        }
        if (*(s32 *)(v + 0x2D4) >= 3 ? *(s32 *)(v + 0x170) >= 334 : *(s32 *)(v + 0x170) >= 168) {
            m[0x20] = 1;
        }
    } else if (state == 1) {
        func_L01_0044E740(v + 0x20);
        if (*(s32 *)(v + 0x2D4) >= 4) {
            D_L01_001DD9A0 = D_L01_001DD9A0 - 1;
            func_L01_003303B8(m + 0x10, 0, 1, 1, 1, 10, 0, 0, 0.5f, 0.0f,
                              D_L01_002C5600_00370A48[D_0014260F[0]].damage * 0.5f, 4.0f, 0, 0, 0, 0, 0, 0,
                              0x10000, 0, 0x384EFF, 0x33FF, 0x404FFF, 0x20FF, 0x8FFF, 0x30FF, 0x7F60A0FF,
                              0x280000FF, 0x30FF, 0);
        } else if (*(s32 *)(v + 0x2D4) == 3) {
            func_L01_003303B8(m + 0x10, 1, 25, 20, 20, 20, 45, 0, 0.5f, 0.0f,
                              D_L01_002C5600_00370A48[D_0014260F[0]].damage * 0.5f, 4.0f, 1, 1, 0, 0, 1, 0,
                              0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430,
                              0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        } else if (*(s32 *)(v + 0x2D4) == 2) {
            func_L01_003303B8(m + 0x10, 0, 1, 1, 1, 20, 0, 1, 0.3f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0,
                              0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0xFF8F00, 0xFF6430,
                              0x7FFFA060, 0x28FF0000, 0xFF6430, 0);
        } else {
            func_L01_003303B8(m + 0x10, 0, 1, 1, 1, 20, 0, 1, 0.3f, 0.0f, 1.0f, 0.75f, 0, 1, 0, 0, 0, 0,
                              0x10000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF,
                              0x280000FF, 0x3064FF, 0);
        }
        func_003A52A0(4, 0, m);
        func_L01_004C8598(*(s32 *)(v + 0x174));
        if (*(s32 *)(v + 0x2D0) != -1) {
            e = D_001A30B0 + *(s32 *)(v + 0x2D0) * 0x80;
            if (*(u8 **)(e + 0xDC) == m && e[0xD0] != 0) {
                func_003A4F28(*(s32 *)(v + 0x2D0));
            }
        }
        *(s32 *)(v + 0x2D0) = -1;
        func_L01_004C8668(*(s32 *)(v + 0x2D8));
        func_003C2880(m);
        return;
    }
    b = *(vu0_v4 *)(m + 0x10);
    b.w = 0.5f;
    if (func_0038DC20(&b, 96.0f) > 0) {
        func_L01_00404A10(func_L01_00372240_00370A48, m);
        c = *(vu0_v4 *)(m + 0x10);
        func_L01_00372430(m, &c, &q90);
    }
    if (*(s32 *)(v + 0x2D4) > 0 && m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD && !(*(u16 *)(m + 0x34) & 2)) {
        if (*(s32 *)(v + 0x2D4) < 4) {
            f = (f32)(D_L01_001DFB40 % 6) * 0.16666667f;
            *(f32 *)(v + 0x2C8) = f;
            if (f == 0.0f) {
                *(s32 *)(v + 0x2C4) = (*(s32 *)(v + 0x2C4) + 1) % 6;
                if (*(s32 *)(v + 0x2C0) < 6) {
                    *(s32 *)(v + 0x2C0) = *(s32 *)(v + 0x2C0) + 1;
                }
            }
        } else {
            f = (f32)(D_L01_001DFB40_00370A48 % 4) * 0.25f;
            *(f32 *)(v + 0x2C8) = f;
            if (f == 0.0f) {
                *(s32 *)(v + 0x2C4) = (*(s32 *)(v + 0x2C4) + 1) % 4;
                if (*(s32 *)(v + 0x2C0) < 4) {
                    *(s32 *)(v + 0x2C0) = *(s32 *)(v + 0x2C0) + 1;
                }
            }
        }
        func_L01_00404A10(func_L01_00372128_00370A48, m);
    }
    *(s32 *)(m + 0xFC) = 0;
    *(s32 *)(m + 0xCC) = 0;
    *(s32 *)(m + 0xDC) = 0;
    *(s32 *)(m + 0xEC) = 0;
}
/* localdecomp:end func_L01_00370A48 */
