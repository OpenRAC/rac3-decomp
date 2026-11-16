/* NTSC-U draft (Claude wave C2): C of func_L18_00352530, the NTSC-U twin of func_L18_00353138, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L18_00352530", whose code is not the PAL one).
 * Worker's note: flags: working flags '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (PAL file: '-O2 -G8 -fopt-stack -mno-check-zero-division'). needs -mvu0-use-vf0-vf2 (vec_add_ab; COMPILE ERROR without it) and @ps2as (float constants); with both: 9 ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L18_00352530 */
typedef int u128_t __attribute__((mode(TI)));

extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_003886E8(f32 *, u8 *);
extern void func_L01_0044B920(u8 *, u8 *, u8 *, f32, f32, f32);
extern void func_L18_0045DD38(u8 *, u8 *, u8 *, f32, f32, f32);
extern u8 D_001A4BE0[];

static __inline__ s32 CurWord(s32 off) {
    return *(s32 *)(D_001A4BE0 + off);
}

void func_L18_00352530(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 t;
    f32 w;

    t = func_00389380(*(f32 *)(s + 0x358), 0.020362176f);
    *(f32 *)(s + 0x358) = t;
    w = func_00388978(t) * 0.02f;
    *(f32 *)(s + 0x35C) = w;
    if (*(s32 *)(s + 0x3BC) != 0) {
        *(f32 *)(a0 + 0x18) = *(f32 *)(s + 0x368) + w;
        *(u128_t *)v = *(u128_t *)(a0 + 0xF0);
        func_L01_0044B920(a0, s + 0x360, s + 0x364, 0.02617994f, 0.00814487f, 0.03723369f);
        if (CurWord(0x25C4) == 0x31 && CurWord(0x19E0) == (s32)a0) {
            *(f32 *)(a0 + 0xF0) = func_00389380(*(f32 *)(a0 + 0xF0), v[0]);
            *(f32 *)(a0 + 0xF4) = func_00389380(*(f32 *)(a0 + 0xF4), v[1]);
        }
    } else {
        func_003886E8(v, s + 0x3C0);
        vec_add_ab(a0 + 0x10, s + 0x420, v);
        func_L18_0045DD38(a0, s + 0x360, s + 0x364, 0.02617994f, 0.00814487f, 0.03723369f);
    }
}
/* localdecomp:end func_L18_00352530 */
