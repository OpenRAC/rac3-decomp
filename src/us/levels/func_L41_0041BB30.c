#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L41_0041BB30 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_0041BB30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0041BB30;

extern s32 D_L41_0024145C;
extern s32 D_001DC094_sda;
extern f32 D_001DC09C_sda;
extern f32 D_001DC0A0_sda;
extern f32 D_001DC0A4_sda_0041BB30;
extern f32 D_001DC0A8_sda;
extern f32 D_001DC098_sda;
extern s32 D_001DC088_sda;
extern s32 D_001DC08C_sda;
extern s32 D_001DC090_sda;

__asm__(".extern D_001DC094_sda, 4");
__asm__(".extern D_001DC09C_sda, 4");
__asm__(".extern D_001DC0A0_sda, 4");
__asm__(".extern D_001DC0A4_sda_0041BB30, 4");
__asm__(".extern D_001DC0A8_sda, 4");
__asm__(".extern D_001DC098_sda, 4");
__asm__(".extern D_001DC088_sda, 4");
__asm__(".extern D_001DC08C_sda, 4");
__asm__(".extern D_001DC090_sda, 4");

extern f32 func_L39_005B2510(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L39_005C3D70(void *, void *, s32, s32, s32, s32, s32, s32);

/* Spawns a set of effect particles (func_L39_005C3D70) for a moby, each with a random velocity of
 * set length and two colours chosen by a global level id, skipping every other one for one level. */
void func_L41_0041BB30(void *o) {
    V_0041BB30 v;
    V_0041BB30 t;
    s32 flag;
    s32 c1;
    s32 c2;
    s32 i;

    flag = 0;
    if (D_L41_0024145C == 0x2D) {
        c1 = 0x7FE9D09F;
        c2 = 0x00E9D09F;
        flag = 1;
    } else {
        c1 = 0x7F325C66;
        c2 = 0x004C6C74;
    }
    for (i = 0; i < D_001DC094_sda; i++) {
        if (flag != 0 && (i & 1) == 0) {
            continue;
        }
        *(u128_t *)&t = 0;
        t.x = func_L39_005B2510(D_001DC09C_sda, D_001DC0A0_sda);
        t.y = func_L39_005B2510(D_001DC09C_sda, D_001DC0A0_sda);
        t.z = func_L39_005B2510(D_001DC0A4_sda_0041BB30, D_001DC0A8_sda);
        *(u128_t *)&v = *(u128_t *)&t;
        func_00388830(&v, &v, D_001DC098_sda * 0.016666668f);
        func_L39_005C3D70(o, &v, c1, c2, D_001DC088_sda, D_001DC08C_sda, D_001DC090_sda, 0);
    }
}
/* localdecomp:end func_L41_0041BB30 */
