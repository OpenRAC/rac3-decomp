#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* declared by functions of L32_003BE008.c, which this file was cut from */
void func_L32_003BED60(void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003BE8E0 */
typedef int u128_t __attribute__((mode(TI)));

extern s32 D_L32_001DF1D8;
__asm__(".extern D_L32_001DF1D8, 4");
extern u8 *func_003C24B0(s32, s32);

u8 *func_L32_003BE8E0(void *arg0, s32 arg1) {
    u8 *r = func_003C24B0(0x1D82, 0x40);
    u8 *p;

    if (r == 0) {
        return 0;
    }
    p = *(u8 **)(r + 0x68);
    *(u8 *)(r + 0x30) = 0xFF;
    *(u128_t *)(r + 0x10) = *(u128_t *)arg0;
    if (arg1 <= 0) {
        s32 g = D_L32_001DF1D8;
        *(s32 *)(p + 0x4) = g;
        *(s32 *)(p + 0x8) = g;
    } else {
        *(s32 *)(p + 0x4) = arg1;
        *(s32 *)(p + 0x8) = arg1;
    }
    return r;
}
/* localdecomp:end func_L32_003BE8E0 */
