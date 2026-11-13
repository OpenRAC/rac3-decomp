#include "common.h"

/* localdecomp:start func_L39_0053DA40 */
typedef struct {
    u8 pad[136];
    s32 f88[1];
} S_352C4C_0053DA40;
typedef struct { u32 w0; s32 w4; } M_0053DA40;
typedef struct {
    u8 p0[0x1C]; s32 f1C; u8 p20[0x20]; s32 f40; u8 p44[0x24]; s32 f68; u8 p6C[0x40]; s32 fAC; u8 pB0[8]; s32 fB8; s32 fBC;
} O_0053DA40;
extern S_352C4C_0053DA40 *D_L39_00352B4C[];
extern s32 D_L39_00352950[];
extern void func_L39_00662B18(M_0053DA40 *, void *, s32);
extern void func_L39_0055D948(s32, s32);

void func_L39_0053DA40(u8 *a0, M_0053DA40 *m) {
    O_0053DA40 *o = *(O_0053DA40 **)(a0 + 0x68);
    s32 buf;
    switch (m->w0 & 0xF) {
    case 0:
        o->f40 = 1;
        break;
    case 1:
        func_L39_00662B18(m, &buf, 4);
        if (o->f68 == -1 || m->w4 + (s32)(m->w0 >> 13) < o->f68) {
            D_L39_00352950[0] = buf;
            o->f68 = m->w4 + (s32)(m->w0 >> 13);
        }
        break;
    case 2:
        func_L39_0055D948(o->fAC, D_L39_00352B4C[0]->f88[o->f1C]);
        o->fBC = 0;
        o->fB8++;
        break;
    }
}
/* localdecomp:end func_L39_0053DA40 */

/* localdecomp:start func_L39_0053DB28 */
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x47];
    u8 *f68;
} Obj_0053DB28;
typedef struct {
    u8 pad0[0x40];
    s32 f40;
    u8 pad44[0x68];
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    s32 fBC;
} Cur_0053DB28;
typedef struct {
    u8 pad0[0x180];
    s32 f180;
} Glob_0053DB28;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0x89];
    s16 fAA;
    u8 padAC[0x54];
} Ent_0053DB28;
extern Glob_0053DB28 *D_L39_00241640;
extern Ent_0053DB28 *D_L39_0024BF5C;
extern s32 func_L01_00445AD0(s32, s32, s32);
extern s32 func_L39_0053D8E8_0053DB28(s32);
extern void func_L39_0053D910(s32);
extern s32 func_L39_0053D938_0053DB28(s32);
extern void func_L39_0053D960(u8 *);
extern s32 func_L39_0053D9E8(s32);
extern void func_L39_0053DA10(s32);

s32 func_L39_0053DB28(Obj_0053DB28 *a0, s32 a1) {
    Cur_0053DB28 *p;
    if (a1 == 0 && a0->f20 == 2) {
        p = (Cur_0053DB28 *)a0->f68;
        if (p->f40 == 0) {
            if (!func_L01_00445AD0(p->fB0, 5, 0)) {
                if (!func_L39_0053D8E8_0053DB28((s32)a0)) {
                    func_L39_0053D910((s32)a0);
                }
            }
        } else {
            if (D_L39_00241640->f180 == 0 && p->fB4 >= 0) {
                Ent_0053DB28 *e = (Ent_0053DB28 *)((p->fB4 << 8) + (s32)D_L39_0024BF5C);
                if (e->fAA == 0x1C57 && e->f20 == a0->f20) {
                    if (!func_L39_0053D938_0053DB28((s32)a0)) func_L39_0053D960((u8 *)a0);
                }
            }
            if (!func_L01_00445AD0(p->fAC, 7, 0)) {
                if (p->fBC >= (s32)((f32)(p->fB8 * 10 + 30) * 50.0f)) {
                    if (!func_L39_0053D9E8((s32)a0)) {
                        func_L39_0053DA10((s32)a0);
                    }
                }
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0053DB28 */

/* localdecomp:start func_L39_0053DC78 */
typedef struct {
    u8 pad0[4];
    f32 f4;
    f32 f8;
    u8 padC[0xC];
    s32 f18;
    s32 f1C;
    u8 pad20[4];
    s32 f24;
    u8 pad28[0x18];
    s32 f40;
    s32 f44[4][2];
    u8 pad64[4];
    s32 f68;
    u8 pad6C[8];
    s32 f74;
    s32 f78;
    u8 pad7C[0x14];
    s32 f90[6];
    u8 padA8[4];
    s32 fAC;
    s32 fB0;
    s32 fB4;
    s32 fB8;
    s32 fBC;
    s32 fC0;
    s32 fC4;
    u8 padC8[0x54];
    s32 f11C;
    u8 pad120[0x30];
    s32 f150[4][2];
    s32 f170[6];
    s32 f188;
    s32 f18C;
    s32 f190;
} S_0053DC78;

typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[0xF];
    u8 f30;
    u8 pad31;
    s16 f32;
    u8 pad34[0x34];
    S_0053DC78 *f68;
} O_0053DC78;

typedef struct {
    u8 pad0[0x40];
    s32 f40[8];
    u8 pad60[0x28];
    s32 f88[8];
    u8 padA8[0x60];
    f32 f108[8];
    f32 f128[8];
    f32 f148[8];
} E_0053DC78;

typedef struct {
    u8 pad[0x20C];
    E_0053DC78 *f20C;
} T_0053DC78;

typedef struct {
    u8 pad0[0x180];
    s32 f180;
    u8 pad184[0xC];
    s8 f190;
    s8 f191;
    s8 pad192[2];
    s8 f194;
} G_0053DC78;

typedef struct {
    u8 pad0[4];
    s16 f4;
} P_0053DC78;

__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_00241120, 16");
__asm__(".extern D_L39_0024BF5C, 16");
extern s32 *D_L39_00241120;
extern T_0053DC78 D_L39_00352940;
extern s16 *D_L39_002927E0[];
extern s32 D_L39_0024BF98;
extern u8 *D_L39_0024BF5C_0053DC78;

extern void func_L01_00404808(void *, void *);
extern void func_003C2880(void *);
extern s32 func_L39_0066C828(void *, s32, s32);
extern f32 func_L39_005B44C8(void);
extern P_0053DC78 *func_00382348(void *);
extern void func_L01_00451F60(s32, s32, s32);
extern s32 func_0038CAD0(void *);
extern u8 *func_L39_0061BF38(s32);
extern void func_L39_0053E300(void);
extern s32 func_L01_00445AD0(s32, s32, s32);

void func_L39_0053DC78(O_0053DC78 *a0) {
    S_0053DC78 *s = a0->f68;
    s32 i;
    s32 j;
    s32 idx;

    if (a0->f20 != 0) {
        func_L01_00404808(func_L39_0053E300, a0);
    }
    if (a0->f20 == 0) {
        if (((G_0053DC78 *)D_L39_00241640)->f190 == 0) {
            func_003C2880(a0);
            return;
        }
        func_L39_0066C828(a0, -1, 1);
        a0->f20 = 1;
        a0->f30 = 0xFF;
        a0->f32 = 0x1FF;
        s->f18 = 0;
        s->f4 = func_L39_005B44C8();
        s->f8 = func_L39_005B44C8();
        s->fC0 = 500;
        s->fC4 = 1;
        s->fB8 = 0;
        idx = 0;
        for (i = 0; i < 8; i++) {
            if ((u8 *)D_L39_0024BF5C + (D_L39_00352940.f20C->f40[i] << 8) == (u8 *)a0) {
                idx = i;
                break;
            }
        }
        D_L39_00352940.f20C->f108[idx] = 100.0f;
        D_L39_00352940.f20C->f148[idx] = 100.0f;
        D_L39_00352940.f20C->f128[idx] = 100.0f;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 2; j++) {
                s->f44[i][j] = 0;
                s->f150[i][j] = 0;
            }
        }
        for (i = 0; i < 6; i++) {
            s->f90[i] = 0;
            s->f170[i] = 0;
        }
        s->f1C = idx;
        s->f68 = -1;
        s->f188 = 0;
        s->f11C = 0;
        s->f18C = 0;
        s->f74 = 0;
        s->f190 = 0;
        s->f78 = 0;
        s->f24 = 0;
    } else if (a0->f20 == 1) {
        s16 *p;
        P_0053DC78 *q;
        D_L39_00352940.f20C->f108[s->f1C] = 0;
        if (((G_0053DC78 *)D_L39_00241640)->f194 != 0) {
            for (p = D_L39_002927E0[s->fB0];
                 (s->fB0 & 0xFF) != 0xFF && s->fB0 <= D_L39_0024BF98 && p != 0 && (p[-1] >= 0 || p == D_L39_002927E0[s->fB0]);
                 p++) {
                u8 *o = (u8 *)D_L39_0024BF5C + ((u16)p[0] & 0x7FFF) * 256;
                if (o == 0) break;
                q = func_00382348(o);
                if (q != 0) {
                    D_L39_00352940.f20C->f108[s->f1C] += q->f4;
                }
            }
        }
        if (s->fB4 >= 0) {
            q = func_00382348(D_L39_0024BF5C_0053DC78 + (s->fB4 << 8));
            if (q != 0) {
                D_L39_00352940.f20C->f108[s->f1C] += q->f4;
            }
        }
        D_L39_00352940.f20C->f148[s->f1C] = D_L39_00352940.f20C->f108[s->f1C];
        D_L39_00352940.f20C->f128[s->f1C] = D_L39_00352940.f20C->f108[s->f1C];
        a0->f20 = 2;
    } else if (a0->f20 == 2) {
        s16 *p;
        P_0053DC78 *q;
        f32 *fp;
        u8 *vec;
        s32 flag;
        D_L39_00352940.f20C->f148[s->f1C] = 0;
        vec = (u8 *)&s->fC0;
        if (((G_0053DC78 *)D_L39_00241640)->f194 != 0) {
            for (p = D_L39_002927E0[s->fB0];
                 (s->fB0 & 0xFF) != 0xFF && s->fB0 <= D_L39_0024BF98 && p != 0 && (p[-1] >= 0 || p == D_L39_002927E0[s->fB0]);
                 p++) {
                u8 *o = (u8 *)D_L39_0024BF5C + ((u16)p[0] & 0x7FFF) * 256;
                if (o == 0) break;
                fp = (f32 *)func_00382348(o);
                if (fp != 0) {
                    D_L39_00352940.f20C->f148[s->f1C] += *fp;
                }
            }
        }
        if (s->fB4 >= 0) {
            fp = (f32 *)func_00382348(D_L39_0024BF5C_0053DC78 + (s->fB4 << 8));
            if (fp != 0) {
                D_L39_00352940.f20C->f148[s->f1C] += *fp;
            }
        }
        func_0038CAD0(vec);
        if (((G_0053DC78 *)D_L39_00241640)->f180 == 0) {
            if (D_L39_00352940.f20C->f148[s->f1C] != D_L39_00352940.f20C->f128[s->f1C]) {
                flag = 0;
                if (s->fC4 == 1) {
                    if (D_L39_00352940.f20C->f148[s->f1C] < D_L39_00352940.f20C->f108[s->f1C] * 0.2f) {
                        s->fC4 = 0;
                        flag = 1;
                    }
                }
                if ((s->fC4 != 0 && s->fC0 == 0) || flag != 0) {
                    s32 id = D_L39_00352940.f20C->f88[s->f1C];
                    s32 k;
                    s->fC0 = 0x8CA;
                    for (k = 0; k < *D_L39_00241120; k++) {
                        u8 *pl = func_L39_0061BF38(k);
                        if (pl != 0 && *(s32 *)(pl + 0x2548) == id) {
                            if (flag != 0) {
                                func_L01_00451F60(0x1160, -1, pl[0x24C9]);
                            } else {
                                func_L01_00451F60(0x115F, -1, pl[0x24C9]);
                            }
                        }
                    }
                }
            }
        }
        if (s->f40 != 0) {
            if (func_L01_00445AD0(s->fAC, 7, 0) == 0) {
                s->fBC = s->fBC + 1;
            } else {
                s->fBC = 0;
            }
        }
    }
}
/* localdecomp:end func_L39_0053DC78 */

INCLUDE_ASM("asm/levels", func_L39_0053E300);

INCLUDE_ASM("asm/levels", func_L39_0053E740);
