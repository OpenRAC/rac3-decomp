/* functional: high. Same calls, args, order and conditions as retail (verified against PAL asm); retail duplicates the 0x95 branches differently so the compiler output is not byte-identical (160 diff lines). */
#include "common.h"

/* localdecomp:start func_L05_003C6080 */
extern s32 D_001D545C;
extern u8 D_001A30B0[];
extern s32 func_L05_003C63A8(u8 *);
extern void func_L05_003C66F0(u8 *);
extern void func_L05_003C6920(u8 *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_00455E18(void *, void *, void *);
extern void func_L01_00452860(void *, void *, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);

s32 func_L05_003C6080(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 i;
    u8 *e;

    if (a0[0x20] == 0) {
        if (func_L05_003C63A8(a0) != 0) {
            return 1;
        }
    }
    i = *(s32 *)(p + 0x420);
    if (i == -1 || *(u8 **)((e = D_001A30B0 + (i << 7)) + 0xDC) != a0 || e[0xD0] == 0) {
        *(s32 *)(p + 0x420) = func_003A52A0(3, 4, a0);
    }
    if (p[0x3E] == 2) {
        func_L05_003C66F0(a0);
        return 1;
    }
    if (a0[0xBC] != 0) {
        a0[0xBC]--;
    }
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, (a0[0x20] == 4 && D_001D545C == 0xB) ? 1 : 0) != 0) {
        if (a0[0xBC] == 0) {
            func_003A52A0(4, 0, a0);
            a0[0xBC] = 0x19;
        }
        *(s16 *)(p + 0x42A) = 1;
        func_L05_003C6920(a0);
    }
    func_L01_00455E18(a0, p + 0x240, p + 0x30);
    func_L01_00452860(a0, p + 0x30, 0);
    if (p[0x5E] != 0) {
        func_L05_003C66F0(a0);
        return 1;
    }
    if (p[0x5F] != 0) {
        func_L01_00456BD0(a0, 5);
        if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), 0, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        func_L01_00456BD0(a0, 3);
        if (*(s16 *)(p + 0x42A) != 0) {
            func_L01_00456C98(a0, -1, 256.0f, 0, 0, 0, 0, 1, 0, 256.0f, 1.0f, 0, 0);
        } else if (a0[0x95] == 0) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), 0, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L05_003C6080 */
