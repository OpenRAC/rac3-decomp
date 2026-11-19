/* functional: high. Needs #include vu0.h and -mvu0-use-vf0-vf2 on this file (as func_L01_003F7350); 224 instruction positions differ at L01 (block layout and register allocation); the multiset of calls, compares, constants and vector ops is identical to retail. */
#include "vu0.h"
typedef struct { vu0_v4 p; vu0_v4 a; vu0_v4 t; vu0_v4 o; } L_3F7490;
extern u8 *D_L01_001E0100;
__asm__(".extern D_L01_001E0100, 16");
extern u8 *D_L01_001E012C;
__asm__(".extern D_L01_001E012C, 16");
extern u8 *D_L01_001E0124;
__asm__(".extern D_L01_001E0124, 16");
extern u8 *D_L01_001E011C;
__asm__(".extern D_L01_001E011C, 16");
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);

s32 func_L01_003F7490(void *pos, u8 *e, f32 radius) {
    L_3F7490 L;
    u8 *m;
    f32 len;
    s32 r;
    *(vu0_q *)&L.p = *(vu0_q *)pos;
    switch (*(s32 *)(e + 0x10)) {
    case 5: {
        f32 reach;
        m = D_L01_001E0124 + (*(s32 *)(e + 0x14) << 7);
        reach = func_0038CEA8(m) + radius;
        len = func_0038CF00(&L.p, m + 0x30);
        if (len < reach) {
            return 1;
        }
        return 0;
    }
    case 3:
        m = D_L01_001E0100 + (*(s32 *)(e + 0x14) << 7);
        vec_sub_ab(&L.t, &L.p, m + 0x30);
        L.t.w = 0.0f;
        func_0038D000(&L.o, &L.t, m + 0x40);
        if (L.o.x >= -1.0f && L.o.x <= 1.0f && L.o.y >= -1.0f && L.o.y <= 1.0f && L.o.z >= -1.0f && L.o.z <= 1.0f) {
            return 1;
        }
        return 0;
    case 6:
        m = D_L01_001E012C + (*(s32 *)(e + 0x14) << 7);
        r = 0;
        vec_sub_ab(&L.t, &L.p, m + 0x30);
        L.t.w = 0.0f;
        func_0038D000(&L.o, &L.t, m + 0x40);
        len = func_0038CED8(&L.o);
        if (len < 1.0f) {
            if (L.o.z >= -1.0f && L.o.z <= 1.0f) {
                r = 1;
            }
        }
        return r;
    case 7:
        m = D_L01_001E011C + *(s32 *)(e + 0x14) * 0x90;
        vec_sub_ab(&L.t, &L.p, m + 0x30);
        L.t.w = 0.0f;
        func_0038D000(&L.o, &L.t, m + 0x40);
        len = func_0038CED8(&L.o);
        if (len < 1.0f) {
            if (L.o.z >= -1.0f && L.o.z <= 1.0f) {
                return 1;
            }
        }
        L.a.x = 0.0f;
        L.a.y = 0.0f;
        L.a.z = 1.0f;
        L.a.w = 1.0f;
        func_0038D000(&L.o, &L.a, m);
        vec_add_ab(&L.o, m + 0x30, &L.o);
        vec_sub_ab(&L.a, &L.p, &L.o);
        len = func_0038CEA8(&L.a);
        if (len < *(f32 *)(m + 0x80)) {
            return 1;
        }
        L.a.z = -1.0f;
        L.a.w = 1.0f;
        L.a.x = 0.0f;
        L.a.y = 0.0f;
        func_0038D000(&L.o, &L.a, m);
        vec_add_ab(&L.o, m + 0x30, &L.o);
        vec_sub_ab(&L.a, &L.p, &L.o);
        len = func_0038CEA8(&L.a);
        if (len < *(f32 *)(m + 0x80)) {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
