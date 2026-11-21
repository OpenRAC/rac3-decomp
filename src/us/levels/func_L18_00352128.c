#include "common.h"

/* NTSC-U counterpart of func_L18_00352D30 (src/levels/shared/L18_00352AF8.c): 0.0523599 -> 0.0436332; 0.00349066 -> 0.00242407; 0.0349066 -> 0.0290888; 0.0288 -> 0.02; 0.216 -> 0.15; 0.01152 -> 0.008; 0.288 -> 0.2 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_003893C8(f32, f32);

/* localdecomp:start func_L18_00352128 */
typedef struct {
    u32 flag;
    u8 pad[0x1C];
} E_00352D30;
typedef struct {
    u8 p0[0x2260];
    f32 x2260;
    f32 x2264;
    u8 p2268[0x25C4 - 0x2268];
    s32 x25C4;
} G_00352D30;
extern G_00352D30 D_001A4BE0_00352128;
extern u8 *D_001D52FC;
extern u8 D_001439F4[];
extern E_00352D30 D_00143A70[];
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L18_00351EF0(u8 *);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_00389018(void *, s32, f32);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern void func_003BEA80(void *, void *);

void func_L18_00352128(u8 *o) {
    u8 *p;
    u8 *cam;
    f32 a;
    f32 b;
    f32 c;
    f32 x;
    f32 ax;
    f32 z;
    f32 s;
    f32 t;
    s32 sel;

    p = *(u8 **)(o + 0x68);
    a = 0.0f;
    b = 0.0f;
    c = 0.0f;
    cam = D_001D52FC;
    if (D_001A4BE0_00352128.x25C4 != 0x31) {
        func_003BEBF8((f32 *)(p + 0x390), 0.0436332338f, 0.00242406852f);
    } else {
        x = D_001A4BE0_00352128.x2260;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            b = ax * -0.6f;
        } else if (x < 0.0f) {
            a = ax * -0.6f;
        }
        c = x * 0.3f;
        x = D_001A4BE0_00352128.x2264;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            z = ax * 0.5f;
            b += z;
            a += z;
        } else if (x < 0.0f) {
            z = ax * -0.6f;
            b += z;
            a += z;
        }
        sel = D_001439F4[0];
        s = 1.0f;
        if (D_00143A70[sel].flag != 0) {
            s = -1.0f;
        }
        if (sel == 0) {
            s = 1.0f;
        }
        x = *(f32 *)(cam + 0x100) * s;
        ax = fabs_asm(x);
        if (x > 0.0f) {
            b += ax * -0.6f;
            a += ax * 0.5f;
        } else if (x < 0.0f) {
            b += ax * 0.5f;
            a += ax * -0.6f;
        }
        if (b > 0.5f) {
            b = 0.5f;
        }
        if (b < -0.6f) {
            b = -0.6f;
        }
        if (a > 0.5f) {
            a = 0.5f;
        }
        if (a < -0.6f) {
            a = -0.6f;
        }
        c += x * 0.3f;
        if (c > 0.3f) {
            c = 0.3f;
        }
        if (c < -0.3f) {
            c = -0.3f;
        }
        if (*(s32 *)(p + 0x3BC) == 0) {
            t = b;
            b = a;
            a = t;
        }
    }
    func_L18_00351EF0(o);
    *(f32 *)(p + 0x388) = func_003893C8(*(f32 *)(p + 0x388), *(f32 *)(p + 0x390));
    *(f32 *)(p + 0x38C) = func_00389380(*(f32 *)(p + 0x38C), *(f32 *)(p + 0x390));
    func_00389018(p + 0xA0, 2, *(f32 *)(p + 0x388));
    func_00389018(p + 0xE0, 2, *(f32 *)(p + 0x38C));
    func_003BEBF8((f32 *)(p + 0x394), b, 0.0290888231f);
    func_003BEBF8((f32 *)(p + 0x39C), a, 0.0290888231f);
    func_00389018(p + 0x120, 1, *(f32 *)(p + 0x394));
    func_00389018(p + 0x160, 1, *(f32 *)(p + 0x39C));
    t = func_00389380(*(f32 *)(p + 0x350), *(f32 *)(p + 0x2B4));
    func_L01_004455F0(p + 0x2C4, -t, p + 0x3A4, 0.0199999996f, 0.150000006f, 0.0290888231f, 0);
    func_L01_004455F0(p + 0x2C8, *(s32 *)(p + 0x3BC) != 0 ? -c : c, p + 0x3A8, 0.00800000038f, 0.200000003f, 0.0290888231f, 0);
    func_003BEA80(p + 0x1A0, p + 0x2C0);
    *(u128_t *)(p + 0x1E0) = *(u128_t *)(p + 0x1A0);
}
/* localdecomp:end func_L18_00352128 */
