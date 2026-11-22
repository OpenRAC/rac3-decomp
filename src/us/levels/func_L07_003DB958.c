#include "common.h"

/* localdecomp:start func_L07_003DB958 */
#include "vu0.h"
typedef struct {
    u8 pad[0x24];
    f32 scale;
} Class_3DD5D8;

typedef struct Obj_3DD5D8 {
    u8 p0[0x10];
    vu0_q pos;
    u8 state;
    u8 p21[3];
    Class_3DD5D8 *cls;
    u8 p28[4];
    f32 scale;
    u8 b30, b31;
    u16 h32;
    u8 p34[4];
    unsigned long flags38;
    u8 p40[0x28];
    void *vars;
    u8 p6C[0x84];
    vu0_q rot;
} Obj_3DD5D8;

typedef struct {
    void *f0;
    void (*cb)(void *);
    u8 p8[8];
    u8 f10[0x40];
    u8 f50[0x10];
    Obj_3DD5D8 *child;
} Vars_3DD5D8;

extern Obj_3DD5D8 *func_003BCFB0(s32, s32);
extern void func_003C26C8(void *);
extern void func_00389018(void *, s32, f32);
extern void func_00388440(void *, s32, s32);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L07_003DBA58(void *);

void func_L07_003DB958(Obj_3DD5D8 *m)
{
    Vars_3DD5D8 *v;
    Obj_3DD5D8 *o;

    if (m->state != 0) return;
    v = m->vars;
    o = func_003BCFB0(0x1D2D, 0x80);
    if (o) {
        o->b31 = 1;
        o->h32 = m->h32;
        o->b30 = m->b30;
        o->flags38 = m->flags38;
        o->scale = o->cls->scale * 1.1f;
        o->pos = m->pos;
        o->rot = m->rot;
        func_003C26C8(o);
    }
    v->child = o;
    func_00389018(v->f50, 2, -0.122173056f);
    func_00388440(v->f10, 0, 0x40);
    func_L01_00437350(m, 0, v->f10);
    v->cb = func_L07_003DBA58;
    func_L07_003DBA58(m);
}
/* localdecomp:end func_L07_003DB958 */
