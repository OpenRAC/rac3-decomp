#include "common.h"

/* declared by functions of L39_0062AD60.c, which this file was cut from */
typedef int q128 __attribute__((mode(TI)));
typedef struct {
    char pad0[0xA0];
    q128 cur;
    char padB0[0x1DC0 - 0xB0];
    q128 hist[32];
    char pad1FC0[0x2348 - 0x1FC0];
    s32 pos;
    s32 count;
} Obj;
extern s32 func_L39_0062AE10(Obj *, s32);

/* localdecomp:start func_L39_0062AE10 */
#include "vu0.h"

typedef union Buf_0062AE10 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0062AE10;

typedef struct G_0062AE10 {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    vu0_v4 v20;
    vu0_v4 v30;
    vu0_v4 v40;
} G_0062AE10;

extern u8 D_L39_004997E0[];
extern G_0062AE10 D_L39_0025F740;
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00632180(u8 *, f32 *, s32, f32, f32, f32);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern s32 func_L01_003FC480(void *, s32, f32, f32, void *);
extern s32 func_L01_003FDCA0(void *, s32, f32);

static __inline__ s16 Dec16_0062AE10(u8 *q) {
    Buf_0062AE10 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

static __inline__ u32 Dec32_0062AE10(u8 *q) {
    Buf_0062AE10 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ s32 Is32_0062AE10(u8 *q, u32 v) {
    return Dec32_0062AE10(q) == v;
}

s32 func_L39_0062AE10(Obj *obj, s32 idx) {
    u8 *s = (u8 *)obj;
    s32 hit;
    s32 c;
    s32 mask;
    s32 i;
    s32 r;

    if (Dec16_0062AE10(s + 0x313) != 0) {
        return 1;
    }
    {
    vu0_v4 save;
    vu0_v4 vel;

    save = *(vu0_v4 *)(s + 0xA0);
    qzero(&vel);
    hit = 0;
    if (func_0038CE68(s + 0x40, s + 0x250) > -0.92f) {
        hit = 1;
    }
    if (s[0x1A06] != 0 || *(s16 *)(s + 0x33E) != 0 || hit) {
        if (s[0x1A06] == 1 || *(s16 *)(s + 0x33E) != 0) {
            func_L39_00632180(s, &vel.x, 0, 0.0f, 0.0f, 0.6f);
        } else {
            func_L39_00632180(s, &vel.x, 0, 0.0f, 0.0f, *(f32 *)(s + 0x1E4));
        }
    } else {
        vel.z = *(f32 *)(s + 0x1E4);
    }
    vec_add_ab(s + 0xA0, s + 0xA0, &vel);

    c = 0;
    if (Is32_0062AE10(s + 0x19E4, 0x7E) ||
        (Is32_0062AE10(s + 0x19E4, 0x90) && Is32_0062AE10(s + 0x19E7, 0x7E))) {
        c = 0xD;
    }
    mask = (c << 8) | 0x24;

    for (i = 0; i < 8; i++) {
        if (s[0x1A06] != 0 || hit) {
            r = func_L01_003FB640(s + 0xA0, mask, *(f32 *)(s + 0x1F4), *(void **)(s + 0x2524));
            if (Dec16_0062AE10(s + 0x312) == 0) {
                r |= func_L01_003FDCA0(s + 0xA0, 0, *(f32 *)(s + 0x1F4));
            }
        } else {
            f32 t = *(f32 *)(s + 0x1E0) - *(f32 *)(s + 0x1E4);
            if (t < 0.05f) {
                t = 0.05f;
            }
            r = func_L01_003FC480(s + 0xA0, mask, *(f32 *)(s + 0x1F4), t, *(void **)(s + 0x2524));
            if (Dec16_0062AE10(s + 0x312) == 0) {
                r |= func_L01_003FDCA0(s + 0xA0, 0, *(f32 *)(s + 0x1F4));
            }
        }
        if (r == 0) {
            break;
        }
        *(q128 *)(s + 0xA0) = *(q128 *)&D_L39_0025F740.v30;
        *(q128 *)(s + 0x1C0) = *(q128 *)&D_L39_0025F740.v40;
        *(q128 *)(s + 0x1D0) = *(q128 *)&D_L39_0025F740.v20;
        s[0x216] = 1;
        *(s32 *)(s + 0x1FC) = D_L39_0025F740.f18;
    }

    vec_sub_ba(s + 0xA0, s + 0xA0, &vel);
    {
    vu0_v4 d;
    f32 len;

    vec_sub_ba(&d, s + 0xA0, &save);
    len = func_0038CEA8(&d);
    if (*(f32 *)(s + 0x1F4) * 1.5f < len) {
        if (idx == 15) {
        if (d.x > 512.0f) {
            d.x = 512.0f;
        } else if (d.x < -512.0f) {
            d.x = -512.0f;
        }
        if (d.y > 512.0f) {
            d.y = 512.0f;
        } else if (d.y < -512.0f) {
            d.y = -512.0f;
        }
        if (d.z > 512.0f) {
            d.z = 512.0f;
        } else if (d.z < -512.0f) {
            d.z = -512.0f;
        }
        func_0038CF68(&d, &d, *(f32 *)(s + 0x1F4));
        vec_add_ab(s + 0xA0, &save, &d);
        }
        return -1;
    }
    }
    }
    return 1;
}
/* localdecomp:end func_L39_0062AE10 */
