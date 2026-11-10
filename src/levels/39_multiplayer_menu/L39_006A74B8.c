#include "common.h"

typedef struct S_006A5FE0 {
    u8 pad0[0x2B1];
    u8 f2B1;
    u8 pad1[6];
    s32 f2B8;
    s32 f2BC[576];
    s32 fBBC[1];
} S_006A5FE0;

typedef struct S_006A6108 {
    u8 pad0[0xCBC];
    u8 f_CBC;
    u8 pad1[7];
    s32 f_CC4;
    s32 f_CC8[1];
    u8 pad2[0x8FC];
    s32 f_15C8[1];
} S_006A6108;

typedef struct S_L39_006A6078 {
    u8 pad0[0x16CC];
    s32 f16CC;
    s32 f16D0[11];
    s32 f16FC[1];
} S_L39_006A6078;

/* localdecomp:start func_L39_006A74B8 */
s32 func_L39_0068ADC8(s32);
s32 func_L39_005C1A60(s32, s32, s32);
s32 func_L39_0067F168();

/* from rac4-decomp's func_L00_007457B0, renamed */
void func_L39_006A74B8(s32 arg0) {
    func_L39_0067F168();
    func_L39_0068ADC8(arg0);
    func_L39_005C1A60(0, 0, 0x400);
}
/* localdecomp:end func_L39_006A74B8 */

INCLUDE_ASM("asm/levels", func_L39_006A74F8);
