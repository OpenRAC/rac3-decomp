#include "common.h"

/* localdecomp:start func_L03_00461E88 */
extern u8 *func_L01_004618E0(s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00474328(u8 *);
extern u8 *D_L03_0021F46C[];

u8 *func_L03_00461E88(void *a, u8 *b, s32 life, s32 idx) {
    u8 *p = func_L01_004618E0(0x75);
    u8 *q;
    s16 *s;
    s32 i;
    s32 j;
    if (p == 0) {
        return 0;
    }
    *(s32 *)(p + 4) = 0;
    p[9] = 0x44;
    p[1] = 0;
    q = p + 0x20;
    *(s32 *)(p + 0xC) = 0;
    p[8] = 0;
    p[2] = D_L03_0021F46C[0][idx];
    *(void **)(q + 0) = a;
    *(s16 *)(p + 0xA) = life;
    *(u8 **)(q + 4) = b;
    p[3] = b[0x10];
    *(s16 *)(q + 8) = life;
    for (i = 3; i >= 0; i--) {
        ((s32 *)(p + 0x30))[i] = 0;
    }
    s = (s16 *)(q + 0xC);
    for (j = 0; j < 2; j++) {
        s[j] = func_00382498(0, 0x7FFF);
        if (func_00382498(0, 1) != 0) {
            s[j] *= -1;
        }
    }
    *(s16 *)(q + 0xA) = 1;
    func_L01_00474328(p);
    *(u16 *)(q + 0xA) &= 0xFFFE;
    return p;
}
/* localdecomp:end func_L03_00461E88 */
