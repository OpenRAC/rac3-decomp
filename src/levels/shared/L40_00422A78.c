#include "common.h"

typedef struct {
    u8 pad00[0x20];
    s32 f20;
    s32 f24;
    u8 pad28[4];
    f32 f2C;
} Obj_00423310;
typedef struct S2_00423310 {
    u8 pad00[0x70];
    s32 f70;
    s32 f74;
    u8 pad78[0xC];
    s32 f84;
} S2_00423310;
typedef struct {
    u8 pad00[0x20];
    u8 f20;
    u8 pad21[0x47];
    S2_00423310 *f68;
    u8 pad6C[0x3C];
    u8 fA8;
} Self_00423310;

/* localdecomp:start func_L40_00422A78 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L40_00422A78(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L40_00422A78 */

/* localdecomp:start func_L40_00422AA0 */
extern s32 func_L39_0066DCC8(s32, s32, s32, s32);
extern void func_L39_00662AA0(s32, s32 *, s32);

void func_L40_00422AA0(s32 a, s32 b) {
    s32 buf[4];
    s32 h = func_L39_0066DCC8(a, 1, 0, 250);
    buf[0] = b;
    func_L39_00662AA0(h, buf, 4);
}
/* localdecomp:end func_L40_00422AA0 */

/* localdecomp:start func_L40_00422AE8 */
s32 func_L40_00422AE8(s32 a0) {
    s32 r;

    r = -1;
    switch (a0) {
    case 0x1ABA: r = 5; break;
    case 0x1ABD: r = 2; break;
    case 0x1ABC: r = 3; break;
    case 0x1ABB: r = 4; break;
    case 0x1ABE: r = 7; break;
    case 0x1AC0: r = 9; break;
    case 0x1AC1: r = 6; break;
    case 0x1B09: r = 15; break;
    case 0x1ABF: case 0x1B0A:
        r = 12;
        break;
    }
    return r;
}
/* localdecomp:end func_L40_00422AE8 */

/* localdecomp:start func_L40_00422B60 */
s32 func_L40_00422B60(s32 a0) {
    switch (a0) {
    case 3: return 0x1096;
    case 2: return 0x1087;
    case 4: return 0x1089;
    case 5: return 0x108A;
    case 6: return 0x1098;
    case 9: return 0x10A7;
    case 7: return 0x10A4;
    case 8: break;
    }
    return -1;
}
/* localdecomp:end func_L40_00422B60 */

/* localdecomp:start func_L40_00422BC8 */
s32 func_L40_00422BC8(s32 index)
{
    switch (index) {
    case 3: return 0x1ABC;
    case 2: return 0x1ABD;
    case 4: return 0x1ABB;
    case 5: return 0x1ABA;
    case 6: return 0x1AC1;
    case 9: return 0x1AC0;
    case 7: return 0x1ABE;
    case 8: break;
    }
    return -1;
}
/* localdecomp:end func_L40_00422BC8 */

/* localdecomp:start func_L40_00422C30 */
typedef struct S_422C30_B {
    char _p0[0x80];
    s32 f80;
} S_422C30_B;
typedef struct S_422C30_A {
    char _p0[0x68];
    S_422C30_B *f68;
    char _p6C[0xAA - 0x6C];
    s16 fAA;
} S_422C30_A;
extern s32 func_L40_00422B60(s32 arg0);

/* from rac4-decomp's func_L41_00411AD8 */
s32 func_L40_00422C30(S_422C30_A *arg0) {
    S_422C30_B *p = arg0->f68;
    switch (arg0->fAA) {
    case 0x1ABA: return 0x108A;
    case 0x1ABB: return 0x1089;
    case 0x1ABC: return 0x1096;
    case 0x1ABD: return 0x1087;
    case 0x1ABE: return 0x10A4;
    case 0x1ABF: return 0x10A5;
    case 0x1AC0: return 0x10A7;
    case 0x1AC1: return 0x1098;
    case 0x1AF2: return 0x1AF3;
    case 0x1B09: return 0x1B0C;
    case 0x1B0A: return 0x1B0D;
    case 0x1B0B: return 0x1B0E;
    case 0x1F1E: return func_L40_00422B60(p->f80);
    }
    return -1;
}
/* localdecomp:end func_L40_00422C30 */

/* localdecomp:start func_L40_00422D58 */
extern s32 func_L40_00422AE8(s32);
extern void func_L39_00672118(s32);
void func_L40_00422D58(u8 *p) {
    func_L39_00672118(func_L40_00422AE8(*(s16 *)(p + 0xAA)));
}
/* localdecomp:end func_L40_00422D58 */

INCLUDE_ASM("asm/levels", func_L40_00422D80);

/* localdecomp:start func_L40_00423120 */
typedef struct {
    u8 pad00[0x30];
    s32 f30;
    u8 pad34[0x40];
    s32 f74;
    u8 pad78[8];
    s32 f80;
} S2_423120;

typedef struct {
    u8 pad00[0x20];
    u8 f20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x32];
    S2_423120 *f68;
    u8 pad6C[0x2C];
    s32 f98;
} Obj_423120;

extern void func_L01_004450F0(void *, s32, s32);
extern void func_L39_005F2FF8(void *, s32);
extern s32 func_L39_0061BFB0(s32);
extern void func_L39_00662B18(s32 *, void *, s32);
extern s32 func_L40_004224E0(void *);
extern s32 func_L40_00422540(void *);
extern s32 func_L40_00422550(void *);
extern s32 func_L40_00422560(void *);
extern void func_L40_00422570(void *);
extern void func_L40_00422678(void *, s32, s32);
extern void func_L40_00423CB0(void *);
extern void func_L40_00423E90(void *, s32);
extern void func_L40_00424540(void *, s32, s32);
extern void func_L40_004C5C78(s32, s32, void *, s32);
extern s32 D_001A5DF8[];

/* from rac4-decomp's func_L41_00411D70 */
void func_L40_00423120(Obj_423120 *obj, s32 *msg) {
    u8 b;
    s32 w;
    S2_423120 *s2;
    u32 type;
    s32 r;
    type = *msg & 0xF;
    s2 = obj->f68;
    switch (type) {
    case 0:
        if ((u32)(obj->f20 - 1) < 2) {
            u16 v;
            s2->f30 = 0;
            v = obj->f34 & 0xEFFF;
            obj->f34 = v;
            if (obj->f20 == 1) {
                func_L40_00424540(obj, 0, 0);
            } else {
                obj->f98 = 0;
                obj->f34 = v | 0x41;
                func_L39_005F2FF8(obj, 1);
                func_L01_004450F0(obj, 4, -1);
            }
            if (func_L40_00422540(obj) != 0) {
                func_L39_00662B18(msg, &b, 1);
                s2->f80 = b;
            }
            if (func_L40_004224E0(obj) != 0 || func_L40_00422560(obj) != 0 || func_L40_00422540(obj) != 0) {
                func_L40_00423CB0(obj);
            }
        }
        break;
    case 1:
        func_L39_00662B18(msg, &w, 4);
        r = func_L39_0061BFB0(w);
        if ((u32)(obj->f20 - 4) < 2) {
            func_L40_00423E90(obj, r);
        }
        obj->f98 = 0;
        obj->f34 = (obj->f34 | 0x41) & 0xEFFF;
        func_L39_005F2FF8(obj, 1);
        func_L40_00422570(obj);
        s2->f74 = D_001A5DF8[0];
        func_L01_004450F0(obj, 6, -1);
        break;
    case 2:
        func_L40_00422678(obj, -1, 0);
        func_L40_004C5C78(0x15, 0, obj, 0);
        if (func_L40_00422550(obj) != 0) {
            func_L40_00423CB0(obj);
        }
        break;
    }
}
/* localdecomp:end func_L40_00423120 */

/* localdecomp:start func_L40_00423310 */
extern u8 *func_L01_00447490(void *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L47_0041F2F0(void *);
extern void func_L40_00422870(void *, void *);
extern s32 func_L40_00422D80(void *, void *);
extern void func_L40_00422AA0(s32, s32);
extern void func_L40_00424540(void *, s32, s32);
extern u8 *func_L39_0061CF40(s32);
extern s32 func_L39_00560220(void *);
extern void func_L39_00560308(void *);
extern s32 D_001A5DF8[];
extern s32 *D_L40_00249330[8] __attribute__((section(".sdata")));

s32 func_L40_00423310(Self_00423310 *self) {
    S2_00423310 *s2 = self->f68;
    Obj_00423310 *v = (Obj_00423310 *)func_L01_00447490(self, 0x0B030001, 0);
    s32 i;
    s32 ok;
    u8 *y;
    s32 *e;

    if (v != 0) {
        if (v->f24 == 0x2000000) {
            v = 0;
        }
    }
    self->fA8 = 0xFF;
    switch (self->f20) {
    case 1:
        if (v != 0 && 0.0f < v->f2C) {
            if (func_L47_0041F2F0(self) == 0) {
                func_L40_00424540(self, 0, (s32)v);
                ok = 1;
                func_L01_004450F0(self, 2, -1);
                y = 0;
                if (v->f20 != 0) {
                    y = func_L39_0061CF40(v->f20);
                    if (y != 0 && y[0x1A14] == 0) {
                        ok = 0;
                    }
                }
                if (ok != 0) {
                    func_L40_00422870(self, y);
                }
            }
        }
        break;
    case 2:
    case 3:
        break;
    case 4:
    case 5:
        for (i = 0; i < 8; i++) {
            e = D_L40_00249330[i];
            if (e != 0 && func_L01_0040E548((u8 *)e + 0xA0, (u8 *)self + 0x10) < 4.0f && func_L40_00422D80(e, self) != 0) {
                func_L40_00422AA0((s32)self, *e);
                break;
            }
        }
        break;
    case 6:
        if (s2->f84 != 0 && s2->f70 > 0) {
            if (s2->f70 < D_001A5DF8[0] - s2->f74) {
                if (func_L39_00560220(self) == 0) {
                    func_L39_00560308(self);
                }
            }
        }
        break;
    }
    return 0;
}
/* localdecomp:end func_L40_00423310 */

/* localdecomp:start func_L40_00423510 */
s32 func_L40_00423510(s32 arg0, s32 *arg1, s32 *arg2) {
    *arg2 = 0;
    *arg1 = 0;
    return 0;
}
/* localdecomp:end func_L40_00423510 */
