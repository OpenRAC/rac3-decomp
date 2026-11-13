#include "common.h"

/* NTSC-U counterpart of func_L04_003E1B88 (src/levels/04_marcadia/L04_003E1B88.c) */
/* localdecomp:start func_L04_003DFC50 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E1B88;
typedef struct { u8 pad[0x5C]; u8 *p5C; } S_003E1B88;

extern S_003E1B88 D_L04_0021FC98;
__asm__(".extern D_L04_0021FC98, 16");
extern f32 func_003BE7F0(void *, s32, void *, f32);
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L04_003DFC50(s32 a0, s32 a1, V4_003E1B88 *a2, s32 a3) {
    V4_003E1B88 s;
    V4_003E1B88 p;
    V4_003E1B88 q;
    V4_003E1B88 *pp;
    V4_003E1B88 *qq;
    f32 d;
    f32 r;
    f32 t;
    s32 n;
    u8 *b;

    s = *a2;
    p = *a2;
    t = func_003BE7F0(&s, 0, 0, 0.5f);
    d = s.z - t;
    p.z = t;
    if (d > 0.0f && d < 12.0f) {
        r = (d - 6.0f) / 6.0f;
        if (r > 1.0f) {
            r = 1.0f;
        } else if (r < 0.0f) {
            r = 0.0f;
        }
        n = 127 - (s32)(r * 127.0f);
        if (n >= 15 && a3 > 0) {
            pp = &p;
            qq = &q;
            do {
                q.x = func_00388960(func_0037E2A8()) * 0.033333335f;
                q.y = func_00388978(func_0037E2A8()) * 0.033333335f;
                q.z = 0.0050000004f;
                b = func_L01_0046C468(pp, qq, 0x3C, 0x303234, func_0037E1D8(3), n, 7, 0, 63000.004f, 105000.0f, 0.0f);
                if (b != 0) {
                    b[2] = *D_L04_0021FC98.p5C;
                    b[3] = 0x48;
                }
                a3--;
            } while (a3 != 0);
        }
    }
}
/* localdecomp:end func_L04_003DFC50 */
