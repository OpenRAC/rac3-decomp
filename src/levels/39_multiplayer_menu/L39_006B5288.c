#include "common.h"

/* localdecomp:start func_L39_006B5288 */
void func_L39_006B5288(void *arg0, s32 arg1, s8 arg2) {
    *(s8 *)((u8 *)arg0 + 0x2B4) = arg2;
    *(s8 *)((u8 *)arg0 + 0x2B6) = 1;
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
}
/* localdecomp:end func_L39_006B5288 */

INCLUDE_ASM("asm/levels", func_L39_006B52A0);

INCLUDE_ASM("asm/levels", func_L39_006B5498);

INCLUDE_ASM("asm/levels", func_L39_006B5D00);

INCLUDE_ASM("asm/levels", func_L39_006B5F20);

INCLUDE_ASM("asm/levels", func_L39_006B6158);

LINKER_REMNANT("asm/levels", func_L39_006B6388);

INCLUDE_ASM("asm/levels", func_L39_006B63B8);

LINKER_REMNANT("asm/levels", func_L39_006B6648);

/* localdecomp:start func_L39_006B6650 */
extern u8 D_L39_0047E540[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B6650(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E540;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B6650 */

/* localdecomp:start func_L39_006B6678 */
/* Same shape as func_L39_0069E768 (task 4); constants from the $gp slots 0x111C..0x112C. */
extern f32 D_001DD9CC_sda;
extern f32 D_001DD9D0_sda;
extern f32 D_001DD9D4_sda;
extern f32 D_001DD9D8_sda;
extern f32 D_001DD9DC_sda;
extern void func_L39_00688460(void *a0, f32 f1, f32 f2, f32 f3, f32 f4, f32 f5, void *p1, void *p2, void *p3, void *p4, void *p5);

void func_L39_006B6678(void *a0)
{
    s32 v[4];
    func_L39_00688460(a0, D_001DD9CC_sda, D_001DD9D0_sda, D_001DD9D4_sda, D_001DD9D8_sda, D_001DD9DC_sda, v, v, v, v, v);
}
/* localdecomp:end func_L39_006B6678 */

INCLUDE_ASM("asm/levels", func_L39_006B66B8);

/* localdecomp:start func_L39_006B6860 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_006B6860(void *);

extern void func_L39_0067F168();
void func_L39_006B6860(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_006B6860 */

INCLUDE_ASM("asm/levels", func_L39_006B6890);
