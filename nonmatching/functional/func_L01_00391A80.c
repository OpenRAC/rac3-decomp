/* functional: high. 79 diff = scheduling/addressing order only; draft's .sdata attribute dropped (retail uses lui/addiu), D_L01_0029EFA0 cast from file context type; verified 0x30 stride, 12 slots, 37.0 and 128.0, 0.04 */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_00391A80;
typedef struct { Vec_00391A80 pos; f32 angle, spin; s32 life; u8 *owner; u8 pad[0x10]; } Entry_00391A80;
void func_L01_00391A80(u8 *moby) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D890(f32 *, f32 *, f32 *, f32);
    extern void func_L01_00391BD0(u8 *, Vec_00391A80 *, s32);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_0038CAD0(void *);
    Vec_00391A80 velocity, position;
    Vec_00391A80 *out = &position;
    u8 *vars = *(u8 **)(moby+0x68);
    Entry_00391A80 *e;
    f32 alpha;
    s32 *life;
    e = (Entry_00391A80 *)D_L01_0029EFA0;
    life = &e->life;
    do {
        if (e->owner != moby) {
            e++;
        } else {
            func_0038CF68(&velocity, *(u8 **)(vars+0x18)+0xD0, 1.0f);
            alpha = (f32)e->life / 37.0f;
            func_0038D890((f32 *)out, (f32 *)&e->pos, (f32 *)&velocity, e->angle);
            func_L01_00391BD0(moby, out, (s32)(alpha*128.0f));
            e->angle = func_0038DAB8(e->angle, e->spin);
            func_0038CF68(&velocity, &velocity, 0.04f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(e->pos) : "m"(e->pos), "m"(velocity) : "vf1", "vf2");
            if (func_0038CAD0(life)) e->owner = 0;
            e++;
        }
        life += 12;
    } while ((s32)e < (s32)D_L01_0029EFA0 + 0x240);
}
