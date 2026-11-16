#include "common.h"

/* NTSC-U counterpart of func_L39_005EBCB8 (src/levels/shared/L39_005EB698.c) */
extern s32 func_L01_00513698(void);
typedef struct { u8 pad[0x74]; s32 t[4][4]; } S_005EBAF0_A;
extern s32 D_L39_0024C990[] __attribute__((section(".sdata")));
extern S_005EBAF0_A D_001A5990;

/* localdecomp:start func_L39_005E9748 */
extern s32 D_L39_0024C990[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_00243E0C, 4");
__asm__(".extern D_L39_00243E10, 4");
__asm__(".extern D_L39_00243E14, 4");
extern f32 D_L39_00243E0C;
extern f32 D_L39_00243E10;
extern f32 D_L39_00243E14;
extern s32 func_L01_00513698(void);
extern s32 func_L01_00512568(s32, f32 *, f32 *);
extern s32 func_L01_00512480(s32, f32, f32);

void func_L39_005E9748(void) {
    f32 v[2];
    s32 i;
    f32 q;
    f32 s;
    f32 k1;
    f32 k2;
    f32 z;
    i = func_L01_00513698();
    k1 = 0.012f;
    k2 = 0.007f;
    z = 0.0f;
    v[0] = z;
    v[1] = z;
    q = (f32)D_001A5990.t[D_L39_0024C990[i]][i] / 100.0f;
    func_L01_00512568(0x54003D, &v[0], &v[1]);
    s = D_L39_00243E0C + D_L39_00243E14;
    v[0] = s + k2 + (D_L39_00243E10 - s - k1) * q;
    func_L01_00512480(0x54003D, v[0], v[1]);
}
/* localdecomp:end func_L39_005E9748 */
