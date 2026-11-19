/* functional: high. Identical behaviour; differs only in VU0 scheduling and branch layout. */
#include "common.h"
/* localdecomp:start func_L07_003C9D88 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003C9D88;
static __inline__ void add_003C9D88(V_003C9D88 *out, V_003C9D88 *a, V_003C9D88 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*out) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
void func_L07_003C9D88(u8 *obj, s32 index) {
    extern void func_003C2EC0(void *, s32, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L07_003C9280(void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L07_003C9E88(void *, void *, f32, f32);
    V_003C9D88 matrix[4];
    V_003C9D88 pos;
    V_003C9D88 offset;
    V_003C9D88 target;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 side = (u8)index;
    func_003C2EC0(obj, side, matrix);
    pos = matrix[3];
    func_0038CF68(&offset, &matrix[1], side ? -20.0f : 20.0f);
    add_003C9D88((V_003C9D88 *)(vars + 0x470), &pos, &offset);
    func_L07_003C9280(obj);
    if (*(f32 *)(vars + 0x488) == 1.0f) {
        add_003C9D88(&target, &pos, &offset);
    } else {
        func_0038CE20(&target, &offset, *(f32 *)(vars + 0x488));
        add_003C9D88(&target, &pos, &target);
    }
    func_L07_003C9E88(&pos, &target, 1.0f, *(f32 *)(vars + 0x48C));
}
/* localdecomp:end func_L07_003C9D88 */
