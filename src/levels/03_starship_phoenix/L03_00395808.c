#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_00395808);

/* localdecomp:start func_L03_00395BF0 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 v10; u8 pad20[0x48]; u8 *p68; } A_00395BF0;
typedef struct { vu0_v4 v0; vu0_v4 v10; u8 pad20[0xC]; s32 i2C; u8 pad30[8]; f32 f38; u8 pad3C[4]; s32 i40; f32 f44; u8 pad48[4]; f32 f4C; s32 i50; u8 pad54[4]; s32 f58; } P_00395BF0;
typedef struct { u8 b[0x80]; } E_00395BF0;
extern E_00395BF0 *D_L03_001DFA80;
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_00395BF0(void *arg) {
    A_00395BF0 *a = arg;
    P_00395BF0 *p;
    if (*(u8 *)((u8 *)arg + 0x20) == 0) {
        p = (P_00395BF0 *)a->p68;
        p->f58 = 0;
        p->v0 = *(vu0_v4 *)&a->v10;
        if (p->i2C != -1) {
            vec_sub_ba(&p->v10, D_L03_001DFA80[p->i2C].b + 0x30, &a->v10);
        }
        p->f44 = p->f38 / (f32)p->i40 * 0.017453292f;
        p->f4C = 1.0f / (f32)p->i50;
        func_L01_004450F0(arg, 1, -1);
    }
}
/* localdecomp:end func_L03_00395BF0 */

INCLUDE_ASM("asm/levels", func_L03_00395CA8);

INCLUDE_ASM("asm/levels", func_L03_00395D60);

INCLUDE_ASM("asm/levels", func_L03_00396190);

INCLUDE_ASM("asm/levels", func_L03_00396320);

/* localdecomp:start func_L03_003965E8 */
#include "vu0.h"
typedef struct { u8 pad0[0x20]; s32 i20; u8 pad24[0x58 - 0x24]; f32 f58; } S_003965E8;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003965E8 *p68; } A_003965E8;
extern u8 *D_L03_001DF99C;
__asm__(".extern D_L03_001DF99C, 16");
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_L01_00409658(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);

void func_L03_003965E8(void *arg) {
    A_003965E8 *a = arg;
    S_003965E8 *s = a->p68;
    vu0_v4 cur;
    vu0_v4 step;
    f32 pts[24][4];
    int i;
    vec_sub_ba(&step, D_L03_001DF99C + (s->i20 << 8) + 0x10, &a->pos);
    func_0038CE20(&step, &step, 0.14285715f);
    cur = a->pos;
    for (i = 0; i < 8; i++) {
        *(vu0_v4 *)pts[i] = cur;
        if (i != 0 && i != 7) {
            func_003C4C18(pts[i], 0.5f);
        }
        pts[i][3] = 0.15f;
        vec_add_ab(&cur, &cur, &step);
    }
    func_L01_00409658(pts, 0.15f, 8.0f, s->f58, 0x17, 0x17, 9, -1, 0x60600000, 0);
}
/* localdecomp:end func_L03_003965E8 */
