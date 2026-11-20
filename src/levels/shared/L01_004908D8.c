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

/* declared by functions of L01_0048B738.c, which this file was cut from */
extern char *func_00381FF0(s32 id);
extern s32 func_003A5348(s32, s32, s32);
extern void *func_L01_0047EBE0(void);
extern void *func_L01_004914D0(void *);
extern void func_L01_00517748(void *);
extern void func_003BB468(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_L01_00490930(void);

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
extern s32 func_003A5348(s32, s32, s32);
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

/* localdecomp:start func_L01_00490A50 */
extern s32 D_L01_001D8D60_00490A50;
extern s32 D_L01_001D8D64_00490A50;
extern s32 D_L01_001D8D68_00490A50;
extern s32 D_L01_001D8DB4_00490A50;
extern E_0048D0C8 D_L01_002EB038_00490A50[];
extern char D_L01_001D8DB8_00490A50[];
extern char D_L01_001D8DC0_00490A50[];
extern char D_L01_001D8DC8_00490A50[];
extern char D_L01_001D8DD0_00490A50[];
typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7;
    s32 w8;
    u8 padC[0xAD - 0xC];
    u8 bAD;
} S_00490A50;
extern S_00490A50 D_00143950;
__asm__(".extern D_001D5520, 16");
extern s32 D_001D5520;
extern s32 *func_003B9BD0(s32);
extern char *func_003B9E30(s32 *, s32, s32);
extern char *func_00381FF0(s32 id);
extern void func_L01_00517190_00490A50(s32 id, s32 v);
extern void func_L01_00516D60_00490A50(s32 id, s32 v);
extern void func_0011B2E8_00490A50(char *dst, char *fmt, ...);

void func_L01_00490A50(void) {
    s32 i;

    for (i = 0; i < D_L01_001D8D60_00490A50; i++) {
        switch (D_L01_002EB038_00490A50[i].w0) {
        case 0x146:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x146));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_00143950.w8 ? func_00381FF0(0x237) : func_00381FF0(0x236));
            break;
        case 0x148:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x148));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_00143950.b6 ? func_00381FF0(0x175) : func_00381FF0(0x176));
            break;
        case 0x234:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x234));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC8_00490A50);
            break;
        case 0x233:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x233));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC8_00490A50);
            break;
        case 0x508:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x508));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_00143950.bAD ? func_00381FF0(0x175) : func_00381FF0(0x176));
            break;
        case 0x509:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DB8_00490A50, func_00381FF0(0x509));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_001D5520 ? func_00381FF0(0x175) : func_00381FF0(0x176));
            break;
        case 0x18E:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DD0_00490A50, func_00381FF0(0x142), func_00381FF0(0x18E));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_00143950.b5 ? func_00381FF0(0x175) : func_00381FF0(0x176));
            break;
        case 0x18D:
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 0, i), D_L01_001D8DD0_00490A50, func_00381FF0(0x142), func_00381FF0(0x18D));
            func_0011B2E8_00490A50(func_003B9E30(func_003B9BD0(0), 1, i), D_L01_001D8DC0_00490A50, D_00143950.b4 ? func_00381FF0(0x175) : func_00381FF0(0x176));
            break;
        }
    }
    if (D_L01_001D8D64_00490A50 >= 0) {
        if (D_L01_001D8D68_00490A50 != D_L01_001D8D64_00490A50) {
            D_L01_001D8DB4_00490A50 = 30;
        }
        if (D_L01_001D8DB4_00490A50 != 0 && --D_L01_001D8DB4_00490A50 == 0) {
            func_L01_00517190_00490A50(0x1E0003, D_L01_002EB038_00490A50[D_L01_001D8D64_00490A50].w8);
            func_L01_00516D60_00490A50(0x1E0003, 1);
        }
        D_L01_001D8D68_00490A50 = D_L01_001D8D64_00490A50;
    }
}
/* localdecomp:end func_L01_00490A50 */
