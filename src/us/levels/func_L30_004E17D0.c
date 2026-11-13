#include "common.h"

/* NTSC-U counterpart of func_L30_004E56D0 (src/levels/shared/L30_004E5158.c): 255 -> 32 */
typedef struct S_004E56D0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B24 - 0x1B08];
    u8 *x1B24;
    u8 pad2[0x25C0 - 0x1B28];
    u8 *x25C0;
} S_004E56D0;
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
extern u8 *func_003C24B0(s32, s32);

/* localdecomp:start func_L30_004E17D0 */
void func_L30_004E17D0(void) {
    u8 *obj = 0;

    switch (((S_004E56D0 *)&D_001A4BE0)->x1B04) {
    case 1:
        obj = func_003C24B0(0x15D5, 0x80);
        break;
    case 2:
        obj = func_003C24B0(0x1C7D, 0x80);
        break;
    case 4:
        obj = func_003C24B0(0x1C7E, 0x80);
        break;
    case 3:
    case 5:
        obj = func_003C24B0(0x1C7C, 0x80);
        break;
    default:
        break;
    }

    if (obj != 0) {
        ((S_004E56D0 *)&D_001A4BE0)->x1B24 = obj;
        *(s16 *)(obj + 0x32) = 0x20;
        obj[0x31] = 1;
        *(long *)(obj + 0x38) = *(long *)(((S_004E56D0 *)&D_001A4BE0)->x25C0 + 0x38);
    }
}
/* localdecomp:end func_L30_004E17D0 */
