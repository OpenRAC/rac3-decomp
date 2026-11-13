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


/* localdecomp:start func_L31_00349DD0 */
typedef struct {
    u8 pad[0x4C];
    f32 hist[16];
} Hist_003491F0;

typedef struct {
    u8 pad[0x68];
    Hist_003491F0 *w68;
} Moby_003491F0;

extern s32 D_L31_001DD0B0;

void func_L31_00349DD0(Moby_003491F0 *m, f32 value) {
    Hist_003491F0 *h;
    s32 i;
    h = m->w68;
    for (i = D_L31_001DD0B0 - 1; i >= 0; i--) {
        h->hist[i + 1] = h->hist[i];
    }
    h->hist[1] = value;
}
/* localdecomp:end func_L31_00349DD0 */

INCLUDE_ASM("asm/levels", func_L31_00349E10);

INCLUDE_ASM("asm/levels", func_L31_0034A0F8);

INCLUDE_ASM("asm/levels", func_L31_0034A638);

INCLUDE_ASM("asm/levels", func_L31_0034A740);

/* localdecomp:start func_L31_0034A968 */
typedef struct {
    f32 unk0;
    s16 unk4;
    char pad6[0x10 - 0x6];
    f32 unk10;
    char pad14[0x50 - 0x14];
    char unk50[0x70 - 0x50];
    s32 unk70;
    char pad74[0x80 - 0x74];
    s32 unk80;
    char pad84[0x90 - 0x84];
    f32 unk90;
    f32 unk94;
    f32 unk98;
} Vars;

typedef struct {
    char pad0[0x24];
    f32 unk24;
} Class;

typedef struct {
    char pad0[0x24];
    Class *cls;
    char pad28[0x2C - 0x28];
    f32 scale;
    char pad30[0x68 - 0x30];
    Vars *vars;
} Moby;

extern f32 D_L31_001DD170;
extern f32 D_L31_001DD190;
extern f32 D_L31_001DD194;
extern void func_L31_00346998(Moby *, void *);

void func_L31_0034A968(Moby *m) {
    Vars *v = m->vars;

    if (v->unk10 <= 0.0f) {
        v->unk10 = D_L31_001DD170 * m->scale / m->cls->unk24;
    }
    v->unk0 = v->unk4;
    func_L31_00346998(m, v->unk50);
    v->unk70 = 1;
    if (v->unk90 <= 0.0f) {
        v->unk90 = D_L31_001DD190;
    }
    if (v->unk94 <= 0.0f) {
        v->unk94 = D_L31_001DD194;
    }
    v->unk98 = 0.0f;
    v->unk80 = 0;
}
/* localdecomp:end func_L31_0034A968 */

INCLUDE_ASM("asm/levels", func_L31_0034AA20);

INCLUDE_ASM("asm/levels", func_L31_0034ABB8);

INCLUDE_ASM("asm/levels", func_L31_0034ACA8);

INCLUDE_ASM("asm/levels", func_L31_0034ADF0);

INCLUDE_ASM("asm/levels", func_L31_0034AFD8);

/* localdecomp:start func_L31_0034B580 */
typedef struct {
    u8 pad[0xC0];
    s32 start;
    s32 count;
    s32 cur;
    s32 prev;
    s32 step;
} Vars_0034B580;

typedef struct {
    u8 pad[0x68];
    Vars_0034B580 *vars;
} Moby_0034B580;

extern s32 D_L31_001DD21C;
__asm__(".extern D_L31_001DD21C, 4");
extern s32 func_00382498(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L31_0034CD18(Moby_0034B580 *);

void func_L31_0034B580(Moby_0034B580 *m) {
    Vars_0034B580 *v = m->vars;

    v->prev = v->cur;
    if (v->cur >= v->start) {
        if (v->step == D_L31_001DD21C - 1) {
            v->cur = v->start - 1;
            func_L01_004450F0(m, 3, -1);
        } else {
            v->cur = func_00382498(0, v->start - 2);
            func_L01_004450F0(m, 2, -1);
        }
    } else {
        if (v->step == D_L31_001DD21C - 1) {
            v->cur = v->start + v->count - 1;
            func_L01_004450F0(m, 3, -1);
        } else {
            v->cur = func_00382498(v->start, v->start + v->count - 2);
            func_L01_004450F0(m, 2, -1);
        }
    }
    v->step = (v->step + 1) % D_L31_001DD21C;
    func_L31_0034CD18(m);
}
/* localdecomp:end func_L31_0034B580 */

INCLUDE_ASM("asm/levels", func_L31_0034B688);

INCLUDE_ASM("asm/levels", func_L31_0034B700);

INCLUDE_ASM("asm/levels", func_L31_0034B850);

INCLUDE_ASM("asm/levels", func_L31_0034BA10);

INCLUDE_ASM("asm/levels", func_L31_0034BB58);

INCLUDE_ASM("asm/levels", func_L31_0034BCA8);

INCLUDE_ASM("asm/levels", func_L31_0034BF90);

INCLUDE_ASM("asm/levels", func_L31_0034C5A0);

INCLUDE_ASM("asm/levels", func_L31_0034CA18);

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
