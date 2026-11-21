/* functional: high. VU0 blocks as inline asm with named vf clobbers (file flags lack j class); scheduling differs only; callees func_0038CF00/func_0038CF68 and D_001D545C verified in asm */
/* VU0 helpers written with named vf clobbers (this file's flags lack the "j" register class) */
static __inline__ void qv_sub(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
static __inline__ void qv_add(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
extern s32 D_001D545C;
extern S_38C110v D_L01_001E1CE0;
extern S_38C110v D_L01_001E1CF0;
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_00367590(void) {
    f32 lim = 40.0f;
    S_38C110v v;

    if (D_001D545C == 11) {
        lim = 80.0f;
    }
    if (lim <= func_0038CF00(&D_L01_001E1CE0, &D_L01_001E1CF0)) {
        qv_sub(&v, &D_L01_001E1CF0, &D_L01_001E1CE0);
        func_0038CF68(&v, &v, D_001D545C == 11 ? 80.0f : 40.0f);
        qv_add(&D_L01_001E1CF0, &D_L01_001E1CE0, &v);
    }
}
