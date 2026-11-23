#include "common.h"

/* NTSC-U counterpart of func_L40_003D65A8 (src/levels/shared/L40_003D6248.c) */
#include "vu0.h"
extern void func_L40_003D6410(u8 *);

/* localdecomp:start func_L40_003D6410 */
/* The code of func_L39_005614B0 with the two colours read from the moby's vars (+0x28, +0x2C)
 * instead of constants. As there: fabs_asm keeps abs.s out of the jal delay slot, the callee
 * returns s32 (unused), and the $gp floats carry .extern size hints. */
#include "vu0.h"
extern u32 D_L40_002412AC;
extern f32 D_L40_00246B08;
__asm__(".extern D_L40_00246B08, 4");
extern f32 D_L40_00246B0C;
__asm__(".extern D_L40_00246B0C, 4");
extern s32 D_L40_00246B10;
__asm__(".extern D_L40_00246B10, 4");
extern s32 D_L40_00246B14;
__asm__(".extern D_L40_00246B14, 4");
extern void func_003886E8(f32 *, f32 *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L39_005CB8E0(f32 *, s32, u8, s32, s32, s32, s32, s32, f32);

void func_L40_003D6410(u8 *a0) {
    f32 v[4];
    s32 i;
    s32 t;
    s32 c;
    s32 b;
    u8 *st = *(u8 **)(a0 + 0x68);

    func_003886E8(v, (f32 *)a0, 0.0009765625f);
    for (i = 0; i < 4; i++) {
        t = (D_L40_002412AC + i * 20) & 0xFF;
        c = func_003894A0(*(s32 *)(st + 0x28), *(s32 *)(st + 0x2C), fabs_asm(0.5f - (f32)(255 - t) / 255.0f));
        b = *(u8 *)&D_L40_002412AC;
        if (i & 2) {
            b = b * 2;
        }
        if (i & 1) {
            b = 255 - b;
        }
        func_L39_005CB8E0(v, c, b, D_L40_00246B14, D_L40_00246B10, 2, 0, 0,
                          (D_L40_00246B08 + (f32)i * D_L40_00246B0C) * (*(f32 *)(a0 + 0x2C) / ((f32 *)*(u8 **)(a0 + 0x24))[9]));
    }
}
/* localdecomp:end func_L40_003D6410 */
