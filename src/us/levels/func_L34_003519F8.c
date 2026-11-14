#include "common.h"

/* localdecomp:start func_L34_003519F8 */
extern s32 D_L34_001DF3C0;
__asm__(".extern D_L34_001DF3C0, 16");
extern u8 D_001A30B0[];
extern s32 func_00388398(void *);
extern void func_L34_00351710(void *, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);
extern void func_L01_00441FB8(void *, s32, s32);

void func_L34_003519F8(u8 *a0) {
    u8 *p;
    u8 *e;
    f32 ph;
    f32 x;
    f32 y;
    s32 c;

    p = *(u8 **)(a0 + 0x68);
    ph = (f32)(D_L34_001DF3C0 % *(s32 *)p) / (f32)*(s32 *)p;
    switch (a0[0x20]) {
    case 0:
        *(s32 *)(p + 0x2C) = 0;
        *(s32 *)(p + 0x20) = 0;
        *(s32 *)(p + 0x24) = 0;
        *(s32 *)(p + 0x28) = 0;
        *(s32 *)(p + 0x18) = -1;
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (func_00388398(p + 0x10) == 0 || func_00388398(p + 0x14) == 0) {
            func_L34_00351710(a0, (f32)*(s32 *)(p + 0x10) / 10.0f, (f32)*(s32 *)(p + 0x14) / 22.0f);
            {
                s32 q = *(s32 *)(p + 0x18);
                if (q == -1 || (e = D_001A30B0 + (q << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                    *(s32 *)(p + 0x18) = func_0039FE80(0, 4, a0);
                }
            }
        } else {
            {
                s32 a1 = *(s32 *)(p + 0x18);
                if (a1 != -1) {
                    e = D_001A30B0 + (a1 << 7);
                    if (*(u8 **)(e + 0xDC) == a0 && e[0xD0] != 0) {
                        func_0039FB08(a1);
                    }
                }
            }
            *(s32 *)(p + 0x18) = -1;
        }
        if (ph < *(f32 *)(p + 8) && *(f32 *)(p + 4) < ph) {
            *(s32 *)(p + 0xC) = 0;
            *(s32 *)(p + 0x10) = 0;
            func_L01_00441FB8(a0, 2, -1);
        }
        break;
    case 2:
        c = *(s32 *)(p + 0xC) + 1;
        *(s32 *)(p + 0xC) = c;
        x = 1.0f;
        y = 1.0f;
        if (c < 0x14) {
            x = (f32)c / 20.0f;
        }
        if (c < 0x37) {
            y = (f32)c / 55.0f;
        }
        func_L34_00351710(a0, x, y);
        {
            s32 q = *(s32 *)(p + 0x18);
            if (q == -1 || (e = D_001A30B0 + (q << 7), *(u8 **)(e + 0xDC) != a0) || e[0xD0] == 0) {
                *(s32 *)(p + 0x18) = func_0039FE80(0, 4, a0);
            }
        }
        if (*(f32 *)(p + 8) < ph || ph < *(f32 *)(p + 4)) {
            *(s32 *)(p + 0x10) = 10;
            *(s32 *)(p + 0x14) = 0x16;
            func_L01_00441FB8(a0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L34_003519F8 */
