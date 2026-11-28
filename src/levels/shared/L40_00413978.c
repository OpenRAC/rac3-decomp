#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L40_00413978 */

typedef union { u8 b[8]; u32 w[2]; } Buf_00413978;
typedef struct {
    s32 target;
    s32 path;
    u8 p8[4];
    s32 sound;
    vu0_v4 push[8];
    vu0_v4 spot[8];
    s32 a110[8];
    s32 step[8];
    s32 a150[8];
    s32 a170[8];
    u8 *owner[8];
    f32 len[8];
} V_00413978;
typedef struct { u8 p0[0xD0]; u8 bD0; u8 pD1[0xB]; u8 *pDC; } Slot_00413978;

extern s32 D_L40_00241128;
extern u8 *D_L40_00248500;
__asm__(".extern D_L40_00248500, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 4");
extern u8 D_001FE020[];
extern u8 *D_L40_00249330[] __attribute__((section(".sdata")));
extern u8 D_L40_003BFE20[];
extern f32 D_L40_00247480[] __attribute__((section(".sdata")));
extern f32 D_L40_00247490[] __attribute__((section(".sdata")));

static __inline__ u32 decode_00413978(u8 *q) {
    Buf_00413978 buf;
    s32 n, k, m, i;
    u8 *d;
    u32 a, b;

    if (*q == 0) return 0;
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

void func_L40_00413978(u8 *m) {
    extern void func_003C2880(void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038CED8(void *);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CFB8(void *, void *, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_L39_005F33E0(s32, s32, void *);
    extern void func_L01_003F2AF8(s32, s32);
    extern void func_L40_00414200(void *, void *);
    extern s32 func_L39_00648840(void *, s32);
    extern void func_L39_00648960(void *, s32);
    extern void func_L11_00348CA0(void *);
    V_00413978 *v = *(V_00413978 **)(m + 0x68);
    s32 i;
    s32 j;
    u8 *e;
    f32 half;

    if (D_L40_00241128 == 2) {
        return;
    }
    switch (m[0x20]) {
    case 0:
        if (v->target != -1) {
            e = (u8 *)(v->target * 128 + (s32)D_L40_00248500);
            *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(e + 0x30),
                                               *(f32 *)(m + 0x14) - *(f32 *)(e + 0x34));
        } else if (v->path == v->target) {
            func_003C2880(m);
            return;
        } else {
            e = (u8 *)((v->path << 8) + (s32)D_L40_0024845C);
            *(f32 *)(m + 0xF8) = func_0038D160(*(f32 *)(m + 0x10) - *(f32 *)(e + 0x10),
                                               *(f32 *)(m + 0x14) - *(f32 *)(e + 0x14));
        }
        *(u16 *)(m + 0x34) |= 0x2000;
        for (j = 0; j < 8; j++) {
            v->step[j] = (*(s16 *)(m + 0xB2) + j) % 8;
            v->a110[j] = -1;
            v->a170[j] = 0;
            v->owner[j] = 0;
        }
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0x80;
        m[0x62] = 0x40;
        v->sound = -1;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        if (v->sound == -1 || ((Slot_00413978 *)(D_001FE020 + (v->sound << 7)))->pDC != m
            || ((Slot_00413978 *)(D_001FE020 + (v->sound << 7)))->bD0 == 0) {
            v->sound = func_L39_005F33E0(0, 4, m);
        }
        half = 0.5f;
        for (i = 0; i < 8; i++) {
            u8 *p = D_L40_00249330[i];
            f32 f20, f21;

            if (p == 0) {
                continue;
            }
            if (v->owner[i] == p) {
                if ((decode_00413978(p + 0x19E4) ^ 0x83) == 0) {
                    vu0_v4 tmp;

                    f20 = func_0038CED8(&v->push[i]);
                    if (func_0038CF38(p + 0xA0, &v->spot[i]) < half) {
                        f20 = 0.0f;
                    } else {
                        f21 = 0.0f;
                        if (f20 != f21) {
                            vec_sub_ba(&tmp, &v->spot[i], p + 0xA0);
                            tmp.z = f21;
                            if (func_0038CE68(&tmp, &v->push[i]) < f21) {
                                f20 = 0.0f;
                            }
                        }
                    }
                    func_0038CFB8(&v->push[i], &v->push[i], f20 - v->len[i]);
                    func_0038CFB8(p + 0x120, p + 0x120, 0.0f);
                    *(vu0_v4 *)(p + 0x130) = *(vu0_v4 *)((u8 *)v->push + i * 16);
                    *(f32 *)(p + 0x13C) = 0.0f;
                } else {
                    if (v->a150[i] != 0) {
                        *(s16 *)(v->a170[i] + 0x1A) = 0;
                        if (p[0x1A14] != 0) {
                            func_L01_003F2AF8(p[0x24C9], v->a170[i]);
                        }
                        v->a150[i] = 0;
                    }
                    v->owner[i] = 0;
                }
                continue;
            }
            if (*(u8 **)(p + 0x2CC) == m) {
                func_L40_00414200(m, &v->spot[i]);
                *(f32 *)(p + 0x2498) = (v->spot[i].z - *(f32 *)(p + 0xA8)) + 6.0f;
                if (func_L39_00648840(p, 0x13) == 0) {
                    func_L39_00648960(p, 0x13);
                }
            }
            if ((decode_00413978(p + 0x19E4) ^ 0x83) == 0 && *(u8 **)(p + 0x2CC) == m && *(s32 *)(p + 0x2F0) == 0) {
                vu0_v4 tmp;
                vu0_v4 tmp2;

                func_L39_005F33E0(1, 0, m);
                if (++v->step[i] >= 12) {
                    v->step[i] = 0;
                }
                f21 = D_L40_00247480[v->step[i] % 4];
                tmp.x = func_0038D098(D_L40_00247490[v->step[i]]) * f21;
                tmp.y = func_0038D0B0(D_L40_00247490[v->step[i]]) * f21;
                tmp.z = 0.0f;
                vec_add_ba(&v->spot[i], &v->spot[i], &tmp);
                f21 = func_0038CF38(p + 0xA0, &v->spot[i]);
                f20 = *(f32 *)(p + 0x249C);
                f20 = f20 * 0.000400000019f;
                f20 = f20 * f21;
                f20 = f20 * half;
                f20 = f20 / *(f32 *)(p + 0x2498);
                vec_sub_ab(&tmp2, &v->spot[i], p + 0xA0);
                tmp2.z = 0.0f;
                func_0038CFB8(&v->push[i], &tmp2, sqrt_asm((f20 + f20) * f21));
                func_0038CFB8(p + 0x120, p + 0x120, 0.0f);
                v->len[i] = f20;
                v->owner[i] = p;
            }
        }
        break;
    }
    if (m[0x31] != 0) {
        func_L11_00348CA0(m);
    }
}
/* localdecomp:end func_L40_00413978 */
