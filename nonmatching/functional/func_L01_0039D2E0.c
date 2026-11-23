/* functional: high. Codex PAL draft re-checked in context: 51 words (same instruction mix and jal list) differs only in scheduling/register allocation/addressing, same calls in the same order.  */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec4_0039E0C8;
#include "vu0.h"
extern u8 *D_L01_002210F4[], *D_L01_0022123C[], *D_L01_00221120[];
void func_L01_0039D2E0(u8 *self)
{
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern void func_00382580(void *, f32, f32);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004C7D98(void *, void *);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(Vec4_0039E0C8 *, Vec4_0039E0C8 *, f32);
    extern void func_L01_00466F50(void *, void *, s32, f32, f32);
    vu0_v4 position, velocity, offset, direction;
    s32 life, spin;
    u8 *p;
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.035f, 0.05f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 84000.0f, 189000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_002210F4[0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.04f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 63000.00390625f, 42000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_0022123C[0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 10.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        life = func_00382498(10, 30);
        life *= 5;
        life += 2;
        life /= 6;
        spin = func_00382498(-1, -3);
        p = func_L01_004713C8(&position, &velocity, life, 0x5A182, spin, 64, 0, 0, 63000.00390625f, 21000.0f, 0.009600000455975533f);
        if (p) {
            p[3] = func_00382468(2) ? 0x48 : 0x44;
            p[2] = *D_L01_00221120[0];
        }
    }
    if (func_00382468(3) == 0) {
        func_00382580(&velocity, 0.01f, 0.03f);
        func_0038CE20((f32 *)&offset, (f32 *)&velocity, 20.0f);
        vec_add_ab(&position, &offset, self + 0x10);
        func_L01_004C7D98(self + 0x10, &direction);
        func_0038CF68((Vec4_0039E0C8 *)&direction, (Vec4_0039E0C8 *)&direction, -func_003824E0(0.01f, 0.05f));
        func_L01_00466F50(&position, &direction, 0x4005A182, -1.0f, -0.006000000052154064f);
    }
}
