#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of PAL func_L06_00352CA0. */
/* localdecomp:start func_L06_00351FA0 */
extern void func_003886C0(void *, void *, void *, f32);
extern s32 func_L01_003F9498(void *, f32, s32, u8 *);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern s32 func_003CF790(void *, f32, s32, void *, void *);
extern void func_00388830(void *, void *, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00351FA0;
typedef struct {
    V_00351FA0 dir;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    u16 h1A;
    f32 f1C;
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00351FA0;
typedef struct { u8 pad[0x18]; u8 *target; } G_00351FA0;
extern void func_L06_00350930(s32, u8 *, void *, void *);
extern G_00351FA0 D_L06_001E8440;
void func_L06_00351FA0(u8 *a0, u8 *a1) {
    V_00351FA0 l;
    V_00351FA0 r;
    V_00351FA0 mid;
    V_00351FA0 p;
    D_00351FA0 d;
    G_00351FA0 *g;
    func_L06_00350930((s32)a0, a1, &l, &r);
    func_003886C0(&mid, &l, &r, 0.5f);
    p = mid;
    p.z = *(f32 *)(a0 + 0x18) + 0.3f;
    if (func_L01_003F9498(&p, 3.0f, 1, a0)) {
        g = &D_L06_001E8440;
        if (g->target != 0 && g->target != a0) {
            func_L01_00443628(&d, a0, 0x10001, a1 + 0x110, 1.0f);
            d.b18 = 2;
            d.h1A = *(u16 *)(a0 + 0xAA);
            vec_sub_ba(&d.dir, g->target + 0x10, a0 + 0x10);
            d.dir.z = 0.0f;
            func_00388830(&d.dir, &d.dir, 3.3333334922790527f);
            d.dir.w = 5627.925f;
            d.flags |= 1;
            func_003CF790(&p, 3.0f, 0, a0, &d);
        }
    }
}
/* localdecomp:end func_L06_00351FA0 */
