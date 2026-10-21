#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

INCLUDE_ASM("asm/levels", func_L01_004838A0);

/* localdecomp:start func_L01_004838C8 */
extern u8 D_00142732[];
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_004838C8(void) {
    D_00142732[0] = 2;
    func_L01_00517748(func_L01_0047EBE0());
}
/* localdecomp:end func_L01_004838C8 */

/* localdecomp:start func_L01_004838F8 */
extern u8 D_00142732[];
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_004838F8(void) {
    D_00142732[0] = 3;
    func_L01_00517748(func_L01_0047EBE0());
}
/* localdecomp:end func_L01_004838F8 */

INCLUDE_ASM("asm/levels", func_L01_00483928);

INCLUDE_ASM("asm/levels", func_L01_00483DD8);

INCLUDE_ASM("asm/levels", func_L01_00483FC0);

/* localdecomp:start func_L01_00483FE8 */
extern void func_L01_0047E4B8_00483FE8();
 
void func_L01_00483FE8(void) {
    func_L01_0047E4B8_00483FE8();
}
/* localdecomp:end func_L01_00483FE8 */

/* localdecomp:start func_L01_00484008 */
extern void func_L01_0047E520_00484008();
 
void func_L01_00484008(void) {
    func_L01_0047E520_00484008();
}
/* localdecomp:end func_L01_00484008 */

/* localdecomp:start func_L01_00484028 */
extern s32 func_L01_00484028(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0718;
extern s32 D_L01_001E0700[2];
extern void func_L01_00483928();
extern void func_L01_00483FC0();
extern void func_L01_00483DD8();
extern void func_L01_00483FE8_00484028(void);
extern void func_L01_00484008_00484028();
s32 func_L01_00484028(void) {
    if (D_L01_001E0718 == 0) {
        func_003E6FA0(D_L01_001E0700, (s32)func_L01_00483928, (s32)func_L01_00483FC0, (s32)func_L01_00483DD8, (s32)func_L01_00483FE8_00484028, (s32)func_L01_00484008_00484028);
        D_L01_001E0718 = 1;
    }
    return (s32)D_L01_001E0700;
}
/* localdecomp:end func_L01_00484028 */

INCLUDE_ASM("asm/levels", func_L01_00484080);

INCLUDE_ASM("asm/levels", func_L01_004845E8);

INCLUDE_ASM("asm/levels", func_L01_00484A38);

/* localdecomp:start func_L01_00484A60 */
extern void func_L01_0047E4B8_00484A60();
 
void func_L01_00484A60(void) {
    func_L01_0047E4B8_00484A60();
}
/* localdecomp:end func_L01_00484A60 */

/* localdecomp:start func_L01_00484A80 */
extern void func_L01_0047E520_00484A80();
 
void func_L01_00484A80(void) {
    func_L01_0047E520_00484A80();
}
/* localdecomp:end func_L01_00484A80 */

/* localdecomp:start func_L01_00484AA0 */
extern s32 func_L01_00484AA0(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0750;
extern s32 D_L01_001E0738[2];
extern void func_L01_00484080();
extern void func_L01_00484A38();
extern void func_L01_004845E8();
extern void func_L01_00484A60_00484AA0(void);
extern void func_L01_00484A80_00484AA0();
s32 func_L01_00484AA0(void) {
    if (D_L01_001E0750 == 0) {
        func_003E6FA0(D_L01_001E0738, (s32)func_L01_00484080, (s32)func_L01_00484A38, (s32)func_L01_004845E8, (s32)func_L01_00484A60_00484AA0, (s32)func_L01_00484A80_00484AA0);
        D_L01_001E0750 = 1;
    }
    return (s32)D_L01_001E0738;
}
/* localdecomp:end func_L01_00484AA0 */

INCLUDE_ASM("asm/levels", func_L01_00484AF8);

INCLUDE_ASM("asm/levels", func_L01_00485A10);

/* localdecomp:start func_L01_00485A38 */
extern S_002EA318 D_L01_002EA2D8[];

int func_L01_00485A38(int a0, int a1)
{
    return D_L01_002EA2D8[a0 * 2 + a1].f0;
}
/* localdecomp:end func_L01_00485A38 */

/* localdecomp:start func_L01_00485A60 */
s32 func_L01_00485A60(s32 a0, s32 a1) {
    return a0 * 2 + a1;
}
/* localdecomp:end func_L01_00485A60 */

INCLUDE_ASM("asm/levels", func_L01_00485A70);

/* localdecomp:start func_L01_00485B18 */
extern s32 D_L01_001D8560;
extern s32 D_L01_001D855C;
extern f32 D_L01_001D8584;
extern f32 D_L01_001D8588;
extern f32 D_L01_001D858C;
extern f32 D_L01_001D8590;
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
void func_L01_00485B18(void) {
    f32 b;
    if (D_L01_001D8560 == 0) b = D_L01_001D858C; else b = D_L01_001D8590;
    func_L01_00516470(0xE000B, D_L01_001D8584 + (f32)D_L01_001D855C * D_L01_001D8588, b);
}
/* localdecomp:end func_L01_00485B18 */

INCLUDE_ASM("asm/levels", func_L01_00485B68);

INCLUDE_ASM("asm/levels", func_L01_00485D00);

/* localdecomp:start func_L01_004861C0 */
extern s32 D_L01_001D855C;
extern s32 D_L01_001D8560;
extern f32 D_L01_001D857C;
extern f32 D_L01_001D8580;
extern u8 D_00142CA0[];
extern int func_L01_00485A38(int, int);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004784C0(s32, s32, f32, f32);

void func_L01_004861C0(void) {
    s32 i;

    i = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
    if (D_00142CA0[i] != 0) {
        func_L01_00516AA0(0xE0009, 1, 1);
        func_L01_004784C0(i, 0xE0009, D_L01_001D857C, D_L01_001D8580);
    } else {
        func_L01_00516AA0(0xE0009, 1, 0);
    }
}
/* localdecomp:end func_L01_004861C0 */

INCLUDE_ASM("asm/levels", func_L01_00486248);

/* localdecomp:start func_L01_00486340 */
extern S_002EA318 D_L01_002EA2D8[];

extern u8 D_00142CA0[];
extern s32 func_L01_00485A10(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L01_00486340(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        s32 h = func_L01_00485A10(i, 0xE002D, 0xE0038);
        if (D_00142CA0[((S_482AE0 *)&D_L01_002EA2D8)[i].idx]) {
            func_L01_00516AA0(h, 1, 1);
        } else {
            func_L01_00516AA0(h, 1, 0);
        }
    }
}
/* localdecomp:end func_L01_00486340 */

INCLUDE_ASM("asm/levels", func_L01_004863D8);

/* localdecomp:start func_L01_004868D8 */

extern s32 D_L01_001D8554;
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);

void func_L01_004868D8(void) {
    Obj *o;
    func_003BB468(D_L01_001D8554);
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(19);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003A2750(1);
}
/* localdecomp:end func_L01_004868D8 */

/* localdecomp:start func_L01_00486940 */
extern void func_L01_0047E4B8_00486940();
 
void func_L01_00486940(void) {
    func_L01_0047E4B8_00486940();
}
/* localdecomp:end func_L01_00486940 */

/* localdecomp:start func_L01_00486960 */
extern void func_L01_0047E520_00486960();
 
void func_L01_00486960(void) {
    func_L01_0047E520_00486960();
}
/* localdecomp:end func_L01_00486960 */

/* localdecomp:start func_L01_00486980 */
extern s32 func_L01_00486980(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E07C8;
extern s32 D_L01_001E07B0[2];
extern void func_L01_00484AF8();
extern void func_L01_004868D8();
extern void func_L01_004863D8();
extern void func_L01_00486940_00486980(void);
extern void func_L01_00486960_00486980();
s32 func_L01_00486980(void) {
    if (D_L01_001E07C8 == 0) {
        func_003E6FA0(D_L01_001E07B0, (s32)func_L01_00484AF8, (s32)func_L01_004868D8, (s32)func_L01_004863D8, (s32)func_L01_00486940_00486980, (s32)func_L01_00486960_00486980);
        D_L01_001E07C8 = 1;
    }
    return (s32)D_L01_001E07B0;
}
/* localdecomp:end func_L01_00486980 */

INCLUDE_ASM("asm/levels", func_L01_004869D8);

INCLUDE_ASM("asm/levels", func_L01_00486A38);

INCLUDE_ASM("asm/levels", func_L01_00486B58);

/* localdecomp:start func_L01_004874F8 */
s32 func_L01_004874F8(s32 a) {
    return a + 0xF001B;
}
/* localdecomp:end func_L01_004874F8 */

/* localdecomp:start func_L01_00487508 */
extern s32 D_L01_001D86F0[2];
s32 func_L01_00487508(s32 a, s32 b) {
    return D_L01_001D86F0[a + b * 5];
}
/* localdecomp:end func_L01_00487508 */

/* localdecomp:start func_L01_00487528 */
s32 func_L01_00487528(s32 a, s32 b) {
    return a + b * 5;
}
/* localdecomp:end func_L01_00487528 */

/* localdecomp:start func_L01_00487538 */

extern s32 D_L01_001D86F0[2];
extern u8 D_001425C0[];
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_004874F8(s32);
extern s32 func_L01_00517190(s32, s32);

void func_L01_00487538(void)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        func_L01_00517190(func_L01_004874F8(i), (&D_L01_002C5600[D_001425C0[D_L01_001D86F0[i]]])->x38);
    }
}
/* localdecomp:end func_L01_00487538 */

/* localdecomp:start func_L01_004875C8 */
extern s32 D_L01_001D86F0[2];
s32 func_L01_004875C8(s32 k) {
    s32 i;
    s32 *p = &(*(s32 *)&D_L01_001D86F0);
    for (i = 0; i < 9; i++) {
        if (p[i] == k) return i;
    }
    return -1;
}
/* localdecomp:end func_L01_004875C8 */

/* localdecomp:start func_L01_004875F8 */
extern f32 D_L01_001D86C8;
extern f32 D_L01_001D86CC;
extern f32 D_L01_001D86D0;
extern f32 D_L01_001D86D4;
extern s32 D_L01_001D86E8;
extern s32 D_L01_001D86EC;
extern void func_L01_00516470(s32, f32, f32);

void func_L01_004875F8(void) {
    f32 off = 0.0f;
    if (D_L01_001D86EC > 0) {
        off = D_L01_001D86D0 * 0.5f;
    }
    func_L01_00516470(0xF0002, D_L01_001D86C8 + off + (f32)D_L01_001D86E8 * D_L01_001D86D0, D_L01_001D86CC + (f32)D_L01_001D86EC * D_L01_001D86D4);
}
/* localdecomp:end func_L01_004875F8 */

INCLUDE_ASM("asm/levels", func_L01_00487670);

/* localdecomp:start func_L01_00487840 */
extern s32 D_L01_001D86F0[2];
extern u8 D_00142CA0[];
extern s32 func_L01_004874F8(s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L01_00487840(void)
{
    s32 i;
    s32 *p = D_L01_001D86F0;

    for (i = 0; i < 9; i++) {
        s32 r = func_L01_004874F8(i);
        if (D_00142CA0[*p++]) {
            func_L01_00516AA0(r, 1, 1);
        } else {
            func_L01_00516AA0(r, 1, 0);
        }
    }
}
/* localdecomp:end func_L01_00487840 */

/* localdecomp:start func_L01_004878D0 */
extern s16 D_001A7464[];
extern s32 func_L01_004875C8(s32 a0);
extern s32 func_L01_004874F8(s32 a0);
extern void func_L01_005170B8_004878D0(s32 a0, u32 a1);
void func_L01_004878D0(void) {
    if (D_001A7464[0] != 0) {
        func_L01_005170B8_004878D0(func_L01_004874F8(func_L01_004875C8(3)), 0x80808080);
        func_L01_005170B8_004878D0(func_L01_004874F8(func_L01_004875C8(2)), 0x80808080);
    }
}
/* localdecomp:end func_L01_004878D0 */

INCLUDE_ASM("asm/levels", func_L01_00487930);

/* localdecomp:start func_L01_00487DF8 */
extern Obj *func_003B42F8(s32);
extern s32 D_L01_001D86D8;
extern s32 D_L01_001D86E0;
extern void func_003BB468(s32 a0);
extern void func_003A2750(s32 a0);
extern void func_L01_00517918(s32 a0);
void func_L01_00487DF8(void) {
    Obj_484598 *o;
    func_003BB468(D_L01_001D86D8);
    func_003BB468(D_L01_001D86E0);
    o = ((Obj_484598 * (*)(s32 a0))func_003B42F8)(0);
    o->vt->fn(o);
    o = ((Obj_484598 * (*)(s32 a0))func_003B42F8)(1);
    o->vt->fn(o);
    func_003A2750(1);
    func_L01_00517918(16);
    func_L01_00517918(19);
}
/* localdecomp:end func_L01_00487DF8 */

/* localdecomp:start func_L01_00487E70 */
extern void func_L01_0047E4B8_00487E70();
 
void func_L01_00487E70(void) {
    func_L01_0047E4B8_00487E70();
}
/* localdecomp:end func_L01_00487E70 */

/* localdecomp:start func_L01_00487E90 */
extern void func_L01_0047E520_00487E90();
 
void func_L01_00487E90(void) {
    func_L01_0047E520_00487E90();
}
/* localdecomp:end func_L01_00487E90 */

/* localdecomp:start func_L01_00487EB0 */
extern s32 func_L01_00487EB0(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0848;
extern s32 D_L01_001E0830[2];
extern void func_L01_00486B58();
extern void func_L01_00487DF8();
extern void func_L01_00487930();
extern void func_L01_00487E70_00487EB0(void);
extern void func_L01_00487E90_00487EB0();
s32 func_L01_00487EB0(void) {
    if (D_L01_001E0848 == 0) {
        func_003E6FA0(D_L01_001E0830, (s32)func_L01_00486B58, (s32)func_L01_00487DF8, (s32)func_L01_00487930, (s32)func_L01_00487E70_00487EB0, (s32)func_L01_00487E90_00487EB0);
        D_L01_001E0848 = 1;
    }
    return (s32)D_L01_001E0830;
}
/* localdecomp:end func_L01_00487EB0 */

INCLUDE_ASM("asm/levels", func_L01_00487F08);

INCLUDE_ASM("asm/levels", func_L01_00487F50);

INCLUDE_ASM("asm/levels", func_L01_00487F78);

INCLUDE_ASM("asm/levels", func_L01_00487FC8);

/* localdecomp:start func_L01_00488108 */
extern s32 func_L01_00517190(s32, s32);
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 D_L01_001D8790;
extern s32 D_L01_001D8844;
extern s32 D_L01_001D87A0[2];
extern s32 D_L01_001D87C0[2];
extern u8 D_001425C0[];
extern void func_L01_00516AA0(s32, s32, s32);
void func_L01_00488108(void) {
    s32 x;
    switch (D_L01_001D8790) {
    case 0:
        x = D_L01_001D87A0[D_L01_001D8844];
        if (x != 0) {
            func_L01_00516AA0(0x190083, 1, 1);
            ((void (*)(s32, s32))func_L01_00517190)(0x190083, ((E_4848A8 *)(D_001425C0[x] * 240 + (s32)((E_4848A8 *)&D_L01_002C5600)))->h38);
        } else {
            func_L01_00516AA0(0x190083, 1, 0);
        }
        break;
    case 1:
        x = D_L01_001D87C0[D_L01_001D8844];
        if (x != 0) {
            func_L01_00516AA0(0x190083, 1, 1);
            ((void (*)(s32, s32))func_L01_00517190)(0x190083, ((E_4848A8 *)(D_001425C0[x] * 240 + (s32)((E_4848A8 *)&D_L01_002C5600)))->h38);
        } else {
            func_L01_00516AA0(0x190083, 1, 0);
        }
        break;
    }
}
/* localdecomp:end func_L01_00488108 */

/* localdecomp:start func_L01_004881F0 */
u8 *func_L01_004881F0(u8 *a0, s32 a1, s32 a2) {
    if (a2 < 4 && a1 < 5) {
        return a0 + a2 * 5 + a1;
    }
    return 0;
}
/* localdecomp:end func_L01_004881F0 */

/* localdecomp:start func_L01_00488220 */
u8 *func_L01_00488220(u8 *a0, s32 a1, s32 a2) {
    if (a2 < 2 && a1 < 4) {
        return a0 + a1 + a2 * 4;
    }
    return 0;
}
/* localdecomp:end func_L01_00488220 */

INCLUDE_ASM("asm/levels", func_L01_00488248);

INCLUDE_ASM("asm/levels", func_L01_00489060);

/* localdecomp:start func_L01_00489160 */
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_00487F78(s32, s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern char D_L01_001D87E0[8];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern char D_L01_002EAAA8[];
extern char D_L01_001D89C8[];
extern char D_L01_001D89D0[];
extern char D_L01_001D89E0[];
extern char D_L01_001D89F0[];

void func_L01_00489160(void) {
    s32 i = func_L01_00487F78(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C);

    if (D_L01_001D8848 == 1) {
        func_L01_00516D60(0x190007, 0);
    } else {
        func_L01_00516D60(0x190007, 1);
    }
    if (D_00142CA0[i]) {
        func_0011B2E8(D_L01_002EAAA8, D_L01_001D89C8, func_00381FF0((((E_4858E8 *)&D_L01_002C5600) + D_001425C0[i])->x4));
        func_0011B2E8(D_L01_001D87E0, D_L01_001D89D0, func_00381FF0(376), D_001427F0[i], ((E_4858E8 *)&D_L01_002C5600)[D_001425C0[i]].x8A);
    } else {
        func_0011B2E8(D_L01_002EAAA8, D_L01_001D89E0);
        func_0011B2E8(D_L01_001D87E0, D_L01_001D89F0);
    }
}
/* localdecomp:end func_L01_00489160 */

INCLUDE_ASM("asm/levels", func_L01_004892C0);

INCLUDE_ASM("asm/levels", func_L01_00489410);

/* localdecomp:start func_L01_004894F8 */
extern s32 D_L01_001D8838;
extern s32 D_L01_001D8848;
extern s32 D_L01_001D883C;
extern s32 D_L01_001D8790;
extern s32 D_L01_001D87A0[2];
extern s32 D_L01_001D87C0[2];
extern s32 D_L01_001D8844;
extern u8 D_00142CA0[];
extern s32 func_L01_00487F78(s32, s32, s32);
void func_L01_004894F8(void) {
    s32 r;
    s32 i;
    r = func_L01_00487F78(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C);
    switch (D_L01_001D8790) {
    case 0:
        if (r == 0 || D_00142CA0[r] == 0) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (D_L01_001D87A0[i] == r) {
                D_L01_001D87A0[i] = 0;
            }
        }
        D_L01_001D87A0[D_L01_001D8844] = r;
        D_L01_001D8844++;
        break;
    case 1:
        if (r == 0 || D_00142CA0[r] == 0) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (D_L01_001D87C0[i] == r) {
                D_L01_001D87C0[i] = 0;
            }
        }
        D_L01_001D87C0[D_L01_001D8844] = r;
        D_L01_001D8844++;
        break;
    }
}
/* localdecomp:end func_L01_004894F8 */

INCLUDE_ASM("asm/levels", func_L01_004895E8);

/* localdecomp:start func_L01_00489758 */
extern s32 func_L01_00517190(s32, s32);
extern u8 *func_L01_004881F0(u8 *a0, s32 a1, s32 a2);
extern Entry_00483CD8 D_L01_002C5600[];

extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern int func_L01_00487F78(int, int, int);
extern void func_L01_00516AA0(int, int, int);

void func_L01_00489758(void)
{
    int i;
    int j;
    int a;
    int b;
    S_002C5640 *p;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            a = func_L01_00487F78(0, j, i);
            b = ((int (*)(int, int, int))func_L01_004881F0)(0x190039, j, i);
            if (a != 0) {
                func_L01_00516AA0(b, 1, D_00142CA0[a]);
                p = &((S_002C5640 *)&D_L01_002C5600)[D_001425C0[a]];
                ((void (*)(int, int))func_L01_00517190)(b, p->unk38);
            } else {
                func_L01_00516AA0(b, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_00489758 */

/* localdecomp:start func_L01_00489870 */
extern s32 func_L01_00517190(s32, s32);
extern u8 *func_L01_00488220(u8 *a0, s32 a1, s32 a2);
extern Entry_00483CD8 D_L01_002C5600[];

extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern s32 func_L01_00487F78(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516D60(s32, s32);

void func_L01_00489870(void) {
    s32 i;
    s32 j;
    s32 x;
    s32 y;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 4; i++) {
            x = func_L01_00487F78(1, i, j);
            y = ((s32 (*)(s32, s32, s32))func_L01_00488220)(0x190069, i, j);
            if (x != 0) {
                if (x == 20) {
                    ((void (*)(s32, s32))func_L01_00517190)(y, 0xEAC9);
                } else {
                    ((void (*)(s32, s32))func_L01_00517190)(y, ((Entry_00485FF8 *)(D_001425C0[x] * 240 + (s32)((Entry_00485FF8 *)&D_L01_002C5600)))->f56);
                }
                func_L01_00516D60(y, D_00142CA0[x] != 0);
            } else {
                func_L01_00516AA0(y, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_00489870 */

INCLUDE_ASM("asm/levels", func_L01_004899B0);

INCLUDE_ASM("asm/levels", func_L01_00489B30);

/* localdecomp:start func_L01_00489C68 */
extern s32 D_L01_001D8848;
extern void func_L01_004899B0(void);
extern void func_L01_00489B30(void);

void func_L01_00489C68(void) {
    switch (D_L01_001D8848) {
    case 0:
        func_L01_004899B0();
        break;
    case 1:
        func_L01_00489B30();
        break;
    }
}
/* localdecomp:end func_L01_00489C68 */

/* localdecomp:start func_L01_00489CB0 */
extern void func_L01_005170B8_00489CB0(s32 a0, u32 a1);
extern u8 *func_L01_00488220(u8 *a0, s32 a1, s32 a2);
extern u8 *func_L01_004881F0(u8 *a0, s32 a1, s32 a2);
void func_L01_00489CB0(s32 a0, s32 a1, s32 a2, s32 a3) {
    switch (a0) {
    case 0:
        ((void (*)(void *, s32))func_L01_005170B8_00489CB0)(((void * (*)(s32))func_L01_004881F0)(0x190039), a3);
        break;
    case 1:
        ((void (*)(void *, s32))func_L01_005170B8_00489CB0)(((void * (*)(s32))func_L01_00488220)(0x190069), a3);
        break;
    }
}
/* localdecomp:end func_L01_00489CB0 */

INCLUDE_ASM("asm/levels", func_L01_00489D20);

INCLUDE_ASM("asm/levels", func_L01_00489F00);

/* localdecomp:start func_L01_00489F90 */
extern void func_L01_0047E4B8_00489F90();
 
void func_L01_00489F90(void) {
    func_L01_0047E4B8_00489F90();
}
/* localdecomp:end func_L01_00489F90 */

/* localdecomp:start func_L01_00489FB0 */
extern void func_L01_0047E520_00489FB0();
 
void func_L01_00489FB0(void) {
    func_L01_0047E520_00489FB0();
}
/* localdecomp:end func_L01_00489FB0 */

/* localdecomp:start func_L01_00489FD0 */
extern s32 func_L01_00489FD0(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0868;
extern s32 D_L01_001E0850[2];
extern void func_L01_00488248();
extern void func_L01_00489F00();
extern void func_L01_00489D20();
extern void func_L01_00489F90_00489FD0(void);
extern void func_L01_00489FB0_00489FD0();
s32 func_L01_00489FD0(void) {
    if (D_L01_001E0868 == 0) {
        func_003E6FA0(D_L01_001E0850, (s32)func_L01_00488248, (s32)func_L01_00489F00, (s32)func_L01_00489D20, (s32)func_L01_00489F90_00489FD0, (s32)func_L01_00489FB0_00489FD0);
        D_L01_001E0868 = 1;
    }
    return (s32)D_L01_001E0850;
}
/* localdecomp:end func_L01_00489FD0 */

/* localdecomp:start func_L01_0048A028 */
extern s32 func_L01_0048A028(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0888;
extern s32 D_L01_001E0870[2];
extern void func_L01_0048A0A0();
extern void func_L01_0048A9F0();
extern void func_L01_0048A8F8();
extern void func_L01_0048AA30_0048A028(void);
extern void func_L01_0048AA50_0048A028();
s32 func_L01_0048A028(void) {
    if (D_L01_001E0888 == 0) {
        func_003E6FA0(D_L01_001E0870, (s32)func_L01_0048A0A0, (s32)func_L01_0048A9F0, (s32)func_L01_0048A8F8, (s32)func_L01_0048AA30_0048A028, (s32)func_L01_0048AA50_0048A028);
        D_L01_001E0888 = 1;
    }
    return (s32)D_L01_001E0870;
}
/* localdecomp:end func_L01_0048A028 */

/* localdecomp:start func_L01_0048A080 */
extern s32 D_L01_001D8A68;

s32 func_L01_0048A080(s32 a0) {
    s32 ret = 0;
    if (D_L01_001D8A68 == 0) {
        D_L01_001D8A68 = a0;
        ret = 1;
    }
    return ret;
}
/* localdecomp:end func_L01_0048A080 */

INCLUDE_ASM("asm/levels", func_L01_0048A0A0);

INCLUDE_ASM("asm/levels", func_L01_0048A8F8);

/* localdecomp:start func_L01_0048A9F0 */
extern void func_L01_00517918_0048A9F0(s32);
extern void func_L01_0048B338(void);
extern void func_003A2750(s32);

void func_L01_0048A9F0(void) {
    func_L01_00517918_0048A9F0(16);
    func_L01_00517918_0048A9F0(17);
    func_L01_00517918_0048A9F0(20);
    func_L01_0048B338();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0048A9F0 */

/* localdecomp:start func_L01_0048AA30 */
extern void func_L01_0047E4B8_0048AA30();
 
void func_L01_0048AA30(void) {
    func_L01_0047E4B8_0048AA30();
}
/* localdecomp:end func_L01_0048AA30 */

/* localdecomp:start func_L01_0048AA50 */
extern void func_L01_0047E520_0048AA50();
 
void func_L01_0048AA50(void) {
    func_L01_0047E520_0048AA50();
}
/* localdecomp:end func_L01_0048AA50 */

INCLUDE_ASM("asm/levels", func_L01_0048AA70);

INCLUDE_ASM("asm/levels", func_L01_0048AAE8);

/* localdecomp:start func_L01_0048AF28 */

extern Ent4876B0 D_L01_00233DD8[];
extern s32 D_L01_001D8A2C;
extern u8 *func_L01_00438D40(s32);

void func_L01_0048AF28(void) {
    u8 *p = func_L01_00438D40(-1);
    s32 id = *p - 1;
    s32 i;
    if (p == 0) return;
    for (i = 0; i < 60; i++) {
        if (D_L01_00233DD8[i].id != id) continue;
        if (!D_L01_00233DD8[i].flag) continue;
        D_L01_001D8A2C = i;
        break;
    }
}
/* localdecomp:end func_L01_0048AF28 */

/* localdecomp:start func_L01_0048AFB8 */
extern int func_0011B2E8(char *, char *, ...);
extern u8 *func_L01_00438D40(s32);
extern Ent4876B0 D_L01_00233DD8[];

extern s32 D_L01_001D8A34;
extern char D_L01_00233E2D[];
extern char D_L01_001D8BA8[];
extern s32 func_L01_00438DD8(s32);
extern u8 *func_L01_00437B38(s32);
extern s32 func_00381FF0(s32);

void func_L01_0048AFB8(s32 i) {
    s32 obj;
    s32 v;
    u8 *m;

    if (D_L01_001D8A34 < 0) {
        return;
    }
    obj = ((Slot_00487740 *)&D_L01_00233DD8)[i].obj;
    v = ((s32 (*)(s32))func_L01_00438D40)(obj);
    if (v == 0) {
        v = func_L01_00438DD8(obj);
    }
    if (v != 0) {
        m = func_L01_00437B38(v);
    } else {
        m = 0;
    }
    if (m != 0) {
        v = func_00381FF0(*(s16 *)(m + 8));
        ((void (*)(char *, char *, s32))func_0011B2E8)(D_L01_00233E2D + i * 176, D_L01_001D8BA8, v);
        return;
    }
    ((Slot_00487740 *)&D_L01_00233DD8)[i].name[0] = 0;
}
/* localdecomp:end func_L01_0048AFB8 */

INCLUDE_ASM("asm/levels", func_L01_0048B080);

INCLUDE_ASM("asm/levels", func_L01_0048B270);

/* localdecomp:start func_L01_0048B338 */
extern Obj *func_003B42F8(s32);

extern s32 D_L01_001D8A40;
extern s32 D_L01_001D8A44;
extern s32 D_L01_001D8A48;
extern s32 D_L01_001D8A50;
extern s32 D_L01_001D8A6C;

extern void func_003BB468(s32 a);
extern void func_003A4F28(s32 a);
extern void func_003A2750(s32 a);

void func_L01_0048B338(void) {
    VObj_487AC0 *o;
    func_003BB468(D_L01_001D8A40);
    func_003BB468(D_L01_001D8A44);
    func_003BB468(D_L01_001D8A48);
    func_003BB468(D_L01_001D8A50);
    if (D_L01_001D8A6C != -1) {
        func_003A4F28(D_L01_001D8A6C);
        D_L01_001D8A6C = -1;
    }
    o = ((VObj_487AC0 * (*)(s32 i))func_003B42F8)(0);
    o->vtbl->fn(o);
    o = ((VObj_487AC0 * (*)(s32 i))func_003B42F8)(1);
    o->vtbl->fn(o);
    o = ((VObj_487AC0 * (*)(s32 i))func_003B42F8)(2);
    o->vtbl->fn(o);
    func_003A2750(1);
}
/* localdecomp:end func_L01_0048B338 */

INCLUDE_ASM("asm/levels", func_L01_0048B3F0);

INCLUDE_ASM("asm/levels", func_L01_0048B588);
