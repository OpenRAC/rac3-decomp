#include "common.h"

/* localdecomp:start func_L39_00578AA8 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x420];
    f32 pos[1];
    f32 f424;
    f32 f428;
    f32 f42C;
    f32 f430;
    f32 f434;
    u8 state;
    u8 flag;
    s16 t;
    f32 rate;
    f32 f440;
    u8 pad444[0x460 - 0x444];
} E_00578AA8;

extern s32 *D_L39_00241120;
extern E_00578AA8 D_L39_0024DE80[];
extern f32 D_L39_0025D770[];
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_L39_005872D8(void);

void func_L39_00578AA8(s32 idx)
{
    E_00578AA8 *e = &D_L39_0024DE80[idx];
    f32 h;
    f32 v;
    f32 k;

    if (e->flag == 1) {
        switch (e->state) {
        case 0:
            if (*D_L39_00241120 == 1) {
                e->flag = 0;
            }
            e->f428 = e->f424;
            break;
        case 3:
            v = func_00382C58(e->pos, e->f428, e->f424, e->f42C, e->f430, e->f434);
            e->f428 = v;
            if (fabs_asm(v - e->f424) < 0.0001f && *D_L39_00241120 == 1) {
                e->flag = 0;
            }
            break;
        case 1:
            if (func_0038CB00(&e->t) != 0) {
                e->flag = 0;
            }
            k = (f32)e->t * e->rate;
            e->f428 = e->f424 + (e->f440 - e->f424) * k;
            break;
        case 2:
            if (func_0038CB00(&e->t) != 0) {
                e->flag = 0;
            }
            e->f428 = func_003C3BE8(e->f424, e->f440, (f32)e->t * e->rate);
            break;
        }
        if (*D_L39_00241120 == 1) {
            h = e->f428 * 0.5f;
            D_L39_0025D770[0] = func_0038D0B0(h) / func_0038D098(h);
            func_L39_005872D8();
        }
    }
}
/* localdecomp:end func_L39_00578AA8 */
