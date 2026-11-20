#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C25D8();
typedef struct { u8 pad[6]; u8 f6; u8 pad7[5]; u8 fC; u8 padD[0x48 - 0xD]; void *f48[1]; } T_3A1870;
typedef struct {
    u8 pad[0x24]; T_3A1870 *f24; u8 pad28[0x32 - 0x28]; s16 f32; u16 f34; u8 pad36[2];
    long f38; u8 pad40[2]; u8 f42; u8 f43; u8 pad44[0x62 - 0x44]; u8 f62; u8 f63; u8 pad64[4];
    u8 *f68; u8 pad6C[0x98 - 0x6C]; s32 f98; u8 pad9C[0xAA - 0x9C]; s16 fAA;
} O_3A1870;
extern void func_003C25D8(O_3A1870 *, s32);
extern u32 func_003C2948(s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 3C0CA0.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003C2880(s32 p);
typedef int u128_t __attribute__((mode(TI)));
extern void func_003C2DC0(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003C2EC0();
extern void func_003C2DC0();
extern void func_003C2D88();
extern void func_003C29B0();
extern u32 D_001DA49C;
extern u32 D_001DA4A0;
extern s32 D_001D9D00;
extern void func_0038CB78();

/* localdecomp:start func_003C25D8 */
typedef struct { u8 p0[0x10]; u8 b10; s8 b11; } R_3C25D8;
typedef struct {
    u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24;
    u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; R_3C25D8 *w48;
} S_3C25D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3C25D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34;
    s16 h36; long d38; u8 p40[8]; f32 f48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64;
    u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E;
    u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA;
    s32 wAC; u8 pB0[0xD]; u8 bBD; u8 pBE[0x42];
} P_3C25D8;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DD190[];
extern s32 D_002DAB00[];
extern S_3C25D8 *D_002DA740_003C25D8[];
extern u32 D_001DA49C;
__asm__(".extern D_001DA49C, 16");
void func_003C25D8(O_3A1870 *arg0, s32 idx) {
    P_3C25D8 *p = (P_3C25D8 *)arg0;
    S_3C25D8 *s;
    u8 c;
    func_0038CB78(p, 0, 0x100);
    p->b22 = D_002DB190[idx];
    c = p->b22;
    p->b23 = 0x80;
    p->bA8 = 0xFF;
    p->b21 = 0xFF;
    p->b61 = 0xFF;
    p->b62 = 0xFF;
    p->d38 = 0x40404000000000;
    p->h36 = 0x7F80;
    p->wAC = ((s32)((u32)p - D_001DA49C) >> 8) << 16;
    p->hAA = idx;
    p->b6E = 0;
    p->b6C = 0xFF;
    p->bA4 = 0x7F;
    p->bA6 = 0x80;
    p->b6D = 0xFF;
    p->bA5 = 0x7F;
    p->bA7 = 0x80;
    if (D_002DAFB0[c] != idx) {
        p->h34 |= 5;
        p->w24 = 0;
        p->w98 = 0;
        p->w64 = D_002DD190[p->b22];
        if (p->w64 == 0) p->h34 |= 2;
        return;
    }
    p->w64 = D_002DAB00[c];
    if (p->w64 == 0) p->h34 |= 2;
    s = D_002DA740_003C25D8[p->b22];
    p->w24 = s;
    p->b62 = s->bE;
    p->h34 |= s->h44;
    p->w98 = s->w10;
    p->f2C = s->f24;
    p->f48 = 1.0f;
    p->f4C = 1.0f;
    if (s->w40) {
        p->h34 |= 0x10;
        p->w78 = s->w40;
    }
    if (p->w24->bF) {
        p->b6F = 0x18;
        p->h34 |= 0x400;
        p->w70 = 0;
        p->w74 = 0;
        p->bBD = 0;
    }
    if (p->w24->b6) p->b63 = 0x18;
    if (p->w24->w48) {
        func_003C29B0(p);
        if (p->w24->w48->b10 >= 2) p->h34 &= ~2;
        if (p->w24->bC == 1) {
            if (p->w24->w48->b10 < 2) {
                p->f48 = 0.0f;
                if (p->w24->w48->b11 < 0) p->h34 |= 0x40;
            } else if (p->w64 == 0) {
                p->f48 = 0.8333333f;
            }
        }
    }
    p->b7E |= p->w24->b47;
}
/* localdecomp:end func_003C25D8 */

typedef struct { u8 p0[0x6]; u8 b6; u8 p7[5]; u8 bC; u8 pD; u8 bE; u8 bF; s32 w10; u8 p14[0x10]; f32 f24; u8 p28[0x18]; s32 w40; u16 h44; u8 p46; u8 b47; struct { u8 p[0x10]; u8 b10; s8 b11; } *w48; } S_3BD0D8;
typedef struct {
    u8 p0[0x21]; u8 b21; u8 b22; u8 b23; S_3BD0D8 *w24; u8 p28[4]; f32 f2C; u8 p30[4]; u16 h34; s16 h36; u8 d38[8]; u8 p40[8]; s32 w48; f32 f4C; u8 p50[0x11]; u8 b61; u8 b62; u8 b63; s32 w64; u8 p68[4]; u8 b6C; u8 b6D; u8 b6E; u8 b6F; s32 w70; s32 w74; s32 w78; u8 p7C[2]; u8 b7E; u8 p7F[0x19]; s32 w98; u8 p9C[8]; u8 bA4; u8 bA5; u8 bA6; u8 bA7; u8 bA8; u8 pA9; s16 hAA; s32 wAC; u8 pB0[0xD]; u8 bBD;
} P_3BD0D8;
extern u8 D_002DB190[];
extern s16 D_002DAFB0[];
extern s32 D_002DD190[];
extern s32 D_002DAB00[];
extern S_3BD0D8 *D_002DA740[];
extern u32 D_001DA49C;

/* localdecomp:start func_003C2880 */
__asm__(".extern D_001DA4A0, 16");
__asm__(".extern D_001DA4B0, 16");
__asm__(".extern D_001DA4B4, 16");
__asm__(".extern D_001D9D00, 16");
typedef struct { u8 pad[0x20]; u8 b20; u8 pad21[0x33]; s32 f54; u8 pad58[0x10]; s32 f68; u8 pad6C[0x34]; s32 fA0; } O_3BD360;
extern u32 D_001DA4A0; 
extern s32 D_001DA4B0; 
extern s32 D_001DA4B4; 
extern s32 D_001D9D00; 
extern void func_003C7480();
extern void func_003C2C98();
extern void func_003C7958();
void func_003C2880(s32 arg) {
    O_3BD360 *o = (O_3BD360 *)arg;
    s32 p;
    if ((u32)o < D_001DA4A0) {
        o->b20 = 0xFD;
    } else {
        o->b20 = 0xFE;
        p = o->f68;
        if (p) {
            if (p >= D_001DA4B0 && p < D_001DA4B0 + D_001DA4B4 * 64) {
                func_003C7480(p);
                o->f68 = 0;
            }
        }
        while (o->f54) {
            func_003C2C98(o, o->f54);
        }
    }
    o->fA0 = D_001D9D00 + 2;
    func_003C7958(o, 0x80807F7F);
}
/* localdecomp:end func_003C2880 */

extern int D_001DA4CC;
extern int D_001DA4BC;
extern int D_001DA4C8;
extern int D_001DA4C0;
extern int D_001DA4C4;
extern void func_0038CB78(void *, int, int);
/* localdecomp:start func_003C2948 */
__asm__(".extern D_001DA4CC, 16");
__asm__(".extern D_001DA4BC, 16");
__asm__(".extern D_001DA4C8, 16");
__asm__(".extern D_001DA4C0, 16");
u32 func_003C2948(s32 count, s32 base) {
    s32 size = count * 4;
    D_001DA4CC = base + size;
    D_001DA4BC = base;
    D_001DA4C8 = base;
    D_001DA4C0 = 0;
    D_001DA4C4 = 0;
    func_0038CB78((void *)base, 0, size);
    base = D_001DA4CC;
    return (base + 0x3F) & 0xFFFFFFC0;
}
/* localdecomp:end func_003C2948 */

/* localdecomp:start func_003C29B0 */
typedef struct { u8 p0[0x48]; u8 *tbl[1]; } C_3BD490;
typedef struct { u8 p0[0x24]; C_3BD490 *f24; u8 p28[0x18]; u8 b40; u8 b41; u8 b42; u8 b43; u8 p44[0x14]; s32 f58; s32 f5C; u8 p60[0xC]; u8 b6C; u8 p6D; u8 b6E; } S_3BD490;
extern u8 D_002D2100[];
void func_003C29B0(S_3BD490 *s)
{
  u8 *new_var2;
  int new_var;
  if (s->b42 != 0xFF)
  {
    new_var2 = s->f24->tbl[s->b42] + (s->b40 * 4);
    s->f58 = *((s32 *) (new_var2 + 0x1C));
    s->b6E = s->f24->tbl[s->b42][0x12];
    s->b6C = s->f24->tbl[s->b42][0x11];
  }
  else
  {
    s->b6C = s->b42;
    s->b6E = 0;
    s->f58 = (s32) (D_002D2100 + (s->b40 << 11));
  }
  s->f5C = *((s32 *) ((s->f24->tbl[s->b43] + (new_var = s->b41 * 4)) + 0x1C));
}
/* localdecomp:end func_003C29B0 */

/* localdecomp:start func_003C2A70 */
typedef struct { u8 p0[0x24]; void *f24; u8 p28[0xC]; u16 h34; u8 p36[0x36]; u8 b6C; u8 b6D; u8 p6E[0xE]; u16 h7C; } S_3BD550;
extern u8 D_1A30B0[];
extern void func_003A4F28(u32);
extern s32 func_003A52A0();
void func_003C2A70(S_3BD550 *p) {
    u8 *e;
    if (p->b6D != 0xFF) {
        e = D_1A30B0 + p->b6D * 128;
        if (*(S_3BD550 **)(e + 0xDC) != p) {
            p->b6D = 0xFF;
            return;
        }
        if (*(s16 *)(e + 0xCA) != p->b6C || (p->h34 & 0x40) || (p->h7C & 0x8000)) {
            func_003A4F28(p->b6D);
            p->b6D = 0xFF;
        }
    } else {
        if (p->b6C == 0xFF) return;
        if (p->h34 & 0x40) return;
        if (*(unsigned long *)((u8 *)p + 0x78) & 0x4800000000000UL) return;
        p->b6D = func_003A52A0(p->b6C, 4, p);
    }
}
/* localdecomp:end func_003C2A70 */

LINKER_REMNANT("asm/remnants", func_003C2B50);

/* localdecomp:start func_003C2B88 */
#include "vu0.h"
/* MATCH */
extern s32 D_002FC020[];
extern s32 D_001DA4E0;
__asm__(".extern D_001DA4E0, 16");
extern void func_003D1708();
s32 func_003C2B88(u8 *obj, u8 *dst) {
    u8 *out = (u8 *)0x70000000;
    u8 *src;
    s32 i;
    s32 *cnt = (s32 *)0x70002000;
    if (dst != 0) out = dst;
    if (obj == 0) goto fail;
    if (*(u8 **)(obj + 0x24) == 0) return 0;
    if ((*(u8 **)(obj + 0x24))[0xF] == 0) goto fail;
    D_002FC020[0] = (s32)obj;
    D_001DA4E0 = 1;
    D_002FC020[1] = 0x1000;
    func_003D1708(cnt, 0x2000);
    if (*cnt == 0) {
fail:
        return 0;
    }
    src = (u8 *)0x70002030;
    i = 0;
    while (i < *cnt) {
        if (*(s16 *)src == 0) {
            u128_t v = *(u128_t *)(src + 0x10);
            qzero(out + 0x10);
            src += 0x20;
            *(u128_t *)out = v;
            out += 0x20;
        } else if (*(s16 *)src == 1) {
            *(u128_t *)out = *(u128_t *)(src + 0x10);
            *(u128_t *)(out + 0x10) = *(u128_t *)(src + 0x20);
            src += 0x30;
            out += 0x20;
        }
        i++;
    }
    return *cnt;
}
/* localdecomp:end func_003C2B88 */

LINKER_REMNANT("asm/remnants", func_003C2C88);

/* localdecomp:start func_003C2C98 */
typedef struct N_BD778 { u8 p0[8]; struct N_BD778 *next; } N_BD778;
typedef struct { u8 p0[0x54]; N_BD778 *head; } L_BD778;
extern void func_0038CB78(void *, s32, s32);
void func_003C2C98(L_BD778 *l, N_BD778 *n) {
    N_BD778 *p;
    N_BD778 *h;
    if (n != 0) {
        h = l->head;
        if (h == n) {
            l->head = n->next;
        } else if (h != 0) {
            p = h;
            while (p->next != 0 && p->next != n) {
                p = p->next;
            }
            if (p->next == n) {
                p->next = n->next;
            }
        }
        func_0038CB78(n, 0, 0x40);
    }
}
/* localdecomp:end func_003C2C98 */

/* localdecomp:start func_003C2D30 */
extern s32 D_001DA400[];
extern s32 D_001DA440[];
s32 func_003C2D30(s32 x) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_001DA400[i] == 0 || D_001DA400[i] == x) {
            D_001DA400[i] = x;
            D_001DA440[i] = 0;
            return i;
        }
    }
    return -1;
}
/* localdecomp:end func_003C2D30 */

/* localdecomp:start func_003C2D88 */
extern s32 D_001DA400[];
extern s32 D_001DA440[];
void func_003C2D88(void) {
    s32 i;
    for (i = 0; i < 16; i++) {
        D_001DA400[i] = 0;
        D_001DA440[i] = 0;
    }
}
/* localdecomp:end func_003C2D88 */

/* US draft of func_003C2DC0 (rac3-uya-decomp func_003BD8A0, commit 13cf5c5), names moved to PAL addresses
   where known. The US callee was the unmapped symbol func_003C1A90; in PAL the retail call
   target is func_003C6FE0 (src/frontbin/3C6FB0.c), which takes the same struct pointer. */


/* localdecomp:start func_003C2DC0 */
typedef struct { u8 p0[0x13]; u8 f13; } S_BDb;
typedef struct { u8 p0[0x48]; S_BDb *arr[1]; } S_BDt;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[3]; S_BDt *f24; u8 p28[9]; u8 f31; u8 p32[0x10]; u8 f42; u8 f43; f32 f44; u8 p48[4]; f32 f4C; } S_BDa;
extern S_BDa *D_001DA400_003C2DC0[16];
extern s32 D_001DA440_003C2DC0[16];
extern void func_003C6FE0();
void func_003C2DC0(void) {
    s32 i = 0;
    S_BDa *p;
    do {
        p = D_001DA400_003C2DC0[i];
        if (p != 0) {
            if (p->f20 & 0x80) { D_001DA400_003C2DC0[i] = 0; goto z; }
            if (p->f42 != 0xFF) { D_001DA400_003C2DC0[i] = 0; goto z; }
            if (p->f31 == 0 && D_001DA440_003C2DC0[i] >= 20) {
                if (p->f24->arr[p->f43]->f13 == p->f42) {
                    p->f44 = 1.0f - p->f4C;
                    func_003C6FE0(D_001DA400_003C2DC0[i]);
                }
            } else {
                D_001DA440_003C2DC0[i]++;
            }
        } else {
z:
            D_001DA440_003C2DC0[i] = 0;
        }
        i++;
    } while (i < 16);
}
/* localdecomp:end func_003C2DC0 */

/* localdecomp:start func_003C2EC0 */
typedef struct { f32 x, y, z, w; } V4_3BD9A0;
typedef int Q_3BD9A0 __attribute__((mode(TI)));
extern void func_003CA4A0();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D570();
extern void func_0038D640();
void func_003C2EC0(u8 *a, s32 b, u8 *out) {
    s32 loc;
    f32 buf[16];
    f32 scale;
    Q_3BD9A0 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003CA4A0(a, 1, &loc, out);
    func_0038CE20((f32 *)(out + 0x30), out + 0x30, scale);
    func_0038D570(buf, a + 0xC0);
    func_0038D640(out, buf, out);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BD9A0 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BD9A0 *)(out + 0x30)));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BD9A0 *)(out + 0x30)) : "j"(x));

}
/* localdecomp:end func_003C2EC0 */

/* localdecomp:start func_003C2F58 */
typedef struct { f32 x, y, z, w; } V4_3BDA38;
typedef int Q_3BDA38 __attribute__((mode(TI)));
extern void func_003CA4A0();
extern void func_0038CE20(f32 *, void *, f32);
extern void func_0038D000(void *, void *, void *);
void func_003C2F58(u8 *a, s32 b, f32 *out) {
    s32 loc;
    f32 buf[12];
    f32 v[4];
    f32 scale;
    Q_3BDA38 x, y;
    loc = b;
    scale = *(f32 *)(a + 0x2C) * 0.0009765625f;
    func_003CA4A0(a, 1, &loc, buf);
    func_0038CE20(out, v, scale);
    func_0038D000(out, out, a + 0xC0);
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V4_3BDA38 *)(a + 0x10)));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*(V4_3BDA38 *)out));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BDA38 *)out) : "j"(x));

}
/* localdecomp:end func_003C2F58 */
