#include "common.h"

/* localdecomp:start func_L03_003B7300 */
typedef struct {f32 x,y,z,w;} __attribute__((aligned(16))) V_3B7300;
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00440A88(f32 *, f32, f32);
extern u8 *func_L01_00467DA8(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L03_003B7300(V_3B7300 *position, s32 count, s32 colour1, s32 colour2)
{
    V_3B7300 pos, velocity;
    s32 i;
    f32 size;
    s32 spin;
    u8 *effect;

    pos = *position;
    position = &pos;
    for (i = 0; i < count; i++) {
        size = func_0037E250(1.0f, 2.0f);
        spin = func_0037E1D8(2);
        if (spin == 0) {
            spin--;
        }
        func_L01_00440A88((f32 *)&velocity, 0.05f, 0.25f);
        effect = func_L01_00467DA8(position, 20, size * 0.1f, size, colour1, 0, spin, &velocity, 0.002f, 0);
        if (effect != 0) {
            effect[9] = 0x74;
        }
        effect = func_L01_00467DA8(position, 20, size * 0.07f, size * 0.7f, colour2, 1, -spin, &velocity, 0.002f, 0);
        if (effect != 0) {
            effect[9] = 0x74;
        }
    }
}
/* localdecomp:end func_L03_003B7300 */
