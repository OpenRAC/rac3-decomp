#include "common.h"

/* localdecomp:start func_L16_003CBF50 */
#include "vu0.h"

extern u8 *D_L16_001E015C;
extern u8 *D_L16_0021ED00[];
extern f32 func_L16_00345DE8(void *, f32, f32, f32);
extern void func_L16_00345F50(void *, void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);

typedef struct {
    u8 pad0[0x1F0];
    s32 a1F0[3];
    s32 a1FC[3];
    u8 pad208[0xC];
    s16 h214;
    s16 h216;
} S_003CBF50;

void func_L16_003CBF50(u8 *a0, vu0_v4 *a1, void *a2, vu0_v4 *a3, f32 f)
{
    S_003CBF50 *q = *(S_003CBF50 **)(a0 + 0x68);
    s32 idx;
    u8 *m;
    u8 *r;
    u8 *p;
    vu0_v4 target;
    vu0_v4 tmp;
    f32 t;

    if (q->h214 != 0) {
        m = D_L16_001E015C + (q->a1FC[q->h216] << 8);
    } else {
        m = D_L16_001E015C + (q->a1F0[q->h216] << 8);
    }
    if (m != 0) {
        r = *(u8 **)(m + 0x68);
        p = D_L16_0021ED00[*(s32 *)(r + 0x78)];
        t = func_L16_00345DE8(p, *(f32 *)(r + 0x88), *(f32 *)(r + 0x84) * f, *(f32 *)(r + 0x8C));
        func_L16_00345F50(p, &tmp, t, *(f32 *)(r + 0x8C));
        vec_sub_ba(&tmp, &tmp, m + 0x10);
        vec_add_ab(&target, a1, &tmp);
    } else {
        *a3 = *a1;
    }
    func_0038CE20(&tmp, a2, f);
    vec_sub_ab(a3, &target, &tmp);
}
/* localdecomp:end func_L16_003CBF50 */
