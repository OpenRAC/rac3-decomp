#include "common.h"

/* localdecomp:start func_L39_006B6A80 */
typedef struct S_6B6A80_C S_6B6A80_C;
typedef struct S_6B6A80_B {
    char _p0[0x24];
    void (*f24)(S_6B6A80_C *arg0);
} S_6B6A80_B;
struct S_6B6A80_C {
    char _p0[0x60];
    S_6B6A80_B *f60;
};
typedef struct S_6B6A80_A {
    char _p0[0x110];
    S_6B6A80_C *f110;
} S_6B6A80_A;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6A80(S_6B6A80_A *arg0) {
    S_6B6A80_C *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006B6A80 */

/* localdecomp:start func_L39_006B6AA8 */
typedef struct T3_6B6AA8 T3_6B6AA8;
typedef struct T2_6B6AA8 {
    char _p0[0xB8];
    void (*fB8)(T3_6B6AA8 *arg0);
} T2_6B6AA8;
struct T3_6B6AA8 {
    char _p0[0x60];
    T2_6B6AA8 *f60;
};
typedef struct T1_6B6AA8 {
    char _p0[0x114];
    T3_6B6AA8 *f114;
} T1_6B6AA8;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006B6AA8(T1_6B6AA8 *arg0) {
    T3_6B6AA8 *o = arg0->f114;
    o->f60->fB8(o);
}
/* localdecomp:end func_L39_006B6AA8 */

/* localdecomp:start func_L39_006B6AD0 */
s32 func_L39_006B6AD0(s32 arg0) {
    return arg0 + 0x2A8;
}
/* localdecomp:end func_L39_006B6AD0 */

/* localdecomp:start func_L39_006B6AD8 */
typedef struct V_006B6AD8 {
    char _p0[0x1C];
    s32 (*f1C)(void *, s32, s32);
} V_006B6AD8;
typedef struct O_006B6AD8 {
    char _p0[0x60];
    V_006B6AD8 *f60;
} O_006B6AD8;
typedef struct S_006B6AD8 {
    char _p0[0x118];
    O_006B6AD8 *f118;
    O_006B6AD8 *f11C;
    O_006B6AD8 *f120;
    O_006B6AD8 *f124;
    char _p1[0x1F4];
    s32 f31C;
} S_006B6AD8;

void func_L39_006B6AD8(S_006B6AD8 *arg0, s32 arg1) {
    arg0->f31C = ((arg1 >> 4) & 1) + (((arg1 >> 3) & 1) + (((arg1 >> 2) & 1) + (arg1 & 1)));
    arg0->f11C->f60->f1C(arg0->f11C, (arg1 & 1) ? 3 : 0, 0);
    arg0->f118->f60->f1C(arg0->f118, (arg1 & 4) ? 3 : 0, 0);
    arg0->f120->f60->f1C(arg0->f120, (arg1 & 8) ? 3 : 0, 0);
    arg0->f124->f60->f1C(arg0->f124, (arg1 & 0x10) ? 3 : 0, 0);
}
/* localdecomp:end func_L39_006B6AD8 */

/* localdecomp:start func_L39_006B6BC0 */
s32 func_L39_006B6BC0(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x318));
}
/* localdecomp:end func_L39_006B6BC0 */

LINKER_REMNANT("asm/levels", func_L39_006B6BC8);

/* localdecomp:start func_L39_006B6BD0 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6BD0(void) {
    func_0038CC88(D_001FC6B0, D_L39_0037C848, 0xF80);
}
/* localdecomp:end func_L39_006B6BD0 */

/* localdecomp:start func_L39_006B6C00 */
void func_0038CC88(void *, void *, s32);
extern u8 D_001FC6B0[];
extern u8 D_L39_0037C848[];

void func_L39_006B6C00(void) {
    func_0038CC88(D_L39_0037C848, D_001FC6B0, 0xF80);
}
/* localdecomp:end func_L39_006B6C00 */

/* localdecomp:start func_L39_006B6C30 */
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern u8 D_001DDA58_sda;

void func_L39_006B6C30(void) {
    D_00241440 = 7;
    D_001DDA58_sda = 1;
}
/* localdecomp:end func_L39_006B6C30 */

/* localdecomp:start func_L39_006B6C48 */
extern u8 D_00249170 __attribute__((section(".data")));
void *func_0011D534(void *, s32, s32);
typedef struct { u8 a; u8 b; s32 c; } E_006B6C48;
typedef struct { u8 pad0[4]; E_006B6C48 e[3]; u8 f1C; u8 f1D; u8 pad1E[0x3D-0x1E]; u8 f3D; u8 pad3E[0x50-0x3E]; u8 f50; u8 pad51[0x171-0x51]; u8 f171; s16 f172; } S_006B6C48;
void func_L39_006B6C48(void *arg0) {
    S_006B6C48 *p = arg0;
    func_0011D534(p, 0, 0x1F0);
    p->f1D = D_00249170;
    p->f3D = D_00249170;
    p->f1C = 0;
    p->f50 = 0;
    p->e[0].a = 1; p->e[0].b = 1; p->e[0].c = 0x32;
    p->e[1].a = 1; p->e[1].b = 1; p->e[1].c = 0x32;
    p->e[2].a = 1; p->e[2].b = 1;
    p->f172 = 0x300;
    p->f171 = 1;
    p->e[2].c = 0x32;
}
/* localdecomp:end func_L39_006B6C48 */

INCLUDE_ASM("asm/levels", func_L39_006B6CC8);

LINKER_REMNANT("asm/levels", func_L39_006B7180);

/* localdecomp:start func_L39_006B7188 */
extern u8 D_L39_0047E680[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006B7188(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047E680;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006B7188 */

LINKER_REMNANT("asm/levels", func_L39_006B71B0);

INCLUDE_ASM("asm/levels", func_L39_006B71B8);

/* localdecomp:start func_L39_006B72B0 */
extern s32 func_L39_0067F168();
extern void func_003C2880(s32);
extern void func_L39_0068ADC8(void *);
extern s32 D_L39_0037C7F0[];
extern s32 D_L39_0024D258;
__asm__(".extern D_L39_0024D258, 16");
extern s32 D_001DDA50_sda;
extern s32 D_001E1B48_sda;

void func_L39_006B72B0(void *arg0) {
    s32 i;
    func_L39_0067F168();
    for (i = 0; i < 10; i++) {
        if (D_L39_0037C7F0[i] != 0) {
            func_003C2880(D_L39_0037C7F0[i]);
        }
        D_L39_0037C7F0[i] = 0;
    }
    if (D_L39_0024D258 != 0) {
        func_003C2880(D_L39_0024D258);
    }
    D_001DDA50_sda = -1;
    D_001E1B48_sda = 0;
    func_L39_0068ADC8(arg0);
}
/* localdecomp:end func_L39_006B72B0 */

/* localdecomp:start func_L39_006B7340 */
typedef struct V_006B7340 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7340;
typedef struct S_006B7340 {
    char _p0[0x60];
    V_006B7340 *f60;
    char _p1[0x259];
    u8 f2BD;
} S_006B7340;

extern void func_L01_00517918(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);
extern void func_L39_006B6C48(void *);
extern void func_L39_006B8AC8(void *, s32);
extern s32 D_001A43E8 __attribute__((section(".data")));
extern s32 D_L39_002403F8;
__asm__(".extern D_L39_002403F8, 16");
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern s32 D_001DDA44_sda;
extern s32 D_001DDA64_sda;
extern u8 D_L39_0037C848[];

void func_L39_006B7340(S_006B7340 *arg0) {
    s32 v;
    arg0->f2BD = 0;
    v = D_001A43E8;
    if (v == 2) {
        if (D_L39_002403F8 == 1) {
            func_L01_00517918(0xA);
            func_L39_005BF798(0x12, 1, 3, 0, 0);
            D_00241440 = 7;
            arg0->f60->fF0(arg0);
            func_L39_00689A70();
        }
        D_001DDA64_sda = v;
    } else {
        func_L39_006B6C48(D_L39_0037C848 + D_001DDA44_sda * 0x1F0);
        func_L39_006B8AC8(arg0, 0);
        D_001DDA64_sda = 3;
    }
}
/* localdecomp:end func_L39_006B7340 */

/* localdecomp:start func_L39_006B7410 */
typedef struct V_006B7410 {
    char _p0[0xF0];
    void (*fF0)(void *);
} V_006B7410;
typedef struct S_006B7410 {
    char _p0[0x60];
    V_006B7410 *f60;
} S_006B7410;

extern void func_L01_00517918(s32);
extern void func_L39_005BF798(s32, s32, s32, s32, s32);
extern void func_L39_00689A70(void);
extern s32 D_001A43E8 __attribute__((section(".data")));
extern s32 D_00241440;
__asm__(".extern D_00241440, 16");
extern s32 D_001DDA64_sda;

void func_L39_006B7410(S_006B7410 *arg0) {
    if (D_001A43E8 == 2) {
        func_L01_00517918(0xA);
        func_L39_005BF798(0x12, 1, 3, 0, 0);
        D_00241440 = 7;
        arg0->f60->fF0(arg0);
        func_L39_00689A70();
    }
    D_001DDA64_sda = 2;
}
/* localdecomp:end func_L39_006B7410 */

/* localdecomp:start func_L39_006B7490 */
extern s32 D_1A43E0[];
extern s32 D_001DDA44_sda;
extern s32 D_001DDA48_sda;
extern s32 D_001DDA64_sda;
extern u8 D_L39_0037C848[];
void func_L39_006B6C00(void);
void func_L39_006B6C48(void *);
void func_L39_006B8AC8(void *, s32);

void func_L39_006B7490(void *a0) {
    D_001DDA64_sda = 3;
    if (D_1A43E0[2] == 2) {
        if (D_1A43E0[0x5B] == 0) {
            func_L39_006B6C00();
            if (D_001DDA48_sda != 0) {
                func_L39_006B6C48(D_L39_0037C848 + D_001DDA44_sda * 0x1F0);
                D_001DDA48_sda = 0;
            }
            func_L39_006B8AC8(a0, 0);
            *(u8 *)((u8 *)a0 + 0x2BC) = 1;
        }
    }
}
/* localdecomp:end func_L39_006B7490 */

/* localdecomp:start func_L39_006B7520 */
typedef struct P_006B7520 {
    char _p0[0x8];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} P_006B7520;
typedef struct V_006B7520 {
    char _p0[0x30];
    void (*f30)(void *, f32 *, f32 *);
} V_006B7520;
typedef struct O_006B7520 {
    char _p0[0x60];
    V_006B7520 *f60;
} O_006B7520;
typedef struct S_006B7520 {
    char _p0[0x110];
    O_006B7520 *f110[0x60];
    s32 f290;
} S_006B7520;

extern P_006B7520 D_L39_004B1618;
extern P_006B7520 D_L39_004B1650;
extern P_006B7520 D_L39_004B16D0;
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

s32 func_L39_006B7520(void *arg) {
    S_006B7520 *arg0 = arg;
    f32 x = 0.0f;
    f32 y = 0.0f;
    f32 a = 0.0f, b = 0.0f, f = 0.0f, e = 0.0f, c = 0.0f, d = 0.0f;
    P_006B7520 *p;
    O_006B7520 *o;

    switch (arg0->f290) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        p = &D_L39_004B1618;
        a = p->f8;
        b = p->fC;
        c = p->f10;
        d = p->f14;
        e = p->f18;
        f = p->f1C;
        break;
    case 8:
        p = &D_L39_004B16D0;
        a = p->f8;
        b = p->fC;
        c = p->f10;
        d = p->f14;
        e = p->f18;
        f = p->f1C;
        break;
    case 7:
        p = &D_L39_004B1650;
        a = p->f8;
        b = p->fC;
        c = p->f10;
        d = p->f14;
        e = p->f18;
        f = p->f1C;
        break;
    }
    o = arg0->f110[arg0->f290];
    o->f60->f30(o, &x, &y);
    func_L39_00689F00(arg0, 3, 3, 3, x + c, y + d, a, b, e, f);
    return 0;
}
/* localdecomp:end func_L39_006B7520 */

LINKER_REMNANT("asm/levels", func_L39_006B7650);

/* localdecomp:start func_L39_006B7658 */
typedef struct V_006B7658 {
    char _p0[0x14];
    void (*f14)(void *, s32);
    char _p1[0x4C];
    s32 (*f64)(void *);
    char _p2[0x5C];
    u8 *(*fC4)(void *);
} V_006B7658;
typedef struct O_006B7658 {
    char _p0[0x60];
    V_006B7658 *f60;
} O_006B7658;
typedef struct S_006B7658 {
    char _p0[0x110];
    O_006B7658 *f110;
    char _p1[0x4];
    O_006B7658 *f118;
    O_006B7658 *f11C;
} S_006B7658;

extern s32 D_1A43E0[];
extern s32 D_001DDA64_sda;
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern u8 D_L39_00249170[];
s32 func_L39_00688340(s32, s32, s32);
s32 func_L39_006872E8(s32 *, s32, s32, s32, s32, f32);
extern s32 func_00381FF0(s32);
s32 func_00120884(u8 *);
void func_L39_0068B2F8(void *, s32, s32);
s32 func_L39_006B7520(void *);
extern void func_L01_00480B10(s32);

s32 func_L39_006B7658(S_006B7658 *arg0) {
    s32 ret = 0;
    u8 *s1;
    u8 *s3;
    s32 r;
    s32 msg;

    if (D_1A43E0[2] != 2) {
        s32 *d;
        func_L39_00688340(5, 0, 0);
        d = D_L39_00247914;
        func_L39_006872E8(d, func_00381FF0(0x19E), 0, 4, 0, 0.0f);
    } else {
        s1 = arg0->f110->f60->fC4(arg0->f110);
        s3 = arg0->f11C->f60->fC4(arg0->f11C);
        r = arg0->f118->f60->f64(arg0->f118);
        if (func_00120884(s1) == 0) {
            func_L39_0068B2F8(arg0, 0, 0);
            func_L39_006B7520(arg0);
            msg = func_00381FF0(0x1B9D);
            func_L39_006872E8(D_L39_00247914, (s32)D_L39_00249170, msg, 4, 0, 0.0f);
            arg0->f110->f60->f14(arg0->f110, 7);
        } else if (r != 0 && func_00120884(s3) == 0) {
            func_L39_0068B2F8(arg0, 3, 0);
            func_L39_006B7520(arg0);
            msg = func_00381FF0(0x1B9E);
            func_L39_006872E8(D_L39_00247914, (s32)D_L39_00249170, msg, 4, 0, 0.0f);
            arg0->f11C->f60->f14(arg0->f11C, 7);
        } else {
            ret = 1;
            func_L39_00688340(4, 0, 0);
            D_001DDA64_sda = 6;
            func_L01_00480B10(10);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006B7658 */

LINKER_REMNANT("asm/levels", func_L39_006B7830);

/* localdecomp:start func_L39_006B7838 */
typedef struct V_006B7838 {
    char _p0[0x14];
    s32 (*f14)(void *, s32);
    char _p1[0x4C];
    s32 (*f64)(void *);
} V_006B7838;
typedef struct O_006B7838 {
    char _p0[0x60];
    V_006B7838 *f60;
} O_006B7838;
typedef struct S_006B7838 {
    char _p0[0x118];
    O_006B7838 *f118;
    O_006B7838 *f11C;
    char _p1[0x170];
    s32 f290;
} S_006B7838;

extern void func_L39_0069E1A8(s32, void *);
s32 func_L39_00688340(s32, s32, s32);
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern u8 D_L39_0037C848[];
extern s32 D_001DDA44_sda;

s32 func_L39_006B7838(S_006B7838 *arg0) {
    switch (arg0->f290) {
    case 1:
        func_L39_0069E1A8(D_L39_00247914[0x10C / 4], D_L39_0037C848 + D_001DDA44_sda * 0x1F0);
        func_L39_00688340(4, 0, 0);
        D_L39_00247914[0x284 / 4] = 0x2A;
        break;
    case 2:
        if (arg0->f118->f60->f64(arg0->f118) != 0) {
            arg0->f11C->f60->f14(arg0->f11C, 7);
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L39_006B7838 */

/* localdecomp:start func_L39_006B78F8 */
__asm__(".extern D_L39_00247914, 16");
extern s32 *D_L39_00247914;
extern s32 D_001DDA64_sda;
s32 func_L39_00688340(s32, s32, s32);
extern s32 func_00381FF0(s32);
s32 func_L39_006872E8(s32 *, s32, s32, s32, s32, f32);

s32 func_L39_006B78F8(void) {
    func_L39_00688340(0x17, 0, 0);
    if (func_L39_006872E8(D_L39_00247914, 0, func_00381FF0(0x1CAA), 3, 0, 0.0f) == 1) {
        D_001DDA64_sda = 7;
    }
    return 1;
}
/* localdecomp:end func_L39_006B78F8 */

/* localdecomp:start func_L39_006B7958 */
typedef struct S_006B7958_V S_006B7958_V;
typedef struct S_006B7958_O { u8 pad[0x60]; S_006B7958_V *vt; } S_006B7958_O;
struct S_006B7958_V {
    u8 p0[0x14]; s32 (*f14)(S_006B7958_O *, s32);
    u8 p18[0x4C]; s32 (*f64)(S_006B7958_O *);
    u8 p68[0x20]; void (*f88)(S_006B7958_O *, s32);
    s32 (*f8C)(S_006B7958_O *);
};
typedef struct S_006B7958 {
    u8 p0[0x118];
    S_006B7958_O *o118;
    S_006B7958_O *o11C;
    u8 p120[8];
    S_006B7958_O *o128;
    u8 p12C[0xC];
    S_006B7958_O *o138;
    u8 p13C[0x154];
    s32 f290;
    u8 p294[0x20];
    s32 f2B4;
    s32 f2B8;
} S_006B7958;

extern s32 D_1A43E0[];
extern s32 D_001DDA44_sda;
extern s32 D_001DDA48_sda;
extern s32 D_001DDA64_sda;
extern u8 *D_001D5A54_sda;
extern u8 D_L39_0037C848[];
extern void func_L39_006B8D88(void *);
extern void func_L39_006B84E8(void *);
extern s32 func_L39_0068AEF8(void *, s32);
s32 func_L39_00688340(s32, s32, s32);
extern s32 func_L39_006B7838(S_006B7838 *);
extern s32 func_L39_006B7658(S_006B7658 *);
extern s32 func_L39_006B78F8(void);
extern s32 func_L39_006B7520(void *);

s32 func_L39_006B7958(S_006B7958 *a0, s32 *a1) {
    S_006B7958_O *o;
    s32 r;
    s32 s;
    s32 v;
    s32 t;

    if ((D_001DDA48_sda != 0 && D_1A43E0[2] == 2) || (D_1A43E0[2] == 2 && D_1A43E0[4] != 0)) {
        D_001DDA48_sda = 0;
        D_001DDA64_sda = 7;
        return 1;
    }
    if (D_001DDA44_sda != -1 && (*(s32 *)(D_001D5A54_sda + 0x1A0) & 1)) {
        func_L39_006B8D88(a0);
        func_L39_006B84E8(a0);
        return 1;
    }
    if (a0->f2B4 != -2) a0->f2B4 = 0;
    if (a0->f2B8 != -2) a0->f2B8 = 0;
    if (D_001DDA44_sda != -1) {
        if (D_L39_0037C848[D_001DDA44_sda * 0x1F0 + 0x50] & 0x80) a0->f2B4 = -2;
        if (D_L39_0037C848[D_001DDA44_sda * 0x1F0 + 0x50] & 0x40) a0->f2B8 = -2;
    }
    if (a0->f290 == 6) {
        o = a0->o128;
        v = o->vt->f8C(o);
        s = *a1;
        if (s == 3 || s == 4 || s == 7) {
            if (s == 3) {
                v--;
                if (v < 0) {
                    v = (a0->f2B4 == -2) ? 0x15 : 0x14;
                }
                if (v == 0x12 && a0->f2B8 != -2) v = 0x11;
            } else if (s == 4 || s == 7) {
                v++;
                if (v == 0x12 && a0->f2B8 != -2) v = 0x13;
                if (v == 0x15 && a0->f2B4 != -2) v = 0x16;
                if (v >= 0x16) v = 0;
            }
            o = a0->o128;
            o->vt->f88(o, v);
            func_L39_006B84E8(a0);
            return 1;
        }
    }
    func_L39_006B84E8(a0);
    r = func_L39_0068AEF8(a0, *a1);
    t = a0->f290;
    if (t == 7) {
        o = a0->o138;
        r = o->vt->f14(o, *a1);
        if (*a1 == t || *a1 == 3 || *a1 == 4) {
            func_L39_00688340(3, 0, 0);
        }
    }
    switch (*a1) {
    case 7:
        if (((s32 (*)(void *))func_L39_006B7838)(a0)) return 1;
        break;
    case 6:
        if (((s32 (*)(void *))func_L39_006B7658)(a0)) return 1;
        r = 1;
        break;
    case 5:
        if (((s32 (*)(void *))func_L39_006B78F8)(a0)) return 1;
        break;
    case 3:
    case 4:
        if (a0->f290 != 2) return 1;
        o = a0->o118;
        if (o->vt->f64(o)) {
            o = a0->o11C;
            o->vt->f14(o, 7);
        }
        break;
    }
    if (func_L39_006B7520(a0)) return 1;
    return r != 0;
}
/* localdecomp:end func_L39_006B7958 */
