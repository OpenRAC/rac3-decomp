#include "common.h"

/* NTSC-U counterpart of func_L24_0034B930 (src/levels/24_insomniac_museum/L24_0034A2C8.c): 17 -> 20 */
/* localdecomp:start func_L24_0034AAE0 */
extern s32 func_L24_0034ABE0(void *);
extern void func_L01_004479A8(void *, void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_L01_004443B0(void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L24_00439040(u8 *, s32, s32, s32, f32, f32);

s32 func_L24_0034AAE0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    s32 r;
    s32 v;
    f32 f;

    if (obj[0x20] == 0) {
        if (func_L24_0034ABE0(obj) != 0) {
            return 1;
        }
    }
    func_L01_004479A8(obj, s + 0x160);
    r = func_L01_00444358(obj, 0x10000, 0);
    v = func_0038CB00(s + 0x36);
    f = func_L01_004443B0(obj, v != 0 ? r : 0);
    obj[0xA8] = 0xFF;
    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - f;
    if (*(f32 *)(s + 0x30) <= 0.0f) {
        if (obj[0x43] != 3) {
            func_003C3A10(obj, 3, 0, 0x14);
        }
        func_L01_00441FB8(obj, 0xE, 3);
    }
    func_L24_00439040(obj, *(s32 *)(s + 0x4A0), 0, 0, 30.0f, 10.0f);
    return 0;
}
/* localdecomp:end func_L24_0034AAE0 */
