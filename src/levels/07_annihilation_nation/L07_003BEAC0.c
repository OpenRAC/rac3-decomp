#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003BEAC0 */
extern void func_L07_003BEB50(void *, void *, s32, s32, s32);

void func_L07_003BEAC0(u8 *arg0) {
    u8 *s2 = *(u8 **)(arg0 + 0x68);
    u8 *p = s2 + 0x4F2;
    s32 i;

    for (i = 0; i < 2; i++) {
        if ((s2[0x4FB] >> i) & 1) {
            func_L07_003BEB50(arg0, s2 + 0x3B0 + i * 0xA0, p[i - 2], p[i], s2[0x4FC] + 0x64);
        }
    }
}
/* localdecomp:end func_L07_003BEAC0 */

INCLUDE_ASM("asm/levels", func_L07_003BEB50);

INCLUDE_ASM("asm/levels", func_L07_003BEE80);

INCLUDE_ASM("asm/levels", func_L07_003BF158);

/* localdecomp:start func_L07_003BF2D0 */
void func_L07_003BF2D0(void *arg0) {
    void *temp_a0;

    temp_a0 = *(*(void ***)((u8 *)arg0 + 0x68));
    if (temp_a0 != 0) {
        func_L07_003BF2D0(temp_a0);
    }
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFFE);
}
/* localdecomp:end func_L07_003BF2D0 */

/* localdecomp:start func_L07_003BF318 */
void func_L07_003BF318(u8 *a, u8 *b) {
    if (b != 0) {
        func_L07_003BF318(b, **(u8 ***)(b + 0x68));
        *(u128_t *)(b + 0x10) = *(u128_t *)(a + 0x10);
        *(u128_t *)(b + 0xF0) = *(u128_t *)(a + 0xF0);
    }
}
/* localdecomp:end func_L07_003BF318 */

/* localdecomp:start func_L07_003BF368 */
void func_003C2880(void *);

void func_L07_003BF368(void *arg0) {
    void *temp_a0;

    temp_a0 = *(*(void ***)((u8 *)arg0 + 0x68));
    if (temp_a0 != 0) {
        func_L07_003BF368(temp_a0);
    }
    func_003C2880(arg0);
}
/* localdecomp:end func_L07_003BF368 */

INCLUDE_ASM("asm/levels", func_L07_003BF3A8);

INCLUDE_ASM("asm/levels", func_L07_003BF480);

/* localdecomp:start func_L07_003BF838 */
typedef struct {
    u8 pad0[0x10];
    f32 f10;
} S_003BF838;

extern void func_L01_00404808(void (*)(void *), void *);
void func_L07_003BF8A8(void *);

void func_L07_003BF838(u8 *arg0) {
    S_003BF838 *p = *(S_003BF838 **)(arg0 + 0x68);
    f32 t = p->f10 + 0.036000002f;

    p->f10 = t;
    if (t > 1.0f) {
        p->f10 = t - 0.180000007f;
    }
    func_L01_00404808(func_L07_003BF8A8, arg0);
}
/* localdecomp:end func_L07_003BF838 */

INCLUDE_ASM("asm/levels", func_L07_003BF8A8);

INCLUDE_ASM("asm/levels", func_L07_003BFAE8);
