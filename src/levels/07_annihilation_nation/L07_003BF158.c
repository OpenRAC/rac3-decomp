#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L07_003BF158 */
u8 *func_L07_003BF158(u8 *parent, u128_t *pos, u128_t *rot, s32 value, u8 kind, s32 count, s32 index) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_003C7C38(void *);
    u8 *m = func_003C24B0(0x1A9F, 0x80);
    u8 *d;
    u128_t *newpos, *newrot;
    if (m != 0) {
        *(u8 **)(m + 0xB8) = parent;
        d = *(u8 **)(m + 0x68);
        newpos = (u128_t *)(m + 0x10);
        newrot = (u128_t *)(m + 0xF0);
        *newpos = *pos;
        *newrot = *rot;
        *(u16 *)(m + 0x34) = *(u16 *)(parent + 0x34);
        *(u16 *)(m + 0x32) = *(u16 *)(parent + 0x32);
        m[0x30] = 0xFF;
        m[0x31] = 1;
        *(u16 *)(d + 0xC) = 0x19;
        *(s32 *)(d + 0x10) = 0;
        m[0x20] = 1;
        *(s32 *)(d + 4) = value;
        d[0xE] = index;
        d[0xF] = kind;
        if (index > 0) {
            m[0x23] = (1.0f - (f32)index / (f32)count) * 128.0f;
            *(u16 *)(m + 0x34) |= 9;
        }
        if (index + 1 < count) {
            *(u8 **)d = func_L07_003BF158(m, newpos, newrot, value, kind, count, index + 1);
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

/* localdecomp:start func_L07_003BF8A8 */
extern f32 D_001E1EC0[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L07_003BFAE8(void *, f32, f32, u8);

void func_L07_003BF8A8(void *arg0) {
    u8 *self = arg0;
    u8 *state;
    f32 ratio, angle;
    s32 count, i, j;
    u8 side;
    if (!self || self[0x20] == 0xFE || self[0x20] == 0xFD || *(s16 *)(self + 0xAA) != 0x1A9F) return;
    state = *(u8 **)(self + 0x68);
    i = (s32)(*(f32 *)(state + 0x10) / 0.15f);
    ratio = *(f32 *)(state + 0x10) / 0.85f;
    count = i + 1;
    if (ratio > 1.0f) ratio = 1.0f;
    angle = func_0038D160(D_001E1EC0[0] - *(f32 *)(self + 0x10), D_001E1EC0[1] - *(f32 *)(self + 0x14));
    angle = func_0038DB00(angle, *(f32 *)(self + 0xF8));
    if (__builtin_fabsf(angle) < 0.34906584f) {
        for (j = 0; j < count; i--, j++) {
            f32 t = *(f32 *)(state + 0x10) - i * 0.15f;
            func_L07_003BFAE8(self, t, ratio, 0);
            func_L07_003BFAE8(self, t, ratio, 1);
        }
    } else {
        f32 step = 0.15f;
        side = angle > 0.0f;
        for (i = 0; i < count * 2; i++) {
            if (i < count) func_L07_003BFAE8(self, *(f32 *)(state + 0x10) - i * step, ratio, !side);
            else func_L07_003BFAE8(self, *(f32 *)(state + 0x10) - (count * 2 - i - 1) * step, ratio, side);
        }
    }
}
/* localdecomp:end func_L07_003BF8A8 */

INCLUDE_ASM("asm/levels", func_L07_003BFAE8);
