/* functional: high. none */
#include "common.h"
/* localdecomp:start func_L07_003C99A0 */
#include "vu0.h"
typedef struct { u8 pad[0x164]; u8 *value; } S_003C99A0;
extern S_003C99A0 D_L07_0021EC98;
void func_L07_003C99A0(u8 *obj) {
    extern void func_003C2F58(u8 *, s32, f32 *);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_00382498(s32, s32);
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_0046FB40(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
    vu0_v4 base;
    vu0_q pos;
    vu0_q vel;
    u8 *state = *(u8 **)(obj + 0x68);
    s32 n;
    if (*(f32 *)(state + 0x488) == 1.0f) *(vu0_q *)&base = *(vu0_q *)(state + 0x470);
    else {
        func_003C2F58(obj, state[0x4DC], (f32 *)&pos);
        vec_sub_ba(&base, state + 0x470, &pos);
        func_0038CE20(&base, &base, *(f32 *)(state + 0x488));
        vec_add_ab(&base, &pos, &base);
    }
    n = func_00382498(0, 2);
    if (n > 0) {
    vu0_q *pp = &pos;
    vu0_q *vp = &vel;
    s32 remaining = n;
    do {
        s32 kind = 0xFD;
        u8 b;
        s32 life;
        f32 speed, angle, pitch, size;
        u8 *p;
        *pp = *(vu0_q *)&base;
        func_003C4C18(pp, 0.3f);
        speed = func_003824E0(3.0f, 5.5f) * 0.020000001415610313f;
        angle = func_00382538();
        pitch = func_003824E0(1.0471975803375244f, 3.1415927410125732f);
        func_00382760(vp, speed, angle, pitch);
        if (!func_00382468(2)) kind = 3;
        b = func_00382468(256);
        life = (func_00382498(20, 40) * 5 + 2) / 6;
        size = func_003824E0(0.25f, 0.75f) * 210000.0f;
        p = func_L01_0046FB40(pp, vp, life, 0x806020, kind, 127, 0, 0, size, size, 0.003920000046491623f);
        size *= 0.3f;
        if (p) {
            p[2] = *D_L07_0021EC98.value;
            b = p[8] + 32;
        }
        p = func_L01_0046FB40(pp, vp, life, 0xFFFFFF, kind, 127, 64, 0, size, size, 0.003920000046491623f);
        if (p) {
            p[8] = b;
            p[2] = *D_L07_0021EC98.value;
        }
    } while (--remaining);
    }
}
/* localdecomp:end func_L07_003C99A0 */
