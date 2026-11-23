/* functional: high. 46 diff = register assignment/scheduling only; verified all float constants (speeds, 94500/199500, 73500/52500, 73500/31500, 0.0096), loop counts (each runs once), call arg order and stores */
#include "common.h"
#include "vu0.h"
typedef struct {
    u8 pad0[0x5C];
    u8 *first;
    u8 pad60[0x88-0x60];
    u8 *third;
    u8 pad8C[0x1A4-0x8C];
    u8 *second;
} Assets_0038FCB8;
extern Assets_0038FCB8 D_L01_00221098;
void func_L01_0038FCB8(u8 *obj) {
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00466F50(void *, void *, u32, f32, f32);
    vu0_v4 position, velocity, offset, normal;
    s32 i, j, life;
    u8 *particle;
    for (i = 0; i >= 0; --i) {
        func_00382580(&velocity, 0.035f, 0.05f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
            : "=m"(position) : "m"(offset), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        life = func_00382498(10, 30) * 5 + 2;
        life /= 6;
        particle = func_L01_004713C8(&position, &velocity, life, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 94500.0f, 199500.0f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098.first;
        }
    }
    for (j = 0; j >= 0; --j) {
        func_00382580(&velocity, 0.01f, 0.04f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
            : "=m"(position) : "m"(offset), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        life = func_00382498(10, 30) * 5 + 2;
        life /= 6;
        particle = func_L01_004713C8(&position, &velocity, life, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 73500.0f, 52500.0f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098.second;
        }
    }
    for (j = 0; j >= 0; --j) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20(&offset.x, &velocity.x, 10.0f);
        __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0"
            : "=m"(position) : "m"(offset), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        life = func_00382498(10, 30) * 5 + 2;
        life /= 6;
        particle = func_L01_004713C8(&position, &velocity, life, 0x5A182,
                     func_00382498(-1, -3), 0x20, 0, 0, 73500.0f, 31500.001953125f, 0.0096f);
        if (particle) {
            particle[3] = func_00382468(2) ? 0x48 : 0x44;
            particle[2] = *D_L01_00221098.third;
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20(&offset.x, &velocity.x, 20.0f);
        __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
            : "=m"(position) : "m"(offset), "m"(*(vu0_v4 *)(obj + 0x10)) : "vf1", "vf2");
        func_L01_004C7D98(obj + 0x10, &normal);
        func_0038CF68(&normal, &normal, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&position, &normal, 0x4005A182, -1.0f, -0.004f);
    }
}
