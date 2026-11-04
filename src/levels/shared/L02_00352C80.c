#include "common.h"

typedef struct S_L02_003532F0 {
    f32 x;
    f32 y;
    u8 pad08[0xC];
    s32 state;
    f32 t18;
    f32 t1C;
} S_L02_003532F0;
typedef struct T_L02_003532F0 {
    f32 thr;
    f32 pad[6];
} T_L02_003532F0;
typedef struct O_L02_003532F0 {
    u8 pad00[0x20];
    s32 count;
    u8 pad24[0xC];
    f32 vx;
    f32 vy;
} O_L02_003532F0;

INCLUDE_ASM("asm/levels", func_L02_00352C80);

INCLUDE_ASM("asm/levels", func_L02_00352DF0);

INCLUDE_ASM("asm/levels", func_L02_00352F60);

INCLUDE_ASM("asm/levels", func_L02_00353208);

/* localdecomp:start func_L02_003532F0 */
extern T_L02_003532F0 D_L02_002B0E50[];

void func_L02_003532F0(s32 unused, O_L02_003532F0 *o) {
    S_L02_003532F0 *p;
    s32 i;
    s32 state;
    s32 ns;
    f32 t;

    p = (S_L02_003532F0 *)((u8 *)o + 0x60);
    for (i = 0; i < o->count; i++) {
        state = p->state;
        if (state != -1) {
            p->t18 = p->t18 + p->t1C;
            if (D_L02_002B0E50[state].thr < p->t18) {
                ns = state + 1;
                t = p->t18 - D_L02_002B0E50[state].thr;
                p->state = ns;
                p->t18 = t;
                if (ns >= 5) {
                    p->state = -1;
                }
            }
            p->x = p->x + o->vx;
            p->y = p->y + o->vy;
        }
        p++;
    }
}
/* localdecomp:end func_L02_003532F0 */

INCLUDE_ASM("asm/levels", func_L02_00353398);

INCLUDE_ASM("asm/levels", func_L02_003534D8);

/* localdecomp:start func_L02_003536B8 */
extern void func_L02_003536D8(s32);
void func_L02_003536B8(u8 *p) {
    func_L02_003536D8(*(s32 *)(p + 0x68));
}
/* localdecomp:end func_L02_003536B8 */

INCLUDE_ASM("asm/levels", func_L02_003536D8);
