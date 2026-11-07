#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0039C730);

INCLUDE_ASM("asm/levels", func_L02_0039CD18);

INCLUDE_ASM("asm/levels", func_L02_0039CE20);

/* localdecomp:start func_L02_0039D160 */
typedef struct {
    u8 pad0[0x6C];
    u32 flags6C;
    u8 pad70[0xA];
    s16 f7A;
    u16 f7C;
} B_39D160;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    B_39D160 *p68;
    u8 pad6C[0x44];
    u8 fB0;
} S_39D160;
extern s32 D_001C5290[][16];
__asm__(".extern D_001C5290, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");

void func_L02_0039D160(S_39D160 *self) {
    B_39D160 *p;
    s32 v;
    if (self->f20 == 0) {
        p = self->p68;
        p->f7A = 1;
        p->flags6C |= 1;
        self->f20 = 1;
        v = D_001C5290[D_001D545C][self->fB0];
        if (v >= 4) v = 3;
        p->f7C = p->f7C * (s32)(v * 0.3f + 1.0f);
    }
}
/* localdecomp:end func_L02_0039D160 */

INCLUDE_ASM("asm/levels", func_L02_0039D200);

INCLUDE_ASM("asm/levels", func_L02_0039D680);

LINKER_REMNANT("asm/levels", func_L02_0039D7C0);

INCLUDE_ASM("asm/levels", func_L02_0039D7D0);

/* localdecomp:start func_L02_0039E208 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_39E208;
typedef struct B_39E208 {
    char pad0[4];
    int timer;
    char pad1[6];
    unsigned char kind;
    char pad2[1];
    V4_39E208 v;
} B_39E208;
typedef struct A_39E208 {
    char pad0[0x10];
    V4_39E208 v;
    unsigned char active;
    char pad1[0xF];
    unsigned char flag;
    char pad2[0x37];
    B_39E208 *b;
} A_39E208;

void func_L02_0039E208(A_39E208 *a) {
    B_39E208 *b;
    if (a->active == 0) {
        b = a->b;
        b->v = a->v;
        if (b->kind == 0) {
            b->timer = 0;
        } else if (b->kind == 1) {
            b->timer = 30;
        } else {
            b->timer = 60;
        }
        a->flag = 255;
        a->active = 1;
    }
}
/* localdecomp:end func_L02_0039E208 */
