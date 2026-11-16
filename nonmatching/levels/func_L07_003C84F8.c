/* NTSC-U draft (Claude wave C2): C of func_L07_003C6B50, the NTSC-U twin of func_L07_003C84F8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 32 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L07_003C6B50", whose code is not the PAL one).
 * Worker's note: flags + 32 diff: needs -mvu0-use-vf0-vf2 (lqc2/vsub.xyz/sqc2; COMPILE ERROR without) which the PAL file src/levels/07_annihilation_nation/L07_003C7468.c flags lack (it has @ps2as); the body in the .near.c is right but the register assignment differs (retail: ...
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L07, @ps2as) */
/* localdecomp:start func_L07_003C6B50 */
extern f32 func_00388730(void *, void *);
extern f32 func_00389410(f32);
extern void func_00389018(void *, s32, f32);
extern void func_00388F50(void *, void *, void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L07_003C6B50(u8 *obj, void *target) {
    vu0_v4 d;
    vu0_v4 e;
    u8 *sub;

    vec_sub_ba(&d, obj + 0x10, target);
    sub = *(u8 **)(obj + 0x68);
    func_00389018(&e, 1, func_00389410(func_00388730(&d, obj + 0xC0) / 0.3f));
    func_00388F50(sub + 0x3D0, sub + 0x3D0, &e);
    func_L01_0044B5C8(obj, sub + 0x240, 6, 0.01f, 0.3f);
    func_L01_0044B5C8(obj, sub + 0x2C0, 3, 0.03f, 0.3f);
    func_L01_0044B5C8(obj, sub + 0x340, 4, 0.03f, 0.3f);
}
/* localdecomp:end func_L07_003C6B50 */
