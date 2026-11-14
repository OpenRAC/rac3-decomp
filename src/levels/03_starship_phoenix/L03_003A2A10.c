#include "common.h"

/* localdecomp:start func_L03_003A2A10 */
typedef struct { u8 pad[0x23]; s8 v; } P_003A2A10;
typedef struct { u8 pad0[0x1200]; P_003A2A10 *p[3]; u8 pad1[0x50 - 12]; } E_003A2A10;
typedef struct { u8 pad0[0x25C0]; P_003A2A10 *q; } H_003A2A10;
extern E_003A2A10 D_001A4BE0_003A2A10;
extern H_003A2A10 D_001A4BE0_003A2A10h;
__asm__(".extern D_001A4BE0_003A2A10, 16");
__asm__(".extern D_001A4BE0_003A2A10h, 16");

void func_L03_003A2A10(s32 d) {
    s32 i;
    E_003A2A10 *e;
    int j;
    H_003A2A10 *h = &D_001A4BE0_003A2A10h;
    h->q->v += d;
    if (h->q->v < 0) h->q->v = 0x7F;
    else if ((u8)h->q->v < 12) h->q->v = 12;
    e = &D_001A4BE0_003A2A10;
    for (i = 0; i < 7; i++, e = (E_003A2A10 *)((u8 *)e + 0x50)) {
        P_003A2A10 *p;
        p = e->p[0];
        if (p != 0) {
            p->v += d;
            p = e->p[0];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[1];
        if (p != 0) {
            p->v += d;
            p = e->p[1];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[2];
        if (p != 0) {
            p->v += d;
            p = e->p[2];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
    }
}
/* localdecomp:end func_L03_003A2A10 */

/* localdecomp:start func_L03_003A2B48 */
typedef struct S_003A2B48 {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x10];
    u16 h34;
} S_003A2B48;
typedef struct G_003A2B48 {
    u8 pad0[0x25C0];
    S_003A2B48 *q;
} G_003A2B48;
extern G_003A2B48 D_001A4BE0;

void func_L03_003A2B48(void) {
    s32 i;

    D_001A4BE0.q->b23 = 0x7F;
    D_001A4BE0.q->h34 &= 0xDFFF;
    for (i = 0; i < 7; i++) {
        u8 *c = (u8 *)&D_001A4BE0 + i * 0x50;

        if (*(S_003A2B48 **)(c + 0x1200) != 0) {
            (*(S_003A2B48 **)(c + 0x1200))->b23 = 0x7F;
        }
        if (*(S_003A2B48 **)(c + 0x1204) != 0) {
            (*(S_003A2B48 **)(c + 0x1204))->b23 = 0x7F;
        }
        if (*(S_003A2B48 **)(c + 0x1208) != 0) {
            (*(S_003A2B48 **)(c + 0x1208))->b23 = 0x7F;
        }
    }
}
/* localdecomp:end func_L03_003A2B48 */

INCLUDE_ASM("asm/levels", func_L03_003A2BB8);
