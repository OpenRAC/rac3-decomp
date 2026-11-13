#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00550D48);

INCLUDE_ASM("asm/levels", func_L39_005510B0);

INCLUDE_ASM("asm/levels", func_L39_005514A0);

/* localdecomp:start func_L39_005515E8 */
void func_L39_00551660(void *);
extern s32 func_L39_00551918(u8 *);
extern s32 func_L39_00552070(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00404A10(void *, u8 *);

void func_L39_005515E8(u8 *a0) {
    s32 a = func_L39_00551918(a0);
    s32 b = func_L39_00552070(a0);
    if (a == 0 && b == 0) {
        if (a0[32] == 2) {
            func_003C2880(a0);
        }
    } else {
        func_L01_00404A10(func_L39_00551660, a0);
    }
}
/* localdecomp:end func_L39_005515E8 */

/* localdecomp:start func_L39_00551660 */
void func_L39_00551A38(void);
void func_L39_005521F8(void *);

void func_L39_00551660(void *arg0) {
    if (arg0 != 0) {
        u8 t = *(u8 *)((char *)arg0 + 0x20);
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            func_L39_00551A38();
            func_L39_005521F8(arg0);
        }
    }
}
/* localdecomp:end func_L39_00551660 */

INCLUDE_ASM("asm/levels", func_L39_005516B0);

INCLUDE_ASM("asm/levels", func_L39_005517C8);

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
