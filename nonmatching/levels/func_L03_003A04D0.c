/* near miss (level 3, Starship Phoenix): 16 differences from one cause: retail has two nops before the div.s that the build does not emit (frontbin gets them from config/frontbin/divs_nops.txt, levels have no such table); every instruction otherwise matches in order, and the twin func_L03_0039F2C8 matched with the same body */
#include "common.h"

/* localdecomp:start func_L03_003A04D0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A04D0;
typedef struct { f32 pad[10]; f32 f28; f32 f2c; V4_003A04D0 v30; } S_003A04D0;
void func_0038D2D0(void *, f32);
void func_003D9740(void *, s32, f32, u32, s32, s32);

void func_L03_003A04D0(void *arg0) {
    S_003A04D0 s;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 t;
    func_0038D2D0(&s, 0.75f);
    s.v30 = *(V4_003A04D0 *)((u8 *)arg0 + 0x10);
    s.f28 = -0.85f;
    s.v30.z += 0.85f;
    t = *(f32 *)(p + 0x454) + 0.024f;
    *(f32 *)(p + 0x454) = t;
    if (1.0f < t) {
        *(f32 *)(p + 0x454) = t - 1.0f;
    }
    func_003D9740(&s, 0x28, *(f32 *)(p + 0x454),
                  ((s32)((p[0x45B] / 15.0f) * 255.0f) << 24) | 0xFF4040, 5, 1);
}
/* localdecomp:end func_L03_003A04D0 */
