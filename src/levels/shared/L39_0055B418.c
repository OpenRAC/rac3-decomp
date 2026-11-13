#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0055B418);

INCLUDE_ASM("asm/levels", func_L39_0055B4D8);

/* localdecomp:start func_L39_0055D598 */
extern s32 D_L39_00242914[];
extern u8 *D_L39_0024BF5C __attribute__((section(".data")));
extern u8 *D_L39_0024BF64 __attribute__((section(".data")));
extern f32 D_L39_0024B3C0;
__asm__(".extern D_L39_0024B3C0, 4");
extern u8 D_L39_0024B3B8[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024B3B8, 8");
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);

typedef struct S_0055D598 {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0xF];
    u8 f30;
    u8 f31;
    s16 f32;
    u16 f34;
    u8 pad36[0x32];
    u8 **f68;
    u8 pad6C[0xC];
    s32 f78;
} S_0055D598;

S_0055D598 *func_L39_0055D598(u8 *a0) {
    S_0055D598 *p;
    if (D_L39_00242914[0] == 0 && a0[0x1A14] != 0) {
        return 0;
    }
    p = (S_0055D598 *)func_003C24B0(0x1935, 0x80);
    if (p != 0) {
        u8 **owner = p->f68;
        if (D_L39_0024B3C0 == 0.0f) {
            u8 *q;
            for (q = D_L39_0024BF5C; q < D_L39_0024BF64; q += 0x100) {
                if (*(s16 *)(q + 0xAA) == 0x1C57) {
                    D_L39_0024B3C0 = *(f32 *)(q + 0x18) + 10.0f;
                    break;
                }
            }
        }
        p->f30 = 0xFF;
        p->f31 = 1;
        p->f34 |= 0x110;
        p->f32 = 0;
        p->f20 = 0;
        p->f78 = ((s32 *)D_L39_0024B3B8)[*(s32 *)(a0 + 0x2548)];
        *owner = a0;
        p->f34 |= 0x41;
        func_003C7C38(p);
    }
    return p;
}
/* localdecomp:end func_L39_0055D598 */
