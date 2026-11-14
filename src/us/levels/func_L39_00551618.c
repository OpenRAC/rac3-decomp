#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_00551618 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_00551618 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00551618;

typedef struct E_00551618 {
    V_00551618 v0;
    V_00551618 v10;
    V_00551618 v20;
    V_00551618 v30;
    V_00551618 v40;
    s16 h50;
    s16 h52;
    s32 w54;
    s32 w58;
    f32 f5C;
} E_00551618;

extern E_00551618 D_L39_003C1120[];

extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);

void func_L39_00551618(u8 *o) {
    V_00551618 a;
    V_00551618 b;
    V_00551618 c;
    u8 *p;
    E_00551618 *e;

    p = *(u8 **)(o + 0x68);
    e = &D_L39_003C1120[p[0x3A]];
    func_00388830(&a, p, 1.0f);
    *(u128_t *)&b = 0;
    b.z = 1.0f;
    b.w = 1.0f;
    func_00388758(&c, &a, &b);
    func_00388830(&c, &c, 1.0f);
    func_00388758(&e->v40, &c, &a);
    *(u128_t *)&e->v30 = *(u128_t *)&a;
    *(u128_t *)&e->v0 = *(u128_t *)(o + 0x10);
    vec_add_ab(&e->v10, o + 0x10, p);
    e->w54 = 0;
    *(u128_t *)&e->v20 = *(u128_t *)&e->v10;
    e->h52 = 0x28;
    e->w58 = 0;
    e->f5C = 0.025f;
    e->h50 = 1;
}
/* localdecomp:end func_L39_00551618 */
