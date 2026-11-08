#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

INCLUDE_ASM("asm/levels", func_L03_0032C3A8);

/* localdecomp:start func_L03_0032C870 */
extern s32 D_001DD118_sda;
__asm__(".extern D_001DD118_sda, 4");
s32 *func_L03_0032C870(void *unused, s32 a1, s32 *out) {
    if (a1 == 0) {
        *out = 16;
        return &D_001DD118_sda;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C870 */

/* localdecomp:start func_L03_0032C890 */
extern u8 D_001DD10A_sda;
__asm__(".extern D_001DD10A_sda, 1");
extern void *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern u32 D_001A7F70[];
__asm__(".extern D_001A7F70, 16");
extern u32 D_001D545C;
__asm__(".extern D_001D545C, 16");
void func_L01_0041A5B0(s32 a, s32 b);
void func_L03_0032CF78(void *a, s32 b);

void func_L03_0032C890(s32 a, u8 b) {
    D_001DD10A_sda = b;
    if (a == 0x7F) {
        if ((D_001A7F70[0] & (1 << D_001D545C)) == 0) {
            func_L01_0041A5B0(0xB79, 0x1C);
        }
    }
    func_L03_0032CF78(D_001DD104_sda, a);
}
/* localdecomp:end func_L03_0032C890 */

/* localdecomp:start func_L03_0032C8F8 */
extern u8 D_L03_001DD10A;

s32 func_L03_0032C8F8(void) {
    if (D_L03_001DD10A != 0) {
        D_L03_001DD10A = 0;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L03_0032C8F8 */

INCLUDE_ASM("asm/levels", func_L03_0032C918);

INCLUDE_ASM("asm/levels", func_L03_0032CBD8);

INCLUDE_ASM("asm/levels", func_L03_0032CE38);

INCLUDE_ASM("asm/levels", func_L03_0032CED0);

/* localdecomp:start func_L03_0032CF78 */
typedef struct S_0032CF78 { char pad[0xD0]; int idx; } S_0032CF78;
extern char *D_L03_001DFA80;
__asm__(".extern D_L03_001DFA80, 16");
void func_L01_004F50C8(void *dst, void *src, int n, int m);
s32 func_L03_0032F670(s32 arg0);
void func_L03_0032CFE8(void *a, s32 b);
void func_L03_0032CF78(void *a, s32 b) {
    char *p = D_L03_001DFA80 + ((S_0032CF78 *)*(void **)((char *)a + 0x68))->idx * 128;
    func_L01_004F50C8(p + 0x30, p + 0x70, 0x74, 1);
    func_L03_0032CFE8(a, func_L03_0032F670(b));
}
/* localdecomp:end func_L03_0032CF78 */

/* localdecomp:start func_L03_0032CFE8 */
typedef struct S_0032CFE8 {
    char pad0[0x68];
    void *p68;
} S_0032CFE8;
typedef struct S_0032CFE8_p {
    char pad[0xCC]; s32 fCC; char padD0[4]; s32 fD4; char padD8[0x14];
    s32 fEC; u8 fF0; u8 fF1; u16 fF2; u8 fF4; char padF5[3]; s32 fF8;
    char padFC[0x10]; u16 f10C;
} S_0032CFE8_p;
typedef struct E_0032CFE8 { char pad[0x14]; s32 f14; s32 f18; char pad2[0xC]; } E_0032CFE8;
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");
extern u8 D_00142CAB[];
extern char *D_L03_001DFA80;
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
__asm__(".extern D_L03_001DFA80, 16");
extern E_0032CFE8 D_L03_002AE4D0_0032CFE8[];
extern u8 D_00142CA0[];
extern u8 D_001427F0[];
extern u8 D_001427C3[];
extern u8 D_001427B6[];
extern u8 D_00142D40[];
extern s32 D_00142668[];
extern u8 D_001A4BE0[];
__asm__(".extern D_001A4BE0, 16");
void func_L01_00419188(s32);
void func_L03_003A1C60();
void func_L01_004A3610();
void func_L01_004F50C8();
void func_L01_004450F0();
void func_L01_004C94B0();
void func_0039EF28();
void func_L01_005003D0();
void func_L01_003EB5E0();
void func_L01_00459AF8();
void func_L03_0032CFE8(void *arg0, s32 b) {
    S_0032CFE8 *a = arg0;
    char buf[0x20];
    S_0032CFE8_p *s;
    u16 *h;
    h = (u16 *)D_001CCFD0;
    s = a->p68;
    if ((u16)(h[0x76/2] - 6) >= 2) h[0x76/2] = 5;
    if ((u16)(h[0x9E/2] - 6) >= 2) h[0x9E/2] = 5;
    if (b == 0) {
        if (D_00142CAB[0] == 0) {
            func_L01_00419188(11);
            func_L01_00419188(20);
        }
        func_L03_003A1C60(D_L03_001DF99C + (s->fCC << 8), buf, buf + 16);
        func_L01_004A3610(buf, buf + 16);
        {
            char *t = D_L03_001DFA80 + (s->fD4 << 7);
            func_L01_004F50C8(t + 0x30, t + 0x70, 0, 1);
        }
        func_L01_004450F0(a, 1, -1);
    } else {
        s32 small;
        u8 *q;
        E_0032CFE8 *e = &D_L03_002AE4D0_0032CFE8[b];
        s->fF1 = b;
        s->fEC = -1;
        if (e->f14 != -1) s->fEC = (e->f14 * 5 + 2) / 6;
        small = b < 9;
        if (e->f18 != -1) {
            u8 *flags = D_00142CA0;
            if (flags[0x16] != 0) {
                u8 c = D_001427F0[0x58];
                *(s32 *)(D_001427F0 + 0x58) = 0;
                D_001427C3[0] = c + 1;
                func_L01_004C94B0();
            }
            if (!small && flags[e->f18] == 0) {
                flags[e->f18] = 1;
                D_00142D40[e->f18] = 1;
                func_0039EF28();
                D_001427B6[0] = e->f18;
            }
        }
        {
            q = D_001A4BE0;
            *(s32 *)(q + 0x2850) = D_00142668[0];
        }
        func_L01_005003D0(0, 1);
        func_L01_003EB5E0(0, 2);
        s->fF0 = 0; s->fF4 = 0; s->fF8 = 0; s->f10C = 0;
        if (small) func_L01_004A3610(q + 0x80, q + 0x90);
        func_L01_00459AF8();
        s->fF2 = 0x11;
        func_L01_004450F0(a, 4, -1);
    }
}
/* localdecomp:end func_L03_0032CFE8 */

/* localdecomp:start func_L03_0032D228 */
extern u8 D_001426E0[];
extern s32 D_00142848[];
extern u8 D_001A74A9[];
s32 func_L01_004AAC98(s32, s32, s32, s32);
void func_L01_004450F0(s32, s32, s32);
void func_L01_003F1760(void);

void func_L03_0032D228(u8 *a0) {
    S_Foo_0032D228 *s = *(S_Foo_0032D228 **)(a0 + 0x68);
    u8 *b;
    s32 v;
    u32 w;

    if (s->f4 != 0) {
        func_L01_004AAC98(8, 0, (s32) a0, 0x1936);
    } else {
        s->f108 = 0;
        func_L01_004AAC98(9, 0, (s32) a0, 0x1936);
    }
    b = D_001426E0;
    v = b[0xE3];
    w = v;
    if (v != 0) {
        s32 *d = D_00142848;
        v = 0;
        b[0xE3] = 0;
        do {
            *d = w - 1;
        } while (0);
    }
    D_001A74A9[0] = 0;
    func_L01_003F1760();
    s->f2 = 0xC8;
    func_L01_004450F0((s32) a0, 9, -1);
}
/* localdecomp:end func_L03_0032D228 */

/* localdecomp:start func_L03_0032D2D8 */
extern s32 func_L03_0032D348(void *p, s32 i);

s32 func_L03_0032D2D8(void *p) {
    s32 i = 0;
    s32 r = 0;
    s32 one = 1;

    do {
        s32 v = func_L03_0032D348(p, i);
        i++;
        if (v != 0) {
            r = one;
        }
    } while (i < 3);
    return r;
}
/* localdecomp:end func_L03_0032D2D8 */

INCLUDE_ASM("asm/levels", func_L03_0032D348);

/* localdecomp:start func_L03_0032D598 */
void *func_L03_0032F6A8();

s32 func_L03_0032D598(void *arg0, u8 *arg1) {
    S_0032D598 *tbl;
    s32 idx;

    arg1 = func_L03_0032F6A8(arg1);
    if (arg1[0x1C] == 1 || arg1[0x1C] == 3) {
        return 1;
    }
    if (arg0 != 0) {
        if (*(s16 *)((u8 *)arg0 + 0xAA) == 0x1936) {
            tbl = *(S_0032D598 **)((u8 *)arg0 + 0x68);
            idx = arg1[0x1D];
            if (tbl->cnt[idx] > 0) {
                goto body;
            }
        }
    }
    return 0;
body:
    arg1[0x1C] = 1;
    {
        s32 j = arg1[0x1D];
        tbl->cnt[j] = tbl->cnt[j] - 1;
    }
    return 1;
}
/* localdecomp:end func_L03_0032D598 */

/* localdecomp:start func_L03_0032D640 */
typedef struct S_0032D640 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D640;

void *func_L03_0032F6A8();

void func_L03_0032D640(void *arg0, void *arg1) {
    u8 *p;
    if (arg0 != 0) {
        if (*(s16 *)((u8 *)arg0 + 0xAA) == 0x1936) {
            p = func_L03_0032F6A8(arg1);
            if (p[0x1C] != 1) {
                p[0x1C] = 0;
            } else {
                S_0032D640 *tbl = *(S_0032D640 **)((u8 *)arg0 + 0x68);
                tbl->cnt[p[0x1D]]++;
                p[0x1C] = 0;
            }
        }
    }
}
/* localdecomp:end func_L03_0032D640 */

/* localdecomp:start func_L03_0032D6B8 */
typedef struct S_0032D6B8 {
    char pad0[0xC];
    struct S_0032D6B8 *tgt;
    f32 f10;
    f32 f14;
    char pad1[0x1C - 0x18];
    u8 t1C;
} S_0032D6B8;
typedef struct S_0032D6B8b {
    char pad0[0x10];
    f32 f10;
    f32 f14;
    char pad1[0x21 - 0x18];
    u8 idx;
    char pad2[0xAA - 0x22];
    short hAA;
} S_0032D6B8b;
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
S_0032D6B8 *func_L03_0032F6A8_func_L03_0032D6B8();
f32 func_L03_0032FB70(f32 a);
f32 func_0038D160(f32 a, f32 b);
f32 func_0038DAB8(f32 a, f32 b);

void func_L03_0032D6B8(S_0032D6B8b *a) {
    S_0032D6B8 *p;
    S_0032D6B8 *q;
    S_0032D6B8b *buf;
    short *cur;
    f32 mn, mx, base, d, v, w;
    p = func_L03_0032F6A8_func_L03_0032D6B8(a);
    mn = 100.0f;
    mx = mn;
    if (p->tgt != 0) {
        p->f10 = func_0038D160(a->f10 - p->tgt->f10, a->f14 - p->tgt->f14);
        base = func_L03_0032FB70(p->f10);
        if (a->idx == 0xFF) {
            goto same;
        }
        cur = (short *)D_L03_0021C620[a->idx];
        for (; a->idx != 0xFF && D_001DF9D8_sda >= a->idx && cur != 0 &&
               (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[a->idx]); cur++) {
            buf = (S_0032D6B8b *)(D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8));
            if (buf == 0) break;
            if (buf == a) continue;
            if (buf->hAA != a->hAA) continue;
            q = func_L03_0032F6A8_func_L03_0032D6B8(buf);
            if (p->tgt != q->tgt) continue;
            if (p->t1C != q->t1C) continue;
            d = base - func_L03_0032FB70(q->f10);
            v = func_L03_0032FB70(d);
            w = func_L03_0032FB70(-d);
            if (v < mn) mn = v;
            if (w < mx) mx = w;
        }
        if (10.0f < mn) goto same;
        p->f14 = func_0038DAB8(p->f10, (mx - mn) * 0.5f);
        return;
same:
        p->f14 = p->f10;
    }
}
/* localdecomp:end func_L03_0032D6B8 */

/* localdecomp:start func_L03_0032D8C0 */
typedef struct S_0032D8C0 {
    char pad0[0x1A];
    short h1A;
    u8 t1C;
} S_0032D8C0;
typedef struct S_0032D8C0b {
    char pad0[0x20];
    u8 f20;
    u8 idx;
    char pad1[0xAA - 0x22];
    short hAA;
} S_0032D8C0b;
extern int D_L03_0021C620[];
extern char *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern int D_001DF9D8_sda;
__asm__(".extern D_001DF9D8_sda, 4");
void *func_L03_0032F6A8();

int func_L03_0032D8C0(S_0032D8C0b *a) {
    S_0032D8C0 *p;
    short *cur;
    int best;
    p = func_L03_0032F6A8(a);
    if ((u8)(p->t1C - 2) < 2) return -1;
    if (p->h1A != -1) return p->h1A;
    cur = (short *)D_L03_0021C620[a->idx];
    best = -1;
    for (; a->idx != 0xFF && D_001DF9D8_sda >= a->idx && cur != 0 &&
           (cur[-1] >= 0 || cur == (short *)D_L03_0021C620[a->idx]); cur++) {
        S_0032D8C0b *buf = (S_0032D8C0b *)(D_L03_001DF99C + ((*(unsigned short *)cur & 0x7FFF) << 8));
        if (buf == 0) return best + 1;
        if (buf == a) continue;
        if (buf->hAA != a->hAA) continue;
        if (buf->f20 == 1) continue;
        p = func_L03_0032F6A8();
        if (p->t1C == 1) {
            if (best < p->h1A) best = p->h1A;
        }
    }
    return best + 1;
}
/* localdecomp:end func_L03_0032D8C0 */
