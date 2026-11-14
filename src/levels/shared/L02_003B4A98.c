#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_003B4D68;

typedef struct { s32 pad[0x14 / 4]; s32 i14; s32 i18; } S_003B5060;
typedef struct { u8 pad[0x42]; u8 f42; u8 pad43[0x25]; S_003B5060 *p68; } O_003B5060;
typedef struct { u8 pad[0x70]; u128_t v70; } E_003B5060;

typedef struct { f32 x, y, z, w; } V4_003B5710;

INCLUDE_ASM("asm/levels", func_L02_003B4A98);

/* localdecomp:start func_L02_003B4D68 */
extern u8 D_001A4BE0[];
extern u8 D_001D5469;
extern s32 D_L02_001DE2DC;
extern G_003B4D68 D_001CCFD0;
extern void func_003C7C38(void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_0038A238(s32);
extern void func_L02_004C2D20(s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_003EB438(s32, void *, void *, s32, s32, s32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern void func_003A2B68(s32, s32);
extern void func_003A1798(void);
void func_L02_003B4D68(u8 *a0) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 v2[4];
    f32 w2[4];
    u8 *h;
    *(s32 *)(a0 + 0x98) = 0;
    func_003C7C38(a0);
    v[0] = func_0038D098(*(f32 *)(q + 0x2C)) * 2.5f;
    v[1] = func_0038D0B0(*(f32 *)(q + 0x2C)) * 2.5f;
    v[2] = 0.0f;
    vec_add_ab(v, v, q + 0x20);
    qzero(w);
    w[2] = func_0038DAB8(*(f32 *)(q + 0x2C), 3.1415927f);
    func_0038A238(8);
    h = D_001A4BE0;
    if (h[0x25E4] == 3) {
        func_L02_004C2D20(0);
    }
    func_L01_004F50C8(v, w, 0x74, 0);
    func_003A52A0(0, 0, a0);
    v2[0] = func_0038D098(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[1] = func_0038D0B0(*(f32 *)(q + 0x2C)) * 1.25f;
    v2[2] = 0.0f;
    v2[0] = v2[0] + func_0038D098(func_0038DAB8(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    v2[1] = v2[1] + func_0038D0B0(func_0038DAB8(*(f32 *)(q + 0x2C), 1.5707964f)) * 4.0f;
    vec_add_ab(v2, v2, q + 0x20);
    v2[2] = v2[2] + 1.0f;
    qzero(w2);
    w2[2] = func_0038DB00(*(f32 *)(q + 0x2C), 1.5707964f);
    func_L01_003EB438(0, v2, w2, 1, 0, 0);
    func_L01_003EB350(0, v2);
    func_L01_003EB3C0(0, w2);
    *(u128_t *)(a0 + 0x10) = *(u128_t *)(h + 0x80);
    *(u128_t *)(a0 + 0xF0) = *(u128_t *)(h + 0x90);
    if (a0[0x43] != 1) {
        func_003C3A10(a0, 1, 0, 0);
    }
    func_L01_0050FB40(0x66, 0, 0.0f);
    if (D_001D5469 != 0) {
        *(u16 *)(a0 + 0x34) |= 0x8000;
    }
    h[0x25F0] = 1;
    D_L02_001DE2DC = 1;
    a0[0x20] = 2;
    *(s32 *)(q + 0x7C) = 0x32;
    if (D_001CCFD0.i6C == 0) {
        if (D_001CCFD0.i24 == -1 && D_001CCFD0.i94 == 0) {
            func_003A2B68(0xEB8, 0);
        }
    }
    if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L02_003B4D68 */

/* localdecomp:start func_L02_003B5060 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern E_003B5060 *D_L02_001DEA80;
extern f32 func_L01_004395E0(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);
extern void func_L01_003EB350(s32, void *);
extern void func_L01_003EB3C0(s32, void *);
void func_L02_003B5060(O_003B5060 *o) {
    S_003B5060 *p = o->p68;
    f32 v[4];
    f32 w[4];
    f32 q1[4];
    f32 q2[4];
    f32 s;
    f32 a;
    if (o->f42 == 1) {
        a = func_L01_004395E0(o);
    } else {
        a = 170.0f;
    }
    s = a / 170.0f;
    if (p->i14 == -1 || p->i18 == -1) {
        u8 *h = D_001A4BE0;
        f32 ang = func_0038DAB8(s * 0.6981317f - 0.34906584f, *(f32 *)(h + 0x98));
        v[0] = func_0038D098(ang) * 5.0f;
        v[1] = func_0038D0B0(ang) * 5.0f;
        v[2] = 0.0f;
        vec_add_ba(v, v, h + 0x80);
        v[2] = v[2] + 1.0f;
        qzero(w);
        w[2] = func_0038DAB8(ang, 3.14159f);
        w[1] = s * -0.17f;
    } else {
        func_0038CDF8(v, (f32 *)((u8 *)D_L02_001DEA80 + (p->i14 << 7) + 0x30), (f32 *)((u8 *)D_L02_001DEA80 + (p->i18 << 7) + 0x30), s);
        *(u128_t *)q1 = D_L02_001DEA80[p->i14].v70;
        *(u128_t *)q2 = D_L02_001DEA80[p->i18].v70;
        w[2] = func_0038DAB8(func_0038DB00(q2[2], q1[2]) * s, q1[2]);
        w[1] = func_0038DAB8(func_0038DB00(q2[1], q1[1]) * s, q1[1]);
        w[0] = func_0038DAB8(func_0038DB00(q2[0], q1[0]) * s, q1[0]);
    }
    func_L01_003EB350(0, v);
    func_L01_003EB3C0(0, w);
}
/* localdecomp:end func_L02_003B5060 */

INCLUDE_ASM("asm/levels", func_L02_003B5268);

/* localdecomp:start func_L02_003B5710 */
#include "vu0.h"
extern u8 D_L02_001E1280[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern f32 func_L01_00443A18(f32, f32);
extern u8 *func_L01_0046B458(f32 *, f32, s32, f32, f32, s32, s32, s32, f32 *, s32);


void func_L02_003B5710(f32 *pos, s32 count) {
    f32 velocity[4], origin[4];
    V4_003B5710 direction;
    V4_003B5710 axis;
    f32 offset[4];
    f32 size, zero, angle, k;
    s32 sign;
    s32 i;
    u8 *p;

    vec_sub_ab(&direction, D_L02_001E1280, pos);
    func_0038CF68(offset, &direction, 0.3f);
    direction.z = 0;
    axis.x = 0;
    axis.y = 0;
    axis.z = 1.0f;
    axis.w = 1.0f;
    i = 0;
    if (count > 0) {
    k = 0.020000001f;
    zero = direction.z;
    for (; i < count; i++) {
        size = func_003824E0(0.5f, 2.0f);
        sign = func_00382468(2);
        if (!sign) sign--;
        angle = func_003824E0(-1.0471976f, 1.0471976f);
        func_0038D890(velocity, &direction, &axis, angle);
        func_0038CF68(velocity, velocity, func_003824E0(0.05f, 3.0f) * k);
        velocity[2] = func_003824E0(1.0f, 5.0f) * k;
        vec_add_ab(origin, pos, offset);
        pos[0] += func_L01_00443A18(zero, 0.15f);
        pos[1] += func_L01_00443A18(zero, 0.15f);
        pos[2] += func_L01_00443A18(zero, 0.15f);
        p = func_L01_0046B458(origin, size * 0.1f, 0x32, size, 0.0028800003f, 0xDD10FFFF, 0, sign, velocity, 0);
        if (p) p[9] = 0x74;
        p = func_L01_0046B458(origin, size * 0.07f, 0x32, size * 0.7f, 0.0028800003f, 0xDD10FFFF, 1, -sign, velocity, 0);
        if (p) p[9] = 0x74;
    }
    }
}
/* localdecomp:end func_L02_003B5710 */
