#include "common.h"

/* localdecomp:start func_L03_003A1D48 */
typedef int u128_003A1D48 __attribute__((mode(TI)));
extern u8 *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
extern void func_003C2880(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L03_003A1EB0(void *);

void func_L03_003A1D48(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    f32 p[4];
    u8 *e;
    s32 n;
    s32 c;
    f32 r;
    switch (m[0x20]) {
    case 0:
        if (v[0] == -1) {
            func_003C2880(m);
        }
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (func_00382468(10) != 0) {
            break;
        }
        func_L01_004AAC98(0, 0, m, 0x19A0);
        r = func_003824E0(0.0f, 1.0f);
        e = D_L03_001DFA80 + (v[0] << 7);
        c = (s32)(r * r * (f32)v[1]);
        if (c > 0) {
            n = c;
            do {
                f32 x;
                f32 y;
                f32 z;
                *(u128_003A1D48 *)p = *(u128_003A1D48 *)(e + 0x30);
                x = *(f32 *)(e + 0x0);
                y = *(f32 *)(e + 0x14);
                z = *(f32 *)(e + 0x28);
                p[0] += func_003824E0(-x, x);
                p[1] += func_003824E0(-y, y);
                p[2] += func_003824E0(-z, z);
                func_L03_003A1EB0(p);
            } while (--n != 0);
        }
        break;
    }
}
/* localdecomp:end func_L03_003A1D48 */

INCLUDE_ASM("asm/levels", func_L03_003A1EB0);
