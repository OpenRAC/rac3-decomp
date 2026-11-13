#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003D6240 */
typedef struct { u8 pad[0x28]; f32 x28; } H_3D6240;
extern H_3D6240 D_L19_001E8E40;
extern f32 D_L19_001DF250;
extern void func_L01_00450F00(u8 *self, void *out);
extern void func_L01_003F8550(u8 *);
extern void func_0038D000(void *, void *, void *);
extern s32 func_L01_003FB640(void *, s32, f32, void *);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern u8 *func_L01_0046ADE0(void *, void *, f32);
extern s32 func_0038CB00(void *);
extern s32 func_00382468(s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);

void func_L19_003D6240(u8 *self) {
    u8 *v = *(u8 **)(self + 0x68);
    vu0_v4 o;
    vu0_v4 pos[2];
    vu0_v4 vel[2];
    f32 ang;
    f32 s;
    u8 *p;
    s32 i;
    u8 *b;
    u32 t;

    func_L01_00450F00(self, &o);
    func_L01_003F8550(self);
    func_0038D000(&pos[0], v + 0x20, self + 0xC0);
    vec_add_ab(&pos[0], &pos[0], self + 0x10);
    if (func_L01_003FB640(&pos[0], 2, *(f32 *)(v + 0x2C), *(void **)(v + 0x54)) != 0) {
        for (i = 0; i < 2; i++) {
            ang = func_00382538();
            pos[1].x = func_0038D098(ang) * (*(f32 *)(v + 0x2C) * 0.5f);
            pos[1].y = func_0038D0B0(ang) * (*(f32 *)(v + 0x2C) * 0.5f);
            pos[1].z = 0.0f;
            vec_add_ab(&pos[1], &pos[1], self + 0x10);
            pos[1].z = D_L19_001E8E40.x28;
            ang = ang + func_003824E0(-0.17453292f, 0.17453292f);
            s = -*(f32 *)(v + 8) * func_003824E0(0.1f, 0.25f);
            vel[0].x = func_0038D098(ang) * s;
            vel[0].y = func_0038D0B0(ang) * s;
            vel[0].z = 0.0f;
            vel[0].z = -*(f32 *)(v + 8) * func_003824E0(0.150000006f, 0.300000012f);
            func_0038CE20(&vel[0], &vel[0], 0.5f);
            vel[0].w = 0.5f;
            func_0038CE20(&vel[1], &vel[0], 0.5f);
            vel[1].z = 0.0f;
            vel[1].w = 0.25f;
            p = func_L01_0046ADE0(pos, vel, 0.25f);
            if (p != 0)
                *(s32 *)(p + 4) = 0x50908080;
        }
    }
    switch (self[0x20]) {
    case 0:
        b = *(u8 **)(self + 0xB8);
        if (b != 0)
            self[0x23] = b[0x23];
        if (func_0038CB00(v + 0x34) != 0
            || (0.95f < D_L19_001DF250 && func_00382468(10) == 0)) {
            func_L01_004450F0(self, 1, -1);
            *(u16 *)(self + 0x34) |= 0x2800;
        }
        break;
    case 1:
        t = self[0x23];
        if (t < 2)
            func_003C2880(self);
        else
            self[0x23] = t - 2;
        break;
    }
}
/* localdecomp:end func_L19_003D6240 */
