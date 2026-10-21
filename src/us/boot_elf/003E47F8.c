#include "common.h"

/* NTSC-U version of func_003E4940 (boot_elf): 0.13 -> 0.1335; 0.009 -> 0.008; 0.05 -> 0.049333 */

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
extern s32 func_11BB58(void *, void *, s32);
extern s32 func_11B868(void *);
extern void func_11B2E8();
typedef struct { u8 pad[0x40]; s32 f40; u8 pad2[0x14]; s32 f58; } S_302D80;
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
extern W_3DE8F0 D_1A4BE0[];
extern F_3DE8F0 D_142CA0[];
extern s32 D_U_001DA868[2];
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
extern s32 func_U_003E80A0(s32, s32);
extern s32 func_U_003E7A90(s32, s32, s32);
extern s32 func_U_003E7FC8(s32, s32);
extern void func_11B2E8(void *, char *, s32);
typedef struct { u8 pad[0x28B4]; s32 a; s32 b; } S_003DEEF0;
extern s32 func_U_003E8448(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
/* localdecomp:start func_U_003E47F8 */
__asm__(".extern D_U_001D9594, 1");
__asm__(".extern D_U_001D959D, 1");
__asm__(".extern D_U_001D959C, 1");
__asm__(".extern D_U_001D97A0, 4");
typedef struct { s32 x0, x4, x8, xC; } S_3DF038;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_3DF038;
typedef struct { u8 pad[8]; VT_3DF038 *vt; u8 padC[0x3E]; s16 x4A; } W_3DF038;

extern u8 D_U_001D9594;
extern u8 D_U_001D959D;
extern u8 D_U_001D959C;
extern s32 D_U_001D97A0;
extern s32 D_U_001DA868[2];
extern S_3DF038 D_U_001DA9B8[];

extern void func_U_003E7608_003E4940(s32);
extern void func_U_0038CEA0(void *, s32, s32);
extern void func_U_003B5268(s32);
extern s32 func_U_003E5300(s32);
extern s32 func_U_003E5468(s32);
extern s32 func_U_003E55D0(s32);
extern s32 func_U_003823F0(s32);
extern s32 func_U_00392D38(void);
extern s32 func_U_003E9240(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_U_003E9390(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_U_003E7D20(s32, s32);
extern s32 func_U_003E7B80(s32, s32, s32);
extern s32 func_U_003E7A90(s32, s32, s32);
extern s32 func_U_003E8250(s32, s32, s32, s32, s32);
extern s32 func_U_003E8358(s32, s32, s32);
extern s32 func_U_003E7610(s32, f32, f32);
extern s32 func_U_003E77E8(s32, f32, f32);
extern s32 func_U_003E8448(s32, f32, f32);
extern s32 func_U_003E8178(s32, s32);
extern s32 func_U_003E7FC8(s32, s32);
extern s32 func_U_003E7EE8_003E4940(s32, void *);
extern s32 func_U_003E80A0(s32, s32);
extern s32 func_U_003E8888(s32, s32);
extern s32 func_U_003E85A0(s32, s32);
extern void func_U_003E7260_003E4940(s32, s32);
extern void func_U_003E40B0(void);
extern S_3DF038 *func_U_003E6E78_003E4940(S_3DF038 *);
extern s32 func_U_003E7058_003E4940(S_3DF038 *);
extern W_3DF038 *func_U_003E65E8(s32, s32);

void func_U_003E47F8(s32 arg0) {
    S_3DF038 *p;
    S_3DF038 *q;
    W_3DF038 *t;
    W_3DF038 *v;

    D_U_001D9594 = 1;
    func_U_003E7608_003E4940(1);
    func_U_0038CEA0(D_U_001DA868, 0, 8);
    func_U_003B5268(0x90000);
    func_U_003E5300(0x90001);
    func_U_003E5300(0x90002);
    func_U_003E5468(0x90003);
    func_U_003E5468(0x90004);
    func_U_003E5468(0x90005);
    func_U_003E55D0(0x90006);
    func_U_003E5468(0x90007);
    func_U_003E9240(0x9000C, func_U_003823F0(0x182D), 0x8066CCFF, 0.4285f, 0.1315f, 0.6f, 0.6f);
    func_U_003E7D20(0x9000C, 1);
    func_U_003E9390(0x90008, 0x706EC8FF, 0, 0.598917f, 0.074f, 0.043083f, 0.050416f);
    func_U_003E7B80(0x90008, 1, 3);
    func_U_003E8250(0x90008, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_U_003E8358(0x90002, func_U_00392D38(), 0x8C);
    func_U_003E8358(0x90001, func_U_00392D38(), 0x8D);
    func_U_003E7610(0x90003, 0.487997f, 0.074f);
    func_U_003E7610(0x90004, 0.440497f, 0.074f);
    func_U_003E7610(0x90005, 0.39347f, 0.074f);
    func_U_003E7610(0x90006, 0.627999f, 0.069f);
    func_U_003E77E8(0x90006, 0.003f, 0.003f);
    func_U_003E8178(0x90006, 1);
    func_U_003E7610(0x90007, 0.464136f, 0.133499995f);
    func_U_003E8448(0x90003, 0.035f, 0.035f);
    func_U_003E8448(0x90004, 0.035f, 0.035f);
    func_U_003E8448(0x90005, 0.035f, 0.035f);
    func_U_003E8448(0x90006, 1.0f, 1.0f);
    func_U_003E8448(0x90007, 0.0f, 0.00800000038f);
    func_U_003E7FC8(0x90001, 0x331465B7);
    func_U_003E7FC8(0x90002, 0x332299DE);
    func_U_003E7FC8(0x90003, 0x8066CCFF);
    func_U_003E7FC8(0x90004, 0x8066CCFF);
    func_U_003E7FC8(0x90005, 0x8066CCFF);
    func_U_003E7FC8(0x90006, 0x8066CCFF);
    func_U_003E7FC8(0x90007, 0x706EC8FF);
    func_U_003E7EE8_003E4940(0x90006, D_U_001DA868);
    func_U_003E7B80(0x90006, 1, 1);
    func_U_003E7B80(0x90007, 1, 3);
    func_U_003E7A90(0x90006, 0x40, 1);
    func_U_003E7A90(0x90003, 0x40, 1);
    func_U_003E7A90(0x90004, 0x40, 1);
    func_U_003E7A90(0x90005, 0x40, 1);
    func_U_003E7B80(0x90003, 1, 3);
    func_U_003E7B80(0x90004, 1, 3);
    func_U_003E7B80(0x90005, 1, 3);

    func_U_003E80A0(0x90003, 0xED1C);
    p = D_U_001DA9B8;
    if (p->x4) q = p; else q = func_U_003E6E78_003E4940(p);
    t = func_U_003E65E8(func_U_003E7058_003E4940(q), 0x90003);
    v = (t != 0 && t->vt->isA(t, D_U_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_U_003E80A0(0x90004, 0xED1D);
    p = D_U_001DA9B8;
    if (p->x4) q = p; else q = func_U_003E6E78_003E4940(p);
    t = func_U_003E65E8(func_U_003E7058_003E4940(q), 0x90004);
    v = (t != 0 && t->vt->isA(t, D_U_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_U_003E80A0(0x90005, 0xED1E);
    p = D_U_001DA9B8;
    if (p->x4) q = p; else q = func_U_003E6E78_003E4940(p);
    t = func_U_003E65E8(func_U_003E7058_003E4940(q), 0x90005);
    v = (t != 0 && t->vt->isA(t, D_U_001D97A0) != 0) ? t : 0;
    v->x4A = 0;

    func_U_003E9390(0x9000A, 0x59000000, 0, 0.61558104f, 0.0739995f, 0.230333f, 0.0493329987f);
    func_U_003E7B80(0x9000A, 2, 3);
    func_U_003E9390(0x9000B, 0x59000000, 0, 0.385248f, 0.0739995f, 0.230333f, 0.0493329987f);
    func_U_003E7B80(0x9000B, 1, 3);
    func_U_003E8250(0x9000B, 0x601465B7, 0x6066CCFF, 0x601465B7, 0x6066CCFF);
    func_U_003E8888(0x90000, 0x90001);
    func_U_003E8888(0x90000, 0x90002);
    func_U_003E8888(0x90000, 0x9000A);
    func_U_003E8888(0x90000, 0x9000B);
    func_U_003E8888(0x90000, 0x90006);
    func_U_003E8888(0x90000, 0x90007);
    func_U_003E8888(0x90000, 0x90008);
    func_U_003E8888(0x90000, 0x90003);
    func_U_003E8888(0x90000, 0x90004);
    func_U_003E8888(0x90000, 0x90005);
    func_U_003E8888(0x90000, 0x9000C);
    func_U_003E85A0(7, 0x90000);
    func_U_003E7260_003E4940(arg0, 1);
    func_U_003E40B0();
    func_U_003E7608_003E4940(0);
    D_U_001D959D = 0;
    D_U_001D959C = 1;
}
/* localdecomp:end func_U_003E47F8 */
