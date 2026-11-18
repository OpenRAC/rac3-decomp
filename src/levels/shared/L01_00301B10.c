#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00301B10 */
extern vu0_v4 D_L01_001E29C0;
extern vu0_v4 D_001A4EC0;
extern f32 D_L01_001DC4F8;
__asm__(".extern D_L01_001DC4F8, 4");
extern f32 D_L01_001DC4FC;
__asm__(".extern D_L01_001DC4FC, 4");
extern s32 D_L01_001DC500;
__asm__(".extern D_L01_001DC500, 4");
extern s32 D_L01_001DC504;
__asm__(".extern D_L01_001DC504, 4");
extern s32 D_L01_001DC508;
__asm__(".extern D_L01_001DC508, 4");
extern s32 D_L01_001DC50C;
__asm__(".extern D_L01_001DC50C, 4");
extern f32 D_L01_001DC510;
__asm__(".extern D_L01_001DC510, 4");
extern f32 D_L01_001DC514;
__asm__(".extern D_L01_001DC514, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L01_00301B10(u8 *o) {
    vu0_v4 d;
    vu0_v4 v10;
    vu0_v4 v20;
    u8 *st;
    s32 color;

    vec_sub_ab(&d, &D_L01_001E29C0, o + 0x10);
    st = *(u8 **)(o + 0x68);
    func_0038CE20(&v10, &D_001A4EC0, func_003824E0(D_L01_001DC4F8 * 0.020000001f, D_L01_001DC4FC * 0.020000001f));
    func_0038D890(&v20, &v10, &d, func_00382538());
    if (st[0x57] != 0) {
        color = D_L01_001DC50C;
    } else {
        color = D_L01_001DC504;
    }
    func_L01_0046C470(o + 0x10, &v20, color, D_L01_001DC510, D_L01_001DC500, func_00382468(0xFF) & 0xFF, 1, 0x40, 0);
    func_L01_0046C470(o + 0x10, &v20, D_L01_001DC508, D_L01_001DC514, D_L01_001DC500, func_00382468(0xFF) & 0xFF, 1, 0x40, 0);
}
/* localdecomp:end func_L01_00301B10 */

INCLUDE_ASM("asm/levels", func_L01_00301C38);
