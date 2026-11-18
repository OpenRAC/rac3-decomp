/* PAL port of the NTSC-U draft (round 8): PAL port of the NTSC-U draft, re-measured in round 8 (draft file now holds the PAL C: func_003C24B0, func_L39_005B44C8, D_L40_002499C0/D0, (n * 5 + 2) / 6): 12 differences with the file's flags and the divs_nops row `func_L40_0042CE98 2`. (a) retail stores the bytes in the order sh 0x32, sb 0x30, sb 0x31, sb 0x20 with 1 in $v0 and 0xFF in $v1/$a0: source order 0x31,0x30,0x32 gives the registers but sb 0x31 first, order 0x30,0x31,0x32 gives the order but swaps the registers (14), sh first merges the HI/QI 0xFF constants (69); (b) the 3-iteration loop: retail counter $v0, &D9C0 $v1, &D9D0 $a0, ours counter $a0 (priority 1.0), &D9D0 $v0; swapped stores/declarations, struct rows, pointer loop, do-while and a count-down loop (32) did not change it */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_0042CE98 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern f32 func_L39_005B44C8(void);
extern s32 D_001DC210_sda;
__asm__(".extern D_001DC210_sda, 4");
extern s16 D_L40_002499C0[];
extern s16 D_L40_002499D0[];

u8 *func_L40_0042CE98(u128_t *pos, s32 a1, s32 a2, u128_t *vec, s32 a4, f32 f)
{
    u8 *o = func_003C24B0(0x1B3A, 0x80);
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
        *(s32 *)(v + 0x10) = (n * 5 + 2) / 6;
        *(f32 *)(v + 0x14) = 1.0f / (f32)((n * 5 + 2) / 6);
        *(s32 *)(v + 0x1C) = a4;
        *(f32 *)(o + 0xF0) = func_L39_005B44C8();
        *(f32 *)(o + 0xF4) = func_L39_005B44C8();
        *(f32 *)(o + 0xF8) = func_L39_005B44C8();
        *(f32 *)v = func_L39_005B44C8();
        *(f32 *)(v + 4) = func_L39_005B44C8();
        *(f32 *)(v + 8) = func_L39_005B44C8();
        *(s32 *)(o + 0xB8) = a1;
        *(f32 *)(v + 0xC) = f;
        for (i = 0; i < 3; i++) {
            D_L40_002499C0[i] = -1;
            D_L40_002499D0[i] = 0x18;
        }
        o[0x20] = 0;
    }
    return o;
}
/* localdecomp:end func_L40_0042CE98 */
