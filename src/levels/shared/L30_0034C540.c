#include "common.h"

/* localdecomp:start func_L30_0034C540 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0034C540;
typedef struct { f32 x, z; } V2_0034C540;
typedef struct {
    V4_0034C540 v[4];
    u8 p40[0x50 - 0x40];
    V2_0034C540 p[4];
} R_0034C540;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L30_0034C540(R_0034C540 *r, V4_0034C540 *c, s32 flat, f32 w, f32 h, f32 ang) {
    s32 i;
    f32 dx;
    f32 dz;

    if (flat) {
        for (i = 0; i < 4; i++) {
            if (i != 1 && i != 3) {
                dx = -w * 0.5f;
            } else {
                dx = w * 0.5f;
            }
            if (i != 2 && i != 3) {
                dz = -h * 0.5f;
            } else {
                dz = h * 0.5f;
            }
            r->p[i].x = c->x + dx * func_0038D098(ang) - dz * func_0038D0B0(ang);
            r->p[i].z = c->z + dx * func_0038D0B0(ang) + dz * func_0038D098(ang);
        }
    } else {
        for (i = 0; i < 4; i++) {
            *(u128_t *)&r->v[i] = *(u128_t *)c;
            if (i != 1 && i != 3) {
                dx = -w * 0.5f;
            } else {
                dx = w * 0.5f;
            }
            if (i != 2 && i != 3) {
                dz = -h * 0.5f;
            } else {
                dz = h * 0.5f;
            }
            r->v[i].x += dx * func_0038D098(ang) - dz * func_0038D0B0(ang);
            r->v[i].z += dx * func_0038D0B0(ang) + dz * func_0038D098(ang);
        }
    }
}
/* localdecomp:end func_L30_0034C540 */
