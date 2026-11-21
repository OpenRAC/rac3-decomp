#include "common.h"

/* NTSC-U counterpart of func_L39_0064BC28 (src/levels/shared/L39_0064AA70.c) */
#include "vu0.h"
extern u8 D_L39_004998A0[];
extern s32 func_L39_00635C78(void *, f32, f32, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_L39_006301D8(void *, void *, void *, f32);
extern void func_L39_0062EC98(void *, s32);
extern void func_L39_00630F00(void *);

/* localdecomp:start func_L39_00649380 */
#include "vu0.h"

typedef struct Q_0064BC28 {
    f32 x, y, z, w;
} Q_0064BC28 __attribute__((aligned(16)));

typedef struct Self_0064BC28 {
    u8 pad0[0x20 - 0x0];
    /* 0x20 */ Q_0064BC28 q20;
    u8 pad30[0xA8 - 0x30];
    /* 0xA8 */ f32 fA8;
    u8 padAC[0xB8 - 0xAC];
    /* 0xB8 */ f32 fB8;
    u8 padBC[0x120 - 0xBC];
    /* 0x120 */ f32 f120;
    u8 pad124[0x160 - 0x124];
    /* 0x160 */ f32 f160;
    u8 pad164[0x1A4 - 0x164];
    /* 0x1A4 */ f32 f1A4;
    u8 pad1A8[0x2C0 - 0x1A8];
    /* 0x2C0 */ f32 f2C0;
    u8 pad2C4[0x2C8 - 0x2C4];
    /* 0x2C8 */ s32 w2C8;
    u8 pad2CC[0x2DE - 0x2CC];
    /* 0x2DE */ s16 h2DE;
    u8 pad2E0[0x324 - 0x2E0];
    /* 0x324 */ s32 w324;
    u8 pad328[0x33A - 0x328];
    /* 0x33A */ s16 h33A;
    u8 pad33C[0x3D0 - 0x33C];
    /* 0x3D0 */ Q_0064BC28 q3D0;
    u8 pad3E0[0x3E4 - 0x3E0];
    /* 0x3E4 */ s16 h3E4;
    /* 0x3E6 */ u8 b3E6;
    u8 pad3E7[0x3E8 - 0x3E7];
    /* 0x3E8 */ f32 f3E8;
    u8 pad3EC[0x474 - 0x3EC];
    /* 0x474 */ s32 w474;
    /* 0x478 */ s32 w478;
    u8 pad47C[0xFB0 - 0x47C];
    /* 0xFB0 */ f32 fFB0;
    u8 padFB4[0xFC0 - 0xFB4];
    /* 0xFC0 */ Q_0064BC28 qFC0;
    /* 0xFD0 */ f32 fFD0;
    u8 padFD4[0xFD8 - 0xFD4];
    /* 0xFD8 */ f32 fFD8;
    u8 padFDC[0x1310 - 0xFDC];
    /* 0x1310 */ s32 w1310;
    u8 pad1314[0x1410 - 0x1314];
    /* 0x1410 */ Q_0064BC28 q1410;
    u8 pad1420[0x1428 - 0x1420];
    /* 0x1428 */ f32 f1428;
    /* 0x142C */ u8 b142C;
    u8 pad142D[0x142F - 0x142D];
    /* 0x142F */ u8 b142F;
    /* 0x1430 */ s32 w1430;
    u8 pad1434[0x15A0 - 0x1434];
    /* 0x15A0 */ Q_0064BC28 q15A0;
    /* 0x15B0 */ f32 f15B0;
    u8 pad15B4[0x19E4 - 0x15B4];
    /* 0x19E4 */ u8 b19E4;
    /* 0x19E5 */ u8 b19E5;
    u8 pad19E6[0x1A05 - 0x19E6];
    /* 0x1A05 */ u8 b1A05;
    /* 0x1A06 */ u8 b1A06;
    u8 pad1A07[0x2468 - 0x1A07];
    /* 0x2468 */ f32 f2468;
    u8 pad246C[0x248C - 0x246C];
    /* 0x248C */ f32 f248C;
    u8 pad2490[0x2534 - 0x2490];
    /* 0x2534 */ s32 p2534;
} Self_0064BC28;

typedef union Buf_0064BC28 {
    u8 b[16];
    u32 w[4];
} Buf_0064BC28;

extern u8 D_L39_004998A0[];

extern void func_L39_006453E8(u8 *state, s32 period, s32 threshold);
extern void func_L39_006455B0(u8 *state, s32 period, s32 threshold);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern s32 func_L39_0061EB48(void *);
extern f32 func_L01_0045D488(s32, s32);
extern f32 func_00389468(f32, f32);
extern void func_L39_00630918(void *);
extern void func_L31_004F0040_00649380(void *, f32, f32);
extern f32 func_L39_0062FFD0(void *, void *);
extern void func_L39_006354F0(u8 *g);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_00630BE0(void *);
extern void func_L39_006314B0(void *);
extern void func_L30_004F0888_00649380(void *);
extern void func_L39_00630E28(u8 *self, f32 angle);
extern void func_L39_00630EE0(void *, void *);
extern void func_L39_0062EC98(void *, s32);
extern void func_L39_00630F00(void *);

/* reads a protected 32-bit value stored as an index byte at q */
static __inline__ u32 get_state_0064BC28(u8 *q) {
    u32 dec;

    if (*q == 0) {
        dec = 0;
    } else {
        Buf_0064BC28 buf;
        u32 a;
        u32 b;
        s32 n;
        s32 k;
        s32 m;
        s32 i;
        u8 *d;

        n = *q;
        k = ((u32)q - n) & 7;
        m = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        dec = b;
    }
    return dec;
}

void func_L39_00649380(Self_0064BC28 *s) {
    s32 c;
    f32 d;
    f32 scale;
    f32 a0;
    f32 a1;
    f32 r;

    c = 0;
    d = s->f2C0 - s->fA8;
    if (s->w2C8 != 0 && d < 0.25f) {
        c = 1;
    }
    if (d < 0.5f || c != 0) {
        if (0.016666668f < s->f1A4) {
            func_L39_006453E8((u8 *)s, 0, 2);
        }
        if (0.008333334f < s->f1A4) {
            func_L39_006455B0((u8 *)s, 2, 4);
        }
    }
    if (!((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_0061EB48(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        f32 x;

        if (s->f1A4 < 0.028333336f) {
            s->b142C = 1;
            if (2.0943952f < fabs_asm(s->fFD8) && s->f2468 == 1.0f) {
                s->b142F = 1;
            }
        }
        x = func_L01_0045D488(1, s->p2534);
        if (1.9198622f < func_00389468(x, func_L01_0045D488(7, s->p2534)) &&
            1.2217305f < fabs_asm(s->fFD8) && s->f2468 == 1.0f) {
            s->b142F = 1;
            s->b142C = 1;
        }
        if (fabs_asm(s->fFD8) < 0.08726646f) {
            s->b142C = 0;
        }
    }
    if (s->w324 < 3 && 1.5707964f < fabs_asm(s->fFD8) && s->b3E6 != 0) {
        s->b142F = 1;
        s->b142C = 1;
    }
    if (s->b142F != 0 && fabs_asm(s->fFD8) < 0.06981317f) {
        s->b142F = 0;
    }
    if (s->f2468 < 0.2f) {
        if (s->w1430 != 0) {
            s->b142F = 1;
        }
        s->qFC0 = s->q1410;
        s->fFD0 = s->f1428;
        s->fFB0 = 0.0f;
    } else {
        s32 v;

        func_L39_00630918(s);
        v = -1;
        if (s->w474 == 2) {
            v = s->w478;
        }
        if (v == 10 && (s->f248C == 1.0f || s->w1430 != 0) && s->b1A05 == 0) {
            s->q1410 = s->qFC0;
            s->f1428 = s->fFD0;
            s->w1430 = 1;
        } else {
            s->q1410 = s->q20;
            s->f1428 = s->fB8;
        }
    }
    if (0.0f < s->f15B0) {
        func_L31_004F0040_00649380(s, 0.7f, 0.0f);
        {
            Q_0064BC28 tmp;

            tmp = s->q15A0;
            s->fFB0 = s->fFB0 + func_L39_0062FFD0(s, &tmp);
        }
        if (s->fFB0 < 0.011666667f) {
            s->fFB0 = 0.011666667f;
        }
        qzero(&s->q15A0);
    }
    scale = 1.0f;
    if (((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_0061EB48(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        func_L39_006354F0((u8 *)s);
    } else {
        s->f3E8 = s->fB8;
        s->q3D0 = s->q20;
        if ((get_state_0064BC28(&s->b19E5) ^ 1) == 0 && s->b142F == 0 && s->b1A05 == 0) {
            func_L39_00630AC0(s, 0, 0.037f, 0.13f, 0.20362175f);
        } else {
            f32 a = fabs_asm(s->fFD8);

            if (s->f2468 < 0.9f || (s->b1A05 != 0 && s->b142F == 0)) {
                if (0.7853982f < a) {
                    scale = 0.0f;
                }
            }
            func_L39_00630BE0(s);
        }
    }
    func_L39_006314B0(s);
    func_L30_004F0888_00649380(s);
    if (s->b142F != 0) {
        f32 lim = 0.12083334f - fabs_asm(s->fFD8) * 0.09166667f / 3.1415927f;

        if (lim < 0.0f) {
            lim = 0.0f;
        }
        if (lim < s->fFB0) {
            s->fFB0 = lim;
        }
    }
    a0 = scale * 0.010277778f;
    a1 = 0.008333334f;
    if (s->b142F != 0) {
        f32 k = 2.6179938f - s->fFD8;

        if (1.0f < k) {
            k = 1.0f;
        }
        if (k < 0.2f) {
            k = 0.2f;
        }
        s->fFB0 = s->fFB0 * k;
        a1 = 0.004722222f;
    }
    r = fabs_asm(s->fFD8);
    if (s->f2468 < 0.75f && 0.61086524f < r) {
        f32 k = 1.0f - r * 0.4f;

        if (k < 0.0f) {
            k = 0.0f;
        }
        s->fFB0 = s->fFB0 * k;
    }
    func_L39_00630DD8((u8 *)s, a0, a1);
    if (s->b142C != 0 || ((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_0061EB48(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
        if (s->b1A06 == 0) {
            func_L39_00630E28((u8 *)s, ((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_0061EB48(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0) ? s->f3E8 : s->fFD0);
        } else if (((s->h3E4 != 0 ||
         (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->p2534) != 0 &&
          func_L39_0061EB48(s) != 10)) &&
        (get_state_0064BC28(&s->b19E4) ^ 0x10) != 0)) {
            func_L39_00630EE0(s, &s->q3D0);
        } else {
            func_L39_00630EE0(s, &s->qFC0);
        }
    } else {
        func_L39_00630E28((u8 *)s, 99999.0f);
    }
    func_L39_0062EC98(s, 0);
    if (s->h33A != 0) {
        func_L39_00635C78(s, 5.0f, 0.2f, 0.35f);
    }
    if (s->h2DE != 0) {
        func_L39_006301D8(s, &s->f120, &s->f160, 0.0069444445f);
        func_L39_00630F00(s);
    } else {
        func_L39_006301D8(s, &s->f120, &s->f120, 0.015000001f);
    }
}
/* localdecomp:end func_L39_00649380 */
