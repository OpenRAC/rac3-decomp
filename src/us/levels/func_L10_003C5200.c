#include "common.h"

/* NTSC-U counterpart of func_L10_003C75E8 (src/levels/10_zeldrin_starport/L10_003C7378.c): 0.02 -> 0.0166667; 37 -> 45 */
#include "vu0.h"

/* localdecomp:start func_L10_003C5200 */
#include "vu0.h"
typedef int u128_t_3C75E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C75E8;
typedef struct { u8 pad0[0x10]; u8 *f10; u8 pad14[0xD4 - 0x14]; u8 *fD4; } S_3C75E8;
__asm__(".extern D_L10_001DE930_003C5200, 4");
__asm__(".extern D_L10_001DE934_003C5200, 4");
__asm__(".extern D_L10_001DE938_003C5200, 4");
__asm__(".extern D_L10_001DE93C_003C5200, 4");
__asm__(".extern D_L10_001DE940_003C5200, 4");
__asm__(".extern D_L10_001DE944_003C5200, 4");
extern f32 D_L10_001DE930_003C5200;
extern f32 D_L10_001DE934_003C5200;
extern f32 D_L10_001DE938_003C5200;
extern f32 D_L10_001DE93C_003C5200;
extern f32 D_L10_001DE940_003C5200;
extern f32 D_L10_001DE944_003C5200;
extern S_3C75E8 D_L10_0021EC18;
extern u8 D_L10_001D66B0_003C5200[8];
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);

void func_L10_003C5200(u8 *m) {
    V4_3C75E8 p;
    V4_3C75E8 z;
    V4_3C75E8 up;
    s32 i;
    s32 col;
    u8 *e;

    if (func_L01_00444358(m, -1, 0) != 0) {
        func_0039FE80(0, 0, m);
        func_L01_0044ED60(m, 0xF, D_L10_001D66B0_003C5200, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, 0xFF, -1.0f, 0xB4, 0, 0, 0x23, 0, 3, 1.0f, 1.0f);
        *(u128_t_3C75E8 *)&up = 0;
        up.z = 1.0f;
        for (i = 0; i < 10; i++) {
            col = 0x7F00CF88;
            func_0037E2F0(&p, D_L10_001DE930_003C5200 * 0.2f, D_L10_001DE930_003C5200);
            vec_add_ab(&p, &p, m + 0x10);
            func_003886E8(&z, &up, func_0037E250(D_L10_001DE934_003C5200 * 0.5f, D_L10_001DE934_003C5200) * 0.0166666675f);
            if (func_0037E1D8(2) != 0) {
                col = 0x7F097A46;
            }
            e = func_L01_00472438(&p, &z, 0x2D, func_0037E208(-2, 2), col, 0xCF88, 0,
                                  D_L10_001DE938_003C5200 * 0.5f * 210000.0f, D_L10_001DE938_003C5200 * 210000.0f, D_L10_001DE940_003C5200);
            if (e != 0) {
                e[2] = *D_L10_0021EC18.f10;
                e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
            }
            if (func_0037E1D8(3) == 0) {
                e = func_L01_00472438(&p, &z, 0x2D, func_0037E208(-2, 2), 0x7F4DBE8A, 0x4DBE8A, 0,
                                      D_L10_001DE93C_003C5200 * 0.7f * 210000.0f, D_L10_001DE93C_003C5200 * 210000.0f, D_L10_001DE944_003C5200);
                if (e != 0) {
                    e[2] = *D_L10_0021EC18.fD4;
                    e[3] = func_0037E1D8(2) ? 0x48 : 0x44;
                }
            }
        }
        func_L01_0044EBF8(m, 1, 0.0f);
        func_003BD360(m);
    }
}
/* localdecomp:end func_L10_003C5200 */
