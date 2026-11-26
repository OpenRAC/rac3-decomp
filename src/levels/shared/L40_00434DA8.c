#include "common.h"

/* localdecomp:start func_L40_00434DA8 */
typedef struct V4_00434DA8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00434DA8;

typedef union Buf {
    u8 b[8];
    u32 w[2];
    f32 f[4];
} Buf;

typedef struct S_00434DA8 {
    f32 f0;
    f32 f4;
    s32 w8;
    u8 *p0C;
    u8 pad10[1];
    u8 b11;
    u8 pad12[0x30 - 0x12];
    f32 f30;
} S_00434DA8;

typedef struct G_00434DA8 {
    u8 pad[0x190];
    s8 b190;
} G_00434DA8;

__asm__(".extern D_L40_00241640, 16");
extern G_00434DA8 *D_L40_00241640;
extern s32 *D_L40_00241120;
extern u8 D_L40_003BFE20[];
extern u8 D_L40_003BFE21[];
__asm__(".extern D_L40_00247EC8, 16");
extern u32 D_L40_00247EC8;

extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L40_00434D68(void *);
extern void func_003C2880(void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_005F33E0(s32, s32, void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00404808(void *, void *);
extern f32 func_003C4138(void *, f32, f32);
extern void func_0038D750(void *, s32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L40_00435388(u8 *);

static inline u8 Gt(f32 a, f32 b) {
    return (u8)(a > b);
}

static inline u8 Ne(f32 a, f32 b) {
    return (u8)(a != b);
}

static inline f32 SfGet(u8 *q) {
    Buf buf;
    s32 n, k, m, i;
    u8 *d;
    if (*q == 0) {
        return 0.0f;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.f[1];
}

static inline void SfSet(u8 *q, f32 v) {
    u8 *hk = q;
    Buf buf;
    u32 key;
    s32 k, m, j, tt;
    u8 *d;
    if (*q == 0) {
        *q = ++D_L40_003BFE20[0];
    } else {
        tt = *q;
        *q = D_L40_003BFE21[0];
        D_L40_003BFE21[0] = tt;
    }
    key = ((u32 *)D_L40_003BFE20)[((u32)hk * D_L40_00247EC8) % 510];
    k = ((u32)q - *q) & 7;
    buf.w[0] = (u32)q ^ key;
    buf.f[1] = v;
    buf.w[1] ^= key;
    m = *q + 1;
    d = buf.b;
    for (j = 0; j < 40; j += 5) {
        D_L40_003BFE20[m + ((k + j) & 7) * 255] = *d++;
    }
}

void func_L40_00434DA8(u8 *a0) {
    S_00434DA8 *s;
    V4_00434DA8 vec;
    s32 s5;
    s32 i;

    s = *(S_00434DA8 **)(a0 + 0x68);
    if (*(u16 *)(a0 + 0x96) < 0x7FFD) {
        *(u16 *)(a0 + 0x96) += 1;
    }
    vec = *(V4_00434DA8 *)(a0 + 0x10);
    vec.w = 2.0f;
    if (func_L39_005BE900(&vec, 0, (f32)a0[0x30]) == -1) {
        s->w8 = 0;
        return;
    }
    s5 = func_L40_00434D68(a0);
    switch (a0[0x20]) {
    case 0:
        if (D_L40_00241640->b190 == 0) {
            func_003C2880(a0);
            return;
        }
        s->p0C = 0;
        if (s->b11 == 0) {
            func_L01_0043A430(a0, 0, (u8 *)s + 0x10);
        }
        func_L01_004450F0(a0, 1, -1);
    case 1:
        if (s->p0C != 0) {
            if (*(u8 **)(s->p0C + 0x2CC) != a0) {
                s->p0C = 0;
            }
        } else {
            for (i = 0; i < *D_L40_00241120; i++) {
                u8 *t0 = func_L39_0061BF38(i);
                s32 ok;
                s32 t4;
                f32 zero;
                if (t0 != 0 && *(u8 **)(t0 + 0x2CC) == a0 && *(s16 *)(t0 + 0x2DE) == 0) {
                    f32 fa = SfGet(t0 + 0x2554);
                    f32 fb = SfGet(t0 + 0x2476);
                    ok = fb < fa;
                    if ((u8)ok && s5 != 0) {
                        if (s->w8 == 0) {
                            s32 arg = 0;
                            s->w8 = 1;
                            t4 = (s32)SfGet(t0 + 0x2554);
                            zero = 0.0f;
                            ok = SfGet(t0 + 0x2476) != zero;
                            if ((u8)ok) {
                                SfSet(t0 + 0x2476, (f32)t4);
                                *(s32 *)(t0 + 0x2514) = 300;
                            }
                            s->p0C = t0;
                            func_L39_005F33E0(arg, 0, a0);
                            func_L01_004450F0(a0, 2, -1);
                            break;
                        }
                    } else {
                        s->w8 = 0;
                    }
                } else {
                    s->w8 = 0;
                }
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            s->f0 = 0.0f;
        }
        if (s->f0 < 0.85f) {
            func_L01_00404808(func_L40_00435388, a0);
            func_003C4138(s, 0.85f, 0.040000003f);
        } else {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    }
    if (s5 != 0) {
        s->f30 = 1.0f;
    } else {
        s->f30 = 0.0f;
    }
    func_0038D750((u8 *)s + 0x20, 2, s->f4);
    s->f4 = func_0038DB00(s->f4, 0.069813177f);
}
/* localdecomp:end func_L40_00434DA8 */

/* localdecomp:start func_L40_00435388 */
typedef struct {
    f32 x, y, z, w;
} V4_00435388 __attribute__((aligned(16)));

typedef struct {
    f32 u, v;
} UV_00435388;

typedef struct {
    V4_00435388 pos[4];
    u32 col[4];
    UV_00435388 uv[4];
    unsigned long a70;
    unsigned long a78;
    unsigned long a80;
    unsigned long a88;
} Q_00435388;

typedef int U128_00435388 __attribute__((mode(TI)));
extern void func_0038D570(void *, void *);
extern void func_0038D308(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern unsigned long func_L39_00589890(s32);
extern void func_L04_0041AE18(void *, s32, void *, s32, void *);

__asm__(".extern D_L40_00247B60, 4");
__asm__(".extern D_L40_00247B64, 4");
__asm__(".extern D_L40_00247B68, 4");
__asm__(".extern D_L40_00247B6C, 4");
__asm__(".extern D_L40_00247B70, 4");
__asm__(".extern D_L40_00247BA0, 4");
__asm__(".extern D_L40_00247BA8, 4");
extern s32 D_L40_00247B60;
extern s32 D_L40_00247B64;
extern s32 D_L40_00247B68;
extern s32 D_L40_00247B6C;
extern s32 D_L40_00247B70;
__asm__(".extern D_L40_00247B78, 8");
__asm__(".extern D_L40_00247B80, 8");
extern u32 D_L40_00247B78[] __attribute__((section(".sdata")));
extern UV_00435388 D_L40_00247B80[] __attribute__((section(".sdata")));
extern f32 D_L40_00247BA0;
extern f32 D_L40_00247BA8;
extern f32 D_L40_00247ED8;

static __inline__ f32 max_00435388(f32 x, f32 lo) {
    if (x < lo) {
        x = lo;
    }
    return x;
}

void func_L40_00435388(u8 *a0) {
    Q_00435388 q[4];
    V4_00435388 m[4];
    V4_00435388 r[3];
    V4_00435388 rot;
    f32 *t = *(f32 **)(a0 + 0x68);
    f32 a, b, c, d;
    s32 k;

    func_0038D570(m, a0 + 0xC0);
    m[3] = *(V4_00435388 *)(a0 + 0x10);
    for (k = 0; k < 4; k++) {
        q[k].a78 = func_L39_00589890(D_L40_00247B70);
        q[k].a80 = 0xFF9000000260UL;
        q[k].a70 = 0;
        q[k].a88 = (long)D_L40_00247B60 | ((long)D_L40_00247B64 << 2) | ((long)D_L40_00247B68 << 4) |
                    ((long)D_L40_00247B6C << 6) | 0x8000000000UL;
    }

    a = (0.85f - *t) * 2.0f;
    b = 0.15f;
    if (a > 1.0f) {
        a = 1.0f;
    } else if (a < 0.0f) {
        a = 0.0f;
    }
    if (*t < 1.15f) {
        c = max_00435388(1.15f - *t, 0.0f);
        d = max_00435388((0.2f - *t) / 0.2f, 0.0f);
        D_L40_00247ED8 = d;
        b = c + 0.15f;
    }

    {
        s32 i, j;
        f32 x;

        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                q[i].uv[j].u = D_L40_00247B80[j].u;
                q[i].uv[j].v = D_L40_00247B80[j].v;
                q[i].col[j] = D_L40_00247B78[i != 0];
                q[i].col[j] = func_0038DBD8(q[i].col[j] & 0xFFFFFF, q[i].col[j], a);
                __asm__("sqc2 $vf0, %0" : "=m"(*(U128_00435388 *)&q[i].pos[j]));
                q[i].pos[j].x = x = *t + (i != 0 ? 0.01f : 0.0f);
                if (j & 1) {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247BA0 + b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247BA0 + D_L40_00247BA8;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247BA0 - b * 0.8f + D_L40_00247BA8;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247BA0 + b * 0.8f + D_L40_00247BA8;
                        break;
                    }
                } else {
                    switch (i) {
                    case 0:
                        q[i].pos[j].z += D_L40_00247BA0 - b;
                        break;
                    case 1:
                        q[i].pos[j].z += D_L40_00247BA0 - D_L40_00247BA8;
                        break;
                    case 2:
                        q[i].pos[j].z += D_L40_00247BA0 - b * 0.8f - D_L40_00247BA8;
                        break;
                    case 3:
                        q[i].pos[j].z += D_L40_00247BA0 + b * 0.8f - D_L40_00247BA8;
                        break;
                    }
                }
            }
        }
    }

    *(U128_00435388 *)&rot = 0;
    rot.z = 0.19634954f;
    func_0038D308(r, &rot);
    func_L04_0041AE18(q, 4, r, 0x20, m);
}
/* localdecomp:end func_L40_00435388 */
