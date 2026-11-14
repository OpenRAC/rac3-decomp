/* near miss (levels 40-53): swarm draft improved by c13 (2026-11-14): 173 -> 31 aligned rows under -mvu0-use-vf0-vf2 @ps2as (the file gets both with func_L40_00417CC0). The position update is a VU0 vadd (vec_add_ba(obj + 0x10, st, obj + 0x10)), not three float adds. Left: only the argument set-up order of the case-2 func_L01_003303B8 call (stack-argument constants, lesson 36); protoperm block positions gave nothing. */
#include "common.h"

/* localdecomp:start func_L40_004179D0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_004179D0;
typedef struct {
    u8 pad0[0x18];
    u8 f18;
    u8 f19;
    u16 f1A;
    u8 pad1C[0x14];
} __attribute__((aligned(16))) I_004179D0;

extern s32 D_L40_0025B9A0[];
extern void func_L19_003B1A70(s32, void *, s32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004C8668(s32);
extern void func_003C2880(void *);
extern void func_L40_00417CC0(void *, void *, void *);

void func_L40_004179D0(u8 *obj) {
    u8 *st = *(u8 **)(obj + 0x68);
    V_004179D0 v90;
    V_004179D0 va0;
    I_004179D0 info;
    V_004179D0 *pos;
    V_004179D0 *p90;

    switch (obj[0x20]) {
    case 1:
        p90 = &v90;
        *(u128_t *)&v90 = *(u128_t *)(obj + 0x10);
        pos = (V_004179D0 *)(obj + 0x10);
        vec_add_ba(obj + 0x10, st, obj + 0x10);
        func_L19_003B1A70(*(s32 *)(st + 0x30), st, 0);
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
            *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
            *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) {
            goto kill;
        }
        if (func_003D3CB0(p90, pos, 0, obj, 0) != 0) {
            *(u128_t *)(obj + 0x10) = *(u128_t *)D_L40_0025B9A0;
            obj[0x20] = 2;
            *(u128_t *)&va0 = *(u128_t *)st;
            func_0038CE20(&va0, &va0, 0.5f);
            va0.w = 5627.925f;
            func_L01_00446760(&info, obj, 0x10001, &va0, *(f32 *)(st + 0x34));
            info.f18 = 0;
            info.f19 = 1;
            info.f1A = *(u16 *)(obj + 0xAA);
            if (D_L40_0025B9A0[-2] != 0) {
                if (D_L40_0025B9A0[-2] != *(s32 *)(st + 0x2C)) {
                    func_003D4D00(D_L40_0025B9A0, 0, obj, &info, 0.3f);
                }
            } else {
                func_003D4D00(D_L40_0025B9A0, 0, obj, &info, 0.6f);
            }
        }
        break;
    case 2:
        func_L01_003303B8(obj + 0x10, 0, 0x19, 0x14, 0x14, 0x14, 0, 0, 0.25f, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 1, 0, 1, 0, 0xF78E38, 0xF76300, 0xFF7F40, 0xFF2000, 0x8FFF,
                          0xFF6430, 0x7FFFA060, 0x280000FF, 0xFF6430, 0);
    kill:
        func_L01_004C8668(*(s32 *)(st + 0x30));
        func_003C2880(obj);
        return;
    }
    *(u128_t *)&va0 = *(u128_t *)(obj + 0x10);
    func_L40_00417CC0(obj, &va0, &v90);
}
/* localdecomp:end func_L40_004179D0 */
