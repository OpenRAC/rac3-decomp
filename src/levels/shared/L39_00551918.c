#include "common.h"

/* declared by functions of L39_00550D48.c, which this file was cut from */
extern s32 func_L39_00551918(u8 *);

/* localdecomp:start func_L39_00551918 */
extern u8 D_L39_003C13E0[];
extern f32 func_0038DAB8(f32, f32);
extern void func_L39_005517C8(u8 *rec, s32 index);
extern s32 func_0038CB00(void *p);

s32 func_L39_00551918(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *base = D_L39_003C13E0 + st[0x3A] * 0x12C0;
    s32 n = *(s16 *)(st + 0x30);
    s32 i = 0;
    u8 *rec;
    f32 v;
    if (n > 0) {
        rec = base;
        do {
            *(f32 *)(rec + 0x20) = func_0038DAB8(*(f32 *)(rec + 0x20), *(f32 *)(rec + 0x28));
            func_L39_005517C8(base, i);
            rec += 0x30;
            i++;
        } while (i < n);
    }
    v = *(f32 *)(st + 0x48);
    if (v > 7.0f) {
        *(f32 *)(st + 0x48) = 0.0f;
    } else if (v < -7.0f) {
        *(f32 *)(st + 0x48) = 0.0f;
    }
    v = *(f32 *)(st + 0x48) - 0.07500000298f;
    *(f32 *)(st + 0x48) = v;
    if (v <= -4.0f)
        *(f32 *)(st + 0x48) = v + 4.0f;
    return func_0038CB00(st + 0x32) == 0;
}
/* localdecomp:end func_L39_00551918 */

INCLUDE_ASM("asm/levels", func_L39_00551A38);
