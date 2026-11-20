#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003F7350);

/* localdecomp:start func_L01_003F7490 */
#include "vu0.h"

extern u8 *D_L01_001E0100_003F7490;
extern u8 *D_L01_001E012C_003F7490;
extern u8 *D_L01_001E0124_003F7490;
extern u8 *D_L01_001E011C_003F7490;
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);

s32 func_L01_003F7490(vu0_v4 p, u8 *o, f32 r) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 out;

    switch (*(s32 *)(o + 0x10)) {
    case 3: {
        u8 *m = D_L01_001E0100_003F7490 + *(s32 *)(o + 0x14) * 0x80;
        vec_sub_ab(&d, &p, m + 0x30);
        *(s32 *)&d.w = 0;
        func_0038D000(&out, &d, m + 0x40);
        return out.x >= -1.0f && out.x <= 1.0f && out.y >= -1.0f && out.y <= 1.0f &&
               out.z >= -1.0f && out.z <= 1.0f;
    }
    case 6: {
        u8 *m = D_L01_001E012C_003F7490 + *(s32 *)(o + 0x14) * 0x80;
        s32 result = 0;
        vec_sub_ab(&d, &p, m + 0x30);
        *(s32 *)&d.w = 0;
        func_0038D000(&out, &d, m + 0x40);
        if (func_0038CED8(&out) < 1.0f && out.z >= -1.0f && out.z <= 1.0f) {
            result = 1;
        }
        return result;
    }
    case 5: {
        u8 *m = D_L01_001E0124_003F7490 + *(s32 *)(o + 0x14) * 0x80;
        f32 s = func_0038CEA8(m) + r;
        return func_0038CF00(&p, m + 0x30) < s;
    }
    case 7: {
        u8 *m = D_L01_001E011C_003F7490 + *(s32 *)(o + 0x14) * 0x90;
        vec_sub_ab(&d, &p, m + 0x30);
        *(s32 *)&d.w = 0;
        func_0038D000(&out, &d, m + 0x40);
        if (func_0038CED8(&out) < 1.0f && out.z >= -1.0f && out.z <= 1.0f) {
            return 1;
        }
        t.x = 0.0f;
        t.y = 0.0f;
        t.z = 1.0f;
        t.w = 1.0f;
        func_0038D000(&out, &t, m);
        vec_add_ab(&out, &out, m + 0x30);
        vec_sub_ab(&t, &p, &out);
        if (func_0038CEA8(&t) < *(f32 *)(m + 0x80)) {
            return 1;
        }
        t.x = 0.0f;
        t.y = 0.0f;
        t.w = 1.0f;
        t.z = -1.0f;
        func_0038D000(&out, &t, m);
        vec_add_ab(&out, &out, m + 0x30);
        vec_sub_ab(&t, &p, &out);
        if (func_0038CEA8(&t) < *(f32 *)(m + 0x80)) {
            return 1;
        }
        return 0;
    }
    }
    return 0;
}
/* localdecomp:end func_L01_003F7490 */
