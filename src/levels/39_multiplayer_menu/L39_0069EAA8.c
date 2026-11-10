#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0069EAA8);

LINKER_REMNANT("asm/levels", func_L39_0069EB08);

INCLUDE_ASM("asm/levels", func_L39_0069EB18);

LINKER_REMNANT("asm/levels", func_L39_0069F0F8);

/* localdecomp:start func_L39_0069F100 */
extern u8 D_L39_0047D410[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_0069F100(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047D410;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_0069F100 */

/* localdecomp:start func_L39_0069F128 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x4B0..0x4C0. */
extern f32 D_001DCD60_sda;
extern f32 D_001DCD64_sda;
extern f32 D_001DCD68_sda;
extern f32 D_001DCD6C_sda;
extern f32 D_001DCD70_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_0069F128(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DCD60_sda, D_001DCD64_sda, D_001DCD68_sda, D_001DCD6C_sda, D_001DCD70_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_0069F128 */

INCLUDE_ASM("asm/levels", func_L39_0069F168);

/* localdecomp:start func_L39_0069F310 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0069F310(void *);

extern void func_L39_0067F168();
void func_L39_0069F310(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_0069F310 */

INCLUDE_ASM("asm/levels", func_L39_0069F340);
