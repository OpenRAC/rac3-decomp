#include "common.h"

/* localdecomp:start func_L40_00420998 */
extern f32 func_L39_005B4410(void);
extern f32 func_L39_005B44C8(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L40_00420998(f32 *out) {
    f32 r = func_L39_005B4410();
    f32 a = func_L39_005B44C8();
    f32 b = func_L39_005B44C8();
    out[0] = func_0038D098(a) * func_0038D0B0(b) * r;
    out[1] = func_0038D0B0(a) * func_0038D0B0(b) * r;
    out[2] = 0.0f;
}
/* localdecomp:end func_L40_00420998 */

INCLUDE_ASM("asm/levels", func_L40_00420A38);

/* localdecomp:start func_L40_00420B50 */
s32 func_L40_00420B50(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 104);
    u8 **p;
    u8 *q;
    s32 i;

    for (i = 0; i < *(s32 *)(v + 1128); i++) {
        p = (u8 **)(v + 784) + i;
        q = p[6];
        if (q == 0 || q[49] == 0 || (q = *(u8 **)(q + 28)) == 0 || *(s16 *)(q + 170) != 6683 || q != p[0]) {
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_00420B50 */

INCLUDE_ASM("asm/levels", func_L40_00420BC8);

INCLUDE_ASM("asm/levels", func_L40_00421148);

/* localdecomp:start func_L40_00421300 */
typedef struct N_00421300 {
    u8 p0[8];
    s32 type;
    s32 wC;
    s32 time;
    s32 w14;
    s32 data[3];
    u8 p24[0x84 - 0x24];
    struct N_00421300 *next;
} N_00421300;
typedef struct { s32 w[3]; } B_00421300;
typedef struct { u8 pad[0x128]; s32 w128; } G_00421300;

extern G_00421300 D_001A5CD0;
extern u8 D_001FE020[];
typedef struct { f32 x, y, z, w; } V_00421300;
__asm__(".extern D_L40_00242930, 16");
extern V_00421300 D_L40_00242930 __attribute__((section(".sdata")));
extern void func_L01_00451FE0(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern s32 func_L39_005F33E0(s32, s32, u8 *);
extern void func_L39_005F3088(s32);
extern void func_L40_0053F6E0(u8 *);
extern s32 func_L40_0053DC18(s32);
extern void func_L39_005F2FF8(void *, s32);
extern N_00421300 *func_L39_0066C3C8(N_00421300 *, N_00421300 **);

void func_L40_00421300(s32 a0, u8 *self) {
    u8 *mv = *(u8 **)(self + 0x90);
    N_00421300 *p = *(N_00421300 **)(mv + 0x38);
    u8 *v = *(u8 **)(self + 0x68);
    s32 *q;
    s32 idx;
    u8 *slot;

    while (p != 0) {
        q = &p->type;
        if (q[2] > D_001A5CD0.w128) {
            p = p->next;
            continue;
        }
        switch (p->type) {
        case 1:
            switch (q[3]) {
            case 0:
                func_L01_004450F0(self, 2, -1);
                *(B_00421300 *)(v + 0x2D0) = *(B_00421300 *)p->data;
                break;
            case 1:
                *(s32 *)(v + 0x450) = p->data[0];
                p = func_L39_0066C3C8(p, (N_00421300 **)(mv + 0x38));
                continue;
            default:
                continue;
            }
            break;
        case 2:
            func_L01_00451FE0(self, 15, &D_L40_00242930, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L39_005F33E0(2, 0, self);
            idx = *(s32 *)(v + 0x2AC);
            if (idx != -1) {
                slot = D_001FE020 + (idx << 7);
                if (*(u8 **)(slot + 0xDC) == self && slot[0xD0]) {
                    func_L39_005F3088(idx);
                }
            }
            *(s32 *)(v + 0x2AC) = -1;
            func_L40_0053F6E0(self);
            func_L40_0053DC18(a0);
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
            func_L01_004450F0(self, 0x25, -1);
            return;
        default:
            p = func_L39_0066C3C8(p, (N_00421300 **)(mv + 0x38));
            continue;
        }
        p = func_L39_0066C3C8(p, (N_00421300 **)(mv + 0x38));
    }
}
/* localdecomp:end func_L40_00421300 */

INCLUDE_ASM("asm/levels", func_L40_00421550);

INCLUDE_ASM("asm/levels", func_L40_00421920);

INCLUDE_ASM("asm/levels", func_L40_00421C08);

INCLUDE_ASM("asm/levels", func_L40_00421FE0);

INCLUDE_ASM("asm/levels", func_L40_00422100);

INCLUDE_ASM("asm/levels", func_L40_00422208);

/* localdecomp:start func_L40_00422358 */
typedef struct {
    u8 p0[0x20]; u8 state;
    u8 p21[0x68 - 0x21]; u8 *vars;
} S_Moby421A88;

extern S_Moby421A88 *func_L40_00422208(S_Moby421A88 *, s32);

void func_L40_00422358(S_Moby421A88 *m, s32 x) {
    u8 *mv = m->vars;
    s32 n1 = *(s32 *)(mv + 0x30);
    s32 n3 = *(s32 *)(mv + 0x38);
    s32 n2 = *(s32 *)(mv + 0x34);
    s32 i;
    S_Moby421A88 *o;

    if (n1 > 0) {
        i = 0;
        while (i < n1) {
            o = func_L40_00422208(m, 4255);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2B8) = x;
                *(s32 *)(v + 0x34C) = *(s32 *)(v + 0x3D8);
            }
            i++;
        }
    }
    if (n3 > 0) {
        i = 0;
        while (i < n3) {
            o = func_L40_00422208(m, 6646);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x1C0) = 500;
                *(s32 *)(v + 0x1A0) = x;
            }
            i++;
        }
    }
    if (n2 > 0) {
        i = 0;
        while (i < n2) {
            o = func_L40_00422208(m, 6683);
            if (o == 0) break;
            {
                S_Moby421A88 *p = o;
                u8 *v;
                p->state = 39;
                v = p->vars;
                *(s32 *)(v + 0x2AC) = x;
                *(s32 *)(v + 0x2E8) = *(s32 *)(v + 0x308);
            }
            i++;
        }
    }
}
/* localdecomp:end func_L40_00422358 */

/* localdecomp:start func_L40_004224A0 */
extern u8 D_L40_0026E7D0[];
extern s32 D_L40_0026DD80[];

void func_L40_004224A0(u8 *a0, s32 a1) {
    u8 b;
    *(s16 *)(a0 + 170) = a1;
    b = D_L40_0026E7D0[(s16)a1];
    a0[34] = b;
    *(s32 *)(a0 + 36) = D_L40_0026DD80[a0[34]];
}
/* localdecomp:end func_L40_004224A0 */

/* localdecomp:start func_L40_004224E0 */
int func_L40_004224E0(u8 *a) {
    u8 *p = *(u8 **)(a + 104);
    return *(s32 *)(p + 124) != -1;
}
/* localdecomp:end func_L40_004224E0 */

/* localdecomp:start func_L40_004224F8 */
s32 func_L40_004224F8(u8 *a0) {
    switch (*(s16 *)(a0 + 170)) {
    case 6842:
    case 6843:
    case 6844:
    case 6845:
    case 6846:
    case 6848:
    case 6849:
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_004224F8 */

/* localdecomp:start func_L40_00422530 */
s32 func_L40_00422530(u8 *a) {
    return (u32)(*(u16 *)(a + 0xAA) - 6842) < 8;
}
/* localdecomp:end func_L40_00422530 */

/* localdecomp:start func_L40_00422540 */
s32 func_L40_00422540(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1f1e;
}
/* localdecomp:end func_L40_00422540 */

/* localdecomp:start func_L40_00422550 */
s32 func_L40_00422550(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1af2;
}
/* localdecomp:end func_L40_00422550 */

/* localdecomp:start func_L40_00422560 */
s32 func_L40_00422560(u8 *a) {
    return *(s16 *)(a + 0xAA) == 0x1b0b;
}
/* localdecomp:end func_L40_00422560 */

/* localdecomp:start func_L40_00422570 */
extern s32 func_L40_004224E0(u8 *a0);
extern s32 func_L40_00422560(u8 *a0);
extern s32 func_L40_00422540(u8 *a0);
extern void func_003C2880(u8 *a0);
extern void func_L40_003DB068(u8 *a0);
void func_L40_00422570(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 104);
    u8 *p;
    if (*(u8 **)(s1 + 120) != 0) {
        if (func_L40_004224E0(a0) || func_L40_00422560(a0) || func_L40_00422540(a0)) {
            func_003C2880(*(u8 **)(s1 + 120));
            *(u8 **)(s1 + 120) = 0;
        } else {
            p = *(u8 **)(s1 + 120);
            if (*(s16 *)(p + 170) == 6899) {
                func_L40_003DB068(p);
            }
            *(u8 **)(s1 + 120) = 0;
        }
    }
}
/* localdecomp:end func_L40_00422570 */

INCLUDE_ASM("asm/levels", func_L40_00422608);

/* localdecomp:start func_L40_00422678 */
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L40_00422570(u8 *);
extern s32 func_L40_00422550(u8 *);
extern void func_L40_00423CB0(u8 *);

void func_L40_00422678(u8 *self) {
    u8 *v;

    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 104);
    func_L01_004450F0(self, 1, -1);
    *(u16 *)(self + 52) &= 0xFFBE;
    *(u16 *)(self + 52) |= *(u16 *)(*(u8 **)(self + 36) + 68) & 0x1000;
    *(s32 *)(self + 152) = *(s32 *)(*(u8 **)(self + 36) + 16);
    self[168] = 255;
    func_L40_00422570(self);
    *(f32 *)(v + 48) = 1.0f;
    *(u16 *)(self + 52) |= 0x1000;
    if (func_L40_00422550(self) != 0) {
        func_L40_00423CB0(self);
    }
}
/* localdecomp:end func_L40_00422678 */

/* localdecomp:start func_L40_00422730 */
extern void func_L40_00422678(u8 *);
extern s32 func_L40_00422608(u8 *);

void func_L40_00422730(u8 *self, s32 a1, s32 a2) {
    u8 *v;

    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 104);
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    if (func_L40_00422608(self) == 0) {
        return;
    }
    *(s32 *)(v + 0x84) = 1;
    if (func_L40_00422550(self) != 0) {
        func_L40_00423CB0(self);
    }
    if (self[32] != 0) {
        *(s32 *)(v + 0x70) = 30000;
        ((void (*)(u8 *, s32, s32))func_L40_00422678)(self, a1, a2);
    } else {
        *(s32 *)(v + 0x70) = 30;
    }
}
/* localdecomp:end func_L40_00422730 */

/* localdecomp:start func_L40_004227F8 */
extern s32 D_L40_00247718[2] __attribute__((section(".sdata")));
extern s32 D_L40_00247720[2] __attribute__((section(".sdata")));
s32 *func_L40_004227F8(u8 *a0, s32 a1, s32 *a2) {
    s32 *r = 0;
    switch (a1) {
    case 0x4027571:
        r = D_L40_00247718;
        *a2 = 4;
        break;
    case 0x4027572:
        r = D_L40_00247720;
        *a2 = 4;
        break;
    }
    return r;
}
/* localdecomp:end func_L40_004227F8 */

/* localdecomp:start func_L40_00422848 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00422848(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L40_00422848 */

/* localdecomp:start func_L40_00422870 */
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_L40_00422540(u8 *a0);
extern s32 func_L40_00545BF0(void);
extern s32 func_L39_00672208(s32);
extern s32 func_0019D510(void);
extern s32 func_L39_00672118(u32);
extern s32 func_L39_00672190(s32);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern u8 *D_L40_00249330[8] __attribute__((section(".sdata")));
extern u8 *D_L40_00241640;

void func_L40_00422870(u8 *self, u8 *other) {
    s32 r = 0;
    s32 i;
    s32 j;
    u8 *p;
    s32 h;
    u8 bits;
    s32 k;
    s32 n;
    s32 me;
    u8 buf[1];

    if (other == 0 || !(func_L01_0040E548(other + 0xA0, self + 0x10) < 4.0f)) {
        r = 250;
    } else {
        for (i = 0; i < 8; i++) {
            p = D_L40_00249330[i];
            if (p != 0 && p != other && func_L01_0040E548(other + 0xA0, p + 0xA0) < 20.0f) {
                r = 250;
                break;
            }
        }
    }
    h = func_L39_0066DCC8((s32)self, 0, 0, r);
    if (func_L40_00422540(self) != 0) {
        bits = D_L40_00241640[0x199];
        k = 0;
        n = func_L40_00545BF0();
        if (func_L39_00672208(1) != 0) {
            n--;
        }
        if (n >= 2) {
            k = func_0019D510() % n;
        }
        me = func_L39_00672118(1);
        for (j = 0; j < 8; j++) {
            if (j != me && ((bits >> j) & 1)) {
                if (k == 0) {
                    break;
                }
                k--;
            }
        }
        buf[0] = func_L39_00672190(j);
        func_L39_00662AA0(h, buf, 1);
    }
}
/* localdecomp:end func_L40_00422870 */
