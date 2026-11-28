/* func_L01_003E01B8 (Claude wave 14 r74, 2026-11-28). First draft kept here. */
/* r74 wave 14 (2026-11-28), first draft (fresh entry, no functional C), written from the PAL disassembly: 1031 diff
 * at level 01 under the file's line (1250 instructions here, 1254 in retail; most remaining rows are register
 * renames: the moby pointer is s6 here, s5 in retail, and every s-register use shifts with it). Structure: state-0
 * flight (position += velocity, damping, a 0x60-byte sweep record at sp+0x30 for func_L01_004C7E70 with the 12-byte
 * extent copied from D_L01_001DF580 at sp+0x20), homing on the nearest live target of the func_003D4D00 list, the spin
 * and the collision struct overlaid at sp+0x90 (pos, owner, 0x01030000, type bytes, scale, 1), a first-hit kill
 * test, then the kill path (radius damage list with the inlined bolt/XP award, twice in retail, here
 * award_003E01B8), two particle loops, the explosion effect and func_L01_004C8668; otherwise the smoke trail and
 * the sound/hit check. Notes for the next pass: the counters 0x001DAFF4/0x001D545C/0x001D673C/0x001D7BE0 are plain
 * externs (SN's assembler makes their delay-slot copies $gp-relative itself), D_L01_001DF558/564/568 are real
 * $gp data (.extern 4); the award block's arguments, the 004C7E70/004CB018 prototypes and the 0x90 overlay are
 * guesses from the argument registers. */
#include "common.h"

/* localdecomp:start func_L01_003E01B8 */
#include "vu0.h"
typedef int u128_003E01B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z; } V3_003E01B8;
typedef struct {
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 vel;
    u8 *owner;
    V3_003E01B8 *ext;
    s32 n;
    f32 radius;
    f32 bounce;
    f32 f74;
    s32 i78;
    s32 i7C;
    s32 i80;
    s32 result;
    s32 i88;
    f32 f8C;
} Sweep_003E01B8;
typedef struct {
    vu0_v4 pos;
    u8 *owner;
    s32 flags;
    u8 b8;
    u8 b9;
    u16 type;
    f32 scale;
    s32 i10;
} Hit_003E01B8;
extern V3_003E01B8 D_L01_001DF580;
extern f32 D_L01_001DF564;
__asm__(".extern D_L01_001DF564, 4");
extern f32 D_L01_001DF558;
__asm__(".extern D_L01_001DF558, 4");
extern f32 D_L01_001DF568;
__asm__(".extern D_L01_001DF568, 4");
extern u8 *D_L01_001EEA80[];
extern s32 D_L01_001D673C;
extern s32 D_L01_001D6740;
extern s32 D_L01_001DAFF4;
extern s32 D_L01_001D7BE0;
extern f32 D_L01_001DAA34;
extern f32 D_L01_002F1600[];
extern u8 D_L01_001D60D8[];
extern u8 D_L01_001D60E0[];
extern u8 D_L01_001EAA20[];
extern u8 D_001A7E18[];
extern u8 D_001425C0[];
extern u8 D_001426E0[];
extern u8 D_00142DE0[];
extern u8 D_001BBE90[];

static __inline__ void award_003E01B8(u8 *q, u8 *o) {
    extern void func_L01_0041A5B0(s32, s32);
    extern s32 func_L01_00444350(void);
    extern s32 func_L01_004006C8(u8 *, s32, s32);
    extern s32 func_L01_0041A4F0(void);
    s32 mode;
    s32 base;
    s32 bolts;
    u8 *table;
    u8 bits;
    f32 f;

    q[0x2F] = 1;
    D_L01_001DAFF4++;
    if (*(u16 *)(D_001A7E18 + 0xDA4) == 0 && D_L01_001DAFF4 >= 6) {
        func_L01_0041A5B0(0x1518, 0x123);
    }
    *(s32 *)(q + 0x38) = (s32)(D_L01_002C5600[D_001425C0[0x37]].scale / *(f32 *)q * 600.0f);
    if (q[0x35] != 0) {
        return;
    }
    switch (*(s16 *)(o + 0xAA)) {
    case 0x19DF:
    case 0x19F1:
    case 0x1BC5:
    case 0x1A18:
    case 0x1A1C:
    case 0x1A1F:
    case 0x1A13:
    case 0x1666:
    case 0x1AFD:
    case 0x1A0A:
    case 0x16CB:
    case 0x1BD9:
        return;
    }
    mode = D_L01_001D7BE0;
    if ((u32)mode < 41) {
        if (mode != 9) {
            *(s32 *)(D_00142DE0 + 0xDC) += func_L01_00444350();
        }
        return;
    }
    if (mode == 9) {
        return;
    }
    base = (D_00142660[0x38 / 4] + 0x31) / 50;
    bits = D_001BBE90[(D_001D545C << 10) + (*(s16 *)(o + 0xB2) >> 1)];
    if (*(u16 *)(o + 0xB2) & 1) {
        bits >>= 4;
    }
    if (bits & 8) {
        table = D_L01_001D60E0;
    } else {
        table = D_L01_001D60D8;
    }
    bolts = func_L01_004006C8(table, *(u16 *)(o + 0xB6), *(s16 *)(o + 0xB2)) << ((u8 *)&D_001A4BE0)[0x28C8];
    if (func_L01_0041A4F0() != 0) {
        f = (f32)bolts;
        if (D_001D545C == 7 && D_001426E0[0x7B] != 0) {
            bolts = (s32)(f * D_L01_001DAA34);
        } else {
            bolts = (s32)(f * D_L01_002F1600[D_001D545C]);
        }
    }
    *(s32 *)(D_00142DE0 + 0xDC) += bolts + base;
}

void func_L01_003E01B8(u8 *m) {
    extern void func_003C5180(void *, void *, s32);
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_0038CAD0(void *);
    extern s32 func_0038CB00(void *);
    extern void func_L01_004C8688(s32, void *, s32);
    extern void func_L01_004C8668(s32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_0038CF00(void *, void *);
    extern void func_0038D850(void *, void *, void *);
    extern void func_L01_004C7D40(void *, void *, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern s32 func_L01_004C7E70(void *, s32);
    extern s32 func_L01_004CB018(s32);
    extern s32 func_003D4D00(void *, s32, void *, s32, f32);
    extern s32 func_003C4B50(void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern void func_003C4840(f32, void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern void func_00382580(void *, f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_003A52A0(s32, s32, void *);
    extern void func_L01_00446780(void *, void *, s32, f32, f32, f32, s32, s32, s32);
    extern u8 *func_L01_0046B288(void *, s32, s32, s32, f32, f32);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern u8 *func_L01_00468678(void *, void *, s32, f32, f32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    extern void func_003C2880(void *);
    extern void func_L01_004471A8(void *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_003E1590(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_L01_003E1990(void *);
    vu0_v4 up;
    vu0_v4 old;
    V3_003E01B8 ext;
    Sweep_003E01B8 sweep;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    u8 *v = *(u8 **)(m + 0x68);
    s32 hits, kind, n, i, best, kill;
    f32 d, bestd, len, radius;
    u8 *o;
    u8 *q;
    u8 *p;

    func_003C5180(m + 0x10, &up, 1);
    if (func_L01_004CB2D8() != 0) {
        func_L01_004CAB30(m + 0x10, m + 0x10);
    }
    func_0038CAD0(v + 0x2C);
    if (m[0x20] == 0) {
        *(u128_003E01B8 *)&old = *(u128_003E01B8 *)(m + 0x10);
        vec_add_ab(m + 0x10, m + 0x10, v);
        func_L01_004C8688(*(s32 *)(v + 0x28), v, 0);
        func_0038CF68(v, v, func_0038CEA8(v) * 0.995f);
        func_L01_004C7D40(m + 0x10, v, 0.00584f);
        ext = D_L01_001DF580;
        radius = D_L01_001DF564;
        if (D_001D545C == 19) {
            radius *= 3.5f;
        }
        sweep.from = old;
        sweep.to = *(vu0_v4 *)(m + 0x10);
        sweep.vel = *(vu0_v4 *)v;
        sweep.owner = m;
        sweep.ext = &ext;
        sweep.n = 3;
        sweep.radius = radius;
        sweep.bounce = (D_L01_001DF558 - 1.0f) * 1.2f + 1.0f;
        sweep.f74 = 1.5f;
        sweep.i78 = 0;
        sweep.i7C = 0;
        sweep.i80 = 1;
        sweep.i88 = 1;
        sweep.f8C = 0.09f;
        hits = func_L01_004C7E70(&sweep, -1);
        kind = func_L01_004CB018(sweep.result);
        *(vu0_v4 *)(m + 0x10) = sweep.to;
        *(vu0_v4 *)v = sweep.vel;
        func_0038D850(m + 0xC0, m + 0xC0, v + 0x10);
        func_0038D850(m + 0xD0, m + 0xD0, v + 0x10);
        func_0038D850(m + 0xE0, m + 0xE0, v + 0x10);
        if (hits > 0) {
            n = func_003D4D00(m + 0x10, 1, *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0), 0, 5.0f);
            best = -1;
            if (n != 0) {
                bestd = 10000.0f;
                for (i = 0; i < n; i++) {
                    o = D_L01_001EEA80[i];
                    if (o[0x31] == 0) continue;
                    if (func_003C4B50(o) != 0) continue;
                    q = func_00382348_003D9548(o);
                    if (q == 0) continue;
                    if (*(f32 *)q <= 0.0f) continue;
                    if (o == 0) continue;
                    if (*(u8 **)(o + 0x24) == 0) continue;
                    if ((*(u8 **)(o + 0x24))[0x46] != 5) continue;
                    if (q[0x2F] == 1) continue;
                    d = func_0038CF00(o + 0x10, m + 0x10);
                    if (d < bestd) {
                        bestd = d;
                        best = i;
                    }
                }
                if (best >= 0) {
                    o = D_L01_001EEA80[best];
                    q = func_00382348_003D9548(o);
                    v90 = *(vu0_v4 *)(o + 0x10);
                    if (D_L01_001D673C != 0) {
                        func_0038CE20(&vA0, o + 0xE0, *(f32 *)(q + 0x10));
                        vec_add_ab(&v90, &v90, &vA0);
                    } else {
                        v90.z += *(f32 *)(q + 0x10);
                    }
                    func_0038CE20(&vA0, &up, func_0038CE68(&up, v));
                    vec_sub_ab(&vB0, v, &vA0);
                    len = func_0038CEA8(&vB0);
                    if (len != 0.0f) {
                        vec_sub_ba(&vC0, &v90, m + 0x10);
                        func_0038CE20(&vD0, &up, func_0038CE68(&vC0, &up));
                        if (len < 0.080000006f) {
                            len = 0.080000006f;
                        }
                        vec_sub_ab(&vE0, &vC0, &vD0);
                        func_0038CF68(&vE0, &vE0, len);
                        vec_add_ab(v, &vE0, &vA0);
                    }
                }
            }
            v90 = *(vu0_v4 *)v;
            v90.z = 0.0f;
            func_0038CE90(&v90, &v90, &up);
            func_0038CF68(&v90, &v90, 1.0f);
            d = func_L01_00443A18(0.0f, 0.5235988f);
            if (fabs_asm(d) < 1e-05f) {
                func_003C4840(d, &vA0, &up);
                func_0038D850(&v90, &v90, &vA0);
            }
            d = ((f32)*(s16 *)(v + 0x20) + 1.0f) * 0.017453292f * 0.020000001f;
            func_003C4840(func_003824E0(d, d), v + 0x10, &v90);
            if (*(s32 *)(v + 0x2C) <= 0) {
                func_003A52A0(0, 0, m);
                *(s32 *)(v + 0x2C) = 6;
            }
            if (func_0038CEA8(v) <= 0.010000001f) {
                *(s16 *)(v + 0x20) = 0;
            }
        }
        {
            Hit_003E01B8 *hit = (Hit_003E01B8 *)&v90;
            kill = 0;
            hit->owner = m;
            hit->flags = 0x1030000;
            hit->scale = 1.0f;
            hit->i10 = 1;
            hit->pos = *(vu0_v4 *)v;
            func_0038CF68(&hit->pos, &hit->pos, 1.0f);
            hit->pos.w = 5627.925f;
            hit->b8 = 3;
            hit->b9 = 1;
            hit->type = *(u16 *)(m + 0xAA);
            n = func_003D4D00(m + 0x10, 1, *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0), 0, 1.0f);
            for (i = 0; i < n; i++) {
                o = D_L01_001EEA80[i];
                q = func_00382348_003D9548(o);
                if (func_003C4B50(o) == 0) {
                    if (q == 0) continue;
                    if (!(0.0f < *(f32 *)q)) continue;
                    if (*(s16 *)(q + 6) != 0) continue;
                }
                if (*(s16 *)(o + 0xAA) == 0x189B || *(s16 *)(o + 0xAA) == 0x1BC3) continue;
                if (*(s16 *)(o + 0xAA) == 0x1D86) continue;
                kill = 1;
                if (!(*(f32 *)q <= 2.0f)) break;
                if (q[0x2F] != 0) break;
                o = D_L01_001EEA80[i];
                if (o == 0) break;
                if (*(u8 **)(o + 0x24) == 0) break;
                if ((*(u8 **)(o + 0x24))[0x46] != 5) break;
                if (func_003C4B50(o) != 0) break;
                kill = 0;
                award_003E01B8(q, D_L01_001EEA80[i]);
                break;
            }
        }
        if (func_0038CB00(v + 0x20) != 0) {
            kill = 1;
        } else if (hits > 0 && (u32)(kind - 1) < 2) {
            kill = 1;
        }
        if (kill != 0) {
            func_003A52A0(1, 0, m);
            n = func_003D4D00(m + 0x10, 0, m, 0, 1.0f);
            for (i = n; i != 0; i--) {
                u8 **slot = &D_L01_001EEA80[n - i];
                q = func_00382348_003D9548(*slot);
                if (q == 0) continue;
                if (q[0x2F] != 0) continue;
                o = *slot;
                if (o == 0) continue;
                if (*(u8 **)(o + 0x24) == 0) continue;
                if ((*(u8 **)(o + 0x24))[0x46] != 5) continue;
                if (o == *(u8 **)((u8 *)&D_001A4BE0 + 0x25C0)) continue;
                if (*(s16 *)(o + 0xAA) == 0x188A) continue;
                if (*(s16 *)(o + 0xAA) == 0x1886) continue;
                if (func_003C4B50(o) != 0) continue;
                award_003E01B8(q, *slot);
            }
            func_L01_00446780(m, m + 0x10, 0x8000000, 1.5f, 1.0f, 1.0f, 0, 1, 0);
            if (D_L01_001D673C == 0 && func_L01_004CB2D8() == 0) {
                for (i = 1; i >= 0; i--) {
                    f32 a = func_00382538();
                    f32 r = func_003824E0(0.0f, 0.6f);
                    f32 b = func_003824E0(0.0f, 1.5f);
                    f32 c = func_003824E0(1.5f, 5.5f);
                    s32 life = func_00382498(100, 160);
                    vC0.x = func_0038D098(a) * r;
                    vC0.y = func_0038D0B0(a) * r;
                    vC0.z = 0.0f;
                    vec_add_ba(&vC0, &vC0, m + 0x10);
                    func_L01_0046B288(&vC0, 0x30305020, 0x182810, life, b, c);
                }
            }
            p = func_L01_003016B0(m + 0x10, 5, func_003824E0(2.0f, 2.5f), 1.04f);
            if (p != 0) {
                func_L01_0043B9E8(p, 0x52, 0xD1, 5);
            }
            for (i = 0; i >= 0; i--) {
                func_L01_004C7D98(m + 0x10, &vC0);
                func_0038CF68(&vC0, &vC0, -1.0f);
                vec_add_ba(&vC0, m + 0x10, &vC0);
                *(u128_003E01B8 *)&vE0 = 0;
                vE0.x = func_003824E0(-1.0f, 1.0f);
                vE0.y = func_003824E0(-1.0f, 1.0f);
                vE0.z = func_003824E0(0.5f, 1.0f);
                vD0 = vE0;
                func_0038CF68(&vD0, &vD0, func_003824E0(0.0039999997f, 0.012f));
                p = func_L01_00468678(&vC0, &vD0, 0x8810D162, func_003824E0(0.05f, 0.15f) * 210000.0f,
                                      *(f32 *)((u8 *)&D_001A4BE0 + 0x88) + 1.0f);
                if (p != 0) {
                    p[3] = 0x44;
                }
            }
            if (func_00382468(3) == 0) {
                func_00382580(&vC0, 0.01f, 0.03f);
                func_0038CE20(&vC0, &vC0, 4.0f);
                func_L01_00466F50(m + 0x10, &vC0, 0x4005A182, -1.0f, -0.011999999f);
            }
            if (D_L01_001D673C == 0 && func_L01_004CB2D8() == 0) {
                for (i = 0; i >= 0; i--) {
                    f32 a = func_00382538();
                    f32 r = func_003824E0(0.0f, 2.5f);
                    f32 b = func_003824E0(0.0f, 1.5f);
                    f32 c = func_003824E0(3.0f, 5.0f);
                    s32 life = func_00382498(100, 160);
                    vC0.x = func_0038D098(a) * r;
                    vC0.y = func_0038D0B0(a) * r;
                    vC0.z = 0.0f;
                    vec_add_ba(&vC0, &vC0, m + 0x10);
                    p = func_L01_0046B288(&vC0, 0x5005D152, 0x5D152, life, b, c);
                    if (p != 0) {
                        p[3] = func_00382468(3) != 0 ? 0x48 : 0x44;
                    }
                }
            }
            func_L01_004C8668(*(s32 *)(v + 0x28));
            func_003C2880(m);
            return;
        }
    }
    if (D_L01_001D673C == 0 && D_L01_001D6740 == 0) {
        func_L01_004471A8(m, D_L01_001DF568);
    }
    for (i = 0; i >= 0; i--) {
        *(u128_003E01B8 *)&old = *(u128_003E01B8 *)(m + 0x10);
        old.x += func_003824E0(-0.1f, 0.1f);
        old.y += func_003824E0(-0.1f, 0.1f);
        old.z += func_003824E0(-0.1f, 0.1f);
        func_L01_004C7D98(m + 0x10, &ext);
        func_0038CE20(&ext, &ext, func_003824E0(0.4f, 1.0f) * 0.020000001f);
        p = func_L01_004713C8(&old, &ext, (func_00382498(10, 15) * 5 + 2) / 6, 0x5A182, 1, 0x4F, 0, 0,
                              58800.0f, 27299.998f, 0.0f);
        if (p != 0) {
            p[3] = func_00382468(2) != 0 ? 0x44 : 0x48;
            p[2] = *D_L01_00221098[0x1A4 / 4];
        }
    }
    *(u128_003E01B8 *)&old = *(u128_003E01B8 *)(m + 0x10);
    old.w = 0.5f;
    if (func_0038DC20(&old, 96.0f) > 0) {
        func_L01_003E1590(m);
        if (D_L01_001D673C == 0 && func_L01_004CB2D8() == 0 && func_00382468(3) == 0) {
            func_L01_004C7D98(m + 0x10, &ext);
            func_0038CF68(&ext, &ext, -5.0f);
            vec_add_ab(&ext, m + 0x10, &ext);
            if (func_003D3CB0(m + 0x10, &ext, 6, (u8 *)D_001A71A0[0], 0) != 0) {
                func_L01_003E1990(D_L01_001EAA20);
            }
        }
    }
}
/* localdecomp:end func_L01_003E01B8 */
