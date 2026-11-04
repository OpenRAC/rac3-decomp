#include "common.h"

typedef struct Foo_003102A8 {
    u8 pad30[0x30];
    u8 b30;
    u8 b31;
    u8 b32;
    u8 pad33[0x15];
    f32 f48;
} Foo_003102A8;

INCLUDE_ASM("asm/levels", func_L02_0030FA80);

INCLUDE_ASM("asm/levels", func_L02_0030FB58);

/* localdecomp:start func_L02_0030FC08 */
f32 func_L02_0030FC08(f32 x) {
    if (x < 0.0f) {
        x = -x;
        x = x - (f32)(s32)x;
        return 1.0f - x;
    }
    return x - (f32)(s32)x;
}
/* localdecomp:end func_L02_0030FC08 */

INCLUDE_ASM("asm/levels", func_L02_0030FC68);

INCLUDE_ASM("asm/levels", func_L02_0030FF48);

INCLUDE_ASM("asm/levels", func_L02_003102A8);

INCLUDE_ASM("asm/levels", func_L02_00310368);

/* localdecomp:start func_L02_00310428 */
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L02_0030FC68(void *);
extern void func_L02_003102A8(void *);
extern void func_L02_00310368(void *);
extern void func_L02_0030FF48(void *);

void func_L02_00310428(u8 *a0) {
    u8 *p;

    func_L01_004450F0(a0, 1, -1);
    p = *(u8 **)(a0 + 0x68);
    a0[0x30] = 0xFF;
    if (*(s32 *)p >= 0) {
        if (p[0x33] < 0x10) {
            *(s32 *)p = -1;
        }
    }
    func_L02_0030FC68(p);
    func_L02_003102A8(p);
    func_L02_00310368(p);
    func_L02_0030FF48(p);
}
/* localdecomp:end func_L02_00310428 */

INCLUDE_ASM("asm/levels", func_L02_003104A8);

INCLUDE_ASM("asm/levels", func_L02_00310730);

INCLUDE_ASM("asm/levels", func_L02_003107D8);

INCLUDE_ASM("asm/levels", func_L02_00310838);
