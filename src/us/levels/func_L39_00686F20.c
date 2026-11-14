#include "common.h"

/* NTSC-U counterpart of func_L39_00689AC8 (src/levels/39_multiplayer_menu/L39_00689610.c) */
/* localdecomp:start func_L39_00686F20 */
extern u8 D_001DC2EA_sda;
__asm__(".extern D_001DC2EA_sda, 1");
extern s32 D_001DC2F0_sda;
__asm__(".extern D_001DC2F0_sda, 4");
extern s32 D_L39_003D2980[];
extern u8 D_L39_00247BC8[];
extern u8 D_L39_0024D8B0[8];
__asm__(".extern D_L39_0024D8B0, 16");
extern void func_L01_00512AB0(s32, s32, s32);
extern s32 func_0037DF98(s32);
extern s32 func_00120048(void *, void *, ...);
extern void func_L01_00512FE8(s32, void *);

void func_L39_00686F20(s32 a0, s32 a1) {
    if (D_001DC2EA_sda != 0) {
        D_001DC2F0_sda = 0xB4;
        func_L01_00512AB0(D_L39_003D2980[0x40 / 4], 1, 1);
        func_00120048(D_L39_0024D8B0, D_L39_00247BC8, func_0037DF98(0xF69), a1);
        func_L01_00512FE8(D_L39_003D2980[0x40 / 4], D_L39_0024D8B0);
    }
}
/* localdecomp:end func_L39_00686F20 */
