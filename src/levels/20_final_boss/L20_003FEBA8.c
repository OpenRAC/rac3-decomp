#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* declared by functions of L20_003FB630.c, which this file was cut from */
extern s32 func_L20_003FB3B0(void *);

/* localdecomp:start func_L20_003FEBA8 */
#include "vu0.h"
typedef struct { u8 p0[0xF8]; u8 xF8[4]; } E_003FEBA8;
typedef struct {
    u8 p0[0x220]; vu0_v4 v220; u8 p230[0xA0]; u8 x2D0[0xFC]; u8 x3CC[4]; u8 x3D0[4]; u8 x3D4[4];
    u8 p3D8[0x14]; E_003FEBA8 *x3EC;
} P_003FEBA8;
extern f32 D_L20_001E2E80[];
__asm__(".extern D_L20_001E2E80, 16");
__asm__(".extern D_L20_001DF5F0, 4");
__asm__(".extern D_L20_001DF5F4, 4");
__asm__(".extern D_L20_001DF5F8, 4");
extern f32 D_L20_001DF5F0;
extern f32 D_L20_001DF5F4;
extern f32 D_L20_001DF5F8;
extern s32 func_0038CAD0(void *);
extern s32 func_0038CB00(void *);
extern void func_L01_00451DF8(void *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L20_003FB350(void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern f32 func_L01_00448728(s32, f32, s32, f32, f32, f32, s32);
extern void func_L20_003FF448(void *);
extern void func_L01_00404808(void *, void *);
extern void func_L05_0035B1A0(u8 *);
extern void func_L05_0035B308(u8 *);

void func_L20_003FEBA8(u8 *a0) {
    P_003FEBA8 *p = *(P_003FEBA8 **)(a0 + 0x68);
    vu0_v4 v;
    vu0_v4 m[3];
    f32 f;

    func_0038CAD0(p->x3D0);
    func_0038CB00(p->x3D4);
    if (*(u16 *)(a0 + 0x96) < 0xFFFF) {
        *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    }
    func_L01_00451DF8(p->x3EC, p->x2D0, 3, 1, 2.5f);
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L20_001E2E80, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6F] = 0x16;
        }
    }
    vec_sub_ba(&v, &p->v220, a0 + 0x10);
    func_L01_0040EE50(m, a0 + 0xC0);
    func_0038D000(&v, &v, m);
    if (v.x > 0.0f || func_L20_003FB350(p->x3EC) != 0) {
        func_0038CF68(&v, &v, 1.0f);
        f = func_0038D0C8(v.y);
        func_L01_00448728((s32)p->x3EC->xF8, f, (s32)p->x3CC,
                          D_L20_001DF5F0 * 0.017453292f * 0.00040000002f,
                          D_L20_001DF5F4 * 0.017453292f * 0.00040000002f,
                          D_L20_001DF5F8 * 0.017453292f * 0.020000001f, 0);
    } else {
        func_L01_00448728((s32)p->x3EC->xF8, 0.0f, (s32)p->x3CC,
                          D_L20_001DF5F0 * 0.017453292f * 0.00040000002f,
                          D_L20_001DF5F4 * 0.017453292f * 0.00040000002f,
                          D_L20_001DF5F8 * 0.017453292f * 0.020000001f, 0);
    }
    if (a0[0x31] != 0) {
        if (func_L20_003FB3B0(a0) != 0) {
            func_L20_003FF448(a0);
            func_L01_00404808(func_L05_0035B308, a0);
        }
        func_L01_00404808(func_L05_0035B1A0, a0);
    }
}
/* localdecomp:end func_L20_003FEBA8 */
