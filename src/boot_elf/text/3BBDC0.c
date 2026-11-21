#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003A0B60(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0B60(u8 *, u32);
extern void func_003A0B60();
/* --- end of declarations from other files --- */

/* declarations of 3BB948.c's earlier functions */
extern void func_0038CF58();
extern void func_11F0A0();
extern void func_003BBB80(s32 a, s32 *p);

/* localdecomp:start func_003BBDC0 */
#include "vu0.h"

typedef struct { u8 p0[0x2E0]; s32 f2E0; s32 f2E4; f32 f2E8; u8 p2EC[0x25C0 - 0x2EC]; s32 f25C0; } S_1A4BE0_003BBDC0;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_003BBDC0;
typedef struct { u8 p0[0x18]; s32 f18; s32 f1C; u8 p20[0xE]; s16 f2E; s32 f30; u8 p34[4]; unsigned long f38; } S_16C580_003BBDC0;
typedef struct { u8 p0[0x40]; s16 f40; } S_142660_003BBDC0;
typedef struct { u8 p0[0x1284]; s32 f1284; u8 p1288[0x30]; struct { s32 a; s32 b; } e[1]; } S_160C40_003BBDC0;
typedef struct {
    s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C;
    s32 f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C;
    s32 f80, f84, f88, f8C, f90, f94, f98;
} H_003BBDC0;
typedef struct { u8 p0[0x18]; H_003BBDC0 *f18; u8 *f1C; u8 p20[0x28]; u8 *f48; u8 p4C[0x18]; s32 f64; s32 f68; u8 p6C[4]; struct V_003BBDC0 *f70; u8 p74[4]; s32 f78; } S_227580_003BBDC0;
typedef struct { u8 *p; s32 n; u8 p8[8]; } P_003BBDC0;
typedef struct V_003BBDC0 { P_003BBDC0 *f0; u8 p4[2]; u8 f6; u8 f7; } V_003BBDC0;
typedef struct { s32 off; u16 w; u8 p6[0xA]; } T_003BBDC0;
typedef struct { s32 off; s32 cls; s32 f8; s32 fC; u8 f10[0x10]; } E_003BBDC0;
typedef struct { s32 f0; f32 f4, f8, fC, f10, f14, f18, f1C; u8 p20[8]; } R_003BBDC0;
typedef struct { u8 p0[0x24]; f32 f24; } C_003BBDC0;
typedef struct {
    u8 p0[0x10]; f32 f10, f14, f18; u8 p1C[8]; C_003BBDC0 *f24; u8 p28[4]; f32 f2C; u8 f30; u8 p31; s16 f32; u8 p34[4]; s32 f38;
    u8 p3C[0x42]; u8 f7E; u8 p7F[0x41]; u8 fC0[0x30]; f32 fF0, fF4, fF8; u8 pFC[4];
} M_003BBDC0;
typedef struct { u8 p0[0x20]; u8 f20; u8 p21[0xDF]; } N_003BBDC0;
typedef struct {
    u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10];
    s32 f250, f254, f258, f25C, f260, f264;
} S_225900_003BBDC0;
typedef struct { s32 f0, f4, f8, fC, f10, f14; f32 f18, f1C, f20, f24; } F_003BBDC0;

extern S_1A4BE0_003BBDC0 D_001A4BE0_003BBDC0;
extern f32 D_001D9BD0_003BBDC0[2];
extern s32 D_001D9BD8_003BBDC0[2];
extern s32 D_001DA058;
extern s32 D_001A1ED0[];
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern u8 D_001D9D80[];
extern u8 D_002DB190[];
extern s32 D_002DE3B0[];
extern s32 D_002DDC30[];
extern S_1CCFD0_003BBDC0 D_001CCFD0_003BBDC0;
extern S_16C580_003BBDC0 D_0016C580_003BBDC0;
extern u16 D_001D54D2;
extern u32 D_001D54D0;
extern S_142660_003BBDC0 D_00142660_003BBDC0;
extern s32 D_001D4B60_003BBDC0;
extern S_160C40_003BBDC0 D_00160C40_003BBDC0;
extern S_227580_003BBDC0 D_00227580_003BBDC0;
__asm__(".extern D_001D8CD4, 4");
extern s32 D_001D8CD4;
extern s32 D_001DA668;
extern s32 D_002FD200[];
extern s32 D_001DA48C;
extern s32 D_002DD430[];
extern s32 D_001DA480;
extern unsigned long D_0022CAD0[3];
extern s32 D_001D5F30_003BBDC0[];
extern s32 D_001D9C04;
extern u8 D_002FF200[];
extern unsigned long D_001D9F60[];
extern u8 D_002FF600_003BBDC0[];
extern u8 D_002FF700[];
extern u8 D_001D6EA0[8];
extern M_003BBDC0 *D_001DA49C_003BBDC0;
extern V_003BBDC0 *D_002DA740_003BBDC0[];
extern N_003BBDC0 *D_001DA4A0_003BBDC0;
extern N_003BBDC0 *D_001DA4A4_003BBDC0;
extern s32 D_001DA4B4;
extern u8 *D_001DA4B0_003BBDC0;
extern s16 D_002DAFB0[];
extern N_003BBDC0 *D_001D9BCC_003BBDC0;
__asm__(".extern D_001D8CD8, 4");
extern s32 D_001D8CD8;
extern u8 *D_001DA5C0_003BBDC0;
extern s32 D_001DA5C8_003BBDC0;
extern s32 D_001DA5C4_003BBDC0;
extern s32 D_001DA5CC;
extern u8 D_002FC640[];
extern u32 D_001D8CE0;
extern S_225900_003BBDC0 D_00225900_003BBDC0;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 D_002228D0[];
extern f32 D_001DA690;
extern s32 D_001DA4D0;
extern s32 D_001DA5D0;

extern void func_00398288(void);
extern void func_0038CF58(void *, s32, s32);
extern void func_00387648(void);
extern void func_003877A0(void);
extern void func_003A94C0(void);
extern void func_00399060(s32);
extern void func_00398F98(s32);
extern void func_00398BE8(s32);
extern s32 func_003A2A80(u8 *, s32, s32);
extern void func_0038A618(s32);
extern s32 func_0013CDF0(s32);
extern void func_0011F0A0(s32);
extern void func_00399980(u8 *, s32, s32, s32 *);
extern void func_00398A48(u8 *);
extern void func_0039A148(char *, s32, void *, s32);
extern void func_0039A260(u8 *, u8 *);
extern void func_00398878(s32 *, s32, s32 *, s32);
extern void func_00398998(u8 *, s32);
extern void func_0038CF80(void *, s32);
extern void func_0038D108(void *, void *, s32);
extern void func_003C2990();
extern void func_0038D708(void *, f32 *);
extern void func_0038D970(void *, void *);
extern unsigned long func_003C7348(u8 *, unsigned long, unsigned long, unsigned long, unsigned long);
extern u32 func_003C2D00(s32, s32);
extern void func_00398E68(s32);
extern void func_00399DE8(u8 *, u8 *);
extern void func_00392640(s32, long, long);
extern void func_003868A0(s32);
extern void func_003882D0(void);

void func_003BBDC0(s32 a0) {
    f32 mtx[16];
    H_003BBDC0 *h;
    u8 *base;
    u8 *buf;
    u8 *mem;
    s32 i;
    s32 n;
    s32 r;
    u8 saved;
    s32 extra;
    s32 p;

    D_001A4BE0_003BBDC0.f2E8 = -1.0f;
    D_001A4BE0_003BBDC0.f2E0 = 0;
    D_001A4BE0_003BBDC0.f2E4 = 0;
    D_001A4BE0_003BBDC0.f25C0 = 0;
    {
        s32 j;
        for (j = 0; j < 1; j++) {
            D_001D9BD0_003BBDC0[j] = 1.0f;
            D_001D9BD8_003BBDC0[j] = 0;
        }
    }
    D_001DA058 = 0x100000;
    func_00398288();
    {
        s32 v = D_001A1ED0[8];
        D_001D4BB0 = v;
        D_001D4BB4 = v;
    }
    func_0038CF58(D_001D9D80, 0x87654321, 0x10);
    func_0038CF58(D_002DB190, -1, 0x2000);
    func_0038CF58(D_002DE3B0, -1, 0xF00);
    func_0038CF58(D_002DDC30, 0, 0xF0);
    func_00387648();
    func_003877A0();
    func_003A94C0();
    saved = D_001CCFD0_003BBDC0.f7;
    D_001CCFD0_003BBDC0.f7 = 0;
    if (a0 != 0) {
        s32 t;
        S_16C580_003BBDC0 *g;
        t = D_001D54D2 & 0x1F;
        g = &D_0016C580_003BBDC0;
        if (g->f30 != t) {
            func_00399060(t);
        }
        if (g->f18 != (D_001D54D0 & 3)) {
            func_00398F98(D_001D54D0 & 3);
        }
    }
    if (D_001D4B60_003BBDC0 != D_00142660_003BBDC0.f40) {
        func_00398BE8(D_00142660_003BBDC0.f40);
    }
    D_001CCFD0_003BBDC0.f7 = saved;
    {
        S_160C40_003BBDC0 *b = &D_00160C40_003BBDC0;
        s32 k = D_0016C580_003BBDC0.f2E;
        func_003A2A80((u8 *)D_00227580_003BBDC0.f18 + 0x400000, b->e[k].a + b->f1284, b->e[k].b);
    }
    func_0038A618(5);
    func_0013CDF0(0);
    func_0011F0A0(0);
    r = ((s32 (*)(u8 *, u32))func_003A0B60)((u8 *)D_00227580_003BBDC0.f18 + 0x400000, (u32)D_00227580_003BBDC0.f18);
    func_0011F0A0(0);
    h = D_00227580_003BBDC0.f18;
    mem = (u8 *)h + r;
    base = (u8 *)h + h->f8;
    {
        u8 *p4 = (u8 *)h + h->f4;
        buf = base + h->f5C;
        D_00227580_003BBDC0.f48 = mem;
        D_001D8CD4 = h->f0;
        func_00399980(p4, h->f10, 0, (s32 *)((u8 *)h + h->f14));
    }
    if (D_001D8CD4 & 2) {
        T_003BBDC0 *t = (T_003BBDC0 *)((u8 *)h + h->f20);
        s32 c = h->f1C;
        D_001DA668 = c;
        for (i = 0; i < c; i++) {
            p = (s32)(buf + t[i].off);
            D_002FD200[i] = p + ((30 - plzcw_asm(t[i].w)) << 28);
        }
    }
    if (D_001D8CD4 & 4) {
        T_003BBDC0 *t = (T_003BBDC0 *)((u8 *)h + h->f3C);
        s32 c = h->f38;
        D_001DA48C = c;
        for (i = 0; i < c; i++) {
            p = (s32)(buf + t[i].off);
            D_002DD430[i] = p + ((30 - plzcw_asm(t[i].w)) << 28);
        }
    }
    if (D_001D8CD4 & 1) {
        func_00398A48(base + h->f24);
    }
    if (D_001D8CD4 & 4) {
        E_003BBDC0 *e = (E_003BBDC0 *)((u8 *)h + h->f30);
        D_001DA480 = 0;
        for (i = 0; i < h->f28; i++, e++) {
            p = 0;
            if (e->off != 0) p = (s32)(base + e->off);
            if (e->cls != 0xD54) {
                if (e->f8 != 0) {
                    D_0022CAD0[0] = D_0016C580_003BBDC0.f38;
                    D_0022CAD0[1] = 0xFFA0000000E0;
                    D_0022CAD0[2] = 0x40000400004000;
                    func_0039A148((char *)p, 0, D_001D5F30_003BBDC0, e->cls);
                    D_002DDC30[D_001DA480 - 1] = 0xFFFC0000;
                } else {
                    func_0039A148((char *)p, (s32)((u8 *)h + h->f3C), e->f10, e->cls);
                }
            }
        }
    }
    if (D_001D8CD4 & 2) {
        u8 *tex = base + h->f18;
        D_00227580_003BBDC0.f1C = tex;
        func_0039A260(tex, (u8 *)h + h->f20);
    }
    if (D_001D8CD4 & 0x10) {
        func_00398878((s32 *)((u8 *)h + h->f40), (s32)(base + h->f60), (s32 *)((u8 *)h + h->f48), h->f44);
    }
    D_001D9C04 = (s32)(base + h->f64);
    func_00398998((u8 *)h + h->f50, h->f4C);
    {
        s32 cbp;
        p = (u32)(D_001A1ED0[13] + (h->f54 << 2)) >> 8;
        cbp = (u32)(D_001A1ED0[8] + h->f58) >> 8;
        D_001D9F60[0] = (unsigned long)p | ((unsigned long)2 << 14) | ((unsigned long)0x1B << 20)
            | ((unsigned long)7 << 26) | ((unsigned long)7 << 30) | ((unsigned long)1 << 34)
            | ((unsigned long)cbp << 37) | ((unsigned long)4 << 61);
        D_001D9F60[1] = 0xFFA0000000E0;
        D_001D9F60[2] = 0x40000400004000;
    }
    func_0038CF80(D_002FF600_003BBDC0, 0x100);
    func_0038CF80(D_002FF700, 0x180);
    func_0038CF80(D_002FF200, 0x400);
    func_0038D108(D_002FF200, D_001D6EA0, 0x40);
    if (D_001D8CD4 & 0xC) {
        R_003BBDC0 *r;
        M_003BBDC0 *m;
        N_003BBDC0 *q;
        n = h->f2C;
        D_001DA49C_003BBDC0 = (M_003BBDC0 *)mem;
        extra = 0x41;
        func_0038CF58(mem, 0, (n + extra) << 8);
        mem += (n + extra) << 8;
        r = (R_003BBDC0 *)((u8 *)h + h->f34);
        m = D_001DA49C_003BBDC0;
        for (i = 0; i < n; i++) {
            func_003C2990(m, r->f0);
            m->f32 = 0xFF;
            m->f30 = 0xFF;
            m->f10 = r->f4;
            m->f14 = r->f8;
            m->f18 = r->fC;
            m->fF0 = r->f10;
            m->fF4 = r->f14;
            m->fF8 = r->f18;
            if (m->f24 != 0) {
                m->f2C = r->f1C * m->f24->f24;
            } else {
                m->f2C = r->f1C;
            }
            func_0038D708(mtx, &m->fF0);
            r++;
            func_0038D970(m->fC0, mtx);
            ((void (*)(u8 *, s32, s32, s32, s32))func_003C7348)((u8 *)m, 0x303030, 0, 0, 0);
            m->f7E &= 0xFE;
            m->f38 = 0;
            m++;
        }
        D_001DA4A0_003BBDC0 = (N_003BBDC0 *)((u8 *)D_001DA49C_003BBDC0 + (n << 8));
        if (D_001D8CD4 & 8) {
            D_001DA4A0_003BBDC0 = D_001DA4A0_003BBDC0 + 1;
        }
        q = D_001DA4A0_003BBDC0;
        D_001DA4A4_003BBDC0 = q + extra;
        q->f20 = 0xFF;
        D_001DA4B4 = extra * 2;
        D_001DA4B0_003BBDC0 = mem;
        mem = (u8 *)func_003C2D00(extra, (s32)(mem + extra * 0x80));
        {
            N_003BBDC0 *o = D_001DA4A0_003BBDC0 + 1;
            for (i = 0; i < extra; i++) {
                o->f20 = 0xFE;
                o++;
            }
        }
        {
            S_16C580_003BBDC0 *g = &D_0016C580_003BBDC0;
            V_003BBDC0 *v;
            s32 k = D_001DA480;
            g->f1C = k;
            k++;
            D_001DA480 = k;
            D_002DDC30[g->f1C] = 0xFFFC0000;
            D_002DAFB0[g->f1C] = 0xD54;
            D_002DA740_003BBDC0[g->f1C] = v = D_00227580_003BBDC0.f70;
            D_002DB190[0xD54] = *(u8 *)&g->f1C;
            if (v->f6 != 0) {
                P_003BBDC0 *pe = &v->f0[v->f7];
                u8 *d = pe->p + (pe->n << 4);
                *(unsigned long *)(d - 0x20) = D_001D9F60[0];
                *(unsigned long *)(d - 0x10) = D_001D9F60[2];
            }
        }
        if (D_002DB190[0] != 0xFF) {
            if (D_001D4B60_003BBDC0 != D_00142660_003BBDC0.f40) {
                func_00398E68(D_00142660_003BBDC0.f40);
                D_001D4B60_003BBDC0 = D_00142660_003BBDC0.f40;
            }
            func_00399DE8((u8 *)D_002DA740_003BBDC0[0], (u8 *)D_00227580_003BBDC0.f78);
            D_002DDC30[0] = 0xFFFC0000;
        }
        if (D_001D8CD4 & 8) {
            D_001D9BCC_003BBDC0 = D_001DA4A0_003BBDC0 - 1;
            D_001D9BCC_003BBDC0->f20 = 0xFD;
        }
    }
    if (D_001D8CD4 & 8) {
        D_001DA058 = D_001DA058 - 0x60000;
        D_001D8CD8 = h->f68;
    }
    mem += 0x400;
    D_00227580_003BBDC0.f64 = (s32)mem;
    D_001DA5C0_003BBDC0 = mem;
    mem += 0x20000;
    D_001DA5C8_003BBDC0 = -1;
    D_001DA5C4_003BBDC0 = 0;
    D_001DA5CC = 0;
    func_0038CF80(D_002FC640, 0x200);
    D_001D8CE0 = h->f98;
    if (h->f94 != 0) {
        F_003BBDC0 *f = (F_003BBDC0 *)((u8 *)h + h->f94);
        S_225900_003BBDC0 *g = &D_00225900_003BBDC0;
        s32 a, b, c;
        a = f->f0;
        g->f25C = a;
        b = f->f4;
        g->f260 = b;
        c = f->f8;
        g->f264 = c;
        g->f250 = f->fC;
        g->f254 = f->f10;
        g->f258 = f->f14;
        g->f228 = f->f18;
        g->f22C = f->f1C;
        g->f238 = f->f20;
        g->f23C = f->f24;
        D_001D9C44 = *(u8 *)&g->f250;
        D_001D9C45 = *(u8 *)&g->f254;
        D_001D9C46 = *(u8 *)&g->f258;
        D_001D9C48 = g->f228;
        D_001D9C4C = g->f22C;
        D_001D9C50 = g->f238;
        D_001D9C54 = g->f23C;
        func_00392640(a, b, c);
        D_002228D0[0] = 0;
        func_003868A0(0);
    }
    func_003882D0();
    D_00227580_003BBDC0.f68 = (s32)mem;
    D_001DA690 = 983040.0f;
    D_001DA4D0 = 0x3C0;
    D_001DA5D0 = 0x7D0000;
}
/* localdecomp:end func_003BBDC0 */
