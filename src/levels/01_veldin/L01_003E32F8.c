#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003E32F8);

/* localdecomp:start func_L01_003E34F0 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

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

INCLUDE_ASM("asm/levels", func_L01_003E37F0);
