#include "common.h"

typedef struct Sub_003E2638 {
    u8 pad00[0x10];
    s32 f10;
} Sub_003E2638;
typedef struct Ent_003E2638 {
    u8 pad00[0x24];
    Sub_003E2638 *f24;
    u8 pad28[0x9];
    u8 f31;
    u8 pad32;
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
} Ent_003E2638;
typedef struct Obj_003E2638 {
    u8 pad00[0x68];
    f32 *f68;
    u8 pad6C[0x10];
    u16 f7C;
    u8 pad7E[0x1A];
    s32 f98;
} Obj_003E2638;
typedef struct Q_003E2638 {
    u8 pad00[0x2C];
    f32 f2C;
} Q_003E2638;

INCLUDE_ASM("asm/levels", func_L16_003E2518);

/* localdecomp:start func_L16_003E2578 */
extern void func_L01_00439880(u8 *, u16 *, u16 *);
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L16_003E2638(u8 *, s32);

void func_L16_003E2578(u8 *a0) {
    u8 *s;
    u16 x;
    s32 w;
    s32 r;
    s32 t;

    t = a0[0x20];
    s = *(u8 **)(a0 + 0x68);
    if (t != 1) {
        if (t < 2) {
            if (t == 0) {
                func_L01_00439880(a0, &x, (u16 *)&w);
                *(u16 *)(a0 + 0x7C) = x;
                *(u16 *)(s + 4) = *(u16 *)(s + 0x40);
                *(f32 *)s = (f32)*(s32 *)(s + 0x40);
                *(u16 *)(s + 0x36) = *(u16 *)&w;
                func_L01_004450F0(a0, 1, -1);
            }
        }
    } else {
        r = func_L01_00447490(a0, 1, 1);
        if (r != 0) {
            func_L16_003E2638(a0, r);
        }
    }
    a0[0xA8] = 0xFF;
}
/* localdecomp:end func_L16_003E2578 */

/* localdecomp:start func_L16_003E2638 */
extern Ent_003E2638 *func_L01_00452460(Obj_003E2638 *, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L16_003E26E8(Obj_003E2638 *, Q_003E2638 *);

void func_L16_003E2638(u8 *p0, s32 p1) {
    Obj_003E2638 *a0 = (Obj_003E2638 *)p0;
    Q_003E2638 *a1 = (Q_003E2638 *)p1;
    f32 d;
    s32 id;
    Ent_003E2638 *e;

    d = *a0->f68 - a1->f2C;
    *a0->f68 = d;
    if (d > 0.0f && a0->f7C != 0) {
        func_L16_003E26E8(a0, a1);
        return;
    }
    id = 0x1C7B;
    e = func_L01_00452460(a0, id, 0);
    if (e != 0) {
        Sub_003E2638 *s = e->f24;
        u16 fl = e->f34;
        s32 v = s->f10;
        fl |= 1;
        e->f98 = v;
        e->f34 = fl;
        e->f31 = 0;
    }
    a0->f98 = 0;
    a0->f7C = 0;
    func_L01_004450F0((u8 *)a0, 2, -1);
}
/* localdecomp:end func_L16_003E2638 */

INCLUDE_ASM("asm/levels", func_L16_003E26E8);

INCLUDE_ASM("asm/levels", func_L16_003E2B18);

INCLUDE_ASM("asm/levels", func_L16_003E2C28);

INCLUDE_ASM("asm/levels", func_L16_003E2C88);

INCLUDE_ASM("asm/levels", func_L16_003E2E30);

/* localdecomp:start func_L16_003E3068 */
extern void func_L16_003E2B18(char *, int);

void func_L16_003E3068(char *a, int bit)
{
    *(unsigned short *)(a + 0x7C) &= ~(1 << bit);
    (*(unsigned short **)(a + 0x68))[0x36 / 2]--;
    func_L16_003E2B18(a, bit);
}
/* localdecomp:end func_L16_003E3068 */
