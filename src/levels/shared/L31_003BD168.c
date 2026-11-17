#include "common.h"

/* localdecomp:start func_L31_003BD168 */
#include "vu0.h"
extern s32 D_001D545C;
extern u8 D_001BBB18[];
extern u8 D_001426E0[];
extern u8 D_001A4BE0[];
__asm__(".extern D_L31_001DEE28, 4");
extern s32 D_L31_001DEE28;
__asm__(".extern D_L31_001DEE30, 4");
extern f32 D_L31_001DEE30;
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(u8 *);
extern void func_L01_00451F60(s32, s32, s32);
extern s32 func_L01_004527A0(s32);
extern s32 func_L01_004527F0(s32);
extern void func_0039EF28(void);
extern void func_L31_003BD3B0(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L31_003BD168(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 i;
    s32 a;
    s32 b;
    u8 *g;

    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        if (*(s32 *)(v + 4) < 0 || D_001BBB18[D_001D545C - 5] != 0) {
            func_L01_004450F0(a0, 4, -1);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 1:
        if (func_L01_00456250(a0)) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            *(s32 *)v = 0;
            func_L01_00451F60(0xC93, -1, 0);
            D_001BBB18[D_001D545C - 5] = 1;
            if (D_001426E0[0xB9] == 0) {
                a = 0;
                b = 0;
                for (i = 0; i < 0x24; i++) {
                    a += func_L01_004527A0(i);
                    b += func_L01_004527F0(i);
                }
                if (a >= b) {
                    D_001426E0[0xB9] = 1;
                    func_0039EF28();
                    func_L01_00451F60(0x12B0, -1, 0);
                }
            }
        }
        func_L31_003BD3B0(a0);
        g = D_001A4BE0;
        if (*(s32 *)(g + 0x360) != 0 && *(s32 *)(g + 0x35C) == 0) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(v + 8) = D_L31_001DEE28;
        }
        func_L31_003BD3B0(a0);
        if (func_0038CAD0(v + 8)) {
            f32 d = func_0038DB00(*(f32 *)v, D_L31_001DEE30);
            if (fabs_asm(d) < 0.031415927f) {
                func_L01_004450F0(a0, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a0, 1);
            *(u16 *)(a0 + 0x34) |= 2;
        }
        break;
    }
}
/* localdecomp:end func_L31_003BD168 */

/* localdecomp:start func_L31_003BD3B0 */
#include "vu0.h"
extern f32 D_L31_001DEE1C;
__asm__(".extern D_L31_001DEE1C, 4");
extern f32 D_L31_001DEE20;
__asm__(".extern D_L31_001DEE20, 4");
extern f32 D_L31_001DEE24;
__asm__(".extern D_L31_001DEE24, 4");
extern s32 D_L31_001DEE28;
__asm__(".extern D_L31_001DEE28, 4");
extern f32 D_L31_001DEE2C;
__asm__(".extern D_L31_001DEE2C, 4");
extern f32 D_L31_001DEE30;
__asm__(".extern D_L31_001DEE30, 4");
extern f32 D_L31_001DEE34;
__asm__(".extern D_L31_001DEE34, 4");
extern f32 D_L31_001DEE38;
__asm__(".extern D_L31_001DEE38, 4");
extern s32 D_L31_001DEE3C;
__asm__(".extern D_L31_001DEE3C, 4");
extern s32 D_L31_001DEE40;
__asm__(".extern D_L31_001DEE40, 4");
extern f32 D_L31_001DEE44;
__asm__(".extern D_L31_001DEE44, 4");
extern f32 D_L31_001DEE48;
__asm__(".extern D_L31_001DEE48, 4");
extern f32 D_L31_001DEE4C;
__asm__(".extern D_L31_001DEE4C, 4");
extern s32 D_L31_001DEE50;
__asm__(".extern D_L31_001DEE50, 4");
extern f32 D_L31_001DEE54;
__asm__(".extern D_L31_001DEE54, 4");
extern f32 D_L31_001DEE58;
__asm__(".extern D_L31_001DEE58, 4");
extern f32 D_L31_001DEE5C;
__asm__(".extern D_L31_001DEE5C, 4");
extern u8 D_1A4C60[];
typedef struct {
    u8 pad0[0x24];
    f32 scale;
} C_003BD3B0;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 state;
    u8 pad21[3];
    C_003BD3B0 *pclass;
    u8 pad28[4];
    f32 scale;
    u8 pad30[0x68 - 0x30];
    f32 *pvar;
    u8 pad6C[0xF0 - 0x6C];
    f32 rx;
    f32 ry;
    f32 rz;
} M_003BD3B0;
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L01_00448690(void *, s32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L30_0034CE78(u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470(void *, void *, s32, s32, s32, s32, s32, s32, f32);

void func_L31_003BD3B0(u8 *a0) {
    M_003BD3B0 *m = (M_003BD3B0 *)a0;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 p;
    vu0_v4 q;
    vu0_v4 r;
    f32 *v = m->pvar;
    f32 s;
    f32 t;
    f32 sz;
    s32 i;

    if (m->state == 2) {
        s = D_L31_001DEE1C;
        v[0] = func_0038DAB8(v[0], D_L31_001DEE2C);
    } else {
        s = func_003C4088(D_L31_001DEE20, D_L31_001DEE1C,
                          (f32)((s32 *)v)[2] / (f32)(D_L31_001DEE28 + 1));
        if (((s32 *)v)[2] == 0) {
            t = fabs_asm(func_0038DB00(v[0], D_L31_001DEE30));
            if (1.5707964f < t) {
                t = 1.5707964f;
            } else if (t < -1.5707964f) {
                t = -1.5707964f;
            }
            t /= 1.5707964f;
            func_L01_00448690(v, 1, D_L31_001DEE30, D_L31_001DEE2C * t);
        } else {
            v[0] = func_0038DAB8(v[0], D_L31_001DEE2C);
        }
    }
    m->scale = func_003C4088(1.0f, D_L31_001DEE24, s / D_L31_001DEE1C) *
                         m->pclass->scale;
    qzero(&c);
    qzero(&b);
    b.z = 1.0f;
    c.y = -1.0f;
    func_0038D890(&a, &c, &b, D_L31_001DEE38);
    func_0038D890(&a, &a, &c, v[0]);
    func_0038CF68(&a, &a, s);
    vec_add_ba(&m->pos, D_1A4C60, &a);
    m->pos.z += func_L30_0034CE78(*(u8 **)(D_1A4C60 + 0x2540)) * 2;
    m->rx = func_0038DAB8(m->rx, D_L31_001DEE34);
    m->ry = -v[0];
    func_0038CE20(&p, m, 0.0009765625f);
    func_L01_00443B88(&q, D_L31_001DEE4C, D_L31_001DEE48);
    sz = D_L31_001DEE44;
        sz *= m->scale;
        sz /= m->pclass->scale;
    func_L01_0046C470(&p, &q, D_L31_001DEE40, D_L31_001DEE3C, func_00382468(0xFF) & 0xFF, 0, 0x40, 0, sz);
    for (i = 0; i < 3; i++) {
        func_L01_00443B88(&r, D_L31_001DEE5C, D_L31_001DEE58);
        vec_add_ab(&q, &q, &r);
        sz = D_L31_001DEE54;
        sz *= m->scale;
        sz /= m->pclass->scale;
        func_L01_0046C470(&p, &q, D_L31_001DEE50, D_L31_001DEE3C, func_00382468(0xFF) & 0xFF, 0, 0x40, 0, sz);
    }
}
/* localdecomp:end func_L31_003BD3B0 */
