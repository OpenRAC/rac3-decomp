/* functional: high. Matrix rotate of a vector by (x,y,z) euler angles with the residual added to the vector at D_001A4C70-16; 18-word near miss (VU0 scheduling). Signature is (void *p, f32 x, f32 y, f32 z): the file's later `extern void func_L01_004E51A0(void *)` declaration and its caller must pass the three angles in f12-f14. */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_004E51A0;
extern Vec_004E51A0 D_001A4C70;
void func_L01_004E51A0(void *p, f32 x, f32 y, f32 z) {
    extern void func_0038D328(void *, void *);
    extern void func_0038D028(void *, void *, void *);
    extern void func_0038D640(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    Vec_004E51A0 input;
    Vec_004E51A0 before, after, delta;
    Vec_004E51A0 a[4], b[4], angles;
    Vec_004E51A0 *matrix = a;
    *(u128_t *)&input = *(u128_t *)p;
    func_0038D328(matrix, &D_001A4C70);
    func_0038D028(&before, &input, matrix);
    angles.v[0]=x; angles.v[1]=y; angles.v[2]=z;
    func_0038D328(b, &angles);
    func_0038D640(matrix, matrix, b);
    func_0038D028(&after, &input, matrix);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(before), "m"(after) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(*(Vec_004E51A0 *)((u8 *)&D_001A4C70-16))
        : "m"(*(Vec_004E51A0 *)((u8 *)&D_001A4C70-16)), "m"(delta) : "vf1", "vf2");
    func_003C48A8(matrix, &D_001A4C70);
}
