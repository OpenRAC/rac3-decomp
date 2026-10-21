#include "common.h"

typedef struct { u8 pad[0x30]; u8 x30[0x20]; s32 x50; u8 pad54[0x6C - 0x54]; f32 x6C; u8 pad70[8]; f32 x78; } V_3A1500;
typedef struct { u8 pad[0x68]; V_3A1500 *x68; u8 pad6C[0xF0 - 0x6C]; f32 xF0; } O_3A1500;

INCLUDE_ASM("asm/levels", func_L30_003A2C68);

INCLUDE_ASM("asm/levels", func_L30_003A2DE8);

/* localdecomp:start func_L30_003A2FA8 */
extern s32 D_L30_001DE944;
extern s32 D_L30_001DE948;
extern f32 D_L30_001DEA10;
extern u8 D_L30_001D66B0[];
extern u8 D_L30_001E1220[];
extern s32 func_L01_004561B8(O_3A1500 *);
extern s32 func_00382498(s32, s32);
extern void func_L30_0034D1E8(O_3A1500 *, void *, void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern int func_0038CAD0(void *);
extern void func_L30_003A2C68(O_3A1500 *, s32);
void func_L30_003A2FA8(O_3A1500 *a0) {
    V_3A1500 *v = a0->x68;
    if (func_L01_004561B8(a0)) {
        v->x50 = func_00382498(D_L30_001DE948, D_L30_001DE944);
    }
    func_L30_0034D1E8(a0, v->x30, v, D_L30_001D66B0, 1, 0, 0, 1, v->x6C, 0.0f, v->x78, v->x78, 0.0f, 0.0f);
    a0->xF0 = func_0038DAB8(a0->xF0, D_L30_001DEA10);
    if (D_L30_001E1220[0] != 0 || func_0038CAD0(&v->x50)) {
        func_L30_003A2C68(a0, 66);
    }
}
/* localdecomp:end func_L30_003A2FA8 */
