/* functional: high. near-miss (9 words VU scheduling) */
/* localdecomp:start func_L07_003B7408 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003B7408;
extern s32 D_L07_001DE480;
__asm__(".extern D_L07_001DE480, 8");
void func_L07_003B7408(void *a, void *b, f32 scale, f32 amount) {
    extern void func_003C2EC0(void *, void *, void *);
    extern void func_0038D890(void *, void *, void *, f32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_003C4C18(void *, f32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L01_0046E078(s32, void *, void *, void *, s32);
    Vec_003B7408 matrix[4];
    Vec_003B7408 direction, scaled, position, p, v;
    Vec_003B7408 *color = (Vec_003B7408 *)&D_L07_001DE480;
    s32 i = 0;
    func_003C2EC0(a, b, matrix);
    __asm__("lqc2 vf1, %1\n\tvsub.xyz vf1, vf0, vf1\n\tsqc2 vf1, %0"
        : "=m"(direction) : "m"(matrix[2]) : "vf1");
    func_0038D890(&direction, &direction, &matrix[1], amount);
    func_0038CF68(&direction, &direction, 1.0f);
    func_0038CE20(&scaled, &direction, scale);
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0"
        : "=m"(position) : "m"(matrix[3]), "m"(scaled) : "vf1", "vf2");
    do {
        p = position;
        func_003C4C18(&p, 0.1f);
        func_0038CE20(&v, &direction, func_003824E0(0.20000002f, 0.24000001f));
        func_L01_0046E078(0, &p, &v, color, i < 2);
        ++i;
        ++color;
    } while (i < 3);
}
/* localdecomp:end func_L07_003B7408 */
