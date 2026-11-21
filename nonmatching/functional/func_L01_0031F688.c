/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 285 words differ in VU0 sequences and quad/UV loop allocation; renders via the game DMA quad helper (func_003D93B0/func_003D2DA0), not microcode; not byte-identical, behaviour as retail. */
typedef int TI_0031F688 __attribute__((mode(TI)));
typedef struct { f32 pos[4][4]; u32 color[4]; f32 uv[4][2]; u8 pad[0x18]; unsigned long flags; } __attribute__((aligned(16))) Quad_0031F688;
extern s32 D_001D52F0 __attribute__((section(".data")));
extern u8 D_L01_001E2A40[];
extern f32 D_L01_001D7C50[][4];
void func_L01_0031F688(void *at, s32 texture, s32 inset, f32 size, f32 offset, f32 rotation, f32 unused, f32 jitter) {
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D308(u8 *, u8 *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, s32);
    extern void func_003D2DA0(void *, s32, s32);
    extern void func_00389478(void *, void *, void *);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    Quad_0031F688 q;
    f32 basis[3][4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 shift[4] __attribute__((aligned(16)));
    f32 scratch[3][4] __attribute__((aligned(16)));
    f32 *v;
    f32 *corners;
    f32 *u;
    f32 *t;
    f32 *out_u;
    f32 *out_t;
    s32 i;
    func_003D93B0(&q, texture, 1, 128);
    *(TI_0031F688 *)pos = *(TI_0031F688 *)at;
    q.flags = 0x800000004A;
    q.color[0] = 0x80808080;
    q.color[3] = 0x80808080;
    q.color[2] = 0x80808080;
    q.color[1] = 0x80808080;
    q.uv[0][0] = 0; q.uv[0][1] = 0;
    q.uv[1][0] = 0; q.uv[1][1] = 1;
    q.uv[2][0] = 1; q.uv[2][1] = 0;
    q.uv[3][0] = 1; q.uv[3][1] = 1;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(TI_0031F688 *)(basis[0])) : "m"(*(TI_0031F688 *)(pos)), "m"(*(TI_0031F688 *)(D_L01_001E2A40 + D_001D52F0 * 0x460)) : "vf1", "vf2");
    func_0038CF68(basis[0], (s32)basis[0], 1.0f);
    func_0038CE90(basis[1], basis[0], (f32 *)(D_L01_001E2A40 + D_001D52F0 * 0x460 + 0x1D0));
    func_0038CF68(basis[1], (s32)basis[1], 1.0f);
    func_0038CE90(basis[2], basis[1], basis[0]);
    if (rotation != 0.0f) {
        *(TI_0031F688 *)shift = 0;
        shift[0] = rotation;
        func_0038D308((u8 *)scratch, (u8 *)shift);
        func_0038D5F0(basis[0], basis[0], scratch);
    }
    func_0038CE20(shift, basis[0], offset);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(TI_0031F688 *)pos) : "m"(*(TI_0031F688 *)pos), "m"(*(TI_0031F688 *)shift) : "vf1", "vf2");
    u = &q.uv[0][0]; t = &q.uv[0][1];
    v = q.pos[0];
    corners = D_L01_001D7C50[0];
    for (i = 3; i >= 0; i--) {
        func_0038CE20(v, corners, size);
        corners += 4;
        func_0038D028(v, v, basis[0]);
        v += 4;
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&q, 0, 0);
    if (inset) {
        *(TI_0031F688 *)scratch[0] = *(TI_0031F688 *)q.pos[0];
        v = q.pos[1];
        for (i = 2; i >= 0; i--) {
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(TI_0031F688 *)(scratch[0])) : "m"(*(TI_0031F688 *)(v)), "m"(*(TI_0031F688 *)(scratch[0])) : "vf1", "vf2");
            v += 4;
        }
        func_0038CE20(scratch[0], scratch[0], 0.25f);
        v = q.pos[0]; out_u = &q.uv[0][0]; out_t = &q.uv[0][1];
        for (i = 3; i >= 0; i--) {
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(TI_0031F688 *)(scratch[1])) : "m"(*(TI_0031F688 *)(scratch[0])), "m"(*(TI_0031F688 *)(v)) : "vf1", "vf2");
            func_0038CE20(scratch[1], scratch[1], 0.8f);
            __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(*(TI_0031F688 *)(scratch[1])) : "m"(*(TI_0031F688 *)(scratch[0])), "m"(*(TI_0031F688 *)(scratch[1])) : "vf1", "vf2");
            func_00389478(scratch[1], out_u, out_t);
            if (func_00382468(1) == 0) {
                *u += func_003824E0(-jitter, jitter);
                *t += func_003824E0(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*t > 1.0f) *t = 1.0f;
            else if (*t < 0.0f) *t = 0.0f;
            u += 2; t += 2; out_u += 2; out_t += 2; v += 4;
        }
    } else {
        v = q.pos[0]; out_u = &q.uv[0][0]; out_t = &q.uv[0][1];
        for (i = 3; i >= 0; i--) {
            func_00389478(v, out_u, out_t);
            if (func_00382468(1) == 0) {
                *u += func_003824E0(-jitter, jitter);
                *t += func_003824E0(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*t > 1.0f) *t = 1.0f;
            else if (*t < 0.0f) *t = 0.0f;
            u += 2; t += 2; out_u += 2; out_t += 2; v += 4;
        }
    }
    func_003D93B0(&q, -1, 1, 128);
    q.flags = 0x8000000054;
    func_003A9440(0x47, 0x33001);
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
