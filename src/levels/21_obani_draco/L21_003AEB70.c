#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L21_003AEB70 */
#include "vu0.h"

extern s32 D_001D6694;
extern u8 *D_001EC4C0[];
extern u8 D_001A4BE0[];
extern u8 D_001D66B0;
extern s32 func_L21_003AF758(u8 *);
extern void func_L21_003AF988(u8 *);
extern void func_L21_003AFBA8(void *);
extern void func_L21_003AFCF0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_L01_004BA800(void);
extern s32 func_L01_004561B8(void *);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern s32 func_L01_004468C8(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern void func_L01_0045A7A8(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern void func_L01_00404A10(void *, void *);
extern f32 func_L01_004395E0(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0045AA30(void *, void *);
extern s32 func_L01_00448070(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern s32 func_00382468(s32);
extern void func_L01_0046C470(void *, void *, s32, s32, f32, u8, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_00454370(void *, void *);
extern s32 func_L03_0043FC00(void *, s32, void *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L21_00339258(s32, s32, s32);
extern void func_L01_00315900(void *, s32, void *);
extern void func_L21_00339190(void *, void *, s32);
void func_L01_004450F0(s32, s32, s32);

static __inline__ void syncvis_003AEB70(u8 *m)
{
    u8 *c = *(u8 **)(m + 0x24);
    *(u16 *)(m + 0x34) &= ~0x41;
    *(u16 *)(m + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
    *(s32 *)(m + 0x98) = *(s32 *)(c + 0x10);
}

void func_L21_003AEB70(u8 *m)
{
    u8 *p;
    vu0_v4 pos;
    vu0_v4 a;
    vu0_v4 v;
    s32 i;
    s32 n;
    s32 r;
    f32 f;

    if (func_L21_003AF758(m) != 0) {
        return;
    }
    if (m[0x95] != 4) {
        if (D_001D6694 == 2) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
            return;
        }
        if (func_L01_004BA800() == 0) {
            syncvis_003AEB70(m);
        }
    }
    func_L21_003AF988(m);
    pos = *(vu0_v4 *)(m + 0x10);
    p = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 2:
    case 3:
        if (func_L01_004561B8(m) != 0 || (m[0x60] & 2)) {
            func_003C3A10(m, func_00382498(1, 2), 0, 8);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_L01_0045BD78(m, 0.0048f, 0.080000006f, 0.0050265486f, 0.50265485f);
            *(f32 *)(p + 0x30C) = func_L01_00443A18(25.0f, 50.0f) * 0.017453292f;
            n = func_00382498(2, 8);
            *(s16 *)(p + 0x304) = 0;
            *(s16 *)(p + 0x306) = (f32)n * 50.0f;
            func_003C3A10(m, 4, 0, 4);
        }
        if (m[0x43] == 4 && (m[0x60] & 2)) {
            func_003C3A10(m, 5, 0, 0);
        } else if (m[0x43] == 5) {
            n = func_L01_004468C8(m, 0, 0.3f, p[0x5F] ? 0x10000 : 1, (f32)p[0x44], 1.0f, 0, 1, 0);
            if (p[0x5F] != 0) {
                s32 j;
                for (j = 0; j < n; j++) {
                    if (*(s16 *)(D_001EC4C0[j] + 0xAA) == *(s16 *)(m + 0xAA)) {
                        *(s16 *)(p + 0x304) = 1;
                    }
                }
            } else {
                s32 j;
                for (j = 0; j < n; j++) {
                    u8 *e = D_001EC4C0[j];
                    u8 *g = D_001A4BE0;
                    if (e == *(u8 **)(g + 0x25C0)) {
                        *(s16 *)(p + 0x304) = 1;
                    }
                }
            }
            func_L01_0045A7A8(m, p + 0xB0, *(f32 *)(p + 0x30C));
            if (func_0038CB00(p + 0x306) != 0) {
                *(f32 *)(p + 0x30C) = func_L01_00443A18(25.0f, 50.0f) * 0.017453292f;
                *(s16 *)(p + 0x306) = (f32)func_00382498(2, 8) * 50.0f;
            }
            func_L01_00404A10(func_L21_003AFCF0, m);
            if (*(s16 *)(p + 0x304) != 0 && (m[0x60] & 2)) {
                func_003C3A10(m, 6, 0, 0);
            }
        } else if (m[0x43] == 6) {
            if (m[0x60] & 2) {
                *(s16 *)(p + 0x304) = 0;
                func_L01_004450F0((s32)m, 5, -1);
            }
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_003C3A10(m, 8, 0, 0);
        }
        f = func_L01_004395E0(m);
        if (8.0f < f && f < 18.0f) {
            vu0_q q1, q2;
            func_0038CF68(&a, m + 0xC0, 0.16f);
            __asm__("lqc2 %0, %1" : "=j"(q1) : "m"(a));
            __asm__("vsub.xyz %0, $vf0, %1" : "=j"(q2) : "j"(q1));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(q2));
            func_L01_0045AA30(m, &a);
            break;
        }
        if (m[0x60] & 2) {
            func_L01_004450F0((s32)m, 4, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            *(s16 *)(p + 0x306) = 100;
            *(s32 *)(p + 0x1C8) &= ~0x10;
            func_003C3A10(m, 0, 0, 0);
        }
        if (func_0038CB00(p + 0x306) != 0) {
            if (m[0x95] == 0) {
                func_L01_004450F0((s32)m, 2, -1);
            } else if (m[0x95] == 1) {
                func_L01_004450F0((s32)m, 3, -1);
            } else if (m[0x95] == 2) {
                func_L01_004450F0((s32)m, 4, -1);
            }
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            *(s16 *)(p + 0x306) = 25;
            *(f32 *)(p + 0x308) = 0.04f;
            *(u16 *)(m + 0x34) |= 0x808;
            p[0xE2] = p[0xE1] = 0xFF;
            func_003C3A10(m, 3, 0, 0);
        }
        syncvis_003AEB70(m);
        if (func_0038CB00(p + 0x306) != 0) {
            m[0x23] = 0x80;
            p[0xE1] = 7;
            p[0xE2] = 9;
            {
                s8 t = p[0x301];
                if (t == 2) {
                    p[0x300] = t;
                } else if (t == 3) {
                    p[0x300] = t;
                }
            }
            func_L01_004450F0((s32)m, 2, 0);
            break;
        }
        m[0x23] = func_L01_00448070(0x80, 0, (f32)*(s16 *)(p + 0x306) * *(f32 *)(p + 0x308));
        for (i = 0; i < 5; i++) {
            f32 ang, r, sc;
            s32 col, k;
            vu0_q qa, qb, qr;
            qzero(&v);
            col = 0xFFE01FC8;
            v.z = func_003824E0(3.0f, 4.0f) * 0.020000001f;
            ang = func_00382538();
            r = func_003824E0(0.25f, 0.5f);
            a.x = func_0038D098(ang) * r;
            a.y = func_0038D0B0(ang) * r;
            a.z = 0.0f;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qr));
            k = (func_00382498(0x1E, 0x3C) * 5 + 2) / 6;
            sc = func_003824E0(0.1f, 0.3f);
            if (func_00382468(2) != 0) {
                col = 0xFFDE5CED;
            }
            func_L01_0046C470(&a, &v, col, k, sc, func_00382468(0xFF), 0, 0x40, 0);
        }
        break;
    case 7:
        if (func_L01_004561B8(m) != 0) {
            *(s16 *)(p + 0x306) = 25;
            *(f32 *)(p + 0x308) = 0.04f;
            *(u16 *)(m + 0x34) |= 0x808;
            p[0xE2] = p[0xE1] = 0xFF;
            func_003C3A10(m, 3, 0, 8);
        }
        if (func_0038CB00(p + 0x306) != 0) {
            m[0x23] = 0;
            p[0xE1] = 7;
            p[0xE2] = 9;
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
            {
                s8 t = p[0x301];
                if (t == 0) {
                    p[0x300] = t;
                } else if (t == 1) {
                    p[0x300] = t;
                }
            }
            func_L01_004450F0((s32)m, 1, 4);
            break;
        }
        m[0x23] = func_L01_00448070(0, 0x80, (f32)*(s16 *)(p + 0x306) * *(f32 *)(p + 0x308));
        for (i = 0; i < 5; i++) {
            f32 ang, r, sc;
            s32 col, k;
            vu0_q qa, qb, qr;
            qzero(&v);
            col = 0xFFE01FC8;
            v.z = func_003824E0(3.0f, 4.0f) * 0.020000001f;
            ang = func_00382538();
            r = func_003824E0(0.25f, 0.5f);
            a.x = func_0038D098(ang) * r;
            a.y = func_0038D0B0(ang) * r;
            a.z = 0.0f;
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(a));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(a) : "j"(qr));
            k = (func_00382498(0x1E, 0x3C) * 5 + 2) / 6;
            sc = func_003824E0(0.1f, 0.3f);
            if (func_00382468(2) != 0) {
                col = 0xFFDE5CED;
            }
            func_L01_0046C470(&a, &v, col, k, sc, func_00382468(0xFF), 0, 0x40, 0);
        }
        break;
    case 9:
        if (func_L01_004561B8(m) != 0) {
            func_003A52A0(1, 0, m);
        }
        r = func_L01_00454370(m, p + 0xD0);
        if ((r & 1) || *(f32 *)(p + 0x30) <= 0.0f) {
            func_L03_0043FC00(m, 0x7F, &D_001D66B0, 4, 2, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0.5f);
            func_L01_003303B8(m + 0x10, 0, 0xA, 0, 0, 0, 0xF, 2, 1.0f, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 1, 0, 0, 0, 0xF7388E, 0xF70063, 0xFF407F, 0xFF0020, 0xFF008F, 0xFF3064,
                0x7FFF60A0, 0x28FF0000, 0xFF3064, 0);
            if (func_00382468(5) == 0) {
                func_L21_00339258(*(s32 *)(m + 0xB8), 3, 0);
            }
            *(u16 *)(m + 0x34) &= ~0x808;
            func_L01_00315900(m, 6, func_L21_003AFBA8);
            break;
        }
        if (r & 2) {
            func_003C3A10(m, 0, 0, 0);
            if (m[0x95] == 0) {
                func_L01_004450F0((s32)m, 2, -1);
            } else if (m[0x95] == 1) {
                func_L01_004450F0((s32)m, 3, -1);
            } else if (m[0x95] == 2) {
                func_L01_004450F0((s32)m, 4, -1);
            }
        }
        break;
    }
    if (m[0x95] == 2) {
        func_L21_00339190(m, &pos, m[0x20] == 9);
    }
}
/* localdecomp:end func_L21_003AEB70 */

/* localdecomp:start func_L21_003AF758 */
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L21_003AFBA8(void *);

s32 func_L21_003AF758(u8 *a0) {
    u8 *s;
    if (a0[0x20] != 0) {
        return 0;
    }
    s = *(u8 **)(a0 + 0x68);
    *(s16 *)(s + 0x108) = 0;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    *(f32 *)(s + 0x100) = 0.5f;
    *(f32 *)(s + 0x104) = 0.5f;
    s[0xE0] = 9;
    s[0xE1] = 7;
    *(f32 *)(s + 0x10C) = 0.15f;
    s[0x118] = 0xFF;
    s[0xE2] = 9;
    s[0xE6] = 10;
    *(f32 *)(s + 0xEC) = 0.3f;
    *(f32 *)(s + 0xF0) = 1.2f / 60.0f;
    *(f32 *)(s + 0xF4) = 0.6f / 60.0f;
    *(f32 *)(s + 0xF8) = 0.014f;
    *(f32 *)(s + 0xFC) = 0.8f / 1000.0f;
    s[0x14B] = 0xFF;
    s[0x147] = 0;
    s[0x148] = 0;
    s[0x149] = 0;
    s[0x14A] = 0;
    s[0x142] = 0;
    s[0x143] = 0;
    *(f32 *)(s + 0x110) = *(f32 *)(a0 + 0x18) - 10.0f;
    *(f32 *)(s + 0x12C) = 0.8f;
    *(f32 *)(s + 0x128) = 0.4f;
    *(f32 *)(s + 0x190) = 0.1f;
    *(f32 *)(s + 0x194) = 0.2f;
    *(f32 *)(s + 0x180) = 1.0f;
    *(f32 *)(s + 0x198) = 2.0f;
    *(f32 *)(s + 0x19C) = 2.0f;
    *(f32 *)(s + 0x1A0) = 1.3089969f;
    *(f32 *)(s + 0x1C0) = 3.1415927f;
    *(f32 *)(s + 0x1BC) = 0.00392f;
    *(f32 *)(s + 0x1C4) = 1.0f;
    *(f32 *)(s + 0x40) = 1.0f;
    s[0x3E] = 1;
    s[0x39] = 0;
    s[0x3F] = 0;
    s[0x64] = 0;
    s[0x5F] = 0;
    if (*(s16 *)(s + 0x34) == 0 || *(f32 *)(s + 0x30) <= 0.0f) {
        *(s16 *)(s + 0x34) = 25;
        *(f32 *)(s + 0x30) = 25.0f;
    }
    if (s[0x44] == 0) {
        s[0x44] = 2;
    }
    s[0x58] = 0x28;
    s[0x5A] = 0x60;
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
    func_L21_003AFBA8(a0);
    return 1;
}
/* localdecomp:end func_L21_003AF758 */
