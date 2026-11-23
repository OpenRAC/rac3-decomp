/* NTSC-U native near miss: 2 instruction words differ. The particle call moves
 * its integer and float arguments in the opposite order. The 1/60 frame step
 * and unscaled NTSC-U lifetime are restored; no register pin or barrier.
 * Not linked and not counted as a match.
 */
#include "common.h"

/* localdecomp:start func_U_L08_0037B8B8 */
#include "vu0.h"

typedef struct V_0037CE30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0037CE30;

extern u8 *D_L08_0021EBA0[];

extern s32 func_U_L08_00422D38(s32);
extern f32 func_U_L08_00422DB0(f32, f32);
extern f32 func_U_L08_00422E68(void);
extern f32 func_U_L08_003EF678(f32);
extern f32 func_U_L08_003EF690(f32);
extern s32 func_U_L08_00422D68(s32, s32);
extern void func_U_L08_003EF580(void *, void *, void *);
extern u8 *func_U_L08_0044B380(void *, void *, u32, s32, f32, s32, s32, s32, s32);

void func_U_L08_0037B8B8(void *ov) {
    u8 *o = ov;
    V_0037CE30 a;
    V_0037CE30 b;
    u8 *p;
    u8 *q;
    f32 ang;
    f32 s;
    f32 sz;
    s32 life;

    p = *(u8 **)(o + 0x68);
    if (func_U_L08_00422D38(*(s32 *)(p + 0x20)) != 0) {
        return;
    }
    qzero(&b);
    b.z = func_U_L08_00422DB0(*(f32 *)p, *(f32 *)(p + 4)) * 0.0166666675f;
    func_U_L08_003EF580(&b, &b, o + 0xC0);
    ang = func_U_L08_00422E68();
    s = func_U_L08_00422DB0(*(f32 *)(p + 0x18), *(f32 *)(p + 0x1C));
    a.x = func_U_L08_003EF678(ang) * s;
    a.y = func_U_L08_003EF690(ang) * s;
    a.z = 0.0f;
    func_U_L08_003EF580(&a, &a, o + 0xC0);
    vec_add_ba(&a, &a, o + 0x10);
    life = func_U_L08_00422D68(*(s32 *)(p + 0x10), *(s32 *)(p + 0x14));
    sz = func_U_L08_00422DB0(*(f32 *)(p + 8), *(f32 *)(p + 0xC));
    q = func_U_L08_0044B380(&a, &b, 0x4F808080, life, sz, func_U_L08_00422D38(0xFF) & 0xFF, 0, 0x40, 0);
    if (q != 0) {
        q[2] = *D_L08_0021EBA0[0];
        q[9] = ((*(s32 *)(p + 0x28) >> 5) << 4) + 4;
    }
}
/* localdecomp:end func_U_L08_0037B8B8 */
