#include "common.h"

INCLUDE_ASM("asm/levels", func_L06_00356C80);

/* localdecomp:start func_L06_003573A0 */
extern int func_L01_004561B8(u8 *);
extern void func_L06_00351930(u8 *, u8 *, int, int, int);
extern int func_L06_00350FD0(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, int, int);

int func_L06_003573A0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_L01_004561B8(moby)) {
        func_L06_00351930(moby, vars, 9, 0, 10);
    }
    func_L06_00350FD0(moby, vars, vars + 544);
    if (moby[96] & 2) {
        *(int *)(vars + 900) = 1;
        func_L01_004450F0(moby, 3, -1);
        func_L06_00351930(moby, vars, 10, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003573A0 */

/* localdecomp:start func_L06_00357440 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L06_00351220(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);

s32 func_L06_00357440(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    s32 ret;
    if (func_L01_004561B8(a0)) {
        func_L06_00351930(a0, s1, 12, 0, 10);
    }
    func_L06_00351220(a0, s1);
    if ((a0[96] & 2) == 0) {
        ret = 0;
    } else {
        *(s32 *)(s1 + 900) = 0;
        func_L01_004450F0(a0, 3, -1);
        func_L06_00351930(a0, s1, 2, 0, 10);
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L06_00357440 */

INCLUDE_ASM("asm/levels", func_L06_003574E0);

INCLUDE_ASM("asm/levels", func_L06_003575B8);

/* localdecomp:start func_L06_00357620 */
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

s32 func_L06_00357620(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 104);

    if (((s32 (*)(void *))func_L01_004561B8)(arg0)) {
        *(s32 *)(s + 636) = -*(s32 *)(s + 636);
        ((void (*)(void *, void *, s32, s32, s32))func_L06_00351930)(arg0, s, 3, 0, 10);
    }
    if (arg0[96] & 2) {
        ((void (*)(void *, s32, s32))func_L01_004450F0)(arg0, 1, -1);
        ((void (*)(void *, void *, s32, s32, s32))func_L06_00351930)(arg0, s, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357620 */

INCLUDE_ASM("asm/levels", func_L06_003576B8);

INCLUDE_ASM("asm/levels", func_L06_00357768);

INCLUDE_ASM("asm/levels", func_L06_00357850);

INCLUDE_ASM("asm/levels", func_L06_00357968);

/* localdecomp:start func_L06_00357A58 */
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L06_00357768(u8 *a0, u8 *a1);
extern s32 func_0038CAD0(s32 *a0);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
s32 func_L06_00357A58(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 104);
    if (func_L06_00357768(a0, s0) != 0) {
        return 1;
    }
    if (((s32 (*)(u8 *a0))((s32 (*)(void *))func_L01_004561B8))(a0) != 0) {
        *(s32 *)(s0 + 816) = 20;
    }
    if (func_0038CAD0((s32 *)(s0 + 816)) != 0) {
        func_L01_004450F0(a0, 22, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357A58 */

INCLUDE_ASM("asm/levels", func_L06_00357AD0);

INCLUDE_ASM("asm/levels", func_L06_00357B28);

/* localdecomp:start func_L06_00357C10 */
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern int func_L06_00350FD0(u8 *, u8 *, u8 *);
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);
extern s32 func_L01_004561B8(u8 *);
typedef struct {
    char pad0[72];
    f32 scale;
} Sub00356F10;

typedef struct {
    char pad0[544];
    char state[64];
    Sub00356F10 *sub;
    char pad264[288];
    s32 timer;
} Data00356F10;

typedef struct {
    char pad0[72];
    f32 scale;
    char pad4C[20];
    u8 flags;
    char pad61[7];
    Data00356F10 *data;
} Moby00356F10;

extern void func_L06_003525E0(Moby00356F10 *, Data00356F10 *);

int func_L06_00357C10(Moby00356F10 *m)
{
    Data00356F10 *d = m->data;

    if (((int (*)(Moby00356F10 *))func_L01_004561B8)(m)) {
        ((void (*)(Moby00356F10 *, Data00356F10 *, int, int, int))func_L06_00351930)(m, d, 13, 0, 10);
        m->scale = 1.5f;
        d->sub->scale = 1.5f;
    }
    ((int (*)(Moby00356F10 *, Data00356F10 *, void *))func_L06_00350FD0)(m, d, d->state);
    if (m->flags & 2) {
        d->timer = 0;
        ((void (*)(Moby00356F10 *, Data00356F10 *, int, int, int))func_L06_00351930)(m, d, 14, 0, 10);
        ((void (*)(Moby00356F10 *, int, int))func_L01_004450F0)(m, 26, -1);
        func_L06_003525E0(m, d);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357C10 */

/* localdecomp:start func_L06_00357CD8 */
extern void func_L06_003525E0(Moby00356F10 *, Data00356F10 *);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern s32 func_0038CAD0(s32 *a0);
extern int func_L06_00350FD0(u8 *, u8 *, u8 *);
extern s32 func_L01_004561B8(u8 *);

s32 func_L06_00357CD8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    if (((s32 (*)(void *))func_L01_004561B8)(m) != 0) {
        *(s32 *)(v + 0x330) = 30;
    }
    ((void (*)(void *, void *, void *))func_L06_00350FD0)(m, v, v + 0x220);
    if (((s32 (*)(void *))func_0038CAD0)(v + 0x330) != 0) {
        ((void (*)(void *, s32, s32))func_L01_004450F0)(m, 26, -1);
        ((void (*)(void *, void *))func_L06_003525E0)(m, v);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357CD8 */

/* localdecomp:start func_L06_00357D58 */
extern int func_L01_004561B8(u8 *);
extern void func_L06_00351930(u8 *, u8 *, int, int, int);
extern int func_L06_00352810(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, int, int);

int func_L06_00357D58(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (func_L01_004561B8(moby)) {
        func_L06_00351930(moby, vars, 15, 0, 10);
        *(int *)(vars + 816) = 20;
    }
    func_L06_00352810(moby, vars);
    if (*(int *)(vars + 860) == 0) {
        func_L01_004450F0(moby, 27, -1);
        func_L06_00351930(moby, vars, 14, 0, 10);
        *(int *)(vars + 816) = 30;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357D58 */

/* localdecomp:start func_L06_00357DF8 */
extern s32 func_0038CAD0(s32 *a0);
extern void func_L01_004450F0(u8 *, s32, s32);

s32 func_L06_00357DF8(u8 *obj) {
    s32 ret;
    if (((s32 (*)(u8 *))func_0038CAD0)(*(u8 **)(obj + 104) + 816) == 0) {
        ret = 0;
    } else {
        func_L01_004450F0(obj, 28, -1);
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L06_00357DF8 */

/* localdecomp:start func_L06_00357E48 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L06_00351930(u8 *, u8 *, int, int, int);
extern int func_L01_004561B8(u8 *);

s32 func_L06_00357E48(u8 *arg0) {
    u8 *s = *(u8 **)(arg0 + 104);

    if (((s32 (*)(void *))func_L01_004561B8)(arg0)) {
        ((void (*)(void *, void *, s32, s32, s32))func_L06_00351930)(arg0, s, 16, 0, 10);
    }
    if (arg0[96] & 2) {
        ((void (*)(void *, s32, s32))func_L01_004450F0)(arg0, 29, -1);
        *(s32 *)(s + 816) = 0;
        *(s32 *)(s + 804) = 300;
        ((void (*)(void *, void *, s32, s32, s32))func_L06_00351930)(arg0, s, 2, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357E48 */

INCLUDE_ASM("asm/levels", func_L06_00357EE0);

INCLUDE_ASM("asm/levels", func_L06_00357FB8);

INCLUDE_ASM("asm/levels", func_L06_00358098);

INCLUDE_ASM("asm/levels", func_L06_003584D0);

INCLUDE_ASM("asm/levels", func_L06_00358630);

INCLUDE_ASM("asm/levels", func_L06_00358938);

INCLUDE_ASM("asm/levels", func_L06_00358A70);

INCLUDE_ASM("asm/levels", func_L06_00358FF0);

/* localdecomp:start func_L06_00359650 */
typedef int u128_t __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32 a, s32 b);
extern f32 func_0038CEA8(f32 *v);
extern void func_L01_004450F0(u8 *m, s32 a, s32 b);
extern f32 func_00382538(void);
extern f32 func_0038D160(f32 a, f32 b);
extern f32 func_0038CED8(f32 *v);
extern void func_0038D308(u8 *a, u8 *b);
extern void func_0038CC88(void *d, void *s, s32 n);
extern void func_003C7C38(u8 *m);
extern s32 D_L06_001DD3D0;

u8 *func_L06_00359650(u8 *a0, u8 *a1, f32 *a2, s32 a3, f32 f) {
    u8 *m;
    u8 *v;

    m = func_003C24B0(5959, 128);
    if (m != 0) {
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        *(u8 **)(m + 184) = a0;
        m[32] = 0;
        v = *(u8 **)(m + 104);
        *(long *)(m + 56) = *(long *)(a0 + 56);
        *(u128_t *)(m + 16) = *(u128_t *)a1;
        *(u128_t *)(v + 16) = *(u128_t *)a2;
        *(f32 *)(v + 8) = func_0038CEA8(a2);
        *(f32 *)(v + 4) = f;
        if (a3 != 0) {
            *(f32 *)(v + 4) = -f;
        }
        func_L01_004450F0(m, 1, -1);
        *(s32 *)v = 100;
        *(f32 *)(m + 240) = func_00382538();
        *(f32 *)(m + 248) = func_0038D160(a2[0], a2[1]);
        *(f32 *)(m + 244) = -func_0038D160(func_0038CED8(a2), a2[2]);
        func_0038D308(m + 192, m + 240);
        *(f32 *)(m + 44) = *(f32 *)(*(u8 **)(m + 36) + 36) + *(f32 *)(*(u8 **)(m + 36) + 36);
        func_0038CC88(v + 48, &D_L06_001DD3D0, 16);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L06_00359650 */

INCLUDE_ASM("asm/levels", func_L06_003597A0);

INCLUDE_ASM("asm/levels", func_L06_00359A88);

INCLUDE_ASM("asm/levels", func_L06_00359B60);

/* localdecomp:start func_L06_00359C38 */
extern s32 func_0038DBD8(s32, s32, f32);
void func_L06_00359C38(u8 *a0, s32 a1, s32 a2, f32 f) {
    s32 *p = (s32 *)(a0 + 64);
    s32 i;
    for (i = 3; i >= 0; i--) {
        *p++ = func_0038DBD8(a1, a2, f);
    }
}
/* localdecomp:end func_L06_00359C38 */

INCLUDE_ASM("asm/levels", func_L06_00359CA8);

INCLUDE_ASM("asm/levels", func_L06_00359CD0);
