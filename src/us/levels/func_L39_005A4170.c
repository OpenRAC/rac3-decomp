#include "common.h"

/* NTSC-U counterpart of func_L39_005A5DE0 (src/levels/shared/L39_005A5C90.c) */
extern s32 D_L39_0024057C;
typedef struct S_005A5D48 { s32 pad0[4]; s32 x10; s32 pad14[0x4D]; s32 x148; } S_005A5D48;
extern S_005A5D48 D_001A4560;
extern s32 D_L39_002431E4;
extern s32 D_L39_002431E8;
extern s32 D_L39_002431EC;
extern s32 D_L39_002431F0;
extern s32 D_L39_002431F4;
extern u8 D_L39_0024BF70;
extern u8 D_L39_0024BF78;
extern s32 D_L39_0024057C;

/* localdecomp:start func_L39_005A4170 */
extern s32 D_L39_002431E4;
extern s32 D_L39_002431E8;
extern s32 D_L39_002431EC;
extern s32 D_L39_002431F0;
extern s32 D_L39_002431F4;
extern s32 D_L39_002431F8;
extern u8 D_L39_0024BF70;
extern u8 D_L39_0024BF78;
extern s32 D_L39_0024057C;
__asm__(".extern D_L39_0024BF78, 16");
__asm__(".extern D_L39_0024057C, 16");
extern void func_00397238(void);

void func_L39_005A4170(s32 a, s32 b, s32 c)
{
    D_L39_002431E4 = a;
    D_L39_002431E8 = c;
    D_L39_002431F8 = b;
    D_001A4560.x148 = 0;
    D_L39_002431EC = 0;
    D_L39_002431F0 = 0;
    D_L39_002431F4 = 0;
    D_L39_0024BF78 = 0;
    D_L39_0024BF70 = 0;
    func_00397238();
    D_001A4560.x10 = 0;
    {
        s32 f = D_L39_0024057C;
        f &= ~4;
        f |= 2;
        f &= ~0x40;
        f &= ~0x10;
        f &= ~0x4000;
        D_L39_0024057C = f;
    }
}
/* localdecomp:end func_L39_005A4170 */
