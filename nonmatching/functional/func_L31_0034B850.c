/* functional: medium. Checked by reading asm against C (compiles, 99 diff words, register/schedule only); w lanes assumed copied from first operand. */
#include "vu0.h"
extern u8 *D_L31_0021D740[];
extern void func_L01_00445208(void *, void *, void *, void *, void *, f32);

/* Samples a stored path (count n at +0, 16-byte points from +0x10) at parameter t in [0,1]. */
void func_L31_0034B850(u8 *obj, vu0_q *out, f32 t) {
    vu0_v4 tan0, tan1;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 slot = *(s32 *)(vars + 0xC8);
    u8 *path = D_L31_0021D740[*(s32 *)(vars + 0x80 + slot * 4)];
    s32 n, seg, off;
    f32 ft;

    qzero(out);
    if (path == 0) return;
    n = *(s32 *)path;
    if (n <= 0) return;
    if (n == 1) {
        *out = *(vu0_q *)(path + 0x10);
        return;
    }
    if (t > 1.0f) {
        t = 1.0f;
    } else if (t < 0.0f) {
        t = 0.0f;
    }
    ft = t * (f32)(n - 1);
    seg = (s32)ft;
    if (n - 2 < seg) {
        *out = *(vu0_q *)(path + n * 16);
        return;
    }
    if (seg == 0) {
        vec_sub_ab(&tan0, path + 0x10, path + 0x20);
        vec_add_ab(&tan0, &tan0, path + 0x10);
        tan0.w = ((vu0_v4 *)(path + 0x10))->w; /* xyz-only vector ops keep w of the first operand */
        off = 0;
    } else {
        off = seg * 16;
        tan0 = *(vu0_v4 *)(path + off);
    }
    if (seg == n - 2) {
        vec_sub_ab(&tan1, path + n * 16, path + n * 16 - 0x10);
        vec_add_ab(&tan1, &tan1, path + n * 16);
        tan1.w = ((vu0_v4 *)(path + n * 16))->w;
    } else {
        tan1 = *(vu0_v4 *)(path + off + 0x30);
    }
    func_L01_00445208(out, path + off + 0x10, path + off + 0x20, &tan0, &tan1,
                      ft - cvtsw_asm(cvtws_asm(ft)));
}
