#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad[0x10];
    vu0_v4 pos;
} Obj_00482190;

/* localdecomp:start func_L40_00482190 */
#include "vu0.h"

extern vu0_v4 D_L40_0025B9A0;
extern vu0_v4 D_L40_0025B9B0;
extern u8 D_L40_0025B980[];

extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003FB640(void *, f32, s32, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);


s32 func_L40_00482190(Obj_00482190 *object, f32 *movement, s32 flags, f32 height, f32 radius, f32 offset) {
    vu0_v4 previous;
    vu0_v4 from;
    vu0_v4 to;
    vu0_v4 scaled;
    s32 mask = (flags << 1) & 0x20;
    s32 result = 0;
    s32 retries;
    f32 base;
    u8 *hit;

    previous = object->pos;
    vec_add_ab(&object->pos, &object->pos, movement);
    if (radius < func_0038CEA8(movement)) {
        from = previous;
        from.z += height;
        func_0038CF68(&scaled, movement, radius);
        vec_add_ab(&to, &scaled, &object->pos);
        to.z += height;
        if (func_003D3CB0(&from, &to, mask, object, 0)) {
            vec_sub_ba(&object->pos, &D_L40_0025B9A0, &scaled);
            result = 1;
            object->pos.z -= height;
        }
    }
    for (retries = 0; retries < 6; retries++) {
        from = object->pos;
        from.z += height;
        if (func_L01_003FB640(&from, radius, mask | 4, object)) {
            object->pos = D_L40_0025B9B0;
            result |= 1;
            object->pos.z -= height;
            continue;
        }
        break;
    }
    base = object->pos.z - offset;
    from = object->pos;
    to = object->pos;
    from.z += height;
    to.z = base - 0.05f;
    if (func_003D3CB0(&from, &to, mask | 2, object, 0)) {
        hit = D_L40_0025B980;
        if (*(s32 *)(hit + 0x1C) > 0) {
            result |= 2;
            if (func_0038D160(*(f32 *)(hit + 0x48), func_0038CED8(hit + 0x40)) > 0.5f)
                result |= 4;
            if (base < *(f32 *)(hit + 0x28))
                object->pos.z += (*(f32 *)(hit + 0x28) - base) * 0.3f;
        }
    }
    vec_sub_ab(movement, &object->pos, &previous);
    return result;
}
/* localdecomp:end func_L40_00482190 */

LINKER_REMNANT("asm/levels", func_L40_00482418);
