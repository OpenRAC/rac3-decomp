/* near miss (level 3, Starship Phoenix): 15 differences from one cause: retail has two nops before the div.s, the build emits one (same div.s nop padding class as func_L03_003A04D0); the twin func_L03_0039F2C8 matched with the same shape */
#include "common.h"

/* localdecomp:start func_L03_003A16D8 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003A16D8;
typedef struct { unsigned char pad0[0x308]; float t; unsigned char pad30C[6]; unsigned char a; } S_003A16D8;
typedef struct { float pad[10]; float f28; float pad2c; V4_003A16D8 pos; } L_003A16D8;
void func_0038D2D0(void *, float);
void func_003D9740(void *, int, int, int, int, float);

void func_L03_003A16D8(void *arg0) {
    S_003A16D8 *s = *(S_003A16D8 **)((char *)arg0 + 0x68);
    L_003A16D8 l;
    float t;
    func_0038D2D0(&l, 0.75f);
    l.pos = *(V4_003A16D8 *)((char *)arg0 + 0x10);
    l.f28 = -0.85f;
    l.pos.z += 0.85f;
    t = s->t + 0.096f;
    s->t = t;
    if (1.0f < t) {
        s->t = t - 1.0f;
    }
    func_003D9740(&l, 0x28, ((int)(s->a / 15.0f * 255.0f) << 24) | 0xFF4040, 5, 1, s->t);
}
/* localdecomp:end func_L03_003A16D8 */
