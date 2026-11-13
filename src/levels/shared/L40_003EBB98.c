#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

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

INCLUDE_ASM("asm/levels", func_L40_003EBCD8);

INCLUDE_ASM("asm/levels", func_L40_003EBEA0);

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

INCLUDE_ASM("asm/levels", func_L40_003EC320);

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

INCLUDE_ASM("asm/levels", func_L40_003ED0C8);

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

INCLUDE_ASM("asm/levels", func_L40_003ED360);

/* localdecomp:start func_L40_003ED820 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003ED820;
extern u8 *D_L40_0025B998[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

void func_L40_003ED820(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V_003ED820 a;
    V_003ED820 b;

    a = *(V_003ED820 *)(m + 0x10);
    b = *(V_003ED820 *)(v + 0x270);
    a.z += *(f32 *)(v + 0x78);
    b.z += *(f32 *)(v + 0x78);
    if (func_0038CF00(&a, &b) < 30.0f && func_003D3CB0(&a, &b, 0x10, m, 0) == 0) {
        *(u128_t *)(v + 0x260) = *(u128_t *)(v + 0x270);
        *(u128_t *)(v + 0x280) = *(u128_t *)(v + 0x270);
        return;
    }
    if (D_L40_0025B998[0] != 0 && D_L40_0025B998[0] == *(u8 **)(v + 0x230)) {
        *(u128_t *)(v + 0x260) = *(u128_t *)(v + 0x270);
        *(u128_t *)(v + 0x280) = *(u128_t *)(v + 0x270);
    }
}
/* localdecomp:end func_L40_003ED820 */

/* localdecomp:start func_L40_003ED8F8 */
extern s32 D_L40_00241118;
extern s32 D_L40_00242914;
extern void func_L01_00451F60(s32, s32, s32);

s32 func_L40_003ED8F8(u8 *a0, s32 a1) {
    s32 id;
    u8 *p;
    s32 v;

    p = *(u8 **)(a0 + 144);
    id = 2250;
    if (a1 != 0) {
        id = 2244;
    }
    if (p != 0) {
        v = p[9417];
        if (v != D_L40_00241118) {
            return 0;
        }
        if (D_L40_00242914 == 0) {
            func_L01_00451F60(id, 4, 0);
        } else {
            func_L01_00451F60(id, 4, v);
        }
    }
    return 0;
}
/* localdecomp:end func_L40_003ED8F8 */
