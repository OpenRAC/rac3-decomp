#include "common.h"

/* declared by functions of L32_003C4E00.c, which this file was cut from */
void func_L01_004450F0(void *, s32, s32);
void func_L32_003C5280(void *);
extern s32 D_L32_001E25F8;
extern f32 D_L32_001DF3A4;
extern s32 func_L01_004561B8(u8 *);
extern s32 func_0038CAD0(void *);
extern u8 D_001A30B0[];

/* localdecomp:start func_L32_003C5280 */
extern s32 func_L01_004561B8(u8 *);
extern void func_L30_0034C8A8(void *, void *);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001A30B0[];
extern s32 D_L32_001E25F8;
__asm__(".extern D_L32_001E25F8, 16");
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern s32 D_L32_001DF3B8;
__asm__(".extern D_L32_001DF3B8, 4");
extern s32 D_L32_001DF3AC;
__asm__(".extern D_L32_001DF3AC, 4");
extern f32 D_L32_001DF3A8;
__asm__(".extern D_L32_001DF3A8, 4");
extern f32 D_L32_001DF3A4;
__asm__(".extern D_L32_001DF3A4, 4");
extern f32 D_L32_001DF398;
__asm__(".extern D_L32_001DF398, 4");
extern s32 D_L32_001DF3E8;
__asm__(".extern D_L32_001DF3E8, 4");
extern f32 D_L32_001DF428;
__asm__(".extern D_L32_001DF428, 4");

void func_L32_003C5280(void *arg0) {
    u8 *a0 = arg0;
    u8 *p;
    u8 *q;
    s32 idx;

    p = *(u8 **)(a0 + 0x68);
    if (func_L01_004561B8(a0) != 0) {
        *(s32 *)(p + 0x18) = D_L32_001DF3B8;
        func_L30_0034C8A8(&D_L32_001E25F8, a0);
    }
    *(f32 *)(p + 0x10) = func_003C4088(D_L32_001DF3A8, D_L32_001DF3A4,
        func_L03_0034B440(1, 0, 5, (f32)D_L32_001DF9C0, (f32)D_L32_001DF3AC, 1.0f));

    idx = *(s32 *)(p + 0x20);
    if (idx == -1) {
        *(s32 *)(p + 0x20) = func_L01_004AAC98(10, 4, (s32)a0, 0x19D1);
    } else {
        q = D_001A30B0 + (idx << 7);
        if (*(s32 *)(q + 0xDC) != (s32)a0 || *(u8 *)(q + 0xD0) == 0) {
            *(s32 *)(p + 0x20) = func_L01_004AAC98(10, 4, (s32)a0, 0x19D1);
        }
    }
    func_L30_0034CF28(a0 + 0x10, p + 0x14, D_L32_001DF3E8, D_L32_001DF398, D_L32_001DF398);
    *(f32 *)(p + 0x1C) = func_0038DAB8(*(f32 *)(p + 0x1C), D_L32_001DF428);
    if (func_0038CAD0(p + 0x18) != 0) {
        func_L01_004450F0(a0, 2, -1);
    }
}
/* localdecomp:end func_L32_003C5280 */

INCLUDE_ASM("asm/levels", func_L32_003C53A0);
