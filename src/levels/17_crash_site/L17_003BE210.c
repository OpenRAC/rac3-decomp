#include "common.h"

/* localdecomp:start func_L17_003BE210 */
typedef struct { s32 f0; } S_E210_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_E210_D *f68; } S_E210_O;
extern u8 D_001A4C60[];
extern s32 D_001D545C;
extern s32 D_00143D70[];
extern s16 D_001426A0[];
extern u32 D_001A8AEC[];
extern s32 func_00382380(void *, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L17_003BE338();
extern void func_L17_003BE2F8();
extern void func_L01_0041A5B0(s32, s32);
void func_L17_003BE210(S_E210_O *self) {
    s32 i;
    S_E210_D *d = self->f68;
    switch (self->b20) {
    case 0:
        func_L17_003BE2F8(self);
        break;
    case 1:
        if (func_00382380(D_001A4C60, d->f0, 0) != 0) {
            func_003A52A0(0, 0, self);
            func_L17_003BE338(self);
        }
        break;
    case 2:
        break;
    }
    i = D_001D545C;
    if (D_00143D70[i] < 5) return;
    if (D_001426A0[0] < 3) {
        if ((D_001A8AEC[0] & (1 << i)) == 0) func_L01_0041A5B0(0x140F, 0x111);
    }
}
/* localdecomp:end func_L17_003BE210 */

/* localdecomp:start func_L17_003BE2F8 */
typedef struct { u8 p0[0x30]; u8 b30; u8 p31[3]; u16 h34; } S_E2F8_O;
extern void func_L01_004450F0(S_E2F8_O *, s32, s32);
void func_L17_003BE2F8(S_E2F8_O *a0) {
    func_L01_004450F0(a0, 1, -1);
    a0->b30 = 0xFF;
    a0->h34 &= ~1;
}
/* localdecomp:end func_L17_003BE2F8 */

INCLUDE_ASM("asm/levels", func_L17_003BE338);
