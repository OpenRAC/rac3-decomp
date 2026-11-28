#include "common.h"
/* localdecomp:start func_L01_00342DB8 */
typedef int s128_00343658 __attribute__((mode(TI)));

extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_0037E2A8(void);
extern void func_0037E4B8(f32 *out, f32 length, f32 a, f32 b);
extern f32 func_L01_00440918(f32, f32);
/* The floats are declared among the ints (the registers are the same under EABI: ints and floats
   count separately) because gcc emits the argument moves in prototype order, and retail sets $f13
   before $a2 and $f14 before $t2. */
extern u8 *func_L01_00467DA8(f32 *pos, s32 life, f32 size_end, f32 size, s32 colour, s32 roll,
                             s32 spin, f32 *velocity, f32 z, s32 n);

/* shield_zap_sparkles: the Shield Charger's zap at the point on the shell toward the enemy:
   eight pairs of 0x35 sparkles, each pair from one f = rand(1, 6): half f shrinking to 0.1 f
   in the shield's colour, and 0.4 f to 0.04 f in grey 0x7F, spinning opposite ways; both
   jittered +-0.1, 0.5-6 u/s any way, life 20 frames, render byte +9 0x74. */
void func_L01_00342DB8(s128_00343658 *at, s32 colour)
{
    f32 velocity[4];
    f32 pos[4];
    s32 i;
    s32 spin;
    f32 f;
    f32 speed;
    f32 a;
    u8 *sparkle;

    for (i = 0; i < 8; i++) {
        f = func_0037E250(1.0f, 6.0f);
        spin = func_0037E1D8(2);
        /* 1 or -1 */
        if (spin == 0) {
            spin--;
        }
        speed = func_0037E250(0.5f, 6.0f) * 0.0166666675f;
        a = func_0037E2A8();
        func_0037E4B8(velocity, speed, a, func_0037E2A8());
        *(s128_00343658 *)pos = *at;
        pos[0] += func_L01_00440918(0.0f, 0.1f);
        pos[1] += func_L01_00440918(0.0f, 0.1f);
        pos[2] += func_L01_00440918(0.0f, 0.1f);
        sparkle = func_L01_00467DA8(pos, 20, f * 0.1f, f, colour | 0x7F000000, 0, spin, velocity, 0.0f, 1);
        if (sparkle != 0) {
            sparkle[9] = 0x74;
        }
        sparkle = func_L01_00467DA8(pos, 20, f * 0.04f, f * 0.4f, 0x7F7F7F7F, 1, -spin, velocity, 0.0f, 1);
        if (sparkle != 0) {
            sparkle[9] = 0x74;
        }
    }
}
/* localdecomp:end func_L01_00342DB8 */
