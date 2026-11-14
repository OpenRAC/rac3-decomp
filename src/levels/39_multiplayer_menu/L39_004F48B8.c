#include "common.h"

/* localdecomp:start func_L39_004F48B8 */
typedef struct V_004F48B8 V_004F48B8;
typedef struct {
    s32 (*f0)(V_004F48B8 *, void *, s32);
} VT_004F48B8;
struct V_004F48B8 { VT_004F48B8 *vt; };
typedef struct { s32 f0; s32 type; V_004F48B8 *obj; } E_004F48B8;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } A_004F48B8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} O_004F48B8;
typedef struct { u8 pad[0x2C]; s32 flags; } C_004F48B8;
extern s32 D_L39_0046D650[];
extern s32 D_L39_0046D678[];
extern s32 D_L39_0046D698[];
extern s32 func_L39_004F7320(E_004F48B8 **, void *, s32);
extern s32 func_L39_004F7648(s32);
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F60D8(void *, s32 *, s32, s32);
extern s32 func_L39_004F5F38(void *, s32 *, void *);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F48B8(void *a0, C_004F48B8 *ctx, A_004F48B8 *a) {
    E_004F48B8 *e0;
    E_004F48B8 *e1;
    E_004F48B8 *e2;
    O_004F48B8 *o;
    s32 r;

    if ((r = func_L39_004F7320(&e0, D_L39_0046D650, a->f0)) != 0) return r;
    if ((r = func_L39_004F7320(&e1, D_L39_0046D678, a->f8)) != 0) return r;
    if ((r = func_L39_004F7320(&e2, D_L39_0046D698, a->f10)) != 0) return r;
    if (e2->type == 2 && e1->type != 6 && e1->type != 7) return 0x201;
    if ((r = func_L39_004F6060(ctx, &o, 0x28)) != 0) return r;
    o->f20 = e2->type;
    if ((r = func_L39_004F60D8(ctx, &o->f0, a->f0, func_L39_004F7648(a->f0) + 1)) != 0) return r;
    o->f18 = (s32)e0->obj;
    if ((r = e0->obj->vt->f0(e0->obj, ctx, a->f4)) != 0) return r;
    if ((r = func_L39_004F5F38(ctx, &o->f4, e0->obj)) != 0) return r;
    if ((r = func_L39_004F60D8(ctx, &o->f8, a->f8, func_L39_004F7648(a->f8) + 1)) != 0) return r;
    o->f24 = e1->type;
    o->f1C = (s32)e1->obj;
    if ((r = e1->obj->vt->f0(e1->obj, ctx, a->fC)) != 0) return r;
    if ((r = func_L39_004F5F38(ctx, &o->fC, e1->obj)) != 0) return r;
    if ((r = func_L39_004F60D8(ctx, &o->f10, a->f10, func_L39_004F7648(a->f10) + 1)) != 0) return r;
    ctx->flags |= 8;
    return func_L39_004F5EA0(ctx, a0, o);
}
/* localdecomp:end func_L39_004F48B8 */

INCLUDE_ASM("asm/levels", func_L39_004F4AE8);

LINKER_REMNANT("asm/levels", func_L39_004F4B50);

LINKER_REMNANT("asm/levels", func_L39_004F4B58);

LINKER_REMNANT("asm/levels", func_L39_004F4B60);

/* localdecomp:start func_L39_004F4B68 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern void func_L39_004F7510(void *, void *, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F4B68(void *a0, void *a1, void *a2) {
    void *buf;
    s32 r = func_L39_004F6060(a1, &buf, 4);
    if (r == 0) {
        func_L39_004F7510(buf, a2, 4);
        r = func_L39_004F5EA0(a1, a0, buf);
    }
    return r;
}
/* localdecomp:end func_L39_004F4B68 */

LINKER_REMNANT("asm/levels", func_L39_004F4BD8);

LINKER_REMNANT("asm/levels", func_L39_004F4BE0);

/* localdecomp:start func_L39_004F4BE8 */
extern s32 func_L39_004F6060(void *, void *, s32);
extern s32 func_L39_004F60D8(void *, s32 *, s32, s32);
extern s32 func_L39_004F5EA0(void *, void *, void *);

s32 func_L39_004F4BE8(void *a0, void *a1, s32 *a2) {
    s32 *buf;
    s32 r = func_L39_004F6060(a1, &buf, 8);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F60D8(a1, buf, a2[0], a2[1]);
    if (r != 0) {
        return r;
    }
    buf[1] = a2[1];
    return func_L39_004F5EA0(a1, a0, buf);
}
/* localdecomp:end func_L39_004F4BE8 */

LINKER_REMNANT("asm/levels", func_L39_004F4C68);
