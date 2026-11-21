#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E41C0(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E17D0 */
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

__asm__(".extern D_001D949C, 4");
__asm__(".extern D_001D94A0, 4");
__asm__(".extern D_001D94A4, 4");
__asm__(".extern D_001D94A8, 1");
__asm__(".extern D_001D94BC, 4");
__asm__(".extern D_001D94C0, 4");

extern S_3DBEC8 D_00306D00_003E17D0;
extern T_3DBEC8 D_001D94D0;
extern T_3DBEC8 D_001D9510;
extern char D_001D94F0[];
extern char D_001D94F8[];
extern char D_001D9500[];
extern char D_001D9530[];
extern s32 D_001D9BC8;
extern u16 D_001D4BC4;
extern s32 D_001D5B90;
extern s32 D_001D4CE8;
extern u8 D_001D9FA0;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern f32 D_001DA074;
extern s32 D_001DA070;
extern char *D_001D949C;
extern char *D_001D94A0;
extern char *D_001D94A4;
extern u8 D_001D94A8;
extern s32 D_001D94BC;
extern s32 D_001D94C0;
extern u8 D_003357E0[];

extern void func_0038B200(s32, s32, s32, s32);
extern void func_00389620(s32);
extern void func_003A97F8(s32, unsigned long);
extern char *func_00382468(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_0038FDF8(T_3DBEC8 *, unsigned long, void *, s32, unsigned long, f32, f32);
extern void func_003AF7C0(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396D48(s32, s32);
extern void func_00397040(s32, s32, s32, s32, s32, s32);
extern s32 func_00396E18(s32);
extern void func_00397A18(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E530(s32);
extern void func_00382490(void);
extern void func_11B2E8();
extern void func_0038C790(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DFB8(s32, s32, f32);
extern s32 func_00391198(s32, s32, s32, void *, s32);
extern long func_00389978(s32);
extern void func_003914C0(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003914A0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00389750(void);

void func_003E17D0(void) {
    char buf[0x200];
    T_3DBEC8 s210;
    T_3DBEC8 s230;
    T_3DBEC8 s250;
    char buf2[0x100];
    s32 tmp;
    T_3DBEC8 *ps;

    if (D_00306D00_003E17D0.f7E == 0) {
        func_0038B200(0, 0, 0, 0x30);
    }
    if (D_00306D00_003E17D0.f7C != 0) {
        return;
    }
    func_00389620(0);
    func_003A97F8(0x42, 0x8000000044UL);
    func_003A97F8(0x47, 0x5360B);
    switch (D_00306D00_003E17D0.f40) {
    case 2: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 n, k, x, y;
        f32 w;
        char *str;
        f32 a, fx;
        s32 r;
        s210 = D_001D94D0;
        func_11BB58(s, func_00382468(0xB75), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        s210.f12 |= 4;
        func_0038FDF8(&s210, 0x80000000UL, s, -1, 0x80000000UL, 1.0f, 1.0f);
        s210.f12 ^= 4;
        tmp = s210.fE;
        n = func_11B868(s);
        for (k = 4; k >= 0; k--) s[n + k] = 1;
        s[n + 5] = 0;
        if (D_00306D00_003E17D0.f5C >= 0x65) {
            str = func_00382468(0x8DE);
        } else {
            str = D_001D94F0;
        }
        w = 272.0f;
        func_003AF7C0(&s210, 0x8066CCFF, s, 1, 1, -1, 1, str, 0, 0);
        x = s210.f0 + tmp;
        func_003A97F8(0x47, 0x3004B);
        y = x + 8;
        func_00397040(func_00396D48(0x755D, 0), 0xE0, y, 0x40, 0x40, 0x80);
        a = (f32)(D_001D9BC8 % 0x37) * -6.2831855f / 55.0f;
        fx = (x + 0x28) << 4;
        r = func_00396E18(func_00396D48(0x755D, 1));
        func_00397A18(4096.0f, fx, w, w, a, 0x40, 0x40, r);
        break;
    }
    case 4: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 id;
        char *str;
        if (D_00306D00_003E17D0.f5C <= 0) break;
        func_11BB58(s, func_00382468(0x194), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        id = D_00306D00_003E17D0.f44 ? 0 : 0x8DE;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        str = id ? func_00382468(id) : 0;
        func_0038E530(1);
        func_003AF7C0(&s210, 0x8066CCFF, p, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 5: {
        char *t;
        s32 id;
        char *str;
        if (D_00306D00_003E17D0.f5C <= 0) break;
        t = func_00382468(D_00306D00_003E17D0.f80 ? 0x1B3 : 0x1B2);
        id = D_00306D00_003E17D0.f44 ? 0 : 0x8DE;
        func_0011A264(&s250, 0, 0x1C);
        s250.f2 = D_001D4BC4;
        s250.f4 = 0x4C;
        s250.f6 = 0x1B4;
        s250.f8 = 0x100;
        s250.fA = 0x68;
        s250.f10 = 0x10;
        s250.f12 = 1;
        s210 = s250;
        str = id ? func_00382468(id) : 0;
        func_0038E530(1);
        func_003AF7C0(&s210, 0x8066CCFF, t, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 1: {
        s32 ok, id2, id3, a;
        char *text;
        char *t2;
        char *t3;
        if (D_001D5B90 != -2) break;
        ok = 1;
        if (D_00306D00_003E17D0.f5C <= 0) break;
        id2 = 0;
        id3 = 0;
        text = D_001D94F8;
        func_00382490();
        switch (D_001D4CE8) {
        case 8:
            a = 0x1A3;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382468(a);
            break;
        case 14:
            if (D_001D9FA0) {
                a = 0x196;
                id2 = 0x197;
                text = func_00382468(a);
                break;
            }
        case 15:
            a = 0x1A0;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382468(a);
            break;
        case 33:
            a = 0x1A9;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382468(a);
            break;
        case 12: case 13: case 31: case 32:
            text = func_00382468(0x1AF);
            break;
        case 9: case 10:
            text = func_00382468(0x1AD);
            break;
        case 16: case 17:
            text = func_00382468(0x1AE);
            break;
        case 25: case 29:
            text = func_00382468(0x1AB);
            break;
        case 23: case 30:
            text = func_00382468(0x1AC);
            break;
        case 19:
            id2 = 0x8DE;
            text = func_00382468(0x1B0);
            break;
        case 20:
            id2 = 0x8DE;
            text = func_00382468(0x1B2);
            break;
        case 3:
            text = func_00382468(0x194);
            id2 = D_00306D00_003E17D0.f44 ? 0 : 0x8DE;
            break;
        case 21:
            if (D_001D9FA0) {
                id2 = 0x197;
                text = func_00382468(0x196);
                break;
            }
            if (D_001D5BDC) {
                char *fmt = D_001D9500;
                text = func_00382468(0x199);
                id2 = 0x8E2;
                id3 = 0x8DF;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382468(0x19A));
                text = buf;
                break;
            } else {
                char *fmt = D_001D9500;
                text = func_00382468(0x199);
                id2 = 0x8E2;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382468(0x19A));
                text = buf;
                break;
            }
        case 24:
            id2 = 0x8DE;
            text = func_00382468(0x1B3);
            break;
        case 22:
            id2 = 0x8DE;
            text = func_00382468(0x1B1);
            break;
        case 27: {
            char *fmt = D_001D9500;
            text = func_00382468(0x1A2);
            id2 = 0x8E2;
            id3 = 0x8DF;
            func_11B2E8(buf, fmt, text, 1, 1, func_00382468(0x11E8));
            text = buf;
            break;
        }
        case 26:
            id2 = 0x8E2;
            id3 = 0x8DF;
            text = func_00382468(0x1A5);
            break;
        case 4: case 5: case 6:
            if (D_001D5BDC && !D_001D9FA0) {
                id2 = 0x8E2;
                id3 = 0x8DF;
                text = func_00382468(0x19C);
                break;
            }
            if (D_001D5BDD) {
                id2 = 0x8E2;
                text = func_00382468(0x19C);
                break;
            }
            if (D_001D9FA0) {
                id2 = 0x197;
                text = func_00382468(0x196);
                break;
            }
            id2 = 0x197;
            text = func_00382468(0x19E);
            break;
        case 7:
            id2 = 0x197;
            text = func_00382468(0x196);
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
        t2 = id2 ? func_00382468(id2) : 0;
        t3 = id3 ? func_00382468(id3) : 0;
        func_0038E530(1);
        func_003AF7C0(&s210, 0x8066CCFF, text, 1, 1, -1, 0, t2, t3, 1);
        break;
    }
    case 3: {
        f32 t;
        s32 c1, id, col;
        t = 1.0f - (f32)D_00306D00_003E17D0.f44 / 25.0f;
        s210 = D_001D9510;
        func_0038C790(0x64, 0x12C, 0x60, 0x1A0, (s32)(t * 80.0f), 0x40404);
        c1 = func_0038DFB8(D_001D94BC, D_001D94C0, t);
        id = func_0038DFB8(0x20FFFF, 0x8020FFFF, t);
        switch (D_00306D00_003E17D0.f58) {
        case 0:
        case 1:
            col = id;
            func_00391198(0xCA, 0x118, col, func_00382468(0x8E2), -1);
            func_00391198(0x135, 0x118, col, func_00382468(0x8DF), -1);
            id = 0x24C;
            break;
        case 2:
            col = id;
            func_00391198(0xCA, 0x118, col, func_00382468(0x8E2), -1);
            func_00391198(0x135, 0x118, col, func_00382468(0x8DF), -1);
            id = 0x24D;
            break;
        case 3:
            col = id;
            func_00391198(0x100, 0x118, col, func_00382468(0x8DE), -1);
            id = 0x24E;
            break;
        default:
            id = 0;
            break;
        }
        ps = &s210;
        if (id == 0) break;
        col = c1;
        c1 = (s32)func_00382468(id);
        func_003914C0(ps, col, (void *)c1, -1, func_00389978(1), D_003357E0);
        break;
    }
    case 9: {
        s32 v;
        char *a, *b, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        tmp = (s32)&s210;
        func_003914A0((T_3DBEC8 *)tmp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D949C) == 0) a = func_00382468(0x8E2);
        if ((b = D_001D94A0) == 0) b = func_00382468(0x8DF);
        if ((c = D_001D94A4) == 0) c = func_00382468(0x17C);
        func_0038E530(1);
        func_003AF7C0((T_3DBEC8 *)tmp, 0x80F0F0F0, c, 1, 1, -1, 0, a, b, D_001D94A8);
        break;
    }
    case 10: {
        s32 v;
        char *a, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        ps = &s210;
        func_003914A0(ps, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D949C) == 0) a = func_00382468(0x8E2);
        if ((c = D_001D94A4) == 0) c = func_00382468(0x17C);
        func_0038E530(1);
        func_003AF7C0(ps, 0x80F0F0F0, c, 1, 1, -1, 0, a, 0, D_001D94A8);
        break;
    }
    case 11: {
        s32 v;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        func_003914A0(&s210, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        switch (D_00306D00_003E17D0.f58) {
        case 0:
            break;
        case 1: {
            char *t1, *t2;
            t1 = func_00382468(0x8DE);
            t2 = func_00382468(0x8C1);
            func_11B2E8(buf2, func_00382468(0x50A), 0xF);
            func_0038E530(1);
            func_003AF7C0(&s210, 0x8066CCFF, buf2, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        case 2:
            break;
        case 3: {
            char *t1, *t2, *t3;
            char *fmt = D_001D9530;
            tmp = (s32)buf2;
            D_00306D00_003E17D0.f60 = D_00306D00_003E17D0.f5C / 50 + 1;
            t1 = func_00382468(0x511);
            t2 = func_00382468(0x512);
            t3 = func_00382468(0x513);
            func_11B2E8((char *)tmp, fmt, t1, t2, D_00306D00_003E17D0.f60, t3);
            t1 = func_00382468(0x8E3);
            t2 = func_00382468(0x8DF);
            func_0038E530(1);
            func_003AF7C0(&s210, 0x8066CCFF, (char *)tmp, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        }
        break;
    }
    case 6: case 7: case 8:
        break;
    }
    func_00389750();
}
/* localdecomp:end func_003E17D0 */

/* localdecomp:start func_003E2610 */
#include "vu0.h"
/* func_003E2610 (frontbin): modal / dialog state machine. Prep draft: shape from rac2's func_00286738,
 * switch tables read from retail (jtbl_0031CB30/CB60/CBF0/CC10). */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003E2258;
typedef struct {
    V4_003E2258 v0;
    V4_003E2258 v10;
    V4_003E2258 v20;
    V4_003E2258 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    f32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_003E2258;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_003E2258;
typedef struct { u8 pad[0x64]; void (*f64)(void *); u8 pad68[0xAA - 0x68]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_003E2258;
typedef struct { u8 pad[8]; s32 f8; s32 fC; s32 f10; } M_003E2258;

/* globals the retail reaches with lui (or $gp in a delay slot) */
__asm__(".extern D_001D52FC_003E2258, 16");
__asm__(".extern D_001D4CE8_003E2258, 16");
__asm__(".extern D_001D4CEC_003E2258, 16");
__asm__(".extern D_001D545C_003E2258, 16");
__asm__(".extern D_001D5520_003E2258, 16");
__asm__(".extern D_001D5B90_003E2258, 16");
__asm__(".extern D_001D5BDC_003E2258, 16");
__asm__(".extern D_001D5BDD_003E2258, 16");
__asm__(".extern D_001D9FA0_003E2258, 16");
__asm__(".extern D_001DA1E8_003E2258, 16");
__asm__(".extern D_001D9D50_003E2258, 16");
__asm__(".extern D_001D9D54_003E2258, 16");
__asm__(".extern D_001D9E10_003E2258, 16");
__asm__(".extern D_001DA4A0_003E2258, 16");

extern P_003E2258 *D_001D52FC_003E2258;
extern s32 D_001D4CE8_003E2258;
extern s32 D_001D4CEC_003E2258;
extern s32 D_001D545C_003E2258;
extern s32 D_001D5520_003E2258;
extern s32 D_001D5B90_003E2258;
extern u8 D_001D5BDC_003E2258;
extern u8 D_001D5BDD_003E2258;
extern u8 D_001D9FA0_003E2258;
extern u8 D_001DA1E8_003E2258;
extern s32 D_001D9D50_003E2258;
extern s32 D_001D9D54_003E2258;
extern f32 D_001D9E10_003E2258;
extern E_003E2258 *D_001DA4A0_003E2258;

/* $gp in retail */
__asm__(".extern D_001D9490, 4");
__asm__(".extern D_001D9494, 4");
__asm__(".extern D_001D9498, 4");
__asm__(".extern D_001D94B0, 4");
__asm__(".extern D_001D94C4, 4");
__asm__(".extern D_001D94C8, 4");
__asm__(".extern D_001DA49C_003E2258, 4");
extern s32 D_001D9490;
extern s32 D_001D9494;
extern s32 D_001D9498;
extern s32 D_001D94B0;
extern s32 D_001D94C4;
extern f32 D_001D94C8;
extern E_003E2258 *D_001DA49C_003E2258;

extern S_003E2258 D_00306D00;
extern M_003E2258 D_142430_003E2258;
extern u16 D_1A7E18_003E2258[];
extern s32 D_001425AC[];
extern u8 D_001A71C4[];
typedef struct { V4_003E2258 position; V4_003E2258 angles; f32 matrix[16]; } Cam_003E2258;
extern Cam_003E2258 D_00222400_003E2258;


extern s32 func_003A4688(void);
extern s32 func_003A12C0(s32, s32, s32, s32, s32);
extern void func_003A12A0(s32);
extern void func_003A1398(s32, s32);
extern void func_003A5748(s32, s32, s32);
extern void func_003B8DF0(s32);
extern void func_003A9308(void);
extern void func_0038A618(s32);
extern s32 func_003BBA30(void);
extern void func_0039C270(void);
extern void func_0039C3B8(void);
extern void func_0039C3D0(void);
extern void func_0039C6E0(void);
extern f32 func_0038D288(void *);
extern void func_003C4558(f32 *, void *, f32, f32, f32, f32);
extern void func_0038D348(void *, void *, f32);
extern void func_0038D3E0(void *, void *, void *);
extern void func_003C4F68(void *, f32);
extern void func_0038D200(void *, void *, f32);
extern void func_003E3CB0(f32 *);
extern void func_003E3B68(f32 *, s32);
extern void func_003E3D38(f32 *);
extern void func_003E1728(void);
extern void func_0038D270(void *, void *, void *); /* stand-in for the inline vsub.xyz / vadd.xyz */
extern void func_0038D990(void *, void *);
extern void func_003C4C60(void *, void *);
extern void func_0038D1D8(void *, void *, void *, f32);
extern void func_003C4378(void *, void *);
extern void func_0038DAA8(void *, void *, void *, f32);
extern void func_0038DBF0(void *, void *);
extern s32 func_00381C68(void);
extern void func_00397FB0(void);
extern s32 func_00393728(s32, s32, void *, void *, void *, s32, s32);
extern void func_003AFBF0(void);
extern void func_00398068(void);
extern void func_00398060(void);
extern void func_00385168(void);
extern void func_003E3E68(void);
extern void func_00393FC8(void);
extern void func_00394020(void);
extern void func_00394A00(void);
extern void func_00395328(void);
extern void func_00395370(void);
extern void func_00395858(void);
extern void func_003E50C8(s32);
extern void func_003E5898(s32);
extern void func_003E41D8(void);

void func_003E2610(void) {
    f32 delta[4] __attribute__((aligned(16)));
    f32 target[4] __attribute__((aligned(16)));
    f32 transform[16];
    f32 distance;
    S_003E2258 *dlg, *dlg3;

    func_003A4688();
    D_001D9D50_003E2258 = D_00306D00.f94;
    if (D_00306D00.f44)
        --D_00306D00.f44;
    if (D_00306D00.f7C)
        --D_00306D00.f7C;
    switch (D_00306D00.f40) {
    case 2:
        ++D_00306D00.f5C;
        if (D_00306D00.f5C > 0x4B && D_00306D00.f60)
            --D_00306D00.f60;
        if (D_001D4CE8_003E2258 == 3) {
            func_003A12C0(4, 2, 1, 0, 0);
            break;
        }
        if (D_00306D00.f5C >= 0x65 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            if (!D_1A7E18_003E2258[0x120 / 2])
                D_1A7E18_003E2258[0x120 / 2] = 1;
            func_003A5748(4, 0, 0);
            func_003A1398(0, 0);
            break;
        }
        break;
    case 5:
        ++D_00306D00.f5C;
        if (D_00306D00.f5C > 0x19 && D_00306D00.f60)
            --D_00306D00.f60;
        if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            D_001D4CEC_003E2258 &= ~0x40;
            D_001425AC[0] = 0;
            func_003B8DF0(-1);
            func_003A9308();
            break;
        }
        break;
    case 4:
        ++D_00306D00.f5C;
        if (D_00306D00.f5C > 0x19 && D_00306D00.f60)
            --D_00306D00.f60;
        if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
            D_001425AC[0] = 0;
            func_003B8DF0(-1);
            func_003A9308();
            break;
        }
        break;
    case 3:
        switch (D_00306D00.f58) {
        case 0:
            if (!D_00306D00.f44)
                D_00306D00.f58 = 1;
            break;
        case 1:
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_003A1398(0, 0);
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x40) {
                func_0038A618(4);
                D_001DA1E8_003E2258 = 0;
                D_00306D00.f58 = 2;
                D_00306D00.f5C = 0x1F4;
            }
            break;
        case 2:
            if (!D_00306D00.f5C || --D_00306D00.f5C == 0) {
                D_001DA1E8_003E2258 = 1;
                D_00306D00.f58 = 3;
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_0038A618(4);
                D_001DA1E8_003E2258 = 1;
                func_003A1398(0, 0);
                break;
            } else if (D_001D52FC_003E2258->f1A4 & 0x40) {
                D_001DA1E8_003E2258 = 0;
                func_003A1398(0, 0);
                break;
            }
            break;
        case 3:
            if (!(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
        default:
            func_003A1398(0, 0);
            break;
        }
        break;
    case 1:
        if (D_001D5B90_003E2258 != -2)
            break;
        ++D_00306D00.f5C;
        if (D_00306D00.f5C > 0x19 && D_00306D00.f60)
            --D_00306D00.f60;
        switch (D_001D4CE8_003E2258) {
        case 3:
            if (D_00306D00.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
            D_001D4CEC_003E2258 &= ~1;
            D_00306D00.f84 = 2;
            if (D_001D5BDD_003E2258) {
                func_003A12A0(5);
                func_003A12C0(3, 2, 7, 0, 0);
                break;
            }
            func_003A1398(0, 0);
            break;
        case 8:
            if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                D_001D4CEC_003E2258 |= 8;
                D_00306D00.f84 = 2;
                break;
            }
            if (D_00306D00.f44 || !(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            if (D_001D5BDD_003E2258) {
                D_00306D00.f84 = 2;
                func_003A9308();
                break;
            }
            D_001D4CEC_003E2258 |= 0x20;
            if (!func_003BBA30())
                D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_00306D00.f84 = 1;
            if (!D_001D5BDC_003E2258) {
                func_003A1398(0, 0);
                break;
            }
            break;
        case 15:
            if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                func_0039C270();
                D_00306D00.f84 = 2;
                break;
            }
            if (D_00306D00.f44 || !(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            if (D_001D5BDD_003E2258) {
                D_00306D00.f84 = 2;
                func_003A9308();
                break;
            }
            D_001D4CEC_003E2258 |= 0x20;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_00306D00.f84 = 1;
            if (!D_001D5BDC_003E2258) {
                func_003A1398(0, 0);
                break;
            }
            break;
        case 33:
            if (D_001D52FC_003E2258->f1A4 & 0x20) {
                func_0039C270();
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                func_0039C3B8();
                func_0039C3D0();
            }
            break;
        case 22:
            if (D_00306D00.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                break;
            D_001D4CEC_003E2258 &= ~0x40;
            D_001D4CEC_003E2258 &= ~0x400;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            D_00306D00.f84 = 2;
            if (D_001D5BDC_003E2258) {
                func_003A1398(0, 0);
            } else {
                func_003A1398(0, 0);
            }
            break;
        case 19:
        case 20:
        case 24:
            if (D_00306D00.f68 > 0) {
                if (--D_00306D00.f68 <= 0) {
                    if (D_142430_003E2258.f8 == 2) {
                        if (!D_142430_003E2258.f10) {
                            D_001D4CE8_003E2258 = 0xB;
                        } else if (D_142430_003E2258.f10 == -1) {
                            D_001D4CE8_003E2258 = 0xB;
                            D_142430_003E2258.f10 = 0;
                        } else if (D_142430_003E2258.f10 == -2) {
                            D_001D4CE8_003E2258 = 7;
                        } else {
                            D_001D4CE8_003E2258 = 0xE;
                        }
                        func_003A1398(0, 0);
                    } else {
                        D_00306D00.f84 = 2;
                        func_003A9308();
                    }
                    break;
                }
            } else {
                if (D_00306D00.f60 || !(D_001D52FC_003E2258->f1A4 & 0x40))
                    break;
                if (D_001D5BDD_003E2258) {
                    D_00306D00.f68 = 0xC;
                } else {
                    D_001D4CEC_003E2258 &= ~0x40;
                    D_001D4CEC_003E2258 &= ~0x400;
                    D_001D4CEC_003E2258 &= ~2;
                    D_001D4CEC_003E2258 &= ~4;
                    D_00306D00.f84 = 2;
                    func_003A1398(0, 0);
                }
            }
            break;
        case 1:
        case 18:
            if (!(D_001D4CEC_003E2258 & 6))
                func_003A1398(0, 0);
            break;
        case 14:
            if (!D_001D9FA0_003E2258)
                break;
        case 4:
        case 5:
        case 7:
            if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                D_00306D00.f84 = 1;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_003A1398(0, 0);
                break;
            }
            break;
        case 21:
            if (D_001D5BDC_003E2258 && !D_001D9FA0_003E2258) {
                
                if (D_00306D00.f60)
                    break;
                if (D_001D52FC_003E2258->f1A4 & 0x40) {
                    func_0039C6E0();
                    D_00306D00.f84 = 2;
                    D_001D4CEC_003E2258 &= ~2;
                    D_001D4CEC_003E2258 &= ~4;
                    D_001D4CEC_003E2258 |= 0x20;
                    func_003A9308();
                    break;
                }
                if (!(D_001D52FC_003E2258->f1A4 & 0x10))
                    break;
                D_00306D00.f84 = 1;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_003A1398(0, 0);
                break;
            }
            if (D_001D5BDD_003E2258) {
                if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x40)) {
                    D_00306D00.f84 = 2;
                    func_003A9308();
                }
                break;
            }
            if (D_00306D00.f60)
                break;
            if (!(D_001D52FC_003E2258->f1A4 & 0x10))
                break;
            D_00306D00.f84 = 1;
            D_001D4CEC_003E2258 &= ~2;
            D_001D4CEC_003E2258 &= ~4;
            func_003A1398(0, 0);
            break;
        case 26:
        case 27:
            dlg = &D_00306D00;
            if (dlg->f60)
                break;
            if (D_001D52FC_003E2258->f1A4 & 0x40) {
                func_0039C6E0();
                dlg->f84 = 2;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                D_001D4CEC_003E2258 |= 0x20;
                func_003A9308();
                break;
            }
            if (D_001D52FC_003E2258->f1A4 & 0x10) {
                dlg->f84 = 1;
                D_001D4CEC_003E2258 |= 0x20;
                func_003A1398(0, 0);
            }
            break;
        case 6:
            if (D_001D5BDC_003E2258) {
                if (!D_001D9FA0_003E2258) {
                    dlg3 = &D_00306D00;
                    if (dlg3->f60)
                        break;
                    if (D_001D52FC_003E2258->f1A4 & 0x40) {
                        func_0039C6E0();
                        dlg3->f84 = 2;
                        D_001D4CEC_003E2258 &= ~2;
                        D_001D4CEC_003E2258 &= ~4;
                        func_003A9308();
                    }
                    if (!dlg3->f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                        dlg3->f84 = 1;
                        D_001D4CEC_003E2258 |= 0x20;
                        D_001D4CEC_003E2258 &= ~2;
                        D_001D4CEC_003E2258 &= ~4;
                        func_003A1398(0, 0);
                    }
                    break;
                }
            } else if (D_001D5BDD_003E2258) {
                if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x20)) {
                    D_00306D00.f84 = 2;
                    func_003A9308();
                }
                break;
            }
            if (!D_00306D00.f60 && (D_001D52FC_003E2258->f1A4 & 0x10)) {
                D_00306D00.f84 = 1;
                D_001D4CEC_003E2258 |= 0x20;
                D_001D4CEC_003E2258 &= ~2;
                D_001D4CEC_003E2258 &= ~4;
                func_003A1398(0, 0);
            }
            break;
        case 11:
            if (!(D_001D4CEC_003E2258 & 6))
                func_003A1398(0, 0);
            break;
        }
        break;
    case 6:
        switch (D_00306D00.f58) {
        case 0:
            D_00306D00.v0 = D_00222400_003E2258.position;
            D_00306D00.v10 = D_00222400_003E2258.angles;
            D_00306D00.f58 = 1;
            if (D_001D545C_003E2258 == 0xB) {
                if (D_001D9E10_003E2258 == 200.0f)
                    D_001D94C4 = 0xAF;
                else
                    D_001D94C4 = 0x7D;
            }
            break;
        case 1:
            if (D_001D545C_003E2258 != 0xB)
                D_001D9D50_003E2258 = 3;
            /* VU0 in retail: vsub.xyz */
            vec_sub_ab(delta, &D_00222400_003E2258.position, &D_001D9E10_003E2258);
            distance = func_0038D288(delta);
            func_003C4558(&distance, &D_00306D00.f6C, (f32)D_001D94C4, 0.060000002f, 0.060000002f, 6.0000005f);
            func_0038D348(delta, delta, distance);
            /* VU0 in retail: vadd.xyz */
            vec_add_ab(&D_00222400_003E2258.position, delta, &D_001D9E10_003E2258);
            func_003E3B68(&D_00306D00.f70, 0);
            if ((f32)D_001D94C4 <= distance)
                D_00306D00.f58 = 2;
            break;
        case 2:
            if (D_001D545C_003E2258 != 0xB)
                D_001D9D50_003E2258 = 3;
            if (D_001D52FC_003E2258->f148 != 0.0f || D_001D52FC_003E2258->f14C != 0.0f) {
                *(vu0_q *)target = 0;
                target[1] = D_001D52FC_003E2258->f148;
                target[2] = D_001D52FC_003E2258->f14C;
                *(vu0_q *)delta = *(vu0_q *)target;
                func_0038D3E0(delta, delta, D_00222400_003E2258.matrix);
                func_003C4F68(delta, 1.0f);
                func_0038D200(delta, delta, (f32)-D_001D94C4 * (D_001D94C8 * 0.017453292f * 0.020000001f));
                func_003E3D38(delta);
            }
            func_003E3B68(&D_00306D00.f70, 1);
            func_003E3CB0((f32 *)((u8 *)D_001D52FC_003E2258 + 0x100));
            break;
        case 3: {
            f32 speed;
            if (D_001D545C_003E2258 != 0xB)
                D_001D9D50_003E2258 = 3;
            speed = (f32)D_001D94C4 * (D_001D94C8 * 0.017453292f * 0.020000001f);
            /* VU0 in retail: vsub.xyz */
            vec_sub_ab(target, &D_00306D00, &D_001D9E10_003E2258);
            func_0038D348(target, target, (f32)D_001D94C4);
            /* vadd.xyz, vsub.xyz */
            vec_add_ab(target, target, &D_001D9E10_003E2258);
            vec_sub_ab(delta, target, &D_00222400_003E2258.position);
            func_0038D990(transform, D_00222400_003E2258.matrix);
            func_0038D3E0(delta, delta, transform);
            delta[0] = 0.0f;
            if (delta[1] == 0.0f && delta[2] == 0.0f)
                delta[1] = 1.0f;
            func_003C4F68(delta, speed);
            func_0038D3E0(delta, delta, D_00222400_003E2258.matrix);
            func_003E3D38(delta);
            func_003E3B68(&D_00306D00.f70, 1);
            if (func_0038D288(delta) < speed - 0.01f) {
                D_001D9D54_003E2258 = 2;
                *(vu0_q *)&D_00306D00.v20 = *(vu0_q *)&D_00222400_003E2258.position;
                func_003C4C60(D_00222400_003E2258.matrix, &D_00306D00.v30);
                D_00306D00.f58 = 4;
            }
            break;
        }
        case 4:
            if (D_001D545C_003E2258 != 0xB)
                D_001D9D50_003E2258 = 3;
            func_003C4558(&D_00306D00.f6C, &D_00306D00.f70, 1.0f, 0.00080000004f, 0.00080000004f, 0.030000001f);
            func_0038D1D8(&D_00222400_003E2258, &D_00306D00.v20, &D_00306D00, D_00306D00.f6C);
            func_003C4378(delta, &D_00306D00.v30);
            func_003C4378(target, &D_00306D00.v10);
            func_0038DAA8(transform, delta, target, D_00306D00.f6C);
            func_0038DBF0(transform, D_00222400_003E2258.matrix);
            if (D_00306D00.f6C >= 1.0f)
                func_003A1398(0, 0);
            break;
        }
        D_00306D00.f7E = 1;
        if ((D_001D52FC_003E2258->f1A4 & 0x500) && D_00306D00.f58 == 2) {
            D_00306D00.f6C = 0.0f;
            D_00306D00.f58 = 3;
            D_00306D00.f70 = 0.0f;
        }
        if ((unsigned)(D_001D545C_003E2258 - 22) < 2) {
            E_003E2258 *object = D_001DA49C_003E2258;
            if (object < D_001DA4A0_003E2258) {
                do {
                    if (object->fAA == 0xD3D && object->f64)
                        object->f64(object);
                    ++object;
                } while (object < D_001DA4A0_003E2258);
            }
        }
        break;
    case 7:
        switch (D_00306D00.f58) {
        case 0:
            D_00306D00.f7E = 1;
            D_00306D00.f58 = 1;
            if (D_001A71C4[0] != 1)
                func_00381C68();
            D_001D9498 = 0;
            D_001D9490 = D_001D9494;
            func_00397FB0();
            func_003E41C0();
            break;
        case 1:
            if (D_001A71C4[0] != 1) {
                func_00381C68();
                func_00393728(0x23, 0, func_00393FC8, func_00394020, func_00394A00, 0, 0);
            } else {
                func_00393728(0x23, 0, func_00395328, func_00395370, func_00395858, 0, 0);
            }
            func_003AFBF0();
            func_003E3E68();
            func_003E50C8(0x12C);
            func_003E5898(0x96);
            func_00397FB0();
            {
                int remaining = D_001D9490;
                if (remaining > 0) {
                    D_001D9490 = remaining - 1;
                    remaining = D_001D9490;
                }
                D_001D9490 = remaining;
            }
            --D_001D94B0;
            if (D_001D94B0 < 0)
                D_001D94B0 = 0;
            if (!D_001D94B0)
                ++D_00306D00.f58;
            break;
        case 2:
            if (D_001A71C4[0] != 1) {
                func_00381C68();
                func_00393728(0x23, 0, func_00393FC8, func_00394020, func_00394A00, 0, 0);
            } else {
                func_00393728(0x23, 0, func_00395328, func_00395370, func_00395858, 0, 0);
            }
            func_003AFBF0();
            func_003E50C8(0x12C);
            func_003E5898(0x96);
            func_00397FB0();
            {
                int remaining = D_001D9490;
                if (remaining > 0) {
                    D_001D9490 = remaining - 1;
                    remaining = D_001D9490;
                }
                D_001D9490 = remaining;
            }
            if (D_001D9490 <= 0) {
                D_001D9490 = 0;
                ++D_00306D00.f58;
            }
            break;
        case 3:
            if (D_001A71C4[0] != 1)
                func_00381C68();
            func_00398068();
            func_00398060();
            func_003A1398(0, 0);
            break;
        }
        break;
    case 8:
        dlg = &D_00306D00;
        if (dlg->f58 != 2) {
            if (dlg->f58 >= 3)
                break;
            if (dlg->f58 < 0)
                break;
            ++dlg->f58;
            break;
        }
        func_003A12C0(3, 2, dlg->f54, 0, 0);
        func_003A12A0(3);
        goto advance;
    case 9:
        dlg = &D_00306D00;
        switch (dlg->f58) {
        case 1:
            if (D_001D52FC_003E2258->f1C4 & dlg->f8C) {
                dlg->f84 = 2;
                func_003A1398(0, 0);
            } else if (D_001D52FC_003E2258->f1C4 & dlg->f90) {
                dlg->f84 = 1;
                func_003A1398(0, 0);
            }
            break;
        case 0:
            goto initialize;
        }
        break;
    case 10:
        dlg = &D_00306D00;
        switch (dlg->f58) {
        case 0:
initialize:
            func_003E41D8();
advance:
            ++dlg->f58;
            break;
        case 1:
            if (D_001D52FC_003E2258->f1C4 & dlg->f8C) {
                dlg->f84 = 2;
                func_003A5748(0x12, 0, 0);
                func_003A1398(0, 0);
            }
            break;
        default:
            break;
        }
        break;
    case 11:
        switch (D_00306D00.f58) {
        case 0:
            func_003E41D8();
            ++D_00306D00.f58;
            if (D_001D5520_003E2258) {
                D_001D5520_003E2258 = !D_001D5520_003E2258;
                func_003E1728();
                func_003A1398(D_00306D00.f54, 0);
                break;
            }
            break;
        case 1:
            if (D_001D52FC_003E2258->f1C4 & 0x40) {
                D_00306D00.f84 = 2;
                ++D_00306D00.f58;
            } else if (D_001D52FC_003E2258->f1C0 & 0x10) {
                D_00306D00.f84 = 1;
                func_003A1398(D_00306D00.f54, 0);
                break;
            }
            break;
        case 2:
            D_00306D00.f5C = 0x2EE;
            D_00306D00.f60 = 0;
            ++D_00306D00.f58;
            D_00306D00.f84 = 0;
            D_001D5520_003E2258 = !D_001D5520_003E2258;
            func_003E1728();
            break;
        case 3:
            if (D_001D52FC_003E2258->f1C4 & 0x20)
                D_00306D00.f84 = 2;
            else if (D_001D52FC_003E2258->f1C4 & 0x10)
                D_00306D00.f84 = 1;
            --D_00306D00.f5C;
            if (D_00306D00.f5C <= 0)
                goto advanceConfirm;
            if (!D_00306D00.f84)
                break;
            goto advanceConfirm;
        case 4:
            if (D_00306D00.f84 < 0)
                goto advanceConfirm;
            if (D_00306D00.f84 < 2) {
                D_001D5520_003E2258 = !D_001D5520_003E2258;
                func_003E1728();
            }
advanceConfirm:
            ++D_00306D00.f58;
            break;
        case 5:
            func_003A1398(D_00306D00.f54, 0);
            break;
        }
        break;
    case 12:
        func_00385168();
        break;
    }
}
/* localdecomp:end func_003E2610 */

/* localdecomp:start func_003E3B68 */
#include "vu0.h"
typedef struct { char pad[48]; } Block48_003E37B0;
typedef struct { char pad[16]; } __attribute__((aligned(16))) Block16_003E37B0;
extern f32 D_001D9E10;
__asm__(".extern D_001D9E10, 16");
extern f32 D_00222400_003E37B0[];
extern s32 D_001D9540;
__asm__(".extern D_001D9540, 4");
extern f32 D_00222420[];
extern void func_0038D348(void *, void *, f32);
extern void func_0038D6E8(void *, void *);
extern void func_0038D9D0(void *, void *, void *);
extern void func_0038D270(void *, void *, void *);
extern f32 func_0038D288(void *);
extern void func_003C50A0(void *, void *, f32);
extern void func_003C4718(void *, f32, f32, f32, f32);
extern void func_0038DBF0(void *, void *);

void func_003E3B68(f32 *arg0, s32 arg1)
{
    Block48_003E37B0 a;
    Block48_003E37B0 b;
    Block48_003E37B0 c;
    Block16_003E37B0 d;
    Block16_003E37B0 e;
    f32 v;
    vec_sub_ba(&e, D_00222400_003E37B0, &D_001D9E10);
    func_0038D348(&e, &e, 1.0f);
    func_0038D6E8(&c, &D_001D9540);
    func_0038D9D0(&b, D_00222400_003E37B0 + 8, &c);
    func_0038D270(&d, &b, &e);
    v = func_0038D288(&d) * 0.5f;
    if (arg1 != 0) {
        func_003C50A0(&d, &d, -v);
    } else {
        func_003C4718(arg0, v, 0.00083775812f, 0.00083775812f, 0.062831856f);
        func_003C50A0(&d, &d, -*arg0);
    }
    func_0038DBF0(&d, &a);
    func_0038D9D0(D_00222420, &a, D_00222420);
}
/* localdecomp:end func_003E3B68 */

typedef int Q_3DCD08 __attribute__((mode(TI)));
typedef struct { Q_3DCD08 a, b; } V2_3DCD08;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DCD08;
typedef struct {
    V4_3DCD08 v0;
    V4_3DCD08 v10;
    V4_3DCD08 v20;
    V4_3DCD08 v30;
    s32 f40;
    s32 f44;
    s32 f48, f4C, f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
    f32 f6C;
    s32 f70;
    s32 f74, f78;
    s16 f7C, f7E;
    s32 f80;
    s16 f84, f86;
    s32 f88, f8C, f90, f94;
} S_3DCD08;
typedef struct {
    u8 pad0[0x100];
    s32 f100;
    u8 pad104[0x148 - 0x104];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1A4 - 0x150];
    s32 f1A4;
    u8 pad1A8[0x1C0 - 0x1A8];
    s32 f1C0;
    s32 f1C4;
} P_3DCD08;
/* US draft of func_003E3CB0 (rac3-uya-decomp func_003E3B68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003E3CB0 */
extern void func_003E3CB0(f32 *);
__asm__(".extern D_001D94CC, 4");
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C50A0();
extern void func_0038DBF0();
extern void func_0038D9D0();
void func_003E3CB0(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003C50A0)(a, D_00222420, *arg0 * (D_001D94CC * 0.017453292f * 0.020000001f));
    func_0038DBF0(a, b);
    func_0038D9D0(D_00222420, b, D_00222420);
}
/* localdecomp:end func_003E3CB0 */

/* localdecomp:start func_003E3D38 */
#include "vu0.h"
extern f32 D_001D9E10;
extern f32 D_00222400_003E37B0[];
extern s32 D_001D94C4;
__asm__(".extern D_001D9E10, 16");
__asm__(".extern D_001D94C4, 4");
void func_003E3D38(f32 *offset) {
    extern void func_0038D348(void *, void *, f32);
    vec_sub_ba(D_00222400_003E37B0, D_00222400_003E37B0, &D_001D9E10);
    vec_add_ba(D_00222400_003E37B0, D_00222400_003E37B0, offset);
    func_0038D348(D_00222400_003E37B0, D_00222400_003E37B0, (f32)D_001D94C4);
    vec_add_ab(D_00222400_003E37B0, D_00222400_003E37B0, &D_001D9E10);
}
/* localdecomp:end func_003E3D38 */

/* localdecomp:start func_003E3DA8 */
#include "vu0.h"
extern f32 D_00222400_003E37B0[];
extern f32 D_00306DD0[];
void func_003E3DA8(f32 *position) {
    extern void func_0038D348(void *, void *, f32);
    extern void func_0038D270(void *, void *, void *);
    vu0_v4 delta;
    vec_sub_ba(&delta, position, D_00222400_003E37B0);
    func_0038D348(D_00222400_003E37B0 + 8, &delta, 1.0f);
    func_0038D270(D_00222400_003E37B0 + 12, D_00222400_003E37B0 + 8, D_00306DD0);
    func_0038D348(D_00222400_003E37B0 + 12, D_00222400_003E37B0 + 12, 1.0f);
    func_0038D270(D_00222400_003E37B0 + 16, D_00222400_003E37B0 + 8, D_00222400_003E37B0 + 12);
    func_0038D348(D_00222400_003E37B0 + 16, D_00222400_003E37B0 + 16, -1.0f);
}
/* localdecomp:end func_003E3DA8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E3E60);

/* localdecomp:start func_003E3E68 */
#include "vu0.h"
typedef struct {
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4C;
    s32 f50;
    f32 f54;
} S_003E3E68;
extern S_003E3E68 D_00306DA0;
extern f32 D_001D9D0C;
extern f32 D_001D9D10;
extern u8 D_001D5471[6]; /* 0x1D5471..0x1D5476; [3] is the byte at 0x1D5474 */
extern f32 D_001A4C60[];
extern f32 func_0038DF28(f32);
extern void func_0038DC70(void *, void *, void *, f32);
extern s32 func_003E41A8(void);

void func_003E3E68(void) {
    vu0_v4 dir;
    vu0_v4 b;
    vu0_v4 a;
    f32 scale;
    s32 i;
    S_003E3E68 *p;
    f32 d;

    if (D_001D9D0C > 1.0f || D_001D9D10 > 1.0f) {
        scale = 2.0f;
    } else {
        scale = 1.0f;
    }
    vec_sub_ab(&dir, D_00222400_003E37B0, &D_00306DA0.v10);
    func_0038D348(&dir, &dir, D_00306DA0.f54);
    for (i = 0; i < 10; i++) {
        func_0038DC70(&a, &dir, &D_00306DA0.v30, func_0038DF28(i * 6.2831855f / 10.0f));
        vec_add_ba(&a, &a, &D_00306DA0.v10);
        func_0038DC70(&b, &dir, &D_00306DA0.v30, func_0038DF28((i + 1) * 6.2831855f / 10.0f));
        vec_add_ab(&b, &b, &D_00306DA0.v10);
    }
    if (func_003E41A8() != 0 && D_001D5471[3] != 0 && D_00306DA0.f50 == 0) {
        if (D_00306DA0.f48 < 0.031415928f) {
            D_00306DA0.f48 = D_00306DA0.f48 + scale * 0.00020943953f;
        } else {
            D_00306DA0.f48 = 0.031415928f;
        }
        p = &D_00306DA0;
        p->f4C = p->f48 / 0.031415928f;
        d = p->f54 - p->f40;
        if (fabs_asm(d) > 0.1f) {
            vec_sub_ba(D_00222400_003E37B0, D_00222400_003E37B0, &p->v10);
            p->f40 = p->f40 + p->f4C * 0.042000055f * d;
            func_0038D348(D_00222400_003E37B0, D_00222400_003E37B0, p->f40);
            vec_add_ab(D_00222400_003E37B0, D_00222400_003E37B0, &p->v10);
        }
        vec_sub_ba(D_00222400_003E37B0, D_00222400_003E37B0, &p->v10);
        func_0038DC70(D_00222400_003E37B0, D_00222400_003E37B0, &p->v30, scale * p->f48 * p->f44);
        vec_add_ab(D_00222400_003E37B0, D_00222400_003E37B0, &p->v10);
        func_0038D1D8(p, p, D_001A4C60, p->f4C * 0.023999989f);
        func_003E3DA8((f32 *)p);
    }
}
/* localdecomp:end func_003E3E68 */
