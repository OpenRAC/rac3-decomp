#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0054D078 */
#include "vu0.h"

typedef struct M_0054D078 M_0054D078;
typedef struct { u8 pad0[0x46]; u8 f46; } T_0054D078;
typedef struct { u8 pad0[0x2544]; s32 f2544; } W_0054D078;
typedef struct {
    u128_t vel;
    f32 f10;
    f32 f14;
    u8 pad18[0x20 - 0x18];
    u128_t f20;
    s32 f30;
    s32 f34;
    s32 f38;
    M_0054D078 *f3C;
    W_0054D078 *f40;
} S_0054D078;
struct M_0054D078 {
    u8 pad0[0x10];
    u128_t pos;
    u8 state;
    u8 pad21[3];
    T_0054D078 *f24;
    u8 pad28[0x34 - 0x28];
    u16 f34;
    u8 pad36[0x68 - 0x36];
    S_0054D078 *f68;
    u8 pad6C[0xB8 - 0x6C];
    s32 fB8;
    u8 padBC[0xF0 - 0xBC];
    f32 fF0;
    f32 fF4;
};
typedef struct { s32 a; s32 b; s32 pad[2]; } F_0054D078;
typedef struct {
    u128_t q0;
    u128_t q1;
    u128_t q2;
    M_0054D078 *hit;
    F_0054D078 *filter;
    s32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    s32 pad50[2];
    s32 f58;
    s32 pad5C;
} C_0054D078;
typedef struct { u128_t q0; u128_t q1; u128_t q2; } D_0054D078;
typedef struct { u8 pad0[0x28]; M_0054D078 *f28; } P_0054D078;

extern f32 D_L39_0024B088;
__asm__(".extern D_L39_0024B088, 4");
extern f32 D_L39_0024B08C;
__asm__(".extern D_L39_0024B08C, 4");
extern D_0054D078 D_L39_0025F760;
extern void func_L39_005BC330(void *, void *, s32);
extern void func_L19_003B1A70(s32, void *, s32);
extern void func_L39_005FF060(void *, void *, void *, f32);
extern s32 func_L39_005FF270(C_0054D078 *, s32);
extern s32 func_00382348(void *);
extern void func_L39_005FF198(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern M_0054D078 *func_L39_0051FC18(void *, void *, s32, void *);
extern s32 func_L39_00577818(void);
extern P_0054D078 *func_L39_0066E338(s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004471A8(void *, f32);

void func_L39_0054D078(M_0054D078 *obj) {
    S_0054D078 *st = obj->f68;
    vu0_v4 start;
    F_0054D078 filter;
    vu0_v4 out;
    C_0054D078 c;
    vu0_v4 d;
    vu0_v4 a;
    vu0_v4 b;
    s32 r;
    void *t;
    M_0054D078 *m;

    switch (obj->state) {
    case 0:
        obj->state = 1;
    case 1:
        *(u128_t *)&start = obj->pos;
        func_L39_005BC330(&start, &out, 1);
        vec_add_ba(&obj->pos, &obj->pos, st);
        func_L19_003B1A70(st->f34, st, 0);
        func_L39_005FF060(st->f40, &obj->pos, st, 0.008f);
        filter.b = 0x107F;
        c.q0 = *(u128_t *)&start;
        c.q1 = obj->pos;
        filter.a = 0;
        c.q2 = st->vel;
        c.f40 = D_L39_0024B088;
        c.f44 = D_L39_0024B08C;
        c.hit = obj;
        c.filter = &filter;
        c.f38 = 2;
        c.f3C = 0.25f;
        c.f48 = 0;
        c.f4C = 0;
        c.f58 = 0;
        r = func_L39_005FF270(&c, st->f40->f2544);
        if (c.hit != 0 && c.hit == st->f3C) {
            c.q0 = *(u128_t *)&start;
            c.q1 = obj->pos;
            c.q2 = st->vel;
            c.filter = &filter;
            c.f38 = 2;
            c.f3C = 0.25f;
            c.f40 = D_L39_0024B088;
            c.f44 = D_L39_0024B08C;
            c.hit = 0;
            c.f48 = 0;
            c.f4C = 0;
            c.f58 = 0;
        } else if (r == 2) {
            obj->state = r;
        }
        obj->pos = c.q1;
        st->vel = c.q2;
        st->f20 = c.q0;
        if (c.hit != 0 && c.hit != st->f3C) {
            if (c.hit->f24->f46 == 5 || c.hit->f24->f46 == 9 || (c.hit->f34 & 0x4000)) {
                t = (void *)func_00382348(c.hit);
                func_L39_005FF198(st->f40, &c.hit->pos, &a);
                *(u128_t *)&d = obj->pos;
                if (t != 0) {
                    func_0038CE20(&b, &a, *(f32 *)((u8 *)t + 0x10));
                    vec_add_ab(&d, &d, &b);
                }
                func_0038CE20(&a, &a, -3.0f);
                obj->state = 2;
                vec_add_ab(&a, &a, &d);
                obj->pos = D_L39_0025F760.q0;
                st->f20 = D_L39_0025F760.q2;
                func_0038CF68(&st->f20, &st->f20, 1.0f);
                if (func_003D3CB0(&d, &a, 6, c.hit, 0) != 0) {
                    obj->pos = D_L39_0025F760.q0;
                    st->f20 = D_L39_0025F760.q2;
                    func_0038CF68(&st->f20, &st->f20, 1.0f);
                }
            }
        }
        break;
    case 2:
        func_L39_005F33E0(0, 0, obj);
        m = func_L39_0051FC18(&obj->pos, &st->f20, st->f38, st->f40);
        if (func_L39_00577818() != 0 && m != 0) {
            P_0054D078 *p = func_L39_0066E338(st->f38);
            if (p != 0) {
                p->f28 = m;
            }
        }
        m->fB8 = st->f30;
        func_L01_004C8668(st->f34);
        func_003C2880(obj);
        return;
    }
    obj->fF0 = func_0038DAB8(obj->fF0, st->f10);
    obj->fF4 = func_0038DAB8(obj->fF4, st->f14);
    func_L01_004471A8(obj, 0.2f);
    if (((f32 *)&obj->pos)[0] < 2.0f || 1021.0f < ((f32 *)&obj->pos)[0] ||
        ((f32 *)&obj->pos)[1] < 2.0f || 1021.0f < ((f32 *)&obj->pos)[1] ||
        ((f32 *)&obj->pos)[2] < 2.0f || 1021.0f < ((f32 *)&obj->pos)[2]) {
        func_L01_004C8668(st->f34);
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L39_0054D078 */
