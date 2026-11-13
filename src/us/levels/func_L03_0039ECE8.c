#include "common.h"

/* NTSC-U counterpart of func_L03_003A04D0 (src/levels/03_starship_phoenix/L03_0039E470.c) */
#include "vu0.h"
void func_00388B98(void *, float);
void func_003D41E0(void *, int, int, int, int, float);
void func_L03_0039ECE8(void *);
#include "vu0.h"

/* localdecomp:start func_L03_0039ECE8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003A04D0;
typedef struct { f32 pad[10]; f32 f28; f32 f2c; V4_003A04D0 v30; } S_003A04D0;

void func_L03_0039ECE8(void *arg0) {
    S_003A04D0 s;
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 t;
    func_00388B98(&s, 0.75f);
    s.v30 = *(V4_003A04D0 *)((u8 *)arg0 + 0x10);
    s.f28 = -0.85f;
    s.v30.z += 0.85f;
    t = *(f32 *)(p + 0x454) + 0.08f;
    *(f32 *)(p + 0x454) = t;
    if (1.0f < t) {
        *(f32 *)(p + 0x454) = t - 1.0f;
    }
    func_003D41E0(&s, 0x28,
                  ((s32)((p[0x45B] / 15.0f) * 255.0f) << 24) | 0xFF4040, 5, 1, *(f32 *)(p + 0x454));
}
/* localdecomp:end func_L03_0039ECE8 */
