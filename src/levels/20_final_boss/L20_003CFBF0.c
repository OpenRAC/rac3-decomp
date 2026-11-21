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

INCLUDE_ASM("asm/levels", func_L20_003D0910);
