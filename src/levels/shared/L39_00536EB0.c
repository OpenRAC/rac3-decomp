#include "common.h"

/* localdecomp:start func_L39_00536EB0 */
#include "vu0.h"

typedef struct {
    u8 pad00[0x26];
    u8 f26;
    u8 pad27[7];
    u16 f2E;
    f32 f30;
    u8 pad34[0x1C];
} S_00536EB0;

extern u8 D_L39_004997E0[];
extern f32 D_L39_0025F760[4];
extern u8 D_L39_0024AD60;
__asm__(".extern D_L39_0024AD60, 4");
extern u8 D_L39_0024AD70;
__asm__(".extern D_L39_0024AD70, 4");
extern u8 D_L39_0024AD80;
__asm__(".extern D_L39_0024AD80, 4");
extern s16 D_L39_00293F38[][64];

extern void func_L39_0061C4D0(u8 *, u8 **);
extern void func_0038D000(void *, void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_L39_006732D0(void *, s32, s32, void *);
extern u8 *func_L39_0053BE50(s32, s32);
extern s32 func_L01_0040E020(void *);
extern s32 func_0038CB00(void *);
extern void func_L39_00621D60(void *, s32);
extern void func_L39_0063A030(void *, s32, s32);
extern void func_L39_005FE6A0(void *, void *, void *, s32, f32, f32, f32, f32, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00620E28(void *, s32, s32);
extern void func_L39_0053B810(void *, void *, void *);
extern void func_003C2880(void *);
extern void func_L01_0044BE50(void *, short *, short);
extern s32 func_L39_00620CF8(void *, s32);
extern u8 *func_L39_0053BB08(void *, void *, void *, void *, u32);

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
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf.w[0] ^= (u32)p;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

/* pos = D_L39_0025F760 + (target - pos) * 0.15f */
static __inline__ void approach_00536EB0(void *pos, void *target) {
    f32 v[4] __attribute__((aligned(16)));

    vec_sub_ba(v, target, pos);
    func_0038CF68(v, v, 0.15f);
    vec_add_ba(v, D_L39_0025F760, v);
    *(vu0_q *)pos = *(vu0_q *)v;
}

void func_L39_00536EB0(u8 *o) {
    u8 *ex;
    u8 *g;
    s32 rc;
    f32 tmp[4] __attribute__((aligned(16)));
    S_00536EB0 sb __attribute__((aligned(16)));

    if (o == 0) return;
    ex = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        func_L39_0061C4D0(o, (u8 **)(ex + 0x2C));
    }
    g = *(u8 **)(ex + 0x2C);
    if (g == 0) return;
    *(vu0_q *)(ex + 0x10) = *(vu0_q *)(g + 0x730);
    if (o[0x20] == 3) {
        func_0038D000(tmp, &D_L39_0024AD80, o + 0xC0);
    } else {
        func_0038D000(tmp, &D_L39_0024AD60, o + 0xC0);
    }
    vec_add_ba(ex + 0x10, ex + 0x10, tmp);
    func_0038D028(ex, &D_L39_0024AD70, g + 0x20);
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
    rc = func_L39_006732D0(g + 0x1A40, 0, 1, &sb);
    if (rc == 8) {
        ex[0x27] = 0x11;
        *(s32 *)(ex + 0x28) = sb.f2E;
        if (0.0f <= sb.f30) {
            u8 *m = func_L39_0053BE50(sb.f26, (s32)sb.f30);
            if (m != 0) {
                *(s32 *)(*(u8 **)(m + 0x68) + 0x5C) = -1;
                m[0x30] = 0xFF;
            }
        }
    }
    func_L01_0040E020(ex + 0x26);
    if (func_L01_0040E020(ex + 0x27) != 0) {
        g[0x1A0D] = 0;
    }
    if ((decode_00536EB0(g + 0x19E4) ^ 1) == 0) {
        (*(void (**)(void *, s32, s32, s32, s32))(*(u8 **)(g + 0x14) + 0x34))(g, 0x1D, 1, 0, 1);
    }
    if ((decode_00536EB0(g + 0x19E4) ^ 0x1D) == 0 && rc == 8) {
        func_L39_00621D60(g, -1);
        g[0x1A0D] = 1;
    }
    if ((g[0x1A07] != 0 && *(s32 *)(g + 0x30C) == 4) || ((decode_00536EB0(g + 0x19E4) ^ 0x22) == 0 && *(s32 *)(g + 0x2F0) == 4)) {
        o[0x20] = 3;
    }
    if (ex[0x26] == 0) {
        if (((decode_00536EB0(g + 0x19E4) ^ 0x22) != 0 && g[0x1A07] != 0 && *(s32 *)(g + 0x30C) == 0xE) ||
            ((decode_00536EB0(g + 0x19E4) ^ 0x22) == 0 && *(s32 *)(g + 0x2F0) == 0xD) ||
            (o[0x20] == 3 && g[0x24FF] == 0 && g[0x1A07] == 0 && (decode_00536EB0(g + 0x19E4) ^ 0x22) != 0)) {
            ((s32 (*)(void *, s32, s32))func_L39_0063A030)(g, 0x10, 0);
            o[0x20] = 4;
        }
    }
    if (*(u8 **)(ex + 0x20) != 0 && g[0x1A0C] == 0) {
        func_L39_005FE6A0(g, *(u8 **)(*(u8 **)(ex + 0x20) + 0x68), ex, 0, 1.5f, 7.0f, 0.120000005f, 0.00472f, 0);
    }
    if (g != 0 && *(s32 *)(g + 0x474) == 3) {
        o[0x20] = 7;
    }
    switch (o[0x20]) {
    case 0:
        *(s32 *)(ex + 0x20) = 0;
        *(s16 *)(ex + 0x24) = 6;
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
        if (func_003D3CB0(g + 0xE0, ex + 0x10, 2, 0, 0) != 0) {
            approach_00536EB0(ex + 0x10, g + 0xE0);
        }
        if (*(u8 **)(ex + 0x20) != 0) {
            *(vu0_q *)(*(u8 **)(ex + 0x20) + 0x10) = *(vu0_q *)(ex + 0x10);
        }
        o[0x20] = 4;
    case 4:
        if (*(u8 **)(ex + 0x20) != 0) {
            func_L39_00620E28(g, 6, 1);
            {
                u8 *e = *(u8 **)(*(u8 **)(ex + 0x20) + 0x68);
                *(u16 *)(e + 0x7E) = *(u16 *)(ex + 0x28);
                func_L39_0053B810(ex + 0x10, *(u8 **)(ex + 0x20), e);
            }
            *(f32 *)(*(u8 **)(ex + 0x20) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(ex + 0x20) + 0x24) + 0x24);
            *(s32 *)(*(u8 **)(ex + 0x20) + 0x9C) = 1;
            ex[0x26] = 6;
            func_L01_0044BE50(*(u8 **)(ex + 0x20), D_L39_00293F38[*(s32 *)(g + 0x2544)], 0x3F);
            *(s32 *)(ex + 0x20) = 0;
            *(s16 *)(ex + 0x24) = 8;
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
            func_003C2880(*(u8 **)(ex + 0x20));
            *(s32 *)(ex + 0x20) = 0;
        }
        break;
    }
    func_0038CB00(ex + 0x24);
    if (*(u8 **)(ex + 0x20) != 0) {
        *(vu0_q *)(*(u8 **)(ex + 0x20) + 0x10) = *(vu0_q *)(ex + 0x10);
    } else if (*(s16 *)(ex + 0x24) == 0) {
        if (func_L39_00620CF8(g, -1) != 0) {
            f32 v[4] __attribute__((aligned(16)));

            qzero(v);
            *(u8 **)(ex + 0x20) = func_L39_0053BB08(o, g, ex + 0x10, v, 0xFFFFFFFF);
        }
    }
}
/* localdecomp:end func_L39_00536EB0 */

/* localdecomp:start func_L39_00537738 */
__asm__(".extern D_L39_0024BF5C, 16");
extern u8 *D_L39_0024BF5C;

void func_L39_00537738(u8 *a0, u8 *a1) {
    u8 *s;
    u8 *best;
    s32 bestv;
    s32 count;
    s32 i;
    s32 b0;
    s32 b1;
    u8 *m;
    u8 *q;
    u8 *pl;

    s = *(u8 **)(*(u8 **)(a0 + 0x68) + 0x2C);
    pl = s;
    if (s == 0) {
        return;
    }
    if (s[0x1A14] == 0) {
        return;
    }
    b1 = s[0x44EE];
    b0 = s[0x44ED];
    if (b1 == 3) {
        b0 += 2;
    } else {
        b0 += 1;
    }
    b1 = (b1 + 1) % 4;
    b0 = b0 % 256;
    if (a1[3] != 8) {
        return;
    }
    *(s32 *)(a1 + 8) = (*(s16 *)(s + 0x44F2) << 16) | (b0 << 8) | b1;
    count = 0;
    best = 0;
    bestv = 0;
    *(s16 *)(s + 0x44F2) = (s16)(*(u16 *)(s + 0x44F2) + 1) % 0x2000;
    for (i = 1; i <= D_L39_00293F38[*(s32 *)(s + 0x2544)][0]; i++) {
        m = D_L39_0024BF5C + D_L39_00293F38[*(s32 *)(s + 0x2544)][i] * 256;
        if (m != 0 && m[0x20] != 0xFE && m[0x20] != 0xFD) {
            q = *(u8 **)(m + 0x68);
            if (q != 0 && *(s16 *)(q + 0x7C) == *(s32 *)(pl + 0x2544)) {
                if (best == 0 || *(s32 *)(q + 0x5C) < bestv) {
                    best = m;
                    bestv = *(s32 *)(q + 0x5C);
                }
                count++;
            }
        }
    }
    if (count >= 8) {
        *(f32 *)(a1 + 0xC) = (f32) * (s16 *)(*(u8 **)(best + 0x68) + 0x7E);
    } else {
        *(f32 *)(a1 + 0xC) = -1.0f;
    }
}
/* localdecomp:end func_L39_00537738 */
