#include "common.h"
#include "vu0.h"

/* types of func_L20_003CFBF0, from upstream's L20_003CE2D0.c */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003CFBF0 */
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
extern f32 D_L20_001DF168;
__asm__(".extern D_L20_001DF168, 4");
extern f32 D_L20_001DEB90;
__asm__(".extern D_L20_001DEB90, 4");
extern s32 D_L20_001DEB88;
__asm__(".extern D_L20_001DEB88, 4");
extern s32 D_L20_001DEB8C;
__asm__(".extern D_L20_001DEB8C, 4");
extern f32 D_L20_001DEB94;
__asm__(".extern D_L20_001DEB94, 4");
extern f32 D_L20_001DEB98;
__asm__(".extern D_L20_001DEB98, 4");
extern f32 D_L20_001DEB9C;
__asm__(".extern D_L20_001DEB9C, 4");
extern u32 D_L20_001DEBA0;
__asm__(".extern D_L20_001DEBA0, 4");
extern u32 D_L20_001DEBA4;
__asm__(".extern D_L20_001DEBA4, 4");
extern f32 D_L20_001DF220;
__asm__(".extern D_L20_001DF220, 4");
extern s32 D_L20_001DF218;
__asm__(".extern D_L20_001DF218, 4");
extern s32 D_L20_001DF21C;
__asm__(".extern D_L20_001DF21C, 4");
extern f32 D_L20_001DF224;
__asm__(".extern D_L20_001DF224, 4");
extern f32 D_L20_001DF228;
__asm__(".extern D_L20_001DF228, 4");
extern f32 D_L20_001DF22C;
__asm__(".extern D_L20_001DF22C, 4");
extern u32 D_L20_001DF230;
__asm__(".extern D_L20_001DF230, 4");
extern u32 D_L20_001DF234;
__asm__(".extern D_L20_001DF234, 4");
extern u8 D_L20_001E2E00[];
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *v, s32 id, u32 col, s32 e, f32 a, f32 b, f32 c);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3, f32 e, f32 f, f32 g);
extern f32 D_L20_001DF23C;
__asm__(".extern D_L20_001DF23C, 4");
extern f32 D_L20_001DF240;
__asm__(".extern D_L20_001DF240, 4");
extern s32 D_L20_001D66B0;
__asm__(".extern D_L20_001D66B0, 16");
extern void func_L01_00404808(void (*)(void *), void *);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003824E0(f32, f32);

void func_L20_003CFBF0(u8 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 e[4] __attribute__((aligned(16)));
    f32 g[4] __attribute__((aligned(16)));
    u8 *p;
    s32 col;
    s32 i;
    f32 nb;
    f32 pf;
    p = *(u8 **)(a0 + 0x68);
    col = func_0038DBD8(D_L20_001DEB88, D_L20_001DEB8C, func_0038D0B0(D_L20_001DEB90) * 0.5f + 0.5f);
    nb = func_0038DAB8(D_L20_001DEB90, func_003824E0(D_L20_001DEB94, D_L20_001DEB98) * 0.017453292f * 0.020000001f);
    pf = *(f32 *)p;
    D_L20_001DEB90 = nb;
    func_003D9508(a0 + 0x10, 0x43, col, 1, 2.25f, -0.1f, pf);
    func_003D9508(a0 + 0x10, 0x31, 0x7FFFFFFF, 1, 1.0f, 0.0f, -*(f32 *)(p + 4));
    func_003D9508(a0 + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -*(f32 *)p);
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, a0 + 0x10);
        func_0038D890(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, d, *(f32 *)(p + 0xD10 + i * 4));
        *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) + 0.03f;
        if (*(f32 *)(p + 0x2C) > 2.5f) {
            *(f32 *)(p + 0x2C) = 2.5f;
        }
        func_0038CF68(p + 0xC50 + i * 0x10, p + 0xC50 + i * 0x10, *(f32 *)(p + 0x2C));
        vec_add_ab(e, p + 0xC50 + i * 0x10, a0 + 0x10);
        *(u128_t *)g = *(u128_t *)(a0 + 0x10);
        func_L01_0040A8C0((u128_t *)e, (u128_t *)g, 0x12, 1, D_L20_001DEBA0, D_L20_001DEBA0, D_L20_001DEBA4, D_L20_001DEBA4, D_L20_001DEB9C, 3.0f, *(f32 *)(p + 0xD40));
    }
    *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) - func_003824E0(0.025f, 0.035f);
    if (*(f32 *)(p + 0xD40) <= -8.0f) {
        *(f32 *)(p + 0xD40) = *(f32 *)(p + 0xD40) + 8.0f;
    }
}
/* localdecomp:end func_L20_003CFBF0 */

/* localdecomp:start func_L20_003CFE80 */
#include "vu0.h"

extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern vu0_v4 D_001A4CB0;
extern s32 D_L20_001DFD40;
extern s32 D_L20_001DEBA8; __asm__(".extern D_L20_001DEBA8, 4");
extern u8 *D_L20_001E9BD8[];
extern vu0_v4 D_L20_001E9BE0;

typedef struct {
    u8 pad0[0xD40];
    f32 fD40;
    u8 padD44[4];
    f32 fD48;
    f32 fD4C;
    vu0_v4 vD50;
    vu0_v4 vD60;
} S_003CFE80;

void func_L20_003CFE80(u8 *self) {
    S_003CFE80 *p;
    vu0_v4 pos;
    vu0_v4 r;
    vu0_v4 d;
    vu0_v4 e;
    vu0_q qc;
    vu0_q qp;
    s32 hit;
    u8 *o;

    p = *(S_003CFE80 **)(self + 0x68);
    __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(D_001A4CB0));
    pos = *(vu0_v4 *)(self + 0x10);
    vec_sub_ba(&d, &p->vD50, &pos);
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(qp) : "j"(qc), "j"(qp));
    __asm__("sqc2 %1, %0" : "=m"(e) : "j"(qp));
    if (D_L20_001DFD40 != D_L20_001DEBA8) {
        func_L01_0044C280(&d, &d, &e, 0, 0.06f);
    }
    D_L20_001DEBA8 = D_L20_001DFD40;
    func_0038CF68(&d, &d, p->fD48 * 60.0f);
    __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(d));
    __asm__("lqc2 %0, %1" : "=j"(qc) : "m"(pos));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qp) : "j"(qp), "j"(qc));
    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qp));
    func_L01_004CB320();
    hit = func_003D3CB0(&pos, &d, 2, self, 0);
    if (hit != 0) {
        o = D_L20_001E9BD8[0];
        if (o != 0 && *(s16 *)(o + 0xAA) == 0x186D && o[0x20] != 2 && o[0x20] != 5) {
            o[0x20] = 4;
        }
    }
    func_L01_004CB358();
    if (hit != 0) {
        r = D_L20_001E9BE0;
        p->vD50 = r;
    } else {
        r = d;
        p->vD50 = r;
    }
    func_L01_0040A8C0((u128_t *)&pos, (u128_t *)&r, 0xE, 0, 0x4F802060, 0x4F802060, 0x4F802060, 0x4F802060, p->fD4C, 1.0f, p->fD40);
    func_L01_0040A8C0((u128_t *)&pos, (u128_t *)&r, 0xE, 3, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, p->fD4C * 0.5f, 1.0f, -p->fD40);
    p->vD60 = r;
}
/* localdecomp:end func_L20_003CFE80 */

/* localdecomp:start func_L20_003D0090 */
#include "vu0.h"

extern u8 D_001A30B0[];
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern vu0_v4 D_001A4CB0;
extern u8 D_00220258[];
extern s32 D_L20_001DEB7C;
__asm__(".extern D_L20_001DEB7C, 4");

extern s32 func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_003A4F28(s32);
extern void func_003C2880(void *);
extern f32 func_0038DAB8(f32, f32);
extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_00382538(void);
extern s32 func_0038CB00(void *);
extern void func_L01_00404808(void (*)(void *), void *);
extern void func_00382580(void *, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_L03_00433C70(void *, void *, void *, s32, s32, s32, s32, f32, f32);
extern u8 *func_L01_004735F0(void *, void *, s32, f32);
extern void func_L01_00404A10(void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L20_003CE4F8(u8 *);
extern void func_L20_003CEEB0(u8 *);
extern void func_L20_003CFE80(u8 *);
extern void func_L20_003CFBF0(u8 *a0);
extern void func_L20_003CF108(u8 *);
extern void func_L20_003CFB08(u8 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);

void func_L20_003D0090(u8 *obj)
{
    u8 *v;
    s32 h;
    u8 *e;
    s32 i;
    s32 i2;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    (*(u16 *)(obj + 0x96))++;
    v = *(u8 **)(obj + 0x68);
    {
        s32 t = *(s32 *)(v + 0xD70);
        if (t == -1 || (e = D_001A30B0 + (t << 7), *(u8 **)(e + 0xDC) != obj) || e[0xD0] == 0) {
            *(s32 *)(v + 0xD70) = func_L01_004AAC98(0xB, 4, obj, 0x1AFD);
        }
    }
    if (*(u16 *)(obj + 0x96) > 300 && D_001D545C != 0x45) {
        h = *(s32 *)(v + 0xD70);
        if (h != -1) {
            e = D_001A30B0 + (h << 7);
            if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) {
                func_003A4F28(h);
            }
        }
        *(s32 *)(v + 0xD70) = -1;
        if (*(u8 **)(v + 0xD74) != 0) {
            func_003C2880(*(u8 **)(v + 0xD74));
        }
        func_003C2880(obj);
        return;
    }

    *(f32 *)(v + 0x0) = func_0038DAB8(*(f32 *)(v + 0x0), 0.0349065885f);
    *(f32 *)(v + 0x4) = func_0038DAB8(*(f32 *)(v + 0x4), 0.104719758f);

    switch (obj[0x20]) {
    case 0: {
        u8 *p;
        vu0_v4 *pv;
        s32 j;

        p = func_003C24B0(0x1DA0, 0x40);
        *(u8 **)(v + 0xD74) = p;
        if (p != 0) {
            *(vu0_q *)(p + 0xF0) = *(vu0_q *)(obj + 0xF0);
            *(vu0_q *)(*(u8 **)(v + 0xD74) + 0x10) = *(vu0_q *)(obj + 0x10);
            (*(u8 **)(v + 0xD74))[0x30] = 0xFF;
            *(u8 **)(*(u8 **)(v + 0xD74) + 0xB8) = obj;
        }
        *(vu0_v4 *)(v + 0xD50) = D_001A4CB0;
        vec_sub_ba(&a, obj + 0x10, &D_001A4CB0);
        func_0038CF68(&a, &a, -25.0f);
        vec_add_ab(v + 0xD50, &a, v + 0xD50);
        for (j = 0; j < 12; j++) {
            ((f32 *)(v + 0xD10))[j] = func_003824E0(0.0174532942f, 0.052359879f);
            *(f32 *)(v + 0x2C) = 2.0f;
            b.x = func_0038D098(*(f32 *)(obj + 0xF8));
            b.y = func_0038D0B0(*(f32 *)(obj + 0xF8));
            b.z = 0.0f;
            vec_sub_ba(&c, &D_L20_001E2E00, obj + 0x10);
            func_0038CF68(&c, &c, 1.0f);
            pv = (vu0_v4 *)(v + 0xC50) + j;
            func_0038CE90(pv, &b, &c);
            func_0038CF68(pv, pv, *(f32 *)(v + 0x2C));
            func_0038D890(pv, pv, &c, func_00382538());
        }
        func_L20_003CE4F8(obj);
        *(s16 *)(v + 0x20) = (*(s32 *)(v + 0x1C) * 5 + 2) / 6;
        obj[0x20] = 2;
        *(f32 *)(v + 0xC) = 2.5f;
        *(s16 *)(v + 0x18) = 1;
        *(s16 *)(v + 0x1A) = 1;
        break;
    }
    case 2:
        if (func_0038CB00(v + 0x20)) {
            obj[0x20] = 3;
            *(s16 *)(v + 0x20) = (*(s16 *)(v + 0x14) * 5 + 2) / 6;
            func_L20_003CE4F8(obj);
        }
        break;
    case 3:
        if (func_0038CB00(v + 0x20)) {
            if (*(s16 *)(v + 0x16) != 0) {
                obj[0x20] = 2;
                *(s16 *)(v + 0x20) = 4;
            } else {
                *(s16 *)(v + 0x20) = 4;
            }
        } else if (*(s16 *)(v + 0x22) == 0) {
            func_L20_003CE4F8(obj);
        }
        break;
    }

    switch (obj[0x95]) {
    case 0:
        if (*(u16 *)(obj + 0x96) > 2) {
            obj[0x95] = 2;
            *(vu0_q *)(v + 0xD60) = *(vu0_q *)(obj + 0x10);
            *(vu0_v4 *)(v + 0xD50) = D_001A4CB0;
            vec_sub_ba(&a, obj + 0x10, &D_001A4CB0);
            a.z = 0.0f;
            func_0038CF68(&a, &a, 25.0f);
            vec_add_ab(v + 0xD50, &a, v + 0xD50);
        }
        break;
    case 2: {
        s32 k;
        s32 n;
        u8 *p;

        func_L01_00404808(func_L20_003CFE80, obj);
        *(f32 *)(v + 0xD4C) += 0.200000018f;
        *(f32 *)(v + 0xD44) = 1.0f;
        if (*(f32 *)(v + 0xD4C) > 1.0f) {
            *(f32 *)(v + 0xD4C) = 1.0f;
        }
        *(f32 *)(v + 0xD48) += 0.0400000028f;
        if (*(f32 *)(v + 0xD48) > 1.0f) {
            *(f32 *)(v + 0xD48) = 1.0f;
        }
        for (k = 0; k < 3; k++) {
            u8 *g = D_00220258;

            func_00382580(&a, 0.0600000024f, 0.0800000057f);
            if (a.z < 0.0f) {
                a.z = -a.z;
            }
            n = func_L01_00443A18(2.0f, 3.0f);
            p = func_L01_004713C8(v + 0xD60, &a, 0x11, 0, n, 0x7F, 0x7F, func_003824E0(0.8f, 1.25f) * 210000.0f, 2100.0f, 0.0f, 6);
            if (p != 0) {
                p[3] = 0x44;
                p[2] = **(u8 **)(g + 0xD4);
            }
            n = func_L01_00443A18(2.0f, 3.0f);
            p = func_L01_004713C8(v + 0xD60, &a, 0x11, 0x7C0030, n, 0x30, 0x30, func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f, 4200.0f, 0.0f, 0);
            if (p != 0) {
                p[3] = 0x44;
                p[2] = **(u8 **)(g + 0xD4);
            }
        }
        func_L03_00433C70(obj, obj + 0x10, v + 0xD60, 1, 0, 1, 0, 45.0f, 1.0f);
        break;
    }
    }

    for (i = 0; i < 1; i++) {
        u8 *p;

        func_00382580(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, obj + 0x10);
        vec_sub_ba(&b, obj + 0x10, &a);
        func_0038CF68(&b, &b, 0.0150000006f);
        p = func_L01_004735F0(&a, &b, 0xC, 3.0f);
        if (p != 0) {
            *(u32 *)(p + 4) = 0xFFFF2020;
        }
    }
    for (i2 = 0; i2 < 1; i2++) {
        u8 *p;

        func_00382580(&a, 0.025f, 0.15f);
        vec_add_ba(&a, &a, obj + 0x10);
        vec_sub_ba(&b, obj + 0x10, &a);
        func_0038CF68(&b, &b, 0.0150000006f);
        p = func_L01_004735F0(&a, &b, 0xC, 1.5f);
        if (p != 0) {
            *(u32 *)(p + 4) = 0x7FFFFFFF;
        }
    }

    func_L01_00404A10(func_L20_003CFB08, obj);
    func_L01_00404A10(func_L20_003CFBF0, obj);
    if (*(s16 *)(v + 0x22) != 0) {
        func_L20_003CEEB0(obj);
        if (D_L20_001DEB7C < *(s16 *)(v + 0x22)) {
            func_L01_00404A10(func_L20_003CF108, obj);
        }
    }
    if (*(u8 **)(v + 0xD74) != 0) {
        vec_sub_ba(&c, v + 0xD50, obj + 0x10);
        *(f32 *)(*(u8 **)(v + 0xD74) + 0xF4) = -func_0038D160(func_0038CED8(&c), c.z);
        *(f32 *)(*(u8 **)(v + 0xD74) + 0xF8) = func_0038D160(c.x, c.y);
    }
}
/* localdecomp:end func_L20_003D0090 */

/* localdecomp:start func_L20_003D0910 */
/* func_L20_003D0910: the final boss's per-frame update on level 20 (Dr. Nefarious' arena; the moby
   with pvars at m+0x68): a switch on its mode (m+0x95) then one on its state (m+0x20: 2-34), then
   the 0x618/0x67C child updates. States 16, 23 and 29 are three copies of one charge/burst routine
   (light, 20-particle ring, sparks, 300-particle blast) with their own bones and constants. */
typedef union Mo_ { long d[0x20]; u8 b[0x100]; s8 c[0x100]; s16 h[0x80]; u16 uh[0x80]; s32 i[0x40]; u32 u[0x40]; f32 f[0x40]; void *p[0x40]; union Pv_ *pv[0x40]; union Mo_ *mp[0x40]; u128_t q[0x10]; } Mo;
typedef union Pv_ { u8 b[0x800]; s8 c[0x800]; s16 h[0x400]; u16 uh[0x400]; s32 i[0x200]; u32 u[0x200]; f32 f[0x200]; void *p[0x200]; Mo *mp[0x200]; f32 *fp[0x200]; u128_t q[0x80]; } Pv;
typedef union { u8 b[0x2900]; s32 i[0xA40]; f32 f[0xA40]; u128_t q[0x290]; } Hero;
typedef struct { u8 x0[0x30]; u128_t pos; u8 x40[0x30]; u128_t x70; } Spot;

typedef struct { f32 r, g, b; s32 on; union { u128_t pos; struct { f32 x, y, z, w; } v; } u; } Light;
typedef struct { u8 x0[0x20]; f32 x20; u8 x24[4]; s32 x28; s32 x2C; u8 x30[0x10]; f32 x40; u8 x44[4]; s32 x48; u8 x4C[0xF8]; Mo *x144; s32 x148; } Boss;
typedef struct { u8 x0[0x20]; u8 *x20[0x80]; } Pal;

extern s32 func_L20_003D61B8(Mo *);
extern s32 func_L20_003D6AE0(Mo *);
extern s32 func_L20_003D6B78(Mo *);
extern void func_L20_003D6BF8(Mo *);
extern void func_L20_003D6D18(Mo *);
extern u8 *func_L20_003E56D8(Mo *, u128_t *, u128_t *, s32, s32);
extern u8 *func_L20_003EAA70(Mo *, u8 *, u128_t *);
extern u8 *func_L20_003F9C10(Mo *, u128_t *, u128_t *, f32);
extern void func_L20_003D6F30(void);
extern void func_L20_003D7558(void);
extern void func_L20_003D7950(void);
extern void func_L20_003D8248(void);
extern f32 *func_L01_003F2A50(s32, s32);
extern void func_L01_00404808_003D0910(void *, Mo *);
extern void func_L01_00404A10_003D0910(void *, Mo *);
extern s32 fe_func_0038CAD0(u8 *);
extern s32 fe_func_0038CB00_003D0910(u8 *);
extern void fe_func_0038CE20(void *, void *, f32);
extern f32 fe_func_0038CED8_003D0910(u128_t *);
extern f32 fe_func_0038CF38(void *, void *);
extern void fe_func_0038CF68_003D0910(u128_t *, void *, f32);
extern f32 fe_func_0038D098(f32);
extern f32 fe_func_0038D0B0(f32);
extern f32 fe_func_0038D160(f32, f32);
extern void fe_func_0038D850(void *, void *, void *);
extern void fe_func_0038D890(void *, void *, void *, f32);
extern f32 fe_func_0038DAB8(f32, f32);
extern f32 fe_func_0038DB00(f32, f32);
extern f32 fe_func_0038DBA0(f32, f32);
extern s32 fe_func_00392B20(u8 *, s32);
extern s32 fe_func_00392C78(u8 *);
extern s32 func_L01_00424CB0(void *, f32, f32, f32, f32, f32);
extern void func_L01_00424D88(s32);
extern Mo *fe_func_003C24B0_003D0910(s32, s32);
extern void fe_func_003C2880_003D0910(Mo *);
extern f32 func_L01_004395E0(Mo *);
extern void fe_func_003C2EC0(Mo *, s32, u128_t *);
extern void fe_func_003C2F58(Mo *, s32, u128_t *);
extern void fe_func_003C7C38(Mo *);
extern s32 fe_func_00382380(void *, s32, s32);
extern s32 fe_func_00382468(s32);
extern s32 fe_func_00382498(s32, s32);
extern f32 fe_func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 fe_func_00382538(void);
extern void fe_func_00382580(void *, f32, f32);
extern void fe_func_003C3938(Mo *, s32, s32);
extern void fe_func_003C3A10(Mo *, s32, s32, s32);
extern void func_L01_004450F0(Mo *, s32, s32);
extern f32 fe_func_003C3D30(u8 *, s32, s32, f32);
extern s32 func_L01_004468C8(f32, f32, f32, Mo *, s32, s32, s32, s32, s32);
extern f32 func_L01_00447878(void *, void *, void *, f32, f32);
extern f32 fe_func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void fe_func_003C4840(void *, void *, f32);
extern s32 func_L01_0044E1B8(Mo *, f32);
extern s32 func_L01_00454370(Mo *, u8 *);
extern void func_L01_00456160(Mo *, Mo *);
extern s32 func_L01_004561B8(Mo *);
extern s32 func_L01_004561E0(Mo *);
extern void func_L01_00456230(Mo *, s32);
extern s32 func_L01_0045A748(Mo *, void *);
extern s32 func_L02_00431568(Mo *, void *, f32, f32, f32, f32, s32);
extern s32 func_L01_0045AA30(Mo *, u128_t *);
extern s32 func_L01_0045BD10(Mo *, f32);
extern void func_L01_0045BD78(Mo *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Mo *, s32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern u8 *func_L01_0046A610(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);
extern u8 *func_L01_004713C8_003D0910(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern void func_L01_004AA7E8(Mo *, s32);
extern void fe_func_003A4F28(s32);
extern s32 fe_func_003A52A0(s32, s32, Mo *);
extern s32 func_L01_004AAC98_003D0910(s32, s32, Mo *, s32);
extern s32 func_L01_004BA800(void);
extern void func_L01_004F50C8(void *, void *, s32, s32);

extern u8 D_L20_001D66B0_003D0910[8];
extern s32 D_L20_001D6694;
extern s32 D_L20_001D67A8;
extern s32 D_L20_001D67A8_d;
extern s32 D_L20_001DEBEC;
extern s32 D_L20_001DEBF0;
extern s32 D_L20_001DEBF4;
extern f32 D_L20_001DEBBC;
extern f32 D_L20_001DEBC0;
extern f32 D_L20_001DEBC4;
extern f32 D_L20_001DEBC8;
extern f32 D_L20_001DEBCC;
extern f32 D_L20_001DEBD0;
extern f32 D_L20_001DEBD4;
extern f32 D_L20_001DEBD8;
extern f32 D_L20_001DEBDC;
extern f32 D_L20_001DEBE0;
extern f32 D_L20_001DEBE4;
extern f32 D_L20_001DEBE8;
extern s32 D_L20_001DFD40;
extern s32 D_L20_001DFD40_d;
extern Mo *D_L20_001E029C_d;
extern Spot *D_L20_001E0380;
extern Spot *D_L20_001E0380_d;
extern s32 D_L20_001E2698;
extern s32 D_L20_001E2698_d;
extern Boss D_L20_001E2E80_003D0910;
extern u8 D_L20_001E9980[];
extern Light D_L20_001F0D00[];
extern void *D_L20_0021E880[];
extern u8 *D_L20_00220258[];
extern u8 D_001A30B0[];
extern char D_001A4BE0[];
extern s32 D_00142C58[];


__asm__(".extern D_L20_001D6694, 4");
__asm__(".extern D_L20_001D67A8, 4");
__asm__(".extern D_L20_001DEBEC, 4");
__asm__(".extern D_L20_001DEBF0, 4");
__asm__(".extern D_L20_001DEBF4, 4");
__asm__(".extern D_L20_001DEBBC, 4");
__asm__(".extern D_L20_001DEBC0, 4");
__asm__(".extern D_L20_001DEBC4, 4");
__asm__(".extern D_L20_001DEBC8, 4");
__asm__(".extern D_L20_001DEBCC, 4");
__asm__(".extern D_L20_001DEBD0, 4");
__asm__(".extern D_L20_001DEBD4, 4");
__asm__(".extern D_L20_001DEBD8, 4");
__asm__(".extern D_L20_001DEBDC, 4");
__asm__(".extern D_L20_001DEBE0, 4");
__asm__(".extern D_L20_001DEBE4, 4");
__asm__(".extern D_L20_001DEBE8, 4");
__asm__(".extern D_L20_001E2698, 4");
__asm__(".extern D_L20_001DFD40, 4");
__asm__(".extern D_L20_001E0380, 4");

static __inline__ f32 fe_speed(f32 x) { return x / 20.0f; }

void func_L20_003D0910(Mo *m) {
    Pv *pv;
    f32 sp0[4] __attribute__((aligned(16)));
    f32 sp10[4] __attribute__((aligned(16)));
    f32 sp20[4] __attribute__((aligned(16)));
    f32 sp30[4] __attribute__((aligned(16)));
    f32 sp40[4] __attribute__((aligned(16)));
    f32 sp50[4] __attribute__((aligned(16)));
    f32 sp60[4] __attribute__((aligned(16)));
    f32 sp70[4] __attribute__((aligned(16)));
    f32 sp80[4] __attribute__((aligned(16)));
    f32 sp90[4] __attribute__((aligned(16)));
    f32 spA0[4] __attribute__((aligned(16)));

    pv = m->pv[0x68/4];
    if ((pv->mp[0x618/4] != 0) && (m->b[0x20] != 0x1B)) {
        pv->mp[0x618/4]->i[0x98/4] = pv->mp[0x618/4]->mp[0x24/4]->i[0x10/4];
        fe_func_003C7C38(pv->mp[0x618/4]);
    }
    if ((pv->mp[0x67C/4] != 0) && (m->b[0x20] != 0x1B)) {
        pv->mp[0x67C/4]->i[0x98/4] = pv->mp[0x67C/4]->mp[0x24/4]->i[0x10/4];
        fe_func_003C7C38(pv->mp[0x67C/4]);
    }
    if (func_L20_003D61B8(m) != 0) {
        fe_func_003C2880_003D0910(m);
        return;
    }
    if (D_L20_001D6694 == 2) {
        m->i[0x98/4] = 0;
        m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
        func_L01_004AA7E8(m, 1);
        if (pv->mp[0x2F8/4] != 0) {
            pv->mp[0x2F8/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2F8/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2F8/4], 1);
        }
        if (pv->mp[0x2FC/4] != 0) {
            pv->mp[0x2FC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2FC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2FC/4], 1);
        }
    } else {
        Mo *c = m->mp[0x24/4];
        m->uh[0x34/2] &= 0xFFBE;
        m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
        m->i[0x98/4] = c->i[0x10/4];
    }
    switch (m->b[0x95]) {
    case 5:
        if (func_L01_004BA800() == 0) {
            f32 *v = (f32 *)&sp0;
            v[2] = 203.97f;
            v[1] = 152.22f;
            v[0] = 267.92f;
            func_L01_004F50C8(&sp0, D_001A4BE0 + 0x90, 0, 1);
            {
            Mo *c = m->mp[0x24/4];
            m->uh[0x34/2] &= 0xFFBE;
            m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
            m->i[0x98/4] = c->i[0x10/4];
            }
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            func_L01_004450F0(m, 7, 2);
        }
        break;
    case 7:
        if ((pv->i[0x638/4] != 0) && (func_L01_004BA800() == 0)) {
            Spot *s;
            void **t;
            {
            Mo *c = m->mp[0x24/4];
            m->uh[0x34/2] &= 0xFFBE;
            m->uh[0x34/2] |= c->uh[0x44/2] & 0x1000;
            m->i[0x98/4] = c->i[0x10/4];
            }
            s = &D_L20_001E0380_d[pv->i[0x65C/4]];
            func_L01_004F50C8(&s->pos, &s->x70, 0, 1);
            D_L20_001DEBF4 = 1;
            func_L01_004450F0(m, 0x1B, 2);
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, 2);
            }
            t = &D_L20_0021E880[pv->i[0x63C/4]];
            m->q[0x10/16] = ((Mo *)*t)->q[0x10/16];
            fe_func_003C3938(m, 0xB, 0);
        }
        break;
    case 6:
        if (func_L01_004BA800() == 0) {
            func_L20_003D6BF8(m);
            fe_func_003C2880_003D0910(m);
            return;
        }
        break;
    case 0:
        if (func_L01_004561E0(m) != 0) {
            pv->h[0x2D6/2] = 0;
        }
        if ((pv->h[0x234/2] == 1) && (fe_func_0038CB00_003D0910(pv->b + 0x2D6) != 0)) {
            if (D_L20_001E2E80_003D0910.x144 == 0) {
                D_L20_001E2E80_003D0910.x144 = m;
                D_L20_001E2E80_003D0910.x148 = 0;
            }
            func_L01_004450F0(m, 7, 2);
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            if (!(D_00142C58[0] & 0x2000000)) {
                func_L01_004450F0(m, 4, 2);
                if (m->b[0x43] != 8) {
                    fe_func_003C3A10(m, 8, 0, 8);
                }
            }
        }
        if (fe_func_00382380(D_001A4BE0 + 0x80, pv->i[0x654/4], 0) != 0) {
            D_L20_001DEBEC = 1;
            D_L20_001DEBF0 = 1;
            D_L20_001DEBF4 = 1;
            func_L20_003D6BF8(m);
            fe_func_003C2880_003D0910(m);
            return;
        }
        break;
    case 1:
        if (pv->h[0x234/2] == 1) {
            func_L01_004450F0(m, 7, 2);
        } else if (pv->i[0x2D0/4] == 0) {
            func_L01_004450F0(m, 2, 0);
        }
        break;
    case 2:
        {
        s32 n;
        if (func_L01_004561E0(m) != 0) {
            D_L20_001E2698_d = D_L20_001D67A8;
        }
        n = D_L20_001E2698;
        if (pv->i[0x648/4] == 0) {
            f32 *p = func_L01_003F2A50(0, 5);
            pv->fp[0x644/4] = p;
            pv->i[0x648/4] = 1;
            p[0] = 7.0f;
            pv->fp[0x644/4][1] = 3.0f;
            n = D_L20_001E2698_d;
        }
        if ((n == D_L20_001D67A8_d) && (((Hero *)D_001A4BE0)->i[0x2850/4] <= 0)) {
            D_L20_001D67A8_d = n + 1;
        }
        if ((pv->h[0x234/2] != 1) && (func_L01_004561E0(m) == 0)) {
            pv->i[0x2D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
        }
        }
        break;
    case 3:
        {
        s32 r = func_L01_00454370(m, pv->b + 0x160);
        if (r & 1) {
            if (D_L20_001E2E80_003D0910.x144 == m) {
                D_L20_001E2E80_003D0910.x144 = 0;
            }
            m->i[0x98/4] = 0;
            m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            func_L01_004450F0(m, 2, 6);
            if (fe_func_00392B20(D_L20_001E9980, 0xBB) != 0) {
                m->i[0x98/4] = 0;
                m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(m, 1);
                func_L01_004450F0(m, 2, 6);
                fe_func_00392C78(D_L20_001E9980);
            }
            return;
        }
        if (r & 2) {
            if (pv->h[0x234/2] == 1) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 8);
                }
                func_L01_004450F0(m, 7, 2);
                if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) <= 18.0f) {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 5);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else {
                func_L01_004450F0(m, 3, 1);
                pv->i[0x2D0/4] = (fe_func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        }
        break;
    case 4:
        break;
    }
    switch (m->b[0x20]) {
    case 2:
    case 3:
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC8 * 0.00040000002f, D_L20_001DEBC4 * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(m, D_001A4BE0 + 0x80);
        if ((m->uh[0x96/2] >= 0x1A) && (fe_func_00392B20(D_L20_001E9980, 0xB9) != 0)) {
            func_L01_004450F0(m, 2, 5);
            fe_func_00392C78(D_L20_001E9980);
        }
        break;
    case 5:
        {
        f32 f;
        f32 t5; f32 den = 20.0f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 5) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            t5 = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, t5, 0.060000002f, 0.060000002f, 0.40000004f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68_003D0910(sp10, m->b + 0xD0, -(3.5f / den));
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        }
        break;
    case 32:
        {
        f32 f;
        f32 t5; f32 den = 20.0f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 5) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            t5 = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, t5, 0.040000003f, 0.060000002f, 0.3f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68_003D0910(sp10, m->b + 0xD0, -(7.0f / den));
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            if (pv->i[0x670/4] == 0xA) {
                if (m->b[0x43] != 0xE) {
                    fe_func_003C3A10(m, 0xE, 0, 7);
                }
                func_L01_004450F0(m, 8, -1);
            } else {
                func_L01_004450F0(m, 0x15, -1);
                if (m->b[0x43] != 0x23) {
                    fe_func_003C3A10(m, 0x23, 0, 0xF);
                }
            }
        }
        }
        break;
    case 6:
        {
        f32 f;
        f32 t5; f32 den = 20.0f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->q[0x5D0/16] = m->q[0x10/16];
        }
        if (m->b[0x42] != 7) {
            break;
        }
        if (pv->i[0x5C8/4] != 0) {
            if (func_L20_003D6AE0(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2F8/4], 0, sp0);
                vec_sub_ba(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
            if (func_L20_003D6B78(m) != 0) {
                fe_func_003C2F58(pv->mp[0x2FC/4], 0, sp0);
                vec_sub_ab(sp10, D_001A4BE0 + 0xD0, sp0);
                func_L20_003E56D8(m, sp0, sp10, pv->b[0x45], 1);
            }
        }
        f = func_L01_004395E0(m);
        *(u128_t *)sp0 = m->q[0x10/16];
        if ((f > 115.0f) && (f < 124.0f)) {
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, pv->f[0x5D8/4] + 10.0f, 0.032f, 0.036000002f, 0.20000002f);
        } else if ((f > 124.0f) && (f < 135.0f)) {
            t5 = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            fe_func_003C41A0(sp0 + 2, pv->b + 0x5C0, t5, 0.040000003f, 0.060000002f, 0.3f);
        } else {
            pv->i[0x5C0/4] = 0;
        }
        if ((f > 115.0f) && (f < 135.0f)) {
            fe_func_0038CF68_003D0910(sp10, m->b + 0xD0, 3.5f / den);
            vec_add_ba(sp0, sp0, sp10);
            vec_sub_ba(sp10, sp0, m->b + 0x10);
            func_L01_0045AA30(m, sp10);
        } else {
            f32 g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if (g < m->f[0x18/4]) {
                m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
                if (m->f[0x18/4] < g) {
                    m->f[0x18/4] = g;
                }
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC0 * 0.00040000002f, D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        func_L01_0045A748(m, D_001A4BE0 + 0x80);
        if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) <= 16.0f) {
            if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4])) < 0.2617994f) {
                if (m->b[0x43] != 0xE) {
                    fe_func_003C3A10(m, 0xE, 0, 8);
                }
                func_L01_004450F0(m, 8, -1);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->p[0x300/4] = 0;
            pv->p[0x304/4] = 0;
            pv->p[0x308/4] = 0;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0xF) {
                fe_func_003C3A10(m, 0xF, 0, 1);
            }
            func_L01_004450F0(m, 9, -1);
        }
        if ((func_L01_0044E1B8(m, 120.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] >= 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68_003D0910(sp0, m->b + 0xD0, 2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x300/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x300/4], m);
            pv->mp[0x300/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x300/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] >= 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68_003D0910(sp0, m->b + 0xD0, -2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x304/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x304/4], m);
            pv->mp[0x304/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x304/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 115.0f) != 0) && (m->b[0x42] == 0xE) && (pv->i[0x5CC/4] != 2)) {
            fe_func_003A52A0(0xE, 0, m);
            fe_func_0038CF68_003D0910(sp0, m->b + 0xC0, 2.0f);
            vec_add_ab(sp0, sp0, m->b + 0x10);
            pv->mp[0x308/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = *(u128_t *)sp0;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        break;
    case 9:
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->uh[0x96/2] >= 5) {
            if (pv->mp[0x300/4] != 0) {
                pv->mp[0x300/4]->b[0xBC] = 1;
            }
            if (pv->mp[0x304/4] != 0) {
                pv->mp[0x304/4]->b[0xBC] = 1;
            }
            if (pv->mp[0x308/4] != 0) {
                pv->mp[0x308/4]->b[0xBC] = 1;
            }
            if ((pv->i[0x61C/4] == 1) || (pv->i[0x61C/4] == 3)) {
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 1, 4);
                }
            } else {
                if (m->b[0x43] != 0x10) {
                    fe_func_003C3A10(m, 0x10, 1, 4);
                }
            }
            func_L01_004450F0(m, 0xA, -1);
        }
        break;
    case 10:
        {
        f32 f;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, 0.36f, 2.0000002f, 0.010053097f, 0.25132743f);
        }
        if ((func_L01_0044E1B8(m, 127.0f) != 0) && ((u32)(m->b[0x42] - 0x10) < 2)) {
            if (pv->i[0x5CC/4] == 1) {
                pv->i[0x61C/4]++;
                if (pv->i[0x61C/4] >= 4) {
                    pv->i[0x61C/4] = 0;
                    if (m->b[0x43] != 0x1C) {
                        fe_func_003C3A10(m, 0x1C, 2, 0xC);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                } else {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 7);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else if (pv->i[0x5CC/4] == 2) {
                pv->i[0x61C/4]++;
                if (pv->i[0x61C/4] >= 2) {
                    pv->i[0x61C/4] = 0;
                    if (m->b[0x43] != 0x1C) {
                        fe_func_003C3A10(m, 0x1C, 2, 0xC);
                    }
                    func_L01_004450F0(m, 0xB, -1);
                } else {
                    if (m->b[0x43] != 0xE) {
                        fe_func_003C3A10(m, 0xE, 0, 7);
                    }
                    func_L01_004450F0(m, 8, -1);
                }
            } else {
                pv->i[0x61C/4] = 0;
                if (m->b[0x43] != 0x1C) {
                    fe_func_003C3A10(m, 0x1C, 2, 0xC);
                }
                func_L01_004450F0(m, 0xB, -1);
            }
            if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                pv->i[0x670/4] = 0xA;
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, -1);
            }
            if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                func_L01_004450F0(m, 2, 7);
                fe_func_00392C78(D_L20_001E9980);
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 112.0f) && (f < 118.0f) && ((u32)(m->b[0x42] - 0x10) < 2)) {
            if (m->b[0x42] == 0x10) {
                func_L01_004468C8(0.5f, pv->b[0x44], 3.0f, m, 0, 1, 0, 1, 0);
            } else {
                func_L01_004468C8(0.5f, pv->b[0x44], 3.0f, m, 1, 1, 0, 1, 0);
            }
        }
        }
        break;
    case 11:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x12) {
                fe_func_003C3A10(m, 0x12, 0, 7);
            }
            func_L01_004450F0(m, 0x13, -1);
        }
        break;
    case 13:
        {
        f32 f;
        if (m->b[0x60] & 2) {
            m->f[0x48/4] = 1.0f;
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 2);
            }
            func_L01_004450F0(m, 0x10, -1);
            if (pv->i[0x638/4] != 0) {
                D_L20_001DEBF4 = 1;
                func_L01_004450F0(m, 0x1B, -1);
                if (m->b[0x43] != 0xB) {
                    fe_func_003C3A10(m, 0xB, 0, 2);
                }
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 112.0f) && (f < 117.0f) && (m->b[0x42] == 0xA)) {
            m->f[0x48/4] = 0.77f;
            func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            m->f[0x18/4] = m->f[0x18/4] + 0.50000006f;
        } else {
            m->f[0x48/4] = 1.0f;
        }
        }
        break;
    case 14:
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (m->uh[0x96/2] >= 0x33) {
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
            func_L01_004450F0(m, 0x10, -1);
        }
        break;
    case 18:
        {
        f32 f;
        if (m->b[0x60] & 2) {
            pv->i[0x5EC/4] = 0;
            m->f[0x18/4] = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            if ((u32)(m->b[0x94] - 0x10) < 2) {
                func_L01_004450F0(m, 0x22, -1);
                if (m->b[0x43] != 0x1C) {
                    fe_func_003C3A10(m, 0x1C, 0, 0xC);
                }
            } else {
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 0, 8);
                }
                func_L01_004450F0(m, 0x17, -1);
            }
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 7);
                }
                func_L01_004450F0(m, 0x19, -1);
            }
        }
        f = func_L01_004395E0(m);
        if ((f > 119.0f) && (f < 123.0f) && (m->b[0x42] == 0xD)) {
            f32 g;
            f32 t;
            func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
            t = m->f[0x18/4] - 0.64000005f;
            m->f[0x18/4] = t;
            if (t < g) {
                m->f[0x18/4] = g;
            }
        }
        }
        break;
    case 34:
        if (func_L01_004561B8(m) != 0) {
            m->f[0x48/4] = 0.8f;
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x11) {
                fe_func_003C3A10(m, 0x11, 0, 8);
            }
            func_L01_004450F0(m, 0x17, -1);
        }
        break;
    case 16:
        {
        f32 f;
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x2EC/4] = 0;
            pv->i[0x5E0/4] = fe_func_00382468(2);
            if (pv->i[0x5CC/4] == 2) {
                pv->i[0x5E0/4] = 1;
            }
            pv->i[0x62C/4] = -1;
        }
        if (pv->i[0x62C/4] == -1) {
            if (func_L01_004395E0(m) < 163.0f) {
                pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
            }
        } else {
            Light *l;
            fe_func_003C2F58(m, 3, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
            if (pv->i[0x5E0/4] == 1) {
                l->r = 0.8f;
                l->g = 0.0f;
                l->b = 0.0f;
                l->on = 0;
            }
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10_003D0910(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 3, sp0);
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            for (k = 0; k < 20; k++) {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(sp60, 0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, n, D_L20_001D66B0_003D0910, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, sp30, sp10);
                }
            }
        }
        if (m->b[0x60] & 2) {
            if (pv->i[0x5EC/4] < 3) {
                if (m->b[0x43] != 0xB) {
                    fe_func_003C3A10(m, 0xB, 0, 2);
                }
                func_L01_004450F0(m, 0x11, -1);
                pv->i[0x5EC/4]++;
            } else {
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 7);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
            if ((pv->i[0x5CC/4] == 2) && (pv->i[0x5EC/4] >= 2)) {
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 7);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0xC) || (f < 156.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.016f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 3, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0_003D0910, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0_003D0910, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 153.0f) || (m->b[0x42] != 0xC)) {
            m->f[0x48/4] = 0.2f;
        }
        if ((f > 153.0f) && (f < 156.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.06f;
        }
        if ((f > 156.0f) && (f < 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 3.0f;
        }
        if ((f > 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.8f;
        }
        if (func_L01_0044E1B8(m, 165.0f) != 0) {
            Mo *o;
            s32 i;
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (pv->i[0x5E0/4] == 0) {
                o = fe_func_003C24B0_003D0910(0x1AF1, 0xD90);
            } else if (pv->i[0x5E0/4] == 1) {
                o = fe_func_003C24B0_003D0910(0x1CDA, 0xD50);
            } else if (pv->i[0x5E0/4] == 2) {
                o = fe_func_003C24B0_003D0910(0x1CDB, 0xD50);
            } else {
                o = fe_func_003C24B0_003D0910(0x1AF1, 0xD90);
            }
            *(u128_t *)sp0 = m->q[0x10/16];
            sp0[2] += 1.0f;
            func_L20_003EAA70(m, D_L20_001D66B0_003D0910, sp0);
            o->b[0x30] = 0xFF;
            o->uh[0x32/2] = 0xFF;
            o->b[0x31] = 1;
            o->mp[0xB8/4] = m;
            o->q[0x10/16] = m->q[0x10/16];
            o->q[0xF0/16] = m->q[0xF0/16];
            o->d[0x38/8] = m->d[0x38/8];
            o->f[0x18/4] += 1.5f;
            fe_func_0038CF68_003D0910(sp10, m->b + 0xC0, 2.0f);
            vec_add_ba(o->b + 0x10, sp10, o->b + 0x10);
            pv->i[0x2EC/4] = 0x15;
            pv->i[0x2F0/4] = 5;
            D_L20_001E2E80_003D0910.x40 = 0.1f;
            D_L20_001E2E80_003D0910.x48 = 0x4B;
            D_L20_001E2E80_003D0910.x20 = 0.2f;
            D_L20_001E2E80_003D0910.x28 = 0x32;
            D_L20_001E2E80_003D0910.x2C = 0;
            for (i = 0; i < 300; i++) {
                s32 n;
                s32 n2;
                s32 c;
                u8 *p;
                fe_func_003C2F58(m, 3, sp20);
                fe_func_00382580(sp30, 0.6f, 0.70000005f);
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8_003D0910(sp20, sp30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.0f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n2 = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8_003D0910(sp20, sp30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f * pv->f[0x2E8/4], c, n2, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.0f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
        }
        }
        break;
    case 19:
        if (func_L01_0044E1B8(m, 125.0f) != 0) {
            pv->i[0x5E4/4] = 0;
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xF);
            }
            if (fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4])) > 0.7853982f) {
                func_L01_004450F0(m, 5, -1);
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 7);
                }
            }
            if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                pv->i[0x670/4] = 0x13;
                if (m->b[0x43] != 5) {
                    fe_func_003C3A10(m, 5, 0, 8);
                }
                func_L01_004450F0(m, 0x20, -1);
            }
        }
        if ((func_L01_0044E1B8(m, 120.0f) != 0) && (m->b[0x42] == 0x12)) {
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xFFBE;
            pv->mp[0x2F8/4]->uh[0x34/2] |= pv->mp[0x2F8/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
            pv->mp[0x2F8/4]->i[0x98/4] = pv->mp[0x2F8/4]->mp[0x24/4]->i[0x10/4];
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xFFBE;
            pv->mp[0x2FC/4]->uh[0x34/2] |= pv->mp[0x2FC/4]->mp[0x24/4]->uh[0x44/2] & 0x1000;
            pv->mp[0x2FC/4]->i[0x98/4] = pv->mp[0x2FC/4]->mp[0x24/4]->i[0x10/4];
        }
        break;
    case 20:
        if (m->uh[0x96/2] >= 2) {
            func_L01_004450F0(m, 0x15, -1);
            if (m->b[0x43] != 0x23) {
                fe_func_003C3A10(m, 0x23, 0, 0xC);
            }
        }
        pv->f[0x418/4] = D_L20_001DEBD4 * 0.017453292f;
        pv->f[0x498/4] = D_L20_001DEBD8 * 0.017453292f;
        pv->f[0x514/4] = D_L20_001DEBDC * 0.017453292f;
        pv->f[0x510/4] = D_L20_001DEBE0 * 0.017453292f;
        pv->f[0x518/4] = D_L20_001DEBE8 * 0.017453292f;
        pv->f[0x590/4] = D_L20_001DEBE4 * 0.017453292f;
        break;
    case 21:
        {
        f32 g;
        if (func_L01_004561B8(m) != 0) {
            m->f[0x48/4] = 1.5f;
            pv->f[0x630/4] = 0.0f;
        }
        g = fe_func_003C3D30(m->b + 0x10, 0, 0, 0.5f);
        if (g < m->f[0x18/4]) {
            m->f[0x18/4] = m->f[0x18/4] - 0.080000006f;
            if (m->f[0x18/4] < g) {
                m->f[0x18/4] = g;
            }
        }
        if (m->b[0x42] == 0x23) {
            s32 h;
            u8 *s;
            s32 fr;
            s32 bit;
            fe_func_0038DB00(fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]), m->f[0xF8/4]);
            fe_func_0038DBA0(m->f[0xF8/4], fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
            h = pv->i[0x658/4];
            if ((h == -1) || (s = D_001A30B0 + (h << 7), *(Mo **)(s + 0xDC) != m) || (s[0xD0] == 0)) {
                pv->i[0x658/4] = func_L01_004AAC98_003D0910(0, 4, m, 0x1CB4);
            }
            if (m->uh[0x96/2] >= 0x97) {
                s32 h = pv->i[0x658/4];
                if (h != -1) {
                    s = D_001A30B0 + (h << 7);
                    if ((*(Mo **)(s + 0xDC) == m) && (s[0xD0] != 0)) {
                        fe_func_003A4F28(h);
                    }
                }
                pv->i[0x658/4] = -1;
                pv->i[0x5C8/4] = 0;
                if (pv->i[0x5C4/4] == 0) {
                    func_L01_004450F0(m, 5, -1);
                    if (m->b[0x43] != 5) {
                        fe_func_003C3A10(m, 5, 0, 7);
                    }
                    if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                        pv->i[0x670/4] = 0x15;
                        if (m->b[0x43] != 5) {
                            fe_func_003C3A10(m, 5, 0, 8);
                        }
                        func_L01_004450F0(m, 0x20, -1);
                    }
                    pv->i[0x5C4/4]++;
                } else if (pv->i[0x5C4/4] == 1) {
                    if (m->b[0x43] != 7) {
                        fe_func_003C3A10(m, 7, 0, 7);
                    }
                    func_L01_004450F0(m, 6, -1);
                    if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 5.0f) {
                        pv->i[0x670/4] = 0x13;
                        if (m->b[0x43] != 5) {
                            fe_func_003C3A10(m, 5, 0, 8);
                        }
                        func_L01_004450F0(m, 0x20, -1);
                    }
                    pv->i[0x5C4/4]++;
                } else {
                    func_L01_004450F0(m, 0x16, -1);
                    if (m->b[0x43] != 0x16) {
                        fe_func_003C3A10(m, 0x16, 0, 5);
                    }
                }
                if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                    m->i[0x98/4] = 0;
                    m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(m, 1);
                    func_L01_004450F0(m, 2, 7);
                    fe_func_00392C78(D_L20_001E9980);
                }
            }
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                func_L01_004450F0(m, 0x16, -1);
                if (m->b[0x43] != 0x16) {
                    fe_func_003C3A10(m, 0x16, 0, 5);
                }
            }
            bit = D_L20_001DFD40_d & 1;
            if (bit == (((s32)m >> 8) & 1)) {
                f32 d;
                f32 z;
                f32 f;
                f32 a;
                fe_func_003C2EC0(pv->mp[0x2F8/4], 0, sp0);
                *(u128_t *)sp40 = *(u128_t *)sp30;
                vec_sub_ab(sp60, D_001A4BE0 + 0xD0, sp40);
                z = sp60[2];
                d = fe_func_0038CED8_003D0910(sp60);
                a = m->f[0xF8/4];
                a = fe_func_0038DAB8(a, fe_func_0038D098(pv->f[0x630/4]));
                sp60[0] = fe_func_0038D098(a) * d;
                sp60[1] = fe_func_0038D0B0(a) * d;
                sp60[2] = z;
                *(u128_t *)sp50 = *(u128_t *)sp60;
                func_L20_003E56D8(m, sp40, sp50, pv->b[0x45], 1);
                if ((D_L20_001DFD40_d & 1) == bit) {
                    f32 d;
                    f32 z;
                    f32 a;
                    fe_func_003C2EC0(pv->mp[0x2FC/4], 0, sp0);
                    *(u128_t *)sp40 = *(u128_t *)sp30;
                    vec_sub_ab(sp60, D_001A4BE0 + 0xD0, sp40);
                    z = sp60[2];
                    d = fe_func_0038CED8_003D0910(sp60);
                    a = m->f[0xF8/4];
                    a = fe_func_0038DB00(a, fe_func_0038D098(pv->f[0x630/4]));
                    sp60[0] = fe_func_0038D098(a) * d;
                    sp60[1] = fe_func_0038D0B0(a) * d;
                    sp60[2] = z;
                    *(u128_t *)sp50 = *(u128_t *)sp60;
                    func_L20_003E56D8(m, sp40, sp50, pv->b[0x45], 1);
                }
            }
            pv->f[0x630/4] = pv->f[0x630/4] + 0.035f;
            if (pv->f[0x630/4] >= 6.0f) {
                pv->f[0x630/4] = 0.0f;
            }
        }
        }
        break;
    case 22:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x5C4/4] = 0;
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0x11) {
                fe_func_003C3A10(m, 0x11, 0, 8);
            }
            func_L01_004450F0(m, 0x17, -1);
            if (pv->i[0x5CC/4] != 1) {
                if (m->b[0x43] != 0xA) {
                    fe_func_003C3A10(m, 0xA, 0, 6);
                }
                func_L01_004450F0(m, 0xD, -1);
            }
            if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
                if (m->b[0x43] != 9) {
                    fe_func_003C3A10(m, 9, 0, 7);
                }
                func_L01_004450F0(m, 0x19, -1);
            }
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0x16)) {
            pv->mp[0x2F8/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2F8/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2F8/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2F8/4], 1);
            pv->mp[0x2FC/4]->uh[0x34/2] |= 0x41;
            pv->mp[0x2FC/4]->uh[0x34/2] &= 0xEFFF;
            pv->mp[0x2FC/4]->i[0x98/4] = 0;
            func_L01_004AA7E8(pv->mp[0x2FC/4], 1);
        }
        break;
    case 23:
        {
        f32 f;
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x62C/4] = -1;
            pv->i[0x2EC/4] = 0;
            pv->i[0x5E0/4] = 0;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (pv->i[0x62C/4] == -1) {
            pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
        } else {
            Light *l;
            fe_func_003C2F58(m, 9, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10_003D0910(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 9, sp0);
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            for (k = 0; k < 20; k++) {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(sp60, 0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, n, D_L20_001D66B0_003D0910, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, sp30, sp10);
                }
            }
        }
        if (func_L01_0044E1B8(m, 127.0f) != 0) {
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (m->b[0x43] != 2) {
                fe_func_003C3A10(m, 2, 0, 0x15);
            }
            func_L01_004450F0(m, 0x18, -1);
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0x11) || (f < 114.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.030000001f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 1, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0_003D0910, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0_003D0910, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 112.0f) || (m->b[0x42] != 0x11)) {
            m->f[0x48/4] = 0.5f;
        } else {
            m->f[0x48/4] = 1.0f;
        }
        if (func_L01_0044E1B8(m, 114.0f) != 0) {
            s32 i; f32 rate = 0.20000002f;
            fe_func_003C2F58(m, 1, sp0);
            for (i = 0; i < 1; i++) {
                f32 w;
                *(u128_t *)sp10 = *(u128_t *)(D_001A4BE0 + 0xD0);
                if (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) > 6.0f) {
                    vec_sub_ab(sp20, m->b + 0x10, D_001A4BE0 + 0x80);
                    fe_func_0038CF68_003D0910(sp20, sp20, 5.0f);
                    vec_add_ab(sp10, sp20, sp10);
                }
                w = fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) * 3.0f * 0.00040000002f;
                if (w < 0.014f) {
                    w = 0.014f;
                }
                vec_sub_ab(sp20, sp10, sp0);
                sp20[2] = 0.0f;
                fe_func_0038CF68_003D0910(sp20, sp20, rate);
                sp20[2] = func_L01_00447878(sp0, sp10, 0, rate, -w);
                fe_func_003A52A0(0x13, 0, m);
                func_L20_003F9C10(m, sp20, sp0, w);
            }
        }
        }
        break;
    case 24:
        if (m->uh[0x96/2] >= 9) {
            if (pv->i[0x634/4] < 5) {
                pv->i[0x634/4] = pv->i[0x634/4] + 1;
                func_L01_004450F0(m, 0x17, -1);
                if (m->b[0x43] != 0x11) {
                    fe_func_003C3A10(m, 0x11, 0, 8);
                }
            } else {
                func_L01_004450F0(m, 0x21, -1);
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 8);
                }
            }
        }
        break;
    case 33:
        if (m->b[0x60] & 2) {
            pv->i[0x634/4] = 0;
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 8);
            }
            func_L01_004450F0(m, 0x19, -1);
            if (pv->i[0x5CC/4] != 4) {
                func_L01_004450F0(m, 7, -1);
            }
            if ((pv->i[0x638/4] != 0) && (fe_func_00392B20(D_L20_001E9980, 0xBA) != 0)) {
                m->i[0x98/4] = 0;
                m->uh[0x34/2] = (m->uh[0x34/2] | 0x41) & 0xEFFF;
                func_L01_004AA7E8(m, 1);
                func_L01_004450F0(m, 2, 7);
                fe_func_00392C78(D_L20_001E9980);
            }
        }
        break;
    case 17:
        {
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBD0 * 0.00040000002f, D_L20_001DEBCC * 0.020000001f, 0.010053097f, 0.25132743f);
            do {
                f32 a = fe_func_00382538();
                f32 r = fe_func_003824E0(13.0f, 15.0f);
                qzero(sp0);
                sp0[0] = fe_func_0038D098(a) * r;
                sp0[1] = fe_func_0038D0B0(a) * r;
                vec_add_ab(pv->b + 0x5F0, m->b + 0x10, sp0);
                if (pv->i[0x5E8/4] != -1) {
                    vec_add_ba(pv->b + 0x5F0, &((Spot *)((u8 *)D_L20_001E0380 + (pv->i[0x5E8/4] << 7)))->pos, sp0);
                }
            } while (!(fe_func_0038CF38(m->b + 0x10, pv->b + 0x5F0) > 8.0f));
        }
        func_L02_00431568(m, pv->b + 0x5F0, fe_func_0038D160(pv->f[0x5F0/4] - m->f[0x10/4], pv->f[0x5F4/4] - m->f[0x14/4]), -1.0f, -1.0f, -1.0f, 0x14);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (fe_func_0038CF38(m->b + 0x10, pv->b + 0x5F0) < 0.75f) {
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
            func_L01_004450F0(m, 0x10, -1);
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        }
        break;
    case 27:
        if (func_L01_004561B8(m) != 0) {
            if (D_L20_001E2E80_003D0910.x144 == m) {
                D_L20_001E2E80_003D0910.x144 = 0;
            }
            pv->i[0x638/4] = 0;
            pv->i[0xA8/4] |= 5;
            func_L01_0045BD78(m, D_L20_001DEBD0 * 0.00040000002f, D_L20_001DEBCC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        pv->h[0x36/2] = 8;
        func_L01_00404808_003D0910(func_L20_003D7558, m);
        func_L01_00404808_003D0910(func_L20_003D7950, m);
        func_L01_00404808_003D0910(func_L20_003D8248, m);
        if (func_L01_0045BDE8(m, pv->i[0x63C/4]) != 0) {
            pv->q[0x5B0/16] = m->q[0x10/16];
            func_L01_004450F0(m, 0x1C, -1);
        }
        break;
    case 28:
        {
        pv->h[0x36/2] = 8;
        func_L01_00404808_003D0910(func_L20_003D7558, m);
        func_L01_00404808_003D0910(func_L20_003D7950, m);
        func_L01_00404808_003D0910(func_L20_003D8248, m);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0xD0/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0xD4/4] - m->f[0x14/4]));
        if ((fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 20.0f) || ((pv->i[0x640/4] != -1) && (fe_func_00382380(D_001A4BE0 + 0x80, pv->i[0x674/4], 0) != 0))) {
            if (pv->i[0x640/4] != -1) {
                pv->i[0x63C/4] = pv->i[0x640/4];
                pv->i[0x640/4] = -1;
                func_L01_004450F0(m, 0x1B, -1);
            } else {
                func_L01_00456230(&D_L20_001E029C_d[pv->i[0x660/4]], 1);
                if (D_L20_001E2E80_003D0910.x144 == 0) {
                    D_L20_001E2E80_003D0910.x144 = m;
                    D_L20_001E2E80_003D0910.x148 = 0;
                }
                if (m->b[0x43] != 0xD) {
                    fe_func_003C3A10(m, 0xD, 0, 5);
                }
                func_L01_004450F0(m, 0x12, -1);
            }
        } else if ((m->uh[0x96/2] >= 0xE2) && (fe_func_0038CF38(m->b + 0x10, D_001A4BE0 + 0x80) < 60.0f)) {
            func_L01_004450F0(m, 0x1D, -1);
            if (m->b[0x43] != 0xC) {
                fe_func_003C3A10(m, 0xC, 0, 5);
            }
        }
        }
        break;
    case 29:
        {
        f32 f;
        pv->h[0x36/2] = 8;
        func_L01_00404808_003D0910(func_L20_003D7558, m);
        func_L01_00404808_003D0910(func_L20_003D7950, m);
        func_L01_00404808_003D0910(func_L20_003D8248, m);
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2E8/4] = 0.0f;
            pv->i[0x2EC/4] = 0;
            fe_func_00382468(2);
            pv->i[0x5E0/4] = 0;
            if (pv->i[0x640/4] == -1) {
                pv->i[0x5E0/4] = 1;
            }
            pv->i[0x62C/4] = -1;
        }
        if (pv->i[0x62C/4] == -1) {
            if (func_L01_004395E0(m) < 163.0f) {
                pv->i[0x62C/4] = func_L01_00424CB0(m->b + 0x10, pv->f[0x2E8/4] * 15.0f, 0.0f, 0.45f, 0.2f, 1.0f);
            }
        } else {
            Light *l;
            fe_func_003C2F58(m, 3, sp0);
            l = &D_L20_001F0D00[pv->i[0x62C/4]];
            l->u.pos = *(u128_t *)sp0;
            l->u.v.w = pv->f[0x2E8/4] * 15.0f;
            l->r = 0.45f;
            l->g = 0.2f;
            l->b = 1.0f;
            l->on = 0;
            if (pv->i[0x5E0/4] == 1) {
                l->r = 0.8f;
                l->g = 0.0f;
                l->b = 0.0f;
                l->on = 0;
            }
        }
        if ((pv->f[0x30/4] < 400.0f) && (pv->i[0x610/4] == 0)) {
            if (m->b[0x43] != 0xD) {
                fe_func_003C3A10(m, 0xD, 0, 8);
            }
            func_L01_004450F0(m, 0x12, -1);
        }
        if (fe_func_0038CAD0(pv->b + 0x2EC) == 0) {
            f32 ang;
            s32 k;
            fe_func_0038CAD0(pv->b + 0x2F0);
            func_L01_00404A10_003D0910(func_L20_003D6F30, m);
            fe_func_003C2F58(m, 3, sp0);
            *(u128_t *)sp30 = 0;
            *(u128_t *)sp40 = *(u128_t *)sp0;
            sp30[0] = 0.3f;
            sp30[1] = -1.0f;
            sp30[3] = 1.0f;
            *(u128_t *)sp70 = m->q[0xC0/16];
            *(u128_t *)sp80 = m->q[0xD0/16];
            fe_func_0038D890(sp30, sp70, sp80, 0.34906584f);
            qzero(sp90);
            *(u128_t *)sp20 = *(u128_t *)sp30;
            fe_func_0038CE20(spA0, sp70, 0.4f);
            vec_add_ab(sp40, sp40, spA0);
            ang = 0.0f;
            for (k = 0; k < 20; k++) {
                s32 n;
                s32 c;
                u8 *p;
                f32 r;
                ang = fe_func_0038DAB8(ang, fe_func_003824E0(0.0f, 0.62831855f));
                fe_func_0038CE20(sp50, sp20, fe_func_003824E0(0.24000001f, 0.32000002f));
                vec_add_ab(sp50, sp50, sp90);
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.3f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.3f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.3f);
                n = func_L01_00443A18(1.0f, 2.0f);
                p = func_L01_004669B0(sp60, 0.0f, 1.0f, 1.01f, fe_func_003824E0(0.2f, 0.75f) * 210000.0f, n, D_L20_001D66B0_003D0910, 0x7F000000, 0);
                if (p != 0) {
                    u8 *q;
                    p[3] = 0x44;
                    *(s16 *)(p + 0xA) = 0x32;
                    p[9] = 0x44;
                    q = p + 0x20;
                    *(f32 *)(q + 0x1C) = 4.0f;
                    *(s32 *)(q + 4) = 3;
                    q[0xA] = 0x30;
                    q[0xB] = p[0xA];
                }
                sp60[0] = sp40[0] + func_L01_00443A18(0.0f, 0.6f);
                sp60[1] = sp40[1] + func_L01_00443A18(0.0f, 0.6f);
                sp60[2] = sp40[2] + func_L01_00443A18(0.0f, 0.6f);
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                r = fe_func_003824E0(0.2f, 1.75f);
                vec_sub_ab(sp60, sp60, sp50);
                p = func_L01_0046A610(sp60, sp50, 5, 0x7F, c, n, r * 210000.0f, 500.0f, 0.95f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0x16C/4][1];
                }
                if (fabs_asm(ang) > 1e-05f) {
                    fe_func_003C4840(sp10, sp70, ang);
                    fe_func_0038D850(sp20, sp30, sp10);
                }
            }
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0xB) {
                fe_func_003C3A10(m, 0xB, 0, 2);
            }
            func_L01_004450F0(m, 0x1C, -1);
        }
        f = func_L01_004395E0(m);
        if ((m->b[0x42] != 0xC) || (f < 156.0f)) {
            {
            f32 e;
            f32 t;
            s32 i;
            u8 *p;
            t = pv->f[0x2E8/4] + 0.030000001f;
            e = t * 262500.0f;
            pv->f[0x2E8/4] = t;
            fe_func_003C2F58(m, 3, sp0);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(sp0, D_L20_001D66B0_003D0910, 0xC, 6, c, n, e * 6.0f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[2] = D_L20_00220258[0x170/4][1];
                }
            }
            sp10[0] = sp0[0] + func_L01_00443A18(0.0f, 0.04f);
            sp10[1] = sp0[1] + func_L01_00443A18(0.0f, 0.04f);
            sp10[2] = sp0[2] + func_L01_00443A18(0.0f, 0.04f);
            if (fe_func_00382468(2) != 0) {
                s32 n;
                s32 c;
                f32 *q;
                c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                q = sp10;
                n = func_L01_00443A18(1.0f, -1.0f);
                p = func_L01_0046A610(q, D_L20_001D66B0_003D0910, 0xC, 0x7F, c, n, e * 2.4f, 500.0f, 1.0f, 0.0f, 0.0f);
                if (p != 0) {
                    p[3] = (fe_func_00382468(2) != 0) ? 0x48 : 0x44;
                    p[2] = D_L20_00220258[0x170/4][0];
                }
            }
            for (i = 0; i < 6; i++) {
                s32 n;
                u8 *p;
                fe_func_00382580(sp20, pv->f[0x2E8/4] * 0.10000001f, pv->f[0x2E8/4] * 0.14000002f);
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.00584f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
                n = func_L01_00443A18(2.0f, 5.0f);
                p = func_L01_004713C8_003D0910(sp0, sp20, 0xC, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 3.0f * pv->f[0x2E8/4], 0, n, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.00584f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
            }
        }
        if ((f < 153.0f) || (m->b[0x42] != 0xC)) {
            m->f[0x48/4] = 0.5f;
        }
        if ((f > 153.0f) && (f < 156.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 0.15f;
        }
        if ((f > 156.0f) && (f < 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 3.0f;
        }
        if ((f > 165.0f) && (m->b[0x42] == 0xC)) {
            m->f[0x48/4] = 1.0f;
        }
        if (func_L01_0044E1B8(m, 165.0f) != 0) {
            Mo *o;
            s32 i;
            if (pv->i[0x62C/4] != -1) {
                func_L01_00424D88(pv->i[0x62C/4]);
            }
            pv->i[0x62C/4] = -1;
            if (pv->i[0x5E0/4] == 0) {
                o = fe_func_003C24B0_003D0910(0x1AF1, 0xD90);
            } else if (pv->i[0x5E0/4] == 1) {
                o = fe_func_003C24B0_003D0910(0x1CDA, 0xD50);
            } else if (pv->i[0x5E0/4] == 2) {
                o = fe_func_003C24B0_003D0910(0x1CDB, 0xD50);
            } else {
                o = fe_func_003C24B0_003D0910(0x1AF1, 0xD90);
            }
            *(u128_t *)sp0 = m->q[0x10/16];
            sp0[2] += 1.0f;
            func_L20_003EAA70(m, D_L20_001D66B0_003D0910, sp0);
            o->b[0x30] = 0xFF;
            o->uh[0x32/2] = 0xFF;
            o->b[0x31] = 1;
            o->mp[0xB8/4] = m;
            o->q[0x10/16] = m->q[0x10/16];
            o->q[0xF0/16] = m->q[0xF0/16];
            o->d[0x38/8] = m->d[0x38/8];
            o->f[0x18/4] += 1.5f;
            fe_func_0038CF68_003D0910(sp10, m->b + 0xC0, 2.0f);
            vec_add_ba(o->b + 0x10, sp10, o->b + 0x10);
            pv->i[0x2EC/4] = 0x15;
            pv->i[0x2F0/4] = 5;
            D_L20_001E2E80_003D0910.x40 = 0.1f;
            D_L20_001E2E80_003D0910.x48 = 0x4B;
            D_L20_001E2E80_003D0910.x20 = 0.2f;
            D_L20_001E2E80_003D0910.x28 = 0x32;
            D_L20_001E2E80_003D0910.x2C = 0;
            for (i = 0; i < 300; i++) {
                s32 n;
                s32 n2;
                s32 c;
                u8 *p;
                fe_func_003C2F58(m, 3, sp20);
                fe_func_00382580(sp30, 0.6f, 0.70000005f);
                n = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8_003D0910(sp20, sp30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * pv->f[0x2E8/4], 0, n, 0x7F, 0x7F, pv->f[0x2E8/4] * 2100.0f, 0.0f, 6);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            c = 0xFFFFFF;
                if (pv->i[0x5E0/4] == 0) {
                    c = 0x7C0030;
                } else if (pv->i[0x5E0/4] == 1) {
                    c = 0x6065C;
                } else if (pv->i[0x5E0/4] == 2) {
                    c = 0x7C30;
                }
                n2 = func_L01_00443A18(2.0f, 3.0f);
                p = func_L01_004713C8_003D0910(sp20, sp30, 0x32, fe_func_003824E0(0.8f, 1.25f) * 210000.0f * 1.25f * pv->f[0x2E8/4], c, n2, 0x30, 0x30, pv->f[0x2E8/4] * 4200.0f, 0.0f, 0);
                if (p != 0) {
                    p[3] = 0x44;
                    p[2] = D_L20_00220258[0xD4/4][0];
                }
            }
        }
        }
        break;
    case 30:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 9) {
                fe_func_003C3A10(m, 9, 0, 7);
            }
            func_L01_004450F0(m, 7, -1);
        }
        break;
    case 31:
        if (m->b[0x60] & 2) {
            if (m->b[0x42] == 3) {
                if (m->b[0x43] != 4) {
                    fe_func_003C3A10(m, 4, 0, 7);
                }
            } else if (m->b[0x42] == 4) {
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 7);
                }
            }
        }
        break;
    case 25:
        {
        u8 *dst;
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78(m, D_L20_001DEBC0 * 0.00040000002f, D_L20_001DEBBC * 0.020000001f, 0.010053097f, 0.25132743f);
        }
        dst = pv->b + 0x5B0;
        func_L01_0045A748(m, dst);
        if (fe_func_0038CF38(m->b + 0x10, dst) <= 0.75f) {
            if (m->b[0x43] != 0xE) {
                fe_func_003C3A10(m, 0xE, 0, 8);
            }
            func_L01_004450F0(m, 0x1A, -1);
        }
        }
        break;
    case 26:
        if (func_L01_004561B8(m) != 0) {
            pv->i[0x610/4] = 1;
        }
        func_L01_0045BD10(m, fe_func_0038D160(((Hero *)D_001A4BE0)->f[0x80/4] - m->f[0x10/4], ((Hero *)D_001A4BE0)->f[0x84/4] - m->f[0x14/4]));
        if ((m->b[0x60] & 2) && (m->b[0x43] != 0xF)) {
            fe_func_003C3A10(m, 0xF, 0, 1);
        }
        if ((func_L01_0044E1B8(m, 125.0f) != 0) && (m->b[0x42] == 0xE)) {
            Spot *s;
            fe_func_003A52A0(0xE, 0, m);
            s = &D_L20_001E0380_d[pv->i[0x71C/4]];
            pv->mp[0x304/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x304/4], m);
            pv->mp[0x304/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x304/4], 0, m->b[0x40]);
        }
        if ((func_L01_0044E1B8(m, 115.0f) != 0) && (m->b[0x42] == 0xE)) {
            Spot *s;
            fe_func_003A52A0(0xE, 0, m);
            s = &D_L20_001E0380_d[pv->i[0x720/4]];
            pv->mp[0x308/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        if ((m->b[0x42] == 0xF) && ((D_L20_001DFD40_d & 0xF) == (((s32)m >> 8) & 0xF))) {
            Spot *s; s32 r;
            fe_func_003A52A0(0xE, 0, m);
            r = fe_func_00382468(0x10);
            s = &D_L20_001E0380_d[*(s32 *)((u8 *)pv + (r << 2) + 0x710)];
            pv->mp[0x308/4] = fe_func_003C24B0_003D0910(0x1CAF, 0x130);
            func_L01_00456160(pv->mp[0x308/4], m);
            pv->mp[0x308/4]->q[0x10/16] = s->pos;
            fe_func_003C3938(pv->mp[0x308/4], 0, m->b[0x40]);
        }
        if (m->uh[0x96/2] >= 0x1F5) {
            if (fe_func_00382468(2) != 0) {
                if (m->b[0x43] != 3) {
                    fe_func_003C3A10(m, 3, 0, 6);
                }
            } else {
                if (m->b[0x43] != 4) {
                    fe_func_003C3A10(m, 4, 0, 6);
                }
            }
            func_L01_004450F0(m, 0x1E, -1);
        }
        break;
    }
    func_L20_003D6D18(m);
    if (pv->mp[0x618/4] != 0) {
        pv->mp[0x618/4]->i[0x98/4] = 0;
        fe_func_003C7C38(pv->mp[0x618/4]);
    }
    if (pv->mp[0x67C/4] != 0) {
        pv->mp[0x67C/4]->i[0x98/4] = 0;
        fe_func_003C7C38(pv->mp[0x67C/4]);
    }
}
/* localdecomp:end func_L20_003D0910 */
