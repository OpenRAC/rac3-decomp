/* NTSC-U draft (Claude wave K): C of func_L39_006646E0, the NTSC-U twin of func_L39_00666FB8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 64 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L39_006646E0", whose code is not the PAL one).
 * Worker's note: 64 diff, all register/schedule order (opcodes and offsets right): pool spawner u8 *f(s32 id, u8 *src, s32 unused_a2, s32 a3, s32 a4, f32 f): o = D_L39_00337800 + D_L39_00246378*0x340 (counter gp via .extern 4), w0 = (n+1)/0x3000000, +0x14 = D_L39_002463A0, ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_00666F88 (src/levels/shared/L39_00666F88.c) */
/* localdecomp:start func_L39_006646E0 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L39_00246378;
__asm__(".extern D_L39_00246378, 4");
extern char D_L39_00337800[];
extern u8 D_L39_002463A0[];
extern u8 D_L39_0049C880[];
extern s32 D_001A5E50[];
extern void func_L39_0061C568(void *, void *, s32);

u8 *func_L39_006646E0(s32 id, u8 *src, s32 a2, s32 a3, s32 a4, f32 f) {
    u8 *o;
    s32 n;

    n = D_L39_00246378;
    o = (u8 *)D_L39_00337800 + n * 0x340;
    *(s32 *)o = (n + 1) | 0x3000000;
    *(u8 **)(o + 0x14) = D_L39_002463A0;
    *(f32 *)(o + 0x314) = f;
    *(s16 *)(o + 0x2FC) = id;
    *(u8 **)(o + 0x2D0) = src;
    *(u8 **)(o + 0x110) = D_L39_0049C880 + id * 0x28;
    *(s32 *)(o + 0x2F4) = a3;
    *(s32 *)(o + 0x2F8) = a4;
    *(u16 *)(o + 0x304) = *(u16 *)(src + 0xB2);
    *(u128_t *)(o + 0x290) = *(u128_t *)(src + 0x10);
    *(u128_t *)(o + 0x2A0) = *(u128_t *)(src + 0xF0);
    *(u128_t *)(o + 0x250) = *(u128_t *)(src + 0x10);
    *(u128_t *)(o + 0x260) = *(u128_t *)(src + 0xF0);
    *(u128_t *)(o + 0x1F0) = *(u128_t *)(src + 0x10);
    *(u128_t *)(o + 0x200) = *(u128_t *)(src + 0xF0);
    *(u128_t *)(o + 0x230) = *(u128_t *)(src + 0x10);
    *(s32 *)(o + 0x318) = 0;
    *(u128_t *)(o + 0x2B0) = 0;
    *(u128_t *)(o + 0x240) = *(u128_t *)(src + 0xF0);
    *(u128_t *)(o + 0x2C0) = 0;
    *(s32 *)(o + 0x2E0) = D_001A5E50[0x128 / 4];
    func_L39_0061C568(o + 0x20, src + 0x10, D_001A5E50[0x128 / 4]);
    D_L39_00246378++;
    return o;
}
/* localdecomp:end func_L39_006646E0 */
