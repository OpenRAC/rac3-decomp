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

/* localdecomp:start func_L07_003BF158 */
extern u8 *func_003C24B0(s32, s32);
extern void func_003C7C38(void *);

/* Spawns a linked chain of class 0x1A9F mobys and returns its first member. */
u8 *func_L07_003BF158(u8 *a0, u8 *a1, u8 *a2, s32 a3, u8 a4, s32 a5, s32 a6) {
    u8 *m;
    u8 *d;
    u8 *p10;
    u8 *pF0;

    m = func_003C24B0(0x1A9F, 0x80);
    if (m != 0) {
        *(u8 **)(m + 0xB8) = a0;
        d = *(u8 **)(m + 0x68);
        p10 = m + 0x10;
        pF0 = m + 0xF0;
        *(u128_t *)p10 = *(u128_t *)a1;
        *(u128_t *)pF0 = *(u128_t *)a2;
        *(u16 *)(m + 0x34) = *(u16 *)(a0 + 0x34);
        *(u16 *)(m + 0x32) = *(u16 *)(a0 + 0x32);
        m[0x30] = 0xFF;
        m[0x31] = 1;
        *(u16 *)(d + 0xC) = 0x19;
        *(s32 *)(d + 0x10) = 0;
        m[0x20] = 1;
        *(s32 *)(d + 4) = a3;
        d[0xE] = a6;
        d[0xF] = a4;
        if (a6 > 0) {
            *(u16 *)(m + 0x34) |= 9;
            m[0x23] = (s32)((1.0f - (f32)a6 / (f32)a5) * 128.0f);
        }
        if (a6 + 1 < a5) {
            *(u8 **)d = func_L07_003BF158(m, p10, pF0, a3, a4, a5, a6 + 1);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L07_003BF158 */

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

/* localdecomp:start func_L07_003BF3A8 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003BF3A8;
void func_L07_003BF3A8(u8 *self, u8 *target, f32 maxTurn, void *direction) {
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    V_003BF3A8 delta;
    f32 angle;
    if (target != 0) {
        __asm__(
            "lqc2 $vf1, 16(%1)\n"
            "lqc2 $vf2, 16(%2)\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(delta) : "r"(target), "r"(self) : "vf1", "vf2", "memory");
        if (direction == 0 || func_0038CE68(&delta, direction) > 0.0f) {
            angle = func_0038D160(*(f32 *)(target + 0x10) - *(f32 *)(self + 0x10),
                                  *(f32 *)(target + 0x14) - *(f32 *)(self + 0x14));
            angle = func_0038DB00(angle, *(f32 *)(self + 0xF8));
            if (angle > maxTurn) angle = maxTurn;
            else if (angle < -maxTurn) angle = -maxTurn;
            *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), angle);
        }
    }
}
/* localdecomp:end func_L07_003BF3A8 */

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
