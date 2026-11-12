#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00399D30);

INCLUDE_ASM("asm/levels", func_L03_00399F38);

INCLUDE_ASM("asm/levels", func_L03_0039A118);

INCLUDE_ASM("asm/levels", func_L03_0039A1F8);

/* localdecomp:start func_L03_0039A4C8 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_0039A4C8;
typedef struct { u8 pad0[0x44]; f32 f44; u8 pad48[0x28]; f32 f70; f32 f74; u8 pad78[8]; u8 b80; u8 b81; } P_0039A4C8;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_0039A5D0(void *, void *);
void func_L03_0039A4C8(void *arg) {
    A_0039A4C8 *a = arg;
    P_0039A4C8 *p = (P_0039A4C8 *)a->p68;
    f32 ang = p->f74;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((p->b80 & ~p->b81) >> i) & 1) {
            vu0_v4 pos;
            vu0_v4 w;
            vu0_v4 u = {0, 0, 0, 0};
            pos = a->pos;
            pos.z += 1.7f;
            u.x = p->f70 * func_0038D0B0(ang);
            u.y = p->f70 * func_0038D098(ang);
            w = u;
            vec_add_ab(&w, &pos, &w);
            w.z = p->f44;
            func_L03_0039A5D0(&pos, &w);
        }
        ang = func_0038DAB8(ang, 1.5707964f);
    }
}
/* localdecomp:end func_L03_0039A4C8 */

INCLUDE_ASM("asm/levels", func_L03_0039A5D0);

INCLUDE_ASM("asm/levels", func_L03_0039A780);
