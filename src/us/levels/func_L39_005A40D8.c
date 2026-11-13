#include "common.h"

/* NTSC-U counterpart of func_L39_005A5D48 (src/levels/shared/L39_005A5C90.c) */
extern s32 D_L39_0024057C;

/* localdecomp:start func_L39_005A40D8 */
typedef struct S_005A5D48 { s32 pad0[4]; s32 x10; s32 pad14[0x4D]; s32 x148; } S_005A5D48;
extern S_005A5D48 D_001A4560;
extern s32 D_L39_002431E4;
extern s32 D_L39_002431E8;
extern s32 D_L39_002431EC;
extern s32 D_L39_002431F0;
extern s32 D_L39_002431F4;
extern s32 D_L39_0024057C_005A40D8;
extern u8 D_L39_0024BF70;
extern u8 D_L39_0024BF78;
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024BF78, 16");
__asm__(".extern D_L39_0024057C, 16");
extern s32 func_00397058();
extern void func_00397238(void);

s32 func_L39_005A40D8(s32 a, s32 b)
{
    s32 r = func_00397058(a);
    if (r != 0) {
        s32 f = D_L39_0024057C_005A40D8;
        f |= 0x10;
        f &= ~4;
        f &= ~2;
        D_L39_002431F4 = b;
        D_001A4560.x148 = 0;
        D_L39_0024057C = f & ~0x40;
        D_001A4560.x10 = 0;
        D_L39_002431E4 = 0;
        D_L39_002431E8 = 0;
        D_L39_002431EC = 0;
        D_L39_002431F0 = 0;
        D_L39_0024BF78 = 0;
        D_L39_0024BF70 = 0;
        func_00397238();
    }
    return r;
}
/* localdecomp:end func_L39_005A40D8 */
