/* NTSC-U draft (Claude wave K): C of func_L40_00424050, the NTSC-U twin of func_L40_00424920, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 68 words differ on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L40_00424050", whose code is not the PAL one).
 * Worker's note: 68 diff lines (almost all one shift): body, vf1/vf2 asm (local vec_add_ba_vf, no vu0 flag so "j" class unusable), fabs_asm, args all match. Blocks: retail loads D_L40_002412AC via lui/lw before the loop (non-gp form) but the delay-slot reload at loop end is ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L40_00424920 (src/levels/shared/L40_00424920.c) */
#include "vu0.h"
extern s32 func_L40_00421C10(u8 *);
extern s32 func_L40_00421C70(u8 *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L39_005CB8E0(void *, s32, s32, s32, s32, s32, s32, s32, f32);

/* localdecomp:start func_L40_00424050 */
static __inline__ void vec_add_ba_vf(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %2
	lqc2 $vf1, %1
	vadd.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
typedef struct { s32 a, b; } E_3A3570;
extern E_3A3570 D_L40_003A3570[];
extern s32 D_L40_002412AC;
extern f32 D_001DC030_sda;
extern f32 D_001DC034_sda;
extern s32 D_001DC038_sda;
extern s32 D_001DC03C_sda;
__asm__(".extern D_001DC030_sda, 4");
__asm__(".extern D_001DC034_sda, 4");
__asm__(".extern D_001DC038_sda, 4");
__asm__(".extern D_001DC03C_sda, 4");

void func_L40_00424050(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    s32 i;
    s32 j;
    s32 idx;
    E_3A3570 *tbl;

    if (func_L40_00421C10(a0)) {
        idx = *(s32 *)(p + 0x7C);
    } else {
        if (!func_L40_00421C70(a0)) {
            return;
        }
        idx = *(s32 *)(p + 0x80);
    }
    tbl = &D_L40_003A3570[idx];
    if (*(void **)(p + 0x78) != 0) {
        func_003886E8(v, *(void **)(p + 0x78), 0.0009765625f);
    } else {
        *(vu0_q *)w = *(vu0_q *)(a0 + 0xE0);
        func_00388830(w, w, 0.75f);
        vec_add_ba_vf(v, a0 + 0x10, w);
    }
    j = 0;
    for (i = 0; i < 4; i++) {
        s32 col;
        s32 a;
        col = func_003894A0(tbl->a, tbl->b, fabs_asm(0.5f - (f32)(0xFF - ((D_L40_002412AC + j) & 0xFF)) / 255.0f));
        j += 0x14;
        a = (u8)D_L40_002412AC;
        if (i & 2) {
            a = a << 1;
        }
        if (i & 1) {
            a = 0xFF - a;
        }
        func_L39_005CB8E0(v, col, a & 0xFF, D_001DC03C_sda, D_001DC038_sda, 2, 0, 0,
                          (D_001DC030_sda + (f32)i * D_001DC034_sda) * (*(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24)));
    }
}
/* localdecomp:end func_L40_00424050 */
