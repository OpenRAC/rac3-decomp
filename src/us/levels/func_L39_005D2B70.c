#include "common.h"

/* NTSC-U counterpart of func_L39_005D50A0 (src/levels/shared/L39_005D50A0.c) */
/* localdecomp:start func_L39_005D2B70 */
#include "vu0.h"

typedef int u128_005D50A0 __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z;   /* 0x00 */
    f32 fC;        /* 0x0C */
    s32 f10;       /* 0x10 */
    f32 f14;       /* 0x14 */
    f32 f18;       /* 0x18 */
    u8 f1C;        /* 0x1C */
    u8 f1D;        /* 0x1D */
    u8 f1E;        /* 0x1E */
} S_005D50A0_sub;

typedef struct {
    u8 pad0[2];
    u8 f2;         /* 0x02 */
    u8 pad3;
    u32 f4;        /* 0x04 */
    u8 f8;         /* 0x08 */
    u8 pad9;
    s16 fA;        /* 0x0A */
    f32 fC;        /* 0x0C */
    f32 pos[3];    /* 0x10 */
    f32 f1C;       /* 0x1C */
    S_005D50A0_sub sub; /* 0x20 */
} S_005D50A0;

typedef struct {
    u8 pad[2];
    u8 f2;
    u8 f3;
} S_005D50A0_part;

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_005D50A0;

extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003BF6A8(f32 *v, f32 r);
extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_003CF790(void *, s32, void *, s32, f32);
extern S_005D50A0_part *func_L01_00471970(s32, void *, void *, u32, f32, f32, f32, s32, s32, s32, s32);

extern u8 D_001D7E80_sda;
extern s32 D_001D7E7C_sda;
extern s32 D_001D7E74_sda_005D2B70;
extern s32 D_001D7E78_sda;
extern f32 D_001D7E68_sda;
extern f32 D_001D7E6C_sda;
extern f32 D_001D7E70_sda;
__asm__(".extern D_001D7E68_sda, 4");
__asm__(".extern D_001D7E6C_sda, 4");
__asm__(".extern D_001D7E70_sda, 4");
__asm__(".extern D_001D7E74_sda_005D2B70, 4");
__asm__(".extern D_001D7E78_sda, 4");

void func_L39_005D2B70(S_005D50A0 *p) {
    S_005D50A0_sub *q;
    f32 save;
    f32 t;
    f32 scale;
    f32 top;
    u8 alpha;
    S_005D50A0_part *r;
    s32 n;
    s32 i;
    V_005D50A0 v;
    V_005D50A0 d;

    if (func_003883C8(&p->fA) != 0) {
        func_003C7CE0(p);
        return;
    }
    q = &p->sub;
    p->f8 += D_001D7E80_sda;
    save = p->f1C;
    t = (f32)p->fA * save;
    alpha = (s32)((f32)q->f1C * t);
    p->f4 = (p->f4 & 0xFFFFFF) | (alpha << 24);
    p->fC = q->f18 + (q->f14 - q->f18) * t;
    scale = p->fC / 500000.0f;
    if (0.0f < q->fC && q->z < 0.0f) {
        f32 dz;
        top = q->fC + scale;
        dz = top - p->pos[2];
        if (q->z * 5.0f < dz) {
            q->z = dz / 5.0f;
        }
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(*(V_005D50A0 *)p->pos) : "m"(*(V_005D50A0 *)&p->sub));
        if (p->pos[2] < top) {
            p->pos[2] = top;
        }
    } else {
        __asm__ __volatile__(
            "lqc2 $vf1, %0\n"
            "lqc2 $vf2, %1\n"
            "vadd.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "+m"(*(V_005D50A0 *)p->pos) : "m"(*(V_005D50A0 *)q));
    }
    if (q->f1E != 0 && func_L39_005B2498(q->f1E) == 0) {
        if (func_L39_005B2498(D_001D7E7C_sda) == 0) {
            *(u128_005D50A0 *)&v = 0;
            v.z = scale * 0.16666667f;
            r = func_L01_00471970(q->f10, p->pos, &v, ((s32)(t * 64.0f) << 24) | 0x202020,
                                  0.0f, p->fC, p->fC * 0.8f, 0x28, 0, 0, 1);
            if (r != 0) {
                r->f3 = 0x44;
            }
        } else {
            V_005D50A0 *dp;
            f32 spread;
            f32 rad;
            f32 yaw;
            f32 yaw2;
            f32 pitch;

            v = *(V_005D50A0 *)p->pos;
            func_003BF6A8(&v.x, scale);
            rad = 0.017453292f;
            dp = &d;
            spread = D_001D7E6C_sda * scale;
            yaw = func_00388A28(q->x, q->y);
            yaw2 = func_00389380(yaw, func_L39_005B2510(-(D_001D7E70_sda * rad), D_001D7E70_sda * rad));
            pitch = func_00388A28(func_003887A0(q), q->z);
            pitch = func_00389380(pitch, func_L39_005B2510(0.0f, D_001D7E70_sda * rad));
            func_0037E4B8(dp, spread, yaw2, pitch);
            n = func_L39_005B24C8(D_001D7E74_sda_005D2B70, D_001D7E78_sda);
            r = func_L01_00471970(q->f10, &v, dp, p->f4, 0.0f, p->fC, p->fC * D_001D7E68_sda, n, 0, 0, 0);
            if (r != 0) {
                r->f2 = p->f2;
            }
        }
    }
    if (q->f1D != 0 && alpha >= 15) {
        n = func_003CF790(p->pos, 1, (void *)q->f10, 0, scale);
        for (i = 0; i < n; i++) {
        }
    }
    p->f1C = save;
}
/* localdecomp:end func_L39_005D2B70 */
