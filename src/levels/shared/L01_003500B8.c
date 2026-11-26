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

typedef struct { char pad[0x20]; unsigned char flag; char pad2[0x47]; char *p; } S;

/* localdecomp:start func_L01_003500C0 */
void func_L01_003500C0(void) {

}
/* localdecomp:end func_L01_003500C0 */

/* localdecomp:start func_L01_003500C8 */
#include "vu0.h"
typedef struct { f32 f[4]; } F4_3500C8;
typedef struct { f32 f[2]; } F2_3500C8;
typedef struct {
    u8 p0[0x10]; vu0_v4 pos; u8 p20[3]; u8 b23; u8 p24[0x10]; u16 h34; u8 p36[0x62]; s32 w98;
} M_3500C8;
typedef struct {
    u8 p0[0x31]; u8 b31;
} M31_3500C8;
typedef struct {
    f32 f0; s32 w4; M_3500C8 *w8; u8 bC; u8 bD; s8 bE; u8 bF;
} S_3500C8;
extern F4_3500C8 D_L01_001DD450;
extern F2_3500C8 D_L01_001DD460[];
extern F2_3500C8 D_L01_001DD468[];
extern F4_3500C8 D_L01_001DD470;
extern s32 func_00382468(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern s32 func_L01_0046C470(void *, void *, s32, s32, f32, s32, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_0044E820(void *, s32);
extern void func_0038D308(void *, void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern void func_003C2880(u8 *);

void func_L01_003500C8(u8 *a0) {
    F4_3500C8 A;
    F2_3500C8 B;
    F2_3500C8 C;
    F4_3500C8 Dd;
    vu0_v4 v40;
    vu0_v4 v50;
    S_3500C8 *s;
    f32 f20;
    f32 t;
    s32 c;
    s32 i;
    s32 idx;
    s32 o4;
    s32 o8;
    s32 j4;

    s = *(S_3500C8 **)(a0 + 0x68);
    switch (a0[0x20]) {
    case 0:
        f20 = 0.1f;
        func_003A52A0(func_00382468(2), 0, a0);
        s->w8->h34 &= ~0x41;
        s->w8->h34 |= *(u16 *)(*(u8 **)((u8 *)s->w8 + 0x24) + 0x44) & 0x1000;
        s->w8->w98 = *(s32 *)(*(u8 **)((u8 *)s->w8 + 0x24) + 0x10);
        s->w8->h34 |= 0x100;
        func_0038CF68((u8 *)s->w8 + 0xC0, (u8 *)s->w8 + 0xC0, f20);
        func_0038CF68((u8 *)s->w8 + 0xD0, (u8 *)s->w8 + 0xD0, f20);
        A = D_L01_001DD450;
        B = D_L01_001DD460[0];
        C = D_L01_001DD468[0];
        Dd = D_L01_001DD470;
        if (s->bD != 0) {
            s->f0 = 1.0f;
        } else {
            *(s32 *)&s->f0 = 0;
        }
        if (s->bC == 0) {
            for (i = 0; i < 30; i++) {
                idx = i & 1;
                o4 = idx * 4;
                o8 = idx * 8;
                func_L01_00443B88(&v40, 0.0f, *(f32 *)((u8 *)&C + o4) * (f32)s->bE);
                vec_add_ab(&v40, &v40, &s->w8->pos);
                t = func_003824E0(0.0f, (f32)s->bE + (f32)s->bE);
                v40.z = v40.z + t;
                j4 = (idx * 2 + 1) * 4;
                c = func_0038DBD8(*(s32 *)((u8 *)&A + o8), *(s32 *)((u8 *)&A + j4), func_003824E0(0.0f, 1.0f));
                f20 = *(f32 *)((u8 *)&B + o4);
                f20 = f20 * (f32)s->bE;
                qzero(&v50);
                v50.z = func_003824E0(*(f32 *)((u8 *)&Dd + o8), *(f32 *)((u8 *)&Dd + j4)) * (f32)s->bE * 0.020000001f;
                func_L01_0046C470(&v40, &v50, c, 0x3C, f20, func_00382468(0xFF) & 0xFF, 0, s->bF, 0);
            }
        }
        func_L01_004450F0(a0, 1, -1);
        break;
    case 1:
        s->w8->b23 = (s32)(s->f0 * 127.0f);
        func_L01_0044E820(s->w8, func_0038DBD8(0xF0FF2000, s->w4, s->f0));
        func_0038D308((u8 *)s->w8 + 0xC0, (u8 *)s->w8 + 0xF0);
        func_0038CF68((u8 *)s->w8 + 0xC0, (u8 *)s->w8 + 0xC0, s->f0);
        func_0038CF68((u8 *)s->w8 + 0xD0, (u8 *)s->w8 + 0xD0, s->f0);
        if (s->bD == 0) {
            func_003C4138(&s->f0, 1.0f, 0.040000003f);
            if (s->f0 == 1.0f) {
                s->w8->h34 &= ~0x100;
                s->w8->h34 &= ~2;
                func_L01_0044E820(s->w8, s->w4);
                func_003C2880(a0);
            }
        } else {
            func_003C4138(&s->f0, 0.0f, 0.10000001f);
            if (s->f0 == 0.0f) {
                s->w8->h34 &= ~0x100;
                s->w8->h34 &= ~2;
                func_L01_0044E820(s->w8, s->w4);
                s->w8->h34 |= 1;
                ((M31_3500C8 *)s->w8)->b31 = 0;
                func_003C2880(a0);
            }
        }
        break;
    }
}
/* localdecomp:end func_L01_003500C8 */

/* localdecomp:start func_L01_00350590 */
typedef struct {
    u8 pad0[0x68];
    u8 *p68;
} S_00350590;
typedef struct {
    u8 pad0[0x24];
    s32 w24;
    u8 pad28[4];
    s32 w2C;
} Sm_00350590;
extern void func_L01_00350658(S *);
extern s32 func_003A52A0(s32, s32, void *);
__asm__(".extern D_L01_001DD49C, 4");
extern void *D_L01_001DD49C;
__asm__(".extern D_L01_001D6694, 4");
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001DD4A8, 4");
extern s32 D_L01_001DD4A8;
__asm__(".extern D_L01_001DD4AC, 4");
extern s32 D_L01_001DD4AC;
extern u8 *D_001D52FC;
typedef struct {
    u8 pad0[0x1210];
    s32 w1210;
    u8 pad1214[0x25ED - 0x1214];
    u8 b25ED;
} Sh_00350590;
extern Sh_00350590 D_001A4BE0;

void func_L01_00350590(S_00350590 *a0) {
    Sm_00350590 *m;
    s32 t;

    m = a0->p68;
    func_L01_00350658((S *)a0);
    if (D_L01_001DD49C != 0) {
        if (D_L01_001D6694 == 0) {
            t = *(s32 *)(D_001D52FC + 0x1A4);
            if ((t & D_001A4BE0.w1210) != 0) {
                if (D_L01_001DD4A8 != 1) {
                    if (D_L01_001DD4A8 != 2) {
                        if (D_001A4BE0.b25ED == 0) {
                            if ((t & 8) == 0) {
                                m->w2C = 0;
                                func_003A52A0(3, 0, a0);
                                D_L01_001DD4A8 = 1;
                                D_L01_001DD4AC = 0x25;
                                m->w24 = 0x25;
                            }
                        }
                    }
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00350590 */

LINKER_REMNANT("asm/levels", func_L01_00350650);

/* localdecomp:start func_L01_00350658 */
void func_L01_00350658(S *s)
{
    char *p = s->p;
    if (s->flag == 0) {
        s->flag = 1;
        *(int *)(p + 0x24) = 0;
    }
}
/* localdecomp:end func_L01_00350658 */

LINKER_REMNANT("asm/levels", func_L01_00350678);

/* localdecomp:start func_L01_00350688 */
__asm__(".extern D_L01_001DD49C, 4");
extern void *D_L01_001DD49C;
extern f32 D_L01_001E1A10[] __attribute__((section(".sdata")));

void func_L01_00350688(void) {
    f32 z = 0.0f;
    D_L01_001DD49C = 0;
    D_L01_001E1A10[3] = z;
    D_L01_001E1A10[2] = z;
    D_L01_001E1A10[1] = z;
    D_L01_001E1A10[0] = z;
}
/* localdecomp:end func_L01_00350688 */

/* localdecomp:start func_L01_003506B8 */
__asm__(".extern D_L01_001DD49C, 4");
extern void *D_L01_001DD49C;
extern void func_L01_003E4008_003506B8(void *p);

void func_L01_003506B8(void) {
    func_L01_003E4008_003506B8(D_L01_001DD49C);
    D_L01_001DD49C = 0;
}
/* localdecomp:end func_L01_003506B8 */

/* localdecomp:start func_L01_003506E0 */
/* Ps2EeAs only uses $gp for these if it knows they are small before the use. */
__asm__(".extern D_L01_001DD570, 4");
__asm__(".extern D_L01_001DD578, 4");
__asm__(".extern D_L01_001DD598, 4");
extern s32 D_L01_001DD570;
extern s32 D_L01_001DD578;
extern s32 D_L01_001DD598;

void *func_L01_003506E0(s32 a0, s32 a1, s32 *a2) {
    switch (a1) {
    case 0:
        *a2 = 4;
        return &D_L01_001DD570;
    case 1:
        *a2 = 0x1C;
        return &D_L01_001DD578;
    case 2:
        *a2 = 0xC;
        return &D_L01_001DD598;
    default:
        return 0;
    }
}
/* localdecomp:end func_L01_003506E0 */

/* localdecomp:start func_L01_00350750 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef union { u8 b[0x2A00]; s16 h[0x1500]; u16 uh[0x1500]; s32 i[0xA80]; u32 u[0xA80]; f32 f[0xA80]; u8 *ptr[0xA80]; u128_t q[0x2A0]; } Hero_350750;
typedef union { u8 b[0x600]; s8 c[0x600]; s16 h[0x300]; u16 uh[0x300]; s32 i[0x180]; u32 u[0x180]; f32 f[0x180]; u8 *ptr[0x180]; u128_t q[0x60]; } Obj_350750;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_350750;

extern Hero_350750 D_001A4BE0_00350750;
extern u8 D_001BBC40[];
extern u8 D_0014275B[];
extern u8 D_0014275C[];
extern s32 D_001D545C;
extern s32 D_L01_001D6694_00350750;
extern u8 D_L01_001D66B0[8];
extern u8 D_L01_001E29C0[];
extern u8 *D_L01_001E001C;
extern Obj_350750 *D_L01_001EAA18[];
extern f32 D_L01_002F1510[];
extern f32 D_L01_002F16F0[];
extern f32 D_L01_001DAA30;
extern f32 D_L01_001DAA38;
extern s32 D_L01_001DD5A4;
__asm__(".extern D_L01_001DD5A4, 4");
extern f32 D_L01_001DD4C4;
__asm__(".extern D_L01_001DD4C4, 4");
extern f32 D_L01_001DD4CC;
__asm__(".extern D_L01_001DD4CC, 4");
extern f32 D_L01_001DD4D0;
__asm__(".extern D_L01_001DD4D0, 4");
extern f32 D_L01_001DD4D4;
__asm__(".extern D_L01_001DD4D4, 4");
extern s32 D_L01_001DD4D8;
__asm__(".extern D_L01_001DD4D8, 4");
extern void func_L01_00353880_00350750(s32);

extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern f32 func_00382538(void);
extern f32 *func_00382348(void *);
extern s32 func_0038CAD0_00350750(void *);
extern s32 func_0038CB00_00350750(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_003C2880_00350750(Obj_350750 *);
extern void func_003C2EC0(Obj_350750 *, s32, void *);
extern void func_003C3A10_00350750(Obj_350750 *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern void func_003C41A0(void *, f32, f32, f32, f32, void *);
extern void func_003C7C38_00350750(Obj_350750 *);
extern void func_L01_00315900_00350750(Obj_350750 *, s32, void *);
extern s32 func_L01_00352950_00350750(Obj_350750 *);
extern void func_L01_003534C0_00350750(Obj_350750 *);
extern void func_L01_003535F0_00350750(Obj_350750 *);
extern void func_L01_003537A0_00350750(Obj_350750 *, s32);
extern void func_L01_00353A88_00350750(Obj_350750 *, void *, f32);
extern s32 func_L01_00353DC8_00350750(Obj_350750 *, void *);
extern s32 func_L01_003FB640(void *, s32, Obj_350750 *, f32);
extern void func_L01_00409598(Obj_350750 *, void *, void *, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_0041A4F0(void);
extern f32 func_L01_004395E0(Obj_350750 *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0_00350750(Obj_350750 *, s32, s32);
extern s32 func_L01_00446058(Obj_350750 *, s32, s32);
extern s32 func_L01_00446780(Obj_350750 *, f32, void *, s32, f32, f32, s32, s32, s32);
extern void func_L01_004468C8(Obj_350750 *, f32, f32, f32, s32, s32, s32, s32, s32);
extern void func_L01_00446A70(Obj_350750 *, Obj_350750 *, s32, void *, void *, f32);
extern void func_L01_00448890(void *, f32, f32, f32, f32, void *, s32);
extern void func_L01_0044E318(Obj_350750 *, void *);
extern void func_L01_0044E340(void *, s32, s32, f32);
extern void func_L01_0044E468(void *, s32);
extern void func_L01_0044E740(void *);
extern s32 func_L01_00454370(Obj_350750 *, void *);
extern s32 func_L01_004561B8(Obj_350750 *);
extern s32 func_L01_004561E0(Obj_350750 *);
extern void func_L01_00456230_00350750(Obj_350750 *, s32);
extern s32 func_L01_00456250(void *);
extern s32 func_L01_00456500(void *, s32);
extern void func_L01_00458F78(Obj_350750 *, void *, s32, s32);
extern void func_L01_00459188(Obj_350750 *, void *, void *);
extern void func_L01_004591B8(Obj_350750 *, void *, void *);
extern u8 *func_L01_004592A8(Obj_350750 *, void *, s32, void *);
extern u8 *func_L01_004593B8(Obj_350750 *, void *, void *, void *, void *);
extern void func_L01_0045A748(Obj_350750 *, void *);
extern void func_L01_0045A898(void *, void *, f32);
extern s32 func_L01_0045A9F0(Obj_350750 *);
extern s32 func_L01_0045AA10(Obj_350750 *, f32);
extern s32 func_L01_0045AA30(Obj_350750 *, void *);
extern void func_L01_0045BD78_00350750(Obj_350750 *, f32, f32, f32, f32);
extern s32 func_L01_0045BDE8(Obj_350750 *, s32);
extern void func_L01_004AA7E8_00350750(Obj_350750 *, s32);
extern void func_L01_004AADE8(s32, s32, Obj_350750 *, s32);

void func_L01_00350750(Obj_350750 *m) {
    V4_350750 s10, s20, s30, s40, s50, s60, s70, s80;
    Obj_350750 *pv;

    pv = (Obj_350750 *)m->ptr[0x68 / 4];
    if (pv->i[0x5D8 / 4] != 0 && (D_001BBC40[m->b[0xB0] + D_001D545C * 0x10] & 0x80) && m->b[0x31] == 0) {
        func_003C2880_00350750(m);
        return;
    }
    if (pv->i[0x5D0 / 4] != -1 && m->b[0x95] != 7 && m->b[0x20] != 0) {
        if (func_L01_00456500(D_L01_001E29C0, pv->i[0x5D0 / 4]) == 0) {
            m->i[0x98 / 4] = 0;
            m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & ~0x1000;
            func_L01_004AA7E8_00350750(m, 1);
            return;
        } else {
            Obj_350750 *c = (Obj_350750 *)m->ptr[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
        }
    }
    if ((D_L01_001DD5A4 != 0 || D_0014275C[0] != 0) && pv->i[0x5E0 / 4] == 0) {
        if (func_L01_00446058(m, 0x1BA0, 0x16BD) != 0) {
            if (D_001D545C == 0x10 || D_001D545C == 4 || D_001D545C == 9) {
                pv->h[0x34 / 2] = 6;
                pv->b[0x44] = 0x19;
                if (func_L01_0041A4F0() != 0) {
                    pv->h[0x34 / 2] = (f32)pv->h[0x34 / 2] * (D_001D545C == 7 && D_0014275B[0] != 0 ? D_L01_001DAA30 : D_L01_002F1510[D_001D545C]);
                    pv->b[0x44] = (f32)pv->b[0x44] * (D_001D545C == 7 && D_0014275B[0] != 0 ? D_L01_001DAA38 : D_L01_002F16F0[D_001D545C]);
                }
                pv->b[0x45] = pv->b[0x44];
                pv->b[0x46] = pv->b[0x44];
                pv->f[0x30 / 4] = pv->h[0x34 / 2];
            }
            m->h[0xAA / 2] = 0x16BD;
            pv->i[0x5E0 / 4] = 1;
            m->uh[0x34 / 2] |= 0x1000;
            ((Obj_350750 *)m->ptr[0x24 / 4])->b[0x46] = 5;
        }
    } else if ((D_001D545C == 0xD || D_001D545C == 0x10 || D_001D545C == 0x1D || D_001D545C == 0xC)
               && pv->i[0x5EC / 4] == 0 && D_0014275C[0] == 0) {
        pv->i[0x5EC / 4] = 1;
        func_L01_00446058(m, 0x1ED8, 0x16BD);
        m->h[0xAA / 2] = 0x16BD;
        m->uh[0x34 / 2] |= 0x1000;
        ((Obj_350750 *)m->ptr[0x24 / 4])->b[0x46] = 5;
    }
    if (m->b[0x95] != 4 && pv->f[0x30 / 4] <= 0.0f) {
        m->i[0x98 / 4] = ((Obj_350750 *)m->ptr[0x24 / 4])->i[0x10 / 4];
        func_003C7C38_00350750(m);
        *(u128_t *)&s10 = *(u128_t *)D_L01_001D66B0;
        func_L01_00446A70(m, m, 0x10000, &m->q[1], D_L01_001D66B0, 100.0f);
    }
    if (m->b[0x20] != 0x13) {
        m->f[0x2C / 4] = ((Obj_350750 *)m->ptr[0x24 / 4])->f[0x24 / 4] * pv->f[0x5D4 / 4];
    }
    if (func_L01_00352950_00350750(m) != 0) {
        func_L01_003537A0_00350750(m, 1);
        return;
    }
    *(u128_t *)&s10 = m->q[1];
    if (pv->h[0x234 / 2] == 1 && ((Obj_350750 *)pv->ptr[0x230 / 4])->h[0xAA / 2] == 0x173B) {
        pv->h[0x234 / 2] = 0;
    }
    if (D_L01_001D6694_00350750 == 2) {
        if ((m->b[0x34] ^ 1) & 1) {
            m->i[0x98 / 4] = 0;
            m->uh[0x34 / 2] = (m->uh[0x34 / 2] | 0x41) & ~0x1000;
            func_L01_004AA7E8_00350750(m, 1);
            pv->i[0x5E8 / 4] = 1;
        }
        return;
    }
    if (pv->i[0x5E8 / 4] != 0) {
        Obj_350750 *c = (Obj_350750 *)m->ptr[0x24 / 4];
        m->uh[0x34 / 2] &= 0xFFBE;
        m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
        m->i[0x98 / 4] = c->i[0x10 / 4];
        pv->i[0x5E8 / 4] = 0;
    }

    switch (m->b[0x95]) {
    case 0: {
        u8 *e = D_L01_001E001C + (pv->i[0x334 / 4] << 8);
        if (pv->h[0x346 / 2] == 0 && pv->i[0x2E8 / 4] != 0) {
            m->i[0x98 / 4] = ((Obj_350750 *)m->ptr[0x24 / 4])->i[0x10 / 4];
            func_L01_00353A88_00350750(m, &m->q[1], pv->f[0x350 / 4]);
        } else if (func_L01_00456250(e) != 0) {
            func_L01_004450F0_00350750(m, 4, 1);
            if (m->b[0x43] != 3) {
                func_003C3A10_00350750(m, 3, func_00382498(0, 0xA), 0);
            }
        }
        break;
    }
    case 1: {
        s32 found;

        if (func_L01_004561E0(m) != 0 && pv->h[0x2E6 / 2] == 0) {
            pv->h[0x2E6 / 2] = (func_00382498(0, 0x28) * 5 + 2) / 6;
        }
        found = 0;
        if (pv->i[0x3E0 / 4] == -1) {
            found = 1;
        } else {
            u8 *e = D_L01_001E001C + (pv->i[0x3E0 / 4] << 8);
            f32 *q = func_00382348(e);
            if (e == 0 || e[0x20] == 0xFE) {
                found = 1;
            } else if (e[0x20] == 0xFD) {
                found = 1;
            } else if (q != 0 && *q <= 0.0f) {
                found = 1;
            }
        }
        if (pv->h[0x234 / 2] == 1 && func_0038CB00_00350750(&pv->h[0x2E6 / 2]) != 0 && found) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 8);
            }
            func_L01_004450F0_00350750(m, 8, 3);
            if (pv->i[0x338 / 4] != -1) {
                func_L01_004450F0_00350750(m, 6, -1);
            }
        } else if (pv->i[0x2E8 / 4] != 0 && func_0038CB00_00350750(&pv->h[0x2E6 / 2]) != 0) {
            func_L01_004450F0_00350750(m, m->b[0x20], 2);
            pv->i[0x2E8 / 4] = 0;
            if (pv->i[0x2E0 / 4] < 0xFA) {
                pv->i[0x2E0 / 4] = (func_00382498(0x1E0, 0x258) * 5 + 2) / 6;
            }
        }
        if (func_L01_00353DC8_00350750(m, pv->ptr[0x230 / 4]) != 0) {
            func_L01_004450F0_00350750(m, 0x15, 8);
        }
        break;
    }
    case 2:
        if (pv->h[0x234 / 2] == 1) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 8);
            }
            func_L01_004450F0_00350750(m, 8, 3);
        } else if (pv->i[0x2E0 / 4] == 0) {
            func_L01_004450F0_00350750(m, m->b[0x20], 1);
        }
        if (func_L01_00353DC8_00350750(m, pv->ptr[0x230 / 4]) != 0) {
            func_L01_004450F0_00350750(m, 0x15, 8);
        }
        break;
    case 3:
        if (pv->h[0x234 / 2] != 1 && func_L01_004561E0(m) == 0 && func_00382468(0x1E) == 0) {
            func_L01_004450F0_00350750(m, 4, 2);
            if (m->b[0x43] != 3) {
                func_003C3A10_00350750(m, 3, func_00382468(3), (func_00382498(8, 0xC) * 5 + 2) / 6);
            }
            pv->i[0x2E0 / 4] = (func_00382498(0x30C, 0x384) * 5 + 2) / 6;
        }
        break;
    case 4: {
        s32 r = func_L01_00454370(m, &pv->b[0x160]);
        if (r & 1) {
            func_L01_003534C0_00350750(m);
            func_L01_00315900_00350750(m, 0, func_L01_00353880_00350750);
            return;
        }
        if (r & 2) {
            if (pv->h[0x234 / 2] == 1) {
                if (m->b[0x43] != 4) {
                    func_003C3A10_00350750(m, 4, 0, 8);
                }
                func_L01_004450F0_00350750(m, 8, 3);
            } else {
                if (m->b[0x43] != 0) {
                    func_003C3A10_00350750(m, 0, 0, 8);
                }
                func_L01_004450F0_00350750(m, 7, 2);
                pv->i[0x2E0 / 4] = (func_00382498(0x244, 0x258) * 5 + 2) / 6;
            }
        }
        break;
    }
    case 7:
        if (pv->h[0x346 / 2] != 0
            && ((pv->i[0x334 / 4] != -1 && func_L01_00456250(D_L01_001E001C + (pv->i[0x334 / 4] << 8)) != 0 && func_0038CB00_00350750(&pv->h[0x2E6 / 2]) != 0)
                || (pv->h[0x234 / 2] == 1 && func_0038CB00_00350750(&pv->h[0x2E6 / 2]) != 0))) {
            Obj_350750 *c;
            if (m->b[0x43] != 0) {
                func_003C3A10_00350750(m, 0, func_00382498(0, 0xA), 0);
            }
            func_L01_00456230_00350750(m, 1);
            m->f[0x18 / 4] = func_003C3D30(&m->q[1], 0, 0, 0.5f);
            if (m->b[0x95] == 9) {
                func_L01_004450F0_00350750(m, 0x18, -1);
            } else {
                func_L01_004450F0_00350750(m, 2, 1);
            }
            c = (Obj_350750 *)m->ptr[0x24 / 4];
            m->uh[0x34 / 2] &= 0xFFBE;
            m->uh[0x34 / 2] |= c->uh[0x44 / 2] & 0x1000;
            m->i[0x98 / 4] = c->i[0x10 / 4];
            m->b[0x31] = 0;
            m->uh[0x34 / 2] |= 1;
            func_L01_00409598(m, &m->q[1], &m->b[0xF0], 0, 2, 3, 0x25, 0x25, 0x80FF40, 0x108F10);
        }
        break;
    case 8:
        if (pv->h[0x234 / 2] == 1) {
            func_L01_004450F0_00350750(m, 2, 1);
        }
        break;
    }

    switch (m->b[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if ((m->b[0x60] & 2) && pv->i[0x340 / 4] == 0) {
            func_L01_004450F0_00350750(m, 4, -1);
            if (m->b[0x43] != 3) {
                func_003C3A10_00350750(m, 3, 0, 8);
            }
        }
        break;
    case 3:
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 8);
            }
            func_L01_004450F0_00350750(m, 8, 3);
        }
        break;
    case 4:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x320]);
            pv->f[0x320 / 4] = func_0038D098(a) * r;
            pv->f[0x324 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x320], &pv->b[0x320], &pv->b[0x310]);
            if (pv->i[0x33C / 4] != -1 && func_L01_00456500(&pv->b[0x320], pv->i[0x33C / 4]) == 0) {
                pv->q[0x320 / 16] = pv->q[0x310 / 16];
            }
            pv->i[0x330 / 4] = func_00382498(0x12C, 0x212);
            func_L01_0045BD78_00350750(m, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
        }
        func_L01_0045A898(m, &pv->b[0x320], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x320 / 4] - m->f[0x10 / 4], pv->f[0x324 / 4] - m->f[0x14 / 4]),
                          0.00181514258f, 0.00181514258f, 0.0349065885f, &pv->b[0x30C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x320]) < 0.75f) {
            f32 a = func_00382538();
            f32 r = func_003824E0(2.0f, 6.0f);
            qzero(&pv->b[0x320]);
            pv->f[0x320 / 4] = func_0038D098(a) * r;
            pv->f[0x324 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x320], &pv->b[0x320], &pv->b[0x310]);
            if (pv->i[0x33C / 4] != -1 && func_L01_00456500(&pv->b[0x320], pv->i[0x33C / 4]) == 0) {
                pv->q[0x320 / 16] = pv->q[0x310 / 16];
            }
        }
        if (func_0038CAD0_00350750(&pv->b[0x330]) != 0) {
            if (m->b[0x43] != func_00382468(2) + 1) {
                func_003C3A10_00350750(m, func_00382468(2) + 1, 0, 8);
            }
            func_L01_004450F0_00350750(m, 2, -1);
        }
        break;
    case 5:
        if (func_L01_004561B8(m) != 0) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.0174532924f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x2F0]);
            pv->f[0x2F0 / 4] = func_0038D098(a) * r;
            pv->f[0x2F4 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x2F0], &m->q[1], &pv->b[0x2F0]);
            func_L01_0045BD78_00350750(m, 0.00219999999f, 0.0300000012f, 0.00181514258f, 0.125663713f);
        }
        func_L01_0045A898(m, &pv->b[0x2F0], m->f[0xF8 / 4]);
        func_L01_00448890(&m->f[0xF8 / 4], func_0038D160(pv->f[0x2F0 / 4] - m->f[0x10 / 4], pv->f[0x2F4 / 4] - m->f[0x14 / 4]),
                          0.00181514258f, 0.00181514258f, 0.0349065885f, &pv->b[0x30C], 0);
        if (func_0038CF38(&m->q[1], &pv->b[0x2F0]) < 0.75f) {
            f32 a = func_0038DAB8(m->f[0xF8 / 4], func_L01_00443A18(60.0f, 80.0f) * 0.0174532924f);
            f32 r = func_003824E0(3.0f, 4.0f);
            qzero(&pv->b[0x2F0]);
            pv->f[0x2F0 / 4] = func_0038D098(a) * r;
            pv->f[0x2F4 / 4] = func_0038D0B0(a) * r;
            vec_add_ab(&pv->b[0x2F0], &m->q[1], &pv->b[0x2F0]);
        }
        if (pv->h[0x234 / 2] == 1
            && (func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 1.91986215f
                || D_001A4BE0_00350750.f[0x174 / 4] > 0.0300000012f)) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 5);
            }
            func_L01_004450F0_00350750(m, 8, -1);
        }
        break;
    case 6:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0045BD78_00350750(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        func_L01_0045BD78_00350750(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        if (func_L01_0045BDE8(m, pv->i[0x338 / 4]) != 0 || func_0038CF38(&m->q[1], &pv->b[0x220]) < 6.0f) {
            func_L01_004450F0_00350750(m, 8, -1);
        }
        break;
    case 8:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x308 / 4] = func_L01_00443A18(0.0f, 15.0f) * 0.0174532924f;
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x360]);
            func_L01_0045BD78_00350750(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        if (pv->ptr[0x230 / 4] != pv->ptr[0x3B0 / 4]) {
            func_L01_00459188(m, pv->ptr[0x230 / 4], &pv->b[0x360]);
        }
        func_L01_00458F78(m, &pv->b[0x360], 0, 0);
        func_L01_0045A748(m, &pv->b[0x360]);
        if (pv->f[0x120 / 4] < pv->f[0x98 / 4] * 0.8f) {
            pv->i[0x3A0 / 4]++;
        }
        *(u128_t *)&s20 = m->q[1];
        s20.z += 0.600000024f;
        if (D_001A4BE0_00350750.i[0x25CC / 4] != 0x12 && func_0038CF38(&m->q[1], &pv->b[0x220]) < 1.0f
            && func_0038DBA0(m->f[0xF8 / 4], func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
            func_L01_004450F0_00350750(m, 0xA, -1);
            if (m->b[0x43] != 0xC) {
                func_003C3A10_00350750(m, 0xC, 0, 8);
            }
        }
        if (func_L01_003FB640(&s20, 1, m, 0.600000024f) != 0 && D_L01_001EAA18[0] != 0
            && D_L01_001EAA18[0] == (Obj_350750 *)pv->ptr[0x230 / 4] && (u8 *)D_L01_001EAA18[0] != D_001A4BE0_00350750.ptr[0x25C0 / 4]) {
            func_L01_004450F0_00350750(m, 0xA, -1);
            if (m->b[0x43] != 0xC) {
                func_003C3A10_00350750(m, 0xC, 0, 8);
            }
        }
        if (func_0038CF38(&m->q[1], &pv->b[0x220]) < 2.5f) {
            pv->f[0x308 / 4] = 0.0f;
        }
        if (fabs_asm(m->f[0x18 / 4] - pv->f[0x228 / 4]) > 4.0f && D_001A4BE0_00350750.i[0x360 / 4] != 0 && pv->i[0x478 / 4] != 0) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 8);
            }
            func_L01_004450F0_00350750(m, 0xF, -1);
        }
        break;
    case 15:
        if (func_L01_004561B8(m) != 0) {
            u8 *n;
            pv->i[0x474 / 4] = 0;
            pv->i[0x470 / 4] = 0;
            n = func_L01_004592A8(m, &pv->b[0x410], pv->i[0x3E8 / 4], &pv->b[0x440]);
            pv->ptr[0x3EC / 4] = n;
            *(u128_t *)&s20 = *(u128_t *)(n + 0x10);
            func_L01_004591B8(m, &s20, &pv->b[0x360]);
            func_L01_0045BD78_00350750(m, 0.00480000023f, 0.0800000057f, 0.0100530973f, 0.251327425f);
        }
        if (pv->i[0x474 / 4] == 0) {
            func_L01_00458F78(m, &pv->b[0x360], 0, 0);
            func_L01_0045A748(m, &pv->b[0x360]);
        } else {
            if (pv->i[0x3A0 / 4] >= 9) {
                func_L01_004450F0_00350750(m, 8, -1);
                if (m->b[0x43] != 4) {
                    func_003C3A10_00350750(m, 4, 0, 8);
                }
            }
            func_L01_0045A748(m, pv->ptr[0x3EC / 4] + 0x10);
        }
        if (func_0038CF38(&m->q[1], pv->ptr[0x3EC / 4] + 0x10) <= 1.5f) {
            pv->i[0x474 / 4] = 1;
            *(u128_t *)&s20 = pv->q[0x220 / 16];
            pv->ptr[0x3EC / 4] = func_L01_004593B8(m, pv->ptr[0x3EC / 4], &pv->b[0x440], &pv->b[0x470], &s20);
            if (pv->ptr[0x3EC / 4] == 0) {
                func_L01_004450F0_00350750(m, 8, -1);
                if (m->b[0x43] != 4) {
                    func_003C3A10_00350750(m, 4, 0, 8);
                }
            }
        }
        break;
    case 10: {
        f32 t = func_L01_004395E0(m);
        if (t > 6.0f && t < 10.0f && m->b[0x42] == 0xC) {
            *(u128_t *)&s20 = m->q[1];
            if (pv->b[0x5F] != 0) {
                func_L01_004468C8(m, 0.5f, (f32)pv->b[0x44], 0.75f, 1, 0x10000, 0, 1, 0);
            } else {
                func_L01_004468C8(m, 0.5f, (f32)pv->b[0x44], 0.75f, 1, 1, 0, 1, 0);
            }
        }
        if (m->b[0x60] & 2) {
            func_L01_004450F0_00350750(m, 0xC, -1);
            if (m->b[0x43] != 6) {
                func_003C3A10_00350750(m, 6, 1, 3);
            }
        }
        break;
    }
    case 12:
        if (func_L01_004561B8(m) != 0) {
            pv->f[0x2F8 / 4] = m->f[0x18 / 4];
        }
        if (m->b[0x42] == 6) {
            f32 t = func_L01_004395E0(m);
            if (t > 2.0f && t < 18.0f) {
                func_0038CF68(&s40, &m->b[0xC0], -0.0843750015f);
                vec_add_ba(&s20, &m->q[1], &s40);
            }
            if (t > 2.0f && t < 12.0f) {
                func_003C41A0(&s20.z, pv->f[0x2F8 / 4] + 1.0f, 0.1f, 0.2f, 0.1f, &pv->b[0x300]);
            }
            if (t == 12.0f) {
                pv->f[0x300 / 4] = 0.0f;
            }
            if (t > 12.0f && t < 18.0f) {
                func_003C41A0(&s20.z, func_003C3D30(&m->q[1], 0, 0, 0.5f), 0.027777778f, 0.333333343f, 0.25f, &pv->b[0x300]);
            }
            if (t > 2.0f && t < 18.0f) {
                vec_sub_ab(&s30, &s20, &m->q[1]);
                func_L01_0045AA30(m, &s30);
            } else {
                func_L01_0045AA10(m, m->f[0xF8 / 4]);
            }
            if (m->b[0x60] & 2) {
                if (func_00382468(0xA) == 0) {
                    if (m->b[0x43] != 9) {
                        func_003C3A10_00350750(m, 9, 0, 7);
                    }
                    func_L01_004450F0_00350750(m, 0xD, -1);
                } else {
                    func_L01_004450F0_00350750(m, 8, -1);
                    if (m->b[0x43] != 4) {
                        func_003C3A10_00350750(m, 4, 0, 5);
                    }
                }
            }
        }
        break;
    case 13:
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x60] & 2) {
            func_L01_004450F0_00350750(m, 8, -1);
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 5);
            }
        }
        break;
    case 11:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2E6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x42] == 1) {
            f32 a;
            func_003C2EC0(m, 0, &s50);
            a = func_0038D160(s70.x, s70.y);
            if (func_0038DBA0(a, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
                pv->h[0x2E6 / 2] = m->uh[0x96 / 2] + 5;
            }
            if ((pv->h[0x2E6 / 2] != 0 && m->uh[0x96 / 2] == pv->h[0x2E6 / 2]) || D_001A4BE0_00350750.f[0x174 / 4] > 0.040000003f) {
                if (m->b[0x43] != 4) {
                    func_003C3A10_00350750(m, 4, 0, 5);
                }
                func_L01_004450F0_00350750(m, 8, -1);
            }
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 2) {
                func_003C3A10_00350750(m, 2, 0, 5);
            }
            func_L01_004450F0_00350750(m, 0xE, -1);
        }
        /* falls through: no break in the original */
    case 14:
        if (func_L01_004561B8(m) != 0) {
            pv->h[0x2E6 / 2] = 0;
        }
        func_L01_0045AA10(m, m->f[0xF8 / 4]);
        if (m->b[0x42] == 2) {
            f32 a;
            func_003C2EC0(m, 0, &s20);
            a = func_0038D160(s40.x, s40.y);
            if (func_0038DBA0(a, func_0038D160(pv->f[0x220 / 4] - m->f[0x10 / 4], pv->f[0x224 / 4] - m->f[0x14 / 4])) < 0.436332315f) {
                pv->h[0x2E6 / 2] = m->uh[0x96 / 2] + 5;
            }
            if (pv->h[0x234 / 2] == 1
                && ((pv->h[0x2E6 / 2] != 0 && m->uh[0x96 / 2] == pv->h[0x2E6 / 2]) || D_001A4BE0_00350750.f[0x174 / 4] > 0.040000003f)) {
                if (m->b[0x43] != 4) {
                    func_003C3A10_00350750(m, 4, 0, 5);
                }
                func_L01_004450F0_00350750(m, 8, -1);
            }
        }
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 3) {
                func_003C3A10_00350750(m, 3, 0, 3);
            }
            func_L01_004450F0_00350750(m, 5, -1);
        }
        break;
    case 21:
        if (func_L01_004561B8(m) != 0 && m->b[0x43] != 0) {
            func_003C3A10_00350750(m, 0, 0, 8);
        }
        func_L01_0045AA10(m, func_0038D160(((Obj_350750 *)pv->ptr[0x230 / 4])->f[0x10 / 4] - m->f[0x10 / 4], ((Obj_350750 *)pv->ptr[0x230 / 4])->f[0x14 / 4] - m->f[0x14 / 4]));
        if (func_L01_00353DC8_00350750(m, pv->ptr[0x230 / 4]) == 0) {
            func_L01_004450F0_00350750(m, 0x16, -1);
        }
        break;
    case 22: {
        Obj_350750 *t;
        if (m->b[0x43] != 9) {
            func_003C3A10_00350750(m, 9, 0, 8);
        }
        t = (Obj_350750 *)pv->ptr[0x230 / 4];
        func_L01_0045AA10(m, func_0038D160(t->f[0x10 / 4] - m->f[0x10 / 4], t->f[0x14 / 4] - m->f[0x14 / 4]));
        if (m->b[0x60] & 2) {
            if (m->b[0x43] != 0) {
                func_003C3A10_00350750(m, 0, 0, 5);
            }
            func_L01_004450F0_00350750(m, 0x17, -1);
        }
        break;
    }
    case 23:
        func_L01_004450F0_00350750(m, 2, 1);
        break;
    case 19: {
        Obj_350750 *o;
        if (func_L01_004561B8(m) != 0) {
            pv->i[0xA8 / 4] |= 0x400;
        }
        if (pv->f[0x34C / 4] < 1.0f) {
            pv->f[0x34C / 4] += D_L01_001DD4C4;
            if (pv->f[0x34C / 4] > 1.0f) {
                pv->f[0x34C / 4] = 1.0f;
            }
            m->f[0x2C / 4] = ((Obj_350750 *)m->ptr[0x24 / 4])->f[0x24 / 4] * pv->f[0x34C / 4] * pv->f[0x5D4 / 4];
        }
        pv->f[0x118 / 4] -= 0.00392000005f;
        pv->f[0x110 / 4] *= 0.988000035f;
        pv->f[0x114 / 4] *= 0.988000035f;
        if (pv->f[0x118 / 4] < -0.540000021f) {
            pv->f[0x118 / 4] = -0.540000021f;
        }
        if (pv->ptr[0x348 / 4] != 0) {
            ((Obj_350750 *)pv->ptr[0x348 / 4])->i[0x98 / 4] = 0;
        }
        func_L01_0045AA30(m, &pv->b[0x110]);
        if ((o = (Obj_350750 *)pv->ptr[0x348 / 4]) != 0) {
            o->i[0x98 / 4] = ((Obj_350750 *)o->ptr[0x24 / 4])->i[0x10 / 4];
        }
        if (m->f[0x18 / 4] - func_003C3D30(&m->q[1], 0, 0, 0.5f) < 0.25f) {
            func_L01_0045A9F0(m);
            func_L01_004450F0_00350750(m, 0x14, -1);
        }
        break;
    }
    case 20:
        if (func_L01_004561B8(m) != 0) {
            if (m->b[0x43] != 5) {
                func_003C3A10_00350750(m, 5, 0, 8);
            }
            pv->i[0xA8 / 4] &= ~0x400;
        }
        func_L01_0045A9F0(m);
        if (m->b[0x60] & 2) {
            func_L01_004450F0_00350750(m, 8, 3);
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, func_00382498(0, 0xA), 0);
            }
        }
        break;
    case 24: {
        f32 t;
        if (func_L01_004561B8(m) != 0) {
            if (m->b[0x43] != 4) {
                func_003C3A10_00350750(m, 4, 0, 5);
            }
            pv->f[0x300 / 4] = 0.0800000057f;
        }
        pv->f[0x300 / 4] += D_L01_001DD4D0;
        t = 1.0f - (pv->f[0x300 / 4] + 0.0800000057f) / 0.160000011f;
        *(u128_t *)&s30 = pv->q[0x2F0 / 16];
        *(u128_t *)&s40 = pv->q[0x320 / 16];
        func_003C4098(&s20, &s30, &s40, t);
        s20.z = m->f[0x18 / 4] + pv->f[0x300 / 4];
        m->f[0xF4 / 4] = t * 1.57079637f;
        vec_sub_ab(&s30, &s20, &m->q[1]);
        func_L01_0045AA30(m, &s30);
        if (t >= 1.0f) {
            func_L01_004450F0_00350750(m, 0x19, -1);
        }
        break;
    }
    case 25:
        if (func_L01_004561B8(m) != 0) {
            m->q[1] = pv->q[0x320 / 16];
            m->f[0xF4 / 4] = 1.57079637f;
            if (func_00382468(0xA) == 0) {
                if (m->b[0x43] != 9) {
                    func_003C3A10_00350750(m, 9, 0, 5);
                }
            } else if (m->b[0x43] != 0xB) {
                func_003C3A10_00350750(m, 0xB, 0, 5);
            }
            pv->f[0x328 / 4] = func_003C3D30(&pv->b[0x320], 0, 0, 0.5f);
            func_L01_0044E318(m, &pv->b[0x480]);
            func_L01_0044E340(&pv->b[0x480], 0x20, 1, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 0x18, 2, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 0x10, 3, D_L01_001DD4D4);
            func_L01_0044E340(&pv->b[0x480], 8, 4, D_L01_001DD4D4);
            if (D_001D545C == 0xD) {
                func_L01_004AADE8(0x13, 0, m, 0);
            }
        }
        pv->f[0x300 / 4] += D_L01_001DD4D0;
        if (pv->f[0x300 / 4] < D_L01_001DD4CC) {
            pv->f[0x300 / 4] = D_L01_001DD4CC;
        }
        qzero(&s20);
        s20.z = pv->f[0x300 / 4];
        func_L01_0045AA30(m, &s20);
        func_L01_0044E468(&pv->b[0x480], D_L01_001DD4D8);
        s30.x = func_0038D098(m->f[0xF8 / 4]) * 0.5f;
        s30.y = func_0038D0B0(m->f[0xF8 / 4]) * 0.5f;
        s30.z = 0.0f;
        vec_add_ba(&s30, &s30, &m->q[1]);
        if (func_L01_00446780(m, 0.5f, &s30, 0x2000001, 1.0f, 1.0f, 0, 1, 0) != 0
            && (u8 *)D_L01_001EAA18[0] == D_001A4BE0_00350750.ptr[0x25C0 / 4]) {
            D_001A4BE0_00350750.h[0x1DE / 2] = 0x32;
        }
        if (m->f[0x18 / 4] <= pv->f[0x328 / 4]) {
            func_L01_004450F0_00350750(m, 0x1A, -1);
        }
        break;
    case 26:
        if (func_L01_004561B8(m) != 0) {
            func_L01_0044E740(&pv->b[0x480]);
            func_L01_00315900_00350750(m, 0, func_L01_00353880_00350750);
        }
        break;
    }
    vec_sub_ab(&s20, &s10, &m->q[1]);
    if (func_0038CEA8(&s20) < pv->f[0x98 / 4] * 0.5f) {
        pv->i[0x3A0 / 4]++;
    } else {
        pv->i[0x3A0 / 4]--;
    }
    func_L01_003535F0_00350750(m);
}
/* localdecomp:end func_L01_00350750 */

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

/* localdecomp:start func_L01_00352E60 */
typedef int u128_00352E60 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x34];
    u16 x34;
    u8 pad36[0x62];
    s32 x98;
    u8 pad9C[0x0E];
    s16 xAA;
    u8 padAC[0x54];
} E_00352E60;
extern s32 func_00382498(s32, s32);
extern void func_L01_00459218(u8 *, u8 *, s32, u8 *);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_0045BD78(u8 *, f32, f32, f32, f32);
extern Cls_00352C58 *func_L01_0043B548(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_L01_004AA7E8(u8 *, s32);
extern s32 D_001D545C;
extern u8 *D_L01_001E001C;
extern u8 *D_L01_001E0020;

typedef struct {
    u8 pad0[0x17C];
    f32 f17C, f180, f184, f188, f18C;
    u8 pad190[0x10];
    f32 f1A0;
    u8 pad1A4[5];
    u8 b1A9;
    s16 h1AA;
    u8 pad1AC[0x2C];
    u8 b1D8, b1D9, b1DA, b1DB;
} T_00352E60;

s32 func_L01_00352E60(S_351E18m *m) {
    u8 *obj = (u8 *)m;
    u8 *p = *(u8 **)(obj + 0x68);
    T_00352E60 *state = (T_00352E60 *)p;
    E_00352E60 *e;
    s32 i;
    s32 k;
    f32 a, b, r;
    Cls_00352C58 *t;
    u8 **w;
    u8 *c1;
    u8 *c2;
    if (func_00382468(2)) {
        *(u16 *)(obj + 0x34) |= 0x8000;
    }
    obj[0x30] = 0x40;
    i = 0;
    c1 = p + 0x410;
    c2 = p + 0x3E8;
    r = func_003824E0(1.25f, 1.5f);
    w = (u8 **)(p + 0x3F0);
    *(f32 *)(p + 0x5D4) = r;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24) * r;
    *(s16 *)(p + 0x5DC) = 0x19;
    *(s16 *)(p + 0x5DE) = 0;
    for (k = 7; k >= 0; k--) {
        w[k] = 0;
    }
    for (e = (E_00352E60 *)D_L01_001E001C; (u8 *)e < D_L01_001E0020; e++) {
        if (e->xAA == 0x1BAF || e->xAA == 0x1BBE || e->xAA == 0x1E8D) {
            w[i] = (u8 *)e;
            e->x98 = 0;
            e->x34 = (e->x34 | 0x41) & 0xEFFF;
            func_L01_004AA7E8((u8 *)e, 1);
            i++;
            if (i >= 8) {
                break;
            }
        }
    }
    if (*(s32 *)(p + 0x240) != 0 && D_001D545C == 1) {
        *(s32 *)(p + 0x478) = D_001D545C;
    } else {
        *(s32 *)(p + 0x478) = 0;
    }
    *(s32 *)(p + 0x3E8) = 0;
    func_L01_00459218(obj, c1, 12, c2);
    *(u128_00352E60 *)(p + 0x2F0) = *(u128_00352E60 *)(obj + 0x10);
    *(u128_00352E60 *)(p + 0x310) = *(u128_00352E60 *)(obj + 0x10);
    *(f32 *)(p + 0x308) = func_L01_00443A18(0.0f, 15.0f) * 0.01745329238474369f;
    p[0x170] = 0x10;
    p[0x1A8] = 4;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(f32 *)(p + 0x19C) = 0.15f;
    p[0x1D7] = 1;
    if (func_00382468(2)) {
        p[0x176] = 7;
        p[0x1D3] = 0x11;
        p[0x1D2] = 0xB;
    } else {
        p[0x176] = 8;
        p[0x1D3] = 0x13;
        p[0x1D2] = 0xA;
    }
    state->f17C = 0.3f;
    state->f180 = 0.020000001415610313f;
    state->f184 = 0.010000000707805157f;
    state->f188 = 0.014000000432133675f;
    state->f18C = 0.000800000037997961f;
    state->b1DA = 4;
    state->b1DB = 0xFF;
    state->b1D8 = 0;
    state->b1D9 = 0;
    state->b1A9 = 1;
    state->f1A0 = m->x18 - 10.0f;
    if (D_001D545C == 12) {
        state->h1AA = 0x280B;
    }
    b = 0.5f;
    a = 1.0f;
    *(f32 *)(p + 0x78) = b;
    *(f32 *)(p + 0x7C) = a;
    *(f32 *)(p + 0x70) = 0.4f;
    *(f32 *)(p + 0x74) = 0.25f;
    *(f32 *)(p + 0x80) = 1.3962633609771729f;
    *(f32 *)(p + 0xA0) = 0.3490658402442932f;
    *(f32 *)(p + 0x9C) = 0.002f;
    func_L01_0045BD78(obj, 0.004800000227987766f, 0.08000000566244125f, 0.005026548635214567f, 0.12566371262073517f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = a;
        *(s16 *)(p + 0x34) = 1;
    }
    *(f32 *)(p + 0x40) = b;
    p[0x38] = 0;
    p[0x39] = 1;
    p[0x3E] = 1;
    p[0x5E] = 0;
    p[0x5F] = 0;
    *(s32 *)(p + 0x2E0) = 0;
    *(s16 *)(p + 0x2E4) = 0;
    *(s16 *)(p + 0x2E6) = 0;
    *(s32 *)(p + 0x2E8) = 0;
    *(s32 *)(p + 0x330) = 0;
    if (*(s32 *)(p + 0x47C) != 0) {
        p[0x3F] = 0;
        p[0x64] = 0;
    }
    if (*(f32 *)(p + 0x2DC) < *(f32 *)(p + 0x2D4)) {
        *(f32 *)(p + 0x2DC) = *(f32 *)(p + 0x2D4) + *(f32 *)(p + 0x2D4);
    }
    if (*(s32 *)(p + 0x240) != 0) {
        obj[0x62] = 0;
    }
    if (D_001D545C == 1) {
        s32 h = *(s16 *)(obj + 0xB2);
        if (h == 10) {
            obj[0x62] = 0;
        } else if (h == 12 || h == 14 || h == 16 || h == 0x255 || h == 0x256) {
            obj[0x62] = 0;
        }
    }
    if (*(s32 *)(p + 0x240) > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(p + 0x240) = -1;
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0);
        }
        p[0x24E] = 0x11;
        p[0x24F] = 5;
        t->f0(obj);
    } else if (*(s16 *)(p + 0x346) != 0 || *(s32 *)(p + 0x47C) != 0) {
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, 0, 0);
        }
        func_L01_004450F0(obj, 0x12, 7);
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
        *(s16 *)(p + 0x2E6) = 0xF;
    } else if (*(s16 *)(p + 0x344) != 0) {
        func_L01_004450F0(obj, 0x12, 7);
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
    } else if (*(s32 *)(p + 0x334) != -1) {
        func_L01_004450F0(obj, 1, 0);
        if (obj[0x43] != 0) {
            func_003C3A10(obj, 0, func_00382498(0, 10), 0);
        }
    } else {
        func_L01_004450F0(obj, 4, 1);
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, func_00382498(0, 10), 0);
        }
        if (*(s32 *)(p + 0x340) != 0) {
            s32 x = func_00382498(0, 7);
            if (obj[0x43] != 2) {
                func_003C3A10(obj, 2, x << 1, 0);
            }
            func_L01_004450F0(obj, 2, -1);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00352E60 */

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

/* localdecomp:start func_L01_003538A0 */
typedef struct {
    u8 pad0[0x20];
    u8 x20;
    u8 pad21[0xAA - 0x21];
    s16 xAA;
} M_003538A0;
extern s32 D_L01_001E0058_003538A0;
__asm__(".extern D_L01_001E0058_003538A0, 16");
extern u8 *D_L01_001E001C_003538A0;
__asm__(".extern D_L01_001E001C_003538A0, 16");

M_003538A0 *func_L01_003538A0(s32 id) {
    u16 *p;
    M_003538A0 *m;

    p = D_L01_0021DE20[id];
    if ((id & 0xFF) != 0xFF && id <= D_L01_001E0058_003538A0 && p != 0) {
        do {
            m = (M_003538A0 *)(D_L01_001E001C_003538A0 + ((*p & 0x7FFF) << 8));
            if (m == 0) {
                break;
            }
            if (m->xAA == 0x16BD && m->x20 == 0x12) {
                return m;
            }
            p++;
            if ((id & 0xFF) == 0xFF || id > D_L01_001E0058_003538A0 || p == 0) {
                break;
            }
        } while ((s16)p[-1] >= 0 || p == D_L01_0021DE20[id]);
    }
    return 0;
}
/* localdecomp:end func_L01_003538A0 */

/* localdecomp:start func_L01_00353970 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_353970;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_353970;
typedef struct Q_353970 { char p0[0x24]; C_353970 *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P_353970 *f68; char p6c[0x2c]; s32 f98; } Q_353970;
typedef struct { char p0[0x10]; W4_353970 f10; char p1[0xa0]; W4_353970 fC0; char p2[0x20]; W4_353970 fF0; } R_353970;
typedef struct P_353970 { char p0[0xF8]; s32 f0F8; s32 f0FC; s32 f100; char p1[0x14]; f32 f118; char p2[0x2C]; s32 f148; char p3[0x1FC]; s32 f348; f32 f34C; } P_353970;
extern f32 D_L01_001DD4C0; __asm__(".extern D_L01_001DD4C0, 4");
extern f32 D_L01_001DD4B0; __asm__(".extern D_L01_001DD4B0, 4");
extern f32 D_L01_001DD4B4; __asm__(".extern D_L01_001DD4B4, 4");
extern void func_0038D308(void *a, void *b);
extern void func_0038CE20(f32 f, void *a, void *b);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3938(void *o, s32 a, s32 b);

void func_L01_00353970(Q_353970 *a0, W4_353970 *a1, s32 a2, f32 f) {
    W4_353970 v;
    P_353970 *p;
    qzero(&v);
    p = a0->f68;
    v.z = f;
    ((R_353970 *)a0)->f10 = *a1;
    ((R_353970 *)a0)->fF0 = v;
    func_0038D308((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f34C = D_L01_001DD4C0;
    a0->f2c = a0->f24->f24 * D_L01_001DD4C0 * *(f32 *)((char *)p + 0x5D4);
    p->f348 = a2;
    func_0038CE20(D_L01_001DD4B0, (char *)p + 0x110, (char *)a0 + 0xC0);
    p->f118 = D_L01_001DD4B4;
    p->f148 = -1;
    p->f100 = 0;
    p->f0F8 = 0;
    p->f0FC = 0;
    qzero((char *)p + 0xC0);
    func_L01_004450F0(a0, 0x13, 6);
    func_003C3938(a0, 9, 0);
}
/* localdecomp:end func_L01_00353970 */

/* localdecomp:start func_L01_00353A78 */
void func_L01_00353A78(u8 *a) {
    *(int *)(*(u8 **)(a + 104) + 840) = 0;
}
/* localdecomp:end func_L01_00353A78 */

/* localdecomp:start func_L01_00353A88 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) W4_353A88;
typedef struct { char p0[0x10]; s32 f10; char p1[0x10]; f32 f24; char p2[0x1c]; u16 f44; } C_353A88;
typedef struct Q_353A88 { char p0[0x24]; C_353A88 *f24; char p28[4]; f32 f2c; char p30[4]; u16 f34; char p36[0x32]; struct P_353A88 *f68; char p6c[0x2c]; s32 f98; } Q_353A88;
typedef struct { char p0[0x10]; W4_353A88 f10; char p1[0xa0]; W4_353A88 fC0; char p2[0x20]; W4_353A88 fF0; } R_353A88;
typedef struct P_353A88 { char p0[0xF8]; s32 f0F8; s32 f0FC; f32 f100; char p1[0x14]; f32 f118; char p2[0x2C]; s32 f148; char p3[0x1FC]; s32 f348; f32 f34C; } P_353A88;
extern f32 D_L01_001DD4C8; __asm__(".extern D_L01_001DD4C8, 4");
extern f32 D_L01_001DD4B8; __asm__(".extern D_L01_001DD4B8, 4");
extern f32 D_L01_001DD4BC; __asm__(".extern D_L01_001DD4BC, 4");
extern void func_0038D308(void *a, void *b);
extern void func_0038CE20(f32 f, void *a, void *b);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C3938(void *o, s32 a, s32 b);

void func_L01_00353A88(Q_353A88 *a0, W4_353A88 *a1, f32 f) {
    W4_353A88 v;
    P_353A88 *p;
    f32 z = 0.0f;
    qzero(&v);
    p = a0->f68;
    v.z = f;
    ((R_353A88 *)a0)->f10 = *a1;
    ((R_353A88 *)a0)->fF0 = v;
    func_0038D308((char *)a0 + 0xC0, &v);
    a0->f34 = (a0->f34 & 0xFFBE);
    a0->f34 |= a0->f24->f44 & 0x1000;
    a0->f98 = a0->f24->f10;
    p->f34C = D_L01_001DD4C8;
    a0->f2c = a0->f24->f24 * D_L01_001DD4C8 * *(f32 *)((char *)p + 0x5D4);
    p->f348 = 0;
    func_0038CE20(D_L01_001DD4B8, (char *)p + 0x110, (char *)a0 + 0xC0);
    p->f118 = D_L01_001DD4BC + func_L01_00443A18(z, 0.03f);
    p->f148 = -1;
    p->f100 = z;
    p->f0F8 = 0;
    p->f0FC = 0;
    qzero((char *)p + 0xC0);
    func_L01_004450F0((u8 *)a0, 0x13, 6);
    func_003C3938(a0, 9, 0);
}
/* localdecomp:end func_L01_00353A88 */

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

/* localdecomp:start func_L01_00353CA0 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V353CA0;

extern s32 func_00382498(s32, s32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L01_004450F0_00353CA0(u8 *, s32, s32);
extern void func_L01_00409598_00353CA0(void *, void *, void *, s32, s32, s32, s32, s32, s32, s32);

void func_L01_00353CA0(u8 *a0, V353CA0 *a1) {
    u8 *m;
    V353CA0 *p = (V353CA0 *)(a0 + 0x10);
    V353CA0 t = *a1;

    *p = t;
    *(u16 *)(a0 + 0x34) &= 0xFFBC;
    m = *(u8 **)(a0 + 0x24);
    *(u16 *)(a0 + 0x34) |= *(u16 *)(m + 0x44) & 0x1000;
    *(s32 *)(a0 + 0x98) = *(s32 *)(m + 0x10);
    if (a0[0x43] != 0) {
        func_003C3A10(a0, 0, func_00382498(0, 10), 0);
    }
    *(f32 *)(a0 + 0x18) = func_003C3D30(p, 0, 0, 0.5f);
    if (a0[0x95] == 9) {
        func_L01_004450F0_00353CA0(a0, 0x18, -1);
    } else {
        func_L01_004450F0_00353CA0(a0, 2, 1);
    }
    a0[0x31] = 0;
    *(u16 *)(a0 + 0x34) |= 1;
    func_L01_00409598_00353CA0(a0, a0 + 0x10, a0 + 0xF0, 0, 2, 3, 0x25, 0x25, 0x80FF40, 0x108F10);
}
/* localdecomp:end func_L01_00353CA0 */

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

/* localdecomp:start func_L01_00353E58 */
__asm__(".extern D_L01_001DD5F0, 8");
__asm__(".extern D_L01_001DD610, 8");
extern int D_L01_001DD5F0[2];
extern int D_L01_001DD610[2];

void *func_L01_00353E58(int a0, int sel, int *out) {
    switch (sel) {
    case 1:
        *out = 0x1C;
        return D_L01_001DD5F0;
    case 2:
        *out = 0xC;
        return D_L01_001DD610;
    }
    return 0;
}
/* localdecomp:end func_L01_00353E58 */
