#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

INCLUDE_ASM("asm/levels", func_L39_006AE3D8);

/* localdecomp:start func_L39_006AE8F8 */
typedef struct {
    s32 f0;
    u8 pad4[0x1D - 4];
    u8 name[0xEC - 0x1D];
    u8 fEC;
    u8 padED[0x1F0 - 0xED];
} P_006AE8F8;
typedef struct {
    s32 v[4];
} U_006AE8F8;
typedef struct {
    u8 pad0[0x2D8];
    u8 f2D8[4];
    u8 names[4][0x20];
    s32 f35C[4];
    u8 pad36C[0x10];
    s32 f37C[4];
    u8 pad38C[8];
    s32 f394;
} O_006AE8F8;
extern P_006AE8F8 D_001FC6B0[];
extern u8 D_L39_00248BB0[];
extern U_006AE8F8 D_L39_00248BB8;
extern u8 D_L39_00248BC8[];
extern u8 *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern u32 func_00120884(u8 *);
extern void func_00120D28(u8 *, u8 *, s32);
extern s32 func_001205B0(u8 *, u8 *);

void func_L39_006AE8F8(O_006AE8F8 *self, s32 all, s32 idx) {
    u8 buf[32];
    s32 count = -1;
    s32 i;
    s32 k;
    s32 n;
    s32 m;
    s32 j;

    if (all) {
        for (i = 0; i < 4; i++) {
            if (self->f2D8[i] && self->f37C[i] == -1) {
                func_00120048(self->names[i], D_L39_00248BB0, func_00381FF0(0x1424), i + 1);
                self->f35C[i] = 0;
            }
        }
        for (j = 0; j < 8; j++) {
            if (D_001FC6B0[j].fEC) {
                count++;
            }
        }
        self->f394 = count + 1;
    }
    if (idx != -1) {
        if (self->f37C[idx] == -1) {
            func_00120048(self->names[idx], D_L39_00248BB0, func_00381FF0(0x1424), idx + 1);
            self->f35C[idx] = 0;
        } else {
            for (k = 0; k < 8; k++) {
                if (D_001FC6B0[k].fEC) {
                    U_006AE8F8 used = D_L39_00248BB8;
                    count++;
                    for (n = 3; n >= 0; n--) {
                        if (n > 0) {
                            if (func_00120884(D_001FC6B0[k].name) >= 14) {
                                func_00120D28(buf, D_001FC6B0[k].name, 16);
                                func_00120048(buf + 13, D_L39_00248BC8, n + 1);
                            } else {
                                func_00120048(buf, D_L39_00248BB0, D_001FC6B0[k].name, n + 1);
                            }
                        } else {
                            func_00120D28(buf, D_001FC6B0[k].name, 16);
                        }
                        buf[15] = 0;
                        for (m = 0; m < 4; m++) {
                            if (func_001205B0(buf, self->names[m]) == 0) {
                                used.v[n] = 0;
                                m = 4;
                            }
                        }
                    }
                    if (self->f2D8[idx] && self->f37C[idx] == count) {
                        for (m = 0; m < 4; m++) {
                            if (used.v[m]) {
                                if (m > 0) {
                                    if (func_00120884(D_001FC6B0[k].name) >= 14) {
                                        func_00120D28(self->names[idx], D_001FC6B0[k].name, 16);
                                        func_00120048(self->names[idx] + 13, D_L39_00248BC8, m + 1);
                                    } else {
                                        func_00120048(self->names[idx], D_L39_00248BB0, D_001FC6B0[k].name, m + 1);
                                    }
                                } else {
                                    func_00120D28(self->names[idx], D_001FC6B0[k].name, 16);
                                }
                                break;
                            }
                        }
                        self->names[idx][15] = 0;
                        self->f35C[idx] = D_001FC6B0[k].f0;
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006AE8F8 */

INCLUDE_ASM("asm/levels", func_L39_006AED18);

/* localdecomp:start func_L39_006AEF20 */
void func_L39_006AEF20(u8 *a0) {
    OBJ_006AEF20 *obj = *(OBJ_006AEF20 **)(a0 + 0x11C);
    obj->vt->f20(obj, 3, 0);
    obj = *(OBJ_006AEF20 **)(a0 + 0x11C);
    obj->vt->f4C(obj, 0x40, 1);
}
/* localdecomp:end func_L39_006AEF20 */

INCLUDE_ASM("asm/levels", func_L39_006AEF70);

/* localdecomp:start func_L39_006AF070 */
extern u8 D_1A5CD0[];
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern s32 D_002404C0;
__asm__(".extern D_002404C0, 16");
typedef struct S_006AF070 {
    u8 pad0[0xF0];
    s16 fF0;
    u8 pad1[0x174 - 0xF2];
    s32 f174;
    s32 f178;
    s16 f17C;
} S_006AF070;
extern S_006AF070 *D_00241640;
__asm__(".extern D_00241640, 16");
typedef struct Vt_006AF070 {
    u8 pad0[0xF0];
    void (*fF0)(void *);
} Vt_006AF070;
typedef struct Obj_006AF070 {
    u8 pad0[0x60];
    Vt_006AF070 *f60;
} Obj_006AF070;
extern s32 func_L39_006CC238(s32, s32);
extern void func_L39_006CC2A8(s32, void *, s32);
extern void func_199A20(void);
extern void func_L39_00689A70(void);
extern void func_L39_0059A578(s32, s32);
extern int func_19D510(void);

void func_L39_006AF070(Obj_006AF070 *self)
{
    u8 *g = D_1A5CD0;
    s32 r;
    s32 v;

    r = func_L39_006CC238(3, *(s32 *)(g + 0x5F4));
    if (r < 8) {
        func_L39_006CC2A8(3, g + 0x5F4, r + 8);
    }
    D_00241640->fF0 = 7;
    D_00241640->f174 = *(s32 *)(g + 0x128) + 600;
    func_199A20();
    self->f60->fF0(self);
    func_L39_00689A70();
    *(s32 *)(g + 0x130) = *D_00241120;
    D_00241640->f178 = *D_00241120;
    v = D_00241640->f17C;
    if (*D_00241120 >= 2 && v <= 45) {
        v += 10;
    }
    func_L39_0059A578(v, 0);
    D_002404C0 = func_19D510();
}
/* localdecomp:end func_L39_006AF070 */

LINKER_REMNANT("asm/levels", func_L39_006AF160);

INCLUDE_ASM("asm/levels", func_L39_006AF168);

LINKER_REMNANT("asm/levels", func_L39_006AF2E8);

/* localdecomp:start func_L39_006AF2F0 */
extern u8 D_L39_0047DEA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AF2F0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DEA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AF2F0 */
