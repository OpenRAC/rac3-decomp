/* NTSC-U draft (Claude wave K): C of func_L20_003CCB38, the NTSC-U twin of func_L20_003CE4F8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L20_003CCB38", whose code is not the PAL one).
 * Worker's note: near (first full draft only, ~1 compile): 584 of 584 words but aligned score 349 (126 hunks), so no real tuning yet. Decoded layout is in the draft's header (v = obj->p68: rope 1 smoothed copies P1[32]@+0x30 / P2[32]@+0x230 of stack arrays a[]@sp+0x10 / ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L20_003CE4F8 (src/levels/*/L20_*.c). NEAR (medium), first full draft: 584 of 584 words but the aligned score
   is 349 (126 hunks): the layout of every loop is decoded from the asm (see below) but the registers/ordering are not tuned.
   Needs -mvu0-use-vf0-vf2 and @ps2as (lqc2/vadd.xyz + lui/ori/mtc1 literals) and a divs row (2 nops before the div.s at +0xF4).
   Layout (v = obj->p68): +8 s32, +0x22 s16 (random), +0x28 u8 tab[4]; rope 1: P1[32] vec at +0x30, P2[32] at +0x230 (smoothed copies of
   a[]/b[] on the stack at sp+0x10 / sp+0x210), rope 2 at +0x640 / +0x840; per-column (k = 0..3) blocks at +0x430/+0x470.. and +0x530/+0x570..
   (stride 0x40 per row, rope 2 at +0xA40/+0xB40); +0x630..0x638 and +0xC40..0xC48 hold the burst angle/pos. Stack temps: sp+0x410 t0, 0x420 t1,
   0x430 t3, 0x440, 0x450, 0x460; obj saved at 0x470, &a at 0x474, obj+0x10 at 0x478, v+0x28 at 0x47C, &t1 at 0x480. */

/* localdecomp:start func_L20_003CCB38 */
extern s32 D_001DEBB0_sda;
extern s32 D_001DEBB4_sda;
extern f32 D_001DEB88_sda;
extern f32 D_001DEB8C_sda;
extern f32 D_001DEBA0_sda;
extern s32 D_001DEBA8_sda;
extern s32 D_001DEBAC_sda;
extern s32 D_001DEB94_sda;
extern s32 D_001DEB98_sda;
extern u8 D_L20_001E2E00[];
__asm__(".extern D_001DEBB0_sda, 4");
__asm__(".extern D_001DEBB4_sda, 4");
__asm__(".extern D_001DEB88_sda, 4");
__asm__(".extern D_001DEB8C_sda, 4");
__asm__(".extern D_001DEBA0_sda, 4");
__asm__(".extern D_001DEBA8_sda, 4");
__asm__(".extern D_001DEBAC_sda, 4");
__asm__(".extern D_001DEB94_sda, 4");
__asm__(".extern D_001DEB98_sda, 4");
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(void *, f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388800(void *, void *);
extern void func_00388BF0(void *, void *);
extern void func_003888F0(void *, void *, void *);
extern void func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L20_003CCB38(u8 *obj) {
    vu0_v4 a[32];
    vu0_v4 b[32];
    vu0_v4 t0;
    vu0_v4 t1;
    vu0_v4 t2;
    vu0_v4 t3;
    vu0_v4 t4;
    vu0_v4 t5;
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    s32 k;
    s32 j;
    s32 r;
    s32 idx;
    f32 spread;
    f32 f;
    f32 d;

    *(f32 *)(obj + 0x1C) = 1.0f;
    r = func_0037E208(D_001DEBB0_sda, D_001DEBB4_sda);
    *(s32 *)(v + 8) = (s16)r;
    *(s16 *)(v + 0x22) = r;
    spread = func_0037E250(4.0f, 5.0f);
    for (i = 0; i < 32; i++) {
        f = (0.5f - (f32)i / 31.0f) * spread;
        if ((u32)(i - 3) < 0x1A) {
            func_L01_00440A88(&a[i], 0.0f, D_001DEB88_sda);
            func_L01_00440A88(&b[i], 0.0f, D_001DEB8C_sda * 0.016666668f);
        } else {
            qzero(&a[i]);
            qzero(&b[i]);
        }
        a[i].w = 1.0f;
        a[i].y = a[i].y + f;
    }
    for (i = 0; i < 32; i++) {
        if (i == 0 || i == 31) {
            *(vu0_v4 *)(v + 0x30 + i * 16) = a[i];
            *(vu0_v4 *)(v + 0x230 + i * 16) = b[i];
        } else {
            vec_add_ba(&t0, &a[i - 1], &a[i]);
            vec_add_ba(&t0, &t0, &a[i + 1]);
            func_003886E8(v + 0x30 + i * 16, &t0, 0.33333334f);
            vec_add_ba(&t0, &b[i - 1], &b[i]);
            vec_add_ba(&t0, &t0, &b[i + 1]);
            func_003886E8(v + 0x230 + i * 16, &t0, 0.33333334f);
        }
    }
    for (i = 0; i < 32; i++) {
        if (i == 0 || i == 31) {
            *(vu0_v4 *)(v + 0x640 + i * 16) = a[i];
            *(vu0_v4 *)(v + 0x840 + i * 16) = b[i];
        } else {
            vec_add_ba(&t0, &a[i - 1], &a[i]);
            vec_add_ba(&t0, &t0, &a[i + 1]);
            func_003886E8(v + 0x640 + i * 16, &t0, 0.33333334f);
            vec_add_ba(&t0, &b[i - 1], &b[i]);
            vec_add_ba(&t0, &t0, &b[i + 1]);
            func_003886E8(v + 0x840 + i * 16, &t0, 0.33333334f);
        }
    }
    for (k = 0; k < 4; k++) {
        func_L01_00440A88(&t0, D_001DEB88_sda, D_001DEB88_sda);
        idx = (s32)func_0037E250((f32)k * 6.0f, (f32)(k + 1) * 6.0f);
        v[0x28 + k] = idx + 4;
        *(vu0_v4 *)(v + 0x430 + k * 16) = *(vu0_v4 *)(v + 0x30 + (idx + 4) * 16);
        *(vu0_v4 *)(v + 0x530 + k * 16) = *(vu0_v4 *)(v + 0x230 + (idx + 4) * 16);
        for (j = 0; j < 3; j++) {
            func_L01_00440A88(&t1, 0.1f, 0.1f);
            func_L01_00440A88(v + 0x570 + k * 16 + j * 0x40, 0.0f, D_001DEB8C_sda * 0.016666668f);
            vec_add_ba(v + 0x470 + k * 16 + j * 0x40, v + 0x430 + k * 16 + j * 0x40, &t0);
            vec_add_ab(v + 0x470 + k * 16 + j * 0x40, v + 0x470 + k * 16 + j * 0x40, &t1);
        }
    }
    for (k = 0; k < 4; k++) {
        func_L01_00440A88(&t0, D_001DEB88_sda, D_001DEB88_sda);
        idx = (s32)func_0037E250((f32)k * 6.0f, (f32)(k + 1) * 6.0f);
        v[0x28 + k] = idx + 4;
        *(vu0_v4 *)(v + 0xA40 + k * 16) = *(vu0_v4 *)(v + 0x640 + (idx + 4) * 16);
        *(vu0_v4 *)(v + 0xB40 + k * 16) = *(vu0_v4 *)(v + 0x840 + (idx + 4) * 16);
        for (j = 0; j < 3; j++) {
            func_L01_00440A88(&t1, 0.1f, 0.1f);
            func_L01_00440A88(v + 0xB80 + k * 16 + j * 0x40, 0.0f, D_001DEB8C_sda * 0.016666668f);
            vec_add_ba(v + 0xA80 + k * 16 + j * 0x40, v + 0xA40 + k * 16 + j * 0x40, &t0);
            vec_add_ab(v + 0xA80 + k * 16 + j * 0x40, v + 0xA80 + k * 16 + j * 0x40, &t1);
        }
    }
    d = func_00388800(obj + 0x10, D_L20_001E2E00);
    if (4.0f <= d) {
        *(f32 *)(v + 0x638) = *(f32 *)(obj + 0xF8);
        *(f32 *)(v + 0x634) = *(f32 *)(obj + 0xF4);
        *(f32 *)(v + 0x634) = *(f32 *)(v + 0x634) + func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        *(f32 *)(v + 0x630) = func_0037E2A8();
        func_00388BF0(&t0, v + 0x630);
        t5 = *(vu0_v4 *)(obj + 0x10);
        for (i = 0; i < 32; i += 8) {
            s32 s;

            func_003888F0(&t0, v + 0x30 + i * 16, &t3);
            t1 = *(vu0_v4 *)(v + 0x230 + i * 16);
            t1.w = D_001DEBA0_sda;
            s = func_0037E1D8(2) ? D_001DEBA8_sda : D_001DEBAC_sda;
            func_L01_0045FEC8(&t0, &t1, &t1, D_001DEB94_sda, D_001DEB98_sda, i >> 1, 0xF, func_0037E1D8(10) + 0x14, s);
        }
        for (i = 0; i < 2; i++) {
            func_003888F0(&t0, v + 0x4F0 + i * 16, &t3);
            t1 = *(vu0_v4 *)(v + 0x5F0 + i * 16);
            t1.w = D_001DEBA0_sda;
            func_0037E1D8(2);
            func_L01_0045FEC8(&t0, &t1, &t1, D_001DEB94_sda, D_001DEB98_sda, v[0x28 + i] >> 1, 0xF, func_0037E1D8(10) + 0x14, D_001DEBAC_sda);
        }
    }
    d = func_00388800(obj + 0x10, D_L20_001E2E00);
    if (4.0f <= d) {
        *(f32 *)(v + 0xC48) = *(f32 *)(obj + 0xF8);
        *(f32 *)(v + 0xC44) = *(f32 *)(obj + 0xF4);
        *(f32 *)(v + 0xC44) = *(f32 *)(v + 0xC44) + func_L01_00440918(0.0f, 30.0f) * 0.017453292f;
        *(f32 *)(v + 0xC40) = func_0037E2A8();
        func_00388BF0(&t0, v + 0xC40);
        t4 = *(vu0_v4 *)(obj + 0x10);
        for (i = 0; i < 32; i += 8) {
            s32 s;

            func_003888F0(&t2, v + 0x640 + i * 16, &t0);
            t5 = *(vu0_v4 *)(v + 0x840 + i * 16);
            t5.w = D_001DEBA0_sda;
            s = func_0037E1D8(2) ? D_001DEBA8_sda : D_001DEBAC_sda;
            func_L01_0045FEC8(&t2, &t5, &t5, D_001DEB94_sda, D_001DEB98_sda, i >> 1, 0xF, func_0037E1D8(10) + 0x14, s);
        }
        for (i = 0; i < 2; i++) {
            func_003888F0(&t2, v + 0xB00 + i * 16, &t0);
            t5 = *(vu0_v4 *)(v + 0xC00 + i * 16);
            t5.w = D_001DEBA0_sda;
            func_0037E1D8(2);
            func_L01_0045FEC8(&t2, &t5, &t5, D_001DEB94_sda, D_001DEB98_sda, v[0x28 + i] >> 1, 0xF, func_0037E1D8(10) + 0x14, D_001DEBAC_sda);
        }
    }
}
/* localdecomp:end func_L20_003CCB38 */
