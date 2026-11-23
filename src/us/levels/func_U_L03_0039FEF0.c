#include "common.h"

extern void func_U_L03_003F9820(void *, f32);
extern void func_U_L03_003F75F8(void *, s32, s32, s32, s32, f32);

/* localdecomp:start func_U_L03_0039FEF0 */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003A16D8;
typedef struct { unsigned char pad0[0x308]; float t; unsigned char pad30C[6]; unsigned char a; } S_003A16D8;
typedef struct { float pad[10]; float f28; float pad2c; V4_003A16D8 pos; } L_003A16D8;

void func_U_L03_0039FEF0(void *arg0) {
    S_003A16D8 *s = *(S_003A16D8 **)((char *)arg0 + 0x68);
    L_003A16D8 l;
    float t;
    func_U_L03_003F9820(&l, 0.75f);
    l.pos = *(V4_003A16D8 *)((char *)arg0 + 0x10);
    l.f28 = -0.85f;
    l.pos.z += 0.85f;
    t = s->t + 0.08f;
    s->t = t;
    if (1.0f < t) {
        s->t = t - 1.0f;
    }
    func_U_L03_003F75F8(&l, 0x28, ((int)(s->a / 15.0f * 255.0f) << 24) | 0xFF4040, 5, 1, s->t);
}
/* localdecomp:end func_U_L03_0039FEF0 */
