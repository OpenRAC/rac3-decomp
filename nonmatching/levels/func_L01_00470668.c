/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_0046CF70, the NTSC-U twin of func_L01_00470668, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2" (src/levels/shared/L01_0046A938.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046CF70 */
/* Needs -mvu0-use-vf0-vf2 (vec_sub_ab) beyond the PAL file's flags. */
typedef int Quad_0046CF70 __attribute__((mode(TI)));
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
    Quad_0046CF70 head;
    vu0_v4 vel;
    Quad_0046CF70 tail;
} Spark_0046CF70;

extern u8 *D_L01_00221280[];
extern Spark_0046CF70 *func_L01_0045E438_0046CF70(s32 type);
extern void func_00388830(void *, void *, f32);

Spark_0046CF70 *func_L01_0046CF70(Quad_0046CF70 *head, Quad_0046CF70 *tail, s32 life, f32 w) {
    Spark_0046CF70 *s = func_L01_0045E438_0046CF70(0x5A);
    vu0_v4 tmp;
    Quad_0046CF70 *q;

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
