/* US draft of func_003A6178 (rac3-uya-decomp func_003A0D58, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003A6178 */
typedef struct { u8 p0[0x20]; s16 f20; } S_16C580_3A0D58;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A0D58;
extern S_16C580_3A0D58 D_16C580_003A6178;
extern f32 func_00382538(void);
extern void func_003C4C18(f32 *v, f32 r);
extern void func_003D3FA0_003A0D58(void *, s32, s32, s32, f32, f32, f32);
void func_003A6178(f32 a, f32 b, u128_t *src, V4_3A0D58 *step, f32 g, s32 n, s32 c) {
    u128_t pos[1];
    u128_t tmp;
    f32 inv;
    f32 t, r;
    s32 i;
    inv = 1.0f / n;
    pos[0] = *src;
    i = 0;
    while (i < n) {
        t = a + (b - a) * (i++ * inv);
        r = func_00382538();
        tmp = pos[0];
        func_003C4C18((f32 *)&tmp, g);
        func_003D3FA0_003A0D58(&tmp, (D_16C580_003A6178.f20 == 2) ? 5 : 0x2E, c, 1, t, 0.0f, r);
        {
            u128_t x, y;
            __asm__("lqc2 %0, %1" : "=j"(x) : "m"(pos[0]));
            __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
            __asm__("sqc2 %1, %0" : "=m"(pos[0]) : "j"(x));
        }
    }
}
/* localdecomp:end func_003A6178 */
