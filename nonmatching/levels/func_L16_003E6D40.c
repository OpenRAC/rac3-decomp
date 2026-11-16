/* NTSC-U draft (Claude wave C4): C of func_L16_003E4E20, the NTSC-U twin of func_L16_003E6D40, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L16_003E4E20", whose code is not the PAL one).
 * Worker's note: flags: needs @ps2as (6 lui/ori/mtc1 constants: 1.618f x3, 0.008333334f, 0.9f, 0.1f; the PAL file's line has -mvu0-use-vf0-vf2 but no @ps2as), so it cannot land even if exact; also NEEDS divs row 'func_L16_003E4E20 1'. With '-mvu0-use-vf0-vf2 -O2 -G8 ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L16_003E6D40 (src/levels/16_kerwan/L16_003E6C48.c). Needs '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (6 lui/ori/mtc1 constants: 1.618f x3, 0.008333334f, 0.9f, 0.1f; the PAL file's line has vu0 but no @ps2as) and the divs_nops row 'func_L16_003E4E20 1'. 16 of 332 words differ (aligned TOTAL 19): see the report row. Names the PAL C uses for other things carry the _003E4E20 alias suffix. func_L01_0045FEC8 returns s32 (ignored): that decides a loop-bound temp register. */

/* localdecomp:start func_L16_003E4E20 */
typedef int u128_t __attribute__((mode(TI)));
typedef union { f32 f[0xA80]; u8 *ptr[0xA80]; u8 b[0x2A00]; } Hero_E4E20;
extern Hero_E4E20 D_001A4BE0;
extern s32 D_001A71A0;
__asm__(".extern D_001A71A0, 16");
extern s32 D_L16_001E98D8[];
extern s32 D_L16_001DFC40_003E4E20;
__asm__(".extern D_L16_001DFC40_003E4E20, 16");
extern u8 *D_L16_001ED940[];
extern f32 D_001DF524_sda;
__asm__(".extern D_001DF524_sda, 4");
extern s32 D_001DF620_sda_003E4E20;
__asm__(".extern D_001DF620_sda_003E4E20, 4");
extern f32 D_001DF624_sda;
__asm__(".extern D_001DF624_sda, 4");
extern f32 D_001DF628_sda_003E4E20;
__asm__(".extern D_001DF628_sda_003E4E20, 4");
extern s32 D_001DF62C_sda_003E4E20;
__asm__(".extern D_001DF62C_sda_003E4E20, 4");
extern s32 D_001DF630_sda_003E4E20;
__asm__(".extern D_001DF630_sda_003E4E20, 4");
extern f32 D_001DF528_sda;
__asm__(".extern D_001DF528_sda, 4");
extern f32 D_001DF52C_sda;
__asm__(".extern D_001DF52C_sda, 4");
extern f32 D_001DF520_sda;
__asm__(".extern D_001DF520_sda, 4");
extern s32 D_001DF51C_sda;
__asm__(".extern D_001DF51C_sda, 4");
extern s32 func_L01_003F9498(void *, s32, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_003BD360(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L16_003E5420(void *, void *, s32);
extern u8 *func_003BF7E8(void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_00443938(void *, void *, s32, void *, void *, f32);
extern s32 func_003CF790(void *, s32, f32, s32, s32);
extern void func_L01_003C2140(void *);
extern void func_L16_003E5CD0(void);
extern void func_L01_00402498(void (*)(void), void *);

void func_L16_003E4E20(u8 *o) {
    vu0_v4 pos0;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    u8 *s;
    u8 *pos;
    u8 *hp;
    u8 *m;
    s32 i;
    s32 j;
    s32 n;
    f32 x;
    f32 y;
    f32 t;
    f32 t1;
    f32 tr;
    f32 td;
    f32 tf;
    f32 f20;
    f32 z0;

    pos = o + 0x10;
    s = *(u8 **)(o + 0x68);
    *(u128_t *)&pos0 = *(u128_t *)(o + 0x10);
    switch (o[0x20]) {
    case 0:
        vec_add_ba(o + 0x10, o + 0x10, s + 0x20);
        break;
    case 1:
        vec_add_ab(o + 0x10, o + 0x10, s + 0x20);
        if (func_L01_003F9498(pos, 0, o, *(f32 *)(s + 0x18)) != 0) {
            if (D_001A71A0 == D_L16_001E98D8[0]) {
                *(f32 *)(o + 0x18) = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_001DF524_sda;
                func_L01_00441FB8(o, 2, -1);
            }
        }
        t1 = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_001DF524_sda;
        if (*(f32 *)(o + 0x18) <= t1) {
            *(f32 *)(o + 0x18) = t1;
            func_L01_00441FB8(o, 2, -1);
        }
        for (i = 0; i < D_001DF620_sda_003E4E20; i++) {
            x = func_0037E2A8();
            y = func_0037E2A8();
            tr = func_0037E250(0.0f, *(f32 *)(s + 0x18) * *(f32 *)s * D_001DF624_sda);
            func_0037E4B8(&a, tr, x, y);
            vec_add_ba(&a, o + 0x10, &a);
            qzero(&b);
            b.w = D_001DF628_sda_003E4E20;
            vec_add_ab(&b, &b, s + 0x30);
            qzero(&c);
            vec_add_ab(&c, &c, s + 0x30);
            func_L01_0045FEC8(&a, &b, &c, D_001DF630_sda_003E4E20, D_001DF630_sda_003E4E20, 1, 0x1E, func_0037E208(0xA, 0x14), D_001DF62C_sda_003E4E20);
        }
        if (!(D_L16_001DFC40_003E4E20 < *(s32 *)(s + 8))) {
            func_003BEBF8((f32 *)s, 0.0f, 0.008333334f);
        }
        if (*(f32 *)s <= 0.0f) {
            func_003BD360(o);
            return;
        }
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            *(f32 *)s = *(f32 *)(s + 0x18);
            qzero(s + 0x20);
            *(f32 *)(o + 0x18) = *(f32 *)(*(u8 **)(s + 0x10) + 0x18) + 1.618f + D_001DF524_sda;
            o[0x23] = 0x80;
            func_L01_004A72A8(0xB, 0, o, 0x1A0A);
            func_L16_003E5420(o, s + 0x30, 1);
        }
        f20 = *(f32 *)s * D_001DF528_sda;
        func_003BEBF8((f32 *)(s + 0x18), f20, D_001DF52C_sda);
        if (*(u8 **)(s + 0x10) != 0) {
            *(u128_t *)(s + 0x30) = *(u128_t *)(func_003BF7E8(*(u8 **)(s + 0x10)) + 0x10);
        }
        vec_add_ab(o + 0x10, o + 0x10, s + 0x30);
        z0 = 0.0f;
        if (z0 < *(f32 *)(s + 0x14)) {
            hp = (u8 *)&D_001A4BE0 + 0x80;
            td = func_00388800(pos, hp);
            if (td < *(f32 *)(s + 0x18) && *(f32 *)(s + 0x18) - D_001DF520_sda < td) {
                if (D_001A4BE0.f[0x88 / 4] < *(f32 *)(o + 0x18)) {
                    qzero(&a);
                    qzero(&b);
                    func_L01_00443938(D_001A4BE0.ptr[0x25C0 / 4], *(u8 **)(s + 4), D_001DF51C_sda, &a, &b, *(f32 *)(s + 0x14));
                    *(f32 *)(s + 0x14) = z0;
                }
            }
        }
        n = func_003CF790(o + 0x10, 1, *(f32 *)(s + 0x18) + 1.5f, D_001A71A0, 0);
        for (j = 0; j < n; j++) {
            m = D_L16_001ED940[j];
            if (m != 0 && *(s16 *)(m + 0xAA) == 0x1ADA) {
                func_L01_003C2140(m);
            }
        }
        if (f20 * 0.9f < *(f32 *)(s + 0x18)) {
            tf = (f20 - *(f32 *)(s + 0x18)) / (f20 * 0.1f);
            if (1.0f < tf) {
                tf = 1.0f;
            } else if (tf < 0.0f) {
                tf = 0.0f;
            }
            o[0x23] = (s32)(tf * 128.0f);
        }
        if (o[0x23] == 0) {
            func_003BD360(o);
            return;
        }
        break;
    }
    vec_sub_ba(&a, o + 0x10, &pos0);
    func_L16_003E5420(o, &a, 0);
    func_L01_00402498(func_L16_003E5CD0, o);
}
/* localdecomp:end func_L16_003E4E20 */
