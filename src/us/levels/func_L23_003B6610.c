#include "common.h"

/* NTSC-U counterpart of func_L23_003B8008 (src/levels/23_holostar_studios_clank/L23_003B7530.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    s32 id;
    s32 x4;
    f32 x8;
    f32 xC;
    f32 x10;
    f32 x14;
    s32 x18;
    u8 pad1C[4];
    V4 x20;
    f32 x30;
    f32 x34;
    f32 x38;
} Vars_3B8008;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 pad21[0xB];
    f32 scale;
    u8 x30;
    u8 pad31[0x37];
    Vars_3B8008 *vars;
    u8 pad6C[0xF0 - 0x6C];
    f32 xF0;
    f32 xF4;
    f32 xF8;
} Moby_3B8008;
#include "vu0.h"
extern f32 func_00388978(f32);
#include "vu0.h"
extern f32 func_00388978(f32);
#include "vu0.h"
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

/* localdecomp:start func_L23_003B6610 */
#include "vu0.h"
extern f32 D_L23_001DE55C;
__asm__(".extern D_L23_001DE55C, 4");
extern f32 D_L23_001DE560;
__asm__(".extern D_L23_001DE560, 4");
extern f32 D_L23_001DE558_003B6610;
__asm__(".extern D_L23_001DE558_003B6610, 4");
extern f32 D_L23_001DE554_003B6610;
__asm__(".extern D_L23_001DE554_003B6610, 4");
extern f32 D_L23_001E13D0;
extern u8 *D_L23_001E8818[];
extern void func_L23_003B6488(s32);
extern void func_L23_003B6568(void *out, s32 idx, f32 dist);
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

void func_L23_003B6610(Moby_3B8008 *m)
{
    Vars_3B8008 *v = m->vars;
    V4 a;
    V4 b;
    V4 d;
    V4 c;
    V4 f;
    V4 e;
    f32 z;

    if (m->x20 == 0) {
        func_L23_003B6488(v->id);
        m->scale *= D_L23_001DE55C;
        v->x18 = 0;
        v->x10 = v->x8;
        v->x8 += D_L23_001DE560 + 0.001f;
        v->xC += D_L23_001E13D0 - 0.001f - D_L23_001DE560;
        m->x30 = 0xFE;
        func_L01_00441FB8(m, 1, -1);
        return;
    }
    if (m->x20 == 1) {
        if (v->x18 == 0) {
            func_003BEC60(&v->x10, &v->x14, v->xC, D_L23_001DE558_003B6610, D_L23_001DE558_003B6610, D_L23_001DE554_003B6610);
        } else {
            func_003BEC60(&v->x10, &v->x14, v->x8, D_L23_001DE558_003B6610, D_L23_001DE558_003B6610, D_L23_001DE554_003B6610);
        }
        func_L23_003B6568(&a, v->id, v->x10 - D_L23_001DE560);
        func_L23_003B6568(&b, v->id, v->x10 + D_L23_001DE560);
        m->xF8 = func_00389380(func_00388A28(b.x - a.x, b.y - a.y), v->x4 != 0 ? 0.0f : 3.1415927f);
        vec_add_ab(&m->pos, &a, &b);
        func_003886E8(&m->pos, &m->pos, 0.5f);
        if (v->x18 == 0 && fabs_asm(v->x10 - v->xC) < 0.01f) {
            v->x18 = 1;
        } else if (v->x18 == 1 && fabs_asm(v->x10 - v->x8) < 0.01f) {
            v->x18 = 0;
        }
        c = b;
        d = b;
        c.z += 1.0f;
        d.z = 0.01f;
        if (!(func_003CE740(&c, &d, 0, m, 0) != 0 && D_L23_001E8818[0] != 0 &&
              (*(u16 *)(D_L23_001E8818[0] + 0xAA) == 0x1C26 || *(u16 *)(D_L23_001E8818[0] + 0xAA) == 0x1C27))) {
            e = a;
            f = a;
            e.z += 1.0f;
            f.z = 0.01f;
            if (!(func_003CE740(&e, &f, 0, m, 0) != 0 && D_L23_001E8818[0] != 0 &&
                  (*(u16 *)(D_L23_001E8818[0] + 0xAA) == 0x1C26 || *(u16 *)(D_L23_001E8818[0] + 0xAA) == 0x1C27))) {
                func_L01_00441FB8(m, 2, -1);
            }
        }
        if (func_L01_00444358(m, -1, 0) != 0) {
            func_L01_00441FB8(m, 3, -1);
        }
    } else if (m->x20 == 2) {
        if (func_L01_00452EC8((u8 *)m) != 0) {
            v->x20.x = func_00388960(m->xF8) * v->x14;
            v->x20.y = func_00388978(m->xF8) * v->x14;
            v->x20.z = 0.0f;
            z = v->x20.z;
            v->x30 = func_L01_00440918(z, 0.008726647f);
            v->x34 = func_0037E250(0.008726647f, 0.017453294f);
            v->x38 = func_L01_00440918(z, 0.008726647f);
            if (v->x18 == 1) {
                v->x34 = -v->x34;
            }
        }
        v->x20.z += -0.0027777778f;
        vec_add_ba(&m->pos, &m->pos, &v->x20);
        m->xF0 = func_00389380(m->xF0, v->x30);
        m->xF4 = func_00389380(m->xF4, v->x34);
        m->xF8 = func_00389380(m->xF8, v->x38);
        if (func_L01_003F9498(&m->pos, 0, (u8 *)m, D_L23_001DE560) != 0) {
            func_L01_00441FB8(m, 3, -1);
        }
    } else if (m->x20 == 3) {
        func_0039FE80(0, 0, m);
        func_L01_0032FE90((u8 *)&m->pos, 1, 4, 10, 2, 10, 20, 4, D_L23_001DE55C + D_L23_001DE55C, 0.0f, 0.0f, 0.0f,
                          0, 1, 1, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF, 0x70303280,
                          0x7F004020, 0x280000FF, 0x3064FF, 0);
        func_003BD360(m);
    }
}
/* localdecomp:end func_L23_003B6610 */
