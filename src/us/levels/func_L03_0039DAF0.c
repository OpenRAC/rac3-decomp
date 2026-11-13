#include "common.h"

/* NTSC-U counterpart of func_L03_0039F2C8 (src/levels/03_starship_phoenix/L03_0039E470.c): 0.096 -> 0.08 */
void func_L03_0039DAF0(void *);

/* localdecomp:start func_L03_0039DAF0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_0039F2C8;
typedef struct { unsigned char pad0[0x2F0]; V4_0039F2C8 pos; unsigned char pad300[4]; float t; unsigned char a; } S_0039F2C8;
typedef struct { float pad[10]; float f28; float pad2c; V4_0039F2C8 pos; } L_0039F2C8;
void func_0038D2D0(void *, float);
void func_003D9740(void *, int, int, int, int, float);

void func_L03_0039DAF0(void *arg0) {
    S_0039F2C8 *s = *(S_0039F2C8 **)((char *)arg0 + 0x68);
    L_0039F2C8 l;
    float t;
    t = s->t + 0.0799999982f;
    s->t = t;
    if (1.0f < t) {
        s->t = t - 1.0f;
    }
    func_0038D2D0(&l, 0.75f);
    l.pos = *(V4_0039F2C8 *)((char *)arg0 + 0x10);
    l.f28 = -0.85f;
    l.pos.z += 0.85f;
    func_003D9740(&l, 0x28, ((int)(s->a / 15.0f * 255.0f) << 24) | 0xFF4040, 5, 1, s->t);
}
/* localdecomp:end func_L03_0039DAF0 */
