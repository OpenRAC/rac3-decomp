#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00334238);

/* localdecomp:start func_L07_00334318 */
typedef struct { u8 b[16]; } B16_00334318;

extern B16_00334318 D_L07_001DD118;
extern f32 func_L07_00334238(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_L03_0032FB70(f32);

void func_L07_00334318(void *arg0, s32 *arg1, s32 *arg2) {
    B16_00334318 tmp;
    s32 *p;
    s32 n;
    s32 i;
    f32 a;

    a = func_L07_00334238(arg0);
    a = func_0038DAB8(a, 0.39269909f);
    a = func_L03_0032FB70(a);
    n = (s32)(a / 0.39269909f);
    tmp = D_L07_001DD118;
    p = (s32 *)tmp.b;
    for (i = 3; i >= 0; i--) {
        if (*p < n) {
            n--;
        }
        p++;
    }
    *arg1 = n >> 1;
    *arg2 = (n & 1) ? 1 : -1;
}
/* localdecomp:end func_L07_00334318 */

/* localdecomp:start func_L07_003343E8 */
s32 func_L07_003343E8(s32 arg0) {
    if (arg0 < 6) {
        return 0;
    }
    return arg0 < 7;
}
/* localdecomp:end func_L07_003343E8 */

/* localdecomp:start func_L07_00334408 */
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C;
__asm__(".extern D_L07_001DF41C, 16");
extern s32 D_L07_001DCE98[2];
__asm__(".extern D_L07_001DCE98, 8");
extern s32 D_001DF458_sda;
__asm__(".extern D_001DF458_sda, 4");

extern u8 *func_L07_00333918(u8 *);
extern void func_L07_00334588(u8 *);

s32 func_L07_00334408(u8 *arg0) {
    u8 *s = func_L07_00333918(arg0);
    s16 v;
    s16 h;
    s32 best;
    u16 *p;
    u8 *e;
    u8 *t;

    if ((u8)(s[0x1C] - 2) < 2) {
        if (*(s16 *)(s + 0xC) != -1) {
            func_L07_00334588(arg0);
        }
        return -1;
    }
    v = *(s16 *)(s + 0xC);
    if (v != -1) {
        return v;
    }
    if (D_L07_001DCE98[s[0x1D]] == -1) {
        return -1;
    }
    best = -1;
    p = D_L07_0021C020[arg0[0x21]];
    while (arg0[0x21] != 0xFF && arg0[0x21] <= D_001DF458_sda && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L07_0021C020[arg0[0x21]])) {
        e = D_L07_001DF41C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e != arg0 && *(s16 *)(e + 0xAA) == *(s16 *)(arg0 + 0xAA) && e[0x20] != 1) {
            t = func_L07_00333918(e);
            if (t[0x1C] == 1) {
                h = *(s16 *)(t + 0xC);
                best = best < h ? h : best;
            }
        }
        p++;
    }
    return best + 1;
}
/* localdecomp:end func_L07_00334408 */
