/* PAL near miss (haiku-w6): 17 words differ with the file's flags; the VU0 add helper is a local vadd_h_3091A8 with the swapped vadd operands (retail vf2 = vf2 + vf1); left: the -1 and 0x1010001 constants in $v0/$v1 swapped and the argument-move/store interleave of the two func_0044AF78 calls. */
#include "common.h"
/* localdecomp:start func_L01_003091A8 */
#include "vu0.h"
extern u8 D_001A4BE0[];
extern vu0_q D_L01_001EAA20[];
typedef struct { u8 pad[0x25C0]; void *moby; } Hero_003091A8;
static __inline__ void vadd_h_3091A8(void *d, void *a, void *b) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)b));
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)a));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qb) : "j"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qb));
}
void func_L01_003091A8(u8 *obj) {
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0044AF78(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, s32, f32, f32, f32, s32, s32, s32, s32, s32);
    extern void func_L01_003090E0(u8 *, u8 *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003C2880(void *);
    extern void func_L01_004471A8(void *, f32);
    struct { vu0_q old, direction, hit; } stack;
    Hero_003091A8 *hero;
    vu0_q *v;
    vu0_q *d;
    u8 *state;
    u8 *pos;
    state = *(u8 **)(obj + 0x68);
    pos = obj + 0x10;
    v = &stack.old;
    *v = *(vu0_q *)(obj + 0x10);
    stack.direction = 0;
    ((f32 *)&stack.direction)[2] = 0.1600000113248825f;
    func_00382760(state, *(f32 *)(state + 0x18), *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    vadd_h_3091A8(obj + 0x10, state, obj + 0x10);
    hero = (Hero_003091A8 *)D_001A4BE0;
    if (func_003D3CB0(v, pos, 0, hero->moby, 0) ||
        func_L01_003FB640(pos, 1, hero->moby, 0.3f)) {
        d = &stack.direction;
        stack.hit = D_L01_001EAA20[0];
        func_L01_0040E790(d, state, D_L01_001EAA20 + 2);
        func_0038CF68(d, d, 0.04000000283122063f);
        func_L01_0044AF78(obj, d, &stack.hit, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, -1, 9.0f, 0.4f, 0.0f, 0, 0, -1, 0, 0x1010001);
        func_L01_003090E0(obj, state, &stack.hit);
        goto destroy;
    }
    if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
        *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
        *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) goto destroy;
    if (*(s32 *)(state + 0x34) == 0 &&
        (func_0038CB00(state + 0x26) || *(f32 *)(state + 0x14) < 0.0f)) {
        func_L01_0044AF78(obj, &stack.direction, 0, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, -1, 9.0f, 0.4f, 0.0f, 0, 0, -1, 0, 0x1010001);
        goto destroy;
    }
    goto update;
destroy:
    func_003C2880(obj);
    return;
update:
    *(f32 *)(state + 0x14) -= *(f32 *)(state + 0x18);
    func_L01_004471A8(obj, 0.2f);
}
