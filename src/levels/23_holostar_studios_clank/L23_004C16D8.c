#include "common.h"

typedef struct { u8 pad[0x24]; s32 f; u8 pad2[0xC8]; } E240;

/* localdecomp:start func_L23_004C16D8 */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];

extern E240 D_L23_002C6740[];
extern s32 D_001DBD14;
extern s32 func_L01_004E9238(s32 a);
extern s32 func_L01_004DFD60(void);

s32 func_L23_004C16D8(s32 arg) {
    s32 mode = D_001A4BE0[0x25E4];
    s32 r;
    switch (mode) {
    case 1:
        return D_001DBD14 == 0 ? 0x14 : 0x1D;
    case 2:
        return 0;
    case 3:
        return 1;
    }
    if (arg != 0 && D_001A4BE0[0x25EB] != 0 && *(s16 *)(D_001A4BE0 + 0x2874) == 0) {
        r = func_L01_004E9238(0);
        return (&D_L23_002C6740[0] + D_001425C0[r])->f;
    }
    if (func_L01_004DFD60() == 0) {
        return D_001A4BE0[0x1474] != 0 ? 0x55 : 0;
    }
    return 0x4A;
}
/* localdecomp:end func_L23_004C16D8 */
