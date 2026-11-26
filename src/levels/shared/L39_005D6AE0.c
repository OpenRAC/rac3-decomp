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

/* localdecomp:start func_L39_005D6DC8 */
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_001D7EE8_sda, 8");
__asm__(".extern D_001DA5F0_sda, 4");
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_005D6DC8;
typedef struct { u8 pad[0x4A]; s16 f4A; } W_005D6DC8;
extern S_005D6DC8 D_L39_0024CD50;
extern s32 *D_L39_00241120;
extern u8 D_001D7EE8_sda[8];
extern f32 D_001D7F00_sda;
__asm__(".extern D_001D7F00_sda, 4");
extern f32 D_001D7F04_sda;
__asm__(".extern D_001D7F04_sda, 4");
extern s32 D_001DA5F0_sda;
extern s32 D_L39_0024C278;
extern s32 func_L01_00517688(void);
extern void func_L01_004D2110(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E51F8(s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_005170B8(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516C78_005D6DC8(s32, s32, s32);
extern void func_L01_00517190(s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void func_003E8348(s32, s32);
extern void func_003E8630(s32, s32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005D6AE0(void);

void func_L39_005D6DC8(s32 arg0) {
    S_005D6DC8 *q;
    s32 *base;
    void *p;
    void *w;
    f32 a;
    f32 b;

    D_001D7EE8_sda[func_L01_00517688()] = 1;
    func_L01_004D2110(1);
    func_0038CB78(&D_L39_0024C278, 0, 4);
    func_003B5060(0x90000);
    func_003E5090(0x90001);
    func_003E5090(0x90002);
    func_003E51F8(0x90006);
    func_003E51F8(0x90003);
    func_003E51F8(0x90004);
    func_003E51F8(0x90005);
    func_L39_00611AC8(0x90002, func_00392A18(), 0x52);
    func_L39_00611AC8(0x90001, func_00392A18(), 0x53);
    if (*D_L39_00241120 == 2) {
        b = 0.085f;
        func_L01_00516470(0x90002, D_001D7F00_sda, D_001D7F04_sda);
        func_L01_00516470(0x90001, D_001D7F00_sda, D_001D7F04_sda);
        func_L01_00516470(0x90006, 0.358f, 0.095f);
        func_L01_00517538(0x90006, 0.28f, 0.07f);
    } else {
        b = 0.068f;
        func_L01_00516470(0x90006, 0.358f, 0.074f);
        func_L01_00517538(0x90006, 0.28f, 0.048f);
    }
    func_L01_00516470(0x90003, 0.52799f, b);
    a = 0.035f;
    func_L01_00516470(0x90004, 0.48049f, b);
    func_L01_00516470(0x90005, 0.43747f, b);
    func_L01_005170B8(0x90001, 0x331465B7);
    func_L01_005170B8(0x90002, 0x332299DE);
    func_L01_005170B8(0x90003, 0x8066CCFF);
    func_L01_005170B8(0x90004, 0x706EC8FF);
    func_L01_005170B8(0x90005, 0x8066CCFF);
    func_L01_00517538(0x90003, a, a);
    func_L01_00517538(0x90004, a, a);
    func_L01_00517538(0x90005, a, a);
    func_L01_00516AA0(0x90003, 0x40, 1);
    func_L01_00516AA0(0x90004, 0x40, 1);
    func_L01_00516AA0(0x90005, 0x40, 1);
    func_L01_005170B8(0x90006, 0x3666CCFF);
    func_L01_00516C78_005D6DC8(0x90006, 1, 3);
    func_L01_00517190(0x90003, 0xED1C);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x90003);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D6DC8 *)w)->f4A = 0;
    func_L01_00517190(0x90004, 0xED1D);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x90004);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D6DC8 *)w)->f4A = 0;
    func_L01_00517190(0x90005, 0xED1E);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x90005);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D6DC8 *)w)->f4A = 0;
    func_003E8630(0x90000, 0x90001);
    func_003E8630(0x90000, 0x90002);
    func_003E8630(0x90000, 0x90006);
    func_003E8630(0x90000, 0x90003);
    func_003E8630(0x90000, 0x90004);
    func_003E8630(0x90000, 0x90005);
    func_003E8348(7, 0x90000);
    func_003E6FF0(arg0, 1);
    func_L39_005D6AE0();
    func_L01_004D2110(0);
}
/* localdecomp:end func_L39_005D6DC8 */
