#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L09_003C8740 (src/levels/shared/L09_003C5E78.c): 1/60.0f for 0.02f */
/* localdecomp:start func_L09_003C6D40 */

extern vu0_v4 D_L09_001DE950[] __attribute__((section(".sdata")));
__asm__(".extern D_L09_001DE950, 4");
extern vu0_v4 D_L09_001DE960[] __attribute__((section(".sdata")));
extern vu0_v4 D_L09_001DE970[] __attribute__((section(".sdata")));
extern vu0_v4 D_L09_001DE980[] __attribute__((section(".sdata")));
extern f32 D_L09_001DAA30;
__asm__(".extern D_L09_001DAA30, 4");
extern s32 D_001D545C;
extern u8 D_0014275B[];
extern void *D_001A71A0[];
extern u8 D_L09_001E9940[];
extern vu0_v4 D_L09_001E9970;
extern f32 D_L09_002F1DD0[];
extern u8 D_L09_001D66B0[8];

extern void func_003888C8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_003888F0(void *, void *, void *);
extern f32 func_L01_00443D00(void *, void *, f32, s32, void *);
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern s32 func_003BF5E0(void *);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern s32 func_L01_00417EA0(void);
extern f32 *func_0037E0B8(void *);
extern void func_L01_00443628(void *, void *, s32, f32, void *);
extern void func_L01_00443840(void *, void *);

s32 func_L09_003C6D40(u8 *m, vu0_v4 *result, vu0_v4 *velocity, vu0_v4 *hit, s32 *unused, s32 side, vu0_v4 *origin,
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

    func_003888C8(&tmp, &D_L09_001DE950[side], m + 0xC0);
    vec_add_ba(&pos, &tmp, m + 0x10);
    *(vu0_q *)origin = *(vu0_q *)&pos;
    vec_add_ab(&tmp, &pos, velocity);
    *unused = 0;
    *(vu0_q *)&delta = *(vu0_q *)velocity;
    damaged = 0;
    vec_add_ab(&end, &pos, &delta);
    frac = func_L01_00443D00(&pos, &end, 1.0f, 0x84, m);
    if (frac <= 0.0f) {
        if (func_L01_003F9498(&pos, 4, m, 1.0f)) {
            vec_sub_ab(&tmp, &D_L09_001E9970, &pos);
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
    *(vu0_q *)hit = *(vu0_q *)(D_L09_001E9940 + 0x20);
    d[0x714] = touched;
    object = *(u8 **)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x18);
    if (object) {
        if (func_003BF5E0(object)) {
            func_L01_00443938(*(void **)(D_L09_001E9940 + 0x18), m, 0x10000, D_L09_001E9940 + 0x20, D_L09_001D66B0, 5.0f);
            damaged = 1;
        } else if (!pass) {
            object = *(u8 **)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x18);
            if (*(s16 *)(object + 0xAA) == 0x1BAE || *(s16 *)(object + 0xAA) == 0x1E58) {
                damage = speed / *(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 40.0f + 60.0f;
                if (func_L01_00417EA0()) {
                    if (D_001D545C == 7 && D_0014275B[0] != 0) {
                        damage *= D_L09_001DAA30;
                    } else {
                        damage *= D_L09_002F1DD0[D_001D545C];
                    }
                }
                func_L01_00443938(*(void **)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x18), m, 1, D_L09_001E9940 + 0x20, velocity, damage);
                damaged = 1;
            } else if (*(u8 **)(object + 0x24) && (*(u8 **)(object + 0x24))[0x46] == 5) {
                hp = func_0037E0B8(object);
                if (hp && *hp > 0.0f) {
                    damage = 3.0f;
                    if (D_001D545C == 9) {
                        damage = speed / (*(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 0.016666668f) * 17.0f + damage;
                    } else {
                        damage = speed / (*(f32 *)(*(u8 **)(d + 0x720) + 0xC) * 0.016666668f) * 80.0f + 20.0f;
                    }
                    if (func_L01_00417EA0()) {
                        if (D_001D545C == 7 && D_0014275B[0] != 0) {
                            damage *= D_L09_001DAA30;
                        } else {
                            damage *= D_L09_002F1DD0[D_001D545C];
                        }
                    }
                    *(vu0_q *)&tmp = *(vu0_q *)velocity;
                    tmp.z = 0.0f;
                    func_003886E8(&tmp, &tmp, 5.0f);
                    vec_sub_ba(&nearpos, *(u8 **)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x18) + 0x10, m + 0x10);
                    func_00388830(&nearpos, &nearpos, 1.0f);
                    if (func_00388730(m + 0xD0, &nearpos) > 0.0f) {
                        func_003886E8(&nearpos, m + 0xD0, 0.5f);
                    } else {
                        func_003886E8(&nearpos, m + 0xD0, -0.5f);
                    }
                    vec_add_ab(&tmp, &tmp, &nearpos);
                    tmp.w = 5627.9248f;
                    func_L01_00443628(record, D_001A71A0[0], 0x10000, damage, &tmp);
                    damaged = 1;
                    record[0x18] = 10;
                    record[0x19] = 2;
                    *(u16 *)(record + 0x1A) = *(u16 *)(m + 0xAA);
                    func_L01_00443840(*(void **)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x18), record);
                    *hp -= damage;
                    if (*hp < 0.0f) {
                        *hp = 0.0f;
                    }
                }
            }
        }
        *(f32 *)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x48) = 0.0f;
    }
    if (*(f32 *)(({ u8 *c_ = D_L09_001E9940; c_; }) + 0x48) > 0.0f && D_001D545C != 24) {
        *(f32 *)(D_L09_001E9940 + 0x48) = 0.0f;
    }
    func_00388830(&normal, D_L09_001E9940 + 0x40, 1.0f);
    dotx = func_00388730(&normal, m + 0xC0);
    doty = func_00388730(&normal, m + 0xD0);
    dotz = func_00388730(&normal, m + 0xE0);
    if (side == 0) {
        if (dotx < 0.0f && doty > 0.0f && *(f32 *)(m + 0xE8) < 0.707f) {
            func_003886E8(&normal, m + 0xC0, -1.0f);
        } else if (dotx > 0.0f && doty < 0.0f) {
            func_003886E8(&normal, m + 0xD0, -1.0f);
        } else if (dotz > 0.5f && doty > 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 2) {
        if (dotx > 0.0f && doty > 0.0f) {
            func_003886E8(&normal, m + 0xC0, 1.0f);
        } else if (dotx < 0.0f && doty < 0.0f) {
            func_003886E8(&normal, m + 0xD0, -1.0f);
        } else if (dotz > 0.5f && doty > 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 1) {
        if (dotx < 0.0f && doty < 0.0f && *(f32 *)(m + 0xE8) < 0.707f) {
            func_003886E8(&normal, m + 0xC0, -1.0f);
        } else if (dotx > 0.0f && doty > 0.0f) {
            func_003886E8(&normal, m + 0xD0, 1.0f);
        } else if (dotz > 0.5f && doty < 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    } else if (side == 3) {
        if (dotx > 0.0f && doty < 0.0f) {
            func_003886E8(&normal, m + 0xC0, 1.0f);
        } else if (dotx < 0.0f && doty > 0.0f) {
            func_003886E8(&normal, m + 0xD0, 1.0f);
        } else if (dotz > 0.5f && doty < 0.0f) {
            *(vu0_q *)&normal = *(vu0_q *)(m + 0xE0);
        }
    }
    damage = func_00388730(&delta, &normal) * -1.01f;
    func_003886E8(&end, &delta, frac);
    vec_add_ba(&pos, &pos, &end);
    func_003886E8(&tmp, &normal, damage * (1.0f - frac));
    vec_add_ba(result, result, &tmp);
    func_003886E8(&tmp, &normal, damage);
    if (!damaged) {
        vec_add_ab(velocity, velocity, &tmp);
    }
    if (mode == 12 && velocity->z > 0.0f) {
        velocity->z = 0.0f;
    }
    length = func_00388770(velocity);
    if (speed < length) {
        func_003886E8(velocity, velocity, speed / length);
        length = speed;
    } else if (length < speed) {
        speed = length;
    }
    if (*(f32 *)(aux + 0x138) > 0.0f) {
        *(f32 *)(aux + 0x138) = length;
    } else if (length < speed) {
        *(f32 *)(aux + 0x138) = -length;
    }
    func_003888F0(&tmp, &normal, aux);
    func_003886E8(&tmp, &tmp, length * 0.01f);
    vec_add_ba(d + 0x660 + side * 16, d + 0x660 + side * 16, &tmp);
    if (!pass) {
        func_003886E8(&delta, velocity, 1.0f - frac);
        vec_add_ab(&end, &pos, &delta);
        frac = func_L01_00443D00(&pos, &end, radius, 0x84, m);
        if (frac < 1.0f && frac >= 0.0f) {
            pass = 1;
            goto again;
        }
    }
final:
    *(vu0_q *)record = *(vu0_q *)&pos;
    switch (side) {
    case 0:
        func_003888C8(&tmp, D_L09_001DE980, m + 0xC0);
        break;
    case 1:
        func_003888C8(&tmp, D_L09_001DE970, m + 0xC0);
        break;
    case 2:
        func_003888C8(&tmp, D_L09_001DE960, m + 0xC0);
        break;
    case 3:
        func_003888C8(&tmp, &D_L09_001DE950[0], m + 0xC0);
        break;
    }
    vec_add_ab(&nearpos, &tmp, m + 0x10);
    frac = func_L01_00443D00(&nearpos, record, 1.0f, 0x84, m);
    if (frac > 0.0f) {
        vec_sub_ba(&tmp, &nearpos, record);
        func_003886E8(&tmp, &tmp, 1.0f - frac);
        vec_add_ba(result, result, &tmp);
    }
    return touched;
}
/* localdecomp:end func_L09_003C6D40 */
