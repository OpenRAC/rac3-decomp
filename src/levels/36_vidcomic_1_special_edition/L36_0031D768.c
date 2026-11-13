#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L36_0031D768);

/* localdecomp:start func_L36_0031D878 */
__asm__(".extern D_L36_001DC7C8, 4");
__asm__(".extern D_L36_001DC7CC, 4");
__asm__(".extern D_L36_001DC7D0, 4");
__asm__(".extern D_L36_001DC7D4, 4");
__asm__(".extern D_L36_001DC7D8, 4");
__asm__(".extern D_L36_001DC7DC, 4");
__asm__(".extern D_L36_001DC7E0, 2");
__asm__(".extern D_L36_001DC7E4, 2");
__asm__(".extern D_L36_001DC7E8, 2");
__asm__(".extern D_L36_001DC7EC, 2");
__asm__(".extern D_L36_001DC7F0, 2");
__asm__(".extern D_L36_001DC7C0, 4");
__asm__(".extern D_L36_001DC7BC, 4");
__asm__(".extern D_L36_001DC7B8, 4");
extern f32 D_L36_001DC7C8;
extern s32 D_L36_001DC7CC;
extern s32 D_L36_001DC7D0;
extern s32 D_L36_001DC7D4;
extern s32 D_L36_001DC7D8;
extern s32 D_L36_001DC7DC;
extern s16 D_L36_001DC7E0;
extern s16 D_L36_001DC7E4;
extern s16 D_L36_001DC7E8;
extern s16 D_L36_001DC7EC;
extern s16 D_L36_001DC7F0;
extern f32 D_L36_001DC7C0;
extern f32 D_L36_001DC7BC;
extern f32 D_L36_001DC7B8;
extern u8 D_001A4C60[];
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, u8 *, s32, void *, f32);
extern s32 func_003D4D00(u8 *, s32, u8 *, void *, f32);
extern void func_003C2880(u8 *);
extern s32 func_L01_003303B8(f32, f32, f32, f32, u8 *, s32, s32, s32, s32, s32, s32, s32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_L36_0031D878(u8 *a0) {
    u8 obj[0x30];
    vu0_v4 v;
    func_L01_003303B8(D_L36_001DC7C8, 0.0f, 0.0f, 0.0f, 
                      a0 + 0x10, D_L36_001DC7CC, D_L36_001DC7D0, D_L36_001DC7D4, D_L36_001DC7D8, D_L36_001DC7DC, D_L36_001DC7E0, D_L36_001DC7E4,
                      D_L36_001DC7E8, D_L36_001DC7EC, D_L36_001DC7F0, 0, 1, 0, 0, 0,
                      0x804020, 0x806040, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F804020, 0x28802020, 0x602010, 0);
    vec_sub_ab(&v, D_001A4C60, a0 + 0x10);
    func_0038CF68(&v, &v, D_L36_001DC7C0);
    func_L01_00446760(obj, a0, 0x10001, &v, D_L36_001DC7BC);
    func_003D4D00(a0 + 0x10, 0x10001, a0, obj, D_L36_001DC7B8);
    func_003C2880(a0);
}
/* localdecomp:end func_L36_0031D878 */
