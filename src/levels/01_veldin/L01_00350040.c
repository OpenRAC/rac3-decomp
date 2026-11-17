#include "common.h"

/* localdecomp:start func_L01_00350040 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00350040;
typedef struct { V_00350040 p; V_00350040 a; V_00350040 pad; V_00350040 b; } T_00350040;
extern void func_L01_003B1750(u8 *, f32, f32, V_00350040 *, V_00350040 *, s32, s32, s32, s32);
extern void func_003C2EC0(u8 *, s32, T_00350040 *);

void func_L01_00350040(u8 *a) {
    T_00350040 t;
    V_00350040 x, y;
    func_003C2EC0(a, 0, &t);
    x = t.b;
    y = t.a;
    func_L01_003B1750(a, 0.0f, 0.65f, &x, &y, 0x60FF1010, 0x60DDDDDD, 0x7F1010, 0xFF1010);
}
/* localdecomp:end func_L01_00350040 */
