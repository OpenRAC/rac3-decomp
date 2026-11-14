#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L20_003D4708 */
typedef struct {
    u8 pad[0x2850];
    s32 w2850;
} Hero2850;

extern s32 func_L20_003D4B20(void *);
extern s32 func_L02_0039E538(void *, s32);
extern void func_L20_003D4540(void *);
extern s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L02_0034ECF8(void *);
extern void func_003BF4F8(void *, void *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004538E0(void *, s32);
extern void func_L01_004539A8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_003F84F0(s32, s32, f32);
extern Hero2850 D_001A4BE0;
extern u8 *D_L20_001E02A8;
__asm__(".extern D_L20_001E02A8, 16");
extern s32 D_L20_001E2698;
__asm__(".extern D_L20_001E2698, 16");
extern s32 D_L20_001D67A8;
__asm__(".extern D_L20_001D67A8, 16");
extern s32 D_L20_001DEC2C;
extern u8 D_L20_001DEBF0_003D4708;
extern u8 D_L20_001DEBF4_003D4708;
extern u8 D_L20_001DEBF8;

s32 func_L20_003D4708(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *o;
    s32 saved;

    if (obj[0x20] == 0) {
        if (func_L20_003D4B20(obj) != 0) {
            return 1;
        }
    }
    if (700.0f <= fabs_asm(*(f32 *)(p + 0x30) - (f32)*(s32 *)(p + 0x650))) {
        for (o = D_L20_001E02A8; o != 0; o = *(u8 **)(o + 0x28)) {
            if (*(s16 *)(o + 0xAA) == 0x1941) {
                func_L02_0039E538(o, 0);
            }
        }
        *(s32 *)(p + 0x650) = (s32)*(f32 *)(p + 0x30);
    }
    if (*(f32 *)(p + 0x30) < (f32)*(s32 *)(p + 0x620)) {
        if (*(s32 *)(p + 0x5CC) < 2) {
            D_L20_001DEC2C = 1;
            *(s32 *)(p + 0x638) = 1;
            *(s32 *)(p + 0x5CC) = 2;
        }
    }
    if (*(f32 *)(p + 0x30) < (f32)*(s32 *)(p + 0x624)) {
        if (*(s32 *)(p + 0x5CC) != 3) {
            *(s32 *)(p + 0x5CC) = 3;
        }
    }
    if (*(f32 *)(p + 0x30) < (f32)*(s32 *)(p + 0x628)) {
        if (*(s32 *)(p + 0x5CC) != 4) {
            *(s32 *)(p + 0x5CC) = 4;
        }
    }
    func_L20_003D4540(obj);
    saved = (s32)*(f32 *)(p + 0x30);
    if (func_L01_0044FCD0(obj, p + 0x160, 0, 0, 0) != 0) {
        if (*(s32 *)(p + 0x664) == 0) {
            *(s32 *)(p + 0x664) = 0x78;
            func_0039FE80(7, 0, obj);
        }
        func_L02_0034ECF8(obj);
    }
    if (*(f32 *)(p + 0x30) < (f32)saved) {
        p[0x167] = D_L20_001DEBF0_003D4708;
        p[0x168] = D_L20_001DEBF4_003D4708;
        p[0x169] = D_L20_001DEBF8;
        func_003BF4F8(obj, p + 0x160);
    }
    if (D_L20_001E2698 == D_L20_001D67A8 && D_001A4BE0.w2850 <= 0) {
        D_L20_001D67A8 = D_L20_001E2698 + 1;
    }
    if (D_001A4BE0.w2850 <= 0) {
        if (obj[0x95] != 4 && obj[0x20] != 5 && obj[0x20] != 6) {
            if (func_0037E1D8(2) != 0) {
                if (obj[0x43] != 3) {
                    func_003BE4F0(obj, 3, 0, 7);
                }
            } else {
                if (obj[0x43] != 4) {
                    func_003BE4F0(obj, 4, 0, 7);
                }
            }
            func_L01_00441FB8(obj, 0x1F, 4);
        }
    }
    if (p[0x5F] != 0) {
        func_L01_004538E0(obj, 5);
        if (obj[0x95] == 0) {
            func_L01_004539A8(obj, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(obj, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_004538E0(obj, 3);
        if (obj[0x95] == 0) {
            func_L01_004539A8(obj, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_004539A8(obj, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    func_L02_003F84F0(5, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
    return 0;
}
/* localdecomp:end func_L20_003D4708 */
