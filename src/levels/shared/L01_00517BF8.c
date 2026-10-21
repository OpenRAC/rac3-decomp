#include "common.h"

/* localdecomp:start func_L01_00517BF8 */
typedef struct S_513C08o S_513C08o;
typedef struct {
    u8 pad0[0x10];
    s32 (*fn10)(S_513C08o *, s32);
} S_513C08vt;
struct S_513C08o {
    u8 pad0[8];
    S_513C08vt *vt;
};

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
} S_513C08g;

extern S_513C08g D_L01_001E15E0[];
extern s32 D_L01_001DC210;
extern S_513C08g *func_003E6C08(void);
extern s32 func_003E6DE8(S_513C08g *);
extern S_513C08o *func_003E6378(s32, s32);
extern void func_003F0B70(S_513C08o *, s32, s32);

s32 func_L01_00517BF8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    S_513C08g *g;
    S_513C08g *x;
    S_513C08o *o;
    s32 ret = 0;

    g = D_L01_001E15E0;
    if (g->w4 != 0) {
        x = g;
    } else {
        x = func_003E6C08();
    }
    o = func_003E6378(func_003E6DE8(x), a0);
    if (o == 0 || o->vt->fn10(o, D_L01_001DC210) == 0) {
        o = 0;
    }
    if (o != 0) {
        ret = 1;
        func_003F0B70(o, 4, a1);
        func_003F0B70(o, 8, a3);
        func_003F0B70(o, 16, a4);
        func_003F0B70(o, 32, a2);
        func_003F0B70(o, 64, a5);
    }
    return ret;
}
/* localdecomp:end func_L01_00517BF8 */

/* localdecomp:start func_L01_00517D18 */
extern S_513C08o *func_003E6378(s32, s32);
extern s32 func_003E6DE8(S_513C08g *);
extern S_513C08g *func_003E6C08(void);
extern S_513C08g D_L01_001E15E0[];
typedef struct UnkObj513D28 UnkObj513D28;

typedef struct {
    void *pad0;
    void *pad4;
    void *pad8;
    void *padC;
    int (*isA)(UnkObj513D28 *, int);
} UnkVtbl513D28;

struct UnkObj513D28 {
    int pad0;
    int pad4;
    UnkVtbl513D28 *vtbl;
};

typedef struct {
    int w0;
    int w4;
} UnkMgr513D28;

extern int D_L01_001DC210;

extern void func_003F0990(UnkObj513D28 *);

int func_L01_00517D18(int id) {
    UnkMgr513D28 *mgr;
    UnkObj513D28 *obj;
    UnkObj513D28 *cast;
    int ret = 0;
    if (((UnkMgr513D28 *)&D_L01_001E15E0)->w4 != 0) {
        mgr = ((UnkMgr513D28 *)&D_L01_001E15E0);
    } else {
        mgr = ((UnkMgr513D28 * (*)(UnkMgr513D28 *))func_003E6C08)(((UnkMgr513D28 *)&D_L01_001E15E0));
    }
    obj = ((UnkObj513D28 * (*)(void *, int))func_003E6378)(((void * (*)(UnkMgr513D28 *))func_003E6DE8)(mgr), id);
    cast = (obj != 0 && obj->vtbl->isA(obj, D_L01_001DC210)) ? obj : 0;
    if (cast != 0) {
        func_003F0990(cast);
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L01_00517D18 */

/* localdecomp:start func_L01_00517DB8 */
extern S_513C08g *func_003E6C08(void);
extern S_513C08o *func_003E6378(s32, s32);
extern s32 func_003E6DE8(S_513C08g *);
extern S_513C08g D_L01_001E15E0[];
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_00513DC8;

extern s32 D_L01_001DC210;
extern void func_003F0B00(void *, f32);
extern void func_003F0B20(void *, s32);
extern void func_003F0B48(void *, s32);

s32 func_L01_00517DB8(s32 a0, s32 a1, s32 a2, f32 f) {
    S_00513DC8 *q = &(*(S_00513DC8 *)&D_L01_001E15E0);
    void *base;
    void *p;
    s32 r = 0;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = ((void * (*)())func_003E6C08)();
    }
    p = (void *)((s32 (*)())func_003E6378)(((s32 (*)(void *))func_003E6DE8)(base), a0);
    if (p == 0 || (*(s32 (**)(void *, s32))(*(u8 **)((u8 *)p + 8) + 0x10))(p, D_L01_001DC210) == 0) {
        p = 0;
    }
    if (p != 0) {
        func_003F0B00(p, f);
        r = 1;
        func_003F0B20(p, a1);
        func_003F0B48(p, a2);
    }
    return r;
}
/* localdecomp:end func_L01_00517DB8 */
