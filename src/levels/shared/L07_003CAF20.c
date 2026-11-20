#include "common.h"

/* localdecomp:start func_L07_003CAF20 */
#include "vu0.h"
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_004CB320(void);
extern void func_L01_004CB358(void);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern f32 func_0038CF00(void *, void *);
extern void func_L07_003CC1C0(void *);
extern void func_L05_003CAE70(void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L07_003CB1F8(void *);
extern u8 D_L07_001D66B0[8];
typedef struct { u8 *g; s32 pad; f32 v[4]; } S_003CAF20;
extern S_003CAF20 D_L07_001E8C18;

static __inline__ void step_003CAF20(vu0_v4 *out, u8 *pos, u8 *vel) {
    if (*(f32 *)(vel + 0x20) < func_0038CEA8(vel)) {
        vec_add_ab(out, pos, vel);
    } else {
        func_0038CF68(out, vel, *(f32 *)(vel + 0x20));
        vec_add_ab(out, out, pos);
    }
}

void func_L07_003CAF20(u8 *o) {
    u8 *st = *(u8 **)(o + 0x68);
    vu0_v4 old;
    vu0_v4 v;
    u8 b[0x30] __attribute__((aligned(16)));
    void *col;
    u8 *g;
    s32 hit;
    s32 n;
    f32 f;

    old = *(vu0_v4 *)(o + 0x10);
    if (o[0x20] == 0) {
        if (func_L01_004561B8(o) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, st);
        }
        if (func_0038CAD0(st + 0x24) != 0) {
            func_003C2880(o);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            step_003CAF20(&v, o + 0x10, st);
            func_L01_00446760(b, o, 0x10001, D_L07_001D66B0, *(f32 *)(st + 0x34));
            *(s32 *)(b + 0x28) = *(s32 *)(st + 0x44);
            col = *(void **)(o + 0xB8);
            func_L01_004CB320();
            hit = func_003D3CB0(o + 0x10, &v, 0x10, col, b);
            if (hit != 0) {
                g = D_L07_001E8C18.g;
                if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                    g[0x20] = 4;
                }
            }
            func_L01_004CB358();
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)D_L07_001E8C18.v;
                f = func_0038CF00(o + 0x10, st + 0x10) / func_0038CEA8(st);
                n = ((s32)f * 5 + 2) / 6;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / n;
                if (D_L07_001E8C18.g == 0) {
                    func_L07_003CC1C0(o);
                } else {
                    func_L05_003CAE70(st + 0x10);
                }
            }
        }
        func_L01_00404A10(func_L07_003CB1F8, o);
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003C2880(o);
    }
}
/* localdecomp:end func_L07_003CAF20 */

INCLUDE_ASM("asm/levels", func_L07_003CB1F8);
