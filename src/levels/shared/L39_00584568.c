#include "common.h"

/* localdecomp:start func_L39_00584568 */
typedef struct S_00584568 {
    s32 x, y, z, pad0C, f10, f14, f18;
} S_00584568;
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern s32 func_00139E08(s32);
extern void func_L39_005F3948(void);
extern s32 D_L39_0025F680[];
extern S_00584568 D_L39_0025C600;
extern s32 D_L39_0024B9C8;
extern s32 D_L39_0024CAD8;
extern s32 D_L39_00242920;
extern f32 D_L39_0024B9D0;
extern s32 D_L39_002402F4;

/* from rac2-decomp's func_00278EB0 */
void func_L39_00584568(void) {
    S_00584568 *state;
    s32 x, y, z;

    func_003A92F0(1);
    func_00139E08(0);
    D_L39_0024B9C8++;
    z = D_L39_0024CAD8;
    y = D_L39_0025F680[4];
    x = D_L39_0025F680[3];
    state = &D_L39_0025C600;
    state->f14 = z - 0x60000;
    D_L39_0024CAD8 = 0x60000;
    state->x = x + 0x60000;
    state->y = y + 0x60000;
    state->z = state->x + 0xD0800;
    D_L39_00242920 = 0x2000;
    func_003A9108();
    func_L39_005F3948();
    state->f18 = D_L39_002402F4;
    D_L39_0024B9D0 = 1.0f;
}
/* localdecomp:end func_L39_00584568 */
