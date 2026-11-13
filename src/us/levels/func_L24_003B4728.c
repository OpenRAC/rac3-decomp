#include "common.h"

/* NTSC-U counterpart of func_L24_003B6320 (src/levels/24_insomniac_museum/L24_003B6050.c): 0.12 -> 0.1 */
/* localdecomp:start func_L24_003B4728 */
extern s32 D_001D545C;
extern s32 func_L24_003B48D0(void);
extern void func_L01_0044CB08(void *, s32, s32, s32);
extern void func_L01_00402498(void *, void *);
extern void func_L24_003B4AD0(void);
extern void func_L24_003B4E00(void *);
extern f32 func_L01_00436500(void *);
extern void func_003C4138(void *, f32, f32);

s32 func_L24_003B4728(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f1;
    if (a0[0x20] == 0 && func_L24_003B48D0() != 0) {
        return 1;
    }
    if (*(s32 *)(p + 0x900) < 6) {
        *(s32 *)(p + 0x900) += 1;
    }
    if (*(s32 *)(p + 0x8DC) != 0) {
        func_L01_0044CB08(a0, *(s32 *)(p + 0x8DC), 0, 0);
        func_L01_00402498(func_L24_003B4AD0, a0);
        func_L24_003B4E00(a0);
    }
    f1 = func_L01_00436500(a0);
    if (a0[0x43] == 0 || (a0[0x42] == 3 && f1 > 17.0f)) {
        func_003C4138(p + 0x8E4, 2.0f, 0.100000009f);
        func_003C4138(p + 0x8E8, 2.0f, 0.100000009f);
    } else if (a0[0x42] == 5 && f1 > 16.0f) {
        func_003C4138(p + 0x8E4, 3.5f, 0.100000009f);
        func_003C4138(p + 0x8E8, 1.5f, 0.100000009f);
    }
    if (D_001D545C == 0x18) {
        *(f32 *)(a0 + 0x18) = 101.86f;
    } else {
        *(f32 *)(a0 + 0x18) = 48.84f;
    }
    return 0;
}
/* localdecomp:end func_L24_003B4728 */
