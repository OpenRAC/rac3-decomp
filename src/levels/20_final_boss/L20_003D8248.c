#include "common.h"

/* localdecomp:start func_L20_003D8248 */
#include "vu0.h"

typedef struct { u8 b[0xA0]; } E_8248;
extern E_8248 D_L20_002A2E40[];
extern s16 D_L20_001E2650[] __attribute__((section(".sdata")));
extern s16 D_L20_001E2660[] __attribute__((section(".sdata")));
extern f32 D_L20_001E2694;
extern vu0_v4 D_001A4EC0;
extern void func_L01_00409658(void *, s32, s32, s32, f32, f32, f32, long, long, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_003D9740(void *, s32, s32, s32, s32, f32);

void func_L20_003D8248(u8 *obj) {
    vu0_v4 rotation;
    vu0_v4 side;
    vu0_v4 cross;
    vu0_v4 position;
    vu0_v4 up;
    vu0_v4 *pc = &cross;
    u8 *v = *(u8 **)(obj + 0x68);
    s32 i;
    for (i = 0; i < 5; i++) {
        if (D_L20_001E2650[i] != 0) {
            s32 color = 0x7F7F7F | ((s32)((f32)D_L20_001E2660[i] * D_L20_001E2694) << 24);
            func_L01_00409658(&D_L20_002A2E40[i], 15, 14, 10, 0.0f, 4.0f, 0.0f, color, color, 1);
        }
    }
    *(f32 *)(v + 0x64C) += 0.1f;
    if (*(f32 *)(v + 0x64C) >= 7.0f) {
        *(f32 *)(v + 0x64C) -= 7.0f;
    }
    position = *(vu0_v4 *)(obj + 0x10);
    position.z += 2.0f;
    position.w = 1.0f;
    rotation = *(vu0_v4 *)(obj + 0xC0);
    func_0038CE20(&up, &D_001A4EC0, -1.0f);
    func_0038CE90(&side, &rotation, &up);
    func_0038CF68(&side, &side, 2.5f);
    func_0038CE90(pc, &side, &rotation);
    func_003D9740(&rotation, 0x17, 0x1FA06565, 10, 1, *(f32 *)(v + 0x64C));
}
/* localdecomp:end func_L20_003D8248 */
