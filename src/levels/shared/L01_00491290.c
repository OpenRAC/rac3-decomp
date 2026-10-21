#include "common.h"

typedef struct {
    s32 pad[3];
    s32 val;
} S_48DA70;
typedef struct { u8 b[16]; } V16_48DCD8;
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6EC0 - 0x4958];
    u8 fX[1];
} S_func_0048E5D8;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} E_002EB338;
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

INCLUDE_ASM("asm/levels", func_L01_00491290);

/* localdecomp:start func_L01_004912D8 */
extern u8 D_00143950[];
extern void func_003A5348(s32, s32, s32);
void func_L01_004912D8(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p = D_00143950;
        p[6] = p[6] == 0;
        func_003A5348(4, 0, 0);
    }
}
/* localdecomp:end func_L01_004912D8 */

/* localdecomp:start func_L01_00491318 */
extern u8 D_00143950[];
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L01_00491318(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_00143950);
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_48DA70 *p = &(*(S_48DA70 *)&D_00143950);
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_003A5348(3, 0, 0);
}
/* localdecomp:end func_L01_00491318 */

INCLUDE_ASM("asm/levels", func_L01_00491390);

/* localdecomp:start func_L01_00491408 */
extern u8 D_00143950[];
extern void func_003A5348(s32, s32, s32);
void func_L01_00491408(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_003A5348(4, 0, 0);
        p = D_00143950;
        p[5] = p[5] == 0;
    }
}
/* localdecomp:end func_L01_00491408 */

/* localdecomp:start func_L01_00491448 */
extern u8 D_00143950[];
extern void func_003A5348(s32, s32, s32);
void func_L01_00491448(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_003A5348(4, 0, 0);
        p = D_00143950;
        p[4] = p[4] == 0;
    }
}
/* localdecomp:end func_L01_00491448 */

/* localdecomp:start func_L01_00491488 */
extern u8 D_00143950[];
extern void func_003A5348(s32, s32, s32);
extern void func_003873C0(void);
void func_L01_00491488(s32 a0) {
    if (a0 & 0xA040) {
        u8 *p;
        func_003A5348(3, 0, 0);
        p = D_00143950;
        p[173] = p[173] == 0;
        func_003873C0();
    }
}
/* localdecomp:end func_L01_00491488 */

/* localdecomp:start func_L01_004914D0 */
extern void func_L01_00491630(void);
extern void func_L01_00491A30_004914D0(void);
extern void func_L01_00491938(void);
extern void func_L01_00491AB0_004914D0(void);
extern void func_L01_00491AD0_004914D0(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0A18;
extern s32 D_L01_001E0A38;
extern s32 D_L01_001E0A58;
extern s32 D_L01_001E0A78;
extern s32 D_L01_001E0A00[2];
extern s32 D_L01_001E0A20[2];
extern s32 D_L01_001E0A40[2];
extern s32 D_L01_001E0A60[2];
extern V16_48DCD8 D_L01_001D8E28[];
s32 func_L01_004914D0(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0A18 == 0) {
        func_003E6FA0(D_L01_001E0A00, (s32)func_L01_00491630, (s32)func_L01_00491A30_004914D0, (s32)func_L01_00491938, (s32)func_L01_00491AB0_004914D0, (s32)func_L01_00491AD0_004914D0);
        D_L01_001E0A18 = 1;
    }
    if (D_L01_001E0A38 == 0) {
        func_003E6FA0(D_L01_001E0A20, (s32)func_L01_00491630, (s32)func_L01_00491A30_004914D0, (s32)func_L01_00491938, (s32)func_L01_00491AB0_004914D0, (s32)func_L01_00491AD0_004914D0);
        D_L01_001E0A38 = 1;
    }
    if (D_L01_001E0A58 == 0) {
        func_003E6FA0(D_L01_001E0A40, (s32)func_L01_00491630, (s32)func_L01_00491A30_004914D0, (s32)func_L01_00491938, (s32)func_L01_00491AB0_004914D0, (s32)func_L01_00491AD0_004914D0);
        D_L01_001E0A58 = 1;
    }
    if (D_L01_001E0A78 == 0) {
        func_003E6FA0(D_L01_001E0A60, (s32)func_L01_00491630, (s32)func_L01_00491A30_004914D0, (s32)func_L01_00491938, (s32)func_L01_00491AB0_004914D0, (s32)func_L01_00491AD0_004914D0);
        D_L01_001E0A78 = 1;
    }
    v = D_L01_001D8E28[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_004914D0 */

INCLUDE_ASM("asm/levels", func_L01_00491630);

INCLUDE_ASM("asm/levels", func_L01_00491938);

/* localdecomp:start func_L01_00491A30 */
extern s32 D_L01_001D8DE8[2];
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern void func_L01_00517918_00491A30(s32);
extern void func_L01_00491E28(void);
extern void func_003A2750(s32);
extern void func_003B9890(void);

void func_L01_00491A30(void) {
    s32 i;

    i = func_L01_00517688();
    D_L01_001D8DE8[i] = func_003B9C58(func_003B9BD0(func_L01_00517688()));
    func_L01_00517918_00491A30(16);
    func_L01_00517918_00491A30(17);
    func_L01_00517918_00491A30(20);
    func_L01_00491E28();
    func_003A2750(1);
    func_003B9890();
}
/* localdecomp:end func_L01_00491A30 */

/* localdecomp:start func_L01_00491AB0 */
extern void func_L01_0047E4B8_00491AB0();
 
void func_L01_00491AB0(void) {
    func_L01_0047E4B8_00491AB0();
}
/* localdecomp:end func_L01_00491AB0 */

/* localdecomp:start func_L01_00491AD0 */
extern void func_L01_0047E520_00491AD0();
 
void func_L01_00491AD0(void) {
    func_L01_0047E520_00491AD0();
}
/* localdecomp:end func_L01_00491AD0 */

INCLUDE_ASM("asm/levels", func_L01_00491AF0);

/* localdecomp:start func_L01_00491DD0 */
extern S_func_0048E5D8 D_00160C40[];
extern void *D_L01_001D8E18;
extern void *D_L01_001D8E1C;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_00491DD0(void) {
    D_L01_001D8E18 = func_003BB3A8(0);
    D_L01_001D8E1C = func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), (s32)D_L01_001D8E18, (s32)D_L01_001D8E1C, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_L01_00491DD0 */

/* localdecomp:start func_L01_00491E28 */
extern void *D_L01_001D8E1C;
extern void *D_L01_001D8E18;
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);
void func_L01_00491E28(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D8E18));
    func_003BB468((*(s32 *)&D_L01_001D8E1C));
}
/* localdecomp:end func_L01_00491E28 */

INCLUDE_ASM("asm/levels", func_L01_00491E68);

/* localdecomp:start func_L01_00492028 */

extern s32 D_L01_001D8DE8[2];
extern s32 D_L01_001D8DF8[2];
extern s32 D_L01_001D8E38;
extern E_002EB338 D_L01_002EB2E8[];
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00492028(void)
{
    s32 i;

    D_L01_001D8DE8[func_L01_00517688()] = func_003B9C58(func_003B9BD0(0));
    i = func_L01_00517688();
    if (D_L01_001D8DF8[i] != D_L01_001D8DE8[func_L01_00517688()]) {
        D_L01_001D8E38 = 30;
    }
    if (D_L01_001D8E38 != 0) {
        if (--D_L01_001D8E38 == 0) {
            func_L01_00517190(0x1C0003, D_L01_002EB2E8[D_L01_001D8DE8[func_L01_00517688()]].unkC);
            func_L01_00516D60(0x1C0003, 1);
        }
    }
    D_L01_001D8DF8[func_L01_00517688()] = D_L01_001D8DE8[func_L01_00517688()];
}
/* localdecomp:end func_L01_00492028 */

INCLUDE_ASM("asm/levels", func_L01_00492140);

/* localdecomp:start func_L01_00492458 */
extern s32 func_003B9BD0(s32);
extern char *func_003B9E30(s32, s32, s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_L01_001D8E10;
extern s32 D_L01_001D8E14;
extern s32 D_L01_001D8E08;
extern s32 D_L01_001D8E0C;
extern char D_L01_001D8E50[];
extern char D_L01_001D8E58[];
extern u8 D_00143A06[];
extern u8 D_00143954[];
extern u8 D_00143955[];
extern u8 D_00143956[];

void func_L01_00492458(void) {
    if (D_L01_001D8E10 >= 0) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, D_L01_001D8E10), D_L01_001D8E50, func_00381FF0(1287), D_00143A06[0] ? func_00381FF0(373) : func_00381FF0(374));
    }
    if (D_L01_001D8E14 >= 0) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, D_L01_001D8E14), D_L01_001D8E58, func_00381FF0(322), func_00381FF0(397), D_00143954[0] ? func_00381FF0(373) : func_00381FF0(374));
    }
    if (D_L01_001D8E08 >= 0) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, D_L01_001D8E08), D_L01_001D8E58, func_00381FF0(322), func_00381FF0(398), D_00143955[0] ? func_00381FF0(373) : func_00381FF0(374));
    }
    if (D_L01_001D8E0C >= 0) {
        func_0011B2E8(func_003B9E30(func_003B9BD0(0), 0, D_L01_001D8E0C), D_L01_001D8E50, func_00381FF0(328), D_00143956[0] ? func_00381FF0(373) : func_00381FF0(374));
    }
}
/* localdecomp:end func_L01_00492458 */

/* localdecomp:start func_L01_00492688 */
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00480B10(s32);
extern s32 func_L01_00482588(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00517688(void);
extern s32 func_L01_004914D0(s32);
extern void func_L01_00516090_00492688(s32);

void func_L01_00492688(void) {
    func_003A5348(4, 0, 0);
    func_L01_00480B10(0);
    func_L01_00517748(func_L01_00482588());
    func_L01_00516090_00492688(func_L01_004914D0(func_L01_00517688()));
}
/* localdecomp:end func_L01_00492688 */

/* localdecomp:start func_L01_004926E0 */
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00480B10(s32);
extern s32 func_L01_00482588(void);
extern void func_L01_00517748(s32);
extern s32 func_L01_00517688(void);
extern s32 func_L01_004914D0(s32);
extern void func_L01_00516090_004926E0(s32);

void func_L01_004926E0(void) {
    func_003A5348(4, 0, 0);
    func_L01_00480B10(1);
    func_L01_00517748(func_L01_00482588());
    func_L01_00516090_004926E0(func_L01_004914D0(func_L01_00517688()));
}
/* localdecomp:end func_L01_004926E0 */

/* localdecomp:start func_L01_00492738 */
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
extern s32 func_L01_0049F168(s32 a0);
extern void func_L01_00517748(s32 a0);
extern s32 func_L01_00517688(void);
extern s32 func_L01_004914D0(s32 a0);
extern void func_L01_00516090_00492738(s32 a0);
void func_L01_00492738(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_0049F168(0));
    func_L01_00516090_00492738(func_L01_004914D0(func_L01_00517688()));
}
/* localdecomp:end func_L01_00492738 */

/* localdecomp:start func_L01_00492788 */
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_004910C0_00492788(s32);
extern void func_L01_00517748(s32);
extern s32 func_L01_00517688(void);
extern s32 func_L01_004914D0_00492788(s32);
extern void func_L01_00516090_00492788(s32);

void func_L01_00492788(void) {
    func_003A5348(4, 0, 0);
    func_L01_00517748(func_L01_004910C0_00492788(func_L01_00517688()));
    func_L01_00516090_00492788(func_L01_004914D0_00492788(func_L01_00517688()));
}
/* localdecomp:end func_L01_00492788 */

INCLUDE_ASM("asm/levels", func_L01_004927E0);

/* localdecomp:start func_L01_00492870 */
extern s32 func_L01_00492870(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0A98;
extern s32 D_L01_001E0A80[2];
extern void func_L01_004928C8();
extern void func_L01_00492C80_00492870();
extern void func_L01_00492B50();
extern void func_L01_00492CC0_00492870(void);
extern void func_L01_00492CE0_00492870();
s32 func_L01_00492870(void) {
    if (D_L01_001E0A98 == 0) {
        func_003E6FA0(D_L01_001E0A80, (s32)func_L01_004928C8, (s32)func_L01_00492C80_00492870, (s32)func_L01_00492B50, (s32)func_L01_00492CC0_00492870, (s32)func_L01_00492CE0_00492870);
        D_L01_001E0A98 = 1;
    }
    return (s32)D_L01_001E0A80;
}
/* localdecomp:end func_L01_00492870 */

INCLUDE_ASM("asm/levels", func_L01_004928C8);

INCLUDE_ASM("asm/levels", func_L01_00492B50);

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

INCLUDE_ASM("asm/levels", func_L01_00492FE0);

INCLUDE_ASM("asm/levels", func_L01_00493038);

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

INCLUDE_ASM("asm/levels", func_L01_00493150);

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

INCLUDE_ASM("asm/levels", func_L01_00493BC8);

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

INCLUDE_ASM("asm/levels", func_L01_00494088);
