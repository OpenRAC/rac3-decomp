#include "common.h"

/* NTSC-U counterpart of func_003BBA08 (src/frontbin/3BBA08.c): func_U_00385B60(5) -> (6) */
/* localdecomp:start func_U_003B6528 */
/* localdecomp:start func_U_003B6528 */
#include "vu0.h"

typedef struct {
    s32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C, f30, f34, f38, f3C;
    s32 f40, f44, f48, f4C, f50, f54, f58, f5C, f60, f64, f68, f6C, f70, f74, f78, f7C;
    s32 f80, f84, f88, f8C, f90, f94, f98;
} H_003B6528;
typedef struct { s32 off; u16 h4; u16 h6; s32 f8; s32 fC; } T_003B6528;
typedef struct { s32 off; s32 oclass; s32 f8; s32 fC; u8 f10[0x10]; } C_003B6528;
typedef struct { s32 f0; f32 f4, f8, fC, f10, f14, f18, f1C; s32 f20, f24; } M_003B6528;
typedef struct { u8 r, g, b, a; } __attribute__((aligned(4))) RGBA_003B6528;
typedef struct { s32 f0, f4, f8; RGBA_003B6528 cC, c10, c14; f32 f18, f1C, f20, f24; } F_003B6528;
typedef struct {
    u8 pad0[0x10]; f32 f10, f14, f18; u8 pad1C[0x24 - 0x1C]; u8 *f24; u8 pad28[4]; f32 f2C;
    u8 b30; u8 pad31; u16 h32; u8 pad34[4]; s32 f38; u8 pad3C[0x7E - 0x3C]; u8 b7E;
    u8 pad7F[0xC0 - 0x7F]; u8 fC0[0x30]; f32 fF0, fF4, fF8; u8 padFC[4];
} O_003B6528;
typedef struct {
    u8 pad0[0x18]; H_003B6528 *f18; u8 *f1C; u8 pad20[0x48 - 0x20]; u8 *f48;
    u8 pad4C[0x64 - 0x4C]; u8 *f64; u8 *f68; u8 pad6C[4]; u8 *f70; u8 pad74[4]; s32 f78;
} R_003B6528;
typedef struct { u8 pad[0x2E0]; s32 f2E0, f2E4; f32 f2E8; u8 pad2EC[0x25C0 - 0x2EC]; s32 f25C0; } G_003B6528;
typedef struct { u8 pad[0x18]; s32 f18; s32 f1C; u8 pad20[0x2E - 0x20]; s16 h2E; s32 f30; u8 pad34[4]; unsigned long f38; } P_003B6528;
typedef struct { u8 pad[0x1284]; s32 f1284; u8 pad1288[0x12B8 - 0x1288]; struct { s32 a, b; } t[1]; } L_003B6528;
typedef struct { u8 pad[0x40]; s16 h40; } K_003B6528;
typedef struct { u8 pad[0x20]; u32 f20; u8 pad24[0x34 - 0x24]; u32 f34; } V_003B6528;
typedef struct { u8 pad[0x228]; f32 f228, f22C; u8 pad230[8]; f32 f238, f23C; u8 pad240[0x10];
    RGBA_003B6528 c250, c254, c258; s32 f25C, f260, f264; } E_003B6528;
typedef struct { u8 *f0; u8 pad4[2]; u8 b6; u8 b7; } X_003B6528;
typedef struct { u8 pad[0x20]; u8 b20; } Q_003B6528;

extern G_003B6528 D_001A4BE0;
extern f32 D_U_001D9C50[] __attribute__((section(".sdata")));
extern s32 D_U_001D9C58[] __attribute__((section(".sdata")));
extern s32 D_U_001DA0D8;
extern V_003B6528 D_001A1ED0;
extern s32 D_001D4BB0;
extern s32 D_001D4BB4;
extern u8 D_U_001D9E00[];
extern u8 D_U_002D7210[];
extern u8 D_U_002DA430[];
extern s32 D_U_002D9CB0[];
extern u8 D_001CCFD0[];
extern P_003B6528 D_0016C580;
extern u32 D_001D54D0;
extern s32 D_001D4B60;
extern K_003B6528 D_00142660;
extern L_003B6528 D_00160C40;
extern R_003B6528 D_U_00227600;
extern s32 D_U_001D8D04;
__asm__(".extern D_U_001D8D04, 4");
extern s32 D_U_001DA6E8;
extern s32 D_U_002F9280[];
extern s32 D_U_001DA50C;
extern s32 D_U_002D94B0[];
extern s32 D_U_001DA500;
extern unsigned long D_U_00228B50[];
extern u8 D_U_001D5F30[];
extern s32 D_U_001D9C84;
extern u8 D_U_002FB280[];
extern u8 D_U_002FB680[];
extern u8 D_U_002FB780[];
extern u8 D_U_001D6EA0[] __attribute__((section(".sdata")));
extern unsigned long D_U_001D9FE0[];
extern O_003B6528 *D_U_001DA51C;
extern O_003B6528 *D_U_001DA520;
extern O_003B6528 *D_U_001DA524;
extern s32 D_U_001DA534;
extern u8 *D_U_001DA530;
extern s16 D_U_002D7030[];
extern X_003B6528 *D_U_002D67C0[];
extern Q_003B6528 *D_U_001D9C4C;
extern s32 D_U_001D8D08;
__asm__(".extern D_U_001D8D08, 4");
extern u8 *D_U_001DA640;
extern s32 D_U_001DA644;
extern s32 D_U_001DA648;
extern s32 D_U_001DA64C;
extern u8 D_U_002F86C0[];
extern E_003B6528 D_U_00225980;
extern u8 D_U_001D9CC4, D_U_001D9CC5, D_U_001D9CC6;
extern f32 D_U_001D9CC8, D_U_001D9CCC, D_U_001D9CD0, D_U_001D9CD4;
extern s32 D_U_00222950[];
extern f32 D_U_001DA710;
extern s32 D_U_001DA550;
extern s32 D_U_001DA650;
extern u32 D_U_001D8D10;

extern void func_U_00393580(void);
extern void func_U_00388440();
extern void func_U_00388468();
extern void func_U_003885F0();
extern void func_U_00382F90(void);
extern void func_U_003830E8();
extern void func_U_003A3BB8(void);
extern void func_U_00393E90(s32);
extern void func_U_00393DC8(s32);
extern void func_U_00393A18(s32);
extern s32 func_U_0039D5F8();
extern void func_U_00385B60(s32);
extern void func_13CDF0(s32);
extern void func_11F0A0();
extern void func_U_0039B760(u8 *, u32);
extern void func_U_003947B0(u8 *, s32, s32, u8 *);
extern void func_U_00393878(u8 *);
extern void func_U_00394F78(u8 *, u8 *, u8 *, s32);
extern void func_U_00395090(u8 *, u8 *);
extern void func_U_003936A8(u8 *, u8 *, u8 *, s32);
extern void func_U_003937C8(u8 *, s32);
extern void func_U_003BD0D8();
extern void func_U_00388BF0(void *, void *);
extern void func_U_00388E58(void *, void *);
extern void func_U_003C1A40(void *, s32, s32, s32, s32);
extern u32 func_U_003BD428(s32, s32);
extern void func_U_00393C98(s32);
extern void func_U_00394C18(X_003B6528 *, s32);
extern void func_U_0038DA28(s32, s32, s32);
extern void func_U_003821E8(s32);
extern void func_U_00383848(void);

void func_U_003B6528(s32 reload, s32 unused) {
    G_003B6528 *g;
    s32 i;
    u8 saved;
    H_003B6528 *hdr;
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
            D_U_001D9C50[j] = 1.0f;
            D_U_001D9C58[j] = 0;
        }
    }
    D_U_001DA0D8 = 0x100000;
    func_U_00393580();
    D_001D4BB4 = D_001D4BB0 = D_001A1ED0.f20;
    func_U_00388440(D_U_001D9E00, 0x87654321, 16);
    func_U_00388440(D_U_002D7210, -1, 0x2000);
    func_U_00388440(D_U_002DA430, -1, 0xF00);
    func_U_00388440(D_U_002D9CB0, 0, 0xF0);
    func_U_00382F90();
    func_U_003830E8();
    func_U_003A3BB8();
    saved = D_001CCFD0[7];
    D_001CCFD0[7] = 0;
    if (reload != 0) {
        s32 a = (D_001D54D0 >> 16) & 0x1F;
        s32 b;
        if (D_0016C580.f30 != a) {
            func_U_00393E90(a);
        }
        b = D_001D54D0 & 3;
        if (D_0016C580.f18 != b) {
            func_U_00393DC8(b);
        }
    }
    {
        s32 c = D_00142660.h40;
        if (D_001D4B60 != c) {
            func_U_00393A18(c);
        }
    }
    D_001CCFD0[7] = saved;
    func_U_0039D5F8((u8 *)D_U_00227600.f18 + 0x400000,
                  D_00160C40.t[D_0016C580.h2E].a + D_00160C40.f1284,
                  D_00160C40.t[D_0016C580.h2E].b);
    func_U_00385B60(6);
    func_13CDF0(0);
    func_11F0A0(0);
    size = ((s32 (*)(u8 *, u32))func_U_0039B760)((u8 *)D_U_00227600.f18 + 0x400000,
                                                (u32)D_U_00227600.f18);
    func_11F0A0(0);
    hdr = D_U_00227600.f18;
    end = (u8 *)hdr + size;
    data = (u8 *)hdr + hdr->f8;
    tex = (u8 *)hdr + hdr->f4;
    base = data + hdr->f5C;
    D_U_00227600.f48 = end;
    D_U_001D8D04 = hdr->f0;
    func_U_003947B0(tex, hdr->f10, 0, (u8 *)hdr + hdr->f14);
    if (D_U_001D8D04 & 2) {
        T_003B6528 *t = (T_003B6528 *)((u8 *)hdr + hdr->f20);
        s32 cnt = hdr->f1C;
        D_U_001DA6E8 = cnt;
        for (i = 0; i < cnt; i++) {
            addr = (s32)base + t[i].off;
            D_U_002F9280[i] = addr + ((30 - plzcw_asm(t[i].h4)) << 28);
        }
    }
    if (D_U_001D8D04 & 4) {
        T_003B6528 *t = (T_003B6528 *)((u8 *)hdr + hdr->f3C);
        s32 cnt = hdr->f38;
        D_U_001DA50C = cnt;
        for (i = 0; i < cnt; i++) {
            addr = (s32)base + t[i].off;
            D_U_002D94B0[i] = addr + ((30 - plzcw_asm(t[i].h4)) << 28);
        }
    }
    if (D_U_001D8D04 & 1) {
        func_U_00393878(data + hdr->f24);
    }
    if (D_U_001D8D04 & 4) {
        C_003B6528 *c = (C_003B6528 *)((u8 *)hdr + hdr->f30);
        D_U_001DA500 = 0;
        for (i = 0; i < hdr->f28; i++, c++) {
            u8 *m = c->off ? data + c->off : 0;
            if (c->oclass != 0xD54) {
                if (c->f8 != 0) {
                    D_U_00228B50[1] = 0xFFA0000000E0;
                    D_U_00228B50[0] = D_0016C580.f38;
                    D_U_00228B50[2] = 0x0040000400004000;
                    func_U_00394F78(m, 0, D_U_001D5F30, c->oclass);
                    D_U_002D9CB0[D_U_001DA500 - 1] = 0xFFFC0000;
                } else {
                    func_U_00394F78(m, (u8 *)hdr + hdr->f3C, c->f10, c->oclass);
                }
            }
        }
    }
    if (D_U_001D8D04 & 2) {
        func_U_00395090(D_U_00227600.f1C = data + hdr->f18, (u8 *)hdr + hdr->f20);
    }
    if (D_U_001D8D04 & 0x10) {
        func_U_003936A8((u8 *)hdr + hdr->f40, data + hdr->f60, (u8 *)hdr + hdr->f48, hdr->f44);
    }
    D_U_001D9C84 = (s32)(data + hdr->f64);
    func_U_003937C8((u8 *)hdr + hdr->f50, hdr->f4C);
    addr = (D_001A1ED0.f34 + hdr->f54 * 4) >> 8;
    tex0lo = (long)addr | 0x1DB08000;
    tex0hi = ((long)(s32)((D_001A1ED0.f20 + hdr->f58) >> 8) << 37) | ((long)0xB800 << 19);
    D_U_001D9FE0[0] = (tex0lo | tex0hi) | ((long)-1 << 63);
    D_U_001D9FE0[1] = 0xFFA0000000E0;
    D_U_001D9FE0[2] = 0x0040000400004000;
    func_U_00388468(D_U_002FB680, 0x100);
    func_U_00388468(D_U_002FB780, 0x180);
    func_U_00388468(D_U_002FB280, 0x400);
    func_U_003885F0(D_U_002FB280, D_U_001D6EA0, 0x40);
    if (D_U_001D8D04 & 0xC) {
        s32 count = 0x41;
        O_003B6528 *o;
        M_003B6528 *mp;
        s32 sz;
        n = hdr->f2C;
        D_U_001DA51C = (O_003B6528 *)end;
        sz = (n + 0x41) << 8;
        func_U_00388440(end, 0, sz);
        end += sz;
        mp = (M_003B6528 *)((u8 *)hdr + hdr->f34);
        o = D_U_001DA51C;
        for (i = 0; i < n; i++) {
            func_U_003BD0D8(o, mp->f0);
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
            func_U_00388BF0(sp, &o->fF0);
            mp++;
            func_U_00388E58(o->fC0, sp);
            func_U_003C1A40(o, 0x303030, 0, 0, 0);
            o->f38 = 0;
            o->b7E &= ~1;
            o++;
        }
        D_U_001DA520 = D_U_001DA51C + n;
        if (D_U_001D8D04 & 8) {
            D_U_001DA520 = D_U_001DA520 + 1;
        }
        D_U_001DA524 = D_U_001DA520 + count;
        ((Q_003B6528 *)D_U_001DA520)->b20 = 0xFF;
        D_U_001DA534 = count * 2;
        D_U_001DA530 = end;
        end = (u8 *)func_U_003BD428(0x41, (s32)(end + count * 128));
        {
            Q_003B6528 *q = (Q_003B6528 *)(D_U_001DA520 + 1);
            for (i = 0; i < count; i++) {
                q->b20 = 0xFE;
                q = (Q_003B6528 *)((u8 *)q + 0x100);
            }
        }
        {
            s32 k;
            X_003B6528 *x;
            D_0016C580.f1C = D_U_001DA500++;
            k = D_0016C580.f1C;
            D_U_002D9CB0[k] = 0xFFFC0000;
            D_U_002D7030[k] = 0xD54;
            x = (X_003B6528 *)D_U_00227600.f70;
            D_U_002D67C0[k] = x;
            D_U_002D7210[0xD54] = D_0016C580.f1C;
            if (x->b6 != 0) {
                u8 *r = x->f0 + x->b7 * 16;
                u8 *w = *(u8 **)r + *(s32 *)(r + 4) * 16;
                *(unsigned long *)(w - 0x20) = D_U_001D9FE0[0];
                *(unsigned long *)(w - 0x10) = D_U_001D9FE0[2];
            }
        }
        if (D_U_002D7210[0] != 0xFF) {
            s32 d = D_00142660.h40;
            if (D_001D4B60 != d) {
                func_U_00393C98(d);
                D_001D4B60 = D_00142660.h40;
            }
            func_U_00394C18(D_U_002D67C0[0], D_U_00227600.f78);
            D_U_002D9CB0[0] = 0xFFFC0000;
        }
        if (D_U_001D8D04 & 8) {
            D_U_001D9C4C = (Q_003B6528 *)(D_U_001DA520 - 1);
            D_U_001D9C4C->b20 = 0xFD;
        }
    }
    if (D_U_001D8D04 & 8) {
        D_U_001DA0D8 = D_U_001DA0D8 - 0x60000;
        D_U_001D8D08 = hdr->f68;
    }
    end += 0x400;
    D_U_00227600.f64 = end;
    D_U_001DA640 = end;
    end += 0x20000;
    D_U_001DA648 = -1;
    D_U_001DA644 = 0;
    D_U_001DA64C = 0;
    func_U_00388468(D_U_002F86C0, 0x200);
    D_U_001D8D10 = hdr->f98;
    if (hdr->f94 != 0) {
        F_003B6528 *f = (F_003B6528 *)((u8 *)hdr + hdr->f94);
        D_U_00225980.f25C = f->f0;
        D_U_00225980.f260 = f->f4;
        D_U_00225980.f264 = f->f8;
        D_U_00225980.c250 = f->cC;
        D_U_00225980.c254 = f->c10;
        D_U_00225980.c258 = f->c14;
        D_U_00225980.f228 = f->f18;
        D_U_00225980.f22C = f->f1C;
        D_U_00225980.f238 = f->f20;
        D_U_00225980.f23C = f->f24;
        D_U_001D9CC6 = D_U_00225980.c258.r;
        D_U_001D9CC4 = D_U_00225980.c250.r;
        D_U_001D9CC5 = D_U_00225980.c254.r;
        D_U_001D9CC8 = D_U_00225980.f228;
        D_U_001D9CCC = D_U_00225980.f22C;
        D_U_001D9CD0 = D_U_00225980.f238;
        D_U_001D9CD4 = D_U_00225980.f23C;
        func_U_0038DA28(D_U_00225980.f25C, D_U_00225980.f260, D_U_00225980.f264);
        D_U_00222950[0] = 0;
        func_U_003821E8(0);
    }
    func_U_00383848();
    D_U_00227600.f68 = end;
    D_U_001DA710 = 983040.0f;
    D_U_001DA550 = 0x3C0;
    D_U_001DA650 = 0x7D0000;
}
/* localdecomp:end func_U_003B6528 */
/* localdecomp:end func_U_003B6528 */
