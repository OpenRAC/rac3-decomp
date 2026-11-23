#include "common.h"
#include "vu0.h"

typedef int Quad_3543C8 __attribute__((mode(TI)));
typedef struct Obj_3543C8 {
    u8 pad0[0x10];
    Quad_3543C8 pos;
    u8 pad20[4];
    u8 *def;
    u8 pad28[0xC];
    u16 flags;
    u8 pad36[0x32];
    u8 *vars;
    u8 pad6C[0x2A];
    u16 timer;
    s32 w98;
    u8 pad9C[0xC];
    u8 alpha;
    u8 padA9[0x13];
    u8 state;
    u8 padBD[0x33];
    Quad_3543C8 pos2;
} Obj_3543C8;
typedef struct Vars_3543C8 {
    u8 pad0[0x30];
    f32 hp;
    s16 maxhp;
    s16 hurt;
    u8 pad38[0x48];
    s32 w80;
    u8 pad84[0x2FE];
    u8 b382;
    u8 pad383[0x7D];
    Quad_3543C8 q400;
    Quad_3543C8 q410;
} Vars_3543C8;

/* declared by functions of L18_003514B8.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L18_00351548 */
typedef struct {
    f32 v[4];
} __attribute__((aligned(16))) V_00351548;

extern s32 func_L01_0041A4F0(void);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_0038D278(void *);
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L18_003514B8(u8 *);
extern s32 D_001D545C;
extern s32 D_001D545C_00351548;
__asm__(".extern D_001D545C_00351548, 16");
extern u8 D_0014275B[];
extern f32 D_L18_001DA8F8;
extern f32 D_L18_002F1F30[];
extern u128_t D_L18_001D9A60 __attribute__((section(".sdata")));
extern s32 D_L18_001D678C;
extern V_00351548 D_L18_001DFD50 __attribute__((section(".sdata")));

void func_L18_00351548(void *arg) {
    u8 *o = arg;
    u8 *v = *(u8 **)(o + 0x68);
    f32 scale;
    s32 level;
    s32 id;
    s32 i;
    V_00351548 d;

    scale = 1.0f;
    (*(u8 **)(o + 0x24))[0x46] = 13;
    *(s32 *)(v + 0x350) = 0;
    qzero(v + 0x290);
    *(s32 *)(v + 0x354) = 0;
    qzero(v + 0x2A0);
    qzero(v + 0x2B0);
    qzero(v + 0x3F0);
    if (func_L01_0041A4F0() != 0) {
        level = D_001D545C;
        scale = level == 7 && D_0014275B[0] ? D_L18_001DA8F8 : D_L18_002F1F30[level];
    }
    id = D_001D545C_00351548;
    if (id == 0x12) {
        s32 n = scale * 400.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else if (id == 0x14) {
        *(s16 *)(v + 0x34) = 400;
        *(f32 *)(v + 0x30) = 400.0f;
    } else if (id == 0x1A) {
        s32 n = scale * 300.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else if (id == 0x1D) {
        s32 n = scale * 100.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    } else {
        s32 n = scale * 150.0f;
        *(s16 *)(v + 0x34) = n;
        *(f32 *)(v + 0x30) = n;
    }
    v[0x3E] = 3;
    v[0x38] = 1;
    v[0x58] = 30;
    v[0x5A] = 32;
    *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 0.8f;
    *(f32 *)(v + 0x368) = *(f32 *)(o + 0x18);
    qzero(v + 0x2C0);
    *(f32 *)(v + 0x390) = 0.05235988f;
    *(s32 *)(v + 0x3AC) = -1;
    *(s32 *)(v + 0x3D4) = 8;
    *(s32 *)(v + 0x3D8) = 21;
    *(s32 *)(v + 0x3DC) = 5;
    *(s32 *)(v + 0x3E0) = 50;
    *(f32 *)(v + 0x388) = 0.0f;
    *(f32 *)(v + 0x38C) = 0.0f;
    *(f32 *)(v + 0x394) = 0.0f;
    *(f32 *)(v + 0x39C) = 0.0f;
    *(f32 *)(v + 0x398) = 0.0f;
    *(f32 *)(v + 0x3A0) = 0.0f;
    *(f32 *)(v + 0x360) = 0.0f;
    *(f32 *)(v + 0x364) = 0.0f;
    *(f32 *)(v + 0x3A4) = 0.0f;
    *(f32 *)(v + 0x3A8) = 0.0f;
    v[0x380] = 0;
    v[0x381] = 0;
    *(s32 *)(v + 0x3B8) = 0;
    *(s16 *)(v + 0x37E) = 0;
    *(s32 *)(v + 0x374) = 0;
    *(s32 *)(v + 0x378) = 0;
    *(s16 *)(v + 0x37C) = 0;
    *(s32 *)(v + 0x3E4) = 0;
    *(s32 *)(v + 0x3E8) = 0;
    for (i = 0; i < 2; i++) {
        if (v[0x91 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 4, v + 0x90 + i * 0x40);
        }
        if (v[0x111 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 2, v + 0x110 + i * 0x40);
        }
        if (v[0x191 + i * 0x40] == 0) {
            func_L01_0043A430(o, i + 9, v + 0x190 + i * 0x40);
        }
    }
    func_0038D278(v + 0x2D0);
    *(u128_t *)(v + 0x3C0) = D_L18_001D9A60;
    *(s32 *)(v + 0x3BC) = D_L18_001D678C == 0;
    if (*(s32 *)(v + 0x3BC) == 0) {
        vec_sub_ab(&d, o + 0x10, &D_L18_001DFD50);
        func_0038CF68(&d, &d, 1.0f);
        *(u128_t *)(v + 0x3C0) = *(u128_t *)&d;
        func_L18_003514B8(o);
    }
    if (*(f32 *)(v + 0x444) <= 0.0f) {
        *(f32 *)(v + 0x444) = 3.0f;
    }
    if (*(s32 *)(v + 0x80) > 0) {
        void *t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(v + 0x80) = -1;
        v[0x8E] = 1;
        v[0x8F] = 9;
        ((void (*)(void *))(*(void **)t))(o);
    } else {
        func_L01_004450F0(o, 0, 1);
    }
    *(u128_t *)(v + 0x420) = *(u128_t *)(o + 0x10);
    *(u128_t *)(v + 0x2D0) = *(u128_t *)(o + 0xC0);
    *(u128_t *)(v + 0x2E0) = *(u128_t *)(o + 0xD0);
    *(u128_t *)(v + 0x2F0) = *(u128_t *)(o + 0xE0);
}
/* localdecomp:end func_L18_00351548 */

/* localdecomp:start func_L18_00351908 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00351908;
typedef struct {
    V_00351908 r[3];
} M3_00351908;
typedef struct {
    u8 pad0[0x12];
    s16 count;
    u8 pad14[0xC];
    s32 *list;
    u8 pad24[0xC];
} Path_00351908;
typedef struct {
    u8 pad0[0x20];
    Path_00351908 paths[1];
} Paths_00351908;
typedef struct {
    u8 pad0[4];
    void (*begin)(void);
    void (*end)(void);
} Timer_00351908;

extern u8 *D_001A71A0[];
typedef struct {
    u8 pad0[0x24];
    u8 *cls;
    u8 pad28[0x70];
    s32 x98;
    u8 pad9C[0x64];
} Moby_00351908;
extern Moby_00351908 *D_L18_001E009C;
__asm__(".extern D_L18_001E009C, 16");
extern u8 *D_L18_001E0180;
__asm__(".extern D_L18_001E0180, 16");
extern Paths_00351908 *D_L18_001DFD4C;
__asm__(".extern D_L18_001DFD4C, 16");
extern V_00351908 D_L18_001EAAB0;
extern V_00351908 D_L18_001EAAC0;
typedef struct {
    u8 pad0[0x19E0];
    void *x19E0;
    u8 pad19E4[0xBE0];
    s32 x25C4;
} G_00351908;
extern G_00351908 D_001A4BE0_00351908;

extern Timer_00351908 *func_L01_0043B568(s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L18_003514B8(u8 *);
extern void func_L18_00353110(u8 *);
extern s32 func_00382380(void *, s32, s32);
extern s32 func_L01_00456500(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004464C8(void *, void *, void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C3DA0(void *, void *, s32, void *, f32);
extern f32 func_L01_00446E38(void *, void *, s32, f32, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L01_003FDCA0(void *, s32, f32);

s32 func_L18_00351908(void *arg) {
    u8 *a0 = arg;
    u8 *s = *(u8 **)(a0 + 0x68);
    V_00351908 target;
    V_00351908 t10;
    V_00351908 v;
    V_00351908 normal;
    V_00351908 delta;
    V_00351908 prev;
    V_00351908 t60;
    V_00351908 dir;
    V_00351908 t80;
    V_00351908 t90;
    s32 ret = 0;
    s32 again = 0;
    s32 tries = 0;
    s32 locked = 0;
    Timer_00351908 *timer;
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
    timer = func_L01_0043B568(0x1E6F, 0, 12);
    if (timer != 0) {
        timer->begin();
    }
    ids = (s32 *)(s + 0x308);
    func_L18_00353110(a0);
    for (k = 0; k < 18; k++) {
        if (ids[k] != -1) {
            Moby_00351908 *m = &D_L18_001E009C[ids[k]];
            m->x98 = *(s32 *)(m->cls + 0x10);
        }
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        if (*(s32 *)(s + 0x3EC) != -1 && func_00382380(a0 + 0x10, *(s32 *)(s + 0x3EC), 0) == 0) {
            vec_sub_ba(&v, D_L18_001E0180 + ((*(s32 *)(s + 0x3EC) << 7) + 0x30), a0 + 0x10);
            v.z = 0.0f;
            func_0038CF68(&v, &v, 0.0003f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v);
        } else if (*(s32 *)(s + 0x43C) != -1 && func_L01_00456500(a0 + 0x10, *(s32 *)(s + 0x43C)) == 0) {
            Path_00351908 *e = &D_L18_001DFD4C->paths[*(s32 *)(s + 0x43C)];
            s32 best = -1;
            s32 second = -1;
            f32 d1 = 999999.0f;
            f32 d2 = 999999.0f;
            for (i = 0; i < e->count; i++) {
                f32 dist = func_L01_0040E570(D_L18_001E0180 + (e->list[i] << 7) + 0x30, a0 + 0x10);
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
            func_L01_004464C8(&t90, D_L18_001E0180 + (best << 7) + 0x30, D_L18_001E0180 + (second << 7) + 0x30, a0 + 0x10);
            vec_sub_ba(&v, &t90, a0 + 0x10);
            v.z = 0.0f;
            func_0038CF68(&v, &v, 0.0003f);
            vec_add_ab(s + 0x3F0, s + 0x3F0, &v);
        } else {
            *(f32 *)(s + 0x3F0) = *(f32 *)(s + 0x3F0) - *(f32 *)(s + 0x3F0) * 0.09f;
            if (fabs_asm(*(f32 *)(s + 0x3F0)) < 0.01f) {
                *(f32 *)(s + 0x3F0) = 0.0f;
            }
            *(f32 *)(s + 0x3F4) = *(f32 *)(s + 0x3F4) - *(f32 *)(s + 0x3F4) * 0.09f;
            if (fabs_asm(*(f32 *)(s + 0x3F4)) < 0.01f) {
                *(f32 *)(s + 0x3F4) = 0.0f;
            }
            *(f32 *)(s + 0x3F8) = *(f32 *)(s + 0x3F8) - *(f32 *)(s + 0x3F8) * 0.09f;
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
            if (D_001A4BE0_00351908.x25C4 == 0x31 && D_001A4BE0_00351908.x19E0 == a0) {
                *(f32 *)(s + 0x298) += 0.024f;
            }
        }
    } else {
        vec_sub_ab(&v, a0 + 0x10, &D_L18_001DFD50);
        len = func_0038CEA8(&v);
        func_0038CE20(&dir, &v, 1.0f / len);
        if (len < *(f32 *)(s + 0x304)) {
            func_0038CE20(&t60, &dir, *(f32 *)(s + 0x304));
            vec_add_ab(a0 + 0x10, &D_L18_001DFD50, &t60);
        } else if (*(f32 *)(s + 0x300) < len) {
            func_0038CE20(&t60, &dir, *(f32 *)(s + 0x300));
            vec_add_ab(a0 + 0x10, &D_L18_001DFD50, &t60);
        }
        func_003C3DA0(&t60, a0 + 0x10, 0, a0, 3.0f);
        func_0038CE20(&v, &dir, 1.9f);
        vec_add_ab(&t60, &t60, &v);
        *(V_00351908 *)(s + 0x3C0) = dir;
        func_L18_003514B8(a0);
        *(M3_00351908 *)(a0 + 0xC0) = *(M3_00351908 *)(s + 0x2D0);
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        v = *(V_00351908 *)(s + 0x290);
    } else {
        func_0038D000(&v, s + 0x290, s + 0x2D0);
    }
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) += 0.5f;
    } else {
        func_0038CE20(&t80, &dir, 0.5f);
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
    frac = func_L01_00446E38(a0 + 0x10, &target, 0x84, 2.5f, a0);
    if (0.0f <= frac && frac < 1.0f) {
    collide:
        func_0038CF68(&normal, &D_L18_001EAAC0, 1.0f);
        func_0038CE20(&t90, &normal, 0.008f);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &t90);
        if (frac == 0.0f) {
            if (tries == 0 || (tries < 3 && 0.0f < func_0038CE68(&prev, &normal))) {
                tries++;
                again = 0;
                prev = normal;
                goto retry;
            }
        }
        d = func_0038CE68(&delta, &normal);
        func_0038CE20(&v, &normal, d * -1.01f);
        vec_add_ba(s + 0x290, s + 0x290, &v);
        func_0038CE20(&t10, &delta, frac);
        vec_add_ab(a0 + 0x10, a0 + 0x10, &t10);
        ret = 1;
        if (*(f32 *)(s + 0x298) < 0.0f) {
            *(f32 *)(s + 0x298) = 0.0f;
        }
        if (again == 0) {
            func_0038CE20(&delta, s + 0x290, 1.0f - frac);
            vec_add_ba(&t90, a0 + 0x10, &delta);
            frac = func_L01_00446E38(a0 + 0x10, &t90, 0x84, 2.5f, a0);
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
        if (func_L01_003FB640(a0 + 0x10, 4, a0, 2.5f)) {
            *(V_00351908 *)(a0 + 0x10) = D_L18_001EAAB0;
            hit = 1;
        }
        if (func_L01_003FDCA0(a0 + 0x10, 0, 2.5f)) {
            *(V_00351908 *)(a0 + 0x10) = D_L18_001EAAB0;
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
            Moby_00351908 *m = &D_L18_001E009C[ids[k]];
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
    *(V_00351908 *)(s + 0x420) = *(V_00351908 *)(a0 + 0x10);
    return ret;
}
/* localdecomp:end func_L18_00351908 */
