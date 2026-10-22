#include "common.h"

typedef struct S_351E18o {
    u8 pad0[0x10];
    s32 x10;
} S_351E18o;
typedef struct S_351E18m {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    f32 x18;
    u8 pad1c[4];
    u8 x20;
    u8 pad21[3];
    S_351E18o *x24;
    u8 pad28[8];
    u8 x30;
    u8 x31;
    u8 pad32[2];
    u8 x34;
    u8 pad35[0x33];
    struct S_351E18v *x68;
    u8 pad6c[3];
    u8 x6F;
    u8 pad70[0x25];
    u8 x95;
    u8 pad96[2];
    s32 x98;
    u8 pad9c[0x16];
    s16 xB2;
} S_351E18m;
typedef struct S_351E18v {
    u8 pad0[0x30];
    f32 x30;
    u8 pad34[0x0A];
    u8 x3E;
    u8 pad3f[0x1F];
    u8 x5E;
    u8 x5F;
    u8 pad60[0x1E0];
    s32 x240;
    u8 pad244[0x8C];
    s32 x2D0;
    f32 x2D4;
    s32 x2D8;
    f32 x2DC;
    u8 pad2e0[0x30];
    u8 x310[0x30];
    unsigned long x340;
    u8 pad348[0x9C];
    s32 x3E4;
    u8 pad3e8[8];
    S_351E18m *x3F0[8];
    u8 pad410[0x1D4];
    s32 x5E4;
} S_351E18v;
typedef struct {
    u8 p0[0xAA];
    s16 h170;
} T_352978;
typedef struct {
    u8 p0[0x47];
    u8 b71;
    T_352978 *target;
    u8 p4C[0x430];
    s32 w1148;
} V_352978;
typedef struct {
    u8 p0[0x68];
    V_352978 *pVar;
} M_352978;
typedef struct {
    u8 pad0[0x2E8];
    s32 x2E8;
    u8 pad2EC[0x2F8 - 0x2EC];
    s32 x2F8;
} V_00352B58;
typedef struct {
    u8 pad0[33];
    u8 x21;
    u8 pad22[104 - 34];
    V_00352B58 *x68;
    u8 pad6C[170 - 108];
    s16 xAA;
} M_00352B58;
typedef struct {
    void (*f0)(u8 *);
    void (*f4)(u8 *);
} Cls_00352C58;

LINKER_REMNANT("asm/levels", func_L01_003500B8);

/* localdecomp:start func_L01_003500C0 */
void func_L01_003500C0(void) {

}
/* localdecomp:end func_L01_003500C0 */

INCLUDE_ASM("asm/levels", func_L01_003500C8);

INCLUDE_ASM("asm/levels", func_L01_00350590);

LINKER_REMNANT("asm/levels", func_L01_00350650);

INCLUDE_ASM("asm/levels", func_L01_00350658);

LINKER_REMNANT("asm/levels", func_L01_00350678);

INCLUDE_ASM("asm/levels", func_L01_00350688);

INCLUDE_ASM("asm/levels", func_L01_003506B8);

INCLUDE_ASM("asm/levels", func_L01_003506E0);

INCLUDE_ASM("asm/levels", func_L01_00350750);

/* localdecomp:start func_L01_00352950 */
extern void func_L01_00353880_00352950(s32 a);
extern void func_L01_003536A0(M_00352B58 *o);
extern void func_L01_003534C0(M_352978 *m);
extern s32 func_L01_00352E60(S_351E18m *m);
extern void func_003C7C38(S_351E18m *m);
extern f32 func_L01_0040E548(void *a, void *b);
extern void func_L01_004472C0(S_351E18m *m);
extern void func_L01_00315900(S_351E18m *m, s32 a, void *b);
extern void func_L01_00452860(S_351E18m *m, void *a, s32 b);
extern s32 func_L01_00452F78(S_351E18m *m, s32 a, s32 b, s32 c);
extern void func_L01_00456BD0(S_351E18m *m, s32 a);
extern void func_L01_00456C98(S_351E18m *m, s32 a1, f32 f12, f32 f13, void *a2, s32 a3, s32 t0, s32 t1, f32 f14, s32 t2, s32 t3, s32 s0, s32 s8);
extern s32 D_001D545C;
extern s32 D_L01_001DFB40;
extern u8 D_L01_001E2A40[];
s32 func_L01_00352950(S_351E18m *m) {
    S_351E18v *v = m->x68;
    s32 i;
    s32 j;

    if (m->x20 == 0 && func_L01_00352E60(m) != 0) {
        return 1;
    }
    if (v->x30 > 0.0f) {
        for (i = 0; i < 8; i++) {
            if (v->x3F0[i] != 0) {
                v->x3F0[i]->x98 = v->x3F0[i]->x24->x10;
                func_003C7C38(v->x3F0[i]);
            }
        }
    }
    if ((m->x34 ^ 1) & 1) {
        if (m->x31 != 0 && func_L01_0040E548(D_L01_001E2A40, &m->x10) < 576.0f) {
            func_L01_004472C0(m);
            m->x6F = 22;
        }
    }
    if (v->x3E == 2) {
        ((void (*)(S_351E18m *m))func_L01_003534C0)(m);
        return 1;
    }
    if (m->x18 <= 79.0f && v->x240 != 0 && D_001D545C == 1) {
        ((void (*)(S_351E18m *m))func_L01_003534C0)(m);
        func_L01_00315900(m, 0, ((void (*)(void))func_L01_00353880_00352950));
        return 1;
    }
    if (m->x10 < 2.0f || m->x10 > 1021.0f || m->x14 < 2.0f || m->x14 > 1021.0f || m->x18 < 2.0f || m->x18 > 1021.0f) {
        return 1;
    }
    func_L01_00452860(m, &v->x30, 0);
    if (func_L01_00452F78(m, 0, 0, 0) != 0) {
        for (j = 0; j < 8; j++) {
            if (v->x3F0[j] != 0) {
                v->x3F0[j]->x98 = 0;
                func_003C7C38(v->x3F0[j]);
            }
        }
        ((void (*)(S_351E18m *m))func_L01_003536A0)(m);
    }
    if (v->x5E != 0) {
        ((void (*)(S_351E18m *m))func_L01_003534C0)(m);
        return 1;
    }
    if (((*(unsigned long *)&m->x30 & 0x104100000000UL) != 0x4100000000UL || m->x98 != 0) && v->x30 > 0.0f && m->x95 != 0) {
        if (v->x5F != 0) {
            func_L01_00456BD0(m, 5);
        } else if (D_001D545C != 9 || (u8)(m->x95 - 3) < 2) {
            func_L01_00456BD0(m, 3);
        }
    }
    if ((m->xB2 + 8) % 8 != D_L01_001DFB40 % 8) {
        return 0;
    }
    if (v->x5F != 0) {
        if (m->x95 == 1) {
            func_L01_00456C98(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 3, 0, 0, 0);
        } else {
            func_L01_00456C98(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 3, 0, 0, 0);
        }
    } else if (m->x95 == 1 || (m->x95 == 7 && (v->x340 & 0xFFFFFFFF00000000UL))) {
        if (v->x3E4 != 0) {
            func_L01_00456C98(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 2, 0, 0, 0);
        } else {
            func_L01_00456C98(m, v->x2D0, v->x2D4, 10.0f, v->x310, 0, 0, 0, 1.0f, 1, v->x5E4 != 0, 0, 0);
        }
    } else {
        if (v->x3E4 != 0) {
            func_L01_00456C98(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 2, 0, 0, 0);
        } else {
            func_L01_00456C98(m, v->x2D8, v->x2DC, 10.0f, v->x310, 0, 0, 0, 1.0f, 1, v->x5E4 != 0, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00352950 */

INCLUDE_ASM("asm/levels", func_L01_00352E60);

/* localdecomp:start func_L01_003534C0 */



extern s32 D_001D545C;
extern s32 D_L01_001D67AC;
extern s32 D_L01_001D67B4;
extern s32 D_L01_001D67C0;
extern void func_L01_00459C50(s32 id);
extern void func_L01_004443E8(M_352978 *m, s32 a, s32 b);

void func_L01_003534C0(M_352978 *m) {
    V_352978 *v = m->pVar;

    if (v->w1148 == 0) {
        func_L01_004443E8(m, 0, 3);
    }
    if (D_001D545C == 4 && v->target != 0 &&
        (v->target->h170 == 6238 || v->target->h170 == 4545)) {
        if (++D_L01_001D67AC >= 25) {
            func_L01_00459C50(6);
        }
    } else if (D_001D545C == 12 && v->target != 0 && v->b71 == 9) {
        if (++D_L01_001D67B4 >= 20) {
            func_L01_00459C50(15);
        }
    } else if (D_001D545C == 18 && v->target != 0 &&
               (v->target->h170 == 6238 || v->target->h170 == 4545)) {
        if (++D_L01_001D67C0 >= 20) {
            func_L01_00459C50(21);
        }
    }
}
/* localdecomp:end func_L01_003534C0 */

/* localdecomp:start func_L01_003535F0 */
extern void func_003C7C38(S_351E18m *m);
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L01_003535F0(u8 *self) {
    u8 *v = *(u8 **)(self + 104);
    u8 **list;
    s32 i;

    func_0038CAD0(v + 736);
    list = (u8 **)(v + 1008);
    func_0038CB00(v + 740);
    for (i = 0; i < 8; i++) {
        if (list[i] != 0) {
            *(s32 *)(list[i] + 152) = 0;
            ((void (*)(u8 *))func_003C7C38)(list[i]);
        }
    }
    if (*(u16 *)(self + 150) < 0xFFFF) {
        *(u16 *)(self + 150) += 1;
    }
    func_L01_00451DF8(self, v + 592, 2, 1, 2.5f);
}
/* localdecomp:end func_L01_003535F0 */

/* localdecomp:start func_L01_003536A0 */


extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;

extern void func_L01_00456230(M_00352B58 *, s32);

void func_L01_003536A0(M_00352B58 *o) {
    u16 *p;
    M_00352B58 *m;

    if (o->x21 == 255) {
        return;
    }
    func_L01_00456230(o, 1);
    p = D_L01_0021DE20[o->x21];
    while (o->x21 != 255 && o->x21 <= D_L01_001E0058 && p != 0
           && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[o->x21])) {
        m = (M_00352B58 *)(D_L01_001E001C + ((*p & 0x7FFF) << 8));
        if (m == 0) {
            return;
        }
        if (m->xAA == o->xAA) {
            m->x68->x2E8 = 1;
        } else if (m->xAA == 5861) {
            m->x68->x2F8 = 1;
        } else if (m->xAA == 5860) {
            m->x68->x2F8 = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L01_003536A0 */

/* localdecomp:start func_L01_003537A0 */

extern Cls_00352C58 *func_L01_0043B548(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_003C2880(u8 *);

void func_L01_003537A0(u8 *a0, s32 a1) {
    u8 *v = *(u8 **)(a0 + 104);
    if (*(s32 *)(v + 576) != 0) {
        Cls_00352C58 *c = func_L01_0043B548(6625, 108);
        c->f0(a0);
        if (a1 != 0) {
            c->f4(a0);
        }
    } else if (*(s32 *)(v + 1148) != 0) {
        if (a0[67] != 0) {
            func_003C3A10(a0, 0, 0, 0);
        }
        func_L01_004450F0(a0, 18, 7);
        *(s32 *)(a0 + 152) = 0;
        *(u16 *)(a0 + 52) = (*(u16 *)(a0 + 52) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L01_003537A0 */

/* localdecomp:start func_L01_00353880 */
extern void func_L01_003537A0_00353880(u8 *a0, s32 a1);
void func_L01_00353880(s32 a) {
    ((s32 * (*)())func_L01_003537A0_00353880)(a, 1);
}
/* localdecomp:end func_L01_00353880 */

INCLUDE_ASM("asm/levels", func_L01_003538A0);

INCLUDE_ASM("asm/levels", func_L01_00353970);

/* localdecomp:start func_L01_00353A78 */
void func_L01_00353A78(u8 *a) {
    *(int *)(*(u8 **)(a + 104) + 840) = 0;
}
/* localdecomp:end func_L01_00353A78 */

INCLUDE_ASM("asm/levels", func_L01_00353A88);

/* localdecomp:start func_L01_00353BA8 */
extern void func_003C3A10(u8 *a0, s32 a1, s32 a2, s32 a3);
void func_L01_00353BA8(u8 *a0, u8 *a1) {
    u8 *p = *(u8 **)(a1 + 104);
    u8 *d = *(u8 **)(a0 + 104);
    u8 *q = *(u8 **)(*(u8 **)(d + 584) + 104);
    s32 v;
    *(s32 *)(d + 720) = *(s32 *)(p + 0);
    if (*(f32 *)(p + 4) > 0.0f) {
        *(f32 *)(d + 724) = *(f32 *)(p + 4);
    }
    *(s32 *)(d + 728) = *(s32 *)(p + 8);
    if (*(f32 *)(p + 12) > 0.0f) {
        *(f32 *)(d + 732) = *(f32 *)(p + 12);
    }
    *(s32 *)(d + 824) = *(s32 *)(p + 16);
    *(s32 *)(d + 828) = *(s32 *)(p + 24);
    *(s32 *)(d + 832) = *(s32 *)(p + 28);
    *(s32 *)(d + 1508) = *(s32 *)(p + 136);
    *(s16 *)(d + 838) = 0;
    *(s16 *)(d + 836) = 0;
    v = *(s32 *)(q + 120);
    if (v != 0) {
        if (v == 2) {
            *(s16 *)(d + 838) = 1;
        } else {
            *(s16 *)(d + 836) = 1;
        }
    }
    if (a0[67] != 0) {
        func_003C3A10(a0, 0, 0, 0);
    }
}
/* localdecomp:end func_L01_00353BA8 */

/* localdecomp:start func_L01_00353C68 */
f32 func_L01_00353C68(void) {
    return 0.4f;
}
/* localdecomp:end func_L01_00353C68 */

/* localdecomp:start func_L01_00353C80 */
extern void func_L01_003537A0_00353C80(u8 *a0, s32 a1);
extern void func_L01_00353C80(void *p);
extern void func_L01_00353C80(void *);

 
void func_L01_00353C80(void *p) {
    ((void (*)(void *, s32))func_L01_003537A0_00353C80)(p, 0);
}
/* localdecomp:end func_L01_00353C80 */

INCLUDE_ASM("asm/levels", func_L01_00353CA0);

/* localdecomp:start func_L01_00353DC8 */
extern f32 func_L01_0040E548(void *a, void *b);

s32 func_L01_00353DC8(u8 *a0, u8 *a1) {
    s32 r = 0;
    if (a1 != 0 && a0 != 0 && *(s16 *)(a1 + 170) == 5947) {
        if (((f32 (*)(u8 *a0, u8 *a1))func_L01_0040E548)(a1 + 16, a0 + 16) < 25.0f) {
            r = a1[67] == 18;
        }
    }
    return r;
}
/* localdecomp:end func_L01_00353DC8 */

LINKER_REMNANT("asm/levels", func_L01_00353E50);

INCLUDE_ASM("asm/levels", func_L01_00353E58);
