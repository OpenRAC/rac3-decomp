#include "common.h"

/* NTSC-U counterpart of func_L01_0034F0B0 (src/levels/shared/L01_00348620.c) */
/* localdecomp:start func_L01_0034E5E0 */
__asm__(".extern D_L01_001DD478, 4");
__asm__(".extern D_L01_001DD47C, 4");
__asm__(".extern D_L01_001DD480, 4");
__asm__(".extern D_L01_001DD484, 4");
__asm__(".extern D_L01_001DD488, 4");
extern s32 D_L01_001DD478;
extern s32 D_L01_001DD47C;
extern s32 D_L01_001DD480;
extern s32 D_L01_001DD484;
extern f32 D_L01_001DD488;
extern void func_003A3EF0(s32, unsigned long);
extern void func_L01_0034E688(u8 *bolt, s32 line, s32 core_alpha, s32 glow_alpha, s32 points);

/* lightning_bolt_draw: scrolls the ribbons' u, then draws each of the bolt's two lines as
   two added ribbons, a core and a glow in the bolt's colour. */
void func_L01_0034E5E0(u8 *bolt)
{
    u8 *vars = *(u8 **)(bolt + 0x68);
    f32 u;

    /* u scrolls 0.2 a frame (D_L01_001DD488), wrapping by 8 */
    u = *(f32 *)(vars + 0x14) - D_L01_001DD488;
    *(f32 *)(vars + 0x14) = u;
    if (u <= -8.0f) {
        *(f32 *)(vars + 0x14) = u + 8.0f;
    }
    func_003A3EF0(0x47, 0x51001);
    /* the core at alpha 0x80, the glow at 0x40; the first line of 10 points, the second of 20 */
    func_L01_0034E688(bolt, *(s32 *)vars, D_L01_001DD478, D_L01_001DD480, 10);
    func_L01_0034E688(bolt, *(s32 *)(vars + 4), D_L01_001DD47C, D_L01_001DD484, 20);
}
/* localdecomp:end func_L01_0034E5E0 */
