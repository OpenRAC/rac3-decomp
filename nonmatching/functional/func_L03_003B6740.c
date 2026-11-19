/* functional: high. Verified vs PAL asm (NTSC draft used 0x14 and 0.002; PAL 0x11 and 0.00288). 0x00382468(2) is rand%2 mapped to +-1 (0 -> -1). */
/* localdecomp:start func_L03_003B6740 */
typedef int u128_3B6740 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3B6740;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_00443B88(void *, f32, f32);
extern u8 *func_L01_0046B458(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);

void func_L03_003B6740(void *src, s32 n, s32 c1, s32 c2) {
    V4_3B6740 v0;
    V4_3B6740 v10;
    f32 r;
    s32 d;
    u8 *p;

    *(u128_3B6740 *)&v0 = *(u128_3B6740 *)src;
    while (n > 0) {
        r = func_003824E0(1.0f, 2.0f);
        d = func_00382468(2);
        d = d != 0 ? d : -1;
        func_L01_00443B88(&v10, 0.05f, 0.25f);
        p = func_L01_0046B458(&v0, 0x11, c1, 0, d, &v10, 0, r * 0.1f, r, 0.00288f);
        if (p != 0) {
            p[9] = 0x74;
        }
        p = func_L01_0046B458(&v0, 0x11, c2, 1, -d, &v10, 0, r * 0.07f, r * 0.7f, 0.00288f);
        if (p != 0) {
            p[9] = 0x74;
        }
        n--;
    }
}
/* localdecomp:end func_L03_003B6740 */
