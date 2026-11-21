/* functional: high. Draft verified against PAL assembly (10 samples t=i/9 along a bolt, noise 0.04, controls at +0x50/+0x60 offset by start and end); 73 words differ in codegen only. points[10] is left unwritten as in retail. func_0038CF68 is declared with void* here; the file declares it later with S_0030CD20 pointers, so that must be reconciled. */
void func_L01_00308508(s32 owner, vu0_v4 *start, vu0_v4 *end, u8 *controls) {
    extern void func_L01_00308238(void *, void *, void *, f32);
    extern void func_L01_003082D0(f32 *,f32 *,f32 *,f32 *,f32 *,f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003088D8(s32,s32,void *,s32);
    vu0_v4 points[11];
    vu0_v4 control0;
    vu0_v4 control1;
    vu0_v4 noise;
    vu0_v4 copy;
    s32 i;
    f32 t;
    for (i = 0; i < 10; i++) {
        t = (f32)i / 9.0f;
        func_L01_00308238(&points[i], start, end, t);
        *(vu0_q *)&control0 = *(vu0_q *)(controls + 0x50);
        *(vu0_q *)&control1 = *(vu0_q *)(controls + 0x60);
        vec_copy(&copy, end);
        vec_add_ba(&control0, &control0, start);
        vec_add_ab(&control1, &control1, &copy);
        func_L01_003082D0((f32 *)&points[i], (f32 *)start, (f32 *)end, (f32 *)&control0, (f32 *)&control1, t);
        noise.w = 0.0f;
        noise.x = func_003824E0(-1.0f, 1.0f);
        noise.y = func_003824E0(-1.0f, 1.0f);
        noise.z = func_003824E0(-1.0f, 1.0f);
        func_0038CF68(&noise, &noise, 0.04f);
        vec_add_ab(&points[i], &points[i], &noise);
    }
    func_L01_003088D8(owner, 0x80, points, 11);
}
