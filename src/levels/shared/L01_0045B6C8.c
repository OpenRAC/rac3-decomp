#include "common.h"

typedef struct { u8 pad[0x10]; f32 x; f32 y; } M_4574A0;
typedef struct {
    u8 pad[0xDC];
    f32 fDC;
    s16 hE0;
    s16 hE2;
    s16 hE4;
} S_4574A0;
typedef struct { u8 pad[16]; u8 sub[248 - 16]; f32 f; } S457;
typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L01_0045B538.c, which this file was cut from */
extern void func_L01_0045B6C8(u8 *, u8 *, f32);
extern u8 *func_L01_00448FF0(u8 *);
#define U8(p, o) (*(u8 *)((p) + (o)))
#define U16(p, o) (*(u16 *)((p) + (o)))
#define S32(p, o) (*(s32 *)((p) + (o)))
#define F32(p, o) (*(f32 *)((p) + (o)))

/* localdecomp:start func_L01_0045B6C8 */
#include "vu0.h"

typedef union { u128_t q; f32 f[4]; } V_0045B6C8;
typedef struct { u8 pad0[0x18]; s32 m18; s32 m1C; u8 pad20[8]; f32 f28; } Hit_0045B6C8;
extern Hit_0045B6C8 D_L01_001EAA00_0045B6C8;
extern f32 D_L01_001EAA40_0045B6C8[];
extern s32 func_003D3CB0(V_0045B6C8 *, V_0045B6C8 *, s32, u8 *, s32);
extern s32 func_003D5630(void);
extern void func_0038CF68(f32 *, f32 *, f32);

/* from rac2-decomp's func_002B5BC0 (rac3 adds the ground-type re-probe) */
void func_L01_0045B6C8(u8 *a0, u8 *a1, f32 f12) {
    V_0045B6C8 v;
    V_0045B6C8 t;
    s32 flags;
    u8 *p;

    v.q = *(u128_t *)(a0 + 0x10);
    v.f[2] += F32(a1, 8) + 0.1f;
    if (f12 != 0.0f) {
        t.q = *(u128_t *)(a0 + 0x10);
        t.f[2] -= f12;
    } else {
        t.q = *(u128_t *)(a0 + 0x10);
        t.f[2] -= F32(a1, 0xC) + 0.1f;
        flags = 2;
    }
    if (func_003D3CB0(&v, &t, 2, a0, 0)) {
        F32(a1, 0x90) = D_L01_001EAA00_0045B6C8.f28;
        S32(a1, 0x88) = D_L01_001EAA00_0045B6C8.m18;
        S32(a1, 0x8C) = D_L01_001EAA00_0045B6C8.m1C;
        S32(a1, 0xD8) = func_003D5630();
        if (S32(a1, 0xD8) != -1) {
            p = func_L01_00448FF0(a0);
            if (p != 0 && U8(p, 0x49) != 0 && U16(p, 0x4A) != 0 &&
                ((U16(p, 0x4A) >> S32(a1, 0xD8)) & 1)) {
                if (0.3f < F32(a0, 0x18) - F32(a1, 0x90)) {
                    S32(a1, 0xD8) = -1;
                    F32(a1, 0x90) = 0.0f;
                    S32(a1, 0x88) = 0;
                    S32(a1, 0x8C) = 0;
                }
            } else if (S32(a1, 0xD8) == 0 || S32(a1, 0xD8) == 3) {
                if (func_003D3CB0(&v, &t, flags | 0x20, a0, 0)) {
                    F32(a1, 0x90) = D_L01_001EAA00_0045B6C8.f28;
                    S32(a1, 0x88) = D_L01_001EAA00_0045B6C8.m18;
                    S32(a1, 0x8C) = D_L01_001EAA00_0045B6C8.m1C;
                    S32(a1, 0xD8) = func_003D5630();
                } else {
                    F32(a1, 0x90) = 0.0f;
                    S32(a1, 0x88) = 0;
                    S32(a1, 0x8C) = 0;
                    S32(a1, 0xD8) = -1;
                    qzero(a1 + 0x50);
                }
            }
        }
        func_0038CF68((f32 *)(a1 + 0x50), D_L01_001EAA40_0045B6C8, 1.0f);
    } else {
        F32(a1, 0x90) = 0.0f;
        S32(a1, 0x88) = 0;
        S32(a1, 0x8C) = 0;
        S32(a1, 0xD8) = -1;
        qzero(a1 + 0x50);
    }
}
/* localdecomp:end func_L01_0045B6C8 */
