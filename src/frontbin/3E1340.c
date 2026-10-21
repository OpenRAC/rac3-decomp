#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern void func_003E5520(void);
extern void func_003E55B8(void);
extern s32 func_003E13F0();
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003E1340);

/* func_003E1370: from the US C of func_003DBE20 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003E1370 */
/* Reached with lui in retail, as the assembler expands an access to a global it does not know to be
   small: declared sized (gcc leaves the access to the assembler as one macro), then with a section
   attribute, which keeps gcc's .extern size hint out of the assembly. */
extern s32 D_001D5520_003E1370;
extern s32 D_001D5520_003E1370 __attribute__((section(".bss")));
extern void func_003A92F0(s32);
extern void func_00391328(void);
extern s32 D_001D5520[];
extern void func_00391678(s32, s32, s32, s32, s32, s32);
extern void func_003D9338(void);
void func_003E1370(void) {   /* same as func_003B6438 plus the call below */
    func_003A92F0(1);
    func_00391328();
    if (D_001D5520_003E1370 != 0) {
        func_00391678(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
    } else {
        func_00391678(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
    }
    func_003D9338();
}
/* localdecomp:end func_003E1370 */

LINKER_REMNANT("asm/remnants", func_003E13E8);

/* localdecomp:start func_003E13F0 */
extern s32 D_00306D40[];
 
s32 func_003E13F0(void) {
    return D_00306D40[0];
}
/* localdecomp:end func_003E13F0 */

LINKER_REMNANT("asm/remnants", func_003E1400);

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
INCLUDE_ASM("asm/nonmatchings/text", func_003E1418);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CA80);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031CAB0);

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
INCLUDE_ASM("asm/nonmatchings/text", func_003E38F8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3980);

INCLUDE_ASM("asm/nonmatchings/text", func_003E39F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3AA8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E3AB0);

extern void func_0038CE90(void *, void *, void *);
extern u8 D_00306DD0[];

/* localdecomp:start func_003E3DC0 */
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00306D00;
 
void func_003E3DC0(void) {
    S_302D80 *s = &D_00306D00;
    if (s->f40 == 7 && s->f58 == 1) {
        s->f58 = 2;
    }
}
/* localdecomp:end func_003E3DC0 */

/* localdecomp:start func_003E3DF0 */
extern s32 D_00306D40[];
s32 func_003E3DF0(void) {
    return D_00306D40[0] == 7;
}
/* localdecomp:end func_003E3DF0 */

/* localdecomp:start func_003E3E08 */
extern s32 D_001D94B0;
void func_003E3E08(void) {
    D_001D94B0 = 3;
}
/* localdecomp:end func_003E3E08 */

LINKER_REMNANT("asm/remnants", func_003E3E18);

/* localdecomp:start func_003E3E20 */
extern s16 D_00306D84[];
 
void func_003E3E20(void) {
    D_00306D84[0] = 0;
}
/* localdecomp:end func_003E3E20 */

/* localdecomp:start func_003E3E30 */
void *func_003E3E30(void *p) {
    return (u8 *)p + 0xED1C;
}
/* localdecomp:end func_003E3E30 */

typedef struct { u8 pad[0xAA]; s16 xAA; } M_3DE8F0;
typedef struct { f32 f0; s16 h4; } R_3DE8F0;
typedef struct {
    u8 pad0[0x19E0];
    M_3DE8F0 *x19E0;
    u8 pad19E4[0x25C4 - 0x19E4];
    s32 x25C4;
    u8 pad25C8[0x25E4 - 0x25C8];
    u8 x25E4;
    u8 pad25E5[0x2850 - 0x25E5];
    s32 x2850;
} W_3DE8F0;
typedef struct { u8 pad[0x20]; u8 x20; } F_3DE8F0;
extern s32 D_001D9550;
extern f32 D_001D9558;
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern s32 D_00142668[];
extern s32 D_001DA7E8[2];
extern char D_001D9560[];
extern R_3DE8F0 *func_00382348(M_3DE8F0 *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_0038D098(f32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7A18(s32, s32);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7B80_003E3E40(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003E3E40);

typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381D30();
extern s32 func_003E81F0(s32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003E4440);

extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E81F0(s32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003E4508);

typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;
extern u8 D_001D9554;
extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 D_001D9760;
extern s32 D_001DA7E8[2];
extern S_3DF038 D_001DA938[];
extern void func_003E73B0_003E4588(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern s32 func_00381FF0(s32);
extern s32 func_00392A18(void);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_003E7928(s32, s32, s32);
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E7FF8(s32, s32, s32, s32, s32);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E7590(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E7D70(s32, s32);
extern s32 func_003E7C90_003E4588(s32, void *);
extern s32 func_003E7E48(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_003E6FF0_003E4588(s32, s32);
extern void func_003E3E40(void);
extern S_3DF038 *func_003E6C08_003E4588(S_3DF038 *);
extern s32 func_003E6DE8_003E4588(S_3DF038 *);
extern W_3DF038 *func_003E6378(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003E4588);

/* localdecomp:start func_003E4D10 */
extern u8 D_001D9554;
extern u8 D_001D9566;
extern s32 D_001D9550;
extern s32 func_003E7838(s32, s32, s32);
extern s32 func_003E4F30(s32);
extern void func_003E4EA8();
void func_003E4D10(s32 a) {
    if (D_001D9554 != 0 && D_001D9566 == 0) {
        D_001D9550 = a;
        func_003E7838(0x90000, 1, a != 0);
        func_003E4EA8(func_003E4F30(0));
    }
}
/* localdecomp:end func_003E4D10 */

LINKER_REMNANT("asm/remnants", func_003E4D60);

extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 func_00392A18(void);
extern s32 func_003E8100(s32, s32, s32);
extern s32 func_003E73B8(s32, f32, f32);
extern s32 func_003E81F0(s32, f32, f32);
INCLUDE_ASM("asm/nonmatchings/text", func_003E4D70);

/* localdecomp:start func_003E4EA8 */
extern s32 D_001D9550;
extern u8 D_001D9566;
extern void func_003E4D70(s32);
extern void func_003E3E40(void);
extern void func_003E4440(void);
extern void func_003E4508(void);
extern s32 func_003E7838(s32, s32, s32);
void func_003E4EA8(void) {
    if (D_001D9550 != 0 && D_001D9566 == 0) {
        D_001D9550--;
        func_003E4D70(0x90000);
        func_003E3E40();
        func_003E4440();
        func_003E4508();
    } else {
        func_003E7838(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003E4EA8 */

/* localdecomp:start func_003E4F10 */
extern u8 D_001D9554;
extern s32 func_003E85A8();
void func_003E4F10(void) {
    D_001D9554 = 0;
    func_003E85A8(7);
}
/* localdecomp:end func_003E4F10 */

/* localdecomp:start func_003E4F30 */
typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E4588(s32);
extern void func_003E4F10(void);
extern void func_003E4EA8(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001DA780;
extern s32 D_001DA7A0;
extern s32 D_001DA7C0;
extern s32 D_001DA7E0;
extern s32 D_001DA768[2];
extern s32 D_001DA788[2];
extern s32 D_001DA7A8[2];
extern s32 D_001DA7C8[2];
extern V16_3DF9E0 D_001D9568[];
s32 func_003E4F30(s32 idx) {
    V16_3DF9E0 v;
    if (D_001DA780 == 0) {
        func_003E6FA0(D_001DA768, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA780 = 1;
    }
    if (D_001DA7A0 == 0) {
        func_003E6FA0(D_001DA788, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7A0 = 1;
    }
    if (D_001DA7C0 == 0) {
        func_003E6FA0(D_001DA7A8, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7C0 = 1;
    }
    if (D_001DA7E0 == 0) {
        func_003E6FA0(D_001DA7C8, (s32)func_003E4588, (s32)func_003E4F10, (s32)func_003E4EA8, 0, 0);
        D_001DA7E0 = 1;
    }
    v = D_001D9568[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_003E4F30 */

/* localdecomp:start func_003E5070 */
void func_003E5070(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003E5070 */

/* localdecomp:start func_003E5090 */
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern void func_003E6348(void **, s32, s32);
extern void *func_003F1CA8();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003E5090(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x48);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F1CA8(func_003F2388(0x48, e));
                r = ((s32 (*)())func_003E6348)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5090 */

/* localdecomp:start func_003E51F8 */
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern s32 func_003E58F8();
extern void func_003E6348(void **, s32, s32);
extern void *func_003EF110();
extern s32 func_003F2388();
extern void func_003E73A0(s32);
extern s32 func_003E73A8();
s32 func_003E51F8(s32 a) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 r = 0;
    s32 obj;
    s32 e;
    s32 d;
    s32 vv;
    s32 w;
    s32 t1;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    obj = func_003E6DE8(q);
    func_003E73A0(0x54);
    vv = func_003E73A8();
    if (obj != 0) {
        if (func_003E58F8(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6C08(p);
            t1 = func_003E6CC0(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EF110(func_003F2388(0x54, e));
                r = ((s32 (*)())func_003E6348)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6C08(p);
                    w = func_003E6CC0(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E51F8 */

/* localdecomp:start func_003E5360 */
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E5360;
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern void func_003E73A0(s32);
extern s32 func_003E73A8(void);
extern s32 func_003E58F8();
extern s32 func_003E6CC0();
extern s32 func_003F2388(s32, s32);
extern void *func_003EFF18();
extern void func_003E6348(void **, s32, s32);
s32 func_003E5360(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 a, b, c, r;
    D_3E5360 *d;
    O_3DFE10 *o;
    r = 0;
    q = D_001DA938;
    if (!q->x4) q = func_003E6C08();
    a = func_003E6DE8(q);
    func_003E73A0(0x64);
    b = func_003E73A8();
    if (a != 0) {
        if (func_003E58F8(a, arg0) == 0) {
            p = D_001DA938;
            if (p->x4) q = p; else q = func_003E6C08(p);
            o = (O_3DFE10 *)func_003E6CC0(q, 1);
            c = o->vt->f8(o, b);
            if (c != 0) {
                d = func_003EFF18(func_003F2388(0x64, c));
                r = ((s32 (*)())func_003E6348)(a, d, arg0) != 0;
                if (r == 0) {
                    ((void (*)())d->vt->f8)(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p; else q = func_003E6C08(p);
                    o = (O_3DFE10 *)func_003E6CC0(q, 1);
                    o->vt->fC(o, c);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5360 */

LINKER_REMNANT("asm/remnants", func_003E54C8);

/* localdecomp:start func_003E54E0 */
extern u8 D_001D9580;
extern s32 D_001D9578;
extern s32 func_003E7838(s32, s32, s32);
void func_003E54E0(s32 a) {
    if (D_001D9580 != 0) {
        D_001D9578 = a;
        func_003E7838(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003E54E0 */

LINKER_REMNANT("asm/remnants", func_003E5510);

extern u8 D_001A71C4[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001D9C10;
extern s32 D_001D9C14;
extern s32 D_001D9C38;
extern s32 D_001D9C40;
extern s16 D_001D9EB4;
extern s16 D_001D9EB6;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
INCLUDE_ASM("asm/nonmatchings/text", func_003E5520);

/* func_003E55B8 (frontbin): PAL matching candidate.
   Based on the US draft (rac3-uya-decomp func_003E0068, commit 13cf5c5) with the
   names moved to the PAL addresses.  The US build needed the single-function
   override @ps2as; here the file's own flags (-mvu0-use-vf0-vf2 -O2 -G8
   -fopt-stack -mno-check-zero-division) have to produce the retail bytes, so
   the globals the retail touches with %hi/%lo (large data) are declared with a
   .extern size above -G8, and the ones the retail touches with $gp (small data)
   with a size of 4.  The frame-counter threshold is the PAL constant 0x2EE. */

/* large data: the retail reaches these with lui/lw (or lui/addiu) */
__asm__(".extern D_001D52FC_003E55B8, 16");
__asm__(".extern D_001D9D00_003E55B8, 16");
__asm__(".extern D_001D4C38_003E55B8, 16");
__asm__(".extern D_001D5BC4_003E55B8, 16");
__asm__(".extern D_001DA580_003E55B8, 16");
__asm__(".extern D_001D9110_003E55B8, 16");
/* small data: the retail reaches these with $gp */
__asm__(".extern D_001D95C8_003E55B8, 4");
__asm__(".extern D_001D4C38_gp_003E55B8, 4");
__asm__(".extern D_001D545C_003E55B8, 4");

extern u8 *D_001D52FC_003E55B8;
extern s32 D_001D95C8_003E55B8;
extern s32 D_001D4C38_gp_003E55B8;
extern s32 D_001D4C38_003E55B8;
extern s32 D_001D545C_003E55B8;
extern s32 D_001D9D00_003E55B8;
extern s32 D_001D5BC4_003E55B8;
extern s32 D_001DA580_003E55B8;
extern s32 D_001D9110_003E55B8;
extern s32 D_001A91E8_003E55B8[];

/* localdecomp:start func_003E55B8 */
void func_003E55B8(void) {
    u8 *o = D_001D52FC_003E55B8;
    s32 *c;
    if (*(s32 *)(o + 0x1A0) != 0) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x108) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x10C) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x100) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else if (*(f32 *)(o + 0x104) != 0.0f) {
        D_001D95C8_003E55B8 = 0;
    } else {
        D_001D95C8_003E55B8 = D_001D95C8_003E55B8 + 1;
    }
    D_001D9D00_003E55B8 += 1;
    D_001D4C38_gp_003E55B8 = D_001D4C38_003E55B8 + 1;
    if (D_001D5BC4_003E55B8 != 0 && D_001D95C8_003E55B8 < 0x2EE) {
        c = &D_001A91E8_003E55B8[D_001D545C_003E55B8];
        *c += 1;
    }
    if (D_001DA580_003E55B8 != D_001D4C38_003E55B8 - 1) {
        D_001D9110_003E55B8 = -1;
    }
}
/* localdecomp:end func_003E55B8 */
TEXT_PADDING(2);

LINKER_REMNANT("asm/remnants", func_003E56C8);

INCLUDE_ASM("asm/nonmatchings/text", func_003E56E0);
