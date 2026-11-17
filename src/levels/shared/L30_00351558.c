#include "common.h"

/* declared by functions of L30_0034EB98.c, which this file was cut from */
extern s32 D_L30_001DF2C0;
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

/* localdecomp:start func_L30_00351558 */
#include "vu0.h"
typedef int q_00351558 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00351558;
typedef struct {
    u8 p0[0x68];
    u8 *vars;      /* 0x68 */
    u8 p6C[0xAA - 0x6C];
    s16 class_id;  /* 0xAA */
} M_00351558;
typedef struct {
    V_00351558 dir;    /* 0x00 */
    M_00351558 *src;   /* 0x10 */
    s32 flags;         /* 0x14 */
    u8 b18;
    u8 b19;
    u16 class_id;      /* 0x1A */
    f32 f1C;
    s32 f20;
} I_00351558;
typedef struct {
    M_00351558 *moby;  /* 0x0 */
    u8 p4[4];
    u8 b8;
    u8 b9;
    u16 hA;
    f32 fC;
} A_00351558;
typedef struct {
    u8 p0[2];
    u8 b2;
    u8 b3;
    s32 i4;
    u8 p8[2];
    s16 hA;
    s32 iC;
    V_00351558 v10;
    V_00351558 v20;
    u8 p30[0x2C - 0x30 + 0x10];
} O_00351558;
typedef struct { u8 p0[0x18]; M_00351558 *hit; } C_00351558;

__asm__(".extern D_L30_001DD8AC, 4");
__asm__(".extern D_L30_001DD8B0, 4");
__asm__(".extern D_L30_001DD8B4, 4");
__asm__(".extern D_L30_001DD8B8, 4");
__asm__(".extern D_L30_001DD8BC, 4");
__asm__(".extern D_L30_001DD8C0, 4");
__asm__(".extern D_L30_001DD8C4, 4");
__asm__(".extern D_L30_001DD8C8, 4");
__asm__(".extern D_L30_001DD8CC, 4");
__asm__(".extern D_L30_001DD8D0, 4");
__asm__(".extern D_L30_001DD8F4, 4");
__asm__(".extern D_L30_001DD8F8, 4");
__asm__(".extern D_L30_001DD8FC, 4");
__asm__(".extern D_L30_001DD900, 4");
__asm__(".extern D_L30_001DD860, 4");
__asm__(".extern D_L30_001DD958, 4");
__asm__(".extern D_L30_001DD95C, 4");
__asm__(".extern D_L30_001DD960, 4");
__asm__(".extern D_L30_001DD964, 4");
__asm__(".extern D_L30_001DD968, 4");
__asm__(".extern D_L30_001DD96C, 4");
__asm__(".extern D_L30_001DD970, 4");
extern s32 D_L30_001DD8AC;
extern s32 D_L30_001DD8B0;
extern f32 D_L30_001DD8B4;
extern f32 D_L30_001DD8B8;
extern f32 D_L30_001DD8BC;
extern f32 D_L30_001DD8C0;
extern f32 D_L30_001DD8C4;
extern f32 D_L30_001DD8C8;
extern f32 D_L30_001DD8CC;
extern f32 D_L30_001DD8D0;
extern s32 D_L30_001DD8F4;
extern f32 D_L30_001DD8F8;
extern f32 D_L30_001DD8FC;
extern s32 D_L30_001DD900;
extern f32 D_L30_001DD860;
extern s32 D_L30_001DD958;
extern s32 D_L30_001DD95C;
extern f32 D_L30_001DD960;
extern f32 D_L30_001DD964;
extern f32 D_L30_001DD968;
extern f32 D_L30_001DD96C;
extern f32 D_L30_001DD970;
extern u8 D_L30_001E1380[] __attribute__((section(".sdata")));
extern u8 *D_L30_0021F278[];
__asm__(".extern D_L30_0021F278, 16");
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DF2C0, 16");
extern C_00351558 D_L30_001E9000;
extern s32 func_L30_0034DBA0(s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_00471BF0(void *, void *, s32);

void func_L30_00351558(O_00351558 *o, A_00351558 *a) {
    M_00351558 *m;
    u8 *g;
    f32 t;
    f32 f;
    f32 dz;

    if (a == 0) return;
    m = a->moby;
    g = D_L30_001E1380;
    if (m == 0) return;
    if (g == 0) return;
    if (a->b9 & 1) {
        qzero(&o->v10);
        qzero(&o->v20);
        a->fC = 0;
        o->i4 = func_L30_0034DBA0(D_L30_001DD8AC, D_L30_001DD8B0);
        o->iC = func_L30_0034DBA0(D_L30_001DD8AC, D_L30_001DD8B0);
        if (func_00382498(0, 1) == 0) {
            o->b2 = D_L30_0021F278[0][D_L30_001DD8F4];
        }
        *(f32 *)((u8 *)o + 0x2C) = func_003824E0(D_L30_001DD8B4, D_L30_001DD8B8);
        o->b3 = g[0x10];
    }
    t = func_L03_0034B148(o->hA, a->b8 << 2, 0.0f);
    f = func_003C4088(D_L30_001DD8C8, D_L30_001DD8C4, a->hA * (1.0f / 65536.0f));
    dz = ((a->b8 * 4 - o->hA) + f) * D_L30_001DD8C0;
    o->v10.x = o->v20.x = o->v20.x + a->fC;
    o->v20.z += dz;
    o->v10.z = o->v20.z + func_003C4088(D_L30_001DD8CC, D_L30_001DD8D0, t);
    if ((D_L30_001DF2C0 & 0xF) == (((s32)o >> 8) & 0xF) &&
        func_003D3CB0(&o->v10, &o->v20, 1, m, 0) != 0) {
        C_00351558 *c = &D_L30_001E9000;
        if (c->hit != 0) {
            V_00351558 d;
            I_00351558 info;
            M_00351558 *h;
            qzero(&d);
            d.x = a->fC;
            info.dir = d;
            info.flags = 0x1010000;
            info.f1C = D_L30_001DD860;
            info.f20 = 1;
            info.src = m;
            func_0038CF68(&info, &info, 1.0f);
            info.b18 = 3;
            info.b19 = 2;
            info.dir.w = 5627.925f;
            info.class_id = m->class_id;
            func_L01_00446978(c->hit, &info);
            h = c->hit;
            if (h != 0 && h->class_id >= 0x175F && h->class_id < 0x1762) {
                *(s32 *)(h->vars + 0xA8) = D_L30_001DD900;
            }
        }
    }
    o->i4 = (o->i4 & 0xFFFFFF) + ((s32)(func_L03_0034B148(a->b8 - o->hA, a->b8, D_L30_001DD8BC) * 128.0f) << 24);
    o->iC = (o->iC & 0xFFFFFF) + ((s32)(func_L03_0034B148(a->b8 - o->hA, a->b8, D_L30_001DD8BC) * 128.0f) << 24);
    o->v10.w = func_003C4088(D_L30_001DD8F8, D_L30_001DD8FC, t);
    D_L30_001DD968 += func_003C4088(D_L30_001DD964, D_L30_001DD960, t);
    if (D_L30_001DD968 > 1.0f) {
        V_00351558 d;
        V_00351558 p;
        D_L30_001DD968 -= 1.0f;
        qzero(&d);
        d.z = D_L30_001DD96C;
        *(q_00351558 *)&p = *(q_00351558 *)&o->v20;
        p.y += D_L30_001DD970;
        func_L01_00471BF0(&p, &d, func_00382498(D_L30_001DD95C, D_L30_001DD958));
    }
}
/* localdecomp:end func_L30_00351558 */

INCLUDE_ASM("asm/levels", func_L30_003518F0);
