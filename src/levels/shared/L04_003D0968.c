#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_003D0968);

INCLUDE_ASM("asm/levels", func_L04_003D0C40);

/* localdecomp:start func_L04_003D10D0 */
void func_L04_003D10D0(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);
    *(s32 *)(d + 128) = *(s32 *)(s + 0);
    if (*(f32 *)(s + 4) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 4);
    }
    *(s32 *)(d + 136) = *(s32 *)(s + 8);
    if (*(f32 *)(s + 12) > 0.0f) {
        *(f32 *)(d + 132) = *(f32 *)(s + 12);
    }
    *(s32 *)(d + 144) = *(s32 *)(s + 88);
    *(s32 *)(d + 152) = *(s32 *)(s + 32);
}
/* localdecomp:end func_L04_003D10D0 */

/* localdecomp:start func_L04_003D1128 */
typedef void (*Fn_003CF2A0)(u8 *);

extern u8 D_001A30B0[];
extern void func_003C2880(s32);
extern void func_003A4F28(s32);
extern Fn_003CF2A0 *func_L01_0043B548(s32, s32);

void func_L04_003D1128(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    s32 idx;
    u8 *e;

    if (*(s32 *)(v + 156) != 0) {
        func_003C2880(*(s32 *)(v + 156));
        *(s32 *)(v + 156) = 0;
    }
    if (*(s32 *)(v + 160) != 0) {
        func_003C2880(*(s32 *)(v + 160));
        *(s32 *)(v + 160) = 0;
    }
    idx = *(s32 *)(v + 164);
    if (idx != -1) {
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 220) == self && e[208] != 0) {
            func_003A4F28(idx);
        }
    }
    *(s32 *)(v + 164) = -1;
    (*func_L01_0043B548(6625, 108))(self);
}
/* localdecomp:end func_L04_003D1128 */

/* localdecomp:start func_L04_003D11E0 */
int func_L04_003D11E0(u8 *a) {
    int r = 3;
    if (a[32] != 2) {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L04_003D11E0 */

INCLUDE_ASM("asm/levels", func_L04_003D11F8);

INCLUDE_ASM("asm/levels", func_L04_003D1420);

INCLUDE_ASM("asm/levels", func_L04_003D1530);

INCLUDE_ASM("asm/levels", func_L04_003D1550);

INCLUDE_ASM("asm/levels", func_L04_003D3018);

INCLUDE_ASM("asm/levels", func_L04_003D3228);

INCLUDE_ASM("asm/levels", func_L04_003D3520);

INCLUDE_ASM("asm/levels", func_L04_003D37F8);

INCLUDE_ASM("asm/levels", func_L04_003D3A30);

INCLUDE_ASM("asm/levels", func_L04_003D3AC8);

INCLUDE_ASM("asm/levels", func_L04_003D3B90);

/* localdecomp:start func_L04_003D3EE0 */
extern void func_L01_00517918(s32);
void func_L04_003D3EE0(void) {
    func_L01_00517918(13);
}
/* localdecomp:end func_L04_003D3EE0 */

/* localdecomp:start func_L04_003D3F00 */
extern f32 D_L04_001DEC04;
extern f32 D_L04_001DEBF8;
extern void func_L01_00517538(s32 a0, f32 a1, f32 a2);

void func_L04_003D3F00(void *a0, u8 *a1)
{
    f32 t = *(f32 *)(a1 + 48) / (f32)*(s16 *)(a1 + 52);

    func_L01_00517538(0x490004, D_L04_001DEC04 * t, D_L04_001DEBF8);
    func_L01_00517538(0x490005, D_L04_001DEC04 * t, D_L04_001DEBF8);
}
/* localdecomp:end func_L04_003D3F00 */

INCLUDE_ASM("asm/levels", func_L04_003D3F68);
