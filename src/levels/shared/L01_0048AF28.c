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
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_003A2750(s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, char *, ...);
extern void func_003BB468(s32 a0);
extern void func_003A2750(s32 a0);
extern int func_0011B2E8(char *, char *, ...);
extern u8 *D_001D52FC;
extern s32 func_003A5348(s32, s32, s32);
extern s32 D_001D545C;
extern s32 func_003B9BD0(s32);
extern void func_003BB0E8(s32);
extern void func_L01_0048B338(void);

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

/* localdecomp:start func_L01_0048B080 */
typedef struct {
    s32 id;
    u8 flag;
    char text[0xAB];
} E_0048B080;
typedef struct { s32 w0; s32 w4; } T_0048B080;
extern void *func_0011A264(void *, s32, s32);
extern s32 func_003BB118(s32);
typedef struct {
    s32 base;
    s32 end;
    s32 slot[6];
} B_0048B080;
extern B_0048B080 D_L01_001E08B0 __attribute__((section(".sdata")));
extern s32 D_L01_001D8A3C;
extern E_0048B080 D_L01_00233DD8_0048B080[];
extern T_0048B080 D_L01_002E9DC0_0048B080[];
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_0048AFB8(s32);

void func_L01_0048B080(void) {
    char fmt[32];
    s32 p;
    s32 i;
    s32 r;

    func_0011A264(fmt, 0, 32);
    p = func_003BB118(0);
    D_L01_001E08B0.base = p;
    p += 0x10;
    for (i = 0; i < 6; i++) {
        D_L01_001E08B0.slot[i] = p;
        p += 0x20;
    }
    D_L01_001E08B0.end = p;
    for (i = 0; i < D_L01_001D8A3C; i++) {
        s32 v = D_L01_00233DD8_0048B080[i].id;
        if (v == 1 || v == 2 || v == 4 || v == 8 || v == 27 || v == 28 || v == 9 || v == 29 ||
            v == 5 || v == 13 || v == 23 || v == 10 || v == 18 || v == 14) {
            r = v > 0 ? D_L01_002E9DC0_0048B080[v % 60].w4 : D_L01_002E9DC0_0048B080[1].w4;
        } else {
            r = v > 0 ? D_L01_002E9DC0_0048B080[v % 60].w0 : D_L01_002E9DC0_0048B080[1].w0;
        }
        if (r != 0) {
            fmt[0] = '%';
            fmt[1] = 's';
            fmt[2] = 0;
            func_0011B2E8(D_L01_00233DD8_0048B080[i].text, fmt, func_00381FF0(r));
        } else {
            fmt[0] = ' ';
            fmt[1] = 0;
            func_0011B2E8(D_L01_00233DD8_0048B080[i].text, fmt);
        }
        func_L01_0048AFB8(i);
    }
}
/* localdecomp:end func_L01_0048B080 */

/* localdecomp:start func_L01_0048B270 */
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
} S_160C40_0048B270;
extern S_160C40_0048B270 D_00160C40;
extern s32 D_L01_001D8A40_0048B270;
extern s32 D_L01_001D8A44_0048B270;
extern s32 D_L01_001D8A48_0048B270;
extern s32 D_L01_001D8A4C_0048B270;
extern s32 D_L01_001D8A50_0048B270;
extern s32 D_L01_001D8A54_0048B270;
extern void *func_003BB3A8(s32);
extern Obj *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);

void func_L01_0048B270(void) {
    s32 size = 0x9600;
    D_L01_001D8A40_0048B270 = (s32)func_003BB3A8(1);
    D_L01_001D8A44_0048B270 = (s32)func_003BB3A8(1);
    D_L01_001D8A48_0048B270 = (s32)func_003BB3A8(0);
    D_L01_001D8A4C_0048B270 = D_L01_001D8A48_0048B270 + size;
    D_L01_001D8A50_0048B270 = (s32)func_003BB3A8(0);
    D_L01_001D8A54_0048B270 = D_L01_001D8A50_0048B270 + size;
    func_003B4528(func_003B42F8(0), D_L01_001D8A40_0048B270, D_L01_001D8A44_0048B270, D_00160C40.f4954, (s32)&D_00160C40 + 0x6C68);
    func_003B4528(func_003B42F8(1), D_L01_001D8A48_0048B270, D_L01_001D8A4C_0048B270, D_00160C40.f4954, (s32)&D_00160C40 + 0x6C78);
    func_003B4528(func_003B42F8(2), D_L01_001D8A50_0048B270, D_L01_001D8A54_0048B270, D_00160C40.f4954, (s32)&D_00160C40 + 0x7080);
}
/* localdecomp:end func_L01_0048B270 */

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

/* localdecomp:start func_L01_0048B588 */
typedef struct {
    s32 id;
    u8 flag;
    u8 pad5[0xA7];
    void (*fn)(void *, s32);
} S_0048B588;

typedef struct {
    u8 pad[0x1C4];
    s32 x1C4;
} P_0048B588;

extern S_0048B588 D_L01_00233DD8_0048B588[];
extern s32 D_L01_001D8A34;
extern s32 D_L01_001D8A28;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003BB0E8(s32);
extern s32 func_L01_0048EE70(void);
extern s32 func_L01_00495030(void);
extern void func_L01_0048D930(s32, s32);
extern void func_L01_00516090_0048B588(void *);
extern void func_L01_00517748(s32);
extern s32 func_L01_0047EBE0(void);

void func_L01_0048B588(void *a0) {
    s32 k;
    D_L01_001D8A34 = func_003B9C58(func_003B9BD0(0));
    if (((P_0048B588 *)D_001D52FC)->x1C4 & 0x40) {
        s32 i = D_L01_001D8A34;
        if (D_L01_00233DD8_0048B588[i].flag && D_L01_00233DD8_0048B588[i].fn) {
            D_L01_00233DD8_0048B588[i].fn(a0, D_L01_00233DD8_0048B588[i].id);
            k = 4;
        } else {
            k = 1;
        }
        func_003A5348(k, 0, 0);
    } else if (((P_0048B588 *)D_001D52FC)->x1C4 & 0x80) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0048EE70());
        func_L01_0048D930(1, -1);
        func_L01_00516090_0048B588(a0);
    }
    if (D_L01_001D8A34 < D_L01_001D8A28) {
        D_L01_001D8A28 = D_L01_001D8A34;
    } else if (D_L01_001D8A34 >= D_L01_001D8A28 + 7) {
        D_L01_001D8A28 = D_L01_001D8A34 - 6;
    }
    if (D_L01_001D8A28 < 0) {
        D_L01_001D8A28 = 0;
    }
    if (((P_0048B588 *)D_001D52FC)->x1C4 & 0x910) {
        if (D_001D545C == 12 || D_001D545C == 18) {
            func_003A5348(5, 0, 0);
            func_L01_00517748(func_L01_00495030());
            func_L01_00516090_0048B588(a0);
        } else {
            func_003BB0E8(D_001D545C);
            func_L01_00517748(func_L01_0047EBE0());
            func_003A5348(20, 0, 0);
            func_L01_00516090_0048B588(a0);
        }
    }
}
/* localdecomp:end func_L01_0048B588 */
