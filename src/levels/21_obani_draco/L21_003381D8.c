#include "common.h"

/* declared by functions of L21_00336EF0.c, which this file was cut from */
extern s32 func_L01_0043B568(s32, s32, s32);

/* localdecomp:start func_L21_003381D8 */
#include "vu0.h"
extern s32 func_L01_0043B568(s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L21_00337BF0(void *arg0);
extern u8 *D_L21_001DED9C_003381D8;
extern u8 D_001A4BE0[];
extern vu0_v4 D_L21_001D66B0 __attribute__((section(".sdata")));
extern f32 D_L21_001DCF40;
__asm__(".extern D_L21_001DCF40, 4");
extern f32 D_L21_001DCF44;

typedef s32 (*Fn1_003381D8)(u8 *);

void func_L21_003381D8(void *arg0) {
    u8 *base;
    u8 *r;
    vu0_v4 pos;
    vu0_v4 rot;
    u8 *cam;

    base = D_L21_001DED9C_003381D8 + (*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x24) << 8);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    if (r == 0) {
        return;
    }
    if (((Fn1_003381D8)(*(void **)(r + 0x1C)))(base) != 0) {
        return;
    }
    cam = D_001A4BE0;
    pos.x = func_0038D098(func_0038DAB8(func_0038D160(*(f32 *)(cam + 0x80) - D_L21_001DCF40,
                                                      *(f32 *)(cam + 0x84) - D_L21_001DCF44), 3.1415927f)) * 9.0f;
    pos.y = func_0038D0B0(func_0038DAB8(func_0038D160(*(f32 *)(cam + 0x80) - D_L21_001DCF40,
                                                      *(f32 *)(cam + 0x84) - D_L21_001DCF44), 3.1415927f)) * 9.0f;
    pos.z = 0.0f;
    vec_add_ab(&pos, &D_L21_001DCF40, &pos);
    pos.z = func_003C3D30(&pos, 0, 0, 0.5f);
    rot = D_L21_001D66B0;
    rot.z = func_0038D160(D_L21_001DCF40 - pos.x, D_L21_001DCF44 - pos.y);
    ((void (*)(u8 *, s32, void *, void *))(*(void **)(r + 0xC)))(base, 3, &pos, &rot);
    ((void (*)(u8 *, s32))(*(void **)(r + 0x18)))(base, 3);
    ((void (*)(u8 *, s32))(*(void **)(r + 0x10)))(base, 1);
    func_L21_00337BF0(arg0);
}
/* localdecomp:end func_L21_003381D8 */
