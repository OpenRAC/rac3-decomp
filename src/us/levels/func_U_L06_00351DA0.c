#include "common.h"

/* localdecomp:start func_U_L06_00351DA0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00352CA0;
typedef struct {
    V_00352CA0 dir;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    u16 h1A;
    f32 f1C;
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00352CA0;
typedef struct { u8 pad[0x18]; u8 *target; } G_00352CA0;
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_L01_003F9498(void *, f32, s32, u8 *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443840(void *, void *);
extern G_00352CA0 D_L06_001E8440;
extern u8 *D_L06_001EC4C0[];

void func_U_L06_00351DA0(u8 *a0, u8 *a1) {
    V_00352CA0 pos;
    D_00352CA0 d;
    G_00352CA0 *g;
    u8 *c;
    f32 h;
    f32 dz;
    s32 n;
    s32 k;

    if (*(s32 *)(a1 + 0x360) == 0) {
        return;
    }
    h = func_003BE7F0(a0 + 0x10, 0, 0, 0.5f);
    dz = *(f32 *)(a0 + 0x18) - h;
    if (0.0f < dz && dz < 5.0f) {
        *(u128_t *)&pos = *(u128_t *)(a0 + 0x10);
        pos.z = h + 0.5f;
        if (func_L01_003F9498(&pos, 2.0f, 1, a0)) {
            g = &D_L06_001E8440;
            if (g->target != 0 && g->target != a0) {
                func_L01_00443628(&d, a0, 0x10001, a1 + 0x110, 5.0f);
                d.b18 = 5;
                d.h1A = *(u16 *)(a0 + 0xAA);
                vec_sub_ba(&d.dir, g->target + 0x10, a0 + 0x10);
                d.dir.z = 0.0f;
                func_00388830(&d.dir, &d.dir, 2.5000002f);
                d.dir.w = 5627.925f;
                d.flags |= 1;
                n = func_003CF790(&pos, 2.0f, 0, a0, 0);
                for (k = 0; k < n; k++) {
                    c = *(u8 **)(D_L06_001EC4C0[k] + 0x24);
                    if (c != 0 && c[0x46] == 0x16) {
                        d.f1C = 9999.9f;
                    } else {
                        d.f1C = 5.0f;
                    }
                    func_L01_00443840(D_L06_001EC4C0[k], &d);
                }
            }
        }
    }
}
/* localdecomp:end func_U_L06_00351DA0 */
