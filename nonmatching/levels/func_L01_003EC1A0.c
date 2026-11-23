/* near miss (round 19 worker J5D): 24 aligned rows of 299 words (297 words here; the raw count is shifted by the two words the clamp block is short) with the file's flags.
 * The camera's swing / follow update (camera_swing_follow): distance and height targets 4.64 and 2.0, or 3.65 + t and 2t while the target is held (t = clamped / limit),
 * three func_003C4138 approaches on the owner's p70, then on state 0x2B the follow angle p->fB8 is smoothed (func_00382C58) towards the angle to the best candidate of a
 * list (D_L01_0021DE20[b21]: bit 15 = last entry; candidates of class 0x323 / 0x2F6 / 0x19C4 in front of the camera, scored by distance - 10 * dot), else towards
 * e->f58 (or a field of the hero-side object when q->w40 == 1); state 0x24 smooths the same way; the tail builds the offset vector (sin, cos, 0) * -pa[0] + pa[4], adds
 * e->v40 and stores it at o + 0x30 whatever func_0038CB00(p + 0x1E) returns (two identical arms: retail branches on the call).
 * What took it from 120 to 24 aligned rows: (1) THE ARM ORDER of the 0x2B state: retail has the default arm (target = e->f58) right after the tests, so the condition is
 * `if ((D != 0xE && D != 7 && D != 9) || ((tgt = e->x138) != 0 && tgt[0x21] == 0xFF)) { default } else { search }` (`tgt` assigned inside the second operand; the search
 * loop's `lbu 0x21(s3)` with s3 == 0 is the null case of the `||`), with one func_00382C58 call per arm (jump2 merges the tails); 120 -> 24. (2) `ang + 1` instead of
 * `p + 0xBC` for the call's pointer (more references to ang), (3) a separate variable for the first read of e->x138 (`t0`), (4) `pa = p + 0xA0` read at the end through
 * `-*pa` / `pa[4]` so p dies early (retail keeps p + 0xA0 in a stack slot).
 * Left: (a) the clamp block at the top (about 14 words): retail loads e->f48 first and has TWO pseudos for the limit (`mov.s f1,f2` in the branch slot, `mov.s f12,f1`,
 * `div.s f12,f12,f1`); 6 spellings (copy variables, order of the loads, if / else-if vs sequential, `d > lim`) did not give the copy; (b) the VU role problem
 * of the helpers in the candidate loop (retail: first-loaded operand in vf1 and the result in vf2; vec_sub_ba gives the mirror); (c) the argument moves of the last call:
 * retail moves f13 before `a0` in the best-candidate arm. */
#include "common.h"

/* localdecomp:start func_L01_003EC1A0 */
extern u8 D_L01_001E2A40_003EC1A0[];
extern u16 *D_L01_0021DE20_003EC1A0[];
extern u8 *D_L01_001E001C_003EC1A0;
extern s32 D_001D545C_003EC1A0;
extern void func_003C4138(void *, f32, f32);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038CB00(void *);

void func_L01_003EC1A0(u8 *o)
{
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    u8 *p;
    u8 *q;
    u8 *ent;
    u8 *e;
    f32 *ang;
    f32 *pa;
    u8 *tgt;
    u8 *t0;
    u8 *best;
    u8 *mob;
    u16 *l;
    f32 d;
    f32 lim;
    f32 t;
    f32 dist;
    f32 h;
    f32 bd;
    f32 dot;
    f32 x;

    p = *(u8 **)(o + 0x70);
    ent = D_L01_001E2A40_003EC1A0 + *(s32 *)(o + 0x94) * 0x460;
    q = p + 0x40;
    e = ent + 0x150;
    pa = (f32 *)(p + 0xA0);
    ang = (f32 *)(p + 0xB8);
    t0 = *(u8 **)(e + 0x138);
    if (t0 != 0 && *(s32 *)(e + 0x100) == 0x2B) {
        d = *(f32 *)(t0 + 0x18) - *(f32 *)(e + 0x48);
        lim = *(f32 *)(e + 0x140);
        if (lim < d) {
            d = lim;
        } else if (d < 0.0f) {
            d = 0.0f;
        }
        t = d / lim;
        h = t + t;
        dist = t + 3.65f;
    } else {
        dist = 4.64f;
        h = 2.0f;
    }
    func_003C4138(*(u8 **)(*(u8 **)(ent + 0x50) + 0x70) + 0xA0, dist, 0.16000001f);
    func_003C4138(*(u8 **)(*(u8 **)(ent + 0x50) + 0x70) + 0xB0, h, 0.080000006f);
    func_003C4138(*(u8 **)(*(u8 **)(ent + 0x50) + 0x70) + 0x8C, h - 0.5f, 0.16000001f);
    if (*(s32 *)(e + 0x100) == 0x2B) {
        if ((D_001D545C_003EC1A0 != 0xE && D_001D545C_003EC1A0 != 7 && D_001D545C_003EC1A0 != 9)
            || ((tgt = *(u8 **)(e + 0x138)) != 0 && tgt[0x21] == 0xFF)) {
            *ang = func_00382C58(ang + 1, *ang, *(f32 *)(e + 0x58), 0.00125f, 0.175f, 0.0f);
        } else {
            best = 0;
            bd = 1000.0f;
            l = D_L01_0021DE20_003EC1A0[tgt[0x21]];
            if (l != 0) {
                do {
                    mob = D_L01_001E001C_003EC1A0 + ((*l & 0x7FFF) << 8);
                    if (mob != tgt) {
                        if (*(s16 *)(mob + 0xAA) == 0x323 || *(s16 *)(mob + 0xAA) == 0x2F6 || *(s16 *)(mob + 0xAA) == 0x19C4) {
                            vec_sub_ba(&v10, mob + 0x10, tgt + 0x10);
                            func_0038CF68(&v20, &v10, 1.0f);
                            v30.x = func_0038D098(*(f32 *)(e + 0x58));
                            v30.y = func_0038D0B0(*(f32 *)(e + 0x58));
                            v30.z = 0.0f;
                            dot = func_0038CE68(&v20, &v30);
                            if (0.0f < dot) {
                                x = func_0038CEA8(&v10) - dot * 10.0f;
                                if (x < bd) {
                                    best = mob;
                                    bd = x;
                                }
                            }
                        }
                    }
                } while (*(s16 *)l++ >= 0);
            }
            if (best != 0) {
                vec_sub_ab(&v10, best + 0x10, tgt + 0x10);
                *ang = func_00382C58(ang + 1, *ang, func_0038D160(v10.x, v10.y), 0.00125f, 0.175f, 0.0f);
            } else if (*(s32 *)(q + 0x40) == 1) {
                *ang = func_00382C58(ang + 1, *ang, *(f32 *)(*(u8 **)(q + 0x44) + 0xF8), 0.00125f, 0.175f, 0.0f);
            } else {
                *ang = func_00382C58(ang + 1, *ang, *(f32 *)(e + 0x58), 0.00125f, 0.175f, 0.0f);
            }
        }
    } else if (*(s32 *)(e + 0x100) == 0x24) {
        if (*(s32 *)(q + 0x40) == 1) {
            *ang = func_00382C58(ang + 1, *ang, *(f32 *)(*(u8 **)(q + 0x44) + 0xF8), 0.00125f, 0.175f, 0.0f);
        } else {
            *ang = func_00382C58(ang + 1, *ang, *(f32 *)(e + 0x58), 0.00125f, 0.175f, 0.0f);
        }
    }
    *(f32 *)(q + 0x30) = func_0038D098(*ang);
    *(f32 *)(q + 0x34) = func_0038D0B0(*ang);
    *(s32 *)(q + 0x38) = 0;
    *(f32 *)(q + 0x3C) = *(f32 *)(q + 0x38);
    func_0038CF68(&v0, q + 0x30, -*pa);
    v0.z = v0.z + pa[4];
    vec_add_ba(&v0, &v0, e + 0x40);
    if (func_0038CB00(p + 0x1E) != 0) {
        *(vu0_q *)(o + 0x30) = *(vu0_q *)&v0;
    } else {
        *(vu0_q *)(o + 0x30) = *(vu0_q *)&v0;
    }
}
/* localdecomp:end func_L01_003EC1A0 */
