/* functional: medium. 203 words differ (916 vs 924 bytes; VU asm helpers cannot reproduce interleaved scheduling). */
#include "vu0.h"
extern u8 D_L01_001EAA40[];
typedef struct {
    vu0_v4 velocity;
    f32 pitch, yaw;
    s16 timer, duration, scale, alpha;
    s32 colors[4];
    s32 kind, collide, texture;
    s16 a, b;
} Vars_00329AD0;
void func_L01_00329AD0(u8 *self) {
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00451388(void *, void *, void *, f32);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_0038CB00(void *);
    Vars_00329AD0 *p = *(Vars_00329AD0 **)(self + 0x68);
    vu0_v4 temp;
    s32 quarter;
    s32 i;
    *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), p->pitch);
    *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), p->yaw);
    if (p->collide) {
        *(vu0_q *)&temp = *(vu0_q *)(self + 0x10);
        __asm__("lqc2 vf2, %0\n\t"
                "lqc2 vf1, %1\n\t"
                "vadd.xyz vf2, vf2, vf1\n\t"
                "sqc2 vf2, %0"
                : "+m"(*(vu0_v4 *)(self + 0x10))
                : "m"(*(vu0_v4 *)p)
                : "vf1", "vf2");
        if (func_003D3CB0(&temp, self + 0x10, 16, self, 0)) {
            f32 speed;
            func_L01_0040E790(p, p, D_L01_001EAA40);
            speed = func_0038CEA8(p);
            func_0038CF68(p, p, speed * 0.76f);
        }
    } else {
        __asm__("lqc2 vf1, %0\n\t"
                "lqc2 vf2, %1\n\t"
                "vadd.xyz vf1, vf1, vf2\n\t"
                "sqc2 vf1, %0"
                : "+m"(*(vu0_v4 *)(self + 0x10))
                : "m"(*(vu0_v4 *)p)
                : "vf1", "vf2");
    }
    func_L01_00451388(self, p, p, (f32)p->alpha * 0.0078125f * 0.0004000000189989805f);
    if (p->kind == 1) {
        if (func_00382468(2)) {
            vu0_v4 random = {0};
            random.x = func_003824E0(-1.0f, 1.0f);
            random.y = func_003824E0(-1.0f, 1.0f);
            random.z = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_0038CF68(&temp, &temp, 0.020000001415610313f);
            func_L01_004637C8(self + 0x10, &temp, p->colors[func_00382468(4)], 0, 0x25, p->a, p->b, p->texture);
        }
    }
    if (p->kind == 4 || p->kind == 2) {
        for (i = 2; i >= 0; --i) {
            vu0_v4 random = {0};
            random.x = func_003824E0(-1.0f, 1.0f);
            random.y = func_003824E0(-1.0f, 1.0f);
            random.z = func_003824E0(-1.0f, 1.0f);
            *(vu0_q *)&temp = *(vu0_q *)&random;
            func_0038CF68(&temp, &temp, 0.020000001415610313f);
            func_L01_004637C8(self + 0x10, &temp, p->colors[func_00382468(4)], 0, 0x25, p->a, p->b, p->texture);
        }
    }
    if (*(f32 *)(self + 0x10) < 0.0f || *(f32 *)(self + 0x14) < 0.0f || *(f32 *)(self + 0x18) < 0.0f) {
        func_003C2880(self);
        return;
    }
    quarter = p->duration / 4;
    if (p->timer < quarter)
        *(f32 *)(self + 0x2C) = (f32)p->scale * 0.0078125f * (f32)p->timer / (f32)quarter;
    if (func_0038CB00(&p->timer)) func_003C2880(self);
}
