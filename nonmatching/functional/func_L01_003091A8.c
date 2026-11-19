/* functional: high. Draft verified against PAL assembly (bounds 2.0..1021.0, hit tests, impact effect call args and stack args, update step); 44 words differ in codegen only (register allocation). func_0038CF68 is declared with void* here; the file declares it later with S_0030CD20 pointers, so the typedef must be hoisted. */
extern u8 D_001A4BE0[];
extern vu0_q D_L01_001EAA20[];
typedef struct { u8 pad[0x25C0]; void *moby; } Hero_003091A8;
void func_L01_003091A8(u8 *obj) {
    extern void func_00382760(void *, f32, f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern s32 func_L01_003FB640(void *, s32, void *, f32);
    extern void func_L01_0040E790(void *, void *, void *);
    /* Near draft: the file declares this later with S_0030CD20 pointers.
     * That typedef must be visible here before the exact prototype can be used. */
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_0044AF78(void *, void *, void *, f32, f32, s32, s32, s32, f32, f32, s32, f32, f32, f32, s32, s32, s32, s32, s32);
    extern void func_L01_003090E0(u8 *, u8 *, void *);
    extern s32 func_0038CB00(void *);
    extern void func_003C2880(void *);
    extern void func_L01_004471A8(void *, f32);
    struct { vu0_q old, direction, hit; } stack;
    Hero_003091A8 *hero;
    vu0_q *v;
    u8 *state;
    u8 *pos;
    v = &stack.old;
    pos = obj + 0x10;
    *v = *(vu0_q *)(obj + 0x10);
    stack.direction = 0;
    ((f32 *)&stack.direction)[2] = 0.1600000113248825f;
    state = *(u8 **)(obj + 0x68);
    func_00382760(state, *(f32 *)(state + 0x18), *(f32 *)(obj + 0xF8), -*(f32 *)(obj + 0xF4));
    vec_add_ba(obj + 0x10, state, obj + 0x10);
    hero = (Hero_003091A8 *)D_001A4BE0;
    if (func_003D3CB0(v, pos, 0, hero->moby, 0) ||
        func_L01_003FB640(pos, 1, hero->moby, 0.3f)) {
        v = &stack.direction;
        stack.hit = D_L01_001EAA20[0];
        func_L01_0040E790(v, state, D_L01_001EAA20 + 2);
        func_0038CF68(v, v, 0.04000000283122063f);
        func_L01_0044AF78(obj, v, &stack.hit, 0.0f, 0.0f, 0, 0, 4, 0.0f, 0.0f, -1, 9.0f, 0.4f, 0.0f, 0, 0, -1, 0, 0x1010001);
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
