#include "common.h"

/* localdecomp:start func_L40_003D9D28 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    s32 (*get)(void *);
} VT_003D9D28;

typedef struct {
    u8 pad0[0x14];
    VT_003D9D28 *vt;
    u8 pad18[0x250 - 0x18];
    vu0_v4 dir;
} Obj_003D9D28;

extern vu0_v4 D_L40_00249F40;
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *d, void *s, f32 k);
extern f32 func_L39_005B44C8(void);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L39_005CDE78(vu0_v4 *pos, vu0_v4 *vel, u32 colour, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f);

void func_L40_003D9D28(u8 *a0, Obj_003D9D28 *a1) {
    vu0_v4 diff;
    vu0_v4 dir;
    vu0_v4 out;

    vec_sub_ab(&diff, &D_L40_00249F40, a0 + 0x10);
    func_0038CE20(&dir, &a1->dir, func_L39_005B4410(0.020000001f, 0.040000003f));
    func_0038D890(&out, &dir, &diff, func_L39_005B44C8());
    func_L39_005CDE78((vu0_v4 *)(a0 + 0x10), &out, 0x50804040, 0x3C, func_L39_005B4398(0xFF) & 0xFF, 1, 0x40, a1->vt->get(a1), 0.4f);
    func_L39_005CDE78((vu0_v4 *)(a0 + 0x10), &out, 0x407F7F7F, 0x3C, func_L39_005B4398(0xFF) & 0xFF, 1, 0x40, a1->vt->get(a1), 0.2f);
}
/* localdecomp:end func_L40_003D9D28 */

INCLUDE_ASM("asm/levels", func_L40_003D9E78);
