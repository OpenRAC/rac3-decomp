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

/* declared by functions of L01_00492C80.c, which this file was cut from */
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_00494018(void);

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
