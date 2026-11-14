#include "common.h"

/* declared by functions of L32_003B5828.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L32_003B6408(void *);

/* localdecomp:start func_L32_003B5F58 */
extern f32 func_0038D0B0(f32);
extern void func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);
extern s32 D_L32_001DF9C0;
extern u8 D_001D66B0;
extern s32 D_L32_001DEE4C;
__asm__(".extern D_L32_001DEE4C, 4");
extern f32 D_L32_001DEE48;
__asm__(".extern D_L32_001DEE48, 4");
extern f32 D_L32_001DEE0C;
__asm__(".extern D_L32_001DEE0C, 4");
extern f32 D_L32_001DEE54;
__asm__(".extern D_L32_001DEE54, 4");
extern f32 D_L32_001DEE50;
__asm__(".extern D_L32_001DEE50, 4");
extern const f32 D_L32_001DEE58;
__asm__(".extern D_L32_001DEE58, 4");
extern const f32 D_L32_001DEE7C;
__asm__(".extern D_L32_001DEE7C, 4");
extern f32 D_L32_001DEE80;
__asm__(".extern D_L32_001DEE80, 4");

void func_L32_003B5F58(void *arg0) {
    u8 *a;
    u8 *p;
    f32 amp;
    f32 v;
    f32 vel;
    f32 sign;
    f32 d;
    f32 k;
    f32 t;
    f32 w;

    a = arg0;
    p = *(u8 **)(a + 0x68);
    if (*(u8 *)(a + 0x20) != 5) {
        if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x238)) {
            amp = D_L32_001DEE7C;
        } else {
            amp = D_L32_001DEE80;
        }
    } else {
        amp = 0.0f;
    }
    v = *(f32 *)(p + 0x250) + D_L32_001DEE48 * func_0038D0B0((f32)(D_L32_001DF9C0 % D_L32_001DEE4C) * 6.2831855f / (f32)D_L32_001DEE4C);
    *(f32 *)(p + 0x138) = v;
    vel = *(f32 *)(p + 0x148);
    if (vel == 0.0f) {
        if (v < *(f32 *)(a + 0x18)) {
            *(f32 *)(p + 0x148) = -D_L32_001DEE0C;
        } else {
            *(f32 *)(p + 0x148) = D_L32_001DEE0C;
        }
    } else {
        sign = 1.0f;
        if (vel < 0.0f) {
            sign = -1.0f;
        }
        d = v - *(f32 *)(a + 0x18);
        if (vel * d < 0.0f || __builtin_fabsf(d) < __builtin_fabsf(vel * (vel + D_L32_001DEE0C) / (D_L32_001DEE0C + D_L32_001DEE0C))) {
            *(f32 *)(p + 0x148) = vel + -sign * D_L32_001DEE0C;
        } else {
            *(f32 *)(p + 0x148) = vel + sign * D_L32_001DEE0C;
        }
    }
    t = (*(f32 *)(a + 0x18) - *(f32 *)(p + 0x138)) / D_L32_001DEE54;
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < -1.0f) {
        t = -1.0f;
    }
    w = D_L32_001DEE58;
    *(f32 *)(a + 0xF4) = -t * D_L32_001DEE50;
    func_L30_0034D1E8(a, a + 0x10, p + 0x140, &D_001D66B0, 0.5f, 0.0f, 1.0f, amp, w, 0.0f, 1, 0, 0, 0);
}
/* localdecomp:end func_L32_003B5F58 */

/* localdecomp:start func_L32_003B6170 */
extern f32 func_003C4088(f32, f32, f32);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L03_0034B248(void *, void *);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003A4F28(s32);
extern u8 D_001A30B0[];
typedef struct {
    s32 x0;
    f32 x4;
} S2_003B6170;
extern S2_003B6170 D_L32_001E2480;
extern s32 D_L32_001E24A0;
extern s32 D_L32_001E24C0;
extern f32 D_L32_001DEEB8;
__asm__(".extern D_L32_001DEEB8, 4");
extern f32 D_L32_001DEEBC;
__asm__(".extern D_L32_001DEEBC, 4");

void func_L32_003B6170(void *arg0) {
    u8 *a;
    u8 *p;
    f32 t;
    s32 h;
    s32 h0;
    u8 *s;

    a = arg0;
    p = *(u8 **)(a + 0x68);
    if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x238)) {
        t = (*(f32 *)(a + 0x10) - *(f32 *)(p + 0x238)) / (*(f32 *)(p + 0x22C) - *(f32 *)(p + 0x238));
        if (t > 1.0f) {
            t = 1.0f;
        }
        D_L32_001E2480.x4 = func_003C4088(D_L32_001DEEB8, D_L32_001DEEBC, t);
        func_L30_0034C8A8(&D_L32_001E2480, a);
        h0 = *(s32 *)(p + 0x25C);
        if (h0 == -1 || (s = (h0 << 7) + D_001A30B0, *(void **)(s + 0xDC) != a) || *(u8 *)(s + 0xD0) == 0) {
            *(s32 *)(p + 0x25C) = func_003A52A0(2, 4, a);
        }
    } else {
        h = *(s32 *)(p + 0x25C);
        if (h != -1) {
            s = (h << 7) + D_001A30B0;
            if (*(void **)(s + 0xDC) == a && *(u8 *)(s + 0xD0) != 0) {
                func_003A4F28(h);
            }
        }
        *(s32 *)(p + 0x25C) = -1;
    }
    if (*(f32 *)(a + 0x10) > *(f32 *)(p + 0x22C)
        || (*(f32 *)(a + 0x10) > *(f32 *)(p + 0xD0) && *(f32 *)(a + 0x10) < *(f32 *)(p + 0xD4))
        || (*(f32 *)(a + 0x10) > *(f32 *)(p + 0xD8) && *(f32 *)(a + 0x10) < *(f32 *)(p + 0xDC))) {
        func_L30_0034C8A8(&D_L32_001E24C0, a);
        if (*(s32 *)(p + 0x260) != 0) {
            h = *(s32 *)(p + 0x258);
            if (h != -1) {
                s = (h << 7) + D_001A30B0;
                if (*(void **)(s + 0xDC) == a && *(u8 *)(s + 0xD0) != 0) {
                    func_003A4F28(h);
                }
            }
            *(s32 *)(p + 0x258) = -1;
            *(s32 *)(p + 0x258) = func_003A52A0(3, 4, a);
        }
        *(s32 *)(p + 0x260) = 0;
    } else {
        func_L03_0034B248(&D_L32_001E24A0, a);
        if (*(s32 *)(p + 0x260) == 0) {
            h = *(s32 *)(p + 0x258);
            if (h != -1) {
                s = (h << 7) + D_001A30B0;
                if (*(void **)(s + 0xDC) == a && *(u8 *)(s + 0xD0) != 0) {
                    func_003A4F28(h);
                }
            }
            *(s32 *)(p + 0x258) = -1;
            if (*(f32 *)(a + 0x10) < *(f32 *)(p + 0xD8)) {
                *(s32 *)(p + 0x258) = func_003A52A0(0, 4, a);
            } else {
                *(s32 *)(p + 0x258) = func_003A52A0(6, 4, a);
            }
        }
        *(s32 *)(p + 0x260) = 1;
    }
}
/* localdecomp:end func_L32_003B6170 */

INCLUDE_ASM("asm/levels", func_L32_003B6408);
