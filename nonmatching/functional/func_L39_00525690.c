/* functional: medium. Written from the PAL assembly, control flow followed block by block. Notes for the gate: retail calls func_L39_0061C4D0 with a stale third argument register (callers declare it with two parameters, so it is dropped here); the key decodes are the file's usual 5-step byte decode (and a 3-step variant on g+0x1A41 that ends in an unsigned divide); retail zeroes the decode scratch quad at sp+0 after the first key test. */
#include "vu0.h"

typedef union {
    vu0_v4 v;
    u32 w[4];
    u8 b[16];
} Buf_525690;

extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
extern u8 D_L39_0049C890[];
extern u8 *D_L39_0024CE20[];
extern u8 D_001FE020[];
extern s32 D_L39_0024112C;
extern f32 D_L39_0024AA28;
extern f32 D_L39_0024AA2C;
extern s32 D_L39_0024AA20;
extern s32 D_L39_0024AA24;
extern s32 D_001DF2F0_sda;
extern s32 D_001DF2F4_sda;
extern f32 D_001DF318_sda;
__asm__(".extern D_001DF2F0_sda, 4");
__asm__(".extern D_001DF2F4_sda, 4");
__asm__(".extern D_001DF318_sda, 4");
extern u8 *D_L39_002637C0[];

extern void func_L39_0061C4D0(void *, void *);
extern void func_L39_005DB0E0(s32, s32, f32);
extern void func_L39_005DB148(s32, f32);
extern s32 func_L39_00639D90(void *);
extern s32 func_L39_005FFD20(void *, void *, s32, f32);
extern void func_L01_003F6F20(s32, void *, u32, void *, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_0038CB00(void *);
extern s32 func_L39_006732D0(void *, s32, s32, s32);
extern u8 func_L39_00673498(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L39_00621D60(void *, s32);
extern void func_003C2F58(void *, s32, void *);
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L39_00674320(void *);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_L39_005FFDF8(s32);
extern void func_L39_005FFE78(void);
extern s32 func_0038CAD0(void *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_00451D38(void *, s32, s32, f32);
extern s32 func_L39_00648AE0(void *, s32);
extern s32 func_L39_005F33E0(s32, s32, void *);
extern s32 func_L39_005F2FA0(void *, s32);
extern void func_L39_005F3088(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L39_00557600(void *, void *);
extern void func_L39_005285A8(void *, void *);
extern void func_L01_00444F38(void *, s32, s32, s32, s32);
extern void func_L39_00622288(void *);

static __inline__ u32 dec5_525690(u8 *key, Buf_525690 *b)
{
    s32 n, k, m, i;
    u8 *dst;

    if (!*key) return 0;
    n = *key;
    m = n + 1;
    k = ((s32)key - n) & 7;
    dst = b->b;
    for (i = 0; i < 40; i += 5) *dst++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    b->w[0] ^= (u32)key;
    b->w[1] ^= b->w[0];
    return b->w[1];
}

/* the 3-step variant on a byte key: returns the 16-bit result retail keeps in sp+0x14 */
static __inline__ u32 dec3_525690(u8 *key, Buf_525690 *b)
{
    s32 n, k, m, i;
    u8 *dst;
    u32 hi, d;

    if (!*key) return 0;
    n = *key;
    m = n + 1;
    k = ((s32)key - n) & 7;
    dst = b->b;
    for (i = 0; i < 24; i += 3) *dst++ = D_L39_00483A00[((k + i) & 7) * 0xD1 + m];
    b->w[0] ^= (u32)key;
    hi = b->w[1] ^ b->w[0];
    hi = hi >> 16;
    d = ((b->w[1] ^ b->w[0]) ^ hi) << 16;
    d = d + 1;
    b->w[1] = hi / d;
    return b->w[1] & 0xFFFF;
}

static __inline__ u8 *live_525690(void *id)
{
    u8 *h = (u8 *)func_L39_0061D7B0(id);
    if (h && (h[3] & 0xF) == 0) return h;
    return 0;
}

void func_L39_00525690(u8 *obj)
{
    Buf_525690 a, d1;
    vu0_v4 v4, t1, t2;
    u8 *p, *g, *sel, *info, *cur, *elem;
    s32 i, n, v, ok, flag, r;
    u32 dec;
    f32 f, w;
    u8 *fp;
    u8 *e;

    D_001DF2F0_sda = D_L39_0024112C;
    D_001DF2F4_sda = (s32)obj;
    p = *(u8 **)(obj + 0x68);
    g = *(u8 **)(p + 0x54);
    sel = 0;
    info = 0;
    if (obj[0x20] == 0) {
        *(f32 *)(p + 0x38) = 1.0f;
        func_L39_0061C4D0(obj, p + 0x54);
        g = *(u8 **)(p + 0x54);
        obj[0x20] = 1;
        p[0x59] = 0xFF;
        *(s32 *)(p + 0x5C) = -1;
        p[0x5A] = 0;
        if (*(u8 *)(*(u8 **)(p + 0x54) + 0x1A14)) {
            func_L39_005DB0E0(0, *(u8 *)(*(u8 **)(p + 0x54) + 0x24C9), 0.0f);
        }
    }
    if (func_L39_00639D90(g)) {
        v = 0;
        if (0.7f <= *(f32 *)(g + 0x1250)) {
            v = func_L39_00524E00(*(void **)(g + 0x122C), *(s32 *)(g + 0x2548)) != 0;
        }
        r = func_L39_005FFD20(g + 0x1338, g + 0x133C, v, 150.0f);
        if (g[0x1A14]) {
            func_L01_003F6F20(g[0x24C9], obj, r, 0, 0x20, -1, 4, 0.8f, 0.0f, 90.0f, 0.5f, 0.5f, 40.0f, 40.0f);
        }
    }
    func_0038CB00(p + 0x1C);
    func_L39_006732D0(g + 0x1A40, 0, 1, 0);
    if (func_L39_00673498(g + 0x1A40, 0) == 0) {
        /* idle path */
        *(u8 *)(p + 0x58) = 1;
        *(s32 *)(p + 0x10) = 0;
        *(s16 *)(p + 0x1E) = 0;
        *(s32 *)(p + 0x44) = 0;
        if (*(s32 *)(p + 0x5C) >= 0) {
            e = D_001FE020 + (*(s32 *)(p + 0x5C) << 7);
            if (*(u8 **)(e + 0xDC) == obj && e[0xD0] != 0) {
                func_L39_005F3088(*(s32 *)(p + 0x5C));
            }
            *(s32 *)(p + 0x5C) = -1;
        }
        if (obj[0x60] & 2) {
            func_L01_00444F38(obj, 1, 0, 1, 0);
        }
        func_L39_00622288(g);
        if (g[0x1A14]) {
            f = func_003C4088(D_001DF318_sda, D_L39_0024AA2C, *(f32 *)(p + 0x38));
            f = f * 0.017453292f;
            r = func_L01_00451D38(p + 0x50, D_L39_0024AA20, D_L39_0024AA24, f * 0.0200000014f);
            func_L39_005DB0E0(r, g[0x24C9], 1.0f);
        }
        return;
    }
    if (obj[0x43] != 2) func_003C3A10(obj, 2, 0, 0);
    if (g[0x1A07] == 0) func_L39_00621D60(g, -1);
    if (*(s16 *)(p + 0x1E) == 0) *(s16 *)(p + 0x1E) = 1;
    if (*(s16 *)(p + 0x1C) == 0) *(s16 *)(p + 0x1C) = 0xC;
    func_003C2F58(obj, 0, p);
    fp = p + 0x44;
    dec = dec5_525690(g + 0x19E4, &d1);
    if (dec == 1) {
        ((void (*)(void *, s32, s32, s32, s32))(*(void ***)(g + 0x14))[0x34 / 4])(g, 0x1D, 1, 0, 1);
    }
    qzero(&v4);
    dec = dec5_525690(g + 0x19E4, &a);
    if (dec == 0x1D) {
        func_0038D5B0(&t2, g + 0x23C0);
        v4.z = 1.0f;
        func_0038D028(&v4, &v4, &t2);
    } else if (g[0x1A08] == 1) {
        func_0038CE20(&v4, obj + 0xD0, -1.0f);
    } else {
        v4.x = 1.0f;
        func_0038D000(&v4, &v4, g + 0x380);
    }
    *(f32 *)(p + 0x48) = func_0038D160(v4.x, v4.y);
    *(f32 *)(p + 0x4C) = func_0038D160(func_0038CED8(&v4), v4.z);
    if (g[0x1A14] == 0) {
        func_L39_00674320(g);
        if (*(u8 **)(g + 0x1078) && func_L39_00524E00(*(void **)(g + 0x1078), *(s32 *)(g + 0x2548))) {
            sel = *(u8 **)(g + 0x1078);
        }
    }
    if (*(s32 *)(g + 0x1310) != 0 && g[0x1A14] != 0) {
        u8 *tgt = *(u8 **)(g + 0x122C);
        if (tgt) {
            if (0.7f < *(f32 *)(g + 0x1250) && func_0038CF00(p, tgt + 0x10) < 12.0f) {
                if (func_L39_00524E00(tgt, *(s32 *)(g + 0x2548))) sel = *(u8 **)(g + 0x122C);
            } else if (func_L01_0040E548(p, *(u8 **)(g + 0x122C) + 0x10) < 6.25f) {
                u8 *tbl;
                func_0038CE20(&t1, obj + 0xD0, -1.35f);
                vec_add_ab(&t1, &t1, obj + 0x10);
                func_0038CE20(&t2, obj + 0xC0, -0.275f);
                vec_add_ab(&t1, &t1, &t2);
                tbl = D_L39_0024CE20[*(s32 *)(g + 0x2544)];
                e = *(u8 **)(g + 0x2524);
                func_L39_005FFDF8(tbl ? *(s32 *)(tbl + 0x2548) : -1);
                n = func_003D4D00(&t1, 1, e, 0, 1.5f);
                func_L39_005FFE78();
                for (i = 0; i < n; i++) {
                    elem = D_L39_002637C0[i];
                    if (elem == *(u8 **)(g + 0x2524)) continue;
                    if (func_L39_00524E00(elem, *(s32 *)(g + 0x2548)) == 0) continue;
                    sel = D_L39_002637C0[i];
                    break;
                }
            }
        }
    } else if (sel == 0) {
        *(vu0_q *)&t1 = *(vu0_q *)p;
        sel = (u8 *)func_L39_00525030((void *)obj, (void *)&t1, (f32 *)(p + 0x48), (f32 *)(p + 0x4C));
    }
    func_0038CAD0(fp);
    if (*(u8 **)(p + 0x10) != 0) {
        cur = live_525690(*(void **)(p + 0x10));
        if (*(u8 **)(p + 0x10) == 0) {
            *(s32 *)(p + 0x10) = 0;
            *(s32 *)(p + 0x44) = 0;
        } else {
            u8 t = (*(u8 **)(p + 0x10))[0x20];
            if (t == 0xFE || t == 0xFD) {
                *(s32 *)(p + 0x10) = 0;
                *(s32 *)(p + 0x44) = 0;
            } else if (cur != 0) {
                u8 *c28 = *(u8 **)(cur + 0x2528);
                if (c28 != 0 && (*(u32 *)(c28 + 0x2F8) & 0x4000000) == 0) {
                    *(s32 *)(p + 0x10) = 0;
                    *(s32 *)(p + 0x44) = 0;
                } else {
                    ok = 0;
                    if (*(u8 **)(cur + 0x2530) != 0 && (*(u8 **)(cur + 0x2530))[0x27B] != 0) {
                        if (dec5_525690(cur + 0x19E4, &a) == 0x31) ok = 1;
                    }
                    if (ok) {
                        *(s32 *)(p + 0x10) = 0;
                        *(s32 *)(p + 0x44) = 0;
                    }
                }
            }
        }
    }
    if (sel == 0) {
        if (*(s32 *)(p + 0x44) == 0) {
            *(f32 *)(p + 0x38) = 1.0f;
            goto after_ease;
        }
    } else {
        info = func_00382348(sel);
        if (sel != *(u8 **)(p + 0x10)) {
            if (*(s32 *)(p + 0x44) != 0) {
                *(u8 **)(g + 0x1078) = sel;
                goto ease;
            }
            *(u8 **)(p + 0x10) = sel;
            *(f32 *)(p + 0x14) = (f32)*(s16 *)(info + 4);
            *(f32 *)(p + 0x18) = *(f32 *)info;
            *(s32 *)(p + 0x44) = 0x13;
            if (*(f32 *)(p + 0x14) <= 1.0f) *(f32 *)(p + 0x18) = 0;
        }
        *(u8 **)(g + 0x1078) = sel;
    }
ease:
    if (func_L39_00648AE0(g, 9)) {
        e = D_L39_0049C890 + (*(s8 *)(D_L39_0049C890 + 0x4A1) << 7);
    } else {
        e = D_L39_0049C890 + 0x480;
    }
    w = *(f32 *)(e + 0x30) * 0.0200000014f * 1.2f;
    f = *(f32 *)(p + 0x18) - w;
    *(f32 *)(p + 0x18) = f;
    if (f < 0.0f) *(f32 *)(p + 0x18) = 0.0f;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x18) / *(f32 *)(p + 0x14);
after_ease:
    f = func_003C4088(D_L39_0024AA28, D_L39_0024AA2C, *(f32 *)(p + 0x38));
    r = func_L01_00451D38(p + 0x50, D_L39_0024AA20, D_L39_0024AA24, (f * 0.017453292f) * 0.0200000014f);
    if (g[0x1A14]) func_L39_005DB0E0(r, g[0x24C9], *(f32 *)(p + 0x38));
    cur = live_525690(*(void **)(p + 0x10));
    if (cur != 0 && cur[0x1A14] != 0) func_L39_005DB148(cur[0x24C9], *(f32 *)(p + 0x38));
    if (*(u8 **)(p + 0x10) != 0 && *(f32 *)(p + 0x18) <= 0.0f) {
        func_L39_005F33E0(3, 0, obj);
        cur = live_525690(*(void **)(p + 0x10));
        if (cur != 0) {
            u8 *c28 = *(u8 **)(cur + 0x2528);
            if (c28 != 0) {
                if ((*(u32 *)(c28 + 0x2F8) & 0x4000000) == 0) goto finish;
            } else if (*(s32 *)(cur + 0x254C) != 0) {
                goto finish;
            }
            if (info != 0) {
                info[0x17] = 9;
                dec = dec3_525690(g + 0x1A41, &a);
                *(u8 **)(cur + 0x2460) = g;
                cur[0x2464] = (dec >> 9) & 1;
                r = info[0xE];
                if (r == 1) {
                    n = func_L39_005B43C8(1, 2);
                    info[0xE] = (n == r) ? 4 : 2;
                }
            }
        } else {
            flag = 1;
            if (info != 0 && info[0xE] == 2) flag = 0;
            if (flag) {
                if (func_L39_005B43C8(1, 2) == 1) func_L39_00557600(*(void **)(p + 0x10), g);
                else func_L39_005285A8(*(void **)(p + 0x10), g);
            }
            *(s32 *)(p + 0x10) = 0;
        }
    }
finish:
    func_L39_00526340(obj);
    if (func_L39_005F2FA0(obj, *(s32 *)(p + 0x5C)) == 0) {
        *(s32 *)(p + 0x5C) = func_L39_005F33E0(1, 4, obj);
    }
}
