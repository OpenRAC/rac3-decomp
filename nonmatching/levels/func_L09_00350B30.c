/* func_L09_00350B30: NEAR 8 diff, needs --as ps2as (file L09_00350718.c has no C)
   only the order of the arg moves (mov.s f12, move a2, mov.s f14, move t1) differs
   prep by w7, p2w2 */
int func_00382498(int, int);
float func_00382538(void);
void func_L09_00350CB0(void *, int, int, int, int, void *, float, float, float);
void func_L09_00350B30(char *a) {
    float f = *(float *)(a + 0x2C) * 90.0f; float f2;
    func_L09_00350CB0(a + 0x10, 0x80103080, func_00382498(0x5F, 0x6F), 0x1C, 2, a, f, func_00382538(), 1.0f);
    f2 = *(float *)(a + 0x2C) * 90.0f * 0.5f; f = f2;
    func_L09_00350CB0(a + 0x10, -1, func_00382498(0x6F, 0x7F), 8, 2, a, f, func_00382538(), 1.0f);
}
