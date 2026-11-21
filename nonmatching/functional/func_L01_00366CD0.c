/* functional: high. 40 words differ in VU0 scheduling only; callees/constants/offsets checked against asm; draft's .sdata attribute on D_1C30 kept from draft */
/* localdecomp:start func_L01_00366CD0 */
extern s128 D_001A4C60;
extern f32 D_L01_001E1C64;
extern s128 D_L01_001E1C30 __attribute__((section(".sdata")));
extern s128 D_L01_001E1C40;
extern s128 D_L01_001E1C50;
static __inline__ void add_00366CD0(s128 *d, s128 *a, s128 *b) {
    __asm__("lqc2 $vf1, %1\n lqc2 $vf2, %2\n vadd.xyz $vf1, $vf1, $vf2\n sqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
void func_L01_00366CD0(void) {
    extern void func_L01_004C7D98(s128 *, s128 *);
    extern void func_0038CDF8(s128 *, s128 *, s128 *, f32);
    s128 a, b;
    func_L01_004C7D98(&D_001A4C60, &a);
    func_0038CE20(&D_L01_001E1C30, &a, 0.5f);
    add_00366CD0(&D_L01_001E1C30, &D_L01_001E1C30, &D_001A4C60);
    if (D_L01_001E1C64 > 0.0f) {
        func_0038CDF8(&D_L01_001E1C30, &D_L01_001E1C30, &D_L01_001E1C40, D_L01_001E1C64 * 0.4f + 0.4f);
        func_0038CE20(&b, &D_L01_001E1C50, D_L01_001E1C64 * -0.55f);
        add_00366CD0(&D_L01_001E1C30, &b, &D_L01_001E1C30);
    } else {
        func_0038CDF8(&D_L01_001E1C30, &D_L01_001E1C30, &D_L01_001E1C40, 0.4f);
    }
}
/* localdecomp:end func_L01_00366CD0 */
