#include "common.h"

/* localdecomp:start func_L24_00350A50 */
#include "vu0.h"

typedef struct {
    vu0_v4 vel;
    vu0_v4 pos;
    void *x20;
    f32 x24;
    f32 x28;
    u8 p2C[4];
    f32 x30;
    f32 x34;
    u8 x38;
    u8 p39[3];
    u8 x3C;
} S_003519E8;

/* the hit record func_L01_00446760 fills (inlined here) */
typedef struct {
    vu0_v4 v;
    void *obj;
    s32 flags;
    u8 b8;
    u8 b9;
    u16 hA;
    f32 fC;
    s32 one;
} Q_003519E8;

extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044E108(void *, void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern s32 func_L01_003F9498(void *, f32, s32, void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00447D00(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern s32 func_003CF790(void *, s32, void *, void *, f32);
extern void func_003BD360(void *);
extern vu0_v4 D_L24_001D9A60;
__asm__(".extern D_001D52FC, 16");
extern u8 *D_001D52FC;
__asm__(".extern D_L24_001DD548, 4");
__asm__(".extern D_L24_001DD54C, 4");
__asm__(".extern D_L24_001DD550, 4");
__asm__(".extern D_L24_001DD554, 4");
extern f32 D_L24_001DD548;
extern f32 D_L24_001DD54C;
extern f32 D_L24_001DD550;
extern f32 D_L24_001DD554;

void func_L24_00350A50(u8 *obj) {
    S_003519E8 *s;
    struct {
        vu0_v4 start[1];
        vu0_v4 from[1];
        union {
            struct {
                vu0_v4 off;
                vu0_v4 vel;
                vu0_v4 dir;
                vu0_v4 last;
                vu0_v4 dest;
            } v;
            Q_003519E8 hit;
        } u;
    } L;

    L.start[0] = *(vu0_v4 *)(obj + 0x10);
    s = *(S_003519E8 **)(obj + 0x68);
    L.from[0] = L.start[0];
    if (obj[0x20] == 0) {
        f32 z;
        s32 n;
        vu0_q qa, qb;

        *(vu0_q *)&L.u.v.dir = 0;
        L.u.v.dir.x = func_0037E250(-1.0f, 1.0f);
        L.u.v.dir.y = func_0037E250(-1.0f, 1.0f);
        L.u.v.dir.z = func_0037E250(-1.0f, 1.0f);
        L.u.v.vel = L.u.v.dir;
        func_00388830(&L.u.v.vel, &L.u.v.vel, func_0037E250(0.1f, 0.2f) * 0.0166666675f);
        func_00388830(&L.u.v.off, s, -func_0037E250(0.0016666668f, 0.0166666675f));
        vec_add_ba(&L.u.v.vel, &L.u.v.vel, &L.u.v.off);
        func_003886E8(&L.u.v.off, s, func_0037E250(0.0f, 1.0f));
        vec_add_ab(&L.u.v.off, &L.u.v.off, obj + 0x10);
        n = func_0037E208(0x1C, 0x28);
        func_L01_00460318(&L.u.v.off, &L.u.v.vel, 0x6F00AFFF, 0x100000FF, n, 0x28, func_0037E208(0x28, 0x46), 1);
        func_00388758(&L.u.v.off, &s->pos, &D_L24_001D9A60);
        {
            f32 t;
            f32 w;

            t = -(*(f32 *)(D_001D52FC + 0x10C) + *(f32 *)(D_001D52FC + 0x104));
            if (t > 1.0f) {
                t = 1.0f;
            } else if (t < -1.0f) {
                t = -1.0f;
            }
            w = -(*(f32 *)(D_001D52FC + 0x108) + *(f32 *)(D_001D52FC + 0x100));
            if (w > 1.0f) {
                w = 1.0f;
            } else if (w < -1.0f) {
                w = -1.0f;
            }
            func_00388830(&L.u.v.off, &L.u.v.off, w * (D_L24_001DD548 * 0.0166666675f));
            if (t > 0.0f) {
                func_00388830(&L.u.v.vel, &s->pos, t * (D_L24_001DD54C * 0.0166666675f));
            } else {
                func_00388830(&L.u.v.vel, &s->pos, t * (D_L24_001DD550 * 0.0166666675f));
            }
        }
        vec_add_ba(&L.u.v.dest, &s->pos, &L.u.v.vel);
        L.u.v.dir = L.u.v.dest;
        L.u.v.last = L.u.v.dest;
        __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %3\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tsqc2 $vf1, %1"
                : "=m"(L.u.v.dir), "=m"(L.u.v.last) : "m"(L.u.v.off), "m"(L.u.v.dir) : "vf1", "vf2");
        L.u.v.dir.z = 0.0f;
        z = s->vel.z;
        s->vel.z = 0.0f;
        func_003886E8(s, s, 1.0f - D_L24_001DD554);
        func_003886E8(&L.u.v.dir, &L.u.v.dir, D_L24_001DD554);
        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(L.u.v.dir));
        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(s->vel));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
        __asm__("sqc2 %1, %0" : "=m"(s->vel) : "j"(qa));
        __asm__("sqc2 %1, %0" : "=m"(L.u.v.last) : "j"(qa));
        s->vel.z = z;
        vec_add_ba(obj + 0x10, obj + 0x10, s);
        *(f32 *)(obj + 0xF8) = func_00388A28(s->vel.x, s->vel.y);
        *(f32 *)(obj + 0xF4) = -func_00388A28(func_003887A0(s), s->vel.z);
        func_L01_0044E108(obj, s, s, s->x28);
        L.u.hit.obj = obj;
        L.u.hit.flags = 0x10001;
        L.u.hit.fC = s->x30;
        L.u.hit.one = 1;
        L.u.hit.v = s->vel;
        func_00388830(&L.u.hit.v, &L.u.hit.v, s->x34);
        L.u.hit.v.w = 5627.925f;
        L.u.hit.b8 = s->x38;
        L.u.hit.b9 = s->x3C;
        L.u.hit.hA = *(u16 *)(obj + 0xAA);
        if (func_003CE740(L.from, obj + 0x10, 0, s->x20, (s32)&L.u.hit) != 0
            || func_L01_003F9498(obj + 0x10, 0.2f, 0, s->x20) != 0) {
            func_0039FE80(0, 0, obj);
            func_L01_00447D00(obj, s, 0, (s32)(s->x24 * 5.0f), (s32)(s->x24 * 4.0f), (s32)(s->x24 * 10.0f), -1, 1, 1, -1, 0,
                              0x1010001, 0.0f, 0.0f, s->x24 * 4.0f, s->x24 + s->x24, 9.0f, s->x24, s->x24 * 15.0f);
            func_003CF790(obj + 0x10, 0x10, s->x20, &L.u.hit, s->x24 * 4.0f);
            func_003BD360(obj);
            return;
        }
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f
        || *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f
        || *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_003BD360(obj);
    }
}
/* localdecomp:end func_L24_00350A50 */
