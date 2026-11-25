#include "common.h"
#include "vu0.h"

typedef int s128 __attribute__((mode(TI)));

/* localdecomp:start func_L01_00470C78 */
typedef struct {
    f32 size0;
    f32 size1;
    s16 life;
    u8 t0;
    u8 alpha;
    f32 vel[3];
    s32 t2;
    s16 pad1C;
    s16 a8;
} Rec_470C78;
typedef struct {
    u8 b0, b1, model, b3;
    s32 color;
    u8 b8, b9;
    s16 life;
    f32 size;
    vu0_v4 pos;
    Rec_470C78 rec;
} Spr_470C78;
extern Spr_470C78 *func_L01_004618E0(s32);
extern s32 func_00382468(s32);
extern u8 *D_L01_00221208[];
extern vu0_v4 D_L01_001E29C0;
extern void func_0038CF68(void *, void *, f32);

Spr_470C78 *func_L01_00470C78(f32 f12, f32 f13, s128 *pos, s32 life, s32 color, s32 mode, s32 t0, f32 *vec, s32 t2, s32 t3, s16 a8, s32 a9) {
    Spr_470C78 *p = func_L01_004618E0(0x5C);
    Rec_470C78 *q;
    f32 *d;
    vu0_v4 v;
    if (p != 0) {
        *(s128 *)&p->pos = *pos;
        p->pos.w = (f32)a9;
        q = &p->rec;
        p->b3 = 0x48;
        p->b9 = 0x20;
        p->color = color;
        p->b1 = 0;
        p->model = D_L01_00221208[0][t3];
        p->size = f12 * 210000.0f;
        p->life = life;
        if (mode == 0) {
            p->b8 = 0x40;
        } else if (mode == 1) {
            p->b8 = 0x5A;
        } else if (mode == 2) {
            p->b8 = func_00382468(0xFF);
        }
        q->size0 = p->size;
        q->size1 = f13 * 210000.0f;
        q->life = life;
        q->t0 = t0;
        q->alpha = color >> 24;
        q->t2 = t2;
        q->a8 = a8;
        d = q->vel;
        d[0] = vec[0];
        d[1] = vec[1];
        d[2] = vec[2];
        vec_sub_ba(&v, &D_L01_001E29C0, &p->pos);
        func_0038CF68(&v, &v, 0.9f);
        vec_add_ab(&p->pos, &p->pos, &v);
    }
    return p;
}
/* localdecomp:end func_L01_00470C78 */
