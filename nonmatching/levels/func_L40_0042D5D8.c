/* NTSC-U draft (Codex wave 3): C of func_L40_0042CBA0, the NTSC-U twin of func_L40_0042D5D8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 207 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L40_0042CBA0", whose code is not the PAL one).
 * Worker's note: 207 diff; grouped VU baseline preserved; permitted flags reject standard j helper: fixed or forbidden register 96 (vf17) spilled for VU_REGS (check02.log); no unlisted flags; best log func_L40_0042CBA0.check01.log
 */
#include "common.h"

/* NTSC-U particle effect; adapted from the nearby native effect. */
#include "vu0.h"

/* localdecomp:start func_L40_0042CBA0 */
extern vu0_v4 D_L40_0024A0C0[];
extern u8 D_L40_0029B0D8[];
extern f32 func_00388A28(f32, f32);
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern void func_003BFC18(void *, void *, s32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_L39_005B2568(f32, f32);
extern u8 *func_L01_004633E8(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_0037E1D8(s32);

void func_L40_0042CBA0(vu0_v4 *pos) {
    vu0_v4 d;
    vu0_v4 vel;
    vu0_v4 at;
    vu0_v4 pt;
    f32 heading;
    f32 speed;
    f32 size;
    f32 tilt;
    f32 yaw;
    s32 n;
    s32 i;
    u8 *q;
    u8 *data;

    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(d) : "m"(D_L40_0024A0C0[0]), "m"(*pos) : "vf1","vf2");
    heading = func_00388A28(d.x, d.y);
    for (i = 19; i >= 0; i--) {
        speed = func_L39_005B2510(0.2f, 3.0f);
        qzero(&at);
        at.z=-1.0f;
        func_003886E8(&vel, &at, -(speed * 0.016666668f));
        n = func_L39_005B2568(1.0f, 2.0f);
        size = func_L39_005B2510(0.3f, 0.75f) * 210000.0f;
        pt.x = pos->x + func_L39_005B2568(0.0f, 0.2f);
        pt.y = pos->y + func_L39_005B2568(0.0f, 0.2f);
        pt.z = pos->z + func_L39_005B2568(0.0f, 0.2f);
        q = func_L01_004633E8(&pt, 0.0f, 1.0f, 1.01f, size, n, &vel, 0x7F202020, 0);
        if (q != 0) {
            q[3] = 0x44;
            *(s16 *)(q + 0xA) = 0x5A;
            q[9] = 0x44;
            data = q + 0x20;
            *(f32 *)(data + 0x1C) = 5.0f;
            *(s32 *)(data + 4) = 3;
            data[0xA] = 0x30;
            data[0xB] = q[0xA];
        }
        speed = func_L39_005B2510(1.0f, 2.0f);
        tilt = func_L39_005B2510(0.0f, 1.3962634f);
        yaw = func_00389380(heading, func_L39_005B2568(0.0f, 1.3962634f));
        func_0037E4B8(&vel, speed * 0.016666668f, yaw, tilt);
        pt.x = pos->x + func_L39_005B2568(0.0f, 0.1f);
        pt.y = pos->y + func_L39_005B2568(0.0f, 0.1f);
        pt.z = pos->z + func_L39_005B2568(0.0f, 0.1f);
        q = func_L01_00466F98(&pt, &vel, 0x1E, 0x7F, 0x7FFF8040, n, func_L39_005B2510(0.25f, 0.7f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
        if(q) q[2]=(*(u8 **)(D_L40_0029B0D8+0x184))[6];
    }

}
/* localdecomp:end func_L40_0042CBA0 */
