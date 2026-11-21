/* functional: medium. Written from the PAL assembly (no draft). Guber-style group controller: ties up to 8 followers (D_L40_00249330[]) to formation slots. The three value reads at +0x19E4 (xor 0x83) are the game's obfuscated byte-table decode (written once as a helper, retail inlines it); the vector adds/subs are plain float math (retail: VU0 vadd/vsub.xyz, w untouched). */
#include "vu0.h"

typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00413978;
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00413978;

extern u8 *D_L40_00248500;
__asm__(".extern D_L40_00248500, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 4");
extern s32 D_L40_00241128;
extern u8 D_001FE020[];
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern u8 D_L40_003BFE20[];
extern f32 D_L40_00247480[];
extern f32 D_L40_00247490[];
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

static s32 decode_00413978(u8 *q) {
    Buf_00413978 buf;
    s32 n, k, m, i;
    u8 *d;

    if (*q == 0) {
        return 0;
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
    return buf.w[1];
}

void func_L40_00413978(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i;

    if (D_L40_00241128 == 2) {
        return;
    }
    if (m[0x20] == 0) {
        s32 a = *(s32 *)v;
        f32 x = *(f32 *)(m + 0x10);
        f32 y = *(f32 *)(m + 0x14);
        f32 ex, ey;

        if (a != -1) {
            u8 *e = D_L40_00248500 + a * 128;
            ex = *(f32 *)(e + 0x30);
            ey = *(f32 *)(e + 0x34);
        } else if (*(s32 *)(v + 4) == a) {
            func_003C2880(m);
            return;
        } else {
            u8 *e = D_L40_0024845C + (*(s32 *)(v + 4) << 8);
            ex = *(f32 *)(e + 0x10);
            ey = *(f32 *)(e + 0x14);
        }
        *(f32 *)(m + 0xF8) = func_0038D160(x - ex, y - ey);
        *(u16 *)(m + 0x34) = *(u16 *)(m + 0x34) | 0x2000;
        for (i = 0; i < 8; i++) {
            s32 n = *(s16 *)(m + 0xB2) + i;

            *(s32 *)(v + 0x130 + i * 4) = n % 8;
            *(s32 *)(v + 0x110 + i * 4) = -1;
            *(s32 *)(v + 0x170 + i * 4) = 0;
            *(s32 *)(v + 0x190 + i * 4) = 0;
        }
        m[0x30] = 0xFF;
        m[0x62] = 0x40;
        *(s16 *)(m + 0x32) = 0x80;
        *(s32 *)(v + 0xC) = -1;
        func_L01_004450F0(m, 1, -1);
    } else if (m[0x20] == 1) {
        s32 c = *(s32 *)(v + 0xC);

        if (c == -1 || *(u8 **)(D_001FE020 + c * 128 + 0xDC) != m || D_001FE020[c * 128 + 0xD0] == 0) {
            *(s32 *)(v + 0xC) = func_L39_005F33E0(0, 4, m);
        }
        for (i = 0; i < 8; i++) {
            u8 *p = D_L40_00249330[i];
            V_00413978 tmp;
            V_00413978 tmp2;
            f32 f20, f21, d;
            s32 k;

            if (p == 0) {
                continue;
            }
            if (*(u8 **)(v + 0x190 + i * 4) == p) {
                if (decode_00413978(p + 0x19E4) == 0x83) {
                    u8 *slot = v + 0x10 + i * 16;
                    V_00413978 *vv = (V_00413978 *)(v + 0x90 + i * 16);
                    V_00413978 *pp = (V_00413978 *)(p + 0xA0);

                    f20 = func_0038CED8(slot);
                    if (func_0038CF38(pp, vv) < 0.5f) {
                        f20 = 0.0f;
                    } else {
                        f21 = 0.0f;
                        if (f20 != f21) {
                            tmp.x = vv->x - pp->x;
                            tmp.y = vv->y - pp->y;
                            tmp.z = f21;
                            tmp.w = vv->w;
                            if (func_0038CE68(&tmp, slot) < f21) {
                                f20 = 0.0f;
                            }
                        }
                    }
                    func_0038CFB8(slot, slot, f20 - *(f32 *)(v + 0x1B0 + i * 4));
                    func_0038CFB8(p + 0x120, p + 0x120, 0.0f);
                    *(V_00413978 *)(p + 0x130) = *(V_00413978 *)slot;
                    *(f32 *)(p + 0x13C) = 0.0f;
                } else {
                    if (*(s32 *)(v + 0x150 + i * 4) != 0) {
                        s32 *tgt = (s32 *)(v + 0x170 + i * 4);

                        *(s16 *)(*tgt + 0x1A) = 0;
                        if (p[0x1A14] != 0) {
                            func_L01_003F2AF8(p[0x24C9], *tgt);
                        }
                        *(s32 *)(v + 0x150 + i * 4) = 0;
                    }
                    *(s32 *)(v + 0x190 + i * 4) = 0;
                }
                continue;
            }
            if (*(u8 **)(p + 0x2CC) == m) {
                V_00413978 *vv = (V_00413978 *)(v + 0x90 + i * 16);

                func_L40_00414200(m, vv);
                *(f32 *)(p + 0x2498) = (*(f32 *)((u8 *)vv + 8) - *(f32 *)(p + 0xA8)) + 6.0f;
                if (func_L39_00648840(p, 0x13) == 0) {
                    func_L39_00648960(p, 0x13);
                }
            }
            if (decode_00413978(p + 0x19E4) == 0x83 && *(u8 **)(p + 0x2CC) == m && *(s32 *)(p + 0x2F0) == 0) {
                s32 *cnt = (s32 *)(v + 0x130 + i * 4);
                V_00413978 *vv = (V_00413978 *)(v + 0x90 + i * 16);
                V_00413978 *pp = (V_00413978 *)(p + 0xA0);
                f32 w;

                func_L39_005F33E0(1, 0, m);
                *cnt = *cnt + 1;
                if (*cnt >= 0xC) {
                    *cnt = 0;
                }
                k = *cnt;
                f21 = D_L40_00247480[k % 4];
                tmp.x = func_0038D098(D_L40_00247490[k]) * f21;
                tmp.y = func_0038D0B0(D_L40_00247490[k]) * f21;
                tmp.z = 0.0f;
                vv->x = vv->x + tmp.x;
                vv->y = vv->y + tmp.y;
                vv->z = vv->z + tmp.z;
                f21 = func_0038CF38(pp, vv);
                f20 = *(f32 *)(p + 0x249C) * 0.000400000019f;
                tmp2.x = vv->x - pp->x;
                tmp2.y = vv->y - pp->y;
                tmp2.z = vv->z - pp->z;
                tmp2.z = 0.0f;
                f20 = f20 * f21;
                f20 = f20 * 0.5f;
                f20 = f20 / *(f32 *)(p + 0x2498);
                w = sqrt_asm((f20 + f20) * f21);
                func_0038CFB8(v + 0x10 + i * 16, &tmp2, w);
                func_0038CFB8(p + 0x120, p + 0x120, 0.0f);
                *(f32 *)(v + 0x1B0 + i * 4) = f20;
                *(u8 **)(v + 0x190 + i * 4) = p;
            }
        }
    }
    if (m[0x31] != 0) {
        func_L11_00348CA0(m);
    }
}
