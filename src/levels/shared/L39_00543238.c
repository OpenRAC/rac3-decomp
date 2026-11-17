#include "common.h"

/* localdecomp:start func_L39_00543238 */
#include "vu0.h"

typedef struct {
    char pad0[0x270];
    u8 q270[0x10];
    char pad280[0x2D0 - 0x280];
    void *f2D0;
    char pad2D4[0x308 - 0x2D4];
    f32 f308;
    f32 f30C;
    s32 f310;
} In_00543238;

typedef struct {
    char pad0[0x384];
    In_00543238 *f384;
} Mid_00543238;

typedef struct {
    char pad0[0x68];
    Mid_00543238 *f68;
} Out_00543238;

extern void func_L39_00543818(void *);

void func_L39_00543238(Out_00543238 *o) {
    Mid_00543238 *m = o->f68;
    In_00543238 *p = (In_00543238 *)m->f384;
    qzero(p->q270);
    p->f308 = 60.0f;
    p->f30C = 60.0f;
    p->f310 = 0;
    func_L39_00543818(p->f2D0);
}
/* localdecomp:end func_L39_00543238 */

/* localdecomp:start func_L39_00543278 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 p0[0x1AC]; s32 w1AC; } Z_00543278;
typedef struct { u8 p0[0x10]; u128_t v10; u8 p20[0xF0 - 0x20]; u128_t vF0; } Y_00543278;
typedef struct {
    u8 p0[0x1A14]; u8 b1A14; u8 p1A15[0x2524 - 0x1A15];
    Y_00543278 *y2524; u8 p2528[0x2538 - 0x2528];
    f32 f2538, f253C, f2540; u8 p2544[0x2558 - 0x2544];
    Z_00543278 *z2558;
} X_00543278;
typedef struct {
    u8 p0[0x230]; u128_t v230; u128_t v240; u128_t v250; u128_t v260; u128_t v270;
    u8 p280[0x2D8 - 0x280];
    X_00543278 *x2D8; X_00543278 *x2DC; u8 p2E0[0x2F8 - 0x2E0];
    s32 w2F8; u8 p2FC[0x310 - 0x2FC]; f32 f310;
} P_00543278;
typedef struct { u8 p0[0x290]; u128_t v290; } B_00543278;
typedef struct {
    u8 p0[0x10];
    union { u128_t v10; struct { f32 f10, f14, f18; } f; } u10;
    u8 p20[0xF0 - 0x20]; u128_t vF0;
} A_00543278;
typedef struct { u8 p0[0x68]; B_00543278 *b68; } AA_00543278;
extern void func_L39_005446C0(void *);
extern void func_L39_00544580(void *);
extern f32 func_0038CEA8(void *);
extern void func_L39_0066A398(void *, f32);

void func_L39_00543278(void *arg) {
    A_00543278 *a = arg;
    B_00543278 *b = ((AA_00543278 *)arg)->b68;
    P_00543278 *p = *(P_00543278 **)((u8 *)b + 0x384);
    X_00543278 *x = p->x2D8;
    if (x != 0 && (x->b1A14 != 0 || (x->z2558 != 0 && (x->z2558->w1AC & 4)))) {
        func_L39_005446C0(a);
    } else {
        func_L39_00544580(a);
    }
    p->v270 = b->v290;
    p->f310 = func_0038CEA8(&p->v270);
    func_L39_0066A398(p, 50.0f);
    if (p->x2D8 != 0) {
        p->x2D8->y2524->v10 = a->u10.v10;
        p->x2D8->y2524->vF0 = a->vF0;
    }
    if (p->x2DC != 0) {
        p->x2DC->y2524->v10 = a->u10.v10;
        p->x2DC->y2524->vF0 = a->vF0;
    }
    if (p->w2F8 & 4) {
        if (p->x2D8 != 0 && p->x2D8->b1A14 != 0) {
            p->x2D8->f2538 = a->u10.f.f10;
            p->x2D8->f253C = a->u10.f.f14;
            p->x2D8->f2540 = a->u10.f.f18;
        }
        if (p->x2DC != 0 && p->x2DC->b1A14 != 0) {
            p->x2DC->f2538 = a->u10.f.f10;
            p->x2DC->f253C = a->u10.f.f14;
            p->x2DC->f2540 = a->u10.f.f18;
        }
        p->v230 = a->u10.v10;
        p->v240 = a->vF0;
    }
    p->v250 = a->u10.v10;
    p->v260 = a->vF0;
}
/* localdecomp:end func_L39_00543278 */
