#include "common.h"

/* NTSC-U counterpart of func_L09_003BE910 (src/levels/09_tyhrranosis/L09_003BE910.c) */
#include "vu0.h"
extern s32 func_003883C8(void *);

/* localdecomp:start func_L09_003BD098 */
extern u8 *D_L09_001E011C;
__asm__(".extern D_L09_001E011C, 16");
extern s32 func_003883C8(void *);
extern void func_003BDA38(void *, s32, void *);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388800(void *, void *);
extern void func_0037E4B8(void *, f32, f32, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_003CB388(u8 *, f32 *, f32 *, f32, u8);
typedef struct {
    u8 pad[0xD0];
    f32 v[4];
} S_003BE910;
extern S_003BE910 D_001A4BE0;

void func_L09_003BD098(u8 *a0, s32 a1, f32 *a2) {
    u8 *p = *(u8 **)(a0 + 0x68);
    u8 *e = D_L09_001E011C + (*(s32 *)(p + 0xCD0) << 8);
    f32 v0[4];
    f32 v1[4];
    f32 m[4];
    f32 ang;
    s32 i;
    s32 has;
    if (func_003883C8(p + 0xD36) == 0)
        return;
    i = 0;
    has = a2 != 0;
    for (; i < (a1 ? 2 : 1); i++) {
        func_003BDA38(e, i == 0 ? 9 : 0xD, v0);
        func_003BDA38(e, i == 0 ? 0xA : 0xE, v1);
        if (a2 == 0) {
            if (a1 != 0) {
                ang = func_00389380(func_00388A28(v1[0] - v0[0], v1[1] - v0[1]),
                                    i == 0 ? -0.43633232f : 0.43633232f);
            } else {
                ang = func_00388A28(v1[0] - v0[0], v1[1] - v0[1]);
            }
        } else {
            ang = func_00388A28(a2[0] - v0[0], a2[1] - v0[1]);
        }
        func_0037E4B8(m, 1.0f, ang,
                      func_00388A28(func_00388800(v1, D_001A4BE0.v), D_001A4BE0.v[2] - v1[2]));
        if (*(s16 *)(p + 0xD5A) == -1)
            *(s16 *)(p + 0xD5A) = func_0039FE80(0, 4, e);
        func_L01_003CB388(a0, v1, m, p[0x46], has);
    }
    *(s16 *)(p + 0xD36) = 3;
}
/* localdecomp:end func_L09_003BD098 */
