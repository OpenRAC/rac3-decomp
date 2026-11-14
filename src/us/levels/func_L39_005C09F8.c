#include "common.h"

/* NTSC-U counterpart of func_L39_005C2A40 (src/levels/shared/L39_005C2A40.c) */
/* localdecomp:start func_L39_005C09F8 */
/* from rac2-decomp's func_002B7C10 */
__asm__(".extern D_L39_00241264, 16");
__asm__(".extern D_L39_002405A8, 16");
typedef struct __attribute__((packed)) { u8 mode[4]; } CdMode_5C2A40;
extern CdMode_5C2A40 D_L39_00225820 __attribute__((section(".data")));
extern u8 D_L39_00241264;
extern s32 D_L39_002405A8;
extern s32 D_001D4D1C_sda_005C09F8 __attribute__((section(".sdata")));
extern s32 func_00194760(void);
extern s32 func_00193680(void);
extern s32 func_00194A60(s32, s32, s32, u8 *);

s32 func_L39_005C09F8(s32 a0, s32 a1, s32 a2) {
    CdMode_5C2A40 mode;
    mode = D_L39_00225820;
    mode.mode[1] = D_L39_00241264;
    D_L39_002405A8 = 0;
    D_001D4D1C_sda_005C09F8 = 0;
    func_00194A60(a1, a2, a0, mode.mode);
    func_00194760();
    func_00193680();
    return 1;
}
/* localdecomp:end func_L39_005C09F8 */
