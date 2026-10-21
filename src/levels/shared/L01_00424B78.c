#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 p0[0xC];
    void *buf;
    s32 used;
    u8 p14[0x1C];
} E_421DE0;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 f12;
    s128 q16;
} C_421DE0;
typedef struct {
    u8 b[1024];
} B_421DE0;
typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    s128 q10;
} S_421F08r;
typedef struct {
    u8 pad0[0xC];
    void *wC;
    s32 w10;
    u8 pad14[0x30 - 0x14];
} S_421F08e;
typedef struct {
    u8 pad0[0x400];
} S_421F08b;

INCLUDE_ASM("asm/levels", func_L01_00424B78);

INCLUDE_ASM("asm/levels", func_L01_00424B80);

/* localdecomp:start func_L01_00424B88 */




extern E_421DE0 D_L01_001F1C40[];
extern C_421DE0 D_L01_001F1B40[];
extern B_421DE0 D_L01_001F1DC0[];
extern void func_0038CBA0(void *p, s32 n);

s32 func_L01_00424B88(s128 *p, s32 color, f32 x, f32 y) {
    s32 i;
    C_421DE0 *c;
    E_421DE0 *e;

    for (i = 0; i < 8 && D_L01_001F1C40[i].used != 0; i++) {
    }
    if (i == 8) {
        return -1;
    }
    c = &D_L01_001F1B40[i];
    c->q16 = *p;
    ((f32 *)c)[7] = x;
    c->f0 = (s32)(color & 0xFF) * 0.0078125f;
    c->f4 = (s32)((color >> 8) & 0xFF) * 0.0078125f;
    c->f8 = (s32)((color >> 16) & 0xFF) * 0.0078125f;
    c->f12 = y;
    e = &D_L01_001F1C40[i];
    func_0038CBA0(e, 48);
    e->used = 1;
    e->buf = &D_L01_001F1DC0[i];
    return i;
}
/* localdecomp:end func_L01_00424B88 */

/* localdecomp:start func_L01_00424CB0 */
extern void func_0038CBA0(void *p, s32 n);
extern B_421DE0 D_L01_001F1DC0[];
extern C_421DE0 D_L01_001F1B40[];
extern E_421DE0 D_L01_001F1C40[];





s32 func_L01_00424CB0(s128 *a0, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16) {
    S_421F08r *r;
    S_421F08e *e;
    s32 i;

    for (i = 0; i < 8 && ((S_421F08e *)&D_L01_001F1C40)[i].w10 != 0; i++) {
    }
    if (i == 8) {
        return -1;
    }
    r = &((S_421F08r *)&D_L01_001F1B40)[i];
    r->q10 = *a0;
    *(f32 *)((u8 *)&r->q10 + 12) = f12;
    r->f0 = f14;
    r->f4 = f15;
    r->f8 = f16;
    r->fC = f13;
    e = &((S_421F08e *)&D_L01_001F1C40)[i];
    ((void (*)(S_421F08e *a0, s32 a1))func_0038CBA0)(e, 48);
    e->w10 = 1;
    e->wC = &((S_421F08b *)&D_L01_001F1DC0)[i];
    return i;
}
/* localdecomp:end func_L01_00424CB0 */

/* localdecomp:start func_L01_00424D88 */
extern E_421DE0 D_L01_001F1C40[];
extern C_421DE0 D_L01_001F1B40[];
extern void func_003D0E00_00424D88(void);
extern void func_0038CBA0(void *p, s32 n);

void func_L01_00424D88(u32 i)
{
    if (i < 8) {
        func_003D0E00_00424D88();
        func_0038CBA0(((u8 *)&D_L01_001F1B40) + i * 32, 32);
        func_0038CBA0(((u8 *)&D_L01_001F1C40) + i * 48, 48);
    }
}
/* localdecomp:end func_L01_00424D88 */
