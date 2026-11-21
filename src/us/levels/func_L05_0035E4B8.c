#include "common.h"

/* NTSC-U counterpart of func_L05_0035F6E0 (src/levels/05_daxx/L05_0035F360.c) */
#include "vu0.h"
extern s32 func_003883C8(void *);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BF6A8(f32 *, f32);
extern void func_003BD360(void *);

/* localdecomp:start func_L05_0035E4B8 */
typedef int u128_35F6E0 __attribute__((mode(TI)));
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_001D545C_sda_0035E4B8;
__asm__(".extern D_001D545C_sda_0035E4B8, 4");
extern u8 D_001BBC40[];
extern u8 D_001C5290[];
extern u8 D_001A4C60[];
extern u8 *D_001A4F3C;
__asm__(".extern D_001A4F3C, 16");
extern u8 *D_L05_0022092C __attribute__((section(".data")));
extern s32 *D_L05_0021EE00[];
extern f32 D_L05_002F41F0[];
extern s32 func_L05_0035EE20(u8 *, s32);
extern void func_L05_0035EFA0(u8 *);
extern u8 *func_L05_0035F080(u8 *, void *);
extern void func_L05_0035F4E0();
extern void func_L05_0035F1F8(u8 *);
extern void func_L01_004026A0(void *, void *);
extern void func_L01_004539A8(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_0039FB08(s32);
extern s32 func_0037E0F0(u8 *, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L03_00461B90(s32, s32, void *, void *, s32, f32);
extern s32 func_L01_00452EC8(void *);
extern void func_003C4F30(void *, s32, s32 *, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_003888C8(void *, void *, void *);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_00388A28(f32, f32);
extern u8 *func_L01_0046CA58(void *, void *, s32, s32, s32, f32, f32, s32, s32, s32, f32, s32, s32);
extern int func_L01_00417EA0(void);
extern u8 *func_L05_00360E30(u8 *, vu0_v4 *, vu0_v4 *, s32, s32, u8, f32);
extern void func_L01_004A6DF8(void *, s32);

static __inline__ s32 *nodes_0035F6E0(u8 *s) {
    return (s32 *)(s + 0x80);
}

void func_L05_0035E4B8(u8 *obj) {
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
        func_003BD360(obj);
        return;
    }
    if (s[0xC9] != 31) {
        for (i = 0; i < 5; i++) {
            if (!((s[0xC9] >> i) & 1)) {
                if (func_L05_0035EE20(obj, i)) {
                    s[0xC9] |= 1 << i;
                }
            }
        }
    }
    func_L01_004539A8(obj, 100.0f, 100.0f, 1.0f, -1, 0, 0, 0, 0, 1, 0, 0, 0);
    if (*(s32 *)(s + 0xD0) == -1) {
        if ((obj[0x34] ^ 1) & 1) {
            *(s32 *)(s + 0xD0) = func_L01_004A72A8(0, 4, obj, 0x1666);
        }
    } else if (*(u16 *)(obj + 0x34) & 1) {
        func_0039FB08(*(s32 *)(s + 0xD0));
        *(s32 *)(s + 0xD0) = -1;
    }
    for (j = 0; j < 4; j++) {
        if (func_0037E0F0(D_001A4C60, nodes_0035F6E0(s)[j], 0)) {
            s[0xCB] |= 1 << j;
        }
    }
    switch (obj[0x20]) {
    case 0:
        k = -1;
        if (*(u16 *)(obj + 0x34) & 2) {
            return;
        }
        if (*(s32 *)(s + 0x54) != k && *D_L05_0021EE00[*(s32 *)(s + 0x54)] >= 2) {
            u8 *n = (u8 *)D_L05_0021EE00[*(s32 *)(s + 0x54)];
            x = func_003887C8(n + 0x10, n + 0x20);
            *(f32 *)(s + 0xA4) = 0.0f;
            *(f32 *)(s + 0xA8) = *(f32 *)(s + 0xA0) * 0.016666668f / x;
            func_L03_00461B90(*(s32 *)(s + 0x54), 0, obj + 0x10, obj + 0xF0, 0, *(f32 *)(s + 0xA4));
        } else {
            *(f32 *)(s + 0xA8) = *(f32 *)(s + 0xA0) / 60.0f;
        }
        func_L01_00441FB8(obj, 1, -1);
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
        func_L01_004A6DF8(obj, 1);
        break;
    case 1:
        if (D_001A4F3C != 0 && *(s16 *)(D_001A4F3C + 0xAA) == 0x1626) {
            break;
        }
        if ((s[0xC9] >> (s8)s[0xC8]) & 1) {
            s[0xC8]++;
            *(f32 *)(obj + 0xF8) = func_00388A28(*(f32 *)(s + 0x30) - *(f32 *)(obj + 0x10),
                                                 *(f32 *)(s + 0x34) - *(f32 *)(obj + 0x14));
            *(f32 *)(s + 0xA4) = 0.0f;
            *(s16 *)(s + 0xBE) = 60;
            s[0xCE] = 2;
            *(s32 *)(s + 0xD0) = func_L01_004A72A8(0, 4, obj, 0x1666);
            func_L01_00441FB8(obj, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(obj)) {
            func_L01_004A72A8(2, 0, obj, 0x1666);
        }
        if (func_003883C8(s + 0xBE)) {
            func_L01_00441FB8(obj, 3, -1);
        } else {
            func_L01_004026A0(func_L05_0035F1F8, obj);
        }
        break;
    case 3:
        func_L05_0035EFA0(obj);
        if ((s[0xC9] >> (s8)s[0xC8]) & 1) {
            s[0xC8]++;
            *(s16 *)(s + 0xBE) = 60;
            func_L01_00441FB8(obj, 4, -1);
        }
        break;
    case 4:
        func_L05_0035EFA0(obj);
        func_003883C8(s + 0xBE);
        if (*(s16 *)(s + 0xBE) >= 6) {
            break;
        }
        x = *(f32 *)(obj + 0x2C);
        x *= 0.0009765625f;
        bone = s[0xCD];
        func_003C4F30(obj, 1, &bone, mat);
        func_003886E8(&a, &mat[3], x);
        *(u128_35F6E0 *)&b = *(u128_35F6E0 *)&a;
        x = 3 - *(s16 *)(s + 0xBE) / 2;
        x *= 0.8f;
        x += 1.5f;
        x *= func_0037E250(0.9f, 1.1f);
        func_003BF6A8((f32 *)&b, 0.3f);
        {
            u8 *f = func_L01_0046CA58(&b, obj, 0x30204080, -1, 0, x * 210000.0f, 0.0f, 10, 0, -1,
                                      0.92f, func_0037E1D8(2) ? 0xD0 : 0x30, 0);
            if (f != 0) {
                f[2] = *D_L05_0022092C;
            }
        }
        if (*(s16 *)(s + 0xBE) != 0) {
            break;
        }
        func_003888C8(&a, &a, obj + 0xC0);
        vec_add_ab(&a, &a, obj + 0x10);
        vec_sub_ab(&c, obj + 0x10, s + 0x30);
        func_00388758(&c, &c, obj + 0xE0);
        func_00388830(&c, &c, *(f32 *)(s + 0xB0) * 4.0f);
        vec_add_ba(&c, s + 0x30, &c);
        func_003BF6A8((f32 *)&c, 0.5f);
        p = func_L05_0035F080(obj, &c);
        if (p != 0) {
            *(f32 *)(s + 0xB8) = c.z = *(f32 *)(p + 0x18) + 0.2f;
        } else if (*(f32 *)(s + 0xB8) > 0.0f) {
            c.z = *(f32 *)(s + 0xB8);
        }
        damage = 12.0f;
        if (func_L01_00417EA0()) {
            damage = D_L05_002F41F0[D_001D545C_sda_0035E4B8] * damage;
        }
        func_L05_00360E30(obj, &a, &c, (s32)p, 60, 0, damage);
        func_L01_004A72A8(1, 0, obj, 0x1666);
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
                func_L01_00441FB8(obj, 3, -1);
            } else {
                *(s16 *)(s + 0xBE) = 60;
                s[0xCE] = 1;
                func_L01_00441FB8(obj, 8, -1);
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
        *(s16 *)(s + 0xBE) = 6000 / rate;
        break;
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        if (func_L01_00452EC8(obj)) {
            func_L01_004A72A8(2, 0, obj, 0x1666);
        }
        if (func_003883C8(s + 0xBE)) {
            if (*(s32 *)(s + 0xD0) != -1) {
                func_0039FB08(*(s32 *)(s + 0xD0));
            }
            func_003BD360(obj);
            return;
        }
        func_L01_004026A0(func_L05_0035F1F8, obj);
        break;
    }
    if (obj[0x20] >= 3 && obj[0x20] <= 6 && *(s32 *)(s + 0x54) != -1) {
        f32 end;
        k = *(s32 *)(s + 0x54);
        *(f32 *)(s + 0xA4) += *(f32 *)(s + 0xA8);
        end = (f32)(*D_L05_0021EE00[k] - 1);
        if (*(f32 *)(s + 0xA4) < end) {
            func_L03_00461B90(k, 0, obj + 0x10, &a, 0, *(f32 *)(s + 0xA4));
        } else {
            *(f32 *)(s + 0xA4) = end;
            t = D_L05_0021EE00[k];
            *(u128_35F6E0 *)(obj + 0x10) = ((u128_35F6E0 *)t)[*t];
        }
    }
    if ((obj[0x34] ^ 1) & 1) {
        func_L05_0035F4E0(obj);
    }
}
/* localdecomp:end func_L05_0035E4B8 */
