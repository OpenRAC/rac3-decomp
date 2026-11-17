#include "common.h"

/* NTSC-U counterpart of func_L01_00510E40 (src/levels/shared/L01_0050F9E8.c) */
typedef struct {
    u8 pad0[0xC20];
    s32 xC20;
    s32 xC24;
    s32 xC28;
} D_001A4BE0_t;
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;
extern D_001A4BE0_t D_001A4BE0;

/* localdecomp:start func_L01_0050CE68 */
typedef struct {
    u8 p0[0x218];
    s16 h218;
    u8 p21A[0x368 - 0x21A];
    s16 h368;
    u8 p36A[0x36E - 0x36A];
    s16 h36E;
    u8 p370[0x1479 - 0x370];
    u8 b1479;
    u8 p147A[2];
    u8 b147C;
    u8 p147D[0x25C4 - 0x147D];
    s32 state;
} H_510E40;
extern s32 D_L01_001D673C_0050CE68;
extern s32 D_L01_001D6740_0050CE68;
__asm__(".extern D_L01_001D6740_0050CE68, 4");
extern u8 D_00142CAD[];

s32 func_L01_0050CE68(void) {
    s32 r = (*(H_510E40 *)&D_001A4BE0).h368;
    if (D_L01_001D673C_0050CE68 != 0 && D_L01_001D6740_0050CE68 == 0) {
        r = 2;
    }
    if (D_L01_001D6740_0050CE68 != 0 || (*(H_510E40 *)&D_001A4BE0).state == 0x3B || ((*(H_510E40 *)&D_001A4BE0).state == 0x73 && (*(H_510E40 *)&D_001A4BE0).b147C == 0) || (*(H_510E40 *)&D_001A4BE0).state == 0x72 ||
        (*(H_510E40 *)&D_001A4BE0).h218 != 0 || ((*(H_510E40 *)&D_001A4BE0).b1479 != 0 && D_00142CAD[0] != 0 && (*(H_510E40 *)&D_001A4BE0).state == 0 && (*(H_510E40 *)&D_001A4BE0).h36E < 4)) {
        r = 1;
    }
    if (r == 1 && (*(H_510E40 *)&D_001A4BE0).b147C != 0 && (*(H_510E40 *)&D_001A4BE0).b1479 == 0) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L01_0050CE68 */
