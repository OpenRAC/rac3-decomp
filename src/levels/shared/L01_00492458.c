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

/* declared by functions of L01_00491A30.c, which this file was cut from */
extern s32 func_L01_00517688(void);
extern s32 func_003B9BD0(s32);
extern void func_003A5348(s32, s32, s32);
extern s32 func_L01_004914D0(s32);
extern void func_L01_00517748(s32);

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

/* localdecomp:start func_L01_004927E0 */
extern s32 D_L01_001D8E20;
extern char D_L01_002EB1E8[];
extern s32 func_003B9700(s32, s32, s32, s32, s32);
extern void func_003B96D8(s32, s32);

void func_L01_004927E0(void) {
    s32 b;
    s32 a;

    D_L01_001D8E20 = 1;
    func_0011B2E8(D_L01_002EB1E8, (char *)func_00381FF0(0x17C));
    b = func_00381FF0(0x1926);
    a = func_00381FF0(0x8DF);
    func_003B9700(0, b, a, (s32)D_L01_002EB1E8, 0);
    func_003B96D8(0x80, 0x10);
    func_003A5348(4, 0, 0);
}
/* localdecomp:end func_L01_004927E0 */

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
