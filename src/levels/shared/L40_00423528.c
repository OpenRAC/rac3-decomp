#include "common.h"

typedef struct Eff_00423528 {
    f32 f0;
    u8 pad4[0x1A];
    u16 f1E;
} Eff_00423528;
typedef struct Mob_00423528 {
    f32 p0[3];
    f32 pad0C;
    f32 p10[3];
    u8 pad1C[0x15];
    u8 f31;
    u8 pad32[2];
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
    u8 pad9C[0x5C];
    f32 fF8;
} Mob_00423528;
typedef struct Aux_00423528 {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x30];
    u16 f44;
} Aux_00423528;
typedef struct Self_00423528 {
    u8 pad0[0x24];
    Aux_00423528 *f24;
    u8 pad28[0xC];
    u16 f34;
    u8 pad36[0x62];
    s32 f98;
} Self_00423528;
typedef struct Obj_00423528 {
    u8 pad0[0x30];
    f32 f30;
    u8 pad34[0x3C];
    s32 f70;
    s32 f74;
    Mob_00423528 *f78;
    u8 pad7C[8];
    s32 f84;
    s32 f88;
} Obj_00423528;

/* localdecomp:start func_L40_00423528 */
#include "vu0.h"

__asm__(".extern D_L40_00241640, 16");
__asm__(".extern D_L40_002412DC, 16");
__asm__(".extern D_L40_00241120, 16");
extern s8 *D_L40_00241640;
extern s32 D_L40_002412DC;
extern s32 *D_L40_00241120;
extern s32 D_001A5DF8[];

extern s32 func_L01_004561B8(u8 *);
extern s32 func_L40_00422608(u8 *);
extern s32 func_L40_00545BF0(void);
extern s32 func_L40_004224F8(u8 *);
extern s32 func_L39_00672208(s32);
extern s32 func_L39_00672190(s32);
extern void func_003C2880(u8 *);
extern s32 func_L39_0066C828(u8 *, s32, s32);
extern s32 func_L40_00422D58(u8 *);
extern s32 func_L40_00422BC8(s32);
extern void func_L40_004224A0(u8 *, s32);
extern void func_L40_00423BD8(u8 *);
extern void func_L39_0061C1E0(u8 *, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L40_00422550(u8 *);
extern void func_L40_00423CB0(u8 *);
extern void func_L39_005F2FF8(void *, s32);
extern s32 func_L40_005406C0(u8 *);
extern u8 *func_L01_00447490(u8 *, s32, s32);
extern void func_L40_00424540(u8 *, s32, void *);
extern u8 *func_L39_0061CF40(s32);
extern s32 func_L47_0041F2F0(u8 *);
extern void func_L40_00422870(u8 *, u8 *);
extern s32 func_L40_004224E0(u8 *);
extern s32 func_L40_00422560(u8 *);
extern s32 func_L40_00422540(u8 *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C4840(void *, void *, f32);
extern void func_0038D850(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L40_00424920(u8 *);
extern u8 *func_L39_0061BF38(s32);
extern f32 func_L01_0040E548(void *, void *);
extern s32 func_L40_00422D80(u8 *, u8 *);
extern u8 *func_L39_0061BFB0(s32);
extern s32 func_L40_00423E90(u8 *, u8 *);
extern void func_L40_00422570(u8 *);


static __inline__ void setf_00423528(Eff_00423528 *e) {
    e->f1E |= 1;
}


void func_L40_00423528(u8 *self) {
    Obj_00423528 *o;
    u8 *p;
    u8 *q;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 flag;

    o = *(Obj_00423528 **)(self + 0x68);
    if ((*(u16 *)(self + 0x34) & 0x80) && D_L40_002412DC == 4) {
        return;
    }
    setf_00423528((Eff_00423528 *)&o->f30);
    switch (self[0x20]) {
    case 0:
        if (func_L01_004561B8(self) != 0) {
            if (func_L40_00422608(self) != 0) {
                a = func_L40_00545BF0();
                c = func_L40_004224F8(self);
                if (c == 0 || (a != 0 && (a != 1 || func_L39_00672208(1) == 0))) {
                    goto L1C;
                }
            }
            func_003C2880(self);
            return;
        L1C:
            func_L39_0066C828(self, -1, 1);
            o->f70 = o->f70 * 1000;
            if (c != 0) {
                s32 s20 = 0x1F1E;
                s32 s21;
                s21 = func_L40_00422D58(self);
                if (func_L40_00545BF0() == 1) {
                    for (i = 0; i < 8; i++) {
                        a = func_L39_00672190(i);
                        if (func_L39_00672208(a) != 0) {
                            s20 = func_L40_00422BC8(a);
                            break;
                        }
                    }
                }
                if (((D_L40_00241640[0x199] >> s21) & 1) == 0) {
                    func_L40_004224A0(self, s20);
                }
            }
            func_L40_00423BD8(self);
            func_L39_0061C1E0(self, -1);
            self[0xBE] &= 0xE7;
            o->f30 = 0;
            *(u16 *)(self + 0x34) &= 0xEFFF;
        }
        if (o->f84 != 0) {
            func_L01_004450F0(self, 1, -1);
            o->f30 = 1.0f;
            *(u16 *)(self + 0x34) |= 0x1000;
            if (func_L40_00422550(self) != 0) {
                func_L40_00423CB0(self);
            }
        } else {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(self + 0x98) = 0;
            func_L39_005F2FF8(self, 1);
            func_L01_004450F0(self, 6, -1);
        }
        break;
    case 1:
        if (func_L40_005406C0(self) == 0) {
            p = func_L01_00447490(self, 0x0B030001, 0);
            if (p != 0) {
                if (*(u32 *)(p + 0x24) == 0x2000000) {
                    p = 0;
                }
            }
            self[0xA8] = 0xFF;
            flag = 0;
            q = 0;
            if (p != 0 && *(f32 *)(p + 0x2C) > 0.0f) {
                func_L40_00424540(self, 0, p);
                func_L01_004450F0(self, 2, -1);
                if (*(s32 *)(p + 0x20) != 0) {
                    q = func_L39_0061CF40(*(s32 *)(p + 0x20));
                    if (q != 0) {
                        flag = q[0x1A14] != 0;
                    }
                }
            }
            if (flag != 0 && func_L47_0041F2F0(self) == 0) {
                func_L40_00422870(self, q);
            }
        }
        break;
    case 2:
        if (func_L01_004561B8(self) != 0) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F2FF8(self, 1);
        }
        *(u16 *)(self + 0x96) += 1;
        if (*(u16 *)(self + 0x96) >= 0x4C) {
            func_L01_004450F0(self, 1, -1);
            *(u16 *)(self + 0x34) &= 0xFFBE;
            ((Self_00423528 *)self)->f34 |= ((Self_00423528 *)self)->f24->f44 & 0x1000;
            ((Self_00423528 *)self)->f98 = ((Self_00423528 *)self)->f24->f10;
        }
        break;
    case 3:
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F2FF8(self, 1);
        func_L01_004450F0(self, 4, -1);
        self[0xA8] = 0xFF;
        break;
    case 4:
        if (func_L40_004224E0(self) != 0 || func_L40_00422560(self) != 0 || func_L40_00422540(self) != 0) {
            if (o->f78 != 0) {
                vu0_v4 w;
                vu0_v4 tmp;
                vu0_v4 v;
                tmp = *(vu0_v4 *)(self + 0xE0);
                o->f78->fF8 = func_0038DAB8(o->f78->fF8, 0.094247788f);
                func_003C4840(&w, &tmp, 0.094247788f);
                v.x = o->f78->p10[0] - o->f78->p0[0] * 0.0009765625f;
                v.y = o->f78->p10[1] - o->f78->p0[1] * 0.0009765625f;
                v.z = o->f78->p10[2] - o->f78->p0[2] * 0.0009765625f;
                func_0038D850(&v, &v, &w);
                vec_add_ab(o->f78->p10, self + 0x10, &v);
                func_0038CF68(&tmp, &tmp, 0.75f);
                vec_add_ba(o->f78->p10, o->f78->p10, &tmp);
            }
        }
        if (o->f78 == 0 || o->f78->f31 != 0) {
            func_L40_00424920(self);
        }
        for (a = 0; a < *D_L40_00241120; a++) {
            u8 *r = func_L39_0061BF38(a);
            if (r != 0 && func_L01_0040E548(r + 0xA0, self + 0x10) < 4.0f && func_L40_00422D80(r, self) != 0) {
                if (o->f78 != 0) {
                    o->f78->f34 |= 0x41;
                    o->f78->f34 &= 0xEFFF;
                    o->f78->f98 = 0;
                    func_L39_005F2FF8(o->f78, 1);
                }
                o->f88 = *(s32 *)r;
                func_L01_004450F0(self, 5, -1);
                return;
            }
        }
        break;
    case 5:
        *(u16 *)(self + 0x96) += 1;
        if (*(u16 *)(self + 0x96) >= 0x4C) {
            u8 *r = func_L39_0061BFB0(o->f88);
            if (r != 0 && r[0x1A14] != 0 && func_L40_00423E90(self, r) != 0) {
                *(s32 *)(self + 0x98) = 0;
                *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F2FF8(self, 1);
                func_L40_00422570(self);
                o->f74 = D_001A5DF8[0];
                func_L01_004450F0(self, 6, -1);
            } else {
                func_L01_004450F0(self, 4, -1);
            }
        }
        break;
    case 6:
    default:
        break;
    }
}
/* localdecomp:end func_L40_00423528 */

INCLUDE_ASM("asm/levels", func_L40_00423BD8);
