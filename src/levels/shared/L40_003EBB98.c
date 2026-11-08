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

INCLUDE_ASM("asm/levels", func_L40_003EBBE0);

INCLUDE_ASM("asm/levels", func_L40_003EBCD8);

INCLUDE_ASM("asm/levels", func_L40_003EBEA0);

INCLUDE_ASM("asm/levels", func_L40_003EC050);

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

INCLUDE_ASM("asm/levels", func_L40_003ED820);

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
