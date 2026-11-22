#include "common.h"


/* localdecomp:start func_L01_0032FBA0 */
extern s32 func_0038CAD0(u8 *);
extern void func_L01_0032FF68(void *);

void func_L01_0032FBA0(u8 *a) {
    if (((s32 (*)(s32))func_0038CAD0)(*(s32 *)(a + 104) + 68) == 0) {
        func_L01_0032FF68(a);
    }
}
/* localdecomp:end func_L01_0032FBA0 */

/* localdecomp:start func_L01_0032FBE0 */
void func_L01_0032FBE0(char *p)
{
    *(long *)(p + 112) = 0L;
    *(int *)(p + 80) = 0;
    *(int *)(p + 84) = 0;
    *(float *)(p + 88) = 1.0f;
    *(int *)(p + 92) = 0;
    *(int *)(p + 96) = 0;
    *(float *)(p + 100) = 1.0f;
    *(float *)(p + 104) = 1.0f;
    *(float *)(p + 108) = 1.0f;
    *(float *)(p + 8) = -2.0f;
    *(float *)(p + 24) = 2.0f;
    *(float *)(p + 40) = -2.0f;
    *(float *)(p + 56) = 2.0f;
    *(float *)(p + 4) = -2.0f;
    *(float *)(p + 36) = 2.0f;
    *(int *)(p + 0) = 0;
    *(int *)(p + 16) = 0;
    *(int *)(p + 32) = 0;
    *(int *)(p + 48) = 0;
    *(float *)(p + 12) = 1.0f;
    *(float *)(p + 28) = 1.0f;
    *(float *)(p + 44) = 1.0f;
    *(long *)(p + 128) = 0x0000FF9000000260L;
    *(float *)(p + 20) = -2.0f;
    *(float *)(p + 52) = 2.0f;
    *(float *)(p + 60) = 1.0f;
}
/* localdecomp:end func_L01_0032FBE0 */

INCLUDE_ASM("asm/levels", func_L01_0032FC70);

/* localdecomp:start func_L01_0032FF68 */
#include "vu0.h"
typedef struct {
    vu0_v4 m[4];
    u32 col[4];
    f32 uv[8];
    long l70;
    long l78;
    long l80;
    long l88;
} A_0032FF68;
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern vu0_v4 D_L01_001E29C0;
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_0032FC70(void *, void *);
extern long func_00389598(s32);
extern void func_L01_0032FBE0(char *);
extern s32 func_0013D3E0();
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_0032FF68(void *arg) {
    u8 *o = arg;
    u8 *s;
    A_0032FF68 a;
    A_0032FF68 b;
    vu0_v4 mat[4];
    vu0_v4 v160;
    vu0_v4 v170;
    vu0_v4 v180;
    vu0_v4 v190;
    vu0_v4 v1a0;
    f32 r;

    s = *(u8 **)(o + 0x68);
    if (D_L01_001DFB40 & 1) {
        func_003C2F58(o, 1, &v180);
    } else {
        func_003C2F58(o, 2, &v180);
    }
    v160 = v180;
    func_0038CF68(&v170, s + 0x30, func_003824E0(2.0f, 4.0f));
    func_0038D000(&v170, &v170, o + 0xC0);
    vec_add_ab(&v170, &v170, &v180);
    func_L01_0032FC70(o, &v160);
    a.l78 = func_00389598(0x17);
    a.l80 = 0x0000FF9000000260L;
    a.col[0] = a.col[1] = 0x7F103080;
    a.l70 = 0;
    a.l88 = 0x0000008000000048L;
    a.col[2] = a.col[3] = 0x103080;
    b.l78 = func_00389598(0x17);
    *(vu0_q *)&v190 = 0;
    *(vu0_q *)&v1a0 = 0;
    b.l80 = 0x0000FF9000000260L;
    b.l88 = 0x0000008000000048L;
    b.l70 = 0;
    b.col[2] = b.col[3] = 0x103080;
    b.col[0] = b.col[1] = 0x3F103080;
    v190.w = 1.0f;
    v1a0.w = 1.0f;
    r = func_003824E0(0.1f, 0.3f);
    v190.z = r;
    v1a0.z = r + r;
    func_L01_0032FBE0((char *)&a);
    func_L01_0032FBE0((char *)&b);
    if ((func_0013D3E0() & 1) == 0) {
        a.uv[0] = 0.0f;
        a.uv[1] = 0.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 1.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 0.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 1.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 0.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 1.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 0.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 1.0f;
    } else {
        a.uv[0] = 0.0f;
        a.uv[1] = 1.0f;
        a.uv[2] = 0.0f;
        a.uv[3] = 0.0f;
        a.uv[4] = 1.0f;
        a.uv[5] = 1.0f;
        a.uv[6] = 1.0f;
        a.uv[7] = 0.0f;
        b.uv[0] = 0.0f;
        b.uv[1] = 1.0f;
        b.uv[2] = 0.0f;
        b.uv[3] = 0.0f;
        b.uv[4] = 1.0f;
        b.uv[5] = 1.0f;
        b.uv[6] = 1.0f;
        b.uv[7] = 0.0f;
    }
    vec_sub_ab(&mat[0], &v170, &v160);
    func_0038CF68(&mat[0], &mat[0], 1.0f);
    vec_sub_ab(&mat[1], &D_L01_001E29C0, &v160);
    func_0038CE90(&mat[2], &mat[1], &mat[0]);
    func_0038CF68(&mat[2], &mat[2], 1.0f);
    func_0038CE90(&mat[1], &mat[0], &mat[2]);
    mat[3] = v160;
    a.m[0] = v190;
    b.m[0] = v1a0;
    func_0038CE20(&a.m[1], &a.m[0], -1.0f);
    func_0038CE20(&b.m[1], &b.m[0], -1.0f);
    func_0038D028(&a.m[0], &a.m[0], mat);
    func_0038D028(&a.m[1], &a.m[1], mat);
    func_0038D028(&b.m[0], &b.m[0], mat);
    func_0038D028(&b.m[1], &b.m[1], mat);
    v190.z = v190.z * 0.15f;
    v1a0.z = v190.z + v190.z;
    mat[3] = v170;
    a.m[2] = v190;
    b.m[2] = v1a0;
    func_0038CE20(&a.m[3], &a.m[2], -1.0f);
    func_0038CE20(&b.m[3], &b.m[2], -1.0f);
    func_0038D028(&a.m[2], &a.m[2], mat);
    func_0038D028(&a.m[3], &a.m[3], mat);
    func_0038D028(&b.m[2], &b.m[2], mat);
    func_0038D028(&b.m[3], &b.m[3], mat);
    func_003D2DA0(&a, 0, 0);
    func_003D2DA0(&b, 0, 0);
}
/* localdecomp:end func_L01_0032FF68 */

/* localdecomp:start func_L01_00330390 */
void func_L01_00330390(void *arg0) {
    if ((u8) (*(u8 *)((u8 *)arg0 + 0x20)) < 8U) {
        *(u8 *)((u8 *)arg0 + 0x20) = 8U;
    }
}
/* localdecomp:end func_L01_00330390 */

LINKER_REMNANT("asm/levels", func_L01_003303B0);

INCLUDE_ASM("asm/levels", func_L01_003303B8);

/* localdecomp:start func_L01_00330820 */
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
extern C_003EEB40 D_L01_001E2A40_00330820[];
extern u8 D_L01_001EAA20[];
extern f32 D_L01_002AF410[];
extern u8 D_L01_00221098[];
extern s32 D_L01_001DCF00;
__asm__(".extern D_L01_001DCF00, 4");

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
extern void func_L01_00404A10_00330820(void *, void *);
extern void func_L01_00331DD0(u8 *);
extern void func_003C2880(void *);

void func_L01_00330820(u8 *a0) {
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
        ang = func_0038D160(D_L01_001E2A40_00330820[D_001D52F0].pos.x - ((vu0_v4 *)(a0 + 0x10))->x,
                            D_L01_001E2A40_00330820[D_001D52F0].pos.y - ((vu0_v4 *)(a0 + 0x10))->y);
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
                k = (D_L01_001DCF00 + 1) % 44;
                v1.x = ((vu0_v4 *)(a0 + 0x10))->x + D_L01_002AF410[k] * *(f32 *)(s + 0xC);
                D_L01_001DCF00 = k;
                k = (D_L01_001DCF00 + 1) % 44;
                v1.y = ((vu0_v4 *)(a0 + 0x10))->y + D_L01_002AF410[k] * *(f32 *)(s + 0xC);
                D_L01_001DCF00 = k;
                k = (D_L01_001DCF00 + 1) % 44;
                v1.z = ((vu0_v4 *)(a0 + 0x10))->z + D_L01_002AF410[k] * *(f32 *)(s + 0xC);
                D_L01_001DCF00 = k;
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
            vec_sub_ba(&v2, &D_L01_001E2A40_00330820[D_001D52F0].pos, a0 + 0x10);
            func_0038CE90(&v3, &v2, &v1);
            func_0038CF68(&v3, &v3, 1.0f);
            g = D_L01_00221098;
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
                v1 = *(vu0_v4 *)(D_L01_001EAA20 + 0x20);
                v2 = *(vu0_v4 *)D_L01_001EAA20;
            } else {
                func_00382580(&v1, 1.0f, 1.0f);
                v2 = *(vu0_v4 *)(a0 + 0x10);
            }
            func_0038CF68(&v1, &v1, 0.05f);
            vec_add_ba(&v2, &v2, &v1);
            func_0038CF68(&v1, &v1, 1.0f);
            vec_sub_ba(&v3, &D_L01_001E2A40_00330820[D_001D52F0].pos, a0 + 0x10);
            func_0038CE90(&v4, &v3, &v1);
            func_0038CF68(&v4, &v4, 1.0f);
            if (*(s16 *)(s + 0x36) != 0) {
                u8 *g = D_L01_00221098;
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
                u8 *g = D_L01_00221098;
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
        func_L01_00404A10_00330820(func_L01_00331DD0, a0);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_00330820 */

INCLUDE_ASM("asm/levels", func_L01_00331230);

/* localdecomp:start func_L01_00331D28 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_331D28;
typedef struct { V4_331D28 v; void *f10; s32 f14; u8 f18, f19; u16 f1A; f32 f1C; s32 f20; } S_331D28;
typedef struct { u8 p0[0x64]; s32 f64; f32 f68; } E_331D28;
typedef struct { u8 p0[0x10]; u8 f10[0x58]; E_331D28 *f68; u8 p6C[0xAA - 0x6C]; u16 fAA; } O_331D28;
extern u8 D_L01_001D66B0;
extern void func_0038CF68(void *, void *, f32);
extern void func_003D4D00(void *, s32, s32, void *, f32);
void func_L01_00331D28(O_331D28 *o, f32 f) {
    S_331D28 s;
    E_331D28 *e;
    e = o->f68;
    s.f10 = o;
    s.f14 = e->f64;
    s.f1C = f;
    s.f20 = 1;
    s.v = *(V4_331D28 *)&D_L01_001D66B0;
    func_0038CF68(&s, &s, 1.0f);
    s.v.w = 5627.9248046875f;
    { u8 b = 2; s.f18 = 3; s.f19 = b; }
    s.f1A = o->fAA;
    func_003D4D00(o->f10, 0, 0, &s, e->f68);
}

/* localdecomp:end func_L01_00331D28 */

/* localdecomp:start func_L01_00331DD0 */
#include "vu0.h"
typedef struct { f32 inner, outer, brightness; u8 p0C[4]; s16 frame, duration, alpha, p16, ring, flash, p1C, beam; } State_00331DD0;
typedef struct { vu0_v4 pos; u8 pad10[0x1D0 - 0x10]; vu0_v4 v1D0; u8 pad1E0[0x460 - 0x1E0]; } C_00332160;
extern s16 D_L01_001CFEC0[];
extern s32 D_L01_001D52F0;
extern C_00332160 D_L01_001E2A40[];
extern void func_003A9440(long, long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_L01_00332160(vu0_v4 *, s32, f32, f32, f32, f32, f32, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);

void func_L01_00331DD0(u8 *obj) {
    u8 packet[0x90] __attribute__((aligned(16)));
    vu0_v4 camera, delta, rotated, center, side, up, temp;
    State_00331DD0 *state = *(State_00331DD0 **)(obj + 0x68);
    f32 scale;
    u32 color;
    if (state->flash != 0 && state->duration - state->frame < 2) {
        if (state->alpha != 0) {
            func_003A9440(0x42, 0x48);
            func_0038AF30(0, D_L01_001CFEC0[0xA9], 0, D_L01_001CFEC0[0xA8], (s32)0x80808080);
        }
    }
    if (state->ring != 0) {
        s32 remaining = state->duration - state->frame;
        if (remaining < 10) {
            func_L01_00332160((vu0_v4 *)(obj + 0x10), 0x3B,
                state->inner + (state->outer - state->inner) * ((f32)remaining / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        } else if ((u16)(state->frame - 46) < 4) {
            func_L01_00332160((vu0_v4 *)(obj + 0x10), 0x3B,
                state->inner + (state->outer - state->inner) * ((f32)(state->frame - 45) / 10.0f), 0.5f, 0.0f, 0.0f, 0.0f, 0);
        }
    }
    if (state->beam != 0 && state->alpha != 0) {
        func_003C5180(obj + 0x10, &camera, 1);
        scale = (f32)state->alpha * state->brightness;
        func_003D93B0(packet, 11, 4, 128);
        color = ((s32)(scale * 255.0f) << 24) | 0xFFFFFF;
        *(u32 *)(packet + 0x40) = *(u32 *)(packet + 0x44) = *(u32 *)(packet + 0x48) = *(u32 *)(packet + 0x4C) = color;
        *(f32 *)(packet + 0x50) = 0.0f;
        *(f32 *)(packet + 0x54) = 0.0f;
        *(f32 *)(packet + 0x58) = 0.0f;
        *(f32 *)(packet + 0x5C) = 1.0f;
        *(f32 *)(packet + 0x60) = 1.0f;
        *(f32 *)(packet + 0x64) = 0.0f;
        *(f32 *)(packet + 0x68) = 1.0f;
        *(f32 *)(packet + 0x6C) = 1.0f;
        vec_sub_ab(&delta, obj + 0x10, &D_L01_001E2A40[D_L01_001D52F0].pos);
        func_0038CF68(&rotated, &delta, 0.1f);
        vec_add_ba(&center, &D_L01_001E2A40[D_L01_001D52F0].pos, &rotated);
        func_0038CE90(&side, &delta, &camera);
        func_0038CF68(&side, &side, 0.075f);
        func_0038CE90(&up, &side, &delta);
        func_0038CF68(&up, &up, 0.075f);
        vec_add_ba(&temp, &center, &up);
        vec_add_ab(packet + 0x00, &temp, &side);
        vec_sub_ab(packet + 0x10, &temp, &side);
        vec_sub_ab(&temp, &center, &up);
        vec_add_ba(packet + 0x20, &temp, &side);
        vec_sub_ab(packet + 0x30, &temp, &side);
        func_003D2DA0(packet, 0, 0);
    }
}
/* localdecomp:end func_L01_00331DD0 */

/* localdecomp:start func_L01_00332160 */
typedef struct { f32 x, y; } P2_00332160;
typedef struct {
    vu0_v4 pos[4];
    u32 col[4];
    P2_00332160 uv[4];
    u8 pad70[0x18];
    unsigned long tag;
} G_00332160;
extern vu0_v4 D_L01_001D7C50[];
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

void func_L01_00332160(vu0_v4 *a0, s32 a1, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, s32 flag)
{
    G_00332160 g;
    vu0_v4 v90, vA0, vB0, vC0, vD0, vE0, vF0;
    s32 i, j, k, m;
    char buf[16];
    C_00332160 *c;

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
    vec_sub_ab(&v90, &D_L01_001E2A40[D_L01_001D52F0].pos, &vC0);
    func_0038CF68(&v90, &v90, 1.0f);
    c = (C_00332160 *)&D_L01_001E2A40[D_L01_001D52F0];
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
        func_0038CE20(&g.pos[i], &D_L01_001D7C50[i], f12);
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
/* localdecomp:end func_L01_00332160 */
