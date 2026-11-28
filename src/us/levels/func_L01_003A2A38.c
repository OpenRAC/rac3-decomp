#include "common.h"
/* localdecomp:start func_L01_003A2A38 */
typedef int u128_3A4180 __attribute__((mode(TI)));
extern void func_003BDA38(void *, s32, void *);
extern void func_003C26C8(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);

void func_L01_003A2A38(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 **pp;
    u8 *m;
    s32 i;
    s32 j;
    u128_3A4180 tmp;

    pp = (u8 **)(v + 0x2F0);
    for (i = 0; i < 2; i++, pp++) {
        m = *pp;
        if (m != 0 && *(s16 *)(m + 0xAA) == 0x1939 && *(u8 **)(m + 0xB8) == a0 && m[0x20] != 0xFE && m[0x20] != 0xFD) {
            u8 *mv = *(u8 **)(m + 0x68);
            if (i != 0) {
                func_003BDA38(a0, 3, &tmp);
            } else {
                func_003BDA38(a0, 2, &tmp);
            }
            *(u128_3A4180 *)(mv + 0x20) = tmp;
        } else {
            *pp = 0;
        }
    }
    pp = (u8 **)(v + 0x3F0);
    for (j = 0; j < 8; j++) {
        if (pp[j] != 0) {
            *(s32 *)(pp[j] + 0x98) = 0;
            func_003C26C8(pp[j]);
        }
    }
    func_L01_0044B5C8(a0, v + 0x300, 4, 0.0299999993f, 0.300000012f);
    func_00388398(v + 0x2E0);
    func_003883C8(v + 0x2E4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    func_L01_0044EB78(a0, v + 0x250, 5, 1, 2.5f);
}
/* localdecomp:end func_L01_003A2A38 */
