/* NTSC-U draft (Claude wave C3): C of func_L22_003E83C8, the NTSC-U twin of func_L22_003EA3F0, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L22_003E83C8", whose code is not the PAL one).
 * Worker's note: flags: byte-exact (native MATCH, 424 B) only with an extra -mvu0-use-vf0-vf2 on the PAL counterpart file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as): its VU0 macros (include/vu0.h) do not compile without -mvu0-use-vf0-vf2. native written ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L22_003EA3F0 (src/levels/22_mylon/L22_003E9FF0.c) */
/* localdecomp:start func_L22_003E83C8 */
#include "vu0.h"
extern u8 D_001DF3D0_sda[8];
__asm__(".extern D_001DF3D0_sda, 8");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_00388BD0(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L22_003E83C8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    f32 v1[4];
    f32 v2[4];
    f32 v3[4];
    u8 *dir;
    f32 s;
    f32 a;
    f32 b;
    f32 c;

    if (obj[0x20] == 0) {
        *(u16 *)(obj + 0x96) = *(u16 *)(obj + 0x96) + 1;
        if (*(u16 *)(obj + 0x96) >= 0x15F) {
            func_L01_00441FB8(obj, 1, -1);
        } else {
            dir = obj + 0xC0;
            s = -0.051f;
            func_00388BD0(dir, obj + 0xF0);
            func_003888C8(v3, D_001DF3D0_sda, dir);
            vec_add_ba(v1, obj + 0x10, v3);
            func_00388830(v2, dir, s);
            v2[2] = v2[2] + s;
            func_003BF6A8(v1, 0.01f);
            func_003BF6A8(v2, 0.02f);
            func_003888C8(v2, v2, dir);
            a = func_0037E250(0.25f, 0.35f) * 2.1e+05f;
            b = func_0037E250(0.7f, 0.9f) * 2.1e+05f;
            c = func_0037E250(-0.007f, -0.01f);
            func_L01_0046C468(v1, v2, 0x14, 0x808080, 0x1E, 0x60, 0x20, 0, a, b, c);
        }
    }
}
/* localdecomp:end func_L22_003E83C8 */
