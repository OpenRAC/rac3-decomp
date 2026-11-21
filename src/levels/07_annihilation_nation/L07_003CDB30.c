#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
} S_003CD938;

/* declared by functions of L07_003CC2B0.c, which this file was cut from */
void func_L07_003CD2E8(void *, s32);
extern void func_L07_003CD2E8(void *, s32);
extern s32 func_00382498(s32, s32);

/* localdecomp:start func_L07_003CDB30 */
extern s32 func_00382498(s32, s32);
extern s32 func_L01_003F8470_003CDB30(void *, s32, s32, f32);
extern void func_L07_003CD2E8(void *, s32);

s32 func_L07_003CDB30(void *arg0) {
    u8 used = 0;
    s32 count;
    s32 slot;
    s32 i;
    s32 kind;
    s32 dir;
    f32 delay;

    for (count = 3; count > 0; count--) {
        slot = func_00382498(0, count - 1);
        for (i = 0; i < 3; i++) {
            if (slot < i) continue;
            slot += (used >> i) & 1;
        }
        if (slot == 2) {
            delay = 1.5f;
            kind = 0;
            dir = -1;
        } else {
            dir = slot == 1 ? -1 : 1;
            delay = 1.8f;
            kind = 1;
        }
        if (func_L01_003F8470_003CDB30(arg0, kind, dir, delay) != 0) {
            func_L07_003CD2E8(arg0, slot + 0x12);
            return 1;
        }
        used = (used | (1 << slot)) & 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L07_003CDB30 */
