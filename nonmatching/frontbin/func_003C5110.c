/* US draft of func_003C5110 (rac3-uya-decomp func_003BFBA8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003C5110 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFBA8;
typedef int Q_3BFBA8 __attribute__((mode(TI)));
extern f32 D_001D5C00;
extern void func_0038CE20(f32 *, void *, f32);
void func_003C5110(void *a, f32 *out, s32 f) {
    Q_3BFBA8 p, q, r;
    __asm__("lqc2 %0, %1" : "=j"(p) : "m"(D_001D5C00));
    __asm__("lqc2 %0, %1" : "=j"(q) : "m"(*(V4_3BFBA8 *)a));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(p), "j"(q));
    __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFBA8 *)out) : "j"(r));
    out[2] = 0;
    ((void (*)(void *, f32))func_0038CF68)(out, 1.0f);
    if (f == 0) {
        func_0038CE20(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5110 */
