#include "common.h"

/* NTSC-U counterpart of func_L04_004AD6A8 (src/levels/04_marcadia/L04_004AD6A8.c) */
/* localdecomp:start func_L04_004A9B08 */
typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 *fC;
    u32 f10;
    u8 f14;
    u8 pad[3];
} S_2ECFD8;

extern S_2ECFD8 D_L04_002ED028[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
extern s32 D_001D9388_sda;
__asm__(".extern D_001D9388_sda, 4");

void func_L04_004A9B08(void) {
    s32 i;

    for (i = 0; D_L04_002ED028[i].f0 != 0; i++) {
        switch (D_L04_002ED028[i].f10) {
        case 1: {
            s32 j;

            D_L04_002ED028[i].f14 = 1;
            for (j = 0; D_L04_002ED028[i].fC[j] != 0; j++) {
                D_L04_002ED028[i].f14 =
                    ((D_L04_002ED028[i].f14 != 0) &&
                     (D_00142BA0[D_L04_002ED028[i].fC[j] >> 2] &
                      (1 << (D_L04_002ED028[i].fC[j] & 0x1F)))) ||
                    (D_001D9388_sda != 0);
            }
            break;
        }
        case 0:
        case 2: {
            u32 v = (u32)D_L04_002ED028[i].fC;

            D_L04_002ED028[i].f14 = ((D_00142BA0[v >> 2] & (1 << (v & 0x1F))) != 0) ||
                                    (D_001D9388_sda != 0);
            break;
        }
        case 3:
            D_L04_002ED028[i].f14 = (D_00142693[0] != 0) || (D_001D9388_sda != 0);
            break;
        case 4:
        default:
            D_L04_002ED028[i].f14 = 1;
            break;
        }
    }
}
/* localdecomp:end func_L04_004A9B08 */
