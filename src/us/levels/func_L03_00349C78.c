#include "common.h"

/* NTSC-U counterpart of func_L03_0034A7D8 (src/levels/03_starship_phoenix/L03_00349C00.c) */
/* localdecomp:start func_L03_00349C78 */
typedef int s128 __attribute__((mode(TI)));
typedef struct { u8 b[0x80]; } Snd80_00349C78;

extern Snd80_00349C78 D_001A30B0[];
extern f32 D_001DD660_sda;
extern f32 D_001DD664_sda;
__asm__(".extern D_001DD660_sda, 4");
__asm__(".extern D_001DD664_sda, 4");
extern void func_L03_00349C00(void *);
extern void func_003C1130(void *, void *, s32, s32, void *, s32, s32, s32, void *, void *, s32);
extern void func_003C1440(void *, void *, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8(void *);
extern f32 func_L01_00436500(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_0039FB08(s32);

void func_L03_00349C78(u8 *self) {
    u8 *s = *(u8 **)(self + 0x68);
    Snd80_00349C78 *e;
    s32 id;
    u16 h;

    func_L03_00349C00(self);
    switch (self[0x20]) {
    case 0:
        *(f32 *)(s + 0x158) = *(f32 *)(self + 0x18);
        func_003C1130(self, s + 0x70, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(s128 *)(s + 0x70) = *(s128 *)(self + 0x10);
        *(f32 *)(s + 0x78) = *(f32 *)(s + 0x78) + D_001DD660_sda;
        if (self[0x43] != 0) {
            func_003BE4F0(self, 0, 0, 0xA);
        }
        func_L01_00441FB8(self, 4, -1);
        break;
    case 1:
        *(f32 *)(s + 0x78) = *(f32 *)(s + 0x78) + ((*(f32 *)(s + 0x158) + D_001DD660_sda) - *(f32 *)(s + 0x78)) * D_001DD664_sda;
        if (self[0xBC] != 0) {
            if (self[0x43] != 1) {
                func_003BE4F0(self, 1, 0, 0xA);
            }
            func_L01_00441FB8(self, 2, -1);
        }
        break;
    case 2:
        *(f32 *)(s + 0x78) = *(f32 *)(s + 0x78) + (*(f32 *)(s + 0x158) - *(f32 *)(s + 0x78)) * D_001DD664_sda;
        if (func_L01_00452EC8(self) != 0) {
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
            *(s32 *)(s + 0x14C) = func_0039FE80(0, 4, self);
        }
        if (self[0x60] & 2) {
            if (self[0x43] != 2) {
                func_003BE4F0(self, 2, 0, 0xA);
            }
            func_L01_00441FB8(self, 3, -1);
        }
        break;
    case 3:
        *(f32 *)(s + 0x78) = *(f32 *)(s + 0x78) + (*(f32 *)(s + 0x158) - *(f32 *)(s + 0x78)) * D_001DD664_sda;
        if (func_L01_00452EC8(self) != 0) {
            *(s32 *)(s + 0x148) = 0xF0;
        }
        h = *(u16 *)(self + 0x96);
        *(u16 *)(self + 0x96) = h + 1;
        if ((*(f32 *)(s + 0x150) + *(f32 *)(s + 0x154)) * 60.0f < (f32)h) {
            if (self[0x43] != 3) {
                func_003BE4F0(self, 3, 0, 0xA);
            }
            func_L01_00441FB8(self, 4, -1);
        }
        break;
    case 4:
        *(f32 *)(s + 0x78) = *(f32 *)(s + 0x78) + ((*(f32 *)(s + 0x158) + D_001DD660_sda) - *(f32 *)(s + 0x78)) * D_001DD664_sda;
        if (self[0x42] == 3) {
            if (func_L01_00436500(self) > 5.0f) {
                *(s32 *)(self + 0x98) = 0;
            }
        }
        if (self[0x60] & 2) {
            if (self[0x43] != 0) {
                func_003BE4F0(self, 0, 0, 0xA);
            }
            self[0xBC] = 0;
            *(s32 *)(self + 0x98) = 0;
            func_L01_00441FB8(self, 1, -1);
            id = *(s32 *)(s + 0x14C);
            if (id != -1) {
                e = &D_001A30B0[id];
                if (*(u8 **)&e->b[0xDC] == self && e->b[0xD0] != 0) {
                    func_0039FB08(id);
                }
            }
            *(s32 *)(s + 0x14C) = -1;
        }
        break;
    }
    func_003C1440(self, s + 0x70, 0);
}
/* localdecomp:end func_L03_00349C78 */
