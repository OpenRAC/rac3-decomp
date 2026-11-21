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

/* declared by functions of L01_004838A0.c, which this file was cut from */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 D_001425C0[];
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_00517190(s32, s32);
extern u8 D_00142CA0[];
extern void func_L01_00516AA0(s32, s32, s32);
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32 a0);
extern void func_003A2750(s32 a0);
extern s32 D_L01_001D8790;
extern s32 D_L01_001D8844;
extern s32 D_L01_001D87A0[2];
extern s32 D_L01_001D87C0[2];
extern s32 func_L01_00487F78(s32, s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;

/* localdecomp:start func_L01_00489410 */
extern u8 *func_L01_004881F0_00489410(u8 *a0, s32 a1, s32 a2);
extern u8 D_00142CA0[];
extern f32 D_L01_001D88C8_00489410;
extern f32 D_L01_001D88CC_00489410;
extern int func_L01_00487F78_00489410(int, int, int);
extern void func_L01_00516AA0_00489410(int, int, int);
extern void func_L01_004784C0_00489410(s32, s32, f32, f32);

void func_L01_00489410(void) {
    int i;
    int j;
    int a;
    int b;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            b = ((int (*)(int, int, int))func_L01_004881F0_00489410)(0x19004D, j, i);
            a = func_L01_00487F78_00489410(0, j, i);
            if (D_00142CA0[a] != 0) {
                func_L01_00516AA0_00489410(b, 1, 1);
                func_L01_004784C0_00489410(a, b, D_L01_001D88C8_00489410, D_L01_001D88CC_00489410);
            } else {
                func_L01_00516AA0_00489410(b, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_00489410 */

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

/* localdecomp:start func_L01_004895E8 */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001D8844_004895E8;
__asm__(".extern D_L01_001D8844_004895E8, 4");
extern s32 D_L01_001D8790_004895E8;
__asm__(".extern D_L01_001D8790_004895E8, 4");
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_004894F8_004895E8(void);
extern s32 func_L01_00487EB0_004895E8(void);
extern s32 func_L01_0048D8D8_004895E8(void);
extern s32 func_L01_00489FD0_004895E8(void);
extern void func_L01_00517748_004895E8(s32);
extern void func_L01_00516090_004895E8(void *);
extern s32 func_L01_005169C8_004895E8(s32, f32);

void func_L01_004895E8(void) {
    s32 v;
    s32 b;
    b = *(s32 *)(D_001D52FC + 0x1C4);
    if (b & 4) {
        func_003A5348(3, 0, 0);
        D_L01_001D8844_004895E8 = D_L01_001D8844_004895E8 - 1;
    } else if (b & 8) {
        func_003A5348(3, 0, 0);
        D_L01_001D8844_004895E8 = D_L01_001D8844_004895E8 + 1;
    } else if (b & 0x40) {
        func_003A5348(4, 0, 0);
        func_L01_004894F8_004895E8();
    } else if (b & 0x80) {
        func_003A5348(4, 0, 0);
        if (D_L01_001D8790_004895E8 == 0) {
            D_L01_001D8790_004895E8 = 1;
        } else {
            D_L01_001D8790_004895E8 = 0;
        }
    } else if (b & 1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748_004895E8(func_L01_00487EB0_004895E8());
        func_L01_00516090_004895E8((void *)func_L01_00489FD0_004895E8());
    } else if (b & 2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748_004895E8(func_L01_0048D8D8_004895E8());
        func_L01_00516090_004895E8((void *)func_L01_00489FD0_004895E8());
    }
    v = D_L01_001D8844_004895E8;
    if (v > -1) { } else { v = 7; }
    v = (v > 7) ? 0 : v;
    D_L01_001D8844_004895E8 = v;
    func_L01_005169C8_004895E8(0x190001, (f32)v);
}
/* localdecomp:end func_L01_004895E8 */

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

/* localdecomp:start func_L01_004899B0 */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern s32 D_L01_001D8848;
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_005170B8(s32, u32);

void func_L01_004899B0(void) {
    s32 b = *(s32 *)(D_001D52FC + 0x1C4);

    if (b & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C--;
        if (D_L01_001D883C < 0) {
            D_L01_001D883C = 3;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
        func_L01_005170B8(0x19000F, 0x402299DE);
    } else if (b & 0x4000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C++;
        if (D_L01_001D883C >= 4) {
            D_L01_001D883C = 0;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
        func_L01_005170B8(0x19000F, 0x402299DE);
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838--;
        if (D_L01_001D8838 < 0) {
            if (D_L01_001D883C < 2) {
                D_L01_001D8838 = 4;
            } else {
                D_L01_001D883C -= 2;
                D_L01_001D8838 = 3;
                D_L01_001D8848 = 1;
            }
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
        func_L01_005170B8(0x19000F, 0x402299DE);
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838++;
        if (D_L01_001D8838 >= 5) {
            D_L01_001D8838 = 0;
            if (D_L01_001D883C >= 2) {
                D_L01_001D883C -= 2;
                D_L01_001D8848 = 1;
            }
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
        func_L01_005170B8(0x19000F, 0x402299DE);
    }
}
/* localdecomp:end func_L01_004899B0 */

/* localdecomp:start func_L01_00489B30 */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern s32 D_L01_001D8848;
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_005170B8(s32, u32);

void func_L01_00489B30(void) {
    s32 b = *(s32 *)(D_001D52FC + 0x1C4);

    if (b & 0x1000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C--;
        if (D_L01_001D883C < 0) {
            D_L01_001D883C = 1;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
    } else if (b & 0x4000) {
        func_003A5348(3, 0, 0);
        D_L01_001D883C++;
        if (D_L01_001D883C > 1) {
            D_L01_001D883C = 0;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838--;
        if (D_L01_001D8838 < 0) {
            D_L01_001D8838 = 4;
            D_L01_001D8848 = 0;
            D_L01_001D883C += 2;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        D_L01_001D8838++;
        if (D_L01_001D8838 > 3) {
            D_L01_001D8838 = 0;
            D_L01_001D8848 = 0;
            D_L01_001D883C += 2;
        }
        func_L01_005170B8(0x19000E, 0x402299DE);
    }
}
/* localdecomp:end func_L01_00489B30 */

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

/* localdecomp:start func_L01_00489D20 */
extern s32 func_L01_00517190_00489D20(s32, s32);
extern s32 func_L01_00516D60_00489D20(s32, s32);
extern void func_L01_00489CB0_00489D20(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 D_L01_001D88E0_00489D20;
extern s32 D_L01_001D88E4_00489D20;
extern s32 D_L01_001D88E8_00489D20;
extern s32 D_L01_001D8838_00489D20;
extern s32 D_L01_001D883C_00489D20;
extern s32 D_L01_001D8848_00489D20;
extern u8 D_L01_001D672C_00489D20;
__asm__(".extern D_L01_001D672C_00489D20, 16");
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern void func_L01_00489758_00489D20(void);
extern void func_L01_00489870_00489D20(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00489160_00489D20(void);
extern s32 func_L01_0047EBE0_00489D20(void);
extern void func_L01_00517748_00489D20(s32);
extern void func_L01_00516090_00489D20(s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28_00489D20(void);
extern void func_L01_004895E8_00489D20(void);
extern void func_L01_00489C68_00489D20(void);
extern void func_L01_00489060_00489D20(void);
extern void func_L01_004892C0_00489D20(void);
extern void func_L01_00489410_00489D20(void);
extern void func_L01_00487FC8_00489D20(void);
extern void func_L01_00488108_00489D20(void);
extern s32 func_L01_0047DAB0_00489D20(void);
extern void func_L01_0047DAC8_00489D20(void);

void func_L01_00489D20(s32 a0) {
    s32 t;

    func_L01_00517190_00489D20(0x190002, 1);
    func_L01_00516D60_00489D20(0x190002, 1);
    if (D_L01_001D88E0_00489D20 != D_L01_001D8838_00489D20 || D_L01_001D88E4_00489D20 != D_L01_001D883C_00489D20 || D_L01_001D88E8_00489D20 != D_L01_001D8848_00489D20) {
        if (D_L01_001D88E0_00489D20 >= 0 && D_L01_001D88E4_00489D20 >= 0 && D_L01_001D88E8_00489D20 >= 0) {
            func_L01_00489CB0_00489D20(D_L01_001D88E8_00489D20, D_L01_001D88E0_00489D20, D_L01_001D88E4_00489D20, 0x706EC8FF);
        }
    }
    func_L01_00489CB0_00489D20(D_L01_001D8848_00489D20, D_L01_001D8838_00489D20, D_L01_001D883C_00489D20, 0x80FFFFFF);
    D_L01_001D88E0_00489D20 = D_L01_001D8838_00489D20;
    D_L01_001D88E4_00489D20 = D_L01_001D883C_00489D20;
    D_L01_001D88E8_00489D20 = D_L01_001D8848_00489D20;
    func_L01_00489758_00489D20();
    func_L01_00489870_00489D20();
    func_003BB5D0();
    func_003BB590(0x19000E);
    func_003BB590(0x19000F);
    func_003BB590(0x190001);
    func_L01_00489160_00489D20();
    t = *(s32 *)(D_001D52FC + 0x1C4);
    if (t & 0x900) {
        func_L01_00517748_00489D20(func_L01_0047EBE0_00489D20());
        func_L01_00516090_00489D20(a0);
    } else if (t & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748_00489D20(func_L01_0047FE28_00489D20());
        func_L01_00516090_00489D20(a0);
    }
    func_L01_004895E8_00489D20();
    func_L01_00489C68_00489D20();
    func_L01_00489060_00489D20();
    func_L01_004892C0_00489D20();
    func_L01_00489410_00489D20();
    func_L01_00487FC8_00489D20();
    func_L01_00488108_00489D20();
    if (func_L01_0047DAB0_00489D20()) {
        func_L01_0047DAC8_00489D20();
        func_L01_00516090_00489D20(a0);
        if (D_L01_001D672C_00489D20 == 0) {
            func_L01_00517748_00489D20(func_L01_0047EBE0_00489D20());
        }
    }
}
/* localdecomp:end func_L01_00489D20 */

/* localdecomp:start func_L01_00489F00 */
__asm__(".extern D_001D4C60, 32");
__asm__(".extern D_001D4C80, 32");
extern s32 D_L01_001D88D8_00489F00;
extern s32 D_L01_001D88DC_00489F00;
extern s32 D_L01_001D87A0_00489F00[2];
extern s32 D_L01_001D87C0_00489F00[2];
extern s32 D_001D4C60;
extern s32 D_001D4C80;
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_L01_00517918_00489F00(s32);
extern void func_003A2750(s32);

void func_L01_00489F00(void) {
    Obj *o;
    func_003BB468(D_L01_001D88D8_00489F00);
    func_003BB468(D_L01_001D88DC_00489F00);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_L01_00517918_00489F00(16);
    func_L01_00517918_00489F00(17);
    func_L01_00517918_00489F00(19);
    func_L01_00487F50_00489F00(D_L01_001D87A0_00489F00, &D_001D4C60);
    func_L01_00487F50_00489F00(D_L01_001D87C0_00489F00, &D_001D4C80);
}
/* localdecomp:end func_L01_00489F00 */

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
