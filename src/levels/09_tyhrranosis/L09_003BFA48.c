#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L09_003BF2F8.c, which this file was cut from */
extern void func_0038CE20(void *, void *, f32);

/* localdecomp:start func_L09_003BFA48 */
/* follows func_L09_003BFC90 (the same effect with the parameters fixed) */
typedef struct { u8 pad0[2]; u8 b2; u8 b3; } S_003BFA48;
typedef struct { u8 pad[0x5C]; u8 *p5C; } G_003BFA48;
typedef struct {
    u8 pad[0x20]; f32 f20; u8 pad24[4]; s32 i28; s32 i2C; u8 pad30[0x10]; f32 f40; u8 pad44[4]; s32 i48;
} T_003BFA48;
extern s32 func_L01_0044E1B8(void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern G_003BFA48 D_L09_00220018;
extern T_003BFA48 D_L09_001E2B80;

void func_L09_003BFA48(u8 *a0) {
    f32 vel[4];
    f32 pos[4];
    s32 i, n;
    f32 size;
    S_003BFA48 *s;

    if (func_L01_0044E1B8(a0, 13.666667f)) {
        D_L09_001E2B80.f20 = 0.2f;
        D_L09_001E2B80.i2C = 0;
        D_L09_001E2B80.i28 = 0x53;
        D_L09_001E2B80.i48 = 0x53;
        D_L09_001E2B80.f40 = 0.1f;
        for (i = 0; i < 30; i++) {
            size = func_003824E0(5.0f, 10.0f) * 210000.0f;
            vel[0] = func_L01_00443A18(0.10000001f, 0.20000002f);
            vel[1] = func_L01_00443A18(0.10000001f, 0.20000002f);
            vel[2] = func_003824E0(0.25f, 0.8f) * 0.020000001f;
            *(u128_t *)pos = *(u128_t *)(a0 + 0x10);
            pos[0] += func_L01_00443A18(0.0f, 0.6f);
            pos[1] += func_L01_00443A18(0.0f, 0.6f);
            pos[2] += func_L01_00443A18(0.0f, 0.2f);
            n = (func_00382498(0x23, 0x78) * 5 + 2) / 6;
            s = (S_003BFA48 *)func_L01_0046FB40(pos, vel, n, 0x10909090, func_00382468(2) ? 1 : -1, 50, 0, size, size, 0.0f, 0);
            if (s) {
                s->b2 = *D_L09_00220018.p5C;
                s->b3 = 0x44;
            }
        }
    }
}
/* localdecomp:end func_L09_003BFA48 */
