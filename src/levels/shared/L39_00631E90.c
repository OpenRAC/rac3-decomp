#include "common.h"

typedef struct {
    u8 pad0[8128];
    f32 hist[224];
    s32 head;
    s32 count;
} S_0062F240;
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
typedef struct {
    u8 pad0[0x20];
    f32 m0[4][4];
    f32 m1[4][4];
    u8 pad[0x1A06 - 0xA0];
    u8 mode;
} Obj62FA50;
typedef struct {
    u8 pad[32];
    u8 m20[64];
    u8 m60[6662 - 96];
    u8 mode;
} S_62FD10;

/* declared by functions of L39_0062D7C8.c, which this file was cut from */
extern void func_0038D000(f32 *, f32 *, u8 *);

/* localdecomp:start func_L39_00631E90 */
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

extern void func_0038D278(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D000(f32 *, f32 *, u8 *);
extern f32 func_003C4138(f32 *, f32, f32);

void func_L39_00631E90(u8 *s) {
    M_00631E90 m;
    Vec4 t;
    M_00631E90 r;
    Vec4 d;
    s32 i;
    s32 j;

    if (*(s16 *)(s + 0x2488) == 0) {
        return;
    }
    func_0038D278(&m);
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
    func_0038CF68(m.m[0], m.m[0], t.f[0]);
    func_0038CF68(m.m[1], m.m[1], t.f[1]);
    func_0038CF68(m.m[2], m.m[2], t.f[2]);
    func_0038D5F0(&r, &m, s + 0x60);
    func_0038D5F0(&r, s + 0x20, &r);
    func_0038D5F0((u8 *)*(s32 *)(s + 0x2524) + 0xC0, (u8 *)*(s32 *)(s + 0x2524) + 0xC0, &m);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            u8 *o = *(u8 **)(s + i * 0x50 + 0x450);
            if (j == 1) {
                o = *(u8 **)(s + i * 0x50 + 0x454);
            }
            if (o != 0) {
                func_0038D5F0(o + 0xC0, &r, o + 0xC0);
                vec_sub_ba(&d, o + 0x10, s + 0xA0);
                func_0038D000(d.f, d.f, (u8 *)&r);
                vec_add_ab(o + 0x10, &d, s + 0xA0);
            }
        }
    }
    if (*(f32 *)(s + 0xF0) == 1.0f && *(f32 *)(s + 0xF4) == 1.0f && *(f32 *)(s + 0xF8) == 1.0f) {
        *(s16 *)(s + 0x2488) = 0;
    }
    func_003C4138((f32 *)(s + 0xF0), 1.0f, 0.0800000057f);
    func_003C4138((f32 *)(s + 0xF4), 1.0f, 0.0800000057f);
    func_003C4138((f32 *)(s + 0xF8), 1.0f, 0.0800000057f);
}
/* localdecomp:end func_L39_00631E90 */
