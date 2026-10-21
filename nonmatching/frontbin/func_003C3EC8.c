/* US draft of func_003C3EC8 (rac3-uya-decomp func_003BE988, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `-mno-split-addresses` `@ps2as` (a single-function override). */


/* localdecomp:start func_003C3EC8 */
extern s32 D_001D99C0;
extern s32 D_001D99A8;
extern f32 D_001D99B8;
extern f32 D_001D99BC;
extern f32 D_001D99B0[];
extern s32 func_00381D50();
extern f32 func_0038CF38();
f32 func_003C3EC8(f32 *p, void *out) {
    f32 t;
    if (D_001D99C0 != 0) {
        t = p[2];
        if (((s32 (*)(f32 *, f32, f32, f32))func_00381D50)(&t, p[0], p[1], p[2]) != 0) return t;
    }
    if (D_001D99A8 != 0) {
        if (__builtin_fabsf(p[2] - *(volatile f32 *)&D_001D99B8) < 0.5f && func_0038CF38(p, D_001D99B0) < D_001D99BC) {
            if (out != 0) {
                __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
            }
            return *(volatile f32 *)&D_001D99B8;
        }
    }
    if (out != 0) {
        __asm__ __volatile__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return p[2];
}
/* localdecomp:end func_003C3EC8 */
