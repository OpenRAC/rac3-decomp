#include "common.h"

typedef struct S_0032FD50 {
    f32 f00;
    s16 f04;
    u8 pad06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[0x34 - 0x0A];
    u16 f34;
    s16 pad36;
    s16 f38;
    u8 pad3A[0x7F - 0x3A];
    u8 f7F;
    u8 pad80[0x98 - 0x80];
    s32 f98;
    u8 pad9C[0xD8 - 0x9C];
    s32 fD8;
} S_0032FD50;

typedef struct S_00330A58 {
    u8 pad[0xF8];
    f32 f0F8;
} S_00330A58;

/* localdecomp:start func_L03_0032FBA8 */
int func_L03_0032FBA8(char *a0) {
    char *p = *(char **)(a0 + 0x68);
    if (*(unsigned char *)(a0 + 0x20) == 9)
        return -1;
    return *(int *)(p + 0xC8);
}
/* localdecomp:end func_L03_0032FBA8 */

/* localdecomp:start func_L03_0032FBC8 */
typedef struct S_0032FBC8a { u8 pad00[0x10]; s32 f10; s16 f14; } S_0032FBC8a;
typedef struct S_0032FBC8b { u8 pad00[0x2F]; u8 f2F; } S_0032FBC8b;
typedef struct S_0032FBC8c { s32 f00; u8 pad04[8]; s32 fC; u8 pad10[0xC]; u8 f1C; } S_0032FBC8c;
extern void *func_L01_00449020(void *);
extern void *func_00382348(void *);
extern void *func_L03_0032F6A8();
extern s32 func_L01_00452860(void *, void *, s32);
extern void func_L03_0032D640(s32, void *);
extern void func_L01_00404A10(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, f32, s32, s32, s32, s32, f32, s32, s32, s32, s32);
extern s32 func_L03_0032FBA8_0032FBC8(s32);
extern s32 D_L03_001DF4C0;
void func_L03_0032FBC8(void *a) {
    S_0032FBC8a *p19;
    S_0032FBC8b *p17;
    S_0032FBC8c *p18;

    p19 = func_L01_00449020(a);
    p17 = func_00382348(a);
    p18 = func_L03_0032F6A8(a);
    if (p17->f2F == 0 && p19->f14 == 1 && (D_L03_001DF4C0 & 7) != 0) return;
    func_L01_00452860(a, p17, 0);
    if (p17->f2F != 0) {
        if (p18->f1C == 1) func_L03_0032D640(p18->f00, a);
        p18->f1C = 3;
        func_L01_00404A10(a, 5);
        func_L01_00456C98(a, func_L03_0032FBA8_0032FBC8(p18->f00), 0, 0, 0, 1, 0, 0, 1.0f, 3, 0, 0, 0);
    } else {
        func_L01_00404A10(a, 3);
        func_L01_00456C98(a, func_L03_0032FBA8_0032FBC8(p18->f00), 0, 0, 0, 1, 0, 0, 1.0f, 1, 0, 0, 0);
    }
    if (p19->f14 == 1) p18->fC = p19->f10; else p18->fC = 0;
}
/* localdecomp:end func_L03_0032FBC8 */

/* localdecomp:start func_L03_0032FD50 */
extern void *func_L01_0045B958(void *);
extern void *func_00382348(void *);
extern void *func_L01_00448FF0(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L03_0032F600(void *);
extern void *func_L03_0032F6A8(void *);
extern void func_L03_0032DA08(void *);
extern void func_L03_0032D640(s32, void *);

void func_L03_0032FD50(S_0032FD50 *p) {
    void *u;
    S_0032FD50 *r;
    S_0032FD50 *s;

    p->f7F = 0;
    ((S_0032FD50 *)func_L01_0045B958(p))->fD8 = -1;
    r = func_00382348(p);
    r->f00 = (f32)r->f04;
    s = func_L01_00448FF0(p);
    s->f38 = 0;
    s->f07 = 0;
    s->f09 = 0;
    s->f08 = 0;
    p->f98 = 0;
    p->f34 = (p->f34 | 0x41) & 0xEFFF;
    func_L01_004AA7E8(p, 1);
    p->f34 = p->f34 | 6;
    func_L03_0032F600(p);
    u = func_L03_0032F6A8(p);
    func_L03_0032DA08(p);
    func_L03_0032D640(((s32 *)u)[0], p);
}
/* localdecomp:end func_L03_0032FD50 */

/* localdecomp:start func_L03_0032FE10 */
#include "vu0.h"
typedef struct S_0032FE10 {
    u8 pad00[0x10];
    s32 f10;
    u8 pad14[0x10];
    f32 f24;
} S_0032FE10;
typedef struct S_0032FE10b {
    u8 pad00[0xE];
    u8 fE;
    u8 pad0F[0x1F];
    u8 f2E;
    u8 f2F;
    u8 f30;
} S_0032FE10b;
typedef struct S_0032FE10c {
    u8 pad00[0x24];
    S_0032FE10 *f24;
    u8 pad28[4];
    f32 f2C;
    u8 pad30[4];
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
    u8 pad9C[0x54];
    u8 fF0[16];
} S_0032FE10c;
extern void *func_00382348(void *);
void func_L03_0032FE10(S_0032FE10c *p) {
    S_0032FE10b *t = func_00382348(p);
    t->f2E = 0;
    t->f30 = 0;
    t->f2F = 0;
    t->fE = 1;
    p->f34 &= 0xBFB8;
    p->f98 = p->f24->f10;
    qzero(p->fF0);
    p->f2C = p->f24->f24;
}
/* localdecomp:end func_L03_0032FE10 */

/* localdecomp:start func_L03_0032FE70 */
/* PAL port of the NTSC-U match src/us/levels/func_L03_0032F7A0.c */
/* NTSC-U counterpart of func_L03_0032FE70 (src/levels/03_starship_phoenix/L03_0032FBA8.c).
 * In the buttons & 0x40 arm 'r = 1' is written AFTER the last call: with r = 1 right after func_003A5348(4, 0, 0)
 * sched2 orders the argument moves a0, a1, a2 instead of retail's a2, a0, a1 (3 differing words). */

extern u8 *D_001D52FC;
extern u8 *D_L03_001DD104;
__asm__(".extern D_L03_001DD104, 4");
extern u8 D_L03_001DD108;
__asm__(".extern D_L03_001DD108, 1");
extern u8 D_L03_001DD109;
__asm__(".extern D_L03_001DD109, 1");
extern s32 D_L03_001DF514;
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003A2CD8(void *);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L03_00330140(void *);
extern void func_L03_0032CFE8(void *, s32);
extern void func_L01_00516558(s32, f32 *, f32 *);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_005170B8(s32, s32);

s32 func_L03_0032FE70(void) {
    s32 r;
    u8 *self;
    u8 *st;
    s32 buttons;
    s32 id;
    f32 t;
    f32 u;
    f32 w;
    f32 buf[2];

    r = 0;
    self = D_L03_001DD104;
    st = *(u8 **)(self + 0x68);
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x10) {
        D_L03_001DF514 = 2;
        func_L01_004450F0(self, 12, -1);
        r = 1;
        func_003A2CD8(D_001D52FC);
    }
    buttons = *(s32 *)(D_001D52FC + 0x1C4);
    if (buttons & 0x1000) {
        if (D_L03_001DD109 != 0) {
            func_003A5348(3, 0, 0);
            D_L03_001DD109 = D_L03_001DD109 - 1;
            if (D_L03_001DD109 < D_L03_001DD108) {
                D_L03_001DD108 = D_L03_001DD108 - 1;
            }
            func_L03_00330140(self);
            func_003A2CD8(D_001D52FC);
        }
    } else if (buttons & 0x4000) {
        if (D_L03_001DD109 < st[0x112] - 1) {
            func_003A5348(3, 0, 0);
            D_L03_001DD109 = D_L03_001DD109 + 1;
            if (D_L03_001DD109 - D_L03_001DD108 >= 5) {
                D_L03_001DD108 = D_L03_001DD108 + 1;
            }
            func_L03_00330140(self);
            func_003A2CD8(D_001D52FC);
        }
    } else if (buttons & 0x40) {
        D_L03_001DF514 = 2;
        func_003A5348(4, 0, 0);
        func_L03_0032CFE8(self, st[0xFF]);
        func_003A2CD8(D_001D52FC);
        r = 1;
    }
    w = *(f32 *)(st + 0x100) + 0.060000002f;
    *(f32 *)(st + 0x100) = w;
    if (2.0f < w) {
        *(f32 *)(st + 0x100) = w - 2.0f;
    }
    id = 0x470024 + (D_L03_001DD109 - D_L03_001DD108);
    func_L01_00516558(id, &buf[0], &buf[1]);
    func_L01_00516470(0x470023, buf[0], buf[1]);
    t = *(f32 *)(st + 0x100);
    u = (t <= 1.0f) ? t : 2.0f - t;
    func_L01_005170B8(id, func_0038DBD8(0x66D6EEFA, 0x80FFFFFF, u));
    return r;
}
/* localdecomp:end func_L03_0032FE70 */

/* localdecomp:start func_L03_003300A0 */
typedef struct { char pad[0x10E]; s16 a, b, c; } S_003300A0;
typedef struct { char pad[0x68]; S_003300A0 *p; } T_003300A0;
extern T_003300A0 *D_001DD104_sda;
__asm__(".extern D_001DD104_sda, 4");
extern u8 D_001DD108_sda;
__asm__(".extern D_001DD108_sda, 1");
extern u8 D_001DD109_sda;
__asm__(".extern D_001DD109_sda, 1");
extern int D_L03_001E11F8;
extern int D_L03_001E11F0;
extern void func_L01_00516FD8(int, void *);
extern int func_00381FF0(int);
extern void func_L01_00516AA0(int, int, int);
extern void func_L03_0032F810(void *, void *, void *);
extern void func_L03_00330140(void *);

void func_L03_003300A0(void) {
    T_003300A0 *t = D_001DD104_sda;
    S_003300A0 *s = t->p;
    func_L01_00516FD8(0x47001E, &D_L03_001E11F8);
    func_L01_00516FD8(0x47001A, &D_L03_001E11F0);
    func_L01_00516FD8(0x470007, (void *)func_00381FF0(0xC44));
    func_L01_00516AA0(0x470014, 1, 0);
    func_L03_0032F810(&s->a, &s->b, &s->c);
    D_001DD108_sda = 0;
    D_001DD109_sda = 0;
    func_L03_00330140(t);
}
/* localdecomp:end func_L03_003300A0 */

/* localdecomp:start func_L03_00330140 */
typedef struct S_00330140 { u8 pad00[0xFF]; u8 fFF; u8 pad100[0x10E - 0x100]; s16 f10E; s16 f110; } S_00330140;
extern u8 D_L03_002AE4D0[];
extern int D_L03_001DD148[];
__asm__(".extern D_L03_001DD148, 16");
extern void func_L03_00330438_00330140(void *, int, int *, int);
extern void func_L01_00517190(int, int);
extern int func_L03_0032FA50(int);
extern int func_L03_0032F948(int);
extern void func_L03_0032FA78(int, int *, int *);
extern void func_0011B2E8();

void func_L03_00330140(void *arg0) {
    S_00330140 *s = *(S_00330140 **)((u8 *)arg0 + 0x68);
    int cnt;
    int v[3];
    int *p;
    int i, id;

    cnt = 0;
    func_L03_00330438_00330140(arg0, s->f110, &cnt, 0x8066CCFF);
    func_L03_00330438_00330140(arg0, s->f10E, &cnt, 0x80808080);
    {
        u8 *e = D_L03_002AE4D0 + s->fFF * 0x28;
        func_L01_00516FD8(0x47000F, (void *)func_00381FF0(*(int *)(e + 0x20)));
        func_L01_00516FD8(0x470012, (void *)func_00381FF0(*(int *)(e + 0x24)));
    }
    func_L01_00516FD8(0x470019, (void *)func_00381FF0(0xC45));
    func_0011B2E8(&D_L03_001E11F0, D_L03_001DD148, func_L03_0032FA50(s->fFF));
    func_0011B2E8(&D_L03_001E11F8, D_L03_001DD148, func_L03_0032F948(s->fFF));
    func_L01_00517190(0x47001C, s->fFF + 1);
    p = &v[1];
    func_L03_0032FA78(s->fFF, p, &v[2]);
    id = 0x470015;
    for (i = 1; i >= 0; i--, p++) {
        if (*p == 0) {
            func_L01_00516AA0(id, 1, 0);
        } else {
            func_L01_00516AA0(id, 1, 1);
            func_L01_00517190(id, *p);
        }
        id++;
    }
}
/* localdecomp:end func_L03_00330140 */

/* localdecomp:start func_L03_003302D0 */
typedef struct { u8 pad00[0xF1]; u8 bF1; } S_003302D0;
extern u8 D_L03_002AE4D0_003302D0[];
extern u8 D_L03_001E1218[4];
extern u8 D_L03_001E1228[4];
extern void func_L03_003AECB0();
extern void func_L01_00516FD8(s32, void *);
extern void func_L01_00517190(s32, s32);
extern void func_L03_003AF098(s32);
extern void func_L03_00330380(u8 *);
void func_L03_003302D0(void *a) {
    s32 r = 0;
    u8 *p;
    S_003302D0 *s = *(S_003302D0 **)((u8 *)a + 0x68);
    func_L03_003AECB0();
    func_L01_00516FD8(0x150006, D_L03_001E1218);
    func_L01_00516FD8(0x150007, D_L03_001E1228);
    p = D_L03_002AE4D0_003302D0 + s->bF1 * 0x28;
    if (*(s32 *)(p + 0x14) != -1) {
        func_L01_00517190(0x150008, 0xEC5A);
        r = 1;
    }
    func_L03_003AF098(r);
    func_L03_00330380(a);
}
/* localdecomp:end func_L03_003302D0 */

/* localdecomp:start func_L03_00330380 */
extern u8 D_L03_002AE4D0[];
extern u8 D_L03_001DD150[];
extern u8 D_L03_001DD158[];
extern u8 D_L03_001E1218[4];
extern u8 D_L03_001E1228[4];
extern s32 func_00381FF0(s32);
extern void func_L03_0032FAB8(s32, s32 *, s32 *);
extern void func_0011B2E8();

void func_L03_00330380(u8 *arg0) {
    s32 a;
    s32 b;
    u8 *s1;
    u8 *p;

    s1 = *(u8 **)(arg0 + 0x68);
    p = D_L03_002AE4D0 + s1[0xF1] * 0x28;
    func_0011B2E8(D_L03_001E1218, D_L03_001DD150, s1[0xF0] + 1, *(s16 *)p);
    if (*(s32 *)(p + 0x14) != -1) {
        func_L03_0032FAB8(*(s32 *)(s1 + 0xEC), &a, &b);
        func_0011B2E8(D_L03_001E1228, D_L03_001DD158, a, b);
    } else {
        func_0011B2E8(D_L03_001E1228, func_00381FF0(0x1921));
    }
}
/* localdecomp:end func_L03_00330380 */

/* localdecomp:start func_L03_00330438 */
typedef struct S_00330438 { u8 pad00[0x20]; s32 f20; u8 pad24[0x28-0x24]; } S_00330438;
typedef struct S_00330438b { u8 pad00[0x68]; u8 *f68; } S_00330438b;
extern S_00330438 D_L03_002AE4D0_00330438[];
extern u8 D_001DD108_sda;
__asm__(".extern D_001DD108_sda, 1");
extern u8 D_001DD109_sda;
__asm__(".extern D_001DD109_sda, 1");
extern s32 func_00381FF0(s32);
extern void func_L01_00516FD8_00330438(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
void func_L03_00330438(S_00330438b *a, s16 mask, s32 *c, s32 d) {
    u8 *p = a->f68;
    s32 i;
    for (i = 0; i < 9; i++) {
        if ((mask >> i) & 1) {
            s32 t = *c - D_001DD108_sda;
            if ((u32)t < 5) {
                s32 q = t + 0x470024;
                s32 r = func_00381FF0(D_L03_002AE4D0_00330438[i].f20);
                func_L01_00516FD8_00330438(q, r);
                func_L01_005170B8(q, d);
                if (*c == D_001DD109_sda) p[0xFF] = i;
            }
            *c = *c + 1;
        }
    }
}
/* localdecomp:end func_L03_00330438 */

/* localdecomp:start func_L03_00330530 */
/* localdecomp:start func_L03_00330530 */
typedef struct S_00330530 { u8 pad00[0x68]; u8 *f68; } S_00330530;
extern s32 func_00381FF0(s32);
extern void func_0011B2E8();
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038FA18(u16 *, long, char *, s32, unsigned long, f32, f32);
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00436020(s32, s32, f32, f32, f32, f32);
extern u8 D_L03_001DD168[];
extern u8 D_L03_001DD170[];
extern f32 D_L03_001E0B24;
extern s32 D_L03_001E0B20;
extern s32 D_001D4BC8;
__asm__(".extern D_001D4BC8, 16");
extern s32 D_L03_001D64E8;

static __inline__ s32 scale_00330530(f32 v) {
    f32 z0 = 0.0f, z1 = 0.0f;
    return (s32)(v * D_L03_001E0B24 + 0.5f + (D_L03_001E0B20 == 1 ? z0 : z1));
}

void func_L03_00330530(S_00330530 *arg0) {
    char buf[0x400];
    u16 m[16];
    s32 *s1 = (s32 *)arg0->f68;
    s32 s = s1[0x108 / 4];
    s32 h, w;

    if (s == -1) return;
    if (s == -2) {
        func_0011B2E8(buf, D_L03_001DD168, func_00381FF0(0x269));
    } else if (s == 0) {
        func_0011B2E8(buf, D_L03_001DD168, func_00381FF0(0x58B));
    } else {
        u8 *fmt = D_L03_001DD170;
        s32 a = func_00381FF0(0x269);
        s32 b = func_00381FF0(0x125C);
        s32 c = func_00381FF0(0x282);
        func_0011B2E8(buf, fmt, a, b, s1[0x108 / 4], c);
    }
    m[12] = 2;
    m[13] = 2;
    func_003910C0((s16 *)m, scale_00330530(256.0f), scale_00330530(384.0f), D_001D4BC8 - 0x90, D_001D4BC8 + 0x90, D_001D4BC8, 0x140, 0x10, 0x27);
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    w = ((s16)m[6] >> 1) + 8;
    h = ((s16)m[7] >> 1) + 8;
    func_0038C3B0(((s16)m[5]) - h, ((s16)m[5]) + h, ((s16)m[4]) - w, ((s16)m[4]) + w, 0x33, 0x331465B7);
    func_L01_00436020(0x33, 0x332299DE, (s16)m[5] - h, (s16)m[5] + h, (s16)m[4] - w, (s16)m[4] + w);
    m[9] &= 0xFFFB;
    func_0038FA18(m, 0x8066CCFFL, buf, -1, 0x80000000UL, 1.0f, 1.0f);
    D_L03_001D64E8 = 1;
}
/* localdecomp:end func_L03_00330530 */
/* localdecomp:end func_L03_00330530 */

/* localdecomp:start func_L03_003307D0 */
#include "vu0.h"
/* the quad descriptor of func_003D2DA0, laid out as in func_L05_003B27F8 */
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_003307D0;
typedef struct { u8 pad0[0xE0]; f32 scroll[2]; u8 padE8[0xFC - 0xE8]; u8 bFC; } S_003307D0;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003307D0 *p68; } A_003307D0;
extern f32 D_001DD110_sda[2];
__asm__(".extern D_001DD110_sda, 8");
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);

/* corner i of the quad: 0 and 1 on the left, 1 and 3 at the top */
static __inline__ s32 left_003307D0(s32 i) { return i < 2; }
static __inline__ s32 top_003307D0(s32 i) { return i & 1; }

void func_L03_003307D0(void *arg) {
    A_003307D0 *a = arg;
    S_003307D0 *s = a->p68;
    vu0_v4 pos;
    Q_003307D0 q;
    f32 off[4];
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    for (i = 0; i < 2; i++) {
        s->scroll[i] = s->scroll[i] + D_001DD110_sda[i] * 1.2f;
        if (s->scroll[i] > 1.0f) s->scroll[i] = s->scroll[i] - 1.0f;
    }
    pos = a->pos;
    q.x78 = func_00389598(s->bFC + 0x64);
    q.x80 = 0xFF9000000260L;
    q.x88 = 0x800000006AL;
    q.x70 = 0;
    q.color[3] = (s32)0xFFFF8040;
    q.color[2] = (s32)0xFFFF8040;
    q.color[1] = (s32)0xFFFF8040;
    q.color[0] = (s32)0xFFFF8040;
    for (j = 0; j < 4; j++) {
        if (left_003307D0(j)) q.uv[j][0] = -7.0f; else q.uv[j][0] = 7.0f;
        if (top_003307D0(j)) q.uv[j][1] = -7.0f; else q.uv[j][1] = 7.0f;
    }
    for (k = 0; k < 4; k++) {
        qzero(off);
        {
            s32 axis = (u32)(k - 1) < 2;
            f32 sign = left_003307D0(k) ? 1.0f : -1.0f;
            off[axis] = sign * 75.0f;
        }
        vec_add_ab(&q.v[k], &pos, off);
    }
    func_003A9440(0x47, 0x51001);
    func_003D2DA0(&q, 0, 0);
    q.x78 = func_00389598(s->bFC + 0x64);
    q.x88 = 0x8000000058L;
    for (m = 0; m < 4; m++) {
        q.uv[m][0] = s->scroll[0] + (left_003307D0(m) ? -6.0f : 6.0f);
        q.uv[m][1] = s->scroll[1] + (top_003307D0(m) ? -6.0f : 6.0f);
    }
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L03_003307D0 */

/* localdecomp:start func_L03_00330A58 */
extern void func_L03_00330B18(void *p, s32 n, f32 a, f32 b);

void func_L03_00330A58(void *arg0) {
    u8 *q;
    f32 x;
    f32 y;
    f32 t;

    q = *(u8 **)((u8 *)arg0 + 0x68);
    if (1.0f < ((S_00330A58 *)q)->f0F8) {
        x = 6.0f;
    } else {
        x = ((S_00330A58 *)q)->f0F8 * 6.0f;
    }
    t = 2.0f - ((S_00330A58 *)q)->f0F8;
    if (1.0f < t) {
        y = 1.0f;
    } else {
        y = t;
    }
    func_L03_00330B18(arg0, 0, x, y);
    func_L03_00330B18(arg0, 1, x, y);
}
/* localdecomp:end func_L03_00330A58 */

/* localdecomp:start func_L03_00330B18 */
typedef struct S_00330B18b { u8 pad00[0xF7]; u8 fF7; u8 padF8[5]; u8 fFD; } S_00330B18b;
typedef struct S_00330B18a { u8 pad00[0x68]; S_00330B18b *f68; } S_00330B18a;
typedef struct S_00330B18c { u8 pad[0x40]; s32 c0; s32 c1; s32 c2; s32 c3; s32 z0; s32 z1; s32 z2; f32 g0; f32 g1; s32 z3; f32 g2; f32 g3; } S_00330B18c;
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_L03_00330CD0_00330B18(void *a, void *b, s32 n, f32 x, f32 y, f32 z, f32 w);
void func_L03_00330B18(void *arg0, s32 n, f32 x, f32 y) {
    S_00330B18a *a = arg0;
    S_00330B18b *p = a->f68;
    S_00330B18c s;
    char buf[32];
    s32 c;
    f32 lo, hi;
    func_003D93B0(&s, p->fFD + 100, 1, 128);
    c = ((s32)(y * 64.0f) << 24) | 0xFF2020;
    s.c1 = c; s.c0 = c;
    s.c3 = 0xFF2020; s.c2 = 0xFF2020;
    s.z0 = 0; s.z1 = 0; s.z2 = 0;
    s.g0 = 1.0f; s.g1 = 1.0f; s.z3 = 0; s.g2 = 1.0f; s.g3 = 1.0f;
    if (p->fF7 & 0x10) {
        lo = 10.5f; if ((p->fF7 >> n) & 1) lo = 22.83f;
        hi = -10.5f; if ((p->fF7 >> (n + 2)) & 1) hi = -22.83f;
        func_L03_00330CD0_00330B18(a, &s, n, x, y, lo, hi);
    } else {
        if ((p->fF7 >> n) & 1) func_L03_00330CD0_00330B18(a, &s, n, x, y, 10.5f, 22.83f);
        if ((p->fF7 >> (n + 2)) & 1) func_L03_00330CD0_00330B18(a, &s, n, x, y, -10.5f, -22.83f);
    }
}
/* localdecomp:end func_L03_00330B18 */

/* localdecomp:start func_L03_00330CD0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct S_00330CD0 { f32 a[4]; f32 b[4]; } S_00330CD0;
extern void func_L03_00330DC0(void *a, s32 i, f32 b, f32 c);
extern f32 func_0038DB00(f32, f32);
void func_L03_00330CD0(u128_t *src, S_00330CD0 *dst, s32 i, f32 a, f32 b, f32 c, f32 d) {
    f32 t = b * 1.5707964f;
    *(u128_t *)dst->a = src[1];
    dst->a[i] += c;
    *(u128_t *)dst->b = src[1];
    dst->b[i] += d;
    func_L03_00330DC0(dst, i, a, t);
    if (b != 1.0f) {
        func_L03_00330DC0(dst, i, a, func_0038DB00(3.1415927f, t));
    }
}
/* localdecomp:end func_L03_00330CD0 */

/* localdecomp:start func_L03_00330DC0 */
#include "vu0.h"
typedef struct { f32 f[4]; } __attribute__((aligned(16))) V_00330DC0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D2DA0(void *, s32, s32);
void func_L03_00330DC0(void *a, s32 i, f32 b, f32 c) {
    V_00330DC0 v;
    f32 k;
    f32 *q = &v.f[1 - i];
    qzero(&v);
    k = b * 0.66f;
    *q = func_0038D098(c);
    v.f[2] = func_0038D0B0(c);
    func_0038CF68(&v, &v, b);
    vec_add_ba((u8 *)a + 0x20, a, &v);
    vec_add_ba((u8 *)a + 0x30, (u8 *)a + 0x10, &v);
    func_003D2DA0(a, 0, 0);
    func_0038CF68(&v, &v, k);
    vec_add_ba((u8 *)a + 0x20, a, &v);
    vec_add_ba((u8 *)a + 0x30, (u8 *)a + 0x10, &v);
    func_003D2DA0(a, 0, 0);
}
/* localdecomp:end func_L03_00330DC0 */

/* localdecomp:start func_L03_00330EC8 */
#include "vu0.h"
typedef struct S_00330EC8b { u8 pad00[0xF7]; u8 fF7; f32 fF8; } S_00330EC8b;
typedef struct S_00330EC8a { u8 pad00[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_00330EC8b *f68; } S_00330EC8a;
extern s32 func_00382468(s32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern void func_L01_00474078(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

/* 0 or 1 at random */
static __inline__ s32 coin_00330EC8(void) {
    return func_00382468(2);
}

/* 1 or -1: the sign sg, or a random one when sg is -1 */
static __inline__ s32 rsign_00330EC8(s32 sg) {
    s32 s;

    if (sg == -1 ? coin_00330EC8() : sg) {
        s = 1;
    } else {
        s = -1;
    }
    return s;
}

/* the axis ax, or a random one (x or y) when ax is -1 */
static __inline__ s32 pick_00330EC8(s32 ax) {
    s32 k;

    if (ax == -1) {
        k = coin_00330EC8();
    } else {
        k = ax;
    }
    return k;
}

/* a random length between lo and hi, with sign s */
static __inline__ f32 rand_len_00330EC8(f32 lo, f32 hi, s32 s) {
    f32 d = func_003824E0(lo, hi);

    return d * (f32)s;
}

void func_L03_00330EC8(void *arg0) {
    S_00330EC8a *a = arg0;
    S_00330EC8b *p = a->f68;
    vu0_v4 v;
    f32 t;
    f32 y;
    f32 lo;
    f32 hi;
    s32 i;
    s32 j;
    s32 n;
    s32 ax;
    s32 sg;

    t = 2.0f - p->fF8;
    if (1.0f < t) {
        y = 1.0f;
    } else {
        y = t;
    }
    for (i = 0; i < 5; i++) {
        n = 4;
        if (!((p->fF7 >> i) & 1)) continue;
        if (i == 4) {
            n = 8;
            lo = 0.0f;
            hi = 10.5f;
            ax = -1;
            sg = -1;
        } else {
            lo = 10.5f;
            hi = 22.83f;
            ax = i % 2;
            sg = 1 - i / 2;
        }
        for (j = 0; j < n; j++) {
            f32 *q;

            {
                s32 k = pick_00330EC8(ax);
                s32 s = rsign_00330EC8(sg);

                qzero(&v);
                q = &(&v.x)[k];
                *q = rand_len_00330EC8(lo, hi, s);
            }
            {
                vu0_v4 w;

                vec_add_ab(&w, &a->pos, &v);
                {
                    vu0_v4 u;

                    {
                        f32 r = func_00382538();

                        func_00382760(&u, 0.40000004f, r, func_003824E0(1.0f, y) * 1.5707964f);
                    }
                    func_L01_00474078(&w, &u, 0x11, 0.08f, 2.0f, 1.5f, 1.0f, 0x80FF2020, 0x80404040, 10, 0);
                }
            }
        }
    }
}
/* localdecomp:end func_L03_00330EC8 */
