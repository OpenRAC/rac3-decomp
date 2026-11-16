/* NTSC-U draft (Claude wave K): C of func_L13_003AD5D0, the NTSC-U twin of func_L13_003AF3B8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 38 words differ on NTSC-U with "-mvu0-use-vf0-vf2 @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L13_003AD5D0", whose code is not the PAL one).
 * Worker's note: 38 aligned diff (138 vs 139 words); retail keeps pos pointer sp+0x30 in s2 (6 saved regs, ours 5), vsub/vadd read 0x30(sp) directly; pointer-local variants rematerialize or move s2 early (46-50)
 */
#include "common.h"

/* NTSC-U counterpart of func_L13_003B0D70-class aim helper (src/levels/shared/L13_003ABD48.c) */
#include "vu0.h"

/* localdecomp:start func_L13_003AD5D0 */
extern f32 D_001DE7F8_sda;
__asm__(".extern D_001DE7F8_sda, 4");
extern f32 D_001DE7F4_sda;
__asm__(".extern D_001DE7F4_sda, 4");
extern s32 D_001D545C_sda_003AD5D0;
__asm__(".extern D_001D545C_sda_003AD5D0, 4");
extern void func_003BD9A0(void *, s32, void *);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_L13_003B2720(void *, void *, void *, s32, s32);

void func_L13_003AD5D0(u8 *self) {
    f32 a[12];
    f32 d[4];
    f32 e[4];
    u8 *t;
    f32 pitch;
    f32 yaw;
    f32 base;
    f32 lim;
    s32 flags;
    f32 *b;

    t = *(u8 **)(self + 0x68);
    func_003BD9A0(self, 2, a);
    b = a + 12;
    vec_sub_ba(d, t + 0x130, b);
    base = func_00388A28(func_003887A0(a), a[2]);
    pitch = func_003893C8(func_00388A28(func_003887A0(d), d[2]), base);
    lim = D_001DE7F8_sda * 0.017453292f;
    if (lim < pitch) pitch = lim;
    else if (pitch < -lim) pitch = -lim;
    pitch = func_00389380(pitch, base);
    base = func_00388A28(a[0], a[1]);
    yaw = func_003893C8(func_00388A28(d[0], d[1]), base);
    lim = D_001DE7F8_sda * 0.017453292f;
    if (lim < yaw) yaw = lim;
    else if (yaw < -lim) yaw = -lim;
    yaw = func_00389380(yaw, base);
    func_0037E4B8(d, D_001DE7F4_sda * 0.0166666675f, yaw, pitch);
    flags = 0x08000001;
    if (t[0x5F]) flags = 0x08010001;
    func_00388830(e, a, -1.0f);
    vec_add_ab(e, e, b);
    if (func_003CE740(e, b, 0x12, self, 0) == 0 || D_001D545C_sda_003AD5D0 != 0x10) {
        func_L13_003B2720(self, b, d, t[0x44], flags);
    }
}
/* localdecomp:end func_L13_003AD5D0 */
