#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_003002A8 */

typedef struct {
    s128 v;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    s32 f1C;
    f32 f20;
    s32 f24;
    f32 f28;
    f32 f2C;
} State_L01_00300250;

typedef struct {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    f32 z;
    u8 pad1C[4];
    u8 b20;
    u8 pad21[0x0B];
    f32 f2C;
    u8 b30;
    u8 b31;
    s16 h32;
    u16 h34;
    u8 pad36[0x68 - 0x36];
    State_L01_00300250 *f68;
    u8 pad6C[0xBC - 0x6C];
    u8 bBC;
    u8 padBD[0xD0 - 0xBD];
    f32 vD0[4];
    u8 padE0[0xF0 - 0xE0];
    f32 fF0;
    f32 fF4;
    f32 fF8;
} Obj_L01_00300250;

extern s32 D_L01_001DC458;
extern f32 D_L01_001DC454;
__asm__(".extern D_L01_001DC458, 4");
__asm__(".extern D_L01_001DC454, 4");

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382498(s32, s32);
extern s32 func_0013D3E0(void);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C7C38(u8 *);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);

Obj_L01_00300250 *func_L01_003002A8(s32 unused, s128 *pos, f32 *vel) {
    Obj_L01_00300250 *obj;
    State_L01_00300250 *st;

    obj = (Obj_L01_00300250 *)func_003C24B0(0x1AC, 0x80);
    if (obj != 0) {
        obj->b30 = 0x40;
        obj->h32 = 0x20;
        obj->b31 = 1;
        obj->h34 |= 0x1000;
        obj->b20 = 0;
        obj->bBC = 0;
        *(s128 *)&obj->x = *pos;
        st = obj->f68;
        obj->z += func_003824E0(0.2f, 0.7f);
        obj->x += vel[0] * 3.0f;
        obj->y += vel[1] * 3.0f;
        *(s128 *)st = *(s128 *)vel;
        obj->fF4 = func_L01_00443A18(0.17453292f, 0.523598790f);
        obj->fF0 = func_003824E0(0.17453292f, 0.785398185f);
        st->f2C = func_003824E0(200.0f, 370.0f) * 0.0174532924f * 0.020000001f;
        st->f24 = -1;
        if (func_0013D3E0() & 1) {
            st->f24 = 1;
            obj->fF4 = -obj->fF4;
        }
        obj->fF8 = func_00382538();
        st->f28 = -(func_003824E0(200.0f, 550.0f) * 0.0174532924f * 0.020000001f);
        st->f10 = func_00382538();
        st->f14 = func_00382538();
        st->f1C = func_00382498((s32)((f32)D_L01_001DC458 * 0.7f), (s32)((f32)D_L01_001DC458 * 1.2f));
        st->f1C = (st->f1C * 5 + 2) / 6;
        obj->f2C = obj->f2C * D_L01_001DC454;
        st->f20 = func_003824E0(-1.2f, -0.4f) * 0.020000001f;
        func_0038CE20(obj->vD0, obj->vD0, 0.5f);
        func_003C7C38((u8 *)obj);
        func_L01_0043B9E8((u8 *)obj, 0x90, 0x90, 0);
    }
    return obj;
}
/* localdecomp:end func_L01_003002A8 */

/* localdecomp:start func_L01_00300550 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00300550;
typedef struct {
    f32 x0;
    f32 x4;
    f32 f8;
    u8 padC[0x1C - 0xC];
    s32 w1C;
    f32 f20;
    s32 w24;
    f32 f28;
    f32 f2C;
} G_00300550;
typedef struct {
    u8 pad0[0x10];
    V_00300550 pos;
    u8 pad20[3];
    u8 b23;
    u8 pad24[0x31 - 0x24];
    u8 b31;
    u8 pad32[0x68 - 0x32];
    G_00300550 *x68;
    u8 pad6C[0xF0 - 0x6C];
    f32 fF0;
    u8 padF4[4];
    f32 fF8;
} O_00300550;

extern f32 D_L01_001DC45C;
__asm__(".extern D_L01_001DC45C, 4");
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0040E020(void *);
extern void func_003C2880(u8 *);

void func_L01_00300550(O_00300550 *o) {
    G_00300550 *g = o->x68;
    f32 t;

    vec_add_ab(&o->pos, &o->pos, g);
    g->f8 = g->f8 - 0.004f;
    g->x0 = g->x0 * D_L01_001DC45C;
    g->x4 = g->x4 * D_L01_001DC45C;
    if (g->f8 < g->f20) {
        g->f8 = g->f20;
    }
    o->fF8 = func_0038DAB8(o->fF8, g->f28);
    t = func_0038DAB8(o->fF0, g->f2C * (f32)g->w24);
    o->fF0 = t;
    if (0.7853982f < fabs_asm(t)) {
        g->w24 = -g->w24;
    }
    if (func_0038CAD0(&g->w1C) != 0 || o->b31 == 0) {
        func_003C2880((u8 *)o);
        return;
    }
    if (g->w1C < 25 && func_L01_0040E020(&o->b23) != 0) {
        func_003C2880((u8 *)o);
    }
}
/* localdecomp:end func_L01_00300550 */
