#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003A20E0);

/* localdecomp:start func_L03_003A2328 */
void func_L01_004450F0(s32, s32, s32);
void func_L03_003A2328(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x20)) == 0) {
        *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 4) = 0;
        func_L01_004450F0((s32) arg0, 1, -1);
    }
}
/* localdecomp:end func_L03_003A2328 */

/* localdecomp:start func_L03_003A2360 */
extern u8 D_001426E0[];

s32 func_L03_003A2360(void) {
    s32 i;
    for (i = 0xB0; i < 0xBF; i++) {
        if (D_001426E0[i] == 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L03_003A2360 */

INCLUDE_ASM("asm/levels", func_L03_003A2398);

INCLUDE_ASM("asm/levels", func_L03_003A2790);

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

INCLUDE_ASM("asm/levels", func_L03_003A2B48);

INCLUDE_ASM("asm/levels", func_L03_003A2BB8);
