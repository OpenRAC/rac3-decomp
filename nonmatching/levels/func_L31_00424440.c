/* func_L31_00424440: NEAR 2 (p2w4, w5). rac2 twin func_002B04E0. One VU0 block (lqc2,lqc2,vsub,sqc2) matches all but the order of move a1,sp vs sqc2.
   Retail interleaves 'move a1,sp' before sqc2; j-form impossible (level flags lack -mvu0-use-vf0-vf2); needs scheduling the block can't give.
   Variants tried: volatile r-form, 2 blocks, "r"(&v) address: 2-16 diff. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_424440;
extern void func_003C5060(void *, void *, void *, void *);
extern float func_0038D160(float, float);
float func_L31_00424440(char *o, V4_424440 *a, void *c) {
    V4_424440 v;
    __asm__(
        "lqc2 $vf2, %2\n"
        "lqc2 $vf1, %1\n"
        "vsub.xyz $vf1, $vf1, $vf2\n"
        "sqc2 $vf1, %0\n"
        : "=m"(v) : "m"(*a), "m"(*(V4_424440 *)(o + 0x10)));
    func_003C5060(o, &v, &v, c);
    return func_0038D160(v.x, v.y);
}
