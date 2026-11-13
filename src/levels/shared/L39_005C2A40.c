#include "common.h"

/* localdecomp:start func_L39_005C2A40 */
/* from rac2-decomp's func_002B7C10 */
__asm__(".extern D_L39_002410E4, 16");
__asm__(".extern D_L39_00240428, 16");
typedef struct __attribute__((packed)) { u8 mode[4]; } CdMode_5C2A40;
extern CdMode_5C2A40 D_002256A0 __attribute__((section(".data")));
extern u8 D_L39_002410E4;
extern s32 D_L39_00240428;
extern s32 D_001D4D1C_sda __attribute__((section(".sdata")));
extern s32 func_00194670(void);
extern s32 func_00193590(void);
extern s32 func_00194970(s32, s32, s32, u8 *);

s32 func_L39_005C2A40(s32 a0, s32 a1, s32 a2) {
    CdMode_5C2A40 mode;
    mode = D_002256A0;
    mode.mode[1] = D_L39_002410E4;
    D_L39_00240428 = 0;
    D_001D4D1C_sda = 0;
    func_00194970(a1, a2, a0, mode.mode);
    func_00194670();
    func_00193590();
    return 1;
}
/* localdecomp:end func_L39_005C2A40 */
