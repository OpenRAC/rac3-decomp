#include "common.h"

/* NTSC-U counterpart of func_L23_003AAF58 (src/levels/23_holostar_studios_clank/L23_003AAA58.c): 0.4 -> 0.333333; 150 -> 180 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

/* localdecomp:start func_L23_003A96E8 */
#include "vu0.h"
__asm__(".extern D_L23_001DE210, 4");
extern s32 D_L23_001DE210;
extern s32 D_001A71A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern void *func_L23_003AF078(void *, void *, void *, s32, s32, s32);

void func_L23_003A96E8(u8 *self)
{
    u8 *s = *(u8 **)(self + 0x68);
    V4 a, b;

    a.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.1f;
    a.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.1f;
    a.z = 1.0f;
    vec_add_ba(&a, &a, self + 0x10);
    b.x = func_0038D098(*(f32 *)(self + 0xF8)) * 0.5f;
    b.y = func_0038D0B0(*(f32 *)(self + 0xF8)) * 0.5f;
    b.z = 0.5f;
    func_0038CF68(&b, &b, 0.333333343f);
    func_L23_003AF078(self, &a, &b, D_001A71A0[0], 0xB4, 1);
    *(s32 *)s = D_L23_001DE210;
}
/* localdecomp:end func_L23_003A96E8 */
