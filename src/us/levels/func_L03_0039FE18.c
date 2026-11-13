#include "common.h"

/* NTSC-U counterpart of func_L03_003A1600 (src/levels/03_starship_phoenix/L03_0039E470.c): 0.072 -> 0.06 */
/* localdecomp:start func_L03_0039FE18 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_003A1600;
typedef struct { char pad[0x2F0]; V4_003A1600 pos; char pad2[0x304 - 0x300]; float t; } S_003A1600;
extern int D_L03_001D9C20;
__asm__(".extern D_L03_001D9C20, 16");
int func_0038DBD8(float, int, int);
void func_L01_004C3500(void *, void *, void *, int, float);

void func_L03_0039FE18(void *arg0) {
    S_003A1600 *s = *(S_003A1600 **)((char *)arg0 + 0x68);
    V4_003A1600 v;
    int c[2];
    float t, f, g;
    v = s->pos;
    v.z += 0.15f;
    t = s->t + 0.0599999987f;
    s->t = t;
    if (2.0f < t) {
        s->t = t - 2.0f;
    }
    c[0] = 0x80802020;
    f = s->t;
    c[1] = func_0038DBD8(f < 1.0f ? f : 2.0f - f, 0x80A0A0A0, 0x80202080);
    func_L01_004C3500(&v, &D_L03_001D9C20, c, 1, 1.0f);
}
/* localdecomp:end func_L03_0039FE18 */
