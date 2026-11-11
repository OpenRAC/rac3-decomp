#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003B2DA8 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x68]; void *p68; } O_003B2DA8;
typedef struct { u8 pad[8]; f32 f8; f32 fC; u128_t v10; } T_003B2DA8;
extern f32 func_0038D160(f32, f32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L03_003B2DA8(void *self, u128_t *arg1) {
    T_003B2DA8 *t = ((O_003B2DA8 *)self)->p68;
    f32 d[4];
    t->v10 = *arg1;
    vec_sub_ba(d, &t->v10, (u8 *)self + 0x10);
    t->f8 = func_0038D160(d[0], d[1]) * 0.6f + t->fC * 0.4f;
    func_L01_004450F0(self, 2, -1);
}
/* localdecomp:end func_L03_003B2DA8 */
