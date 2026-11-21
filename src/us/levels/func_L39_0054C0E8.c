#include "common.h"

/* NTSC-U counterpart of func_L39_0054CA00 (src/levels/shared/L39_0054C7E8.c): the frame-time scale 0.0004f becomes 1/3600 (0.00027777778f) */
/* localdecomp:start func_L39_0054C0E8 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Q_0054C0E8;

typedef struct { u8 pad0[0x10]; s32 f10; u8 pad14[0x46 - 0x14]; u8 f46; } K_0054C0E8;
typedef struct {
    u8 pad0[0x10];
    Q_0054C0E8 pos;
    u8 pad20[0x24 - 0x20];
    K_0054C0E8 *f24;
    u8 pad28[0x34 - 0x28];
    u16 f34;
    u8 pad36[0x98 - 0x36];
    s32 f98;
} M_0054C0E8;
typedef struct { u8 pad0[0x2544]; s32 f2544; s32 f2548; } W_0054C0E8;
typedef struct {
    Q_0054C0E8 vel;
    f32 f10;
    f32 f14;
    u8 pad18[0x20 - 0x18];
    Q_0054C0E8 f20;
    Q_0054C0E8 f30;
    u8 pad40[0x44 - 0x40];
    s32 f44;
    s32 f48;
    M_0054C0E8 *f4C;
    W_0054C0E8 *f50;
} V_0054C0E8;
typedef struct {
    u8 pad0[0x10];
    Q_0054C0E8 pos;
    u8 state;
    u8 pad21[0x68 - 0x21];
    V_0054C0E8 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    f32 fF4;
} O_0054C0E8;
typedef struct { s32 a; s32 b; } F_0054C0E8;
typedef struct {
    Q_0054C0E8 start;
    Q_0054C0E8 end;
    Q_0054C0E8 vel;
    M_0054C0E8 *hit;
    F_0054C0E8 *filter;
    s32 f38;
    f32 f3C;
    f32 f40;
    f32 f44;
    s32 f48;
    s32 f4C;
    u8 pad50[0x58 - 0x50];
    s32 f58;
    u8 pad5C[0x60 - 0x5C];
} C_0054C0E8;
typedef struct { Q_0054C0E8 v0; Q_0054C0E8 v1; Q_0054C0E8 v2; } D_0054C0E8;

extern f32 D_L39_0024B190 __attribute__((section(".sdata")));
extern f32 D_L39_0024B194 __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B190, 4");
__asm__(".extern D_L39_0024B194, 4");
extern f32 D_L39_0024B128;
extern D_0054C0E8 D_L39_0025F860;
extern W_0054C0E8 *D_L39_0024CF20[] __attribute__((section(".sdata")));

extern void func_L39_005BA378(void *a0, void *a1, s32 a2);
extern void func_L19_003AFE00(s32, void *, s32);
extern void func_L39_005FC9F8(void *, void *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_L39_005FCAD0(void *, s32);
extern u8 *func_0037E0B8(void *);
extern s32 func_L39_0061B038(void *a0);
extern void func_L39_005FD658(s32 a0);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L39_005FD6D8(void);
extern s32 func_L39_005F0CE0(s32 index, s32 a1, u8 *a2);
extern s32 func_L39_0051E580(void *, void *, s32, void *, void *);
extern s32 func_L39_00576AD8(void);
extern u8 *func_L39_0066BA18(s32);
extern void func_L01_004C4AB8(s32);
extern void func_003BD360(void *);
extern f32 func_00389380(f32, f32);
extern void func_L01_00444070(f32, void *);

void func_L39_0054C0E8(O_0054C0E8 *o) {
    V_0054C0E8 *v = o->vars;
    Q_0054C0E8 old[1];
    F_0054C0E8 filter;
    u8 tmp[16] __attribute__((aligned(16)));
    C_0054C0E8 coll __attribute__((aligned(16)));
    Q_0054C0E8 pos[1];
    Q_0054C0E8 dir[1];
    Q_0054C0E8 off[1];
    vu0_q qa, qb;
    s32 restore;
    s32 r;
    M_0054C0E8 *hit;
    u8 *pv;
    u8 *p;
    u8 *q;
    Q_0054C0E8 *d;
    W_0054C0E8 *w;
    s32 res;
    s32 id;
    Q_0054C0E8 *opos;

    switch (o->state) {
    case 0:
        o->state = 1;
    case 1:
        old[0] = o->pos;
        func_L39_005BA378(old, tmp, 1);
        opos = &o->pos;
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v->vel));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(qa));
        func_L19_003AFE00(v->f44, v, 0);
        restore = 0;
        func_L39_005FC9F8(v->f50, opos, &v->f30);
        func_003886E8(&v->f30, &v->f30, -(D_L39_0024B128 * 0.00027777778f));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(v->vel));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(v->f30));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(v->vel) : "j"(qa));
        filter.a = 0;
        filter.b = 0x108A;
        coll.start = old[0];
        coll.end = o->pos;
        coll.vel = v->vel;
        coll.hit = (M_0054C0E8 *)o;
        coll.filter = &filter;
        coll.f38 = 2;
        coll.f3C = 0.25f;
        coll.f40 = D_L39_0024B190;
        coll.f44 = D_L39_0024B194;
        coll.f48 = 0;
        coll.f4C = 0;
        coll.f58 = 0;
        if (v->f4C->f98 != 0) {
            v->f4C->f98 = 0;
            restore = 1;
        }
        r = func_L39_005FCAD0(&coll, v->f50->f2544);
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
            coll.f40 = D_L39_0024B190;
            coll.f44 = D_L39_0024B194;
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
        pv = func_0037E0B8(coll.hit);
        p = (u8 *)func_L39_0061B038(coll.hit);
        q = 0;
        if (p != 0 && (p[3] & 0xF) == 0) {
            q = p;
        }
        if (q != 0) {
            func_L39_005FC9F8(q, &coll.hit->pos, dir);
            d = dir;
        } else {
            func_00388830(dir, &v->f30, -1.0f);
            d = dir;
        }
        pos[0] = o->pos;
        if (pv != 0) {
            func_003886E8(off, d, *(f32 *)(pv + 0x10));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos[0]));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(off[0]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(pos[0]) : "j"(qa));
        }
        func_003886E8(d, d, -3.0f);
        o->state = 2;
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(dir[0]));
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(pos[0]));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(dir[0]) : "j"(qa));
        o->pos = D_L39_0025F860.v0;
        v->f20 = D_L39_0025F860.v2;
        func_00388830(&v->f20, &v->f20, 1.0f);
        id = v->f50->f2544;
        w = D_L39_0024CF20[id];
        hit = coll.hit;
        id = w != 0 ? w->f2548 : -1;
        func_L39_005FD658(id);
        res = func_003CE740(pos, d, 6, hit, 0);
        func_L39_005FD6D8();
        if (res != 0) {
            o->pos = D_L39_0025F860.v0;
            v->f20 = D_L39_0025F860.v2;
            func_00388830(&v->f20, &v->f20, 1.0f);
        }
        break;
    case 2:
        func_L39_005F0CE0(0, 0, (u8 *)o);
        res = func_L39_0051E580(&o->pos, &v->f20, v->f48, v->f50, &v->f30);
        if (res != 0 && func_L39_00576AD8() != 0) {
            u8 *t = func_L39_0066BA18(v->f48);
            if (t != 0) {
                *(s32 *)(t + 0x28) = res;
            }
        }
        func_L01_004C4AB8(v->f44);
        func_003BD360(o);
        return;
    }
    o->fF0 = func_00389380(o->fF0, v->f10);
    o->fF4 = func_00389380(o->fF4, v->f14);
    func_L01_00444070(0.2f, o);
    if (o->pos.x < 2.0f || 1021.0f < o->pos.x ||
        o->pos.y < 2.0f || 1021.0f < o->pos.y ||
        o->pos.z < 2.0f || 1021.0f < o->pos.z) {
        func_L01_004C4AB8(v->f44);
        func_003BD360(o);
    }
}
/* localdecomp:end func_L39_0054C0E8 */
