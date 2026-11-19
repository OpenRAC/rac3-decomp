#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00550D48);

/* localdecomp:start func_L39_005510B0 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x12];
    f32 f34;
    u8 pad38[0x48];
} S_005510B0;

typedef struct {
    u8 pad0[0x18];
    s32 f18;
} G_005510B0;

typedef struct {
    vu0_q v0;
    void *p10;
    s32 i14;
    u8 b18;
    u8 b19;
    u16 h1A;
    f32 f1C;
    s32 i20;
} __attribute__((aligned(16))) A_005510B0;

typedef struct {
    vu0_q a;
    vu0_v4 b;
} __attribute__((aligned(16))) L_005510B0;

extern S_005510B0 D_L39_0049C890[];
extern G_005510B0 D_L39_0025F740;
extern u8 D_L39_00483A00[];
extern s32 func_L39_005BE900(void *, s32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00470668(void *, void *, s32, f32);
extern s32 func_L39_00648AE0(void *, s32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);

static __inline__ void init_005510B0(L_005510B0 *s, vu0_v4 *pos, vu0_q *v) {
    vu0_q *b = (vu0_q *)&s->b;
    vu0_q t = *(vu0_q *)pos;
    vu0_q u = *v;
    *b = t;
    s->a = u;
}

static __inline__ s32 chk_005510B0(u8 *o, s32 sh) {
    u32 buf[2];
    u8 *p;
    u8 *dst;
    u32 n, m, base, t, a, b, q;
    s32 i;
    u16 x;

    p = o + 0x1A41;
    if (o[0x1A41] == 0) {
        x = 0;
    } else {
        n = o[0x1A41];
        m = n + 1;
        base = ((u32)p - n) & 7;
        dst = (u8 *)buf;
        i = 0;
        do {
            t = (base + i) & 7;
            i += 3;
            *dst++ = D_L39_00483A00[t * 209 + m];
        } while (i < 24);
        a = buf[0] ^ (u32)p;
        b = buf[1] ^ a;
        buf[0] = a;
        q = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
        buf[1] = q;
        x = *(u16 *)(buf + 1);
    }
    return ((s16)x >> sh) & 1;
}

void func_L39_005510B0(u8 *a0, void *a1) {
    L_005510B0 seg;
    u8 *st;
    S_005510B0 *p;
    s32 i;
    s32 vis;

    init_005510B0(&seg, (vu0_v4 *)(a0 + 0x10), (vu0_q *)a1);
    st = *(u8 **)(a0 + 0x68);
    seg.b.w = 1.5f;
    if (func_L39_005BE900(&seg.b, 0, 96.0f) >= 0 || st[0x38] == 1) {
        vu0_v4 dir;

        func_L01_003303B8(&seg, 0, 0xC, 4, 5, 5, 0, 0, 0.13f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x10000, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF20FF, 0xFF8F00,
                          0xFF6430, 0x7FFFA0FF, 0x28FF00FF, 0xFF6430, 0);

        {
            vu0_q qa, qb, qr;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(a0 + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)(*(u8 **)(st + 0x3C) + 0x23A0)));
            __asm__("vsub.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(dir) : "j"(qr));
            func_0038CF68(&dir, &dir, func_L39_005B4410(0.1f, 0.2f));
            for (i = 0; i < 2; i++) {
                dir.x += func_L39_005B4410(-0.05f, 0.05f);
                dir.y += func_L39_005B4410(-0.05f, 0.05f);
                dir.z += func_L39_005B4410(-0.05f, 0.05f);
                func_L01_00470668(&seg, &dir, (func_L39_005B43C8(0x19, 0x28) * 5 + 2) / 6, 0.00584f);
            }
        }
    }
    vis = *(s32 *)(st + 0x4C);
    if ((vis == 0 || vis == D_L39_0025F740.f18) && !chk_005510B0(*(u8 **)(st + 0x3C), 3)) {
        return;
    }
    {
    A_005510B0 args;
    args.p10 = a0;
    args.i14 = 0x1010001;
    if (func_L39_00648AE0(*(void **)(st + 0x3C), 3)) {
        S_005510B0 *tb = D_L39_0049C890;
        p = tb + tb[3].b21;
    } else {
        p = D_L39_0049C890;
        p += 3;
    }
    args.f1C = p->f34;
    args.i20 = 1;
    args.v0 = *(vu0_q *)st;
    func_0038CF68(&args, &args, 1.0f);
    args.b18 = 3;
    *(f32 *)((u8 *)&args + 0xC) = 5627.9248f;
    args.b19 = 2;
    args.h1A = *(u16 *)(a0 + 0xAA);
    func_003D4D00(&seg, 1, *(void **)(*(u8 **)(st + 0x3C) + 0x2524), &args, 2.0f);
    }
}
/* localdecomp:end func_L39_005510B0 */

/* localdecomp:start func_L39_005514A0 */
#include "vu0.h"

typedef struct { f32 x, y, z; } V3_005514A0;
typedef struct {
    s16 h0;
    u8 b2;
    u8 b3;
    s32 w4;
    u32 w8;
    V3_005514A0 c;
    V3_005514A0 a;
} Buf_005514A0;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x128 - 8];
    s32 f128;
    u8 pad12C[0x170 - 0x12C];
    s32 f170;
    u8 pad174[0x7D4 - 0x174];
    u8 b7D4;
} G_005514A0;
extern G_005514A0 D_001A5CD0;
extern s32 D_L39_002405E0_005514A0;
extern s32 func_L39_0061D780_005514A0(void *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

static __inline__ void v3copy_005514A0(V3_005514A0 *d, V3_005514A0 *s) {
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}

void func_L39_005514A0(u8 *self, u8 *other) {
    Buf_005514A0 buf;
    vu0_v4 d;
    u8 *s2;
    u8 *t;
    u8 v;

    s2 = *(u8 **)(self + 0x68);
    t = *(u8 **)(s2 + 0x3C);
    buf.w4 = D_001A5CD0.f128;
    buf.h0 = 3;
    buf.b3 = 8;
    v = t[0x2544] | 0x40;
    buf.b2 = v;
    if (s2[0x38] == 1) {
        buf.b2 = v | 0x80;
    }
    buf.w8 = func_L39_0061D780_005514A0(other);
    if (buf.w8 != 0xFFFFFFFF && other != 0) {
        vec_sub_ab(&d, self + 0x10, other + 0x10);
        v3copy_005514A0(&buf.a, (V3_005514A0 *)&d);
    } else {
        v3copy_005514A0(&buf.a, (V3_005514A0 *)(self + 0x10));
    }
    v3copy_005514A0(&buf.c, (V3_005514A0 *)(s2 + 0x10));
    if (D_001A5CD0.f170 == 0) {
        func_0014AD08(D_001A5CD0.b7D4 | 0x80, D_001A5CD0.f4, -1, D_L39_002405E0_005514A0, 0x24, &buf);
    }
    s2[0x3B] = 1;
}
/* localdecomp:end func_L39_005514A0 */
