/* func_L39_0059A578: NEAR 2 (p2w2 w5). MATCH at level 39 only; false fold, levels 40-53 and US differ in gp slot/struct addresses. */
typedef struct {
    u8 pad00[0x18];
    s16 f18;
    u8 pad1A[0x17C - 0x1A];
    s32 f17C;
} S_0059A578;
extern S_0059A578 D_001A43E0;
extern s32 D_001D71E4_sda;
extern s32 D_001E0430_sda;
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern s32 D_L39_00240400;
__asm__(".extern D_L39_00240400, 16");
extern s32 D_L39_002403FC;
__asm__(".extern D_L39_002403FC, 16");
extern void func_L01_003D4C00(s32 *);

void func_L39_0059A578(s32 a0) {
    s32 v = a0;
    s32 w;
    func_L01_003D4C00(&v);
    w = v;
    D_001D71E4_sda = 1;
    D_L39_00240400 = D_L39_002412DC;
    D_001E0430_sda = w;
    if (w == -1) {
        if (D_001A43E0.f17C != 0) {
            D_001A43E0.f17C = 0;
        }
        if (D_001A43E0.f18 >= 0) {
            D_001A43E0.f18 = w;
        }
        D_L39_002403FC &= ~0x200;
    }
}
