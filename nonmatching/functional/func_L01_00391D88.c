/* functional: high. 55 diff = div.s nop placement + scheduling; D_L01_0029F1E0 cast from file context type; verified offsets 0x28..0x44 and constants */
#include "common.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00391D88;
typedef struct {
    V_00391D88 position, velocity;
    u8 pad20[8];
    f32 goal, angle;
    s32 initial, current, unused38, remaining, duration;
    u8 *owner;
    u8 pad48[8];
} R_00391D88;
void func_L01_00391D88(u8 *obj) {
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038CF68(void *out, void *in, f32 length);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_0038CAD0(void *);
    R_00391D88 *r;
    u8 *vars = *(u8 **)(obj + 0x68);
    V_00391D88 change;
    s32 i;
    for (i = 0; i < 128; i++) {
        r = &((R_00391D88 *)D_L01_0029F1E0)[i];
        if (r->owner == obj) {
            r->current = (s32)((f32)r->initial * ((f32)r->remaining / (f32)r->duration));
            r->angle = func_0038DAB8(r->angle, r->goal);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(r->position) : "m"(r->velocity), "m"(r->position) : "vf1", "vf2");
            func_0038CF68(&change, *(u8 **)(vars + 0x18) + 0xD0, 1.0f);
            func_0038CE20((f32 *)&change, (f32 *)&change, -0.0009f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(r->velocity) : "m"(r->velocity), "m"(change) : "vf1", "vf2");
            if (func_0038CAD0(&r->remaining)) {
                if (r->current > 0) r->current--;
                else {
                    r->owner = 0;
                    (*(s32 *)vars)--;
                }
            }
        }
    }
}
