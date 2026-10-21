/* US draft of func_00384878 (rac3-uya-decomp func_00384850, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00384878 */
/* VU0 j-form (needs -mvu0-use-vf0-vf2, on every line of tools/text_parts.txt).
   sq $zero through the documented non-volatile QZERO "=m" form. */
typedef int Q_3801C0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3801C0;
typedef union { V_3801C0 v; u128_t q; f32 f[4]; } U_3801C0;
typedef struct { u8 p0[0x86]; s16 h86; } P_3801C0;
typedef struct {
    f32 f0, f4, f8, fC;
    f32 f10[4];
    U_3801C0 u20;
    u128_t q30;
    u128_t q40;
    U_3801C0 u50;
    U_3801C0 u60;
    V_3801C0 v70;
    V_3801C0 v80;
    u128_t q90;
    f32 fA0, fA4, fA8;
    f32 fAC[5];
    u8 pC0[0x30];
} B_3801C0;
typedef struct {
    u8 p0[0x40];
    U_3801C0 u40;
    u8 p50[8];
    f32 f58;
    u8 p5C[0x24];
    V_3801C0 v80;
    u8 p90[0x6C];
    s32 iFC;
    s32 i100;
    u8 p104[0x460 - 0x150 - 0x104];
} A_3801C0;
typedef struct {
    u8 p0[0x50];
    P_3801C0 *f50;
    u8 p54[0xC];
    B_3801C0 b;
    A_3801C0 a;
} E_3801C0;
__asm__(".extern D_001D57B8, 4");
__asm__(".extern D_001D57BC, 4");
__asm__(".extern D_001D57C4, 4");
extern f32 D_001D57B8, D_001D57BC, D_001D57C4;
extern E_3801C0 D_00222480_00384878[];
extern void func_0038D200(f32 *, void *, f32);
extern f32 func_00382FA8(f32 *, f32, f32, f32, f32, f32);
void func_00384878(s32 idx, s32 flag) {
    E_3801C0 *e = &D_00222480_00384878[idx];
    A_3801C0 *a = &e->a;
    B_3801C0 *b = &e->b;
    U_3801C0 t;
    U_3801C0 u;
    f32 l;
    s32 i;
    func_0038D348((s32)&t, (s32)&a->v80, -1.0f);
    e->b.q40 = e->b.q30;
    e->b.q30 = t.q;
    if (flag != 0) {
        e->b.u20.q = t.q;
        __asm__("sq $0,%0" : "=m"(e->b.u50.q));
    } else {
        f32 k1, k2;
        if (func_0038D248(&e->b.u20, &t) < -0.98f) {
            t.v.x += 0.2f;
            t.v.y += 0.2f;
            t.v.z += 0.2f;
        }
        k1 = D_001D57BC;
        k2 = D_001D57B8;
        if (e->f50->h86 == 0x20) {
            k2 = D_001D57C4;
            k1 = k2;
        }
        b->u20.v.x = func_00382FA8(&e->b.u50.f[0], b->u20.v.x, t.v.x, k1, k2, 0.0f);
        b->u20.v.y = func_00382FA8(&e->b.u50.f[1], b->u20.v.y, t.v.y, k1, k2, 0.0f);
        b->u20.v.z = func_00382FA8(&e->b.u50.f[2], b->u20.v.z, t.v.z, k1, k2, 0.0f);
        func_0038D348((s32)&e->b.u20, (s32)&e->b.u20, 1.0f);
    }
    {
        Q_3801C0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(b->u60));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(a->u40));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->v70) : "j"(x));
    }
    b->fA0 = func_0038D288(&b->v70);
    l = func_0038D248(&b->v70, &t);
    b->fA8 = l;
    func_0038D348((s32)&u, (s32)&t, l);
    b->q90 = u.q;
    {
        Q_3801C0 x, y;
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(u));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b->v70));
        __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(b->v80) : "j"(x));
    }
    l = func_0038D288(&b->v80);
    b->fA4 = l;
    func_0038D200(&b->v80.x, &b->v80, 1.0f / l);
    b->u60.q = a->u40.q;
    if (a->iFC != 0x50 || a->i100 == 0x11) {
        b->f0 = a->u40.v.x;
        b->f4 = a->u40.v.y;
        b->f8 = func_00382FA8(b->f10, b->f8, a->u40.v.z, 0.0075f, 0.175f, 0.0f);
        b->fC = a->u40.v.z;
    } else {
        b->f0 = a->u40.v.x;
        b->f4 = a->u40.v.y;
    }
    for (i = 0; i < 4; i++) b->fAC[i] = b->fAC[i + 1];
    b->fAC[i] = a->f58;
}
/* localdecomp:end func_00384878 */
