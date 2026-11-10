/* func_L01_0033D2B8: matches with --as ps2as at 34 PAL levels (US 2 diff); file L01_003386E0.c has C without ps2as, so not deliverable
   switch(a[0x20]) case0 init, case1 angle*scale. Needs the float literals built inline (ps2as).
   prep by w7, p2w2 */
extern float D_L01_001DCFD8;
float func_00382538(void);
float func_0038DAB8(float, float);
void func_0038D750(void *, int, float);
void func_L01_0043A430(void *, int, void *);
void func_L01_0033D2B8(unsigned char *a) {
    unsigned char *s = *(unsigned char **)(a + 0x68);
    float f;
    switch (a[0x20]) {
    case 0:
        a[0x20] = 1;
        a[0x63] = 0x20;
        *(float *)(s + 0x40) = func_00382538();
        func_L01_0043A430(a, 1, s);
        break;
    case 1:
        f = D_L01_001DCFD8 * 0.01745329238474369f * 0.020000001415610313f;
        *(float *)(a + 0xF8) = func_0038DAB8(*(float *)(a + 0xF8), f);
        *(float *)(s + 0x40) = func_0038DAB8(*(float *)(s + 0x40), f * -2.0f);
        func_0038D750(s + 0x10, 2, *(float *)(s + 0x40));
        break;
    }
}
