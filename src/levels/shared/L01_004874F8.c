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
extern void func_L01_00517748(s32);
extern s32 func_L01_0047EBE0(void);
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 D_001425C0[];
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_00517190(s32, s32);
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
extern u8 D_00142CA0[];
extern void func_L01_00516AA0(s32, s32, s32);
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern s32 func_L01_00486980(void);
extern int func_L01_0047DB70(int);

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

/* localdecomp:start func_L01_00487670 */
typedef struct {
    u8 pad0[4];
    s32 x4;
    u8 pad8[0x36];
    s16 h3E;
    u8 pad40[0xB0];
} E_00487670;

extern s32 D_L01_001D86E8_00487670;
extern s32 D_L01_001D86EC_00487670;
extern s32 D_L01_001D8718_00487670[2];
extern s32 D_L01_001D8770_00487670;
extern char D_L01_001D8778_00487670[];
extern char D_L01_001D8780_00487670[];
extern char D_L01_001D8788_00487670[];
extern char D_L01_002EA828_00487670[];
extern char D_L01_002EA8A8_00487670[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern E_00487670 D_L01_002C5600_00487670[];
extern s32 func_L01_00487508_00487670(s32, s32);
extern s32 func_L01_00487528_00487670(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern s32 func_L01_00517190_00487670(s32, s32);
extern s32 func_L01_00516D60_00487670(s32, s32);
extern void func_L01_00517D18_00487670(s32);

void func_L01_00487670(void) {
    s32 idx = func_L01_00487508_00487670(D_L01_001D86E8_00487670, D_L01_001D86EC_00487670);
    if (D_00142CA0[idx] != 0) {
        func_0011B2E8(D_L01_002EA828_00487670, D_L01_001D8778_00487670, func_00381FF0(((E_00487670 *)(D_001425C0[idx] * 0xF0 + (u8 *)D_L01_002C5600_00487670))->x4));
        func_0011B2E8(D_L01_002EA8A8_00487670, D_L01_001D8778_00487670, func_00381FF0(D_L01_002C5600_00487670[D_001425C0[idx]].h3E));
        func_L01_00517190_00487670(0xF000B, D_L01_001D8718_00487670[func_L01_00487528_00487670(D_L01_001D86E8_00487670, D_L01_001D86EC_00487670)] + 1);
        func_L01_00517190_00487670(0xF000D, D_L01_001D8718_00487670[func_L01_00487528_00487670(D_L01_001D86E8_00487670, D_L01_001D86EC_00487670)] + 1);
        func_L01_00516D60_00487670(0xF000B, 1);
        func_L01_00516D60_00487670(0xF000D, 1);
    } else {
        func_0011B2E8(D_L01_002EA828_00487670, D_L01_001D8780_00487670);
        func_0011B2E8(D_L01_002EA8A8_00487670, D_L01_001D8788_00487670);
        func_L01_00517190_00487670(0xF000B, 3);
        func_L01_00517190_00487670(0xF000D, 3);
    }
    if (D_L01_001D8770_00487670 != idx) {
        func_L01_00517D18_00487670(0xF0008);
    }
    D_L01_001D8770_00487670 = idx;
}
/* localdecomp:end func_L01_00487670 */

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

/* localdecomp:start func_L01_00487930 */
extern void func_L01_0047EC88(void);
extern void func_L01_00487840(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00487670(void);
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00487930(s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28(void);
extern s32 D_L01_001D86E8;
extern s32 D_L01_001D86EC;
extern s32 D_L01_001D86F0[2];
extern s32 func_L01_005170B8(s32, u32);
extern s32 func_L01_00487508(s32, s32);
extern s32 func_L01_00487528(s32, s32);
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s16 D_001A7464[];
extern Entry_00483CD8 D_L01_002C5600[];
extern int func_L01_0047DB70(int);
extern void func_L01_0047EC38(s32);
extern s32 func_L01_00486980(void);
extern s32 func_L01_00489FD0(void);
extern void func_L01_0047EDB0_00487930(s32, s32);
extern void func_L01_004875F8(void);
extern s32 func_L01_00516D60(s32, s32);
extern void func_L01_004878D0(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern u8 D_L01_001D672C;
__asm__(".extern D_L01_001D672C, 16");

typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padC[0xF0 - 0xC];
} E_00487930;

void func_L01_00487930(s32 a0) {
    s32 b;
    s32 i;
    s32 j;
    s32 ok;

    func_L01_0047EC88();
    func_L01_00487840();
    func_003BB5D0();
    func_003BB590(0xF0002);
    func_L01_00487670();
    b = *(s32 *)(D_001D52FC + 0x1C4);
    if (b & 0x800) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_00487930(a0);
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00487930(a0);
    } else if (b & 0x1000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86E8 == 4 && D_L01_001D86EC == 0) {
            D_L01_001D86EC = 1;
            D_L01_001D86E8 = 3;
        } else {
            D_L01_001D86EC = (D_L01_001D86EC + 1) % 2;
        }
        func_L01_005170B8(0xF0002, 0x402299DE);
    } else if (b & 0x4000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86E8 == 4 && D_L01_001D86EC == 0) {
            D_L01_001D86EC = 1;
            D_L01_001D86E8 = 3;
        } else {
            D_L01_001D86EC = (D_L01_001D86EC + 1) % 2;
        }
        func_L01_005170B8(0xF0002, 0x402299DE);
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86EC > 0) {
            D_L01_001D86E8 = (D_L01_001D86E8 + 3) % 4;
        } else {
            D_L01_001D86E8 = (D_L01_001D86E8 + 4) % 5;
        }
        func_L01_005170B8(0xF0002, 0x402299DE);
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86EC > 0) {
            D_L01_001D86E8 = (D_L01_001D86E8 + 1) % 4;
        } else {
            D_L01_001D86E8 = (D_L01_001D86E8 + 1) % 5;
        }
        func_L01_005170B8(0xF0002, 0x402299DE);
    } else if (b & 0x40) {
        s32 idx = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
        s32 a = D_00142CA0[idx] && !(idx == 2 || idx == 3);
        s32 c = (idx == 2 || idx == 3) && D_001A7464[0] == 0;
        if (a | c) {
            s32 s;
            func_003A5348(4, 0, 0);
            s = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
            if (((E_00487930 *)&D_L01_002C5600[D_001425C0[s]])->x8 == 1 && func_L01_0047DB70(1) == s) {
                func_L01_0047EC38(0x1C);
            } else {
                func_L01_0047EC38(s);
            }
        } else {
            func_003A5348(5, 0, 0);
        }
    } else if (b & 0x1) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00486980());
        func_L01_00516090_00487930(a0);
    } else if (b & 0x2) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_00489FD0());
        func_L01_00516090_00487930(a0);
    }
    func_L01_0047EDB0_00487930(func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC), *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_004875F8();
    for (i = 0; i < 9; i++) {
        ok = 1;
        for (j = 0; ok && j < 4; j++) {
            if (func_L01_0047DB70(j) == D_L01_001D86F0[i]) {
                ok = 0;
            }
        }
        if (ok) {
            func_L01_005170B8(i + 0xF001B, 0x8066CCFF);
            func_L01_00516D60(i + 0xF0026, 0);
        } else {
            func_L01_00516D60(i + 0xF0026, 1);
        }
    }
    func_L01_005170B8(func_L01_00487528(D_L01_001D86E8, D_L01_001D86EC) + 0xF001B, 0x80FFFFFF);
    func_L01_004878D0();
    if (func_L01_0047DAB0()) {
        func_L01_0047DAC8();
        func_L01_00516090_00487930(a0);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_00487930 */

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

/* localdecomp:start func_L01_00487F08 */
void func_L01_00487F08(void) {
    s32 i;
    for (i = 0; i <= 20; i++) {
    }
    for (i = 0; i <= 7; i++) {
    }
}
/* localdecomp:end func_L01_00487F08 */

/* localdecomp:start func_L01_00487F50 */
void func_L01_00487F50(s32 *a, s32 *b) {
    s32 i;
    for (i = 7; i >= 0; i--) {
        *b++ = *a++;
    }
}
/* localdecomp:end func_L01_00487F50 */

/* localdecomp:start func_L01_00487F78 */
extern s32 D_L01_002EAB28[];
extern s32 D_L01_001D88F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D88F0, 8");

s32 func_L01_00487F78(s32 a, s32 b, s32 c) {
    s32 i;
    switch (a) {
    case 0:
        i = b * 4 + c;
        return D_L01_002EAB28[i];
    case 1:
        i = b * 2 + c;
        return D_L01_001D88F0[i];
    }
    return 0;
}
/* localdecomp:end func_L01_00487F78 */

/* localdecomp:start func_L01_00487FC8 */
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8_00487FC8;

extern s32 func_L01_005170B8_00487FC8(s32, u32);
extern s32 func_L01_00517190_00487FC8(s32, s32);
extern void func_L01_00516AA0_00487FC8(s32, s32, s32);
extern Entry_00483CD8 D_L01_002C5600_00487FC8[];
extern s32 D_L01_001D8790_00487FC8;
extern s32 D_L01_001D8844_00487FC8;
extern s32 D_L01_001D87A0_00487FC8[2];
extern s32 D_L01_001D87C0_00487FC8[2];
extern u8 D_001425C0[];

void func_L01_00487FC8(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (i == D_L01_001D8844_00487FC8) {
            func_L01_005170B8_00487FC8(0x19007B + i, 0x80FFFFFF);
        } else {
            func_L01_005170B8_00487FC8(0x19007B + i, 0x706EC8FF);
        }
        switch (D_L01_001D8790_00487FC8) {
        case 0:
            if (D_L01_001D87A0_00487FC8[i] != 0) {
                func_L01_00516AA0_00487FC8(0x19007B + i, 1, 1);
                ((void (*)(s32, s32))func_L01_00517190_00487FC8)(0x19007B + i, ((E_4848A8_00487FC8 *)(D_001425C0[D_L01_001D87A0_00487FC8[i]] * 240 + (s32)((E_4848A8_00487FC8 *)&D_L01_002C5600_00487FC8)))->h38);
            } else {
                func_L01_00516AA0_00487FC8(0x19007B + i, 1, 0);
            }
            break;
        case 1:
            if (D_L01_001D87C0_00487FC8[i] != 0) {
                func_L01_00516AA0_00487FC8(0x19007B + i, 1, 1);
                ((void (*)(s32, s32))func_L01_00517190_00487FC8)(0x19007B + i, ((E_4848A8_00487FC8 *)(D_001425C0[D_L01_001D87C0_00487FC8[i]] * 240 + (s32)((E_4848A8_00487FC8 *)&D_L01_002C5600_00487FC8)))->h38);
            } else {
                func_L01_00516AA0_00487FC8(0x19007B + i, 1, 0);
            }
            break;
        }
    }
}
/* localdecomp:end func_L01_00487FC8 */

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
