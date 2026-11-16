/* NTSC-U draft (Claude wave K): C of func_L40_003D6410, the NTSC-U twin of func_L40_003D65A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L40_003D6410", whose code is not the PAL one).
 * Worker's note: 2 words off: only slti/bnel vs retail slti(v1)/bnez with the lw in the delay slot; NEEDS divs row 'func_L40_003D6410 0 2'; fabs_asm, int ff=0xFF local fixes the prologue, D_L40_002412AC read as s32 (head) and u8 (a)
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_003D6410 */
typedef struct V_003D6410 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003D6410;

extern f32 D_001DB27C_sda;
extern f32 D_001DB278_sda;
extern s32 D_001DB284_sda;
extern s32 D_001DB280_sda;
__asm__(".extern D_001DB27C_sda, 4");
__asm__(".extern D_001DB278_sda, 4");
__asm__(".extern D_001DB284_sda, 4");
__asm__(".extern D_001DB280_sda, 4");
extern s32 D_L40_002412AC;

extern void func_003886E8(void *, void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L39_005CB8E0(void *, s32, s32, s32, s32, s32, s32, s32, f32);

void func_L40_003D6410(u8 *o) {
    V_003D6410 v;
    u8 *p;
    s32 i;
    s32 j;
    s32 col;
    s32 a;
    s32 ff;

    ff = 0xFF;
    p = *(u8 **)(o + 0x68);
    func_003886E8(&v, o, 0.0009765625f);
    j = 0;
    for (i = 0; i < 4; i++) {
        col = func_003894A0(*(s32 *)(p + 0x28), *(s32 *)(p + 0x2C), fabs_asm(0.5f - (f32)(ff - ((D_L40_002412AC + j) & 0xFF)) / 255.0f));
        j += 0x14;
        a = *(u8 *)&D_L40_002412AC;
        if ((i & 2) != 0) {
            a = a * 2;
        }
        if ((i & 1) != 0) {
            a = ff - a;
        }
        func_L39_005CB8E0(&v, col, a & 0xFF, D_001DB284_sda, D_001DB280_sda, 2, 0, 0, (D_001DB278_sda + (f32)i * D_001DB27C_sda) * (*(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24)));
    }
}
/* localdecomp:end func_L40_003D6410 */
