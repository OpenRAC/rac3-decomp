#include "common.h"

/* localdecomp:start func_L20_003EE688 */
extern unsigned int D_00142C58[];
extern void func_003C2880(void *);

void func_L20_003EE688(int a0) {
    if (D_00142C58[0] & 0x2000000)
        func_003C2880((void *)a0);
}
/* localdecomp:end func_L20_003EE688 */

/* localdecomp:start func_L20_003EE6B8 */
extern unsigned int D_00142C58[];
extern void func_003C2880(void *);

void func_L20_003EE6B8(int a0) {
    if (D_00142C58[0] & 0x2000000)
        func_003C2880((void *)a0);
}
/* localdecomp:end func_L20_003EE6B8 */

INCLUDE_ASM("asm/levels", func_L20_003EE6E8);

INCLUDE_ASM("asm/levels", func_L20_003EEB40);

INCLUDE_ASM("asm/levels", func_L20_003EF550);

INCLUDE_ASM("asm/levels", func_L20_003EFFE0);

INCLUDE_ASM("asm/levels", func_L20_003F0088);

/* localdecomp:start func_L20_003F0418 */
#include "vu0.h"
typedef struct { f32 x, y; } P2_3F0418;
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    P2_3F0418 uv[4];
    u8 pad70[0x18];
    unsigned long tag;
} G_3F0418;
typedef struct { vu0_v4 pos; u8 pad10[0x1D0 - 0x10]; vu0_v4 v1D0; u8 pad1E0[0x460 - 0x1E0]; } C_3F0418;
extern C_3F0418 D_L20_001E2E80[];
extern s32 D_001D52F0;
extern vu0_v4 D_L20_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(long, long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L20_003F0418(vu0_v4 *a0, s32 a1, s32 flag, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16)
{
    G_3F0418 g;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0, vF0;
    s32 i, j, k, m;
    char buf[16];
    C_3F0418 *c;

    func_003D93B0(&g, a1, 1, 0x80);
    g.tag = 0x800000004AUL;
    g.col[3] = 0x80808080;
    g.col[2] = 0x80808080;
    g.col[1] = 0x80808080;
    g.col[0] = 0x80808080;
    g.uv[0].x = 0; g.uv[0].y = 0;
    g.uv[1].x = 0; g.uv[1].y = 1.0f;
    g.uv[2].x = 1.0f; g.uv[2].y = 0;
    g.uv[3].x = 1.0f; g.uv[3].y = 1.0f;
    vC0 = *a0;
    vec_sub_ab(&v90, &D_L20_001E2E80[D_001D52F0].pos, &vC0);
    func_0038CF68(&v90, &v90, 1.0f);
    c = &D_L20_001E2E80[D_001D52F0];
    func_0038CE90(&vA0, &v90, &c->v1D0);
    func_0038CF68(&vA0, &vA0, 1.0f);
    func_0038CE90(&vB0, &vA0, &v90);
    if (f14 != 0.0f) {
        *(vu0_q *)&vD0 = 0;
        vD0.x = f14;
        func_0038D308(&vE0, &vD0);
        func_0038D5F0(&v90, &v90, &vE0);
    }
    func_0038CE20(&vD0, &v90, f13);
    vec_add_ab(&vC0, &vC0, &vD0);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&g.pos[i], &D_L20_001D7C50[i], f12);
        func_0038D028(&g.pos[i], &g.pos[i], &v90);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&g, 0, 0);
    if (flag) {
        vE0 = g.pos[0];
        for (j = 1; j < 4; j++) {
            vec_add_ba(&vE0, &vE0, &g.pos[j]);
        }
        func_0038CE20(&vE0, &vE0, 0.25f);
        for (k = 0; k < 4; k++) {
            vec_sub_ba(&vF0, &g.pos[k], &vE0);
            func_0038CE20(&vF0, &vF0, 0.8f);
            vec_add_ab(&vF0, &vE0, &vF0);
            func_00389478(&vF0, &g.uv[k].x, &g.uv[k].y);
            if (0.0f < f16 && func_00382468(1) == 0) {
                f32 n = -f16;
                g.uv[k].x += func_003824E0(n, f16);
                g.uv[k].y += func_003824E0(n, f16);
            }
            if (g.uv[k].x > 1.0f) g.uv[k].x = 1.0f; else if (g.uv[k].x < 0.0f) g.uv[k].x = 0.0f;
            if (g.uv[k].y > 1.0f) g.uv[k].y = 1.0f; else if (g.uv[k].y < 0.0f) g.uv[k].y = 0.0f;
        }
    } else {
        for (m = 0; m < 4; m++) {
            func_00389478(&g.pos[m], &g.uv[m].x, &g.uv[m].y);
            if (func_00382468(1) == 0) {
                f32 n = -f16;
                g.uv[m].x += func_003824E0(n, f16);
                g.uv[m].y += func_003824E0(n, f16);
            }
            if (g.uv[m].x > 1.0f) g.uv[m].x = 1.0f; else if (g.uv[m].x < 0.0f) g.uv[m].x = 0.0f;
            if (g.uv[m].y > 1.0f) g.uv[m].y = 1.0f; else if (g.uv[m].y < 0.0f) g.uv[m].y = 0.0f;
        }
    }
    func_003D93B0(&g, -1, 1, 0x80);
    g.tag = 0x8000000054UL;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&g, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003F0418 */

/* localdecomp:start func_L20_003F0960 */
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L20_003F0960(u8 *p)
{
    u8 *a = *(u8 **)(p + 0x68);

    if (func_0038CAD0(a) != 0) {
        func_003C2880(p);
        return;
    }
    p[0x23] = a[0];
}
/* localdecomp:end func_L20_003F0960 */
