#include "common.h"

/* declared by functions of L13_003C5430.c, which this file was cut from */
extern f32 D_L13_001DEB58;
extern f32 func_003824E0(f32, f32);

/* localdecomp:start func_L13_003C54F8 */
__asm__(".extern D_L13_001DEB58, 4");
extern s32 D_L13_001E1B18_003C54F8;
extern f32 D_L13_001E1B20_003C54F8[] __attribute__((section(".sdata")));
extern u8 D_001426E0[];
extern u8 D_001D54B0[] __attribute__((section(".sdata")));
extern void func_0038CC88(void *, void *, s32);
extern f32 func_003C4088(f32, f32, f32);

void func_L13_003C54F8(u8 *self)
{
    f32 w[5];
    u8 *p = *(u8 **)(self + 0x68);
    f32 sum;
    f32 r;
    s32 i;
    u8 *g;

    func_0038CC88(w, D_L13_001E1B20_003C54F8, sizeof(w));
    if (*(s32 *)(p + 0x254) != 0) {
        w[4] = 0.0f;
    }
    g = D_001426E0;
    if (g[0x81] < 125) {
        g[0x81]++;
    }
    if (g[0x81] < 75) {
        w[2] = 0.0f;
    } else if (D_L13_001E1B18_003C54F8 == 0 && D_001D54B0[16] == 0) {
        w[2] = 100.0f;
    }
    sum = 0.0f;
    for (i = 0; i < 5; i++) {
        sum += w[i];
    }
    r = func_003824E0(0.0f, sum);
    for (i = 0; i < 4; i++) {
        r -= w[i];
        if (r < 0.0f) {
            break;
        }
    }
    *(s32 *)(p + 0x240) = i;
    if (i == 2) {
        D_L13_001E1B18_003C54F8 = 1;
    }
    for (i = 0; i < 5; i++) {
        if (i == *(s32 *)(p + 0x240)) {
            D_L13_001E1B20_003C54F8[i] = func_003C4088(D_L13_001E1B20_003C54F8[i], 0.0f, 0.5f);
        } else {
            D_L13_001E1B20_003C54F8[i] = func_003C4088(D_L13_001E1B20_003C54F8[i], (&D_L13_001DEB58)[i], 0.5f);
        }
    }
}
/* localdecomp:end func_L13_003C54F8 */
