#include "common.h"

/* NTSC-U counterpart of func_L39_005CA8B0 (src/levels/shared/L39_005CA8B0.c): 58 -> 70; 117 -> 140; 0.0349066 -> 0.0290888; 0.139626 -> 0.116355; 0.01 -> 0.00833333; 0.028 -> 0.0233333 */
/* localdecomp:start func_L39_005C84F8 */
/* func_L39_005C84F8: from asm (rac2 twin func_002BF728 not used); needs --as ps2as; 4 diff rows
   Phase 2 w3 w7; 384 bytes, 15 places (39..53); only the global-pointer lui register ($a2 vs $v0) and its schedule differ
   Left: reg alloc of D_L39_002969A0 load (retail lui $a2, lw $v0, lbu $v1) */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C7B98(s32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_003BE988(void *, s32);
extern f32 func_L39_005B25C8_005C84F8(void);
extern u8 *D_L39_002969A0 __attribute__((section(".data")));

u8 *func_L39_005C84F8(void *a0, f32 *a1, s32 a2, f32 f12, f32 f13) {
    u8 *p = func_003C7B98(0x22);
    u8 *q;
    if (p != 0) {
        *(s32 *)(p + 4) = a2;
        p[1] = 0;
        p[9] = 0x44;
        p[3] = 0x44;
        q = p + 0x20;
        *(f32 *)(q + 0xC) = func_L39_005B2510(0.75f, 1.25f) * f12;
        *(f32 *)(p + 0xC) = 5250.0f;
        p[8] = func_L39_005B24C8(-10, 10) - 0x80;
        p[2] = *D_L39_002969A0;
        *(s16 *)(p + 0xA) = func_L39_005B24C8(0x46, 0x8C);
        if (f13 == -1.0f)
            *(f32 *)(q + 0x10) = func_003BE988(a0, 0);
        else
            *(f32 *)(q + 0x10) = f13;
        *(f32 *)(q + 0x14) = func_L39_005B25C8_005C84F8();
        *(f32 *)(q + 0x18) = func_L39_005B2510(0.0290888231f, 0.116355292f);
        *(f32 *)(q + 0x1C) = func_L39_005B2510(0.00833333377f, 0.0233333334f);
        *(f32 *)(q + 0) = a1[0];
        *(f32 *)(q + 4) = a1[1];
        *(f32 *)(q + 8) = a1[2];
        *(u128_t *)(p + 0x10) = *(u128_t *)a0;
    }
    return p;
}
/* localdecomp:end func_L39_005C84F8 */
