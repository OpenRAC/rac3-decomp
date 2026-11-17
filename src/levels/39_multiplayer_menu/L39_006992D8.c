#include "common.h"

/* localdecomp:start func_L39_006992D8 */
typedef struct S_006992D8_obj S_006992D8_obj;

typedef struct {
    char pad0[0x28];
    void (*m28)(S_006992D8_obj *, f32, f32);
    char pad2C[0x4];
    void (*m30)(S_006992D8_obj *, f32 *, f32 *);
    char pad34[0x4];
    void (*m38)(S_006992D8_obj *, f32, f32);
    char pad3C[0x9C];
    void (*mD8)(S_006992D8_obj *, f32, f32);
} S_006992D8_vt;

struct S_006992D8_obj {
    char pad[0x60];
    S_006992D8_vt *vt;
};

typedef struct {
    char pad0[0x110];
    S_006992D8_obj *f110[3];
    S_006992D8_obj *f11C;
    char pad120[0x170];
    s32 f290;
    char pad294[0x14];
    s32 f2A8;
    s32 f2AC;
    f32 f2B0;
    u8 f2B4;
    u8 f2B5;
} S_006992D8_self;

typedef struct {
    char pad0[0x284];
    s32 f284;
} S_006992D8_g;

extern S_006992D8_g *D_L39_00247914;
extern S_006992D8_g *D_001DC204_sda;
extern f32 D_001DC9AC_sda;
extern f32 D_001DC9B0_sda;
__asm__(".extern D_001DC204_sda, 4");
__asm__(".extern D_001DC9AC_sda, 4");
__asm__(".extern D_001DC9B0_sda, 4");
typedef struct {
    f32 f0;
    f32 f4;
} S_006992D8_lit;

extern S_006992D8_lit D_L39_002480D0;
extern s32 D_001A43E8[];
extern void func_L39_00689F00(void *, f32, f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_L39_0068B1E0(void *, s32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern s32 func_L39_0068AEF8(void *, s32);

s32 func_L39_006992D8(u8 *arg0, s32 arg1)
{
    S_006992D8_self *self = (S_006992D8_self *)arg0;
    S_006992D8_obj *o;
    f32 x;
    f32 y;
    s32 r;
    s32 ok;
    s32 sel;

    if (self->f2B0 != 0.6f) {
        o = self->f110[0];
        o->vt->m38(o, D_001DC9AC_sda, 0.65f);
        o = self->f110[0];
        o->vt->mD8(o, 0.0f, -0.064f);
        o = self->f11C;
        o->vt->m28(o, 0.5f, 0.65f);
    } else {
        o = self->f110[0];
        o->vt->m38(o, D_001DC9AC_sda, D_001DC9B0_sda);
        o = self->f110[0];
        o->vt->mD8(o, 0.0f, 0.0f);
        o = self->f11C;
        o->vt->m28(o, D_L39_002480D0.f4, 0.6125f);
    }
    if (self->f2B4 != 0) {
        o = self->f110[0];
        o->vt->m38(o, 0.8f, 0.8f);
        o = self->f110[0];
        o->vt->mD8(o, 0.0f, -0.064f);
        o = self->f11C;
        o->vt->m28(o, 0.5f, 0.7f);
    }
    if (self->f290 >= 0) {
        o = self->f110[self->f290];
        o->vt->m30(o, &x, &y);
        func_L39_00689F00(self, x, y, 0.2f, 0.05f, 0.0f, 0.0f, 0, 3, 3);
    }

    if (arg1 == 1 || arg1 == 2) {
        return 1;
    }
    if (arg1 == 3 || arg1 == 4) {
        r = func_L39_0068B1E0(self, -1);
        if (r != -1) {
            func_L39_00688340(3, 0, 0);
        }
        func_L39_0068B2F8(self, r, arg1);
        return 1;
    }
    if (func_L39_0068AEF8(self, arg1) != 0) {
        return 1;
    }
    if (self->f2B5 != 0 && D_001A43E8[0] != 2) {
        self->f2A8 = 0x40;
        D_L39_00247914->f284 = 0x2C;
        return 1;
    }
    if (arg1 == 7) {
        func_L39_00688340(4, 0, 0);
        ok = 0;
        sel = self->f290;
        if (sel == 1) {
            self->f2A8 = 1;
            ok = 1;
        } else if (sel == 2) {
            self->f2A8 = 2;
            ok = 1;
        } else if (sel == 3) {
            self->f2A8 = 4;
            ok = 1;
        } else if (sel == 4) {
            self->f2A8 = 8;
            ok = 1;
        } else if (sel == 5) {
            self->f2A8 = 0x10;
            ok = 1;
        } else if (sel == 6) {
            self->f2A8 = 0x20;
            ok = 1;
        } else if (D_001A43E8[0] != 2) {
            self->f2A8 = 0x40;
            ok = 1;
        }
        if (ok) {
            D_001DC204_sda->f284 = 0x2C;
            return 1;
        }
        return 0;
    }
    if (arg1 == 5 && self->f2AC >= 2) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_006992D8 */
