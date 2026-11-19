#include "common.h"

/* localdecomp:start func_L05_003DCBF0 */
typedef int u128_003DCBF0 __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern s32 func_00382468(s32);
extern void func_0038D328(void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_003C48A8(void *, void *);
extern void func_003C7C38(void *);

u8 *func_L05_003DCBF0(u8 *src, s32 cls, s32 kind) {
    f32 mat[4][4];
    u8 *m = func_003C24B0(cls, 0x80);
    if (m != 0) {
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x31] = 1;
        *(f32 *)(m + 0x2C) *= *(f32 *)(src + 0x2C) / *(f32 *)(*(u8 **)(src + 0x24) + 0x24);
        *(u128_003DCBF0 *)(m + 0x10) = *(u128_003DCBF0 *)(src + 0x10);
        if (func_00382468(2) != 0) {
            func_0038D328(mat, src + 0xF0);
            func_0038D890(mat[0], mat[0], mat[2], 3.1415927f);
            func_0038D890(mat[1], mat[1], mat[2], 3.1415927f);
            func_003C48A8(mat, m + 0xF0);
        } else {
            *(u128_003DCBF0 *)(m + 0xF0) = *(u128_003DCBF0 *)(src + 0xF0);
        }
        *(long *)(m + 0x38) = *(long *)(src + 0x38);
        *(s16 *)(m + 0x34) = 0;
        m[0x30] = kind;
        func_003C7C38(m);
        return m;
    }
    return 0;
}
/* localdecomp:end func_L05_003DCBF0 */
