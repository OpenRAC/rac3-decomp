#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { s32 count; s32 pad[3]; V4 points[1]; } Path;
typedef struct {
    u8 pad0[0x30]; u8 a30[0x3C]; s32 w6C; f32 f70; s32 w74; s32 w78; u8 pad7C[4]; V4 pos80;
} V_3B7530;
typedef struct { u8 pad0[0x10]; s32 w10; u8 pad14[0x44 - 0x14]; u16 h44; } C_3B7530;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[3]; C_3B7530 *p24; u8 pad28[0xC]; u16 h34;
    u8 pad36[0x68 - 0x36]; V_3B7530 *vars; u8 pad6C[0x98 - 0x6C]; s32 w98; u8 pad9C[0xF0 - 0x9C]; u8 aF0[0x10];
} M_3B7530;
typedef struct {
    u8 pad0[0x30];
    u8 x30[0x3C];
    s32 x6C;
    f32 x70;
    s32 x74;
    s32 x78;
    u8 pad7C[4];
    V4 x80;
} Vars_3B7730;
typedef struct {
    s32 path; s32 rev; f32 x8; f32 xC; f32 x10; f32 x14; s32 x18; u8 pad1C[4];
    V4 vel; f32 x30; f32 x34; f32 x38;
} Vars_3B7930;
typedef struct {
    u8 pad0[0x10]; V4 pos; u8 b20; u8 pad21[0xB]; f32 scale; u8 b30; u8 pad31[0x37]; Vars_3B7930 *vars; u8 pad6C[0x84]; f32 rot[3];
} Moby_3B7930;
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

/* localdecomp:start func_L23_003B7530 */
#include "vu0.h"
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001DEC40;
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L23_003B7530(M_3B7530 *m)
{
    V_3B7530 *v = m->vars;
    V4 a;
    V4 b;
    V4 c;

    if (D_L23_001D6694 == 2) {
        m->w98 = 0;
        m->h34 = (m->h34 | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
    } else {
        m->h34 &= ~0x41;
        m->h34 |= m->p24->h44 & 0x1000;
        m->w98 = m->p24->w10;
    }
    if (m->b20 == 0) {
        if (v->w74 < 10) {
            v->w74 = v->w74 * 50.0f;
        } else {
            v->w74 = (v->w74 * 5 + 2) / 6;
        }
        if (v->w78 < 10) {
            v->w78 = v->w78 * 50.0f;
        } else {
            v->w78 = (v->w78 * 5 + 2) / 6;
        }
        v->pos80 = m->pos;
        v->w6C |= 1;
        m->b20 = 1;
    }
    a = m->pos;
    b = v->pos80;
    b.z += func_0038D0B0(func_0038DB48((f32)((D_L23_001DEC40 + v->w78) % v->w74) / (f32)v->w74 * 6.2831855f)) * v->f70;
    m->pos = b;
    vec_sub_ab(&c, &b, &a);
    func_003C4DA8(v->a30, &c, m->aF0, m->aF0);
}
/* localdecomp:end func_L23_003B7530 */

/* localdecomp:start func_L23_003B7730 */
#include "vu0.h"
extern s32 D_L23_001D6694;
__asm__(".extern D_L23_001D6694, 16");
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L23_003B7730(u8 *a0)
{
    Vars_3B7730 *v = *(Vars_3B7730 **)(a0 + 0x68);
    V4 a;
    V4 b;
    V4 d;

    if (D_L23_001D6694 == 2) {
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & ~0x1000;
        func_L01_004AA7E8(a0, 1);
    } else {
        u8 *o = *(u8 **)(a0 + 36);
        *(u16 *)(a0 + 52) &= ~0x41;
        *(u16 *)(a0 + 52) |= *(u16 *)(o + 68) & 0x1000;
        *(s32 *)(a0 + 152) = *(s32 *)(o + 16);
    }
    if (a0[0x20] == 0) {
        if (v->x74 < 10)
            v->x74 = v->x74 * 50.0f;
        else
            v->x74 = (v->x74 * 5 + 2) / 6;
        if (v->x78 < 10)
            v->x78 = v->x78 * 50.0f;
        else
            v->x78 = (v->x78 * 5 + 2) / 6;
        v->x80 = *(V4 *)(a0 + 0x10);
        v->x6C |= 1;
        a0[0x20] = 1;
    }
    a = *(V4 *)(a0 + 0x10);
    b = v->x80;
    b.z += func_0038D0B0(func_0038DB48((f32)((D_L23_001DEC40 + v->x78) % v->x74) / (f32)v->x74 * 6.2831855f)) * v->x70;
    *(V4 *)(a0 + 0x10) = b;
    vec_sub_ab(&d, &b, &a);
    func_003C4DA8(v->x30, &d, a0 + 0xF0, a0 + 0xF0);
}
/* localdecomp:end func_L23_003B7730 */

/* localdecomp:start func_L23_003B7930 */
#include "vu0.h"
extern f32 D_L23_001DE500;
__asm__(".extern D_L23_001DE500, 4");
extern f32 D_L23_001DE504;
__asm__(".extern D_L23_001DE504, 4");
extern f32 D_L23_001DE508;
__asm__(".extern D_L23_001DE508, 4");
extern f32 D_L23_001DE50C;
__asm__(".extern D_L23_001DE50C, 4");
extern f32 D_L23_001E1350;
extern u8 *D_L23_001E8798[];
void func_L23_003B7E80(s32);
void func_L23_003B7F60(void *out, s32 idx, f32 dist);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_003FB640(void *a0, s32 a1, u8 *a2, f32 f12);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L23_003B7930(Moby_3B7930 *self)
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
        func_L23_003B7E80(v->path);
        self->scale *= D_L23_001DE508;
        v->x18 = 0;
        v->x10 = v->x8;
        v->x8 = v->x8 + (D_L23_001DE50C + 0.001f);
        v->xC = v->xC + (D_L23_001E1350 - 0.001f - D_L23_001DE50C);
        self->b30 = 0xFE;
        func_L01_004450F0(self, 1, -1);
    } else if (self->b20 == 1) {
        if (v->x18 == 0)
            func_003C41A0(&v->x10, &v->x14, v->xC, D_L23_001DE504, D_L23_001DE504, D_L23_001DE500);
        else
            func_003C41A0(&v->x10, &v->x14, v->x8, D_L23_001DE504, D_L23_001DE504, D_L23_001DE500);
        func_L23_003B7F60(&a, v->path, v->x10 - D_L23_001DE50C);
        func_L23_003B7F60(&b, v->path, v->x10 + D_L23_001DE50C);
        self->rot[2] = func_0038DAB8(func_0038D160(b.x - a.x, b.y - a.y), v->rev != 0 ? 3.1415927f : 0.0f);
        vec_add_ab(&self->pos, &a, &b);
        func_0038CE20(&self->pos, &self->pos, 0.5f);
        if (v->x18 == 0 && fabs_asm(v->x10 - v->xC) < 0.01f)
            v->x18 = 1;
        else if (v->x18 == 1 && fabs_asm(v->x10 - v->x8) < 0.01f)
            v->x18 = 0;
        c1 = b;
        d1 = b;
        d1.z = 0.01f;
        c1.z += 1.0f;
        if (func_003D3CB0(&c1, &d1, 0, self, 0) == 0 || D_L23_001E8798[0] == 0 ||
            (u16)(*(u16 *)(D_L23_001E8798[0] + 0xAA) - 0x1C26) >= 2) {
            c2 = a;
            d2 = a;
            d2.z = 0.01f;
            c2.z += 1.0f;
            if (func_003D3CB0(&c2, &d2, 0, self, 0) == 0 || D_L23_001E8798[0] == 0 ||
                (u16)(*(u16 *)(D_L23_001E8798[0] + 0xAA) - 0x1C26) >= 2)
                func_L01_004450F0(self, 2, -1);
        }
        if (func_L01_00447490(self, -1, 0) != 0)
            func_L01_004450F0(self, 3, -1);
    } else if (self->b20 == 2) {
        if (func_L01_004561B8((u8 *)self) != 0) {
            v->vel.x = func_0038D098(self->rot[2]) * v->x14;
            v->vel.y = func_0038D0B0(self->rot[2]) * v->x14;
            v->vel.z = 0.0f;
            z = v->vel.z;
            v->x30 = func_L01_00443A18(z, 0.010471976f);
            v->x34 = func_003824E0(0.010471976f, 0.020943953f);
            v->x38 = func_L01_00443A18(z, 0.010471976f);
            if (v->x18 == 1)
                v->x34 = -v->x34;
        }
        v->vel.z += -0.004f;
        vec_add_ba(&self->pos, &self->pos, &v->vel);
        self->rot[0] = func_0038DAB8(self->rot[0], v->x30);
        self->rot[1] = func_0038DAB8(self->rot[1], v->x34);
        self->rot[2] = func_0038DAB8(self->rot[2], v->x38);
        if (func_L01_003FB640(&self->pos, 0, (u8 *)self, D_L23_001DE50C) != 0)
            func_L01_004450F0(self, 3, -1);
    } else if (self->b20 == 3) {
        func_003A52A0(0, 0, self);
        func_L01_003303B8((u8 *)&self->pos, 1, 4, 10, 2, 10, 0x14, 4, D_L23_001DE508 * 1.5f, 0.0f, 0.0f, 0.0f,
                          0, 1, 1, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF, 0x70303280, 0x7F004020, 0x280000FF, 0x3064FF, 0);
        func_003C2880(self);
    }
}
/* localdecomp:end func_L23_003B7930 */

INCLUDE_ASM("asm/levels", func_L23_003B7E80);

/* localdecomp:start func_L23_003B7F60 */
extern Path *D_L23_0021D380[];
extern f32 D_L23_002A3B30[];
extern void func_003C4098(void *, void *, void *, f32);

void func_L23_003B7F60(void *out, s32 idx, f32 dist)
{
    Path *path = D_L23_0021D380[idx];
    V4 a = path->points[0];
    V4 b;
    s32 i;

    for (i = 1; i < path->count; i++) {
        b = path->points[i];
        if (dist < D_L23_002A3B30[i - 1]) {
            func_003C4098(out, &a, &b, dist / D_L23_002A3B30[i - 1]);
            return;
        }
        a = b;
        dist -= D_L23_002A3B30[i - 1];
    }
}
/* localdecomp:end func_L23_003B7F60 */

/* localdecomp:start func_L23_003B8008 */
#include "vu0.h"
extern f32 D_L23_001DE51C;
__asm__(".extern D_L23_001DE51C, 4");
extern f32 D_L23_001DE520;
__asm__(".extern D_L23_001DE520, 4");
extern f32 D_L23_001DE518;
__asm__(".extern D_L23_001DE518, 4");
extern f32 D_L23_001DE514;
__asm__(".extern D_L23_001DE514, 4");
extern f32 D_L23_001E1350;
extern u8 *D_L23_001E8798[];
extern void func_L23_003B7E80(s32);
extern void func_L23_003B7F60(void *out, s32 idx, f32 dist);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_L01_003FB640(void *a0, s32 a1, u8 *a2, f32 f12);
extern void func_003A52A0(s32, s32, void *);
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003C2880(void *);

void func_L23_003B8008(Moby_3B8008 *m)
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
        func_L23_003B7E80(v->id);
        m->scale *= D_L23_001DE51C;
        v->x18 = 0;
        v->x10 = v->x8;
        v->x8 += D_L23_001DE520 + 0.001f;
        v->xC += D_L23_001E1350 - 0.001f - D_L23_001DE520;
        m->x30 = 0xFE;
        func_L01_004450F0(m, 1, -1);
        return;
    }
    if (m->x20 == 1) {
        if (v->x18 == 0) {
            func_003C41A0(&v->x10, &v->x14, v->xC, D_L23_001DE518, D_L23_001DE518, D_L23_001DE514);
        } else {
            func_003C41A0(&v->x10, &v->x14, v->x8, D_L23_001DE518, D_L23_001DE518, D_L23_001DE514);
        }
        func_L23_003B7F60(&a, v->id, v->x10 - D_L23_001DE520);
        func_L23_003B7F60(&b, v->id, v->x10 + D_L23_001DE520);
        m->xF8 = func_0038DAB8(func_0038D160(b.x - a.x, b.y - a.y), v->x4 != 0 ? 0.0f : 3.1415927f);
        vec_add_ab(&m->pos, &a, &b);
        func_0038CE20(&m->pos, &m->pos, 0.5f);
        if (v->x18 == 0 && fabs_asm(v->x10 - v->xC) < 0.01f) {
            v->x18 = 1;
        } else if (v->x18 == 1 && fabs_asm(v->x10 - v->x8) < 0.01f) {
            v->x18 = 0;
        }
        c = b;
        d = b;
        c.z += 1.0f;
        d.z = 0.01f;
        if (!(func_003D3CB0(&c, &d, 0, m, 0) != 0 && D_L23_001E8798[0] != 0 &&
              (*(u16 *)(D_L23_001E8798[0] + 0xAA) == 0x1C26 || *(u16 *)(D_L23_001E8798[0] + 0xAA) == 0x1C27))) {
            e = a;
            f = a;
            e.z += 1.0f;
            f.z = 0.01f;
            if (!(func_003D3CB0(&e, &f, 0, m, 0) != 0 && D_L23_001E8798[0] != 0 &&
                  (*(u16 *)(D_L23_001E8798[0] + 0xAA) == 0x1C26 || *(u16 *)(D_L23_001E8798[0] + 0xAA) == 0x1C27))) {
                func_L01_004450F0(m, 2, -1);
            }
        }
        if (func_L01_00447490(m, -1, 0) != 0) {
            func_L01_004450F0(m, 3, -1);
        }
    } else if (m->x20 == 2) {
        if (func_L01_004561B8((u8 *)m) != 0) {
            v->x20.x = func_0038D098(m->xF8) * v->x14;
            v->x20.y = func_0038D0B0(m->xF8) * v->x14;
            v->x20.z = 0.0f;
            z = v->x20.z;
            v->x30 = func_L01_00443A18(z, 0.010471976f);
            v->x34 = func_003824E0(0.010471976f, 0.020943953f);
            v->x38 = func_L01_00443A18(z, 0.010471976f);
            if (v->x18 == 1) {
                v->x34 = -v->x34;
            }
        }
        v->x20.z += -0.004f;
        vec_add_ba(&m->pos, &m->pos, &v->x20);
        m->xF0 = func_0038DAB8(m->xF0, v->x30);
        m->xF4 = func_0038DAB8(m->xF4, v->x34);
        m->xF8 = func_0038DAB8(m->xF8, v->x38);
        if (func_L01_003FB640(&m->pos, 0, (u8 *)m, D_L23_001DE520) != 0) {
            func_L01_004450F0(m, 3, -1);
        }
    } else if (m->x20 == 3) {
        func_003A52A0(0, 0, m);
        func_L01_003303B8((u8 *)&m->pos, 1, 4, 10, 2, 10, 20, 4, D_L23_001DE51C + D_L23_001DE51C, 0.0f, 0.0f, 0.0f,
                          0, 1, 1, 0, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x70000000, 0x700020FF, 0x8FAF, 0x70303280,
                          0x7F004020, 0x280000FF, 0x3064FF, 0);
        func_003C2880(m);
    }
}
/* localdecomp:end func_L23_003B8008 */
