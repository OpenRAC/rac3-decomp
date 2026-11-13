#include "common.h"

/* localdecomp:start func_L30_003434E8 */
extern f32 func_0038CF00(void *, void *);
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_L30_00343798(u8 *, f32);

void func_L30_003434E8(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 0x68);
    f32 t;
    f32 r;
    s32 fl;
    f32 a;

    a = func_0038CF00(vars + 0x130, vars + 0x140);
    a = a / func_0038CF00(vars + 0x140, vars + 0x150);
    fl = *(s32 *)(vars + 0x194);
    t = a;
    r = 0.0f;
    if (fl) {
        r = 1.0f;
    }
    func_003C41A0(&t, vars + 0x164, r, *(f32 *)(vars + 0x170), *(f32 *)(vars + 0x174), *(f32 *)(vars + 0x178));
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    func_L30_00343798(moby, t);
}
/* localdecomp:end func_L30_003434E8 */

/* localdecomp:start func_L30_003435C0 */
extern u8 D_001A4C60[];

extern f32 func_0038CF00(void *, void *);
extern void func_L30_003434E8(u8 *);

void func_L30_003435C0(u8 *moby) {
    u8 *vars = *(u8 **)(moby + 104);
    int saved;
    f32 d;
    if (vars[439]) {
        saved = *(int *)(vars + 404);
    }
    d = func_0038CF00(D_001A4C60, vars + 320);
    *(int *)(vars + 404) = func_0038CF00(D_001A4C60, vars + 336) < d;
    func_L30_003434E8(moby);
    if (vars[439]) {
        *(int *)(vars + 404) = saved;
    }
}
/* localdecomp:end func_L30_003435C0 */
