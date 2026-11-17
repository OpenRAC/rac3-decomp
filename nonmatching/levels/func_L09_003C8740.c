/* near miss (levels 09, 18, 20, 24, 29): func_L09_003C8740, 0xBA0 bytes, PAL rewrite by e7b (2026-11-17) of the NTSC-U draft (func_L09_003C6D40, 650 words off, ad-hoc asm): 13 aligned rows under the file's own flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2), 14 at 18/20/24/29 (same rows). VU code through include/vu0.h only. What got it here: the frac<=0 branch is plain vec_sub_ab/vec_add_ba on result (retail's 0xB0/0xD0 slots are reload spills of the helpers' VU0 pseudos, not locals: frame 0x150 -> 0x160); the collision record D_L09_001E98C0 read as the symbol at some sites and through a per-use pointer local (COLL_3C8740 statement expression) at others (a greedy flip over the 11 sites: 90 -> 50); prototypes func_L01_00446E38(void *, void *, f32, s32, void *) and func_L01_00446760(void *, void *, s32, f32, void *) (float position: 50 -> 31); PAL's 0.020000001f; `damage = 3.0f;` before the level-9 test (retail's 3.0 in $f20 before the branch); D_001A71A0 as an array (split lui/lw); `damaged = 0` as a statement before the end vector; PAL-only `if (mode == 12 && velocity->z > 0) velocity->z = 0` with `s32 mode = 0` set once at the top (retail's `move $v1, $zero; bne $v1, $v0(12)`: a REG_EQUIV constant that cprop does not fold into the jump). Left (13 rows, all in the final switch on side): retail's cases 0 and 1 are `lui/addiu a1; b; addiu a0` (a0 in the b delay slot, beqz's delay slot a nop), ours `addiu a0; b; addiu a1` with the lui stolen into the beqz slot: sched2 issues a0 beside the %hi in cases 0/1. Tried: default/no-break forms, casts, array decls, if-chain (26), goto to a shared call (12 but other rows move). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003C8740 */
#define COLL_3C8740 ({ u8 *c_ = D_L09_001E98C0; c_; })

extern vu0_v4 D_L09_001DE910[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE910, 4");
extern vu0_v4 D_L09_001DE920;
extern vu0_v4 D_L09_001DE930;
extern vu0_v4 D_L09_001DE940;
extern f32 D_L09_001DA9F0;
__asm__(".extern D_L09_001DA9F0, 4");
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern void *D_001A71A0[];
extern u8 D_L09_001E98C0[];
extern vu0_v4 D_L09_001E98F0;
extern f32 D_L09_002F1D50[];
extern u8 D_L09_001D66B0[8];

extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern f32 func_L01_00446E38(void *, void *, f32, s32, void *);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern s32 func_003C4B50(void *);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern s32 func_L01_0041A4F0(void);
extern f32 *func_00382348(void *);
extern void func_L01_00446760(void *, void *, s32, f32, void *);
extern void func_L01_00446978(void *, void *);

s32 func_L09_003C8740(u8 *m, vu0_v4 *result, vu0_v4 *velocity, vu0_v4 *hit, s32 *unused, s32 side, vu0_v4 *origin,
                      f32 speed, f32 unusedf, f32 radius) {
    vu0_v4 delta, pos, end, tmp, normal, nearpos;
    u8 record[0x30] __attribute__((aligned(16)));
    u8 *d = *(u8 **)(m + 0x68);
    u8 *aux = *(u8 **)(d + 0x6D0);
    u8 *object;
    s32 touched = 0, pass = 0, damaged;
    s32 mode = 0;
    f32 frac, damage, dotx, doty, dotz, length;
    f32 *hp;

    func_0038D000(&tmp, &D_L09_001DE910[side], m + 0xC0);
    vec_add_ba(&pos, &tmp, m + 0x10);
    *(vu0_q *)origin = *(vu0_q *)&pos;
    vec_add_ab(&tmp, &pos, velocity);
    *unused = 0;
    *(vu0_q *)&delta = *(vu0_q *)velocity;
    damaged = 0;
    vec_add_ab(&end, &pos, &delta);
    frac = func_L01_00446E38(&pos, &end, 1.0f, 0x84, m);
    if (frac <= 0.0f) {
        if (func_L01_003FB640(&pos, 4, m, 1.0f)) {
            vec_sub_ab(&tmp, &D_L09_001E98F0, &pos);
            vec_add_ba(result, result, &tmp);
        }
        goto final;
    }
    if (!(frac < 1.0f)) {
        goto final;
    }
again:
    if (m[0x20] == 3) {
        qzero(aux + 0xC0);
        *(s32 *)(aux + 0x138) = 0;
    }
    touched = 1;
    *(vu0_q *)hit = *(vu0_q *)(D_L09_001E98C0 + 0x20);
    d[0x714] = touched;
    object = *(u8 **)(COLL_3C8740 + 0x18);
    if (object) {
        if (func_003C4B50(object)) {
            func_L01_00446A70(*(void **)(D_L09_001E98C0 + 0x18), m, 0x10000, D_L09_001E98C0 + 0x20, D_L09_001D66B0, 5.0f);
            damaged = 1;
        } else if (!pass) {
            object = *(u8 **)(COLL_3C8740 + 0x18);
            if (*(s16 *)(object + 0xAA) == 0x1BAE || *(s16 *)(object + 0xAA) == 0x1E58) {
                damage = speed / *(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 40.0f + 60.0f;
                if (func_L01_0041A4F0()) {
                    if (D_001D545C == 7 && D_0014275B[0] != 0) {
                        damage *= D_L09_001DA9F0;
                    } else {
                        damage *= D_L09_002F1D50[D_001D545C];
                    }
                }
                func_L01_00446A70(*(void **)(COLL_3C8740 + 0x18), m, 1, D_L09_001E98C0 + 0x20, velocity, damage);
                damaged = 1;
            } else if (*(u8 **)(object + 0x24) && (*(u8 **)(object + 0x24))[0x46] == 5) {
                hp = func_00382348(object);
                if (hp && *hp > 0.0f) {
                    damage = 3.0f;
                    if (D_001D545C == 9) {
                        damage = speed / (*(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 0.020000001f) * 17.0f + damage;
                    } else {
                        damage = speed / (*(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 0.020000001f) * 80.0f + 20.0f;
                    }
                    if (func_L01_0041A4F0()) {
                        if (D_001D545C == 7 && D_0014275B[0] != 0) {
                            damage *= D_L09_001DA9F0;
                        } else {
                            damage *= D_L09_002F1D50[D_001D545C];
                        }
                    }
                    *(vu0_q *)&tmp = *(vu0_q *)velocity;
                    tmp.z = 0.0f;
                    func_0038CE20(&tmp, &tmp, 5.0f);
                    vec_sub_ba(&nearpos, *(u8 **)(COLL_3C8740 + 0x18) + 0x10, m + 0x10);
                    func_0038CF68(&nearpos, &nearpos, 1.0f);
                    if (func_0038CE68(m + 0xD0, &nearpos) > 0.0f) {
                        func_0038CE20(&nearpos, m + 0xD0, 0.5f);
                    } else {
                        func_0038CE20(&nearpos, m + 0xD0, -0.5f);
                    }
                    vec_add_ab(&tmp, &tmp, &nearpos);
                    tmp.w = 5627.9248f;
                    func_L01_00446760(record, D_001A71A0[0], 0x10000, damage, &tmp);
                    damaged = 1;
                    record[0x18] = 10;
                    record[0x19] = 2;
                    *(u16 *)(record + 0x1A) = *(u16 *)(m + 0xAA);
                    func_L01_00446978(*(void **)(COLL_3C8740 + 0x18), record);
                    *hp -= damage;
                    if (*hp < 0.0f) {
                        *hp = 0.0f;
                    }
                }
            }
        }
        *(f32 *)(COLL_3C8740 + 0x48) = 0.0f;
    }
    if (*(f32 *)(COLL_3C8740 + 0x48) > 0.0f && D_001D545C != 24) {
        *(f32 *)(D_L09_001E98C0 + 0x48) = 0.0f;
    }
    func_0038CF68(&normal, D_L09_001E98C0 + 0x40, 1.0f);
    dotx = func_0038CE68(&normal, m + 0xC0);
    doty = func_0038CE68(&normal, m + 0xD0);
    dotz = func_0038CE68(&normal, m + 0xE0);
    if (side == 0) {
        if (dotx < 0.0f && doty > 0.0f && *(f32 *)(m + 0xE8) < 0.707f) {
            func_0038CE20(&normal, m + 0xC0, -1.0f);
        } else if (dotx > 0.0f && doty < 0.0f) {
            func_0038CE20(&normal, m + 0xD0, -1.0f);
        } else if (dotz > 0.5f && doty > 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 2) {
        if (dotx > 0.0f && doty > 0.0f) {
            func_0038CE20(&normal, m + 0xC0, 1.0f);
        } else if (dotx < 0.0f && doty < 0.0f) {
            func_0038CE20(&normal, m + 0xD0, -1.0f);
        } else if (dotz > 0.5f && doty > 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 1) {
        if (dotx < 0.0f && doty < 0.0f && *(f32 *)(m + 0xE8) < 0.707f) {
            func_0038CE20(&normal, m + 0xC0, -1.0f);
        } else if (dotx > 0.0f && doty > 0.0f) {
            func_0038CE20(&normal, m + 0xD0, 1.0f);
        } else if (dotz > 0.5f && doty < 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 3) {
        if (dotx > 0.0f && doty < 0.0f) {
            func_0038CE20(&normal, m + 0xC0, 1.0f);
        } else if (dotx < 0.0f && doty > 0.0f) {
            func_0038CE20(&normal, m + 0xD0, 1.0f);
        } else if (dotz > 0.5f && doty < 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    }
    damage = func_0038CE68(&delta, &normal) * -1.01f;
    func_0038CE20(&end, &delta, frac);
    vec_add_ba(&pos, &pos, &end);
    func_0038CE20(&tmp, &normal, damage * (1.0f - frac));
    vec_add_ba(result, result, &tmp);
    func_0038CE20(&tmp, &normal, damage);
    if (!damaged) {
        vec_add_ab(velocity, velocity, &tmp);
    }
    if (mode == 12 && velocity->z > 0.0f) {
        velocity->z = 0.0f;
    }
    length = func_0038CEA8(velocity);
    if (speed < length) {
        func_0038CE20(velocity, velocity, speed / length);
        length = speed;
    } else if (length < speed) {
        speed = length;
    }
    if (*(f32 *)(aux + 0x138) > 0.0f) {
        *(f32 *)(aux + 0x138) = length;
    } else if (length < speed) {
        *(f32 *)(aux + 0x138) = -length;
    }
    func_0038D028(&tmp, &normal, aux);
    func_0038CE20(&tmp, &tmp, length * 0.01f);
    vec_add_ba(d + 0x660 + side * 16, d + 0x660 + side * 16, &tmp);
    if (!pass) {
        func_0038CE20(&delta, velocity, 1.0f - frac);
        vec_add_ab(&end, &pos, &delta);
        frac = func_L01_00446E38(&pos, &end, radius, 0x84, m);
        if (frac < 1.0f && frac >= 0.0f) {
            pass = 1;
            goto again;
        }
    }
final:
    *(vu0_q *)record = *(vu0_q *)&pos;
    switch (side) {
    case 0:
        func_0038D000(&tmp, &D_L09_001DE940, m + 0xC0);
        break;
    case 1:
        func_0038D000(&tmp, &D_L09_001DE930, m + 0xC0);
        break;
    case 2:
        func_0038D000(&tmp, &D_L09_001DE920, m + 0xC0);
        break;
    case 3:
        func_0038D000(&tmp, &D_L09_001DE910[0], m + 0xC0);
        break;
    }
    vec_add_ab(&nearpos, &tmp, m + 0x10);
    frac = func_L01_00446E38(&nearpos, record, 1.0f, 0x84, m);
    if (frac > 0.0f) {
        vec_sub_ba(&tmp, &nearpos, record);
        func_0038CE20(&tmp, &tmp, 1.0f - frac);
        vec_add_ba(result, result, &tmp);
    }
    return touched;
}
/* localdecomp:end func_L09_003C8740 */
