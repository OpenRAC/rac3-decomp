/* functional: high. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 6 words differ in VU0 scheduling only; not byte-identical, behaviour as retail. */
typedef int Q_0031DE80 __attribute__((mode(TI)));
typedef union { Q_0031DE80 q; f32 f[4]; } V_0031DE80;
void func_L01_0031DE80(u8 *obj) {
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_004C7D40(u8 *, u8 *, f32);
    extern void func_L01_004CAB30(u8 *, u8 *);
    extern void func_L01_004C8688(s32, u8 *, s32);
    extern void func_L01_0031DFD8(u8 *, void *);
    extern s32 func_0038DC20(void *, f32);
    extern s32 func_0038CAD0(s32);
    extern void func_L01_004C8668(s32);
    extern void func_003C2880(Moby_0031BEF0 *);
    extern void func_L01_00404A10(void *, u8 *);
    extern void func_L01_0031E148(u8 *);
    V_0031DE80 old, sphere;
    u8 *vars = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        obj[0x20] = 1;
    case 1:
        old.q = *(Q_0031DE80 *)(obj + 0x10);
        __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
            : "=m" (*(Q_0031DE80 *)(obj + 0x10))
            : "m" (*(Q_0031DE80 *)(obj + 0x10)), "m" (*(Q_0031DE80 *)vars)
            : "vf1", "vf2");
        func_L01_004C7D40(obj + 0x10, vars, func_003824E0(4.0f, 7.0f) * 0.00040000002f);
        func_L01_004CAB30(obj + 0x10, obj + 0x10);
        func_L01_004C8688(*(s32 *)(vars + 0x1C), vars, 0);
        func_L01_0031DFD8(obj, &old);
        sphere.q = *(Q_0031DE80 *)(obj + 0x10);
        sphere.f[3] = 0.1f;
        if (func_0038DC20(&sphere, 96.0f) > 0) {
            if (func_0038CAD0((s32)(vars + 0x10))) obj[0x20] = 2;
            break;
        }
    case 2:
        func_L01_004C8668(*(s32 *)(vars + 0x1C));
        func_003C2880((Moby_0031BEF0 *)obj);
        return;
    }
    func_L01_00404A10(func_L01_0031E148, obj);
}
