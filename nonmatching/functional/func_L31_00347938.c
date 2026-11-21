/* functional: high. 41 words differ (scheduling only); needs the file's vu0 flag line (already set). Prototype differs from the unit's earlier declaration (void*, void*, s32, vu0_v4*, f32x7, s32): the asm passes four pointers and one int, so a2 is a vec pointer, not an s32. */
/* localdecomp:start func_L31_00347938 */
#include "vu0.h"
__asm__(".extern D_L31_001DCFCC, 4");
extern f32 D_L31_001DCFCC;
extern u8 D_L31_001E9180[];
extern vu0_v4 D_L31_001E91A0;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L31_00346838(void *, void *, void *, s32, f32, f32);
extern s32 func_L30_003445B8(u8 *);
extern s32 func_L30_00343830(u8 *, void *, void *, f32);
void func_L31_00347938(u8 *owner, vu0_v4 *pos, vu0_v4 *mv, vu0_v4 *axis, s32 flag, f32 range, f32 depth, f32 hi, f32 loT, f32 k, f32 kk, f32 zoff) {
    vu0_v4 s0, s10, s20, s30, s40, s50, s60;
    f32 lim, d;
    s32 hit, extra;
    u8 *moby;

    d = func_0038CE68(axis, mv);
    func_0038CE20(&s30, axis, d / func_0038CE68(axis, axis));
    vec_sub_ab(&s40, mv, &s30);
    hit = func_L31_00346838(owner, pos, axis, flag, range, zoff);
    if (hit != 0 && !(func_0038CE68(axis, &s30) < 0.0f)) {
        lim = depth;
        qzero(&s30);
    } else {
        vec_add_ab(&s30, &s30, axis);
        lim = hi;
    }
    if (lim < func_0038CEA8(&s40)) {
        func_0038CE20(&s40, &s40, 1.0f - k);
        func_0038CF68(&s60, &s40, kk);
        vec_sub_ab(&s40, &s40, &s60);
    }
    if (loT < func_0038CEA8(&s30)) {
        func_0038CE20(&s30, &s30, 1.0f - k);
        func_0038CF68(&s60, &s30, kk);
        vec_sub_ab(&s30, &s30, &s60);
    }
    vec_add_ab(mv, &s30, &s40);
    s10 = *pos;
    s10.z += zoff;
    vec_add_ab(&s0, &s10, mv);
    if (func_L01_003FB640(&s0, 2, owner, range + D_L31_001DCFCC) != 0) {
        moby = *(u8 **)(D_L31_001E9180 + 0x18);
        extra = 0;
        hit = 0;
        if (moby != 0) {
            u8 *o2 = 0;
            if (func_L30_003445B8(moby) == 0) {
                return;
            }
            if (func_L30_00343830(moby, &s60, &s10, range + D_L31_001DCFCC) == 0) {
                return;
            }
            if (*(u16 *)(moby + 0x34) & 0x20) {
                o2 = *(u8 **)(*(u8 **)(moby + 0x68) + 8);
            }
            if (o2 != 0 && func_0038CEA8(o2 + 0x10) > 0.0f) {
                vec_add_ab(&s0, &s0, o2 + 0x10);
                hit = 1;
            }
        }
        if (!(func_0038CF00(&D_L31_001E91A0, &s0) <= range) && hit == 0) {
            goto done;
        }
        vec_sub_ab(&s50, &s0, &D_L31_001E91A0);
        func_0038CF68(&s50, &s50, 1.0f);
        func_0038CF68(&s50, &s50, range);
        vec_add_ab(&s0, &s50, &D_L31_001E91A0);
    }
done:
    vec_sub_ab(&s20, &s0, &s10);
    s10 = s0;
    vec_add_ab(pos, &s20, pos);
}
/* localdecomp:end func_L31_00347938 */
