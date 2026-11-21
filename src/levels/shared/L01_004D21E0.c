#include "common.h"

typedef struct Obj_004CE458 Obj_004CE458;
typedef struct {
    u8 pad[8];
    void (*fn8)(Obj_004CE458 *);
} Vt_004CE458;
struct Obj_004CE458 {
    u8 pad[36];
    Vt_004CE458 *vt;
    u8 pad2[20];
};

/* localdecomp:start func_L01_004D21E0 */
extern s32 D_L01_001DFD60 __attribute__((section(".data")));
extern f32 D_L01_001DB76C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB76C, 4");
extern f32 D_L01_001DB770 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB770, 4");
extern f32 D_L01_001DB774 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB774, 4");
extern f32 D_L01_001DB778 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB778, 4");
extern s32 D_L01_001DB77C __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB77C, 4");
extern u32 D_L01_001DB780 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DB780, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_004D21E0(Obj_004CE458 (*base)[26], s32 row, s32 cx, s32 cy, s32 z) {
    u32 i;
    f32 a;
    s32 x, y;

    if (D_L01_001DFD60 != 0) {
        f32 fx = cx;
        f32 sx = D_L01_001DB76C;
        f32 fy = cy;
        f32 sy = D_L01_001DB770;
        f32 ox = D_L01_001DB774;
        f32 oy = D_L01_001DB778;

        for (i = 0; i < 8; i++) {
            a = (f32)i * 2.0f * 3.1415927f / (f32)D_L01_001DFD60 - 3.1415927f + 1.5707964f;
            x = fx + ox + (f32)(s32)(func_0038D098(a) * 74.0f * sx);
            y = fy + oy + (f32)(s32)(func_0038D0B0(a) * 74.0f * sy);
            if (i == D_L01_001DB780) {
                func_L01_004D2118(base, row, i, x, y + D_L01_001DB77C, z);
            } else {
                func_L01_004D2118(base, row, i, x, y, z);
            }
        }
    }
}
/* localdecomp:end func_L01_004D21E0 */
