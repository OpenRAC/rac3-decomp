#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0054C7E8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0054C7E8;
typedef struct { u8 p0[0x2524]; void *f2524; } P_0054C7E8;
typedef struct {
    u8 p0[0x18]; f32 f18;
    u8 p1C[0x30 - 0x1C]; V4_0054C7E8 f30;
    V4_0054C7E8 f40;
    u8 p50[0x58 - 0x50]; P_0054C7E8 *p58;
    u8 p5C[0x64 - 0x5C]; u8 b64;
    u8 p65[3]; u8 b68;
    u8 p69[3]; u8 b6C; u8 b6D;
} V_0054C7E8;
typedef struct {
    u8 p0[0x10]; V4_0054C7E8 pos;
    u8 p20[0x68 - 0x20]; V_0054C7E8 *vars;
} M_0054C7E8;
typedef struct { u8 b0, b1, b2; } Msg_0054C7E8;
typedef struct {
    u8 p0[4]; s32 f4;
    u8 p8[0x170 - 0x8]; s32 f170;
    u8 p174[0x7D4 - 0x174]; u8 b7D4;
} S_1A5CD0_0054C7E8;
extern S_1A5CD0_0054C7E8 D_001A5CD0;
extern s32 D_L39_002405B0;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_0054C7E8(M_0054C7E8 *m, V4_0054C7E8 *p1, V4_0054C7E8 *p2, f32 dist) {
    V_0054C7E8 *v = m->vars;
    V4_0054C7E8 tmp;
    V4_0054C7E8 a;
    V4_0054C7E8 b;
    Msg_0054C7E8 msg;
    f32 d;
    s32 hit;

    if (v->b6D == 0 || v->b6C != 0) {
        return;
    }
    if (!(dist <= v->f18 * 2.9f)) {
        return;
    }
    func_0038CE20(&tmp, &v->f30, v->f18 * 2.0f);
    vec_add_ba(&a, &m->pos, &tmp);
    func_0038CE20(&tmp, p2, 2.0f);
    vec_add_ba(&b, p1, &tmp);
    vec_add_ab(&b, &b, &v->f40);
    if (!(func_0038CF00(&b, &a) <= v->f18)) {
        return;
    }
    if (func_003D3CB0(&a, &b, 0x12, v->p58->f2524, 0) != 0) {
        return;
    }
    d = func_0038CF00(p1, &a);
    if (func_003D3CB0(&a, p1, 0x12, v->p58->f2524, 0) != 0) {
        return;
    }
    hit = 0;
    if (d <= v->f18) {
        hit = 1;
    } else {
        func_0038CE20(&tmp, &v->f30, v->f18);
        vec_add_ab(&a, &m->pos, &tmp);
        if (func_0038CF00(p1, &a) <= v->f18) {
            hit = 1;
        }
    }
    if (hit) {
        msg.b0 = v->b64;
        msg.b2 = v->b68;
        msg.b1 = 2;
        if (D_001A5CD0.f170 == 0) {
            func_0014AD08(D_001A5CD0.b7D4 | 0xC0, D_001A5CD0.f4, -1, D_L39_002405B0, 3, &msg);
        }
    }
}
/* localdecomp:end func_L39_0054C7E8 */

/* localdecomp:start func_L39_0054CA00 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_0054CA00;

typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x46 - 0x14]; u8 f46; } K_0054CA00;
typedef struct {
    u8 pad0[0x10];
    Q_0054CA00 pos;
    u8 pad20[0x24 - 0x20];
    K_0054CA00 *f24;
    u8 pad28[0x34 - 0x28];
    u16 f34;
    u8 pad36[0x98 - 0x36];
    s32 f98;
} M_0054CA00;
typedef struct { u8 pad0[0x2544]; s32 f2544; s32 f2548; } W_0054CA00;
typedef struct {
    Q_0054CA00 vel;
    f32 f10;
    f32 f14;
    u8 pad18[0x20 - 0x18];
    Q_0054CA00 f20;
    Q_0054CA00 f30;
    u8 pad40[0x44 - 0x40];
    s32 f44;
    s32 f48;
    M_0054CA00 *f4C;
    W_0054CA00 *f50;
} V_0054CA00;
typedef struct {
    u8 pad0[0x10];
    Q_0054CA00 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    V_0054CA00 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
} O_0054CA00;
typedef struct { s32 a; s32 b; } F_0054CA00;
typedef struct {
    Q_0054CA00 start;
    Q_0054CA00 end;
    Q_0054CA00 vel;
    M_0054CA00 *hit;
    F_0054CA00 *filter;
    s32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    u8 pad50[0x58 - 0x50];
    s32 f58;
    u8 pad5C[0x60 - 0x5C];
} C_0054CA00;
typedef struct { Q_0054CA00 v0; Q_0054CA00 v1; Q_0054CA00 v2; } D_0054CA00;

extern f32 D_L39_0024B080 __attribute__((section(".sdata")));
extern f32 D_L39_0024B084 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B080, 4");
__asm__(".extern D_L39_0024B084, 4");
extern f32 D_L39_0024B018;
extern D_0054CA00 D_L39_0025F760;
extern W_0054CA00 *D_L39_0024CE20[] __attribute__((section(".sdata")));

extern void func_L39_005BC330(void *a0, void *a1, s32 a2);
extern void func_L19_003B1A70(s32, void *, s32);
extern void func_L39_005FF198(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L39_005FF270(void *, s32);
extern u8 *func_00382348(void *);
extern s32 func_L39_0061D7B0(void *a0);
extern void func_L39_005FFDF8(s32 a0);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_005FFE78(void);
extern s32 func_L39_005F33E0(s32 index, s32 a1, u8 *a2);
extern s32 func_L39_0051E9A8(void *, void *, s32, void *, void *);
extern s32 func_L39_00577818(void);
extern u8 *func_L39_0066E338(s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_004471A8(f32, void *);

void func_L39_0054CA00(O_0054CA00 *o) {
    V_0054CA00 *v = o->vars;
    Q_0054CA00 old[1];
    F_0054CA00 filter;
    u8 tmp[16] __attribute__((aligned(16)));
    C_0054CA00 coll __attribute__((aligned(16)));
    Q_0054CA00 pos[1];
    Q_0054CA00 dir[1];
    Q_0054CA00 off[1];
    vu0_q qa, qb;
    s32 restore;
    s32 r;
    M_0054CA00 *hit;
    u8 *pv;
    u8 *p;
    u8 *q;
    Q_0054CA00 *d;
    W_0054CA00 *w;
    s32 res;
    s32 id;
    Q_0054CA00 *opos;

    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        old[0] = o->pos;
        func_L39_005BC330(old, tmp, 1);
        opos = &o->pos;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v->vel));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(qa));
        func_L19_003B1A70(v->f44, v, 0);
        restore = 0;
        func_L39_005FF198(v->f50, opos, &v->f30);
        func_0038CE20(&v->f30, &v->f30, -(D_L39_0024B018 * 0.00040000002f));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v->vel));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v->f30));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v->vel) : "j"(qa));
        filter.a = 0;
        filter.b = 0x108A;
        coll.start = old[0];
        coll.end = o->pos;
        coll.vel = v->vel;
        coll.hit = (M_0054CA00 *)o;
        coll.filter = &filter;
        coll.f38 = 2;
        coll.f3C = 0.25f;
        coll.f40 = D_L39_0024B080;
        coll.f44 = D_L39_0024B084;
        coll.f48 = 0;
        coll.f4C = 0;
        coll.f58 = 0;
        if (v->f4C->f98 != 0) {
            v->f4C->f98 = 0;
            restore = 1;
        }
        r = func_L39_005FF270(&coll, v->f50->f2544);
        if (restore) {
            v->f4C->f98 = v->f4C->f24->f10;
        }
        if (coll.hit != 0 && coll.hit == v->f4C) {
            coll.start = old[0];
            coll.end = o->pos;
            coll.vel = v->vel;
            coll.filter = &filter;
            coll.f38 = 2;
            coll.f3C = 0.25f;
            coll.f40 = D_L39_0024B080;
            coll.f44 = D_L39_0024B084;
            coll.hit = 0;
            coll.f48 = 0;
            coll.f4C = 0;
            coll.f58 = 0;
        } else if (r == 2) {
            o->state = r;
        }
        o->pos = coll.end;
        v->vel = coll.vel;
        v->f20 = coll.start;
        if (coll.hit == 0 || coll.hit == v->f4C) {
            break;
        }
        if (coll.hit->f24->f46 != 5 && coll.hit->f24->f46 != 9 && !(coll.hit->f34 & 0x4000)) {
            break;
        }
        pv = func_00382348(coll.hit);
        p = (u8 *)func_L39_0061D7B0(coll.hit);
        q = 0;
        if (p != 0 && (p[3] & 0xF) == 0) {
            q = p;
        }
        if (q != 0) {
            func_L39_005FF198(q, &coll.hit->pos, dir);
            d = dir;
        } else {
            func_0038CF68(dir, &v->f30, -1.0f);
            d = dir;
        }
        pos[0] = o->pos;
        if (pv != 0) {
            func_0038CE20(off, d, *(f32 *)(pv + 0x10));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos[0]));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(off[0]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(pos[0]) : "j"(qa));
        }
        func_0038CE20(d, d, -3.0f);
        o->state = 2;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(dir[0]));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(pos[0]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(dir[0]) : "j"(qa));
        o->pos = D_L39_0025F760.v0;
        v->f20 = D_L39_0025F760.v2;
        func_0038CF68(&v->f20, &v->f20, 1.0f);
        id = v->f50->f2544;
        w = D_L39_0024CE20[id];
        hit = coll.hit;
        id = w != 0 ? w->f2548 : -1;
        func_L39_005FFDF8(id);
        res = func_003D3CB0(pos, d, 6, hit, 0);
        func_L39_005FFE78();
        if (res != 0) {
            o->pos = D_L39_0025F760.v0;
            v->f20 = D_L39_0025F760.v2;
            func_0038CF68(&v->f20, &v->f20, 1.0f);
        }
        break;
    case 2:
        func_L39_005F33E0(0, 0, (u8 *)o);
        res = func_L39_0051E9A8(&o->pos, &v->f20, v->f48, v->f50, &v->f30);
        if (res != 0 && func_L39_00577818() != 0) {
            u8 *t = func_L39_0066E338(v->f48);
            if (t != 0) {
                *(s32 *)(t + 0x28) = res;
            }
        }
        func_L01_004C8668(v->f44);
        func_003C2880(o);
        return;
    }
    o->fF0 = func_0038DAB8(o->fF0, v->f10);
    o->fF4 = func_0038DAB8(o->fF4, v->f14);
    func_L01_004471A8(0.2f, o);
    if (o->pos.x < 2.0f || 1021.0f < o->pos.x ||
        o->pos.y < 2.0f || 1021.0f < o->pos.y ||
        o->pos.z < 2.0f || 1021.0f < o->pos.z) {
        func_L01_004C8668(v->f44);
        func_003C2880(o);
    }
}
/* localdecomp:end func_L39_0054CA00 */
