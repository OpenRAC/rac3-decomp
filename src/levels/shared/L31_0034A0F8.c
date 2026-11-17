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

/* localdecomp:start func_L31_0034A0F8 */
typedef struct {
    u8 pad0[0x14];
    f32 f14;
} Ent_0034A0F8;

typedef struct {
    u8 pad0[0x50];
    u8 info[0x10];
    u8 move[0x14];
    s32 timer;
    s32 path[2];
    Ent_0034A0F8 *ent;
    u8 pad84[0x4];
    s32 a88;
    s32 a8C;
    u8 pad90[0x8];
    s32 turn;
    s32 done;
    u8 padA0[0x68];
    f32 f108;
    u8 pad10C[0x7C];
    f32 f188;
} Vars_0034A0F8;

typedef struct {
    u8 pad0[0x10];
    f32 pos[4];
    u8 state;
    u8 pad21[0x27];
    f32 f48;
    u8 pad4C[0x14];
    u8 flags;
    u8 pad61[0x7];
    Vars_0034A0F8 *vars;
    u8 pad6C[0x2C];
    s32 f98;
    u8 pad9C[0x5C];
    f32 fF8;
} Moby_0034A0F8;

extern f32 D_001A4C60[];
extern f32 D_001A4C64[];
extern f32 D_L31_001DD118;
__asm__(".extern D_L31_001DD118, 4");
extern f32 D_L31_001DD11C;
__asm__(".extern D_L31_001DD11C, 4");
extern f32 D_L31_001DD124;
__asm__(".extern D_L31_001DD124, 4");
extern f32 D_L31_001DD128;
__asm__(".extern D_L31_001DD128, 4");
extern f32 D_L31_001DD12C;
__asm__(".extern D_L31_001DD12C, 4");
extern f32 D_L31_001DD144;
__asm__(".extern D_L31_001DD144, 4");
extern f32 D_L31_001DD15C;
__asm__(".extern D_L31_001DD15C, 4");
extern f32 D_L31_001DD168;
__asm__(".extern D_L31_001DD168, 4");
extern f32 D_L31_001DD16C;
__asm__(".extern D_L31_001DD16C, 4");
extern f32 D_L31_001DD174;
__asm__(".extern D_L31_001DD174, 4");
extern f32 D_L31_001DD198;
__asm__(".extern D_L31_001DD198, 4");

extern void func_L31_0034A968();
extern void func_L31_0034AA20(void *, s32);
extern void func_L31_0034A740(void *);
extern void func_L31_0034A638(void *);
extern void func_L31_003A4280(void *, s32);
extern void func_L31_003478E8(void *, void *, void *, f32, f32, f32, f32, f32, f32, f32, s32);
extern s32 func_L31_00346798(void *, f32, f32, f32);
extern s32 func_L31_00347CB8(s32, s32, s32, s32 *);
extern s32 func_L31_00347868(u8 *, u8 *);
extern void func_L31_00346470(f32, f32, f32, f32, f32, f32);
extern f32 func_L30_0034CE78(u8 *);
extern int func_L30_0034D8D8(void *, float);
extern s32 func_L01_004561B8(void *);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L01_00456230(u8 *, s32);
extern s32 func_L01_00456250(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038DB00(f32, f32);

void func_L31_0034A0F8(Moby_0034A0F8 *m) {
    Vars_0034A0F8 *v = m->vars;
    f32 a;

    if (m->state == 0) {
        func_L31_0034A968(m);
        func_L31_0034AA20(m, 3);
    }
    func_L31_0034A740(m);
    switch (m->state) {
    case 0x42:
        if (func_L01_004561B8(m)) {
            if (func_L30_0034D8D8(m->pos, D_L31_001DD174)) {
                func_003A52A0(1, 0, m);
                func_L31_003A4280(m, -1);
            }
            func_L31_00347868((u8 *)m, v->info);
        }
        break;
    case 1:
        if (func_L01_004561B8(m)) {
            m->f98 = 0;
            func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 0.0f, D_L31_001DD15C, 0);
        }
        func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 0.0f, D_L31_001DD15C, 0);
        if (m->flags & 2) {
            func_L31_0034AA20(m, 0x42);
        }
        break;
    case 2:
        if (func_L01_004561B8(m)) {
            func_L31_0034A638(m);
        }
        if (func_L01_0044E1B8(m, D_L31_001DD168) && v->ent != 0) {
            func_L01_00456230((u8 *)v->ent, 1);
            v->ent->f14 = D_001A4C64[0];
            v->ent = 0;
        }
        func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 1.0f, 0.0f, 0);
        if (v->ent != 0 && !func_L01_00456250(v->ent)) {
            func_003C2F58(m, 1, (u8 *)v->ent + 0x10);
        }
        if (m->flags & 2) {
            func_L31_0034AA20(m, 3);
        }
        break;
    case 3:
        func_L01_004561B8(m);
        if (!func_L31_00346798(m, -3.1415927f, 0.0f, D_L31_001DD124) && v->done != 0) {
            func_L31_0034AA20(m, 5);
        } else if (func_L31_00347CB8(v->a88, v->a8C, 5, v->path) && func_L30_0034D8D8(m->pos, D_L31_001DD174) &&
                   func_L31_00346798(m, -3.1415927f, 0.0f, D_L31_001DD124)) {
            func_L31_0034AA20(m, 2);
        }
        func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 1.0f, 0.0f, 0);
        break;
    case 4:
        if (func_L01_004561B8(m)) {
            v->timer = 12;
            func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 0.0f, D_L31_001DD144, 0);
        }
        func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 0.0f, D_L31_001DD144, 0);
        m->f48 = D_L31_001DD12C;
        if (m->flags & 2) {
            func_L31_0034AA20(m, 3);
        }
        break;
    case 5:
        if (func_L01_004561B8(m)) {
            v->turn = 0;
        }
        if (((s32 (*)(void *, s32 *, f32, f32, f32, f32, f32, f32))func_L31_00346470)(m, &v->turn, -3.1415927f, 0.0f, D_L31_001DD128, D_L31_001DD118, D_L31_001DD11C, D_L31_001DD124)) {
            func_L31_0034AA20(m, 3);
        }
        func_L31_003478E8(m, m->pos, v->move, D_L31_001DD16C, func_L30_0034CE78((u8 *)m), 0.0f, 0.0f, D_L31_001DD198, 1.0f, 0.0f, 0);
        a = func_0038DB00(D_001A4C60[0] < m->pos[0] ? 3.1415927f : 0.0f, m->fF8);
        if (a > 2.0943952f) {
            a = 2.0943952f;
        } else if (a < -2.0943952f) {
            a = -2.0943952f;
        }
        v->f108 = a * 0.5f;
        v->f188 = a * 0.4f;
        break;
    }
}
/* localdecomp:end func_L31_0034A0F8 */

/* localdecomp:start func_L31_0034A638 */
#include "vu0.h"

extern s32 D_L31_001DD17C;
__asm__(".extern D_L31_001DD17C, 4");
extern s32 D_L31_001DD180;
__asm__(".extern D_L31_001DD180, 4");
extern s32 D_L31_001DD184;
__asm__(".extern D_L31_001DD184, 4");
extern s32 D_L31_001DD188;
__asm__(".extern D_L31_001DD188, 4");
extern f32 D_L31_001DD18C;
__asm__(".extern D_L31_001DD18C, 4");
extern f32 D_L31_001DD16C;
__asm__(".extern D_L31_001DD16C, 4");
extern s32 func_L31_003A12B0(void *m, void *a, void *b, void *c, s32 i4, s32 i5, s32 i6, s32 i7, s32 i8, f32 x, f32 y, f32 z);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038DB00(f32, f32);

void func_L31_0034A638(void *obj) {
    u8 *o = obj;
    u8 *v = *(u8 **)(o + 0x68);
    f32 p10[4];
    f32 p20[4];
    f32 p30[4];
    f32 a1;
    f32 a2;
    f32 f2;
    s32 res;

    func_003C2F58(obj, 1, p10);
    qzero(p20);
    p10[1] = *(f32 *)(o + 0x14);
    p20[2] = *(f32 *)(v + 0x94);
    a1 = fabs_asm(func_0038DB00(-3.1415927f, *(f32 *)(o + 0xF8)));
    a2 = fabs_asm(func_0038DB00(0.0f, *(f32 *)(o + 0xF8)));
    if (a2 < a1) {
        f2 = *(f32 *)(v + 0x90);
    } else {
        f2 = -*(f32 *)(v + 0x90);
    }
    qzero(p30);
    p20[0] = f2;
    p30[2] = D_L31_001DD16C / 3.0f;
    res = func_L31_003A12B0(obj, p20, p10, p30, D_L31_001DD17C, D_L31_001DD180, D_L31_001DD184, D_L31_001DD188, 1,
                            (f32)*(u8 *)(v + 0x14), *(f32 *)(v + 0x84), D_L31_001DD18C);
    *(s32 *)(v + 0x80) = res;
}
/* localdecomp:end func_L31_0034A638 */
