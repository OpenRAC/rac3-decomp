#include "common.h"

/* localdecomp:start func_U_L07_00350F58 */
#include "vu0.h"
extern void func_L07_00351810(u8 *);
extern void func_L07_00351A58(u8 *);
extern void func_L07_00351DC8(s32, s32);
extern void func_L07_00352188(u8 *);
extern void func_L07_00352230(u8 *, f32);
extern void func_L07_003522F0(u8 *, f32);
extern void func_L07_00352478(u8 *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003525D0(u8 *);
extern s32 func_L07_00352678(u8 *, u8);
extern s32 func_L07_00352798(s32);
extern void func_L07_003528E8(u8 *, f32);
extern void func_L07_00352A30(s32);
extern void func_L07_00352AB0(s32);
extern void func_L07_00352BA0(u8 *);
extern void func_L07_00352C80(u8 *);
extern void func_L07_00352DB0(u8 *);
extern void func_L07_00330E70(u8 *);
extern s32 func_L07_003308C8(s32, s32);
extern s32 func_L01_004576E8(void *);
extern s32 func_L01_00457708(u8 *, f32);
extern void func_L01_00457440(void *, void *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_0038CB00(void *);
extern s32 func_L01_00451078(void *, void *);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00436500(void *);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_003C2F58(u8 *, s32, void *);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L06_003577D0(void *, void *, void *, void *, s32, s32, f32);
extern s32 D_L07_001D66B0;
__asm__(".extern D_L07_001D66B0, 16");

void func_U_L07_00350F58(u8 *self) {
    u8 *v;
    vu0_v4 a;
    vu0_v4 b;
    s32 r;
    f32 ang;

    if (self[0x20] == 0) func_L07_00351810(self);
    func_L07_00351A58(self);
    v = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_004576E8(self);
        if (func_0038CB00(v + 0x24E)) func_L07_00351DC8((s32)self, 3);
        break;
    case 3:
        func_L01_004576E8(self);
        func_L07_00351DC8((s32)self, 4);
        break;
    case 4:
        func_L01_00457440(self, *(u8 **)(v + 0x240) + 0x10);
        if (func_L01_0040C040(*(u8 **)(v + 0x240) + 0x10, self + 0x10) < 484.0f) {
            v[0x25E] = 1;
            func_L07_00351DC8((s32)self, 6);
        }
        break;
    case 5:
        func_L01_004576E8(self);
        r = func_L01_00451078(self, v + 0x70);
        if (r & 1) {
            *(vu0_q *)&a = *(vu0_q *)(self + 0x10);
            a.z += *(f32 *)(v + 0x40);
            func_L01_0032FE90(&a, 0, 10, 5, 4, 10, 15, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_0044ED60(self, 0x3FFF, &D_L07_001D66B0, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            func_L07_00330E70(self);
            func_003A52A0(9, 0, self);
        } else if (r & 2) {
            if (v[0x25E] != 0) {
                if (self[0x94] >= 7) {
                    func_L07_00351DC8((s32)self, 7);
                } else {
                    func_L07_00351DC8((s32)self, 6);
                }
            } else {
                func_L07_00351DC8((s32)self, 4);
            }
        }
        break;
    case 6:
        func_L01_004576E8(self);
        if (func_L07_003308C8(*(s32 *)(v + 0x240), (s32)self) != 0) {
            func_L07_00351DC8((s32)self, 7);
        } else {
            func_L07_00351DC8((s32)self, 24);
        }
        break;
    case 7:
        func_L01_004576E8(self);
        r = func_L07_00352678(self, 0);
        if (r != -1) {
            v[0x466] = 0;
            v[0x464] = r;
            v[0x465] = 1;
            func_L07_003525D0(self);
        }
        break;
    case 8:
        func_L07_003522F0(self, 6.0f);
        break;
    case 9:
        func_L07_003522F0(self, 10.0f);
        break;
    case 10:
        func_L07_00352188(self);
        if (self[0x60] & 2) func_L07_00351DC8((s32)self, 11);
        break;
    case 11:
        func_L07_003522F0(self, -1.0f);
        break;
    case 12:
        if (self[0x60] & 2) func_L07_00351DC8((s32)self, v[0x464] + 13);
        break;
    case 13:
        func_L01_00457708(self,
            func_0038D160(*(f32 *)(v + 0x130) - *(f32 *)(self + 0x10),
                          *(f32 *)(v + 0x134) - *(f32 *)(self + 0x14)));
        if (v[0x466] == 0) {
            f32 t = func_L01_00436500(self);
            if (t >= 14.0f && t <= 24.0f) func_L07_00352BA0(self);
        }
        func_L07_003528E8(self, 25.0f);
        break;
    case 14:
        func_L01_004576E8(self);
        if (v[0x466] == 0) {
            f32 t = func_L01_00436500(self);
            if (t >= 12.0f && t <= 20.0f) func_L07_00352C80(self);
        }
        func_L07_003528E8(self, 25.0f);
        break;
    case 15:
        func_L01_004576E8(self);
        if (v[0x466] == 0) {
            f32 t = func_L01_00436500(self);
            if (t >= 15.0f && t <= 21.0f) func_L07_00352DB0(self);
        }
        func_L07_003528E8(self, 30.0f);
        break;
    case 16:
        if (v[0x466] == 0) {
            f32 t = func_L01_00436500(self);
            if (t >= 22.0f && t <= 26.0f) func_L07_00352DB0(self);
        }
        func_L07_00352478(self, 13, 0, 1, func_L01_00436500(self), 1.5f, 3.5f, 8.0f, 24.0f, 16.0f);
        func_L01_00445758(self + 0xF8,
                          func_0038D160(*(f32 *)(v + 0x130) - *(f32 *)(self + 0x10),
                                        *(f32 *)(v + 0x134) - *(f32 *)(self + 0x14)),
                          v + 0x204, *(f32 *)(v + 0x164), *(f32 *)(v + 0x168), *(f32 *)(v + 0x16C), 0);
        func_L07_003528E8(self, 30.0f);
        break;
    case 17:
        func_L01_004576E8(self);
        if (func_L01_0044AF40(self, 14.0f) && self[0x42] == 14) {
            func_003C2F58(self, 4, &b);
            ang = func_0038DB00(func_0038D160(*(f32 *)(v + 0x130) - b.x, *(f32 *)(v + 0x134) - b.y),
                                *(f32 *)(self + 0xF8));
            if (ang > 0.7853982f) ang = 0.7853982f;
            else if (ang < -0.7853982f) ang = -0.7853982f;
            ang = func_0038DAB8(*(f32 *)(self + 0xF8), ang);
            a.x = func_0038D098(ang) * 0.8333334f;
            a.y = func_0038D0B0(ang) * 0.8333334f;
            a.z = 0.0f;
            func_L06_003577D0(self, &a, &b, self + 0xF0, 0x10001, 1, 1.0f);
        }
        func_L07_003528E8(self, 15.5f);
        break;
    case 18:
        func_L07_00352478(self, 8, 1, 1, func_L01_00436500(self), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_00352A30((s32)self);
        break;
    case 19:
        func_L07_00352478(self, 7, 1, -1, func_L01_00436500(self), 1.8f, 3.0f, 7.0f, 23.0f, 16.0f);
        func_L07_00352A30((s32)self);
        break;
    case 20:
        func_L07_00352478(self, 9, 0, -1, func_L01_00436500(self), 1.5f, 3.0f, 8.0f, 24.0f, 16.0f);
        func_L07_00352A30((s32)self);
        break;
    case 21:
    case 22:
    case 23:
        func_L07_00352AB0((s32)self);
        break;
    case 24:
        func_L07_00352230(self, 5.5f);
        if (func_L07_003308C8(*(s32 *)(v + 0x240), (s32)self) != 0) {
            func_L07_00351DC8((s32)self, 6);
        } else if (func_L01_0040C040(self + 0x10, v + 0x130) < 36.0f) {
            func_L07_00352798((s32)self);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_00350F58 */
