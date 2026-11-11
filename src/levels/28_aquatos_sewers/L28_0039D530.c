#include "common.h"

INCLUDE_ASM("asm/levels", func_L28_0039D530);

INCLUDE_ASM("asm/levels", func_L28_0039E820);

INCLUDE_ASM("asm/levels", func_L28_0039EBC8);

INCLUDE_ASM("asm/levels", func_L28_0039EDB8);

/* localdecomp:start func_L28_0039F010 */
extern u8 D_L28_001E1540[];
extern void func_L01_00404808(void *, void *);
extern void func_L08_0039F4E8(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(f32, u32, u32);
void func_L28_0039F010(u8 *a0) {
    u8 *d = *(u8 **)(a0 + 0x68);
    f32 t;
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE) *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L28_001E1540, a0 + 0x10) < 1024.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x1E;
        }
    }
    if (a0[0x20] != 1 && a0[0x31] != 0) func_L01_00404808(func_L08_0039F4E8, a0);
    t = func_0038DAB8(*(f32 *)(d + 0x1DC), 0.15358898f);
    *(f32 *)(d + 0x1DC) = t;
    *(s32 *)(a0 + 0x78) = func_0038DBD8((func_0038D0B0(t) + 1.0f) * 0.5f, 0x8000A0A0, 0x80005050);
}
/* localdecomp:end func_L28_0039F010 */
