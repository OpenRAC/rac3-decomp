#include "common.h"

/* localdecomp:start func_L30_003413C8 */
extern void func_L30_00409890(void *, s32, void *);
extern void func_L30_003E0528(void *, s32, f32);
extern f32 func_L30_003E0978(f32, f32);

void func_L30_003413C8(u8 *object) {
    u8 *state = *(u8 **)(object + 0x68);
    if (state[0x251] == 0) {
        func_L30_00409890(object, 0, state + 0x250);
    }
    func_L30_003E0528(state + 0x260, 2, *(f32 *)(state + 0x29C));
    *(f32 *)(state + 0x29C) = func_L30_003E0978(*(f32 *)(state + 0x29C), 0.14544411f);
}
/* localdecomp:end func_L30_003413C8 */
