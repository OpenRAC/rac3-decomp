#include "common.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    V4 r[4];
} S_3ABB50;
typedef struct { s32 x0; f32 x4; u8 pad8[8]; u128_t pos; } Vars_3AB2F0;

/* localdecomp:start func_L23_003AAA58 */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
void func_L23_003AAD58(u8 *self);
void func_L23_003AAED8(u8 *a0);
void func_L23_003AAF58(u8 *self);
void func_L23_003AB058(u8 *a0);
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern struct Moby *D_L23_001E8798[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_0045A9F0();
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004048D0(void *, u8 *);
extern s32 func_0038CAD0(void *);
void func_L23_003AB140(u8 *self);

void func_L23_003AAA58(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    V4 p;
    f32 ang;
    u8 *pos;

    if (self[0x20] != 4)
        func_L23_003AAD58(self);
    switch (self[0x20]) {
    case 0:
        func_L23_003AAED8(self);
        break;
    case 1:
        if ((D_L23_001DEC40 & 0xF) == (((s32)self >> 8) & 0xF) &&
            func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) < 800.0f) {
            p = *(V4 *)(self + 0x10);
            p.z += 1.5f;
            if (func_003D3CB0(&p, &D_001A4BE0.pickup_point, 0, self, 0) == 0 || D_L23_001E8798[0] == D_001A4BE0.hero_moby)
                func_L01_004450F0(self, 2, -1);
        }
        func_L01_0045A9F0(self);
        break;
    case 2:
        ang = func_0038D160(D_001A4BE0.pos.x - *(f32 *)(self + 0x10), D_001A4BE0.pos.y - *(f32 *)(self + 0x14));
        func_L01_00448890(self + 0xF8, ang, 0.0025132743f, 0.0025132743f, 0.12566371f, v + 4, 0);
        *(u128_t *)(self + 0x10) = *(u128_t *)(v + 0x10);
        if (func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) > 800.0f)
            func_L01_004450F0(self, 1, -1);
        if (func_0038DBA0(*(f32 *)(self + 0xF8), ang) < 0.08726646f) {
            if (fabs_asm(*(f32 *)(v + 4)) < 0.00087266468f) {
                *(f32 *)(v + 4) = 0.0f;
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0)
            func_L23_003AAF58(self);
        pos = self + 0x10;
        *(u128_t *)pos = *(u128_t *)(v + 0x10);
        if (*(s32 *)v <= 0) {
            if (func_003D3CB0(pos, D_001A4BE0.pad_A0 + 0x30, 0, self, 0) != 0 && D_L23_001E8798[0] != D_001A4BE0.hero_moby)
                func_L01_004450F0(self, 1, -1);
            else
                func_L01_004450F0(self, 2, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(self) != 0) {
            func_L23_003AB058(self);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x41;
        }
        func_L01_004048D0(func_L23_003AB140, self);
        return;
    }
    *(u16 *)(self + 0x96) += 1;
    func_0038CAD0(v);
}
/* localdecomp:end func_L23_003AAA58 */

/* localdecomp:start func_L23_003AAD58 */
#include "vu0.h"
#include "structs/hero.h"
extern u8 D_L23_001E1A40[];
extern struct Hero D_001A4BE0;
extern u8 *D_L23_001DE2D0;
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_00404A10(void *, s32);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AAD58(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;

    if (self[0x31] != 0 && func_L01_0040E548(D_L23_001E1A40, self + 0x10) < 1024.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 0x1E;
    }
    if (self[0x20] == 0)
        return;
    func_L01_00404A10(self, 3);
    if ((fabs_asm(*(f32 *)(self + 0x18) - D_001A4BE0.pos.z) < 1.0f &&
         func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) < 16.0f) ||
        (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(D_L23_001DE2D0 + 0x18)) < 1.0f &&
         func_L01_0040E570(self + 0x10, D_L23_001DE2D0 + 0x10) < 16.0f)) {
        func_L01_004450F0(self, 4, -1);
    }
    hit = (u8 *)func_L01_00447490(self, -1, 0);
    if (hit != 0) {
        *(f32 *)(v + 8) -= *(f32 *)(hit + 0x2C);
        if (*(f32 *)(v + 8) <= 0.0f)
            func_L01_004450F0(self, 4, -1);
    }
}
/* localdecomp:end func_L23_003AAD58 */

/* localdecomp:start func_L23_003AAED8 */
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AAED8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    *(u16 *)(a0 + 0x34) |= 0x10;
    *(f32 *)(a0 + 0x18) = func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
    *(f32 *)(v + 8) = 40.0f;
    *(s32 *)(v + 0) = 0;
    *(s32 *)(v + 4) = 0;
    *(u128_t *)(v + 0x10) = *(u128_t *)(a0 + 0x10);
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L23_003AAED8 */

/* localdecomp:start func_L23_003AAF58 */
#include "vu0.h"
__asm__(".extern D_L23_001DE1D0, 4");
extern s32 D_L23_001DE1D0;
extern s32 D_001A71A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L23_003B0978(void *, void *, void *, s32, s32, s32);

void func_L23_003AAF58(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    V4 a, b;

    a.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.1f;
    a.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.1f;
    a.z = 1.0f;
    vec_add_ba(&a, &a, self + 0x10);
    b.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.5f;
    b.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.5f;
    b.z = 0.5f;
    func_0038CF68(&b, &b, 0.40000004f);
    func_L23_003B0978(self, &a, &b, D_001A71A0[0], 0x96, 1);
    *(s32 *)s = D_L23_001DE1D0;
}
/* localdecomp:end func_L23_003AAF58 */

/* localdecomp:start func_L23_003AB058 */
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L23_003AB058(u8 *a0) {
    func_L01_003303B8(a0 + 16, 1, 4, 20, 2, 10, 20, 4, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 1, 1, 0, 0, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 1);
    func_003A52A0(0, 0, a0);
}
/* localdecomp:end func_L23_003AB058 */

/* localdecomp:start func_L23_003AB140 */
#include "vu0.h"
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern long func_00389598(s32);
extern void func_0038D570(void *, void *);
extern void func_003D2DA0(S_3ABB50 *, V4 *, s32);
extern u8 D_L23_001E1A40[];
extern s32 D_L23_001DE1D8[2];
extern f32 D_L23_001DE1D4;
__asm__(".extern D_L23_001DE1D8, 8");
__asm__(".extern D_L23_001DE1D4, 4");

void func_L23_003AB140(u8 *self)
{
    S_3ABB50 s;
    f32 d;
    s32 c;

    d = func_L01_0040E570(self + 0x10, D_L23_001E1A40);
    if (d > 1600.0f) {
        return;
    }
    if (d > 1024.0f) {
        c = func_0038DBD8(0x50000000, 0, (d - 1024.0f) / 576.0f);
        s.c4C = c;
        s.c48 = c;
        s.c44 = c;
        s.c40 = c;
    } else {
        s.c4C = 0x50000000;
        s.c48 = 0x50000000;
        s.c44 = 0x50000000;
        s.c40 = 0x50000000;
    }
    s.x78 = func_00389598(D_L23_001DE1D8[((s32)self >> 8) % 2]);
    qzero(s.m[0]);
    qzero(s.m[1]);
    qzero(s.m[2]);
    qzero(s.m[3]);
    s.m[0][0] = -D_L23_001DE1D4;
    s.m[1][1] = D_L23_001DE1D4;
    s.x80 = 0xFF9000000379L;
    s.x70 = 5;
    s.m[2][1] = -D_L23_001DE1D4;
    s.m[3][0] = D_L23_001DE1D4;
    s.x88 = 0x8000000044L;
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.m[0][3] = 1.0f;
    s.m[1][3] = 1.0f;
    s.m[2][3] = 1.0f;
    s.m[3][3] = 1.0f;
    func_0038D570(s.r, self + 0xC0);
    s.r[3] = *(V4 *)(self + 0x10);
    s.r[3].w = 1.0f;
    s.r[3].z += 0.02f;
    func_003D2DA0(&s, s.r, 0);
}
/* localdecomp:end func_L23_003AB140 */

/* localdecomp:start func_L23_003AB2F0 */
/* 55 diff: only real difference is case 3's bgtzl (ours) vs bgtz + fallthrough delay slot (retail); everything else is the resulting branch-offset shift */
#include "vu0.h"
#include "structs/hero.h"
extern struct Hero D_001A4BE0;
extern s32 D_L23_001DEC40;
__asm__(".extern D_L23_001DEC40, 16");
extern struct Moby *D_L23_001E8798[];
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_00448890(void *a0, f32 f12, f32 f13, f32 f14, f32 f15, void *a1, s32 a2);
extern f32 func_0038DBA0(f32, f32);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_004048D0(void *, u8 *);
extern s32 func_0038CAD0(void *);
void func_L23_003AB5F0(u8 *self);
void func_L23_003AB770(u8 *self);
void func_L23_003AB7F0(u8 *self);
void func_L23_003ABA68(u8 *self);
void func_L23_003ABB50(u8 *self);

void func_L23_003AB2F0(u8 *self)
{
    Vars_3AB2F0 *v = *(Vars_3AB2F0 **)(self + 0x68);
    V4 t;
    u8 *pos;
    f32 ang;

    if (self[0x20] != 4)
        func_L23_003AB5F0(self);
    switch (self[0x20]) {
    case 0:
        func_L23_003AB770(self);
        break;
    case 1:
        if ((D_L23_001DEC40 & 0xF) == (((s32)self >> 8) & 0xF)) {
            if (func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) < 800.0f) {
                t = *(V4 *)(self + 0x10);
                t.z += 1.5f;
                if (func_003D3CB0(&t, &D_001A4BE0.pickup_point, 0, self, 0) == 0 ||
                    D_L23_001E8798[0] == D_001A4BE0.hero_moby)
                    func_L01_004450F0(self, 2, -1);
            }
        }
        *(u128_t *)(self + 0x10) = v->pos;
        break;
    case 2:
        ang = func_0038D160(D_001A4BE0.pos.x - *(f32 *)(self + 0x10), D_001A4BE0.pos.y - *(f32 *)(self + 0x14));
        func_L01_00448890(self + 0xF8, ang, 0.0025132743f, 0.0025132743f, 0.12566371f, &v->x4, 0);
        *(u128_t *)(self + 0x10) = v->pos;
        if (func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) > 800.0f)
            func_L01_004450F0(self, 1, -1);
        if (func_0038DBA0(*(f32 *)(self + 0xF8), ang) < 0.08726646f) {
            if (fabs_asm(v->x4) < 0.0008726647f) {
                v->x4 = 0.0f;
                func_L01_004450F0(self, 3, -1);
            }
        }
        break;
    case 3:
        if (func_L01_004561B8(self) != 0)
            func_L23_003AB7F0(self);
        pos = self + 0x10;
        *(u128_t *)pos = v->pos;
        if (v->x0 <= 0) {
            if (func_003D3CB0(pos, D_001A4BE0.pad_A0 + 0x30, 0, self, 0) != 0 &&
                D_L23_001E8798[0] != D_001A4BE0.hero_moby)
                func_L01_004450F0(self, 1, -1);
            else
                func_L01_004450F0(self, 2, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(self) != 0) {
            func_L23_003ABA68(self);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) |= 0x41;
        }
        func_L01_004048D0(func_L23_003ABB50, self);
        return;
    }
    (*(u16 *)(self + 0x96))++;
    func_0038CAD0(v);
}
/* localdecomp:end func_L23_003AB2F0 */

/* localdecomp:start func_L23_003AB5F0 */
void func_L23_003AB5F0(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    u8 *hit;

    if (self[0x31] != 0 && func_L01_0040E548(D_L23_001E1A40, self + 0x10) < 1024.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 0x1E;
    }
    if (self[0x20] == 0)
        return;
    func_L01_00404A10(self, 3);
    if ((fabs_asm(*(f32 *)(self + 0x18) - D_001A4BE0.pos.z) < 1.0f &&
         func_L01_0040E570(self + 0x10, &D_001A4BE0.pos) < 16.0f) ||
        (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(D_L23_001DE2D0 + 0x18)) < 1.0f &&
         func_L01_0040E570(self + 0x10, D_L23_001DE2D0 + 0x10) < 16.0f)) {
        func_L01_004450F0(self, 4, -1);
    }
    hit = (u8 *)func_L01_00447490(self, -1, 0);
    if (hit != 0) {
        *(f32 *)(v + 8) -= *(f32 *)(hit + 0x2C);
        if (*(f32 *)(v + 8) <= 0.0f)
            func_L01_004450F0(self, 4, -1);
    }
}
/* localdecomp:end func_L23_003AB5F0 */

/* localdecomp:start func_L23_003AB770 */
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L23_003AB770(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);

    *(u16 *)(self + 0x34) |= 0x10;
    *(f32 *)(self + 0x18) = func_003C3D30(self + 0x10, 0, 0, 0.5f);
    *(f32 *)(s + 0x8) = 40.0f;
    *(s32 *)(s + 0x0) = 0;
    *(s32 *)(s + 0x4) = 0;
    *(V4 *)(s + 0x10) = *(V4 *)(self + 0x10);
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L23_003AB770 */

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

__asm__(".extern D_L23_001DE1E0, 4");
extern s32 D_L23_001DE1E0;
/* localdecomp:start func_L23_003AB7F0 */
void func_L23_003AB7F0(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    V4 a, d, w, c;
    s32 i;
    s32 r1, r2;

    a.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.1f;
    a.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.1f;
    a.z = 1.0f;
    vec_add_ba(&a, &a, self + 0x10);
    vec_sub_ab(&d, &D_001A4BE0.pickup_point, self + 0x10);
    func_0038CF68(&d, &d, 1.2f);
    for (i = 9; i >= 0; i--) {
        w = d;
        w.x += func_003824E0(-0.40000004f, 0.40000004f);
        w.y += func_003824E0(-0.40000004f, 0.40000004f);
        w.z += func_003824E0(-0.40000004f, 0.40000004f);
        func_0038CE20(&w, &w, 0.25f);
        w.w = func_003824E0(0.5f, 1.0f);
        qzero(&c);
        c.z = 0.01f;
        c.w = 1.2f;
        r1 = func_00382498(0x11, 0x19);
        r2 = func_00382498(8, 0x11);
        func_L01_00463378(&a, &w, &c, 0x80406060, 0x80808080, 1, r1, r2, -1);
    }
    func_L23_003B0978(self, &a, &d, (s32)D_001A4BE0.hero_moby, 0x96, 0);
    *(s32 *)s = D_L23_001DE1E0;
}
/* localdecomp:end func_L23_003AB7F0 */

/* localdecomp:start func_L23_003ABA68 */
extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);

void func_L23_003ABA68(u8 *self)
{
    func_L01_003303B8(self + 16, 1, 4, 20, 2, 10, 20, 4, 2.0f, 0.0f, 0.0f, 0.0f,
                      1, 1, 1, 1, 1, 0, 0, 0, 0x388EF7, 25591, 0x407FFF, 8447, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 1);
    func_003A52A0(0, 0, self);
}
/* localdecomp:end func_L23_003ABA68 */

/* localdecomp:start func_L23_003ABB50 */
#include "vu0.h"
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern long func_00389598(s32);
extern void func_0038D570(void *, void *);
extern void func_003D2DA0(S_3ABB50 *, V4 *, s32);
extern u8 D_L23_001E1A40[];
extern s32 D_L23_001DE1E8[2];
extern f32 D_L23_001DE1E4;
__asm__(".extern D_L23_001DE1E8, 8");
__asm__(".extern D_L23_001DE1E4, 4");

void func_L23_003ABB50(u8 *self)
{
    S_3ABB50 s;
    f32 d;
    s32 c;

    d = func_L01_0040E570(self + 0x10, D_L23_001E1A40);
    if (d > 1600.0f) {
        return;
    }
    if (d > 1024.0f) {
        c = func_0038DBD8(0x50000000, 0, (d - 1024.0f) / 576.0f);
        s.c4C = c;
        s.c48 = c;
        s.c44 = c;
        s.c40 = c;
    } else {
        s.c4C = 0x50000000;
        s.c48 = 0x50000000;
        s.c44 = 0x50000000;
        s.c40 = 0x50000000;
    }
    s.x78 = func_00389598(D_L23_001DE1E8[((s32)self >> 8) % 2]);
    qzero(s.m[0]);
    qzero(s.m[1]);
    qzero(s.m[2]);
    qzero(s.m[3]);
    s.m[0][0] = -D_L23_001DE1E4;
    s.m[1][1] = D_L23_001DE1E4;
    s.x80 = 0xFF9000000379L;
    s.x70 = 5;
    s.m[2][1] = -D_L23_001DE1E4;
    s.m[3][0] = D_L23_001DE1E4;
    s.x88 = 0x8000000044L;
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    s.m[0][3] = 1.0f;
    s.m[1][3] = 1.0f;
    s.m[2][3] = 1.0f;
    s.m[3][3] = 1.0f;
    func_0038D570(s.r, self + 0xC0);
    s.r[3] = *(V4 *)(self + 0x10);
    s.r[3].w = 1.0f;
    s.r[3].z += 0.02f;
    func_003D2DA0(&s, s.r, 0);
}
/* localdecomp:end func_L23_003ABB50 */
