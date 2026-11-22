#include "common.h"

/* localdecomp:start func_L41_0041B858 */
#include "vu0.h"
__asm__(".extern D_L41_00247748, 4");
extern s32 D_L41_00247748;
__asm__(".extern D_L41_0024774C, 4");
extern f32 D_L41_0024774C;
__asm__(".extern D_L41_00247750, 4");
extern f32 D_L41_00247750;
__asm__(".extern D_L41_00247754, 4");
extern f32 D_L41_00247754;
__asm__(".extern D_L41_00247758, 4");
extern f32 D_L41_00247758;
__asm__(".extern D_L41_0024775C, 4");
extern f32 D_L41_0024775C;
__asm__(".extern D_L41_00247760, 4");
extern f32 D_L41_00247760;
__asm__(".extern D_L41_00247764, 4");
extern f32 D_L41_00247764;
__asm__(".extern D_L41_00247768, 4");
extern f32 D_L41_00247768;
__asm__(".extern D_L41_0024776C, 4");
extern f32 D_L41_0024776C;
__asm__(".extern D_L41_00247770, 4");
extern f32 D_L41_00247770;
__asm__(".extern D_L41_00247774, 4");
extern f32 D_L41_00247774;
__asm__(".extern D_L41_00242930, 16");
extern vu0_v4 D_L41_00242930 __attribute__((section(".sdata")));
extern s32 func_L39_005BE900(vu0_v4 *, s32, f32);
extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L41_0041B350(vu0_v4 *, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L41_0041B6F0(vu0_v4 *);
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0xC0 - 0x20];
    vu0_v4 mC0;
    vu0_v4 mD0;
    vu0_v4 mE0;
} GeObj;
void func_L41_0041B858(GeObj *o) {
    vu0_v4 t;
    vu0_v4 p;
    vu0_v4 sum;
    vu0_v4 v;
    s32 i;

    t = o->pos;
    t.w = 5.0f;
    if (func_L39_005BE900(&t, 0, 128.0f) == -1) {
        return;
    }
    for (i = 0; i < D_L41_00247748; i++) {
        func_0038CE20(&v, &o->mC0, D_L41_00247768 + func_L39_005B4410(-D_L41_0024776C, D_L41_0024776C));
        vec_add_ab(&sum, &v, &D_L41_00242930);
        func_0038CE20(&v, &o->mD0, func_L39_005B4410(-D_L41_00247770, D_L41_00247770));
        vec_add_ba(&sum, &v, &sum);
        func_0038CE20(&v, &o->mE0, D_L41_00247764 + func_L39_005B4410(-D_L41_00247774, D_L41_00247774));
        vec_add_ba(&sum, &v, &sum);
        vec_add_ba(&p, &o->pos, &sum);
        func_L41_0041B350(&p, 3, 16.0f, D_L41_0024774C, D_L41_00247750, D_L41_00247754, D_L41_00247758,
                          D_L41_0024775C, D_L41_00247760);
        func_L41_0041B6F0(&p);
    }
}
/* localdecomp:end func_L41_0041B858 */
