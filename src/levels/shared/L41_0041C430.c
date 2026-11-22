#include "common.h"

/* localdecomp:start func_L41_0041C430 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct V_0041BB30 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_0041BB30;

extern s32 D_L41_002412DC;
__asm__(".extern D_L41_002412DC, 16");
extern s32 D_L41_002477A4;
extern f32 D_L41_002477AC;
extern f32 D_L41_002477B0;
extern f32 D_L41_002477B4;
extern f32 D_L41_002477B8;
extern f32 D_L41_002477A8;
extern s32 D_L41_00247798;
extern s32 D_L41_0024779C;
extern s32 D_L41_002477A0;

__asm__(".extern D_L41_002477A4, 4");
__asm__(".extern D_L41_002477AC, 4");
__asm__(".extern D_L41_002477B0, 4");
__asm__(".extern D_L41_002477B4, 4");
__asm__(".extern D_L41_002477B8, 4");
__asm__(".extern D_L41_002477A8, 4");
__asm__(".extern D_L41_00247798, 4");
__asm__(".extern D_L41_0024779C, 4");
__asm__(".extern D_L41_002477A0, 4");

extern f32 func_L39_005B4410(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_005C5FC8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L41_0041C430(void *o) {
    V_0041BB30 v;
    V_0041BB30 t;
    s32 flag;
    s32 c1;
    s32 c2;
    s32 i;

    flag = 0;
    if (D_L41_002412DC == 0x2D) {
        c1 = 0x7FE9D09F;
        c2 = 0x00E9D09F;
        flag = 1;
    } else {
        c1 = 0x7F325C66;
        c2 = 0x004C6C74;
    }
    for (i = 0; i < D_L41_002477A4; i++) {
        if (flag != 0 && (i & 1) == 0) {
            continue;
        }
        *(u128_t *)&t = 0;
        t.x = func_L39_005B4410(D_L41_002477AC, D_L41_002477B0);
        t.y = func_L39_005B4410(D_L41_002477AC, D_L41_002477B0);
        t.z = func_L39_005B4410(D_L41_002477B4, D_L41_002477B8);
        *(u128_t *)&v = *(u128_t *)&t;
        func_0038CF68(&v, &v, D_L41_002477A8 * 0.020000001f);
        func_L39_005C5FC8(o, &v, c1, c2, D_L41_00247798, D_L41_0024779C, D_L41_002477A0, 0);
    }
}
/* localdecomp:end func_L41_0041C430 */
