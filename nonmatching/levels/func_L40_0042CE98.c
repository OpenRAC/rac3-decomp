/* NTSC-U draft (Claude wave C2): C of func_L40_0042C490, the NTSC-U twin of func_L40_0042CE98, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 12 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L40_0042C490", whose code is not the PAL one).
 * Worker's note: 12 diff (NEEDS divs row 'func_L40_0042C490 2' - one div.s, 2 nops - injected for the check). Body, call sequence and register assignment of the parameters/s-registers match (a4 store placed after the 1.0f/n store so pos gets $s3); left: (a) the byte stores ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L40_0042CE98 (src/levels/shared/L40_0042CE98.c) */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L40_0042C490 */
extern u8 *func_003BCFB0(s32, s32);
extern f32 func_L39_005B25C8(void);
extern s32 D_001DC210_sda;
__asm__(".extern D_001DC210_sda, 4");
extern s16 D_L40_00249B40[];
extern s16 D_L40_00249B50[];

u8 *func_L40_0042C490(u128_t *pos, s32 a1, s32 a2, u128_t *vec, s32 a4, f32 f)
{
    u8 *o = func_003BCFB0(0x1B3A, 0x80);
    u8 *v;
    s32 i;
    s32 n;

    if (o != 0) {
        o[0x31] = 1;
        o[0x30] = 0xFF;
        *(u16 *)(o + 0x32) = 0xFF;
        o[0x20] = 0;
        *(s32 *)(o + 0xB8) = a1;
        v = *(u8 **)(o + 0x68);
        *(u128_t *)(v + 0x30) = *vec;
        *(u128_t *)(o + 0x10) = *pos;
        n = D_001DC210_sda;
        *(s32 *)(v + 0x10) = n;
        *(f32 *)(v + 0x14) = 1.0f / (f32)n;
        *(s32 *)(v + 0x1C) = a4;
        *(f32 *)(o + 0xF0) = func_L39_005B25C8();
        *(f32 *)(o + 0xF4) = func_L39_005B25C8();
        *(f32 *)(o + 0xF8) = func_L39_005B25C8();
        *(f32 *)v = func_L39_005B25C8();
        *(f32 *)(v + 4) = func_L39_005B25C8();
        *(f32 *)(v + 8) = func_L39_005B25C8();
        *(s32 *)(o + 0xB8) = a1;
        *(f32 *)(v + 0xC) = f;
        for (i = 0; i < 3; i++) {
            D_L40_00249B40[i] = -1;
            D_L40_00249B50[i] = 0x18;
        }
        o[0x20] = 0;
    }
    return o;
}
/* localdecomp:end func_L40_0042C490 */
