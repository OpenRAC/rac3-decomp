#include "common.h"

/* NTSC-U counterpart of func_L08_0039EFB0 (src/levels/08_aquatos/L08_0039ED70.c) */
#include "vu0.h"
#include "vu0.h"
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);

/* localdecomp:start func_L08_0039D488 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0039EFB0;

extern s32 D_L08_001DE0F0_0039D488;
__asm__(".extern D_L08_001DE0F0_0039D488, 4");
extern s32 D_L08_001DE0F4_0039D488;
__asm__(".extern D_L08_001DE0F4_0039D488, 4");
extern s32 D_L08_001DE0F8_0039D488;
__asm__(".extern D_L08_001DE0F8_0039D488, 4");
extern f32 D_L08_001DE0FC_0039D488;
__asm__(".extern D_L08_001DE0FC_0039D488, 4");
extern f32 D_L08_001DE100_0039D488;
__asm__(".extern D_L08_001DE100_0039D488, 4");
extern f32 D_L08_001DE104_0039D488;
__asm__(".extern D_L08_001DE104_0039D488, 4");
extern f32 D_L08_001DE108_0039D488;
__asm__(".extern D_L08_001DE108_0039D488, 4");
extern f32 D_L08_001DE10C_0039D488;
__asm__(".extern D_L08_001DE10C_0039D488, 4");
extern s32 D_L08_001DE110_0039D488;
__asm__(".extern D_L08_001DE110_0039D488, 4");
extern f32 D_L08_001DE114_0039D488;
__asm__(".extern D_L08_001DE114_0039D488, 4");
extern f32 D_L08_001DE118_0039D488;
__asm__(".extern D_L08_001DE118_0039D488, 4");
extern f32 D_L08_001DE11C_0039D488;
__asm__(".extern D_L08_001DE11C_0039D488, 4");
extern f32 D_L08_001DE120_0039D488;
__asm__(".extern D_L08_001DE120_0039D488, 4");
extern f32 D_L08_001DE124;
__asm__(".extern D_L08_001DE124, 4");
extern s32 D_L08_001DE128_0039D488;
__asm__(".extern D_L08_001DE128_0039D488, 4");
extern s32 D_L08_001DE12C;
__asm__(".extern D_L08_001DE12C, 4");
extern s32 D_L08_001DE130_0039D488;
__asm__(".extern D_L08_001DE130_0039D488, 4");
extern s32 D_L08_001DE134;
__asm__(".extern D_L08_001DE134, 4");
extern s32 D_L08_001DE138;
__asm__(".extern D_L08_001DE138, 4");
extern s32 D_L08_001DE13C;
__asm__(".extern D_L08_001DE13C, 4");
extern f32 D_L08_001DE140_0039D488;
__asm__(".extern D_L08_001DE140_0039D488, 4");
extern s32 D_L08_001DE144;
__asm__(".extern D_L08_001DE144, 4");
extern s32 D_L08_001DE148;
__asm__(".extern D_L08_001DE148, 4");
extern f32 D_L08_001DE14C;
__asm__(".extern D_L08_001DE14C, 4");
extern f32 D_L08_001DE150;
__asm__(".extern D_L08_001DE150, 4");
extern f32 D_L08_001DE154;
__asm__(".extern D_L08_001DE154, 4");
extern f32 D_L08_001DE158;
__asm__(".extern D_L08_001DE158, 4");
extern f32 D_L08_001DE15C;
__asm__(".extern D_L08_001DE15C, 4");
extern f32 D_L08_001DE160_0039D488;
__asm__(".extern D_L08_001DE160_0039D488, 4");

extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_00470258(void *, void *, s32, s32, s16, u8, f32);
extern s32 func_L01_0045FEC8(void *, void *, void *, s32, s32, s32, s32, s32, s32);

void func_L08_0039D488(u8 *m) {
    V4_0039EFB0 rot;
    V4_0039EFB0 a;
    V4_0039EFB0 b;
    V4_0039EFB0 c;
    s32 i, j, k;
    f32 f, ang, r, z, t, g, s;
    s32 c1, c2;

    rot = *(V4_0039EFB0 *)(m + 0xE0);
    for (i = 0; i < D_L08_001DE13C; i++) {
        func_00388830(&a, &rot, func_0037E250(D_L08_001DE14C, D_L08_001DE150) * 0.0166666675359f);
        func_003BF6A8(&a, D_L08_001DE160_0039D488 * 0.0166666675359f);
        func_00388830(&b, &rot, D_L08_001DE140_0039D488);
        vec_add_ab(&b, &b, m + 0x10);
        func_003BF6A8(&b, D_L08_001DE15C);
        f = func_0037E250(D_L08_001DE154, D_L08_001DE158) * 210000.0f;
        func_L01_00470258(&b, &a, D_L08_001DE144, D_L08_001DE148, func_0037E208(0x78, 0xF0), 0, f);
    }
    for (j = 0; j < D_L08_001DE0F0_0039D488; j++) {
        a = *(V4_0039EFB0 *)(m + 0x10);
        func_003BF6A8(&a, D_L08_001DE10C_0039D488);
        a.z += 0.7f;
        ang = func_0037E2A8();
        r = func_0037E250(D_L08_001DE11C_0039D488, D_L08_001DE100_0039D488);
        z = func_0037E250(D_L08_001DE104_0039D488, D_L08_001DE108_0039D488);
        qzero(&b);
        b.x += func_00388960(ang) * (r * 0.0166666675359f);
        b.y += func_00388978(ang) * (r * 0.0166666675359f);
        b.z += z * 0.0166666675359f;
        c = b;
        t = func_0037E250(D_L08_001DE0FC_0039D488 * 0.7f, D_L08_001DE0FC_0039D488 * 1.3f);
        c.z -= t * 0.000277777784504f * (f32)(D_L08_001DE0F4_0039D488);
        for (k = 0; k < D_L08_001DE110_0039D488; k++) {
            s = func_0037E250(0.5f, 1.5f);
            b.w = s * D_L08_001DE120_0039D488;
            c.w = s * D_L08_001DE124;
            func_003BF6A8(&a, D_L08_001DE114_0039D488);
            func_003BF6A8(&c, D_L08_001DE118_0039D488 * 0.0166666675359f);
            c1 = func_003894A0(D_L08_001DE128_0039D488, D_L08_001DE130_0039D488, func_0037E250(0.0f, 1.0f));
            c2 = func_003894A0(D_L08_001DE12C, D_L08_001DE134, func_0037E250(0.0f, 1.0f));
            g = (f32)D_L08_001DE0F8_0039D488;
            g = func_0037E250(g * 0.5f, g * 2.5f);
            func_L01_0045FEC8(&a, &b, &c, c1, c2, D_L08_001DE138, D_L08_001DE0F4_0039D488,
                (s32)g, -1);
        }
    }
}
/* localdecomp:end func_L08_0039D488 */
