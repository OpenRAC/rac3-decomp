#include "common.h"
#include "vu0.h"
#include "structs/moby.h"

/* NTSC-U counterpart of func_L06_00358938 (src/levels/shared/L06_00356C80.c): +0x1C takes the count as it is (no 50 Hz rescale), so the 1.0f store is the last one (it must be the last use of v for sched1), the $gp data 0x40 later */
/* localdecomp:start func_L06_00357C38 */
extern u8 *func_003BCFB0(s32 a, s32 b);
extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_003887A0(f32 *v);
extern void func_00388BD0(u8 *a, u8 *b);
extern s32 D_L06_001DD398;
__asm__(".extern D_L06_001DD398, 4");
extern f32 D_L06_001DD39C;
__asm__(".extern D_L06_001DD39C, 4");
extern s32 D_L06_001DD3AC;
__asm__(".extern D_L06_001DD3AC, 4");

struct Moby *func_L06_00357C38(struct Moby *a0, f32 *a1, f32 *a2, s32 a3, f32 f12, f32 f13) {
    struct Moby *m = (struct Moby *)func_003BCFB0(0x1738, 0x80);
    u8 *v;
    s32 n, k;
    f32 g;

    if (m != 0) {
        m->pad_30[0] = 0xFF;
        m->state = 0;
        m->draw_dist = 0xFF;
        m->pad_30[1] = 1;
        v = m->pvar;
        *(long *)((u8 *)m + 0x38) = *(long *)((u8 *)a0 + 0x38);
        *(vu0_q *)&m->position = *(vu0_q *)a1;
        *(vu0_q *)v = *(vu0_q *)a2;
        n = D_L06_001DD398;
        k = D_L06_001DD3AC;
        g = D_L06_001DD39C;
        *(s32 *)(v + 0x1C) = n;
        *(s32 *)(v + 0x28) = k;
        *(struct Moby **)(v + 0x18) = a0;
        *(s32 *)(v + 0x20) = a3;
        *(f32 *)(v + 0x14) = f13;
        *(f32 *)(v + 0x24) = g;
        *(f32 *)(v + 0x2C) = 1.0f;
        m->rotation.x = f12;
        m->rotation.z = func_00388A28(a2[0], a2[1]);
        m->rotation.y = -func_00388A28(func_003887A0(a2), a2[2]);
        func_00388BD0((u8 *)m->matrix, (u8 *)&m->rotation);
    }
    return m;
}
/* localdecomp:end func_L06_00357C38 */
