#include "common.h"

/* NTSC-U counterpart of func_L07_003CAF20 (src/levels/shared/L07_003CAF20.c) */
/* localdecomp:start func_L07_003C9548 */
#include "vu0.h"
extern s32 func_L01_00452EC8(void *);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern f32 func_00388770(void *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00443628(void *, void *, s32, void *, f32);
extern void func_L01_004C76B8(void);
extern void func_L01_004C76F0(void);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern f32 func_003887C8(void *, void *);
extern void func_L07_003CA7C0(void *);
extern void func_L05_003C8CC8(void *);
extern void func_L01_004026A0(void *, void *);
extern void func_L07_003C9808(void *);
extern u8 D_L07_001D66B0_003C9548[8];
typedef struct { u8 *g; s32 pad; f32 v[4]; } S_003CAF20;
extern S_003CAF20 D_L07_001E8C18_003C9548;

static __inline__ void step_003CAF20(vu0_v4 *out, u8 *pos, u8 *vel) {
    if (*(f32 *)(vel + 0x20) < func_00388770(vel)) {
        vec_add_ab(out, pos, vel);
    } else {
        func_00388830(out, vel, *(f32 *)(vel + 0x20));
        vec_add_ab(out, out, pos);
    }
}

void func_L07_003C9548(u8 *o) {
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
        if (func_L01_00452EC8(o) == 0) {
            vec_add_ab(o + 0x10, o + 0x10, st);
        }
        if (func_00388398(st + 0x24) != 0) {
            func_003BD360(o);
            return;
        }
        if (*(s32 *)(st + 0x30) == 0) {
            step_003CAF20(&v, o + 0x10, st);
            func_L01_00443628(b, o, 0x10001, D_L07_001D66B0_003C9548, *(f32 *)(st + 0x34));
            *(s32 *)(b + 0x28) = *(s32 *)(st + 0x44);
            col = *(void **)(o + 0xB8);
            func_L01_004C76B8();
            hit = func_003CE740(o + 0x10, &v, 0x10, col, b);
            if (hit != 0) {
                g = D_L07_001E8C18_003C9548.g;
                if (g != 0 && *(s16 *)(g + 0xAA) == 0x186D && g[0x20] != 2 && g[0x20] != 5) {
                    g[0x20] = 4;
                }
            }
            func_L01_004C76F0();
            if (hit != 0) {
                *(s32 *)(st + 0x30) = 1;
                *(vu0_v4 *)(st + 0x10) = *(vu0_v4 *)D_L07_001E8C18_003C9548.v;
                f = func_003887C8(o + 0x10, st + 0x10) / func_00388770(st);
                n = (s32)f;
                *(s32 *)(st + 0x24) = n;
                *(f32 *)(st + 0x28) = 1.0f / n;
                if (D_L07_001E8C18_003C9548.g == 0) {
                    func_L07_003CA7C0(o);
                } else {
                    func_L05_003C8CC8(st + 0x10);
                }
            }
        }
        func_L01_004026A0(func_L07_003C9808, o);
    }
    if (*(f32 *)(o + 0x10) < 2.0f || 1021.0f < *(f32 *)(o + 0x10) ||
        *(f32 *)(o + 0x14) < 2.0f || 1021.0f < *(f32 *)(o + 0x14) ||
        *(f32 *)(o + 0x18) < 2.0f || 1021.0f < *(f32 *)(o + 0x18)) {
        func_003BD360(o);
    }
}
/* localdecomp:end func_L07_003C9548 */
