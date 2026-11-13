#include "common.h"

/* NTSC-U counterpart of func_L39_005DC180 (src/levels/shared/L39_005DBF90.c): 25 -> 30 */
extern u8 D_001D8194_sda;
extern s32 func_L01_00512AB0(s32, s32, s32);
extern u8 D_001D8194_sda;
extern s32 func_L01_00512AB0(s32, s32, s32);

/* localdecomp:start func_L39_005D9BD8 */
typedef struct S_005DC180 {
    u8 pad[0x18F];
    s8 f18F;
} S_005DC180;
__asm__(".extern D_L39_002412A0, 16");
__asm__(".extern D_001D8194_sda, 1");
__asm__(".extern D_L39_0024C4F8, 16");
__asm__(".extern D_L39_0024C500_005D9BD8, 16");
extern u8 D_001D8194_sda;
extern u8 D_L39_0024C4F8[8];
extern s32 D_L39_0024C500_005D9BD8[2];
extern s32 *D_L39_002412A0;
extern S_005DC180 *D_001D5F30_sda_005D9BD8;
extern s32 func_L01_00512AB0(s32, s32, s32);

void func_L39_005D9BD8(s32 a0, s32 a1)
{
    if (D_001D8194_sda != 0) {
        if (a1 != 0 && D_L39_0024C4F8[a0] == 0) {
            D_L39_0024C500_005D9BD8[a0] = 0x1E;
        }
        D_L39_0024C4F8[a0] = a1;
        if (*D_L39_002412A0 == 1) {
            if (a1 != 0 && D_001D5F30_sda_005D9BD8->f18F != 0) {
                func_L01_00512AB0(0x50024, 1, 1);
            } else {
                func_L01_00512AB0(0x50024, 1, 0);
            }
            func_L01_00512AB0(0x50023, 1, 0);
        }
    }
}
/* localdecomp:end func_L39_005D9BD8 */
