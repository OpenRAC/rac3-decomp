/* NTSC-U draft (Claude wave C4): C of func_L19_003AC958, the NTSC-U twin of func_L19_003AE5A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L19_003AC958", whose code is not the PAL one).
 * Worker's note: flags: needs -mvu0-use-vf0-vf2 (3 vec ops through the vu0.h helpers: vec_sub_ba x2, vec_add_ab) on top of its PAL flags (STD @ps2as); the PAL file's flag line lacks it, so it cannot land even if exact. With '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L19_003AE5A8 (src/levels/shared/L19_003ADE70.c) */
#include "vu0.h"

/* localdecomp:start func_L19_003AC958 */
typedef int u128_t __attribute__((mode(TI)));
extern f32 D_001DE5E8_sda;
__asm__(".extern D_001DE5E8_sda, 4");
extern f32 D_001DE5EC_sda;
__asm__(".extern D_001DE5EC_sda, 4");
extern f32 D_001DE5F0_sda;
__asm__(".extern D_001DE5F0_sda, 4");
extern s32 D_001DE5F8_sda;
__asm__(".extern D_001DE5F8_sda, 4");
extern s32 D_001DF240_sda;
__asm__(".extern D_001DF240_sda, 4");
extern f32 D_L19_001DE5F4;
__asm__(".extern D_L19_001DE5F4, 16");
extern s32 D_L19_001DE5FC;
__asm__(".extern D_L19_001DE5FC, 16");
extern s32 D_L19_001DE600;
__asm__(".extern D_L19_001DE600, 16");
extern s32 D_L19_001DE604;
__asm__(".extern D_L19_001DE604, 16");
extern u8 D_L19_001E1F40[];
extern u8 D_L19_001E8E60[];
extern s32 D_001A71A0[];
extern u8 D_001A30B0[];
extern u8 D_001A3190[];
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0039FB08(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L01_00443610(void *, void *, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern u8 *func_0037E0B8(s32);
extern void func_L01_00463938(void *, void *, s32, f32, f32);
extern s32 func_00388398(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L19_003ACFB8(void);

void func_L19_003AC958(u8 *o) {
    u8 *s = *(u8 **)(o + 0x68);
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30[3];
    s32 hit;
    s32 slot;
    u8 *rec;
    f32 dist;

    if (o[0x20] == 3 && func_0037E208(0, 0x1E) < *(u16 *)(o + 0x96)) {
        vec_sub_ba(&v10, s + 0x60, o + 0x10);
        func_00388830(&v10, &v10, D_001DE5E8_sda);
        v10.x += func_0037E250(-D_001DE5EC_sda, D_001DE5EC_sda);
        v10.y += func_0037E250(-D_001DE5EC_sda, D_001DE5EC_sda);
        v10.z += func_0037E250(-D_001DE5EC_sda, D_001DE5EC_sda);
        v10.w = func_0037E250(D_001DE5F0_sda, D_L19_001DE5F4);
        func_003886E8(&v20, &v10, 0.5f);
        v20.z -= 0.1f;
        func_L01_0045FEC8(o + 0x10, &v10, &v20,
                          func_003894A0(D_001DE5F8_sda, D_L19_001DE5FC, func_0037E250(0.0f, 1.0f)),
                          func_003894A0(D_L19_001DE600, D_L19_001DE604, func_0037E250(0.0f, 1.0f)),
                          10, 20, 6, 0x1003C);
        slot = *(s32 *)(s + 8);
        if (slot != -1) {
            rec = D_001A30B0 + (slot << 7);
            if (*(u8 **)(rec + 0xDC) == o && rec[0xD0] != 0) {
                func_0039FB08(slot);
            }
        }
        *(s32 *)(s + 8) = -1;
        return;
    }
    hit = 0;
    dist = func_L01_0040C040(s + 0x40, (D_L19_001E1F40 + 0x140));
    if (dist < 256.0f) {
        func_L01_00443610(v30, o, 0x110001, 10.0f);
        *(u16 *)((u8 *)v30 + 0x1A) = *(u16 *)(o + 0xAA);
        *(u128_t *)(s + 0x50) = *(u128_t *)(s + 0x60);
        if (func_003CE740(o + 0x10, s + 0x40, 0, o, o[0x20] != 3 ? (void *)v30 : 0) != 0) {
            *(u128_t *)(s + 0x60) = *(u128_t *)D_L19_001E8E60;
            if (*(s32 *)(D_L19_001E8E60 - 8) == D_001A71A0[0] || func_0037E0B8(*(s32 *)(D_L19_001E8E60 - 8)) != 0) {
                hit = 1;
            }
        } else {
            *(u128_t *)(s + 0x60) = *(u128_t *)(s + 0x40);
        }
    } else {
        *(u128_t *)(s + 0x60) = *(u128_t *)(s + 0x40);
    }
    vec_sub_ba(&v10, s + 0x60, (D_L19_001E1F40 + 0x140));
    if (*(s32 *)s != 3 && dist < 256.0f &&
        0.0f < ((f32 *)D_L19_001E1F40)[0x160 / 4] * v10.x + ((f32 *)D_L19_001E1F40)[0x164 / 4] * v10.y) {
        if (*(s32 *)s != 2) {
            qzero(&v20);
            func_L01_00463938(s + 0x60, &v20, 0, -1.0f, 0.0f);
            if (dist < 128.0f) {
                vec_add_ab(&v30[0], s + 0x60, s + 0x50);
                func_003886E8(&v30[0], &v30[0], 0.5f);
                func_L01_00463938(&v30[0], &v20, 0, -1.0f, 0.0f);
            }
        }
        if (dist < 128.0f) {
            if (D_001DF240_sda & 1) {
                qzero(&v20);
                v20.x = func_0037E250(-0.005f, 0.005f);
                v20.y = func_0037E250(-0.005f, 0.005f);
                qzero(&v30[0]);
                v20.z = 0.03f;
                v20.w = 0.1f;
                v30[0].x = v20.x * 0.5f;
                v30[0].y = v20.y * 0.5f;
                v30[0].z = 0.01f;
                v30[0].w = 0.4f;
                func_L01_0045FEC8(s + 0x60, &v20, &v30[0], 0x75000000, 0x60404040, 5, 10, 10, -1);
            } else {
                qzero(&v20);
                v20.x = func_0037E250(-0.01f, 0.01f);
                v20.y = func_0037E250(-0.01f, 0.01f);
                qzero(&v30[0]);
                v20.z = 0.03f;
                v20.w = 0.1f;
                v30[0].x = v20.x * 0.5f;
                v30[0].y = v20.y * 0.5f;
                v30[0].z = 0.0f;
                v30[0].w = 0.2f;
                func_L01_0045FEC8(s + 0x60, &v20, &v30[0], 0x7F0040FF, 0x40204060, 2, 6, 4, -1);
            }
        }
    }
    if (*(s32 *)(s + 8) < 0 || *(u8 **)(D_001A30B0 + (*(s32 *)(s + 8) << 7) + 0xDC) != o) {
        *(s32 *)(s + 8) = func_0039FE80(0, 0xC, o);
    }
    if (*(s32 *)(s + 8) >= 0) {
        *(u128_t *)(D_001A3190 + (*(s32 *)(s + 8) << 7)) = *(u128_t *)(s + 0x60);
    }
    if (func_00388398(s + 0x14) != 0 && hit != 0) {
        func_0039FE80(1, 0, o);
        *(s32 *)(s + 0x14) = 0x1E;
    }
    func_L01_00402498((void *)func_L19_003ACFB8, o);
}
/* localdecomp:end func_L19_003AC958 */
