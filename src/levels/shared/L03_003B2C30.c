#include "common.h"

/* localdecomp:start func_L03_003B2C30 */
typedef int u128_003B2C30 __attribute__((mode(TI)));
extern u8 D_00142700[];
extern void func_003C2880(void *);
extern void func_0038D308(void *, void *);
extern void func_L03_003B2E38(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_00448890(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038DBA0(f32, f32);

void func_L03_003B2C30(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        if (D_00142700[0] != 0) {
            func_003C2880(m);
            return;
        }
        func_0038D308(m + 0xC0, m + 0xF0);
        *(u128_003B2C30 *)(v + 0x20) = *(u128_003B2C30 *)(m + 0xC0);
        *(f32 *)(v + 0xC) = *(f32 *)(m + 0xF8);
        func_L03_003B2E38(m);
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        func_L01_00448890(m + 0xF8, *(f32 *)(v + 0xC), v, 0.00125663716f, 0.00251327432f, 0.146607667f, 0);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(s32 *)(v + 4) = 0;
        break;
    case 2:
        func_L01_00448890(m + 0xF8, *(f32 *)(v + 8), v, 0.00125663716f, 0.00251327432f, 0.146607667f, 0);
        func_0038D308(m + 0xC0, m + 0xF0);
        *(s32 *)(v + 4) = func_0038DBA0(*(f32 *)(m + 0xF8), *(f32 *)(v + 8)) < 0.05f;
        break;
    }
}
/* localdecomp:end func_L03_003B2C30 */
