#include "common.h"

typedef struct { char b[28]; } B28;

INCLUDE_ASM("asm/levels", func_L24_0034A2C8);

INCLUDE_ASM("asm/levels", func_L24_0034AA48);

/* localdecomp:start func_L24_0034AE40 */
extern B28 D_L24_001DD358;
extern s32 D_L24_002B0FA0[];
extern s32 func_00381FF0(s32 a);
extern void func_003AF408(void *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_0034AE40(u8 *obj) {
    s32 *st = *(s32 **)(obj + 0x68);
    B28 buf = D_L24_001DD358;
    s32 r = func_00381FF0(D_L24_002B0FA0[*st]);
    func_003AF408(&buf, 0x80F0F0F0, r, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_0034AE40 */

/* localdecomp:start func_L24_0034AF10 */
extern B28 D_L24_001DD378;
extern s32 D_L24_002B1000[];
__asm__(".extern D_001DD310_sda, 8");
extern s32 D_001DD310_sda[2];
extern s32 func_00381FF0(s32 a);
extern void func_003AF408(void *buf, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern void func_003A9440(s32, unsigned long);
extern void func_0038E138(void);

void func_L24_0034AF10(u8 *obj) {
    s32 *q = D_001DD310_sda;
    s32 v = D_L24_002B1000[**(s32 **)(obj + 0x68)];
    B28 buf = D_L24_001DD378;
    s32 r = func_00381FF0(q[v]);
    func_003AF408(&buf, 0x80F0F0F0, r, 1, 0, -1, 0, 0, 0, 0);
    func_003A9440(0x47, 0x5360B);
    func_0038E138();
}
/* localdecomp:end func_L24_0034AF10 */

/* localdecomp:start func_L24_0034AFF0 */
/* PAL port of the NTSC-U match src/us/levels/func_L24_0034A1B8.c: PAL's frame counts are 5/6 and its rates 6/5 of NTSC-U's */
extern s32 func_L24_0034B930(u8 *);
extern void func_L24_0034C088(u8 *), func_L24_0034C208(void *), func_L24_0034C348(void *), func_L24_0034CCA0(void *), func_L24_0034BBD8(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L01_00315900(s32, s32, s32);
extern s32 func_00382498(s32, s32), func_00382468(s32);
extern void func_003C4138(void *, f32, f32);
extern void func_L01_0045A748(void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045BD10(void *, f32);
extern f32 func_L01_004395E0(void *);
extern s32 D_001DD39C_sda, D_001DD3A0_sda;
__asm__(".extern D_001DD39C_sda, 4");
__asm__(".extern D_001DD3A0_sda, 4");
extern struct { u8 pad[0x80]; f32 x, y; } D_001A4BE0;
extern u8 D_001A4C60[];
void func_L24_0034AFF0(u8 *m) {
    u8 *p = *(u8 **)(m + 0x68);
    if (func_L24_0034B930(m)) return;
    if (!*(s32 *)(p + 0x588)) {
        func_L24_0034C088(m);
        func_L24_0034C208(m);
        func_L24_0034C348(m);
        return;
    }
    switch (m[0x95]) {
    case 0:
        if (*(s16 *)(p + 0x234) == 1) {
            *(f32 *)(p + 0x584) = 0.5f;
            if (m[0x43] != 5) func_003C3A10(m, 5, 0, 4);
            func_L01_004450F0(m, 3, 2);
        } else if (*(s32 *)(p + 0x4b8)) {
            func_L01_004450F0(m, 2, 1);
            *(s32 *)(p + 0x4b8) = 0;
            if (*(s32 *)(p + 0x4b0) < 250) *(s32 *)(p + 0x4b0) = (func_00382498(480, 600) * 5 + 2) / 6;
        }
        break;
    case 1:
        if (*(s16 *)(p + 0x234) == 1) func_L01_004450F0(m, 5, 2);
        else if (!*(s32 *)(p + 0x4b0)) func_L01_004450F0(m, 1, 0);
        break;
    case 2:
        break;
    case 3:
        func_003C4138(p + 0x584, 0.6f, 0.040000003f);
        if (m[0x60] & 2) {
            func_L24_0034BBD8(m);
            func_L01_00315900((s32)m, 0, 0);
            return;
        }
        break;
    }
    switch (m[0x20]) {
    case 1: break;
    case 2: break;
    case 3:
        if (m[0x60] & 2) {
            if (m[0x43] != 2) func_003C3A10(m, 2, 0, 4);
            func_L01_004450F0(m, 5, -1);
            D_001DD39C_sda = 0;
        }
        break;
    case 4:
        func_003C4138(p + 0x584, 0.6f, 0.040000003f);
        func_L01_0045A748(m, D_001A4C60);
        func_L01_004450F0(m, 5, -1);
        if (m[0x43] != 2) func_003C3A10(m, 2, 0, 5);
        if (!func_00382468(4)) {
            if (m[0x43] != 15) func_003C3A10(m, 15, 0, 5);
        }
        break;
    case 5:
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.x - *(f32 *)(m + 0x10), D_001A4BE0.y - *(f32 *)(m + 0x14)));
        func_003C4138(p + 0x584, 1.6f, 0.035000004f);
        if (m[0x60] & 2) {
            func_L01_004450F0(m, 6, -1);
            if (m[0x43] != 7) func_003C3A10(m, 7, 0, 8);
            if (D_001DD39C_sda) {
                if (m[0x43] != 6) func_003C3A10(m, 6, 0, 8);
                func_L01_004450F0(m, 7, -1);
                if (D_001DD39C_sda == 2 && func_00382468(10)) {
                    if (m[0x43] != func_00382468(2) + 4) func_003C3A10(m, func_00382468(2) + 4, 0, 8);
                }
            }
        }
        break;
    case 7:
        if (func_L01_004395E0(m) < 125.0f && (m[0x42] == 6 || m[0x43] == 6)) {
            func_003C4138(p + 0x584, 0.0f, 0.080000006f);
        } else if (m[0x42] == 6) {
            func_003C4138(p + 0x584, 0.6f, 0.080000006f);
        } else {
            func_003C4138(p + 0x584, 0.6f, 0.8000001f);
        }
        if (m[0x60] & 2) {
            if (m[0x43] != 5) func_003C3A10(m, 5, 0, 4);
            func_L01_004450F0(m, 3, 2);
        }
        break;
    case 6:
        func_003C4138(p + 0x584, 0.5f, 0.16000001f);
        if (m[0x60] & 2) {
            if (m[0x42] == 7) {
                func_L01_004450F0(m, 8, -1);
                if (m[0x43] != 11) func_003C3A10(m, 11, 0, 8);
            } else if (D_001DD39C_sda == 2) {
                if (m[0x43] != 5) func_003C3A10(m, 5, 0, 4);
                func_L01_004450F0(m, 3, 2);
            } else {
                func_L01_004450F0(m, 4, -1);
                if (m[0x43] != 1) func_003C3A10(m, 1, 0, 8);
            }
        }
        break;
    case 8:
        func_003C4138(p + 0x584, 0.6f, 0.040000003f);
        if (m[0x60] & 2) {
            if (m[0x43] != 8) func_003C3A10(m, 8, 0, 8);
            func_L01_004450F0(m, 9, -1);
            D_001DD39C_sda = 1;
        }
        break;
    case 9:
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.x - *(f32 *)(m + 0x10), D_001A4BE0.y - *(f32 *)(m + 0x14)));
        if (*(f32 *)(p + 0x58c) + 3.0f < *(f32 *)(m + 0x18)) {
            if (m[0x43] != 10) func_003C3A10(m, 10, 0, 8);
            func_L01_004450F0(m, 12, -1);
            if (D_001DD3A0_sda) {
                if (m[0x43] != 9) func_003C3A10(m, 9, 0, 8);
            }
        } else *(f32 *)(m + 0x18) += 0.20000002f;
        break;
    case 12:
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.x - *(f32 *)(m + 0x10), D_001A4BE0.y - *(f32 *)(m + 0x14)));
        if (func_L01_004395E0(m) < 19.0f) {
            func_003C4138(p + 0x584, 0.7f, 0.060000002f);
        } else {
            func_003C4138(p + 0x584, 2.0f, 0.36f);
        }
        if (m[0x60] & 2) {
            func_L01_004450F0(m, 11, -1);
            if (m[0x43] != 13) func_003C3A10(m, 13, 0, 8);
            if (D_001DD3A0_sda) {
                if (m[0x43] != 14) func_003C3A10(m, 14, 0, 8);
            }
        }
        break;
    case 11:
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.x - *(f32 *)(m + 0x10), D_001A4BE0.y - *(f32 *)(m + 0x14)));
        func_003C4138(p + 0x584, 0.6f, 0.120000005f);
        if (m[0x60] & 2) {
            if (m[0x43] != 8) func_003C3A10(m, 8, 0, 4);
            func_L01_004450F0(m, 9, -1);
            if (D_001DD3A0_sda) {
                func_L01_004450F0(m, 10, -1);
            }
            D_001DD3A0_sda = 1;
        }
        break;
    case 10:
        func_003C4138(p + 0x584, 0.5f, 0.040000003f);
        func_L01_0045BD10(m, func_0038D160(D_001A4BE0.x - *(f32 *)(m + 0x10), D_001A4BE0.y - *(f32 *)(m + 0x14)));
        if (*(f32 *)(m + 0x18) <= *(f32 *)(p + 0x58c)) {
            if (m[0x43] != 12) func_003C3A10(m, 12, 0, 8);
            func_L01_004450F0(m, 13, -1);
        } else *(f32 *)(m + 0x18) -= 0.120000005f;
        break;
    case 13:
        if (m[0x60] & 2) {
            if (m[0x43] != 5) func_003C3A10(m, 5, 0, 8);
            func_L01_004450F0(m, 6, -1);
        }
        break;
    }
    func_L24_0034C088(m);
    func_L24_0034C208(m);
    func_L24_0034C348(m);
    func_L24_0034CCA0(m);
}
/* localdecomp:end func_L24_0034AFF0 */

/* localdecomp:start func_L24_0034B930 */
extern s32 func_L24_0034BA30(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004474E8(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);

s32 func_L24_0034B930(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 r;
    s32 v;
    f32 f;

    if (obj[0x20] == 0) {
        if (func_L24_0034BA30(obj) != 0) {
            return 1;
        }
    }
    func_L01_0044ABD0(obj, s + 0x160);
    r = func_L01_00447490(obj, 0x10000, 0);
    v = func_0038CB00(s + 0x36);
    f = func_L01_004474E8(obj, v != 0 ? r : 0);
    obj[0xA8] = 0xFF;
    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - f;
    if (*(f32 *)(s + 0x30) <= 0.0f) {
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 0x11);
        }
        func_L01_004450F0(obj, 0xE, 3);
    }
    func_L24_0043C3B0(obj, *(s32 *)(s + 0x4A0), 0, 0, 30.0f, 10.0f);
    return 0;
}
/* localdecomp:end func_L24_0034B930 */

/* localdecomp:start func_L24_0034BA30 */
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void func_L24_0034BC48(void *);
extern void func_L24_0034BF38(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
__asm__(".extern D_L24_001DD39C, 4");
__asm__(".extern D_L24_001DD3A0, 4");
extern s32 D_L24_001DD39C;
extern s32 D_L24_001DD3A0;

s32 func_L24_0034BA30(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 y;

    *(s32 *)(s + 0x580) = 0;
    D_L24_001DD39C = 0;
    y = *(f32 *)(obj + 0x18);
    D_L24_001DD3A0 = 0;
    *(f32 *)(s + 0x58C) = y;
    if (*(s16 *)(obj + 0xB2) == 0x34) {
        *(u16 *)(obj + 0x34) |= 0x8000;
    }
    s[0x1A8] = 3;
    *(f32 *)(s + 0x190) = 0.5f;
    s[0x170] = 0xE;
    s[0x176] = 3;
    *(f32 *)(s + 0x194) = 0.5f;
    *(f32 *)(s + 0x19C) = 0.15f;
    s[0x1D7] = 1;
    if (*(s16 *)(s + 0x34) == 0) {
        *(s16 *)(s + 0x34) = 100;
        *(f32 *)(s + 0x30) = 100.0f;
    }
    *(f32 *)(s + 0x40) = 2.0f;
    *(f32 *)(s + 0x80) = 0.9599311f;
    *(f32 *)(s + 0xA0) = 1.4835298f;
    *(f32 *)(s + 0x9C) = 0.002f;
    *(f32 *)(s + 0xA4) = 1.5f;
    *(f32 *)(s + 0x74) = 4.5f;
    *(f32 *)(s + 0x70) = 6.0f;
    func_L01_0045BD78(obj, 0.0048f, 0.120000005f, 0.0069813174f, 0.47472957f);
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * 0.75f;
    *(s32 *)(s + 0x584) = 0;
    func_L24_0034BC48(obj);
    func_L24_0034BF38(obj);
    func_L01_004450F0(obj, 1, 0);
    if (obj[0x43] != 0) {
        func_003C3A10(obj, 0, 0, 0);
    }
    return 0;
}
/* localdecomp:end func_L24_0034BA30 */

/* localdecomp:start func_L24_0034BBD8 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L24_0034BBD8(void *arg0) {
    s32 *p;
    s32 *base;
    s32 n;

    base = *(s32 **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32)arg0, 0, 3);
    p = (s32 *)((u8 *)base + 0x560);
    n = 4;
    do {
        func_L01_00315900(p[-8], 0, 0);
        n--;
        func_L01_00315900(p[0], 0, 0);
        p++;
    } while (n >= 0);
}
/* localdecomp:end func_L24_0034BBD8 */

/* localdecomp:start func_L24_0034BC48 */
#include "vu0.h"
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0043A430(void *, s32, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_0044FD88(void *, void *, s32, s32);
extern void func_003C2F58(void *, s32, void *);

void func_L24_0034BC48(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v0[4];
    f32 v1[4];
    u8 **a;
    u8 **b;
    s32 i;
    s32 j;

    func_0038CB78(s + 0x500, 0, 0x40);
    func_0038CB78(s + 0x4C0, 0, 0x40);
    func_L01_0043A430(obj, 1, s + 0x500);
    func_L01_0043A430(obj, 0, s + 0x4C0);
    *(f32 *)(s + 0x528) = 0.0001f;
    *(f32 *)(s + 0x524) = 0.0001f;
    *(f32 *)(s + 0x520) = 0.0001f;
    *(f32 *)(s + 0x4E8) = 0.0001f;
    *(f32 *)(s + 0x4E4) = 0.0001f;
    *(f32 *)(s + 0x4E0) = 0.0001f;
    s[0x502] = 1;
    s[0x4C2] = 1;
    *(u8 **)(s + 0x540) = func_003C24B0(0x1838, 0x80);
    func_L01_00456160(*(u8 **)(s + 0x540), obj);
    *(u16 *)(*(u8 **)(s + 0x540) + 0x34) |= 0x8000;
    *(f32 *)(*(u8 **)(s + 0x540) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(s + 0x540) + 0x24) + 0x24) * 0.75f;
    func_L01_0043B9E8(*(u8 **)(s + 0x540), 0x40, 0x10, 0x80);
    func_L01_0044FD88(obj, *(u8 **)(s + 0x540), 1, 0);
    a = (u8 **)(s + 0x540);
    for (i = 1; i < 5; i++) {
        a[i] = func_003C24B0(i + 0x1838, 0x80);
        func_L01_00456160(a[i], obj);
        *(u16 *)(a[i] + 0x34) |= 0x200;
        func_L01_0043B9E8(a[i], 0x40, 0x10, 0x80);
        *(f32 *)(a[i] + 0x2C) = *(f32 *)(*(u8 **)(a[i] + 0x24) + 0x24) * 0.75f;
        func_L01_0044FD88(a[i - 1], a[i], 0, 0);
    }
    *(u8 **)(s + 0x560) = func_003C24B0(0x1838, 0x80);
    func_L01_00456160(*(u8 **)(s + 0x560), obj);
    *(f32 *)(*(u8 **)(s + 0x560) + 0x2C) = *(f32 *)(*(u8 **)(*(u8 **)(s + 0x560) + 0x24) + 0x24) * 0.75f;
    func_L01_0043B9E8(*(u8 **)(s + 0x560), 0x40, 0x10, 0x80);
    func_L01_0044FD88(obj, *(u8 **)(s + 0x560), 0, 0);
    b = (u8 **)(s + 0x560);
    for (j = 1; j < 5; j++) {
        b[j] = func_003C24B0(j + 0x1838, 0x80);
        func_L01_00456160(b[j], obj);
        *(u16 *)(b[j] + 0x34) |= 0x200;
        func_L01_0043B9E8(b[j], 0x40, 0x10, 0x80);
        *(f32 *)(b[j] + 0x2C) = *(f32 *)(*(u8 **)(b[j] + 0x24) + 0x24) * 0.75f;
        func_L01_0044FD88(b[j - 1], b[j], 0, 0);
    }
    func_003C2F58(*(u8 **)(s + 0x540), 0, v1);
    func_003C2F58(*(u8 **)(s + 0x560), 0, v0);
    *(vu0_q *)(s + 0x2C0) = *(vu0_q *)v1;
    *(vu0_q *)(s + 0x3F0) = *(vu0_q *)v0;
}
/* localdecomp:end func_L24_0034BC48 */

/* localdecomp:start func_L24_0034BF38 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L24_0034C618(s32, s32, s32, void *, s32);

void func_L24_0034BF38(u8 *obj) {
    u8 buf[0x60];
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    s32 *q;
    s32 n;
    s32 m;
    u8 *p2;
    s32 *q2;

    p = s + 0x250;
    q = (s32 *)(s + 0x540);
    n = 3;
    do {
        func_003C2EC0((char *)q[0], 0, buf + 0x10);
        n--;
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(p, buf, buf + 0x40);
        *(u128_t *)(p + 0x90) = *(u128_t *)p;
        *(u128_t *)(buf + 0x50) = *(u128_t *)p;
        p += 0x10;
        func_L24_0034C618(q[0], q[1], 0, buf + 0x50, 0);
        q++;
    } while (n >= 0);
    p2 = s + 0x380;
    q2 = (s32 *)(s + 0x560);
    m = 3;
    do {
        func_003C2EC0((char *)q2[0], 0, buf + 0x10);
        m--;
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(p2, buf, buf + 0x40);
        *(u128_t *)(p2 + 0x90) = *(u128_t *)p2;
        *(u128_t *)(buf + 0x50) = *(u128_t *)p2;
        p2 += 0x10;
        func_L24_0034C618(q2[0], q2[1], 0, buf + 0x50, 0);
        q2++;
    } while (m >= 0);
}
/* localdecomp:end func_L24_0034BF38 */

/* localdecomp:start func_L24_0034C088 */
#include "vu0.h"
extern void func_003C2EC0(char *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

void func_L24_0034C088(u8 *obj) {
    u8 buf[0x50];
    u8 *s = *(u8 **)(obj + 0x68);
    char **a;
    char **b;
    s32 i;
    s32 j;
    f32 f;

    a = (char **)(s + 0x540);
    for (i = 0; i < 4; i++) {
        func_003C2EC0(a[i], 0, buf + 0x10);
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(s + 0x2E0 + i * 16, buf, buf + 0x40);
        f = func_003C3D30(s + 0x250 + i * 16, 2, 0, 0.5f) + 0.25f;
        if (*(f32 *)(s + 0x2E8 + i * 16) < f) {
            *(f32 *)(s + 0x2E8 + i * 16) = f;
        }
    }
    b = (char **)(s + 0x560);
    for (j = 0; j < 4; j++) {
        func_003C2EC0(b[j], 0, buf + 0x10);
        func_0038CF68(buf, buf + 0x10, *(f32 *)(s + 0x584));
        vec_add_ab(s + 0x410 + j * 16, buf, buf + 0x40);
        f = func_003C3D30(s + 0x380 + j * 16, 2, 0, 0.5f) + 0.25f;
        if (*(f32 *)(s + 0x418 + j * 16) < f) {
            *(f32 *)(s + 0x418 + j * 16) = f;
        }
    }
}
/* localdecomp:end func_L24_0034C088 */

INCLUDE_ASM("asm/levels", func_L24_0034C208);

INCLUDE_ASM("asm/levels", func_L24_0034C348);
