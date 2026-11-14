#include "common.h"

/* NTSC-U counterpart of func_L31_0034ADF0 (src/levels/shared/L31_0034ACA8.c): 0.02 -> 0.0166667 */
extern u8 D_L31_001D66B0_0034A1C8[8];
extern s32 D_L31_001DD2E8[8] __attribute__((section(".sdata")));

/* localdecomp:start func_L31_0034A1C8 */
#include "vu0.h"
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034ADF0;
typedef struct {
    u8 pad0[0x68];
    void **vars;
} Owner_0034ADF0;
typedef struct {
    u8 pad0[0x158];
    Owner_0034ADF0 *owner;
    s32 x15C;
} Vars_0034ADF0;
typedef struct {
    u8 pad0[0x68];
    Vars_0034ADF0 *vars;
    u8 pad6C[0xC0 - 0x6C];
    f32 xC0;
} Moby_0034ADF0;

__asm__(".extern D_L31_001DD348, 4");
__asm__(".extern D_L31_001DD34C, 4");
__asm__(".extern D_L31_001DD350, 4");
extern f32 D_L31_001DD348;
extern f32 D_L31_001DD34C;
extern f32 D_L31_001DD350;
__asm__(".extern D_L31_001DD2E8, 8");
extern s32 D_L31_001DD2E8[] __attribute__((section(".sdata")));
extern void *D_L31_001E1350[] __attribute__((section(".sdata")));
extern u8 D_L31_001D66B0_0034A1C8[8];
extern void func_0037E2F0(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void *func_L01_003F5830(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L31_00349F90(Moby_0034ADF0 *, s32);

void func_L31_0034A1C8(Moby_0034ADF0 *m, V4_0034ADF0 *base, s32 idx) {
    Vars_0034ADF0 *v = m->vars;
    void **slots = v->owner->vars;
    V4_0034ADF0 vel;
    V4_0034ADF0 off;
    V4_0034ADF0 pos;
    s32 type;
    void *r;

    func_0037E2F0(&vel, D_L31_001DD348 * 0.6f * 0.0166666675f, D_L31_001DD348 * 0.0166666675f);
    func_003886E8(&off, &m->xC0, -(D_L31_001DD34C * 0.0166666675f));
    vec_add_ab(&vel, &vel, &off);
    vel.z += func_0037E250(D_L31_001DD350 * 0.5f, D_L31_001DD350) * 0.0166666675f;
    vel.y = func_0037E250(-1.0f, 1.0f) * 0.0166666675f;
    qzero(&pos);
    type = 1;
    if (idx == 0) {
        type = 13;
        pos.x = m->xC0 * 12.0f;
    } else if (idx == 13) {
        type = 0;
    } else {
        pos.x = m->xC0 * 2.0f;
    }
    vec_add_ba(&pos, &pos, base);
    r = func_L01_003F5830(m, 2, 0x165E, type, &pos, D_L31_001D66B0_0034A1C8, &vel, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
    D_L31_001E1350[idx] = r;
    if (!(idx & 1)) {
        if (D_L31_001DD2E8[v->x15C] == -1) {
            void **e = slots + idx;

            *e = r;
            func_L31_00349F90(m, idx);
        }
    }
}
/* localdecomp:end func_L31_0034A1C8 */
