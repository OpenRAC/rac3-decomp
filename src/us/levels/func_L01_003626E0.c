#include "common.h"

/* NTSC-U counterpart of func_L01_00363468 (src/levels/shared/L01_0035E450.c): 17 -> 20 */
extern u8 D_L01_001D66B0_003626E0[8];

/* localdecomp:start func_L01_003626E0 */
extern u8 D_L01_001D66B0_003626E0[8];
extern u8 *func_L01_00467DA8(u8 *position, s32 life, s32 colour, s32 roll_kind, s32 spin, void *velocity,
                             s32 delay, f32 size, f32 start_size, f32 unk);
extern u8 *func_L01_0046D570(u8 *position, s32 life, s32 colour, s32 a3, s32 spin, void *velocity, s32 t2,
                             s32 t3, s16 arg8, s32 arg9, f32 size, f32 start_size);

/* suck_take_in_sparkles: the Suck Cannon taking something in: at the muzzle four orange 0x35
 * sparkles (the Flux's muzzle sparkles) and three 0x5C bursts; D_L01_001D66B0_003626E0 is a zero vector. */
void func_L01_003626E0(u8 *moby)
{
    u8 *muzzle = *(u8 **)(moby + 0x68) + 0x10;

    func_L01_00467DA8(muzzle, 14, 0xBF204080, 2, 4, D_L01_001D66B0_003626E0, 1, 5.25f, 0.1f, 0.0f);
    func_L01_00467DA8(muzzle, 14, 0xBF2040A0, 2, -4, D_L01_001D66B0_003626E0, 1, 3.75f, 0.1f, 0.0f);
    func_L01_00467DA8(muzzle, 14, 0xC0FFFFFF, 2, 4, D_L01_001D66B0_003626E0, 1, 2.625f, 0.1f, 0.0f);
    func_L01_00467DA8(muzzle, 14, 0xB0FFFFFF, 2, -4, D_L01_001D66B0_003626E0, 1, 1.875f, 0.1f, 0.0f);
    func_L01_0046D570(muzzle, 20, 0x46787878, 2, 4, D_L01_001D66B0_003626E0, 0, 2, 6, 1, 1.08f, 0.84000003f);
    func_L01_0046D570(muzzle, 20, 0x46787878, 2, -2, D_L01_001D66B0_003626E0, 1, 2, 6, 1, 2.0400002f, 0.84000003f);
    func_L01_0046D570(muzzle, 20, 0x2D787878, 2, 2, D_L01_001D66B0_003626E0, 1, 2, 6, 1, 2.4f, 1.8000001f);
}
/* localdecomp:end func_L01_003626E0 */
