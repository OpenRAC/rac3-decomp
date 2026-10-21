#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E15B0.c's earlier functions (tools/port_from_us.py) */
extern void func_003A96A8(s32);
extern void func_00391708(void);
extern s32 D_001D5520[];
extern void func_00391A58(s32, s32, s32, s32, s32, s32);
extern void func_003D96F0(void);
extern s32 D_00306D40[];
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
extern f32 D_001D94CC;
extern f32 D_00222420[];
extern void func_003C50A0();
extern void func_0038DBF0();
extern void func_0038D9D0();
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
extern S_302D80 D_00306D00;
extern s32 D_00306D40[];
extern s32 D_001D94B0;
extern s16 D_00306D84[];

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
extern R_3DE8F0 *func_00382728(M_3DE8F0 *);
extern s32 func_0038DFB8(s32, s32, f32);
extern f32 func_0038D478(f32);
extern s32 func_003E41E8(s32);
extern void func_003E5428(f32 *, f32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E7F38_003E41F8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E41F8);

typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381C40();
extern s32 func_003E85A8(s32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E47F8);

/* localdecomp:start func_003E48C0 */
extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E85A8(s32, f32, f32);
void func_003E48C0(void) {
    if (D_00142CC0[0]) {
        u8 *s = D_001426E0;
        f32 r = 0.0f;
        if (s[0xD4]) r = (f32)s[0xD3] / (f32)s[0xD4];
        func_003E85A8(0x90008, r * 0.0430830009f, 0.0504160002f);
    }
}
/* localdecomp:end func_003E48C0 */

/* func_003E4940 (from rac3-uya-decomp func_003E47F8, commit 13cf5c5), names moved to PAL
   addresses where known. Matches the PAL retail bytes with this file's own compiler flags.
   PAL differs from the US draft in three float constants: 0.13f (was 0.1335f), 0.009f
   (was 0.008f), and 0.05f (was 0.049333f, in both func_003E94F0 calls, where it is shared). */


/* localdecomp:start func_003E4940 */
__asm__(".extern D_001D9554, 1");
__asm__(".extern D_001D955D, 1");
__asm__(".extern D_001D955C, 1");
__asm__(".extern D_001D9760, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;

extern u8 D_001D9554;
extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 D_001D9760;
extern s32 D_001DA7E8[2];
extern S_3DF038 D_001DA938[];

extern void func_003E7768_003E4940(s32);
extern void func_0038CF58(void *, s32, s32);
extern void func_003B5418(s32);
extern s32 func_003E5448(s32);
extern s32 func_003E55B0(s32);
extern s32 func_003E5718(s32);
extern s32 func_003823D0(s32);
extern s32 func_00392DF8(void);
extern s32 func_003E93A0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E94F0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7E80(s32, s32);
extern s32 func_003E7CE0(s32, s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E83B0(s32, s32, s32, s32, s32);
extern s32 func_003E84B8(s32, s32, s32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E7948(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E82D8(s32, s32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E8048_003E4940(s32, void *);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E89E8(s32, s32);
extern s32 func_003E8700(s32, s32);
extern void func_003E73A8_003E4940(s32, s32);
extern void func_003E41F8(void);
extern S_3DF038 *func_003E6FC0_003E4940(S_3DF038 *);
extern s32 func_003E71A0_003E4940(S_3DF038 *);
extern W_3DF038 *func_003E6730(s32, s32);

void func_003E4940(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    W_3DF038 *t;
    W_3DF038 *v;

    D_001D9554 = 1;
    func_003E7768_003E4940(1);
    func_0038CF58(D_001DA7E8, 0, 8);
    func_003B5418(0x90000);
    func_003E5448(0x90001);
    func_003E5448(0x90002);
    func_003E55B0(0x90003);
    func_003E55B0(0x90004);
    func_003E55B0(0x90005);
    func_003E5718(0x90006);
    func_003E55B0(0x90007);
    func_003E93A0(0x9000C, func_003823D0(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_003E7E80(0x9000C, 1);
    func_003E94F0(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_003E7CE0(0x90008, 1, 3);
    func_003E83B0(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E84B8(0x90002, func_00392DF8(), 0x8C);
    func_003E84B8(0x90001, func_00392DF8(), 0x8D);
    func_003E7770(0x90003, 0.487997f, 0.074f);
    func_003E7770(0x90004, 0.440497f, 0.074f);
    func_003E7770(0x90005, 0.39347f, 0.074f);
    func_003E7770(0x90006, 0.627999f, 0.069f);
    func_003E7948(0x90006, 0.003f, 0.003f);
    func_003E82D8(0x90006, 1);
    func_003E7770(0x90007, 0.464136f, 0.13f);
    func_003E85A8(0x90003, 0.035f, 0.035f);
    func_003E85A8(0x90004, 0.035f, 0.035f);
    func_003E85A8(0x90005, 0.035f, 0.035f);
    func_003E85A8(0x90006, 1.0f, 1.0f);
    func_003E85A8(0x90007, 0.0f, 0.009f);
    func_003E8128(0x90001, 0x331465B7);
    func_003E8128(0x90002, 0x332299DE);
    func_003E8128(0x90003, 0x8066CCFF);
    func_003E8128(0x90004, 0x8066CCFF);
    func_003E8128(0x90005, 0x8066CCFF);
    func_003E8128(0x90006, 0x8066CCFF);
    func_003E8128(0x90007, 0x706EC8FF);
    func_003E8048_003E4940(0x90006, D_001DA7E8);
    func_003E7CE0(0x90006, 1, 1);
    func_003E7CE0(0x90007, 1, 3);
    func_003E7BF0(0x90006, 0x40, 1);
    func_003E7BF0(0x90003, 0x40, 1);
    func_003E7BF0(0x90004, 0x40, 1);
    func_003E7BF0(0x90005, 0x40, 1);
    func_003E7CE0(0x90003, 1, 3);
    func_003E7CE0(0x90004, 1, 3);
    func_003E7CE0(0x90005, 1, 3);

    func_003E8200(0x90003, 0xED1C);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6FC0_003E4940(p);
    t = func_003E6730(func_003E71A0_003E4940(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E8200(0x90004, 0xED1D);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6FC0_003E4940(p);
    t = func_003E6730(func_003E71A0_003E4940(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E8200(0x90005, 0xED1E);
    p = D_001DA938;
    if (p->x4) q = p; else q = func_003E6FC0_003E4940(p);
    t = func_003E6730(func_003E71A0_003E4940(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_001D9760) != 0) ? t : 0;
    v->x4A = 0;

    func_003E94F0(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7CE0(0x9000A, 2, 3);
    func_003E94F0(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.05f);
    func_003E7CE0(0x9000B, 1, 3);
    func_003E83B0(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_003E89E8(0x90000, 0x90001);
    func_003E89E8(0x90000, 0x90002);
    func_003E89E8(0x90000, 0x9000A);
    func_003E89E8(0x90000, 0x9000B);
    func_003E89E8(0x90000, 0x90006);
    func_003E89E8(0x90000, 0x90007);
    func_003E89E8(0x90000, 0x90008);
    func_003E89E8(0x90000, 0x90003);
    func_003E89E8(0x90000, 0x90004);
    func_003E89E8(0x90000, 0x90005);
    func_003E89E8(0x90000, 0x9000C);
    func_003E8700(7, 0x90000);
    func_003E73A8_003E4940(arg0, 1);
    func_003E41F8();
    func_003E7768_003E4940(0);
    D_001D955D = 0;
    D_001D955C = 1;
}
/* localdecomp:end func_003E4940 */
