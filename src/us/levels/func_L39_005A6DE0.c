#include "common.h"

/* NTSC-U counterpart of func_L39_005A8BF8 (src/levels/shared/L39_005A88B0.c) */
typedef struct { s32 f0; u8 p4[0x20]; struct { s32 f24; u8 p28[0x9C]; } c[1]; } S_005A8968;
extern S_005A8968 D_001A4560;

/* localdecomp:start func_L39_005A6DE0 */
typedef struct { u8 p0[0x148]; s32 f148; u8 p14C[0x10]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; u8 p16C[8]; s32 f174; u8 p178[4]; s32 f17C; } M_005A8BF8;
__asm__(".extern D_001D7978_sda, 4");
extern s32 D_001D7978_sda;
__asm__(".extern D_L39_002404A0, 16");
extern s32 D_L39_002404A0;
extern u8 D_L39_0021E3E0[];
extern void func_00139328(void *);
extern void func_00192508(void *);
s32 func_L39_005A6DE0(void) {
    func_00139328(&D_L39_002404A0);
    func_00192508(&D_L39_002404A0);
    if (((M_005A8BF8 *)&D_001A4560)->f148 == -1) return 0;
    if (((M_005A8BF8 *)&D_001A4560)->f17C != 0 && ((M_005A8BF8 *)&D_001A4560)->f15C < 3 && ((M_005A8BF8 *)&D_001A4560)->f164 < 0) {
        ((M_005A8BF8 *)&D_001A4560)->f174 = (s32)D_L39_0021E3E0;
        func_0039E7C8_005A6DE0(D_L39_0021E3E0, 0, &D_001D7978_sda);
        if (((M_005A8BF8 *)&D_001A4560)->f164 < 0) {
            ((M_005A8BF8 *)&D_001A4560)->f164 = 0x22;
            ((M_005A8BF8 *)&D_001A4560)->f168 = ((M_005A8BF8 *)&D_001A4560)->f148;
        }
    }
    return ((M_005A8BF8 *)&D_001A4560)->f164 == 0x22;
}
/* localdecomp:end func_L39_005A6DE0 */
