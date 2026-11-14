#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    Vec4 v;
    u8 *o;
    s32 pad14;
    u8 b18;
    u8 b19;
    u16 h1A;
    u8 pad1C[20];
} S_357DC0;
extern f32 fe_func_0038D098(f32);
extern f32 fe_func_0038D0B0(f32);
extern void fe_func_0038CE20(f32 *, void *, f32);
extern s32 fe_func_003D3CB0(s32 a, s32 b, s32 c, u8 *o, S_357DC0 *s);
/* localdecomp:start func_L01_0035A1B8 */
extern u8 D_L01_00284580[];
extern void func_L01_004C6EC8(void *, void *);
extern void func_L01_00445168(f32 *, f32, f32 *, f32, f32, f32);
extern s32 func_00388398(s32 *);

/* Updates the 25-record table: for each active record scrolls two vec4 values and two positions
 * (wrapping at -8), and runs a fade-in, 60-frame hold and fade-out state using game_spring and
 * timer_tick. */
void func_L01_0035A1B8(void)
{
    int index, axis;
    char *record;
    float *position, *velocity, value, cur;

    char *base = (char *)D_L01_00284580;

    for (index = 0; index < 25; index++) {
        record = (char *)(index * 0x530 + (int)base);
        if (*(int *)(record + 0x514) != 1)
            continue;
        velocity = (float *)(record + 0x4f0);
        position = (float *)(record + 0x500);
        for (axis = 0; axis < 2; axis++) {
            func_L01_004C6EC8(record + 0x20 + axis * 16, record + 0x20 + axis * 16);
            cur = position[axis];
            value = cur + velocity[axis];
            position[axis] = value;
            if (value <= -8.0f)
                position[axis] = value + 8.0f;
        }
        if (*(int *)(record + 0x518) == 0) {
            func_L01_00445168((float *)(record + 0x510), 0.5f, (float *)(record + 0x51c), 0.00200000009f, 0.000199999995f, 0.0199999996f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.5f) {
                *(int *)(record + 0x518) = 2;
                *(int *)(record + 0x520) = 60;
            }
        } else if (*(int *)(record + 0x518) == 1) {
            func_L01_00445168((float *)(record + 0x510), 0.0f, (float *)(record + 0x51c), 0.00200000009f, 0.000199999995f, 0.0199999996f);
            cur = *(float *)(record + 0x510);
            if (cur == 0.0f)
                *(int *)(record + 0x514) = 0;
        } else if (func_00388398((int *)(record + 0x520))) {
            *(int *)(record + 0x518) = 1;
        }
    }
}
/* localdecomp:end func_L01_0035A1B8 */
