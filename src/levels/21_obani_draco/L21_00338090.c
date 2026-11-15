#include "common.h"

/* localdecomp:start func_L21_00338090 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 func_00382468(s32);
extern s32 func_L21_00337F08(void *, s32, s32);
extern s32 D_L21_001DED9C[];

void func_L21_00338090(void *arg0) {
    s32 base;
    s32 k;
    s32 a;
    s32 v;
    u8 *r;

    base = D_L21_001DED9C[0];
    base += *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 0x68)) + 0x24) << 8;
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    a = func_00382468(2);
    v = 1;
    if (a == 0) {
        v = -1;
    }
    v += ((s32 (*)(s32))(*(void **)(r + 0x2C)))(base);
    if (v >= 6) {
        v = 0;
    } else {
        if (v <= -1) {
            v = 5;
        }
    }
    func_L21_00337F08(arg0, v, 0);
}
/* localdecomp:end func_L21_00338090 */

/* localdecomp:start func_L21_00338150 */
extern s32 func_L01_0043B568(s32, s32, s32);
extern s32 D_L21_001DED9C[];
void func_L21_00338150(void *arg0) {
    u8 *r;
    s32 base;
    base = D_L21_001DED9C[0] + ((*(s32 *)(*(u8 **)((u8 *)arg0 + 0x68) + 0x24)) << 8);
    r = (u8 *)func_L01_0043B568(0x1BC5, 0, 0x44);
    if (((s32 (*)(s32))(*(void **)(r + 0x30)))(base) != 0) {
        return;
    }
    if (((s32 (*)(s32))(*(void **)(r + 0x34)))(base) != 0) {
        return;
    }
    ((void (*)(s32, s32))(*(void **)(r + 0x8)))(base, 0);
}
/* localdecomp:end func_L21_00338150 */
