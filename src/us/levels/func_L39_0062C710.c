#include "common.h"

/* NTSC-U counterpart of func_L39_0062EF58 (src/levels/shared/L39_0062E930.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;
extern u8 D_L39_004998A0[];
#include "vu0.h"
extern u8 D_L39_004998A0[];
extern void func_L39_0062FD10(S_62FD10 *, Vec4 *, Vec4 *, f32);
extern void func_003BEBF8(f32 *, f32, f32);

/* localdecomp:start func_L39_0062C710 */
#include "vu0.h"

typedef int q_0062EF58 __attribute__((mode(TI)));

typedef union Buf_0062EF58 {
    q_0062EF58 q;
    u8 b[8];
    u32 w[2];
    f32 f[4];
} Buf_0062EF58;

typedef union V_0062EF58 {
    q_0062EF58 q;
    f32 f[4];
} V_0062EF58;

typedef struct S_0062EF58 {
    u8 pad0[0x20];
    u8 m20[0x20];
    u8 m40[0x78];
    f32 fB8;
    u8 padBC[0x120 - 0xBC];
    Vec4 v120;
    u8 pad130[0x190 - 0x130];
    q_0062EF58 q190;
    u8 pad1A0[4];
    f32 f1A4;
    u8 pad1A8[0x2D8 - 0x1A8];
    s16 h2D8;
    s16 h2DA;
    u8 pad2DC[0x2F0 - 0x2DC];
    s32 t2F0;
    u8 pad2F4[0x3D0 - 0x2F4];
    q_0062EF58 q3D0;
    u8 pad3E0[4];
    s16 h3E4;
    u8 pad3E6[2];
    f32 f3E8;
    u8 pad3EC[0x628 - 0x3EC];
    f32 f628;
    u8 pad62C[0xFB0 - 0x62C];
    f32 fFB0;
    f32 fFB4;
    u8 padFB8[0xFC0 - 0xFB8];
    V_0062EF58 vFC0;
    f32 fFD0;
    u8 mFD4[4];
    f32 fFD8;
    u8 padFDC[0x1310 - 0xFDC];
    s32 w1310;
    u8 pad1314[0x1464 - 0x1314];
    f32 f1464;
    u8 pad1468[0x1480 - 0x1468];
    Vec4 v1480;
    q_0062EF58 q1490;
    u8 pad14A0[4];
    f32 f14A4;
    u8 pad14A8[0x14AE - 0x14A8];
    u8 b14AE;
    u8 pad14AF[0x14BE - 0x14AF];
    s16 h14BE;
    u8 pad14C0[0x14CC - 0x14C0];
    f32 f14CC;
    f32 f14D0;
    f32 f14D4;
    u8 pad14D8[0x14E4 - 0x14D8];
    s32 w14E4;
    f32 f14E8;
    f32 f14EC;
    u8 pad14F0[0x1500 - 0x14F0];
    V_0062EF58 v1500;
    u8 pad1510[0x1530 - 0x1510];
    f32 f1530;
    s16 h1534;
    u8 pad1536[0x153D - 0x1536];
    u8 b153D;
    u8 pad153E[0x15A0 - 0x153E];
    q_0062EF58 q15A0;
    u8 pad15B0[0x15C4 - 0x15B0];
    f32 f15C4;
    u8 pad15C8[0x19E4 - 0x15C8];
    u8 b19E4;
    u8 pad19E5;
    u8 b19E6;
    u8 pad19E7[0x1A06 - 0x19E7];
    u8 b1A06;
    u8 pad1A07[0x23B8 - 0x1A07];
    f32 f23B8;
    u8 pad23BC[4];
    q_0062EF58 q23C0;
    u8 pad23D0[0x2468 - 0x23D0];
    f32 f2468;
    u8 pad246C[0x2534 - 0x246C];
    s32 w2534;
} S_0062EF58;

extern f32 D_L39_00246190;
extern void func_L31_004F0040_0062C710(void *, f32, f32);
extern void func_L39_00630DD8(void *, f32, f32);
extern void func_L39_0062FA50(void *, void *, void *, f32);
extern void func_L39_00630040(void *, void *, void *, f32);
extern void func_L39_00630AC0(void *, s32, f32, f32, f32);
extern void func_L39_0062A9B8(void *, f32);
extern f32 func_00388730(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern s32 func_L39_0061EB48(void *);
extern void func_L39_006355C8(void *);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389468(f32, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_L01_004455F0(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_003893C8(f32, f32);
extern void func_L39_00631138(void *, f32, f32, f32);
extern f32 func_L39_0062FD90(void *, void *);

void func_L39_0062C710(S_0062EF58 *s) {
    Buf_0062EF58 buf;
    Buf_0062EF58 buf2;
    f32 t;
    f32 len;
    f32 r;

    if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0xA) == 0)) {
        func_L31_004F0040_0062C710(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
        s->fFB4 = s->f1A4;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0x10) == 0)) {
        if (s->t2F0 >= 0x37) {
            ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f1530, 0.0069444444961845875f, 0.0019444444915279746f);
        }
        if (s->t2F0 < 0x37) {
            s->fFB0 = s->f1464;
        } else {
            s->fFB0 = 0.05833333730697632f;
        }
        func_L39_00630DD8(s, 0.012222222983837128f, 0.012500000186264515f);
        func_L39_0062FA50(s, &s->v120, &s->v120, 0.0f);
        func_L39_00630040(s, &s->v120, &s->v120, s->fFB4);
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0x1B) == 0)) {
        f32 x;

        if (s->t2F0 >= 0x29) {
            func_L39_00630AC0(s, 0, 0.03999999910593033f, 0.20000000298023224f, 0.25016388297080994f);
            func_L39_0062A9B8(s, 0.0055555556900799274f);
        }
        x = s->f628;
        if (13.0f <= x && x <= 30.0f) {
            if (27.0f < x) {
                ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f14CC, 0.0f, 0.002222222276031971f);
            } else {
                ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f14CC, 0.03333333507180214f, 0.002222222276031971f);
            }
        }
        buf.f[0] = s->f14CC;
        buf.f[1] = 0.0f;
        buf.f[2] = func_00388730(&s->v120, s->m40);
        func_003888C8(&s->v120, &buf, s->m20);
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0xB) == 0)) {
        if ((s->h3E4 != 0 ||
             (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->w2534) != 0 &&
              func_L39_0061EB48(s) != 10)) &&
            ((({
                    u8 *q = &s->b19E4;
                    u32 dec;
                
                    if (*q == 0) {
                        dec = 0;
                    } else {
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
                    dec;
                }) ^ 0x10) != 0)) {
            func_L39_006355C8(s);
        } else {
            s->fFD0 = s->f14D4;
            s->vFC0.q = s->q1490;
            func_L39_00630AC0(s, 0, 0.03999999910593033f, 0.20000000298023224f, 0.1163552924990654f);
        }
        if (s->w14E4 != 3) {
            s->fFB4 = s->f14E8;
        } else {
            s->fFB4 = 0.0f;
        }
        if (s->b153D != 0) {
            f32 r = s->f2468 * 0.0833333358168602f;
            if (r < 0.03333333507180214f) {
                r = 0.03333333507180214f;
            }
            ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f14EC, r, 0.010277777910232544f);
            s->fFB4 = s->f1A4;
        } else if (s->b14AE != 0 && s->h14BE < 12) {
            ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f14EC, 0.0f, 0.002222222276031971f);
        } else {
            ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&s->f14EC, 0.07000000029802322f, 0.002222222276031971f);
        }
        if (s->b1A06 == 0) {
            s->v120.f[0] = func_00388960(s->f14D0) * s->f14EC;
            s->v120.f[1] = func_00388978(s->f14D0) * s->f14EC;
        } else {
            func_L39_0062FA50(s, &buf, &s->v1480, s->f14EC);
            func_L39_0062FD10((S_62FD10 *)s, (Vec4 *)&buf, (Vec4 *)&buf, 0.0f);
            func_L39_0062FA50(s, &s->v120, &s->v120, 0.0f);
            vec_add_ab(&s->v120, &s->v120, &buf);
        }
        if (s->b1A06 == 0 && s->b153D == 0) {
            f32 k = s->f14E8 * func_00388978(func_00389468(s->f14D4, s->f14D0));
            s->v120.f[0] += func_00388960(s->f14D4) * k;
            s->v120.f[1] += func_00388978(s->f14D4) * k;
        }
        func_L31_004F0040_0062C710(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0x11) == 0)) {
        V_0062EF58 *dir = &s->vFC0;

        s->fFD0 = s->v1500.f[3];
        dir->q = s->v1500.q;
        if (s->t2F0 >= 10) {
            func_L39_00630AC0(s, -1, 0.041999999433755875f, 0.20000000298023224f, 0.19780398905277252f);
        }
        if (s->t2F0 >= 9) {
            if (s->h2D8 == 0) {
                s->v120.f[0] = func_00388960(s->fFD0) * 0.08166667073965073f;
                s->v120.f[1] = func_00388978(s->fFD0) * 0.08166667073965073f;
            } else {
                func_L39_0062FA50(s, &s->v120, &s->v120, 0.0f);
                func_00388830(&buf, dir, 0.08166667073965073f);
                vec_add_ab(&s->v120, &s->v120, &buf);
            }
        }
        s->fFB4 = s->f1A4;
    } else if (((({
            u8 *q = &s->b19E4;
            u32 dec;
        
            if (*q == 0) {
                dec = 0;
            } else {
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
            dec;
        }) ^ 0x83) == 0)) {
        if (s->w1310 != 0) {
            s->fFD0 = s->f23B8;
        }
        func_L39_00630AC0(s, 0, 0.03999999910593033f, 0.20000000298023224f, s->f14A4);
        s->fFB4 = 0.0f;
    } else {
        if (((({
                u8 *q = &s->b19E4;
                u32 dec;
            
                if (*q == 0) {
                    dec = 0;
                } else {
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
                dec;
            }) ^ 0x2C) == 0)) {
            f32 yaw;

            t = s->fB8;
            s->fFD8 = func_L01_004455F0(&t, s->fFD0, s->mFD4, 0.017999999225139618f, 0.20000000298023224f, 0.12217305600643158f, 0);
            yaw = func_003893C8(t, s->fB8);
            func_L39_00631138(s, 0.0f, 0.0f, yaw);
        } else {
            f32 sf;

            buf.q = s->vFC0.q;
            sf = s->fFD0;
            if ((s->h3E4 != 0 ||
                 (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->w2534) != 0 &&
                  func_L39_0061EB48(s) != 10)) &&
                ((({
                        u8 *q = &s->b19E4;
                        u32 dec;
                    
                        if (*q == 0) {
                            dec = 0;
                        } else {
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
                            d = buf2.b;
                            for (i = 0; i < 40; i += 5) {
                                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                            }
                            a = buf2.w[0] ^ (u32)q;
                            b = buf2.w[1] ^ a;
                            buf2.w[0] = a;
                            buf2.w[1] = b;
                            dec = b;
                        }
                        dec;
                    }) ^ 0x10) != 0)) {
                s->fFD0 = s->f23B8;
                s->vFC0.q = s->q23C0;
            }
            func_L39_00630AC0(s, 0, 0.03999999910593033f, 0.20000000298023224f, s->f14A4);
            if ((s->h3E4 != 0 ||
                 (s->w1310 == 1 && func_L01_0045D358(0x28, 2, 0, s->w2534) != 0 &&
                  func_L39_0061EB48(s) != 10)) &&
                ((({
                        u8 *q = &s->b19E4;
                        u32 dec;
                    
                        if (*q == 0) {
                            dec = 0;
                        } else {
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
                            d = buf2.b;
                            for (i = 0; i < 40; i += 5) {
                                *d++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
                            }
                            a = buf2.w[0] ^ (u32)q;
                            b = buf2.w[1] ^ a;
                            buf2.w[0] = a;
                            buf2.w[1] = b;
                            dec = b;
                        }
                        dec;
                    }) ^ 0x10) != 0)) {
                s->f3E8 = sf;
                s->q3D0 = buf.q;
                s->fFD0 = sf;
                s->vFC0.q = buf.q;
            }
        }
        func_L31_004F0040_0062C710(s, 0.7f, 0.0f);
        s->q190 = s->q15A0;
        r = 0.0055555556900799274f;
        if (s->fFB0 < D_L39_00246190 * 0.01666666753590107f * 0.2f) {
            if (((({
                    u8 *q = &s->b19E6;
                    u32 dec;
                
                    if (*q == 0) {
                        dec = 0;
                    } else {
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
                    dec;
                }) ^ 2) == 0)) {
                f32 rate = s->f15C4;

                len = func_L39_0062FD90(s, &s->v120);
                ((f32 (*)(f32 *, f32, f32))func_003BEBF8)(&len, 0.0f, rate);
                func_L39_0062FA50(s, &s->v120, &s->v120, len);
                return;
            }
            if (s->h2DA != 0) {
                r = 0.003055555745959282f;
            } else if (s->h1534 != 0) {
                r = 0.0005555555690079927f;
            } else {
                r = 0.002222222276031971f;
            }
        }
        func_L39_0062A9B8(s, r);
    }
}
/* localdecomp:end func_L39_0062C710 */
