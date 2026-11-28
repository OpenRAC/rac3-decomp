#include "common.h"
/* localdecomp:start func_L01_00375C70 */
#include "vu0.h"
typedef struct {
    u8 pad[0x40]; f32 phase, radius; u8 pad48[0x28];
    f32 a, b, angle, angle2; u8 pad80[0x20];
    vu0_v4 direction[24], result[24]; f32 angles[24];
} State_00376D08;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; State_00376D08 *state; } M_00376D08;
extern f32 func_00389380(f32, f32);
extern void func_L01_003750E0(void *, s32, f32, f32, f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_004084B0(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_0037E2A8(void);
extern void func_003D3FA0(void *, s32, s32, s32, f32, f32, f32);
void func_L01_00375C70(M_00376D08 *obj)
{
    vu0_v4 at, center;
    State_00376D08 *s = obj->state;
    s32 i;
    s->a -= 0.04f;
    if (s->a <= 0.0f) {
        s->a = 0.0f;
    }
    s->b -= 0.025f;
    if (s->b <= 0.0f) {
        s->b = 0.0f;
    }
    s->angle = func_00389380(s->angle, 0.0436332338f);
    s->angle2 = func_00389380(s->angle, 0.072722055f);
    func_L01_003750E0(&obj->pos, 54, s->a, 0.5f, s->angle, 0.5f);
    func_L01_003750E0(&obj->pos, 54, s->b, 0.5f, s->angle2, 0.5f);
    func_L01_003750E0(&obj->pos, 54, s->radius, 0.5f, -s->angle, 0.8f);
    func_L01_003750E0(&obj->pos, 54, s->radius, 0.5f, s->angle, 0.8f);
    s->radius -= 0.125f;
    if (s->radius < 0.0f) {
        s->radius = 0.0f;
    }
    for (i = 0; i < 24; i++) {
        func_00389158(&s->result[i], &s->result[i], &s->direction[i], s->angles[i]);
        func_00388830(&s->result[i], &s->result[i], s->radius);
        vec_add_ab(&at, &s->result[i], &obj->pos);
        *(vu0_q *)&center = *(vu0_q *)&obj->pos;
        func_L01_004084B0(&at, &center, 18, 1, 0x2020FF, 0x2020FF, 0x1FFF2020, 0x1FFF2020, 0.08f, 3.0f, s->phase);
    }
    s->phase -= func_0037E250(0.025f, 0.035f);
    if (s->phase <= -8.0f) {
        s->phase += 8.0f;
    }
    func_003D3FA0(&obj->pos, 57, 0x4FFFFFFF, 1, 0.25f, 0.0f, func_0037E2A8());
    func_003D3FA0(&obj->pos, 11, 0x3FFF2040, 3, 0.3f, 0.01f, func_0037E2A8());
    func_003D3FA0(&obj->pos, 57, 0x4FFFFFFF, 1, 0.27f, 0.0f, func_0037E2A8());
    func_003D3FA0(&obj->pos, 11, 0x3FFF2040, 1, 0.35f, 0.01f, func_0037E2A8());
}
/* localdecomp:end func_L01_00375C70 */
