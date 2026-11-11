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

/* localdecomp:start func_L39_006AE3D8 */
typedef struct {
    u8 pad0[0x1C4];
    s32 f1C4;
    u8 pad1C8[0x558 - 0x1C8];
    u8 f558;
    u8 pad559[0x5C0 - 0x559];
} PAD_006AE3D8;
typedef struct {
    u8 pad0[0x50];
    u8 f50_0 : 6;
    u8 f50_6 : 1;
    u8 f50_7 : 1;
    u8 pad51[0x1F0 - 0x51];
} P_006AE3D8;
typedef struct {
    u8 names[8][16];
    u8 pad80[0x40];
    u16 fC0[8];
    u16 fD0[8];
    u8 padE0[0x180 - 0xE0];
    s32 f180;
    u8 pad184[0x19D - 0x184];
    s8 f19D;
} G_006AE3D8;
typedef struct {
    u8 pad0[0x2A8];
    s32 f2A8[4];
    s32 f2B8[8];
    u8 f2D8[4];
    u8 names[4][0x20];
    s32 f35C[4];
    s32 f36C[4];
    s32 f37C[4];
    s32 f38C;
    s32 f390;
    s32 f394;
} O_006AE3D8;
extern PAD_006AE3D8 D_00225780[];
extern PAD_006AE3D8 *D_L39_00241170[4] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00241640, 16");
extern G_006AE3D8 *D_L39_00241640;
__asm__(".extern D_L39_00241120, 16");
extern s32 *D_L39_00241120;
extern G_006AE3D8 *D_001D5F30_sda;
extern P_006AE3D8 D_001FC6B0_006AE3D8[];
extern void func_L39_006AE8F8_006AE3D8(O_006AE3D8 *, s32, s32);
extern void func_001206F4(u8 *, u8 *);
extern void func_L39_0059A660(s32, s32);

void func_L39_006AE3D8(O_006AE3D8 *self) {
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 m;
    s32 q;
    s32 count = 0;

    for (i = 0; i < 4; i++) {
        if (self->f2D8[i]) {
            PAD_006AE3D8 *pad = &D_00225780[self->f2A8[i]];
            count++;
            if ((pad->f1C4 & 0x10) || !pad->f558) {
                self->f2D8[i] = 0;
                count--;
                self->f2B8[self->f2A8[i]] = -1;
                self->f2A8[i] = -1;
            } else if (pad->f1C4 & 1) {
                s32 b7 = 0;
                s32 b6 = 0;
                if (self->f37C[i] >= 0) {
                    b6 = D_001FC6B0_006AE3D8[self->f37C[i]].f50_6;
                    b7 = D_001FC6B0_006AE3D8[self->f37C[i]].f50_7;
                }
                self->f35C[i]--;
                if (!b6 && self->f35C[i] == 0x12) {
                    self->f35C[i]--;
                }
                if (self->f35C[i] < 0) {
                    if (b7) {
                        self->f35C[i] = self->f38C - 1;
                    } else {
                        self->f35C[i] = self->f38C - 2;
                    }
                }
            } else if (pad->f1C4 & 2) {
                s32 b7 = 0;
                s32 b6 = 0;
                if (self->f37C[i] >= 0) {
                    b6 = D_001FC6B0_006AE3D8[self->f37C[i]].f50_6;
                    b7 = D_001FC6B0_006AE3D8[self->f37C[i]].f50_7;
                }
                self->f35C[i]++;
                if (!b6 && self->f35C[i] == 0x12) {
                    self->f35C[i]++;
                }
                if (!b7 && self->f35C[i] == 0x15) {
                    self->f35C[i] = 0x16;
                }
                if (self->f35C[i] >= self->f38C) {
                    self->f35C[i] = 0;
                }
            } else if (pad->f1C4 & 4) {
                if (D_L39_00241640->f180 != 2 || D_L39_00241640->f19D != 0) {
                    self->f36C[i]--;
                    if (self->f36C[i] < 0) {
                        self->f36C[i] = self->f390 - 1;
                    }
                }
            } else if (pad->f1C4 & 8) {
                if (D_L39_00241640->f180 != 2 || D_L39_00241640->f19D != 0) {
                    self->f36C[i]++;
                    if (self->f36C[i] >= self->f390) {
                        self->f36C[i] = 0;
                    }
                }
            } else if (pad->f1C4 & 0x8000) {
                self->f37C[i]--;
                if (self->f37C[i] < -1) {
                    self->f37C[i] = self->f394 - 1;
                }
                func_L39_006AE8F8_006AE3D8(self, 0, i);
            } else if (pad->f1C4 & 0x2000) {
                self->f37C[i]++;
                if (self->f37C[i] >= self->f394) {
                    self->f37C[i] = -1;
                }
                func_L39_006AE8F8_006AE3D8(self, 0, i);
            }
        }
    }
    if (count < 4) {
        for (j = 0; j < 8; j++) {
            if (self->f2B8[j] < 0) {
                PAD_006AE3D8 *pad = &D_00225780[j];
                if (pad->f558 && (pad->f1C4 & 0x20)) {
                    for (k = 0; k < 4; k++) {
                        if (!self->f2D8[k]) {
                            break;
                        }
                    }
                    self->f2D8[k] = 1;
                    self->f2A8[k] = j;
                    self->f2B8[j] = k;
                    count++;
                }
            }
        }
    }
    n = 0;
    for (m = 0; m < 4; m++) {
        if (self->f2D8[m]) {
            G_006AE3D8 *g = D_001D5F30_sda;
            D_L39_00241170[n] = &D_00225780[self->f2A8[m]];
            g->fC0[n] = self->f35C[m];
            g->fD0[n] = self->f36C[m];
            func_001206F4(g->names[n], self->names[m]);
            if (self->f37C[m] >= 0) {
                func_L39_0059A660(self->f37C[m], m);
            }
            n++;
        }
    }
    for (q = n; q < 8; q++) {
        if (q < 4) {
            D_L39_00241170[q] = 0;
        }
        D_L39_00241640->fC0[q] = 0;
        D_L39_00241640->fD0[q] = 0;
        D_L39_00241640->names[q][0] = 0;
    }
    *D_L39_00241120 = count;
}
/* localdecomp:end func_L39_006AE3D8 */

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
