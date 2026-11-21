#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L03_003B99B8 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x7C];
    s16 h7C;
    u8 pad7E[0xF0 - 0x7E];
    f32 fF0;
} Child_003B7D18;

typedef struct {
    Child_003B7D18 *p[4];
    union { s32 w10[4]; struct { f32 f10; f32 f14; f32 f18; f32 f1C; } f; } u;
} St_003B7D18;

extern s32 D_L03_001DEAC0;
extern f32 D_L03_001DEAB4;
extern f32 D_L03_001DEAB8;
extern f32 D_L03_001DEAB0;
extern s32 D_L03_001DEAC4;
extern s32 D_L03_001DEAC8;
__asm__(".extern D_L03_001DEAC0, 4");
__asm__(".extern D_L03_001DEAB4, 4");
__asm__(".extern D_L03_001DEAB8, 4");
__asm__(".extern D_L03_001DEAB0, 4");

extern Child_003B7D18 *func_L03_003B9938(void *);
extern void func_L03_003B9D08(u8 *);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_0038D308(u8 *, u8 *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2880(void *);

void func_L03_003B99B8(void *self) {
    u8 *o = self;
    St_003B7D18 *st;
    Child_003B7D18 **pp;
    vu0_v4 tmp;
    s32 n;
    s32 m;

    st = *(St_003B7D18 **)(o + 0x68);
    switch (o[0x20]) {
    case 0:
        o[0x30] = 0xFF;
        for (n = 0; n < 4; n++) {
            st->u.w10[n] = 0;
            st->p[n] = func_L03_003B9938(o);
            if (st->p[n] != 0) st->p[n]->h7C = 1 << n;
        }
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        if (*(u8 **)(o + 0xB8) != 0 && *(s16 *)(*(u8 **)(o + 0xB8) + 0xAA) == 0x1AE0) {
            *(f32 *)(o + 0xF0) = *(f32 *)(*(u8 **)((u8 *)st + 0x20) + 0xF0);
            func_0038D308(o + 0xC0, o + 0xF0);
            func_L03_003B9D08(o);
        }
        if (func_L01_00456250(o) != 0) {
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if ((f32)D_L03_001DEAC0 <= st->u.f.f10) {
            st->p[0]->h7C = 0;
            func_L01_004450F0(o, 3, -1);
        } else if (st->p[0] != 0) {
            func_L03_003B9D08(o);
            st->u.f.f10 = st->u.f.f10 + D_L03_001DEAB4;
            st->p[0]->fF0 = func_0038DAB8(*(f32 *)(o + 0xF0), st->u.f.f10 * 0.017453292f);
            func_0038D308((u8 *)st->p[0] + 0xC0, (u8 *)st->p[0] + 0xF0);
        }
        break;
    case 3:
        if ((f32)D_L03_001DEAC4 <= st->u.f.f14) {
            st->p[1]->h7C = 0;
            func_L01_004450F0(o, 4, -1);
        } else if (st->p[1] != 0) {
            func_L03_003B9D08(o);
            st->u.f.f14 = st->u.f.f14 + D_L03_001DEAB4;
            st->p[1]->fF0 = func_0038DAB8(*(f32 *)(o + 0xF0), st->u.f.f14 * 0.017453292f);
            func_0038D308((u8 *)st->p[1] + 0xC0, (u8 *)st->p[1] + 0xF0);
        }
        break;
    case 4:
        func_L03_003B9D08(o);
        if ((f32)D_L03_001DEAC8 <= st->u.f.f18) {
            st->p[2]->h7C = 0;
            func_L01_004450F0(o, 5, -1);
        } else if (st->p[2] != 0) {
            func_L03_003B9D08(o);
            st->u.f.f18 = st->u.f.f18 + D_L03_001DEAB4;
            st->p[2]->fF0 = func_0038DAB8(*(f32 *)(o + 0xF0), st->u.f.f18 * 0.017453292f);
            func_0038D308((u8 *)st->p[2] + 0xC0, (u8 *)st->p[2] + 0xF0);
        }
        break;
    case 5:
        if (D_L03_001DEAB8 <= func_0038CF00((u8 *)st->p[3] + 0x10, o + 0x10)) {
            func_L01_004450F0(o, 6, -1);
        } else if (st->p[3] != 0) {
            st->u.f.f1C = st->u.f.f1C + D_L03_001DEAB0 * 0.020000001f;
            func_0038CF68(&tmp, (u8 *)st->p[3] + 0xD0, st->u.f.f1C);
            vec_add_ba((u8 *)st->p[3] + 0x10, o + 0x10, &tmp);
        }
        break;
    case 6:
        pp = st->p;
        for (m = 3; m >= 0; m--) {
            if (*pp != 0) func_003C2880(*pp);
            pp++;
        }
        break;
    }
}
/* localdecomp:end func_L03_003B99B8 */

/* localdecomp:start func_L03_003B9D08 */

extern void func_0038D308(u8 *, u8 *);

void func_L03_003B9D08(u8 *a0) {
    u8 **p = *(u8 ***)(a0 + 104);
    s32 i;
    for (i = 3; i >= 0; i--) {
        if (*p != 0) {
            *(f32 *)(*p + 240) = *(f32 *)(a0 + 240);
            *(u128_t *)(*p + 16) = *(u128_t *)(a0 + 16);
            func_0038D308(*p + 192, *p + 240);
        }
        p++;
    }
}
/* localdecomp:end func_L03_003B9D08 */
