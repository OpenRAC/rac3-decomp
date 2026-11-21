/* functional: high. Same operations in the same order; retail's VU0 source-load order differs by 2 words (scheduling only). Constants/gp globals/callees checked against PAL asm. */
#include "common.h"
/* localdecomp:start func_L01_003C5DF0 */
#include "vu0.h"
__asm__(".extern D_L01_001DEDD0, 8");
extern u8 D_L01_001DEDD0[8];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
void func_L01_003C5DF0(s32 arg0, s32 unused, s32 flag) {
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_L01_005003D0(s32, s32);
    vu0_v4 pos, rot;
    u8 *m = (u8 *)arg0;
    u8 *hero;
    f32 angle;
    func_0038D000(&pos, D_L01_001DEDD0, m + 0xC0);
    angle = *(f32 *)(m + 0xF8);
    vec_add_ba(&pos, &pos, m + 0x10);
    qzero(&rot);
    rot.z = func_0038DAB8(angle, 3.1415927f);
    *(vu0_q *)D_001A4C60 = *(vu0_q *)&pos;
    hero = D_001A4C60 - 0x80;
    *(vu0_q *)(*(u8 **)(hero + 0x25C0) + 0x10) = *(vu0_q *)&pos;
    *(vu0_q *)(hero + 0x90) = *(vu0_q *)&rot;
    if (flag) {
        if (*(s32 *)(hero + 0x25C4) != 0x31) func_L01_005003D0(0x31, 1);
    } else {
        if (*(s32 *)(hero + 0x25C4) != 0x74) func_L01_005003D0(0x74, 1);
    }
}
/* localdecomp:end func_L01_003C5DF0 */
