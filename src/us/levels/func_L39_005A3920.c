#include "common.h"

/* NTSC-U counterpart of func_L39_005A5590 (src/levels/shared/L39_005A5238.c) */
typedef struct S_005A5238 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
} S_005A5238;
typedef struct S_005A54A0 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x148];
    s32 f15C;
    s32 f160;
    s32 f164;
    s32 f168;
} S_005A54A0;
extern S_005A5238 D_001A4560;
extern S_005A5238 D_001A4560;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;
extern s32 D_L39_0024057C;
extern s32 D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3920;
extern int D_001D4CEC_sda_005A3920;
extern int D_L39_00240578;
extern s32 D_001D4CEC_sda_005A3920;

/* localdecomp:start func_L39_005A3920 */
extern s32 D_001D4CEC_sda_005A3920;
extern s32 D_L39_00240578;
extern s32 D_L39_0024057C;

void func_L39_005A3920(void)
{
    S_005A54A0 *p = (S_005A54A0 *)&D_001A4560;

    if (p->f15C == 2 && p->f164 < 0) {
        p->f10 = 0;
        p->f164 = 7;
        p->f168 = 0;
        D_L39_00240578 = 0x20;
        D_L39_0024057C = D_001D4CEC_sda_005A3920 & ~0x800;
    }
}
/* localdecomp:end func_L39_005A3920 */
