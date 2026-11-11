/* func_L32_003A2508: matches with `--as ps2as` and -mvu0-use-vf0-vf2 (tools/check.py MATCH), but its file
   src/levels/32_vidcomic_4/L32_003A0BB8.c cannot take @ps2as: the matched func_L32_003A0BB8 and func_L32_003A3E70 there need the default assembler
   (24/20/46 rows differ under ps2as). Lands when the file is split or the others match under ps2as. */
#include "common.h"
#include "vu0.h"

extern void func_0038CF68(void *, void *, f32);

void func_L32_003A2508(void *arg0v, s32 arg1, f32 arg2) {
    u8 *arg0 = arg0v;
    s32 i;
    u8 **p;
    u8 *obj;
    u8 *sub;

    p = (u8 **)(*(u8 **)(arg0 + 0x68) + 0x200);
    i = 5;
    do {
        obj = *p;
        i--;
        if (obj != 0) {
            sub = *(u8 **)(obj + 0x68);
            *(s32 *)(sub + 0x4C) = arg1;
            *(f32 *)(sub + 0x5C) = arg2;
            vec_sub_ab(sub + 0x20, arg0 + 0x10, *p + 0x10);
            func_0038CF68(sub + 0x20, sub + 0x20, 1.0f);
        }
        p++;
    } while (i >= 0);
}
