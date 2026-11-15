#include "common.h"

/* declared by functions of L24_0035AB58.c, which this file was cut from */
s32 func_L24_0035B0D0(void *);

/* localdecomp:start func_L24_0035B0D0 */
#include "vu0.h"
extern f32 D_L24_001DD5C8, D_L24_001DD5D4;
__asm__(".extern D_L24_001DD5C8, 4");
__asm__(".extern D_L24_001DD5D4, 4");
extern vu0_v4 D_L24_001D66B0 __attribute__((section(".sdata")));
extern void func_003C4C18(void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L24_0042C1C8(void *, s32, s32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);

typedef struct {
    u8 pad0[0x160];
    vu0_v4 v160;
    u8 pad170[0x200 - 0x170];
    f32 f200;
    f32 f204;
} S_0035B0D0;

s32 func_L24_0035B0D0(void *arg0) {
    u8 *a = arg0;
    S_0035B0D0 *s = *(S_0035B0D0 **)(a + 0x68);
    vu0_v4 pos;
    s32 found;
    s32 i = 0;

    pos = *(vu0_v4 *)(a + 0x10);
    pos.z += D_L24_001DD5C8;
    do {
        s->v160 = D_L24_001D66B0;
        i++;
        func_003C4C18(&s->v160, 4.0f);
        found = 0;
        s->v160.z = 0.0f;
        func_0038CF68(&s->v160, &s->v160, D_L24_001DD5D4);
        vec_add_ab(&s->v160, a + 0x10, &s->v160);
        s->v160.z += D_L24_001DD5C8;
        if (func_L24_0042C1C8(&s->v160, 0, 0, s->f200, s->f204) != 0) {
            found = func_003D3CB0(&pos, &s->v160, 2, a, 0) == 0;
        }
    } while (!found && i < 8);
    s->v160.z -= D_L24_001DD5C8;
    return found;
}
/* localdecomp:end func_L24_0035B0D0 */
