#include "common.h"

/* declared by functions of L30_00343398.c, which this file was cut from */
extern void func_L30_00343798(u8 *, f32);

/* localdecomp:start func_L30_00343660 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00343660;
extern u8 D_001A4BE0[];
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);
extern void func_L30_0034C540(void *, void *, f32, f32, f32, s32);
extern void func_003C7DD8(void *);

void func_L30_00343660(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 x = *(f32 *)(m + 0x10);
    V_00343660 buf[10];
    f32 a, b;
    u8 *hero;

    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(m + 0xC0, m + 0xC0, *(f32 *)(v + 0x1A4));
    func_0038CE20(m + 0xD0, m + 0xD0, *(f32 *)(v + 0x1A8));
    func_0038CE20(m + 0xE0, m + 0xE0, *(f32 *)(v + 0x1AC));
    func_L30_00343AC8(m, buf, &a, &b);
    vec_sub_ab(m + 0x10, v + 0x130, &buf[0]);
    hero = D_001A4BE0;
    if (*(u8 **)(hero + 0x3C0) == m && *(u8 **)(hero + 0x35C) == m && *(s16 *)(hero + 0x36E) == 0 &&
        x != *(f32 *)(m + 0x10)) {
        V_00343660 t;
        qzero(&t);
        t.x = x - *(f32 *)(m + 0x10);
        vec_add_ab(hero + 0x370, hero + 0x370, &t);
    }
    func_L30_0034C540(&buf[1], v + 0x130, a + a, b + b, 0.0f, 0);
    func_003C7DD8(m);
    *(vu0_q *)(v + 0x70) = *(vu0_q *)(m + 0x10);
}
/* localdecomp:end func_L30_00343660 */

INCLUDE_ASM("asm/levels", func_L30_00343798);

INCLUDE_ASM("asm/levels", func_L30_00343830);

INCLUDE_ASM("asm/levels", func_L30_00343AC8);
