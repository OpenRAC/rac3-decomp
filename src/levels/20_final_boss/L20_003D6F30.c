#include "common.h"

/* localdecomp:start func_L20_003D6F30 */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    u8 pad50[0x40];
} S_003D6F30;
typedef struct {
    u8 pad0[0x150];
    s16 h150;
    s16 h152;
} S_1CFEC0_003D6F30;

extern vu0_v4 D_L20_001E2E80;
extern S_1CFEC0_003D6F30 D_001CFEC0_003D6F30[];

extern void func_003C2F58(void *, s32, void *);
extern void func_L20_003D7220(void *, s32, s32, f32, f32, f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern void func_003A9440(s32 reg, long value);
extern void func_0038AF30(s32, s32, s32, s32, s32);

void func_L20_003D6F30(u8 *obj) {
    vu0_v4 p0;
    S_003D6F30 s;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    vu0_v4 e;
    vu0_v4 f;
    vu0_v4 g;
    vu0_v4 t;
    u8 *v = *(u8 **)(obj + 0x68);
    s32 color;

    func_003C2F58(obj, 3, &p0);
    func_L20_003D7220(&p0, 0x42, *(s32 *)(v + 0x2EC) * 5, 1.0f, 0.0f, 0.0f, 0.9f);
    a = p0;
    func_003C5180(&a, &b, 1);
    vec_sub_ba(&c, &D_L20_001E2E80, &a);
    func_0038CF68(&c, &c, 1.0f);
    func_0038CE20(&d, &b, 6.0f);
    vec_add_ab(&e, &a, &d);
    if (*(s32 *)(v + 0x2F0) != 0) {
        g = a;
        color = -1;
        if (*(s32 *)(v + 0x5E0) == 0) {
            color = 0xFF7C0030;
        } else if (*(s32 *)(v + 0x5E0) == 1) {
            color = 0xFF06065C;
        } else if (*(s32 *)(v + 0x5E0) == 2) {
            color = 0xFF007C30;
        }
        func_003D93B0(&s, 0xB, 0, 0x80);
        s.c[3] = color;
        s.c[2] = color;
        s.c[1] = color;
        s.c[0] = color;
        func_0038CE20(&t, &c, -0.1f);
        vec_add_ba(&g, &D_L20_001E2E80, &t);
        func_0038CE90(&f, &c, &b);
        func_0038CF68(&f, &f, 0.04f);
        func_0038CE90(&d, &f, &c);
        func_0038CF68(&d, &d, 0.04f);
        vec_add_ba(&e, &g, &d);
        vec_add_ab(&s.v[0], &e, &f);
        vec_sub_ab(&s.v[1], &e, &f);
        vec_sub_ab(&e, &g, &d);
        vec_add_ab(&s.v[2], &e, &f);
        vec_sub_ab(&s.v[3], &e, &f);
        func_003D2DA0(&s, 0, 0);
        if (*(s32 *)(v + 0x5E0) == 0) {
            color = 0x207C0030;
        } else if (*(s32 *)(v + 0x5E0) == 1) {
            color = 0x2006065C;
        } else if (*(s32 *)(v + 0x5E0) == 2) {
            color = 0x20007C30;
        }
        s.c[3] = color;
        s.c[2] = color;
        s.c[1] = color;
        s.c[0] = color;
        func_003A9440(0x42, 0x48);
        func_0038AF30(0, D_001CFEC0_003D6F30->h152, 0, D_001CFEC0_003D6F30->h150, s.c[0]);
    }
}
/* localdecomp:end func_L20_003D6F30 */

INCLUDE_ASM("asm/levels", func_L20_003D7220);

INCLUDE_ASM("asm/levels", func_L20_003D7558);

INCLUDE_ASM("asm/levels", func_L20_003D7950);

INCLUDE_ASM("asm/levels", func_L20_003D7CE0);

INCLUDE_ASM("asm/levels", func_L20_003D8248);
