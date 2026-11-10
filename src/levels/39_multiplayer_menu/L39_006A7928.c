#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006A7928);

INCLUDE_ASM("asm/levels", func_L39_006A79C0);

INCLUDE_ASM("asm/levels", func_L39_006A8138);

INCLUDE_ASM("asm/levels", func_L39_006A83B8);

INCLUDE_ASM("asm/levels", func_L39_006A8E38);

LINKER_REMNANT("asm/levels", func_L39_006A8E80);

INCLUDE_ASM("asm/levels", func_L39_006A8E90);

INCLUDE_ASM("asm/levels", func_L39_006A8F08);

/* localdecomp:start func_L39_006A8F60 */
extern u8 D_001DD250_sda;
extern u8 D_001DD251_sda;
extern u16 *D_001DD254_sda;

s16 func_L39_006A8F60(s32 a0)
{
    s32 r = 0;
    s16 v;

    if (D_001DD250_sda != 0) {
        v = D_001DD254_sda[a0];
        r = v;
        if (D_001DD251_sda != 0) {
            r = ((v & 0xFF) << 8) | ((v >> 8) & 0xFF);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006A8F60 */

INCLUDE_ASM("asm/levels", func_L39_006A8FB0);

INCLUDE_ASM("asm/levels", func_L39_006A90F0);

INCLUDE_ASM("asm/levels", func_L39_006A9160);

/* localdecomp:start func_L39_006A9E68 */
extern u8 D_L39_0047DB98[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006A9E68(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DB98;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006A9E68 */

INCLUDE_ASM("asm/levels", func_L39_006A9E90);

INCLUDE_ASM("asm/levels", func_L39_006AA0F0);

/* localdecomp:start func_L39_006AA9B8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_0067F168();

void func_L39_006AA9B8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
    *(s32 *)((u8 *)p + 0x39C) = -1;
    *(s32 *)((u8 *)p + 0x3A0) = -1;
    *(s32 *)((u8 *)p + 0x3AC) = -1;
    *(s32 *)((u8 *)p + 0x3A8) = -1;
    *(s32 *)((u8 *)p + 0x3A4) = -1;
    *(s32 *)((u8 *)p + 0x3B0) = -1;
    *(s32 *)((u8 *)p + 0x3B4) = -1;
    *(s32 *)((u8 *)p + 0x3B8) = -1;
}
/* localdecomp:end func_L39_006AA9B8 */

INCLUDE_ASM("asm/levels", func_L39_006AAA08);
