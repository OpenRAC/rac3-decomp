#include "common.h"

/* localdecomp:start func_U_L07_003B5C58 */
#include "vu0.h"
typedef struct { u8 b[16]; } Hit_003B7548;
extern u8 D_L07_001E1EC0[];
extern u8 *D_L07_001DF41C;
extern s32 D_L07_001D66B0;
__asm__(".extern D_L07_001D66B0, 16");
extern void func_L07_003B6550(u8 *);
extern void func_L07_003B6690(u8 *);
extern s32 func_L01_004576E8(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B6DA0(void *, s32);
extern void func_L07_003B7360(u8 *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern s32 func_L01_0044AF40(void *, f32);
extern void func_L07_003B7490(u8 *);
extern void func_L07_0030FC78(void *, void *, s32, f32);
extern void func_L07_003B70F0(u8 *);
extern f32 func_L01_00436500(void *);
extern void func_L07_003A5D60(s32);
extern void func_U_L07_003A5CA8(s32, s32, s32);
extern s32 func_L01_004A72A8(s32, s32, void *, s32);
extern void func_L07_003B72B0(u8 *);
extern void func_L07_003B7698(void *);
extern void func_L07_003B7000(u8 *);
extern s32 func_L01_00457440(void *, void *);
extern f32 func_0038CF38(void *, void *);
extern s32 func_00382468(s32);
extern void func_L07_003B73F0(u8 *);
extern void func_L01_00438908(void *, s32, s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_00330E70(void *);
extern void func_L07_003B70D0(int, void (*)(void));

void func_U_L07_003B5C58(u8 *self) {
    u8 *p;

    if (self[0x20] == 0) func_L07_003B6550(self);
    func_L07_003B6690(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 1:
        break;
    case 2:
        func_L01_004576E8(self);
        if (func_0038CB00(p + 0x19E)) func_L07_003B6DA0(self, 3);
        break;
    case 3:
        p[0x1AE] = 1;
        func_L07_003B7360(self);
        break;
    case 5:
        if (func_L01_00452EC8(self)) {
            *(u16 *)(self + 0x34) |= 0x5000;
            if (*(s16 *)(p + 0x29C) == 0) {
                func_L07_003A0BC0(16, (s32)self, 0, 120);
                *(s16 *)(p + 0x29C) = 400;
            }
        }
        if (self[0x60] & 2) func_L07_003B6DA0(self, 6);
        break;
    case 6:
        if (func_L01_00452EC8(self)) p[0x29A] = 0;
        func_L01_004576E8(self);
        *(f32 *)(p + 0x218) = func_0038DB00(func_0038D160(*(f32 *)(p + 0x70) - *(f32 *)(self + 0x10),
                                                          *(f32 *)(p + 0x74) - *(f32 *)(self + 0x14)),
                                            *(f32 *)(self + 0xF8));
        if (self[0x42] == 6 && func_L01_0044AF40(self, 20.5f)) {
            vu0_v4 pos;
            {
                u8 *g = D_L07_001E1EC0;
                f32 a;
                p[0x29A]++;
                *(f32 *)(g + 0x20) = 0.1f;
                *(s32 *)(g + 0x28) = 30;
                *(s32 *)(g + 0x2C) = 0;
                *(f32 *)(g + 0x40) = 0.1f;
                *(s32 *)(g + 0x48) = 30;
                func_L07_003B7490(self);
                pos = *(vu0_v4 *)(self + 0x10);
                a = func_0038DAB8(*(f32 *)(self + 0xF8), *(f32 *)(p + 0x1F8));
                func_L07_0030FC78(self, &pos, p[0x44], a);
            }
        }
        if (self[0x60] & 2) {
            if (p[0x296] == 0) {
                if (p[0x29A] >= 4) func_L07_003B6DA0(self, 7);
            } else if (p[0x29A] >= 5) {
                func_L07_003B70F0(self);
            }
        }
        break;
    case 7:
        func_L01_004576E8(self);
        if (self[0x60] & 2) func_L07_003B70F0(self);
        break;
    case 8:
        if (self[0x42] == 4) {
            f32 d = func_L01_00436500(self);
            if (d >= 30.0f && d <= 50.0f) func_L07_003A5D60(*(s32 *)(p + 0x288));
            if (func_L01_0044AF40(self, 20.0f)) func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 1, 10);
            if (func_L01_0044AF40(self, 45.0f)) {
                func_L01_004A72A8(10, 0, self, 0x1A1F);
                func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 2, 10);
            }
        }
        func_L01_004576E8(self);
        if (self[0x60] & 2) {
            func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 0, 10);
            func_L07_003B72B0(self);
        }
        break;
    case 9:
        if (self[0x42] == 5) {
            f32 d = func_L01_00436500(self);
            if (d >= 30.0f && d <= 90.0f) func_L07_003A5D60(*(s32 *)(p + 0x288));
            if (func_L01_0044AF40(self, 15.0f) || func_L01_0044AF40(self, 55.0f))
                func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 1, 10);
            if (func_L01_0044AF40(self, 45.0f) || func_L01_0044AF40(self, 80.0f)) {
                func_L01_004A72A8(10, 0, self, 0x1A1F);
                func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 2, 10);
            }
        }
        func_L01_004576E8(self);
        if (self[0x60] & 2) {
            func_U_L07_003A5CA8(*(s32 *)(p + 0x288), 0, 10);
            func_L07_003B72B0(self);
        }
        break;
    case 10:
        if (func_L01_00452EC8(self)) {
            u8 *q = p + 0x90;
            *(s32 *)(q + 0x38) |= 0x415;
            *(f32 *)(q + 0x20) = 0.05f;
            *(f32 *)(q + 0x28) = 0.33333334f;
            *(f32 *)(q + 0x24) = 0.05f;
        }
        if (self[0x42] == 1 && func_L01_00436500(self) > 5.0f) {
            func_L07_003B7698(self);
            func_L07_003B7000(self);
            func_L01_00457440(self, p + 0x270);
        } else {
            func_L01_004576E8(self);
        }
        if (self[0x60] & 2) func_L07_003B6DA0(self, 11);
        break;
    case 11: {
        vu0_v4 v;
        vu0_v4 *pv;
        f32 t;
        if (func_L01_00452EC8(self)) *(f32 *)(p + 0x28C) = func_0038CF38(self + 0x10, p + 0x270);
        func_L07_003B7698(self);
        func_L07_003B70D0((s32)self, *(void (**)(void))(p + 0x290));
        func_L07_003B7000(self);
        pv = &v;
        *pv = *(vu0_v4 *)(p + 0x270);
        t = func_0038CF38(self + 0x10, pv);
        v.z += t * 20.0f / *(f32 *)(p + 0x28C) + 2.0f;
        if (func_L01_00457440(self, pv) & 0x80) func_L07_003B6DA0(self, 12);
        break;
    }
    case 12:
        func_L07_003B70D0((s32)self, *(void (**)(void))(p + 0x290));
        if (self[0x42] != 3 || func_L01_00436500(self) <= 3.0f) {
            func_L07_003B7698(self);
            func_L07_003B7000(self);
            func_L01_00457440(self, p + 0x270);
        } else {
            if (func_L01_00452EC8(self)) {
                if (p[0x297] != 14) {
                    u8 *g = D_L07_001E1EC0;
                    *(s32 *)(g + 0x2C) = 0;
                    *(f32 *)(g + 0x20) = 0.05f;
                    *(s32 *)(g + 0x28) = 15;
                    *(s32 *)(g + 0x48) = 15;
                    *(f32 *)(g + 0x40) = 0.05f;
                }
                func_L07_003B7490(self);
            }
            *(s32 *)(p + 0xC8) &= ~0x415;
            func_L01_004576E8(self);
        }
        if (self[0x60] & 2) {
            if (p[0x296] == 0 && (p[0x29B] & 1)) {
                func_L07_003A0BC0(9, (s32)self, 0, 120);
                p[0x29B] |= 1;
            }
            func_L07_003B6DA0(self, p[0x297]);
        }
        break;
    case 13:
        if (func_L01_00452EC8(self)) {
            *(s32 *)(p + 0xC8) &= ~0x415;
            *(u16 *)(self + 0x34) &= ~0x5000;
            if (*(f32 *)(p + 0x138) > 0.0f) *(f32 *)(p + 0x138) = 0.0f;
            if (p[0x296] == 1) func_L07_003A0BC0(3, (s32)(D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8)), 0, 120);
        }
        func_L01_004576E8(self);
        if (self[0x60] & 2) func_L07_003B7360(self);
        break;
    case 14:
        if (func_L01_00452EC8(self)) *(s16 *)(p + 0x294) = func_00382468(120) + 240;
        func_L01_004576E8(self);
        func_0038CB00(p + 0x294);
        if (self[0xBC] == 3) {
            func_L07_003B73F0(self);
        } else if (*(s16 *)(p + 0x294) == 0) {
            if (self[0xBC] == 2) {
                func_L07_003B6DA0(self, 15);
                self[0xBC] = 0;
            } else if (self[0xBC] == 1) {
                func_L07_003B6DA0(self, 16);
                self[0xBC] = 0;
            }
        }
        break;
    case 15:
    case 16:
        func_L01_004576E8(self);
        if (self[0x60] & 2) func_L07_003B6DA0(self, 14);
        break;
    case 17:
        func_L01_004576E8(self);
        if (self[0x60] & 2) {
            Hit_003B7548 saved = *(Hit_003B7548 *)(p + 0x180);
            func_L01_00438908(self, saved.b[4], saved.b[5], saved.b[6]);
            func_L07_003A0BC0(7, (s32)(D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8)), 0, 120);
            func_L01_0044ED60(self, 0x3FFF, &D_L07_001D66B0, 3.0f, 6.0f, 10.0f, 16.0f, -1.0f, -1.0f, 1.0f, 1.0f,
                              255, 180, 0, 0, 35, 0, 3);
            func_L07_00330E70(self);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_003B5C58 */
