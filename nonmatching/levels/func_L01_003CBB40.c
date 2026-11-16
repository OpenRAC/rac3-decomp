/* NTSC-U draft (Codex wave 3): C of func_L01_003CA2A8, the NTSC-U twin of func_L01_003CBB40, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 216 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_003CA2A8", whose code is not the PAL one).
 * Worker's note: 216 diff; best log func_L01_003CA2A8.a02.log. VU0 memory-operand blocks compile with allowed flags but do not reproduce interleaved VU0 loads/spill at +0x05C..0x0AC; stack 0xB0 vs 0xC0 and scheduling/nops differ. Sibling j-form draft a01.c fails: fixed or ...
 */
#include "common.h"

/* Adapted from the matched NTSC-U sibling func_L04_003CD0D8. */
#include "vu0.h"
extern void func_00388830(void *, void *, f32);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);

static __inline__ void subab_003CA2A8(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void subba_003CA2A8(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void addab_003CA2A8(void *d,void *a,void *b) {
 __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
static __inline__ void addba_003CA2A8(void *d,void *a,void *b) {
 __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_v4 *)d) : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b) : "vf1", "vf2");
}
/* localdecomp:start func_L01_003CA2A8 */
extern u8 D_001A4BE0[];
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00388830(void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern f32 func_00388730(void *, void *);
extern f32 func_003887A0(void *);
extern void func_003BEE20(f32 *, f32, f32, f32, f32);
extern f32 func_003BE7F0(void *, s32, void *, f32);

void func_L01_003CA2A8(u8 *obj, u8 *q) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 u;
    vu0_v4 n;
    f32 x;
    f32 old;
    f32 l;
    u8 *h;

    t.x = func_00388960(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.y = func_00388978(*(f32 *)(q + 0x488)) * *(f32 *)(q + 0x48C);
    t.z = 0.0f;
    addab_003CA2A8(&t, &t, q + 0x4B0);
    old = *(f32 *)(q + 0x238);
    subab_003CA2A8(&d, &t, obj + 0x10);
    *(f32 *)(q + 0x238) = 0.0f;
    d.z = 0.0f;
    func_00388830(&u, &d, 1.0f);
    func_00388758(&n, &u, obj + 0xE0);
    func_00388830(&n, &n, 1.0f);
    x = func_00388730(&n, q + 0x230);
    if (0.0009722222457639873f < x) {
        x = 0.0009722222457639873f;
    } else if (x < -0.0009722222457639873f) {
        x = -0.0009722222457639873f;
    }
    func_00388830(&n, &n, x);
    subba_003CA2A8(q + 0x230, q + 0x230, &n);
    l = func_003887A0(&d);
    x = func_003887A0(q + 0x230);
    func_003BEE20(&x, l, 0.0019444444915279746f, 0.0011111111380159855f, 0.10000000894069672f);
    func_00388830(&u, &d, 0.0019444444915279746f);
    addab_003CA2A8(q + 0x230, q + 0x230, &u);
    if (x < func_003887A0(q + 0x230)) {
        func_00388830(q + 0x230, q + 0x230, x);
    }
    if (obj[0x20] == 0x13) {
        *(f32 *)(q + 0x238) = old + 0.02777777798473835f;
        if (-0.0833333358168602f < *(f32 *)(q + 0x238))
            *(f32 *)(q + 0x238) = -0.0833333358168602f;
    } else {
        *(f32 *)(q + 0x238) = old;
        h = D_001A4BE0;
        if (*(s32 *)(h + 0x25C4) == 0xB0) {
            f32 delta = *(f32 *)(h + 0x88) - *(f32 *)(obj + 0x18);
            f32 distance = fabs_asm(delta);
            if (distance < 2.25f) {
                if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                    *(f32 *)(q + 0x238) = old - 0.013888888992369175f;
                    if (*(f32 *)(q + 0x238) < -0.21666666865348816f)
                        *(f32 *)(q + 0x238) = -0.21666666865348816f;
                } else {
                    *(f32 *)(q + 0x238) = old + 0.013888888992369175f;
                    if (-0.15000000596046448f < *(f32 *)(q + 0x238))
                        *(f32 *)(q + 0x238) = -0.15000000596046448f;
                }
            } else if (10.0f < distance) {
                if (*(f32 *)(obj + 0x18) < *(f32 *)(h + 0x88)) {
                    *(f32 *)(q + 0x238) = old + 0.013888888992369175f;
                    if (-0.15000000596046448f < *(f32 *)(q + 0x238))
                        *(f32 *)(q + 0x238) = -0.15000000596046448f;
                } else {
                    *(f32 *)(q + 0x238) = old - 0.013888888992369175f;
                    if (*(f32 *)(q + 0x238) < -0.21666666865348816f)
                        *(f32 *)(q + 0x238) = -0.21666666865348816f;
                }
            } else goto fall;
        } else {
fall:
            *(f32 *)(q + 0x238) = *(f32 *)(q + 0x238) - 0.013888888992369175f;
            if (*(f32 *)(q + 0x238) < -0.18333333730697632f)
                *(f32 *)(q + 0x238) = -0.18333333730697632f;
        }
    }
    addba_003CA2A8(obj + 0x10, obj + 0x10, q + 0x230);
    *(f32 *)(q + 0x220) = func_003BE7F0(obj + 0x10, 0, 0, 0.5f);
}
/* localdecomp:end func_L01_003CA2A8 */
