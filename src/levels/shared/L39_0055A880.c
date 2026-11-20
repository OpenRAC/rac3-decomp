#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_0055A880 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0055A880;
__asm__(".extern D_L39_0024B3B0, 4");

typedef struct {
    s16 sel[4];
    s32 col[4][4];
    f32 rate;
    V_0055A880 *verts;
    s16 (*quads)[4][2];
    f32 *uvs;
    s16 count;
    s16 pad5A;
    f32 scroll;
} E_0055A880;

typedef int Q_0055A880 __attribute__((mode(TI)));

typedef struct {
    V_0055A880 m[4];
    s32 c[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_0055A880;

extern E_0055A880 D_L39_00472488[];
extern s32 D_L39_0024112C;
extern s32 D_L39_0024D5D0;
extern f32 D_L39_0024B3B0 __attribute__((section(".sdata")));
extern u8 *func_L39_0061D1D8(s32);
extern unsigned long func_L39_00589890(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L39_0055A880(u8 *a0)
{
    S_0055A880 s;
    u8 *v;
    u8 *g;
    E_0055A880 *e;
    s32 st;
    s32 idx = 0;
    s32 n;
    s32 shift;
    s32 s0, s1, s2, s3;
    s32 col;
    f32 alpha;
    f32 size;
    f32 time;
    s32 t;
    s32 d;
    s32 i = 0;
    s32 j = 0;

    if (a0 == 0) return;
    if (*(s16 *)(a0 + 0xAA) != 0x18AB) return;
    if (a0[0x20] == 0xFE) return;
    if (a0[0x20] == 0xFD) return;
    v = *(u8 **)(a0 + 0x68);
    if (v == 0) return;
    if (*(f32 *)(v + 0x70) == 0.0f) return;
    g = func_L39_0061D1D8(*(s32 *)(a0 + 0x90));
    if (g == 0) return;
    if (*(f32 *)(v + 0x70) == 1.0f) {
        long a = (*(u8 **)(g + 0x2524))[0x42];
        if (a != (*(u8 **)(g + 0x2524))[0x43] || a == 0xFF) {
            *(f32 *)(v + 0x70) = 0.0f;
            return;
        }
    }
    st = (*(u8 **)(g + 0x2524))[0x42];
    n = 0x14;
    shift = 1;
    col = 0x808080;
    size = 1.0f;
    alpha = 1.0f;
    if ((u32)(st - 0x17) >= 3 && st != 0x27) {
        st = *(s16 *)(v + 0x78);
    } else {
        st = (*(u8 **)(g + 0x2524))[0x42];
    }
    if (st == 0x17) {
        *(s16 *)(v + 0x78) = st;
        idx = 0;
    } else if (st == 0x18) {
        *(s16 *)(v + 0x78) = st;
        idx = 1;
    } else if (st == 0x19) {
        *(s16 *)(v + 0x78) = st;
        idx = 2;
    } else {
        *(s16 *)(v + 0x78) = 0x27;
        alpha = 0.7f;
        idx = 3;
        size = 1.25f;
        n = 0xC;
        col = 0x408080;
        shift = 2;
    }
    e = &D_L39_00472488[idx];
    s0 = e->sel[0];
    s1 = e->sel[1];
    s2 = e->sel[2];
    s3 = e->sel[3];
    if (*(f32 *)(v + 0x70) == 1.0f) {
        *(Q_0055A880 *)(v + 0x00) = *(Q_0055A880 *)(*(u8 **)(g + 0x2524) + 0xC0);
        *(Q_0055A880 *)(v + 0x10) = *(Q_0055A880 *)(*(u8 **)(g + 0x2524) + 0xD0);
        *(Q_0055A880 *)(v + 0x20) = *(Q_0055A880 *)(*(u8 **)(g + 0x2524) + 0xE0);
        D_L39_0024D5D0 = D_L39_0024112C;
    }
    t = D_L39_0024112C;
    d = t - D_L39_0024D5D0;
    if (d <= 0) d = 1;
    time = *(f32 *)(v + 0x70) + (f32)d * e->rate;
    *(f32 *)(v + 0x70) = time;
    D_L39_0024D5D0 = t;
    if ((f32)(e->count * 2) <= time) {
        st = (*(u8 **)(g + 0x2524))[0x42];
        if ((u32)(st - 0x17) >= 3 && st != 0x27) {
            *(f32 *)(v + 0x70) = 0.0f;
        }
        return;
    }
    s.x78 = func_L39_00589890(n);
    s.x80 = 0xFF9000000260L;
    s.x70 = 5;
    s.x88 = ((long)shift << 2) | 0x8000000040L;
    *(Q_0055A880 *)(v + 0x30) = *(Q_0055A880 *)(*(u8 **)(g + 0x2524) + 0x10);
    for (i = 0; i < e->count; i++) {
        for (j = 0; j < 4; j++) {
            s32 k2;
            s32 vi;
            f32 *uv;
            f32 k;
            f32 off;
            vi = e->quads[i][j][0];
            if (i == s0) {
                s.c[j] = e->col[0][j];
            } else if (i == s1) {
                s.c[j] = e->col[1][j];
            } else if (i == s2) {
                s.c[j] = e->col[2][j];
            } else if (i == s3) {
                s.c[j] = e->col[3][j];
            } else {
                s.c[j] = 0x50808080;
            }
            k2 = (s8)(s.c[j] >> 24);
            k2 = k2 * alpha;
            s.c[j] = (k2 << 24) | col;
            func_0038CE20(&s.m[j], &e->verts[vi], size);
            uv = (f32 *)(e->quads[i][j][1] * 8 + (s32)e->uvs);
            k = D_L39_0024B3B0;
            off = 1.0f - *(f32 *)(v + 0x70) * e->scroll;
            s.uv[j][0] = (uv[0] - 0.5f) * k + 0.5f;
            s.uv[j][1] = (uv[1] - 0.5f) * k + 0.5f + off;
        }
        func_003D2DA0(&s, v, 0);
    }
}
/* localdecomp:end func_L39_0055A880 */
