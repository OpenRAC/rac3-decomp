#include "common.h"

typedef int q128_51E8E0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_51E8E0;

/* localdecomp:start func_L40_0051E8E0 */
extern u8 D_L40_003BFE20[];
extern s32 D_L40_0025FA00[];

extern s32 func_L39_00632C48(f32, u8 *);
extern void func_L39_0063A030(u8 *, s32, s32);
extern void func_L39_00632D78(f32, u8 *, s32);
extern void func_L39_00633308(f32, f32, f32, u8 *, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(u8 *);
extern void func_L39_00633670(f32, u8 *);
extern void func_L39_00633620(f32, f32, u8 *);
extern void func_L39_0062D0C8(f32, u8 *);
extern void func_L40_00509C28(f32, f32, u8 *);
extern void func_L39_00632888(f32, u8 *, void *, void *);
extern void func_L39_00632988(f32, u8 *, void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern f32 func_L39_00632678(u8 *, void *);
extern void func_L01_0044E468(u8 *, s32);
extern void func_L39_00632180(f32, f32, f32, u8 *, void *, s32);
extern s32 func_003D4D00(f32, void *, s32, s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L39_005B8928(s32);
extern void func_L01_00446A70(s32, s32, s32, void *, void *, f32);
extern void func_L39_0062E930(u8 *);
extern void func_L40_004FF6B8(u8 *);
extern void func_L39_0062EF58(u8 *);
extern void func_L39_00633CF8(u8 *);

static inline u32 dec_51E8E0(u8 *p) {
    u32 x;
    if (*p == 0) {
        x = 0;
    } else {
        u32 buf[2];
        u8 *b;
        s32 i;
        s32 n = *p;
        s32 m = n + 1;
        s32 k = ((s32)p - n) & 7;
        b = (u8 *)buf;
        for (i = 0; i < 40; i += 5) {
            *b++ = D_L40_003BFE20[m + ((k + i) & 7) * 255];
        }
        buf[0] ^= (u32)p;
        buf[1] ^= buf[0];
        x = buf[1];
    }
    return x;
}

#define F32(p, o) (*(f32 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define S16(p, o) (*(s16 *)((p) + (o)))
#define U8(p, o) (*(u8 *)((p) + (o)))

void func_L40_0051E8E0(u8 *g) {
    if ((dec_51E8E0(g + 0x19E4) ^ 0x1B) == 0 && S16(g, 0x2480) == 0 && S32(g, 0x568) == 3 && func_L39_00632C48(10.0f, g) != 0) {
        func_L39_0063A030(g, 4, 0);
    }
    if (S16(g, 0x1538) != 0 && U8(g, 0x372) != 0) {
        F32(g, 0xFB0) = F32(g, 0xFB4);
    } else {
        if (U8(g, 0x14AC) != 0) {
            func_L39_00632D78(0.14500001f, g, 0);
        }
        func_L39_00632D78(F32(g, 0x14B4), g, 0);
    }
    if (S32(g, 0x2F0) == S16(g, 0x14BC)) {
        *(q128_51E8E0 *)(g + 0x1470) = *(q128_51E8E0 *)(g + 0xA0);
    }
    if (U8(g, 0x14AC) != 0 || (S32(g, 0x2F0) < S16(g, 0x14BC) && (dec_51E8E0(g + 0x19E4) ^ 0xB) != 0 && (dec_51E8E0(g + 0x19E4) ^ 0x10) != 0 &&
                            (dec_51E8E0(g + 0x19E4) ^ 0xC) != 0 && (dec_51E8E0(g + 0x19E4) ^ 0x11) != 0 && (dec_51E8E0(g + 0x19E4) ^ 0x1B) != 0)) {
        f32 save;
        func_L39_00633308(0.021600001f, 0.28800002f, 0.30019665f, g, 0);
        save = F32(g, 0xFB4);
        if (U8(g, 0x14AC) >= 2) {
            F32(g, 0xFB4) = save * 0.4f;
        }
        if ((S16(g, 0x3E4) != 0 || (S32(g, 0x1310) == 1 && func_L01_004606E8(0x28, 2, 0, S32(g, 0x2534)) != 0 && func_L39_006212E8(g) != 0xA)) &&
            (dec_51E8E0(g + 0x19E4) ^ 0x10) != 0) {
            func_L39_00633670(F32(g, 0x3E8), g);
        } else {
            func_L39_00633670(99999.0f, g);
        }
        F32(g, 0xFB4) = save;
        if (U8(g, 0x14AC) != 1) {
            func_L39_00633620(F32(g, 0x1510), F32(g, 0x1514), g);
        }
        if (U8(g, 0x14AC) != 0) {
            if (*(s32 *)(*(u8 **)(g + 0x2534) + 0x1D4) != 0 && S16(g, 0x2DA) != 0) {
                F32(g, 0xFB4) = 0.0f;
            }
            if (U8(g, 0x14AC) != 0) {
                func_L39_0062D0C8(F32(g, 0x1514), g);
            }
        }
        func_L40_00509C28(0.5f, 0.040000003f, g);
        if ((dec_51E8E0(g + 0x19E4) ^ 9) == 0) {
            s32 t = S32(g, 0x2F0);
            if (t < S16(g, 0x14BC) + 3) {
                func_L39_00632888((f32)t * 0.0064000003f, g, g + 0x120, g + 0x120);
            }
        }
        if ((dec_51E8E0(g + 0x19E4) ^ 0xA) == 0) {
            s32 t = S32(g, 0x2F0);
            if (t < 0x1C) {
                func_L39_00632888((f32)t * 0.021200001f, g, g + 0x120, g + 0x120);
            }
        }
        if (S32(g, 0x2F0) < 8 && F32(g, 0x2468) > 0.2f) {
            V4_51E8E0 a;
            V4_51E8E0 b;
            *(q128_51E8E0 *)&a = *(q128_51E8E0 *)(g + 0xA0);
            func_L39_00632988(0.5f, g, &a, &a);
            func_L39_00632888(0.95f, g, &b, &a);
            if (func_003D3CB0(&a, &b, 4, S32(g, 0x2524), 0) != 0) {
                S16(g, 0x1534) = 1;
            }
        }
    } else {
        func_L39_0062EF58(g);
    }
    if (F32(g, 0x2A8) > F32(g, 0x14A0)) {
        F32(g, 0x14A0) = F32(g, 0x14A0) + 0.120000005f;
        if (F32(g, 0x14A0) > F32(g, 0x2A8)) {
            F32(g, 0x14A0) = F32(g, 0x2A8);
        }
    }
    if (F32(g, 0xA8) < F32(g, 0x14A0)) {
        F32(g, 0x14A0) = F32(g, 0xA8);
    }
    if (S16(g, 0x14BC) < S32(g, 0x2F0) && func_L39_00632678(g, g + 0x120) < 0.001f && (U8(g, 0x14AD) == 0 || S32(g, 0x2F0) > S32(g, 0x1444))) {
        if ((dec_51E8E0(g + 0x19E4) ^ 0xE) != 0 || S32(g, 0x2F0) >= 0xF) {
            U8(g, 0x14AE) = 1;
            if (F32(g, 0x1468) != 0.0f) {
                F32(g, 0x1530) = F32(g, 0x1468);
            }
        }
    }
    func_L39_00633CF8(g);
    if (U8(g, 0x1A14) == 0 || S32(g, 0x1310) != 2) {
        if ((dec_51E8E0(g + 0x19E4) ^ 0x10) == 0 || (dec_51E8E0(g + 0x19E4) ^ 0xD) == 0) {
            func_L01_0044E468(g + 0x1630, S32(g, 0x2F0) < 0xB ? 0 : 2);
        }
    }
    if (U8(g, 0x1A14) == 0 || S32(g, 0x1310) != 2) {
        if ((dec_51E8E0(g + 0x19E4) ^ 0x83) == 0) {
            func_L01_0044E468(g + 0x1630, S32(g, 0x2F0) < 0xC ? 0 : 2);
        }
    }
    if ((dec_51E8E0(g + 0x19E4) ^ 0x10) == 0 && S32(g, 0x2F0) >= 8 && F32(g, 0x628) < 28.0f) {
        V4_51E8E0 a;
        V4_51E8E0 b;
        s32 n;
        func_L39_00632180(0.8f, 0.0f, 0.3f, g, &a, 1);
        n = func_003D4D00(0.9f, &a, 0, S32(g, 0x2524), 0);
        if (n != 0) {
            s32 i;
            func_0038CE20(&b, g + 0x140, 7.0f);
            for (i = 0; i < n; i++) {
                if (func_L39_005B8928(D_L40_0025FA00[i]) != 0) {
                    func_L01_00446A70(D_L40_0025FA00[i], S32(g, 0x2524), 0x10000, g + 0xA0, &b, 1.0f);
                }
            }
        }
    }
    func_L39_0062E930(g);
    func_L40_004FF6B8(g);
}
/* localdecomp:end func_L40_0051E8E0 */
