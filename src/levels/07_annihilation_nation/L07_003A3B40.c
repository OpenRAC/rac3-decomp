#include "common.h"

/* localdecomp:start func_L07_003A3B40 */
extern s32 func_L01_0033D178(void *);
extern s32 D_L07_001DF41C;
extern s32 D_L07_001DF41C_sda;
__asm__(".extern D_L07_001DF41C, 16");
__asm__(".extern D_L07_001DF41C_sda, 4");

s32 func_L07_003A3B40(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    s32 a, r;

    if (func_L01_0033D178((u8 *)D_L07_001DF41C + (*(s32 *)p << 8)) == 0)
        return 0;
    a = *(s32 *)(p + 4);
    if (a != -1) {
        r = func_L01_0033D178((u8 *)D_L07_001DF41C_sda + (a << 8));
        if (r == 0)
            return 1;
    }
    return -1;
}
/* localdecomp:end func_L07_003A3B40 */

/* localdecomp:start func_L07_003A3BB0 */
extern s32 func_L07_003A3B40(void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32,
                              f32, f32, f32, f32, f32, f32);
extern void func_L01_0033D0E8(u8 *);
extern u8 D_L07_001D66B0[8];
extern s32 D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");

void func_L07_003A3BB0(void *arg0, s32 arg1) {
    s32 r;
    u8 *p;
    u8 *t;
    s32 idx;

    r = func_L07_003A3B40(arg0);
    if (r != arg1)
        return;
    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (r != 0)
        idx = *(s32 *)(p + 4);
    else
        idx = *(s32 *)p;
    t = (u8 *)D_L07_001DF41C;
    t += idx << 8;
    func_L01_00451FE0(t, 0x25, D_L07_001D66B0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f,
                      6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
    func_L01_0033D0E8(t);
}
/* localdecomp:end func_L07_003A3BB0 */
