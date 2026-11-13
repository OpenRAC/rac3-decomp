#include "common.h"

/* localdecomp:start func_L30_003595C0 */
typedef struct { char p0[0xA0]; s32 fA0; char pA4[0x18]; s32 fBC; char pC0[0x14]; s32 fD4; } S_003595C0b;
typedef struct { char p0[0x68]; S_003595C0b *p68; } S_003595C0a;
extern s32 D_L30_001DE8FC[] __attribute__((section(".sdata")));
extern u8 D_00142BC4[]; __asm__(".extern D_00142BC4, 16");
extern u8 D_L30_001E8DC0[];
extern s32 func_00392B20(void *, s32);
extern s32 func_00392C78(void *);
void func_L30_003595C0(void *a0) {
    S_003595C0b *b = ((S_003595C0a *)a0)->p68;
    unsigned long t;
    D_L30_001DE8FC[0] = 0;
    b->fBC = -1;
    b->fA0 = 0;
    t = D_00142BC4[0];
    if ((t >> 7) == 0) {
        func_00392B20(D_L30_001E8DC0, 0x27);
        func_00392C78(D_L30_001E8DC0);
        b->fD4 = 1;
    }
}
/* localdecomp:end func_L30_003595C0 */
