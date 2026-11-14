#include "common.h"

/* localdecomp:start func_L39_0050C4B0 */
extern u8 D_L39_0046F3B8[];
extern void *func_L39_004F7590(s32);
extern void func_L39_005076E0(void *arg0, s32 arg1);
extern void func_L39_004F73F0(void *);
extern void func_L39_0050C768(void);

void *func_L39_0050C4B0(void *obj, s32 arg1, s32 arg2, s32 arg3) {
    if (obj == 0) {
        obj = func_L39_004F7590(0x30);
        if (obj == 0) {
            return obj;
        }
    }
    func_L39_005076E0(obj, arg1);
    func_L39_004F73F0((u8 *)obj + 0x20);
    *(void **)((u8 *)obj + 0x1C) = (void *)func_L39_0050C768;
    *(u8 **)((u8 *)obj + 0xC) = D_L39_0046F3B8;
    *(s32 *)((u8 *)obj + 0x14) = arg2;
    *(s32 *)((u8 *)obj + 0x18) = arg3;
    *(s32 *)((u8 *)obj + 0x2C) = 0;
    return obj;
}
/* localdecomp:end func_L39_0050C4B0 */

/* localdecomp:start func_L39_0050C550 */
extern void func_L39_004F7410(void *);

void func_L39_0050C550(u8 *a0) {
    func_L39_004F7410(a0 + 0x20);
}
/* localdecomp:end func_L39_0050C550 */

/* localdecomp:start func_L39_0050C568 */
typedef struct {
    u8 pad[0x14];
    void *(*fn14)(void *);
} V_0050C568;

typedef struct {
    u8 pad[0x10];
    V_0050C568 *vt;
    u8 pad14[0xC];
    void *obj;
} S_0050C568;

extern void *func_L39_00508278(void *);

void *func_L39_0050C568(S_0050C568 *a0) {
    void *r = a0->vt->fn14(a0->obj);
    if (r) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_0050C568 */

/* localdecomp:start func_L39_0050C5A8 */
extern int func_L39_00508128(void *, void *, int, int, int, int, int);

int func_L39_0050C5A8(char *obj, int a, int b, int c) {
    int r = func_L39_00508128(obj, obj + 0x10, 1, a, *(int *)(obj + 0x2C), b, c);
    if (r == 0) {
        *(char **)(obj + 8) = obj + 0x10;
    }
    return r;
}
/* localdecomp:end func_L39_0050C5A8 */

/* localdecomp:start func_L39_0050C5F8 */
typedef struct {
    s32 pad0[2];
    void *f8;
    s32 padC;
    s32 f10[7];
    s32 f2C;
} S_50C5F8;

extern int func_L39_00508128(void *, void *, int, int, int, int, int);

int func_L39_0050C5F8(S_50C5F8 *obj, int a, int b, int c) {
    int r = func_L39_00508128(obj, &obj->f10, 0, a, obj->f2C, b, c);
    if (r == 0) {
        obj->f8 = &obj->f10;
    }
    return r;
}
/* localdecomp:end func_L39_0050C5F8 */

/* localdecomp:start func_L39_0050C648 */
typedef struct {
    u8 pad[0x8];
    void *(*fn8)(void *, s32, s32, s32, s32, s32, s32);
} V_0050C648;

typedef struct {
    u8 pad[0x10];
    V_0050C648 *vt;
    u8 pad14[0xC];
    void *obj;
} S_0050C648;

extern void *func_L39_00508278(void *);

void *func_L39_0050C648(S_0050C648 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    void *r = a0->vt->fn8(a0->obj, a1, a2, a3, a4, a5, a7);
    if (r) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_0050C648 */

/* localdecomp:start func_L39_0050C690 */
typedef struct {
    u8 pad[0x8];
    void *(*fn8)(void *, s32, s32, s32, s32, s32, s32);
} V_0050C690;

typedef struct {
    u8 pad[0x10];
    V_0050C690 *vt;
    u8 pad14[0xC];
    void *obj;
} S_0050C690;

extern void *func_L39_00508278(void *);

void *func_L39_0050C690(S_0050C690 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    void *r = a0->vt->fn8(a0->obj, a1, a2, a3, a4, a5, a7);
    if (r) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_0050C690 */

/* localdecomp:start func_L39_0050C6D8 */
typedef struct {
    u8 pad[0xC];
    void *(*fnC)(void *, s32, s32, s32, s32);
} V_0050C6D8;

typedef struct {
    u8 pad[0x10];
    V_0050C6D8 *vt;
    u8 pad14[0xC];
    void *obj;
} S_0050C6D8;

extern void *func_L39_00508278(void *);

void *func_L39_0050C6D8(S_0050C6D8 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    void *r = a0->vt->fnC(a0->obj, a1, a2, a3, a5);
    if (r) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_0050C6D8 */

/* localdecomp:start func_L39_0050C720 */
typedef struct {
    u8 pad[0xC];
    void *(*fnC)(void *, s32, s32, s32, s32);
} V_0050C720;

typedef struct {
    u8 pad[0x10];
    V_0050C720 *vt;
    u8 pad14[0xC];
    void *obj;
} S_0050C720;

extern void *func_L39_00508278(void *);

void *func_L39_0050C720(S_0050C720 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    void *r = a0->vt->fnC(a0->obj, a1, a2, a3, a5);
    if (r) {
        return func_L39_00508278(r);
    }
    return r;
}
/* localdecomp:end func_L39_0050C720 */

INCLUDE_ASM("asm/levels", func_L39_0050C768);

/* localdecomp:start func_L39_0050C878 */
extern void *func_L39_004F7590(s32);
extern void func_L39_00517090(void *, void *, void *);
extern u8 D_L39_0046F3E0[];
extern u8 D_L39_0046F3D8[];

void *func_L39_0050C878(void *obj, void *arg)
{
    if (obj == 0) {
        obj = func_L39_004F7590(0x44);
        if (obj == 0) {
            return obj;
        }
    }
    func_L39_00517090(obj, arg, D_L39_0046F3E0);
    *(u8 **)((u8 *)obj + 0x40) = D_L39_0046F3D8;
    return obj;
}
/* localdecomp:end func_L39_0050C878 */

/* localdecomp:start func_L39_0050C8E8 */
typedef struct S_0050C8E8 { s32 p0, p4, p8, pC, p10, p14, p18, p1C, p20, p24, p28, p2C; u8 *buf; u32 len; u32 tail; } S_0050C8E8;
extern void func_L39_004F7538(u8 *, u8 *, s32);
extern s32 func_L39_00516FD8(void *, u8 *, s32, s32);

s32 func_L39_0050C8E8(S_0050C8E8 *p, void *a1, s32 a2) {
    u32 len = p->len;
    u32 tail = p->tail;
    u32 k;
    u32 pad;
    s32 r;
    u8 tmp;

    if (len < tail + 3) {
        return 0x20D;
    }
    pad = len - tail - 3;
    func_L39_004F7538(p->buf + pad + 3, p->buf, tail);
    p->buf[0] = 0;
    p->buf[1] = 2;
    for (k = 2; k < pad + 2; k++) {
        do {
            r = func_L39_00516FD8(a1, &tmp, 1, a2);
            if (r != 0) {
                return r;
            }
        } while (tmp == 0);
        p->buf[k] = tmp;
    }
    p->buf[pad + 2] = 0;
    return 0;
}
/* localdecomp:end func_L39_0050C8E8 */

INCLUDE_ASM("asm/levels", func_L39_0050C9E8);

LINKER_REMNANT("asm/levels", func_L39_0050CA78);

INCLUDE_ASM("asm/levels", func_L39_0050CA80);

/* localdecomp:start func_L39_0050CC00 */
extern s32 func_L39_00515DA8(s32, void *, s32, s32 *);
extern s32 func_L39_0050CC90(void *, void *, void *, s32, void *);

s32 func_L39_0050CC00(void *a0, void *a1, void *a2, s32 a3, void *a4) {
    s32 out;
    if (a4 == 0) {
        out = a3;
    } else if (func_L39_00515DA8(*(s32 *)a0, a4, a3, &out) != 0) {
        return 0x803;
    }
    return func_L39_0050CC90(a0, a1, a2, out, a4);
}
/* localdecomp:end func_L39_0050CC00 */

INCLUDE_ASM("asm/levels", func_L39_0050CC90);
