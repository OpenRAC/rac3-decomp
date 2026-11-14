#include "common.h"

/* NTSC-U-only function (flags of its neighbours: @ps2as is not used here) */
/* localdecomp:start func_L07_003D7790 */
extern u8 D_00142764[];
extern u8 D_00142763[];
extern void func_L07_003A0BC0(s32, s32, s32, s32);
extern s32 func_L07_003335B8(s32, s32);
extern void func_L07_003D78E8(u8 *, s32, s32, s32, f32);

void func_L07_003D7790(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    s32 i;
    s32 j;
    u8 *p;

    for (i = 1; i >= 0; i--) {
        *(s32 *)(sub + 0x20 + i * 4) = 0;
    }
    if (sub[0x13] != 0) {
        if (D_00142764[0] == 0) {
            func_L07_003A0BC0(0x1C, *(s32 *)sub, 0, 0x78);
        }
        sub[0x3C] = 1;
        func_L07_003D78E8(obj, func_L07_003335B8(*(s32 *)sub, 0), sub[0x3C], 0, 0.0f);
    } else if (*(u16 *)(sub + 0x14) != 0) {
        if (D_00142763[0] == 0) {
            func_L07_003A0BC0(0x1B, *(s32 *)sub, 0, 0x78);
        }
        sub[0x3C] = 1;
        func_L07_003D78E8(obj, func_L07_003335B8(*(s32 *)sub, 1), sub[0x3C], 0, 1.0f);
        func_L07_003D78E8(obj, func_L07_003335B8(*(s32 *)sub, 2), sub[0x3C], 1, -1.0f);
    }
    p = sub + 0x15;
    for (j = 2; j >= 0; j--) {
        *p = 0;
        p--;
    }
}
/* localdecomp:end func_L07_003D7790 */
