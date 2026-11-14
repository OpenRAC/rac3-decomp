#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E1418 */
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

extern S_3DBEC8 D_00306D00_003E1418;
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

extern void func_0038AE20(s32, s32, s32, s32);
extern void func_00389240(s32);
extern void func_003A9440(s32, unsigned long);
extern char *func_00382088(s32);
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_0038FA18(T_3DBEC8 *, unsigned long, void *, s32, unsigned long, f32, f32);
extern void func_003AF408(T_3DBEC8 *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 func_00396968(s32, s32);
extern void func_00396C60(s32, s32, s32, s32, s32, s32);
extern s32 func_00396A38(s32);
extern void func_00397638(f32, f32, f32, f32, f32, s32, s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_0038E150(s32);
extern void func_003820B0(void);
extern void func_11B2E8();
extern void func_0038C3B0(s32, s32, s32, s32, s32, s32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_00390DB8(s32, s32, s32, void *, s32);
extern long func_00389598(s32);
extern void func_003910E0(T_3DBEC8 *, s32, void *, s32, long, void *);
extern void func_003910C0(T_3DBEC8 *, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_00389370(void);

void func_003E1418(void) {
    char buf[0x200];
    T_3DBEC8 s210;
    T_3DBEC8 s230;
    T_3DBEC8 s250;
    char buf2[0x100];
    s32 tmp;
    T_3DBEC8 *ps;

    if (D_00306D00_003E1418.f7E == 0) {
        func_0038AE20(0, 0, 0, 0x30);
    }
    if (D_00306D00_003E1418.f7C != 0) {
        return;
    }
    func_00389240(0);
    func_003A9440(0x42, 0x8000000044UL);
    func_003A9440(0x47, 0x5360B);
    switch (D_00306D00_003E1418.f40) {
    case 2: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 n, k, x, y;
        f32 w;
        char *str;
        f32 a, fx;
        s32 r;
        s210 = D_001D94D0;
        func_11BB58(s, func_00382088(0xB75), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        s210.f12 |= 4;
        func_0038FA18(&s210, 0x80000000UL, s, -1, 0x80000000UL, 1.0f, 1.0f);
        s210.f12 ^= 4;
        tmp = s210.fE;
        n = func_11B868(s);
        for (k = 4; k >= 0; k--) s[n + k] = 1;
        s[n + 5] = 0;
        if (D_00306D00_003E1418.f5C >= 0x65) {
            str = func_00382088(0x8DE);
        } else {
            str = D_001D94F0;
        }
        w = 272.0f;
        func_003AF408(&s210, 0x8066CCFF, s, 1, 1, -1, 1, str, 0, 0);
        x = s210.f0 + tmp;
        func_003A9440(0x47, 0x3004B);
        y = x + 8;
        func_00396C60(func_00396968(0x755D, 0), 0xE0, y, 0x40, 0x40, 0x80);
        a = (f32)(D_001D9BC8 % 0x37) * -6.2831855f / 55.0f;
        fx = (x + 0x28) << 4;
        r = func_00396A38(func_00396968(0x755D, 1));
        func_00397638(4096.0f, fx, w, w, a, 0x40, 0x40, r);
        break;
    }
    case 4: {
        u8 *s = (u8 *)0x70000000;
        u8 *p;
        s32 id;
        char *str;
        if (D_00306D00_003E1418.f5C <= 0) break;
        func_11BB58(s, func_00382088(0x194), 0x400);
        p = s;
        while (*p >= 2) p++;
        while (*p == 1) { *p = 0; p++; }
        id = D_00306D00_003E1418.f44 ? 0 : 0x8DE;
        func_0011A264(&s230, 0, 0x1C);
        s230.f2 = D_001D4BC4;
        s230.f4 = 0x4C;
        s230.f6 = 0x1B4;
        s230.f8 = 0x100;
        s230.fA = 0x68;
        s230.f10 = 0x10;
        s230.f12 = 1;
        s210 = s230;
        str = id ? func_00382088(id) : 0;
        func_0038E150(1);
        func_003AF408(&s210, 0x8066CCFF, p, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 5: {
        char *t;
        s32 id;
        char *str;
        if (D_00306D00_003E1418.f5C <= 0) break;
        t = func_00382088(D_00306D00_003E1418.f80 ? 0x1B3 : 0x1B2);
        id = D_00306D00_003E1418.f44 ? 0 : 0x8DE;
        func_0011A264(&s250, 0, 0x1C);
        s250.f2 = D_001D4BC4;
        s250.f4 = 0x4C;
        s250.f6 = 0x1B4;
        s250.f8 = 0x100;
        s250.fA = 0x68;
        s250.f10 = 0x10;
        s250.f12 = 1;
        s210 = s250;
        str = id ? func_00382088(id) : 0;
        func_0038E150(1);
        func_003AF408(&s210, 0x8066CCFF, t, 1, 1, -1, 0, str, 0, 0);
        break;
    }
    case 1: {
        s32 ok, id2, id3, a;
        char *text;
        char *t2;
        char *t3;
        if (D_001D5B90 != -2) break;
        ok = 1;
        if (D_00306D00_003E1418.f5C <= 0) break;
        id2 = 0;
        id3 = 0;
        text = D_001D94F8;
        func_003820B0();
        switch (D_001D4CE8) {
        case 8:
            a = 0x1A3;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382088(a);
            break;
        case 14:
            if (D_001D9FA0) {
                a = 0x196;
                id2 = 0x197;
                text = func_00382088(a);
                break;
            }
        case 15:
            a = 0x1A0;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382088(a);
            break;
        case 33:
            a = 0x1A9;
            id2 = 0x8E3;
            id3 = 0x8DF;
            text = func_00382088(a);
            break;
        case 12: case 13: case 31: case 32:
            text = func_00382088(0x1AF);
            break;
        case 9: case 10:
            text = func_00382088(0x1AD);
            break;
        case 16: case 17:
            text = func_00382088(0x1AE);
            break;
        case 25: case 29:
            text = func_00382088(0x1AB);
            break;
        case 23: case 30:
            text = func_00382088(0x1AC);
            break;
        case 19:
            id2 = 0x8DE;
            text = func_00382088(0x1B0);
            break;
        case 20:
            id2 = 0x8DE;
            text = func_00382088(0x1B2);
            break;
        case 3:
            text = func_00382088(0x194);
            id2 = D_00306D00_003E1418.f44 ? 0 : 0x8DE;
            break;
        case 21:
            if (D_001D9FA0) {
                id2 = 0x197;
                text = func_00382088(0x196);
                break;
            }
            if (D_001D5BDC) {
                char *fmt = D_001D9500;
                text = func_00382088(0x199);
                id2 = 0x8E2;
                id3 = 0x8DF;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382088(0x19A));
                text = buf;
                break;
            } else {
                char *fmt = D_001D9500;
                text = func_00382088(0x199);
                id2 = 0x8E2;
                func_11B2E8(buf, fmt, text, 1, 1, func_00382088(0x19A));
                text = buf;
                break;
            }
        case 24:
            id2 = 0x8DE;
            text = func_00382088(0x1B3);
            break;
        case 22:
            id2 = 0x8DE;
            text = func_00382088(0x1B1);
            break;
        case 27: {
            char *fmt = D_001D9500;
            text = func_00382088(0x1A2);
            id2 = 0x8E2;
            id3 = 0x8DF;
            func_11B2E8(buf, fmt, text, 1, 1, func_00382088(0x11E8));
            text = buf;
            break;
        }
        case 26:
            id2 = 0x8E2;
            id3 = 0x8DF;
            text = func_00382088(0x1A5);
            break;
        case 4: case 5: case 6:
            if (D_001D5BDC && !D_001D9FA0) {
                id2 = 0x8E2;
                id3 = 0x8DF;
                text = func_00382088(0x19C);
                break;
            }
            if (D_001D5BDD) {
                id2 = 0x8E2;
                text = func_00382088(0x19C);
                break;
            }
            if (D_001D9FA0) {
                id2 = 0x197;
                text = func_00382088(0x196);
                break;
            }
            id2 = 0x197;
            text = func_00382088(0x19E);
            break;
        case 7:
            id2 = 0x197;
            text = func_00382088(0x196);
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
        t2 = id2 ? func_00382088(id2) : 0;
        t3 = id3 ? func_00382088(id3) : 0;
        func_0038E150(1);
        func_003AF408(&s210, 0x8066CCFF, text, 1, 1, -1, 0, t2, t3, 1);
        break;
    }
    case 3: {
        f32 t;
        s32 c1, id, col;
        t = 1.0f - (f32)D_00306D00_003E1418.f44 / 25.0f;
        s210 = D_001D9510;
        func_0038C3B0(0x64, 0x12C, 0x60, 0x1A0, (s32)(t * 80.0f), 0x40404);
        c1 = func_0038DBD8(D_001D94BC, D_001D94C0, t);
        id = func_0038DBD8(0x20FFFF, 0x8020FFFF, t);
        switch (D_00306D00_003E1418.f58) {
        case 0:
        case 1:
            col = id;
            func_00390DB8(0xCA, 0x118, col, func_00382088(0x8E2), -1);
            func_00390DB8(0x135, 0x118, col, func_00382088(0x8DF), -1);
            id = 0x24C;
            break;
        case 2:
            col = id;
            func_00390DB8(0xCA, 0x118, col, func_00382088(0x8E2), -1);
            func_00390DB8(0x135, 0x118, col, func_00382088(0x8DF), -1);
            id = 0x24D;
            break;
        case 3:
            col = id;
            func_00390DB8(0x100, 0x118, col, func_00382088(0x8DE), -1);
            id = 0x24E;
            break;
        default:
            id = 0;
            break;
        }
        ps = &s210;
        if (id == 0) break;
        col = c1;
        c1 = (s32)func_00382088(id);
        func_003910E0(ps, col, (void *)c1, -1, func_00389598(1), D_003357E0);
        break;
    }
    case 9: {
        s32 v;
        char *a, *b, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        tmp = (s32)&s210;
        func_003910C0((T_3DBEC8 *)tmp, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D949C) == 0) a = func_00382088(0x8E2);
        if ((b = D_001D94A0) == 0) b = func_00382088(0x8DF);
        if ((c = D_001D94A4) == 0) c = func_00382088(0x17C);
        func_0038E150(1);
        func_003AF408((T_3DBEC8 *)tmp, 0x80F0F0F0, c, 1, 1, -1, 0, a, b, D_001D94A8);
        break;
    }
    case 10: {
        s32 v;
        char *a, *c;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        ps = &s210;
        func_003910C0(ps, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        if ((a = D_001D949C) == 0) a = func_00382088(0x8E2);
        if ((c = D_001D94A4) == 0) c = func_00382088(0x17C);
        func_0038E150(1);
        func_003AF408(ps, 0x80F0F0F0, c, 1, 1, -1, 0, a, 0, D_001D94A8);
        break;
    }
    case 11: {
        s32 v;
        { f32 z0 = 0.0f, z1 = 0.0f; v = (s32)(D_001DA074 * 100.0f + 0.5f + (D_001DA070 == 1 ? z0 : z1)); }
        func_003910C0(&s210, 0xF0, 0x1E0, 0x4C, 0x1B4, 0x100, v, 0x10, 3);
        switch (D_00306D00_003E1418.f58) {
        case 0:
            break;
        case 1: {
            char *t1, *t2;
            t1 = func_00382088(0x8DE);
            t2 = func_00382088(0x8C1);
            func_11B2E8(buf2, func_00382088(0x50A), 0xF);
            func_0038E150(1);
            func_003AF408(&s210, 0x8066CCFF, buf2, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        case 2:
            break;
        case 3: {
            char *t1, *t2, *t3;
            char *fmt = D_001D9530;
            tmp = (s32)buf2;
            D_00306D00_003E1418.f60 = D_00306D00_003E1418.f5C / 50 + 1;
            t1 = func_00382088(0x511);
            t2 = func_00382088(0x512);
            t3 = func_00382088(0x513);
            func_11B2E8((char *)tmp, fmt, t1, t2, D_00306D00_003E1418.f60, t3);
            t1 = func_00382088(0x8E3);
            t2 = func_00382088(0x8DF);
            func_0038E150(1);
            func_003AF408(&s210, 0x8066CCFF, (char *)tmp, 1, 1, -1, 0, t1, t2, 0);
            break;
        }
        }
        break;
    }
    case 6: case 7: case 8:
        break;
    }
    func_00389370();
}
/* localdecomp:end func_003E1418 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E2258);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CB30);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CB60);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CBF0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CC10);

INCLUDE_ASM("asm/nonmatchings/text", func_003E37B0);

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
typedef struct { u8 pad[0x120]; u16 f120; } T_3DCD08;
typedef struct { u8 pad[8]; s32 f8; s32 fC; s32 f10; } M_3DCD08;
typedef struct { u8 pad[0x64]; void (*f64)(void *); u8 pad68[0xAA - 0x68]; s16 fAA; u8 padAC[0x100 - 0xAC]; } E_3DCD08;
extern S_3DCD08 D_00306D00_003DCD08;
extern P_3DCD08 *D_001D52FC;
extern s32 D_001D4CEC;
extern s32 D_001D4CE8;
extern s32 D_001D545C;
extern s32 D_001D5B90;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD;
extern s32 D_001D9D50;
extern s32 D_001D9D54;
extern f32 D_001D9E10;
extern u8 D_001D9FA0;
extern u8 D_001DA1E8;
extern E_3DCD08 *D_001DA49C;
extern E_3DCD08 *D_001DA4A0;
extern s32 D_001D5520_003DCD08;
extern s32 D_001D9490;
extern s32 D_001D9494;
extern s32 D_001D9498;
extern s32 D_001D94B0;
extern s32 D_001D94C4;
extern f32 D_001D94C8;
extern u8 D_001A71C4[];
extern T_3DCD08 D_1A7E18;
extern M_3DCD08 D_142430;
extern s32 D_001425AC[];
extern V4_3DCD08 D_00222400[];
extern void func_003A5348(s32, s32, s32);
extern void func_003B8A38(s32);
extern void func_003A8F50(void);
extern void func_0038A238(s32);
extern void func_003A0EA0(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_003A0F98(s32, s32);
extern s32 func_003BB678(void);
extern void func_0039BE90(void);
extern void func_0039BFD8(void);
extern void func_0039BFF0(void);
extern void func_0039C300(void);
extern f32 func_0038CEA8(void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern void func_003C4BB0(void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003E38F8(f32 *);
extern void func_0038D5B0(void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_003C3FC0(void *, void *);
extern void func_0038D6C8(void *, void *, void *, f32);
extern void func_0038D810(void *, void *);
extern s32 func_00381D58(void);
extern void func_00397BD0(void);
extern s32 func_00393348(s32, s32, void *, void *, void *, s32, s32);
extern void func_003AF838(void);
extern void func_00397C88(void);
extern void func_00397C80(void);
extern void func_003E1370(void);
extern void func_00384D88(void);
extern void func_00393BE8(void);
extern void func_00394620(void);
extern void func_00394F48(void);
extern void func_00394F90(void);
extern void func_00395478(void);
extern s32 D_001D9540;
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038CE90(void *, void *, void *);
extern void func_003C4CE8(void *, void *, f32);
extern void func_003C4360(void *, f32, f32, f32, f32);
extern f32 D_00222420[];
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C4CE8();
extern void func_0038D810();
extern void func_0038D5F0();
/* localdecomp:start func_003E38F8 */
/* US draft of func_003E38F8 (rac3-uya-decomp func_003E3B68, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern void func_003E38F8(f32 *);
__asm__(".extern D_001D94CC_003E38F8, 4");
extern f32 D_001D94CC_003E38F8;
extern f32 D_00222420_003E38F8[];
extern void func_003C4CE8_003E38F8();
extern void func_0038D810_003E38F8();
extern void func_0038D5F0_003E38F8();
void func_003E38F8(f32 *arg0) {
    f32 a[4];
    f32 b[12];
    ((void (*)(f32 *, f32 *, f32))func_003C4CE8_003E38F8)(a, D_00222420_003E38F8, *arg0 * (D_001D94CC_003E38F8 * 0.017453292f * 0.020000001f));
    func_0038D810_003E38F8(a, b);
    func_0038D5F0_003E38F8(D_00222420_003E38F8, b, D_00222420_003E38F8);
}
/* localdecomp:end func_003E38F8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003E3980);

INCLUDE_ASM("asm/nonmatchings/text", func_003E39F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3AA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3AB0);
