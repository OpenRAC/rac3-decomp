#include "common.h"

/* localdecomp:start func_L08_00308978 */
#include "vu0.h"

__asm__(".extern D_L08_001DC4CC, 4");
__asm__(".extern D_L08_001DC4D0, 4");
__asm__(".extern D_L08_001DC4D4, 4");
__asm__(".extern D_L08_001DC4D8, 4");
__asm__(".extern D_L08_001DC4DC, 4");
__asm__(".extern D_L08_001DC4E0, 4");
__asm__(".extern D_L08_001DC4E4, 4");
__asm__(".extern D_L08_001DC4E8, 4");
__asm__(".extern D_L08_001DC4EC, 4");
__asm__(".extern D_L08_001DC4F0, 4");
__asm__(".extern D_L08_001DC4F4, 4");
__asm__(".extern D_L08_001DC4F8, 4");
__asm__(".extern D_L08_001DC4FC, 4");
extern f32 D_L08_001DC4CC;
extern f32 D_L08_001DC4D0;
extern f32 D_L08_001DC4D4;
extern f32 D_L08_001DC4D8;
extern s32 D_L08_001DC4DC;
extern s32 D_L08_001DC4E0;
extern s32 D_L08_001DC4E4;
extern f32 D_L08_001DC4E8;
extern f32 D_L08_001DC4EC;
extern s32 D_L08_001DC4F0;
extern s32 D_L08_001DC4F4;
extern s32 D_L08_001DC4F8;
extern s32 D_L08_001DC4FC;
extern s32 D_L08_001DEDC0;
extern vu0_v4 D_L08_001E1CC0;

extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L01_0046C2E8(void *, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L08_00308978(u8 *o) {
    vu0_v4 pos, v10, v20, v30, v40;
    s32 i, j;
    s32 c;
    f32 q;

    *(vu0_q *)&pos = *(vu0_q *)(o + 0x10);
    if (func_00382468(4) == 0) {
        func_L01_00443B88(&v10, D_L08_001DC4CC * 0.020000001f, D_L08_001DC4D0 * 0.020000001f);
        i = 2;
        func_L01_0046C470(&pos, &v10, D_L08_001DC4E0, D_L08_001DC4E8, D_L08_001DC4DC, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        do {
            func_L01_00443B88(&v20, D_L08_001DC4D4 * 0.020000001f, D_L08_001DC4D8 * 0.020000001f);
            vec_add_ab(&v10, &v10, &v20);
            func_L01_0046C470(&pos, &v10, D_L08_001DC4E4, D_L08_001DC4EC, D_L08_001DC4DC, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        } while (--i >= 0);
    }
    vec_sub_ba(&v30, &D_L08_001E1CC0, &pos);
    func_0038CF68(&v30, &v30, -0.3f);
    func_0038CF68(&v40, &v30, 0.1f);
    vec_add_ab(&v30, &v30, &pos);
    for (j = 0; j < 4; j++) {
        s32 x = (D_L08_001DEDC0 + j * 20) & 0xFF;
        s32 r = func_0038DBD8(D_L08_001DC4F0, D_L08_001DC4F4, fabs_asm(0.5f - (f32)(212 - (x * 5 + 2) / 6) / 212.0f));
        c = *(u8 *)&D_L08_001DEDC0;
        if (j & 2) c = c << 1;
        if (j & 1) c = 255 - c;
        func_L01_0046C2E8(&v30, r, c & 0xFF, D_L08_001DC4FC, D_L08_001DC4F8, 2, 0,
                          0, ((f32)j + 3.0f) * (*(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24)));
        vec_add_ab(&v30, &v30, &v40);
    }
}
/* localdecomp:end func_L08_00308978 */

INCLUDE_ASM("asm/levels", func_L08_00308C30);
