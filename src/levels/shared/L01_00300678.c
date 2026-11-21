#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00300678 */
extern s32 D_001A71A4[];
extern void func_003C3A10(void *, s32, s32, s32);

void func_L01_00300678(u8 *a0) {
    if (D_001A71A4[0] == 8) {
        if (a0[0x43] != 6) {
            func_003C3A10(a0, 6, 0, 8);
        }
    }
}
/* localdecomp:end func_L01_00300678 */
