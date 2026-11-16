#include "common.h"

/* NTSC-U counterpart of func_L20_003FEBA8 (src/levels/20_final_boss/L20_003FEBA8.c) */
extern s32 func_L20_003F9120(void *);

/* localdecomp:start func_L20_003FC898 */
#include "vu0.h"
typedef struct { u8 p0[0xF8]; u8 xF8[4]; } E_003FEBA8;
typedef struct {
    u8 p0[0x220]; vu0_v4 v220; u8 p230[0xA0]; u8 x2D0[0xFC]; u8 x3CC[4]; u8 x3D0[4]; u8 x3D4[4];
    u8 p3D8[0x14]; E_003FEBA8 *x3EC;
} P_003FEBA8;
extern f32 D_L20_001E2E80_003FC898[];
__asm__(".extern D_L20_001E2E80_003FC898, 16");
__asm__(".extern D_L20_001DF630, 4");
__asm__(".extern D_L20_001DF634_003FC898, 4");
__asm__(".extern D_L20_001DF638_003FC898, 4");
extern f32 D_L20_001DF630;
extern f32 D_L20_001DF634_003FC898;
extern f32 D_L20_001DF638_003FC898;
extern s32 func_00388398(void *);
extern s32 func_003883C8(void *);
extern void func_L01_0044EB78(void *, void *, s32, s32, f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_L01_00444188(void *);
extern void func_L01_0040C920(void *, void *);
extern void func_003888C8(void *, void *, void *);
extern s32 func_L20_003F90C0(void *);
extern void func_00388830(void *, void *, f32);
extern f32 func_00388990(f32);
extern f32 func_L01_004455F0(s32, f32, s32, f32, f32, f32, s32);
extern void func_L20_003FD138(void *);
extern void func_L01_00402498(void *, void *);
extern void func_L05_0035A068(u8 *);
extern void func_L05_0035A1D0(u8 *);

void func_L20_003FC898(u8 *a0) {
    P_003FEBA8 *p = *(P_003FEBA8 **)(a0 + 0x68);
    vu0_v4 v;
    vu0_v4 m[3];
    f32 f;

    func_00388398(p->x3D0);
    func_003883C8(p->x3D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    }
    func_L01_0044EB78(p->x3EC, p->x2D0, 3, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040C018(D_L20_001E2E80_003FC898, a0 + 0x10) < 576.0f) {
            func_L01_00444188(a0);
            a0[0x6F] = 0x16;
        }
    }
    vec_sub_ba(&v, &p->v220, a0 + 0x10);
    func_L01_0040C920(m, a0 + 0xC0);
    func_003888C8(&v, &v, m);
    if (v.x > 0.0f || func_L20_003F90C0(p->x3EC) != 0) {
        func_00388830(&v, &v, 1.0f);
        f = func_00388990(v.y);
        func_L01_004455F0((s32)p->x3EC->xF8, f, (s32)p->x3CC,
                          D_L20_001DF630 * 0.017453292f * 0.00027777778450399637f,
                          D_L20_001DF634_003FC898 * 0.017453292f * 0.00027777778450399637f,
                          D_L20_001DF638_003FC898 * 0.017453292f * 0.01666666753590107f, 0);
    } else {
        func_L01_004455F0((s32)p->x3EC->xF8, 0.0f, (s32)p->x3CC,
                          D_L20_001DF630 * 0.017453292f * 0.00027777778450399637f,
                          D_L20_001DF634_003FC898 * 0.017453292f * 0.00027777778450399637f,
                          D_L20_001DF638_003FC898 * 0.017453292f * 0.01666666753590107f, 0);
    }
    if (a0[0x31] != 0) {
        if (func_L20_003F9120(a0) != 0) {
            func_L20_003FD138(a0);
            func_L01_00402498(func_L05_0035A1D0, a0);
        }
        func_L01_00402498(func_L05_0035A068, a0);
    }
}
/* localdecomp:end func_L20_003FC898 */
