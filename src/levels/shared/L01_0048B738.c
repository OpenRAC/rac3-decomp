#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
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
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

INCLUDE_ASM("asm/levels", func_L01_0048B738);

INCLUDE_ASM("asm/levels", func_L01_0048BA38);

INCLUDE_ASM("asm/levels", func_L01_0048BD78);

INCLUDE_ASM("asm/levels", func_L01_0048BF00);

/* localdecomp:start func_L01_0048BF28 */
extern s32 D_L01_001D8A10;

void func_L01_0048BF28(s32 a) {
    D_L01_001D8A10 = a;
}
/* localdecomp:end func_L01_0048BF28 */

/* localdecomp:start func_L01_0048BF30 */
extern s32 D_L01_001D8A10;
void func_L01_0048BF30(void) {
    D_L01_001D8A10 = -1;
}
/* localdecomp:end func_L01_0048BF30 */

INCLUDE_ASM("asm/levels", func_L01_0048BF40);

/* localdecomp:start func_L01_0048BFC8 */

extern s32 D_L01_001D8BE0;
extern struct U_488750 D_L01_001E0900 __attribute__((section(".sdata")));
extern struct U_488750 D_L01_001D8BDC __attribute__((section(".sdata")));
extern char D_L01_001D8BE8[];
extern char D_L01_001D8BF0[];
extern E_488750 D_L01_002BC9F0[];
extern char *func_00381FF0(s32 id);
extern void func_L01_00516FD8(s32 id, char *s);
extern void func_L01_00517190(s32 id, s32 v);
extern void func_L01_00516D60(s32 id, s32 v);
extern void func_0011B2E8(char *dst, char *fmt, char *s);

void func_L01_0048BFC8(void) {
    s32 v = ((s32 *)&D_L01_001E0900)[D_L01_001D8BE0];
    E_488750 *e;

    if (v == -1) {
        **(char **)&D_L01_001D8BDC = 0;
        func_L01_00516FD8(29, D_L01_001D8BE8);
        func_L01_00517190(28, 17);
        return;
    }
    e = &D_L01_002BC9F0[v];
    func_L01_00516D60(28, 1);
    if (e->w0 != -1) {
        func_0011B2E8(*(char **)&D_L01_001D8BDC, D_L01_001D8BF0, func_00381FF0(e->w0));
    }
    if (e->w4 != -1) {
        func_L01_00516FD8(29, func_00381FF0(e->w4));
    } else {
        func_L01_00516FD8(29, D_L01_001D8BE8);
    }
    if (e->w12 != -1) {
        func_L01_00516D60(28, 1);
        func_L01_00517190(28, e->w12);
    } else {
        func_L01_00517190(28, 17);
    }
}
/* localdecomp:end func_L01_0048BFC8 */

INCLUDE_ASM("asm/levels", func_L01_0048C0F0);

INCLUDE_ASM("asm/levels", func_L01_0048C4A0);

INCLUDE_ASM("asm/levels", func_L01_0048D588);

/* localdecomp:start func_L01_0048D820 */

extern s32 D_L01_001D8BB8;
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_L01_00517918(s32);

void func_L01_0048D820(void) {
    O_00489FA8 *o;
    func_003BB468(D_L01_001D8BB8);
    o = func_003B42F8(0);
    o->vt->f12(o);
    func_003A2750(1);
    func_L01_00517918(15);
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(18);
    func_L01_00517918(19);
    func_L01_00517918(20);
}
/* localdecomp:end func_L01_0048D820 */

/* localdecomp:start func_L01_0048D898 */
extern void func_L01_0047E4B8_0048D898();
 
void func_L01_0048D898(void) {
    func_L01_0047E4B8_0048D898();
}
/* localdecomp:end func_L01_0048D898 */

/* localdecomp:start func_L01_0048D8B8 */
extern void func_L01_0047E520_0048D8B8();
 
void func_L01_0048D8B8(void) {
    func_L01_0047E520_0048D8B8();
}
/* localdecomp:end func_L01_0048D8B8 */

/* localdecomp:start func_L01_0048D8D8 */
extern s32 func_L01_0048D8D8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E08F8;
extern s32 D_L01_001E08E0[2];
extern void func_L01_0048C4A0();
extern void func_L01_0048D820();
extern void func_L01_0048D588();
extern void func_L01_0048D898_0048D8D8(void);
extern void func_L01_0048D8B8_0048D8D8();
s32 func_L01_0048D8D8(void) {
    if (D_L01_001E08F8 == 0) {
        func_003E6FA0(D_L01_001E08E0, (s32)func_L01_0048C4A0, (s32)func_L01_0048D820, (s32)func_L01_0048D588, (s32)func_L01_0048D898_0048D8D8, (s32)func_L01_0048D8B8_0048D8D8);
        D_L01_001E08F8 = 1;
    }
    return (s32)D_L01_001E08E0;
}
/* localdecomp:end func_L01_0048D8D8 */

/* localdecomp:start func_L01_0048D930 */
extern void func_L01_0048D930(s32, s32);
extern s32 D_L01_001D8C30;
extern s32 D_L01_001D8C34;

void func_L01_0048D930(s32 a, s32 b) { D_L01_001D8C30 = a; D_L01_001D8C34 = b; }
/* localdecomp:end func_L01_0048D930 */

/* localdecomp:start func_L01_0048D940 */
extern s32 D_L01_001D8C84;
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C7C;
extern void func_L01_0047DE68(void);
extern s32 func_003BB118(s32);

void func_L01_0048D940(void) {
    func_L01_0047DE68();
    D_L01_001D8C84 = func_003BB118(0);
    D_L01_001D8C78 = 0;
    D_L01_001D8C7C = 0;
}
/* localdecomp:end func_L01_0048D940 */

/* localdecomp:start func_L01_0048D970 */
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C34;
extern s32 D_L01_001D8C84;
extern s32 func_003BB118(s32);
extern s32 func_L01_00437B68(s32, s32 *, s32, s32);

void func_L01_0048D970(void) {
    s32 v;
    D_L01_001D8C78 = 0;
    v = func_003BB118(0);
    D_L01_001D8C84 = v;
    if (func_L01_00437B68(v, &D_L01_001D8C78, 409, D_L01_001D8C34) == 0) {
        D_L01_001D8C78 = 0;
    }
}
/* localdecomp:end func_L01_0048D970 */

/* localdecomp:start func_L01_0048D9B0 */
extern void func_L01_0048D970(void);
extern s32 D_L01_001D8C78;
extern s32 D_L01_001D8C7C;

void func_L01_0048D9B0(void) {
    func_L01_0048D970();
    if (D_L01_001D8C7C >= D_L01_001D8C78) {
        D_L01_001D8C7C = D_L01_001D8C78 - 1;
    }
}
/* localdecomp:end func_L01_0048D9B0 */

INCLUDE_ASM("asm/levels", func_L01_0048D9E8);

INCLUDE_ASM("asm/levels", func_L01_0048DE98);

INCLUDE_ASM("asm/levels", func_L01_0048DF60);

INCLUDE_ASM("asm/levels", func_L01_0048E028);

INCLUDE_ASM("asm/levels", func_L01_0048E0C0);

INCLUDE_ASM("asm/levels", func_L01_0048EA10);

INCLUDE_ASM("asm/levels", func_L01_0048EB88);

INCLUDE_ASM("asm/levels", func_L01_0048EB90);

/* localdecomp:start func_L01_0048EDA8 */
extern O_00489FA8 *func_003B42F8(s32);

extern s32 D_L01_001D8C88;
extern s32 D_L01_001D8C8C;
extern s32 D_L01_001D8C90;
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);

void func_L01_0048EDA8(void)
{
    Obj_0048B530 *obj;

    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(18);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(0);
    obj->vtbl->fn(obj);
    obj = ((Obj_0048B530 * (*)(s32))func_003B42F8)(1);
    obj->vtbl->fn(obj);
    func_003A2750(1);
    func_003BB468(D_L01_001D8C88);
    func_003BB468(D_L01_001D8C8C);
    func_003BB468(D_L01_001D8C90);
}
/* localdecomp:end func_L01_0048EDA8 */

/* localdecomp:start func_L01_0048EE30 */
extern void func_L01_0047E4B8_0048EE30();
 
void func_L01_0048EE30(void) {
    func_L01_0047E4B8_0048EE30();
}
/* localdecomp:end func_L01_0048EE30 */

/* localdecomp:start func_L01_0048EE50 */
extern void func_L01_0047E520_0048EE50();
 
void func_L01_0048EE50(void) {
    func_L01_0047E520_0048EE50();
}
/* localdecomp:end func_L01_0048EE50 */

/* localdecomp:start func_L01_0048EE70 */
extern s32 func_L01_0048EE70(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0950;
extern s32 D_L01_001E0938[2];
extern void func_L01_0048E0C0();
extern void func_L01_0048EDA8();
extern void func_L01_0048EB90();
extern void func_L01_0048EE30_0048EE70(void);
extern void func_L01_0048EE50_0048EE70();
s32 func_L01_0048EE70(void) {
    if (D_L01_001E0950 == 0) {
        func_003E6FA0(D_L01_001E0938, (s32)func_L01_0048E0C0, (s32)func_L01_0048EDA8, (s32)func_L01_0048EB90, (s32)func_L01_0048EE30_0048EE70, (s32)func_L01_0048EE50_0048EE70);
        D_L01_001E0950 = 1;
    }
    return (s32)D_L01_001E0938;
}
/* localdecomp:end func_L01_0048EE70 */

INCLUDE_ASM("asm/levels", func_L01_0048EEC8);

INCLUDE_ASM("asm/levels", func_L01_0048F390);

INCLUDE_ASM("asm/levels", func_L01_0048F428);

/* localdecomp:start func_L01_0048F490 */
extern void func_L01_0047E4B8_0048F490(void);
extern void func_003A9440(s32, s32);
extern void func_L01_0042EBF0(s32);
extern void func_L01_0047E520(void);
void func_L01_0048F490(void) {
    func_L01_0047E4B8_0048F490();
    func_003A9440(66, 68);
    func_003A9440(71, 11);
    func_L01_0042EBF0(1);
    func_L01_0047E520();
}
/* localdecomp:end func_L01_0048F490 */

INCLUDE_ASM("asm/levels", func_L01_0048F4D8);

INCLUDE_ASM("asm/levels", func_L01_0048F4E0);

/* localdecomp:start func_L01_0048FB98 */
extern s32 func_L01_0048FB98(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0978;
extern s32 D_L01_001E0960[2];
extern void func_L01_0048EEC8();
extern void func_L01_0048F428();
extern void func_L01_0048F390();
extern void func_L01_0048F490(void);
extern void func_L01_0048F4D8_0048FB98();
s32 func_L01_0048FB98(void) {
    if (D_L01_001E0978 == 0) {
        func_003E6FA0(D_L01_001E0960, (s32)func_L01_0048EEC8, (s32)func_L01_0048F428, (s32)func_L01_0048F390, (s32)func_L01_0048F490, (s32)func_L01_0048F4D8_0048FB98);
        D_L01_001E0978 = 1;
    }
    return (s32)D_L01_001E0960;
}
/* localdecomp:end func_L01_0048FB98 */

INCLUDE_ASM("asm/levels", func_L01_0048FBF0);

INCLUDE_ASM("asm/levels", func_L01_00490050);

/* localdecomp:start func_L01_00490370 */
extern void func_L01_00517918_00490370(s32);
extern void func_L01_00490930(void);
extern void func_003A2750(s32);

void func_L01_00490370(void) {
    func_L01_00517918_00490370(16);
    func_L01_00517918_00490370(17);
    func_L01_00517918_00490370(20);
    func_L01_00490930();
    func_003A2750(1);
}
/* localdecomp:end func_L01_00490370 */

/* localdecomp:start func_L01_004903B0 */
extern void func_L01_0047E4B8_004903B0();
 
void func_L01_004903B0(void) {
    func_L01_0047E4B8_004903B0();
}
/* localdecomp:end func_L01_004903B0 */

/* localdecomp:start func_L01_004903D0 */
extern void func_L01_0047E520_004903D0();
 
void func_L01_004903D0(void) {
    func_L01_0047E520_004903D0();
}
/* localdecomp:end func_L01_004903D0 */

INCLUDE_ASM("asm/levels", func_L01_004903F0);

INCLUDE_ASM("asm/levels", func_L01_004906D0);

/* localdecomp:start func_L01_004908D8 */
extern O_00489FA8 *func_003B42F8(s32);
extern S_48D030 D_00160C40[];
extern void *D_L01_001D8D74;
extern void *D_L01_001D8D78;
extern void *func_003BB3A8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_004908D8(void) {
    D_L01_001D8D74 = func_003BB3A8(0);
    D_L01_001D8D78 = func_003BB3A8(0);
    func_003B4528(((void * (*)(s32))func_003B42F8)(1), (s32)D_L01_001D8D74, (s32)D_L01_001D8D78, D_00160C40->f4954, (s32)D_00160C40->f6F30);
}
/* localdecomp:end func_L01_004908D8 */

/* localdecomp:start func_L01_00490930 */
extern O_00489FA8 *func_003B42F8(s32);
extern void *D_L01_001D8D78;
extern void *D_L01_001D8D74;

extern void func_003BB468(s32);

void func_L01_00490930(void) {
    Obj *o = ((Obj * (*)(s32))func_003B42F8)(1);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D8D74));
    func_003BB468((*(s32 *)&D_L01_001D8D78));
}
/* localdecomp:end func_L01_00490930 */

/* localdecomp:start func_L01_00490970 */

extern s32 D_L01_001D8D64;
extern u8 D_L01_001D672C;
extern E_0048D0C8 D_L01_002EB038[];
extern void func_003A5348(s32, s32, s32);
extern void *func_L01_00517688(void);
extern void *func_L01_004914D0(void *);
extern void *func_L01_0047EBE0(void);
extern void func_L01_00517748(void *);
extern void func_L01_00516090_00490970(void *);

void func_L01_00490970(void *a0, u32 a1) {
    if (a1 & 0xA040) {
        if (D_L01_002EB038[D_L01_001D8D64].fn != 0) {
            (D_L01_001D8D64)[D_L01_002EB038].fn(a1);
        }
    } else if (a1 & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_004914D0(func_L01_00517688()));
        func_L01_00516090_00490970(a0);
    } else if (a1 & 0x900) {
        if (D_L01_001D672C == 0) {
            func_003A5348(4, 0, 0);
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090_00490970(a0);
        }
    }
}
/* localdecomp:end func_L01_00490970 */

INCLUDE_ASM("asm/levels", func_L01_00490A50);

INCLUDE_ASM("asm/levels", func_L01_00490FC8);

/* localdecomp:start func_L01_004910C0 */
extern void func_L01_0048FBF0(void);
extern void func_L01_00490370_004910C0(void);
extern void func_L01_00490050(void);
extern void func_L01_004903B0_004910C0(void);
extern void func_L01_004903D0_004910C0(void);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 D_L01_001E0998;
extern s32 D_L01_001E09B8;
extern s32 D_L01_001E09D8;
extern s32 D_L01_001E09F8;
extern s32 D_L01_001E0980[2];
extern s32 D_L01_001E09A0[2];
extern s32 D_L01_001E09C0[2];
extern s32 D_L01_001E09E0[2];
extern V16_48DCD8 D_L01_001D8DD8[];
s32 func_L01_004910C0(s32 idx) {
    V16_48DCD8 v;
    if (D_L01_001E0998 == 0) {
        func_003E6FA0(D_L01_001E0980, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E0998 = 1;
    }
    if (D_L01_001E09B8 == 0) {
        func_003E6FA0(D_L01_001E09A0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09B8 = 1;
    }
    if (D_L01_001E09D8 == 0) {
        func_003E6FA0(D_L01_001E09C0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09D8 = 1;
    }
    if (D_L01_001E09F8 == 0) {
        func_003E6FA0(D_L01_001E09E0, (s32)func_L01_0048FBF0, (s32)func_L01_00490370_004910C0, (s32)func_L01_00490050, (s32)func_L01_004903B0_004910C0, (s32)func_L01_004903D0_004910C0);
        D_L01_001E09F8 = 1;
    }
    v = D_L01_001D8DD8[0];
    return *(s32 *)(v.b + (idx << 2));
}
/* localdecomp:end func_L01_004910C0 */
