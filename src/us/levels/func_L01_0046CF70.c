#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L01_00470668 (src/levels/shared/L01_0046A938.c): spin starts 15 below the life, not 12 */
/* localdecomp:start func_L01_0046CF70 */
typedef int Quad_46CF70 __attribute__((mode(TI)));
typedef struct {
    u8 type;
    s8 flags;
    u8 texture;
    u8 render;
    s32 rgba;
    u8 spin;
    u8 render2;
    s16 life;
    s32 end_rgba;
    Quad_46CF70 head;
    vu0_v4 vel;
    Quad_46CF70 tail;
} Spark_46CF70;

extern u8 *D_L01_00221280[];
extern void func_00388830(void *, void *, f32);
extern Spark_46CF70 *func_L01_0045E438(s32 size);

Spark_46CF70 *func_L01_0046CF70(Quad_46CF70 *head, Quad_46CF70 *tail, s32 life, f32 w)
{
    Spark_46CF70 *s = func_L01_0045E438(0x5A);
    vu0_v4 tmp;
    Quad_46CF70 *q;

    if (s != 0) {
        s->rgba = 0x7FFFFFFF;
        s->end_rgba = 0x7FFFFFFF;
        s->render2 = 0x22;
        s->render = 0x48;
        s->flags = 3;
        q = &s->tail;
        s->texture = *D_L01_00221280[0];
        *q = *tail;
        ((f32 *)q)[3] = w;
        s->head = *head;
        func_00388830(&tmp, q, 0.9f);
        vec_sub_ab(&s->vel, head, &tmp);
        s->life = life;
        ((f32 *)&s->head)[3] = 0.05f;
        ((f32 *)&s->vel)[3] = 2.0f;
        s->spin = (u8)s->life - 15;
    }
    return s;
}
/* localdecomp:end func_L01_0046CF70 */
