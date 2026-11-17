#include "common.h"

/* declared by functions of L03_003B11C8.c, which this file was cut from */
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern void func_L03_003B1520(void *);

/* localdecomp:start func_L03_003B1520 */
#include "vu0.h"

extern u8 D_001A4BE0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038CED8(void *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L03_003B1520(void *arg) {
    u8 *a0 = arg;
    u8 *st;
    f32 rate = 0.02f;
    f32 rate2 = 0.3f;
    f32 yaw;
    f32 pitch;
    vu0_v4 d;
    vu0_q qt, qp, qd;
    vu0_v4 target;
    vu0_v4 pos;

    st = *(u8 **)(a0 + 0x68);
    if (a0[0x42] == 1) {
        yaw = 0.0f;
        pitch = yaw;
    } else {
        if (*(s32 *)(st + 0x124) != 0) {
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(a0 + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(*(vu0_v4 *)(st + 0x100)));
        } else {
            if (func_0038CF38(a0 + 0x10, D_001A4BE0 + 0x80) < 8.0f) {
                u8 *hero = D_001A4BE0;
                f32 ang = func_0038D160(*(f32 *)(hero + 0xE0) - *(f32 *)(a0 + 0x10),
                                        *(f32 *)(hero + 0xE4) - *(f32 *)(a0 + 0x14));
                if (func_0038DBA0(*(f32 *)(a0 + 0xF8), ang) < 1.5707964f) {
                    if (func_0038CEA8(D_001A4BE0 + 0x110) > 0.01f) {
                        *(s32 *)(st + 0x114) = 100;
                    } else {
                        func_0038CAD0(st + 0x114);
                    }
                    goto timer;
                }
            }
            if (*(s32 *)(st + 0x114) != 0) {
                *(s32 *)(st + 0x114) = 0;
                *(vu0_q *)(st + 0x100) = *(vu0_q *)(D_001A4BE0 + 0xE0);
            }
        timer:
            if (func_0038CAD0(st + 0x118)) {
                f32 r = 6.0f;
                f32 h;
                f32 p;
                *(s32 *)(st + 0x118) = (func_003824E0(180.0f, 300.0f) * 5.0f + 2.0f) / r;
                h = func_0038DAB8(*(f32 *)(a0 + 0xF8), func_003824E0(-90.0f, 90.0f) * 0.017453292f);
                p = func_003824E0(0.0f, 30.0f) * 0.017453292f;
                func_00382760(st + 0x100, r, h, p);
                vec_add_ab(st + 0x100, st + 0x100, a0 + 0x10);
            }
            if (*(s32 *)(st + 0x114) != 0) {
                rate = 0.04f;
                rate2 = 0.3f;
                *(vu0_q *)&target = *(vu0_q *)(D_001A4BE0 + 0xE0);
            } else {
                *(vu0_q *)&target = *(vu0_q *)(st + 0x100);
            }
            *(vu0_q *)&pos = *(vu0_q *)(a0 + 0x10);
            pos.z += 2.0f;
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(target));
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(pos));
        }
        __asm__("vsub.xyz %0, %1, %2" : "=j"(qd) : "j"(qt), "j"(qp));
        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qd));
        yaw = func_0038DB00(func_0038D160(d.x, d.y), *(f32 *)(a0 + 0xF8));
        pitch = -func_0038D160(func_0038CED8(&d), d.z);
    }
    if (yaw > 1.2217305f) {
        yaw = 1.2217305f;
    } else if (yaw < -1.2217305f) {
        yaw = -1.2217305f;
    }
    if (pitch > 0.5235988f) {
        pitch = 0.5235988f;
    } else if (pitch < -0.5235988f) {
        pitch = -0.5235988f;
    }
    *(f32 *)(st + 0x68) = yaw * 0.8f;
    *(f32 *)(st + 0xE8) = yaw * 0.2f;
    *(f32 *)(st + 0x64) = pitch;
    func_L01_0044E850(a0, st, 0, rate * 1.44f, rate2 * 1.44f);
    func_L01_0044E850(a0, st + 0x80, 1, rate * 1.44f, rate2 * 1.44f);
}
/* localdecomp:end func_L03_003B1520 */
