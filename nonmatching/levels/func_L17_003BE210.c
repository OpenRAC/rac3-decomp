/* Near miss of func_L17_003BE210: tools/check.py reports 51 diff.
   What differs: the switch on
   the state byte is laid out differently (retail tests `== 1` first, then `< 2`) and the reload
   of D_001D545C uses `$gp` on some paths and `lui` on others. */
#include "common.h"
typedef struct { s32 f0; } S_E210_D;
typedef struct { u8 p0[0x20]; u8 b20; u8 p21[0x47]; S_E210_D *f68; } S_E210_O;
extern u8 D_001A4C60[];
extern u32 D_001D545C;
extern u32 D_001D545C_b[];
extern u32 D_00143D70[];
extern s16 D_001426A0[];
extern u32 D_001A8AEC[];
__asm__(".extern D_001D545C, 4");
extern s32 func_00382380(void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L17_003BE338(void *);
extern void func_L17_003BE2F8(void *);
extern void func_L01_0041A5B0(s32, s32);
void func_L17_003BE210(S_E210_O *a0) {
    u32 i;
    if (a0->b20 == 1) {
        if (func_00382380(D_001A4C60, a0->f68->f0, 0) != 0) {
            func_003A52A0(0, 0, a0);
            func_L17_003BE338(a0);
        }
        i = D_001D545C_b[0];
    } else if (a0->b20 == 0) {
        func_L17_003BE2F8(a0);
        i = D_001D545C;
    } else {
        i = D_001D545C;
    }
    if (D_00143D70[i] < 5) return;
    if (D_001426A0[0] < 3) {
        if ((D_001A8AEC[0] & (1 << i)) == 0) func_L01_0041A5B0(0x140F, 0x111);
    }
}
