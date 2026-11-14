#include "common.h"

typedef struct {
    u8 pad[0x2850];
    s32 w2850;
} Hero2850;

/* localdecomp:start func_L20_003D61B8 */
/* PAL port of the NTSC-U match src/us/levels/func_L20_003D4708.c */
#include "vu0.h"


extern s32 func_L20_003D65D0(void *);
extern s32 func_L02_003A02D8(void *, s32);
extern void func_L20_003D5FF0(void *);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L02_0034FD58(void *);
extern void func_003C4A40(void *, void *);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L02_003FB148(s32, s32, f32);
extern Hero2850 D_1A4BE0;
extern u8 *D_L20_001E02A8;
__asm__(".extern D_L20_001E02A8, 16");
extern s32 D_L20_001E2698;
__asm__(".extern D_L20_001E2698, 16");
extern s32 D_L20_001D67A8;
__asm__(".extern D_L20_001D67A8, 16");
extern s32 D_L20_001DEBEC;
extern u8 D_L20_001DEBB0;
extern u8 D_L20_001DEBB4;
extern u8 D_L20_001DEBB8;

s32 func_L20_003D61B8(u8 *obj) {
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *o;
    s32 saved;

    if (obj[0x20] == 0) {
        if (func_L20_003D65D0(obj) != 0) {
            return 1;
        }
    }
    if (700.0f <= fabs_asm(*(f32 *)(p + 0x30) - (f32)*(s32 *)(p + 0x650))) {
        for (o = D_L20_001E02A8; o != 0; o = *(u8 **)(o + 0x28)) {
            if (*(s16 *)(o + 0xAA) == 0x1941) {
                func_L02_003A02D8(o, 0);
            }
        }
        *(s32 *)(p + 0x650) = (s32)*(f32 *)(p + 0x30);
    }
    if (*(f32 *)(p + 0x30) < (f32)*(s32 *)(p + 0x620)) {
        if (*(s32 *)(p + 0x5CC) < 2) {
            D_L20_001DEBEC = 1;
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
    func_L20_003D5FF0(obj);
    saved = (s32)*(f32 *)(p + 0x30);
    if (func_L01_00452FB0(obj, p + 0x160, 0, 0, 0) != 0) {
        if (*(s32 *)(p + 0x664) == 0) {
            *(s32 *)(p + 0x664) = 100;
            func_003A52A0(7, 0, obj);
        }
        func_L02_0034FD58(obj);
    }
    if (*(f32 *)(p + 0x30) < (f32)saved) {
        p[0x167] = D_L20_001DEBB0;
        p[0x168] = D_L20_001DEBB4;
        p[0x169] = D_L20_001DEBB8;
        func_003C4A40(obj, p + 0x160);
    }
    if (D_L20_001E2698 == D_L20_001D67A8 && D_1A4BE0.w2850 <= 0) {
        D_L20_001D67A8 = D_L20_001E2698 + 1;
    }
    if (D_1A4BE0.w2850 <= 0) {
        if (obj[0x95] != 4 && obj[0x20] != 5 && obj[0x20] != 6) {
            if (func_00382468(2) != 0) {
                if (obj[0x43] != 3) {
                    func_003C3A10(obj, 3, 0, 6);
                }
            } else {
                if (obj[0x43] != 4) {
                    func_003C3A10(obj, 4, 0, 6);
                }
            }
            func_L01_004450F0(obj, 0x1F, 4);
        }
    }
    if (p[0x5F] != 0) {
        func_L01_00456BD0(obj, 5);
        if (obj[0x95] == 0) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 3, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    } else {
        func_L01_00456BD0(obj, 3);
        if (obj[0x95] == 0) {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2C0), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2C4), 10.0f, 1.0f);
        } else {
            func_L01_00456C98(obj, *(s32 *)(p + 0x2C8), 0, 0, 0, 0, 1, 0, 0, 0, *(f32 *)(p + 0x2CC), 10.0f, 1.0f);
        }
    }
    func_L02_003FB148(5, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
    return 0;
}
/* localdecomp:end func_L20_003D61B8 */

INCLUDE_ASM("asm/levels", func_L20_003D65D0);

/* localdecomp:start func_L20_003D6AE0 */
extern s32 func_L01_0044E1B8(void *, f32);

s32 func_L20_003D6AE0(void *arg0) {
    if (func_L01_0044E1B8(arg0, 112.0f) || func_L01_0044E1B8(arg0, 120.0f) ||
        func_L01_0044E1B8(arg0, 128.0f) || func_L01_0044E1B8(arg0, 136.0f) ||
        func_L01_0044E1B8(arg0, 144.0f)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L20_003D6AE0 */

INCLUDE_ASM("asm/levels", func_L20_003D6B78);

INCLUDE_ASM("asm/levels", func_L20_003D6BF8);

INCLUDE_ASM("asm/levels", func_L20_003D6D18);
