#include "common.h"

typedef struct S_003BED60 {
    u8 pad00[4];
    u8 f04[8];
    f32 f0C;
    f32 f10;
    u8 pad14[0x28];
    s32 f3C;
} S_003BED60;
typedef struct S_003BED60_arg {
    u8 pad00[0x68];
    S_003BED60 *f68;
} S_003BED60_arg;

/* declared by functions of L32_003BE008.c, which this file was cut from */
void func_L32_003BED60(void *);
void func_L01_004450F0(void *, s32, s32);

/* localdecomp:start func_L32_003BE960 */
#include "vu0.h"
extern s32 func_L01_004561B8(void *);
extern void func_003A4F28(s32);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L30_0034C8A8(void *, void *);
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C4C18(void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 D_001A30B0[];
extern u8 D_L32_001E2590[] __attribute__((section(".sdata")));
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L32_001DF1B4, 4");
extern f32 D_L32_001DF1B4;
__asm__(".extern D_L32_001DF1B8, 4");
extern f32 D_L32_001DF1B8;
__asm__(".extern D_L32_001DF1C0, 4");
extern f32 D_L32_001DF1C0;
__asm__(".extern D_L32_001DF1C4, 4");
extern f32 D_L32_001DF1C4;
__asm__(".extern D_L32_001DF1C8, 4");
extern s32 D_L32_001DF1C8;
__asm__(".extern D_L32_001DF1CC, 4");
extern s32 D_L32_001DF1CC;
__asm__(".extern D_L32_001DF1D4, 4");
extern s32 D_L32_001DF1D4;
__asm__(".extern D_L32_001DF1E0, 4");
extern f32 D_L32_001DF1E0;
__asm__(".extern D_L32_001DF1E4, 4");
extern f32 D_L32_001DF1E4;
__asm__(".extern D_L32_001DF214, 4");
extern s32 D_L32_001DF214;
__asm__(".extern D_L32_001DF218, 4");
extern s32 D_L32_001DF218;
__asm__(".extern D_L32_001DF21C, 4");
extern s32 D_L32_001DF21C;
__asm__(".extern D_L32_001DF220, 4");
extern f32 D_L32_001DF220;
__asm__(".extern D_L32_001DF224, 4");
extern s32 D_L32_001DF224;
__asm__(".extern D_L32_001DF228, 4");
extern s32 D_L32_001DF228;
__asm__(".extern D_L32_001DF22C, 4");
extern f32 D_L32_001DF22C;
__asm__(".extern D_L32_001DF230, 4");
extern f32 D_L32_001DF230;
__asm__(".extern D_L32_001DF234, 4");
extern f32 D_L32_001DF234;
__asm__(".extern D_L32_001DF238, 4");
extern f32 D_L32_001DF238;
__asm__(".extern D_L32_001DF23C, 4");
extern f32 D_L32_001DF23C;
__asm__(".extern D_L32_001DF240, 4");
extern f32 D_L32_001DF240;
__asm__(".extern D_L32_001DF244, 4");
extern f32 D_L32_001DF244;
__asm__(".extern D_L32_001DF248, 4");
extern f32 D_L32_001DF248;
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

void func_L32_003BE960(u8 *o) {
    V_003BE960 *v = *(V_003BE960 **)(o + 0x68);
    f32 scale;
    f32 h;
    s32 i;
    V4_003BE960 p;
    V4_003BE960 q;
    S_003BE960 s;

    if (func_L01_004561B8(o) != 0) {
        v->f04 = D_L32_001DF1C8;
        if (v->f3C != -1) {
            u8 *t = D_001A30B0 + v->f3C * 0x80;
            if (*(u8 **)(t + 0xDC) == o && t[0xD0] != 0) {
                func_003A4F28(v->f3C);
            }
        }
        v->f3C = -1;
        func_L01_004AAC98(0xC, 0, (s32)o, 0x19D1);
    }
    if (v->f04 >= D_L32_001DF1C8 - D_L32_001DF1D4) {
        func_L30_0034C8A8(D_L32_001E2590, o);
    }
    if (D_L32_001DF1C8 - D_L32_001DF1D4 < v->f04) {
        scale = func_L03_0034B440(1, 0, 4, (f32)(v->f04 - D_L32_001DF1C8 + D_L32_001DF1D4),
                                  (f32)(D_L32_001DF1D4 + 1), 1.0f);
    } else {
        scale = 1.0f;
    }
    h = D_L32_001DF1C0 * scale;
    if (D_L32_001DF1C8 - D_L32_001DF1CC < v->f04) {
        for (i = 0; i < 3; i++) {
            p = *(V4_003BE960 *)(o + 0x10);
            p.x += D_L32_001DF1C4 * (f32)(i - 1);
            q = p;
            q.z += h;
            func_L30_0034CC28(&s, o, D_L32_001D66B0, 1, 0, D_L32_001DF1B8);
            s.flags |= 0x30000;
            func_003D3CB0(&p, &q, 1, o, &s);
        }
    }
    v->f00 += D_L32_001DF1B4;
    while (v->f00 > 1.0f) {
        f32 z;
        f32 w;
        f32 r;
        s32 n1, n2, c;

        v->f00 -= 1.0f;
        p = *(V4_003BE960 *)(o + 0x10);
        z = func_003824E0(0.0f, h);
        p.z += z;
        if (h - D_L32_001DF1C4 < z && D_L32_001DF1C4 < z) {
            f32 d = z - h + D_L32_001DF1C4;
            w = D_L32_001DF1C4 * D_L32_001DF1C4;
            w -= d * d;
            w = sqrt_asm(w);
            p.x += func_003824E0(-w, w);
        } else {
            p.x += func_003824E0(-D_L32_001DF1C4, D_L32_001DF1C4);
        }
        func_003C4C18(&p, D_L32_001DF22C);
        q.x = func_003824E0(D_L32_001DF240, D_L32_001DF23C);
        q.y = func_003824E0(0.0f, 0.020000001f);
        q.z = func_003824E0(D_L32_001DF248, D_L32_001DF244);
        n2 = func_00382498(0, 2) - 1;
        n1 = func_00382498(D_L32_001DF228, D_L32_001DF224);
        c = func_0038DBD8(D_L32_001DF218, D_L32_001DF21C, func_003824E0(0.0f, 1.0f));
        r = func_003824E0(D_L32_001DF234, D_L32_001DF230);
        func_L01_0046FB40(&p, &q, n1, c, n2, D_L32_001DF214, 0, 0, r, D_L32_001DF238 * r, D_L32_001DF220);
    }
    v->f0C = func_0038DAB8(v->f0C, D_L32_001DF1E0);
    v->f10 = func_0038DAB8(v->f10, D_L32_001DF1E4);
    if (func_0038CAD0(&v->f04) != 0) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L32_003BE960 */
