/* func_L39_0053C248: near miss, 4 diff (Sonnet w3, p2w4). Size 84, 15 levels (39-53), src/levels/shared/L39_00537998.c
   Callee func_0038CE68 called K&R with 2 args (a2 passes through). Only diff: retail loads `lw $a1,0x68($a0)`
   between the lqc2s and the vsub (j-form interleave; levels lack -mvu0-use-vf0-vf2). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_53C248;
extern void func_0038CF68(void *dst, void *src, float value);
extern void func_0038CE68();

void func_L39_0053C248(char *self, V4_53C248 *base, void *arg)
{
    V4_53C248 d;
    V4_53C248 tmp;
    __asm__("lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(d) : "m"(*base), "m"(*(V4_53C248 *)(self + 0x10)));
    func_0038CF68(&tmp, (char *)*(char **)(self + 0x68) + 0x20, 1.0f);
    func_0038CE68(&d, &tmp);
}
