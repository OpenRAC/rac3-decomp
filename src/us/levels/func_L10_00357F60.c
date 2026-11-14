#include "common.h"

/* NTSC-U counterpart of func_L10_00359238 (src/levels/10_zeldrin_starport/L10_003587D8.c): 0.1 -> 0.0833333 */
extern s32 func_0039FE80(s32, s32, void *);

/* localdecomp:start func_L10_00357F60 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_359238;
extern u8 *D_L10_001DF31C;
extern void func_L10_00358090(void *);
extern void func_L01_00441FB8(s32, s32, s32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L10_00357F60(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_359238 c;
    s32 i;

    func_L10_00358090(m);
    switch (m[0x20]) {
    case 1:
        i = v[0];
        if (i != -1 && *(D_L10_001DF31C + (i << 8) + 0x20) >= 0xFD) {
            func_L01_00441FB8((s32)m, 2, -1);
        }
        break;
    case 2:
        func_00388830(&c, m + 0xC0, 0.0833333358f);
        func_0039FE80(0, 0, m);
        func_L01_0044ED60(m, 0x3F, &c, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f,
                          3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L01_0044EBF8(m, 1, 0.0f);
        func_003BD360(m);
        break;
    }
}
/* localdecomp:end func_L10_00357F60 */
