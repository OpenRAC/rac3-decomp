#include "common.h"
/* localdecomp:start func_L01_00308F20 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern vu0_q D_L01_001EAAA0[];
typedef struct { u8 pad[0x25C0]; void *moby; } Hero_003091A8;
/* A shot's tick: move by its velocity (state+0x00); on a hit (a ray against the hero's moby, or
   func_L01_003F9498's test) throw blast pieces and damage, outside the 2..1021 box just die, and
   when its life (state+0x14) runs out without the stay flag (state+0x34) throw pieces and die. */
void func_L01_00308F20(u8 *obj) {
    extern void func_0037E4B8(vu0_v4 *, f32, f32, f32);
    extern s32 func_003CE740(void *, void *, s32, void *, s32);
    extern s32 func_L01_003F9498(void *, s32, void *, f32);
    extern void func_L01_0040C260(void *, void *, void *);
    extern void func_00388830(f32 *, f32 *, f32);
    extern void func_L01_00447D00(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, s32, f32, f32, f32, s32, s32, s32, s32, s32);
    extern void func_L01_00308E58(u8 *, u8 *, void *);
    extern s32 func_003883C8(void *);
    extern void func_003BD360(void *);
    extern void func_L01_00444070(void *, f32);
    struct { vu0_q old, direction, hit; } stack;
    Hero_003091A8 *hero;
    vu0_q *old;
    vu0_q *dir;
    u8 *state;
    u8 *pos;
    state = *(u8 **)(obj + 0x68);
    pos = obj + 0x10;
    old = &stack.old;
    *old = *(vu0_q *)(obj + 0x10);
    stack.direction = 0;
    ((f32 *)&stack.direction)[2] = 0.13333334f; /* 0x3E23D70B, one ulp above 0.13333334f */
    func_0037E4B8((vu0_v4 *)state, *(f32 *)(state + 0x18), *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    vec_add_ab(obj + 0x10, obj + 0x10, state);
    hero = (Hero_003091A8 *)D_001A4BE0;
    if (func_003CE740(old, pos, 0, hero->moby, 0) ||
        func_L01_003F9498(pos, 1, hero->moby, 0.3f)) {
        dir = &stack.direction;
        stack.hit = D_L01_001EAAA0[0];
        func_L01_0040C260(dir, state, D_L01_001EAAA0 + 2);
        func_00388830((f32 *)dir, (f32 *)dir, 0.0333333351f); /* 0x3D23D70B */
        func_L01_00447D00(obj, dir, &stack.hit, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, -1, 9.0f, 0.4f, 0.0f, 0, 0, -1, 0, 0x1010001);
        func_L01_00308E58(obj, state, &stack.hit);
        func_003BD360(obj);
        return;
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
        func_003BD360(obj);
        return;
    }
    if (*(s32 *)(state + 0x34) == 0 &&
        (func_003883C8(state + 0x26) || *(f32 *)(state + 0x14) < 0.0f)) {
        func_L01_00447D00(obj, &stack.direction, 0, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, -1, 9.0f, 0.4f, 0.0f, 0, 0, -1, 0, 0x1010001);
        func_003BD360(obj);
        return;
    }
    *(f32 *)(state + 0x14) -= *(f32 *)(state + 0x18);
    func_L01_00444070(obj, 0.2f);
}
/* localdecomp:end func_L01_00308F20 */
