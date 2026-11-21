#include "common.h"

/* NTSC-U counterpart of func_L02_003067B8 (src/levels/shared/L02_003067B8.c) */
/* localdecomp:start func_L02_00306530 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0x70];
    s32 path;      /* 0x70 */
    f32 dz;        /* 0x74 */
    f32 speed;     /* 0x78 */
    f32 t;         /* 0x7C */
    vu0_v4 vel;    /* 0x80 */
    s32 flag;      /* 0x90 */
    f32 dt;        /* 0x94 */
    s32 timer;     /* 0x98 */
} S_003067B8;

extern s32 *D_L02_0021C780[];
extern s32 D_L02_001DE540;
extern f32 D_L02_001DC524;
__asm__(".extern D_L02_001DC524, 4");
extern f32 D_L02_001DC528;
__asm__(".extern D_L02_001DC528, 4");
extern s32 D_L02_001DC52C;
__asm__(".extern D_L02_001DC52C, 4");
extern s32 D_L02_001DC530;
__asm__(".extern D_L02_001DC530, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A4C60[];

extern f32 func_003887C8(void *, void *);
extern f32 func_00388800(void *, void *);
extern s32 func_0037E1D8(s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00474140(void *, f32, s32, void *, void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_003888C8(void *, void *, void *);
extern void func_L01_00456960(s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_004488B8(void *, void *, s32, f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern s32 func_00388398(void *);
extern void func_003BD360(void *);
extern void func_L02_00306A00(u8 *);
extern void func_L01_0044EBF8(void *, s32, f32);

void func_L02_00306530(u8 *o) {
    S_003067B8 *v = *(S_003067B8 **)(o + 0x68);
    s32 *path = D_L02_0021C780[v->path];
    f32 z;
    f32 d;

    switch (*(u8 *)(o + 0x20)) {
    case 0:
        if (v->path == -1) {
            func_003BD360(o);
            return;
        }
        D_L02_001DC530 = -1800;
        D_L02_001DC52C = 0;
        z = func_003887C8(path + 4, path + 8);
        d = func_003887C8(path + 4, path + path[0] * 4);
        v->dt = D_L02_001DC524 * 0.016666668f / z;
        v->flag = fabs_asm(z - d) < 1.0f;
        v->t = v->speed * (f32)path[0];
        *(u8 *)(o + 0x20) = 1;
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * D_L02_001DC528;
        *(u8 *)(o + 0x30) = 0xFF;
    case 1:
        if (D_L02_001DC530 + 900 < D_L02_001DE540) {
            if (func_00388800(o + 0x10, D_001A4C60) < 20.0f) {
                if (func_0037E1D8(300) == 0) {
                    func_0039FE80(0, 0, o);
                    D_L02_001DC530 = D_L02_001DE540;
                }
            }
        }
        z = *(f32 *)(o + 0x18);
        func_L01_00474140(path, v->t, v->flag, o + 0x10, o + 0xF0, 0);
        *(f32 *)(o + 0xF4) = *(f32 *)(o + 0xF4) * 0.5f;
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + v->dz;
        v->t = v->t + v->dt;
        if ((f32)path[0] < v->t) {
            v->t = v->t - (f32)path[0];
        }
        if (*(u8 *)(o + 0x60) & 2) {
            if (z < *(f32 *)(o + 0x18)) {
                if (*(u8 *)(o + 0x43) != 0) {
                    func_003BE4F0(o, 0, 0, 10);
                }
            } else if (*(u8 *)(o + 0x43) != 1) {
                func_003BE4F0(o, 1, 0, 10);
            }
        }
        if (func_L01_00444358(o, 0x10000, 0)) {
            v->vel.x = D_L02_001DC524 * 0.016666668f * 0.5f;
            func_003888C8(&v->vel, &v->vel, o + 0xC0);
            v->vel.z = -0.050000004f;
            D_L02_001DC52C++;
            if (D_L02_001DC52C >= 10 && D_001D545C == 0x11) {
                func_L01_00456960(20);
            }
            func_L01_00441FB8(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(o)) {
            func_L01_004488B8(o, o + 0x10, -1, 0.5f, 13.0f);
            func_0039FE80(1, 0, o);
            v->timer = 600;
        }
        *(f32 *)(o + 0x48) = 0.5f;
        vec_add_ba(o + 0x10, o + 0x10, &v->vel);
        v->vel.z = v->vel.z - 0.003f;
        v->vel.x = v->vel.x * 0.98f;
        v->vel.y = v->vel.y * 0.98f;
        *(f32 *)(o + 0xF0) = func_00389380(-3.1415927f, (*(f32 *)(o + 0xF0) + 3.1415927f) * 0.95f);
        if (fabs_asm(((f32 (*)(void *, s32, f32, void *))func_003BE7F0)(o + 0x10, 0, 0.5f, 0) - *(f32 *)(o + 0x18)) < 0.5f) {
            v->timer = 30;
            func_L01_00441FB8(o, 3, -1);
        }
        if (func_00388398(&v->timer)) {
            func_003BD360(o);
        }
        break;
    case 3:
        if (func_L01_00452EC8(o)) {
            func_L02_00306A00(o);
            func_L01_0044EBF8(o, 1, 0.0f);
        }
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + v->vel.z;
        if (func_00388398(&v->timer)) {
            func_003BD360(o);
        }
        break;
    }
}
/* localdecomp:end func_L02_00306530 */
