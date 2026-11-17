/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00532580, the NTSC-U twin of func_L39_00532BE0, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as" (src/levels/shared/L39_00531FB0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00532BE0 (src/levels/shared/L39_00531FB0.c) */
/* localdecomp:start func_L39_00532580 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern f32 D_001DF500_sda;
extern f32 D_001DF504_sda;
extern f32 D_001DF50C_sda;
extern f32 D_001DF520_sda;
extern f32 D_001DF524_sda;
extern f32 D_001DF528_sda;
extern f32 D_001DF52C_sda;
extern f32 D_001DF530_sda;
extern f32 D_001DF534_sda;
extern f32 D_001DF538_sda;
extern f32 D_001DF548_sda;
extern f32 D_001DF54C_sda;
extern f32 D_001DF550_sda;
extern f32 D_001DF554_sda;
extern f32 D_001DF558_sda;
extern f32 D_001DF55C_sda;
extern f32 D_001DF564_sda;
extern f32 D_001DF568_sda;
extern f32 D_001DF56C_sda;
__asm__(".extern D_001DF500_sda, 4");
__asm__(".extern D_001DF504_sda, 4");
__asm__(".extern D_001DF50C_sda, 4");
__asm__(".extern D_001DF520_sda, 4");
__asm__(".extern D_001DF524_sda, 4");
__asm__(".extern D_001DF528_sda, 4");
__asm__(".extern D_001DF52C_sda, 4");
__asm__(".extern D_001DF530_sda, 4");
__asm__(".extern D_001DF534_sda, 4");
__asm__(".extern D_001DF538_sda, 4");
__asm__(".extern D_001DF548_sda, 4");
__asm__(".extern D_001DF54C_sda, 4");
__asm__(".extern D_001DF550_sda, 4");
__asm__(".extern D_001DF554_sda, 4");
__asm__(".extern D_001DF558_sda, 4");
__asm__(".extern D_001DF55C_sda, 4");
__asm__(".extern D_001DF564_sda, 4");
__asm__(".extern D_001DF568_sda, 4");
__asm__(".extern D_001DF56C_sda, 4");
extern u8 D_L39_002440A0[];
extern f32 func_L01_00445168(void *, void *, f32, f32, f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388A28(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_L01_0040C1F8(void *, void *, f32);
extern s32 func_L01_0040C188(void *, void *, f32);
extern void func_L39_00531EF0(void *);
extern void func_L39_005BA7E0(void *, void *, void *, void *, f32, f32, f32);
extern void func_L39_00532038(void *, void *, void *, void *, f32, f32, f32, void *, void *);
extern void func_L39_00667AC0(void *, f32);

void func_L39_00532580(u8 *self) {
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
    if (*(f32 *)(cam + 0x310) < -0.0083333338f) {
        flag = 1;
    }
    *(u128_t *)(L + 0x20) = *(u128_t *)(self + 0x10);
    gain = D_001DF500_sda;
    if (tgt != 0) {
        x = *(f32 *)(*(u8 **)(tgt + 0x2534) + 0x10C);
        if (x < 0.0f) {
            gain = gain * -x;
        } else {
            gain = D_001DF504_sda * -x;
        }
        if (gain != 0.0f) {
            func_L01_00445168(cam + 0x310, s + 0x148, gain * 0.016666668f, D_001DF528_sda, D_001DF52C_sda, D_001DF524_sda * 0.00027777778f);
        } else {
            func_L01_00445168(cam + 0x310, s + 0x148, 0.0f, D_001DF534_sda, D_001DF538_sda, D_001DF530_sda * 0.00027777778f);
        }
    } else {
        func_L01_00445168(cam + 0x310, s + 0x148, 0.0f, D_001DF54C_sda, D_001DF550_sda, D_001DF548_sda * 0.00027777778f);
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
        f20 = *(f32 *)(tgt + 0x110) * D_001DF520_sda;
        if (flag != 0) {
            *(f32 *)(self + 0xF8) = func_003893C8(*(f32 *)(self + 0xF8), f20 * 0.017453292f * 0.016666668f);
        } else {
            *(f32 *)(self + 0xF8) = func_00389380(*(f32 *)(self + 0xF8), f20 * 0.017453292f * 0.016666668f);
        }
    }
    f20 = 0.0f;
    if (cam[0x300] != 0) {
        ang = func_00388A28(*(f32 *)(cam + 0x270), *(f32 *)(cam + 0x274));
    } else {
        f20 = -*(f32 *)(self + 0xF4);
        if (flag != 0) {
            ang = func_00389380(*(f32 *)(self + 0xF8), 3.1415927f);
        } else {
            ang = *(f32 *)(self + 0xF8);
        }
    }
    func_0037E4B8(L, f21, ang, f20);
    p = cam + 0x270;
    func_003886E8(L, L, D_001DF50C_sda);
    vec_add_ab(cam + 0x270, cam + 0x270, L);
    if (cam[0x300] != 0) {
        *(f32 *)(cam + 0x278) = *(f32 *)(s + 0xF8) - D_001DF554_sda * 0.00027777778f;
        func_L01_0040C1F8(p, p, f21);
    } else {
        func_L01_0040C188(p, p, f21);
    }
    func_L39_00531EF0(self);
    if (cam[0x300] == 0) {
        func_L39_005BA7E0(self + 0xC0, self + 0xF0, cam + 0x284, s + 0x100, D_001DF564_sda, D_001DF568_sda, D_001DF56C_sda);
    } else {
        *(u128_t *)(s + 0x100) = *(u128_t *)D_L39_002440A0;
        func_L39_005BA7E0(self + 0xC0, self + 0xF0, cam + 0x284, s + 0x100, D_001DF564_sda, D_001DF568_sda, D_001DF56C_sda);
    }
    *(u128_t *)(s + 0xF0) = *(u128_t *)(cam + 0x270);
    if (cam[0x300] != 0) {
        *(u16 *)(cam + 0x302) = *(u16 *)(cam + 0x302) + 1;
    } else {
        *(u16 *)(cam + 0x302) = 0;
        *(f32 *)(s + 0x144) = *(f32 *)(self + 0x18);
    }
    func_L39_00532038(self, cam, self + 0x10, p, fabs_asm(*(f32 *)(cam + 0x310)), D_001DF558_sda, D_001DF55C_sda, L + 0x10, L + 0x30);
    if (tgt != 0) {
        *(u128_t *)(*(u8 **)(tgt + 0x2524) + 0x10) = *(u128_t *)(self + 0x10);
        *(u128_t *)(*(u8 **)(tgt + 0x2524) + 0xF0) = *(u128_t *)(self + 0xF0);
    }
    func_L39_00667AC0(cam, 50.0f);
    *(u128_t *)(cam + 0x230) = *(u128_t *)(self + 0x10);
    *(u128_t *)(cam + 0x240) = *(u128_t *)(self + 0xF0);
    *(u128_t *)(cam + 0x250) = *(u128_t *)(self + 0x10);
    *(u128_t *)(cam + 0x260) = *(u128_t *)(self + 0xF0);
}
/* localdecomp:end func_L39_00532580 */
