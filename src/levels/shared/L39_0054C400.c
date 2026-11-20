#include "common.h"

/* declared by functions of L39_0054A250.c, which this file was cut from */
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x28 - 0x22];
    f32 f28;
    u8 pad2C[0x80 - 0x2C];
} T_0054A250;
extern s32 func_L39_00648AE0(void *, s32);
extern T_0054A250 D_L39_0049C890[];
typedef int u128_0054C2B0 __attribute__((mode(TI)));
extern void func_0038CE20(u128_0054C2B0 *, u128_0054C2B0 *, f32);

/* localdecomp:start func_L39_0054C400 */
#include "vu0.h"
typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[2];
    f32 f24;
    u8 pad28[0x58];
} E_0054C400;
typedef struct {
    u8 pad0[0x58];
    u8 *p58;
    f32 f5C;
} P_0054C400;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;
    u8 pad20[0x48];
    P_0054C400 *p68;
} M_0054C400;
extern u8 D_L39_00242930[8];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_L39_005B4398(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046FB40(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);

void func_L39_0054C400(M_0054C400 *m, vu0_v4 *from, s32 mode) {
    vu0_v4 base;
    vu0_v4 *bp = &base;
    vu0_v4 cur;
    vu0_v4 d;
    vu0_v4 r;
    vu0_v4 step;
    P_0054C400 *p;
    s32 h = 4;
    f32 len;
    f32 fn;
    f32 t;
    s32 n;
    s32 i;
    s32 c;

    *bp = *from;
    p = m->p68;
    len = (func_L39_00648AE0(p->p58, h) ? &((E_0054C400 *)D_L39_0049C890)[((E_0054C400 *)D_L39_0049C890)[h].b21] : &((E_0054C400 *)D_L39_0049C890)[h])->f24 *
          0.020000001f;
    n = len / 0.1f;
    switch (mode) {
    case 2:
        n = n * 0.6f;
        break;
    case 3:
        n = n * 0.3f;
        break;
    }
    fn = n;
    cur = *bp;
    vec_sub_ab(&d, &m->pos, bp);
    func_0038CF68(&d, &d, len / fn);
    func_0038CE20((u128_0054C2B0 *)&step, (u128_0054C2B0 *)&d, 1.0f / fn);
    for (i = 0; i < n; i++) {
        t = func_L39_005B4410(0.1f, 0.3f) * p->f5C;
        c = func_L39_005B4398(0xFF);
        func_L01_00443B88(&r, 0.0f, 0.1f);
        vec_add_ab(&r, &r, &cur);
        func_L01_0046FB40(&r, D_L39_00242930, 0xC, 0x80FFFFFF, c, 0x20, 0, t * 210000.0f, t * 0.2f * 210000.0f, 0.0f, 0);
        vec_add_ab(&cur, &cur, &step);
    }
}
/* localdecomp:end func_L39_0054C400 */
