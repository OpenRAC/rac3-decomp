#include "common.h"

typedef struct {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
} Vec_00349D18;
typedef struct {
    u8 pad[0x68];
    Vec_00349D18 *w68;
} Obj_00349D18;

extern f32 D_L31_001DD018;
extern float D_L31_001DD09C;
extern float D_L31_001DD0A0;
extern u8 D_L31_001D66B0[8];
extern void func_L30_0034CB68(s32, u8 *, s32, s32, s32, s32, float, float);

/* localdecomp:start func_L31_0034CB80 */
#include "vu0.h"

typedef int u128_0034CB80 __attribute__((mode(TI)));

typedef struct L_0034CB80 {
    u8 pad0[0x28];
    struct L_0034CB80 *next;    /* 0x28 */
    u8 pad2C[0xAA - 0x2C];
    s16 oclass;                 /* 0xAA */
} L_0034CB80;

typedef struct {
    u8 pad0[0xC8];
    s32 c8;
    s32 cc;
    s32 d0;
    s32 d4;
    s32 d8;
    L_0034CB80 *dc;
    u8 padE0[0xFC - 0xE0];
    s32 fc;
    u8 v100[0x10];
    s32 x110;
    s32 x114;
    u8 pad118[4];
    s32 x11C;
    u8 v120[0x10];
    s32 x130;
    f32 x134;
    s32 x138;
    u8 pad13C[0x150 - 0x13C];
    s32 x150;
    u8 pad154[0x15C - 0x154];
    s32 x15C;
} V_0034CB80;

typedef struct {
    u8 pad0[0x10];
    u128_0034CB80 pos;          /* 0x10 */
    u8 pad20[0x30 - 0x20];
    u8 b30;                     /* 0x30 */
    u8 pad31[0x34 - 0x31];
    u16 flags;                  /* 0x34 */
    u8 pad36[0x68 - 0x36];
    V_0034CB80 *vars;           /* 0x68 */
} M_0034CB80;

extern L_0034CB80 *D_L31_001DF7A8 __attribute__((section(".data")));
extern u128_0034CB80 D_L31_001E12C0[];

void func_L31_0034CB80(M_0034CB80 *m) {
    V_0034CB80 *v;
    L_0034CB80 *p;

    m->b30 = 0xFF;
    m->flags |= 0x104;
    v = m->vars;
    qzero(v->v100);
    v->c8 = -1;
    v->cc = -1;
    v->d0 = 0;
    v->d4 = 0;
    v->d8 = 0;
    v->x110 = 0;
    v->x114 = 0;
    v->x11C = 0;
    v->x15C = 0;
    for (p = D_L31_001DF7A8; p != 0; p = p->next) {
        if (p->oclass == 0x1B55) {
            v->dc = p;
        }
    }
    v->fc = -1;
    qzero(v->v120);
    v->x134 = 1.0f;
    v->x138 = 0;
    v->x150 = 0;
    v->x130 = 0;
    D_L31_001E12C0[0] = m->pos;
}
/* localdecomp:end func_L31_0034CB80 */

INCLUDE_ASM("asm/levels", func_L31_0034CC30);

INCLUDE_ASM("asm/levels", func_L31_0034CD18);
