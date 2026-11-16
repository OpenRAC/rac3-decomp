#include "common.h"

/* NTSC-U counterpart of func_L39_00536EB0 (src/levels/shared/L39_00536EB0.c) */
/* localdecomp:start func_L39_00536728 */
#include "vu0.h"

typedef struct {
    u8 pad00[0x26];
    u8 f26;
    u8 pad27[7];
    u16 f2E;
    f32 f30;
    u8 pad34[0x1C];
} S_00536EB0;

extern u8 D_L39_004998A0[];
extern f32 D_L39_0025F860[4];
extern u8 D_L39_0024AE70;
__asm__(".extern D_L39_0024AE70, 4");
extern u8 D_L39_0024AE80;
__asm__(".extern D_L39_0024AE80, 4");
extern u8 D_L39_0024AE90_00536728;
__asm__(".extern D_L39_0024AE90_00536728, 4");
extern s16 D_L39_00294038[][64];

extern void func_L39_00619D58(u8 *, u8 **);
extern void func_003888C8(void *, void *, void *);
extern void func_003888F0(void *, void *, void *);
extern s32 func_L39_00670988(void *, s32, s32, void *);
extern u8 *func_L39_0053B6B8(s32, s32);
extern s32 func_L01_0040BAF0(void *);
extern s32 func_003883C8(void *);
extern void func_L39_0061F5C0(void *, s32);
extern void func_L39_006377E8(void *, s32, s32);
extern void func_L39_005FBF00(void *, void *, void *, s32, f32, f32, f32, f32, s32);
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_0061E688(void *, s32, s32);
extern void func_L39_0053B078(void *, void *, void *);
extern void func_003BD360(void *);
extern void func_L01_00448BD8(void *, short *, short);
extern s32 func_L39_0061E558(void *, s32);
extern u8 *func_L39_0053B370(void *, void *, void *, void *, u32);

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00536EB0;

static __inline__ u32 decode_00536EB0(u8 *p) {
    Buf_00536EB0 buf;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* pos = D_L39_0025F860 + (target - pos) * 0.15f */
static __inline__ void approach_00536EB0(void *pos, void *target) {
    f32 v[4] __attribute__((aligned(16)));

    vec_sub_ba(v, target, pos);
    func_00388830(v, v, 0.15f);
    vec_add_ba(v, D_L39_0025F860, v);
    *(vu0_q *)pos = *(vu0_q *)v;
}

void func_L39_00536728(u8 *o) {
    u8 *ex;
    u8 *g;
    s32 rc;
    f32 tmp[4] __attribute__((aligned(16)));
    S_00536EB0 sb __attribute__((aligned(16)));

    if (o == 0) return;
    ex = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        func_L39_00619D58(o, (u8 **)(ex + 0x2C));
    }
    g = *(u8 **)(ex + 0x2C);
    if (g == 0) return;
    *(vu0_q *)(ex + 0x10) = *(vu0_q *)(g + 0x730);
    if (o[0x20] == 3) {
        func_003888C8(tmp, &D_L39_0024AE90_00536728, o + 0xC0);
    } else {
        func_003888C8(tmp, &D_L39_0024AE70, o + 0xC0);
    }
    vec_add_ba(ex + 0x10, ex + 0x10, tmp);
    func_003888F0(ex, &D_L39_0024AE80, g + 0x20);
    vec_add_ab(ex, ex, g + 0xA0);
    if (*(u8 **)(ex + 0x20) != 0) {
        if (o[0x20] == 3) {
            *(f32 *)(*(u8 **)(ex + 0x20) + 0x2C) += *(f32 *)(*(u8 **)(*(u8 **)(ex + 0x20) + 0x24) + 0x24) * 0.05f;
        } else {
            *(f32 *)(*(u8 **)(ex + 0x20) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(ex + 0x20) + 0x24) + 0x24) * 0.3f;
        }
        *(s32 *)(*(u8 **)(ex + 0x20) + 0x9C) = 0;
    }
    if (*(u8 **)(ex + 0x20) == 0 || (*(u8 **)(ex + 0x20))[0x20] == 0xFE || (*(u8 **)(ex + 0x20))[0x20] == 0xFD) {
        *(s32 *)(ex + 0x20) = 0;
    }
    rc = func_L39_00670988(g + 0x1A40, 0, 1, &sb);
    if (rc == 8) {
        ex[0x27] = 0x14;
        *(s32 *)(ex + 0x28) = sb.f2E;
        if (0.0f <= sb.f30) {
            u8 *m = func_L39_0053B6B8(sb.f26, (s32)sb.f30);
            if (m != 0) {
                *(s32 *)(*(u8 **)(m + 0x68) + 0x5C) = -1;
                m[0x30] = 0xFF;
            }
        }
    }
    func_L01_0040BAF0(ex + 0x26);
    if (func_L01_0040BAF0(ex + 0x27) != 0) {
        g[0x1A0D] = 0;
    }
    if ((decode_00536EB0(g + 0x19E4) ^ 1) == 0) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 1, 0, 1);
    }
    if ((decode_00536EB0(g + 0x19E4) ^ 0x1D) == 0 && rc == 8) {
        func_L39_0061F5C0(g, -1);
        g[0x1A0D] = 1;
    }
    if ((g[0x1A07] != 0 && *(s32 *)(g + 0x30C) == 5) || ((decode_00536EB0(g + 0x19E4) ^ 0x22) == 0 && *(s32 *)(g + 0x2F0) == 5)) {
        o[0x20] = 3;
    }
    if (ex[0x26] == 0) {
        if (((decode_00536EB0(g + 0x19E4) ^ 0x22) != 0 && g[0x1A07] != 0 && *(s32 *)(g + 0x30C) == 0x11) ||
            ((decode_00536EB0(g + 0x19E4) ^ 0x22) == 0 && *(s32 *)(g + 0x2F0) == 0x10) ||
            (o[0x20] == 3 && g[0x24FF] == 0 && g[0x1A07] == 0 && (decode_00536EB0(g + 0x19E4) ^ 0x22) != 0)) {
            ((s32 (*)(void *, s32, s32))func_L39_006377E8)(g, 0x10, 0);
            o[0x20] = 4;
        }
    }
    if (*(u8 **)(ex + 0x20) != 0 && g[0x1A0C] == 0) {
        func_L39_005FBF00(g, *(u8 **)(*(u8 **)(ex + 0x20) + 0x68), ex, 0, 1.5f, 7.0f, 0.100000009f, 0.003277777927f, 0);
    }
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        o[0x20] = 7;
    }
    switch (o[0x20]) {
    case 0:
        *(s32 *)(ex + 0x20) = 0;
        *(s16 *)(ex + 0x24) = 7;
        if (o[0x60] & 2) {
            o[0x20] = 2;
        } else {
            o[0x20] = 1;
        }
    case 1:
        if (o[0x60] & 2) {
            o[0x20] = 2;
        }
        break;
    case 3:
        if (g[0x24FF] == 0) {
            break;
        }
        g[0x24FF] = 0;
        if (*(f32 *)(g + 0x18F0) != 0.0f) {
            *(vu0_q *)(ex + 0x10) = *(vu0_q *)(g + 0x18F0);
        }
        if (func_003CE740(g + 0xE0, ex + 0x10, 2, 0, 0) != 0) {
            approach_00536EB0(ex + 0x10, g + 0xE0);
        }
        if (*(u8 **)(ex + 0x20) != 0) {
            *(vu0_q *)(*(u8 **)(ex + 0x20) + 0x10) = *(vu0_q *)(ex + 0x10);
        }
        o[0x20] = 4;
    case 4:
        if (*(u8 **)(ex + 0x20) != 0) {
            func_L39_0061E688(g, 6, 1);
            {
                u8 *e = *(u8 **)(*(u8 **)(ex + 0x20) + 0x68);
                *(u16 *)(e + 0x7E) = *(u16 *)(ex + 0x28);
                func_L39_0053B078(ex + 0x10, *(u8 **)(ex + 0x20), e);
            }
            *(f32 *)(*(u8 **)(ex + 0x20) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(ex + 0x20) + 0x24) + 0x24);
            *(s32 *)(*(u8 **)(ex + 0x20) + 0x9C) = 1;
            ex[0x26] = 7;
            func_L01_00448BD8(*(u8 **)(ex + 0x20), D_L39_00294038[*(s32 *)(g + 0x2544)], 0x3F);
            *(s32 *)(ex + 0x20) = 0;
            *(s16 *)(ex + 0x24) = 10;
            o[0x20] = 5;
        }
        break;
    case 5:
        if (ex[0x27] == 0) {
            g[0x1A0D] = 0;
            o[0x20] = 2;
        }
        break;
    case 6:
        o[0x20] = 7;
        break;
    case 7:
        if (*(u8 **)(ex + 0x20) != 0) {
            func_003BD360(*(u8 **)(ex + 0x20));
            *(s32 *)(ex + 0x20) = 0;
        }
        break;
    }
    func_003883C8(ex + 0x24);
    if (*(u8 **)(ex + 0x20) != 0) {
        *(vu0_q *)(*(u8 **)(ex + 0x20) + 0x10) = *(vu0_q *)(ex + 0x10);
    } else if (*(s16 *)(ex + 0x24) == 0) {
        if (func_L39_0061E558(g, -1) != 0) {
            f32 v[4] __attribute__((aligned(16)));

            qzero(v);
            *(u8 **)(ex + 0x20) = func_L39_0053B370(o, g, ex + 0x10, v, 0xFFFFFFFF);
        }
    }
}
/* localdecomp:end func_L39_00536728 */
