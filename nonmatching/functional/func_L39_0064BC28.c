/* functional: medium. No byte match (retail inlines the obfuscated hash check at every use; mine uses static helpers mp_hash/mp_gate), but the sets of float constants and the order of every call equal retail. Delay-slot stores honoured (142C=1 stored unconditionally inside the f1A4 test). Needs -mvu0-use-vf0-vf2 like its file (fabs_asm = retail abs.s). Unrun-block coverage unknown: gate not available. */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));

extern u8 D_L39_004997E0[];
extern void func_L39_00647C48(u8 *, s32, s32);
extern void func_L39_00647E10(u8 *, s32, s32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern s32 func_L39_006212E8(void *);
extern f32 func_L01_00460818(s32, s32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_00633160(u8 *);
extern void func_L31_004F3CA0(u8 *, f32);
extern f32 func_L39_00632818(void *, u128_t *);
extern void func_L39_00637D38(u8 *);
extern void func_L39_00633308(void *, s32, f32, f32, f32);
extern void func_L39_00633428(void *);
extern void func_L39_00633CF8(u8 *);
extern void func_L30_004F4800(u8 *);
extern void func_L39_00633620(void *, f32, f32);
extern void func_L39_00633670(void *, f32);
extern void func_L39_00633728(void *, void *);
extern void func_L39_006314E0(u8 *, s32);
extern void func_L39_006384C0(void *, f32, f32, f32);
extern void func_L39_00632A20(void *, void *, void *, f32);
extern void func_L39_00633748(u8 *);

/* the game's obfuscated byte check: hash of the byte at p and of its address (0 when the byte is 0) */
static s32 mp_hash(u8 *p) {
    u32 buf[2];
    u8 *b;
    s32 i, n, m, k;
    if (*p == 0)
        return 0;
    n = *p;
    m = n + 1;
    k = ((s32)p - n) & 7;
    b = (u8 *)buf;
    for (i = 0; i < 40; i += 5) {
        *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    buf[0] ^= (u32)p;
    buf[1] ^= buf[0];
    return buf[1];
}

/* 1 on the normal path: not (h3E4 != 0 || (mode 1 && flag 0x28 set && state != 10)), or the 0x19E4 hash is 0x10 */
static s32 mp_gate(u8 *s) {
    if (*(s16 *)(s + 0x3E4) == 0) {
        if (*(s32 *)(s + 0x1310) != 1)
            return 1;
        if (func_L01_004606E8(0x28, 2, 0, *(s32 *)(s + 0x2534)) == 0)
            return 1;
        if (func_L39_006212E8(s) == 10)
            return 1;
    }
    return mp_hash(s + 0x19E4) == 0x10;
}

void func_L39_0064BC28(u8 *s) {
    f32 d, f1, f2, f12, f13, f20;
    s32 r3, v;
    u128_t q;
    u8 *v120;

    d = *(f32 *)(s + 0x2C0) - *(f32 *)(s + 0xA8);
    r3 = 0;
    if (*(s32 *)(s + 0x2C8) != 0 && d < 0.25f)
        r3 = 1;
    if (d < 0.5f || r3 != 0) {
        if (0.020000001415610313f < *(f32 *)(s + 0x1A4))
            func_L39_00647C48(s, 0, 2);
        if (0.010000000707805157f < *(f32 *)(s + 0x1A4))
            func_L39_00647E10(s, 2, 4);
    }
    if (mp_gate(s)) {
        if (*(f32 *)(s + 0x1A4) < 0.03400000184774399f) {
            s[0x142C] = 1;
            if (fabs_asm(*(f32 *)(s + 0xFD8)) > 2.094395160675049f) {
                if (*(f32 *)(s + 0x2468) == 1.0f)
                    s[0x142F] = 1;
            }
        }
        f1 = func_L01_00460818(1, *(s32 *)(s + 0x2534));
        f2 = func_L01_00460818(7, *(s32 *)(s + 0x2534));
        if (1.919862151145935f < func_0038DBA0(f1, f2)) {
            if (fabs_asm(*(f32 *)(s + 0xFD8)) > 1.2217304706573486f) {
                if (*(f32 *)(s + 0x2468) == 1.0f) {
                    s[0x142C] = 1;
                    s[0x142F] = 1;
                }
            }
        }
        if (fabs_asm(*(f32 *)(s + 0xFD8)) < 0.0872664600610733f)
            s[0x142C] = 0;
    }
    if (*(s32 *)(s + 0x324) < 2) {
        if (fabs_asm(*(f32 *)(s + 0xFD8)) > 1.5707963705062866f) {
            if (s[0x3E6] != 0) {
                s[0x142C] = 1;
                s[0x142F] = 1;
            }
        }
    }
    if (s[0x142F] != 0) {
        if (fabs_asm(*(f32 *)(s + 0xFD8)) < 0.06981316953897476f)
            s[0x142F] = 0;
    }
    if (*(f32 *)(s + 0x2468) < 0.20000000298023224f) {
        if (*(s32 *)(s + 0x1430) != 0)
            s[0x142F] = 1;
        *(u128_t *)(s + 0xFC0) = *(u128_t *)(s + 0x1410);
        *(f32 *)(s + 0xFD0) = *(f32 *)(s + 0x1428);
        *(s32 *)(s + 0xFB0) = 0;
    } else {
        func_L39_00633160(s);
        v = (*(s32 *)(s + 0x474) == 2) ? *(s32 *)(s + 0x478) : -1;
        if (v == 10 && (*(f32 *)(s + 0x248C) == 1.0f || *(s32 *)(s + 0x1430) != 0) && s[0x1A05] == 0) {
            *(u128_t *)(s + 0x1410) = *(u128_t *)(s + 0xFC0);
            *(f32 *)(s + 0x1428) = *(f32 *)(s + 0xFD0);
            *(s32 *)(s + 0x1430) = 1;
        } else {
            *(u128_t *)(s + 0x1410) = *(u128_t *)(s + 0x20);
            *(f32 *)(s + 0x1428) = *(f32 *)(s + 0xB8);
        }
    }
    if (0.0f < *(f32 *)(s + 0x15B0)) {
        func_L31_004F3CA0(s, 0.699999988079071f);
        q = *(u128_t *)(s + 0x15A0);
        f1 = *(f32 *)(s + 0xFB0) + func_L39_00632818(s, &q);
        *(f32 *)(s + 0xFB0) = f1;
        if (f1 < 0.014000000432133675f)
            *(f32 *)(s + 0xFB0) = 0.014000000432133675f;
        *(u128_t *)(s + 0x15A0) = 0;
    }
    f20 = 1.0f;
    if (!mp_gate(s)) {
        func_L39_00637D38(s);
    } else {
        *(u128_t *)(s + 0x3D0) = *(u128_t *)(s + 0x20);
        *(f32 *)(s + 0x3E8) = *(f32 *)(s + 0xB8);
        if (mp_hash(s + 0x19E5) == 1 && s[0x142F] == 0 && s[0x1A05] == 0) {
            func_L39_00633308(s, 0, 0.05328000336885452f, 0.18719999492168427f, 0.24434609711170197f);
        } else {
            if (*(f32 *)(s + 0x2468) < 0.8999999761581421f || (s[0x1A05] != 0 && s[0x142F] == 0)) {
                if (0.7853981852531433f < fabs_asm(*(f32 *)(s + 0xFD8)))
                    f20 = 0.0f;
            }
            func_L39_00633428(s);
        }
    }
    func_L39_00633CF8(s);
    func_L30_004F4800(s);
    if (s[0x142F] != 0) {
        f2 = 0.14500001072883606f - (fabs_asm(*(f32 *)(s + 0xFD8)) * 0.11000000685453415f) / 3.1415927410125732f;
        if (f2 < 0.0f)
            f2 = 0.0f;
        if (f2 < *(f32 *)(s + 0xFB0))
            *(f32 *)(s + 0xFB0) = f2;
    }
    f12 = f20 * 0.014800000935792923f;
    f13 = 0.012000000104308128f;
    if (s[0x142F] != 0) {
        f1 = 2.6179938316345215f - *(f32 *)(s + 0xFD8);
        if (1.0f < f1)
            f1 = 1.0f;
        if (f1 < 0.20000000298023224f)
            f1 = 0.20000000298023224f;
        f13 = 0.0068000005558133125f;
        *(f32 *)(s + 0xFB0) = *(f32 *)(s + 0xFB0) * f1;
    }
    f2 = fabs_asm(*(f32 *)(s + 0xFD8));
    if (*(f32 *)(s + 0x2468) < 0.75f && 0.6108652353286743f < f2) {
        f1 = 1.0f - f2 * 0.4000000059604645f;
        if (f1 < 0.0f)
            f1 = 0.0f;
        *(f32 *)(s + 0xFB0) = *(f32 *)(s + 0xFB0) * f1;
    }
    func_L39_00633620(s, f12, f13);
    if (s[0x142C] == 0 && mp_gate(s)) {
        func_L39_00633670(s, 100000.0f);
    } else if (s[0x1A06] == 0) {
        func_L39_00633670(s, mp_gate(s) ? *(f32 *)(s + 0xFD0) : *(f32 *)(s + 0x3E8));
    } else if (mp_gate(s)) {
        func_L39_00633728(s, s + 0xFC0);
    } else {
        func_L39_00633728(s, s + 0x3D0);
    }
    func_L39_006314E0(s, 0);
    if (*(s16 *)(s + 0x33A) != 0)
        func_L39_006384C0(s, 5.0f, 0.20000000298023224f, 0.3499999940395355f);
    v120 = s + 0x120;
    if (*(s16 *)(s + 0x2DE) != 0) {
        func_L39_00632A20(s, v120, s + 0x160, 0.010000000707805157f);
        func_L39_00633748(s);
    } else {
        func_L39_00632A20(s, v120, v120, 0.02160000056028366f);
    }
}
