#include "common.h"

/* localdecomp:start func_L02_003067B8 */
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

extern s32 *D_L02_0021C700[];
extern s32 D_L02_001DE4C0;
extern f32 D_L02_001DC4E4;
__asm__(".extern D_L02_001DC4E4, 4");
extern f32 D_L02_001DC4E8;
__asm__(".extern D_L02_001DC4E8, 4");
extern s32 D_L02_001DC4EC;
__asm__(".extern D_L02_001DC4EC, 4");
extern s32 D_L02_001DC4F0;
__asm__(".extern D_L02_001DC4F0, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001A4C60[];

extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382468(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00477998(void *, f32, s32, void *, void *, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_0038D000(void *, void *, void *);
extern void func_L01_00459C50(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0044BB30(void *, void *, s32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern void func_L02_00306C88(u8 *);
extern void func_L01_00451E78(void *, s32, f32);

void func_L02_003067B8(u8 *o) {
    S_003067B8 *v = *(S_003067B8 **)(o + 0x68);
    s32 *path = D_L02_0021C700[v->path];
    f32 z;
    f32 d;

    switch (*(u8 *)(o + 0x20)) {
    case 0:
        if (v->path == -1) {
            func_003C2880(o);
            return;
        }
        D_L02_001DC4F0 = -1500;
        D_L02_001DC4EC = 0;
        z = func_0038CF00(path + 4, path + 8);
        d = func_0038CF00(path + 4, path + path[0] * 4);
        v->dt = D_L02_001DC4E4 * 0.020000001f / z;
        v->flag = fabs_asm(z - d) < 1.0f;
        v->t = v->speed * (f32)path[0];
        *(u8 *)(o + 0x20) = 1;
        *(f32 *)(o + 0x2C) = *(f32 *)(o + 0x2C) * D_L02_001DC4E8;
        *(u8 *)(o + 0x30) = 0xFF;
    case 1:
        if (D_L02_001DC4F0 + 750 < D_L02_001DE4C0) {
            if (func_0038CF38(o + 0x10, D_001A4C60) < 20.0f) {
                if (func_00382468(250) == 0) {
                    func_003A52A0(0, 0, o);
                    D_L02_001DC4F0 = D_L02_001DE4C0;
                }
            }
        }
        z = *(f32 *)(o + 0x18);
        func_L01_00477998(path, v->t, v->flag, o + 0x10, o + 0xF0, 0);
        *(f32 *)(o + 0xF4) = *(f32 *)(o + 0xF4) * 0.5f;
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + v->dz;
        v->t = v->t + v->dt;
        if ((f32)path[0] < v->t) {
            v->t = v->t - (f32)path[0];
        }
        if (*(u8 *)(o + 0x60) & 2) {
            if (z < *(f32 *)(o + 0x18)) {
                if (*(u8 *)(o + 0x43) != 0) {
                    func_003C3A10(o, 0, 0, 10);
                }
            } else if (*(u8 *)(o + 0x43) != 1) {
                func_003C3A10(o, 1, 0, 10);
            }
        }
        if (func_L01_00447490(o, 0x10000, 0)) {
            v->vel.x = D_L02_001DC4E4 * 0.020000001f * 0.5f;
            func_0038D000(&v->vel, &v->vel, o + 0xC0);
            v->vel.z = -0.060000002f;
            D_L02_001DC4EC++;
            if (D_L02_001DC4EC >= 10 && D_001D545C == 0x11) {
                func_L01_00459C50(20);
            }
            func_L01_004450F0(o, 2, -1);
        }
        break;
    case 2:
        if (func_L01_004561B8(o)) {
            func_L01_0044BB30(o, o + 0x10, -1, 0.5f, 13.0f);
            func_003A52A0(1, 0, o);
            v->timer = 500;
        }
        *(f32 *)(o + 0x48) = 0.5f;
        vec_add_ba(o + 0x10, o + 0x10, &v->vel);
        v->vel.z = v->vel.z - 0.0043200003f;
        v->vel.x = v->vel.x * 0.976f;
        v->vel.y = v->vel.y * 0.976f;
        *(f32 *)(o + 0xF0) = func_0038DAB8(-3.1415927f, (*(f32 *)(o + 0xF0) + 3.1415927f) * 0.94f);
        if (fabs_asm(((f32 (*)(void *, s32, f32, void *))func_003C3D30)(o + 0x10, 0, 0.5f, 0) - *(f32 *)(o + 0x18)) < 0.5f) {
            v->timer = 25;
            func_L01_004450F0(o, 3, -1);
        }
        if (func_0038CAD0(&v->timer)) {
            func_003C2880(o);
        }
        break;
    case 3:
        if (func_L01_004561B8(o)) {
            func_L02_00306C88(o);
            func_L01_00451E78(o, 1, 0.0f);
        }
        *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + v->vel.z;
        if (func_0038CAD0(&v->timer)) {
            func_003C2880(o);
        }
        break;
    }
}
/* localdecomp:end func_L02_003067B8 */
