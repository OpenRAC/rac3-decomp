/* functional: high. Same calls and stores as retail; the stack struct field order is the file's S_00527460 style and the vector helpers are the shared vu0.h ones, so only register allocation/scheduling can differ. */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00527A38;

typedef struct {
    V_00527A38 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_00527A38;

extern long func_L39_00589890(s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern V_00527A38 D_L39_0024AA30[];
extern T_00526280 D_L39_003B5140[];

void func_L39_00527A38(u8 *a0)
{
    S_00527A38 s;
    V_00527A38 mtx[3];
    V_00527A38 tmp;
    V_00527A38 c0;
    u8 *v;
    u8 *e;
    s32 id;
    s32 i;

    v = *(u8 **)(a0 + 0x68);
    e = *(u8 **)(v + 0x54);
    id = 0;
    if (e != 0) {
        id = *(s32 *)(e + 0x2544);
    }
    s.x78 = func_L39_00589890(11);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.c40 = 0x7F207F7F;
    s.c44 = 0x7F207F7F;
    s.c48 = 0x7F207F7F;
    s.c4C = 0x7F207F7F;
    s.x70 = 0;
    s.uv[0][0] = 0.0f;
    s.uv[0][1] = 0.0f;
    s.uv[1][0] = 0.0f;
    s.uv[1][1] = 1.0f;
    s.uv[2][0] = 1.0f;
    s.uv[2][1] = 0.0f;
    s.uv[3][0] = 1.0f;
    s.uv[3][1] = 1.0f;
    func_0038CF68(&tmp, a0 + 0xD0, -0.5f);
    vec_add_ab(&c0, &D_L39_003B5140[id].pos[0], &tmp);
    vec_sub_ab(&tmp, e + 0x23A0, &c0);
    func_0038CF68(&mtx[0], &tmp, 1.0f);
    func_0038CE90(&mtx[1], &mtx[0], e + 0x250);
    func_0038CF68(&mtx[1], &mtx[1], -1.0f);
    func_0038CE90(&mtx[2], &mtx[1], &mtx[0]);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&tmp, &D_L39_0024AA30[i], 0.4f);
        func_0038D028(&s.m[i], &tmp, &mtx[0]);
    }
    func_003D2DA0(&s, 0, 0);
    s.c40 = -1;
    s.c4C = -1;
    s.c48 = -1;
    s.c44 = -1;
    for (i = 0; i < 4; i++) {
        func_0038CE20(&tmp, &D_L39_0024AA30[i], 0.1f);
        func_0038D028(&s.m[i], &tmp, &mtx[0]);
    }
    func_003D2DA0(&s, 0, 0);
}
