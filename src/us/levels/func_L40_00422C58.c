#include "common.h"

/* NTSC-U counterpart of func_L40_00423528 (src/levels/shared/L40_00423528.c) */
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

/* localdecomp:start func_L40_00422C58 */
#include "vu0.h"

__asm__(".extern D_L40_002417C0, 16");
__asm__(".extern D_L40_0024145C, 16");
__asm__(".extern D_L40_002412A0, 16");
extern s8 *D_L40_002417C0;
extern s32 D_L40_0024145C;
extern s32 *D_L40_002412A0;
extern s32 D_001A5F78[];

extern s32 func_L01_00452EC8(u8 *);
extern s32 func_L40_00421D38(u8 *);
extern s32 func_L40_005432E0(void);
extern s32 func_L40_00421C28(u8 *);
extern s32 func_L39_0066F8B8(s32);
extern s32 func_L39_0066F840(s32);
extern void func_003BD360(u8 *);
extern s32 func_L39_00669F20(u8 *, s32, s32);
extern s32 func_L40_00422488(u8 *);
extern s32 func_L40_004222F8(s32);
extern void func_L40_00421BD0(u8 *, s32);
extern void func_L40_00423308(u8 *);
extern void func_L39_00619A68(u8 *, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern s32 func_L40_00421C80(u8 *);
extern void func_L40_004233E0(u8 *);
extern void func_L39_005F08F8(void *, s32);
extern s32 func_L40_0053DDF8(u8 *);
extern u8 *func_L01_00444358(u8 *, s32, s32);
extern void func_L40_00423C70(u8 *, s32, void *);
extern u8 *func_L39_0061A7C8(s32);
extern s32 func_L40_00421F78_00422C58(u8 *);
extern void func_L40_00421FA0(u8 *, u8 *);
extern s32 func_L40_00421C10(u8 *);
extern s32 func_L40_00421C90(u8 *);
extern s32 func_L40_00421C70(u8 *);
extern f32 func_00389380(f32, f32);
extern void func_003BF2F8(void *, void *, f32);
extern void func_00389118(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern void func_L40_00424050(u8 *);
extern u8 *func_L39_006197C0(s32);
extern f32 func_L01_0040C018(void *, void *);
extern s32 func_L40_004224B0(u8 *, u8 *);
extern u8 *func_L39_00619838(s32);
extern s32 func_L40_004235C0(u8 *, u8 *);
extern void func_L40_00421CA0(u8 *);


static __inline__ void setf_00423528(Eff_00423528 *e) {
    e->f1E |= 1;
}


void func_L40_00422C58(u8 *self) {
    Obj_00423528 *o;
    u8 *p;
    u8 *q;
    s32 i;
    s32 a;
    s32 b;
    s32 c;
    s32 flag;

    o = *(Obj_00423528 **)(self + 0x68);
    if ((*(u16 *)(self + 0x34) & 0x80) && D_L40_0024145C == 4) {
        return;
    }
    setf_00423528((Eff_00423528 *)&o->f30);
    switch (self[0x20]) {
    case 0:
        if (func_L01_00452EC8(self) != 0) {
            if (func_L40_00421D38(self) != 0) {
                a = func_L40_005432E0();
                c = func_L40_00421C28(self);
                if (c == 0 || (a != 0 && (a != 1 || func_L39_0066F8B8(1) == 0))) {
                    goto L1C;
                }
            }
            func_003BD360(self);
            return;
        L1C:
            func_L39_00669F20(self, -1, 1);
            o->f70 = o->f70 * 1000;
            if (c != 0) {
                s32 s20 = 0x1F1E;
                s32 s21;
                s21 = func_L40_00422488(self);
                if (func_L40_005432E0() == 1) {
                    for (i = 0; i < 8; i++) {
                        a = func_L39_0066F840(i);
                        if (func_L39_0066F8B8(a) != 0) {
                            s20 = func_L40_004222F8(a);
                            break;
                        }
                    }
                }
                if (((D_L40_002417C0[0x199] >> s21) & 1) == 0) {
                    func_L40_00421BD0(self, s20);
                }
            }
            func_L40_00423308(self);
            func_L39_00619A68(self, -1);
            self[0xBE] &= 0xE7;
            o->f30 = 0;
            *(u16 *)(self + 0x34) &= 0xEFFF;
        }
        if (o->f84 != 0) {
            func_L01_00441FB8(self, 1, -1);
            o->f30 = 1.0f;
            *(u16 *)(self + 0x34) |= 0x1000;
            if (func_L40_00421C80(self) != 0) {
                func_L40_004233E0(self);
            }
        } else {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(self + 0x98) = 0;
            func_L39_005F08F8(self, 1);
            func_L01_00441FB8(self, 6, -1);
        }
        break;
    case 1:
        if (func_L40_0053DDF8(self) == 0) {
            p = func_L01_00444358(self, 0x0B030001, 0);
            if (p != 0) {
                if (*(u32 *)(p + 0x24) == 0x2000000) {
                    p = 0;
                }
            }
            self[0xA8] = 0xFF;
            flag = 0;
            q = 0;
            if (p != 0 && *(f32 *)(p + 0x2C) > 0.0f) {
                func_L40_00423C70(self, 0, p);
                func_L01_00441FB8(self, 2, -1);
                if (*(s32 *)(p + 0x20) != 0) {
                    q = func_L39_0061A7C8(*(s32 *)(p + 0x20));
                    if (q != 0) {
                        flag = q[0x1A14] != 0;
                    }
                }
            }
            if (flag != 0 && func_L40_00421F78_00422C58(self) == 0) {
                func_L40_00421FA0(self, q);
            }
        }
        break;
    case 2:
        if (func_L01_00452EC8(self) != 0) {
            *(s32 *)(self + 0x98) = 0;
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F08F8(self, 1);
        }
        *(u16 *)(self + 0x96) += 1;
        if (*(u16 *)(self + 0x96) >= 0x5B) {
            func_L01_00441FB8(self, 1, -1);
            *(u16 *)(self + 0x34) &= 0xFFBE;
            ((Self_00423528 *)self)->f34 |= ((Self_00423528 *)self)->f24->f44 & 0x1000;
            ((Self_00423528 *)self)->f98 = ((Self_00423528 *)self)->f24->f10;
        }
        break;
    case 3:
        *(s32 *)(self + 0x98) = 0;
        *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
        func_L39_005F08F8(self, 1);
        func_L01_00441FB8(self, 4, -1);
        self[0xA8] = 0xFF;
        break;
    case 4:
        if (func_L40_00421C10(self) != 0 || func_L40_00421C90(self) != 0 || func_L40_00421C70(self) != 0) {
            if (o->f78 != 0) {
                vu0_v4 w;
                vu0_v4 tmp;
                vu0_v4 v;
                tmp = *(vu0_v4 *)(self + 0xE0);
                o->f78->fF8 = func_00389380(o->f78->fF8, 0.07853981853f);
                func_003BF2F8(&w, &tmp, 0.07853981853f);
                v.x = o->f78->p10[0] - o->f78->p0[0] * 0.0009765625f;
                v.y = o->f78->p10[1] - o->f78->p0[1] * 0.0009765625f;
                v.z = o->f78->p10[2] - o->f78->p0[2] * 0.0009765625f;
                func_00389118(&v, &v, &w);
                vec_add_ab(o->f78->p10, self + 0x10, &v);
                func_00388830(&tmp, &tmp, 0.75f);
                vec_add_ba(o->f78->p10, o->f78->p10, &tmp);
            }
        }
        if (o->f78 == 0 || o->f78->f31 != 0) {
            func_L40_00424050(self);
        }
        for (a = 0; a < *D_L40_002412A0; a++) {
            u8 *r = func_L39_006197C0(a);
            if (r != 0 && func_L01_0040C018(r + 0xA0, self + 0x10) < 4.0f && func_L40_004224B0(r, self) != 0) {
                if (o->f78 != 0) {
                    o->f78->f34 |= 0x41;
                    o->f78->f34 &= 0xEFFF;
                    o->f78->f98 = 0;
                    func_L39_005F08F8(o->f78, 1);
                }
                o->f88 = *(s32 *)r;
                func_L01_00441FB8(self, 5, -1);
                return;
            }
        }
        break;
    case 5:
        *(u16 *)(self + 0x96) += 1;
        if (*(u16 *)(self + 0x96) >= 0x5B) {
            u8 *r = func_L39_00619838(o->f88);
            if (r != 0 && r[0x1A14] != 0 && func_L40_004235C0(self, r) != 0) {
                *(s32 *)(self + 0x98) = 0;
                *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
                func_L39_005F08F8(self, 1);
                func_L40_00421CA0(self);
                o->f74 = D_001A5F78[0];
                func_L01_00441FB8(self, 6, -1);
            } else {
                func_L01_00441FB8(self, 4, -1);
            }
        }
        break;
    case 6:
    default:
        break;
    }
}
/* localdecomp:end func_L40_00422C58 */
