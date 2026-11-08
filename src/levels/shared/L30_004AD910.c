#include "common.h"

typedef struct { u8 pad[0x24]; s32 anim; u8 pad2[0xF0 - 0x28]; } Entry_4AD910;

/* localdecomp:start func_L30_004AD910 */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];

extern u8 D_L30_002C3E80[];
extern s32 D_001DBBD4;
extern s32 func_L01_004E9238(s32 a);
extern s32 func_L01_004DFD60(void);

s32 func_L30_004AD910(s32 a0) {
    switch (D_001A4BE0[0x25E4]) {
    case 3:
        return 1;
    case 1:
        return D_001DBBD4 == 0 ? 0x14 : 0x1D;
    case 5:
        return 1;
    }
    if (a0 != 0 && D_001A4BE0[0x25EB] != 0 && *(s16 *)(D_001A4BE0 + 0x2874) == 0) {
        s32 idx = func_L01_004E9238(0);
        return ((Entry_4AD910 *)(D_L30_002C3E80 + D_001425C0[idx] * 0xF0))->anim;
    }
    if (func_L01_004DFD60() == 0)
        return D_001A4BE0[0x1474] != 0 ? 0x55 : 0;
    return 0x4A;
}
/* localdecomp:end func_L30_004AD910 */
