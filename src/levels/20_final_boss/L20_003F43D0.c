#include "common.h"

/* localdecomp:start func_L20_003F43D0 */
#include "vu0.h"

extern s32 D_L20_001E9C00[];
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

typedef struct {
    u8 pad0[0xC];
    f32 f0C;
    vu0_v4 pts[8];
    u8 pad90[8];
    f32 f98;
} St_003F43D0;

void func_L20_003F43D0(u8 *self)
{
    St_003F43D0 *st;
    vu0_v4 v;
    s32 i;
    f32 h;
    f32 z;
    f32 r;
    f32 a;

    st = *(St_003F43D0 **)(self + 0x68);
    z = func_003C3D30(self + 0x10, 0, 0, 3.0f);
    if (st->f0C == 0.0f && z != 0.0f) {
        func_0038CF68(st, D_L20_001E9C00, 1.0f);
        st->f0C = z;
    }
    h = st->f98 * 0.5f;
    for (i = 0; i < 8; i++) {
        qzero(&v);
        if (i < 3)
            r = func_003824E0(0.0f, h);
        else
            r = func_003824E0(h, st->f98);
        a = func_00382538();
        v.x = func_0038D098(a) * r;
        v.y = func_0038D0B0(a) * r;
        vec_add_ba(&st->pts[i], &v, self + 0x10);
        st->pts[i].w = r;
        st->pts[i].z = z;
    }
}
/* localdecomp:end func_L20_003F43D0 */
