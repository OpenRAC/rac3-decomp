#include "common.h"

/* localdecomp:start func_L32_003B5828 */
typedef int u128_t __attribute__((mode(TI)));

extern void func_L32_003B6C88(void *);
extern void func_L32_003B6408(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L32_003B6DD0(void *);
extern void func_L32_003B70F8(void *);
extern void func_L32_003B7190(void *, void *);

void func_L32_003B5828(void *arg0) {
    u8 buf[16] __attribute__((aligned(16)));

    *(u128_t *)buf = *(u128_t *)((u8 *)arg0 + 0x10);
    switch (*(u8 *)((u8 *)arg0 + 0x20)) {
    case 1:
        func_L32_003B6C88(arg0);
        break;
    case 0:
        func_L32_003B6408(arg0);
        func_L01_004450F0(arg0, 5, -1);
        break;
    case 2:
    case 3:
    case 4:
        func_L32_003B6DD0(arg0);
        break;
    case 5:
        func_L32_003B70F8(arg0);
        break;
    }
    func_L32_003B7190(arg0, buf);
}
/* localdecomp:end func_L32_003B5828 */

INCLUDE_ASM("asm/levels", func_L32_003B58D0);

INCLUDE_ASM("asm/levels", func_L32_003B5C98);

INCLUDE_ASM("asm/levels", func_L32_003B5F58);

INCLUDE_ASM("asm/levels", func_L32_003B6170);

INCLUDE_ASM("asm/levels", func_L32_003B6408);

/* localdecomp:start func_L32_003B6618 */
extern s32 func_00382498(s32, s32);

s32 func_L32_003B6618(void *arg0) {
    s32 i;
    s32 idx;
    f32 *p;
    f32 thr;

    idx = -1;
    thr = *(f32 *)((u8 *)arg0 + 0x10);
    p = (f32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0xB0);
    for (i = 0; i < 16; i++, p++) {
        if (*p <= thr) {
            if (*p > 1.0f) {
                idx = i;
            }
        }
    }
    if (idx == -1) {
        return -2;
    }
    return func_00382498(-1, idx);
}
/* localdecomp:end func_L32_003B6618 */

INCLUDE_ASM("asm/levels", func_L32_003B66A0);

INCLUDE_ASM("asm/levels", func_L32_003B6A58);

INCLUDE_ASM("asm/levels", func_L32_003B6C88);

INCLUDE_ASM("asm/levels", func_L32_003B6DD0);

/* localdecomp:start func_L32_003B70F8 */
s32 func_003A52A0(s32, s32, void *);
void func_L01_004450F0(void *, s32, s32);
s32 func_L05_00328FF8(void *);
void func_L32_003B5F58();
extern u8 D_001A30B0[];

void func_L32_003B70F8(void *arg0) {
    s32 temp_a0;
    void *temp_a0_2;
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L32_003B5F58();
    temp_a0 = *(s32 *)((u8 *)temp_s1 + 0x258);
    if ((temp_a0 == -1) || (temp_a0_2 = (temp_a0 << 7) + D_001A30B0, ((*(s32 *)((u8 *)temp_a0_2 + 0xDC)) != arg0)) || ((*(u8 *)((u8 *)temp_a0_2 + 0xD0)) == 0)) {
        *(s32 *)((u8 *)temp_s1 + 0x258) = func_003A52A0(5, 4, arg0);
    }
    if (func_L05_00328FF8(arg0) != 0) {
        func_L01_004450F0(arg0, 2, -1);
    }
}
/* localdecomp:end func_L32_003B70F8 */

INCLUDE_ASM("asm/levels", func_L32_003B7190);

INCLUDE_ASM("asm/levels", func_L32_003B7610);

INCLUDE_ASM("asm/levels", func_L32_003B7AB0);

INCLUDE_ASM("asm/levels", func_L32_003B7BE8);

/* localdecomp:start func_L32_003B8160 */
void func_003C2880(void *);
void func_L32_003B8230(void *);

void func_L32_003B8160(void *arg0) {
    u8 *p;
    s32 *slot;
    s32 i;

    p = *(u8 **)((u8 *)arg0 + 0x68);
    *(s32 *)(p + 0x8C) = 0;
    slot = (s32 *)p;
    i = 31;
    do {
        if (*slot != 0) {
            if (*(u8 *)(*(u8 **)slot + 0x20) >= 0xFD) {
                *slot = 0;
            } else {
                *(s32 *)(p + 0x8C) = *(s32 *)(p + 0x8C) + 1;
            }
        }
        i--;
        slot++;
    } while (i >= 0);
    if (*(s32 *)(p + 0x88) == 0 && *(s32 *)(p + 0x8C) == 0) {
        func_003C2880(arg0);
    } else {
        func_L32_003B8230(arg0);
    }
}
/* localdecomp:end func_L32_003B8160 */

INCLUDE_ASM("asm/levels", func_L32_003B81F0);

INCLUDE_ASM("asm/levels", func_L32_003B8230);

/* localdecomp:start func_L32_003B8390 */

extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern f32 D_L32_001DEF90;
__asm__(".extern D_L32_001DEF90, 4");
extern f32 D_L32_001DEF8C;
__asm__(".extern D_L32_001DEF8C, 4");

u8 *func_L32_003B8390(u8 *a0, f32 f20, f32 f21) {
    u8 *o;
    u8 *p2;
    s32 *q;
    s32 i;

    o = func_003C24B0(0x1C96, 0x90);
    if (o == 0) {
        return 0;
    }
    *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
    *(s32 *)(o + 0x98) = 0;
    *(u8 *)(o + 0x30) = 0xFF;
    func_L01_004AA7E8(o, 1);
    *(u128_t *)(o + 0x10) = *(u128_t *)a0;
    p2 = *(u8 **)(o + 0x68);
    q = (s32 *)(p2 + 0x7C);
    i = 31;
    do {
        *q = 0;
        q--;
        i--;
    } while (i >= 0);
    *(f32 *)(p2 + 0x80) = (0.0f < f20) ? f20 : D_L32_001DEF90;
    *(f32 *)(p2 + 0x84) = (0.0f < f21) ? f21 : D_L32_001DEF8C;
    *(s32 *)(p2 + 0x88) = 1;
    return o;
}
/* localdecomp:end func_L32_003B8390 */
