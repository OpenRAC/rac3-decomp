#include "common.h"

/* localdecomp:start func_L39_005D9908 */
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_001D7F50_sda, 8");
__asm__(".extern D_001D7F80_sda, 1");
__asm__(".extern D_001D7FA8_sda, 4");
__asm__(".extern D_001D7FD0_sda, 4");
__asm__(".extern D_001D7FE8_sda, 4");
__asm__(".extern D_001DA5F0_sda, 4");
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_005D9908;
typedef struct { u8 pad[0x4A]; s16 f4A; } W_005D9908;
typedef struct { s32 a[6]; } E_005D9908;

extern E_005D9908 D_L39_002B5780[];
extern S_005D9908 D_L39_0024CD50;
extern s32 *D_L39_00241120;
typedef struct { u8 a, b, c; } T_005D9908;
extern T_005D9908 D_L39_00243691;
extern u8 D_001D7F50_sda[8];
extern u8 D_001D7F80_sda;
extern f32 D_001D7FA8_sda;
extern f32 D_001D7FD0_sda;
extern f32 D_001D7FE8_sda;
extern s32 D_001DA5F0_sda;

extern s32 func_L01_00517688(void);
extern void func_L01_004D2110_005D9908(s32);
extern void func_0038CB78(void *, s32, s32);
extern void func_003B5060(s32);
extern void func_003E5090(s32);
extern void func_003E5360(s32);
extern void func_003E51F8(s32);
extern s32 func_00392A18(void);
extern s32 func_L39_00611AC8(s32, s32, s32);
extern void func_L01_005170B8(s32, s32);
extern void func_L01_005169C8(s32, f32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00484A80(s32);
extern s32 func_003E8348(s32, s32);
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void func_L01_00516C78_005D9908(s32, s32, s32);
extern s32 func_L01_00516FD8(s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern void func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_00516470(s32, f32, f32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003E6FF0(s32, s32);
extern void func_L39_005DB800(void);
extern void func_L39_005DB370(void);
extern void func_L39_005DA870(s32, s32, s32, s32);

void func_L39_005D9908(s32 arg0) {
    s32 idx;
    s32 i;
    f32 a, b, c, d, e;
    S_005D9908 *q;
    s32 *base;
    void *p;
    void *w;

    idx = func_L01_00517688();
    D_001D7F50_sda[idx] = 1;
    func_L01_004D2110_005D9908(1);
    func_0038CB78(&D_L39_002B5780[idx], 0, 0x18);
    func_003B5060(0x20000);
    func_003B5060(0x20001);
    func_003B5060(0x20002);
    func_003E5090(0x20003);
    func_L39_00611AC8(0x20003, func_00392A18(), 0x20);
    func_L01_005170B8(0x20003, 0x331465B7);
    func_L01_005169C8(0x20003, D_001D7FA8_sda);
    func_003E5090(0x20004);
    func_L39_00611AC8(0x20004, func_00392A18(), 0x1F);
    func_L01_005170B8(0x20004, 0x332299DE);
    func_L01_005169C8(0x20004, D_001D7FA8_sda);
    func_003E8A08(0x20002, 0x20003, 0x20004);

    func_003E51F8(0x20006);
    func_L01_005170B8(0x20006, 0x706EC8FF);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x20006);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D9908 *)w)->f4A = 0;
    func_003E51F8(0x20007);
    func_L01_005170B8(0x20007, 0x506EC8FF);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x20007);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D9908 *)w)->f4A = 0;
    func_003E51F8(0x20008);
    func_L01_005170B8(0x20008, 0x306EC8FF);
    q = &D_L39_0024CD50;
    if (q->f4 != 0) { base = (s32 *)q; } else { base = (s32 *)func_003E6C08(); }
    p = (void *)func_003E6378(func_003E6DE8(base), 0x20008);
    w = (p != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001DA5F0_sda) != 0) ? p : 0;
    ((W_005D9908 *)w)->f4A = 0;

    a = 0.88f;
    func_003E5360(0x20005);
    b = 0.1f;
    func_L01_005170B8(0x20005, 0x7075D5FF);
    c = -1.2f;
    func_L01_00516C78_005D9908(0x20005, 2, 1);
    d = 1.2f;
    func_L01_00516FD8(0x20005, (s32)&D_L39_002B5780[idx]);
    e = 1.2307693f;
    func_L01_00516AA0(0x20005, 0x40, 1);
    func_003E5360(0x2000A);
    func_L01_005170B8(0x2000A, 0x8066CCFF);
    func_L01_00516FD8(0x2000A, 0);
    func_L01_00516AA0(0x2000A, 0x40, 1);
    func_003E8AE8(0x20002, 0x20006, 0x20007, 0x20008, 0x20005, 0x2000A);
    func_003E5090(0x20009);
    func_L01_005170B8(0x20009, 0x706EC8FF);
    func_L39_00611AC8(0x20009, func_00392A18(), 0x6F);
    func_003E51F8(0x2000B);
    func_L01_005170B8(0x2000B, 0x332299DE);
    func_L01_00516C78_005D9908(0x2000B, 1, 3);
    func_L01_00516D60(0x2000B, 0);
    func_003E8A08(0x20002, 0x20009, 0x2000B);
    func_003E5090(0x20011);
    func_L39_00611AC8(0x20011, func_00392A18(), 0x4F);
    func_L01_005170B8(0x20011, 0x331465B7);
    func_003E5090(0x20010);
    func_L39_00611AC8(0x20010, func_00392A18(), 0x4E);
    func_L01_005170B8(0x20010, 0x332299DE);
    func_003E9138(0x20012, 0x332299DE, 0.074f, 0.224f, 0.05f, 0.005f, 0);
    func_L01_00518110(0x20002, 0x20011, 0x20010, 0x20012);
    func_003E8630(0x20001, 0x20002);
    func_003B5060(0x20013);
    func_003E5090(0x20014);
    func_L01_00516AA0(0x20014, 1, 0);
    func_L39_00611AC8(0x20014, func_00392A18(), 0x2F);
    func_L01_005170B8(0x20014, 0x332299DE);
    func_L01_00516470(0x20014, b, D_001D7FD0_sda + a);
    func_L01_00517538(0x20014, c, d);
    func_003E5090(0x20015);
    func_L01_00516AA0(0x20015, 1, 0);
    func_L39_00611AC8(0x20015, func_00392A18(), 0x30);
    func_L01_005170B8(0x20015, 0x331465B7);
    func_L01_00516470(0x20015, b, D_001D7FD0_sda + a);
    func_L01_00517538(0x20015, c, d);
    func_003E8A08(0x20013, 0x20015, 0x20014);
    func_003E9138(0x20016, 0x706EC8FF, b, D_001D7FD0_sda + 0.876f, b, 0.12f, 0);
    func_L01_00516AA0(0x20016, 1, 0);
    func_003E9138(0x20017, 0x8000FF00, b, D_001D7FD0_sda + 0.866f, 0.03f, 0.03f, 0);
    func_L01_00516AA0(0x20017, 1, 0);
    func_L01_00517190(0x20017, 0xED35);
    func_003E9138(0x20018, 0x8000FF00, 0.075f, D_001D7FD0_sda + 0.085f, 0.025f, 0.025f, 0);
    func_L01_00516AA0(0x20018, 1, 0);
    func_L01_00517190(0x20018, 0xED35);
    func_L01_00518110(0x20013, 0x20016, 0x20017, 0x20018);
    func_003E8630(0x20001, 0x20013);
    func_003E8630(0x20000, 0x20001);
    func_L01_00484A80(0x2000C);
    func_003E5090(0x2000E);
    func_L39_00611AC8(0x2000E, func_00392A18(), 0x10);
    func_L01_005170B8(0x2000E, 0x331465B7);
    func_003E5090(0x2000D);
    func_L39_00611AC8(0x2000D, func_00392A18(), 0x11);
    func_L01_005170B8(0x2000D, 0x332299DE);
    func_003E51F8(0x2000F);
    func_L01_005170B8(0x2000F, 0x8066CCFF);
    func_L01_00516C78_005D9908(0x2000F, 3, 2);
    func_L01_00517538(0x2000F, 0.0f, 0.0f);
    func_L01_00518110(0x2000C, 0x2000E, 0x2000D, 0x2000F);
    func_L01_00516D60(0x2000C, 0);
    func_003E8630(0x20000, 0x2000C);
    func_L01_00484A80(0x20019);
    func_L01_00484A80(0x2001A);
    if (*D_L39_00241120 == 2) {
        e = 1.3461539f;
    }
    for (i = 0; i < 17; i++) {
        f32 g = D_001D7FE8_sda;
        func_003E9138(0x2001B + i, 0x706EC8FF, 0.5f - (4.0f - (f32)i * 0.5f) * g, 0.5f, g, g * e, 0);
        func_003E8630(0x20019 + (i & 1), 0x2001B + i);
    }
    func_L01_00516D60(0x20019, 0);
    func_L01_00516D60(0x2001A, 0);
    func_003E8A08(0x20000, 0x20019, 0x2001A);
    func_003E8348(6, 0x20000);
    if (*D_L39_00241120 == 2) {
        func_L39_005DB800();
    } else {
        func_L39_005DB370();
    }
    D_001D7F80_sda = 0;
    D_L39_00243691.a = 0;
    D_L39_00243691.b = 0;
    D_L39_00243691.c = 0;
    func_L39_005DA870(0, 0, 0, -1);
    func_L39_005DA870(0, 0, 1, -1);
    func_L39_005DA870(0, 0, 2, -1);
    func_003E6FF0(arg0, 1);
    func_L01_004D2110_005D9908(0);
}
/* localdecomp:end func_L39_005D9908 */

INCLUDE_ASM("asm/levels", func_L39_005DA400);
