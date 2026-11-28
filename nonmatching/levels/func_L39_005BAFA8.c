/* wave 13c c43 (2026-11-28): 324 diff at level 39 under the line
 * '-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as' (L01_003225F8.c's; tools/check.py
 * --flags="-fno-opt-stack @ps2as -mvu0-use-vf0-vf2") with an sq_ra_funcs row injected (r25's draft: 480
 * there). Frame 0x1F0, sq saves, li.s, the parameter spill slots and the VU0 sequences now follow retail.
 * Changed from r25: aLim is the third parameter (EABI: same registers; retail spills it to 0xA4 between dir
 * and count), sp90[2] became two scalars (head at 0x98), thr = 999999.0f (0x497423F0) declared after best,
 * VU0 ops as vu0.h helpers (cross-jumped like retail) and one "j" block for sc += dirV, angA = angB = 0
 * after the weight call (0.0f stays in $f27 as retail), the bLim test in both angle branches (retail's
 * cross-jumped tails), obj/hid on the left of the search compares, the insert as if (head != 0) {...} else
 * {first}. Left: angA/angB in $f23/$f22 (retail $f22/$f23), reload registers in the excl/ids searches,
 * $f0/$f2 roles for sz, store order of the pool entry, one instruction short overall.
 * Earlier notes (r25):
 * First draft (wave 13, r25), 605 diff at level 39 with the file's line (-O2 -G8 -fopt-stack
 * -mno-check-zero-division), mostly positional: two things in retail come from another line.
 * (1) Retail saves $s0-$fp/$ra with sq in 16-byte slots (frame 0x1F0): that needs a line
 * without -fopt-stack plus an sq_ra_funcs row (--sq-ra alone still leaves the 8-byte slots and the
 * 0x1A0 frame). (2) Every float constant is lui/ori/mtc1 in retail, as SN's Ps2EeAs expands li.s
 * (@ps2as); under this line GNU as puts them in .lit4 and loads them through $gp. The file holds no
 * other C, so the line -O2 -G8 -mno-check-zero-division @ps2as would be the coordinator's call.
 * Structure from the native port's C, corrected from retail: float parameter order (aLim, bLim,
 * maxDist, bMin, aMin), i++ at the continue label (retail's ddiu s4, s1, 1 in the delay slots),
 * the -1/NULL-terminated searches as while loops plus a re-test, the sorted insert as a search loop,
 * the five VU0 vector ops as one asm block each (retail interleaves compiler insns in two of them:
 * ddiu s3, sp, 0x20/daddu a0, s3 in d = pos - org, which one block cannot), D_L39_002429BC read
 * both absolute (.extern 16) and through its gp slot D_001D72AC_sda as retail does.
 * Mnemonic alignment (W/aligndiff.py --ops): 514 of 618 retail instructions line up.
 */#include "common.h"

/* localdecomp:start func_L39_005BAFA8 */
#include "vu0.h"
typedef int u128_005BAFA8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_005BAFA8;
typedef struct Cand_005BAFA8 {
    u8 *obj;
    f32 score;
    struct Cand_005BAFA8 *next;
    struct Cand_005BAFA8 **prev;
    V4_005BAFA8 pos;
} Cand_005BAFA8;

extern u8 *D_L39_00292C20[];
extern Cand_005BAFA8 D_L39_002943C0[];
extern s32 D_L39_002429BC;
__asm__(".extern D_L39_002429BC, 16");
extern s32 D_001D72AC_sda;
__asm__(".extern D_001D72AC_sda, 4");

u8 *func_L39_005BAFA8(f32 *org, f32 *dir, f32 aLim, s32 *count, u8 **out, s32 max, u8 **excl, s32 flagB4,
                      s32 *ids, s16 req, s16 optC0, s16 reqC4, f32 bLim, f32 maxDist, f32 bMin, f32 aMin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D0C8(f32);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
    extern f32 *func_00382348(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_L39_005B8928(u8 *);
    extern void func_L01_00439880(u8 *, s32 *, s32 *);
    extern void func_L39_005BC330(void *, void *, s32);
    V4_005BAFA8 tmp;
    V4_005BAFA8 pos;
    V4_005BAFA8 d;
    V4_005BAFA8 up;
    V4_005BAFA8 h;
    V4_005BAFA8 dH;
    V4_005BAFA8 dirV;
    V4_005BAFA8 dirH;
    V4_005BAFA8 sc;
    s32 n90;
    s32 n94;
    Cand_005BAFA8 *head;
    Cand_005BAFA8 *tail;
    Cand_005BAFA8 *e;
    Cand_005BAFA8 *p;
    u8 *best;
    f32 thr;
    u8 *obj;
    f32 *r;
    f32 heading;
    f32 pitch;
    f32 dist;
    f32 w;
    f32 angB;
    f32 angA;
    f32 score;
    f32 lim;
    f32 f20;
    f32 f21;
    f32 dot;
    f32 sz;
    s32 poolUsed;
    s32 i;
    s32 s18;
    s32 s21;
    s32 spDC;
    s32 hid;
    s32 k;

    head = 0;
    best = 0;
    poolUsed = 0;
    tail = 0;
    thr = 999999.0f;
    *count = 0;
    if (aLim == 0.0f) {
        return 0;
    }
    if (bLim == 0.0f) {
        return 0;
    }
    if (maxDist == 0.0f) {
        return 0;
    }
    heading = func_0038D160(dir[0], dir[1]);
    pitch = func_0038D160(func_0038CED8(dir), dir[2]);
    i = 0;
    obj = D_L39_00292C20[0];
    if (obj != 0) {
        do {
            if (req != 0) {
                if (obj[0x31] == 0) {
                    goto next;
                }
            }
            hid = *(s16 *)(obj + 0xAA);
            spDC = 0;
            if (hid == 0x1A90 || hid == 0x1ADE) {
                spDC = 1;
            }
            s18 = 0;
            s21 = func_L39_005B8928(obj);
            if (obj != 0 && *(u8 **)(obj + 0x24) != 0 && (*(u8 **)(obj + 0x24))[0x46] == 0x16 &&
                (*(u16 *)(obj + 0x34) & 0x4000) && obj[0x31] != 0) {
                func_L01_00439880(obj, &n90, &n94);
                if (n94 > 0) {
                    s18 = 1;
                    spDC = 1;
                }
            }
            if (s21 != 0) {
                if (flagB4 == 0) {
                    goto next;
                }
            }
            if (s18 != 0) {
                if (reqC4 == 0) {
                    goto next;
                }
            }
            r = func_00382348(obj);
            if (r == 0 || (r[0] <= 0.0f && s21 == 0)) {
                if (s18 == 0) {
                    goto next;
                }
            }
            if (!(obj != 0 && *(u8 **)(obj + 0x24) != 0 && (*(u8 **)(obj + 0x24))[0x46] == 5)) {
                if (s21 == 0) {
                    if (s18 == 0) {
                        goto next;
                    }
                }
            }
            if (excl != 0) {
                k = 0;
                while (excl[k] != 0 && obj != excl[k]) {
                    k++;
                }
                if (excl[k] != 0) {
                    goto next;
                }
            }
            if (ids != 0) {
                if (ids[0] != -1) {
                    hid = *(s16 *)(obj + 0xAA);
                    k = 0;
                    while (ids[k] != -1 && hid != ids[k]) {
                        k++;
                    }
                    if (ids[k] != -1) {
                        goto next;
                    }
                }
            }
            *(u128_005BAFA8 *)&pos = *(u128_005BAFA8 *)(obj + 0x10);
            if (r != 0) {
                if (D_L39_002429BC != 0 || optC0 != 0) {
                    func_0038CE20(&tmp, obj + 0xE0, r[4]);
                    vec_add_ab(&pos, &pos, &tmp);
                } else {
                    pos.z += r[4];
                }
            } else {
                sz = *(f32 *)(obj + 0xC);
                if (D_L39_002429BC != 0 || optC0 != 0) {
                    func_0038CE20(&tmp, obj + 0xE0, sz * 0.0009765625f);
                    vec_add_ab(&pos, &pos, &tmp);
                } else {
                    pos.z += sz * 0.0009765625f;
                }
            }
            vec_sub_ab(&d, &pos, org);
            dist = func_0038CEA8(&d);
            if (maxDist < dist) {
                goto next;
            }
            if (dist < 0.1f) {
                goto next;
            }
            w = func_L01_004451D0(-2.0f, 0.0f, 1.0f, 0.0f, dist / maxDist);
            angA = angB = 0.0f;
            if (aLim < 3.1415927f || bLim < 3.1415927f) {
                if (D_001D72AC_sda == 0) {
                    angA = func_0038DBA0(func_0038D160(d.x, d.y), heading);
                    lim = aLim;
                    if (0.0f < aMin) {
                        lim = aMin + (aLim - aMin) * w;
                    }
                    if (lim <= angA) {
                        goto next;
                    }
                    angB = func_0038DBA0(func_0038D160(func_0038CED8(&d), d.z), pitch);
                    lim = bLim;
                    if (0.0f < bMin) {
                        lim = bMin + (bLim - bMin) * w;
                    }
                    if (lim <= angB) {
                        goto next;
                    }
                } else {
                    func_L39_005BC330(org, &up, 1);
                    dot = func_0038CE68(&up, &d);
                    func_0038CE20(&h, &up, dot);
                    vec_sub_ab(&dH, &d, &h);
                    dot = func_0038CE68(&up, dir);
                    func_0038CE20(&dirV, &up, dot);
                    vec_sub_ba(&dirH, dir, &dirV);
                    angA = func_0038CE68(&dirH, &dH);
                    if (angA < 0.0f) {
                        goto next;
                    }
                    f21 = func_0038CEA8(&dH);
                    if (f21 == 0.0f) {
                        goto next;
                    }
                    f20 = func_0038CEA8(&dirH);
                    if (f20 == 0.0f) {
                        goto next;
                    }
                    angA = 1.5707964f - func_0038D0C8(angA / (f21 * f20));
                    lim = aLim;
                    if (0.0f < aMin) {
                        lim = aMin + (aLim - aMin) * w;
                    }
                    if (lim <= angA) {
                        goto next;
                    }
                    func_0038CE20(&sc, &dH, f20 / f21);
                    {
                        vu0_q q1, q2;
                        __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(sc));
                        __asm__("lqc2 %0, %1" : "=j"(q2) : "m"(dirV));
                        __asm__("vadd.xyz %0, %1, %2" : "=j"(q1) : "j"(q1), "j"(q2));
                        __asm__("sqc2 %1, %0" : "=m"(sc) : "j"(q1));
                    }
                    f20 = func_0038CEA8(&sc);
                    angB = 1.5707964f - func_0038D0C8(func_0038CE68(&sc, &d) / (f20 * dist));
                    lim = bLim;
                    if (0.0f < bMin) {
                        lim = bMin + (bLim - bMin) * w;
                    }
                    if (lim <= angB) {
                        goto next;
                    }
                }
            }
            score = angA * 3.0f + angB * 0.2f * dist + dist * 0.1f;
            if (s21 != 0 || spDC != 0) {
                score = score * (maxDist * 0.8f);
            }
            if (poolUsed < 32) {
                e = &D_L39_002943C0[poolUsed];
                poolUsed++;
            } else {
                e = tail;
                *e->prev = 0;
            }
            e->obj = obj;
            *(u128_005BAFA8 *)&e->pos = *(u128_005BAFA8 *)&pos;
            e->score = score;
            if (head != 0) {
                for (p = head; p != 0; p = p->next) {
                    if (e->score < p->score) {
                        break;
                    }
                }
                e->next = p;
                if (p != 0) {
                    e->prev = p->prev;
                    *p->prev = e;
                    p->prev = &e->next;
                } else {
                    tail->next = e;
                    e->prev = &tail->next;
                    tail = e;
                }
            } else {
                tail = e;
                head = e;
                e->prev = &head;
                e->next = 0;
            }
        next:
            i++;
            obj = D_L39_00292C20[i];
        } while (obj != 0);
    }

    while (head != 0) {
        p = head;
        obj = p->obj;
        if (p->score < thr) {
            if (func_003D3CB0(org, &p->pos, 0x12, obj, 0) != 0) {
                goto skip;
            }
            best = obj;
            thr = head->score;
        }
        if (out != 0) {
            if (*count < max) {
                out[*count] = obj;
                (*count)++;
            }
        }
    skip:
        head = head->next;
    }

    if (out != 0) {
        if (best != 0) {
            u8 *first;

            for (k = 0; k < max; k++) {
                if (out[k] == best) {
                    if (k != 0) {
                        first = out[0];
                        out[0] = out[k];
                        out[k] = first;
                    }
                    break;
                }
            }
            if (k == max) {
                out[0] = best;
            }
        }
        if (*count < max) {
            out[*count] = 0;
        }
    }
    return best;
}
/* localdecomp:end func_L39_005BAFA8 */
