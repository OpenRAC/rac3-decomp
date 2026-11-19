/* functional: high. Draft verified block by block against retail asm (all offsets, constants, callees, branch conditions); check.py compiles, 344 byte diffs are frame size/scheduling only. */
#include "common.h"
#include "vu0.h"

typedef struct {
    s32 target;
    u8 pad4[0xE];
    s16 timer;
    u8 pad14[4];
    u8 idx[4];
    u8 pad1C[4];
    vu0_v4 pos[32];
    vu0_v4 vel[32];
    vu0_v4 grid[4][4];
    vu0_v4 gvel[4][4];
    s32 total;
    u8 pad624[0x2C];
    vu0_v4 rotation;
} Vars_336AA0;
typedef struct {
    u8 pad0[0x74];
    f32 y;
    f32 z;
    u8 pad7C[4];
} Target_336AA0;
extern s32 D_L20_001DCAAC;
extern s32 D_L20_001DCAB0;
extern s32 D_001D545C;
extern f32 D_L20_001DCB10;
extern f32 D_L20_001DCB14;
extern s32 D_L20_001DCB1C;
extern s32 D_L20_001DCB20;
extern f32 D_L20_001DCB28;
extern s32 D_L20_001DCB30;
extern s32 D_L20_001DCB34;
extern vu0_v4 D_L20_001E2E00;
extern Target_336AA0 *D_L20_001E0380;
__asm__(".extern D_L20_001DCAAC, 4");
__asm__(".extern D_L20_001DCAB0, 4");
__asm__(".extern D_L20_001DCB10, 4");
__asm__(".extern D_L20_001DCB14, 4");
__asm__(".extern D_L20_001DCB1C, 4");
__asm__(".extern D_L20_001DCB20, 4");
__asm__(".extern D_L20_001DCB28, 4");
__asm__(".extern D_L20_001DCB30, 4");
__asm__(".extern D_L20_001DCB34, 4");
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_L01_00443B88(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_00382538(void);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern s32 func_00382468(s32);
extern void func_L01_00463378(void *, void *, void *, s32, s32, s32, s32, s32, s32);

/* One real VU0 sequence per block; no ordinary EE instructions or barriers. */
static __inline__ void add_336AA0(void *d, void *a, void *b) {
    __asm__(
        "lqc2 vf2,%1\n"
        "lqc2 vf1,%2\n"
        "vadd.xyz vf2,vf2,vf1\n"
        "sqc2 vf2,%0"
        : "=m"(*(vu0_v4 *)d)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b)
        : "vf1", "vf2");
}

void func_L20_00336AA0(void *self) {
    vu0_v4 positions[32];
    vu0_v4 velocities[32];
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 matrix[3];
    vu0_v4 position;
    Vars_336AA0 *v;
    s32 lo;
    s32 hi;
    f32 width;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 n2;

    lo = (D_L20_001DCAAC * 5 + 2) / 6;
    hi = (D_L20_001DCAB0 * 5 + 2) / 6;
    v = *(Vars_336AA0 **)((u8 *)self + 0x68);
    *(f32 *)((u8 *)self + 0x1C) = 1.0f;
    v->timer = func_00382498(lo, hi);
    v->total = v->timer;
    if (D_001D545C == 0xD5 || D_001D545C == 0x10 || D_001D545C == 0x14)
        width = func_003824E0(15.0f, 20.0f);
    else
        width = func_003824E0(4.0f, 8.0f);
    for (i = 0; i < 32; i++) {
        f32 displacement = (f32)i / 31.0f;
        displacement = 0.5f - displacement;
        displacement *= width;
        if (i < 3 || i > 28) {
            qzero(&positions[i]);
            qzero(&velocities[i]);
        } else {
            func_L01_00443B88(&positions[i], 0.0f, D_L20_001DCB10);
            if (D_001D545C == 0x10 || D_001D545C == 0xD5)
                func_L01_00443B88(&velocities[i], 0.0f, 0.2400000095f);
            else
                func_L01_00443B88(&velocities[i], 0.0f, D_L20_001DCB14 * 0.020000001f);
        }
        positions[i].w = 1.0f;
        positions[i].y += displacement;
    }
    for (j = 0; j < 32; j++) {
        if (j == 0 || j == 31) {
            v->pos[j] = positions[j];
            v->vel[j] = velocities[j];
        } else {
            add_336AA0(&a, &positions[j-1], &positions[j]);
            add_336AA0(&a, &a, &positions[j+1]);
            func_0038CE20(&v->pos[j], &a, 0.333000004f);
            add_336AA0(&a, &velocities[j-1], &velocities[j]);
            add_336AA0(&a, &a, &velocities[j+1]);
            func_0038CE20(&v->vel[j], &a, 0.333000004f);
        }
    }
    for (k = 0; k < 4; k++) {
        s32 index;
        if (D_001D545C == 0xD5 || D_001D545C == 0x10)
            func_L01_00443B88(&a, 1.0f, 1.0f);
        else
            func_L01_00443B88(&a, D_L20_001DCB10, D_L20_001DCB10);
        index = (s32)func_003824E0((f32)k * 6.0f, (f32)(k+1) * 6.0f) + 4;
        v->idx[k] = index;
        v->grid[0][k] = v->pos[index];
        v->gvel[0][k] = v->vel[index];
        for (m = 1; m < 4; m++) {
            func_L01_00443B88(&b, 0.1f, 0.1f);
            if (D_001D545C == 0xD5 || D_001D545C == 0x10)
                func_L01_00443B88(&v->gvel[m][k], 0.0f, 0.2400000095f);
            else
                func_L01_00443B88(&v->gvel[m][k], 0.0f, D_L20_001DCB14 * 0.020000001f);
            add_336AA0(&v->grid[m][k], &v->grid[m-1][k], &a);
            add_336AA0(&v->grid[m][k], &v->grid[m][k], &b);
        }
    }
    if (func_0038CF38((u8 *)self + 0x10, &D_L20_001E2E00) >= 4.0f) {
        v->rotation.z = D_L20_001E0380[v->target].z;
        v->rotation.y = D_L20_001E0380[v->target].y;
        v->rotation.x = func_00382538();
        func_0038D328(matrix, &v->rotation);
        position = *(vu0_v4 *)((u8 *)self + 0x10);
        for (n = 0; n < 32; n += 8) {
            s32 color;
            func_0038D028(&a, &v->pos[n], matrix);
            b = v->vel[n];
            b.w = D_L20_001DCB28;
            color = func_00382468(2) ? D_L20_001DCB30 : D_L20_001DCB34;
            func_L01_00463378(&a, &b, &b, D_L20_001DCB1C, D_L20_001DCB20,
                n >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, color);
        }
        for (n2 = 0; n2 < 2; n2++) {
            func_0038D028(&a, &v->grid[3][n2], matrix);
            b = v->gvel[3][n2];
            b.w = D_L20_001DCB28;
            func_00382468(2);
            func_L01_00463378(&a, &b, &b, D_L20_001DCB1C, D_L20_001DCB20,
                v->idx[n2] >> 1, 15, ((func_00382468(10) + 20) * 5 + 2) / 6, D_L20_001DCB34);
        }
    }
}
