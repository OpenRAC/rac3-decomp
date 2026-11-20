#include "common.h"

typedef struct {
    u8 pad0[0x34];
    u16 f34;
    u8 pad36[0xB2 - 0x36];
    s16 fB2;
    u8 padB4[0x100 - 0xB4];
} Type_004A3A90;

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x4B90 - 0x4958];
    u8 f4B90[1];
    u8 pad2[0x6D28 - 0x4B91];
    u8 fX[1];
} S_func_0049A930;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 pad[3];
} Ent_0049AB20;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14;
    u8 pad[3];
} S_2EC7A8;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    s32 v[12][3];
} S_236B80;
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_49E5B8;
typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 fC;
    u8 pad[11];
} S_2EC760_0049E648;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} S_2ED730_0049F2C8;

/* localdecomp:start func_L01_0049E9F0 */
extern s32 func_L01_0041A4F0(void);

s32 func_L01_0049E9F0(s32 a0) {
    s32 r = 0;
    if (func_L01_0041A4F0() == 0 || a0 != 0) {
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_0049E9F0 */

INCLUDE_ASM("asm/levels", func_L01_0049EA38);

/* localdecomp:start func_L01_0049EE28 */
__asm__(".extern D_L01_001D954C, 4");
extern s32 D_L01_001D954C;
extern E_49E5B8 D_L01_002ECBA8[];
extern u8 D_L01_001EA7C0_0049EE28[];
extern u8 D_L01_001426E0[];
extern s32 func_00392B20(void *, s32);
extern void func_00392C78(void *);
extern void func_00392DF0(s32, s32);

void func_L01_0049EE28(void) {
    s32 i;
    u32 t;

    if (!D_L01_002ECBA8[D_L01_001D954C].x14) {
        return;
    }
    switch (D_L01_002ECBA8[D_L01_001D954C].x10) {
    case 0:
        func_00392B20(D_L01_001EA7C0_0049EE28, D_L01_002ECBA8[D_L01_001D954C].xC);
        func_00392C78(D_L01_001EA7C0_0049EE28);
        return;
    case 1:
        for (i = 0; ((s32 *)D_L01_002ECBA8[D_L01_001D954C].xC)[i] != 0; i++) {
            func_00392B20(D_L01_001EA7C0_0049EE28, ((s32 *)D_L01_002ECBA8[D_L01_001D954C].xC)[i]);
        }
        func_00392C78(D_L01_001EA7C0_0049EE28);
        return;
    case 2:
    case 3:
        return;
    case 4:
    default:
        if (!D_L01_002ECBA8[D_L01_001D954C].x14) {
            return;
        }
        switch (D_L01_002ECBA8[D_L01_001D954C].x0) {
        case 0xE46:
            D_L01_001426E0[0x71] = 0x27;
            t = 0xFFFFFFFF;
            D_L01_001426E0[0x72] = t;
            func_00392DF0(4, 1);
            break;
        case 0xE47: func_00392DF0(7, 1); break;
        case 0xE48: func_00392DF0(0x1C, 1); break;
        case 0xE49: func_00392DF0(0x1D, 1); break;
        case 0xE4B: func_00392DF0(0xC, 1); break;
        case 0xBC5: func_00392DF0(0x12, 1); break;
        case 0xD3D: func_00392DF0(0x1A, 1); break;
        case 0x15E9: func_00392DF0(0x17, 1); break;
        case 0x15EA: func_00392DF0(0xA, 1); break;
        case 0x15EB: func_00392DF0(0x1B, 1); break;
        case 0x15EC: func_00392DF0(1, 1); break;
        case 0x15ED:
            D_L01_001426E0[0x71] = 8;
            D_L01_001426E0[0x72] = 1;
            func_00392DF0(1, 1);
            break;
        case 0x15EE: func_00392DF0(2, 1); break;
        case 0x15EF: func_00392DF0(6, 1); break;
        case 0x15F0: func_00392DF0(9, 1); break;
        case 0x15F1: func_00392DF0(0x10, 1); break;
        case 0x15F2: func_00392DF0(0x15, 1); break;
        case 0x52F: func_00392DF0(0x18, 1); break;
        case 0x13A3: func_00392DF0(0x17, 1); break;
        }
        return;
    }
}
/* localdecomp:end func_L01_0049EE28 */

LINKER_REMNANT("asm/levels", func_L01_0049F150);

/* localdecomp:start func_L01_0049F168 */
extern void func_L01_0049F2C8(void);
extern void func_L01_0049F868_0049F168(void);
extern void func_L01_0049F798_0049F168(void);
extern void func_L01_0049F8A8_0049F168(void);
extern void func_L01_0049F8C8_0049F168(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
__asm__(".extern D_L01_001E0C58, 4");
extern s32 D_L01_001E0C58;
__asm__(".extern D_L01_001E0C78, 4");
extern s32 D_L01_001E0C78;
__asm__(".extern D_L01_001E0C98, 4");
extern s32 D_L01_001E0C98;
__asm__(".extern D_L01_001E0CB8, 4");
extern s32 D_L01_001E0CB8;
__asm__(".extern D_L01_001E0C40, 8");
extern s32 D_L01_001E0C40[2];
__asm__(".extern D_L01_001E0C60, 8");
extern s32 D_L01_001E0C60[2];
__asm__(".extern D_L01_001E0C80, 8");
extern s32 D_L01_001E0C80[2];
__asm__(".extern D_L01_001E0CA0, 8");
extern s32 D_L01_001E0CA0[2];
extern V16_48DCD8 D_L01_001D9628[];
s32 func_L01_0049F168(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0C58 == 0) {
        func_003E6FA0(D_L01_001E0C40, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798_0049F168, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C58 = 1;
    }
    if (D_L01_001E0C78 == 0) {
        func_003E6FA0(D_L01_001E0C60, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798_0049F168, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C78 = 1;
    }
    if (D_L01_001E0C98 == 0) {
        func_003E6FA0(D_L01_001E0C80, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798_0049F168, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0C98 = 1;
    }
    if (D_L01_001E0CB8 == 0) {
        func_003E6FA0(D_L01_001E0CA0, (s32)func_L01_0049F2C8, (s32)func_L01_0049F868_0049F168, (s32)func_L01_0049F798_0049F168, (s32)func_L01_0049F8A8_0049F168, (s32)func_L01_0049F8C8_0049F168);
        D_L01_001E0CB8 = 1;
    }
    v = D_L01_001D9628[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_0049F168 */

/* localdecomp:start func_L01_0049F2C8 */
extern u8 D_00143950[];
extern s32 D_L01_001E0CD0[2];
__asm__(".extern D_L01_001E0CD0_0049F2C8, 4");
extern s32 D_L01_001E0CD0_0049F2C8;
extern s32 D_L01_001E0CC0[2];
extern S_2ED730_0049F2C8 D_L01_002ED730_0049F2C8[];
extern u8 D_L01_002ECCB0[];
extern void func_L01_004A0788(void);
extern void func_L01_004A0300(void);
extern void func_L01_004A02B8(void);
extern void func_L01_0049FDF0(void);
extern void func_L01_004A04B8(void);
extern void func_L01_004A0A80(void);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_0049F8E8(void *);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_00516640(s32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003B42F8(s32);
extern s32 func_003E8710(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_L01_00518D40_0049F2C8(s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_005170B8(s32, s32);
__asm__(".extern D_L01_001D9578_0049F2C8, 4");
extern f32 D_L01_001D9578_0049F2C8;
__asm__(".extern D_L01_001D957C_0049F2C8, 4");
extern f32 D_L01_001D957C_0049F2C8;
__asm__(".extern D_L01_001D9580_0049F2C8, 4");
extern f32 D_L01_001D9580_0049F2C8;
__asm__(".extern D_L01_001D9584_0049F2C8, 4");
extern f32 D_L01_001D9584_0049F2C8;
__asm__(".extern D_L01_001D9588_0049F2C8, 4");
extern f32 D_L01_001D9588_0049F2C8;
__asm__(".extern D_L01_001D958C, 4");
extern f32 D_L01_001D958C;

void func_L01_0049F2C8(void) {
    s32 i = 0;
    f32 k1 = 0.0035000001f;
    f32 k2 = 0.006f;
    s32 n3 = 3;
    u8 t = D_00143950[0xA4];
    if (t == 2) {
        D_L01_001E0CD0[0] = t;
    } else if (t == 1) {
        D_L01_001E0CD0[0] = t;
    } else {
        D_L01_001E0CD0_0049F2C8 = 0;
    }
    D_L01_001E0CC0[i] = D_L01_001E0CD0[i];
    func_L01_004A0788();
    func_L01_004A0300();
    func_L01_004A02B8();
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x112), 0xD0006, 0xFF, 0xD0007, 0xCD5, 0.0f);
    func_L01_0049F8E8(D_L01_002ECCB0);
    func_003E8348(0x11, 0x540000);
    func_L01_00516640(0x540002, 0.0035000001f, 0.006f);
    func_003E7F20(0x54000A, 1);
    func_003E7F20(0x54000E, 1);
    func_003E7F20(0x540012, 1);
    func_003E7F20(0x540016, 1);
    func_003E7F20(0x54001A, 1);
    func_003E7F20(0x54001E, 1);
    func_003E7F20(0x540022, 1);
    func_003E7F20(0x540026, 1);
    func_003E7F20(0x54002A, 1);
    func_003E7F20(0x54002E, 1);
    func_003E7F20(0x540032, 1);
    func_003E7F20(0x540036, 1);
    func_003E8710(0x540003, func_003B42F8(0));
    func_L01_00516D60(0x540003, 0);
    func_L01_00517190(0x540003, 0);
    func_003E87B8(0x540003, 1, 8);
    func_L01_0049FDF0();
    func_L01_00518D40_0049F2C8(0x54003A);
    func_003E9270(0x54003D, 0x706EC8FF, D_L01_001D9580_0049F2C8 + D_L01_001D9588_0049F2C8, D_L01_001D9578_0049F2C8 + D_L01_001D957C_0049F2C8 * n3, 0.01953f, 0.040868f, 0.0035000001f, 0.006f);
    func_003E9270(0x54003C, 0x332299DE, ((D_L01_001D9580_0049F2C8 + D_L01_001D9588_0049F2C8) + D_L01_001D9584_0049F2C8) * 0.5f, D_L01_001D9578_0049F2C8 + D_L01_001D957C_0049F2C8 * n3, D_L01_001D9584_0049F2C8 - (D_L01_001D9580_0049F2C8 + D_L01_001D9588_0049F2C8), D_L01_001D958C, 0.0035000001f, 0.006f);
    func_003E9138(0x54003B, 0x332299DE, (D_L01_001D9580_0049F2C8 + D_L01_001D9588_0049F2C8) + k1, D_L01_001D9578_0049F2C8 + D_L01_001D957C_0049F2C8 * n3, (D_L01_001D9584_0049F2C8 - (D_L01_001D9580_0049F2C8 + D_L01_001D9588_0049F2C8)) - (k1 + k1), D_L01_001D958C - (k2 + k2), 0);
    func_L01_00516B90(0x54003B, 1, 3);
    func_L01_00518110(0x54003A, 0x54003B, 0x54003C, 0x54003D);
    func_003E8630(0x540000, 0x54003A);
    func_L01_005170B8(0x54003C, 0x331465B7);
    func_L01_005170B8(0x54003B, 0x60000000);
    t = D_00143950[0xA4];
    switch (t) {
    case 0:
        D_L01_001E0CD0[i] = 0;
        D_L01_002ED730_0049F2C8[i].a = 0;
        break;
    case 1:
        D_L01_001E0CD0[i] = 1;
        D_L01_002ED730_0049F2C8[i].a = 2;
        break;
    case 2:
        D_L01_001E0CD0[i] = 2;
        D_L01_002ED730_0049F2C8[i].a = 1;
        break;
    }
    func_L01_004A04B8();
    func_L01_004A0A80();
}
/* localdecomp:end func_L01_0049F2C8 */

/* localdecomp:start func_L01_0049F798 */
extern u8 *D_001D52FC_0049F798;
__asm__(".extern D_001D52FC_0049F798, 16");
extern u8 D_L01_001D672C_0049F798;
__asm__(".extern D_L01_001D672C_0049F798, 16");
extern void func_L01_00516D60_0049F798(s32, s32);
extern void func_L01_00517190_0049F798(s32, s32);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern void func_L01_004A0430_0049F798(s32);
extern void func_L01_004A04B8_0049F798(void);
extern void func_L01_004A0608_0049F798(void);
extern void func_L01_004A0A80_0049F798(void);
extern void func_L01_004A1050_0049F798(void);
extern s32 func_L01_0047DAB0_0049F798(void);
extern void func_L01_0047DAC8_0049F798(void);
extern void func_L01_00516090_0049F798(s32);
extern s32 func_L01_0047EBE0_0049F798(void);
extern void func_L01_00517748_0049F798(s32);

void func_L01_0049F798(s32 a0)
{
    s32 v = *(s32 *)(D_001D52FC_0049F798 + 0x1C4);

    func_L01_00516D60_0049F798(0x540003, 1);
    func_L01_00517190_0049F798(0x540003, 1);
    func_003BA4F8(func_003B9BD0(0), v);
    func_L01_004A0430_0049F798(a0);
    func_L01_004A04B8_0049F798();
    func_L01_004A0608_0049F798();
    func_L01_004A0A80_0049F798();
    func_L01_004A1050_0049F798();
    if (func_L01_0047DAB0_0049F798()) {
        func_L01_0047DAC8_0049F798();
        func_L01_00516090_0049F798(a0);
        if (D_L01_001D672C_0049F798 == 0) {
            func_L01_00517748_0049F798(func_L01_0047EBE0_0049F798());
        }
    }
}
/* localdecomp:end func_L01_0049F798 */

/* localdecomp:start func_L01_0049F868 */
extern void func_L01_00517918(s32);
extern void func_L01_004A03A8_0049F868(void);
extern void func_003A2750(s32);

void func_L01_0049F868(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_004A03A8_0049F868();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049F868 */

/* localdecomp:start func_L01_0049F8A8 */
extern void func_L01_0047E4B8_0049F8A8();

void func_L01_0049F8A8(void) {
    func_L01_0047E4B8_0049F8A8();
}
/* localdecomp:end func_L01_0049F8A8 */

/* localdecomp:start func_L01_0049F8C8 */
extern void func_L01_0047E520_0049F8C8();

void func_L01_0049F8C8(void) {
    func_L01_0047E520_0049F8C8();
}
/* localdecomp:end func_L01_0049F8C8 */
