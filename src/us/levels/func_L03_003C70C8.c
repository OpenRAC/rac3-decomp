#include "common.h"
/* localdecomp:start func_L03_003C70C8 */
#include "vu0.h"

extern s32 func_00388398(void *);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_003886C0(void *, void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern f32 D_L03_001DEEF0[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DEEF0, 4");
extern f32 D_L03_001DEF00[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DEF00, 4");
extern u8 D_L03_001D66B0[] __attribute__((section(".sdata")));

typedef struct { u8 pad[8]; f32 vel[2]; f32 pos[2]; s32 tm[2]; } M_3C8F78_003C8F78;

void func_L03_003C70C8(u8 *o) {
    M_3C8F78_003C8F78 *m = *(M_3C8F78_003C8F78 **)(o + 0x68);
    s32 i;
    f32 t;
    f32 s;
    vu0_v4 v;

    for (i = 0; i < 2; i++) {
        if (func_00388398(&m->tm[i])) {
            m->tm[i] = func_0037E208(0xC8, 0x190);
            m->pos[i] = 0.0f;
            m->vel[i] = func_0037E250(0.0166666675f, 0.0500000045f);
        }
        t = m->pos[i] += m->vel[i];
        if (t > 0.0f && t <= 1.0f) {
            func_003886C0(&v, D_L03_001DEEF0, D_L03_001DEF00, t);
            v.y += (f32)i * 0.3f;
            s = func_0037E250(0.3f, 0.7f);
            func_L01_00468DC0(&v, D_L03_001D66B0, 0x4010A090, s, 3, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
}
/* localdecomp:end func_L03_003C70C8 */
