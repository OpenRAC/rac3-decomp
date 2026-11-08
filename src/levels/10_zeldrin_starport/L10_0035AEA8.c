#include "common.h"

/* localdecomp:start func_L10_0035AEA8 */
typedef struct L19Thing {
    u8 pad[0xAA];
    s16 kind;
} L19Thing;
typedef struct L19Group {
    u8 pad0[0x44];
    s16 count;
    u8 pad1[0x1A0 - 0x46];
    L19Thing *items[1];      
} L19Group;
extern L19Group D_L10_001E5F00;
extern s32 D_L10_001D6694[] __attribute__((section(".sdata")));
extern u8 D_001D5471[] __attribute__((section(".sdata")));
extern u8 D_L10_001E0720[] __attribute__((section(".sdata")));
extern f32 D_L10_001E0740[] __attribute__((section(".sdata")));
extern void func_L01_0043A430(u8 *, u32, u8 *);

/* from rac2-decomp's func_L19_0042AF70 */
void func_L10_0035AEA8(L19Thing *a0)
{
    L19Thing *e;
    s32 i;
    if (D_L10_001D6694[0] != 2)
        return;
    if (D_001D5471[0] == 0)
        return;
    for (i = 0; i < D_L10_001E5F00.count; i++) {
        e = D_L10_001E5F00.items[i];
        if (e->kind != a0->kind)
            continue;
        if (D_L10_001E0720[1] != 0)
            continue;
        func_L01_0043A430((u8 *)e, 1, D_L10_001E0720);
        D_L10_001E0740[0] = 2.3f;
        D_L10_001E0740[1] = 2.3f;
        D_L10_001E0740[2] = 2.3f;
    }
}
/* localdecomp:end func_L10_0035AEA8 */

INCLUDE_ASM("asm/levels", func_L10_0035AF90);
