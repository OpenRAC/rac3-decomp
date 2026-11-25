#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L07_003AFD10. */
/* localdecomp:start func_U_L07_003AE498 */
typedef struct {
    u8 pad[0x80];
    f32 x, y;
} Hero_003AFD10;
extern Hero_003AFD10 D_001A4BE0_003AFD10;
extern u8 D_001A4C60[];
extern u8 D_001A30B0[];
extern s32 func_U_003AED30(void *);
extern void func_U_00436AE0(void *);
extern s32 func_U_00453488(void *);
extern void func_U_004421E8(void *, s32, s32, s32);
extern s32 func_U_004537B0(void *, s32);
extern f32 func_U_0040C8F8(void *, void *);
extern void func_U_004A60E0(s32, s32, void *);
extern void func_U_004A5D68(s32);
extern f32 func_U_0040D8C0(f32, f32);
extern f32 func_U_0040D820(f32, f32);
extern f32 func_U_0040CDA0(f32, f32);
extern f32 func_U_0040D7D8(f32, f32);
extern void func_U_004460C8(char *a0, char *a1, int a2, float f12, float f13,
                              float f14, float f15);
extern void func_U_003AEEB8(u8 *);
extern void func_U_003AEDE0(u8 *);
extern void func_U_00403C00(void *, void *);
extern s32 func_U_0040C3A0(void *);
extern void func_U_0040CA00(void *, void *, f32);
extern void func_U_00437F58(void *, s32, void *);
extern void func_U_003A13D8(void *, void *, void *, s32, f32);
extern void func_U_00442528(void *, s32, s32);
extern void func_U_003AF0D0(u8 *);

static __inline__ void release_003AFD10(u8 *self, u8 *p) {
    s32 index = *(s32 *)(p + 0x7C);
    if (index != -1) {
        u8 *slot = D_001A30B0 + index * 128;
        if (*(u8 **)(slot + 0xDC) == self && slot[0xD0])
            func_U_004A5D68(index);
    }
    *(s32 *)(p + 0x7C) = -1;
}

void func_U_L07_003AE498(u8 *self) {
    vu0_v4 position, direction;
    u8 *p = *(u8 **)(self + 0x68);
    f32 angle;

    if (func_U_003AED30(self)) {
        func_U_00436AE0(self);
        return;
    }
    switch (self[0x20]) {
    case 1:
        if (func_U_00453488(self) && self[0x43] != 0)
            func_U_004421E8(self, 0, 0, 10);
        if (*(s32 *)(p + 0x80) != -1 ? func_U_004537B0(D_001A4C60, *(s32 *)(p + 0x80))
                                     : func_U_0040C8F8(self + 0x10, D_001A4C60) < *(f32 *)(p + 0x84))
            func_U_00442528(self, 2, -1);
        break;
    case 2:
        if (func_U_00453488(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_U_004A60E0)(3, 4, self);
            if (self[0x43] != 1)
                func_U_004421E8(self, 1, 0, 0);
        }
        if (self[0x60] & 2) {
            release_003AFD10(self, p);
            func_U_00442528(self, 4, -1);
        }
        break;
    case 3:
        if (func_U_00453488(self) && self[0x43] != 2)
            func_U_004421E8(self, 2, 0, 0);
        if (func_U_0040D8C0(*(f32 *)(self + 0xF8), *(f32 *)(p + 0x90)) <= 0.017453292f)
            func_U_00442528(self, 7, -1);
        else
            ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_U_004460C8)(self + 0xF8, p + 0x94, *(f32 *)(p + 0x90), 0.0027777778f, 0.0027777778f, 0.5f, 0);
        break;
    case 4:
        if (func_U_00453488(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_U_004A60E0)(0, 4, self);
            if (self[0x43] != 2)
                func_U_004421E8(self, 2, 0, 0);
            *(s32 *)(p + 0xA0) = 60;
        }
        angle = func_U_0040D820(func_U_0040CDA0(D_001A4BE0_003AFD10.x - *(f32 *)(self + 0x10),
                                            D_001A4BE0_003AFD10.y - *(f32 *)(self + 0x14)),
                              *(f32 *)(p + 0x90));
        if (angle > 0.7853982f)
            angle = 0.7853982f;
        else if (angle < -0.7853982f)
            angle = -0.7853982f;
        angle = func_U_0040D7D8(*(f32 *)(p + 0x90), angle);
        ((void (*)(void *, void *, f32, f32, f32, f32, s32))func_U_004460C8)(self + 0xF8, p + 0x94, angle, 0.0027777778f, 0.0027777778f, 0.5f, 0);
        func_U_003AEEB8(self);
        func_U_00403C00(func_U_003AEDE0, self);
        if (func_U_0040C3A0(p + 0xA0)) {
            release_003AFD10(self, p);
            func_U_00442528(self, 5, -1);
        } else {
            angle = func_U_0040D8C0(func_U_0040CDA0(D_001A4BE0_003AFD10.x - *(f32 *)(self + 0x10),
                                                D_001A4BE0_003AFD10.y - *(f32 *)(self + 0x14)),
                                  *(f32 *)(p + 0x90));
            if (angle > 1.5707964f || *(s32 *)(p + 0x88) != -1) {
                if (func_U_004537B0(&D_001A4BE0_003AFD10.x, *(s32 *)(p + 0x88)))
                    break;
            } else if (!(func_U_0040C8F8(self + 0x10, &D_001A4BE0_003AFD10.x) > *(f32 *)(p + 0x8C))) {
                break;
            }
            release_003AFD10(self, p);
            func_U_00442528(self, 3, -1);
        }
        break;
    case 5:
        if (func_U_00453488(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_U_004A60E0)(1, 4, self);
            if (self[0x43] != 3)
                func_U_004421E8(self, 3, 0, 0);
            *(s32 *)(p + 0xA0) = 60;
            func_U_0040CA00(&direction, self + 0xC0, 0.8333334f);
            func_U_00437F58(self, 1, &position);
            func_U_003A13D8(self, &direction, &position, 1, (f32)p[0x44]);
        }
        if (func_U_0040C3A0(p + 0xA0)) {
            release_003AFD10(self, p);
            func_U_00442528(self, 4, -1);
        }
        break;
    case 6:
        if (func_U_00453488(self)) {
            p[0xA8] = 1;
            if (self[0x43] != 4)
                func_U_004421E8(self, 4, 0, 0);
        }
        if (self[0x60] & 2)
            func_U_00442528(self, 7, -1);
        break;
    case 7:
        if (func_U_00453488(self)) {
            s32 index = *(s32 *)(p + 0x7C);
            u8 *slot;
            if (index == -1 || (slot = D_001A30B0 + index * 128, *(u8 **)(slot + 0xDC) != self) || !slot[0xD0])
                *(s32 *)(p + 0x7C) = ((s32 (*)(s32, s32, void *))func_U_004A60E0)(3, 4, self);
            if (self[0x43] != 0)
                func_U_004421E8(self, 0, 0, 10);
            *(s32 *)(p + 0xA0) = 10;
        }
        if (p[0xA8])
            func_U_003AF0D0(self);
        if (func_U_0040C3A0(p + 0xA0)) {
            release_003AFD10(self, p);
        }
        break;
    }
}
/* localdecomp:end func_U_L07_003AE498 */
