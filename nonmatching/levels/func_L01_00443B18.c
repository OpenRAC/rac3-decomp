/* func_L01_00443B18: near miss (p2 w2): 4 diff at level 01, sequence is rac2 twin + callee renames.
   Retail has a bare "sq $zero,0($s0)" (not plain C; u128_t store of 0 gives por+sq) scheduled before the jal.
   Left: a way to get sq $zero (only that), else stays near miss. */
typedef int u128_t __attribute__((mode(TI)));
extern float func_00382538(void);
extern float func_L01_00443AC0(float);
extern float func_0038D098(float);
extern float func_0038D0B0(float);

void func_L01_00443B18(float *arg0, float arg1) {
    float a = func_00382538();
    float b = func_L01_00443AC0(arg1);
    *(u128_t *)arg0 = 0;
    arg0[0] = func_0038D098(a) * b;
    arg0[1] = func_0038D0B0(a) * b;
}
