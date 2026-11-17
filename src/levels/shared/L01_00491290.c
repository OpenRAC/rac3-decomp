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

/* localdecomp:start func_L01_00491390 */
typedef struct {
    s32 pad[4];
    s32 val;
} S_491390;
extern u8 D_00143950[];
extern void func_003A5348(s32 a0, s32 a1, s32 a2);
void func_L01_00491390(s32 buttons) {
    s32 v;
    if (buttons & 0x8000) {
        S_491390 *p = &(*(S_491390 *)&D_00143950);
        v = p->val - 30;
        p->val = (v < 0) ? 0 : v;
    } else if (buttons & 0x2000) {
        S_491390 *p = &(*(S_491390 *)&D_00143950);
        v = p->val + 30;
        p->val = (v > 1024) ? 1024 : v;
    }
    func_003A5348(3, 0, 0);
}
/* localdecomp:end func_L01_00491390 */

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
extern void func_L01_00491938(s32);
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
