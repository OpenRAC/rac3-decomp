/* func_L40_0040CD80: near miss, 7 diff at level 40. 376 bytes, 14 levels (40-53),
   src/levels/shared/L40_0040A4D0.c (flags -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
   -mno-check-zero-division @ps2as). Written from asm (2026-11-11). The Ranger dies: debris from the
   legs and the torso (func_L01_00451FE0, the call Veldin's func_L01_003B1DC0 makes), the torso
   destroyed (func_003C2880), state 37 (dead), collision off.

   Every instruction is retail's; only the argument moves before the second debris call are in
   another order: retail puts the float copies (mov.s $f15, $f13 and mov.s $f17, $f16, cse's reuse
   of the first argument registers) before the int arguments $a3 .. $t3, ours after them.
   Tried: the float block of func_L01_00451FE0's prototype at each of the 11 places among the ints
   (7 or 8 diff), the float constants as named locals (7), both calls through a static inline
   helper (84: the constants are no longer shared). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_0040CD80 */
extern u8 D_L40_00242930[] __attribute__((section(".sdata")));
extern void func_L39_005F3488(s32 a0, s32 a1, u8 *m, s32 cls);
extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_003C2880(u8 *m);
extern void func_L01_004450F0(u8 *m, s32 state, s32 a2);
extern void func_L39_005F2FF8(u8 *m, s32 a1);

/* The Ranger dies: debris from legs and torso, the torso destroyed, state 37 (dead). */
void func_L40_0040CD80(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);

    func_L39_005F3488(3, 0, m, 0x109E);
    func_L01_00451FE0(m, 0xF, D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_L01_00451FE0(*(u8 **)(v + 0x270), 0xF, D_L40_00242930, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
    func_003C2880(*(u8 **)(v + 0x270));
    *(u8 **)(v + 0x270) = 0;
    func_L01_004450F0(m, 0x25, -1);
    *(s32 *)(m + 0x98) = 0;
    *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
    func_L39_005F2FF8(m, 1);
}
/* localdecomp:end func_L40_0040CD80 */
