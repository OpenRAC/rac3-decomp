#include "vu0.h"
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

/* localdecomp:start func_L06_003574E0 */
extern void func_L06_00352E08(s32, u8 *);
s32 func_L06_003574E0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        func_L06_00351930(a0, v, 0x12, 0, 10);
        func_L06_00352E08((s32)a0, v);
        *(s32 *)(v + 0x384) = 0;
        qzero(v + 0x110);
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L06_00351930(a0, v, 2, 0, 10);
        *(f32 *)(v + 0x34C) = 0.0f;
        if (*(f32 *)(v + 0x328) == *(f32 *)(v + 0x34C)) {
            func_L01_004450F0(a0, 1, -1);
        } else {
            func_L01_004450F0(a0, 0x18, -1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003574E0 */

/* localdecomp:start func_L06_003575B8 */
s32 func_L06_003575B8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        qzero(v + 0x110);
    }
    func_L01_004450F0(a0, 3, -1);
    func_L06_00351930(a0, v, 7, 0, 10);
    return 1;
}
/* localdecomp:end func_L06_003575B8 */

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

/* localdecomp:start func_L06_003576B8 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L06_00351930(u8 *, u8 *, s32, s32, s32);
extern int func_L06_00350FD0(u8 *, u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

s32 func_L06_003576B8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    if (*(s32 *)(vars + 900) != 0) {
        func_L01_004450F0(moby, 0x12, -1);
        func_L06_00351930(moby, vars, 10, 0, 10);
        return 1;
    }
    if (func_L01_004561B8(moby)) {
        func_L06_00351930(moby, vars, 9, 0, 10);
    }
    func_L06_00350FD0(moby, vars, vars + 544);
    if (moby[96] & 2) {
        *(s32 *)(vars + 900) = 1;
        func_L01_004450F0(moby, 0x12, -1);
        func_L06_00351930(moby, vars, 10, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_003576B8 */

/* localdecomp:start func_L06_00357768 */
extern s32 func_L06_00351718(u8 *, u8 *);
extern void func_L06_00351728(u8 *, u8 *, void *, s32 *, f32 *);
extern s32 func_L06_00351508(u8 *, u8 *, s32, f32);
extern void func_L06_00355610(u8 *, u8 *, s32, void *);
extern void func_L06_003552F8(u8 *, u8 *, s32, void *);
extern f32 func_0038CF38(void *, void *);
extern f32 func_003824E0(f32, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00357768;
s32 func_L06_00357768(u8 *a0, u8 *a1) {
    V_00357768 pos;
    s32 n;
    f32 t;
    f32 d;
    if (func_L06_00351718(a0, a1)) {
        d = func_0038CF38(a0 + 0x10, a1 + 0x220);
        func_L06_00351728(a0, a1, &pos, &n, &t);
        if (func_L06_00351508(a0, a1, 0, d) && func_003824E0(0.0f, 1.0f) < 0.5f) {
            func_L06_00355610(a0, a1, n, &pos);
        } else {
            func_L06_003552F8(a0, a1, n, &pos);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357768 */

/* localdecomp:start func_L06_00357850 */
extern s32 func_L06_00357768(u8 *, u8 *);
extern s32 func_0038CAD0(s32 *a0);
extern s32 func_L06_003523F0(u8 *, u8 *);
extern void func_L06_003523E0(u8 *, u8 *);
s32 func_L06_00357850(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L06_00357768(a0, v)) {
        return 3;
    }
    if (*(s32 *)(v + 0x384) == 0) {
        *(s32 *)(v + 0x35C) = 0;
        func_L01_004450F0(a0, 0x11, -1);
        return 2;
    }
    if (func_L01_004561B8(a0)) {
        if ((*(u8 **)(v + 0x260))[0x43] == 0xB) {
            func_L06_00350FD0(a0, v, v + 0x220);
            func_L01_004450F0(a0, 0x13, -1);
            return 2;
        }
        if (func_L06_003523F0(a0, v)) {
            func_L06_003523E0(a0, v);
        } else {
            *(s32 *)(v + 0x35C) = 0;
        }
    }
    if (func_L06_00350FD0(a0, v, v + 0x220)) {
        if (((s32 (*)(void *))func_0038CAD0)(v + 0x330) && func_L06_003523F0(a0, v)) {
            func_L01_004450F0(a0, 0x13, -1);
            return 1;
        }
    } else {
        ((s32 (*)(void *))func_0038CAD0)(v + 0x330);
    }
    return 0;
}
/* localdecomp:end func_L06_00357850 */

/* localdecomp:start func_L06_00357968 */
extern s32 func_L06_00357768(u8 *, u8 *);
extern void func_L06_00351A08(u8 *, u8 *, s32);
extern void func_L06_00352370(u8 *, u8 *);
extern s32 func_L06_00352500(u8 *, u8 *);
extern void func_L06_003523B0(u8 *, u8 *);
s32 func_L06_00357968(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L06_00357768(a0, v)) {
        return 1;
    }
    if (func_L01_004561B8(a0)) {
        if ((*(u8 **)(v + 0x260))[0x43] == 0xB) {
            func_L06_00351A08(a0, v, 10);
        } else {
            func_L06_00351930(a0, v, 0xB, 6, 10);
            func_L06_00352370(a0, v);
        }
    }
    func_L06_00350FD0(a0, v, v + 0x220);
    func_L06_00352500(a0, v);
    if (*(s32 *)(v + 0x35C) < 0) {
        func_L06_003523B0(a0, v);
        func_L01_004450F0(a0, 0x14, -1);
        func_L06_00351930(a0, v, 10, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357968 */

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

/* localdecomp:start func_L06_00357AD0 */
extern s32 func_L06_00351220(u8 *, u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

s32 func_L06_00357AD0(u8 *a0) {
    u8 *obj = a0;
    u8 *parts = *(u8 **)(obj + 104);
    if (*(s32 *)(parts + 900) == 0) {
        func_L01_004450F0(a0, 22, -1);
        return 1;
    }
    if (func_L06_00351220(obj, parts) != 0) {
        func_L01_004450F0(obj, 22, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357AD0 */

/* localdecomp:start func_L06_00357B28 */
extern f32 func_L01_0040E570(void *, void *);
s32 func_L06_00357B28(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        if (*(s16 *)(v + 0x23C) != 0 && func_L01_0040E570(v + 0x220, a0 + 0x10) < 225.0f) {
            func_L01_004450F0(a0, 0x12, -1);
            return 2;
        }
        func_L06_00351930(a0, v, 0xD, 0, 10);
    }
    func_L06_00350FD0(a0, v, v + 0x220);
    if (a0[0x60] & 2) {
        *(s32 *)(v + 0x384) = 0;
        func_L01_004450F0(a0, 0x19, -1);
        func_L06_00351930(a0, v, 0xE, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357B28 */

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

/* localdecomp:start func_L06_00357EE0 */
extern void func_L06_00352E08(s32, u8 *);
s32 func_L06_00357EE0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        func_L06_00351930(a0, v, 0x12, 0, 10);
        func_L06_00352E08((s32)a0, v);
        *(s32 *)(v + 0x384) = 0;
    }
    func_L06_00351220(a0, v);
    if (a0[0x60] & 2) {
        func_L06_00351930(a0, v, 2, 0, 10);
        if (*(f32 *)(v + 0x328) <= 0.0f) {
            func_L01_004450F0(a0, 1, -1);
        } else {
            func_L01_004450F0(a0, 0x18, -1);
        }
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00357EE0 */

/* localdecomp:start func_L06_00357FB8 */
extern void func_L06_00352E08(s32, u8 *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L06_00352110(u8 *, u8 *);
typedef struct { u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 w28; s32 w2C; } S_00357FB8;
extern S_00357FB8 D_L06_001E1700;
s32 func_L06_00357FB8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0)) {
        func_L06_00351930(a0, v, 0x13, 0, 10);
        func_L06_00352E08((s32)a0, v);
        *(s32 *)(v + 0x384) = 0;
        qzero(v + 0x110);
    }
    func_L06_00351220(a0, v);
    if (func_L01_0044E1B8(a0, 21.0f) || func_L01_0044E1B8(a0, 53.0f)) {
        D_L06_001E1700.f20 = 0.1f;
        D_L06_001E1700.w28 = 25;
        D_L06_001E1700.w2C = 0;
    }
    if (a0[0x60] & 2) {
        func_L06_00352110(a0, v);
        return 5;
    }
    return 0;
}
/* localdecomp:end func_L06_00357FB8 */

INCLUDE_ASM("asm/levels", func_L06_00358098);

/* localdecomp:start func_L06_003584D0 */
extern u8 *func_003C24B0(s32 a, s32 b);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003C7C38(u8 *m);
extern u8 D_001A30B0[];
u8 *func_L06_003584D0(u8 *a0, void *a1, void *a2, void *a3, s32 t0, s32 t1, f32 f) {
    u8 *m;
    u8 *v;
    u8 *e;
    m = func_003C24B0(0x169E, 0x80);
    if (m != 0) {
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        m[0x20] = 0;
        v = *(u8 **)(m + 0x68);
        *(long *)(m + 0x38) = *(long *)(a0 + 0x38);
        *(vu0_q *)(m + 0x10) = *(vu0_q *)a2;
        *(vu0_q *)(m + 0xF0) = *(vu0_q *)a3;
        *(u8 **)(m + 0xB8) = a0;
        *(vu0_q *)v = *(vu0_q *)a1;
        *(u8 **)(v + 0x10) = a0;
        *(f32 *)(v + 0x14) = f;
        *(f32 *)(v + 0x20) = 0.15f;
        *(s32 *)(v + 0x2C) = t0;
        *(s32 *)(v + 0x34) = t1;
        *(f32 *)(m + 0x2C) = *(f32 *)(*(u8 **)(m + 0x24) + 0x24) + *(f32 *)(*(u8 **)(m + 0x24) + 0x24);
        if (*(s32 *)(v + 0x30) == -1 || (e = D_001A30B0 + *(s32 *)(v + 0x30) * 0x80, *(u8 **)(e + 0xDC) != m) ||
            e[0xD0] == 0) {
            *(s32 *)(v + 0x30) = func_003A52A0(0, 4, m);
        }
        *(s32 *)(v + 0x24) = 0;
        func_003C7C38(m);
    }
    *(s32 *)(m + 0x98) = 0;
    return m;
}
/* localdecomp:end func_L06_003584D0 */

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
__asm__(".extern D_L06_001DD3D0, 4");

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

/* localdecomp:start func_L06_00359A88 */
extern f32 func_003824E0(f32, f32);
extern void func_L01_0046E078(void *, void *, void *, void *, s32);
void func_L06_00359A88(u8 *a0, u8 *a1) {
    vu0_v4 d;
    vu0_v4 v;
    v.x = func_003824E0(-1.0f, -0.9f) * *(f32 *)(a1 + 8);
    v.y = func_003824E0(-0.05f, 0.05f) * *(f32 *)(a1 + 8);
    v.z = func_003824E0(-0.05f, 0.05f) * *(f32 *)(a1 + 8);
    vec_sub_ba(&d, a0 + 0x10, a1 + 0x10);
    func_L01_0046E078(a0, &d, &v, a1 + 0x30, 1);
}
/* localdecomp:end func_L06_00359A88 */

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

/* localdecomp:start func_L06_00359CA8 */
/* from rac4-decomp's func_L05_004D6808, renamed */
void func_L06_00359CA8(s32 arg0, s32 arg1) {
    u32 var_a0;
    s32 var_v0;
    var_a0 = (u32)(arg0 + 0x4C);
    var_v0 = 3;
    do {
        *(s32 *)var_a0 = arg1;
        var_v0 -= 1;
        var_a0 -= 4;
    } while (var_v0 >= 0);
}
/* localdecomp:end func_L06_00359CA8 */

INCLUDE_ASM("asm/levels", func_L06_00359CD0);
