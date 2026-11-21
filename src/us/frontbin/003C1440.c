#include "common.h"

/* NTSC-U counterpart of func_003C6990 (src/frontbin/3C6360.c): 8 -> 10 */
/* localdecomp:start func_U_003C1440 */
#include "vu0.h"
typedef int Q_3C1440 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C1440;
typedef struct { u8 p0[0x10]; V_3C1440 pos; u8 p20[0xA0]; u8 fC0[0x30]; V_3C1440 fF0; } O_3C1440;
typedef struct {
    V_3C1440 f0; V_3C1440 f10; u8 f20[0x10]; f32 f30[3]; f32 f3C[3]; f32 f48[3]; f32 f54[3];
    f32 f60; f32 f64; f32 f68; f32 f6C; f32 f70; f32 f74; f32 f78[3]; f32 f84[3]; f32 f90[3]; f32 f9C[3]; s32 fA8; s32 fAC;
} C_3C1440;
typedef struct { u8 p0[0x80]; V_3C1440 f80; u8 p90[0x2CC]; O_3C1440 *f35C; s32 f360; } W_3C1440;
extern W_3C1440 D_001A4BE0;
extern s32 func_0011A264(void *, s32, s32);
extern void func_U_003BFAF8();
extern s32 func_U_00388398(void *);
extern f32 func_U_00389380_003C1440(f32, f32);
extern f32 func_U_00388978(f32);
extern void func_U_00388BD0();
extern void func_U_00388EB8();
extern void func_U_003888C8(void *, void *, void *);
extern void func_U_003BFD90(void *, void *, void *, f32);
extern s32 func_U_003BF7E8();
extern void func_U_003BF838();
void func_U_003C1440(O_3C1440 *o, C_3C1440 *c, V_3C1440 *tgt) {
    V_3C1440 a, b;
    f32 cc[4] __attribute__((aligned(16)));
    V_3C1440 e, g, f, h[3], i, k, l;
    s32 n;
    f32 *pe;
    s32 r;
    s32 m;
    a = o->pos;
    b = o->fF0;
    func_0011A264(cc, 0, 0x10);
    if (tgt != 0 || (D_001A4BE0.f35C == o && D_001A4BE0.f360 >= 2)) {
        if (tgt != 0) vec_sub_ab(&e, tgt, &o->pos);
        else vec_sub_ab(&e, &D_001A4BE0.f80, &o->pos);
        func_U_003BFAF8(o, &e, &e, 0);
        vec_sub_ab(&e, &e, &c->f10);
        cc[0] = -e.y * c->f6C;
        cc[1] = e.x * c->f70;
        cc[2] = -c->f74;
        if (c->fAC == 0) {
            for (m = 0; m < 3; m++) c->f3C[m] += cc[m] * c->f78[m];
            c->fAC = 10;
        }
    } else {
        func_U_00388398(&c->fAC);
    }
    pe = &e.x;
    for (n = 0; n < 3; n++) {
        c->f3C[n] += c->f48[n] * (cc[n] - c->f30[n]);
        c->f3C[n] -= c->f54[n] * c->f3C[n];
        c->f30[n] += c->f3C[n];
        c->f84[n] = func_U_00389380_003C1440(c->f84[n], c->f90[n]);
        pe[n] = c->f9C[n] * func_U_00388978(c->f84[n]);
    }
    *(Q_3C1440 *)&f = 0;
    f.x = c->f30[0] + e.x;
    f.y = c->f30[1] + e.y;
    g = f;
    if (c->f60 < g.x) g.x = c->f60;
    else if (g.x < -c->f60) g.x = -c->f60;
    if (g.y > c->f64) g.y = c->f64;
    else if (g.y < -c->f64) g.y = -c->f64;
    func_U_00388BD0(h, &g);
    func_U_00388BD0(o->fC0, c->f20);
    func_U_00388EB8(o->fC0, o->fC0, h);
    f = c->f10;
    f.z = f.z + e.z;
    func_U_003888C8(&i, &f, o->fC0);
    {
        Q_3C1440 t1, t2, t3, t4, w, t5, t6, t7, t8;
        __asm__("lqc2 %0, %1" : "=j"(t1) : "m"(i));
        __asm__("lqc2 %0, %1" : "=j"(t2) : "m"(o->pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(t3) : "j"(t1), "j"(t2));
        __asm__("sqc2 %1, %0" : "=m"(i) : "j"(t3));
        __asm__("lqc2 %0, %1" : "=j"(w) : "m"(o->pos));
        __asm__("lqc2 %0, %1" : "=j"(t4) : "m"(c->f0));
        __asm__("lqc2 %0, %1" : "=j"(t5) : "m"(i));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(t6) : "j"(t4), "j"(t5));
        __asm__("sqc2 %1, %0" : "=m"(k) : "j"(t6));
        __asm__("lqc2 %0, %1" : "=j"(t7) : "m"(k));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(t8) : "j"(w), "j"(t7));
        __asm__("sqc2 %1, %0" : "=m"(o->pos) : "j"(t8));
    }
    {
        f32 v = -c->f30[2];
        if (c->f68 < v) v = c->f68;
        else if (v < -c->f68) v = -c->f68;
        func_U_003BFD90(o, &o->pos, &o->pos, v);
    }
    r = func_U_003BF7E8(o);
    if (r != 0) {
        vec_sub_ba(&l, &o->pos, &a);
        func_U_003BF838(r, &l, &b, &o->fF0);
    }
}
/* localdecomp:end func_U_003C1440 */
