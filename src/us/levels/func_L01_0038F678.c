#include "common.h"

typedef int u128_L01_0038F678 __attribute__((mode(TI)));

/* localdecomp:start func_L01_0038F678 */
extern void *func_L01_00435E70(s32, s32);

/* infecto_burst_spawn: spawns an effect moby (class 0x188B) at the given position, stores the
 * direction and a 30-frame duration in its data block, and returns it (or 0 if none was spawned). */
void *func_L01_0038F678(void *position, void *direction) {
    u8 *effect = func_L01_00435E70(0x188B, 0x80);
    if (effect != 0) {
        u8 *inner;
        s32 duration = 0x1E;
        u128_L01_0038F678 copied;
        effect[0x20] = 0;
        effect[0x30] = 0xFF;
        inner = *(u8 **)(effect + 0x68);
        *(u128_L01_0038F678 *)(effect + 0x10) = *(u128_L01_0038F678 *)position;
        copied = *(u128_L01_0038F678 *)direction;
        *(s32 *)(inner + 0x18) = 0x46;
        *(u128_L01_0038F678 *)inner = copied;
        *(s32 *)(inner + 0x10) = duration;
        *(s32 *)(inner + 0x14) = 0;
    }
    return effect;
}
/* localdecomp:end func_L01_0038F678 */
