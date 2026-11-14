#include "common.h"

/* declared by functions of L39_00629DE0.c, which this file was cut from */
extern u8 D_L39_004997E0[];

/* localdecomp:start func_L39_0062A4C0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0062A4C0;
typedef struct {
    u8 pad0[0xA0];
    V_0062A4C0 vA0;
    u8 padB0[0x120 - 0xB0];
    V_0062A4C0 v120;
    V_0062A4C0 v130;
    V_0062A4C0 v140;
    V_0062A4C0 v150;
    V_0062A4C0 v160;
    V_0062A4C0 v170;
    V_0062A4C0 v180;
    V_0062A4C0 pad190;
    f32 f1A0;
    f32 f1A4;
    f32 f1A8;
    f32 f1AC;
    f32 f1B0;
    f32 f1B4;
    u8 pad1B8[0x1F4 - 0x1B8];
    f32 f1F4;
    u8 pad1F8[4];
    s32 w1FC;
    u8 pad200[0x216 - 0x200];
    u8 b216;
    u8 pad217[0x2AC - 0x217];
    f32 f2AC;
    u8 pad2B0[0x313 - 0x2B0];
    u8 b313;
    u8 pad314[0x15A0 - 0x314];
    V_0062A4C0 v15A0;
    u8 pad15B0[0x19E4 - 0x15B0];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
} O_0062A4C0;
typedef union {
    u8 b[16];
    u32 w[4];
    u16 h[8];
} B_0062A4C0;
extern f32 func_L39_006325D8(void *, void *);
extern void func_L39_00632298(void *, void *, void *, f32);
extern f32 func_L39_00632678(void *, void *);
extern void func_L39_00632558(void *, void *, void *, f32);
extern void func_L39_00632B68(void *, void *, void *);
extern f32 func_L39_00632818(void *, void *);
extern void func_L39_0062AD60(void *);
extern void func_L39_00630548(void *);
extern void func_L39_00631100(void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);

/* the obfuscated-value getters: a byte key at q decodes to a 32-bit or a 16-bit value */
static __inline__ u32 get32_0062A4C0(u8 *q) {
    B_0062A4C0 buf;
    s32 n, k, m, j;
    u8 *bp;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    bp = buf.b;
    for (j = 0; j < 40; j += 5) {
        *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
    }
    buf.w[0] ^= (u32)q;
    buf.w[1] ^= buf.w[0];
    return buf.w[1];
}

static __inline__ s16 get16_0062A4C0(u8 *q) {
    B_0062A4C0 buf;
    s32 n, k, m, j;
    u8 *bp;
    u32 a, b;
    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    bp = buf.b;
    for (j = 0; j < 24; j += 3) {
        *bp++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

void func_L39_0062A4C0(u8 *arg0) {
    O_0062A4C0 *o = (O_0062A4C0 *)arg0;
    V_0062A4C0 saved;
    f32 lim;
    f32 d;

    lim = o->f1F4 - 0.02f;
    saved = o->vA0;
    if ((get32_0062A4C0(&o->b19E4) ^ 0x14) == 0 || (get32_0062A4C0(&o->b19E4) ^ 0x83) == 0) {
        if (get16_0062A4C0(&o->b313) == 0) {
            if (lim < func_L39_006325D8(o, &o->v120)) {
                func_L39_00632298(o, &o->v120, &o->v120, lim);
            }
        }
        d = func_L39_00632678(o, &o->v120);
        if (d < 0.0f) {
            f32 m = -o->f2AC;
            if (d < m) {
                f32 lo = m - 0.1f;
                if (d < lo) {
                    d = lo;
                }
                if (d > 0.0f) {
                    d = 0.0f;
                }
                func_L39_00632558(o, &o->v120, &o->v120, d);
            }
        }
        {
            f32 len = func_0038CEA8(&o->v120);
            if (lim < len) {
                func_0038CE20(&o->v120, &o->v120, lim / len);
            }
        }
    } else if ((get32_0062A4C0(&o->b19E6) ^ 0xD) != 0 && (get32_0062A4C0(&o->b19E6) ^ 0xE) != 0) {
        if (get16_0062A4C0(&o->b313) == 0) {
            if (lim < func_0038CEA8(&o->v120)) {
                func_0038CF68(&o->v120, &o->v120, lim);
            }
        }
    }
    {
        V_0062A4C0 a;
        V_0062A4C0 b;
        vec_add_ab(&o->vA0, &o->vA0, &o->v120);
        vec_add_ab(&o->vA0, &o->vA0, &o->v15A0);
        o->b216 = 0;
        qzero(&o->v15A0);
        o->w1FC = 0;
        if (func_0038CEA8(&o->v130) <= 0.0001f) {
            func_L39_0062AD60(o);
            func_L39_00630548(o);
            vec_sub_ab(&o->v140, &o->vA0, &saved);
            func_L39_00631100(o);
        } else {
            func_L39_00630548(o);
        }
        vec_sub_ba(&o->v150, &o->vA0, &saved);
        o->v170 = o->v150;
        o->v160 = o->v150;
        func_0038CF68(&o->v150, &o->v150, 1.0f);
        {
            f32 t = func_0038CE68(&o->v150, &o->v120);
            if (t < 0.0f) {
                t = 0.0f;
            }
            func_0038CF68(&o->v150, &o->v120, t);
        }
        a = o->v120;
        {
            func_L39_00632B68(o, &a, &a);
            func_L39_00632B68(o, &o->v170, &o->v170);
            func_0038CF68(&o->v170, &o->v170, 1.0f);
            {
                f32 t = func_0038CE68(&o->v170, &a);
                if (t < 0.0f) {
                    t = 0.0f;
                }
                func_0038CF68(&o->v170, &a, t);
            }
            {
                V_0062A4C0 *d = &o->v160;
                b = o->v120;
                func_L39_00632298(o, &b, &b, 0.0f);
                func_L39_00632298(o, d, d, 0.0f);
                func_0038CF68(d, d, 1.0f);
                {
                    f32 t = func_0038CE68(d, &b);
                    if (t < 0.0f) {
                        t = 0.0f;
                    }
                    func_0038CF68(d, &b, t);
                }
            }
        }
        o->f1A0 = func_0038CEA8(&o->v150);
        o->f1A4 = func_L39_006325D8(o, &o->v150);
        a = o->v150;
        o->f1A8 = func_L39_00632818(o, &a);
        o->f1B0 = func_L39_00632678(o, &o->v150);
        if (o->f1A8 < 0.0f) {
            o->f1A8 = 0.0f;
        }
        a = o->vA0;
        {
            if (func_0038CEA8(&o->v130) > 0.0001f) {
                vec_add_ba(&o->vA0, &o->vA0, &o->v130);
                {
                    f32 w = o->v130.w;
                    qzero(&o->v130);
                    o->v130.w = w;
                }
                func_L39_0062AD60(o);
                func_L39_00630548(o);
                vec_sub_ab(&o->v140, &o->vA0, &saved);
                func_L39_00631100(o);
            }
            vec_sub_ba(&o->v180, &o->vA0, &a);
        }
        o->f1B4 = func_0038CEA8(&o->v180);
        o->v180.w = o->v130.w;
        o->v130.w = 0.0f;
        vec_sub_ba(&o->v140, &o->vA0, &saved);
        o->f1AC = 0.0f;
        if (o->f1A4 > 0.004f) {
            f32 r = o->v140.z / o->f1A4;
            o->f1AC = r;
            if (r > 0.5f) {
                o->f1AC = 0.5f;
            } else if (r < -0.5f) {
                o->f1AC = -0.5f;
            }
        }
        if (o->f1A0 > 1.0400001f) {
            func_0038CE20(&o->v140, &o->v140, 1.0400001f / o->f1A0);
            o->f1A0 = 1.0400001f;
        }
    }
}
/* localdecomp:end func_L39_0062A4C0 */
