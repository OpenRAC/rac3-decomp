#include "common.h"

/* localdecomp:start func_L09_003CD268 */
#include "vu0.h"

typedef struct {
    s16 h0;
    s16 h2;
    s32 timer;
    f32 rate;
    s32 idx;
    vu0_v4 to;
    vu0_v4 from;
} S_003CD268;

extern u8 *D_L09_001E009C;
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(u8 *, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00445438(void *, void *, void *, f32);

void func_L09_003CD268(u8 *arg0) {
    S_003CD268 *s;
    vu0_v4 t;
    f32 ang;

    s = *(S_003CD268 **)(arg0 + 0x68);
    switch (arg0[0x20]) {
    case 0:
        if (s->h2 != 0) {
            func_L01_004450F0(arg0, 3, -1);
            break;
        }
        *(vu0_q *)&s->from = *(vu0_q *)(arg0 + 0x10);
        ang = func_0038DAB8(*(f32 *)(arg0 + 0xF8), s->h0 != 0 ? 4.712389f : 1.5707964f);
        t.x = func_0038D098(ang) * 20.0f;
        t.y = func_0038D0B0(ang) * 20.0f;
        t.z = 0.0f;
        vec_add_ab(arg0 + 0x10, arg0 + 0x10, &t);
        *(vu0_q *)&s->to = *(vu0_q *)(arg0 + 0x10);
        func_L01_004450F0(arg0, 1, -1);
        break;
    case 1:
        if (s->idx != -1 && func_L01_00456250(D_L09_001E009C + (s->idx << 8)) != 0) {
            func_L01_00456230(arg0, 1);
            func_L01_004450F0(arg0, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(arg0) != 0) {
            s->timer = 0xB4;
            s->rate = 0.0055555557f;
        }
        if (func_0038CAD0(&s->timer) != 0) {
            func_L01_004450F0(arg0, 3, -1);
        } else {
            func_L01_00445438(arg0 + 0x10, &s->from, &s->to, (f32)s->timer * s->rate);
        }
        break;
    }
}
/* localdecomp:end func_L09_003CD268 */
