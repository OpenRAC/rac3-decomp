#include "common.h"

/* localdecomp:start func_L20_003EE688 */
extern unsigned int D_00142C58[];
extern void func_003C2880(void *);

void func_L20_003EE688(int a0) {
    if (D_00142C58[0] & 0x2000000)
        func_003C2880((void *)a0);
}
/* localdecomp:end func_L20_003EE688 */

/* localdecomp:start func_L20_003EE6B8 */
extern unsigned int D_00142C58[];
extern void func_003C2880(void *);

void func_L20_003EE6B8(int a0) {
    if (D_00142C58[0] & 0x2000000)
        func_003C2880((void *)a0);
}
/* localdecomp:end func_L20_003EE6B8 */

INCLUDE_ASM("asm/levels", func_L20_003EE6E8);

/* localdecomp:start func_L20_003EEB40 */
#include "vu0.h"

typedef struct {
    vu0_v4 pos;
    u8 pad10[0x450];
} C_003EEB40;
typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[2];
    u8 bA;
    u8 bB;
    u8 padC[0x1C - 0xC];
    f32 f1C;
} P_003EEB40;
typedef struct {
    u8 pad0[9];
    u8 b9;
    s16 hA;
    u8 padC[0x20 - 0xC];
    P_003EEB40 sub;
} Q_003EEB40;

extern s32 D_001D52F0;
extern s32 D_001A71A0 __attribute__((section(".data")));
extern C_003EEB40 D_L20_001E2E80[];
extern u8 D_L20_001E9BE0[];
extern f32 D_L20_002C51D0[];
extern u8 D_L20_00220258[];
extern s32 D_L20_001DF338;
__asm__(".extern D_L20_001DF338, 4");

extern s32 func_L01_0044C638(u8 *, s32, u8 *, u8 *, u8 *, u8 *);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044C870(u8 *, s32, u8 *, void *);
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern void *func_L01_00470668(void *, void *, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern Q_003EEB40 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, s32, s32);
extern f32 func_00382538(void);
extern void *func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);
extern s32 func_L01_003FB640(void *, f32, s32, u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L20_003F0088(void);
extern void func_003C2880(void *);

void func_L20_003EEB40(u8 *a0) {
    vu0_v4 v0;
    vu0_v4 v1;
    vu0_v4 v2;
    vu0_v4 v3;
    vu0_v4 v4;
    vu0_v4 v5;
    u8 *s = *(u8 **)(a0 + 0x68);
    f32 ang;
    f32 a;
    f32 b;

    if (*(s32 *)(s + 0x38) != 0) {
        func_L01_0044C638(a0, *(s32 *)(s + 0x38), a0 + 0x10, a0 + 0xF0, a0 + 0x10, a0 + 0xF0);
    }
    if (func_0038CB00(s + 0x10) == 0) {
        ang = func_0038D160(D_L20_001E2E80[D_001D52F0].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                            D_L20_001E2E80[D_001D52F0].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
        qzero(&v0);
        if (*(s32 *)(s + 0x38) != 0) {
            func_L01_0044C870(a0, *(s32 *)(s + 0x38), a0 + 0x10, &v0);
        }
        if (*(s16 *)(s + 0x10) == 0x3A) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x32); i++) {
                func_00382580(&v1, *(f32 *)(s + 0xC) * 0.3f, *(f32 *)(s + 0xC) * 0.40000004f);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_00470668(a0 + 0x10, &v1, (func_00382498(0x19, 0x28) * 5 + 2) / 6, 0.00584f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x39) {
            s32 i;
            s32 k;
            s32 sign = 1;
            for (i = 0; i < *(s32 *)(s + 0x2C); i++) {
                Q_003EEB40 *q;
                sign = -sign;
                k = (D_L20_001DF338 + 1) % 44;
                v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L20_002C51D0[k] * *(f32 *)(s + 0xC);
                D_L20_001DF338 = k;
                k = (D_L20_001DF338 + 1) % 44;
                v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L20_002C51D0[k] * *(f32 *)(s + 0xC);
                D_L20_001DF338 = k;
                k = (D_L20_001DF338 + 1) % 44;
                v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L20_002C51D0[k] * *(f32 *)(s + 0xC);
                D_L20_001DF338 = k;
                a = func_003824E0(0.020000001f, 0.040000003f) * *(f32 *)(s + 0xC);
                b = func_L01_00443A18(0.0f, 1.3962634f);
                func_00382760(&v2, a, func_0038DAB8(ang, func_L01_00443A18(0.0f, 1.5707964f)), b);
                vec_add_ab(&v2, &v2, &v0);
                q = func_L01_004669B0(&v1, 0.0f, 1.0f, 1.01f, *(f32 *)(s + 0xC) * 1.5f * 210000.0f, sign, &v2,
                                      *(s32 *)(s + 0x58), 0);
                if (q != 0) {
                    P_003EEB40 *p;
                    q->hA = (func_00382498(0x28, 0x46) * 5 + 2) / 6;
                    q->b9 = 0x44;
                    p = &q->sub;
                    p->w4 = 3;
                    p->f1C = (func_00382498(1, 10) * 5 + 2) / 6;
                    p->bA = 0x40;
                    p->bB = q->hA;
                }
            }
        }
        if (*(s16 *)(s + 0x10) == 0x38) {
            s32 i;
            for (i = 0; i < *(s16 *)(s + 0x30); i++) {
                a = func_003824E0(0.43633232f, 0.7853982f);
                b = func_00382538();
                func_00382760(&v1, func_003824E0(10.0f, 20.0f) * 0.020000001f * *(f32 *)(s + 0xC), b, a);
                vec_add_ab(&v1, &v1, &v0);
                func_L01_002FB660(a0 + 0x10, &v1, func_00382498(100, 125), 2, 0, 1);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x37 && *(s16 *)(s + 0x3C) != 0) {
            u8 *g;
            s32 i;
            a = func_00382538();
            func_00382580(&v1, 1.0f, 1.0f);
            vec_sub_ba(&v2, &D_L20_001E2E80[D_001D52F0].pos, a0 + 0x10);
            func_0038CE90(&v3, &v2, &v1);
            func_0038CF68(&v3, &v3, 1.0f);
            g = D_L20_00220258;
            for (i = 0; i < 100; i++) {
                s32 n;
                u8 *e;
                n = func_L01_00443A18(2.0f, 5.0f);
                func_0038D890(&v4, &v3, &v1, a);
                func_0038CF68(&v4, &v4, *(f32 *)(s + 0xC) * 0.3f);
                e = func_L01_004713C8(a0 + 0x10, &v4, (func_00382498(0x14, 0x1B) * 5 + 2) / 6,
                                      *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                if (e != 0) {
                    e[2] = **(u8 **)(g + 0x170);
                }
                a = func_0038DAB8(a, 0.06346652f);
            }
        }
        if (*(s16 *)(s + 0x10) == 0x36 && *(s16 *)(s + 0x16) != 0) {
            a = func_00382538();
            if (func_L01_003FB640(a0 + 0x10, 1.0f, 0x14, (u8 *)D_001A71A0) != 0) {
                v1 = *(vu0_v4 *)(D_L20_001E9BE0 + 0x20);
                v2 = *(vu0_v4 *)D_L20_001E9BE0;
            } else {
                func_00382580(&v1, 1.0f, 1.0f);
                v2 = *(vu0_v4 *)(a0 + 0x10);
            }
            func_0038CF68(&v1, &v1, 0.05f);
            vec_add_ba(&v2, &v2, &v1);
            func_0038CF68(&v1, &v1, 1.0f);
            vec_sub_ba(&v3, &D_L20_001E2E80[D_001D52F0].pos, a0 + 0x10);
            func_0038CE90(&v4, &v3, &v1);
            func_0038CF68(&v4, &v4, 1.0f);
            if (*(s16 *)(s + 0x36) != 0) {
                u8 *g = D_L20_00220258;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L01_00443A18(2.0f, 5.0f);
                    func_0038D890(&v5, &v4, &v1, a);
                    func_0038CF68(&v5, &v5, func_003824E0(5.0f, 9.0f) * 0.020000001f * *(f32 *)(s + 0xC));
                    if (i % 3 == 0) {
                        e = func_L01_004713C8(&v2, &v5, (func_00382498(0x14, 0x1B) * 5 + 2) / 6,
                                              *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                        if (e != 0) {
                            e[2] = **(u8 **)(g + 0x170);
                        }
                    }
                    a = func_0038DAB8(a, 0.06346652f);
                }
            } else {
                u8 *g = D_L20_00220258;
                s32 i;
                for (i = 0; i < 100; i++) {
                    s32 n;
                    u8 *e;
                    n = func_L01_00443A18(2.0f, 5.0f);
                    func_0038D890(&v5, &v4, &v1, a);
                    func_0038CF68(&v5, &v5, *(f32 *)(s + 0xC) * 0.3f);
                    e = func_L01_004713C8(&v2, &v5, (func_00382498(0x14, 0x1B) * 5 + 2) / 6,
                                          *(f32 *)(s + 0xC) * 231000.0f, *(s32 *)(s + 0x60), n, 0x4F, 0,
                                              *(f32 *)(s + 0xC) * 252000.02f, 0.0f, 1);
                    if (e != 0) {
                        e[2] = **(u8 **)(g + 0x170);
                    }
                    a = func_0038DAB8(a, 0.06346652f);
                }
            }
        }
        func_0038CB00(s + 0x14);
        func_L01_00404A10(func_L20_003F0088, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L20_003EEB40 */

INCLUDE_ASM("asm/levels", func_L20_003EF550);

INCLUDE_ASM("asm/levels", func_L20_003EFFE0);

INCLUDE_ASM("asm/levels", func_L20_003F0088);

/* localdecomp:start func_L20_003F0418 */
#include "vu0.h"
typedef struct { f32 x, y; } P2_3F0418;
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    P2_3F0418 uv[4];
    u8 pad70[0x18];
    unsigned long tag;
} G_3F0418;
typedef struct { vu0_v4 pos; u8 pad10[0x1D0 - 0x10]; vu0_v4 v1D0; u8 pad1E0[0x460 - 0x1E0]; } C_3F0418;
extern s32 D_001D52F0;
extern vu0_v4 D_L20_001D7C50[];
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003A9440(long, long);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);

void func_L20_003F0418(vu0_v4 *a0, s32 a1, s32 flag, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16)
{
    G_3F0418 g;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0, vF0;
    s32 i, j, k, m;
    char buf[16];
    C_3F0418 *c;

    func_003D93B0(&g, a1, 1, 0x80);
    g.tag = 0x800000004AUL;
    g.col[3] = 0x80808080;
    g.col[2] = 0x80808080;
    g.col[1] = 0x80808080;
    g.col[0] = 0x80808080;
    g.uv[0].x = 0; g.uv[0].y = 0;
    g.uv[1].x = 0; g.uv[1].y = 1.0f;
    g.uv[2].x = 1.0f; g.uv[2].y = 0;
    g.uv[3].x = 1.0f; g.uv[3].y = 1.0f;
    vC0 = *a0;
    vec_sub_ab(&v90, &D_L20_001E2E80[D_001D52F0].pos, &vC0);
    func_0038CF68(&v90, &v90, 1.0f);
    c = (C_3F0418 *)&D_L20_001E2E80[D_001D52F0];
    func_0038CE90(&vA0, &v90, &c->v1D0);
    func_0038CF68(&vA0, &vA0, 1.0f);
    func_0038CE90(&vB0, &vA0, &v90);
    if (f14 != 0.0f) {
        *(vu0_q *)&vD0 = 0;
        vD0.x = f14;
        func_0038D308(&vE0, &vD0);
        func_0038D5F0(&v90, &v90, &vE0);
    }
    func_0038CE20(&vD0, &v90, f13);
    vec_add_ab(&vC0, &vC0, &vD0);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&g.pos[i], &D_L20_001D7C50[i], f12);
        func_0038D028(&g.pos[i], &g.pos[i], &v90);
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&g, 0, 0);
    if (flag) {
        vE0 = g.pos[0];
        for (j = 1; j < 4; j++) {
            vec_add_ba(&vE0, &vE0, &g.pos[j]);
        }
        func_0038CE20(&vE0, &vE0, 0.25f);
        for (k = 0; k < 4; k++) {
            vec_sub_ba(&vF0, &g.pos[k], &vE0);
            func_0038CE20(&vF0, &vF0, 0.8f);
            vec_add_ab(&vF0, &vE0, &vF0);
            func_00389478(&vF0, &g.uv[k].x, &g.uv[k].y);
            if (0.0f < f16 && func_00382468(1) == 0) {
                f32 n = -f16;
                g.uv[k].x += func_003824E0(n, f16);
                g.uv[k].y += func_003824E0(n, f16);
            }
            if (g.uv[k].x > 1.0f) g.uv[k].x = 1.0f; else if (g.uv[k].x < 0.0f) g.uv[k].x = 0.0f;
            if (g.uv[k].y > 1.0f) g.uv[k].y = 1.0f; else if (g.uv[k].y < 0.0f) g.uv[k].y = 0.0f;
        }
    } else {
        for (m = 0; m < 4; m++) {
            func_00389478(&g.pos[m], &g.uv[m].x, &g.uv[m].y);
            if (func_00382468(1) == 0) {
                f32 n = -f16;
                g.uv[m].x += func_003824E0(n, f16);
                g.uv[m].y += func_003824E0(n, f16);
            }
            if (g.uv[m].x > 1.0f) g.uv[m].x = 1.0f; else if (g.uv[m].x < 0.0f) g.uv[m].x = 0.0f;
            if (g.uv[m].y > 1.0f) g.uv[m].y = 1.0f; else if (g.uv[m].y < 0.0f) g.uv[m].y = 0.0f;
        }
    }
    func_003D93B0(&g, -1, 1, 0x80);
    g.tag = 0x8000000054UL;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&g, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003F0418 */

/* localdecomp:start func_L20_003F0960 */
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);

void func_L20_003F0960(u8 *p)
{
    u8 *a = *(u8 **)(p + 0x68);

    if (func_0038CAD0(a) != 0) {
        func_003C2880(p);
        return;
    }
    p[0x23] = a[0];
}
/* localdecomp:end func_L20_003F0960 */
