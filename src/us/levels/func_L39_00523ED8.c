#include "common.h"

/* NTSC-U counterpart of func_L39_00524380 (src/levels/shared/L39_00523B68.c) */
/* localdecomp:start func_L39_00523ED8 */
typedef int u128_t_00524380 __attribute__((mode(TI)));
extern void func_L01_00305A58(void *);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_0019D650();

void func_L39_00523ED8(u8 *self, f32 *p, void *a2, void *a3) {
    s32 i, j, off;
    u8 *rec;
    u8 *sub;
    u8 *obj = *(u8 **)(self + 0x68);
    f32 f, g;
    f32 *vec, *vel, *pos;
    s32 *rnd;

    for (i = 0; i < 10; i++) {
        rec = (u8 *)(i * 0x530 + *(s32 *)(obj + 0x60));
        if (*(s32 *)(rec + 0x514) != 0)
            continue;
        rnd = (s32 *)(rec + 0x4E0);
        pos = (f32 *)(rec + 0x500);
        vel = (f32 *)(rec + 0x4F0);
        vec = (f32 *)rec;
        for (j = 0; j < 2; j++) {
            off = j * 0x90;
            sub = rec + off;
            func_L01_00305A58(rec + (off + 0x2A0));
            func_L01_00305A58(rec + (off + 0x60));
            f = func_L39_005B2510(0.3f, 0.5f);
            *(f32 *)(sub + 0x64) *= f;
            *(f32 *)(sub + 0x74) *= f;
            *(f32 *)(sub + 0x84) *= f;
            *(f32 *)(sub + 0x94) *= f;
            g = func_L39_005B2510(0.9f, 1.0f);
            *(f32 *)(sub + 0x78) *= g;
            *(f32 *)(sub + 0x98) *= g;
            *(f32 *)(sub + 0x74) *= 0.4f;
            *(f32 *)(sub + 0x94) *= 0.4f;
            vec[0x20 / 4 + j * 4] = p[0] + func_L39_005B2510(-0.1f, 0.1f);
            vec[0x24 / 4 + j * 4] = p[1] + func_L39_005B2510(-0.1f, 0.1f);
            vec[0x28 / 4 + j * 4] = p[2];
            vec[0x2C / 4 + j * 4] = 1.0f;
            vel[j] = func_L39_005B2510(-0.02f, -0.01f);
            pos[j] = func_L39_005B2510(-7.99f, 0.0f);
            rnd[j] = func_0019D650() % 2;
        }
        *(s32 *)(rec + 0x510) = 0;
        *(s32 *)(rec + 0x514) = 1;
        *(s32 *)(rec + 0x518) = 0;
        *(s32 *)(rec + 0x51C) = 0;
        *(u128_t_00524380 *)(rec + 0x10) = *(u128_t_00524380 *)a3;
        *(u128_t_00524380 *)rec = *(u128_t_00524380 *)a2;
        return;
    }
}
/* localdecomp:end func_L39_00523ED8 */
