/* functional: medium. Same reads, writes and calls in retail order; the COP2 vadd.xyz is written as scalar adds (w taken from the anchor, as retail) and the lq/sq copies are struct copies; register allocation differs (SN spills the COP2 asm here). */
#include "vu0.h"
__asm__(".extern D_L30_001DD930, 4");
extern f32 D_L30_001DD930;
__asm__(".extern D_L30_001DD938, 4");
extern f32 D_L30_001DD938;
__asm__(".extern D_L30_001DD934, 4");
extern f32 D_L30_001DD934;
__asm__(".extern D_L30_001DD908, 4");
extern f32 D_L30_001DD908;
__asm__(".extern D_L30_001DD950, 4");
extern f32 D_L30_001DD950;
__asm__(".extern D_L30_001DD94C, 4");
extern f32 D_L30_001DD94C;
__asm__(".extern D_L30_001DD944, 4");
extern f32 D_L30_001DD944;
__asm__(".extern D_L30_001DD954, 4");
extern f32 D_L30_001DD954;
__asm__(".extern D_L30_001DD91C, 4");
extern s32 D_L30_001DD91C;
__asm__(".extern D_L30_001DD918, 4");
extern s32 D_L30_001DD918;
__asm__(".extern D_L30_001DD914, 4");
extern s32 D_L30_001DD914;
__asm__(".extern D_L30_001DD910, 4");
extern s32 D_L30_001DD910;
__asm__(".extern D_L30_001DD924, 4");
extern f32 D_L30_001DD924;
__asm__(".extern D_L30_001DD90C, 4");
extern f32 D_L30_001DD90C;
__asm__(".extern D_L30_001DD93C, 4");
extern f32 D_L30_001DD93C;
__asm__(".extern D_L30_001DD904, 4");
extern f32 D_L30_001DD904;
extern u8 D_L30_001E9000[];
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_351;
typedef struct { u8 pad0[0x10]; V4_351 x10; u8 pad20[0x68 - 0x20]; u8 *x68; } M_3518F0;
typedef struct { s32 x4; u8 b8; u8 pad9; s16 hA; f32 xC; V4_351 x10; } P_3518F0;
typedef struct {
    M_3518F0 *x0; s32 x4; s16 h8; u16 hA; u8 bC; u8 padD; u16 hE;
    f32 x10; f32 x14; s32 x18; s32 x1C;
} Q_3518F0;

void func_L30_003518F0(P_3518F0 *a, Q_3518F0 *b) {
    M_3518F0 *m;
    f32 base, fE, fC, w, dur, c;
    f32 ang, spin, rate;
    V4_351 tmp;

    if (b == 0) return;
    m = b->x0;
    if (m == 0) return;
    if (b->x4 == 0) return;
    fC = D_L30_001DD930 * (f32)b->h8 * (f32)(b->hE >> 8);
    fE = (f32)(b->hE & 0xFF);
    dur = fC * 0.00390625f;
    w = func_003C4088(D_L30_001DD938, D_L30_001DD934, (f32)b->bC * 0.00390625f);
    if (b->hA & 1) {
        f32 off;
        ang = func_0038DAB8(func_0038DB48(func_003824E0(-D_L30_001DD908, D_L30_001DD908)), *(f32 *)(m->x68 + 0x18));
        spin = func_003824E0(D_L30_001DD950, D_L30_001DD94C);
        off = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        tmp.x = func_0038D098(off) * D_L30_001DD944;
        tmp.y = 0.0f;
        tmp.z = func_0038D0B0(off) * D_L30_001DD944;
        a->x10.x = m->x10.x + tmp.x; a->x10.y = m->x10.y + tmp.y; a->x10.z = m->x10.z + tmp.z; a->x10.w = m->x10.w;
        a->x10.y += D_L30_001DD954;
        tmp.x = func_0038D098(ang) * spin;
        tmp.z = func_0038D0B0(ang) * spin;
        tmp.y = 0.0f;
        b->x10 = tmp.x;
        b->x14 = tmp.z;
        b->x18 = func_0038DBD8(D_L30_001DD91C, D_L30_001DD918, func_003824E0(0.0f, 1.0f));
        b->x1C = func_0038DBD8(D_L30_001DD914, D_L30_001DD910, func_003824E0(0.0f, 1.0f));
        b->h8 = b->h8 + (s32)(D_L30_001DD924 / spin);
        a->hA = b->h8;
    }
    b->x14 = b->x14 + D_L30_001DD90C;
    tmp = a->x10;
    tmp.x += b->x10;
    tmp.z += b->x14;
    if (func_003D3CB0(&a->x10, &tmp, 1, m, 0) != 0 && *(s32 *)(D_L30_001E9000 + 0x18) != 0) {
        f32 h = b->x10 * 0.74f;
        f32 z = tmp.z;
        tmp.x = a->x10.x + h;
        if (a->x10.y <= *(f32 *)(D_L30_001E9000 + 0x24)) {
            tmp.z = z - h;
        } else {
            tmp.z = z + h;
        }
    }
    a->x10 = tmp;
    c = fE + dur;
    a->xC = func_003C4088(D_L30_001DD93C, w, func_L03_0034B148(a->hA, b->h8, 0.0f));
    a->x4 = func_0038DBD8(b->x18, b->x1C, func_L03_0034B148(a->hA, b->h8, 0.0f));
    a->x4 = (a->x4 & 0xFFFFFF) + ((s32)(func_L03_0034B148(b->h8 - a->hA, b->h8, D_L30_001DD904) * 128.0f) << 24);
    a->b8 = (s32)func_003C4088(fE, c, func_L03_0034B148(a->hA, b->h8, 0.0f));
}
