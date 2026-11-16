#include "common.h"

/* localdecomp:start func_L39_005B2498 */
extern s32 func_0019D650(void);

/* Returns a random number below the given modulus (the game's random value modulo it). */
s32 func_L39_005B2498(s32 modulus) {
    return func_0019D650() % modulus;
}
/* localdecomp:end func_L39_005B2498 */
