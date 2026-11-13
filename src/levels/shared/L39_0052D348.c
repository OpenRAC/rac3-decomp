#include "common.h"

/* localdecomp:start func_L39_0052D348 */
typedef struct { u8 p0[0x20]; f32 f20; s32 w24; s32 w28; s32 w2C; f32 f30; s32 w34; s32 w38; s32 w3C; f32 f40; s32 w44; s32 w48; u8 p4C[0x460 - 0x4C]; } E_0052D348;
typedef struct { u8 p0[0x1A14]; u8 b1A14; u8 p1A15[0x24C9 - 0x1A15]; u8 b24C9; u8 p24CA[0x2534 - 0x24CA]; s32 w2534; } P_0052D348;
typedef struct { u8 p0[0x2D8]; P_0052D348 *pl0; P_0052D348 *pl1; } R_0052D348;
typedef struct { u8 p0[0x6D0]; R_0052D348 *r; } Q_0052D348;
typedef struct { u8 p0[0x68]; Q_0052D348 *q; } O_0052D348;
extern E_0052D348 D_L39_0024DE80[];
extern void func_L01_003F1F20(s32, s32);

void func_L39_0052D348(O_0052D348 *o) {
    Q_0052D348 *q = o->q;
    P_0052D348 *p = q->r->pl0;
    s32 idx;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        (D_L39_0024DE80 + p->b24C9)->f20 = 0.3f;
        (D_L39_0024DE80 + p->b24C9)->w28 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f30 = 0.1f;
        (D_L39_0024DE80 + p->b24C9)->w38 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
        (D_L39_0024DE80 + p->b24C9)->f40 = 0.01f;
        (D_L39_0024DE80 + p->b24C9)->w48 = 20;
        (D_L39_0024DE80 + p->b24C9)->w2C = 0;
    }
    p = q->r->pl1;
    idx = -1;
    if (p != 0 && p->b1A14 != 0) {
        func_L01_003F1F20(0x12, p->w2534);
        idx = p->b24C9;
    }
    if (idx >= 0) {
        (D_L39_0024DE80 + idx)->f20 = 0.3f;
        (D_L39_0024DE80 + idx)->w28 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f30 = 0.1f;
        (D_L39_0024DE80 + idx)->w38 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
        (D_L39_0024DE80 + idx)->f40 = 0.01f;
        (D_L39_0024DE80 + idx)->w48 = 20;
        (D_L39_0024DE80 + idx)->w2C = 0;
    }
}
/* localdecomp:end func_L39_0052D348 */

INCLUDE_ASM("asm/levels", func_L39_0052D4E8);

INCLUDE_ASM("asm/levels", func_L39_0052D9D0);
