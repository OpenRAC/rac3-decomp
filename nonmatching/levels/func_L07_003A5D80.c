/* NTSC-U draft (Claude wave C2): C of func_L07_003A45C0, the NTSC-U twin of func_L07_003A5D80, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division -fno-sched-interblock @ps2as") (NTSC-U twin "func_L07_003A45C0", whose code is not the PAL one).
 * Worker's note: flags: working flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (PAL file: '-O2 -G8 -fopt-stack -mno-check-zero-division'). MATCH only with -mvu0-use-vf0-vf2 and @ps2as (vec_add_ba needs the VU0 flag, float constants are ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003A45C0 */
extern void func_00388830(f32 *, u8 *, f32);
extern void func_L01_00457440(u8 *, f32 *);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(u8 *, u8 *, s32, f32, f32, f32, f32);
extern f32 func_00388800(u8 *, u8 *);
extern void func_L07_00333678(s32, f32, u8 *, u8 *, u8 *);

void func_L07_003A45C0(u8 *a0, u8 a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u8 *rot;
    u8 *pos;
    f32 v[4];
    f32 k;
    f32 ang;

    k = -1.0f;
    if (a1 == 0) {
        k = 1.0f;
    }
    pos = a0 + 0x10;
    rot = a0 + 0xF8;
    func_00388830(v, a0 + 0xD0, k * 50.0f * 0.033333335f);
    vec_add_ba(v, pos, v);
    func_L01_00457440(a0, v);
    ang = func_00388A28(*(f32 *)(s + 0x130) - *(f32 *)(a0 + 0x10), *(f32 *)(s + 0x134) - *(f32 *)(a0 + 0x14));
    func_L01_00445758(rot, s + 0x204, 0, ang, *(f32 *)(s + 0x164), *(f32 *)(s + 0x168), *(f32 *)(s + 0x16C));
    if ((*(u16 *)(a0 + 0x96) & 7) == 0) {
        if (a1 == 0) {
            func_L07_00333678(*(s32 *)(s + 0x270), func_00388800(pos, s + 0x130), a0, s + 0x4A0, 0);
        } else {
            func_L07_00333678(*(s32 *)(s + 0x270), func_00388800(pos, s + 0x130), a0, 0, s + 0x4A0);
        }
    }
    *(u16 *)(a0 + 0x96) += 1;
}
/* localdecomp:end func_L07_003A45C0 */
