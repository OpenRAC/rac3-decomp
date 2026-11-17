#include "common.h"

/* localdecomp:start func_L16_00434AE8 */
extern s32 D_L16_001E6EF4[];
extern s32 D_L16_001D6C88;
__asm__(".extern D_L16_001D6C88, 4");
extern u8 D_L16_001DFF70[] __attribute__((section(".sdata")));
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L16_00434AE8(void) {
    s32 a = 0xFF - (s32)((f32)(D_L16_001E6EF4[0] - D_L16_001D6C88) / 15.0f * 255.0f);
    func_003D9740(D_L16_001DFF70, 30, (a << 24) | 0xFF00 | a, 10, 1, 0.0f);
}
/* localdecomp:end func_L16_00434AE8 */

/* localdecomp:start func_L16_00434B70 */
__asm__(".extern D_L16_001D6C88, 4");
typedef struct { f32 x, y, z, w; } V_00434B70;
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L16_00434B70(void *o) {
    s32 delta = D_L16_001E6EF4[0] - D_L16_001D6C88;
    V_00434B70 *v;
    s32 i;

    if (o) {
        func_003C2EC0(o, 0, D_L16_001DFF70);
        v = (V_00434B70 *)D_L16_001DFF70;
        for (i = 2; i >= 0; i--) {
            func_0038CF68(v, v, (f32)delta * 0.01f);
            v++;
        }
    }
}
/* localdecomp:end func_L16_00434B70 */
