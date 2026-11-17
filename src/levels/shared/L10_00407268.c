#include "common.h"

typedef struct { u8 pad[0x34]; s32 frame; } S_Game;
typedef struct { u8 pad[0xB0]; } S_Rec;

/* localdecomp:start func_L10_00407268 */
#include "vu0.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00407268;

extern V4_00407268 D_L10_001E1B60[];
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern void func_003C4C18(void *, f32);

void func_L10_00407268(void *a0) {
    V4_00407268 m[4];
    V4_00407268 v;

    func_003C2EC0(a0, 0, m);
    func_0038CF68(&v, D_L10_001E1B60, -2.0f);
    vec_add_ab(&v, &v, &m[3]);
    func_003D9508(&v, 0xB, 0x80404080, 1, func_003824E0(1.7f, 1.9f), 0.08f, 0.0f);
    func_003C4C18(&v, 0.3f);
    func_003D9508(&v, 0xB, 0x80001080, 1, func_003824E0(0.9f, 1.0f), 0.08f, 0.0f);
}
/* localdecomp:end func_L10_00407268 */

INCLUDE_ASM("asm/levels", func_L10_00407378);
