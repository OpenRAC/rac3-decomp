/* functional: high. Near-miss draft (compiles under file flags); 13 diff words, register choice only; fully verified against asm; allowed COP2 inline asm */
/* localdecomp:start func_L01_0034DBA8 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_0034DBA8;
void func_L01_0034DBA8(Vec_0034DBA8 *p, s32 n)
{
    Vec_0034DBA8 delta;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(p[n-2]), "m"(p[n-3]) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(p[n-1]) : "m"(p[n-2]), "m"(delta) : "vf1", "vf2");
}
/* localdecomp:end func_L01_0034DBA8 */
