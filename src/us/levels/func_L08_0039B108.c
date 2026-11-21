#include "common.h"

/* NTSC-U counterpart of func_L08_0039CB60 (src/levels/08_aquatos/L08_0039C930.c) */
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L08_0039B108 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0039CB60;

extern s32 D_L08_001DE030_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE030_0039B108, 4");
extern s32 D_L08_001DE034_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE034_0039B108, 4");
extern s32 D_L08_001DE038_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE038_0039B108, 4");
extern f32 D_L08_001DE03C_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE03C_0039B108, 4");
extern f32 D_L08_001DE040_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE040_0039B108, 4");
extern f32 D_L08_001DE044_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE044_0039B108, 4");
extern f32 D_L08_001DE048_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE048_0039B108, 4");
extern f32 D_L08_001DE04C_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE04C_0039B108, 4");
extern s32 D_L08_001DE050_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE050_0039B108, 4");
extern f32 D_L08_001DE054_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE054_0039B108, 4");
extern f32 D_L08_001DE058_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE058_0039B108, 4");
extern f32 D_L08_001DE05C_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE05C_0039B108, 4");
extern f32 D_L08_001DE060_0039B108 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE060_0039B108, 4");
extern f32 D_L08_001DE064 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE064, 4");
extern s32 D_L08_001DE068 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE068, 4");
extern s32 D_L08_001DE06C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE06C, 4");
extern s32 D_L08_001DE070 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE070, 4");
extern s32 D_L08_001DE074 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE074, 4");
extern s32 D_L08_001DE078 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE078, 4");
extern s32 D_L08_001DE07C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE07C, 4");
extern f32 D_L08_001DE080 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE080, 4");
extern s32 D_L08_001DE084 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE084, 4");
extern s32 D_L08_001DE088 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE088, 4");
extern f32 D_L08_001DE08C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE08C, 4");
extern f32 D_L08_001DE090 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE090, 4");
extern f32 D_L08_001DE094 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE094, 4");
extern f32 D_L08_001DE098 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE098, 4");
extern f32 D_L08_001DE09C __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE09C, 4");
extern f32 D_L08_001DE0A0 __attribute__((section(".sdata")));
__asm__(".extern D_L08_001DE0A0, 4");
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_00470258(void *, void *, s32, s32, s16, u8, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039B108(u8 *m) {
    V_0039CB60 dir;
    V_0039CB60 a;
    V_0039CB60 b;
    V_0039CB60 c;
    s32 i;
    s32 j;
    s32 k;

    dir = *(V_0039CB60 *)(m + 0xE0);
    for (i = 0; i < D_L08_001DE07C; i++) {
        f32 s;
        func_00388830(&a, &dir, func_0037E250(D_L08_001DE08C, D_L08_001DE090) * 0.016666668f);
        func_003BF6A8(&a, D_L08_001DE0A0 * 0.016666668f);
        func_00388830(&b, &dir, D_L08_001DE080);
        vec_add_ab(&b, &b, m + 0x10);
        func_003BF6A8(&b, D_L08_001DE09C);
        s = func_0037E250(D_L08_001DE094, D_L08_001DE098) * 210000.0f;
        func_L01_00470258(&b, &a, D_L08_001DE084, D_L08_001DE088, func_0037E208(0x78, 0xF0), 0, s);
    }
    for (j = 0; j < D_L08_001DE030_0039B108; j++) {
        f32 ang;
        f32 r;
        f32 z;
        f32 n;
        a = *(V_0039CB60 *)(m + 0x10);
        func_003BF6A8(&a, D_L08_001DE04C_0039B108);
        a.z += 1.3f;
        ang = func_0037E2A8();
        r = func_0037E250(D_L08_001DE05C_0039B108, D_L08_001DE040_0039B108);
        z = func_0037E250(D_L08_001DE044_0039B108, D_L08_001DE048_0039B108);
        qzero(&b);
        b.x += func_00388960(ang) * (r * 0.016666668f);
        b.y += func_00388978(ang) * (r * 0.016666668f);
        b.z += z * 0.016666668f;
        c = b;
        c.z -= func_0037E250(D_L08_001DE03C_0039B108 * 0.7f, D_L08_001DE03C_0039B108 * 1.3f) * 0.00027777778f * (f32)D_L08_001DE034_0039B108;
        for (k = 0; k < D_L08_001DE050_0039B108; k++) {
            s32 c1;
            s32 c2;
            f32 f;
            f = func_0037E250(0.5f, 1.5f);
            b.w = f * D_L08_001DE060_0039B108;
            c.w = f * D_L08_001DE064;
            func_003BF6A8(&a, D_L08_001DE054_0039B108);
            func_003BF6A8(&c, D_L08_001DE058_0039B108 * 0.016666668f);
            c1 = func_003894A0(D_L08_001DE068, D_L08_001DE070, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(D_L08_001DE06C, D_L08_001DE074, func_0037E250(0.0f, 1.0f));
            n = (f32)D_L08_001DE038_0039B108;
            func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L08_001DE078, D_L08_001DE034_0039B108,
                func_0037E250(n * 0.5f, n * 2.5f), -1);
        }
    }
}
/* localdecomp:end func_L08_0039B108 */
