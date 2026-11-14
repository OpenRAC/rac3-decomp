#include "common.h"

/* NTSC-U counterpart of func_L39_00631E90 (src/levels/shared/L39_00631E90.c): 0.08 -> 0.0666667 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
extern void func_003888C8(f32 *, f32 *, u8 *);

/* localdecomp:start func_L39_0062F648 */
#include "vu0.h"
/* log:
 * v1: one volatile block per VU0 sequence (form 3), file flags: 25 diff (s/i registers swapped,
 *     and retail puts `move $a0` between the vsub and its sqc2).
 * v2: vec_sub_ba / vec_add_ab of vu0.h (j-form) with --flags=-mvu0-use-vf0-vf2: MATCH.
 * v3: form 3 with the sqc2 split into its own statement, file flags: 25 diff.
 */
typedef struct {
    f32 m[3][4];
} M_00631E90;

extern void func_00388B40(void *);
extern void func_00388830(void *, void *, f32);
extern void func_00388EB8(void *, void *, void *);
extern void func_003888C8(f32 *, f32 *, u8 *);
extern f32 func_003BEBF8(f32 *, f32, f32);

void func_L39_0062F648(u8 *s) {
    M_00631E90 m;
    Vec4 t;
    M_00631E90 r;
    Vec4 d;
    s32 i;
    s32 j;

    if (*(s16 *)(s + 0x2488) == 0) {
        return;
    }
    func_00388B40(&m);
    t.q = *(u128_t *)(s + 0xF0);
    if (t.f[0] < 0.0f) {
        t.f[0] = 0.0f;
    }
    if (t.f[1] < 0.0f) {
        t.f[1] = 0.0f;
    }
    if (t.f[2] < 0.0f) {
        t.f[2] = 0.0f;
    }
    func_00388830(m.m[0], m.m[0], t.f[0]);
    func_00388830(m.m[1], m.m[1], t.f[1]);
    func_00388830(m.m[2], m.m[2], t.f[2]);
    func_00388EB8(&r, &m, s + 0x60);
    func_00388EB8(&r, s + 0x20, &r);
    func_00388EB8((u8 *)*(s32 *)(s + 0x2524) + 0xC0, (u8 *)*(s32 *)(s + 0x2524) + 0xC0, &m);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            u8 *o = *(u8 **)(s + i * 0x50 + 0x450);
            if (j == 1) {
                o = *(u8 **)(s + i * 0x50 + 0x454);
            }
            if (o != 0) {
                func_00388EB8(o + 0xC0, &r, o + 0xC0);
                vec_sub_ba(&d, o + 0x10, s + 0xA0);
                func_003888C8(d.f, d.f, (u8 *)&r);
                vec_add_ab(o + 0x10, &d, s + 0xA0);
            }
        }
    }
    if (*(f32 *)(s + 0xF0) == 1.0f && *(f32 *)(s + 0xF4) == 1.0f && *(f32 *)(s + 0xF8) == 1.0f) {
        *(s16 *)(s + 0x2488) = 0;
    }
    func_003BEBF8((f32 *)(s + 0xF0), 1.0f, 0.0666666701f);
    func_003BEBF8((f32 *)(s + 0xF4), 1.0f, 0.0666666701f);
    func_003BEBF8((f32 *)(s + 0xF8), 1.0f, 0.0666666701f);
}
/* localdecomp:end func_L39_0062F648 */
