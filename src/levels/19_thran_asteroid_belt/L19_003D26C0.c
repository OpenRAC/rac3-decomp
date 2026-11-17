#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L19_003D26C0);

/* localdecomp:start func_L19_003D2788 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2788;
typedef struct { V4_3D2788 dir; s32 x10; s32 x14; s32 x18; f32 x1C; void *x20; s32 x24; } D_3D2788;
typedef struct {
    u8 pad0[0x10]; V4_3D2788 pos; u8 x20; u8 pad21[0xF]; u8 x30; u8 pad31; s16 x32; u8 pad34[0x34];
    D_3D2788 *x68; u8 pad6C[0x54]; V4_3D2788 xC0; V4_3D2788 xD0; V4_3D2788 xE0;
} M_3D2788;
__asm__(".extern D_L19_001DEB50, 4");
__asm__(".extern D_L19_001DEB54, 4");
__asm__(".extern D_L19_001DEB58, 4");
__asm__(".extern D_L19_001DEB5C, 4");
__asm__(".extern D_L19_001DEB60, 4");
__asm__(".extern D_L19_001DEB80, 4");
__asm__(".extern D_L19_001DEBA0, 4");
__asm__(".extern D_L19_001DEBC0, 4");
extern f32 D_L19_001DEB50;
extern f32 D_L19_001DEB54;
extern f32 D_L19_001DEB58;
extern f32 D_L19_001DEB5C;
extern s32 D_L19_001DEB60;
extern s32 D_L19_001DEB64;
extern f32 D_L19_001DEB80;
extern f32 D_L19_001DEBA0;
extern s32 D_L19_001DEBC0;
extern u8 D_L19_001D66F0[8];
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_00470C78(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 a3, s32 spin,
                             void *velocity, s32 t2, s32 t3, s16 arg8, s32 arg9);

M_3D2788 *func_L19_003D2788(void *owner, u8 *pos, V4_3D2788 *dir, f32 f, s32 a3) {
    V4_3D2788 m;
    V4_3D2788 v;
    V4_3D2788 r;
    M_3D2788 *p;
    D_3D2788 *d;
    s32 i;

    func_003C5180(pos, &m, 1);
    p = (M_3D2788 *)func_003C24B0(0x1DE0, 0x30);
    if (p != 0) {
        d = p->x68;
        d->x10 = 0x14D;
        p->x30 = 0xFF;
        p->x32 = 0xFF;
        p->x20 = 0;
        p->pos = *(V4_3D2788 *)pos;
        d->dir = *dir;
        d->x1C = f;
        d->x18 = 0;
        d->x14 = 0;
        func_0038CF68(&v, dir, 1.0f);
        p->xC0 = v;
        func_0038CE90(&p->xD0, &p->xC0, &m);
        func_0038CF68(&p->xD0, &p->xD0, 1.0f);
        func_0038CE90(&p->xE0, &p->xD0, &p->xC0);
        p->xC0.w = p->xD0.w = p->xE0.w = 0.0f;
        d->x20 = owner;
        d->x24 = a3;
        for (i = 0; i < 10; i++) {
            func_00382580(&r, 0.100000009f, 0.200000018f);
            func_L01_00474078(pos, &r, (func_00382498(10, 0x19) * 5 + 2) / 6, D_L19_001DEB50, D_L19_001DEB54,
                              D_L19_001DEB58, D_L19_001DEB5C, D_L19_001DEB60, D_L19_001DEB64, 0, 0);
        }
        for (i = 0; i < 4; i++)
            func_L01_0046B458(pos, 0xC, (&D_L19_001DEB80)[i], (&D_L19_001DEBA0)[i], (&D_L19_001DEB60)[i],
                              2, 1, D_L19_001D66F0, 0.0f, 1);
        for (; i < 7; i++)
            func_L01_00470C78(pos, 0x11, (&D_L19_001DEB80)[i], (&D_L19_001DEBA0)[i], (&D_L19_001DEB60)[i], 2, 2,
                              D_L19_001D66F0, 0, (&D_L19_001DEBC0)[i - 4], 6, 1);
    }
    return p;
}
/* localdecomp:end func_L19_003D2788 */

/* localdecomp:start func_L19_003D2A40 */
typedef struct { u8 p0[0x18]; u8 *f18; } S_3D2A40g;
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446A70(s32, s32, s32, s32, s32, f32);
extern void func_L19_003D2DD8(void *, s32, s32, s32, void *);
extern u8 *D_L19_001E8E58[];
extern S_3D2A40g D_L19_001E8E40;
__asm__(".extern D_L19_001DEBCC, 4");
extern f32 D_L19_001DEBCC;
__asm__(".extern D_L19_001DEBD0, 4");
extern f32 D_L19_001DEBD0;
__asm__(".extern D_L19_001DEBD4, 4");
extern f32 D_L19_001DEBD4;

void func_L19_003D2A40(u8 *a, void *b) {
    u8 *s;
    u8 *pos;
    s32 r;
    u8 *o;
    u8 *q;
    f32 v[4];
    pos = a + 0x10;
    s = *(u8 **)(a + 0x68);
    func_L01_004CB320();
    r = func_003D3CB0(b, pos, 0, a, 0);
    if (r != 0) {
        o = D_L19_001E8E58[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (r == 0) {
        if (func_L01_003FB640(a + 0x10, 0, a, D_L19_001DEBD4) == 0) {
            return;
        }
    }
    q = D_L19_001E8E40.f18;
    if (q != 0) {
        o = *(u8 **)(s + 0x20);
        if (q != o && (*(u16 *)(q + 0x34) & 0x4000) && *(s16 *)(q + 0xAA) != *(s16 *)(o + 0xAA)) {
            f32 f = D_L19_001DEBCC;
            if (*(s32 *)(s + 0x24) == 0) {
                f = f * 0.5f;
            }
            func_0038CF68(v, s, f);
            v[2] = D_L19_001DEBD0;
            v[3] = 5627.9248f;
            func_L01_00446A70((s32)D_L19_001E8E40.f18, (s32)a, 0x10001, (s32)(a + 0x10), (s32)v, *(f32 *)(s + 0x1C));
            func_L19_003D2DD8(a + 0x10, 0xA, 2, 1, a);
        }
        if (D_L19_001E8E40.f18 != 0) {
            a[0x20] = 2;
            return;
        }
    }
    func_L19_003D2DD8(a + 0x10, 0xF, 5, 0, a);
    a[0x20] = 2;
}
/* localdecomp:end func_L19_003D2A40 */

/* localdecomp:start func_L19_003D2BF8 */
typedef int u128_t_3D2BF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2BF8;
__asm__(".extern D_L19_001DEBE8, 4");
__asm__(".extern D_L19_001DEBD8, 4");
__asm__(".extern D_L19_001DEC18, 4");
__asm__(".extern D_L19_001DEC28, 4");
__asm__(".extern D_L19_001DEBF8, 4");
__asm__(".extern D_L19_001DEC08, 4");
extern u32 D_L19_001DEBE8;
extern u32 D_L19_001DEBEC;
extern u32 D_L19_001DEBF0;
extern f32 D_L19_001DEBD8;
extern f32 D_L19_001DEBDC;
extern f32 D_L19_001DEBE0;
extern u32 D_L19_001DEC18;
extern u32 D_L19_001DEC1C;
extern u32 D_L19_001DEC20;
extern s32 D_L19_001DEC28;
extern s32 D_L19_001DEC2C;
extern s32 D_L19_001DEC30;
extern f32 D_L19_001DEBF8;
extern f32 D_L19_001DEBFC;
extern f32 D_L19_001DEC00;
extern f32 D_L19_001DEC08;
typedef struct { f32 a; f32 b; } P_3D2BF8;
__asm__(".extern D_L19_001DEC0C, 16");
extern P_3D2BF8 D_L19_001DEC0C;
extern f32 func_0038CEA8(void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_L01_0040A4A0(void *, void *, s32, u32, s32, s32, f32, f32, f32);

void func_L19_003D2BF8(u8 *self) {
    u8 *d;
    V4_3D2BF8 v;

    *(u128_t_3D2BF8 *)&v = 0;
    d = *(u8 **)(self + 0x68);
    v.w = 1.0f;
    *(f32 *)(d + 0x14) = *(f32 *)(d + 0x14) - 0.1f;
    if (*(f32 *)(d + 0x14) <= -8.0f)
        *(f32 *)(d + 0x14) = *(f32 *)(d + 0x14) + 8.0f;
    *(f32 *)(d + 0x18) = *(f32 *)(d + 0x18) + func_0038CEA8(d);
    func_003D9508(self + 0x10, 0x31, D_L19_001DEBE8, 1, D_L19_001DEBD8, 0.0f, func_00382538());
    func_003D9508(self + 0x10, 0x31, D_L19_001DEBEC, 0, D_L19_001DEBDC, 0.0f, func_00382538());
    func_003D9508(self + 0x10, 0x2F, D_L19_001DEBF0, 1, D_L19_001DEBE0, 0.0f, func_00382538());
    if (1.0f < *(f32 *)(d + 0x18)) {
        func_L01_0040A4A0(self, &v, 1, D_L19_001DEC18, D_L19_001DEC28, 0x17, D_L19_001DEBF8, D_L19_001DEC08, *(f32 *)(d + 0x14));
        func_L01_0040A4A0(self, &v, 1, D_L19_001DEC1C, D_L19_001DEC2C, 0x17, D_L19_001DEBFC, D_L19_001DEC0C.a, *(f32 *)(d + 0x14));
        func_L01_0040A4A0(self, &v, 1, D_L19_001DEC20, D_L19_001DEC30, 0x17, D_L19_001DEC00, D_L19_001DEC0C.b, *(f32 *)(d + 0x14));
    }
}
/* localdecomp:end func_L19_003D2BF8 */

/* localdecomp:start func_L19_003D2DD8 */
typedef int u128_t_3D2DD8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3D2DD8;
__asm__(".extern D_L19_001DEC38, 4");
__asm__(".extern D_L19_001DEC40, 4");
__asm__(".extern D_L19_001DEC44, 4");
__asm__(".extern D_L19_001DEC48, 4");
__asm__(".extern D_L19_001DEC4C, 4");
__asm__(".extern D_L19_001DEC50, 4");
__asm__(".extern D_L19_001DEC54, 4");
__asm__(".extern D_L19_001DEC58, 4");
extern s32 D_L19_001DEC38;
extern s32 D_L19_001DEC3C;
extern f32 D_L19_001DEC40;
extern f32 D_L19_001DEC44;
extern f32 D_L19_001DEC48;
extern f32 D_L19_001DEC4C;
extern f32 D_L19_001DEC50;
extern f32 D_L19_001DEC54;
extern f32 D_L19_001DEC58;
extern V4_3D2DD8 D_L19_001E2080;
extern V4_3D2DD8 D_001A4EC0;
extern u8 *D_L19_0021EED8[];
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D890(void *, f32, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_004708C8(void *, void *, s32, s32, f32, f32, s32, s32, s32, s32, s32);

void func_L19_003D2DD8(void *p, s32 n2, s32 n1, s32 flag, void *obj) {
    V4_3D2DD8 *pos = p;
    V4_3D2DD8 axis;
    V4_3D2DD8 vel;
    V4_3D2DD8 dir;
    V4_3D2DD8 a;
    V4_3D2DD8 c;
    V4_3D2DD8 d;
    s32 spin;
    s32 k;
    s32 i, j;
    s32 one;
    s32 life;
    f32 sz;
    f32 ang;
    f32 el;
    u8 *r;
    u8 *t;
    u8 *q;

    *(u128_t_3D2DD8 *)&axis = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    vec_sub_ab(&dir, &D_L19_001E2080, pos);
    for (i = 0; i < n1; i++) {
        {
            a = *pos;
            a.x += func_L01_00443A18(0.0f, 0.05f);
            a.y += func_L01_00443A18(0.0f, 0.05f);
            a.z += func_L01_00443A18(0.0f, 0.05f);
            spin = func_00382468(2);
            if (spin == 0)
                spin--;
            func_0038D890(&vel, func_003824E0(-1.0471976f, 1.0471976f), &dir, &axis);
            func_0038CF68(&vel, &vel, func_003824E0(D_L19_001DEC40, D_L19_001DEC44) * 0.020000001f);
            vel.z = func_003824E0(D_L19_001DEC48, D_L19_001DEC4C) * 0.020000001f;
            func_L01_0046B458((u8 *)&a, 0x32, func_003824E0(D_L19_001DEC54, D_L19_001DEC58), D_L19_001DEC58,
                              D_L19_001DEC38, 0, spin, &vel, D_L19_001DEC50 * 1.44f, 0);
        }
    }
    for (j = 0; j < n2; j++) {
        {
            func_0038CE20(&a, &D_001A4EC0, -(func_003824E0(0.1f, 1.5f) * 0.020000001f));
            k = (s32)func_L01_00443A18(1.0f, 2.0f);
            sz = func_003824E0(0.15f, 0.35f) * 210000.0f;
            c.x = pos->x + func_L01_00443A18(0.0f, 0.1f);
            c.y = pos->y + func_L01_00443A18(0.0f, 0.1f);
            c.z = pos->z + func_L01_00443A18(0.0f, 0.1f);
            r = func_L01_004669B0(&c, 0.0f, 1.0f, 1.01f, sz, k, &a, 0x7F202020, 0);
            if (r != 0) {
                *(s16 *)(r + 0xA) = 0x4B;
                t = r + 0x20;
                r[0x3] = 0x44;
                r[0x9] = 0x44;
                *(f32 *)(t + 0x1C) = 4.0f;
                *(s32 *)(t + 0x4) = 3;
                t[0xA] = 0x30;
                t[0xB] = r[0xA];
            }
        }
    }
    one = 1;
    for (j = 0; j < 2; j++) {
        el = func_003824E0(-0.9599311f, -1.3962634f);
        ang = func_00382538();
        func_00382760(&a, func_003824E0(0.0f, 0.5f) * 0.020000001f, ang, el);
        vec_sub_ab(&c, &D_L19_001E2080, pos);
        func_0038CF68(&c, &c, 0.3f);
        vec_add_ba(pos, pos, &c);
        sz = func_003824E0(20000.0f, 75000.0f);
        d.x = pos->x + func_L01_00443A18(0.0f, 0.02f);
        d.y = pos->y + func_L01_00443A18(0.0f, 0.02f);
        d.z = pos->z + func_L01_00443A18(0.01f, 0.05f);
        if (flag)
            q = func_L01_004708C8(&d, &a, D_L19_001DEC38, D_L19_001DEC3C, sz, 0.1f, func_00382498(8, 0x11), 1, 1, -1, one);
        else
            q = func_L01_004708C8(&d, &a, D_L19_001DEC38, D_L19_001DEC3C, sz, 0.1f, func_00382498(0x15, 0x32), 1, 1, -1, one);
        if (q != 0)
            q[2] = D_L19_0021EED8[0x16C / 4][1];
    }
}
/* localdecomp:end func_L19_003D2DD8 */
