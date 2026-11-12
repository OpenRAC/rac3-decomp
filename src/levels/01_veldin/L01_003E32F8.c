#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003E32F8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { f32 x, y, z, w; } W4;
typedef struct { char p0[0x10]; f32 x; f32 y; } H;
typedef struct { f32 x, y; char p[0x460 - 8]; } E;

extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E D_001E2A40[];
extern W4 D_001DF608;
extern f32 D_001DFB50;
extern f32 D_001DF5F8_sda;
__asm__(".extern D_001DF5F8_sda, 4");
extern f32 D_001DF5FC_sda;
__asm__(".extern D_001DF5FC_sda, 4");
extern f32 D_001DF600_sda;
__asm__(".extern D_001DF600_sda, 4");

extern f32 func_0040E9C0(f32 a, f32 b);
extern f32 func_0040F3F8(f32 a, f32 b);
extern f32 func_004439C0(f32 a, f32 b);
extern f32 func_00443A18(f32 a, f32 b);
extern void func_00443E10(V4 *v, f32 a, f32 b, f32 c);
extern s32 func_00443948(s32 a);
extern s32 func_00443978(s32 a, s32 b);
extern void func_L01_003298C8(V4 *a, V4 *b, s32 c, s32 d, s32 e, s32 f, W4 *g, s32 h, s32 i, s32 j, f32 k, f32 l);

void func_L01_003E32F8(H *a0, V4 *a1) {
    V4 v1;
    V4 v2;
    W4 v3;
    f32 a, b, c, d;
    s32 col, flag, n, t;

    E *e;
    e = &D_001E2A40[D_001D52F0];
    v2 = *a1;
    a = func_0040E9C0(e->x - a0->x, e->y - a0->y);
    b = func_004439C0(D_001DF5F8_sda * 0.300000011921f, D_001DF5F8_sda);
    b = b * 0.0200000014156f;
    c = func_00443A18(0.0f, 1.39626336098f);
    d = func_00443A18(0.0f, 1.57079637051f);
    func_00443E10(&v1, b, func_0040F3F8(a, d), c);
    col = 0x7F3F81A3;
    if (func_00443948(3)) col = 0x7F519DC5;
    v3 = D_001DF608;
    if (D_001DFB50 < 0.800000011920929f && func_00443948(4) == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    n = (func_00443978(100, 250) * 5 + 2) / 6;
    t = (s16)func_00443978(250, 300);
    func_L01_003298C8(&v2, &v1, n, flag, 0, col, &v3, 0, t, 400, D_001DF600_sda, D_001DF5FC_sda);
}
/* localdecomp:end func_L01_003E32F8 */

/* localdecomp:start func_L01_003E34F0 */


extern f32 D_001DF620_sda;
__asm__(".extern D_001DF620_sda, 4");
extern f32 D_001DF628_sda;
__asm__(".extern D_001DF628_sda, 4");
extern f32 D_001DF62C_sda;
__asm__(".extern D_001DF62C_sda, 4");
extern s32 D_001DF630_sda;
__asm__(".extern D_001DF630_sda, 4");
extern f32 D_001DF634_sda;
__asm__(".extern D_001DF634_sda, 4");
extern s32 D_001DF638_sda;
__asm__(".extern D_001DF638_sda, 4");
extern s32 D_001DF63C_sda;
__asm__(".extern D_001DF63C_sda, 4");
typedef struct { char p0[0x10]; u8 *a; char p1[0x170]; u8 *b; } S_221098;
extern S_221098 D_00221098;

extern void func_00443C30(V4 *v, f32 a, f32 b);
extern s32 func_00443978(s32 a, s32 b);
extern s32 func_00443948(s32 a);
extern f32 func_004439C0(f32 a, f32 b);
extern u8 *func_L01_00475C60(void *a0, V4 *v, s32 d, s32 e, s32 f, s32 g, s32 h, f32 a, f32 b, f32 c);

void func_L01_003E34F0(void *a0, s32 n, f32 sc) {
    V4 v;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 m;
    f32 t;
    f32 u;
    f32 w;
    u8 *p;
    u8 *q;

    func_00443C30(&v, D_001DF620_sda * 0.5f * 0.0200000014156f, D_001DF620_sda * 0.0200000014156f);
    for (i = 0; i < n; i++) {
        func_00443C30(&v, D_001DF628_sda * 0.5f * 0.0200000014156f, D_001DF628_sda * 0.0200000014156f);
        a = (D_001DF630_sda * 5 + 2) / 6;
        b = func_00443978(-1, 1);
        if (func_00443948(2) != 0) {
            c = D_001DF638_sda;
            d = D_001DF63C_sda;
        } else {
            c = D_001DF63C_sda;
            d = c;
        }
        m = d & 0xFFFFFF;
        t = D_001DF62C_sda * sc;
        u = t * 0.34999999404f;
        t = t * 210000.0f;
        u = u * 210000.0f;
        w = func_004439C0(D_001DF634_sda * 0.600000023842f, D_001DF634_sda);
        p = func_L01_00475C60(a0, &v, a, b, c, m, 0, t, u, w);
        if (p != 0) {
            p[9] = 0xF2;
            p[3] = 0x44;
            if (func_00443948(6) != 0) {
                q = D_00221098.a;
                p[2] = q[0];
            } else {
                q = D_00221098.b;
                p[2] = q[3];
            }
        }
    }
}
/* localdecomp:end func_L01_003E34F0 */

INCLUDE_ASM("asm/levels", func_L01_003E36E8);

/* localdecomp:start func_L01_003E37F0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E37F0;
extern f32 D_001DFB50;
extern void func_00450F00(void *, void *);
extern void func_003F8550(void *);
extern void func_0040E800(void *, void *, void *);
extern s32 func_0040DFF0(void *);
extern s32 func_00443948(s32);
extern void func_L01_003E36E8(void *);
extern void func_004450F0(void *, s32, s32);
extern void func_00439300(void *);

void func_L01_003E37F0(u8 *o) {
    V4_3E37F0 v0;
    V4_3E37F0 v10;
    u8 *p = *(u8 **)(o + 0x68);
    func_00450F00(o, &v0);
    func_003F8550(o);
    func_0040E800(&v10, p + 0x20, o + 0xC0);
    vec_add_ab(&v10, &v10, o + 0x10);
    switch (o[0x20]) {
    case 0:
        if (*(u8 **)(o + 0xB8) != 0) {
            o[0x23] = (*(u8 **)(o + 0xB8))[0x23];
        }
        if (*(s16 *)(*(u8 **)(o + 0xB8) + 0xAA) != 0x1A54 || func_00443948(4) == 0) {
            func_L01_003E36E8(o);
        }
        if (func_0040DFF0(p + 0x34) != 0 || (0.95f < D_001DFB50 && func_00443948(10) == 0)) {
            func_004450F0(o, 1, -1);
            *(u16 *)(o + 0x34) |= 0x2800;
        }
        break;
    case 1:
        if (o[0x23] < 2) {
            func_00439300(o);
        } else {
            o[0x23] = o[0x23] - 2;
        }
        break;
    }
}
/* localdecomp:end func_L01_003E37F0 */
