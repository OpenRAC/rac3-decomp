#include "common.h"
#include "vu0.h"

typedef struct { u8 pad0[0x20]; u8 b20; u8 pad21[0x43 - 0x21]; u8 b43; u8 pad44[0x68 - 0x44]; void *p68; } Obj_0034BC90;
typedef struct { u8 pad0[0x50]; f32 f50; s16 h54; u8 pad56[0x210 - 0x56]; f32 f210; s32 w214; s32 w218; u8 pad21c[0x220 - 0x21c]; f32 f220; } P_0034BC90;

/* localdecomp:start func_L30_00349390 */
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
__asm__(".extern D_L30_001DD2F8, 4");
extern s32 D_L30_001DD2F8[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD2D8, 4");
extern f32 D_L30_001DD2D8[] __attribute__((section(".sdata")));

typedef struct { u8 pad0[0x9C]; s32 a9C[8]; s32 wBC; } S_00349390;

void func_L30_00349390(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    s32 i = 0;
    f32 r;

    if (a0[0x20] >= 3 && a0[0x20] < 6) {
        *(s32 *)(st + 0xD0) = D_L30_001DD2F8[a0[0x20] - 3];
        r = func_003824E0(0.0f, 1.0f);
        while (D_L30_001DD2D8[i] < r) {
            r -= D_L30_001DD2D8[i];
            i++;
        }
        i++;
        *(s32 *)(st + 0xCC) = i;
        if (i == 2) {
            ((S_00349390 *)st)->wBC = ((S_00349390 *)st)->a9C[func_00382498(0, a0[0x20] - 3)];
        }
    }
}
/* localdecomp:end func_L30_00349390 */

/* localdecomp:start func_L30_00349470 */
extern void func_L30_00349630(void *, void *, float *);
extern void func_0038CF68(void *, void *, f32);
extern f32 D_L30_001DD2F0;
__asm__(".extern D_L30_001DD2F0, 4");

void func_L30_00349470(u8 *a0, void *a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 v[4];
    f32 w[4];
    f32 k;

    func_L30_00349630(a0, 0, v);
    vec_sub_ab(w, a1, v);
    func_0038CF68(w, w, 1.0f);
    k = D_L30_001DD2F0;
    *(f32 *)(p + 0x68) = w[0] * k;
    *(f32 *)(p + 0x64) = w[2] * (-k);
}
/* localdecomp:end func_L30_00349470 */

/* localdecomp:start func_L30_003494F0 */
extern void func_0038CF68(void *, void *, f32);
extern f32 D_L30_001DD2F0;
__asm__(".extern D_L30_001DD2F0, 4");

void func_L30_003494F0(u8 *a0, f32 *out) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 k;

    qzero(out);
    k = D_L30_001DD2F0;
    out[0] = *(f32 *)(p + 0x48) / k;
    out[2] = *(f32 *)(p + 0x44) / -k;
    func_0038CF68(out, out, 1.0f);
}
/* localdecomp:end func_L30_003494F0 */

/* localdecomp:start func_L30_00349550 */
__asm__(".extern D_L30_001DD1F0, 4");
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));

f32 func_L30_00349550(u8 *a0, u32 a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 m;

    if (a1 >= 5) {
        return 0.0f;
    }
    if (a0[0x20] < 3) {
        return 0.0f;
    }
    if (a0[0x20] >= 6) {
        return 0.0f;
    }
    m = D_L30_001DD1F0[a0[0x20] - 3];
    if (a1 == 0) {
        return 1.0f - *(s32 *)(p + 0xD0) / m;
    }
    if (a1 == 1) {
        return 1.0f - *(s32 *)(p + 0x110) / m;
    }
    if (a1 == 2) {
        return 1.0f - *(s32 *)(p + 0x120) / m;
    }
    if (a1 == 3) {
        return 1.0f - *(s32 *)(p + 0xF0) / m;
    }
    if (a1 == 4) {
        return 1.0f - *(s32 *)(p + 0x100) / m;
    }
    return 0.0f;
}
/* localdecomp:end func_L30_00349550 */

/* localdecomp:start func_L30_00349630 */
typedef int Q_00349630 __attribute__((mode(TI)));
typedef struct { u8 p0[0x10]; Q_00349630 q; u8 p20[0xE0]; } E_00349630;
__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF71C;
extern void func_003C2EC0(void *, s32, void *);

void func_L30_00349630(void *a, void *c, float *out) {
    u8 *v = *(u8 **)((u8 *)a + 0x68);
    Q_00349630 m[4];

    if ((u32)c >= 5) {
        qzero(out);
        return;
    }
    switch ((u32)c) {
    case 0:
        func_003C2EC0(a, 3, m);
        *(Q_00349630 *)out = m[3];
        return;
    case 1:
        *(Q_00349630 *)out = ((E_00349630 *)D_L30_001DF71C)[*(s32 *)(v + 0x104)].q;
        break;
    case 2:
        *(Q_00349630 *)out = ((E_00349630 *)D_L30_001DF71C)[*(s32 *)(v + 0x114)].q;
        break;
    case 3:
        *(Q_00349630 *)out = ((E_00349630 *)D_L30_001DF71C)[*(s32 *)(v + 0xE4)].q;
        break;
    case 4:
        *(Q_00349630 *)out = ((E_00349630 *)D_L30_001DF71C)[*(s32 *)(v + 0xF4)].q;
        break;
    }
}
/* localdecomp:end func_L30_00349630 */

INCLUDE_ASM("asm/levels", func_L30_003496D8);

/* localdecomp:start func_L30_003497B0 */
typedef struct { u8 pad0[0x34]; u16 h34; u8 pad36[0x98 - 0x36]; s32 w98; u8 pad9C[0x100 - 0x9C]; } E_003497B0;
__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DD36C, 4");
extern f32 D_L30_001DD36C;
extern void func_L30_00321070(void *, f32);
extern void func_L30_0034BC90(void *, f32, s32, s32);
extern void func_L01_004AA7E8(void *, s32);

void func_L30_003497B0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e;
    f32 k;
    s32 i;

    for (i = 2; i >= 0; i--) {
        ((s32 *)(p + 0x9C))[i] = -1;
    }
    e = D_L30_001DF71C + (*(s32 *)(p + 0xE4) << 8);
    k = D_L30_001DD36C;
    *(s32 *)(p + 0xA8) = 0;
    *(s32 *)(p + 0xAC) = 0;
    *(s32 *)(p + 0xCC) = 0;
    *(s32 *)(p + 0xD0) = 0;
    *(s32 *)(p + 0xC4) = 0;
    *(s32 *)(p + 0xC8) = 0;
    *(s32 *)(p + 0xEC) = 0;
    *(s32 *)(p + 0xF0) = 0;
    *(s32 *)(p + 0xFC) = 0;
    *(s32 *)(p + 0x100) = 0;
    func_L30_00321070(e, k);
    func_L30_00321070(D_L30_001DF71C + (*(s32 *)(p + 0xF4) << 8), D_L30_001DD36C);
    e = D_L30_001DF71C + (*(s32 *)(p + 0x104) << 8);
    *(s32 *)(p + 0x10C) = 0;
    *(s32 *)(p + 0x110) = 0;
    func_L30_0034BC90(e, -0.77f, 4, 0x3C);
    func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x108) << 8), -0.77f, 4, 0x3C);
    e = D_L30_001DF71C + (*(s32 *)(p + 0x114) << 8);
    *(s32 *)(p + 0x11C) = 0;
    *(s32 *)(p + 0x120) = 0;
    func_L30_0034BC90(e, -0.77f, 4, 0x3C);
    func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x118) << 8), -0.77f, 4, 0x3C);
    ((E_003497B0 *)D_L30_001DF71C)[*(s32 *)(p + 0x90)].h34 |= 0x41;
    ((E_003497B0 *)D_L30_001DF71C)[*(s32 *)(p + 0x90)].h34 &= 0xEFFF;
    ((E_003497B0 *)D_L30_001DF71C)[*(s32 *)(p + 0x90)].w98 = 0;
    func_L01_004AA7E8(&((E_003497B0 *)D_L30_001DF71C)[*(s32 *)(p + 0x90)], 1);
}
/* localdecomp:end func_L30_003497B0 */

/* localdecomp:start func_L30_00349968 */
s32 func_L30_00349968(u8 *a0, u32 a1, s32 a2) {
    u8 *p = *(u8 **)(a0 + 0x68);

    if (a1 >= 5) {
        return 0;
    }
    if (a1 == 0 && *(s32 *)(p + 0xD0) > 0) {
        if (a2 != 0 && *(s32 *)(p + 0xCC) != 4 && *(s32 *)(p + 0xCC) != 5 && *(s32 *)(p + 0xCC) != 6) {
            return 0;
        }
        return 1;
    }
    if (a1 == 1 && *(s32 *)(p + 0x110) > 0) {
        return 1;
    }
    if (a1 == 2 && *(s32 *)(p + 0x120) > 0) {
        return 1;
    }
    if (a1 == 3 && *(s32 *)(p + 0xF0) > 0) {
        return 1;
    }
    if (a1 == 4 && *(s32 *)(p + 0x100) > 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L30_00349968 */

/* localdecomp:start func_L30_00349A20 */
extern f32 D_L30_001DD278[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD278, 8");
extern f32 D_L30_001DD288[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD288, 8");
extern f32 D_L30_001DD298[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD298, 8");
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD1F0, 8");
extern f32 func_003824E0(f32, f32);

void func_L30_00349A20(u8 *a0, s32 a1) {
    u8 *q = *(u8 **)(a0 + 0x68);
    f32 *tbl;
    s32 n;
    s32 i;
    f32 r;

    i = 0;
    if (a0[0x20] == 3) {
        tbl = D_L30_001DD278;
    } else if (a0[0x20] == 4) {
        tbl = D_L30_001DD288;
    } else if (a0[0x20] == 5) {
        tbl = D_L30_001DD298;
    } else {
        return;
    }
    n = D_L30_001DD1F0[a0[0x20] - 3];
    r = func_003824E0(0.0f, 1.0f);
    while (tbl[i] < r) {
        r -= tbl[i];
        i++;
    }
    i++;
    if (a1 == 3) {
        *(s32 *)(q + 0xEC) = i;
        *(s32 *)(q + 0xF0) = n;
        *(s32 *)(q + 0xE8) = 0;
    } else {
        *(s32 *)(q + 0xFC) = i;
        *(s32 *)(q + 0x100) = n;
        *(s32 *)(q + 0xF8) = 0;
    }
}
/* localdecomp:end func_L30_00349A20 */

/* localdecomp:start func_L30_00349B28 */
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
__asm__(".extern D_L30_001DD1F0, 4");
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD2A8, 4");
extern f32 D_L30_001DD2A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD2B8, 4");
extern f32 D_L30_001DD2B8[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD2C8, 4");
extern f32 D_L30_001DD2C8[] __attribute__((section(".sdata")));
extern s32 D_L30_001DD2F4;

void func_L30_00349B28(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 *tbl;
    f32 r;
    s32 i = 0;

    if (a0[0x20] == 3) {
        tbl = D_L30_001DD2A8;
    } else if (a0[0x20] == 4) {
        tbl = D_L30_001DD2B8;
    } else if (a0[0x20] == 5) {
        tbl = D_L30_001DD2C8;
    } else {
        return;
    }
    *(s32 *)(p + 0xD0) = D_L30_001DD1F0[a0[0x20] - 3];
    r = func_003824E0(0.0f, 1.0f);
    while (tbl[i] < r) {
        r -= tbl[i];
        i++;
    }
    i += 4;
    *(s32 *)(p + 0xCC) = i;
    if (i == 4) {
        *(s32 *)(p + 0xC0) = func_00382498(0, 1);
    }
    if (*(s32 *)(p + 0xCC) == 6) {
        if (a0[0x43] != 1) {
            func_003C3A10(a0, 1, 0, (D_L30_001DD2F4 * 5 + 2) / 6);
        }
        *(s32 *)(p + 0xA8) = 1;
    } else {
        if (a0[0x43] != 2) {
            func_003C3A10(a0, 2, 0, (D_L30_001DD2F4 * 5 + 2) / 6);
        }
        *(s32 *)(p + 0xA8) = 0;
    }
}
/* localdecomp:end func_L30_00349B28 */

/* localdecomp:start func_L30_00349CA8 */
extern f32 func_003824E0(f32, f32);
extern void func_L30_0034BC90(void *, f32, s32, s32);
__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF71C;
__asm__(".extern D_L30_001DD1F0, 4");
extern s32 D_L30_001DD1F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD248, 4");
extern f32 D_L30_001DD248[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD258, 4");
extern f32 D_L30_001DD258[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD268, 4");
extern f32 D_L30_001DD268[] __attribute__((section(".sdata")));

void func_L30_00349CA8(u8 *a0, s32 a1) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 *tbl;
    f32 r;
    s32 v;
    s32 i = 0;

    if (a0[0x20] == 3) {
        tbl = D_L30_001DD248;
    } else if (a0[0x20] == 4) {
        tbl = D_L30_001DD258;
    } else if (a0[0x20] == 5) {
        tbl = D_L30_001DD268;
    } else {
        return;
    }
    v = D_L30_001DD1F0[a0[0x20] - 3];
    r = func_003824E0(0.0f, 1.0f);
    while (tbl[i] < r) {
        r -= tbl[i];
        i++;
    }
    i++;
    switch (i) {
    case 1:
        if (a1 == 1) {
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x104) << 8), -0.77f, 1, 0x3C);
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x108) << 8), -1.54f, 1, 0x3C);
            *(s32 *)(p + 0x10C) = i;
            *(s32 *)(p + 0x110) = v;
        } else {
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x114) << 8), -2.31f, 1, 0x3C);
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x118) << 8), -1.54f, 1, 0x3C);
            *(s32 *)(p + 0x11C) = i;
            *(s32 *)(p + 0x120) = v;
        }
        break;
    case 3:
    case 4:
        break;
    case 2:
        if (a1 == 1) {
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x104) << 8), -0.77f, 2, 0x3C);
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x108) << 8), -1.54f, 2, 0x3C);
            *(s32 *)(p + 0x10C) = i;
            *(s32 *)(p + 0x110) = v;
        } else {
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x114) << 8), -2.31f, 2, 0x3C);
            func_L30_0034BC90(D_L30_001DF71C + (*(s32 *)(p + 0x118) << 8), -1.54f, 2, 0x3C);
            *(s32 *)(p + 0x11C) = i;
            *(s32 *)(p + 0x120) = v;
        }
        break;
    }
}
/* localdecomp:end func_L30_00349CA8 */

/* localdecomp:start func_L30_00349EE8 */
extern s32 func_L30_00349968(u8 *, u32, s32);
extern void func_L30_00349B28(u8 *);
extern void func_L30_00349CA8(u8 *, s32);
extern void func_L30_00349A20(u8 *, s32);
extern f32 func_003824E0(f32, f32);
__asm__(".extern D_L30_001DD200, 4");
extern f32 D_L30_001DD200[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD218, 4");
extern f32 D_L30_001DD218[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD230, 4");
extern f32 D_L30_001DD230[] __attribute__((section(".sdata")));

s32 func_L30_00349EE8(u8 *a0) {
    f32 *tbl;
    f32 sum = 0.0f;
    f32 r;
    s32 i;
    s32 found;

    if (a0[0x20] == 3) {
        tbl = D_L30_001DD200;
    } else if (a0[0x20] == 4) {
        tbl = D_L30_001DD218;
    } else if (a0[0x20] == 5) {
        tbl = D_L30_001DD230;
    } else {
        return -1;
    }
    for (i = 0; i < 5; i++) {
        if (func_L30_00349968(a0, i, 1) == 0) {
            sum += tbl[i];
        }
    }
    r = func_003824E0(0.0f, sum);
    found = 0;
    for (i = 0; !found && i < 5; i++) {
        if (func_L30_00349968(a0, i, 1) == 0) {
            if (r < tbl[i]) {
                found = 1;
            } else {
                r -= tbl[i];
            }
        }
    }
    if (!found) {
        return -1;
    }
    i--;
    if (i == 0) {
        func_L30_00349B28(a0);
    }
    if ((u32)(i - 1) < 2) {
        func_L30_00349CA8(a0, i);
    }
    if ((u32)(i - 3) < 2) {
        func_L30_00349A20(a0, i);
    }
    return i;
}
/* localdecomp:end func_L30_00349EE8 */

/* localdecomp:start func_L30_0034A058 */
extern u8 D_L30_001D66B0;
extern void func_L30_00349630(void *, void *, float *);
extern void func_L30_00342C80(float *, u8 *, float, float);
void func_L30_0034A058(void *a, s32 unused, void *c) {
    float v[4];
    func_L30_00349630(a, c, v);
    v[2] += 0.5f;
    func_L30_00342C80(v, &D_L30_001D66B0, 0.5f, 1.0f);
}
/* localdecomp:end func_L30_0034A058 */

/* localdecomp:start func_L30_0034A0A8 */
__asm__(".extern D_L30_001DF728, 16");
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DEAB0, 4");
extern s32 D_L30_001DEAB0;

void func_L30_0034A0A8(s32 unused, s32 flag) {
    u8 *p = D_L30_001DF728;
    u8 *obj = 0;

    if (p != 0) {
        do {
            if (*(s16 *)(p + 0xAA) == 0x1B55) {
                obj = *(u8 **)(p + 0x68);
            }
            p = *(u8 **)(p + 0x28);
        } while (p != 0);
    }
    if (obj != 0) {
        if (flag != 0) {
            *(f32 *)(obj + 0x10C) = 1.0f;
        } else {
            *(s32 *)(obj + 0x10C) = 0;
        }
    }
    D_L30_001DEAB0 = flag ^ 1;
}
/* localdecomp:end func_L30_0034A0A8 */

LINKER_REMNANT("asm/levels", func_L30_0034A100);

/* localdecomp:start func_L30_0034A108 */
typedef struct { u8 pad0[0x24]; u8 *p24; u8 pad28[0x34 - 0x28]; u16 h34; u8 pad36[0x98 - 0x36]; s32 w98; u8 pad9C[0x100 - 0x9C]; } E_0034A108;
typedef struct {
    s32 w0;
    s32 w4;
    u8 pad8[0x10 - 0x8];
    s32 w10;
    f32 f14;
    f32 f18;
    s32 w1C;
    u8 pad20[0x24 - 0x20];
    s32 w24;
    s32 w28;
    f32 f2C;
    s32 w30;
    s32 w34;
} S_0034A108;

__asm__(".extern D_L30_001DF71C, 16");
extern u8 *D_L30_001DF71C;
extern u8 D_001A4C60[];
__asm__(".extern D_L30_001DD3C0, 4");
extern f32 D_L30_001DD3C0 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3C4, 4");
extern f32 D_L30_001DD3C4 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3C8, 4");
extern f32 D_L30_001DD3C8 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3CC, 4");
extern f32 D_L30_001DD3CC __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3D0, 4");
extern f32 D_L30_001DD3D0 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3D4, 4");
extern f32 D_L30_001DD3D4 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3D8, 4");
extern s32 D_L30_001DD3D8 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3E4, 4");
extern f32 D_L30_001DD3E4 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3E8, 4");
extern f32 D_L30_001DD3E8 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD3EC, 4");
extern f32 D_L30_001DD3EC __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD400, 4");
extern s32 D_L30_001DD400 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD404, 4");
extern s32 D_L30_001DD404 __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DD408, 4");
extern s32 D_L30_001DD408 __attribute__((section(".sdata")));
extern void func_L01_004AA7E8(void *, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_0038CAD0(void *);
extern f32 func_L01_004395E0(void *);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003C2880(void *);
extern void func_L30_0034ACC8(s32, s32);
extern void func_L30_0034AA20(void *);
extern void func_L30_0034A968(void *);
extern void func_L30_0034ABF8(u8 *);

void func_L30_0034A108(u8 *a0) {
    S_0034A108 *st = *(S_0034A108 **)(a0 + 0x68);
    s32 base;
    f32 t;
    f32 k;

    switch (a0[0x20]) {
    case 0:
        st->w1C = 0;
        st->w28 = 0;
        st->w34 = 0;
        st->w24 = 1;
        ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 |= 0x41;
        ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 &= 0xEFFF;
        ((E_0034A108 *)D_L30_001DF71C)[st->w0].w98 = 0;
        func_L01_004AA7E8(&((E_0034A108 *)D_L30_001DF71C)[st->w0], 1);
        ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 |= 0x41;
        ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 &= 0xEFFF;
        ((E_0034A108 *)D_L30_001DF71C)[st->w4].w98 = 0;
        func_L01_004AA7E8(&((E_0034A108 *)D_L30_001DF71C)[st->w4], 1);
        st->f2C = func_003C3D30(a0 + 0x10, 0, 0, 0.5f);
        if (a0[0x43] != 1) {
            func_003C3A10(a0, 1, 0, 0);
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        if (func_00382380(D_001A4C60, st->w10, 0) != 0) {
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 &= 0xFFBE;
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 |= *(u16 *)(((E_0034A108 *)D_L30_001DF71C)[st->w0].p24 + 0x44) & 0x1000;
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].w98 = *(s32 *)(((E_0034A108 *)D_L30_001DF71C)[st->w0].p24 + 0x10);
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 &= 0xFFBE;
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 |= *(u16 *)(((E_0034A108 *)D_L30_001DF71C)[st->w4].p24 + 0x44) & 0x1000;
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].w98 = *(s32 *)(((E_0034A108 *)D_L30_001DF71C)[st->w4].p24 + 0x10);
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            st->w34 = D_L30_001DD400;
        }
        func_L30_0034ACC8((s32)a0, 0);
        if (func_0038CAD0(&st->w34)) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            st->w30 = 0;
            st->w34 = D_L30_001DD408;
            st->w24 = 0;
            *(f32 *)(a0 + 0x48) = D_L30_001DD3D4;
            if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, 8);
            }
        }
        if (st->w30 != 0) {
            if (st->w1C == 1) {
                *(f32 *)(a0 + 0xF8) = (1.0f - (f32)st->w34 / (f32)D_L30_001DD404) * 3.1415927f;
            } else {
                *(f32 *)(a0 + 0xF8) = (f32)st->w34 / (f32)D_L30_001DD404 * 3.1415927f;
            }
        }
        if (func_0038CAD0(&st->w34)) {
            if (st->w30 == 0) {
                st->w24 = 1;
                st->w34 = D_L30_001DD404;
                st->w30 = 1;
                if (a0[0x43] != 6) {
                    func_003C3A10(a0, 6, 0, 8);
                }
            } else {
                st->w30 = 0;
                st->w1C = st->w1C == 0;
                func_L01_004450F0(a0, 4, -1);
            }
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            st->w24 = 1;
            *(f32 *)(a0 + 0x48) = D_L30_001DD3D0;
            if (a0[0x43] != (st->w1C == 1 ? 3 : 2)) {
                func_003C3A10(a0, st->w1C == 1 ? 3 : 2, 0, 8);
            }
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 5, -1);
        }
        break;
    case 5:
        base = st->w1C == 1 ? 4 : 0;
        if (func_L01_004561B8(a0)) {
            if (a0[0x43] != base + 8) {
                func_003C3A10(a0, base + 8, 0, 8);
            }
            a0[0xBC] = 0;
            *(f32 *)(a0 + 0x48) = D_L30_001DD3C4;
            st->w28 = 0;
        }
        if (a0[0x60] & 2) {
            if (a0[0xBC] == 0) {
                if (a0[0x43] != base + 10) {
                    func_003C3A10(a0, base + 10, 0, 2);
                }
                a0[0xBC] = 1;
                *(f32 *)(a0 + 0x48) = D_L30_001DD3C0;
                func_L30_0034AA20(a0);
            }
            if (a0[0xBC] == 1) {
                st->w28++;
                func_L30_0034AA20(a0);
                if (st->w28 >= D_L30_001DD3D8) {
                    if (a0[0x43] != base + 11) {
                        func_003C3A10(a0, base + 11, 0, 2);
                    }
                    a0[0xBC] = 2;
                    *(f32 *)(a0 + 0x48) = D_L30_001DD3C4;
                }
            }
            if (a0[0xBC] == 2) {
                func_L01_004450F0(a0, 6, -1);
            }
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(a0 + 0x98) = 0;
            if (a0[0x43] != 5) {
                func_003C3A10(a0, 5, 0, 4);
            }
            *(f32 *)(a0 + 0x48) = D_L30_001DD3C8;
        }
        t = func_L01_004395E0(a0);
        if (D_L30_001DD3E4 <= t && t <= D_L30_001DD3E8) {
            k = (t - D_L30_001DD3E4) / (D_L30_001DD3E8 - D_L30_001DD3E4);
            if (st->w1C == 1) {
                *(f32 *)(a0 + 0x10) = func_003C4088(st->f14, st->f18, k);
            } else {
                *(f32 *)(a0 + 0x10) = func_003C4088(st->f18, st->f14, k);
            }
            *(f32 *)(a0 + 0x18) = st->f2C + D_L30_001DD3EC * 4.0f * k * (1.0f - k);
        }
        if (D_L30_001DD3E8 < t) {
            st->w24 = 0;
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            *(f32 *)(a0 + 0x18) = st->f2C;
            *(f32 *)(a0 + 0x10) = st->w1C == 1 ? st->f18 : st->f14;
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 7:
        if (func_L01_004561B8(a0)) {
            if (a0[0x43] != 0x10) {
                func_003C3A10(a0, 0x10, 0, 8);
            }
            *(f32 *)(a0 + 0x48) = D_L30_001DD3CC;
            st->w24 = 1;
        }
        if (a0[0x60] & 2) {
            if (st->w30 == 0) {
                st->w34 = 0;
            }
            if (a0[0x43] != 6) {
                func_003C3A10(a0, 6, 0, 8);
            }
            a0[0x20] = 3;
        }
        break;
    case 8:
        if (func_L01_004561B8(a0)) {
            if (a0[0x43] != 0x11) {
                func_003C3A10(a0, 0x11, 0, 8);
            }
        }
        func_L30_0034ACC8((s32)a0, 1);
        if (a0[0x60] & 2) {
            func_L30_0034ACC8((s32)a0, 1);
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 |= 0x41;
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].h34 &= 0xEFFF;
            ((E_0034A108 *)D_L30_001DF71C)[st->w0].w98 = 0;
            func_L01_004AA7E8(&((E_0034A108 *)D_L30_001DF71C)[st->w0], 1);
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 |= 0x41;
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].h34 &= 0xEFFF;
            ((E_0034A108 *)D_L30_001DF71C)[st->w4].w98 = 0;
            func_L01_004AA7E8(&((E_0034A108 *)D_L30_001DF71C)[st->w4], 1);
            func_003C2880(a0);
            return;
        }
        break;
    }
    if (a0[0x20] != 6) {
        func_L30_0034A968(a0);
    }
    func_L30_0034ABF8(a0);
}
/* localdecomp:end func_L30_0034A108 */

/* localdecomp:start func_L30_0034A968 */
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_003D4D00(void *, s32, void *, void *, f32);
extern f32 D_L30_001DD3F0;
__asm__(".extern D_L30_001DD3F0, 4");
extern s32 D_L30_001DD3DC;
__asm__(".extern D_L30_001DD3DC, 4");

typedef struct {
    u8 pad0[0x20];
    s32 w20;
    u8 pad24[0xC];
} S_0034A968;

void func_L30_0034A968(void *arg0) {
    u8 *a;
    u8 *p;
    S_0034A968 buf;
    vu0_v4 v30;
    vu0_v4 v40;

    a = arg0;
    p = *(u8 **)(a + 0x68);
    v40 = *(vu0_v4 *)(a + 0x10);
    v30 = *(vu0_v4 *)(a + 0x10);
    v40.z += D_L30_001DD3F0;
    v30.z = *(f32 *)(p + 0x2C);
    v30.x = (*(f32 *)(p + 0x14) + *(f32 *)(p + 0x18)) * 0.5f;
    vec_sub_ba(&v30, &v30, a + 0x10);
    func_L01_00446760(&buf, a, 1, &v30, (f32)D_L30_001DD3DC);
    buf.w20 |= 1;
    func_003D4D00(&v40, 0x10, a, &buf, D_L30_001DD3F0);
}
/* localdecomp:end func_L30_0034A968 */

/* localdecomp:start func_L30_0034AA20 */
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003C2EC0(void *, s32, void *);
extern char *func_L30_0034C300(char *object, char *a1, char *a2, s32 a3, s32 a4, float f12);
extern u8 D_001A4C60[];
__asm__(".extern D_L30_001DD3E0, 4");
extern s32 D_L30_001DD3E0;
__asm__(".extern D_L30_001DD3F4, 4");
extern f32 D_L30_001DD3F4;
__asm__(".extern D_L30_001DD3F8, 4");
extern f32 D_L30_001DD3F8;
__asm__(".extern D_L30_001DD3FC, 4");
extern f32 D_L30_001DD3FC;

void func_L30_0034AA20(void *arg0) {
    u8 *a0 = (u8 *)arg0;
    u8 *st = *(u8 **)(a0 + 0x68);
    f32 v[4] __attribute__((aligned(16)));
    f32 m[16] __attribute__((aligned(16)));
    s32 col;

    qzero(v);
    if (D_L30_001DD3E0 < *(s32 *)(st + 0x20)) {
        v[0] = (*(s32 *)(st + 0x1C) == 1) ? 1.0f : -1.0f;
        col = 0xFF0000;
        v[2] = func_003824E0(-D_L30_001DD3F4, D_L30_001DD3F4);
        func_0038CF68(v, v, D_L30_001DD3FC);
    } else {
        vec_sub_ba(v, D_001A4C60, a0 + 0x10);
        col = 0xFF00;
        v[0] *= func_003824E0(1.0f - D_L30_001DD3F8, D_L30_001DD3F8 + 1.0f);
        func_0038CF68(v, v, D_L30_001DD3FC);
    }
    if (*(s32 *)(st + 0x1C) == 1) {
        func_003C2EC0(a0, 3, m);
        func_L30_0034C300((char *)a0, (char *)v, (char *)&m[12], col, col, 1.0f);
        func_003C2EC0(a0, 4, m);
        func_L30_0034C300((char *)a0, (char *)v, (char *)&m[12], col, col, 1.0f);
    } else {
        func_003C2EC0(a0, 1, m);
        func_L30_0034C300((char *)a0, (char *)v, (char *)&m[12], col, col, 1.0f);
        func_003C2EC0(a0, 2, m);
        func_L30_0034C300((char *)a0, (char *)v, (char *)&m[12], col, col, 1.0f);
    }
}
/* localdecomp:end func_L30_0034AA20 */

/* localdecomp:start func_L30_0034ABF8 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 D_L30_001DF0D8;

void func_L30_0034ABF8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p;
    u8 *q;
    s32 n;

    D_L30_001DF0D8 = 0.0f;
    p = func_L01_00447490(a0, 0x10000, 0);
    a0[0xA8] = 0xFF;
    if (*(s32 *)(st + 0x24) != 0) {
        return;
    }
    if (p == 0) {
        return;
    }
    q = *(u8 **)(p + 0x20);
    if (q != 0) {
        if (*(s16 *)(q + 0xAA) == 0x9DE) {
            return;
        }
    }
    n = *(f32 *)(p + 0x2C);
    a0[0xA8] = 0xFF;
    *(s32 *)(st + 0x20) -= n;
    D_L30_001DF0D8 = 1.0f;
    if (*(s32 *)(st + 0x20) > 0) {
        func_L01_004450F0(a0, 7, -1);
    } else {
        func_L01_004450F0(a0, 8, -1);
    }
}
/* localdecomp:end func_L30_0034ABF8 */

/* localdecomp:start func_L30_0034ACC8 */
__asm__(".extern D_L30_001DF728, 16");
extern u8 *D_L30_001DF728;
__asm__(".extern D_L30_001DEAB0, 4");
extern s32 D_L30_001DEAB0;

void func_L30_0034ACC8(s32 unused, s32 flag) {
    u8 *v = D_L30_001DF728;
    u8 *f = 0;

    if (v != 0) {
        do {
            if (*(s16 *)(v + 0xAA) == 0x1B55) {
                f = *(u8 **)(v + 0x68);
            }
            v = *(u8 **)(v + 0x28);
        } while (v != 0);
    }
    if (f != 0) {
        if (flag != 0) {
            *(f32 *)(f + 0xEC) = 1.0f;
        } else {
            *(s32 *)(f + 0xEC) = 0;
        }
    }
    D_L30_001DEAB0 = flag ^ 1;
}
/* localdecomp:end func_L30_0034ACC8 */

/* localdecomp:start func_L30_0034AD28 */
extern void func_L24_0043C3B0(u8 *, s32, s32, s32, f32, f32);
extern s32 func_L30_0034B2F0(u8 *);
extern void func_0038D308(void *, void *);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L30_0034B4A0(u8 *);
extern void func_L30_0034B538(u8 *);
extern void func_L30_0034B688(u8 *);
extern f32 func_003824E0(f32, f32);
__asm__(".extern D_001DD434, 4");
extern f32 D_001DD434;
__asm__(".extern D_L30_001DD40C, 4");
extern f32 D_L30_001DD40C;
__asm__(".extern D_L30_001DD410, 4");
extern s32 D_L30_001DD410;
__asm__(".extern D_L30_001DD414, 4");
extern f32 D_L30_001DD414;
__asm__(".extern D_L30_001DD41C, 4");
extern f32 D_L30_001DD41C;
__asm__(".extern D_L30_001DD420, 4");
extern f32 D_L30_001DD420;
__asm__(".extern D_L30_001DD428, 4");
extern s32 D_L30_001DD428;
__asm__(".extern D_L30_001DD42C, 4");
extern f32 D_L30_001DD42C;
__asm__(".extern D_L30_001DD430, 4");
extern s32 D_L30_001DD430;
__asm__(".extern D_L30_001DD438, 4");
extern s32 D_L30_001DD438;
__asm__(".extern D_L30_001DD43C, 4");
extern f32 D_L30_001DD43C;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x44 - 0x34];
    s16 h44;
    u8 pad46[0x190 - 0x46];
    s32 w190;
    s32 w194;
    f32 f198;
} St_0034AD28;

void func_L30_0034AD28(u8 *a0) {
    St_0034AD28 *st = *(St_0034AD28 **)(a0 + 0x68);
    s32 done;
    s32 h;
    s32 ok;
    s32 prev;
    s32 side;

    func_L24_0043C3B0(a0, -1, 0, 0, D_L30_001DD41C, D_L30_001DD420);
    if (func_L30_0034B2F0(a0)) {
        func_L01_004450F0(a0, 0x42, -1);
    }
    *(f32 *)(a0 + 0x48) = D_L30_001DD40C;
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    func_0038CF68(a0 + 0xD0, a0 + 0xD0, D_001DD434);
    switch (a0[0x20]) {
    case 0:
        func_L30_0034B688(a0);
        break;
    case 1:
        if (func_L01_004561B8(a0)) {
            st->w190 = D_L30_001DD430;
            if (st->w194) {
                if (a0[0x43] != 2) {
                    func_003C3A10(a0, 2, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
            } else if (a0[0x43] != 0) {
                func_003C3A10(a0, 0, 0, (D_L30_001DD410 * 5 + 2) / 6);
            }
        }
        func_L30_0034B4A0(a0);
        done = func_0038CAD0(&st->w190) != 0;
        h = st->h44 == 1;
        if (*(f32 *)(a0 + 0x10) < st->f30) {
            ok = D_L30_001DD414 > fabs_asm(*(f32 *)(a0 + 0xF8));
        } else {
            ok = D_L30_001DD414 > fabs_asm(3.1415927f - *(f32 *)(a0 + 0xF8));
        }
        if (done && h && ok) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0)) {
            prev = st->w194;
            side = st->f198 < func_003824E0(0.0f, 1.0f);
            st->w194 = side;
            if (side != prev) {
                if (side) {
                    if (a0[0x43] != 1) {
                        func_003C3A10(a0, 1, 0, (D_L30_001DD410 * 5 + 2) / 6);
                    }
                } else if (a0[0x43] != 3) {
                    func_003C3A10(a0, 3, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
            } else {
                func_L01_004450F0(a0, 3, -1);
            }
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 3, -1);
        }
        break;
    case 3:
        if (func_L01_004561B8(a0)) {
            if (st->w194) {
                if (a0[0x43] != 8) {
                    func_003C3A10(a0, 8, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
            } else if (a0[0x43] != 4) {
                func_003C3A10(a0, 4, 0, (D_L30_001DD410 * 5 + 2) / 6);
            }
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 4, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0)) {
            if (st->w194) {
                if (a0[0x43] != 9) {
                    func_003C3A10(a0, 9, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
                st->w190 = D_L30_001DD428;
            } else {
                if (a0[0x43] != 5) {
                    func_003C3A10(a0, 5, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
                st->w190 = D_L30_001DD438;
            }
        }
        if (func_0038CAD0(&st->w190)) {
            func_L01_004450F0(a0, 5, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(a0)) {
            if (st->w194) {
                if (a0[0x43] != 0xA) {
                    func_003C3A10(a0, 0xA, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
            } else if (a0[0x43] != 6) {
                func_003C3A10(a0, 6, 0, (D_L30_001DD410 * 5 + 2) / 6);
            }
        }
        if (func_L01_0044E1B8(a0, st->w194 ? D_L30_001DD42C : D_L30_001DD43C)) {
            func_L30_0034B538(a0);
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 6, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(a0)) {
            if (st->w194) {
                if (a0[0x43] != 0xB) {
                    func_003C3A10(a0, 0xB, 0, (D_L30_001DD410 * 5 + 2) / 6);
                }
            } else if (a0[0x43] != 7) {
                func_003C3A10(a0, 7, 0, (D_L30_001DD410 * 5 + 2) / 6);
            }
        }
        if (a0[0x60] & 2) {
            func_L01_004450F0(a0, 1, -1);
        }
        break;
    case 0x42:
        if (func_L01_004561B8(a0)) {
            *(s32 *)(a0 + 0x98) = 0;
            *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & ~0x1000;
            func_L01_004AA7E8(a0, 1);
        }
        break;
    }
}
/* localdecomp:end func_L30_0034AD28 */

/* localdecomp:start func_L30_0034B2F0 */
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);

s32 func_L30_0034B2F0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *e;
    f32 f;
    vu0_v4 pos;

    e = func_L01_00447490(a0, 0x10000, 0);
    func_L01_0044ABD0(a0, st + 0x180);
    if (e == 0) {
        return 0;
    }
    f = *(f32 *)(e + 0x2C);
    if (0.0f < f && a0[0x20] != 0x42) {
        *(f32 *)(st + 0x50) -= f;
        a0[0xA8] = 0xFF;
        if (*(f32 *)(st + 0x50) <= 0.0f) {
            pos = *(vu0_v4 *)(a0 + 0x10);
            pos.z += *(f32 *)(st + 0x60);
            func_L01_003303B8(&pos, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, 1.0f, 0.0f, 0.0f, 2.0f,
                              1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                              0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_003A52A0(1, 0, a0);
            return 1;
        }
        st[0x187] = 0xFF;
        func_003C4A40(a0, st + 0x180);
    }
    return 0;
}
/* localdecomp:end func_L30_0034B2F0 */

/* localdecomp:start func_L30_0034B4A0 */
extern s32 func_L01_0045BD10(u8 *, f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_001DD434, 4");
extern f32 D_001DD434;

void func_L30_0034B4A0(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x, s;
    u8 *q;

    if (*(f32 *)(p + 0x30) < *(f32 *)(a0 + 0x10)) {
        func_L01_0045BD10(a0, 3.1415927f);
    } else {
        func_L01_0045BD10(a0, 0.0f);
    }
    q = a0 + 0xD0;
    x = *(f32 *)(a0 + 0xF8);
    s = func_0038D0B0(x);
    func_0038CF68(q, q, D_001DD434 + (1.0f - D_001DD434) * __builtin_fabsf(s));
}
/* localdecomp:end func_L30_0034B4A0 */

/* localdecomp:start func_L30_0034B538 */
extern void func_003C2F58(void *, s32, void *);
extern void *func_L30_00342D98(u8 *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_0011A264(void *, s32, s32);
__asm__(".extern D_L30_001DD418, 4");
extern f32 D_L30_001DD418;
__asm__(".extern D_L30_001DD424, 4");
extern f32 D_L30_001DD424;

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0034B538;

void func_L30_0034B538(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    V_0034B538 t;
    V_0034B538 v;
    V_0034B538 dir;
    u8 *p;

    func_003C2F58(a0, 0, &v);
    v.y = *(f32 *)(a0 + 0x14);
    if (*(s32 *)(st + 0x194)) {
        v.z += D_L30_001DD424;
    }
    func_0011A264(&dir, 0, 0x10);
    if (1.5707964f < *(f32 *)(a0 + 0xF8)) {
        dir.x = -1.0f;
    } else {
        dir.x = 1.0f;
    }
    p = func_L30_00342D98(a0, &v, &dir);
    t = v;
    if (1.5707964f < *(f32 *)(a0 + 0xF8)) {
        t.x += D_L30_001DD418 * 2.1f;
    } else {
        t.x -= D_L30_001DD418 * 2.1f;
    }
    if (func_L01_003FB640(&t, 0x10, a0, D_L30_001DD418)) {
        p[0xBC] = 1;
        *(f32 *)(p + 0x10) = t.x;
    }
}
/* localdecomp:end func_L30_0034B538 */

/* localdecomp:start func_L30_0034B688 */
extern void func_L01_004450F0(void *, s32, s32);
__asm__(".extern D_L30_001DD440, 4");
__asm__(".extern D_L30_001DD444, 4");
__asm__(".extern D_L30_001DD448, 4");
extern f32 D_L30_001DD440;
extern f32 D_L30_001DD444;
extern f32 D_L30_001DD448;

typedef struct { u8 pad0[0x60]; f32 f60; u8 pad64[0xA4 - 0x64]; f32 fA4; f32 fA8; f32 fAC; } S_0034B688;

void func_L30_0034B688(u8 *a0) {
    S_0034B688 *p = *(S_0034B688 **)(a0 + 0x68);

    p->f60 = 0.75f;
    p->fA4 = D_L30_001DD440 * 0.017453292f * (0.024f * (1.0f / 60.0f));
    p->fA8 = D_L30_001DD444 * 0.017453292f * (0.024f * (1.0f / 60.0f));
    p->fAC = D_L30_001DD448 * 0.017453292f * (1.2f * (1.0f / 60.0f));
    *(u16 *)(a0 + 0x34) |= 0x100;
    func_L01_004450F0(a0, 1, -1);
}
/* localdecomp:end func_L30_0034B688 */

/* localdecomp:start func_L30_0034B720 */
extern void func_L30_0034BBC0(u8 *);
extern s32 func_L01_004561B8(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L30_0034BD28(u8 *);
extern s32 func_L30_0034B980(u8 *);
extern void func_L30_0034BA88(u8 *);
__asm__(".extern D_L30_001DD458, 4");
extern f32 D_L30_001DD458;
__asm__(".extern D_L30_001DD450, 4");
extern f32 D_L30_001DD450;
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DF2C0, 16");

void func_L30_0034B720(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    s32 anim = 2;

    func_L30_0034BBC0(a0);
    switch (a0[0x20]) {
    case 0:
        *(s32 *)(p + 0x228) = 0;
        *(f32 *)(p + 0x210) = *(f32 *)(p + 0x220);
        *(s32 *)(p + 0x218) = (*(s32 *)(p + 0x218) * 5 + 2) / 6;
        *(s32 *)(p + 0x21C) = (*(s32 *)(p + 0x21C) * 5 + 2) / 6;
        if (*(f32 *)(p + 0x224) <= 0.0f) {
            *(f32 *)(p + 0x224) = D_L30_001DD458;
        }
        if ((u32)(*(s32 *)(p + 0x214) - 1) < 0x41) {
            func_L01_004450F0(a0, *(s32 *)(p + 0x214), -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) && a0[0x43] != anim) {
            func_003C3A10(a0, anim, 0, 0);
        }
        func_L30_0034BD28(a0);
        if (func_L30_0034B980(a0)) {
            func_L30_0034BA88(a0);
        }
        break;
    case 1:
    case 3:
        if (func_L01_004561B8(a0) && a0[0x43] != anim) {
            func_003C3A10(a0, anim, 0, 0);
        }
        if (func_L30_0034B980(a0)) {
            func_L30_0034BA88(a0);
        }
        break;
    case 4:
        if (func_L01_004561B8(a0) && a0[0x43] != 4) {
            func_003C3A10(a0, 4, 0, 0);
        }
        if (a0[0x60] & 2) {
            if (a0[0x43] == 4) {
                func_003C3A10(a0, 0, 0, 0);
            } else if (a0[0x43] == 0) {
                if ((f32)*(s32 *)(p + 0x228) + D_L30_001DD450 < (f32)D_L30_001DF2C0) {
                    func_003C3A10(a0, 1, 0, 0);
                }
            } else if (a0[0x43] == 1) {
                *(f32 *)(p + 0x50) = (f32)*(s16 *)(p + 0x54);
                func_L01_004450F0(a0, *(s32 *)(p + 0x214), -1);
            }
        }
        break;
    case 0xFF:
        break;
    }
}
/* localdecomp:end func_L30_0034B720 */

/* localdecomp:start func_L30_0034B980 */
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern void func_L01_0044E850(f32, f32, void *, void *, s32);
__asm__(".extern D_L30_001DD460, 4");
extern f32 D_L30_001DD460;
__asm__(".extern D_L30_001DD45C, 4");
extern f32 D_L30_001DD45C;

s32 func_L30_0034B980(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f20;
    s32 ret = 1;
    f32 r2;

    f20 = *(f32 *)(p + 0x210) + *(f32 *)(a0 + 0xF4);
    if (func_0038D0B0(f20) < D_L30_001DD460) {
        r2 = func_0038D098(f20);
        f20 = (r2 < 0.0f) ? 3.1415927f : 0.0f;
        ret = 0;
    }
    if (func_0038D098(f20) < 0.0f) {
        *(f32 *)(p + 0x1F8) = -D_L30_001DD45C;
        *(f32 *)(p + 0x1F0) = f20 - 3.1415927f;
    } else {
        *(f32 *)(p + 0x1F8) = D_L30_001DD45C;
        *(f32 *)(p + 0x1F0) = -f20;
    }
    func_L01_0044E850(0.0432000011f, 0.432000041f, a0, p + 0x190, 1);
    return ret;
}
/* localdecomp:end func_L30_0034B980 */

/* localdecomp:start func_L30_0034BA88 */
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003C2EC0(void *, s32, void *);
extern char *func_L30_0034C300(char *object, char *a1, char *a2, s32 a3, s32 a4, float f12);
extern u8 D_001A4C60[];
extern s32 D_L30_001DF2C0;
__asm__(".extern D_L30_001DF2C0, 16");
__asm__(".extern D_L30_001DD44C, 4");
extern s32 D_L30_001DD44C;
__asm__(".extern D_L30_001DD454, 4");
extern f32 D_L30_001DD454;
__asm__(".extern D_L30_001DD464, 4");
extern f32 D_L30_001DD464;
__asm__(".extern D_L30_001DD468, 4");
extern s32 D_L30_001DD468;
__asm__(".extern D_L30_001DD46C, 4");
extern s32 D_L30_001DD46C;
__asm__(".extern D_L30_001DD470, 4");
extern s32 D_L30_001DD470;
__asm__(".extern D_L30_001DD474, 4");
extern s32 D_L30_001DD474;

typedef struct {
    u8 pad0[0x64]; u8 b64; u8 pad65[0x210 - 0x65];
    f32 f210; u8 pad214[0x218 - 0x214]; s32 w218; s32 w21C; u8 pad220[0x228 - 0x220]; s32 w228;
} P_0034BA88;

void func_L30_0034BA88(u8 *a0) {
    P_0034BA88 *p = *(P_0034BA88 **)(a0 + 0x68);
    u8 buf[0x30];
    f32 tmp[4] __attribute__((aligned(16)));
    f32 vec[4] __attribute__((aligned(16)));
    s32 t, r;

    if (D_L30_001DD454 < func_0038CF00(D_001A4C60, a0 + 0x10)) {
        return;
    }
    t = D_L30_001DF2C0;
    r = (t + p->w21C) % p->w218;
    if (r < D_L30_001DD44C) {
        r = t - r;
        if (p->w228 < r) {
            p->w228 = r;
            func_003C2EC0(a0, 2, buf);
            qzero(vec);
            vec[0] = func_0038D098(p->f210) * D_L30_001DD464;
            vec[2] = func_0038D0B0(p->f210) * D_L30_001DD464;
            if (a0[0x20] == 1) {
                func_L30_0034C300((char *)a0, (char *)vec, (char *)tmp, D_L30_001DD468, D_L30_001DD46C, p->b64);
            }
            if (a0[0x20] == 2) {
                func_L30_0034C300((char *)a0, (char *)vec, (char *)tmp, D_L30_001DD470, D_L30_001DD474, p->b64);
            }
        }
    }
}
/* localdecomp:end func_L30_0034BA88 */

/* localdecomp:start func_L30_0034BBC0 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_003C4A40(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_0034BBC0(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    u8 *p = func_L01_00447490(a0, 0x10000, 0);
    f32 f;

    func_L01_0044ABD0(a0, st + 0x180);
    if (p == 0) {
        return;
    }
    a0[0xA8] = 0xFF;
    f = *(f32 *)(p + 0x2C);
    if (0.0f < f) {
        if (a0[0x20] == 4) {
            return;
        }
        *(f32 *)(st + 0x50) = *(f32 *)(st + 0x50) - f;
        if (*(f32 *)(st + 0x50) <= 0.0f) {
            func_L01_004450F0(a0, 4, -1);
        } else {
            st[0x187] = 0xFF;
            func_003C4A40(a0, st + 0x180);
        }
    }
}
/* localdecomp:end func_L30_0034BBC0 */

/* localdecomp:start func_L30_0034BC90 */
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L30_0034BC90(void *a0, f32 a3, s32 a1, s32 a2) {
    Obj_0034BC90 *o = (Obj_0034BC90 *)a0;
    P_0034BC90 *p = (P_0034BC90 *)o->p68;
    p->f50 = (f32)p->h54;
    p->f220 = p->f210 = a3;
    p->w214 = a1;
    p->w218 = a2;
    if (o->b43 != 2) func_003C3A10(a0, 2, 0, 0);
    if ((u32)(p->w214 - 1) < 0x42 && o->b20) func_L01_004450F0(a0, p->w214, -1);
}
/* localdecomp:end func_L30_0034BC90 */

/* localdecomp:start func_L30_0034BD28 */
extern u8 D_001A4C60[];
extern f32 func_0038D160(f32, f32);

void func_L30_0034BD28(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    f32 cur;
    f32 ang;
    f32 fwd;
    f32 back;
    f32 r;

    vec_sub_ab(&d, D_001A4C60, a0 + 0x10);
    cur = *(f32 *)(p + 0x210);
    ang = func_0038D160(d.x, d.z);
    *(f32 *)(p + 0x210) = ang;
    if (cur < ang) {
        back = cur - ang + 6.2831855f;
        fwd = ang - cur;
    } else {
        fwd = ang - cur + 6.2831855f;
        back = cur - ang;
    }
    if (fwd <= back) {
        if (*(f32 *)(p + 0x224) < fwd) {
            fwd = *(f32 *)(p + 0x224);
        }
        r = fwd + cur;
        *(f32 *)(p + 0x210) = r;
        if (3.1415927f < r) {
            *(f32 *)(p + 0x210) = r - 6.2831855f;
        }
    } else {
        if (*(f32 *)(p + 0x224) < back) {
            back = *(f32 *)(p + 0x224);
        }
        r = cur - back;
        *(f32 *)(p + 0x210) = r;
        if (r < -3.1415927f) {
            *(f32 *)(p + 0x210) = r + 6.2831855f;
        }
    }
}
/* localdecomp:end func_L30_0034BD28 */
