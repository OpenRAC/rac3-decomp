#include "common.h"

typedef struct {
    s32 n;
    s32 done;
    s32 pad[2];
} Tab_00477BC0;

INCLUDE_ASM("asm/levels", func_L01_004729D8);

INCLUDE_ASM("asm/levels", func_L01_00472C98);

INCLUDE_ASM("asm/levels", func_L01_00472F58);

INCLUDE_ASM("asm/levels", func_L01_004730F8);

INCLUDE_ASM("asm/levels", func_L01_00473268);

INCLUDE_ASM("asm/levels", func_L01_004734A8);

/* localdecomp:start func_L01_004735F0 */
typedef int Quad_4735F0 __attribute__((mode(TI)));
typedef struct {
    u8 type;                       /* 0x00 */
    s8 flags;                      /* 0x01 */
    u8 texture;                    /* 0x02 */
    u8 render;                     /* 0x03 */
    u32 rgba;                      /* 0x04: R in the low byte */
    u8 spin;                       /* 0x08 */
    u8 render2;                    /* 0x09 */
    s16 life;                      /* 0x0A: frames */
    u32 end_rgba;                  /* 0x0C */
    Quad_4735F0 head;              /* 0x10: w is the half width */
    u8 pad_20[0xC];
    f32 drag;                      /* 0x2C: velocity kept a frame, 1.0 for none */
    Quad_4735F0 tail;              /* 0x30: w is the scale */
} Ray_4735F0;

extern u8 *D_L01_00221254[];
/* func_L01_004618E0, under an alias: a later block declares it with its own particle type */
extern Ray_4735F0 *func_L01_004618E0_004735F0(s32 type);

/* particle_spawn_ray: a type 0x6F particle, a ray from head to tail for life frames: white at
 * 0x64 at scale 1, else blue (0x20, 0x20, 0xFF), added, half width scale x 0.013. */
Ray_4735F0 *func_L01_004735F0(Quad_4735F0 *head, Quad_4735F0 *tail, s32 life, f32 scale) {
    Ray_4735F0 *ray = func_L01_004618E0_004735F0(0x6F);

    if (ray != 0) {
        if (scale != 1.0f) ray->rgba = 0x64FF2020;
        else ray->rgba = 0x64FFFFFF;
        ray->end_rgba = ray->rgba;
        ray->render2 = 0x22;
        ray->render = 0x48;
        ray->flags = 3;
        ray->texture = *D_L01_00221254[0];
        ray->tail = *tail;
        ((f32 *)&ray->tail)[3] = scale;
        ray->head = *head;
        ray->life = life;
        ((f32 *)&ray->head)[3] = scale * 0.013f;
        ray->drag = 1.0f;
        ray->spin = (u8)ray->life - 12;
    }
    return ray;
}
/* localdecomp:end func_L01_004735F0 */

INCLUDE_ASM("asm/levels", func_L01_004736F0);

LINKER_REMNANT("asm/levels", func_L01_00473858);

INCLUDE_ASM("asm/levels", func_L01_00473860);

/* localdecomp:start func_L01_004739D0 */
void func_L01_004739D0(void) {

}
/* localdecomp:end func_L01_004739D0 */

/* localdecomp:start func_L01_004739D8 */
typedef int s128_00470258 __attribute__((mode(TI)));
typedef struct {
    s128_00470258 v;
    s32 f10;
    s32 f14;
    s16 f18;
    u8 f1A;
} Sub_00470258;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    s32 f4;
    u8 f8;
    u8 f9;
    s16 fA;
    f32 fC;
    s128_00470258 f10;
    Sub_00470258 sub;
} Part_00470258;
extern u8 *D_L01_002210FC[];
extern Part_00470258 *func_L01_004618E0(s32);
extern u8 func_00382498(s32, s32);
void func_L01_004739D8(s128_00470258 *pos, s128_00470258 *v2, s32 a2, s32 a3, s16 t0, u8 t1, f32 f) {
    Part_00470258 *p;
    Sub_00470258 *q;
    p = func_L01_004618E0(114);
    if (p != 0) {
        p->f10 = *pos;
        p->f9 = 68;
        p->f3 = 72;
        p->fC = f;
        p->f1 = 0;
        p->f8 = 0;
        p->f2 = *D_L01_002210FC[0];
        q = &p->sub;
        p->fA = t0;
        q->f18 = t0;
        p->f4 = a2;
        q->f10 = a2;
        q->f14 = a3;
        q->f1A = t1;
        p->f8 = func_00382498(0, 255);
        q->v = *v2;
    }
}
/* localdecomp:end func_L01_004739D8 */

INCLUDE_ASM("asm/levels", func_L01_00473AC8);

INCLUDE_ASM("asm/levels", func_L01_00474068);

INCLUDE_ASM("asm/levels", func_L01_00474078);

INCLUDE_ASM("asm/levels", func_L01_004741B8);

LINKER_REMNANT("asm/levels", func_L01_00474320);

/* localdecomp:start func_L01_00474328 */
typedef struct Ops_45E458 Ops_45E458;
typedef struct {
    s32 pad;
    Ops_45E458 *ops;
} Sub_45E458;
struct Ops_45E458 {
    s32 pad[5];
    void (*fn)(u8 *a0, Sub_45E458 *s);
};

extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *a0);

void func_L01_00474328(u8 *a0)
{
    Sub_45E458 *s = (Sub_45E458 *)(a0 + 32);

    if (s != 0) {
        if (func_0038CB00(a0 + 10)) {
            func_003CD250(a0);
        } else if (s->ops != 0) {
            s->ops->fn(a0, s);
        }
    }
}
/* localdecomp:end func_L01_00474328 */

INCLUDE_ASM("asm/levels", func_L01_00474390);

INCLUDE_ASM("asm/levels", func_L01_004744D0);

INCLUDE_ASM("asm/levels", func_L01_00474680);

INCLUDE_ASM("asm/levels", func_L01_004747C0);

/* localdecomp:start func_L01_00474968 */
extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *a0);
void func_L01_00474968(u8 *a0) {
    u8 *s1 = a0 + 48;
    if (s1 != 0) {
        if (((s32 (*)(u8 *a0))func_0038CB00)(a0 + 10) != 0) {
            func_003CD250(a0);
        } else {
            (*(void (**)(u8 *, u8 *))(*(u8 **)(s1 + 4) + 20))(a0, s1);
        }
    }
}
/* localdecomp:end func_L01_00474968 */

INCLUDE_ASM("asm/levels", func_L01_004749C8);

INCLUDE_ASM("asm/levels", func_L01_00474B48);

LINKER_REMNANT("asm/levels", func_L01_00474DD8);

INCLUDE_ASM("asm/levels", func_L01_00474DE0);

INCLUDE_ASM("asm/levels", func_L01_00474F38);

INCLUDE_ASM("asm/levels", func_L01_00475128);

INCLUDE_ASM("asm/levels", func_L01_00475278);

/* localdecomp:start func_L01_004756D0 */
extern s32 func_0038CB00(void *p);
extern void func_003CD250(u8 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 D_L01_001D7FC4;

void func_L01_004756D0(u8 *a0) {
    if (((s32 (*)(u8 *))func_0038CB00)(a0 + 10) != 0 || *(f32 *)(a0 + 12) < D_L01_001D7FC4 * 210000.0f) {
        func_003CD250(a0);
    } else {
        u8 *p = a0 + 32;
        *(s32 *)(a0 + 4) = func_0038DBD8(*(s32 *)(p + 8), *(s32 *)(p + 4),
                                         (f32)*(s16 *)(a0 + 10) * *(f32 *)(p + 12));
        *(f32 *)(a0 + 12) = *(f32 *)(a0 + 12) + *(f32 *)(a0 + 32);
    }
}
/* localdecomp:end func_L01_004756D0 */

INCLUDE_ASM("asm/levels", func_L01_00475770);

INCLUDE_ASM("asm/levels", func_L01_00475910);

INCLUDE_ASM("asm/levels", func_L01_00475C60);

INCLUDE_ASM("asm/levels", func_L01_00475DC8);

INCLUDE_ASM("asm/levels", func_L01_00475F28);

INCLUDE_ASM("asm/levels", func_L01_004760C8);

LINKER_REMNANT("asm/levels", func_L01_00476408);

/* localdecomp:start func_L01_00476440 */
s32 func_L01_00476440(const s32 *count, s32 index, s32 delta, s32 wrap) {
    if (wrap != 0) {
        index = (index + delta + *count) % *count;
    } else {
        index += delta;
        if (delta < 0) {
            if (index < 0) index = 0;
        } else if (index > *count - 1) {
            index = *count - 1;
        }
    }
    return index;
}
/* localdecomp:end func_L01_00476440 */

INCLUDE_ASM("asm/levels", func_L01_00476498);

/* localdecomp:start func_L01_004766E0 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

extern void func_0038CF38(Vec4 *a0, Vec4 *a1);
extern void func_0038CF00(Vec4 *a0, Vec4 *a1);

void func_L01_004766E0(Vec4 *a0, Vec4 *a1, f32 r) {
    Vec4 a;
    Vec4 b;
    Vec4 *pa = &a;
    Vec4 *pb = &b;
    a.q = a0->q;
    b.q = a1->q;
    if (0.0f < r && __builtin_fabsf(pa->f[2] - pb->f[2]) < r) {
        func_0038CF38(pa, pb);
    } else {
        func_0038CF00(pa, pb);
    }
}
/* localdecomp:end func_L01_004766E0 */

INCLUDE_ASM("asm/levels", func_L01_00476750);

INCLUDE_ASM("asm/levels", func_L01_00476920);

INCLUDE_ASM("asm/levels", func_L01_00476B98);

INCLUDE_ASM("asm/levels", func_L01_00476F10);

INCLUDE_ASM("asm/levels", func_L01_00477190);

INCLUDE_ASM("asm/levels", func_L01_00477488);

INCLUDE_ASM("asm/levels", func_L01_00477668);

INCLUDE_ASM("asm/levels", func_L01_00477890);

LINKER_REMNANT("asm/levels", func_L01_00477990);

INCLUDE_ASM("asm/levels", func_L01_00477998);

/* localdecomp:start func_L01_00477BC0 */
extern int D_L01_0021F6C0[];


void func_L01_00477BC0(s32 a0, s32 a1) {
    Tab_00477BC0 *p;
    s32 next;
    s32 off;
    s32 i;

    if (a0 != -1) {
        p = (Tab_00477BC0 *)D_L01_0021F6C0[a0];
        if (p->done == 0 || a1 != 0) {
            for (i = 0; i < p->n - 1; i = next) {
                next = i + 1;
                off = i * 16;
                *(f32 *)((u8 *)p + off + 0x1C) = ((f32 (*)(void *, void *))func_0038CF00)((u8 *)p + (off + 16), (u8 *)p + ((next % p->n) * 16 + 16));
            }
            p->done = 1;
        }
    }
}
/* localdecomp:end func_L01_00477BC0 */

INCLUDE_ASM("asm/levels", func_L01_00477C80);

/* localdecomp:start func_L01_00477ED0 */
extern int D_L01_0021F6C0[];
extern float func_L01_00477F20(int a);

float func_L01_00477ED0(int a0)
{
    if (a0 != -1) {
        int v = D_L01_0021F6C0[a0];
        if (v != 0) {
            return func_L01_00477F20(v);
        }
    }
    return -1.0f;
}
/* localdecomp:end func_L01_00477ED0 */

INCLUDE_ASM("asm/levels", func_L01_00477F20);

LINKER_REMNANT("asm/levels", func_L01_004781A0);

INCLUDE_ASM("asm/levels", func_L01_004781D0);
