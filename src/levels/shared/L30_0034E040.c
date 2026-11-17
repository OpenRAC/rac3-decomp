#include "common.h"

/* localdecomp:start func_L30_0034E040 */
#include "vu0.h"
typedef struct { s16 a, b; f32 c; s32 d, e, f; void *g; } S_0034E710;
extern S_0034E710 D_L30_001E1240 __attribute__((section(".sdata")));
extern S_0034E710 D_L30_001E1260 __attribute__((section(".sdata")));
extern s32 D_L30_001DD568; __asm__(".extern D_L30_001DD568, 4");
extern f32 D_L30_001DD584; __asm__(".extern D_L30_001DD584, 4");
extern f32 D_L30_001DD588; __asm__(".extern D_L30_001DD588, 4");
extern f32 D_L30_001DD590; __asm__(".extern D_L30_001DD590, 4");
extern s32 D_L30_001DD5C4; __asm__(".extern D_L30_001DD5C4, 4");
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_001A7E18[];
extern s32 D_001A66E8[];
extern void func_L30_0034E370(void *);
extern void func_L30_0034E710(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L01_0041A5B0(s32, s32);
extern void func_L01_0041BE28(s32, s32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern int func_L30_0034D8D8(void *, float);
extern void func_L03_0034B248(void *, void *);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
void func_L30_0034E040(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *p;
    u8 *q;
    f32 buf[4] __attribute__((aligned(16)));
    switch (a0[0x20]) {
    case 0:
        func_L30_0034E710(a0);
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(a0)) {
            *(u16 *)(a0 + 0x34) &= ~0x41;
            *(u16 *)(a0 + 0x34) |= *(u16 *)(*(u8 **)(a0 + 0x24) + 0x44) & 0x1000;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        if (D_L30_001DD5C4) {
            func_L01_004048D0(func_L30_0034E370, a0);
        } else {
            func_L01_00404A10(func_L30_0034E370, a0);
        }
        if (*(s32 *)(s + 0x1C)) {
            qzero(buf);
            buf[2] = D_L30_001DD588;
            func_L30_0034D1E8(a0, a0 + 0x10, s, buf, D_L30_001DD590, D_L30_001DD590, 1.0f, 0.0f, 0.08f, 0.0f, 1, 1, 0, 0);
        }
        if (func_0038CF00(D_001A4C60, a0 + 0x10) < D_L30_001DD584) {
            p = D_001A7E18;
            if (*(u16 *)(p + 0x9714) == 0) {
                if (func_L01_0041A5B0(0xC97, 0x5A) == 0) {
                    func_L01_0041BE28(0xC97, 0x5A);
                }
                if (*(u16 *)(p + 0x9714) == 0) {
                    *(u16 *)(p + 0x9714) = 1;
                }
            }
            func_L01_004AAC98(0, 0, (s32)a0, 0x1677);
            q = D_001A4BE0;
            if (*(s32 *)(q + 0x1B04) != *(s32 *)(s + 0x14)) {
                *(s32 *)(q + 0x1B04) = *(s32 *)(s + 0x14);
                *(s32 *)(q + 0x1B08) = *(s32 *)(s + 0x18);
            } else {
                *(s32 *)(q + 0x1B08) += *(s32 *)(s + 0x18);
            }
            if (*(s32 *)(s + 0x24) >= 0) {
                func_L01_004450F0(a0, 2, -1);
            } else {
                func_L01_004450F0(a0, 3, -1);
            }
        }
        if (func_L30_0034D8D8(a0 + 0x10, 1.5f)) {
            func_L03_0034B248(&D_L30_001E1260, a0);
            func_L30_0034C8A8(&D_L30_001E1240, a0);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(s + 0x20) = *(s32 *)(s + 0x24);
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a0, 1);
        }
        if (func_0038CAD0(s + 0x20) && D_001A66E8[0] < *(s32 *)(s + 0x28)) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a0, 1);
            *(s32 *)(s + 0x20) = D_L30_001DD568;
        }
        if (func_0038CAD0(s + 0x20)) {
            func_003C2880(a0);
        }
        break;
    }
}
/* localdecomp:end func_L30_0034E040 */
