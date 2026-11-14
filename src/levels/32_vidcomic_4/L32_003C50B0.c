#include "common.h"

/* declared by functions of L32_003C4E00.c, which this file was cut from */
void func_L01_004450F0(void *, s32, s32);
void func_L32_003C50B0(void *);
extern f32 D_L32_001DF3A4;
extern s32 func_L01_004561B8(u8 *);
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_001A30B0[];

/* localdecomp:start func_L32_003C50B0 */
#include "vu0.h"
extern s32 func_L01_004561B8(u8 *);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001A30B0[];
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
extern vu0_v4 D_001A4C60;
extern u8 *D_L32_001E9998 __attribute__((section(".data")));
extern s32 D_L32_001DF9C0;
__asm__(".extern D_L32_001DF9C0, 16");
extern s32 D_L32_001DF3AC;
extern const f32 D_L32_001DF3A8_3C50B0;
extern f32 D_L32_001DF3A4;
extern s32 D_L32_001DF3DC;
extern f32 D_L32_001DF398;
extern f32 D_L32_001DF390;
extern f32 D_L32_001DF3BC;
extern f32 D_L32_001DF3B0;
extern f32 D_L32_001DF428;

void func_L32_003C50B0(void *arg0) {
    u8 *a0 = arg0;
    u8 *p;
    u8 *q;
    u8 *m;
    s32 idx;
    vu0_v4 d;

    p = *(u8 **)(a0 + 0x68);
    func_L01_004561B8(a0);
    *(f32 *)(p + 0x10) = func_003C4088(D_L32_001DF3A8_3C50B0, D_L32_001DF3A4,
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
    func_L30_0034CF28(a0 + 0x10, p + 0x14, D_L32_001DF3DC, D_L32_001DF398, 0.0f);
    vec_sub_ba(&d, &D_001A4C60, a0 + 0x10);
    func_0038CF68(&d, &d, D_L32_001DF390);
    vec_add_ba(p, p, &d);
    func_L30_0034D1E8(a0, a0 + 0x10, p, D_L32_001D66B0, *(f32 *)(p + 0x10), *(f32 *)(p + 0x10),
                      D_L32_001DF3BC, D_L32_001DF3BC, D_L32_001DF3B0, 0.0f, 1, 0, 0, 1);
    *(f32 *)(p + 0x1C) = func_0038DAB8(*(f32 *)(p + 0x1C), D_L32_001DF428);
    if (func_L01_003FB640(a0 + 0x10, 1, a0, D_L32_001DF3A8_3C50B0) != 0) {
        m = D_L32_001E9998;
        if (m != 0) {
            if (*(s16 *)(m + 0xAA) == *(s16 *)(*(u8 **)((u8 *)&D_001A4C60 + 0x2540) + 0xAA) ||
                *(s16 *)(m + 0xAA) == 0x19D1) {
                func_L01_004450F0(a0, 1, -1);
            }
        }
    }
}
/* localdecomp:end func_L32_003C50B0 */
