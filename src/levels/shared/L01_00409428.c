#include "common.h"

/* localdecomp:start func_L01_00409428 */
#include "structs/moby.h"
typedef int u128_409428 __attribute__((mode(TI)));
/* moby_fade_move: fades a moby out by fade_out a frame until the timer runs out, then puts it at
   a position and rotation and fades it back in by fade_in a frame (up to 0x80) for `frames` more;
   *phase goes 0 (out), 1 (in), 2 (done), and a phase also ends when func_L01_00409070 (given the
   last two arguments) returns 0. Returns 0 once done (open-rac-engine docs/research/weapons.md:
   the Megaturret's move, alpha -2 a frame for 45 frames, then +3 up to 128). */
s32 func_L01_00409428(struct Moby *moby, s16 *timer, s16 *phase, u128_409428 *position, u128_409428 *rotation, s32 fade_out, s32 fade_in, s32 frames, s32 arg_a, s32 arg_b) {
    extern s32 func_0038CB00(s16 *);
    extern s32 func_L01_00409070(struct Moby *, s32, s32);
    if (moby == 0) return 0;
    if (*phase == 2) {
        moby->opacity = 0x80;
        return 0;
    }
    if (*phase == 0) {
        if (func_0038CB00(timer) == 0) {
            moby->opacity -= fade_out;
            if (func_L01_00409070(moby, arg_a, arg_b) == 0) *phase = 2;
        } else {
            *phase = 1;
            moby->opacity = 0;
            *timer = frames;
            *(u128_409428 *)&moby->position = *position;
            *(u128_409428 *)&moby->rotation = *rotation;
        }
    } else if (*phase == 1) {
        if (func_0038CB00(timer) == 0) {
            moby->opacity += fade_in;
            if (moby->opacity > 0x80) moby->opacity = 0x80;
            if (func_L01_00409070(moby, arg_a, arg_b) == 0) *phase = 2;
        } else {
            moby->opacity = 0x80;
            *phase = 2;
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00409428 */
