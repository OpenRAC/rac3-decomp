#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003E5428(f32 *, f32);
extern s32 func_003E5448(s32);
extern s32 func_003E55B0(s32);
extern s32 func_003E5718(s32);
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
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
extern s32 func_003E7DD0(s32, s32);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E8128(s32, s32);
extern s32 func_003E7F38_003E41F8(s32, f32 *, f32 *, f32 *, f32 *);
extern void func_11B2E8(void *, char *, s32);
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern S_003DEEF0 D_001A4BE0;
extern s32 D_00142694[];
extern void func_00381C40();
extern s32 func_003E85A8(s32, f32, f32);
extern u8 D_00142CC0[];
extern u8 D_001426E0[];
extern s32 func_003E85A8(s32, f32, f32);
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

/* localdecomp:start func_003E50C8 */
extern u8 D_001D9554;
extern u8 D_001D9566;
extern s32 D_001D9550;
extern s32 func_003E7BF0(s32, s32, s32);
extern s32 func_003E52E8(s32);
extern void func_003E5260();
void func_003E50C8(s32 a) {
    if (D_001D9554 != 0 && D_001D9566 == 0) {
        D_001D9550 = a;
        func_003E7BF0(0x90000, 1, a != 0);
        func_003E5260(func_003E52E8(0));
    }
}
/* localdecomp:end func_003E50C8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5118);

extern u8 D_001D955D;
extern u8 D_001D955C;
extern s32 func_00392DF8(void);
extern s32 func_003E84B8(s32, s32, s32);
extern s32 func_003E7770(s32, f32, f32);
extern s32 func_003E85A8(s32, f32, f32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003E5128);

/* localdecomp:start func_003E5260 */
extern s32 D_001D9550;
extern u8 D_001D9566;
extern void func_003E5128(s32);
extern void func_003E41F8(void);
extern void func_003E47F8(void);
extern void func_003E48C0(void);
extern s32 func_003E7BF0(s32, s32, s32);
void func_003E5260(void) {
    if (D_001D9550 != 0 && D_001D9566 == 0) {
        D_001D9550--;
        func_003E5128(0x90000);
        func_003E41F8();
        func_003E47F8();
        func_003E48C0();
    } else {
        func_003E7BF0(0x90000, 1, 0);
    }
}
/* localdecomp:end func_003E5260 */

/* localdecomp:start func_003E52C8 */
extern u8 D_001D9554;
extern s32 func_003E8960();
void func_003E52C8(void) {
    D_001D9554 = 0;
    func_003E8960(7);
}
/* localdecomp:end func_003E52C8 */

/* localdecomp:start func_003E52E8 */
typedef struct { u8 b[16]; } V16_3DF9E0;
extern void func_003E4940(s32);
extern void func_003E52C8(void);
extern void func_003E5260(void);
extern s32 func_003E7358(s32 *, s32, s32, s32, s32, s32);
extern s32 D_001DA780;
extern s32 D_001DA7A0;
extern s32 D_001DA7C0;
extern s32 D_001DA7E0;
extern s32 D_001DA768[2];
extern s32 D_001DA788[2];
extern s32 D_001DA7A8[2];
extern s32 D_001DA7C8[2];
extern V16_3DF9E0 D_001D9568[];
s32 func_003E52E8(s32 idx) {
    V16_3DF9E0 v;
    if (D_001DA780 == 0) {
        func_003E7358(D_001DA768, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA780 = 1;
    }
    if (D_001DA7A0 == 0) {
        func_003E7358(D_001DA788, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7A0 = 1;
    }
    if (D_001DA7C0 == 0) {
        func_003E7358(D_001DA7A8, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7C0 = 1;
    }
    if (D_001DA7E0 == 0) {
        func_003E7358(D_001DA7C8, (s32)func_003E4940, (s32)func_003E52C8, (s32)func_003E5260, 0, 0);
        D_001DA7E0 = 1;
    }
    v = D_001D9568[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_003E52E8 */

/* localdecomp:start func_003E5428 */
void func_003E5428(f32 *p, f32 a) {
    *p = (a < *p) ? a : *p;
}
/* localdecomp:end func_003E5428 */

/* localdecomp:start func_003E5448 */
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern void func_003E6700(void **, s32, s32);
extern void *func_003F2060();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003E5448(s32 a) {
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
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x48);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003F2060(func_003F2740(0x48, e));
                r = ((s32 (*)())func_003E6700)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6FC0(p);
                    w = func_003E7078(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5448 */

/* localdecomp:start func_003E55B0 */
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern s32 func_003E7078();
extern s32 func_003E5CB0();
extern void func_003E6700(void **, s32, s32);
extern void *func_003EF4C8();
extern s32 func_003F2740();
extern void func_003E7758(s32);
extern s32 func_003E7760();
s32 func_003E55B0(s32 a) {
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
    if (!q->x4) q = func_003E6FC0();
    obj = func_003E71A0(q);
    func_003E7758(0x54);
    vv = func_003E7760();
    if (obj != 0) {
        if (func_003E5CB0(obj, a) == 0) {
            p = D_001DA938;
            if (p->x4) q = p;
            else q = func_003E6FC0(p);
            t1 = func_003E7078(q, 1);
            e = (*(s32 (**)(s32, s32))(*(s32 *)t1 + 8))(t1, vv);
            if (e != 0) {
                d = (s32)func_003EF4C8(func_003F2740(0x54, e));
                r = ((s32 (*)())func_003E6700)(obj, d, a) != 0;
                if (r == 0) {
                    (*(void (**)(s32, s32))(*(s32 *)(d + 8) + 8))(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p;
                    else q = func_003E6FC0(p);
                    w = func_003E7078(q, 1);
                    (*(s32 (**)(s32, s32))(*(s32 *)w + 0xC))(w, e);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E55B0 */

/* localdecomp:start func_003E5718 */
typedef struct { u8 pad[8]; s32 (*f8)(); s32 (*fC)(); } VT_3DFE10;
typedef struct { VT_3DFE10 *vt; } O_3DFE10;
typedef struct { u8 pad[8]; VT_3DFE10 *vt; } D_3E5718;
extern void *func_003E6FC0();
extern s32 func_003E71A0();
extern void func_003E7758(s32);
extern s32 func_003E7760(void);
extern s32 func_003E5CB0();
extern s32 func_003E7078();
extern s32 func_003F2740(s32, s32);
extern void *func_003F02D0();
extern void func_003E6700(void **, s32, s32);
s32 func_003E5718(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    s32 a, b, c, r;
    D_3E5718 *d;
    O_3DFE10 *o;
    r = 0;
    q = D_001DA938;
    if (!q->x4) q = func_003E6FC0();
    a = func_003E71A0(q);
    func_003E7758(0x64);
    b = func_003E7760();
    if (a != 0) {
        if (func_003E5CB0(a, arg0) == 0) {
            p = D_001DA938;
            if (p->x4) q = p; else q = func_003E6FC0(p);
            o = (O_3DFE10 *)func_003E7078(q, 1);
            c = o->vt->f8(o, b);
            if (c != 0) {
                d = func_003F02D0(func_003F2740(0x64, c));
                r = ((s32 (*)())func_003E6700)(a, d, arg0) != 0;
                if (r == 0) {
                    ((void (*)())d->vt->f8)(d, 2);
                    p = D_001DA938;
                    if (p->x4) q = p; else q = func_003E6FC0(p);
                    o = (O_3DFE10 *)func_003E7078(q, 1);
                    o->vt->fC(o, c);
                }
            }
        }
    }
    return r;
}
/* localdecomp:end func_003E5718 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E5880);

/* localdecomp:start func_003E5898 */
extern u8 D_001D9580;
extern s32 D_001D9578;
extern s32 func_003E7BF0(s32, s32, s32);
void func_003E5898(s32 a) {
    if (D_001D9580 != 0) {
        D_001D9578 = a;
        func_003E7BF0(0x10000, 1, a != 0);
    }
}
/* localdecomp:end func_003E5898 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E58C8);
