/* PAL near miss (wave 13c, worker c44): func_L39_005BB950, rebuilt from wave 13 r24's first draft. File
 * src/levels/shared/L39_005BAF38.c holds only a LINKER_REMNANT, func_L39_005BAFA8 (INCLUDE_ASM) and this
 * function, so the whole file can take "-mvu0-use-vf0-vf2 -O2 -G8 -mno-check-zero-division @ps2as" (an
 * existing level line): no -fopt-stack gives retail's sq saves and frame 0x190 (NEEDS sq_ra row
 * 'func_L39_005BB950'), Ps2EeAs li.s gives 999999.0f/0.95f/0.1f/pi inline, -mvu0-use-vf0-vf2 lets vu0.h's
 * vec_add_ab/vec_sub_ab interleave as retail. Under that line (level 39, sq_ra row injected in memory):
 * 111 positional diffs, aligned 15 of 523 retail words differ (build/codex/wc44/lcs.py).
 * Levers: the scan loop as for (i...; i++) with continues (n = i + 1 in $s5, count spilled), f32 dummy[12],
 * pos a loop-level f32[4] aligned(16) that is also the 0x19E6 decode buffer (retail shares 0x40), d an
 * f32[4], b1 = b + 1 as its own local for the table index, the exclusion/id lists as for loops with break
 * (obj == excl[n]), the list insertion as a for loop then e->next = p and the p / tail cases with head != 0
 * first, the final loop's object a new local and out[(*count)++], the out[0] swap inside the search loop,
 * aMin/bMin in that parameter order, (dec ^ 0x14) == 0 (retail's xori/beqz).
 * Left (15 words): retail reads the 0x19E6 byte again after its test (here the test's register is reused:
 * one word short); the head load after the entry's pos/score stores (here it is hoisted above them) and
 * the head reload in the final loop's test; the 0x12 argument's place.
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_005BB950 */
typedef struct Cand_005BB950 {
    u8 *obj;
    f32 score;
    struct Cand_005BB950 *next;
    struct Cand_005BB950 **prev;
    vu0_q pos;
} Cand_005BB950;

typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(void *, s32);
} VT_005BB950;
typedef struct {
    u8 pad0[3];
    u8 b3;
    u8 pad4[0x14 - 4];
    VT_005BB950 *vt;
    u8 pad18[0x19E6 - 0x18];
    u8 b19E6;
} T_005BB950;

extern u8 *D_L39_00264D68[];
extern Cand_005BB950 D_L39_002943C0[];
extern u8 D_L39_004997E0[];

u8 *func_L39_005BB950(f32 *org, f32 *dir, s32 mode, s32 *count, u8 **out, s32 max, u8 **excl, s32 flag,
                      s32 *ids, s16 req, f32 aLim, f32 bLim, f32 maxDist, f32 bMin, f32 aMin) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(f32 *);
    extern f32 func_0038CEA8(void *);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_0038CE20(f32 *, void *, f32);
    extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
    extern f32 *func_00382348(void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_L39_005B8928(u8 *);
    extern T_005BB950 *func_L39_0061D7B0(u8 *);
    f32 dummy[16];
    Cand_005BB950 *head;
    Cand_005BB950 *tail;
    Cand_005BB950 *e;
    Cand_005BB950 *p;
    u8 *best;
    u8 *obj;
    T_005BB950 *t;
    f32 *r;
    f32 heading, pitch, dist, w, angA, angB, score, thr, lim;
    s32 poolUsed;
    s32 i, s18, s19, extra;

    dummy[0] = 1.0f;
    dummy[4] = 0.0f;
    best = 0;
    poolUsed = 0;
    tail = 0;
    *count = 0;
    head = 0;
    thr = 999999.0f;

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

    for (i = 0; i < 0x100; i++) {
        f32 pos[4] __attribute__((aligned(16)));

        obj = D_L39_00264D68[i];
        if (obj == 0) {
            continue;
        }
        if (req != 0) {
            if (obj[0x31] == 0) {
                continue;
            }
        }
        if (!(*(u16 *)(obj + 0x34) & 0x1000)) {
            continue;
        }
        if (mode == 0) {
            if (obj[0xBE] & 0x10) {
                continue;
            }
        } else if (mode == 1) {
            if (obj[0xBE] & 0x8) {
                continue;
            }
        }
        s18 = func_L39_005B8928(obj);
        s19 = (*(s16 *)(obj + 0xAA) == 0x1099);
        if (s18 != 0) {
            if (flag == 0) {
                continue;
            }
        }
        t = func_L39_0061D7B0(obj);
        extra = 0;
        if (t != 0) {
            if ((t->b3 & 0xF) == 0) {
                u8 *addr = &t->b19E6;
                u32 dec = 0;
                if (t->b19E6 != 0) {
                    u8 *p = (u8 *)pos;
                    s32 b = *addr;
                    s32 b1 = b + 1;
                    s32 k = ((u32)addr - b) & 7;
                    s32 j;
                    for (j = 0; j < 40; j += 5) {
                        *p++ = D_L39_004997E0[b1 + ((k + j) & 7) * 255];
                    }
                    ((u32 *)pos)[0] ^= (u32)addr;
                    ((u32 *)pos)[1] ^= ((u32 *)pos)[0];
                    dec = ((u32 *)pos)[1];
                }
                if ((dec ^ 0x14) == 0) {
                    continue;
                }
                extra = 1;
            }
            if (t->vt->f1C(t, mode) != 0) {
                continue;
            }
            if (*(s16 *)(obj + 0xAA) == 0x109D) {
                if (t->vt->f1C(t, -1) != 0) {
                    continue;
                }
            }
        }
        if (s19 == 0) {
            r = func_00382348(obj);
        } else {
            r = dummy;
        }
        if (r == 0) {
            continue;
        }
        if (r[0] <= 0.0f) {
            if (s18 == 0) {
                continue;
            }
        }
        if (!(obj != 0 && *(u8 **)(obj + 0x24) != 0 && (*(u8 **)(obj + 0x24))[0x46] == 5)) {
            if (s18 == 0) {
                if (s19 == 0) {
                    continue;
                }
            }
        }
        if (excl != 0) {
            s32 n;
            for (n = 0; excl[n] != 0; n++) {
                if (obj == excl[n]) {
                    break;
                }
            }
            if (excl[n] != 0) {
                continue;
            }
        }
        if (ids != 0) {
            s32 n;
            for (n = 0; ids[n] != -1; n++) {
                if (*(s16 *)(obj + 0xAA) == ids[n]) {
                    break;
                }
            }
            if (ids[n] != -1) {
                continue;
            }
        }
    ok:
        {
            f32 d[4] __attribute__((aligned(16)));
            *(vu0_q *)pos = *(vu0_q *)(obj + 0x10);
            if (*(f32 *)(obj + 0xE8) < 0.95f) {
                func_0038CE20(d, obj + 0xE0, r[4]);
                vec_add_ab(pos, pos, d);
            } else {
                pos[2] += r[4];
            }
            vec_sub_ab(d, pos, org);
            dist = func_0038CEA8(d);
            if (maxDist < dist) {
                continue;
            }
            if (dist < 0.1f) {
                continue;
            }
            w = func_L01_004451D0(-2.0f, 0.0f, 1.0f, 0.0f, dist / maxDist);
            angA = 0.0f;
            angB = 0.0f;
            if (aLim < 3.1415927f || bLim < 3.1415927f) {
                angA = func_0038DBA0(func_0038D160(d[0], d[1]), heading);
                lim = aLim;
                if (0.0f < aMin) {
                    lim = aMin + (aLim - aMin) * w;
                }
                if (lim <= angA) {
                    continue;
                }
                angB = func_0038DBA0(func_0038D160(func_0038CED8(d), d[2]), pitch);
                lim = bLim;
                if (0.0f < bMin) {
                    lim = bMin + (bLim - bMin) * w;
                }
                if (lim <= angB) {
                    continue;
                }
            }
            score = dist + angA * dist + angB * dist;
            if (s18 != 0) {
                score += 8.0f;
            }
            if (extra != 0) {
                score += -8.0f;
            }
            if (poolUsed < 32) {
                e = &D_L39_002943C0[poolUsed];
                poolUsed++;
            } else {
                e = tail;
                *e->prev = 0;
            }
            e->obj = obj;
            e->pos = *(vu0_q *)pos;
        }
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
    }

    while (head != 0) {
        p = head;
        if (p->score < thr) {
            u8 *o = p->obj;
            if (func_003D3CB0(org, &p->pos, 0x12, o, 0) == 0) {
                best = o;
                thr = head->score;
                if (out != 0) {
                    if (*count < max) {
                        out[(*count)++] = o;
                    }
                }
            }
        }
        head = head->next;
    }

    if (out != 0) {
        if (best != 0) {
            s32 idx;
            for (idx = 0; idx < max; idx++) {
                if (out[idx] == best) {
                    if (idx != 0) {
                        u8 *tmp = out[0];
                        out[0] = best;
                        out[idx] = tmp;
                    }
                    break;
                }
            }
            if (idx == max) {
                out[0] = best;
            }
        }
        if (*count < max) {
            out[*count] = 0;
        }
    }
    return best;
}
/* localdecomp:end func_L39_005BB950 */
