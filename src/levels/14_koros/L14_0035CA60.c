#include "common.h"
#include "vu0.h"

/* declared by functions of L14_0035C810.c, which this file was cut from */
extern s32 func_L14_0035CA60(u8 *, u8 *);
extern f32 D_L14_001DD6C0;

/* localdecomp:start func_L14_0035CA60 */
#include "vu0.h"
__asm__(".extern D_L14_001DD6BC, 4");
__asm__(".extern D_L14_001DD6B8, 4");
__asm__(".extern D_L14_001DD6C0, 4");
__asm__(".extern D_L14_001DD6C8, 4");
__asm__(".extern D_L14_001DD6C4, 4");
__asm__(".extern D_L14_001DD6CC_0035CA60, 4");
extern f32 D_L14_001DD6BC;
extern f32 D_L14_001DD6B8;
extern f32 D_L14_001DD6C0;
extern f32 D_L14_001DD6C8;
extern f32 D_L14_001DD6C4;
extern f32 D_L14_001DD6CC_0035CA60;
extern void func_003C41A0(f32 *, void *, f32, f32, f32, f32);
extern void func_0038CE20(f32 *, void *, f32);
typedef struct {
    u8 pad0[0x10];
    f32 x10;
    f32 x14;
    f32 x18;
    f32 x1C;
    u8 pad20[0xF0 - 0x20];
    f32 xF0;
} O_0035CA60;

s32 func_L14_0035CA60(u8 *a0, u8 *a1) {
    O_0035CA60 *o = (O_0035CA60 *)a0;
    f32 t;
    func_003C41A0((f32 *)(a1 + 0x14), a1 + 0xC, *(f32 *)(a1 + 0x10), D_L14_001DD6BC, D_L14_001DD6BC, D_L14_001DD6B8);
    func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
    vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
    t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
    o->x18 += t * D_L14_001DD6C8;
    o->xF0 = t * D_L14_001DD6C4;
    if (fabs_asm(*(f32 *)(a1 + 0x10) - *(f32 *)(a1 + 0x14)) < D_L14_001DD6CC_0035CA60) {
        *(f32 *)(a1 + 0x14) = *(f32 *)(a1 + 0x10);
        func_0038CE20((f32 *)(a0 + 0x10), a0 + 0xD0, *(f32 *)(a1 + 0x14));
        vec_add_ab(a0 + 0x10, a0 + 0x10, a1 + 0x30);
        t = fabs_asm(*(f32 *)(a1 + 0x14)) / D_L14_001DD6C0;
        o->x18 += t * D_L14_001DD6C8;
        o->xF0 = t * D_L14_001DD6C4;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L14_0035CA60 */
