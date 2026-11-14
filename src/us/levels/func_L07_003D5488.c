#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003D5488 */
extern u8 D_001A4BE0[];
extern s32 D_001D545C_sda_003D5488;
__asm__(".extern D_001D545C_sda_003D5488, 4");
extern f32 D_001DA9B8_sda;
__asm__(".extern D_001DA9B8_sda, 4");
extern u8 D_0014275B[];
extern f32 D_L07_002F35F0[];
extern u8 D_L07_003D5A68[];
extern u8 D_L07_001D66B0[8];

extern void func_L07_003D5790(u8 *);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L01_00402498(void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_L07_003D5960(u8 *, void *, s32);
extern void func_L03_003A06C8(void *);
extern f32 func_L01_0040C040(void *, void *);
extern s32 func_L01_00417EA0(void);
extern void func_L01_00443938(s32, u8 *, s32, void *, void *, f32);
extern void func_L01_004A6D70(s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003BE6A8(f32, f32, f32);
extern void func_003C26C8(void *);

void func_L07_003D5488(u8 *self) {
    u8 *st;
    f32 buf[4];

    func_L07_003D5790(self);
    st = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 0:
        break;
    case 1:
        if (st[8] == 2) {
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 2:
        if (func_L01_00452EC8(self) != 0) {
            func_0039FE80(1, 4, self);
        }
        if (self[0x31] != 0) {
            func_L01_00402498(D_L07_003D5A68, self);
            if (func_0037E1D8(10) == 0) {
                func_L07_003D5960(self, buf, func_0037E1D8(12));
                func_L03_003A06C8(buf);
            }
        }
        if (func_L01_0040C040(self + 0x10, D_001A4BE0 + 0x80) < 9.0f) {
            u8 *hero = D_001A4BE0;
            if (fabs_asm(*(f32 *)(self + 0x18) - *(f32 *)(hero + 0x88)) < 0.75f) {
                f32 t;
                if (func_L01_00417EA0() != 0) {
                    if (D_001D545C_sda_003D5488 == 7 && D_0014275B[0] != 0) {
                        t = D_001DA9B8_sda;
                    } else {
                        t = D_L07_002F35F0[D_001D545C_sda_003D5488];
                    }
                } else {
                    t = 1.0f;
                }
                func_L01_00443938(*(s32 *)(hero + 0x25C0), self, 1, D_L07_001D66B0, D_L07_001D66B0, t);
            }
        }
        if (st[8] == 1) {
            func_L01_004A6D70(1, self);
            func_L01_00441FB8(self, 5, -1);
        }
        break;
    case 4:
        if (func_L01_00452EC8(self) != 0) {
            func_0039FE80(0, 4, self);
        }
        {
            f32 v;
            *(f32 *)(st + 0x14) += 0.01f;
            if (*(f32 *)(st + 0x14) >= 1.0f) {
                *(f32 *)(st + 0x14) = 1.0f;
                func_L01_004A6D70(0, self);
                func_L01_00441FB8(self, 2, -1);
            }
            v = func_003BE6A8(3.1415927f, 0.0f, *(f32 *)(st + 0x14));
            *(f32 *)(self + 0xF0) = v;
            *(f32 *)(*(u8 **)(st + 0x10) + 0xF0) = v;
            func_003C26C8(*(void **)(st + 0x10));
        }
        break;
    case 5:
        if (func_L01_00452EC8(self) != 0) {
            func_0039FE80(0, 4, self);
        }
        {
            f32 v;
            *(f32 *)(st + 0x14) -= 0.01f;
            if (*(f32 *)(st + 0x14) <= 0.0f) {
                *(f32 *)(st + 0x14) = 0.0f;
                func_L01_004A6D70(0, self);
                func_L01_00441FB8(self, 1, -1);
            }
            v = func_003BE6A8(3.1415927f, 0.0f, *(f32 *)(st + 0x14));
            *(f32 *)(self + 0xF0) = v;
            *(f32 *)(*(u8 **)(st + 0x10) + 0xF0) = v;
            func_003C26C8(*(void **)(st + 0x10));
        }
        break;
    }
}
/* localdecomp:end func_L07_003D5488 */
