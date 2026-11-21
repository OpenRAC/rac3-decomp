#include "common.h"

extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L01_00497210 */
extern s32 D_L01_001D91FC;
extern s32 D_L01_001D9200;
extern s32 D_L01_001D9204;
extern s32 D_L01_001D9208;
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
__asm__(".extern D_L01_001D91FC, 4");
__asm__(".extern D_L01_001D9200, 4");
__asm__(".extern D_L01_001D9204, 4");
__asm__(".extern D_L01_001D9208, 4");
__asm__(".extern D_L01_001D91B0, 4");
__asm__(".extern D_L01_001D91B4, 4");

void func_L01_00497210(s32 a, s32 b) {
    f32 *v = (f32 *)b;
    f32 w, h, nx, ny;
    s32 i;

    func_003E9270(0x470013, 0x332299DE, v[0], v[1], v[2], v[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8630(a, 0x470013);
    nx = v[0] + (f32)D_L01_001D9204 * 0.001953125f;
    ny = v[1] + (f32)D_L01_001D9208 / 416.0f;
    w = v[2] / 3.0f - (f32)D_L01_001D91FC * 0.001953125f;
    h = v[3] - (f32)D_L01_001D9200 / 416.0f;
    v[1] = ny;
    v[0] = nx;
    for (i = 0; i < 3; i++) {
        func_003E9138(i + 0x470014, 0x8066CCFF, 0, v[0] + w * (f32)(i - 1), v[1], w, h);
        func_L01_00516AA0(i + 0x470014, 0x40, 1);
        func_003E8630(a, i + 0x470014);
    }
}
/* localdecomp:end func_L01_00497210 */
