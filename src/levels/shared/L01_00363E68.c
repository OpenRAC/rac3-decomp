#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00363E68);

INCLUDE_ASM("asm/levels", func_L01_00364180);

INCLUDE_ASM("asm/levels", func_L01_003649E8);

INCLUDE_ASM("asm/levels", func_L01_00364C20);

INCLUDE_ASM("asm/levels", func_L01_00365E28);

/* localdecomp:start func_L01_003660B0 */
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} __attribute__((aligned(16))) S_38C110v;

extern void func_0038D328(s128 *, S_38C110v *);
extern void func_0038D640(s128 *, void *, s128 *);
extern void func_0038CE20(s128 *, s128 *, f32);
extern void func_L01_00365E28(s128 *, f32, f32, f32, s32, f32, s32, s32);

void func_L01_003660B0(S_38C110v *a0, void *a1, s32 a2, s32 a3, f32 f12, f32 f13, f32 f14, f32 f15, f32 f16, f32 f17) {
    S_38C110v v;
    s128 m1[4];
    s128 m2[4];

    v.x = 0.0f;
    v.y = 0.0f;
    v.z = f12;
    v.w = 1.0f;
    func_0038D328(m1, &v);
    func_0038D640(m2, a1, m1);
    func_0038CE20(&m2[0], &m2[0], f13);
    func_0038CE20(&m2[1], &m2[1], f13);
    func_0038CE20(&m2[2], &m2[2], f13);
    *(S_38C110v *)&m2[3] = *a0;
    func_L01_00365E28(m2, f17, f14, f15, a2, f16, a3, 1);
}
/* localdecomp:end func_L01_003660B0 */

/* localdecomp:start func_L01_003661D8 */
extern s16 D_L01_001E1B10;
extern void func_L01_00364180();
extern void func_L01_00404808(void *, void *);
void func_L01_003661D8(void *a0) {
    s32 i;
    if (D_L01_001E1B10 > 0) {
        for (i = 0; i < 10; i++) {
            if ((&D_L01_001E1B10)[i] > 64) {
                (&D_L01_001E1B10)[i] = 64;
            }
            (&D_L01_001E1B10)[i] -= 8;
        }
        func_L01_00404808(func_L01_00364180, a0);
    }
}
/* localdecomp:end func_L01_003661D8 */

INCLUDE_ASM("asm/levels", func_L01_00366240);

LINKER_REMNANT("asm/levels", func_L01_003663F0);

INCLUDE_ASM("asm/levels", func_L01_00366400);

INCLUDE_ASM("asm/levels", func_L01_00366BE0);

INCLUDE_ASM("asm/levels", func_L01_00366CD0);

INCLUDE_ASM("asm/levels", func_L01_00366DE0);

/* localdecomp:start func_L01_00366E48 */
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_0043A430(s32, s32, void *);
void func_L01_00366E48(s32 a, s32 *b, s32 *c, void *buf, s32 e) {
    *b = 0;
    *c = 0;
    func_0038CB78(buf, 0, 64);
    func_L01_0043A430(a, e, buf);
}
/* localdecomp:end func_L01_00366E48 */

INCLUDE_ASM("asm/levels", func_L01_00366EA8);

/* localdecomp:start func_L01_00366FC8 */
typedef struct {
    u8 pad[0x1200];
    u8 *p1200;
    u8 pad2[0x24];
    s32 mode1228;
} State_00366240;

extern State_00366240 D_001A4BE0;

s32 func_L01_00366FC8(void) {
    State_00366240 *s = &D_001A4BE0;
    if (s->mode1228 != 18 || s->p1200 == 0 || s->p1200[32] == 1 || s->p1200[32] == 5) {
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L01_00366FC8 */

INCLUDE_ASM("asm/levels", func_L01_00367018);

LINKER_REMNANT("asm/levels", func_L01_00367078);

INCLUDE_ASM("asm/levels", func_L01_00367080);

INCLUDE_ASM("asm/levels", func_L01_00367260);

INCLUDE_ASM("asm/levels", func_L01_00367430);

LINKER_REMNANT("asm/levels", func_L01_00367580);

INCLUDE_ASM("asm/levels", func_L01_00367590);

INCLUDE_ASM("asm/levels", func_L01_00367658);

INCLUDE_ASM("asm/levels", func_L01_00367688);

INCLUDE_ASM("asm/levels", func_L01_00367780);

INCLUDE_ASM("asm/levels", func_L01_00367EE0);

INCLUDE_ASM("asm/levels", func_L01_00368478);

INCLUDE_ASM("asm/levels", func_L01_003687C8);

INCLUDE_ASM("asm/levels", func_L01_00368B30);

LINKER_REMNANT("asm/levels", func_L01_003691D0);

INCLUDE_ASM("asm/levels", func_L01_003691D8);

LINKER_REMNANT("asm/levels", func_L01_003693E8);

INCLUDE_ASM("asm/levels", func_L01_003693F8);

INCLUDE_ASM("asm/levels", func_L01_00369700);

INCLUDE_ASM("asm/levels", func_L01_00369C48);

INCLUDE_ASM("asm/levels", func_L01_00369D80);

INCLUDE_ASM("asm/levels", func_L01_00369E28);

INCLUDE_ASM("asm/levels", func_L01_0036AA60);

INCLUDE_ASM("asm/levels", func_L01_0036AB88);

INCLUDE_ASM("asm/levels", func_L01_0036B078);

INCLUDE_ASM("asm/levels", func_L01_0036B440);
