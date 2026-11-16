/* NTSC-U draft (Claude wave K): C of func_L01_00455C88, the NTSC-U twin of func_L01_00458F78, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 20 words differ on NTSC-U with "@ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L01_00455C88", whose code is not the PAL one).
 * Worker's note: 20 diff with @ps2as (the PAL line lacks it; float constants inline): void f(u8 *a, u8 *s, s32 a2, s32 a3): s->w58 = func_L01_00455A60(a); if (!a2 && !a3) func_L01_004559A8(a,s); target p = s->0x50: p ? (s->pos = tmp = p->pos) : tmp = s->pos; return if s->f10 ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00457F00 (src/levels/shared/L01_00457F00.c) */
/* localdecomp:start func_L01_00455C88 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_L01_00455A60(void *);
extern void func_L01_004559A8(void *, void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00454C30(void *, void *, s32, s32, f32);

#define RETARGET()                                    \
    {                                                 \
        *(u128_t *)(s + 0x20) = *(u128_t *)(s + 0x10); \
        *(u128_t *)s = *(u128_t *)(s + 0x10);          \
        func_L01_00454C30(a, s, a2, a3, 12.0f);       \
        *(s32 *)(s + 0x40) = 0;                       \
        *(u128_t *)(s + 0x70) = *(u128_t *)(a + 0x10); \
    }

void func_L01_00455C88(u8 *a, u8 *s, s32 a2, s32 a3) {
    u128_t tmp;
    u8 *p;
    u8 *s2;

    *(s32 *)(s + 0x58) = func_L01_00455A60(a);
    if (a2 == 0 && a3 == 0) {
        func_L01_004559A8(a, s);
    }
    p = *(u8 **)(s + 0x50);
    if (p != 0) {
        *(u128_t *)(s + 0x10) = *(u128_t *)(p + 0x10);
        tmp = *(u128_t *)(p + 0x10);
    } else {
        tmp = *(u128_t *)(s + 0x10);
    }
    if (*(f32 *)(s + 0x10) == 0.0f && *(f32 *)(s + 0x14) == 0.0f) {
        return;
    }
    if (func_00388800(s + 0x20, &tmp) > 1.0f) {
        RETARGET()
    }
    s2 = a + 0x10;
    if (func_00388800(s2, s) < 0.75f) {
        RETARGET()
    }
    if (func_00388800(s2, s + 0x70) > 8.0f) {
        RETARGET()
    }
    if (*(s32 *)(s + 0x40) >= 8) {
        RETARGET()
    }
}
/* localdecomp:end func_L01_00455C88 */
