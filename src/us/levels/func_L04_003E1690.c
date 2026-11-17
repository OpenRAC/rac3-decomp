#include "common.h"

/* localdecomp:start func_L04_003E1690 */
extern void func_L04_0044FEA8(f32, f32, f32 *);
extern s32 func_L04_0044FC98(s32, s32);
extern u8 *func_L04_00477908(u8 *, s32, s32, s32, s32, f32 *, s32, f32, f32, f32);

/* Spawns three particles (func_L04_00477908) at the object's position, each with a random small
 * velocity and random spin from -120 to 120, colour 0xFF4265FE and life 20. */
void func_L04_003E1690(u8 *object) {
    f32 vector[3];
    s32 index;
    s32 random;

    index = 2;
    do {
        func_L04_0044FEA8(0.0333333351f, 0.0666666701f, vector);
        index--;
        random = func_L04_0044FC98(-120, 120);
        func_L04_00477908(object + 0x10, 20, 0xFF4265FE, 0, random, vector,
                           0, 1.0f, 0.1f, 0.0f);
    } while (index >= 0);
}
/* localdecomp:end func_L04_003E1690 */
