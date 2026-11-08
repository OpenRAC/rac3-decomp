/* func_L01_00448F30: near miss, 2 diff (Sonnet w3, p2w4). Size 132, 49 levels, src/levels/shared/L01_00448CC0.c
   rac2 twin func_002AB168 (vsub.xyz inlined instead of func_00282CF0). Single non-volatile m-operand asm block.
   Only diff: retail schedules epilogue `ld $s0,0x20($sp)` before the final sqc2 (j-form split of sqc2?). */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_448F30;
extern float func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, float);
extern void func_0038CF68(float *, float *, float);

void func_L01_00448F30(V4_448F30 *out, V4_448F30 *vector, float *axis, float amount)
{
    V4_448F30 scaled;
    V4_448F30 unit;
    float dot;
    func_0038CF68((float *)&unit, axis, 1.0f);
    dot = func_0038CE68(&unit, vector);
    func_0038CE20(&scaled, &unit, dot * amount);
    __asm__("lqc2 $vf1, %1\n"
            "lqc2 $vf2, %2\n"
            "vsub.xyz $vf1, $vf1, $vf2\n"
            "sqc2 $vf1, %0\n"
            : "=m"(*out) : "m"(*vector), "m"(scaled));
}
