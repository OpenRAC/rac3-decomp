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

/* localdecomp:start func_L31_0034AA20 */
typedef struct {
    u8 pad0[0x20];
    u8 state;           /* 0x20 */
    u8 pad21[0x43 - 0x21];
    u8 anim;            /* 0x43 */
    f32 f44;
    f32 f48;
    f32 f4C;
} M_0034AA20;

extern f32 D_L31_001DD120;
extern f32 D_L31_001DD130;
extern f32 D_L31_001DD134;
extern f32 D_L31_001DD138;
extern s32 D_L31_001DD13C;
extern f32 D_L31_001DD148;
extern f32 D_L31_001DD14C;
extern s32 D_L31_001DD154;
extern f32 D_L31_001DD158;
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);

void func_L31_0034AA20(M_0034AA20 *m, s32 arg) {
    func_L01_004450F0(m, arg, -1);
    switch (m->state) {
    case 0:
        break;
    case 0x42:
        m->f48 = 0.0f;
        break;
    case 1:
        if (m->anim != 6) {
            func_003C3A10(m, 6, D_L31_001DD158, D_L31_001DD154);
        }
        m->f48 = D_L31_001DD130;
        m->f44 += m->f4C;
        break;
    case 2:
        if (m->anim != 4) {
            func_003C3A10(m, 4, 0, (D_L31_001DD13C * 5 + 2) / 6);
        }
        m->f48 = D_L31_001DD138;
        break;
    case 3:
        if (m->anim != 1) {
            func_003C3A10(m, 1, 0, (D_L31_001DD13C * 5 + 2) / 6);
        }
        m->f48 = D_L31_001DD134;
        break;
    case 4:
        func_003C3A10(m, 5, D_L31_001DD148, D_L31_001DD14C);
        m->f44 += m->f4C;
        break;
    case 5:
        if (m->anim != 1) {
            func_003C3A10(m, 1, 0, (D_L31_001DD13C * 5 + 2) / 6);
        }
        m->f48 = D_L31_001DD120;
        break;
    }
}
/* localdecomp:end func_L31_0034AA20 */

/* localdecomp:start func_L31_0034ABB8 */
typedef struct {
    u8 pad[0x15C];
    s32 n;
} Vars_0034ABB8;

typedef struct {
    u8 pad[0x10];
    u8 pos[0x58];
    Vars_0034ABB8 *vars;
} Moby_0034ABB8;

typedef struct {
    f32 r;
    f32 g;
    f32 b;
    u8 pad[0x14];
} Light_0034ABB8;

extern s32 func_L01_00424B88(void *, s32, f32, f32);
extern s32 D_L31_001DD2A8[] __attribute__((section(".sdata")));
__asm__(".extern D_L31_001DD2A8, 4");
extern s32 D_L31_001DD2C8[] __attribute__((section(".sdata")));
__asm__(".extern D_L31_001DD2C8, 4");
extern s32 D_L31_001DD304;
__asm__(".extern D_L31_001DD304, 4");
extern Light_0034ABB8 D_L31_001F01C0[];

void func_L31_0034ABB8(Moby_0034ABB8 *m, s32 idx) {
    Vars_0034ABB8 *v;
    s32 h;
    s32 c;
    Light_0034ABB8 *l;
    f32 r, g, b;

    v = m->vars;
    h = func_L01_00424B88(m->pos, 0x4080FF, 10.5f, 0.0f);
    c = D_L31_001DD304;
    l = &D_L31_001F01C0[h];
    D_L31_001DD2A8[v->n] = h;
    l->r = (c & 0xFF) * 0.0078125f;
    l->g = ((c >> 8) & 0xFF) * 0.0078125f;
    l->b = ((c >> 16) & 0xFF) * 0.0078125f;
    D_L31_001DD2C8[idx] = v->n;
    v->n++;
}
/* localdecomp:end func_L31_0034ABB8 */
