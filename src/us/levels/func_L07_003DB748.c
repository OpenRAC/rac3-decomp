#include "common.h"

/* localdecomp:start func_L07_003DB748 */
typedef struct O_3DD3C8 O_3DD3C8;
typedef struct {
    u8 pad0[8];
    u8 state;
    u8 pad9[0x17];
    u8 f20[0x30];
    u8 f50[0x10];
    O_3DD3C8 *child;
    f32 progress;
} V_3DD3C8;

struct O_3DD3C8 {
    u8 pad0[0x20];
    u8 state;
    u8 pad21[0x47];
    V_3DD3C8 *vars;
    u8 pad6C[0x84];
    f32 rot;
};

struct Obj_3DD5D8;
extern void func_L07_003DB958(struct Obj_3DD5D8 *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_00388F50(void *, void *, void *);
extern void func_L07_003DBAD0(void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003C26C8(void *);

void func_L07_003DB748(void *arg)
{
    O_3DD3C8 *m = arg;
    V_3DD3C8 *v;
    f32 r;

    func_L07_003DB958(arg);
    v = m->vars;
    switch (m->state) {
    case 0:
        break;
    case 1:
        if (v->state == 2) func_L01_00441FB8(m, 4, -1);
        break;
    case 2:
        if (func_L01_00452EC8(m)) func_0039FE80(1, 4, m);
        func_00388F50(v->f20, v->f20, v->f50);
        func_L07_003DBAD0(m);
        if (v->state == 1) {
            func_L01_004A6D70(1, m);
            func_L01_00441FB8(m, 5, -1);
        }
        break;
    case 3:
        break;
    case 4:
        if (func_L01_00452EC8(m)) func_0039FE80(0, 4, m);
        v->progress += 0.01f;
        if (v->progress >= 1.0f) {
            v->progress = 1.0f;
            func_L01_004A6D70(0, m);
            func_L01_00441FB8(m, 2, -1);
        }
        r = func_003BE6A8(3.1415927f, 0.0f, v->progress);
        m->rot = r;
        v->child->rot = r;
        func_003C26C8(v->child);
        break;
    case 5:
        if (func_L01_00452EC8(m)) func_0039FE80(0, 4, m);
        v->progress -= 0.01f;
        if (v->progress <= 0.0f) {
            v->progress = 0.0f;
            func_L01_004A6D70(0, m);
            func_L01_00441FB8(m, 1, -1);
        }
        r = func_003BE6A8(3.1415927f, 0.0f, v->progress);
        m->rot = r;
        v->child->rot = r;
        func_003C26C8(v->child);
        break;
    }
}
/* localdecomp:end func_L07_003DB748 */
