#include "common.h"

/* localdecomp:start func_L08_003A0888 */
extern s32 func_L08_003A0AC0(void *);
extern void func_L08_003A0D40(void *);
extern void *func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern u8 func_L01_0044CE88(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L08_003A0E90(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);

s32 func_L08_003A0888(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *q;

    if (a0[0x20] == 0 && func_L08_003A0AC0(a0) != 0) return 1;
    if (p[0x3E] == 2) goto done;
    q = (u8 *)func_L01_00447490(a0, 0x10000, 0);
    if (func_0038CB00(p + 0x36) == 0) q = 0;
    if (q != 0 && a0[0x95] != 5) {
        p[0x47] = func_L01_0044CE88(*(void **)(q + 0x20));
        *(f32 *)(p + 0x30) -= *(f32 *)(q + 0x2C);
        func_L01_004450F0(a0, 12, 3);
        func_L08_003A0E90(a0);
    }
    a0[0xA8] = 0xFF;
    if (a0[0x95] != 5) func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5E] != 0) {
done:
        func_L08_003A0D40(a0);
        return 1;
    }
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x184), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x188), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x18C), 10.0f, 1.0f);
    } else {
        if (a0[0x95] == 2) func_L01_00456BD0(a0, 3);
        if (a0[0x95] == 0) func_L01_00456C98(a0, *(s32 *)(p + 0x180), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x184), 10.0f, 1.0f);
        else func_L01_00456C98(a0, *(s32 *)(p + 0x188), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x18C), 10.0f, 1.0f);
    }
    return 0;
}
/* localdecomp:end func_L08_003A0888 */
