#include "common.h"

/* NTSC-U counterpart of func_L24_003503F0 (src/levels/24_insomniac_museum/L24_0034F040.c): 8 -> 10 */
/* localdecomp:start func_L24_0034F4D0 */
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_004479A8(void *, void *);
extern void func_003C4A40(void *, void *);
extern u8 D_L24_001E2200_0034F4D0[];
extern f32 D_001A65CC[];

void func_L24_0034F4D0(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *r;
    u8 *t;
    s32 h;

    if (obj[0x31] != 0) {
        if (func_L01_0040C018(D_L24_001E2200_0034F4D0, obj + 0x10) < 1024.0f) {
            func_L01_00444188(obj);
            obj[0x6F] = 0x1E;
        }
    }
    if (obj[0x95] != 0) {
        *(f32 *)(obj + 0x18) = *(f32 *)(s + 0x150);
        r = (u8 *)func_L01_00444358(obj, 1, 0);
        if (r != 0 && *(u8 **)(r + 0x20) != 0) {
            t = *(u8 **)(r + 0x20);
            h = *(s16 *)(t + 0xAA);
            if (h != 0x15D4 && h != 0) {
                if (t != *(u8 **)(s + 0x48) || *(s16 *)(s + 0x36) == 0) {
                    s[0x77] = 0xD2;
                    s[0x78] = 0xD2;
                    s[0x79] = 0xD2;
                    func_003C4A40(obj, s + 0x70);
                    *(f32 *)(s + 0x30) = *(f32 *)(s + 0x30) - *(f32 *)(r + 0x2C);
                    D_001A65CC[0] = *(f32 *)(s + 0x30);
                    if (*(f32 *)(s + 0x30) <= 0.0f) {
                        obj[0x95] = 6;
                    }
                    *(u8 **)(s + 0x48) = *(u8 **)(r + 0x20);
                    *(s16 *)(s + 0x36) = 10;
                }
            }
        }
        obj[0xA8] = 0xFF;
    } else {
        *(f32 *)(s + 0x150) = *(f32 *)(obj + 0x18);
    }
    func_L01_004479A8(obj, s + 0x70);
}
/* localdecomp:end func_L24_0034F4D0 */
