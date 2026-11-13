#include "common.h"

/* localdecomp:start func_L39_0051E200 */
extern s32 D_L39_0024D48C[];

/* from rac4-decomp's func_004F4E58 */
void func_L39_0051E200(void) {
    s32 i;
    s32 *p;
    i = 0xF;
    p = &D_L39_0024D48C[0];
    do {
        *p = 0;
        i -= 1;
        p -= 1;
    } while (i >= 0);
}
/* localdecomp:end func_L39_0051E200 */

/* localdecomp:start func_L39_0051E230 */
extern s32 D_L39_0024D450[];

s32 func_L39_0051E230(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_L39_0024D450[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_0051E230 */

/* localdecomp:start func_L39_0051E268 */
extern s32 D_L39_0024D490[];
extern s32 D_L39_0024D450[];
extern s32 D_L39_0024D490_b;
void func_L39_0051E268(s32 a0) {
    s32 n = D_L39_0024D490[0];
    s32 i = 0;
    s32 *p = D_L39_0024D450;
    do {
        if (*p == a0) {
            *p = 0;
            n--;
            break;
        }
        i++;
        p++;
    } while (i < 16);
    D_L39_0024D490_b = n;
}
/* localdecomp:end func_L39_0051E268 */

INCLUDE_ASM("asm/levels", func_L39_0051E2B0);

INCLUDE_ASM("asm/levels", func_L39_0051E370);

/* localdecomp:start func_L39_0051E9A8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051E9A8;
typedef struct S_0051E9A8_owner {
    s32 f0;
    u8 pad4[0x2520];
    u8 *f2524;
} S_0051E9A8_owner;
typedef struct {
    V4_0051E9A8 v;
    u8 pad10[0x1C];
    s32 f2C;
    S_0051E9A8_owner *f30;
    u8 pad34[0xC];
    V4_0051E9A8 v40;
} P_0051E9A8;
typedef struct {
    u8 pad0[0x10];
    V4_0051E9A8 v10;
    u8 b20;
    u8 pad21[0xF];
    u8 b30;
    u8 pad31;
    s16 s32;
    u16 flags;
    u8 pad36[0x32];
    P_0051E9A8 *p68;
    u8 pad6C[0x24];
    s32 f90;
    u8 pad94[0x24];
    u8 *fB8;
    u8 padBC[4];
    V4_0051E9A8 vC0;
    u8 padD0[0x10];
    V4_0051E9A8 vE0;
} O_0051E9A8;
extern O_0051E9A8 *func_003C24B0(s32, s32);
extern void func_0038D308(V4_0051E9A8 *, void *);
extern void func_0038D278(V4_0051E9A8 *);
extern void func_0038CF68(V4_0051E9A8 *, void *, f32);
extern void func_0038CE90(V4_0051E9A8 *, V4_0051E9A8 *, V4_0051E9A8 *);
extern f32 func_0038CE68(V4_0051E9A8 *, V4_0051E9A8 *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_0038CE20(V4_0051E9A8 *, V4_0051E9A8 *, f32);
extern void func_0038D810(V4_0051E9A8 *, f32 *);
extern void func_0038D5F0(V4_0051E9A8 *, f32 *, V4_0051E9A8 *);

O_0051E9A8 *func_L39_0051E9A8(V4_0051E9A8 *a0, V4_0051E9A8 *a1, s32 a2, S_0051E9A8_owner *a3, V4_0051E9A8 *a4) {
    O_0051E9A8 *o = func_003C24B0(0x108F, 0x80);
    P_0051E9A8 *p;
    V4_0051E9A8 quat;
    V4_0051E9A8 axis;
    V4_0051E9A8 tmp;
    f32 mat[12];
    f32 half;

    if (o != 0) {
        o->b20 = 0;
        o->s32 = 255;
        o->b30 = 255;
        o->flags |= 0x100;
        p = o->p68;
        o->v10 = *a0;
        p->v = *a1;
        p->v40 = *a4;
        p->f2C = a2;
        p->f30 = a3;
        o->f90 = a3->f0;
        if (a3 != 0) {
            o->fB8 = a3->f2524;
            func_0038D308(&o->vC0, a3->f2524 + 0xF0);
        } else {
            o->fB8 = 0;
            func_0038D278(&o->vC0);
        }
        func_0038CF68(&tmp, a4, -1.0f);
        func_0038CE90(&axis, &o->vE0, &tmp);
        half = func_0038CE68(&o->vE0, &tmp) * 0.5f;
        func_0038CE20(&quat, &axis, func_0038D0B0(half));
        quat.w = func_0038D098(half);
        func_0038D810(&quat, mat);
        func_0038D5F0(&o->vC0, mat, &o->vC0);
    }
    return o;
}
/* localdecomp:end func_L39_0051E9A8 */
