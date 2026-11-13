/* near miss (level 3, Starship Phoenix): 26 differences, one cause: with the prototype below (seven ints, three floats, then the last int) the C matches exactly under -fno-sched-interblock; with the file's flags gcc's interblock scheduler moves the loop's `i--` from the latch into the first block (into the first jal's delay slot), retail keeps it at the bottom. Adding about six RTL insns to the loop body stops the motion (region over 100 insns), so retail's source had a bigger loop body before scheduling; inline helpers, a partial initializer for the angle vector, if/else for the sign and split statements did not stop it. func_L03_00399D30 and func_L03_0039F028 are the same family with the same problem */
#include "common.h"

/* localdecomp:start func_L03_00399F38 */
#include "vu0.h"
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; u8 *p68; } A_00399F38;
typedef struct { u8 pad0[0x5C]; u8 *p5C; } T_00399F38;
extern T_00399F38 D_L03_0021F298;
__asm__(".extern D_L03_0021F298, 16");
extern f32 func_00382538(void);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L03_00399F38(void *arg) {
    A_00399F38 *a = arg;
    u8 *s = a->p68;
    vu0_v4 vel;
    vu0_v4 pos;
    vu0_v4 dir;
    int i;
    for (i = 2; i >= 0; i--) {
        f32 ang = func_00382538();
        vu0_v4 t;
        s32 n;
        f32 h;
        f32 z;
        u8 *p;
        *(vu0_q *)&t = 0;
        t.x = func_0038D0B0(ang);
        t.y = func_0038D098(ang);
        dir = t;
        func_0038CF68(&vel, &dir, func_003824E0(2.0f, 4.0f) * 0.020000001f);
        n = func_00382498(0x3C, 0x78);
        h = a->pos.z - *(f32 *)(s + 0x44);
        if (h > 1.0f) h = 1.0f;
        z = func_003824E0(h * 0.5f, h);
        func_0038CF68(&dir, &dir, 1.7f);
        vec_add_ba(&pos, &a->pos, &dir);
        pos.z = *(f32 *)(s + 0x44) + z * 0.5f;
        p = func_L01_0046FB40(&pos, &vel, n, 0x7FFFFFFF, func_00382468(2) != 0 ? -2 : 2, 0x7F, 0x20, z * 210000.0f, 0.0f, 0.0f, 0);
        if (p != 0) {
            p[2] = D_L03_0021F298.p5C[0];
            p[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L03_00399F38 */
