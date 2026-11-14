#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

INCLUDE_ASM("asm/levels", func_L03_003AF848);

/* localdecomp:start func_L03_003AFC08 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC08(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 6, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 6;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC08 */

/* localdecomp:start func_L03_003AFC50 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC50(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 4, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 4;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFC50 */

/* localdecomp:start func_L03_003AFC98 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFC98(s32 arg0) {
    func_L01_00445130(arg0, 8, -1);
}
/* localdecomp:end func_L03_003AFC98 */

/* localdecomp:start func_L03_003AFCB8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCB8(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003AFCB8 */

/* localdecomp:start func_L03_003AFCD8 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003AFCD8(void *arg0) {
    void *temp_v1;

    temp_v1 = *(void **)((u8 *)arg0 + 0x68);
    if ((*(s32 *)((u8 *)temp_v1 + 0x140)) != 0) {
        func_L01_00445130((s32) arg0, 7, -1);
        return;
    }
    *(s32 *)((u8 *)temp_v1 + 0x13C) = 7;
    func_L01_00445130((s32) arg0, 3, -1);
}
/* localdecomp:end func_L03_003AFCD8 */

/* localdecomp:start func_L03_003AFD20 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad100[0x100]; u128_t v100; char pad[0x34]; int f144; } S_003AFD20;
typedef struct { void *pad[0x1A]; S_003AFD20 *p68; } T_003AFD20;
void func_L03_003AFD20(T_003AFD20 *a, u128_t *b) {
    S_003AFD20 *s = a->p68;
    if (b == 0) { s->f144 = 0; return; }
    s->f144 = 1;
    s->v100 = b[1];
}
/* localdecomp:end func_L03_003AFD20 */

/* localdecomp:start func_L03_003AFD48 */
typedef struct { u8 pad[0x31]; u8 f31; u8 pad32[2]; u16 f34; u8 pad36[0x98 - 0x36]; int f98; } S_003AFD48;
extern u8 D_001426E0[];
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
extern s32 D_00142C40[];
__asm__(".extern D_00142C40, 16");
extern u8 D_00142CC2[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
void func_L03_003B0ED8(int, int);
void func_L03_003AFD48(void *arg0) {
    S_003AFD48 *p = (S_003AFD48 *)arg0;
    u8 *t = D_001426E0;
    u8 *q = *(u8 **)((u8 *)arg0 + 0x68);
    S_003AFD48 *e;
    unsigned long w;
    D_001DE858_sda = 0x3F;
    if (t[0x20] != 0) {
        func_L03_003B0ED8(0, 0);
        p->f31 = 0;
        p->f34 |= 1;
        p->f98 = 0;
    }
    if (t[0x3D] != 0 && t[0x85] == 0) {
        func_L03_003B0ED8(4, 0);
    }
    w = D_00142C40[0];
    if (((w >> 1) & 1) == 1) {
        e = (S_003AFD48 *)(D_L03_001DF99C + *(int *)(q + 0x16C) * 256);
        func_L03_003B0ED8(3, 0);
        e->f98 = 0;
        e->f34 |= 3;
        e->f31 = 0;
    }
    if (D_00142CC2[0] != 0) {
        e = (S_003AFD48 *)(D_L03_001DF99C + *(int *)(q + 0x168) * 256);
        func_L03_003B0ED8(2, 0);
        e->f31 = 0;
        e->f34 |= 1;
        e->f98 = 0;
    }
}
/* localdecomp:end func_L03_003AFD48 */

/* localdecomp:start func_L03_003AFE60 */
typedef struct { char p0[0x24]; int f24; char p28[0x44]; int f6C; char p70[0x24]; int f94; } S_003AFE60;
extern S_003AFE60 D_001CCFD0_003AFE60;
extern int D_L03_001DF99C_003AFE60;
__asm__(".extern D_L03_001DF99C_003AFE60, 16");
int func_L01_004BA800(void *);
void func_003A2B68(int, int);
int func_L03_003AFE60(void *a, int b, int c) {
    struct { char pad[0x160]; int arr[1]; } *p = *(void **)((char *)a + 0x68);
    S_003AFE60 *d;
    if (func_L01_004BA800(a) == 0) {
        d = &D_001CCFD0_003AFE60;
        if (d->f6C == 0 && d->f24 == -1 && d->f94 == 0) {
            if (c == -1) {
                func_003A2B68((b & 0x3FFF) + 0x7D0, 0);
            } else {
                func_003A2B68(b + 0x7D0, D_L03_001DF99C_003AFE60 + (p->arr[c] << 8));
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L03_003AFE60 */

/* localdecomp:start func_L03_003AFF18 */
extern S_001CCFD0_003AFF18 D_001CCFD0;
void func_003A1798(void);

void func_L03_003AFF18(void) {
    if (D_001CCFD0.f76 == 0 && D_001CCFD0.f9E == 3 && D_001CCFD0.f98 < 0x1B58) {
        func_003A1798();
    }
}
/* localdecomp:end func_L03_003AFF18 */

/* localdecomp:start func_L03_003AFF68 */
typedef struct { char pad[4]; int f4; } S_003AFF68_b;
typedef struct { char pad[0x68]; S_003AFF68_b *f68; } S_003AFF68_c;
typedef struct { char pad[0x15C]; int f15C; } S_003AFF68_d;
typedef struct { char pad[0x20]; unsigned char f20; char pad2[0x47]; S_003AFF68_d *f68; } S_003AFF68_a;
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");

int func_L03_003AFF68(S_003AFF68_a *a, int x) {
    S_003AFF68_a *p = a;
    S_003AFF68_c *c;
    S_003AFF68_d *d = p->f68;
    if (x != 0) return 1;
    c = (S_003AFF68_c *)(D_L03_001DF99C + d->f15C * 256);
    if (c->f68->f4 == 0) return 0;
    return (unsigned)(p->f20 - 4) < 4;
}
/* localdecomp:end func_L03_003AFF68 */

/* localdecomp:start func_L03_003AFFB8 */
typedef struct { char pad[0x160]; int f160[8]; } U_003AFFB8;
typedef struct { void *pad[0x1A]; U_003AFFB8 *p68; } T_003AFFB8;
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void (*D_L03_002BA5F8[])(char *, int);
void func_L03_003AFCB8_003AFFB8();
void func_L03_003AFC08_003AFFB8();
void func_L03_003AFFB8(T_003AFFB8 *a, unsigned int i, unsigned int j) {
    U_003AFFB8 *s = a->p68;
    int k;
    void (*fn)(char *, int);
    if (i >= 7) return;

    if (((D_001DE858_sda >> i) ^ 1) & 1) return;
    if (j >= 6) return;
    if ((int)j >= 4) {
        if (i == 0) {
            if (j == 4) { func_L03_003AFCB8_003AFFB8(a, 0); return; }
            if (j == 5) { func_L03_003AFC08_003AFFB8(a, 0); return; }
            return;
        }
        j -= 2;
    }
    k = 20;
    fn = *(void (**)(char *, int))((char *)D_L03_002BA5F8 + j * 4 + i * k);
    if (fn) fn(D_L03_001DF99C + (s->f160[i] << 8), 0);
}
/* localdecomp:end func_L03_003AFFB8 */

INCLUDE_ASM("asm/levels", func_L03_003B0088);

INCLUDE_ASM("asm/levels", func_L03_003B0140);

/* localdecomp:start func_L03_003B0238 */
extern int D_001DE858_sda;
__asm__(".extern D_001DE858_sda, 4");

int func_L03_003B0238(void) {
    int i;
    int cnt;
    int a, b, n;
    cnt = 0;
    for (i = 0; i < 6; i++) {
        cnt += (D_001DE858_sda >> i) & 1;
    }
    b = D_001DE858_sda & 2;
    a = D_001DE858_sda & 1;
    n = a + (b != 0);
    a = cnt - n;
    if (n == 0) {
        return 0;
    }
    return a >= 2;
}
/* localdecomp:end func_L03_003B0238 */

/* localdecomp:start func_L03_003B0290 */
typedef struct { u8 pad0[0x128]; int f128; int f12C; int f130; int f134; int f138; u8 pad13C[0x190-0x13C]; int f190; int f194; int f198; int f19C; } S_003B0290;
typedef struct { u8 pad0[0x24]; int f24; u8 pad28[0x6C-0x28]; int f6C; u8 pad70[0x94-0x70]; int f94; } D_003B0290;
typedef struct { u8 pad[0x68]; S_003B0290 *p; } A_003B0290;
extern char D_001A4C60_003B0290[];
extern D_003B0290 D_001CCFD0_003B0290;
int func_00382380();
int func_00382498();
void func_0038CAD0();
int func_L03_003B0238_003B0290();
void func_L03_003B0760_003B0290();
int func_L03_003B0810_003B0290();
void func_L03_003B0140_003B0290();
void func_L03_003AFFB8_003B0290();
void func_L03_003B0088_003B0290();
int func_L03_003AFF68_003B0290();
int func_L03_003AFE60_003B0290();
void func_L03_003AFF18_003B0290();

void func_L03_003B0290(A_003B0290 *a) {
    S_003B0290 *s = a->p;
    if (func_00382380(D_001A4C60_003B0290, s->f138, 0) == 0) {
        if (s->f130 != 0) {
            s->f130 = 7;
        }
        return;
    }
    if (s->f130 != 0) {
        if (func_L03_003B0238_003B0290() == 0) {
            return;
        }
    }
    switch (s->f130) {
    case 0:
        s->f134 = 0xFA;
        func_L03_003B0760_003B0290(a);
        s->f130 = 1;
    case 1:
        if (func_L03_003B0810_003B0290(a) != 0) {
            s->f130 = 2;
        }
        break;
    case 2:
        if (s->f134 == 0) {
            func_L03_003B0140_003B0290(a, s->f128, s->f12C);
            func_L03_003AFFB8_003B0290(a, s->f128, 0);
            func_L03_003B0088_003B0290(a, s->f128, s->f12C);
            if (s->f12C == 0) {
                func_L03_003B0140_003B0290(a, 0, s->f128);
            }
            s->f130 = 3;
        }
        break;
    case 3:
        if (func_L03_003AFF68_003B0290(a, s->f128) != 0) {
            if (func_L03_003AFE60_003B0290(a, s->f190, s->f128) != 0) {
                s->f130 = 4;
            }
        }
        break;
    case 4:
        if (s->f134 == 0) {
            if (func_L03_003AFE60_003B0290(a, s->f194, s->f12C) != 0) {
                func_L03_003B0140_003B0290(a, s->f12C, s->f128);
                func_L03_003AFFB8_003B0290(a, s->f128, 5);
                func_L03_003AFFB8_003B0290(a, s->f12C, 0);
                func_L03_003B0088_003B0290(a, s->f12C, s->f128);
                s->f130 = 5;
            }
        }
        break;
    case 5:
        if (s->f134 == 0) {
            if (func_L03_003AFE60_003B0290(a, s->f198, s->f128) != 0) {
                func_L03_003AFFB8_003B0290(a, s->f128, 4);
                func_L03_003AFFB8_003B0290(a, s->f12C, 1);
                s->f130 = 6;
            }
        }
        break;
    case 6:
        if (s->f134 == 0) {
            if (func_L03_003AFE60_003B0290(a, s->f19C, s->f12C) != 0) {
                func_L03_003AFFB8_003B0290(a, s->f128, 1);
                func_L03_003AFFB8_003B0290(a, s->f12C, 2);
                s->f130 = 7;
            }
        }
        break;
    case 7:
        if (s->f134 == 0) {
            if (D_001CCFD0_003B0290.f6C == 0 && D_001CCFD0_003B0290.f24 == -1 && D_001CCFD0_003B0290.f94 == 0) {
                int r = func_00382498(300, 700);
                s->f130 = 1;
                s->f134 = (r * 5 + 2) / 6;
                func_L03_003AFFB8_003B0290(a, s->f128, 3);
                func_L03_003AFFB8_003B0290(a, s->f12C, 3);
                func_L03_003B0088_003B0290(a, s->f128, -1);
                func_L03_003B0088_003B0290(a, s->f12C, -1);
                func_L03_003B0140_003B0290(a, s->f128, -1);
                func_L03_003B0140_003B0290(a, s->f12C, -1);
            }
        }
        break;
    }
    func_0038CAD0(&s->f134);
    func_L03_003AFF18_003B0290();
}
/* localdecomp:end func_L03_003B0290 */

/* localdecomp:start func_L03_003B05B0 */
s32 func_L03_003B05B0(s32 *a, s32 n) {
    s32 v = a[n];
    s32 i;
    for (i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = v;
    return v;
}
/* localdecomp:end func_L03_003B05B0 */

/* localdecomp:start func_L03_003B05F0 */
s32 func_00382468(s32);

void func_L03_003B05F0(s32 arg0, s32 arg1) {
    s32 *temp_s0_2;
    s32 *temp_v0;
    s32 temp_a0;
    s32 temp_s0;
    s32 var_s1;

    if (arg1 > 0) {
        var_s1 = arg1;
        do {
            var_s1 -= 1;
            temp_s0 = func_00382468(arg1);
            temp_v0 = (func_00382468(arg1) * 4) + arg0;
            temp_s0_2 = (temp_s0 * 4) + arg0;
            temp_a0 = *temp_s0_2;
            *temp_s0_2 = *temp_v0;
            *temp_v0 = temp_a0;
        } while (var_s1 != 0);
    }
}
/* localdecomp:end func_L03_003B05F0 */

/* localdecomp:start func_L03_003B0670 */
s32 func_L03_003B05B0(s32 *a, s32 n);
s32 func_L03_003B0670(s32 *a, s32 n, s32 *b, s32 m, s32 k) {
    s32 i, j, v;
    for (i = n - 1; i >= 0; i--) {
        v = a[i];
        for (j = 0; j < m; j++) {
            if (v == b[j]) {
                if (k-- <= 0) {
                    return func_L03_003B05B0(a, i);
                }
            }
        }
    }
    return -1;
}
/* localdecomp:end func_L03_003B0670 */

/* localdecomp:start func_L03_003B06F0 */
s32 func_L03_003B05B0(s32 *a, s32 n);
s32 func_L03_003B06F0(s32 *a, s32 n, s32 lo, s32 hi, s32 skip) {
    s32 i;
    for (i = n - 1; i >= 0; i--) {
        if (a[i] >= lo && a[i] <= hi) {
            if (skip-- <= 0) {
                return func_L03_003B05B0(a, i);
            }
        }
    }
    return -1;
}
/* localdecomp:end func_L03_003B06F0 */

/* localdecomp:start func_L03_003B0760 */
extern s32 D_L03_002A2430[];
extern s32 D_L03_001DE830;
extern s32 D_L03_001DE840;
void func_L03_003B05F0(s32, s32);

void func_L03_003B0760(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 off;
    s32 *q;
    s32 *base;
    s32 m = 0x78;
    s32 n = 0x78;

    base = D_L03_002A2430;
    i = 0;
    do {
        off = i * n;
        j = i + 1;
        q = (s32 *)(off + (s32)base);
        q += 29;
        for (k = 0x1d; k >= 0; k--) {
            *q = k;
            q--;
        }
        func_L03_003B05F0((s32)((u8 *)base + i * m), 30);
        i = j;
    } while (i < 6);
    func_L03_003B05F0((s32)&D_L03_001DE830, 4);
    func_L03_003B05F0((s32)&D_L03_001DE840, 6);
}
/* localdecomp:end func_L03_003B0760 */

INCLUDE_ASM("asm/levels", func_L03_003B0810);

/* localdecomp:start func_L03_003B0ED8 */
extern s32 D_L03_001DE858;

void func_L03_003B0ED8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        D_L03_001DE858 |= 1 << arg0;
        return;
    }
    D_L03_001DE858 &= ~(1 << arg0);
}
/* localdecomp:end func_L03_003B0ED8 */
