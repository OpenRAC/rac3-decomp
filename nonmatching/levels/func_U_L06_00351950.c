/* Unlinked NTSC-U draft. 88 positional differences at the canonical level 06 placement. Joint output pointer, signed scale, and loop scheduling remain; level 14 has not been linked. */
#include "common.h"
#include "vu0.h"

__asm__(".extern D_L06_001DD320, 8");
__asm__(".extern D_L06_001DD330, 8");
__asm__(".extern D_L06_001DD338, 4");
extern s32 D_L06_001DD320[2];
extern s32 D_L06_001DD330[2];
extern s32 D_L06_001DD338;
extern void func_003BDA38(void *, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void *func_L06_00358938(void *, void *, void *, s32, f32);
extern void *func_L01_0046A9C8(void *, void *, void *, s32 *, s32);
extern void func_L06_00353B28(void *, void *, void *, s32);

/* localdecomp:start func_U_L06_00351950 */
void func_U_L06_00351950(u8 *m, u8 *p, s32 side) {
    vu0_v4 pos, dir, base, velocity, offset;
    vu0_v4 *where;
    s32 i;
    u8 *model;
    f32 scale;
    vu0_v4 *off;

    func_003BDA38(*(void **)(p + 0x260), D_L06_001DD320[side], &pos);
    model = *(u8 **)(p + 0x260);
    if (side == 0) {
        scale = -0.35f;
        off = &offset;
    } else {
        off = &offset;
        scale = 0.35f;
    }
    func_003886E8(off, model + 0xD0, scale);
    vec_add_ab(&pos, &offset, &pos);
    pos.z += 0.3f;
    func_003886E8(&dir, *(u8 **)(p + 0x260) + 0xC0, 0.2f);
    dir.z = 1.0f;
    func_00388830(&dir, &dir, 0.5f);
    func_L06_00358938(m, &pos, &dir, ((*(s32 *)(p + 0x35C) - 1) & 3) == 0, (f32)p[0x45]);
    func_003BDA38(*(void **)(p + 0x260), D_L06_001DD330[side], &base);
    where = &base;
    qzero(&velocity);
    velocity.z += -0.3f;
    for (i = 3; i >= 0; i--) {
        func_L01_0046A9C8(0, where, &velocity, &D_L06_001DD338, 1);
        func_003886E8(&velocity, &velocity, 0.75f);
    }
    func_L06_00353B28(m, p, where, 15);
}
/* localdecomp:end func_U_L06_00351950 */
