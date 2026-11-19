/* functional: high. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 26 words differ in VU0 interleaving and loop address scheduling; not byte-identical, behaviour as retail. */
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_00321710;
__asm__(".extern D_L01_001DC940, 4");
__asm__(".extern D_L01_001DC948, 4");
__asm__(".extern D_L01_001DC978, 4");
extern s32 D_L01_001DC940;
extern f32 D_L01_001DC948;
extern f32 D_L01_001DC978;
extern End_00321608 D_L01_00276A30[];
extern Vec_00321710 D_L01_00276A30_00321710[];
extern Vec_00321710 D_L01_002769C0[];
extern Vec_00321710 D_L01_002762C0_00321710[][16];
void func_L01_00321710(u8 *gun) {
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);
    extern f32 func_003824E0(f32, f32);
    Vec_00321710 v;
    u8 *vars = *(u8 **)(gun + 0x68);
    s32 i, j, next;
    for (i = 0; i < D_L01_001DC940; i = next) {
        s32 offset = i * 16;
        Vec_00321710 *end = &D_L01_00276A30_00321710[i];
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(v) : "m"(*(Vec_00321710 *)(vars + 16)), "m"(*end) : "vf1", "vf2");
        func_0038CF68(v.f, (s32)&v, D_L01_001DC948);
        next = i + 1;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
                : "=m"(v) : "m"(*end), "m"(v) : "vf1", "vf2");
        {
        Vec_00321710 *p = (Vec_00321710 *)((i << 8) + (s32)D_L01_002762C0_00321710);
        for (j = 0; j < 16; j++, p++) {
            f32 t = j * 0.0625f;
            if (j == 15) t = 1.0f;
            func_L01_00445208(p, vars + 16, (void *)(offset + (s32)D_L01_00276A30), (void *)(offset + (s32)D_L01_002769C0), &v, t);
            p->f[0] += func_003824E0(-D_L01_001DC978, D_L01_001DC978);
            p->f[1] += func_003824E0(-D_L01_001DC978, D_L01_001DC978);
            p->f[2] += func_003824E0(-D_L01_001DC978, D_L01_001DC978);
        }
        }
    }
}
