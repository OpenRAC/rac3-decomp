#include "common.h"

/* localdecomp:start func_L08_0039F4E8 */
#include "vu0.h"
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_003C5458(void *, s32, f32, f32);
__asm__(".extern D_L08_001DE168, 8");
extern s32 D_L08_001DE168[2];
__asm__(".extern D_L08_001DE140, 8");
extern u8 D_L08_001DE140[8];
__asm__(".extern D_L08_001DE160, 8");
extern s32 D_L08_001DE160[2];
__asm__(".extern D_L08_001DE130, 8");
extern f32 D_L08_001DE130[2];
__asm__(".extern D_L08_001DE128, 8");
extern f32 D_L08_001DE128[2];

void func_L08_0039F4E8(s32 a0)
{
    s32 i;
    vu0_v4 p;
    u8 m[0x40];
    vu0_v4 d;

    for (i = 0; i < 2; i++) {
        func_003C2F58((u8 *)a0, D_L08_001DE168[i], (u8 *)&p);
        func_003C2EC0((void *)a0, D_L08_001DE168[i], m);
        func_0038D028(&d, D_L08_001DE140 + i * 0x10, m);
        vec_add_ab(&p, &p, &d);
        func_003C5458(&p, D_L08_001DE160[i], D_L08_001DE130[i], D_L08_001DE128[i]);
    }
}
/* localdecomp:end func_L08_0039F4E8 */
