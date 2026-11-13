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

INCLUDE_ASM("asm/levels", func_L39_00551F68);

INCLUDE_ASM("asm/levels", func_L39_00552070);

INCLUDE_ASM("asm/levels", func_L39_005521F8);

/* localdecomp:start func_L39_00552750 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005FF198(u8 *, u8 *, u8 *);

u8 *func_L39_00552750(s32 a0, u8 *a1, u8 *a2, u8 *a3, s32 a4, f32 a5) {
    u8 *object = func_003C24B0(0x10A9, 0x80);
    u8 *state;
    u8 stamp;
    u8 *pos;
    u8 *vec;
    if (object != 0) {
        state = *(u8 **)(object + 0x68);
        stamp = 0xFF;
        *(u16 *)(object + 0x32) = stamp;
        object[0x30] = stamp;
        if (a4 != 0) {
            object[0x20] = 1;
        } else {
            object[0x20] = 0;
        }
        vec = object + 0xE0;
        pos = object + 0x10;
        *(u128_t *)pos = *(u128_t *)a2;
        *(u128_t *)state = *(u128_t *)a3;
        *(f32 *)(state + 0x10) = func_L39_005B44C8();
        *(f32 *)(state + 0x18) = 0.005f;
        *(f32 *)(state + 0x1C) = 0.01f;
        *(s32 *)(state + 0x24) = -1;
        *(f32 *)(state + 0x28) = a5;
        *(s32 *)(state + 0x30) = 0x19;
        *(s32 *)(state + 0x14) = 0;
        *(u8 **)(state + 0x2C) = a1;
        *(f32 *)(object + 0x2C) = *(f32 *)(*(u8 **)(object + 0x24) + 0x24) * 3.25f;
        object[0x23] = 0x14;
        *(u16 *)(object + 0x34) |= 0x100;
        *(s32 *)(object + 0xB8) = a0;
        *(u128_t *)(object + 0xC0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xC0);
        *(u128_t *)(object + 0xD0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xD0);
        *(u128_t *)(object + 0xE0) = *(u128_t *)(*(u8 **)(a1 + 0x2524) + 0xE0);
        func_0038CF68(object + 0xD0, object + 0xD0, *(f32 *)(state + 0x18));
        func_0038CF68(vec, vec, *(f32 *)(state + 0x1C));
        *(u16 *)(object + 0x34) |= 4;
        *(s32 *)(object + 0x98) = 0;
        state[0x70] = a1 != 0 && *(s16 *)(a1 + 0x2D8) != 0;
        func_L39_005FF198(a1, pos, state + 0x60);
        func_0038CF68(state + 0x60, state + 0x60, 0.0048f);
    }
    return object;
}
/* localdecomp:end func_L39_00552750 */

INCLUDE_ASM("asm/levels", func_L39_00552920);

INCLUDE_ASM("asm/levels", func_L39_00553148);

INCLUDE_ASM("asm/levels", func_L39_005537B8);

INCLUDE_ASM("asm/levels", func_L39_00553C30);
