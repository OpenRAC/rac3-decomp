#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3BB530.c's earlier functions */
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0760(u8 *, u32);
extern void func_003A0760();
extern void func_11F0A0();
extern void func_003BB7C8(s32 a, s32 *p);

/* localdecomp:start func_003BBA08 */
#include "vu0.h"

typedef struct {
    s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C;
    s32 f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C;
    s32 f80, f84, f88, f8C, f90, f94, f98;
} H_003BBA08;
typedef struct { s32 off; u16 h4; u16 h6; s32 f8; s32 fC; } T_003BBA08;
typedef struct { s32 off; s32 oclass; s32 f8; s32 fC; u8 f10[0x10]; } C_003BBA08;
typedef struct { s32 f0; f32 f4, f8, fC, f10, f14, f18, f1C; s32 f20, f24; } M_003BBA08;
typedef struct { u8 r, g, b, a; } __attribute__((aligned(4))) RGBA_003BBA08;
typedef struct { s32 f0, f4, f8; RGBA_003BBA08 cC, c10, c14; f32 f18, f1C, f20, f24; } F_003BBA08;
typedef struct {
    u8 pad0[0x10]; f32 f10, f14, f18; u8 pad1C[0x24 - 0x1C]; u8 *f24; u8 pad28[4]; f32 f2C;
    u8 b30; u8 pad31; u16 h32; u8 pad34[4]; s32 f38; u8 pad3C[0x7E - 0x3C]; u8 b7E;
    u8 pad7F[0xC0 - 0x7F]; u8 fC0[0x30]; f32 fF0, fF4, fF8; u8 padFC[4];
} O_003BBA08;
typedef struct {
    u8 pad0[0x18]; H_003BBA08 *f18; u8 *f1C; u8 pad20[0x48 - 0x20]; u8 *f48;
    u8 pad4C[0x64 - 0x4C]; u8 *f64; u8 *f68; u8 pad6C[4]; u8 *f70; u8 pad74[4]; s32 f78;
} R_003BBA08;
typedef struct { u8 pad[0x2E0]; s32 f2E0, f2E4; f32 f2E8; u8 pad2EC[0x25C0 - 0x2EC]; s32 f25C0; } G_003BBA08;
typedef struct { u8 pad[0x18]; s32 f18; s32 f1C; u8 pad20[0x2E - 0x20]; s16 h2E; s32 f30; u8 pad34[4]; unsigned long f38; } P_003BBA08;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x12B8 - 0x1288]; struct { s32 a, b; } t[1]; } L_003BBA08;
typedef struct { u8 pad[0x40]; s16 h40; } K_003BBA08;
typedef struct { u8 pad[0x20]; u32 f20; u8 pad24[0x34 - 0x24]; u32 f34; } V_003BBA08;
typedef struct { u8 pad[0x228]; f32 f228, f22C; u8 pad230[8]; f32 f238, f23C; u8 pad240[0x10];
    RGBA_003BBA08 c250, c254, c258; s32 f25C, f260, f264; } E_003BBA08;
typedef struct { u8 *f0; u8 pad4[2]; u8 b6; u8 b7; } X_003BBA08;
typedef struct { u8 pad[0x20]; u8 b20; } Q_003BBA08;

extern G_003BBA08 D_001A4BE0;
extern f32 D_001D9BD0[] __attribute__((section(".sdata")));
extern s32 D_001D9BD8[] __attribute__((section(".sdata")));
extern s32 D_001DA058;
extern V_003BBA08 D_001A1ED0;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern u8 D_001D9D80[];
extern u8 D_002DB190[];
extern u8 D_002DE3B0[];
extern s32 D_002DDC30[];
extern u8 D_001CCFD0[];
extern P_003BBA08 D_0016C580;
extern u32 D_001D54D0;
extern s32 D_001D4B60;
extern K_003BBA08 D_00142660;
extern L_003BBA08 D_00160C40;
extern R_003BBA08 D_00227580_003BBA08;
extern s32 D_001D8CD4;
__asm__(".extern D_001D8CD4, 4");
extern s32 D_001DA668;
extern s32 D_002FD200[];
extern s32 D_001DA48C;
extern s32 D_002DD430[];
extern s32 D_001DA480;
extern unsigned long D_0022CAD0[];
extern u8 D_001D5F30[];
extern s32 D_001D9C04;
extern u8 D_002FF200[];
extern u8 D_002FF600[];
extern u8 D_002FF700[];
extern u8 D_001D6EA0[] __attribute__((section(".sdata")));
extern unsigned long D_001D9F60[];
extern O_003BBA08 *D_001DA49C;
extern O_003BBA08 *D_001DA4A0;
extern O_003BBA08 *D_001DA4A4;
extern s32 D_001DA4B4;
extern u8 *D_001DA4B0;
extern s16 D_002DAFB0[];
extern X_003BBA08 *D_002DA740[];
extern Q_003BBA08 *D_001D9BCC;
extern s32 D_001D8CD8;
__asm__(".extern D_001D8CD8, 4");
extern u8 *D_001DA5C0;
extern s32 D_001DA5C4;
extern s32 D_001DA5C8;
extern s32 D_001DA5CC;
extern u8 D_002FC640[];
extern E_003BBA08 D_00225900;
extern u8 D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 D_002228D0[];
extern f32 D_001DA690;
extern s32 D_001DA4D0;
extern s32 D_001DA5D0;
extern u32 D_001D8CE0;

extern void func_00397EA8(void);
extern void func_0038CB78();
extern void func_0038CBA0();
extern void func_0038CD28();
extern void func_00387268(void);
extern void func_003873C0();
extern void func_003A9108(void);
extern void func_00398C80(s32);
extern void func_00398BB8(s32);
extern void func_00398808(s32);
extern s32 func_003A2680();
extern void func_0038A238(s32);
extern void func_13CDF0(s32);
extern void func_003995A0(u8 *, s32, s32, u8 *);
extern void func_00398668(u8 *);
extern void func_00399D68(u8 *, u8 *, u8 *, s32);
extern void func_00399E80(u8 *, u8 *);
extern void func_00398498(u8 *, u8 *, u8 *, s32);
extern void func_003985B8(u8 *, s32);
extern void func_003C25D8();
extern void func_0038D328(void *, void *);
extern void func_0038D590(void *, void *);
extern void func_003C6F90_003BBA08(void *, s32, s32, s32, s32);
extern u32 func_003C2948(s32, s32);
extern void func_00398A88(s32);
extern void func_00399A08(X_003BBA08 *, s32);
extern void func_00392260_003BBA08(s32, s32, s32);
extern void func_003864C0(s32);
extern void func_00387EF0(void);

void func_003BBA08(s32 reload, s32 unused) {
    G_003BBA08 *g;
    s32 i;
    u8 saved;
    H_003BBA08 *hdr;
    u8 *data;
    u8 *end;
    u8 *base;
    s32 size;
    s32 n;
    u8 sp[0x40] __attribute__((aligned(16)));
    long tex0lo;
    long tex0hi;
    s32 addr;
    u8 *tex;

    g = &D_001A4BE0;
    g->f2E8 = -1.0f;
    g->f2E0 = 0;
    g->f2E4 = 0;
    g->f25C0 = 0;
    {
        s32 j;
        for (j = 0; j < 1; j++) {
            D_001D9BD0[j] = 1.0f;
            D_001D9BD8[j] = 0;
        }
    }
    D_001DA058 = 0x100000;
    func_00397EA8();
    D_001D4BB4 = D_001D4BB0 = D_001A1ED0.f20;
    func_0038CB78(D_001D9D80, 0x87654321, 16);
    func_0038CB78(D_002DB190, -1, 0x2000);
    func_0038CB78(D_002DE3B0, -1, 0xF00);
    func_0038CB78(D_002DDC30, 0, 0xF0);
    func_00387268();
    func_003873C0();
    func_003A9108();
    saved = D_001CCFD0[7];
    D_001CCFD0[7] = 0;
    if (reload != 0) {
        s32 a = (D_001D54D0 >> 16) & 0x1F;
        s32 b;
        if (D_0016C580.f30 != a) {
            func_00398C80(a);
        }
        b = D_001D54D0 & 3;
        if (D_0016C580.f18 != b) {
            func_00398BB8(b);
        }
    }
    {
        s32 c = D_00142660.h40;
        if (D_001D4B60 != c) {
            func_00398808(c);
        }
    }
    D_001CCFD0[7] = saved;
    func_003A2680((u8 *)D_00227580_003BBA08.f18 + 0x400000,
                  D_00160C40.t[D_0016C580.h2E].a + D_00160C40.f1284,
                  D_00160C40.t[D_0016C580.h2E].b);
    func_0038A238(5);
    func_13CDF0(0);
    func_11F0A0(0);
    size = ((s32 (*)(u8 *, u32))func_003A0760)((u8 *)D_00227580_003BBA08.f18 + 0x400000,
                                                (u32)D_00227580_003BBA08.f18);
    func_11F0A0(0);
    hdr = D_00227580_003BBA08.f18;
    end = (u8 *)hdr + size;
    data = (u8 *)hdr + hdr->f8;
    tex = (u8 *)hdr + hdr->f4;
    base = data + hdr->f5C;
    D_00227580_003BBA08.f48 = end;
    D_001D8CD4 = hdr->f0;
    func_003995A0(tex, hdr->f10, 0, (u8 *)hdr + hdr->f14);
    if (D_001D8CD4 & 2) {
        T_003BBA08 *t = (T_003BBA08 *)((u8 *)hdr + hdr->f20);
        s32 cnt = hdr->f1C;
        D_001DA668 = cnt;
        for (i = 0; i < cnt; i++) {
            addr = (s32)base + t[i].off;
            D_002FD200[i] = addr + ((30 - plzcw_asm(t[i].h4)) << 28);
        }
    }
    if (D_001D8CD4 & 4) {
        T_003BBA08 *t = (T_003BBA08 *)((u8 *)hdr + hdr->f3C);
        s32 cnt = hdr->f38;
        D_001DA48C = cnt;
        for (i = 0; i < cnt; i++) {
            addr = (s32)base + t[i].off;
            D_002DD430[i] = addr + ((30 - plzcw_asm(t[i].h4)) << 28);
        }
    }
    if (D_001D8CD4 & 1) {
        func_00398668(data + hdr->f24);
    }
    if (D_001D8CD4 & 4) {
        C_003BBA08 *c = (C_003BBA08 *)((u8 *)hdr + hdr->f30);
        D_001DA480 = 0;
        for (i = 0; i < hdr->f28; i++, c++) {
            u8 *m = c->off ? data + c->off : 0;
            if (c->oclass != 0xD54) {
                if (c->f8 != 0) {
                    D_0022CAD0[1] = 0xFFA0000000E0;
                    D_0022CAD0[0] = D_0016C580.f38;
                    D_0022CAD0[2] = 0x0040000400004000;
                    func_00399D68(m, 0, D_001D5F30, c->oclass);
                    D_002DDC30[D_001DA480 - 1] = 0xFFFC0000;
                } else {
                    func_00399D68(m, (u8 *)hdr + hdr->f3C, c->f10, c->oclass);
                }
            }
        }
    }
    if (D_001D8CD4 & 2) {
        func_00399E80(D_00227580_003BBA08.f1C = data + hdr->f18, (u8 *)hdr + hdr->f20);
    }
    if (D_001D8CD4 & 0x10) {
        func_00398498((u8 *)hdr + hdr->f40, data + hdr->f60, (u8 *)hdr + hdr->f48, hdr->f44);
    }
    D_001D9C04 = (s32)(data + hdr->f64);
    func_003985B8((u8 *)hdr + hdr->f50, hdr->f4C);
    addr = (D_001A1ED0.f34 + hdr->f54 * 4) >> 8;
    tex0lo = (long)addr | 0x1DB08000;
    tex0hi = ((long)(s32)((D_001A1ED0.f20 + hdr->f58) >> 8) << 37) | ((long)0xB800 << 19);
    D_001D9F60[0] = (tex0lo | tex0hi) | ((long)-1 << 63);
    D_001D9F60[1] = 0xFFA0000000E0;
    D_001D9F60[2] = 0x0040000400004000;
    func_0038CBA0(D_002FF600, 0x100);
    func_0038CBA0(D_002FF700, 0x180);
    func_0038CBA0(D_002FF200, 0x400);
    func_0038CD28(D_002FF200, D_001D6EA0, 0x40);
    if (D_001D8CD4 & 0xC) {
        s32 count = 0x41;
        O_003BBA08 *o;
        M_003BBA08 *mp;
        s32 sz;
        n = hdr->f2C;
        D_001DA49C = (O_003BBA08 *)end;
        sz = (n + 0x41) << 8;
        func_0038CB78(end, 0, sz);
        end += sz;
        mp = (M_003BBA08 *)((u8 *)hdr + hdr->f34);
        o = D_001DA49C;
        for (i = 0; i < n; i++) {
            func_003C25D8(o, mp->f0);
            o->h32 = 0xFF;
            o->b30 = 0xFF;
            o->f10 = mp->f4;
            o->f14 = mp->f8;
            o->f18 = mp->fC;
            o->fF0 = mp->f10;
            o->fF4 = mp->f14;
            o->fF8 = mp->f18;
            if (o->f24 != 0) {
                o->f2C = mp->f1C * *(f32 *)(o->f24 + 0x24);
            } else {
                o->f2C = mp->f1C;
            }
            func_0038D328(sp, &o->fF0);
            mp++;
            func_0038D590(o->fC0, sp);
            func_003C6F90_003BBA08(o, 0x303030, 0, 0, 0);
            o->f38 = 0;
            o->b7E &= ~1;
            o++;
        }
        D_001DA4A0 = D_001DA49C + n;
        if (D_001D8CD4 & 8) {
            D_001DA4A0 = D_001DA4A0 + 1;
        }
        D_001DA4A4 = D_001DA4A0 + count;
        ((Q_003BBA08 *)D_001DA4A0)->b20 = 0xFF;
        D_001DA4B4 = count * 2;
        D_001DA4B0 = end;
        end = (u8 *)func_003C2948(0x41, (s32)(end + count * 128));
        {
            Q_003BBA08 *q = (Q_003BBA08 *)(D_001DA4A0 + 1);
            for (i = 0; i < count; i++) {
                q->b20 = 0xFE;
                q = (Q_003BBA08 *)((u8 *)q + 0x100);
            }
        }
        {
            s32 k;
            X_003BBA08 *x;
            D_0016C580.f1C = D_001DA480++;
            k = D_0016C580.f1C;
            D_002DDC30[k] = 0xFFFC0000;
            D_002DAFB0[k] = 0xD54;
            x = (X_003BBA08 *)D_00227580_003BBA08.f70;
            D_002DA740[k] = x;
            D_002DB190[0xD54] = D_0016C580.f1C;
            if (x->b6 != 0) {
                u8 *r = x->f0 + x->b7 * 16;
                u8 *w = *(u8 **)r + *(s32 *)(r + 4) * 16;
                *(unsigned long *)(w - 0x20) = D_001D9F60[0];
                *(unsigned long *)(w - 0x10) = D_001D9F60[2];
            }
        }
        if (D_002DB190[0] != 0xFF) {
            s32 d = D_00142660.h40;
            if (D_001D4B60 != d) {
                func_00398A88(d);
                D_001D4B60 = D_00142660.h40;
            }
            func_00399A08(D_002DA740[0], D_00227580_003BBA08.f78);
            D_002DDC30[0] = 0xFFFC0000;
        }
        if (D_001D8CD4 & 8) {
            D_001D9BCC = (Q_003BBA08 *)(D_001DA4A0 - 1);
            D_001D9BCC->b20 = 0xFD;
        }
    }
    if (D_001D8CD4 & 8) {
        D_001DA058 = D_001DA058 - 0x60000;
        D_001D8CD8 = hdr->f68;
    }
    end += 0x400;
    D_00227580_003BBA08.f64 = end;
    D_001DA5C0 = end;
    end += 0x20000;
    D_001DA5C8 = -1;
    D_001DA5C4 = 0;
    D_001DA5CC = 0;
    func_0038CBA0(D_002FC640, 0x200);
    D_001D8CE0 = hdr->f98;
    if (hdr->f94 != 0) {
        F_003BBA08 *f = (F_003BBA08 *)((u8 *)hdr + hdr->f94);
        D_00225900.f25C = f->f0;
        D_00225900.f260 = f->f4;
        D_00225900.f264 = f->f8;
        D_00225900.c250 = f->cC;
        D_00225900.c254 = f->c10;
        D_00225900.c258 = f->c14;
        D_00225900.f228 = f->f18;
        D_00225900.f22C = f->f1C;
        D_00225900.f238 = f->f20;
        D_00225900.f23C = f->f24;
        D_001D9C46 = D_00225900.c258.r;
        D_001D9C44 = D_00225900.c250.r;
        D_001D9C45 = D_00225900.c254.r;
        D_001D9C48 = D_00225900.f228;
        D_001D9C4C = D_00225900.f22C;
        D_001D9C50 = D_00225900.f238;
        D_001D9C54 = D_00225900.f23C;
        func_00392260_003BBA08(D_00225900.f25C, D_00225900.f260, D_00225900.f264);
        D_002228D0[0] = 0;
        func_003864C0(0);
    }
    func_00387EF0();
    D_00227580_003BBA08.f68 = end;
    D_001DA690 = 983040.0f;
    D_001DA4D0 = 0x3C0;
    D_001DA5D0 = 0x7D0000;
}
/* localdecomp:end func_003BBA08 */
