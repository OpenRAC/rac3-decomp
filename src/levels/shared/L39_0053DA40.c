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

INCLUDE_ASM("asm/levels", func_L39_0053DC78);

INCLUDE_ASM("asm/levels", func_L39_0053E300);

INCLUDE_ASM("asm/levels", func_L39_0053E740);
