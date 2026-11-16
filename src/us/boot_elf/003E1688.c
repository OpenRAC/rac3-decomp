#include "common.h"

/* NTSC-U counterpart of func_003E17D0 (boot_elf). */
/* localdecomp:start func_U_003E1688 */
typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3DBEC8;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    s32 f44;
    u8 pad48[0x58 - 0x48];
    s32 f58;
    s32 f5C;
    s32 f60;
    u8 pad64[0x7C - 0x64];
    s16 f7C, f7E;
    s32 f80;
    u8 pad84[0x98 - 0x84];
} S_3DBEC8;

__asm__(".extern D_U_001D94DC, 4");
__asm__(".extern D_U_001D94E0, 4");
__asm__(".extern D_U_001D94E4, 4");
__asm__(".extern D_U_001D94E8, 1");
__asm__(".extern D_U_001D94FC, 4");
__asm__(".extern D_U_001D9500, 4");

extern S_3DBEC8 D_U_00306D80_003E1688;
extern T_3DBEC8 D_U_001D9510;
extern T_3DBEC8 D_U_001D9550;
extern char D_U_001D9530[];
extern char D_U_001D9538[];
extern char D_U_001D9540[];
extern char D_U_001D9570[];
extern s32 D_U_001D9C48;
extern u16 D_001D4BC4;
extern s32 D_U_001D5B90;
extern s32 D_001D4CE8;
extern u8 D_U_001DA020;
extern u8 D_U_001D5BDC;
extern u8 D_U_001D5BDD;
extern f32 D_U_001DA0F4;
extern s32 D_U_001DA0F0;
extern char *D_U_001D94DC;
extern char *D_U_001D94E0;
extern char *D_U_001D94E4;
extern u8 D_U_001D94E8;
extern s32 D_U_001D94FC;
extern s32 D_U_001D9500;
extern u8 D_U_00335860[];

extern void func_U_0038B148(s32, s32, s32, s32);
extern void func_U_003895C8(s32);
extern void func_U_003A96B0(s32, unsigned long);
extern char *func_U_00382488(s32);
extern s32 func_0011BB58(void *, void *, s32);
extern s32 func_0011B868(void *);
extern void func_U_0038FD40(T_3DBEC8 *, unsigned long, void *, s32, unsigned long, f32, f32);
extern void func_U_003AF620(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_U_00396C60(s32, s32);
extern void func_U_00396F58(s32, s32, s32, s32, s32, s32);
extern s32 func_U_00396D30(s32);
extern void func_U_00397930(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_U_0038E478(s32);
extern void func_U_003824B0(void);
extern void func_0011B2E8();
extern void func_U_0038C6D8(s32, s32, s32, s32, s32, s32);
extern s32 func_U_0038DF00(s32, s32, f32);
extern s32 func_U_003910D8(s32, s32, s32, void *, s32);
extern long func_U_00389920(s32);
extern void func_U_00391400(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_U_003913E0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_U_003896F8(void);

void func_U_003E1688(void) {
    char buf[0x200];
    T_3DBEC8 s210;
    T_3DBEC8 s230;
    T_3DBEC8 s250;
    char buf2[0x100];
    s32 tmp;
    T_3DBEC8 *ps;

    if (D_U_00306D80_003E1688.f7E == 0) {
        func_U_0038B148(0, 0, 0, 0x30);
    }
    if (D_U_00306D80_003E1688.f7C != 0) {
        return;
    }
    func_U_003895C8(0);
    func_U_003A96B0(0x42, 0x8000000044UL);
    func_U_003A96B0(0x47, 0x5360B);
    switch (D_U_00306D80_003E1688.f40) {
    case 2: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 n, k, x, y;
        f32 w;
        char *str;
        f32 a, fx;
        s32 r;
        s210 = D_U_001D9510;
        func_0011BB58(s, func_U_00382488(0xB75), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        s210.f12 |= 4;
        func_U_0038FD40(&s210, 0x80000000UL, s, -1, 0x80000000UL, 1.0f, 1.0f);
        s210.f12 ^= 4;
        tmp = s210.fE;
        n = func_0011B868(s);
        for (k = 4; k >= 0; k--) s[n + k] = 1;
        s[n + 5] = 0;
        if (D_U_00306D80_003E1688.f5C >= 0x79) {
            str = func_U_00382488(0x8DE);
        } else {
            str = D_U_001D9530;
        }
        w = 272.0f;
        func_U_003AF620(&s210, 0x8066CCFF, s, 1, 1, -1, 1, str, 0, 0);
        x = s210.f0 + tmp;
        func_U_003A96B0(0x47, 0x3004B);
        y = x + 8;
        func_U_00396F58(func_U_00396C60(0x755D, 0), 0xE0, y, 0x40, 0x40, 0x80);
        a = (f32)(D_U_001D9C48 % 0x37) * -6.2831855f / 55.0f;
        fx = (x + 0x28) << 4;
        r = func_U_00396D30(func_U_00396C60(0x755D, 1));
        func_U_00397930(4096.0f, fx, w, w, a, 0x40, 0x40, r);
        break;
    }
    case 4: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 id;
        char *str;
        if (D_U_00306D80_003E1688.f5C <= 0) break;
        func_0011BB58(s, func_U_00382488(0x194), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        id = D_U_00306D80_003E1688.f44 ? 0 : 0x8DE;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        str = id ? func_U_00382488(id) : 0;
        func_U_0038E478(1);
        func_U_003AF620(&s210, 0x8066CCFF, p, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 5: {
        char *t;
        s32 id;
        char *str;
        if (D_U_00306D80_003E1688.f5C <= 0) break;
        t = func_U_00382488(D_U_00306D80_003E1688.f80 ? 0x1B3 : 0x1B2);
        id = D_U_00306D80_003E1688.f44 ? 0 : 0x8DE;
        func_0011A264(&s250, 0, 0x1C);
        s250.f2 = D_001D4BC4;
        s250.f4 = 0x4C;
        s250.f6 = 0x1B4;
        s250.f8 = 0x100;
        s250.fA = 0x68;
        s250.f10 = 0x10;
        s250.f12 = 1;
        s210 = s250;
        str = id ? func_U_00382488(id) : 0;
        func_U_0038E478(1);
        func_U_003AF620(&s210, 0x8066CCFF, t, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 1: {
        s32 ok, id2, id3, a;
        char *text;
        char *t2;
        char *t3;
        if (D_U_001D5B90 != -2) break;
        ok = 1;
        if (D_U_00306D80_003E1688.f5C <= 0) break;
        id2 = 0;
        id3 = 0;
        text = D_U_001D9538;
        func_U_003824B0();
        switch (D_001D4CE8) {
        case 8:
            a = 0x1A3;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_U_00382488(a);
            break;
        case 14:
            if (D_U_001DA020) {
                a = 0x195;
                id2 = 0x197;
                text = func_U_00382488(a);
                break;
            }
        case 15:
            a = 0x19F;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_U_00382488(a);
            break;
        case 33:
            a = 0x1A8;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_U_00382488(a);
            break;
        case 12: case 13: case 31: case 32:
            text = func_U_00382488(0x1AF);
            break;
        case 9: case 10:
            text = func_U_00382488(0x1AD);
            break;
        case 16: case 17:
            text = func_U_00382488(0x1AE);
            break;
        case 25: case 29:
            text = func_U_00382488(0x1AB);
            break;
        case 23: case 30:
            text = func_U_00382488(0x1AC);
            break;
        case 19:
            id2 = 0x8DE;
            text = func_U_00382488(0x1B0);
            break;
        case 20:
            id2 = 0x8DE;
            text = func_U_00382488(0x1B2);
            break;
        case 3:
            text = func_U_00382488(0x194);
            id2 = D_U_00306D80_003E1688.f44 ? 0 : 0x8DE;
            break;
        case 21:
            if (D_U_001DA020) {
                id2 = 0x197;
                text = func_U_00382488(0x195);
                break;
            }
            if (D_U_001D5BDC) {
                char *fmt = D_U_001D9540;
                text = func_U_00382488(0x198);
                id2 = 0x8E2;
                id3 = 0x8DF;
                func_0011B2E8(buf, fmt, text, 1, 1, func_U_00382488(0x19A));
                text = buf;
                break;
            } else {
                char *fmt = D_U_001D9540;
                text = func_U_00382488(0x198);
                id2 = 0x8E2;
                func_0011B2E8(buf, fmt, text, 1, 1, func_U_00382488(0x19A));
                text = buf;
                break;
            }
        case 24:
            id2 = 0x8DE;
            text = func_U_00382488(0x1B3);
            break;
        case 22:
            id2 = 0x8DE;
            text = func_U_00382488(0x1B1);
            break;
        case 27: {
            char *fmt = D_U_001D9540;
            text = func_U_00382488(0x1A1);
            id2 = 0x8E2;
            id3 = 0x8DF;
            func_0011B2E8(buf, fmt, text, 1, 1, func_U_00382488(0x11E8));
            text = buf;
            break;
        }
        case 26:
            id2 = 0x8E2;
            id3 = 0x8DF;
            text = func_U_00382488(0x1A5);
            break;
        case 4: case 5: case 6:
            if (D_U_001D5BDC && !D_U_001DA020) {
                id2 = 0x8E2;
                id3 = 0x8DF;
                text = func_U_00382488(0x19B);
                break;
            }
            if (D_U_001D5BDD) {
                id2 = 0x8E2;
                text = func_U_00382488(0x19B);
                break;
            }
            if (D_U_001DA020) {
                id2 = 0x197;
                text = func_U_00382488(0x195);
                break;
            }
            id2 = 0x197;
            text = func_U_00382488(0x19D);
            break;
        case 7:
            id2 = 0x197;
            text = func_U_00382488(0x195);
            break;
        default:
            ok = 0;
            break;
        }
        if (!ok) break;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        t2 = id2 ? func_U_00382488(id2) : 0;
        t3 = id3 ? func_U_00382488(id3) : 0;
        func_U_0038E478(1);
        func_U_003AF620(&s210, 0x8066CCFF, text, 1, 1, -1, 0, t2, t3, 1);
        break;
    }
    case 3: {
        f32 t;
        s32 c1, id, col;
        t = 1.0f - (f32)D_U_00306D80_003E1688.f44 / 30.0f;
        s210 = D_U_001D9550;
        func_U_0038C6D8(0x64, 0x12C, 0x60, 0x1A0, (s32)(t * 80.0f), 0x40404);
        c1 = func_U_0038DF00(D_U_001D94FC, D_U_001D9500, t);
        id = func_U_0038DF00(0x20FFFF, 0x8020FFFF, t);
        switch (D_U_00306D80_003E1688.f58) {
        case 0:
        case 1:
            col = id;
            func_U_003910D8(0xCA, 0x118, col, func_U_00382488(0x8E2), -1);
            func_U_003910D8(0x135, 0x118, col, func_U_00382488(0x8DF), -1);
            id = 0x24C;
            break;
        case 2:
            col = id;
            func_U_003910D8(0xCA, 0x118, col, func_U_00382488(0x8E2), -1);
            func_U_003910D8(0x135, 0x118, col, func_U_00382488(0x8DF), -1);
            id = 0x24D;
            break;
        case 3:
            col = id;
            func_U_003910D8(0x100, 0x118, col, func_U_00382488(0x8DE), -1);
            id = 0x24E;
            break;
        default:
            id = 0;
            break;
        }
        ps = &s210;
        if (id == 0) break;
        col = c1;
        c1 = (s32)func_U_00382488(id);
        func_U_00391400(ps, col, (void *)c1, -1, func_U_00389920(1), D_U_00335860);
        break;
    }
    case 9: {
        s32 v;
        char *a, *b, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_U_001DA0F4 * 100.0f + 0.5f + (D_U_001DA0F0 == 1 ? z0 : z1)); }
        tmp = (s32)&s210;
        func_U_003913E0((T_3DBEC8 *)tmp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_U_001D94DC) == 0) a = func_U_00382488(0x8E2);
        if ((b = D_U_001D94E0) == 0) b = func_U_00382488(0x8DF);
        if ((c = D_U_001D94E4) == 0) c = func_U_00382488(0x17C);
        func_U_0038E478(1);
        func_U_003AF620((T_3DBEC8 *)tmp, 0x80F0F0F0, c, 1, 1, -1, 0, a, b, D_U_001D94E8);
        break;
    }
    case 10: {
        s32 v;
        char *a, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_U_001DA0F4 * 100.0f + 0.5f + (D_U_001DA0F0 == 1 ? z0 : z1)); }
        ps = &s210;
        func_U_003913E0(ps, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_U_001D94DC) == 0) a = func_U_00382488(0x8E2);
        if ((c = D_U_001D94E4) == 0) c = func_U_00382488(0x17C);
        func_U_0038E478(1);
        func_U_003AF620(ps, 0x80F0F0F0, c, 1, 1, -1, 0, a, 0, D_U_001D94E8);
        break;
    }
    case 11: {
        s32 v;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_U_001DA0F4 * 100.0f + 0.5f + (D_U_001DA0F0 == 1 ? z0 : z1)); }
        func_U_003913E0(&s210, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        switch (D_U_00306D80_003E1688.f58) {
        case 0:
            break;
        case 1: {
            char *t1, *t2;
            t1 = func_U_00382488(0x8DE);
            t2 = func_U_00382488(0x8C1);
            func_0011B2E8(buf2, func_U_00382488(0x50A), 0xF);
            func_U_0038E478(1);
            func_U_003AF620(&s210, 0x8066CCFF, buf2, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        case 2:
            break;
        case 3: {
            char *t1, *t2, *t3;
            char *fmt = D_U_001D9570;
            tmp = (s32)buf2;
            D_U_00306D80_003E1688.f60 = D_U_00306D80_003E1688.f5C / 60 + 1;
            t1 = func_U_00382488(0x511);
            t2 = func_U_00382488(0x512);
            t3 = func_U_00382488(0x513);
            func_0011B2E8((char *)tmp, fmt, t1, t2, D_U_00306D80_003E1688.f60, t3);
            t1 = func_U_00382488(0x8E3);
            t2 = func_U_00382488(0x8DF);
            func_U_0038E478(1);
            func_U_003AF620(&s210, 0x8066CCFF, (char *)tmp, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        }
        break;
    }
    case 6: case 7: case 8:
        break;
    }
    func_U_003896F8();
}
/* localdecomp:end func_U_003E1688 */
