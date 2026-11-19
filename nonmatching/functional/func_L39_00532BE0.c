/* functional: high. Same operations as retail; only instruction scheduling and the layout of the two branches differ. */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern f32 D_001DF570_sda;
extern f32 D_001DF574_sda;
extern f32 D_001DF57C_sda;
extern f32 D_001DF590_sda;
extern f32 D_001DF594_sda;
extern f32 D_001DF598_sda;
extern f32 D_001DF59C_sda;
extern f32 D_001DF5A0_sda;
extern f32 D_001DF5A4_sda;
extern f32 D_001DF5A8_sda;
extern f32 D_001DF5B8_sda;
extern f32 D_001DF5BC_sda;
extern f32 D_001DF5C0_sda;
extern f32 D_001DF5C4_sda;
extern f32 D_001DF5C8_sda;
extern f32 D_001DF5CC_sda;
extern f32 D_001DF5D4_sda;
extern f32 D_001DF5D8_sda;
extern f32 D_001DF5DC_sda;
__asm__(".extern D_001DF570_sda, 4");
__asm__(".extern D_001DF574_sda, 4");
__asm__(".extern D_001DF57C_sda, 4");
__asm__(".extern D_001DF590_sda, 4");
__asm__(".extern D_001DF594_sda, 4");
__asm__(".extern D_001DF598_sda, 4");
__asm__(".extern D_001DF59C_sda, 4");
__asm__(".extern D_001DF5A0_sda, 4");
__asm__(".extern D_001DF5A4_sda, 4");
__asm__(".extern D_001DF5A8_sda, 4");
__asm__(".extern D_001DF5B8_sda, 4");
__asm__(".extern D_001DF5BC_sda, 4");
__asm__(".extern D_001DF5C0_sda, 4");
__asm__(".extern D_001DF5C4_sda, 4");
__asm__(".extern D_001DF5C8_sda, 4");
__asm__(".extern D_001DF5CC_sda, 4");
__asm__(".extern D_001DF5D4_sda, 4");
__asm__(".extern D_001DF5D8_sda, 4");
__asm__(".extern D_001DF5DC_sda, 4");
extern u8 D_L39_00243F20[];
extern f32 func_L01_004482A0(void *, void *, f32, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D160(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_0040E728(void *, void *, f32);
extern s32 func_L01_0040E6B8(void *, void *, f32);
extern void func_L39_00532550(void *);
extern void func_L39_005BC798(void *, void *, void *, void *, f32, f32, f32);
extern void func_L39_00532698(void *, void *, void *, void *, f32, f32, f32, void *, void *);
extern void func_L39_0066A398(void *, f32);

void func_L39_00532BE0(u8 *self) {
    u8 *s;
    u8 *cam;
    u8 *tgt;
    u8 *p;
    s32 flag;
    f32 gain;
    f32 x;
    f32 f20;
    f32 f21;
    f32 ang;
    u8 L[0x40] __attribute__((aligned(16)));

    s = *(u8 **)(self + 0x68);
    cam = *(u8 **)(s + 0x160);
    *(s32 *)(L + 0x30) = 0;
    tgt = *(u8 **)(cam + 0x2D8);
    flag = 0;
    if (*(f32 *)(cam + 0x310) < -0.0100000007f) {
        flag = 1;
    }
    *(u128_t *)(L + 0x20) = *(u128_t *)(self + 0x10);
    gain = D_001DF570_sda;
    if (tgt != 0) {
        x = *(f32 *)(*(u8 **)(tgt + 0x2534) + 0x10C);
        if (x < 0.0f) {
            gain = gain * -x;
        } else {
            gain = D_001DF574_sda * -x;
        }
        if (gain != 0.0f) {
            func_L01_004482A0(cam + 0x310, s + 0x148, gain * 0.0200000014f, D_001DF598_sda * 1.44000006f, D_001DF59C_sda * 1.44000006f, D_001DF594_sda * 0.000400000019f);
        } else {
            func_L01_004482A0(cam + 0x310, s + 0x148, 0.0f, D_001DF5A4_sda * 1.44000006f, D_001DF5A8_sda * 1.44000006f, D_001DF5A0_sda * 0.000400000019f);
        }
    } else {
        func_L01_004482A0(cam + 0x310, s + 0x148, 0.0f, D_001DF5BC_sda * 1.44000006f, D_001DF5C0_sda * 1.44000006f, D_001DF5B8_sda * 0.000400000019f);
    }
    {
        f32 y = *(f32 *)(cam + 0x310);
        if (y < 0.0f) {
            f21 = -y;
        } else {
            f21 = y;
        }
    }
    if (tgt != 0) {
        f20 = *(f32 *)(tgt + 0x110) * D_001DF590_sda;
        if (flag != 0) {
            *(f32 *)(self + 0xF8) = func_0038DB00(*(f32 *)(self + 0xF8), f20 * 0.0174532924f * 0.0200000014f);
        } else {
            *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), f20 * 0.0174532924f * 0.0200000014f);
        }
    }
    f20 = 0.0f;
    if (cam[0x300] != 0) {
        ang = func_0038D160(*(f32 *)(cam + 0x270), *(f32 *)(cam + 0x274));
    } else {
        f20 = -*(f32 *)(self + 0xF4);
        if (flag != 0) {
            ang = func_0038DAB8(*(f32 *)(self + 0xF8), 3.14159274f);
        } else {
            ang = *(f32 *)(self + 0xF8);
        }
    }
    func_00382760(L, f21, ang, f20);
    p = cam + 0x270;
    func_0038CE20(L, L, D_001DF57C_sda);
    vec_add_ab(cam + 0x270, cam + 0x270, L);
    if (cam[0x300] != 0) {
        *(f32 *)(cam + 0x278) = *(f32 *)(s + 0xF8) - D_001DF5C4_sda * 0.000400000019f;
        func_L01_0040E728(p, p, f21);
    } else {
        func_L01_0040E6B8(p, p, f21);
    }
    func_L39_00532550(self);
    if (cam[0x300] == 0) {
        func_L39_005BC798(self + 0xC0, self + 0xF0, cam + 0x284, s + 0x100, D_001DF5D4_sda, D_001DF5D8_sda, D_001DF5DC_sda);
    } else {
        *(u128_t *)(s + 0x100) = *(u128_t *)D_L39_00243F20;
        func_L39_005BC798(self + 0xC0, self + 0xF0, cam + 0x284, s + 0x100, D_001DF5D4_sda, D_001DF5D8_sda, D_001DF5DC_sda);
    }
    *(u128_t *)(s + 0xF0) = *(u128_t *)(cam + 0x270);
    if (cam[0x300] != 0) {
        *(u16 *)(cam + 0x302) = *(u16 *)(cam + 0x302) + 1;
    } else {
        *(u16 *)(cam + 0x302) = 0;
        *(f32 *)(s + 0x144) = *(f32 *)(self + 0x18);
    }
    func_L39_00532698(self, cam, self + 0x10, p, fabs_asm(*(f32 *)(cam + 0x310)), D_001DF5C8_sda, D_001DF5CC_sda, L + 0x10, L + 0x30);
    if (tgt != 0) {
        *(u128_t *)(*(u8 **)(tgt + 0x2524) + 0x10) = *(u128_t *)(self + 0x10);
        *(u128_t *)(*(u8 **)(tgt + 0x2524) + 0xF0) = *(u128_t *)(self + 0xF0);
    }
    func_L39_0066A398(cam, 50.0f);
    *(u128_t *)(cam + 0x230) = *(u128_t *)(self + 0x10);
    *(u128_t *)(cam + 0x240) = *(u128_t *)(self + 0xF0);
    *(u128_t *)(cam + 0x250) = *(u128_t *)(self + 0x10);
    *(u128_t *)(cam + 0x260) = *(u128_t *)(self + 0xF0);
}
