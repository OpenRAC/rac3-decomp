#include "common.h"

/* NTSC-U counterpart of func_L43_0041F848 (src/levels/shared/L43_0041F848.c) */
/* localdecomp:start func_L43_0041EED8 */
#include "vu0.h"
typedef struct {
    u8 pad00[0x68];
    u8 *p68;
    u8 pad6C[0x94];
} M_0041F848;
extern M_0041F848 *D_001DCCCC_sda_0041EED8;
extern u8 D_L43_001FE1A0[];
typedef struct {
    u8 pad00[0xD0];
    u8 bD0;
    u8 padD1[0xB];
    u8 *wDC;
} Slot_0041F848;
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_L01_00442300(void *, void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L39_005F0CE0(s32, s32, void *);
extern void func_L39_005F0988(s32);
extern s32 func_L01_00443080(f32 *, f32 *, f32, f32, f32);

typedef struct {
    u8 pad00[0x80];
    s32 f80;
    u8 pad84[4];
    f32 f88;
    s32 f8C;
    vu0_q q90;
    vu0_q qA0;
    f32 fB0;
    f32 fB4;
    f32 fB8;
    f32 fBC;
    s32 fC0;
} O_0041F848;

void func_L43_0041EED8(u8 *a0) {
    O_0041F848 *obj = *(O_0041F848 **)(a0 + 0x68);
    vu0_v4 v;
    f32 r0;
    f32 r1;
    f32 ang;
    f32 target;
    f32 step;
    f32 a;
    f32 b;
    f32 ratio;
    s32 i;
    s32 idx;
    u8 *pos;
    u8 *dst;
    u8 *prev;

    switch (*(u8 *)(a0 + 0x20)) {
    case 0:
        obj->fB4 = 0.0f;
        obj->fC0 = -1;
        dst = (u8 *)&obj->qA0;
        pos = a0 + 0x10;
        *(vu0_q *)dst = *(vu0_q *)pos;
        ang = func_00389380(*(f32 *)(a0 + 0xF8), obj->f80 != 0 ? 4.712389f : 1.5707964f);
        v.x = func_00388960(ang) * obj->fBC;
        v.y = func_00388978(ang) * obj->fBC;
        v.z = 0.0f;
        prev = (u8 *)&obj->q90;
        vec_add_ab(a0 + 0x10, a0 + 0x10, &v);
        *(vu0_q *)prev = *(vu0_q *)(a0 + 0x10);
        obj->fB8 = obj->fB8 * 0.01666666753590107f;
        obj->fB0 = obj->fB0 * 0.01666666753590107f;
        *(u8 *)(a0 + 0x30) = 0xFF;
        obj->f88 = 0.0f;
        if (obj->f8C >= 0) {
            obj->f88 = *(f32 *)(D_001DCCCC_sda_0041EED8[obj->f8C].p68 + 4) * obj->fBC;
        }
        func_L01_00442300(pos, prev, dst, obj->f88 / obj->fBC);
        func_L01_00441FB8(a0, 1, -1);
        break;
    case 1:
        if (obj->f8C == -1) {
            break;
        }
        target = *(f32 *)(D_001DCCCC_sda_0041EED8[obj->f8C].p68 + 4) * obj->fBC;
        if (obj->f88 != target) {
        {
        s32 snd = obj->fC0;
        if (snd == -1 || ((Slot_0041F848 *)(D_L43_001FE1A0 + (snd << 7)))->wDC != a0 || ((Slot_0041F848 *)(D_L43_001FE1A0 + (snd << 7)))->bD0 == 0) {
            obj->fC0 = func_L39_005F0CE0(0, 4, a0);
        }
        }
        step = obj->fB0;
        if (target < obj->f88) {
            step = -step;
        }
        if (obj->fB4 != 0.0f) {
            a = fabs_asm(target - obj->f88);
            b = fabs_asm(obj->fB4);
            ratio = a / b;
            r0 = 0.0f;
            r1 = 0.0f;
            if (func_L01_00443080(&r0, &r1, obj->fB0 * -0.5f, b, -a) > 0) {
                if (r0 > 0.0f && ratio < r0) {
                    step = -step;
                }
            }
        }
        obj->fB4 = obj->fB4 + step;
        if (obj->fB4 > obj->fB8) {
            obj->fB4 = obj->fB8;
        }
        if (obj->fB4 < -obj->fB8) {
            obj->fB4 = -obj->fB8;
        }
        obj->f88 = obj->f88 + obj->fB4;
        if (obj->f88 > obj->fBC) {
            obj->f88 = obj->fBC;
        }
        if (obj->f88 < 0.0f) {
            obj->f88 = 0.0f;
        }
        if ((obj->fB4 < 0.0f && obj->f88 < target) ||
            (obj->fB4 > 0.0f && obj->f88 > target)) {
            obj->f88 = target;
        }
        func_L01_00442300(a0 + 0x10, &obj->q90, &obj->qA0, obj->f88 / obj->fBC);
        } else {
            obj->fB4 = 0.0f;
            idx = obj->fC0;
            if (idx != -1 && ((Slot_0041F848 *)(D_L43_001FE1A0 + (idx << 7)))->wDC == a0 && ((Slot_0041F848 *)(D_L43_001FE1A0 + (idx << 7)))->bD0 != 0) {
                func_L39_005F0988(idx);
            }
            obj->fC0 = -1;
        }
        break;
    }
}
/* localdecomp:end func_L43_0041EED8 */
