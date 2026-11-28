#include "common.h"
/* localdecomp:start func_L01_00329678 */
#include "vu0.h"
extern u8 D_L01_001EAAC0[];
typedef struct {
    vu0_v4 velocity;
    f32 pitch, yaw;
    s16 timer, duration, scale, alpha;
    s32 colors[4];
    s32 kind, collide, texture;
    s16 a, b;
} Vars_00329AD0;
void func_L01_00329678(u8 *self) {
    extern f32 func_00389380(f32, f32);
    extern s32 func_003CE740(void *, void *, s32, void *, void *);
    extern void func_L01_0040C260(void *, void *, void *);
    extern f32 func_00388770(void *);
    extern void func_00388830(void *, void *, f32);
    extern void func_L01_0044E108(void *, void *, void *, f32);
    extern s32 func_0037E1D8(s32);
    extern f32 func_0037E250(f32, f32);
    extern void func_L01_00460318(void *, void *, s32, s32, s32, s32, s32, s32);
    extern void func_003BD360(void *);
    extern s32 func_003883C8(void *);
    Vars_00329AD0 *p = *(Vars_00329AD0 **)(self + 0x68);
    vu0_v4 temp;
    s32 quarter;
    s32 i;
    *(f32 *)(self + 0xF0) = func_00389380(*(f32 *)(self + 0xF0), p->pitch);
    *(f32 *)(self + 0xF4) = func_00389380(*(f32 *)(self + 0xF4), p->yaw);
    if (p->collide) {
        *(vu0_q *)&temp = *(vu0_q *)(self + 0x10);
        vec_add_ab(self + 0x10, self + 0x10, p);
        if (func_003CE740(&temp, self + 0x10, 16, self, 0)) {
            f32 speed;
            func_L01_0040C260(p, p, D_L01_001EAAC0);
            speed = func_00388770(p);
            func_00388830(p, p, speed * 0.800000012f);
        }
    } else {
        vec_add_ab(self + 0x10, self + 0x10, p);
    }
    func_L01_0044E108(self, p, p, (f32)p->alpha * 0.0078125f * 0.000277777785f);
    if (p->kind == 1) {
        if (func_0037E1D8(2)) {
            vu0_v4 random = {0};
            random.x = func_0037E250(-1.0f, 1.0f);
            random.y = func_0037E250(-1.0f, 1.0f);
            random.z = func_0037E250(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_00388830(&temp, &temp, 0.0166666675f);
            func_L01_00460318(self + 0x10, &temp, p->colors[func_0037E1D8(4)], 0, 0x2D, p->a, p->b, p->texture);
        }
    }
    if (p->kind == 4 || p->kind == 2) {
        for (i = 0; i < 3; i++) {
            vu0_v4 random = {0};
            random.x = func_0037E250(-1.0f, 1.0f);
            random.y = func_0037E250(-1.0f, 1.0f);
            random.z = func_0037E250(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_00388830(&temp, &temp, 0.0166666675f);
            func_L01_00460318(self + 0x10, &temp, p->colors[func_0037E1D8(4)], 0, 0x2D, p->a, p->b, p->texture);
        }
    }
    if (*(f32 *)(self + 0x10) < 0.0f || *(f32 *)(self + 0x14) < 0.0f || *(f32 *)(self + 0x18) < 0.0f) {
        func_003BD360(self);
        return;
    }
    quarter = p->duration / 4;
    if (p->timer < quarter)
        *(f32 *)(self + 0x2C) = (f32)p->scale * 0.0078125f * (f32)p->timer / (f32)quarter;
    if (func_003883C8(&p->timer)) {
        func_003BD360(self);
    }
}
/* localdecomp:end func_L01_00329678 */
