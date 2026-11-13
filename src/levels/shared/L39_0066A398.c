#include "common.h"

/* localdecomp:start func_L39_0066A398 */
typedef struct { u8 p0[0x1A0A]; u8 b1A0A; } S_0066A398x;
typedef struct { u8 p0[0x18]; f32 f18; u8 p1C[0x34 - 0x1C]; u16 w34; u8 p36[0x98 - 0x36]; s32 w98; u8 p9C[0xBC - 0x9C]; u8 bBC; } S_0066A398a;
typedef struct {
    u8 p0[0x298]; f32 f298; u8 p29C[0x2D0 - 0x29C];
    S_0066A398a *a2D0; u8 p2D4[4]; S_0066A398x *x2D8; S_0066A398x *x2DC;
    u8 p2E0[0x2F0 - 0x2E0]; s32 w2F0;
} S_0066A398;
extern f32 D_L39_0024BC30;
extern s32 func_L39_0061BF68(void *);
extern void func_L39_00667700(void *, void *, s32);
extern void func_L39_006673E8(void *, void *, s32);
extern void func_L01_00356B88(void *);

void func_L39_0066A398(S_0066A398 *self, f32 arg) {
    S_0066A398x *x;
    f32 v = self->a2D0->f18;
    if (v + arg < self->f298 || v < D_L39_0024BC30) {
        if (func_L39_0061BF68(self->x2D8) >= 0) {
            x = self->x2D8;
            x->b1A0A = 2;
            func_L39_00667700(self, self->x2D8, 0);
            func_L01_00356B88(x);
            x->b1A0A = 1;
        }
        if (func_L39_0061BF68(self->x2DC) >= 0) {
            x = self->x2DC;
            x->b1A0A = 2;
            func_L39_006673E8(self, self->x2DC, 1);
            func_L01_00356B88(x);
            x->b1A0A = 1;
        }
        self->a2D0->w98 = 0;
        self->a2D0->w34 |= 0x41;
        self->a2D0->bBC = 7;
        self->w2F0 = 25;
    }
}
/* localdecomp:end func_L39_0066A398 */

INCLUDE_ASM("asm/levels", func_L39_0066A490);
