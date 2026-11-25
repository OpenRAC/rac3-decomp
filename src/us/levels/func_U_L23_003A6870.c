#include "common.h"
#include "structs/hero.h"
#include "vu0.h"

typedef struct { s32 id; f32 x4; f32 x8; f32 xC; u8 x10; u8 pad11[3]; } Rec14;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

/* localdecomp:start func_U_L23_003A6870 */
typedef struct { u8 pad0[0x24]; f32 x24; } Cls_3A8028;
typedef struct { u8 pad0[0x2C]; f32 x2C; } Hit_3A8028;
typedef struct {
    u8 pad0[0x10];
    V4 pos;
    u8 x20;
    u8 pad21[2];
    u8 x23;
    Cls_3A8028 *cls;
    u8 pad28[4];
    f32 scale;
    u8 x30;
    u8 pad31[3];
    u16 x34;
    u8 pad36[0x46];
    u16 x7C;
    u8 pad7E[0x18];
    u16 timer;
    u8 pad98[0x10];
    u8 xA8;
    u8 padA9;
    s16 xAA;
    u8 padAC[0x14];
    V4 xC0;
    u8 padD0[0x28];
    f32 xF8;
} Moby_3A8028;
typedef struct {
    s32 id;
    s32 x4;
    f32 x8;
    f32 xC;
    u8 pad10[4];
    f32 x14;
    s32 x18;
    s32 x1C;
    s32 x20;
    u8 pad24[8];
    s32 x2C;
    f32 x30;
    f32 x34;
    u8 pad38[0x18];
    u8 x50[0x10];
} Vars_3A8028;

extern struct Hero D_001A4BE0;
extern u8 D_001A30B0[];
extern Rec14 D_L23_002BC878[];
extern u8 D_L23_001E1AC0[];
extern s32 D_L23_001DECC0;
__asm__(".extern D_L23_001DECC0, 16");
extern s32 D_L23_001DECC0_3A6870;
__asm__(".extern D_L23_001DECC0_3A6870, 4");
extern s32 D_L23_001DE170;
__asm__(".extern D_L23_001DE170, 4");
extern s32 D_L23_001DE174;
__asm__(".extern D_L23_001DE174, 4");
extern V4 D_L23_001DE180[] __attribute__((section(".sdata")));
__asm__(".extern D_L23_001DE180, 4");
extern s32 D_L23_001D66B0[2];
__asm__(".extern D_L23_001D66B0, 16");
extern u16 **D_L23_001D6764;
__asm__(".extern D_L23_001D6764, 16");
extern u16 **D_L23_001D676C;
__asm__(".extern D_L23_001D676C, 16");
extern u8 *D_L23_001DFF88;
__asm__(".extern D_L23_001DFF88, 16");
extern u8 *D_L23_001E0094;
__asm__(".extern D_L23_001E0094, 16");

extern void func_U_003A7F48(Moby_3A8028 *);
extern void func_U_003A8490(u8 *);
extern u8 *func_U_0044FD88(void *, void *, s32, s32, float, float, s32, float);
extern f32 func_U_004235B0(f32, f32);
extern s32 func_U_00423538(s32);
extern s32 func_U_00423568(s32, s32);
extern f32 func_U_00423668(void);
extern f32 func_U_00423608(f32, f32);
extern s32 func_U_00441630(void *, void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_U_003EEFC8(void *, void *, f32);
extern void func_U_003EED68(void *, void *, f32);
extern void func_U_003EEDF8(void *, void *, void *);
extern void func_U_003EF1A8(void *, void *, void *);
extern s32 func_U_003EFEF8(s32, s32, f32);
extern f32 func_U_003EF2B8(f32);
extern f32 func_U_003EF2A0(f32);
extern f32 func_U_003EF368(f32, f32);
extern s32 func_U_003EE938(void *);
extern s32 func_U_00427B60(s32, s32, f32);
extern s32 func_U_00488B48(s32, s32, void *);
extern s32 func_U_00436868(u8 *);
extern void func_U_00432478(void *, void *, f32, s32, s32, void *, f32, f32, f32, s32, void *, s32);
extern void func_U_0042F510(void *, void *);
extern void func_U_00424BF8(u8 *, s32, s32);
extern void func_U_003E5670(void (*)(u8 *), u8 *);
extern void func_U_004887D0(s32);
extern s32 func_U_00426F80(void *, s32, s32);
extern void func_U_00419828(void *, s32, void *);
extern void func_U_004197E0(void *, s32 *, s32 *);
extern u8 *func_U_003D8A68(void *, s32, s32, s32, void *, void *, void *, s32, f32, f32, s32, s32, s32);
extern s32 func_U_0032FF28(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_0013D3E0(void);

void func_U_L23_003A6870(Moby_3A8028 *self)
{
    Vars_3A8028 *v = (Vars_3A8028 *)*(void **)((u8 *)self + 0x68);
    Hit_3A8028 *h;
    V4 a, b, c, d, e, g, f, m, k;
    s32 i, n, r, j, k5, i2b, i3b;
    s32 i1, i2;
    f32 s, sc, sz, ang, t, t2, t3, lim;
    u16 *p;
    u8 *q;

    if (v->id < 0)
        return;
    switch (self->x20) {
    case 0:
        func_U_003A7F48(self);
        break;
    case 1:
        func_U_003EE938(&v->x18);
        if (D_L23_002BC878[v->x20].id == 0x1D20 &&
            (D_L23_001DECC0 & 3) == (((s32)self >> 8) & 3)) {
            for (i = 0; i < 3; i++) {
                func_U_003EED68(&a, &D_L23_001DE180[i], self->scale / self->cls->x24);
                func_U_003EF1A8(&a, &a, &self->xC0);
                vec_add_ab(&a, &a, &self->pos);
                b.x = func_U_00423608(0.0f, 0.0050000004f);
                b.y = func_U_00423608(0.0f, 0.0050000004f);
                b.z = 0.06666667f;
                b.w = 0.8f;
                c = b;
                c.w = 1.6f;
                func_U_00441630(&a, &b, &c, 0x80000000, 0x60202020, 1, 60, 30, -1);
            }
        }
        h = (Hit_3A8028 *)func_U_00426F80(self, -1, 0);
        if (h != 0) {
            if (D_L23_001DECC0_3A6870 >= D_L23_001DE174 && v->x18 <= 0 && 3.0f < h->x2C) {
                func_U_00488B48(1, 0x10, self);
                v->xC -= h->x2C;
                v->x18 = D_L23_001DE170;
                D_L23_001DE174 = D_L23_001DECC0 + v->x18;
                self->x34 &= ~0x10;
                if (D_001A4BE0.pos.z - v->x8 < 0.5f) {
                    f32 ra, rs, rt;

                    ra = func_U_003EF368(D_001A4BE0.hand_history[14][1].x - self->pos.x, D_001A4BE0.hand_history[14][1].y - self->pos.y);
                    rs = self->scale * 0.5f / self->cls->x24;
                    rt = rs * rs;
                    rt = sqrt_asm(rt + rt);
                    a.x = self->pos.x + rt * func_U_003EF2A0(ra);
                    a.y = self->pos.y + rt * func_U_003EF2B8(ra);
                    a.z = D_001A4BE0.hand_history[14][1].z < self->pos.z + rs * 20.0f ? D_001A4BE0.hand_history[14][1].z : self->pos.z + rs * 20.0f;
                    vec_sub_ab(&b, &D_001A4BE0.hand_history[14][1], &a);
                    func_U_003EEFC8(&b, &b, 1.0f);
                    *(vu0_q *)&c = 0;
                    c.z = 1.0f;
                    c.w = 1.0f;
                    g = b;
                    func_U_003EEDF8(&d, &c, &g);
                    func_U_003EEDF8(&e, &g, &d);
                    qzero(&c);
                    vec_sub_ab(&f, &a, &self->pos);
                    func_U_00432478(self, &a, 1.0f, 10, 1, D_L23_001D66B0, 3.0f, 1.75f, 2.25f, 0x50604040, 0, 0xB4);
                    for (j = 7; j >= 0; j--) {
                        f32 an = func_U_004235B0(-3.1415927f, 3.1415927f);
                        f32 zf;

                        m.x = func_U_004235B0(0.083333336f, 0.16666667f) * func_U_003EF2A0(an);
                        m.y = func_U_004235B0(0.083333336f, 0.16666667f) * func_U_003EF2B8(an);
                        m.z = func_U_004235B0(0.016666668f, 0.033333335f);
                        func_U_003EF1A8(&m, &m, &d);
                        func_U_003EED68(&k, &m, 0.25f);
                        k.z = -0.083333336f;
                        func_U_00441630(&a, &m, &k, func_U_003EFEF8(0x80202020, 0x80707070, func_U_004235B0(0.0f, 1.0f)), 0x40707070, 5, (func_U_00423538(0x1E) + 0x1E), 5, -1);
                        sz = func_U_004235B0(0.05f, 0.2f);
                        zf = v->x8 - 1.0f;
                        func_U_0044FD88(&a, &m, 0, 0x80606060, sz, zf, func_U_00423568(1, 2), 0.0027777778f);
                    }
                }
            }
            self->xA8 = 0xFF;
        }
        if (v->x18 > 0) {
            f32 an = func_U_004235B0(-3.1415927f, 3.1415927f);
            f32 ss;
            f32 tt = (f32)(v->x18 - 1) / (f32)D_L23_001DE170;
            tt = tt * 0.20000002f;
            a.x = v->x30 - self->pos.x + tt * func_U_003EF2A0(an);
            a.y = v->x34 - self->pos.y + tt * func_U_003EF2B8(an);
            a.z = 0.0f;
            a.w = 1.0f;
            vec_add_ab(&self->pos, &self->pos, &a);
            func_U_0042F510(self, v->x50);
            ss = self->scale * 0.5f / self->cls->x24;
            for (k5 = 5; k5 >= 0; k5--) {
                a = self->pos;
                a.z = func_U_004235B0(v->x8, self->pos.z);
                if (func_U_00423538(2) != 0) {
                    a.x += (f32)(func_U_00423568(0, 1) * 2 - 1) * (ss + 0.20000002f);
                    a.y += func_U_004235B0(-ss, ss);
                } else {
                    a.y += (f32)(func_U_00423568(0, 1) * 2 - 1) * (ss + 0.20000002f);
                    a.x += func_U_004235B0(-ss, ss);
                }
                vec_sub_ab(&b, &a, &self->pos);
                b.z = 0.0f;
                func_U_003EEFC8(&b, &b, func_U_004235B0(0.0f, 0.016666668f));
                qzero(&c);
                b.w = 0.6f;
                c.z = -0.13333334f;
                c.w = 0.75f;
                func_U_00441630(&a, &b, &c, func_U_003EFEF8(0x60202020, 0x60707070, func_U_004235B0(0.0f, 1.0f)), 0x30707070, 5, (func_U_00423538(0x1E) + 0x1E), 5, -1);
            }
        }
        if (v->xC <= 0.0f)
            func_U_00424BF8((u8 *)self, 2, -1);
        break;
    case 2:
        if (func_U_00436868((u8 *)self) != 0) {
            u8 *st;

            v->x1C = func_U_00488B48(0, 0x14, self);
            v->x14 = 0;
            st = D_L23_001E1AC0;
            self->x30 = 0xFF;
            *(f32 *)(st + 0x20) = 0.1f;
            *(s32 *)(st + 0x28) = 300;
            *(s32 *)(st + 0x2C) = 0;
        }
        ang = func_U_004235B0(-3.1415927f, 3.1415927f);
        v->x14 += 0.0016666667f;
        a.x = v->x30 - self->pos.x + func_U_003EF2A0(ang) * 0.20000002f;
        a.y = v->x34 - self->pos.y + func_U_003EF2B8(ang) * 0.20000002f;
        a.z = -v->x14;
        a.w = 1.0f;
        vec_add_ab(&self->pos, &self->pos, &a);
        func_U_0042F510(self, v->x50);
        s = self->scale * 0.5f / self->cls->x24;
        if ((D_L23_001DECC0 & 7) == (((s32)self >> 8) & 7)) {
            f32 z;

            func_U_004197E0(self, &i1, &i2);
            r = func_U_00423568(0, i2 - 1);
            func_U_00419828(self, r, &b);
            c = self->pos;
            z = func_U_004235B0(v->x8, self->pos.z);
            qzero(&d);
            c.z = z - (b.z - self->pos.z);
            b.z = z;
            vec_sub_ab(&e, &b, &self->pos);
            e.z = -v->x14 * 0.5f;
            func_U_003EEFC8(&e, &e, func_U_004235B0(0.016666668f, 0.13333334f));
            e.w = 1.0f;
            lim = func_U_004235B0(-10.0f, 10.0f);
            if (D_L23_002BC878[v->x20].x10 != 0 && func_U_00423538(2) != 0) {
                func_U_003D8A68(self, 2, self->xAA, r, &c, &d, &e, 0xFF, lim, 10.0f, 0xB4, 0, 0x80);
            } else {
                g = c;
                if (func_U_00423538(2) != 0) {
                    g.x += (f32)(func_U_00423568(0, 1) * 2 - 1) * s;
                    g.y += func_U_004235B0(-s, s);
                } else {
                    g.y += (f32)(func_U_00423568(0, 1) * 2 - 1) * s;
                    g.x += func_U_004235B0(-s, s);
                }
                func_U_00432478(self, &g, 1.0f, 2, 1, D_L23_001D66B0, 3.0f, 1.75f, 3.25f, 0x50604040, 0, 0xB4);
            }
            if (func_U_00423538(2) != 0) {
                func_U_0032FF28((u8 *)&b, 0, 10, 10, 0, 10, 10, 1, func_U_004235B0(0.2f, 0.5f), 0.0f, 0.0f, 0.0f,
                                  0, 0, 0, 0, 0, 0, 0, 0, 0x80F7F7, 0xF0F7, 0x70000000, 0x700020FF,
                                  0x8FAF, 0x70303280, 0x7F103030, 0x280000FF, 0x3064FF, 0);
            }
        }
        for (i2b = 0; i2b < 3; i2b++) {
            b = self->pos;
            b.z = func_U_004235B0(v->x8, self->pos.z);
            if (func_U_00423538(2) != 0) {
                b.x += (f32)(func_U_00423568(0, 1) * 2 - 1) * s;
                b.y += func_U_004235B0(-s, s);
            } else {
                b.y += (f32)(func_U_00423568(0, 1) * 2 - 1) * s;
                b.x += func_U_004235B0(-s, s);
            }
            vec_sub_ab(&c, &b, &self->pos);
            c.z = func_U_004235B0(-v->x14, s);
            func_U_003EEFC8(&c, &c, func_U_004235B0(0.016666668f, 0.13333334f));
            qzero(&d);
            c.w = 0.4f;
            d.w = 3.0f;
            vec_sub_ab(&e, &b, &self->pos);
            vec_add_ab(&e, &e, &a);
            e.z = func_U_004235B0(-v->x14, 0.0f);
            func_U_003EEFC8(&e, &e, func_U_004235B0(0.0f, 0.13333334f));
            e.w = func_U_004235B0(0.05f, 0.2f);
            func_U_00441630(&b, &c, &d, 0x75000000, 0x60404040, 5, 10, 10, -1);
            if (D_L23_001DECC0 & 1) {
                f32 zf = v->x8 - 1.0f;

                func_U_0044FD88(&b, &e, 0, 0x80606060, e.w, zf, func_U_00423568(1, 2), 0.0027777778f);
            } else {
                f32 zf;

                b.z = v->x8;
                e.z = func_U_004235B0(0.0f, 0.13333334f);
                zf = v->x8 - 1.0f;
                func_U_0044FD88(&b, &e, 0, 0x80606060, e.w, zf, func_U_00423568(1, 2), 0.0027777778f);
            }
            b.z = v->x8 + func_U_004235B0(0.0f, (self->pos.z - v->x8) * 0.5f);
            c.z = 0.0f;
            func_U_00441630(&b, &c, &d, func_U_003EFEF8(0x80202020, 0x80707070, func_U_004235B0(0.0f, 1.0f)), 0x40707070, 5, (func_U_00423538(0x1E) + 0x1E), 5, -1);
        }
        if (self->pos.z < v->x8)
            func_U_00424BF8((u8 *)self, 3, -1);
        t2 = (f32)self->timer / 60.0f;
        t2 = 1.0f < t2 ? 1.0f : t2;
        v->x2C = func_U_00427B60(0, 0x70, t2);
        func_U_003E5670(func_U_003A8490, (u8 *)self);
        break;
    case 3:
        if (func_U_00436868((u8 *)self) != 0) {
            u8 *st = D_L23_001E1AC0;

            *(s32 *)(st + 0x28) = 60;
            *(f32 *)(st + 0x20) = 0.25f;
            self->x23 = 0;
            self->x34 = (self->x34 & 0xFEFF) | 0x2800;
            self->xF8 = func_U_00423668();
            self->x7C = 0;
            self->x34 &= 0xFFBE;
            self->pos.z = v->x8 + self->scale / self->cls->x24 * 0.094f;
            self->scale *= D_L23_002BC878[v->x20].xC;
            if (v->x1C != -1) {
                q = D_001A30B0 + (v->x1C << 7);
                if (*(void **)(q + 0xDC) == self && q[0xD0] != 0)
                    func_U_004887D0(v->x1C);
            }
            v->x1C = -1;
            if (v->x4 >= 0) {
                p = D_L23_001D676C[v->x4];
                while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D676C[v->x4])) {
                    u8 *ent = D_L23_001DFF88 + ((*p & 0x7FFF) << 5);

                    if (ent == 0)
                        break;
                    ent[0x16] |= 1;
                    p++;
                }
            }
            p = D_L23_001D6764[v->id];
            while (p != 0 && ((s16)p[-1] >= 0 || p == D_L23_001D6764[v->id])) {
                u8 *ent = D_L23_001E0094 + ((*p & 0x7FFF) << 5);

                if (ent == 0)
                    break;
                ent[0x1E] |= 4;
                p++;
            }
        }
        t = (f32)self->timer / 60.0f;
        t = 1.0f < t ? 1.0f : t;
        n = func_U_00427B60(0, 0x80, t);
        self->x23 = n;
        sc = self->scale * 0.5f / self->cls->x24;
        if ((s8)n >= 0) {
            for (i3b = 0; i3b < 3; i3b++) {
                a = self->pos;
                a.x += func_U_004235B0(-sc, sc) * 0.8f;
                a.y += func_U_004235B0(-sc, sc) * 0.8f;
                a.z = v->x8;
                vec_sub_ab(&b, &a, &self->pos);
                b.z = func_U_004235B0(1.0f, 4.0f * sc);
                func_U_003EEFC8(&b, &b, func_U_004235B0(0.016666668f, 0.13333334f) * 2.0f);
                qzero(&c);
                b.w = 0.5f;
                c.w = func_U_004235B0(1.5f, 3.0f);
                func_U_00441630(&a, &b, &c, func_U_003EFEF8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0())), 0x40606060, 1, (func_U_00423538(0x14) + 0x1E), (func_U_00423538(0xA) + 0x1E), -1);
            }
        }
        a = self->pos;
        a.x += func_U_004235B0(-sc, sc) * 0.5f;
        a.y += func_U_004235B0(-sc, sc) * 0.5f;
        a.z = v->x8;
        vec_sub_ab(&b, &self->pos, &a);
        func_U_003EED68(&b, &b, 1.0f / 60.0f);
        b.z = func_U_004235B0(0.016666668f, 0.13333334f);
        qzero(&c);
        b.w = 0.5f;
        c.z = b.z;
        c.w = func_U_004235B0(1.5f, 3.0f);
        func_U_00441630(&a, &b, &c, func_U_003EFEF8(0x80202020, 0x80707070, (f32)(func_0013D3E0() * func_0013D3E0())), 0x40606060, 1, (func_U_00423538(0x14) + 0x1E), (func_U_00423538(0xA) + 0x1E), -1);
        if (self->timer >= 0xC9)
            self->x34 = (self->x34 & 0xD7FF) | 2;
        t3 = (f32)self->timer / 120.0f;
        t3 = 1.0f < t3 ? 1.0f : t3;
        v->x2C = func_U_00427B60(0x70, 0, t3);
        func_U_003E5670(func_U_003A8490, (u8 *)self);
        break;
    }
    self->timer++;
}
/* localdecomp:end func_U_L23_003A6870 */
