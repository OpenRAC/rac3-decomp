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

/* localdecomp:start func_L01_0048BF00 */
extern s32 D_L01_001E08A0[] __attribute__((section(".sdata")));
extern s32 D_L01_001D8A60;

void func_L01_0048BF00(void) {
    D_L01_001E08A0[0] = 0;
    D_L01_001E08A0[1] = 0;
    D_L01_001E08A0[2] = 0;
    D_L01_001E08A0[3] = 0;
    D_L01_001D8A60 = 0;
}
/* localdecomp:end func_L01_0048BF00 */

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

/* localdecomp:start func_L01_0048BF40 */
typedef struct {
    s32 id;
    u8 on;
    u8 pad5[0xB0 - 5];
} S_0048BF40;

extern s32 D_L01_001D8A10;
extern s32 D_L01_001D8A2C;
extern S_0048BF40 D_L01_00233DD8[];

s32 func_L01_0048BF40(void) {
    s32 key = D_L01_001D8A10;
    s32 found = 0;
    s32 i = 0;

    if (key >= 0) {
        for (i = 0; i < 30; i++) {
            if (D_L01_00233DD8[i].id == key && D_L01_00233DD8[i].on) {
                D_L01_001D8A2C = i;
                found = 1;
                break;
            }
        }
    }
    D_L01_001D8A10 = -1;
    return found;
}
/* localdecomp:end func_L01_0048BF40 */

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

/* localdecomp:start func_L01_0048C0F0 */
typedef struct {
    s32 w0;
    u8 pad4[0x3C];
    s16 h40;
    s16 h42;
} S_0048C0F0;

extern S_0048C0F0 D_00142660;
extern u8 D_001426E0[];
extern u8 D_00142CA0[];
extern s32 D_00142C18[];
extern u8 D_001D554F[] __attribute__((section(".sdata")));
extern u8 D_001D5550[] __attribute__((section(".sdata")));
extern u8 D_001D5551[] __attribute__((section(".sdata")));
extern u8 D_001D5552[] __attribute__((section(".sdata")));
extern u8 D_001D5553[] __attribute__((section(".sdata")));
extern s32 D_L01_001E0900_0048C0F0;
extern char *D_L01_001D8BC0[] __attribute__((section(".sdata")));
extern char *D_L01_001D8BC0_0048C0F0;
extern char D_L01_001D8BF8[];
extern s32 func_L01_00517F50(s32, s32, s32);
extern s32 func_L01_00452740(void);
extern s32 func_L01_004526E8(void);
extern s32 func_0011B2E8_0048C0F0(char *, char *, s32);

void func_L01_0048C0F0(void) {
    s32 i;
    s32 id;
    s32 a, b, r;

    for (i = 9; i >= 0; i--) {
        ((s32 *)&D_L01_001E0900)[i] = -1;
    }
    D_L01_001E0900_0048C0F0 = D_00142660.h40 + 11;
    if (D_00142CA0[0x14]) {
        ((s32 *)&D_L01_001E0900)[1] = 0;
    } else if (D_00142CA0[0x21]) {
        if (!(D_00142C18[0] & 0x1000000)) {
            ((s32 *)&D_L01_001E0900)[1] = 3;
        }
    }
    if (D_00142CA0[7]) ((s32 *)&D_L01_001E0900)[2] = 2;
    if (D_00142CA0[5]) ((s32 *)&D_L01_001E0900)[3] = 1;
    if (D_00142CA0[0x20]) ((s32 *)&D_L01_001E0900)[4] = 0x10;
    if (D_001D554F[0]) ((s32 *)&D_L01_001E0900)[5] = 5;
    if (D_001D5551[0]) ((s32 *)&D_L01_001E0900)[6] = 6;
    if (D_001D5552[0]) ((s32 *)&D_L01_001E0900)[7] = 7;
    if (D_001D5550[0]) ((s32 *)&D_L01_001E0900)[8] = 8;
    if (D_00142CA0[0x22]) ((s32 *)&D_L01_001E0900)[9] = 4;
    if (D_001D5553[0]) ((s32 *)&D_L01_001E0900)[9] = 9;

    for (i = 0; i < 10; i++) {
        id = i + 0x30;
        if (((s32 *)&D_L01_001E0900)[i] == -1 || D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8 == -1) {
            ((s32 (*)(s32, s32))func_L01_00516D60)(id, 0);
        } else {
            ((s32 (*)(s32, s32))func_L01_00516D60)(id, 1);
            if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC6E) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 0);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC6F) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 1);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC70) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 2);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC71) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 3);
            } else if (D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w0 == 0xC72) {
                func_L01_00517F50(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8, 4);
            } else {
                func_L01_00517190(id, D_L01_002BC9F0[((s32 *)&D_L01_001E0900)[i]].w8);
            }
        }
    }

    a = func_L01_00452740();
    b = func_L01_004526E8();
    r = 40 - a;
    func_0011B2E8_0048C0F0(D_L01_001D8BC0_0048C0F0, D_L01_001D8BF8, a);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[1], D_L01_001D8BF8, r);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[2], D_L01_001D8BF8, b);
    a = D_00142660.h42;
    b = D_001426E0[0x7E];
    r = 101 - a - b;
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[3], D_L01_001D8BF8, a);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[4], D_L01_001D8BF8, r);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[5], D_L01_001D8BF8, b);
    func_0011B2E8_0048C0F0(D_L01_001D8BC0[6], D_L01_001D8BF8, D_00142660.w0);
    D_L01_001D8BE0 = 0;
    func_L01_0048BFC8();
}
/* localdecomp:end func_L01_0048C0F0 */
