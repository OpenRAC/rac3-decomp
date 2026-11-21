#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L18_00351908 (src/levels/shared/L18_00351548.c): 60 Hz step constants (0.00025f, 0.075f, 1/60.0f) */
/* localdecomp:start func_L18_00350D08 */

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00350D08;
typedef struct {
    V_00350D08 r[3];
} M3_00350D08;
typedef struct {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0xC];
    s32 *list;
    u8 pad24[0xC];
} Path_00350D08;
typedef struct {
    u8 pad0[0x20];
    Path_00350D08 paths[1];
} Paths_00350D08;
typedef struct {
    u8 pad0[4];
    void (*begin)(void);
    void (*end)(void);
} Timer_00350D08;

extern u8 *D_001A71A0[];
extern V_00350D08 D_L18_001DFDD0 __attribute__((section(".sdata")));
typedef struct {
    u8 pad0[0x24];
    u8 *cls;
    u8 pad28[0x70];
    s32 x98;
    u8 pad9C[0x64];
} Moby_00350D08;
extern Moby_00350D08 *D_L18_001E011C;
__asm__(".extern D_L18_001E011C, 16");
extern u8 *D_L18_001E0200;
__asm__(".extern D_L18_001E0200, 16");
extern Paths_00350D08 *D_L18_001DFDCC;
__asm__(".extern D_L18_001DFDCC, 16");
extern V_00350D08 D_L18_001EAB30;
extern V_00350D08 D_L18_001EAB40;
typedef struct {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0xBE0];
    s32 x25C4;
} G_00350D08;
extern G_00350D08 D_001A4BE0_00350D08;

extern Timer_00350D08 *func_L01_00438488(s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L18_003508B8(u8 *);
extern void func_L18_00352508(u8 *);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_L01_00453210(void *, s32);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L01_00443390(void *, void *, void *, void *);
extern f32 func_00388770(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003BE860(void *, void *, s32, void *, f32);
extern f32 func_L01_00443D00(void *, void *, s32, f32, void *);
extern f32 func_00388730(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_003F9498(void *, s32, u8 *, f32);
extern s32 func_L01_003FBAF8(void *, s32, f32);

s32 func_L18_00350D08(void *arg) {
    u8 *a0 = arg;
    u8 *s = *(u8 **)(a0 + 0x68);
    V_00350D08 target;
    V_00350D08 t10;
    V_00350D08 v;
    V_00350D08 normal;
    V_00350D08 delta;
    V_00350D08 prev;
    V_00350D08 t60;
    V_00350D08 dir;
    V_00350D08 t80;
    V_00350D08 t90;
    s32 ret = 0;
    s32 again = 0;
    s32 tries = 0;
    s32 locked = 0;
    Timer_00350D08 *timer;
    vu0_q start;
    s32 *ids;
    s32 i = 0;
    s32 k = 0;
    f32 len = 0.0f;
    f32 frac = 0.0f;
    f32 d = 0.0f;
    s32 j = 0;

    if (a0[0x20] != 5) {
        u8 *p = D_001A71A0[0];
        if (*(s32 *)(p + 0x9C) != 0 || *(s32 *)(p + 0x98) != 0) {
            locked = 1;
            *(s32 *)(p + 0x9C) = -1;
        }
    }
    timer = func_L01_00438488(0x1E6F, 0, 12);
    if (timer != 0) {
        timer->begin();
    }
    ids = (s32 *)(s + 0x308);
    func_L18_00352508(a0);
    for (k = 0; k < 18; k++) {
        if (ids[k] != -1) {
            Moby_00350D08 *m = &D_L18_001E011C[ids[k]];
            m->x98 = *(s32 *)(m->cls + 0x10);
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        if (*(s32 *)(s + 0x3EC) != -1 && func_0037E0F0(a0 + 0x10, *(s32 *)(s + 0x3EC), 0) == 0) {
            vec_sub_ba(&v, D_L18_001E0200 + ((*(s32 *)(s + 0x3EC) << 7) + 0x30), a0 + 0x10);
            v.z = 0.0f;
            func_00388830(&v, &v, 0.00025f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v);
        } else if (*(s32 *)(s + 0x43C) != -1 && func_L01_00453210(a0 + 0x10, *(s32 *)(s + 0x43C)) == 0) {
            Path_00350D08 *e = &D_L18_001DFDCC->paths[*(s32 *)(s + 0x43C)];
            s32 best = -1;
            s32 second = -1;
            f32 d1 = 999999.0f;
            f32 d2 = 999999.0f;
            for (i = 0; i < e->count; i++) {
                f32 dist = func_L01_0040C040(D_L18_001E0200 + (e->list[i] << 7) + 0x30, a0 + 0x10);
                if (dist < d1) {
                    second = best;
                    d2 = d1;
                    d1 = dist;
                    best = i;
                } else if (dist < d2) {
                    d2 = dist;
                    second = i;
                }
            }
            func_L01_00443390(&t90, D_L18_001E0200 + (best << 7) + 0x30, D_L18_001E0200 + (second << 7) + 0x30, a0 + 0x10);
            vec_sub_ba(&v, &t90, a0 + 0x10);
            v.z = 0.0f;
            func_00388830(&v, &v, 0.00025f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v);
        } else {
            *(f32 *)(s + 0x3F0) = *(f32 *)(s + 0x3F0) - *(f32 *)(s + 0x3F0) * 0.075f;
            if (fabs_asm(*(f32 *)(s + 0x3F0)) < 0.01f) {
                *(f32 *)(s + 0x3F0) = 0.0f;
            }
            *(f32 *)(s + 0x3F4) = *(f32 *)(s + 0x3F4) - *(f32 *)(s + 0x3F4) * 0.075f;
            if (fabs_asm(*(f32 *)(s + 0x3F4)) < 0.01f) {
                *(f32 *)(s + 0x3F4) = 0.0f;
            }
            *(f32 *)(s + 0x3F8) = *(f32 *)(s + 0x3F8) - *(f32 *)(s + 0x3F8) * 0.075f;
            if (fabs_asm(*(f32 *)(s + 0x3F8)) < 0.01f) {
                *(f32 *)(s + 0x3F8) = 0.0f;
            }
        }
        vec_add_ab(s + 0x290, s + 0x290, s + 0x3F0);
        if (*(f32 *)(a0 + 0x18) > *(f32 *)(s + 0x300)) {
            *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x300);
            if (0.0f < *(f32 *)(s + 0x298)) {
                *(f32 *)(s + 0x298) = 0.0f;
            }
        } else if (*(f32 *)(a0 + 0x18) < *(f32 *)(s + 0x304)) {
            if (D_001A4BE0_00350D08.x25C4 == 0x31 && D_001A4BE0_00350D08.x19E0 == a0) {
                *(f32 *)(s + 0x298) += (1.0f / 60.0f);
            }
        }
    } else {
        vec_sub_ab(&v, a0 + 0x10, &D_L18_001DFDD0);
        len = func_00388770(&v);
        func_003886E8(&dir, &v, 1.0f / len);
        if (len < *(f32 *)(s + 0x304)) {
            func_003886E8(&t60, &dir, *(f32 *)(s + 0x304));
            vec_add_ab(a0 + 0x10, &D_L18_001DFDD0, &t60);
        } else if (*(f32 *)(s + 0x300) < len) {
            func_003886E8(&t60, &dir, *(f32 *)(s + 0x300));
            vec_add_ab(a0 + 0x10, &D_L18_001DFDD0, &t60);
        }
        func_003BE860(&t60, a0 + 0x10, 0, a0, 3.0f);
        func_003886E8(&v, &dir, 1.9f);
        vec_add_ab(&t60, &t60, &v);
        *(V_00350D08 *)(s + 0x3C0) = dir;
        func_L18_003508B8(a0);
        *(M3_00350D08 *)(a0 + 0xC0) = *(M3_00350D08 *)(s + 0x2D0);
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        v = *(V_00350D08 *)(s + 0x290);
    } else {
        func_003888C8(&v, s + 0x290, s + 0x2D0);
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) += 0.5f;
    } else {
        func_003886E8(&t80, &dir, 0.5f);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &t80);
    }
    {
        vu0_q qv, qp, qt, qa, qr;
        __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(v));
        __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qt) : "j"(qp), "j"(qv));
        __asm__("lqc2 %0, %1" : "=j"(start) : "m"(*(vu0_v4 *)(a0 + 0x10)));
        __asm__("sqc2 %1, %0" : "=m"(target) : "j"(qt));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(target));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(start));
        __asm__("sqc2 %1, %0" : "=m"(delta) : "j"(qr));
    }
retry:
    frac = func_L01_00443D00(a0 + 0x10, &target, 0x84, 2.5f, a0);
    if (0.0f <= frac && frac < 1.0f) {
    collide:
        func_00388830(&normal, &D_L18_001EAB40, 1.0f);
        func_003886E8(&t90, &normal, 0.008f);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &t90);
        if (frac == 0.0f) {
            if (tries == 0 || (tries < 3 && 0.0f < func_00388730(&prev, &normal))) {
                tries++;
                again = 0;
                prev = normal;
                goto retry;
            }
        }
        d = func_00388730(&delta, &normal);
        func_003886E8(&v, &normal, d * -1.01f);
        vec_add_ba(s + 0x290, s + 0x290, &v);
        func_003886E8(&t10, &delta, frac);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &t10);
        ret = 1;
        if (*(f32 *)(s + 0x298) < 0.0f) {
            *(f32 *)(s + 0x298) = 0.0f;
        }
        if (again == 0) {
            func_003886E8(&delta, s + 0x290, 1.0f - frac);
            vec_add_ba(&t90, a0 + 0x10, &delta);
            frac = func_L01_00443D00(a0 + 0x10, &t90, 0x84, 2.5f, a0);
            if (frac < 1.0f) {
                if (0.0f <= frac) {
                    again = 1;
                    goto collide;
                }
            } else {
                vec_add_ab(a0 + 0x10, a0 + 0x10, &delta);
            }
        }
    } else {
        vec_add_ab(a0 + 0x10, a0 + 0x10, &delta);
    }
    for (j = 0; j < 4; j++) {
        s32 hit = 0;
        if (func_L01_003F9498(a0 + 0x10, 4, a0, 2.5f)) {
            *(V_00350D08 *)(a0 + 0x10) = D_L18_001EAB30;
            hit = 1;
        }
        if (func_L01_003FBAF8(a0 + 0x10, 0, 2.5f)) {
            *(V_00350D08 *)(a0 + 0x10) = D_L18_001EAB30;
            hit = 1;
        }
        if (!hit) {
            break;
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) -= 0.5f;
    } else {
        vec_sub_ab(a0 + 0x10, a0 + 0x10, &t80);
    }
    if (*(f32 *)(a0 + 0x10) < 10.0f) {
        *(f32 *)(a0 + 0x10) = 10.0f;
    }
    if (1013.0f < *(f32 *)(a0 + 0x10)) {
        *(f32 *)(a0 + 0x10) = 1013.0f;
    }
    if (*(f32 *)(a0 + 0x14) < 10.0f) {
        *(f32 *)(a0 + 0x14) = 10.0f;
    }
    if (1013.0f < *(f32 *)(a0 + 0x14)) {
        *(f32 *)(a0 + 0x14) = 1013.0f;
    }
    if (*(f32 *)(a0 + 0x18) < 10.0f) {
        *(f32 *)(a0 + 0x18) = 10.0f;
    }
    if (1013.0f < *(f32 *)(a0 + 0x18)) {
        *(f32 *)(a0 + 0x18) = 1013.0f;
    }
    for (k = 0; k < 18; k++) {
        if (ids[k] != -1) {
            Moby_00350D08 *m = &D_L18_001E011C[ids[k]];
            m->x98 = 0;
        }
    }
    if (locked != 0 && a0[0x20] != 5) {
        *(s32 *)(D_001A71A0[0] + 0x9C) = 0;
    }
    if (timer != 0) {
        timer->end();
    }
    *(f32 *)(s + 0x368) = *(f32 *)(a0 + 0x18);
    *(V_00350D08 *)(s + 0x420) = *(V_00350D08 *)(a0 + 0x10);
    return ret;
}
/* localdecomp:end func_L18_00350D08 */
