/* functional: high. Rewritten from the PAL disassembly (the NTSC draft differs: PAL stores (r*5+2)/6 sizes). 81 instructions differ (frame size and scheduling). */
#include "common.h"
/* localdecomp:start func_L41_0041BAF8 */
#include "vu0.h"
extern s32 *D_00241120;
extern f32 D_L41_0024A100[];
extern s32 func_L39_005BE900(void *, s32, f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern s32 func_L39_005B43C8(s32, s32);

void func_L41_0041BAF8(f32 *pos, s32 n, u32 col, f32 scale) {
    vu0_v4 probe;
    f32 t[4];
    vu0_v4 dir;
    f32 base;
    f32 size;
    f32 pitch;
    f32 yaw;
    s32 sign;
    s32 i;
    u8 *e;
    u8 *p;
    s32 r;
    *(vu0_q *)&probe = *(vu0_q *)pos;
    probe.w = 5.0f;
    if (func_L39_005BE900(&probe, 0, 128.0f) == -1) {
        return;
    }
    base = func_0038D160(D_L41_0024A100[0] - pos[0], D_L41_0024A100[1] - pos[1]);
    if (!(*D_00241120 < 3)) {
        n = n / 3;
    }
    sign = 1;
    if (n > 0) {
        for (i = n; i != 0; i--) {
            sign = -sign;
            t[0] = pos[0] + func_L39_005B4468(0.0f, 1.0f) * scale;
            t[1] = pos[1] + func_L39_005B4468(0.0f, 1.0f) * scale;
            t[2] = pos[2] + func_L39_005B4468(0.0f, 1.0f) * scale;
            size = func_L39_005B4410(0.020000001f, 0.040000003f) * scale;
            pitch = func_L39_005B4468(0.0f, 1.3962634f);
            yaw = func_L39_005B4468(0.0f, 1.5707964f);
            func_00382760(&dir, size, func_0038DAB8(base, yaw), pitch);
            e = func_L01_004669B0(t, 0.0f, 1.0f, 1.05f, scale * 1.5f * 210000.0f, sign, &dir, col, 0);
            if (e != 0) {
                r = func_L39_005B43C8(40, 70);
                p = e + 0x20;
                e[9] = 0x44;
                *(s16 *)(e + 0xA) = (r * 5 + 2) / 6;
                *(s32 *)(p + 4) = 3;
                r = func_L39_005B43C8(1, 10);
                p[0xA] = 0x40;
                *(f32 *)(p + 0x1C) = (f32)((r * 5 + 2) / 6);
                e[3] = 0x44;
                p[0xB] = e[0xA];
            }
        }
    }
}
/* localdecomp:end func_L41_0041BAF8 */
