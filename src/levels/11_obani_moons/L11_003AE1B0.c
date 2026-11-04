#include "common.h"

typedef struct List_003AE1B0 {
    u8 pad0[0x44];
    s16 count;
    u8 pad46[0x1A0 - 0x46];
    u32 *entries[1];
} List_003AE1B0;

/* localdecomp:start func_L11_003AE1B0 */
extern s32 D_L11_001D6694;
extern u8 D_001D5471;
extern List_003AE1B0 D_L11_001E5AC0;
extern u8 D_L11_001E02A0;
extern u8 D_L11_001E02A1;
extern f32 D_L11_001E02C0;
extern f32 D_L11_001E02C4;
extern f32 D_L11_001E02C8;
extern void func_L01_0043A430(u32 *, s32, u8 *);

void func_L11_003AE1B0(u8 *arg) {
    u32 *elem;
    s32 i;

    if (D_L11_001D6694 == 2) {
        if (D_001D5471 != 0) {
            for (i = 0; i < D_L11_001E5AC0.count; i++) {
                elem = D_L11_001E5AC0.entries[i];
                if (*(s16 *)((u8 *)elem + 0xAA) == *(s16 *)(arg + 0xAA)) {
                    if (D_L11_001E02A1 == 0) {
                        func_L01_0043A430(elem, 0, &D_L11_001E02A0);
                        D_L11_001E02C0 = 2.75f;
                        D_L11_001E02C4 = 2.75f;
                        D_L11_001E02C8 = 2.75f;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L11_003AE1B0 */

INCLUDE_ASM("asm/levels", func_L11_003AE290);

INCLUDE_ASM("asm/levels", func_L11_003AE938);

INCLUDE_ASM("asm/levels", func_L11_003AEA18);

INCLUDE_ASM("asm/levels", func_L11_003AEBE8);

INCLUDE_ASM("asm/levels", func_L11_003AEDE8);

INCLUDE_ASM("asm/levels", func_L11_003AF058);

INCLUDE_ASM("asm/levels", func_L11_003AF6B8);

INCLUDE_ASM("asm/levels", func_L11_003AFD48);

INCLUDE_ASM("asm/levels", func_L11_003AFF60);
