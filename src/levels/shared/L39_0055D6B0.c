#include "common.h"

/* localdecomp:start func_L39_0055D6B0 */
#include "vu0.h"
typedef struct S_0055D6B0Inner { u8 pad0[0x40]; u8 b40[0x10]; u8 pad50[0x50]; vu0_q vA0; u8 pad_b0[0x24A8]; s32 f2558; } S_0055D6B0Inner;
typedef struct S_0055D6B0Self { u8 pad0[0x10]; vu0_q v10; u8 pad20[0x48]; S_0055D6B0Inner **f68; } S_0055D6B0Self;
extern void func_003C2880(void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00404AD8(void *, void *);
extern void func_L01_004048D0(void *, void *);
extern void func_L39_0055D790(u8 *);
extern void func_L01_0034C4E0_0055D6B0(void *);

void func_L39_0055D6B0(u8 *a0) {
    S_0055D6B0Self *self = (S_0055D6B0Self *)a0;
    S_0055D6B0Inner **pp = self->f68;
    vu0_v4 v[2];
    if (*pp != 0 && (*pp)->f2558 == 0) {
        func_003C2880(a0);
        return;
    }
    *(vu0_q *)&v[0] = (*pp)->vA0;
    func_0038CE20(&v[1], (*pp)->b40, 0.8f);
    vec_add_ab(&v[0], &v[0], &v[1]);
    if (a0[0x20] == 0) {
        func_L01_00404AD8(func_L39_0055D790, self);
        a0[0x20] = 1;
    }
    self->v10 = (*pp)->vA0;
    *(f32 *)(a0 + 0x18) += 2.0f;
    func_L01_004048D0(func_L01_0034C4E0_0055D6B0, self);
}
/* localdecomp:end func_L39_0055D6B0 */
