#include "common.h"

typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 w0;
    u8 b4;
    u8 pad5[3];
    void (*fn)(void);
    s32 wC;
} S_48F880e;
typedef struct {
    u8 pad0[0x1C4];
    s32 w1C4;
} S_48F880;
typedef struct O_490778 O_490778;
typedef struct {
    u8 pad0[12];
    void (*fn)(O_490778 *);
} V_490778;
struct O_490778 {
    u8 pad0[4];
    V_490778 *vt;
};

/* localdecomp:start func_L01_00492C80 */
extern void func_L01_00517918(s32);
extern void func_L01_00493038_00492C80(void);
extern void func_003A2750(s32);

void func_L01_00492C80(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_00493038_00492C80();
    func_003A2750(1);
}
/* localdecomp:end func_L01_00492C80 */

/* localdecomp:start func_L01_00492CC0 */
extern void func_L01_0047E4B8_00492CC0();

void func_L01_00492CC0(void) {
    func_L01_0047E4B8_00492CC0();
}
/* localdecomp:end func_L01_00492CC0 */

/* localdecomp:start func_L01_00492CE0 */
extern void func_L01_0047E520_00492CE0();

void func_L01_00492CE0(void) {
    func_L01_0047E520_00492CE0();
}
/* localdecomp:end func_L01_00492CE0 */

INCLUDE_ASM("asm/levels", func_L01_00492D00);

/* localdecomp:start func_L01_00492FE0 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F08 - 0x4958];
    u8 f6F08[1];
} S_L01_160C40;

extern s32 func_L01_0047EF58(s32 a);
extern s32 func_L01_00494160(s32 a);
extern void func_L01_00494390(s32 a, s32 b, s32 c, s32 d, s32 e);
extern S_L01_160C40 D_00160C40_00492FE0[];
extern s32 D_L01_001D8E70;
extern s32 D_L01_001D8E74;

void func_L01_00492FE0(void) {
    s32 r;

    D_L01_001D8E70 = func_L01_0047EF58(0);
    D_L01_001D8E74 = func_L01_0047EF58(0);
    r = func_L01_00494160(0);
    func_L01_00494390(r, D_L01_001D8E70, D_L01_001D8E74, D_00160C40_00492FE0->f4954, (s32)&D_00160C40_00492FE0->f6F08);
}
/* localdecomp:end func_L01_00492FE0 */

/* localdecomp:start func_L01_00493038 */
extern void *D_L01_001D8E70_00493038;
extern void *D_L01_001D8E74_00493038;
extern void *func_L01_00494160_00493038(s32);
extern void func_L01_0047F018(s32);
void func_L01_00493038(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_L01_00494160_00493038)(0);
    o->vt->fn(o);
    func_L01_0047F018((*(s32 *)&D_L01_001D8E70_00493038));
    func_L01_0047F018((*(s32 *)&D_L01_001D8E74_00493038));
}
/* localdecomp:end func_L01_00493038 */

/* localdecomp:start func_L01_00493078 */


extern s32 D_L01_001D8E68;
extern S_48F880e D_L01_002EB498[];
extern S_48F880 *D_001D52FC;
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_004A1128(void);
extern void func_L01_00517748(s32 a0);
extern void func_L01_00516090_00493078(s32 a0);

void func_L01_00493078(s32 a0, s32 flags) {
    S_48F880e *e;

    if (flags & 0x40) {
        e = &D_L01_002EB498[D_L01_001D8E68];
        if (e->b4 != 0 && D_L01_002EB498[D_L01_001D8E68].fn != 0) {
            e->fn();
        } else {
            func_003A5348(5, 0, 0);
        }
    }
    if (flags & 0x910) {
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00493078(a0);
    } else if (D_001D52FC->w1C4 & 1) {
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090_00493078(a0);
    }
}
/* localdecomp:end func_L01_00493078 */

/* localdecomp:start func_L01_00493150 */
extern s32 D_L01_001D8E6C;
extern s32 D_L01_001D8E7C;
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00493150(void) {
    s32 r;

    r = func_003B9C58(func_003B9BD0(0));
    D_L01_001D8E68 = r;
    if (r >= 0) {
        if (D_L01_001D8E6C != r) {
            D_L01_001D8E7C = 30;
        }
        if (D_L01_001D8E7C != 0) {
            if (--D_L01_001D8E7C == 0) {
                func_L01_00516D60(0x1C0003, 1);
                func_L01_00517190(0x1C0003, D_L01_002EB498[D_L01_001D8E68].wC);
            }
        }
        D_L01_001D8E6C = D_L01_001D8E68;
    }
}
/* localdecomp:end func_L01_00493150 */

INCLUDE_ASM("asm/levels", func_L01_004931E0);

/* localdecomp:start func_L01_00493558 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00480AB8(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_00493558(s32);
void func_L01_00493558(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_00480AB8());
    func_L01_00516090_00493558(func_L01_00492870());
}
/* localdecomp:end func_L01_00493558 */

/* localdecomp:start func_L01_004935A0 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00494018(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_004935A0(s32);
void func_L01_004935A0(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_00494018());
    func_L01_00516090_004935A0(func_L01_00492870());
}
/* localdecomp:end func_L01_004935A0 */

/* localdecomp:start func_L01_004935E8 */
extern void func_L01_0047DAD0(s32 a0);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32 a0);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_004935E8(s32 a0);
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L01_004935E8(void) {
    func_L01_0047DAD0(5);
    func_L01_00517748(func_L01_0047EBE0());
    func_L01_00516090_004935E8(func_L01_00492870());
    func_003A5348(4, 0, 0);
}
/* localdecomp:end func_L01_004935E8 */

/* localdecomp:start func_L01_00493638 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_0049B550(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00492870(void);
extern void func_L01_00516090_00493638(s32);
void func_L01_00493638(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_0049B550());
    func_L01_00516090_00493638(func_L01_00492870());
}
/* localdecomp:end func_L01_00493638 */

INCLUDE_ASM("asm/levels", func_L01_00493680);

/* localdecomp:start func_L01_00493BC8 */
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; s32 w10; } E_00493BC8;
typedef struct { s32 w0; s32 w4; } T_00493BC8;
extern S_48F880 *D_001D52FC_00493BC8[] __attribute__((section(".sdata")));
extern char D_L01_001E0AC0_00493BC8[] __attribute__((section(".sdata")));
extern char D_L01_001D8F00_00493BC8[];
extern u8 D_L01_001D672C_00493BC8[] __attribute__((section(".sdata")));
extern E_00493BC8 D_L01_002EB638_00493BC8[];
extern T_00493BC8 D_L01_002E9DC0_00493BC8[];
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_003BA4F8(s32, s32);
extern s32 func_L01_00492870_00493BC8(void);
extern void func_L01_00517748_00493BC8(s32);
extern void func_L01_00516090_00493BC8(s32);
extern void func_003A5348(s32, s32, s32);
extern char *func_00381FF0(s32);
extern s32 func_L01_00494088_00493BC8(void);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00516D60_00493BC8(s32, s32);
extern s32 func_L01_00516FD8_00493BC8(s32, char *);
extern s32 func_L01_00517190_00493BC8(s32, s32);
extern s32 func_L01_00494070_00493BC8(s32 i);
extern char *func_003B9E30(s32, s32, s32);
extern void func_L01_00498948_00493BC8(s32, s32, s32);
extern s32 func_L01_0047DAB0_00493BC8(void);
extern void func_L01_0047DAC8_00493BC8(void);
extern s32 func_L01_0047EBE0_00493BC8(void);

void func_L01_00493BC8(s32 a0) {
    s32 idx;
    s32 v;
    s32 t;
    u32 i;

    func_003BA4F8(func_003B9BD0(0), D_001D52FC_00493BC8[0]->w1C4);
    if (D_001D52FC_00493BC8[0]->w1C4 & 0x10) {
        func_L01_00517748_00493BC8(func_L01_00492870_00493BC8());
        func_L01_00516090_00493BC8(a0);
        func_003A5348(4, 0, 0);
    }
    func_0011B2E8(D_L01_001E0AC0_00493BC8, func_00381FF0(0x253), func_L01_00494088_00493BC8(), 0x1E);
    idx = func_003B9C58(func_003B9BD0(0));
    v = D_L01_002EB638_00493BC8[idx].w0;
    if (v < 30) {
        s32 r;
        s32 k = v;
        if (v == 1 || v == 2 || v == 4 || v == 8 || v == 27 || v == 28 || v == 9 || v == 29 ||
            v == 5 || v == 13 || v == 23 || v == 10 || v == 18 || v == 14) {
            r = k > 0 ? D_L01_002E9DC0_00493BC8[k % 60].w4 : D_L01_002E9DC0_00493BC8[1].w4;
        } else {
            r = v > 0 ? D_L01_002E9DC0_00493BC8[v % 60].w0 : D_L01_002E9DC0_00493BC8[1].w0;
        }
        t = r;
    } else {
        t = v > 0 ? D_L01_002E9DC0_00493BC8[v % 60].w4 : D_L01_002E9DC0_00493BC8[1].w4;
    }
    func_L01_00516D60_00493BC8(0x530005, 0);
    if (t >= 0) {
        func_L01_00516D60_00493BC8(0x530005, 1);
        func_L01_00516FD8_00493BC8(0x530005, func_00381FF0(t));
    }
    if (func_L01_00494070_00493BC8(D_L01_002EB638_00493BC8[idx].wC)) {
        func_L01_00516FD8_00493BC8(0x530007, func_00381FF0(D_L01_002EB638_00493BC8[idx].w8));
        func_L01_00517190_00493BC8(0x530003, D_L01_002EB638_00493BC8[idx].w10);
    } else {
        func_L01_00516FD8_00493BC8(0x530007, func_00381FF0(0x16CE));
        func_L01_00517190_00493BC8(0x530003, 0x1F);
    }
    for (i = 0; i < 30; i++) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8F00_00493BC8,
                      func_00381FF0(D_L01_002EB638_00493BC8[i].w4));
        if (func_L01_00494070_00493BC8(D_L01_002EB638_00493BC8[i].wC)) {
            func_L01_00498948_00493BC8(func_003B9BD0(0), i, 0);
        } else {
            func_L01_00498948_00493BC8(func_003B9BD0(0), i, 1);
        }
    }
    if (func_L01_0047DAB0_00493BC8()) {
        func_L01_0047DAC8_00493BC8();
        func_L01_00516090_00493BC8(a0);
        if (D_L01_001D672C_00493BC8[0] == 0) {
            func_L01_00517748_00493BC8(func_L01_0047EBE0_00493BC8());
        }
    }
}
/* localdecomp:end func_L01_00493BC8 */

/* localdecomp:start func_L01_00493F70 */
extern void *func_003B42F8(s32);

extern void func_L01_00517918(s32);
extern s32 func_003B9BD0(s32);
extern void func_003B9E90(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
extern s32 D_L01_001D8E90;

void func_L01_00493F70(void) {
    O_490778 *o;
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_003B9E90(func_003B9BD0(0));
    o = ((O_490778 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D8E90);
}
/* localdecomp:end func_L01_00493F70 */

/* localdecomp:start func_L01_00493FD8 */
extern void func_L01_0047E4B8_00493FD8();

void func_L01_00493FD8(void) {
    func_L01_0047E4B8_00493FD8();
}
/* localdecomp:end func_L01_00493FD8 */

/* localdecomp:start func_L01_00493FF8 */
extern void func_L01_0047E520_00493FF8();

void func_L01_00493FF8(void) {
    func_L01_0047E520_00493FF8();
}
/* localdecomp:end func_L01_00493FF8 */

/* localdecomp:start func_L01_00494018 */
extern s32 func_L01_00494018(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0AB8;
extern s32 D_L01_001E0AA0[2];
extern void func_L01_00493680();
extern void func_L01_00493F70();
extern void func_L01_00493BC8();
extern void func_L01_00493FD8_00494018(void);
extern void func_L01_00493FF8_00494018();
s32 func_L01_00494018(void) {
    if (D_L01_001E0AB8 == 0) {
        func_003E6FA0(D_L01_001E0AA0, (s32)func_L01_00493680, (s32)func_L01_00493F70, (s32)func_L01_00493BC8, (s32)func_L01_00493FD8_00494018, (s32)func_L01_00493FF8_00494018);
        D_L01_001E0AB8 = 1;
    }
    return (s32)D_L01_001E0AA0;
}
/* localdecomp:end func_L01_00494018 */

/* localdecomp:start func_L01_00494070 */
extern u8 D_001D54B0[];

s32 func_L01_00494070(s32 i) {
    return D_001D54B0[i] != 0;
}
/* localdecomp:end func_L01_00494070 */
