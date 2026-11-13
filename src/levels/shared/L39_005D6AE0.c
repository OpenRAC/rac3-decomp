#include "common.h"

/* localdecomp:start func_L39_005D6AE0 */
typedef union Buf_005D6AE0 {
    u8 b[8];
    u32 w[2];
    f32 f[2];
} Buf_005D6AE0;

extern u8 D_L39_004997E0[];
__asm__(".extern D_001D7EF0_sda, 8");
extern u8 *D_001D7EF0_sda[2];
extern s32 *D_00241120;
extern s32 func_L01_00517688(void);
extern s32 func_003E3E30(s32);
extern void func_L01_00517190(s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L39_005D6AE0(void) {
    s32 pl = func_L01_00517688();
    s32 v;
    s32 d0, d1, d2;
    s32 h;
    f32 sp;
    f32 s;
    f32 r;

    if (D_001D7EF0_sda[pl] != 0) {
        {
            u8 *q = D_001D7EF0_sda[pl] + 0x2476;
            if (*q == 0) {
                s = 0.0f;
            } else {
                Buf_005D6AE0 buf;
                u32 a;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                buf.w[0] = a;
                buf.w[1] ^= a;
                s = buf.f[1];
            }
        }
        s *= 100.0f;
        {
            u8 *q = D_001D7EF0_sda[pl] + 0x2554;
            if (*q == 0) {
                r = 0.0f;
            } else {
                Buf_005D6AE0 buf;
                u32 a;
                s32 n = *q;
                s32 k = ((u32)q - n) & 7;
                s32 m = n + 1;
                s32 i;
                u8 *d = buf.b;
                for (i = 0; i < 40; i += 5) {
                    *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
                }
                a = buf.w[0] ^ (u32)q;
                buf.w[0] = a;
                buf.w[1] ^= a;
                r = buf.f[1];
            }
        }
        v = (s32)(s / r);
    } else {
        v = 0;
    }
    sp = 0.068f;
    d0 = func_003E3E30(v % 10);
    d1 = func_003E3E30(v / 10 % 10);
    h = v / 100 % 10;
    d2 = func_003E3E30(h);
    func_L01_00517190(0x90003, d0);
    func_L01_00517190(0x90004, d1);
    func_L01_00517190(0x90005, d2);
    if (*D_00241120 == 2) {
        sp = 0.085f;
    }
    if (h != 0) {
        func_L01_00516470(0x90003, 0.52799f, sp);
        func_L01_00516470(0x90004, 0.48049f, sp);
        func_L01_00516AA0(0x90005, 1, 1);
    } else {
        func_L01_00516470(0x90003, 0.51799f, sp);
        func_L01_00516470(0x90004, 0.47049f, sp);
        func_L01_00516AA0(0x90005, 1, 0);
    }
}
/* localdecomp:end func_L39_005D6AE0 */

INCLUDE_ASM("asm/levels", func_L39_005D6DC8);
