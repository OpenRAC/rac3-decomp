#include "common.h"

typedef struct S_L02_003532F0 {
    f32 x;
    f32 y;
    u8 pad08[0xC];
    s32 state;
    f32 t18;
    f32 t1C;
} S_L02_003532F0;
typedef struct T_L02_003532F0 {
    f32 thr;
    f32 pad[6];
} T_L02_003532F0;
typedef struct O_L02_003532F0 {
    u8 pad00[0x20];
    s32 count;
    u8 pad24[0xC];
    f32 vx;
    f32 vy;
} O_L02_003532F0;

typedef struct B_L02_00352C80 {
    s32 id;
    u8 pad04[0x1C];
    s32 cnt20;
    s32 a24;
    s32 a28;
    s32 r2C;
    u8 pad30[0x10];
    s32 cnt40;
    s32 a44;
    s32 a48;
    s32 r4C;
    s32 flag50;
    f32 f54;
    f32 f58;
} B_L02_00352C80;
typedef struct A_L02_00352C80 {
    u8 pad00[0x20];
    u8 b20;
    u8 pad21[0x47];
    B_L02_00352C80 *sub;
} A_L02_00352C80;

/* localdecomp:start func_L02_00352C80 */
extern s32 D_L02_001F1580[];
extern void func_L02_00352DF0(A_L02_00352C80 *, B_L02_00352C80 *);
extern s32 func_0038CAD0(void *);
extern s32 func_L02_00353208(A_L02_00352C80 *, B_L02_00352C80 *);
extern s32 func_00382498(s32, s32);
extern void func_L02_003532F0();
extern s32 func_L02_00353398(A_L02_00352C80 *, B_L02_00352C80 *);
extern s32 func_L02_003534D8(A_L02_00352C80 *, B_L02_00352C80 *);
extern void func_L02_003536B8(u8 *);
extern void func_L01_004048D0(void (*)(u8 *), void *);

void func_L02_00352C80(A_L02_00352C80 *a) {
    B_L02_00352C80 *b = a->sub;

    if (a->b20 == 0) {
        func_L02_00352DF0(a, b);
    }
    if (D_L02_001F1580[0] != b->id) {
        return;
    }
    if (b->cnt20 > 0) {
        if (func_0038CAD0((u8 *)b + 0x2C) != 0) {
            if (func_L02_00353208(a, b) != 0) {
                b->r2C = func_00382498(b->a24, b->a28);
            }
        }
        func_L02_003532F0(a, b);
    }
    if (b->cnt40 > 0) {
        if (func_0038CAD0((u8 *)b + 0x4C) != 0) {
            if (func_L02_00353398(a, b) != 0) {
                b->r4C = func_00382498(b->a44, b->a48);
            }
        }
    }
    if (b->flag50 != 0) {
        b->f58 = b->f58 + b->f54;
        if (b->f58 > 1.0f) {
            do {
                if (func_L02_003534D8(a, b) != 0) {
                    b->f58 = b->f58 - 1.0f;
                } else {
                    b->f58 = b->f58 - 0.25f;
                }
            } while (b->f58 > 1.0f);
        }
    }
    func_L01_004048D0(func_L02_003536B8, a);
}
/* localdecomp:end func_L02_00352C80 */

INCLUDE_ASM("asm/levels", func_L02_00352DF0);

INCLUDE_ASM("asm/levels", func_L02_00352F60);

INCLUDE_ASM("asm/levels", func_L02_00353208);

/* localdecomp:start func_L02_003532F0 */
extern T_L02_003532F0 D_L02_002B0E50[];

void func_L02_003532F0(s32 unused, O_L02_003532F0 *o) {
    S_L02_003532F0 *p;
    s32 i;
    s32 state;
    s32 ns;
    f32 t;

    p = (S_L02_003532F0 *)((u8 *)o + 0x60);
    for (i = 0; i < o->count; i++) {
        state = p->state;
        if (state != -1) {
            p->t18 = p->t18 + p->t1C;
            if (D_L02_002B0E50[state].thr < p->t18) {
                ns = state + 1;
                t = p->t18 - D_L02_002B0E50[state].thr;
                p->state = ns;
                p->t18 = t;
                if (ns >= 5) {
                    p->state = -1;
                }
            }
            p->x = p->x + o->vx;
            p->y = p->y + o->vy;
        }
        p++;
    }
}
/* localdecomp:end func_L02_003532F0 */

INCLUDE_ASM("asm/levels", func_L02_00353398);

INCLUDE_ASM("asm/levels", func_L02_003534D8);

/* localdecomp:start func_L02_003536B8 */
extern void func_L02_003536D8(s32);
void func_L02_003536B8(u8 *p) {
    func_L02_003536D8(*(s32 *)(p + 0x68));
}
/* localdecomp:end func_L02_003536B8 */

INCLUDE_ASM("asm/levels", func_L02_003536D8);
