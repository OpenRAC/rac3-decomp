#include "common.h"

/* localdecomp:start func_L03_003D0120 */
extern s32 func_L01_00447490(u8 *, s32, s32);
extern void func_L03_003D02A0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32);
void func_L03_003D0120(u8 *a0) {
    if (func_L01_00447490(a0, -1, 0)) {
        func_L03_003D02A0(a0, 15, 0, 0, 1, 0, 0, 0, 0xC050C020, -20.0f, 0.0f);
    }
}
/* localdecomp:end func_L03_003D0120 */

/* localdecomp:start func_L03_003D0190 */
typedef int u128_003D0190 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);

u8 *func_L03_003D0190(u8 *src, s32 cls, s32 flip) {
    f32 mat[4][4];
    u8 *m = func_003C24B0(cls, 0x80);
    if (m != 0) {
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(f32 *)(m + 0x2C) *= *(f32 *)(src + 0x2C) / *(f32 *)(*(u8 **)(src + 0x24) + 0x24);
        *(u128_003D0190 *)(m + 0x10) = *(u128_003D0190 *)(src + 0x10);
        if (flip != 0 && func_00382468(2) != 0) {
            func_0038D328(mat, src + 0xF0);
            func_0038D890(mat[1], mat[1], mat, 3.1415927f);
            func_0038D890(mat[2], mat[2], mat, 3.1415927f);
            func_003C48A8(mat, m + 0xF0);
        } else {
            *(u128_003D0190 *)(m + 0xF0) = *(u128_003D0190 *)(src + 0xF0);
        }
        *(long *)(m + 0x38) = *(long *)(src + 0x38);
        *(s16 *)(m + 0x34) = 0;
        func_003C7C38(m);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L03_003D0190 */
