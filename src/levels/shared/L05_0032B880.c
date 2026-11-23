#include "common.h"

/* localdecomp:start func_L05_0032B880 */
typedef int u128_0032B880 __attribute__((mode(TI)));

extern u8 *func_003C24B0(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_003C7C38(void *);

u8 *func_L05_0032B880(void *pos, void *vel, s32 col, f32 f) {
    u8 *obj;
    u8 *p;

    obj = func_003C24B0(0x184D, 0x80);
    if (obj != 0) {
        obj[0x30] = 0xFF;
        *(s16 *)(obj + 0x32) = 0x1FF;
        obj[0x23] = 0x60;
        obj[0x31] = 1;
        p = *(u8 **)(obj + 0x68);
        obj[0x20] = 0;
        if (col != 0) {
            *(s32 *)(obj + 0xB8) = col;
        }
        *(u128_0032B880 *)(obj + 0x10) = *(u128_0032B880 *)pos;
        *(u128_0032B880 *)p = *(u128_0032B880 *)vel;
        *(f32 *)(p + 0x20) = f;
        *(s32 *)(p + 0x10) = 25;
        *(s32 *)(p + 0x18) = 250;
        *(s32 *)(p + 0x14) = 0;
        *(f32 *)(obj + 0xF0) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(obj + 0xF4) = func_003824E0(-3.1415927f, 3.1415927f);
        *(f32 *)(obj + 0xF8) = func_003824E0(-3.1415927f, 3.1415927f);
        *(s32 *)(obj + 0xFC) = 0;
        func_003C7C38(obj);
    }
    return obj;
}
/* localdecomp:end func_L05_0032B880 */
