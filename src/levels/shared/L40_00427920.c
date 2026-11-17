#include "common.h"

/* localdecomp:start func_L40_00427920 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_00427920;

extern s32 func_0038CAD0(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L40_004276F0(void *);

void func_L40_00427920(u8 *obj) {
    V4_00427920 m[4];
    V4_00427920 out;

    if (func_0038CAD0(*(u8 **)(obj + 0x68) + 0x270) != 0) {
        return;
    }
    func_003C2EC0(obj, 3, m);
    func_0038CF68(&out, &m[1], 0.3f);
    vec_add_ab(&m[3], &m[3], &out);
    func_L40_004276F0(obj);
}
/* localdecomp:end func_L40_00427920 */
