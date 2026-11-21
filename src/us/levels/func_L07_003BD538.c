#include "common.h"

/* NTSC-U counterpart of func_L07_003BEE80 (src/levels/07_annihilation_nation/L07_003BEE80.c) */
/* localdecomp:start func_L07_003BD538 */
#include "vu0.h"

typedef struct {
    u8 pad_0[0x25C0];
    void *moby; /* 0x25C0 */
} S_003BEE80_HERO;

extern S_003BEE80_HERO D_001A4BE0;
extern void *D_L07_001ECC80_003BD538[];
extern vu0_v4 D_L07_001D9B20 __attribute__((section(".sdata")));

extern void func_L07_003BD9D0_003BD538(u8 *, u8 *);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_00452EC8(void *);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L07_003BDEE8(u8 *);
extern void func_L07_003BDA60(u8 *, u8 *, f32, void *);
extern s32 func_003883C8(void *);
extern void func_L07_003BD988(void *);
extern f32 func_00388800(void *, void *);
extern void func_L01_004A6D70(s32, void *);
extern void func_L07_003BDA20(void *);
extern void func_L07_003BDB38(void *);
extern void func_00388758(void *, void *, void *);
extern void func_00388830(void *, void *, f32);
extern s32 func_L01_00443648(void *, void *, s32, s32, f32, f32, f32, s32, s32);
extern s32 func_L07_003A0BC0(s32, s32, s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00452F40(void *, s32);

void func_L07_003BD538(u8 *obj) {
    vu0_v4 direction;
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *target;
    void **objects;
    s32 count;

    if (d[0xE]) return;
    func_L07_003BD9D0_003BD538(obj, *(u8 **)d);
    *(f32 *)(obj + 0xF4) = func_00389380(*(f32 *)(obj + 0xF4), 0.20943953f);
    switch (obj[0x20]) {
    case 1:
        if (func_L01_00452EC8(obj)) func_0039FE80(0, 4, obj);
        func_L07_003BDEE8(obj);
        func_L07_003BDA60(obj, *(u8 **)(d + 4), 0.0043633235f, 0);
        if (func_003883C8(d + 0xC)) {
            obj[0x20] = 2;
            *(s16 *)(d + 0xC) = 300;
            if (*(u8 **)d) func_L07_003BD988(*(u8 **)d);
        }
        break;
    case 2:
        if (func_003883C8(d + 0xC) || func_00388800(obj + 0x10, *(u8 **)(obj + 0xB8) + 0x10) > 100.0f) {
            func_L01_004A6D70(0, obj);
            func_L07_003BDA20(obj);
        } else {
            func_L07_003BDB38(obj);
            func_L07_003BDEE8(obj);
            *(f32 *)(d + 8) += 0.083333336f;
            if (*(f32 *)(d + 8) > 0.5f) *(f32 *)(d + 8) = 0.5f;
            func_00388758(&direction, &D_L07_001D9B20, obj + 0xD0);
            func_00388830(&direction, &direction, *(f32 *)(d + 8));
            vec_add_ba(obj + 0x10, obj + 0x10, &direction);
            func_L07_003BDA60(obj, *(u8 **)(d + 4), 0.017453294f, &direction);
            count = func_L01_00443648(obj, obj + 0x10, 1, 0, 1.0f, (f32)d[0xF], 1.0f, 1, 9);
            if (count > 0) {
                s32 remaining;
                objects = D_L07_001ECC80_003BD538;
                remaining = count;
                do {
                    if (*objects == D_001A4BE0.moby) {
                        func_0039FE80(1, 0, obj);
                        target = *(u8 **)(obj + 0xB8);
                        if (target && *(s16 *)(target + 0xAA) == 0x1A18) {
                            u8 *child = *(u8 **)(target + 0x68);
                            if (*(s16 *)(child + 0x66E) == 0) {
                                func_L07_003A0BC0(25, (s32)obj, 0, 120);
                                *(s16 *)(child + 0x66E) = func_0037E1D8(150) + 300;
                            }
                            func_L01_00452F40(*(u8 **)(obj + 0xB8), 1);
                        }
                    }
                    remaining--;
                    objects++;
                } while (remaining);
            }
        }
        break;
    }
}
/* localdecomp:end func_L07_003BD538 */
