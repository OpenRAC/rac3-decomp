/* US draft of func_003C5180 (rac3-uya-decomp func_003BFC18, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003C5180 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3BFC18;
typedef int Q_3BFC18 __attribute__((mode(TI)));
extern s32 D_001D5BEC_003C5180;
extern s32 D_001D5BF0;
typedef struct { u8 p0[0xB0]; V4_3BFC18 v; } S_3BFC18;
extern S_3BFC18 D_001A4BE0;
extern void func_0038CE20(f32 *, void *, f32);
extern void func_003C5110(void *, void *, s32);
void func_003C5180(void *a, f32 *out, s32 flag) {
    if (D_001D5BEC_003C5180 == 0) {
        Q_3BFC18 r;
        __asm__("vmr32.xyzw %0, $vf0" : "=j"(r));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
    } else if (D_001D5BF0 != 0) {
        func_003C5110(a, out, 1);
    } else {
        Q_3BFC18 p, q, r;
        S_3BFC18 *d = &D_001A4BE0;
        f32 s = 1.0f;
        if (d->v.w > 0.0f) {
            s = -1.0f;
        }
        __asm__("lqc2 %0, %1" : "=j"(p) : "m"(*(V4_3BFC18 *)a));
        __asm__("lqc2 %0, %1" : "=j"(q) : "m"(d->v));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(q), "j"(p));
        __asm__("sqc2 %1, %0" : "=m"(*(V4_3BFC18 *)out) : "j"(r));
        ((void (*)(void *, void *, f32))func_0038CF68)(out, out, s);
    }
    if (flag == 0) {
        func_0038CE20(out, out, -1.0f);
    }
}
/* localdecomp:end func_003C5180 */
