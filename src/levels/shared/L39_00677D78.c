#include "common.h"

/* localdecomp:start func_L39_00677D78 */
typedef struct {
    u8 pad0[0x10];
    s32 f10;
} S_00677D78;
extern s32 func_003BDF18(void);
extern s32 func_0038CAD0(void *);
extern void func_003BE008(f32);
extern s32 D_L39_00240288_00677D78;
extern s32 D_L39_0024D028_00677D78;
extern f32 D_L39_0024D038_00677D78;
extern S_00677D78 D_L39_00352CE0_00677D78;

s32 func_L39_00677D78(s32 a0) {
    s32 r = 0;
    if (func_003BDF18() != 0) {
        (&D_L39_00240288_00677D78)[1] = 0;
    }
    switch (D_L39_0024D028_00677D78) {
    case 0:
        if (func_0038CAD0(&(&D_L39_0024D028_00677D78)[1]) != 0) {
            D_L39_0024D028_00677D78 = 1;
            (&D_L39_0024D028_00677D78)[1] = 0x4B;
        } else {
            (&D_L39_0024D038_00677D78)[1] = (f32)(&D_L39_0024D028_00677D78)[1] / 75.0f;
        }
        break;
    case 1:
        if (func_0038CAD0(&(&D_L39_0024D028_00677D78)[1]) != 0) {
            D_L39_0024D028_00677D78 = 2;
            (&D_L39_0024D028_00677D78)[1] = 0x19;
        }
        (&D_L39_0024D038_00677D78)[1] = 0.0f;
        break;
    case 2:
        if (func_0038CAD0(&(&D_L39_0024D028_00677D78)[1]) != 0) {
            r = a0;
        }
        (&D_L39_0024D038_00677D78)[1] = 1.0f - (f32)D_L39_00352CE0_00677D78.f10 / 25.0f;
        break;
    }
    func_003BE008(0.0f);
    return r;
}
/* localdecomp:end func_L39_00677D78 */
