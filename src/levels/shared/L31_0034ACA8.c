#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034ACA8 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_0034ACA8;

typedef struct {
    u8 pad0[0x10];
    V4_0034ACA8 pos;
    u8 state;
    u8 pad21[0x34 - 0x21];
    u16 flags34;
    u8 pad36[0x68 - 0x36];
    void *vars;
} Obj_0034ACA8;

typedef struct {
    u8 pad0[0x10];
    f32 x, y, z;
    u8 pad1C[0x20 - 0x1C];
} Slot_0034ACA8;

typedef struct {
    u8 pad0[0x158];
    u8 *w158;
} Vars_0034ACA8;

typedef struct {
    u8 pad0[0x68];
    Vars_0034ACA8 *vars;
} Moby_0034ACA8;

__asm__(".extern D_L31_001DD2C8, 4");
__asm__(".extern D_L31_001DD2A8, 4");
extern s32 D_L31_001DD2C8[8] __attribute__((section(".sdata")));
extern s32 D_L31_001DD2A8[8] __attribute__((section(".sdata")));
extern Slot_0034ACA8 D_L31_001F01C0[];
extern void func_L01_00424D88(s32);

void func_L31_0034ACA8(Moby_0034ACA8 *m) {
    Obj_0034ACA8 **list = *(Obj_0034ACA8 ***)(m->vars->w158 + 0x68);
    s32 i;

    for (i = 0; list != 0 && i < 8; i++) {
        if (D_L31_001DD2C8[i] >= 0) {
            s32 h = D_L31_001DD2A8[D_L31_001DD2C8[i]];
            Obj_0034ACA8 *o = list[i];
            if (o == 0 || o->state == 0xFE || o->state == 0xFD || (o->flags34 & 2) || o->vars == 0) {
                if (h != -1) {
                    func_L01_00424D88(h);
                    D_L31_001DD2A8[D_L31_001DD2C8[i]] = -1;
                }
            } else {
                V4_0034ACA8 pos = o->pos;
                if (h >= 0) {
                    Slot_0034ACA8 *s = &D_L31_001F01C0[h];
                    s->x = pos.x;
                    s->y = pos.y;
                    s->z = pos.z;
                }
            }
        }
    }
}
/* localdecomp:end func_L31_0034ACA8 */

/* localdecomp:start func_L31_0034ADF0 */
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

__asm__(".extern D_L31_001DD308, 4");
__asm__(".extern D_L31_001DD30C, 4");
__asm__(".extern D_L31_001DD310, 4");
extern f32 D_L31_001DD308;
extern f32 D_L31_001DD30C;
extern f32 D_L31_001DD310;
__asm__(".extern D_L31_001DD2A8, 8");
extern s32 D_L31_001DD2A8[] __attribute__((section(".sdata")));
extern void *D_L31_001E12D0[] __attribute__((section(".sdata")));
extern u8 D_L31_001D66B0[8];
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void *func_L01_003F79D8(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern void func_L31_0034ABB8(Moby_0034ADF0 *, s32);

void func_L31_0034ADF0(Moby_0034ADF0 *m, V4_0034ADF0 *base, s32 idx) {
    Vars_0034ADF0 *v = m->vars;
    void **slots = v->owner->vars;
    V4_0034ADF0 vel;
    V4_0034ADF0 off;
    V4_0034ADF0 pos;
    s32 type;
    void *r;

    func_00382580(&vel, D_L31_001DD308 * 0.6f * 0.0200000014f, D_L31_001DD308 * 0.0200000014f);
    func_0038CE20(&off, &m->xC0, -(D_L31_001DD30C * 0.0200000014f));
    vec_add_ab(&vel, &vel, &off);
    vel.z += func_003824E0(D_L31_001DD310 * 0.5f, D_L31_001DD310) * 0.0200000014f;
    vel.y = func_003824E0(-1.0f, 1.0f) * 0.0200000014f;
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
    r = func_L01_003F79D8(m, 2, 0x165E, type, &pos, D_L31_001D66B0, &vel, 0xFF, 30.0f, 15.0f, 0xB4, 0, 0x80);
    D_L31_001E12D0[idx] = r;
    if (!(idx & 1)) {
        if (D_L31_001DD2A8[v->x15C] == -1) {
            void **e = slots + idx;

            *e = r;
            func_L31_0034ABB8(m, idx);
        }
    }
}
/* localdecomp:end func_L31_0034ADF0 */

INCLUDE_ASM("asm/levels", func_L31_0034AFD8);
