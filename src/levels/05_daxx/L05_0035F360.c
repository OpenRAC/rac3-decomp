#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L05_0035F360 */
typedef struct { u8 pad[0x90]; f32 ang[4]; s32 lo[4]; s32 hi[4]; } Q_0035F360;
extern u8 *D_001DFB9C_sda;
__asm__(".extern D_001DFB9C_sda, 4");
extern s32 func_0038CB00(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_0013D3E0(void);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern void func_003C4A40(void *, void *);
extern void func_003C4C18(f32 *, f32);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_003C2880(void *);
extern void func_L01_0044ABD0(void *, void *);

void func_L05_0035F360(u8 *p) {
    u8 *q;
    u8 *e;
    Q_0035F360 *qq;
    s32 k;
    s32 m;
    s32 h;
    s32 flag;
    s32 idx;
    s32 o;
    s32 r;
    f32 f0;
    f32 f21;
    f32 loc[4];
    f32 *lp;

    q = *(u8 **)(p + 0x68);
    qq = (Q_0035F360 *)q;
    if (p[0x20] == 0) {
        k = *(s32 *)(q + 0x84);
        if (k != -1) {
            e = D_001DFB9C_sda + (k << 8);
            if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || *(u16 *)(e + 0x7C) == 0 || *(s16 *)(q + 0x8E) == 0) {
                *(s32 *)(q + 0x84) = -1;
            }
        }
        *(u16 *)(p + 0x7C) = *(u16 *)(p + 0x7C) | 1;
    }

    m = *(s32 *)(q + 0x80);
    if (m == -1 || (e = (u8 *)((m << 8) + (s32)D_001DFB9C_sda), e[0x20] == 0xFE) || e[0x20] == 0xFD) {
        *(s32 *)(q + 0x80) = -1;
        if (p[0x20] == 0 || func_0038CB00(q + 0x8C) != 0) {
            idx = func_00382498(0, 3);
            o = idx << 2;
            f0 = qq->ang[idx] * 0.017453292f * 0.020000001f;
            *(f32 *)(q + 0x88) = f0;
            if (func_0013D3E0() & 1) {
                *(f32 *)(q + 0x88) = -*(f32 *)(q + 0x88);
            }
            r = func_00382498(qq->lo[idx], qq->hi[idx]);
            *(s16 *)(q + 0x8C) = (r * 5 + 2) / 6;
            func_L01_004450F0(p, 1, -1);
        }
        *(f32 *)(p + 0xF0) = func_0038DAB8(*(f32 *)(p + 0xF0), *(f32 *)(q + 0x88));
    } else {
        *(f32 *)(p + 0xF0) = *(f32 *)(e + 0xF0);
    }

    func_L01_004450F0(p, 1, -1);
    flag = 0;
    h = func_L01_00447490(p, -1, 0);
    f21 = func_L01_004474E8(p, h);
    if (h != 0 && f21 != 0.0f) {
        *(f32 *)(p + 0xF4) = func_003824E0(-0.05235988f, 0.05235988f);
        func_003C4A40(p, q + 0x70);
        f0 = *(f32 *)(q + 0x30) - f21;
        *(f32 *)(q + 0x30) = f0;
        if (f0 <= 0.0f) {
            *(f32 *)(q + 0x30) = 0.0f;
            flag = 1;
        }
    }

    k = *(s32 *)(q + 0x84);
    if (k != -1) {
        e = D_001DFB9C_sda + (k << 8);
        if (e == 0 || e[0x20] == 0xFE || e[0x20] == 0xFD || (*(u16 *)(e + 0x7C) & *(s16 *)(q + 0x8E)) == 0) {
            flag = 1;
            *(s32 *)(q + 0x84) = -1;
        }
    }

    if (flag != 0) {
        lp = loc;
        qzero(lp);
        func_003C4C18(lp, 0.040000003f);
        func_L01_0044BB30(p, p + 0x10, -1, 0.5f, 13.0f);
        func_003A52A0(0, 0, p);
        func_L01_00451FE0(p, 1, lp, 255, 180, 0, 0, 35, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_003C2880(p);
    } else {
        func_L01_0044ABD0(p, q + 0x70);
        p[0xA8] = 0xFF;
    }
}
/* localdecomp:end func_L05_0035F360 */

/* localdecomp:start func_L05_0035F6E0 */
typedef int u128_35F6E0 __attribute__((mode(TI)));
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern u8 D_001BBC40[];
extern u8 D_001C5290[];
extern u8 D_001A4C60[];
extern u8 *D_001A4F3C;
__asm__(".extern D_001A4F3C, 16");
extern u8 *D_L05_002208AC __attribute__((section(".data")));
extern s32 *D_L05_0021ED80[];
extern f32 D_L05_002F4170[];
extern s32 func_L05_00360070(u8 *, s32);
extern void func_L05_003601F0(u8 *);
extern u8 *func_L05_003602D0(u8 *, void *);
extern void func_L05_00360730();
extern void func_L05_00360448(u8 *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004AAC98(s32, s32, void *, s32);
extern void func_003A4F28(s32);
extern s32 func_00382380(u8 *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern void func_L03_004657D0(s32, s32, void *, void *, s32, f32);
extern s32 func_L01_004561B8(void *);
extern void func_003CA4A0(void *, s32, s32 *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382468(s32);
extern f32 func_0038D160(f32, f32);
extern u8 *func_L01_00470150(void *, void *, s32, s32, s32, f32, f32, s32, s32, s32, f32, s32, s32);
extern int func_L01_0041A4F0(void);
extern u8 *func_L05_00362148(u8 *, vu0_v4 *, vu0_v4 *, s32, s32, u8, f32);
extern void func_L01_004AA7E8(void *, s32);

static __inline__ s32 *nodes_0035F6E0(u8 *s) {
    return (s32 *)(s + 0x80);
}

void func_L05_0035F6E0(u8 *obj) {
    vu0_v4 a;
    vu0_v4 mat[4];
    vu0_v4 b;
    vu0_v4 c;
    s32 bone;
    u8 *s;
    u8 *p;
    s32 *t;
    s32 i;
    s32 j;
    s32 k;
    s32 level;
    s32 rate;
    f32 x;
    f32 damage;

    s = *(u8 **)(obj + 0x68);
    if (D_001BBC40[obj[0xB0] + D_001D545C * 16] & 0x80) {
        func_003C2880(obj);
        return;
    }
    if (s[0xC9] != 31) {
        for (i = 0; i < 5; i++) {
            if (!((s[0xC9] >> i) & 1)) {
                if (func_L05_00360070(obj, i)) {
                    s[0xC9] |= 1 << i;
                }
            }
        }
    }
    func_L01_00456C98(obj, 100.0f, 100.0f, 1.0f, -1, 0, 0, 0, 0, 1, 0, 0, 0);
    if (*(s32 *)(s + 0xD0) == -1) {
        if ((obj[0x34] ^ 1) & 1) {
            *(s32 *)(s + 0xD0) = func_L01_004AAC98(0, 4, obj, 0x1666);
        }
    } else if (*(u16 *)(obj + 0x34) & 1) {
        func_003A4F28(*(s32 *)(s + 0xD0));
        *(s32 *)(s + 0xD0) = -1;
    }
    for (j = 0; j < 4; j++) {
        if (func_00382380(D_001A4C60, nodes_0035F6E0(s)[j], 0)) {
            s[0xCB] |= 1 << j;
        }
    }
    switch (obj[0x20]) {
    case 0:
        k = -1;
        if (*(u16 *)(obj + 0x34) & 2) {
            return;
        }
        if (*(s32 *)(s + 0x54) != k && *D_L05_0021ED80[*(s32 *)(s + 0x54)] >= 2) {
            u8 *n = (u8 *)D_L05_0021ED80[*(s32 *)(s + 0x54)];
            x = func_0038CF00(n + 0x10, n + 0x20);
            *(f32 *)(s + 0xA4) = 0.0f;
            *(f32 *)(s + 0xA8) = *(f32 *)(s + 0xA0) * 0.020000001f / x;
            func_L03_004657D0(*(s32 *)(s + 0x54), 0, obj + 0x10, obj + 0xF0, 0, *(f32 *)(s + 0xA4));
        } else {
            *(f32 *)(s + 0xA8) = *(f32 *)(s + 0xA0) * 1.2f / 60.0f;
        }
        func_L01_004450F0(obj, 1, -1);
        *(f32 *)(s + 0xB0) = 1.0f;
        *(f32 *)(s + 0xB4) = -0.4f;
        *(f32 *)(s + 0xB8) = -1.0f;
        *(s16 *)(s + 0xBC) = 60;
        s[0xCB] = 0;
        obj[0xBC] = 0;
        s[0xC9] = 0;
        *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.5f;
        *(s16 *)(obj + 0x32) = 128;
        s[0xCD] = 0;
        *(u16 *)(obj + 0x34) &= 0xBFFF;
        *(s32 *)(s + 0xD0) = -1;
        *(s32 *)(obj + 0x98) = 0;
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(obj, 1);
        break;
    case 1:
        if (D_001A4F3C != 0 && *(s16 *)(D_001A4F3C + 0xAA) == 0x1626) {
            break;
        }
        if ((s[0xC9] >> (s8)s[0xC8]) & 1) {
            s[0xC8]++;
            *(f32 *)(obj + 0xF8) = func_0038D160(*(f32 *)(s + 0x30) - *(f32 *)(obj + 0x10),
                                                 *(f32 *)(s + 0x34) - *(f32 *)(obj + 0x14));
            *(f32 *)(s + 0xA4) = 0.0f;
            *(s16 *)(s + 0xBE) = 50;
            s[0xCE] = 2;
            *(s32 *)(s + 0xD0) = func_L01_004AAC98(0, 4, obj, 0x1666);
            func_L01_004450F0(obj, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj)) {
            func_L01_004AAC98(2, 0, obj, 0x1666);
        }
        if (func_0038CB00(s + 0xBE)) {
            func_L01_004450F0(obj, 3, -1);
        } else {
            func_L01_00404A10(func_L05_00360448, obj);
        }
        break;
    case 3:
        func_L05_003601F0(obj);
        if ((s[0xC9] >> (s8)s[0xC8]) & 1) {
            s[0xC8]++;
            *(s16 *)(s + 0xBE) = 50;
            func_L01_004450F0(obj, 4, -1);
        }
        break;
    case 4:
        func_L05_003601F0(obj);
        func_0038CB00(s + 0xBE);
        if (*(s16 *)(s + 0xBE) >= 6) {
            break;
        }
        x = *(f32 *)(obj + 0x2C);
        x *= 0.0009765625f;
        bone = s[0xCD];
        func_003CA4A0(obj, 1, &bone, mat);
        func_0038CE20(&a, &mat[3], x);
        *(u128_35F6E0 *)&b = *(u128_35F6E0 *)&a;
        x = 3 - *(s16 *)(s + 0xBE) / 2;
        x *= 0.8f;
        x += 1.5f;
        x *= func_003824E0(0.9f, 1.1f);
        func_003C4C18((f32 *)&b, 0.3f);
        {
            u8 *f = func_L01_00470150(&b, obj, 0x30204080, -1, 0, x * 210000.0f, 0.0f, 10, 0, -1,
                                      0.92f, func_00382468(2) ? 0xD0 : 0x30, 0);
            if (f != 0) {
                f[2] = *D_L05_002208AC;
            }
        }
        if (*(s16 *)(s + 0xBE) != 0) {
            break;
        }
        func_0038D000(&a, &a, obj + 0xC0);
        vec_add_ab(&a, &a, obj + 0x10);
        vec_sub_ab(&c, obj + 0x10, s + 0x30);
        func_0038CE90(&c, &c, obj + 0xE0);
        func_0038CF68(&c, &c, *(f32 *)(s + 0xB0) * 4.0f);
        vec_add_ba(&c, s + 0x30, &c);
        func_003C4C18((f32 *)&c, 0.5f);
        p = func_L05_003602D0(obj, &c);
        if (p != 0) {
            *(f32 *)(s + 0xB8) = c.z = *(f32 *)(p + 0x18) + 0.2f;
        } else if (*(f32 *)(s + 0xB8) > 0.0f) {
            c.z = *(f32 *)(s + 0xB8);
        }
        damage = 12.0f;
        if (func_L01_0041A4F0()) {
            damage = D_L05_002F4170[D_001D545C_sda] * damage;
        }
        func_L05_00362148(obj, &a, &c, (s32)p, 60, 0, damage);
        func_L01_004AAC98(1, 0, obj, 0x1666);
        *(f32 *)(s + 0xB0) += *(f32 *)(s + 0xB4);
        if (*(f32 *)(s + 0xB0) > 1.0f) {
            *(f32 *)(s + 0xB0) = 1.0f;
            *(f32 *)(s + 0xB4) = -*(f32 *)(s + 0xB4);
        } else if (*(f32 *)(s + 0xB0) < -1.0f) {
            *(f32 *)(s + 0xB0) = -1.0f;
            *(f32 *)(s + 0xB4) = -*(f32 *)(s + 0xB4);
        }
        if ((s[0xCB] >> ((s8)s[0xC8] - 2)) & 1) {
            s32 n = ((s8)s[0xC8] - 1) * 4;
            if (*(s32 *)((u8 *)nodes_0035F6E0(s) + n) >= 0) {
                func_L01_004450F0(obj, 3, -1);
            } else {
                *(s16 *)(s + 0xBE) = 50;
                s[0xCE] = 1;
                func_L01_004450F0(obj, 8, -1);
            }
            break;
        }
        s[0xCD] ^= 1;
        level = *(s32 *)(D_001C5290 + D_001D545C * 64);
        rate = 100;
        if (level >= 6) {
            rate = 75;
        } else if (level >= 11) {
            rate = 50;
        } else if (level >= 26) {
            rate = 25;
        } else if (level >= 2) {
            rate = 95 - (level - 2) * 10;
        }
        s[0xCC] = 1;
        *(s16 *)(s + 0xBE) = ((6000 / rate) * 5 + 2) / 6;
        break;
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        if (func_L01_004561B8(obj)) {
            func_L01_004AAC98(2, 0, obj, 0x1666);
        }
        if (func_0038CB00(s + 0xBE)) {
            if (*(s32 *)(s + 0xD0) != -1) {
                func_003A4F28(*(s32 *)(s + 0xD0));
            }
            func_003C2880(obj);
            return;
        }
        func_L01_00404A10(func_L05_00360448, obj);
        break;
    }
    if (obj[0x20] >= 3 && obj[0x20] <= 6 && *(s32 *)(s + 0x54) != -1) {
        f32 end;
        k = *(s32 *)(s + 0x54);
        *(f32 *)(s + 0xA4) += *(f32 *)(s + 0xA8);
        end = (f32)(*D_L05_0021ED80[k] - 1);
        if (*(f32 *)(s + 0xA4) < end) {
            func_L03_004657D0(k, 0, obj + 0x10, &a, 0, *(f32 *)(s + 0xA4));
        } else {
            *(f32 *)(s + 0xA4) = end;
            t = D_L05_0021ED80[k];
            *(u128_35F6E0 *)(obj + 0x10) = ((u128_35F6E0 *)t)[*t];
        }
    }
    if ((obj[0x34] ^ 1) & 1) {
        func_L05_00360730(obj);
    }
}
/* localdecomp:end func_L05_0035F6E0 */

/* localdecomp:start func_L05_00360070 */
typedef struct {
    u8 pad0[0x58];
    s32 f58[5];
    s32 f6C[5];
    u8 pad80[0x4A];
    u8 fCA;
} S_360070;
typedef struct {
    u8 p0[0x35C];
    s32 a35C;
    s32 a360;
    u8 p1[0x6F0];
    s32 aA54;
    u8 p2[0x1B74];
    s32 a25CC;
} B_360070;

extern B_360070 D_001A4BE0;
__asm__(".extern D_001A4BE0, 16");
extern u8 D_001A4C60[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 func_00382380(u8 *, s32, s32);

s32 func_L05_00360070(u8 *a0, s32 a1) {
    S_360070 *s = *(S_360070 **)(a0 + 0x68);
    s32 r;
    if (s->f6C[a1] == -1 && s->f58[a1] == -1) {
        return 1;
    }
    r = 0;
    if (((s->fCA >> a1) & 1) == 0) {
        if (s->f6C[a1] != -1 && D_001A4BE0.aA54 == (s32)D_L05_001DFB9C + (s->f6C[a1] << 8)
            && D_001A4BE0.a25CC == 0xE) {
            s->fCA |= 1 << a1;
        } else if (s->f58[a1] != -1 && func_00382380(D_001A4C60, s->f58[a1], 0)) {
            r = 1;
        } else if (D_001A4BE0.a360 != 0) {
            r = D_001A4BE0.a35C == (s32)D_L05_001DFB9C + (s->f6C[a1] << 8);
        }
    } else if (D_001A4BE0.aA54 != (s32)D_L05_001DFB9C + (s->f6C[a1] << 8)
               || D_001A4BE0.a25CC != 0xE) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L05_00360070 */

/* localdecomp:start func_L05_003601F0 */
extern void func_L01_00448890(u8 *a0, u8 *a1, f32 f12, f32 f13, f32 f14, f32 f15, s32 a2);
extern f32 func_0038D160(f32, f32);

void func_L05_003601F0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x68);
    f32 d;
    *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * 0.5f;
    d = func_0038D160(*(f32 *)(q + 0x30) - *(f32 *)(p + 0x10), *(f32 *)(q + 0x34) - *(f32 *)(p + 0x14));
    {
        f32 k = 2.0943953132e-4f;
        func_L01_00448890(p + 0xF8, q + 0xAC, d, k, k, 0.02792526968f, 0);
    }
}
/* localdecomp:end func_L05_003601F0 */

/* localdecomp:start func_L05_00360280 */
s32 func_L05_00360280(u8 *a0) {
    s32 v;
    s32 r;
    if (a0 == 0) {
        return 0;
    }
    v = *(s16 *)(a0 + 0xAA);
    if (v == 0x1684) {
        return 1;
    }
    r = 0;
    if (v == 0x15F7) {
        u8 *q = *(u8 **)(a0 + 0x68);
        s32 x = *(s32 *)(q + 0x70);
        s32 m = -1;
        if (x != m) {
            return 1;
        }
    }
    return r;
}
/* localdecomp:end func_L05_00360280 */

/* localdecomp:start func_L05_003602D0 */
extern u16 *D_L05_0021DAE0[];
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DFB9C, 16");
extern s32 D_L05_001DFBD8;
extern s32 func_L01_00456250(u8 *);
extern f32 func_L01_0040E570(u8 *, void *);
extern s32 func_L05_00360280(u8 *);
u8 *func_L05_003602D0(u8 *a0, void *a1) {
    u8 *s = *(u8 **)(a0 + 0x68);
    u16 *p = D_L05_0021DAE0[*(s32 *)(s + 0x50)];
    u8 *best = 0;
    s32 k;
    u8 *e;
    f32 d;
    while (1) {
        k = *(s32 *)(s + 0x50);
        if ((k & 0xFF) == 0xFF) break;
        if (D_L05_001DFBD8 < k) break;
        if (p == 0) break;
        if (!((s16)p[-1] >= 0 || p == D_L05_0021DAE0[k])) break;
        e = D_L05_001DFB9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (e[0x20] != 0xFE) {
            if (e[0x20] == 0xFD) {
                p++;
                continue;
            }
            if (func_L01_00456250(e) != 0) {
                p++;
                continue;
            }
            d = func_L01_0040E570(e + 0x10, a1);
            if (func_L05_00360280(e) != 0 && d < 64.0f) {
                *(u128_t *)a1 = *(u128_t *)(e + 0x10);
                return e;
            }
            if (d < 4.84f) {
                best = e;
            }
        }
        p++;
    }
    return best;
}
/* localdecomp:end func_L05_003602D0 */

/* localdecomp:start func_L05_00360448 */
extern vu0_v4 D_L05_001E2700;
extern f32 func_0038D098(f32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0040C3C0(void *, s32, s32, s32, s32, s32, s32, f32, f32);

void func_L05_00360448(u8 *o) {
    vu0_v4 q[4];
    vu0_v4 e;
    u8 *v;
    f32 t;
    f32 sz;
    s32 n;
    s32 al;
    s32 col;

    v = *(u8 **)(o + 0x68);
    t = 1.0f - __builtin_fabsf(1.0f - (f32)(*(s16 *)(v + 0xBE) - 1) * 2.0f / (f32)(*(s16 *)(v + 0xBC) - 2));
    if (t < 0.0f) {
        return;
    }
    t = (1.0f - func_0038D098(t * 3.1415927f)) * 0.5f;
    n = (f32)(*(s16 *)(v + 0xBC) - 2) * 0.5f;
    sz = t * 0.6f;
    if (v[0xCE] != 0 && n >= *(s16 *)(v + 0xBE)) {
        if (v[0xCE] == 2) {
            *(u16 *)(o + 0x34) &= 0xFFBE;
            *(u16 *)(o + 0x34) |= *(u16 *)(*(u8 **)(o + 0x24) + 0x44) & 0x1000;
            *(s32 *)(o + 0x98) = *(s32 *)(*(u8 **)(o + 0x24) + 0x10);
        } else {
            *(s32 *)(o + 0x98) = 0;
            *(u16 *)(o + 0x34) = (*(u16 *)(o + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(o, 1);
        }
        v[0xCE] = 0;
    }
    vec_sub_ab(&q[0], &D_L05_001E2700, o + 0x10);
    func_0038CF68(&q[0], &q[0], *(f32 *)(o + 0x2C) * 15.5f + 2.0f);
    func_0038CF68(&q[2], o + 0xE0, *(f32 *)(o + 0x2C) * 12.0f + 2.0f);
    func_0038CE90(&q[1], &q[2], &q[0]);
    func_0038CF68(&q[1], &q[1], *(f32 *)(o + 0x2C) * 26.0f + 2.0f);
    func_0038CF68(&e, &q[2], -1.8f);
    vec_add_ba(&q[3], o + 0x10, &e);
    func_0038CE20(&q[0], &q[0], 0.5f);
    vec_add_ab(&q[3], &q[3], &q[0]);
    *(f32 *)(v + 0xC0) = func_0038DAB8(*(f32 *)(v + 0xC0), 0.05585054f);
    if (t < 0.05f) {
        al = (u8)(s32)(t * 20.0f * 127.0f);
    } else {
        al = 0x7F;
    }
    col = (al << 24) | 0x808080;
    func_L01_0040C3C0(q, 0x40, col, col, col, 0x4D, -1, sz, *(f32 *)(v + 0xC0));
}
/* localdecomp:end func_L05_00360448 */

/* localdecomp:start func_L05_00360730 */
extern int abs(int);
typedef struct {
    char pad0[0x10];
    vu0_v4 pos;
    char pad20[0xC];
    f32 f2C;
    char pad30[0x90];
    char mat[0x38];
    f32 fF8;
} S_360730;

__asm__(".extern D_L05_001DD840, 8");
__asm__(".extern D_L05_001DD850, 8");
__asm__(".extern D_L05_001DD860, 8");
__asm__(".extern D_L05_001DD870, 8");
extern f32 D_L05_001DD840[2];
extern f32 D_L05_001DD850[2];
extern f32 D_L05_001DD860[2];
extern f32 D_L05_001DD870[2];
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L05_00360868(u8 *, f32, f32);

void func_L05_00360730(S_360730 *p) {
    s32 i = 0;
    vu0_v4 b;
    vu0_v4 a;
    do {
        s32 k = 2 - abs(2 - i);
        *(vu0_q *)&a = 0;
        a.x = D_L05_001DD840[k];
        a.y = D_L05_001DD850[k];
        a.z = D_L05_001DD860[k];
        b = a;
        if (i >= 3) {
            b.y = -b.y;
        }
        func_0038CE20(&b, &b, p->f2C);
        func_0038D000(&b, &b, p->mat);
        vec_add_ba(&b, &p->pos, &b);
        func_L05_00360868((u8 *)&b, func_0038DAB8(p->fF8, 3.1415927f), D_L05_001DD870[k]);
        i++;
    } while (i < 5);
}
/* localdecomp:end func_L05_00360730 */

/* localdecomp:start func_L05_00360868 */
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L05_00360868(u8 *p, f32 a, f32 b) {
    f32 v[4];
    s32 n;
    s32 n2;
    s32 sg;
    f32 s1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t5;

    s32 r;
    r = func_00382498(4, 8);
    if (r > 0) {
        n = r;
        do {
            n--;
            s1 = func_003824E0(15.0f, 20.0f) * 0.020000001f;
            t2 = func_003824E0(-0.52359879f, 0.52359879f);
            t3 = func_0038DAB8(a, t2);
            t4 = func_003824E0(-0.52359879f, 0.52359879f);
            func_00382760(v, s1, t3, t4);
            t5 = func_003824E0(2.5f, 3.0f) * b;
            n2 = func_00382498(4, 10);
            sg = func_00382468(2) != 0 ? 1 : -1;
            func_L01_0046FB40(p, v, n2, 0x204080, sg, 110, 32, 0, t5 * 210000.0f, t5 * 0.75f * 210000.0f, 0.0f);
        } while (n != 0);
    }
}
/* localdecomp:end func_L05_00360868 */
