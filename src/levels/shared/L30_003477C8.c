#include "common.h"

/* declared by functions of L30_003468C8.c, which this file was cut from */
extern void func_L30_0034CB68(u8 *, void *, int, int, int, int, f32, f32);

/* localdecomp:start func_L30_003477C8 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003477C8;
extern s32 D_001D545C;
extern V_003477C8 D_001A4C60;
extern s32 func_L30_0034D8D8(void *, f32);
extern void func_L30_00348240(u8 *);
extern void func_L30_003478F0(u8 *);
extern void func_L01_004450F0(void *, s32, s32);
void func_L30_003477C8(u8 *m) {
    u8 *v;
    V_003477C8 d;
    s32 t;

    v = *(u8 **)(m + 0x68);
    if (m[0x20] != 0x42 && func_L30_0034D8D8(m + 0x10, 1.4f)) {
        t = D_001D545C;
        if (t == 0x22 || t == 0x1E) {
            func_L30_00348240(m);
            t = D_001D545C;
        }
        if (t == 0x23) {
            func_L30_003478F0(m);
        }
    }
    if ((u8)(m[0x20] - 1) < 2) {
        vec_sub_ba(&d, &D_001A4C60, m + 0x10);
        func_L30_0034CB68(m, &d, 1, -1, (int)(m + 0x10), 1, 20.0f, *(f32 *)(v + 0x40));
    }
    if (func_L30_0034D8D8(m + 0x10, 1.5f) == 0 && m[0x20] == 2) {
        if (*(s32 *)(v + 0x68) & 1) {
            func_L01_004450F0(m, 0x42, -1);
        }
    }
}
/* localdecomp:end func_L30_003477C8 */

INCLUDE_ASM("asm/levels", func_L30_003478F0);

INCLUDE_ASM("asm/levels", func_L30_00347C20);

INCLUDE_ASM("asm/levels", func_L30_00347EF0);

INCLUDE_ASM("asm/levels", func_L30_00347FC8);
