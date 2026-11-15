#include "common.h"

/* localdecomp:start func_L20_003F3FF8 */
#include "vu0.h"

typedef int q_003F3FF8 __attribute__((mode(TI)));

extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
extern f32 func_00382538(void);
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, f32, f32, f32, u32, u32, u32, u32);
extern f32 D_L20_001E2E00[];
__asm__(".extern D_L20_001E2E00, 16");
__asm__(".extern D_L20_001DF410, 4");
__asm__(".extern D_L20_001DF414, 4");
__asm__(".extern D_L20_001DF418, 4");
__asm__(".extern D_L20_001DF41C, 4");
__asm__(".extern D_L20_001DF420, 4");
__asm__(".extern D_L20_001DF424, 4");
__asm__(".extern D_L20_001DF428, 4");
__asm__(".extern D_L20_001DF42C, 4");
extern s32 D_L20_001DF410;
extern s32 D_L20_001DF414;
extern f32 D_L20_001DF418;
extern f32 D_L20_001DF41C;
extern f32 D_L20_001DF420;
extern f32 D_L20_001DF424;
extern u32 D_L20_001DF428;
extern u32 D_L20_001DF42C;

typedef struct {
    u8 p0[0x20];
    f32 x20;
    f32 x24;
    u8 p28[0x4C - 0x28];
    f32 x4C;
    u8 p50[0xC70 - 0x50];
    f32 xC70[12][4];
    f32 xD30[12];
    f32 xD60;
} S_003F3FF8;

void func_L20_003F3FF8(u8 *obj) {
    S_003F3FF8 *s = *(S_003F3FF8 **)(obj + 0x68);
    f32 d[4] __attribute__((aligned(16)));
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u32 col;
    s32 i;

    col = func_0038DBD8(D_L20_001DF410, D_L20_001DF414, func_0038D0B0(D_L20_001DF418) * 0.5f + 0.5f);
    D_L20_001DF418 = func_0038DAB8(D_L20_001DF418, func_003824E0(D_L20_001DF41C, D_L20_001DF420) * 0.017453292f * 0.020000001f);
    func_003D9508(obj + 0x10, 0x43, col, 1, 2.25f, -0.1f, s->x20);
    func_003D9508(obj + 0x10, 0x4B, 0x7FFFFFFF, 3, 2.0f, 0.025f, -s->x20);
    func_003D9508(obj + 0x10, 0x31, 0x7FFFFFFF, 3, 4.0f, 0.0f, -s->x24);
    func_003D9508(obj + 0x10, 0x31, 0x4FFFFFFF, 1, 4.0f, 0.08f, s->x24);
    func_003D9508(obj + 0x10, 0x31, 0x7FFFFFFF, 3, 4.0f, 0.0f, func_00382538());
    func_003D9508(obj + 0x10, 0x31, 0x4FFFFFFF, 1, 4.0f, 0.0f, func_00382538());
    for (i = 0; i < 12; i++) {
        vec_sub_ab(d, D_L20_001E2E00, obj + 0x10);
        func_0038D890(s->xC70[i], s->xC70[i], d, s->xD30[i]);
        s->x4C = s->x4C + 0.03f;
        if (2.5f < s->x4C) {
            s->x4C = 2.5f;
        }
        func_0038CF68(s->xC70[i], s->xC70[i], s->x4C);
        vec_add_ab(a, s->xC70[i], obj + 0x10);
        *(q_003F3FF8 *)b = *(q_003F3FF8 *)(obj + 0x10);
        func_L01_0040A8C0(a, b, 0x12, 1, D_L20_001DF424, 3.0f, s->xD60, D_L20_001DF428, D_L20_001DF428, D_L20_001DF42C, D_L20_001DF42C);
    }
    s->xD60 = s->xD60 - func_003824E0(0.025f, 0.035f);
    if (s->xD60 <= -8.0f) {
        s->xD60 = s->xD60 + 8.0f;
    }
}
/* localdecomp:end func_L20_003F3FF8 */
