#include "common.h"

/* localdecomp:start func_L07_003A70B0 */
s32 func_L07_003BAC00(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003A70B0(void *arg0) {
    u8 *p = arg0;
    u8 *s = *(u8 **)(p + 0x68);
    s32 f;

    if (p[0x20] != 0) {
        if (*(s32 *)(s + 0x74) != 0) {
            if (func_L07_003BAC00(*(s32 *)(s + 0x74), *(s32 *)(s + 0x70)) == 0) {
                return;
            }
        }
    }
    f = p[0x20];
    if (f != 1) {
        if (f >= 2) {
            return;
        }
        if (f != 0) {
            return;
        }
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x40;
        p[0x31] = 0;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x70) = -1;
        func_L01_004450F0(p, 1, -1);
    } else {
        if (*(s32 *)(s + 0x70) != -1) {
            func_L01_004450F0(p, 2, -1);
        }
    }
}
/* localdecomp:end func_L07_003A70B0 */

/* localdecomp:start func_L07_003A7178 */
typedef int u128_t __attribute__((mode(TI)));

s32 func_L07_003A7178(u8 *self, u128_t *vec, s32 a2, s32 a3) {
    u8 *s = *(u8 **)(self + 0x68);

    if (*(s32 *)(s + 0x70) != -1) {
        return 0;
    }
    self[0x30] = 0x40;
    *(s16 *)(self + 0x32) = 0x40;
    self[0x31] = 1;
    *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    *(u128_t *)(s + 0x80) = *(u128_t *)(self + 0x10);
    *(u128_t *)(self + 0x10) = *vec;
    *(s32 *)(s + 0x70) = a3;
    *(s32 *)(s + 0x74) = a2;
    *(s32 *)(s + 0x6C) |= 1;
    return 1;
}
/* localdecomp:end func_L07_003A7178 */

INCLUDE_ASM("asm/levels", func_L07_003A71E8);

INCLUDE_ASM("asm/levels", func_L07_003A7238);

INCLUDE_ASM("asm/levels", func_L07_003A7378);

/* localdecomp:start func_L07_003A7488 */
typedef struct { u8 pad[0x294]; void *f294; u8 pad2[4]; f32 f29C; } S_003A7488;
extern s32 D_L07_001DE350_sda;
extern s32 D_L07_001DE370_sda;
extern s32 D_L07_001DE390_sda;
extern s32 D_L07_001DE3B0_sda;
__asm__(".extern D_L07_001DE350_sda, 4");
__asm__(".extern D_L07_001DE370_sda, 4");
__asm__(".extern D_L07_001DE390_sda, 4");
__asm__(".extern D_L07_001DE3B0_sda, 4");
extern void func_L01_004450F0(void *, s32, s32);

void func_L07_003A7488(u8 *a0, s32 a1, s32 a2) {
    S_003A7488 *s;

    if (a1 == a0[0x20]) {
        return;
    }
    s = *(S_003A7488 **)(a0 + 0x68);
    s->f29C = 1.0f / (f32)a2;
    switch (a1) {
    case 0:
        s->f294 = &D_L07_001DE350_sda;
        break;
    case 1:
        s->f294 = &D_L07_001DE370_sda;
        break;
    case 2:
        s->f294 = &D_L07_001DE390_sda;
        break;
    case 4:
        s->f294 = &D_L07_001DE3B0_sda;
        break;
    }
    func_L01_004450F0(a0, a1, -1);
}
/* localdecomp:end func_L07_003A7488 */

/* localdecomp:start func_L07_003A7540 */
void func_L07_003A7540(void *arg0) {
    if (arg0 != 0) {
        *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2BC) = 1;
    }
}
/* localdecomp:end func_L07_003A7540 */

INCLUDE_ASM("asm/levels", func_L07_003A7558);

INCLUDE_ASM("asm/levels", func_L07_003A75E0);

INCLUDE_ASM("asm/levels", func_L07_003A79F0);
