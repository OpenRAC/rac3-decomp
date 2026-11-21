#include "common.h"

/* localdecomp:start func_L04_00500298 */
#include "vu0.h"

typedef struct {
    u8 pad0[0xF0];
    vu0_v4 fF0;
    u8 pad100[0x74];
    f32 f174;
    f32 f178;
    u8 pad17C[0x14];
    vu0_v4 f190;
    f32 f1A0;
    u8 pad1A4[0xC];
    f32 f1B0;
    f32 f1B4;
    u8 pad1B8[0xEF];
    u8 f2A7;
    u8 pad2A8[0xC2];
    s16 f36A;
    u8 pad36C[0x188];
    s16 f4F4;
    u8 pad4F6[0x4EA];
    vu0_v4 f9E0;
    u8 pad9F0[0xA44];
    s16 f1434;
    u8 pad1436[0x27A];
    s32 f16B0;
    u8 pad16B4[0xF10];
    s32 f25C4;
    u8 pad25C8[0x4];
    s32 f25CC;
    u8 pad25D0[0x24];
    u8 f25F4;
} Hero_L04_00500298;

__asm__(".extern D_001A4BE0, 16");
extern Hero_L04_00500298 D_001A4BE0;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_L01_004F05F0(void *);
extern void func_L01_00511508(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_L01_00511408(void *);
extern void func_L01_00511588(void *, void *, f32);
extern s32 func_L01_004606E8(s32, s32, s32, s32);

void func_L04_00500298(f32 amount) {
    vu0_v4 v;
    vu0_v4 tmp;
    vu0_v4 v2;
    f32 angle;
    f32 speed;
    f32 dot;
    f32 l1;
    f32 l2;

    switch (D_001A4BE0.f25F4) {
    case 0:
        angle = D_001A4BE0.f1A0;
        speed = D_001A4BE0.f1B0;
        if (D_001A4BE0.f25CC == 4 && D_001A4BE0.f4F4 != 0 && D_001A4BE0.f2A7 != 0) {
            speed = 0.100000009f;
        }
        if (D_001A4BE0.f36A != 0 && D_001A4BE0.f25C4 == 14 && 0.0200000014f < speed) {
            speed = 0.0200000014f;
        }
        v.x = func_0038D098(angle) * speed;
        v.y = func_0038D0B0(angle) * speed;
        v.z = D_001A4BE0.fF0.z;
        dot = -(D_001A4BE0.fF0.x * v.x + D_001A4BE0.fF0.y * v.y);
        l1 = func_0038CED8(&v);
        l2 = func_0038CED8(&D_001A4BE0.fF0);
        if (l1 == 0.0f || l2 == 0.0f) {
            dot = 0.0f;
        } else {
            dot /= l1;
            dot /= l2;
        }
        if (D_001A4BE0.f25C4 == 0xB0) {
            dot += 0.5f;
        } else {
            dot += 1.0f;
            dot *= 1.5f;
        }
        if (3.0f < dot) {
            dot = 3.0f;
        }
        if (dot < 1.0f) {
            dot = 1.0f;
        }
        vec_sub_ab(&v, &v, &D_001A4BE0.fF0);
        amount *= dot;
        if (amount < func_0038CED8(&v)) {
            func_0038CFB8(&v, &v, amount);
        }
        vec_add_ab(&D_001A4BE0.fF0, &D_001A4BE0.fF0, &v);
        *(vu0_q *)&tmp = *(vu0_q *)&D_001A4BE0.f9E0;
        D_001A4BE0.f1B4 = D_001A4BE0.f178 - func_L01_004F05F0(&tmp);
        if (D_001A4BE0.f1434 != 0 || (D_001A4BE0.f16B0 == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
            D_001A4BE0.f1B4 = D_001A4BE0.f174;
        }
        break;
    case 1:
    case 2:
        *(vu0_q *)&tmp = *(vu0_q *)&D_001A4BE0.f190;
        speed = D_001A4BE0.f1B0;
        func_L01_00511508(&v, &tmp, 0.0f);
        func_0038CF68(&v, &v, speed);
        func_L01_00511508(&v2, &D_001A4BE0.fF0, 0.0f);
        dot = -func_0038CE68(&v2, &v);
        l1 = func_L01_00511408(&v);
        l2 = func_L01_00511408(&D_001A4BE0.fF0);
        if (l1 == 0.0f || l2 == 0.0f) {
            dot = 0.0f;
        } else {
            dot /= l1;
            dot /= l2;
        }
        dot += 1.0f;
        dot *= 1.5f;
        if (3.0f < dot) {
            dot = 3.0f;
        }
        if (dot < 1.0f) {
            dot = 1.0f;
        }
        vec_sub_ab(&v, &v, &D_001A4BE0.fF0);
        func_L01_00511508(&v, &v, 0.0f);
        amount *= dot;
        if (amount < func_L01_00511408(&v)) {
            func_L01_00511588(&v, &v, amount);
        }
        vec_add_ab(&D_001A4BE0.fF0, &D_001A4BE0.fF0, &v);
        D_001A4BE0.f1B4 = D_001A4BE0.f178;
        if (D_001A4BE0.f1434 != 0 || (D_001A4BE0.f16B0 == 1 && func_L01_004606E8(0x28, 2, 0, 0) != 0)) {
            D_001A4BE0.f1B4 = D_001A4BE0.f174;
        }
        break;
    default:
        return;
    }
}
/* localdecomp:end func_L04_00500298 */
