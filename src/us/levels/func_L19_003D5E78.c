#include "common.h"

/* NTSC-U counterpart of func_L19_003D8280 (src/levels/19_thran_asteroid_belt/L19_003D7AE8.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_003886E8(void *, void *, f32);
typedef int u128_t_3D7F80 __attribute__((mode(TI)));
extern u8 D_L19_001D66F0_003D5E78;
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, u8 *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L01_0032FE90_003D5E78(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388758(void *, void *, void *);

/* localdecomp:start func_L19_003D5E78 */
typedef struct { u8 pad[0x24]; f32 scale; } A_3D8280;
typedef struct {
    u8 pad00[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    A_3D8280 *info;
    u8 pad28[4];
    f32 x2C;
    u8 pad30[4];
    u16 flags;
    u8 pad36[0x60];
    u16 timer;
    u8 pad98[0x28];
    vu0_v4 rot;
    u8 padD0[0x10];
    vu0_v4 axis;
    vu0_v4 aim;
} M_3D8280;
extern u8 D_001A30B0[];
extern vu0_v4 D_001A4C60;
__asm__(".extern D_L19_001DED40, 4");
__asm__(".extern D_L19_001DED44, 4");
__asm__(".extern D_L19_001DED48, 4");
__asm__(".extern D_L19_001DED4C, 4");
__asm__(".extern D_L19_001DED50, 4");
__asm__(".extern D_L19_001DED54, 4");
__asm__(".extern D_L19_001DED58, 4");
extern f32 D_L19_001DED40;
extern f32 D_L19_001DED44;
extern s32 D_L19_001DED48;
extern f32 D_L19_001DED4C;
extern f32 D_L19_001DED50;
extern f32 D_L19_001DED54;
extern f32 D_L19_001DED58;
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_0039FB08(s32);
extern void func_L01_0040C920(void *, void *);
extern s32 func_L02_003E4518(f32, f32, f32);

void func_L19_003D5E78(M_3D8280 *self) {
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 h;
    f32 ft, a, old, dist, t, r;
    s32 *tp;
    u8 *o;

    tp = (s32 *)((u8 *)self + 0x48);
    vec_sub_ab(&d, &D_001A4C60, &self->pos);
    switch (self->state) {
    case 0:
        *(s32 *)((u8 *)self + 0x48) = -1;
        self->flags |= 0x100;
        self->aim = self->rot;
        r = func_0037E250(-D_L19_001DED4C, D_L19_001DED4C);
        self->aim.w = r;
        if (r < 0.0f)
            func_L01_00441FB8(self, 2, -1);
        else
            func_L01_00441FB8(self, 1, -1);
        break;
    case 1:
        if (D_L19_001DED48 < self->timer) {
            f32 lim, fc;
            if (*tp == -1 || *(u8 **)((o = D_001A30B0 + (*tp << 7)) + 0xDC) != (void *)self || !o[0xD0])
                *tp = func_0039FE80(1, 4, self);
            fc = self->aim.w - D_L19_001DED50;
            lim = -D_L19_001DED4C;
            self->aim.w = fc;
            if (fc < lim) {
                if (*tp != -1) {
                    o = D_001A30B0 + (*tp << 7);
                    if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                        func_0039FB08(*tp);
                }
                *tp = -1;
                self->aim.w = -D_L19_001DED4C;
                func_L01_00441FB8(self, 2, -1);
            }
        }
        break;
    case 2:
        if (D_L19_001DED48 < self->timer) {
            f32 lim, fc;
            if (*tp == -1 || *(u8 **)((o = D_001A30B0 + (*tp << 7)) + 0xDC) != (void *)self || !o[0xD0])
                *tp = func_0039FE80(1, 4, self);
            lim = D_L19_001DED4C;
            fc = self->aim.w + D_L19_001DED50;
            self->aim.w = fc;
            if (lim < fc) {
                if (*tp != -1) {
                    o = D_001A30B0 + (*tp << 7);
                    if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                        func_0039FB08(*tp);
                }
                *tp = -1;
                self->aim.w = D_L19_001DED4C;
                func_L01_00441FB8(self, 1, -1);
            }
        }
        break;
    case 3:
        if (D_L19_001DED48 < self->timer) {
            g = self->axis;
            e = self->aim;
            old = self->aim.w;
            func_00388758(&f, &g, &e);
            func_L01_0040C920(&e, &e);
            func_003888C8(&h, &d, &e);
            h.z = 0.0f;
            func_00388830(&h, &h, 1.0f);
            a = 0.0f;
            if (h.x < a) {
                if (h.y < a)
                    a = -D_L19_001DED4C;
                else
                    a = D_L19_001DED4C;
            } else {
                ft = h.y * 180.0f / 3.1415927f;
                if (ft < -D_L19_001DED4C)
                    a = -D_L19_001DED4C;
                else if (D_L19_001DED4C < ft)
                    a = D_L19_001DED4C;
                else
                    a = ft;
            }
            if (a < self->aim.w) {
                self->aim.w -= D_L19_001DED50;
                if (self->aim.w < a)
                    self->aim.w = a;
            } else {
                self->aim.w += D_L19_001DED50;
                if (a < self->aim.w)
                    self->aim.w = a;
            }
            if (func_L02_003E4518(old, self->aim.w, 0.01f)) {
                if (*tp != -1) {
                    o = D_001A30B0 + (*tp << 7);
                    if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                        func_0039FB08(*tp);
                }
                *tp = -1;
            } else {
                if (*tp == -1 || *(u8 **)((o = D_001A30B0 + (*tp << 7)) + 0xDC) != (void *)self || !o[0xD0])
                    *tp = func_0039FE80(1, 4, self);
            }
        }
        break;
    default:
        break;
    }
    d.z = 0.0f;
    dist = func_00388730(&d, &d);
    if (self->state != 3) {
        if (dist < D_L19_001DED54) {
            func_L01_00441FB8(self, 3, -1);
            if (*tp != -1) {
                o = D_001A30B0 + (*tp << 7);
                if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                    func_0039FB08(*tp);
            }
            *tp = -1;
        }
    } else {
        if (D_L19_001DED58 < dist) {
            if (*tp != -1) {
                o = D_001A30B0 + (*tp << 7);
                if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                    func_0039FB08(*tp);
            }
            *tp = -1;
            if (0.0f < self->aim.w)
                func_L01_00441FB8(self, 1, -1);
            else
                func_L01_00441FB8(self, 2, -1);
        }
    }
    func_L19_003D5DC8((u8 *)self);
    if (self->timer <= 0xFFFE)
        self->timer = self->timer + 1;
    if (func_L01_00444358(self, -1, 0) != 0) {
        if (*tp != -1) {
            o = D_001A30B0 + (*tp << 7);
            if (*(u8 **)(o + 0xDC) == (void *)self && o[0xD0])
                func_0039FB08(*tp);
        }
        *tp = -1;
        func_0039FE80(0, 0, self);
        func_L01_0044ED60(self, 0x1F, &D_L19_001D66F0_003D5E78, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
        t = 1.0f / self->info->scale;
        *(u128_t_3D7F80 *)&e = 0;
        e.x = 0.1f;
        e.z = 0.4f;
        func_003886E8(&e, &e, t);
        *(u128_t_3D7F80 *)&f = 0;
        f.z = -0.116666675f;
        func_L02_003E0520(self, &e, 0.1f, &f, 0x14, 0, 0.15f, D_L19_001DED44 * t * self->x2C, 20.0f, 1.0f, 0);
        func_003886E8(&e, &e, self->x2C);
        func_003888C8(&e, &e, &self->rot);
        vec_add_ab(&e, &e, &self->pos);
        func_L01_0032FE90_003D5E78(&e, 0, 0, 0, 0, 2, 5, 0, D_L19_001DED40 * t * self->x2C, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x27B2F3, 0xBDFFF, 0, 0, 0, 0, 0x7F27B2F3, 0x280BDFFF, 0, 0);
        func_L01_0044EBF8(self, 1, 0.0f);
        func_003BD360(self);
    }
}
/* localdecomp:end func_L19_003D5E78 */
