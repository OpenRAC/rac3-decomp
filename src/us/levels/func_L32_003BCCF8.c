#include "common.h"

/* NTSC-U counterpart of func_L32_003BE960 (src/levels/32_vidcomic_4/L32_003BE960.c) */
/* localdecomp:start func_L32_003BCCF8 */
#include "vu0.h"
extern s32 func_L01_00452EC8(void *);
extern void func_0039FB08(s32);
extern s32 func_L01_004A72A8(s32, s32, s32, s32);
extern void func_L30_0034B9C8(void *, void *);
extern f32 func_L03_0034A880(s32, s32, s32, f32, f32, f32);
extern void func_L30_0034BD48(void *, void *, void *, s32, s32, f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_0037E250(f32, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_0037E208(s32, s32);
extern s32 func_003894A0(s32, s32, f32);
extern void func_L01_0046C468(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern u8 D_001A30B0[];
extern u8 D_L32_001E2590_003BCCF8[] __attribute__((section(".sdata")));
extern u8 D_L32_001D66B0_003BCCF8[] __attribute__((section(".sdata")));
__asm__(".extern D_L32_001DF1F4, 4");
extern f32 D_L32_001DF1F4;
__asm__(".extern D_L32_001DF1F8, 4");
extern f32 D_L32_001DF1F8;
__asm__(".extern D_L32_001DF200, 4");
extern f32 D_L32_001DF200;
__asm__(".extern D_L32_001DF204, 4");
extern f32 D_L32_001DF204;
__asm__(".extern D_L32_001DF208, 4");
extern s32 D_L32_001DF208;
__asm__(".extern D_L32_001DF20C, 4");
extern s32 D_L32_001DF20C;
__asm__(".extern D_L32_001DF214_003BCCF8, 4");
extern s32 D_L32_001DF214_003BCCF8;
__asm__(".extern D_L32_001DF220_003BCCF8, 4");
extern f32 D_L32_001DF220_003BCCF8;
__asm__(".extern D_L32_001DF224_003BCCF8, 4");
extern f32 D_L32_001DF224_003BCCF8;
__asm__(".extern D_L32_001DF254, 4");
extern s32 D_L32_001DF254;
__asm__(".extern D_L32_001DF258, 4");
extern s32 D_L32_001DF258;
__asm__(".extern D_L32_001DF25C, 4");
extern s32 D_L32_001DF25C;
__asm__(".extern D_L32_001DF260, 4");
extern f32 D_L32_001DF260;
__asm__(".extern D_L32_001DF264, 4");
extern s32 D_L32_001DF264;
__asm__(".extern D_L32_001DF268, 4");
extern s32 D_L32_001DF268;
__asm__(".extern D_L32_001DF26C, 4");
extern f32 D_L32_001DF26C;
__asm__(".extern D_L32_001DF270, 4");
extern f32 D_L32_001DF270;
__asm__(".extern D_L32_001DF274, 4");
extern f32 D_L32_001DF274;
__asm__(".extern D_L32_001DF278, 4");
extern f32 D_L32_001DF278;
__asm__(".extern D_L32_001DF27C, 4");
extern f32 D_L32_001DF27C;
__asm__(".extern D_L32_001DF280, 4");
extern f32 D_L32_001DF280;
__asm__(".extern D_L32_001DF284, 4");
extern f32 D_L32_001DF284;
__asm__(".extern D_L32_001DF288, 4");
extern f32 D_L32_001DF288;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BE960;
typedef struct { u8 pad[0x14]; s32 flags; u8 pad2[0x18]; } S_003BE960;
typedef struct {
    f32 f00;
    s32 f04;
    s32 f08;
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} V_003BE960;

void func_L32_003BCCF8(u8 *o) {
    V_003BE960 *v = *(V_003BE960 **)(o + 0x68);
    f32 scale;
    f32 h;
    s32 i;
    V4_003BE960 p;
    V4_003BE960 q;
    S_003BE960 s;

    if (func_L01_00452EC8(o) != 0) {
        v->f04 = D_L32_001DF208;
        if (v->f3C != -1) {
            u8 *t = D_001A30B0 + v->f3C * 0x80;
            if (*(u8 **)(t + 0xDC) == o && t[0xD0] != 0) {
                func_0039FB08(v->f3C);
            }
        }
        v->f3C = -1;
        func_L01_004A72A8(0xC, 0, (s32)o, 0x19D1);
    }
    if (v->f04 >= D_L32_001DF208 - D_L32_001DF214_003BCCF8) {
        func_L30_0034B9C8(D_L32_001E2590_003BCCF8, o);
    }
    if (D_L32_001DF208 - D_L32_001DF214_003BCCF8 < v->f04) {
        scale = func_L03_0034A880(1, 0, 4, (f32)(v->f04 - D_L32_001DF208 + D_L32_001DF214_003BCCF8),
                                  (f32)(D_L32_001DF214_003BCCF8 + 1), 1.0f);
    } else {
        scale = 1.0f;
    }
    h = D_L32_001DF200 * scale;
    if (D_L32_001DF208 - D_L32_001DF20C < v->f04) {
        for (i = 0; i < 3; i++) {
            p = *(V4_003BE960 *)(o + 0x10);
            p.x += D_L32_001DF204 * (f32)(i - 1);
            q = p;
            q.z += h;
            func_L30_0034BD48(&s, o, D_L32_001D66B0_003BCCF8, 1, 0, D_L32_001DF1F8);
            s.flags |= 0x30000;
            func_003CE740(&p, &q, 1, o, &s);
        }
    }
    v->f00 += D_L32_001DF1F4;
    while (v->f00 > 1.0f) {
        f32 z;
        f32 w;
        f32 r;
        s32 n1, n2, c;

        v->f00 -= 1.0f;
        p = *(V4_003BE960 *)(o + 0x10);
        z = func_0037E250(0.0f, h);
        p.z += z;
        if (h - D_L32_001DF204 < z && D_L32_001DF204 < z) {
            f32 d = z - h + D_L32_001DF204;
            w = D_L32_001DF204 * D_L32_001DF204;
            w -= d * d;
            w = sqrt_asm(w);
            p.x += func_0037E250(-w, w);
        } else {
            p.x += func_0037E250(-D_L32_001DF204, D_L32_001DF204);
        }
        func_003BF6A8(&p, D_L32_001DF26C);
        q.x = func_0037E250(D_L32_001DF280, D_L32_001DF27C);
        q.y = func_0037E250(0.0f, 0.0166666675f);
        q.z = func_0037E250(D_L32_001DF288, D_L32_001DF284);
        n2 = func_0037E208(0, 2) - 1;
        n1 = func_0037E208(D_L32_001DF268, D_L32_001DF264);
        c = func_003894A0(D_L32_001DF258, D_L32_001DF25C, func_0037E250(0.0f, 1.0f));
        r = func_0037E250(D_L32_001DF274, D_L32_001DF270);
        func_L01_0046C468(&p, &q, n1, c, n2, D_L32_001DF254, 0, 0, r, D_L32_001DF278 * r, D_L32_001DF260);
    }
    v->f0C = func_00389380(v->f0C, D_L32_001DF220_003BCCF8);
    v->f10 = func_00389380(v->f10, D_L32_001DF224_003BCCF8);
    if (func_00388398(&v->f04) != 0) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L32_003BCCF8 */
