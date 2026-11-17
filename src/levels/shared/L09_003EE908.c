#include "common.h"

/* localdecomp:start func_L09_003EE908 */
#include "vu0.h"

/* func_L09_003EE908 log:
   - first draft (switch on state, vec_add_ab, 0.02f): 3 diff; 0.020000001f fixes the constant.
   - needs -mvu0-use-vf0-vf2 --as ps2as (vec_add_ab helper; without ps2as the global goes through $gp).
   - left: move $a3 / mov.s $f12 swapped. Temporaries, inline args: no change.
   - callee prototype with the float third (pos, vel, size, life, a3, color): MATCH. EABI gives the
     same registers either way; the L03 definition with that order still matches (checked).
*/

typedef int u128_003EE908 __attribute__((mode(TI)));
typedef struct {
    s32 i0;
    s32 i4;
    f32 f8;
    f32 fC;
    s32 i10;
} S_003EE908;

extern s32 D_001D545C;
extern u8 D_001426E0[];
extern void func_0038D308(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern s32 func_0038DC20(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern u8 *func_L03_00458A70(u128_003EE908 *, u128_003EE908 *, f32, s32, s32, s32);

void func_L09_003EE908(u8 *self) {
    S_003EE908 *v = *(S_003EE908 **)(self + 0x68);

    if (D_001D545C == 10 && (D_001426E0[2] == 0 || D_001426E0[0x7A] != 0)) {
        return;
    }
    switch (self[0x20]) {
    case 0:
        func_0038D308(self + 0xC0, self + 0xF0);
        func_L01_004450F0(self, 1, -1);
        break;
    case 1: {
        vu0_v4 pos;
        vu0_v4 a;
        vu0_v4 b;
        u128_003EE908 *p;
        if (func_L01_004561B8(self)) {
            func_003A52A0(0, 0, self);
        }
        if (func_0038CAD0(&v->i10)) {
            v->i10 = (func_00382498(v->i4 >> 1, v->i4 << 1) * 5 + 2) / 6;
            if (v->i10 < 50) {
                v->i10 = 50;
            }
            func_L01_004450F0(self, 2, -1);
        }
        p = (u128_003EE908 *)(self + 0x10);
        *(u128_003EE908 *)&pos = *p;
        pos.w = 0.3f;
        if (func_0038DC20(&pos, 5.0f)) {
            f32 size;
            s32 life;
            func_0038CF68(&a, self + 0xC0, -(v->f8 * 0.020000001f));
            func_L01_00443B88(&b, 0.0f, v->f8 * 0.2f * 0.020000001f);
            vec_add_ab(&a, &b, &a);
            size = v->fC * func_003824E0(0.6f, 1.3f);
            life = (func_00382498(40, 80) * 5 + 2) / 6;
            func_L03_00458A70(p, (u128_003EE908 *)&a, size, life, func_00382498(-4, 4), 0x30FFFFFF);
        }
        break;
    }
    case 2:
        if (func_0038CAD0(&v->i10)) {
            v->i10 = (func_00382498(v->i0 >> 1, v->i0 << 1) * 5 + 2) / 6;
            if (v->i10 < 50) {
                v->i10 = 50;
            }
            func_L01_004450F0(self, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L09_003EE908 */
