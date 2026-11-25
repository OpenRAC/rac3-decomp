#include "common.h"

/* localdecomp:start func_L41_0041B9C8 */
#include "vu0.h"
extern s32 *D_00241120;
extern s32 D_002412DC;
__asm__(".extern D_L41_002476F8, 4");
__asm__(".extern D_L41_00247704, 4");
__asm__(".extern D_L41_00247708, 4");
__asm__(".extern D_L41_0024770C, 4");
__asm__(".extern D_L41_00247710, 4");
__asm__(".extern D_L41_00247714, 4");
__asm__(".extern D_L41_00247718, 4");
extern s32 D_L41_002476F8;
extern f32 D_L41_00247704;
extern f32 D_L41_00247708;
extern f32 D_L41_0024770C;
extern f32 D_L41_00247710;
extern f32 D_L41_00247714;
extern f32 D_L41_00247718;
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L41_0041B350(void *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L41_0041B578(void *, f32, f32, f32);

void func_L41_0041B9C8(u8 *pos, s32 count, f32 scale, f32 lo, f32 hi) {
    vu0_v4 probe;
    s32 mode = 0;
    *(vu0_q *)&probe = *(vu0_q *)pos;
    probe.w = 5.0f;
    if (func_L39_005BE900(&probe, 0, 128.0f) != -1) {
        if (D_002412DC == 0x2D || D_002412DC == 0x37) {
            mode = 1;
        }
        if (!(*D_00241120 < 3)) {
            mode = 1;
        }
        if (count > 0) {
            do {
                if (mode != 0 || func_L39_005B4398(4) != 0) {
                    func_L41_0041B350(pos, D_L41_002476F8, 15.6f, D_L41_00247704, D_L41_00247708, D_L41_0024770C, D_L41_00247710, D_L41_00247714, D_L41_00247718);
                } else {
                    func_L41_0041B578(pos, scale, lo, hi);
                }
                count--;
            } while (count != 0);
        }
    }
}
/* localdecomp:end func_L41_0041B9C8 */

/* localdecomp:start func_L41_0041BAF8 */
extern f32 D_L41_0024A100[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern u8 *func_L01_004669B0(void *, f32, f32, f32, f32, s32, void *, u32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B4468(f32, f32);

void func_L41_0041BAF8(f32 *pos, s32 count, u32 arg2, f32 scale) {
    vu0_v4 probe;
    vu0_v4 p2;
    vu0_v4 dir;
    s32 sign = 1;
    s32 i;
    f32 ang;
    f32 r;
    f32 a;
    f32 b;
    u8 *p;
    u8 *q;
    *(vu0_q *)&probe = *(vu0_q *)pos;
    probe.w = 5.0f;
    if (func_L39_005BE900(&probe, 0, 128.0f) != -1) {
        ang = func_0038D160(D_L41_0024A100[0] - pos[0], D_L41_0024A100[1] - pos[1]);
        if (!(*D_00241120 < 3)) {
            count /= 3;
        }
        for (i = 0; i < count; i++) {
            sign = -sign;
            p2.x = pos[0] + func_L39_005B4468(0.0f, 1.0f) * scale;
            p2.y = pos[1] + func_L39_005B4468(0.0f, 1.0f) * scale;
            p2.z = pos[2] + func_L39_005B4468(0.0f, 1.0f) * scale;
            r = func_L39_005B4410(0.020000001f, 0.040000003f) * scale;
            a = func_L39_005B4468(0.0f, 1.3962634f);
            b = func_0038DAB8(ang, func_L39_005B4468(0.0f, 1.5707964f));
            func_00382760(&dir, r, b, a);
            p = func_L01_004669B0(&p2, 0.0f, 1.0f, 1.05f, scale * 1.5f * 210000.0f, sign, &dir, arg2, 0);
            if (p != 0) {
                q = p + 0x20;
                *(s16 *)(p + 0xA) = (func_L39_005B43C8(40, 70) * 5 + 2) / 6;
                p[9] = 0x44;
                *(s32 *)(q + 4) = 3;
                *(f32 *)(q + 0x1C) = (f32)((func_L39_005B43C8(1, 10) * 5 + 2) / 6);
                q[0xA] = 0x40;
                p[3] = 0x44;
                q[0xB] = p[0xA];
            }
        }
    }
}
/* localdecomp:end func_L41_0041BAF8 */
