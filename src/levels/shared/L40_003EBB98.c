#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct { f32 x, y, z, w; } V4_003EBCD8;
typedef struct { u8 pad[0x88]; s32 arr[1]; } T_003EBCD8;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003EBEA0;

typedef struct {
    u8 pad00[0x30];
    f32 f30;
    u8 pad34[0x114];
    s32 w148;
    u8 pad14C[0x14];
    u8 b160[0xC0];
    V_003EBEA0 v220;
    u8 *p230;
    s16 s234;
    u8 pad236[0x1A];
    s32 w250;
    u8 pad254[2];
    u8 b256[2];
    s32 w258;
    u8 pad25C[4];
    V_003EBEA0 v260;
    V_003EBEA0 v270;
    V_003EBEA0 v280;
    u8 pad290[0x14];
    s32 w2A4;
    u8 pad2A8[4];
    s32 w2AC;
    u8 pad2B0[8];
    s32 w2B8;
    f32 f2BC;
    V_003EBEA0 v2C0;
    f32 f2D0;
    f32 f2D4;
    f32 f2D8;
    s32 w2DC;
} Vars_003EC320;

/* localdecomp:start func_L40_003EBB98 */
typedef struct {
    s32 f0;
    u8 pad4[24];
    s32 f28;
    u8 pad32[17];
    u8 f49;
    u8 pad50[18];
} S_003EB740;
extern S_003EB740 D_L40_0033F2E0[];
s32 func_L40_003EBB98(s32 id) {
    s32 i;
    for (i = 0; i < 50; i++) {
        if (D_L40_0033F2E0[i].f49 == 1 && D_L40_0033F2E0[i].f28 == id) {
            return D_L40_0033F2E0[i].f0;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_003EBB98 */

/* localdecomp:start func_L40_003EBBE0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003EBBE0;
typedef struct {
    f32 x, y, z, w;
    s32 a1;
    s32 a3;
    s32 index;
} Msg_003EBBE0;
extern u8 *D_L40_0024845C[] __attribute__((section(".sdata")));
extern s32 D_001A5DF8[];
extern s32 func_L40_003EBB98(s32 id);
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_00197498(s32 n);

s32 func_L40_003EBBE0(V_003EBBE0 *pos, s32 a1, s32 index, s32 a3) {
    V_003EBBE0 p = *pos;
    s32 r;
    u8 *msg;
    s32 uid;
    s32 n;
    Msg_003EBBE0 *q;

    r = func_L40_003EBB98((s32)(D_L40_0024845C[0] + (index << 8)));
    if (r != -1) {
        return r;
    }
    msg = func_L39_0066C2B8();
    if (msg == 0) {
        return -2;
    }
    uid = func_00197498(2);
    n = func_L39_0066C280(0, uid, D_001A5DF8[0] + 500, 0x109A, msg);
    q = (Msg_003EBBE0 *)(msg + n);
    q->x = p.x;
    q->y = p.y;
    q->z = p.z;
    q->w = p.w;
    q->a1 = a1;
    q->a3 = a3;
    q->index = index;
    *(s32 *)msg = n + 0x1C;
    return uid;
}
/* localdecomp:end func_L40_003EBBE0 */

/* localdecomp:start func_L40_003EBCD8 */
__asm__(".extern D_L40_00241120, 16");
extern s32 *D_L40_00241120;

extern T_003EBCD8 *D_L40_0035746C[];
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_0038CB78(void *, s32, s32);
extern void func_003C7C38(u8 *m);
extern void func_L40_003D3D80(u8 *m, s32 cls);
extern void func_L40_00413158(u8 *m, s32 cls);

u8 *func_L40_003EBCD8(s32 a0, s32 a1, u8 *msg) {
    s32 *h = (s32 *)(msg + 8);
    f32 *q = (f32 *)(msg + 0x18);
    u8 *m;
    u8 *v;
    s32 team;
    s32 *mode;

    m = func_L40_0053F570(0x109A, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), *(s32 *)(msg + 0x30));
    if (m != 0) {
        u8 *p = *(u8 **)(m + 0x24);
        *(u16 *)(m + 0x34) |= 0x20;
        *(u16 *)(m + 0x34) &= 0xFFBE;
        *(u16 *)(m + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(m + 0x98) = *(s32 *)(p + 0x10);
        func_0038CB78(*(u8 **)(m + 0x68), 0, 0x2E0);
        *(u8 *)(m + 0x30) = 0x7F;
        *(u16 *)(m + 0x32) = 0x7F;
        v = *(u8 **)(m + 0x68);
        *(f32 *)(m + 0x10) = *(f32 *)(msg + 0x18);
        *(f32 *)(m + 0x14) = q[1];
        *(f32 *)(m + 0x18) = q[2];
        *(f32 *)(m + 0x1C) = q[3];
        team = *(s32 *)(msg + 0x28);
        *(s32 *)(v + 0x2B8) = team;
        *(s32 *)(v + 0x2AC) = *(s32 *)(msg + 0x2C);
        *(u8 **)(v + 0x1C) = v + 0x70;
        *(u8 **)(v + 0xC) = v + 0x220;
        *(u8 **)(v + 0x0) = v + 0x30;
        *(u8 **)(v + 0x10) = v + 0x160;
        *(f32 *)(v + 0x244) = 35.0f;
        *(f32 *)(v + 0x24C) = 32.0f;
        *(s32 *)(v + 0xA8) |= 0x100;
        *(u8 *)(v + 0x3E) = 1;
        *(s32 *)(v + 0x240) = -1;
        *(s32 *)(v + 0x248) = -1;
        if (team != -1) {
            *(s32 *)(v + 0x2AC) = D_L40_0035746C[0]->arr[team];
        }
        mode = D_L40_00241120;
        if (*mode >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        if (*(s32 *)(v + 0x2AC) == 0) {
            *(u8 *)(m + 0xBE) = (*(u8 *)(m + 0xBE) | 0x10) & 0xF7;
        } else if (*(s32 *)(v + 0x2AC) == 1) {
            *(u8 *)(m + 0xBE) = (*(u8 *)(m + 0xBE) | 0x8) & 0xEF;
        } else {
            *(u8 *)(m + 0xBE) &= 0xE7;
        }
        func_L40_003D3D80(m, 0x109A);
        func_L40_00413158(m, 0x109A);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L40_003EBCD8 */

/* localdecomp:start func_L40_003EBEA0 */
extern u8 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 D_001A5DF8[];
extern s32 func_L40_0053E760(s32 uid, void *pos, s32 a2, s32 a3);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L40_0053E1A8(u8 *obj, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6);
extern u8 *func_L39_0061D1D8(s32 id);


void func_L40_003EBEA0(u8 *obj) {
    u8 *net;
    u8 *v;
    s32 uid;
    s32 id;
    s32 found;
    f32 r;
    s32 a1;
    u8 *e;
    u8 *msg;
    V_003EBEA0 pos;

    if (obj == 0) {
        return;
    }
    uid = **(s32 **)(obj + 0x90);
    v = *(u8 **)(obj + 0x68);
    if ((*(s32 *)0x24112C & 8) != (((s32)obj >> 8) & 8)) {
        return;
    }
    id = -1;
    found = 0;
    if (*(s32 *)(v + 0x2B0) != -1) {
        if (func_L40_0053E760(*(s32 *)(v + 0x2B0), &pos, -1, 0) != 0) {
            if (func_0038CF38(obj + 0x10, &pos) < *(f32 *)(v + 0x244) * 3.5f) {
                id = *(s32 *)(v + 0x2B0);
                found = 1;
            }
            if (obj[0x20] == 1 && *(u16 *)(obj + 0x96) >= 0xFB) {
                found = 0;
            }
        }
        if (found != 0) {
            goto have;
        }
    }
    id = func_L40_0053E1A8(obj, *(s32 *)(v + 0x2AC), 0, 0, *(f32 *)(v + 0x244) * 3.0f, -1.0f, 3.0f);
have:
    if (id == -1) {
        return;
    }
    e = func_L39_0061D1D8(id);
    if (e != 0 && (e[3] & 0xF) == 0 && *(u8 **)(e + 0x2528) != 0) {
        if (*(s16 *)(*(u8 **)(*(u8 **)(e + 0x2528) + 0x2D0) + 0xAA) == 0x107E) {
            id = -1;
        }
    }
    if (id == -1) {
        return;
    }
    if (*(s32 *)(v + 0x2B0) == id) {
        return;
    }
    msg = func_L39_0066C2B8();
    if (msg != 0) {
        s32 n = func_L39_0066C280(1, uid, D_001A5DF8[0] + 500, id, msg);
        *(s32 *)(v + 0x2B0) = id;
        *(s32 *)msg = n;
    }
}
/* localdecomp:end func_L40_003EBEA0 */

/* localdecomp:start func_L40_003EC050 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003EC050;
typedef struct { u8 pad[0x128]; s32 w128; } G_003EC050;
extern G_003EC050 D_001A5CD0;
extern void func_L39_0066C470(void *);
extern s32 func_L40_0053E760(s32 uid, void *pos, s32 a2, s32 a3);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern s32 func_L40_0053F018(void *);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L40_003ED268(void *);
extern void func_L40_0053F6E0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern u8 *func_L39_0066C3C8(u8 *, void *);
extern f32 func_0038CF38(void *, void *);

void func_L40_003EC050(void *a, void *b) {
    u8 *m = b;
    u8 *v = *(u8 **)(m + 0x68);
    u8 *net = *(u8 **)(m + 0x90);
    u8 *n;
    s32 *e;
    s32 r;
    s32 t;
    V_003EC050 pos;

    if (v[0x3E] == 2) {
        func_L39_0066C470(a);
        func_L40_0053F6E0(m);
        func_L01_004450F0(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(m, 1);
        return;
    }
    for (n = *(u8 **)(net + 0x38); n != 0; ) {
        e = (s32 *)(n + 8);
        if (D_001A5CD0.w128 < e[2]) {
            n = *(u8 **)(n + 0x84);
            continue;
        }
        switch (e[0]) {
        case 1:
            r = func_L40_0053E760(e[3], &pos, -1, 0);
            if (r != 0) {
                func_L39_005F3488(3, 0, m, 0x109A);
                *(s32 *)(v + 0x230) = r;
                *(s32 *)(v + 0x2B4) = e[3];
            }
            break;
        case 2:
            if (func_L40_0053F018(m) == 0) {
                func_L01_003303B8(m + 0x10, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f,
                                  0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                                  0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            }
            func_L40_003ED268(m);
        func_L40_0053F6E0(m);
        func_L01_004450F0(m, 0x25, -1);
        *(s32 *)(m + 0x98) = 0;
        *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
        func_L39_005F2FF8(m, 1);
            return;
        }
        n = func_L39_0066C3C8(n, net + 0x38);
    }
    if (*(s32 *)(v + 0x2B4) != 0) {
        *(s16 *)(v + 0x234) = 0;
        t = func_L40_0053E760(*(s32 *)(v + 0x2B4), v + 0x220, *(s32 *)(v + 0x2AC), 0);
        *(s32 *)(v + 0x230) = t;
        if (t != 0 && func_0038CF38(m + 0x10, v + 0x220) <= *(f32 *)(v + 0x244) + 5.0f &&
            func_0038CF38(m + 0x10, v + 0x2C0) < *(f32 *)(v + 0x244) * 3.0f) {
            *(s16 *)(v + 0x234) = 1;
        }
    }
}
/* localdecomp:end func_L40_003EC050 */

/* localdecomp:start func_L40_003EC320 */
/* PAL port of the NTSC-U match src/us/levels/func_L40_003EBEC8.c; PAL scales its frame counts by (n * 5 + 2) / 6 */


extern u8 D_L40_00242930;
__asm__(".extern D_L40_00242930, 16");
extern f32 D_L40_00246D30;
__asm__(".extern D_L40_00246D30, 4");
extern s32 D_L40_00246D34;
__asm__(".extern D_L40_00246D34, 4");

extern s32 func_L40_003ECFA0(void *, u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L39_005F3488(s32, s32, void *, s32);
extern void func_L01_00451FE0(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_L01_004561B8(void *);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L40_003ED360(void *);
extern void func_L40_003ED820(void *);
extern s32 func_L01_0045A748(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L40_003ED308();
extern void func_L39_0061C258(void *);
extern void func_0038CB00(void *);

#define SPAWN_3303B8(p) ((u8 *(*)(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, \
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32))func_L01_003303B8)( \
    p, 0, 10, 4, 5, 5, 10, 0, 0.8f, 3.0f, 2.0f, 2.0f, \
    0, 1, 0, 0, 1, 0, 1, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0)

void func_L40_003EC320(u8 *obj) {
    Vars_003EC320 *v;
    s32 *net;
    s32 uid;
    s32 hit;
    u8 *q;
    s32 st;
    s32 t;
    u8 *r;
    f32 f;
    V_003EBEA0 tmp;
    V_003EBEA0 tmp2;

    if (obj == 0) {
        return;
    }
    v = *(Vars_003EC320 **)(obj + 0x68);
    net = *(s32 **)(obj + 0x90);
    uid = *net;
    if (v->w2B8 != -1) {
        v->w2AC = D_L40_0035746C[0]->arr[v->w2B8];
        net[6] = v->w2AC;
    }
    t = v->w2AC;
    if ((u32)t >= 2) {
        t = 0;
    }
    obj[0x7E] = ((obj[0x7E] | 0x80) & 0x8F) | (t << 4);
    if (func_L40_003ECFA0((void *)uid, obj) != 0) {
        goto range;
    }
    if ((u8)(obj[0x20] + 3) < 2) {
        goto range;
    }
    switch (obj[0x95]) {
    case 4:
        *(f32 *)(obj + 0x2C) = *(f32 *)(obj + 0x2C) + v->f2D4;
        if (v->f2D8 <= *(f32 *)(obj + 0x2C)) {
            func_L01_004450F0(obj, 1, 0);
            *(V_003EBEA0 *)&v->v2C0 = *(V_003EBEA0 *)(obj + 0x10);
        }
        *(f32 *)(obj + 0x18) = *(f32 *)(obj + 0x18) + 0.030000001f;
        break;
    case 0:
        if (v->s234 == 1) {
            if (obj[0x43] != 1) {
                func_003C3A10(obj, 1, 0, 8);
            }
            func_L01_004450F0(obj, 3, 2);
            goto sw2;
        }
        if (v->w258 != 0 && ((s32 (*)(void *))func_0038CB00)(v->b256) != 0) {
            func_L01_004450F0(obj, 2, 1);
            v->w258 = 0;
            if (v->w250 < 250) {
                v->w250 = (func_L39_005B43C8(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    case 1:
        if (v->s234 == 1) {
            func_L01_004450F0(obj, 3, 2);
            goto sw2;
        }
        if (v->w250 == 0) {
            func_L01_004450F0(obj, 1, 0);
        }
        goto sw2;
    case 2:
        break;
    case 3:
        hit = func_L01_00454370(obj, v->b160);
        if (v->f30 <= 0.0f && func_L40_0053F018(obj) != 0) {
            func_L40_003ED268(obj);
            if (func_L40_0053F018(obj) != 0) {
                r = SPAWN_3303B8(obj + 0x10);
            } else {
                r = SPAWN_3303B8(obj + 0x10);
            }
            if (r != 0) {
                *(s32 *)(r + 0xB8) = (s32)obj;
            }
            func_L40_0053F6E0(obj);
            func_L01_004450F0(obj, 0x25, -1);
            *(s32 *)(obj + 0x98) = 0;
            *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(obj, 1);
            return;
        }
        if ((hit & 2) != 0) {
            if (v->s234 == 1) {
                func_L01_004450F0(obj, 3, 2);
                goto sw2;
            }
            func_L01_004450F0(obj, 2, 1);
            v->w250 = (func_L39_005B43C8(0x244, 0x258) * 5 + 2) / 6;
        }
        break;
    }
sw2:
    st = obj[0x20];
    switch (st) {
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            f = func_003C3D30(obj + 0x10, 0, 0, 0.5f);
            v->f2D0 = *(f32 *)(obj + 0x18) - f - 0.5f;
        }
        v->f2BC = func_0038DAB8(v->f2BC, 0.008726646f);
        *(f32 *)(obj + 0x18) = v->v2C0.z + v->f2D0 * func_0038D0B0(v->f2BC);
        goto post;
    case 2:
        goto post;
    case 3:
        if (func_L01_004561B8(obj) != 0) {
            func_L01_0045BD78(obj, 0.018000001f, 0.38000003f, 0.010053097f, 0.25132743f);
            v->v270 = v->v220;
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ED360(obj);
        }
        func_L40_003ED820(obj);
        q = (u8 *)&v->v220;
        tmp = *(V_003EBEA0 *)q;
        if (func_0038CF38(&v->v280, &tmp) > 1.0f) {
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ED360(obj);
            v->w2A4 = 0;
        }
        v->v270 = v->v220;
        if (v->w2A4 >= 5) {
            v->v260 = v->v220;
            v->v280 = v->v220;
            func_L40_003ED360(obj);
            v->w2A4 = 0;
        }
        func_L01_0045A748(obj, &v->v260);
        v->w2DC = v->w2DC + 1;
        if (func_L40_0053F018(obj) != 0) {
            f = func_0038CF38(obj + 0x10, q);
            if (f <= 1.4f || v->v2C0.z + 6.0f <= *(f32 *)(obj + 0x18) || (D_L40_00246D34 * 5 + 2) / 6 < v->w2DC || v->w148 == 0) {
                r = SPAWN_3303B8(obj + 0x10);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F3488(4, 0, obj, 0x109A);
                func_L01_00451FE0(obj, 0x3F, &D_L40_00242930, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L40_0053F6E0(obj);
                func_L01_004450F0(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F2FF8(obj, 1);
                return;
            } else {
                tmp2 = *(V_003EBEA0 *)(obj + 0x10);
                tmp2.z = tmp2.z + 0.5f;
                if (v->p230 == 0) {
                    goto post;
                }
                if (*(s16 *)(v->p230 + 0xAA) != 0x107C && *(s16 *)(v->p230 + 0xAA) != 0x107E) {
                    goto post;
                }
                if (!(func_L01_0040E570(obj + 0x10, v->p230 + 0x10) < D_L40_00246D30)) {
                    goto post;
                }
                r = SPAWN_3303B8(obj + 0x10);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F3488(4, 0, obj, 0x109A);
                func_L01_00451FE0(obj, 0x3F, &D_L40_00242930, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L39_0061C258(obj);
                func_L40_0053F6E0(obj);
                func_L01_004450F0(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F2FF8(obj, 1);
                return;
            }
        } else {
            f = func_0038CF38(obj + 0x10, q);
            if (f <= 1.1f || v->v2C0.z + 6.0f <= *(f32 *)(obj + 0x18) || ((f32)D_L40_00246D34 * 1.5f * 5.0f + 2.0f) / 6.0f < (f32)v->w2DC) {
                r = SPAWN_3303B8(obj + 0x10);
                if (r != 0) {
                    *(s32 *)(r + 0xB8) = (s32)obj;
                }
                func_L39_005F3488(4, 0, obj, 0x109A);
                func_L01_00451FE0(obj, 0x3F, &D_L40_00242930, 3.0f, 7.0f, 4.0f, 7.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
                func_L40_0053F6E0(obj);
                func_L39_0066C470((void *)uid);
                func_L01_004450F0(obj, 0x25, -1);
                *(s32 *)(obj + 0x98) = 0;
                *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F2FF8(obj, 1);
                return;
            }
        }
        goto post;
    }
post:
    func_L40_003ED308(obj);
range:
    if (*(f32 *)(obj + 0x10) < 2.0f || 1021.0f < *(f32 *)(obj + 0x10) || *(f32 *)(obj + 0x14) < 2.0f || 1021.0f < *(f32 *)(obj + 0x14) ||
        *(f32 *)(obj + 0x18) < 2.0f || 1021.0f < *(f32 *)(obj + 0x18)) {
        func_L40_0053F6E0(obj);
        func_L39_0066C470((void *)uid);
        func_L01_004450F0(obj, 0x25, -1);
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(obj, 1);
    }
    return;
}
/* localdecomp:end func_L40_003EC320 */

/* localdecomp:start func_L40_003ECFA0 */
extern u8 D_L40_00249FC0[];
extern s32 func_L40_003ED0C8(void *obj);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_L01_004472C0(void *obj);
extern u8 *func_L01_00447490(void *obj, s32 a, s32 b);
extern u8 *func_L39_0061CEA0(void *a);
extern void func_L40_0048C560(void *obj, void *p, s32 a, s32 b, s32 c);
extern void func_L40_003EC050(void *a, void *b);

s32 func_L40_003ECFA0(void *ctx, u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *r;
    u8 *h;
    s32 flag;
    if (obj[0x20] == 0) {
        if (func_L40_003ED0C8(obj) != 0) {
            return 1;
        }
        *(u128_t *)(st + 0x2C0) = *(u128_t *)(obj + 0x10);
    }
    if (obj[0x31] != 0) {
        if (func_L01_0040E548(D_L40_00249FC0, obj + 0x10) < 256.0f) {
            func_L01_004472C0(obj);
            obj[0x6F] = 0xF;
        }
    }
    flag = 1;
    r = func_L01_00447490(obj, 0x10000, 1);
    if (r != 0 && *(s32 *)(r + 0x20) != 0) {
        h = func_L39_0061CEA0(*(void **)(r + 0x20));
        if (h != 0) {
            if ((*(s32 (**)(void *, s32))(*(u8 **)(h + 0x14) + 0x1C))(h, *(s32 *)(st + 0x2AC)) != 0) {
                flag = 0;
                obj[0xA8] = 0xFF;
            }
        }
    }
    if (flag != 0) {
        func_L40_0048C560(obj, st + 0x160, 0, 0, 0);
    }
    func_L40_003EC050(ctx, obj);
    return 0;
}
/* localdecomp:end func_L40_003ECFA0 */

/* localdecomp:start func_L40_003ED0C8 */
/* PAL port of the NTSC-U match src/us/levels/func_L40_003ECC28.c */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

s32 func_L40_003ED0C8(void * a0_) {
    u8 * a0 = a0_;

    u8 *p = *(u8 **)(a0 + 0x68);

    *(f32 *)(p + 0x7C) = 1.0f;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(s32 *)(p + 0x1DC) = -1;
    *(f32 *)(p + 0x74) = 0.5f;
    p[0x170] = 4;
    p[0x1A8] = 3;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1D7] = 1;
    *(f32 *)(p + 0x70) = 0.7f;
    *(f32 *)(p + 0x78) = 0.5f;
    *(f32 *)(p + 0x80) = 1.4835298f;
    *(f32 *)(p + 0xA0) = 0.34906584f;
    *(f32 *)(p + 0x9C) = 0.01192f;
    *(s32 *)(p + 0xAC) = -1;
    func_L01_0045BD78(a0, 0.018000001f, 0.38000003f, 0.010053097f, 0.25132743f);
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = 1.0f;
        *(s16 *)(p + 0x34) = 1;
    }
    *(f32 *)(p + 0x40) = 0.2f;
    a0[0x30] = 0xFF;
    *(u16 *)(a0 + 0x32) = 0xFF;
    func_L01_004450F0(a0, 5, 4);
    *(f32 *)(p + 0x2D4) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) / 60.0f;
    *(f32 *)(p + 0x2D8) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) / 60.0f;
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L40_003ED0C8 */

INCLUDE_ASM("asm/levels", func_L40_003ED268);

/* localdecomp:start func_L40_003ED308 */
typedef struct {
    u8 pad0[104];
    u8 *vars;
    u8 pad6C[42];
    u16 timer;
} Obj3ECE68;

extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);

void func_L40_003ED308(Obj3ECE68 *obj) {
    u8 *vars = obj->vars;
    func_0038CAD0(vars + 592);
    func_0038CB00(vars + 596);
    if (obj->timer < 0xFFFF) {
        obj->timer++;
    }
}
/* localdecomp:end func_L40_003ED308 */
