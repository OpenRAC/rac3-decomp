#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
void func_L32_003A14C8(void *, s32);

/* localdecomp:start func_L32_003A14C8 */
extern s32 D_L32_001DE6DC;
extern s32 D_L32_001DE6E4;
extern s32 D_L32_001DE6E8;
extern s32 D_L32_001DE6EC;
extern u16 D_L32_001DE7F4;
extern u8 D_L32_001DE80C;
extern f32 D_L32_001DE7B4;
extern f32 D_L32_001DE7B8;
extern f32 D_L32_001DE7BC;
extern f32 D_L32_001DE808;
extern f32 D_L32_001DE7C0;
extern f32 D_L32_001DE7C4;
extern s32 D_L32_001E2224;
extern f32 D_L32_001E2228;
extern f32 D_L32_001E222C;
__asm__(".extern D_L32_001DE6DC, 4");
__asm__(".extern D_L32_001DE6E4, 4");
__asm__(".extern D_L32_001DE6E8, 4");
__asm__(".extern D_L32_001DE6EC, 4");
__asm__(".extern D_L32_001DE7F4, 2");
__asm__(".extern D_L32_001DE80C, 1");
__asm__(".extern D_L32_001DE7B4, 4");
__asm__(".extern D_L32_001DE7B8, 4");
__asm__(".extern D_L32_001DE7BC, 4");
__asm__(".extern D_L32_001DE808, 4");
__asm__(".extern D_L32_001DE7C0, 4");
__asm__(".extern D_L32_001DE7C4, 4");
__asm__(".extern D_L32_001E222C, 4");
extern u8 D_1A30B0[];
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(u32);
extern void func_L32_003A1E58(void *);
extern void func_L32_003B8498(void *, f32, f32, f32, s32, u8, s32, s32, f32, s32, s32);
extern void func_L32_003A3310(void *);

void func_L32_003A14C8(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    s32 i;
    s32 n;
    u8 *e;

    *(s32 *)(p + 0x21C) = arg1;
    *(s32 *)(p + 0x220) = 0;
    switch (arg1) {
    case 0:
        *(s32 *)(p + 0x220) = D_L32_001DE6DC - 1;
        func_003A52A0(1, 0, arg0);
        break;
    case 2:
        *(s32 *)(p + 0x220) = D_L32_001DE6E4 - 1;
        *(s32 *)(p + 0x1EC) = 0;
        *(s32 *)(p + 0x1F0) = 0;
        func_L32_003A1E58(arg0);
        *(u16 *)(p + 0x1FA) = D_L32_001DE7F4;
        p[0x1F9] = 1;
        *(s32 *)(p + 0x1E8) = 0;
        p[0x1F8] = 0;
        for (i = 2; i >= 0; i--) {
            ((s32 *)(p + 0x1D0))[i] = 0;
        }
        func_L32_003B8498(p + 0x1C0, D_L32_001DE7B4, D_L32_001DE7B8, D_L32_001DE7BC, 0xC4,
                          D_L32_001DE80C, 0, 0x5A, D_L32_001DE808, 0x3C, 0);
        func_L32_003A3310(p + 0x1C0);
        D_L32_001E2224 = D_L32_001DE6E4;
        D_L32_001E2228 = D_L32_001DE7C0;
        D_L32_001E222C = D_L32_001DE7C4;
        break;
    case 3:
        *(s32 *)(p + 0x220) = D_L32_001DE6E8 - 1;
        func_003A52A0(2, 0, arg0);
        break;
    case 1:
        *(s32 *)(p + 0x220) = D_L32_001DE6EC;
        func_003A52A0(0, 0, arg0);
        p[0x229] = 0;
        break;
    case 4:
        p[0x229] = 1;
        p[0x228] = 0;
        n = *(s32 *)(p + 0x1F4);
        if (n != -1) {
            e = D_1A30B0 + n * 128;
            if (*(void **)(e + 0xDC) == arg0 && e[0xD0] != 0) {
                func_003A4F28(n);
            }
        }
        *(s32 *)(p + 0x1F4) = -1;
        break;
    }
}
/* localdecomp:end func_L32_003A14C8 */
