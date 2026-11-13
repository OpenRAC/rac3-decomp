#include "common.h"

/* NTSC-U counterpart of func_L23_003B7930 (src/levels/23_holostar_studios_clank/L23_003B7530.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    s32 path; s32 rev; f32 x8; f32 xC; f32 x10; f32 x14; s32 x18; u8 pad1C[4];
    V4 vel; f32 x30; f32 x34; f32 x38;
} Vars_3B7930;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0xB]; f32 scale; u8 b30; u8 pad31[0x37]; Vars_3B7930 *vars; u8 pad6C[0x84]; f32 rot[3];
} Moby_3B7930;
#include "vu0.h"
extern f32 func_00388978(f32);
#include "vu0.h"
extern f32 func_00388978(f32);

/* localdecomp:start func_L23_003B5F38 */
#include "vu0.h"
extern f32 D_L23_001DE540_003B5F38;
__asm__(".extern D_L23_001DE540_003B5F38, 4");
extern f32 D_L23_001DE544;
__asm__(".extern D_L23_001DE544, 4");
extern f32 D_L23_001DE548;
__asm__(".extern D_L23_001DE548, 4");
extern f32 D_L23_001DE54C;
__asm__(".extern D_L23_001DE54C, 4");
extern f32 D_L23_001E13D0;
extern u8 *D_L23_001E8818[];
void func_L23_003B6488(s32);
void func_L23_003B6568(void *out, s32 idx, f32 dist);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BEC60(f32 *, void *, f32, f32, f32, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_L01_00452EC8(u8 *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_003F9498(void *a0, s32 a1, u8 *a2, f32 f12);
extern void func_0039FE80(s32, s32, void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003BD360(void *);

void func_L23_003B5F38(Moby_3B7930 *self)
{
    Vars_3B7930 *v = self->vars;
    V4 a;
    V4 b;
    V4 d1;
    V4 c1;
    V4 d2;
    V4 c2;
    f32 z;

    if (self->b20 == 0) {
        func_L23_003B6488(v->path);
        self->scale *= D_L23_001DE548;
        v->x18 = 0;
        v->x10 = v->x8;
        v->x8 = v->x8 + (D_L23_001DE54C + 0.001f);
        v->xC = v->xC + (D_L23_001E13D0 - 0.001f - D_L23_001DE54C);
        self->b30 = 0xFE;
        func_L01_00441FB8(self, 1, -1);
    } else if (self->b20 == 1) {
        if (v->x18 == 0)
            func_003BEC60(&v->x10, &v->x14, v->xC, D_L23_001DE544, D_L23_001DE544, D_L23_001DE540_003B5F38);
        else
            func_003BEC60(&v->x10, &v->x14, v->x8, D_L23_001DE544, D_L23_001DE544, D_L23_001DE540_003B5F38);
        func_L23_003B6568(&a, v->path, v->x10 - D_L23_001DE54C);
        func_L23_003B6568(&b, v->path, v->x10 + D_L23_001DE54C);
        self->rot[2] = func_00389380(func_00388A28(b.x - a.x, b.y - a.y), v->rev != 0 ? 3.1415927f : 0.0f);
        vec_add_ab(&self->pos, &a, &b);
        func_003886E8(&self->pos, &self->pos, 0.5f);
        if (v->x18 == 0 && fabs_asm(v->x10 - v->xC) < 0.01f)
            v->x18 = 1;
        else if (v->x18 == 1 && fabs_asm(v->x10 - v->x8) < 0.01f)
            v->x18 = 0;
        c1 = b;
        d1 = b;
        d1.z = 0.01f;
        c1.z += 1.0f;
        if (func_003CE740(&c1, &d1, 0, self, 0) == 0 || D_L23_001E8818[0] == 0 ||
            (u16)(*(u16 *)(D_L23_001E8818[0] + 0xAA) - 0x1C26) >= 2) {
            c2 = a;
            d2 = a;
            d2.z = 0.01f;
            c2.z += 1.0f;
            if (func_003CE740(&c2, &d2, 0, self, 0) == 0 || D_L23_001E8818[0] == 0 ||
                (u16)(*(u16 *)(D_L23_001E8818[0] + 0xAA) - 0x1C26) >= 2)
                func_L01_00441FB8(self, 2, -1);
        }
        if (func_L01_00444358(self, -1, 0) != 0)
            func_L01_00441FB8(self, 3, -1);
    } else if (self->b20 == 2) {
        if (func_L01_00452EC8((u8 *)self) != 0) {
            v->vel.x = func_00388960(self->rot[2]) * v->x14;
            v->vel.y = func_00388978(self->rot[2]) * v->x14;
            v->vel.z = 0.0f;
            z = v->vel.z;
            v->x30 = func_L01_00440918(z, 0.008726647f);
            v->x34 = func_0037E250(0.008726647f, 0.017453294f);
            v->x38 = func_L01_00440918(z, 0.008726647f);
            if (v->x18 == 1)
                v->x34 = -v->x34;
        }
        v->vel.z += -0.0027777778f;
        vec_add_ba(&self->pos, &self->pos, &v->vel);
        self->rot[0] = func_00389380(self->rot[0], v->x30);
        self->rot[1] = func_00389380(self->rot[1], v->x34);
        self->rot[2] = func_00389380(self->rot[2], v->x38);
        if (func_L01_003F9498(&self->pos, 0, (u8 *)self, D_L23_001DE54C) != 0)
            func_L01_00441FB8(self, 3, -1);
    } else if (self->b20 == 3) {
        func_0039FE80(0, 0, self);
        func_L01_0032FE90((u8 *)&self->pos, 1, 4, 10, 2, 10, 0x14, 4, D_L23_001DE548 * 1.5f, 0.0f, 0.0f, 0.0f,
                          0, 1, 1, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF, 0x70303280, 0x7F004020, 0x280000FF, 0x3064FF, 0);
        func_003BD360(self);
    }
}
/* localdecomp:end func_L23_003B5F38 */
