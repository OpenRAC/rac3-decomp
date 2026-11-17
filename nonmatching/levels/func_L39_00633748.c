/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_00630F00, the NTSC-U twin of func_L39_00633748, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L39_00632C48.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_00630F00 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_00630F00 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00630F00;

extern f32 func_003887A0(void *);
extern f32 func_00388A28(f32, f32);
extern void func_0013D528(void *, void *);
extern void func_003886E8(void *, void *, f32);

void func_L39_00630F00(u8 *o) {
    V_00630F00 v;
    f32 f;

    if (*(s16 *)(o + 0x2DE) == 0) {
        return;
    }
    if (!(*(f32 *)(o + 0x2AC) < 0.15f)) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x148))) {
        return;
    }
    if (o[0x216] == 0) {
        return;
    }
    if (!(0.0f < *(f32 *)(o + 0x1C8))) {
        return;
    }
    f = func_00388A28(*(f32 *)(o + 0x1C8), func_003887A0(o + 0x1C0));
    if (0.87266463f <= f) {
        *(u128_t *)&v = *(u128_t *)(o + 0x1C0);
        v.z = 0.0f;
        func_0013D528(&v, &v);
        f = -*(f32 *)(o + 0x120) * v.x - *(f32 *)(o + 0x124) * v.y;
        if (0.0f < f) {
            func_003886E8(&v, &v, f);
            vec_add_ab(o + 0x120, o + 0x120, &v);
            *(f32 *)(o + 0x128) = *(f32 *)(o + 0x128) - 0.030000001f;
        }
    }
}
/* localdecomp:end func_L39_00630F00 */
