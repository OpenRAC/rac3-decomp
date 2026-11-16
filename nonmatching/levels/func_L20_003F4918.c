/* PAL near miss (Codex wave 7): near miss: 75 words differ with the file's flags.
 * Worker's note: 75 instruction differences in build/codex/w373/func_L20_003F4918.02.log; PAL constants decoded, complete behavior reconstructed; float register allocation and scheduling remain. Fixed flags, approved fabs_asm helper; no all-place/type-contract claim.
 */
#include "common.h"
/* localdecomp:start func_L20_003F4918 */
#include "vu0.h"
extern u8 *D_L20_002203DC;
void func_L20_003F4918(void *pos) {
    extern void func_L01_00443B88(void *, f32, f32);
    vu0_v4 velocity;
    f32 scale;
    u32 color;
    u8 *p;
    func_L01_00443B88(&velocity, 0.020000001415610313f, 0.05000000447034836f);
    velocity.z = fabs_asm(velocity.z);
    velocity.z += func_003824E0(7.0f, 10.5f) * 0.020000001415610313f;
    scale = func_003824E0(0.05999999865889549f, 0.2199999988079071f);
    func_00382468(3);
    color = func_00382468(3) ? 0x263438 : 0x273538;
    scale *= 210000.0f;
    p = func_L01_004713C8(pos, &velocity, (func_00382498(90, 150) * 5 + 2) / 6,
        color, -2, 127, 127, 0, scale, scale,
        0.006240000482648611f);
    if (p) {
        s32 i = func_00382468(3);
        p[2] = D_L20_002203DC[i + 10];
        p[3] = 0x44;
    }
}
/* localdecomp:end func_L20_003F4918 */
