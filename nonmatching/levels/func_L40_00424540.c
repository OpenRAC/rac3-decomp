/* PAL draft of func_L40_00424540 (wave 11 wp04, re-measured in wave 12 by r02): 235 diff with the file's own line
 * (-O2 -G8 -fopt-stack -mno-check-zero-division). It replaces the NTSC-U twin draft, which is not this function
 * (no count: 'not in object'). What differs is mostly the line: retail is Ps2EeAs output (@ps2as): inline li.s for
 * 0.3f/1.01f/1.075f/1.07f/0.05f (here .lit4 lwc1 off(gp)), and D_L40_0024112C/00249848/0024984C/00248380 loaded
 * and stored absolute (lui+lw/sw) except one store in a beql delay slot that is gp-relative; with the default
 * assembler they are all gp-relative (1 word instead of 2), so this object is about 27 words short and every
 * position after the prologue shifts. Unsized-array externs give the absolute form but gcc then CSEs the %hi
 * halves into saved registers (236). Also left (from wp04): the c ladder (retail: c in a2, set in the delay slots
 * of the taken branches; here c in v1 with fall-through blocks) and the switch (c) {1,2} tree (retail tests c==2,
 * c<3, c!=1). */
#include "common.h"

/* localdecomp:start func_L40_00424540 */
#include "vu0.h"

extern s32 D_L40_0024112C;
extern s32 D_L40_00249848;
extern s32 D_L40_0024984C;
extern s32 D_L40_00248380;
extern s32 D_001DC000_sda;
__asm__(".extern D_001DC000_sda, 4");
extern s32 D_001DC004_sda;
__asm__(".extern D_001DC004_sda, 4");

void func_L40_00424540(u8 *obj, s32 unused, u8 *src) {
    extern s32 func_L39_005F33E0(s32, s32, void *);
    extern u8 *func_L01_004653B8(void *, s32, s32, f32, f32, f32, f32, f32);
    extern f32 func_L01_00448248(s32 *, s32, s32);
    extern void func_L01_00451FE0(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 zero;
    s32 i;
    s32 n;
    s32 c;
    s32 mask;
    s32 d;
    s32 r;

    if (abs_asm(D_L40_0024112C - D_L40_00249848) >= 2) {
        r = func_L39_005F33E0(0, 0, obj);
        *(vu0_q *)&dir = 0;
        dir.z = 0.5f;
        func_L39_005F3718(r, &dir);
        D_L40_00249848 = D_L40_0024112C;
    }
    if (abs_asm(D_L40_0024112C - D_L40_0024984C) >= 2) {
        D_L40_0024984C = D_L40_0024112C;
    }
    *(vu0_q *)&pos = *(vu0_q *)(obj + 0x10);
    pos.z = pos.z + 0.3f;
    func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    for (i = 0; i < 5; i++) {
        func_L01_004653B8(&pos, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    }
    if (src != 0) {
        *(vu0_q *)&dir = *(vu0_q *)(src + 0x10);
    } else {
        qzero(&dir);
        dir.z = 1.0f;
    }
    d = abs_asm(D_L40_0024112C - D_001DC000_sda);
    if (d >= 0xC9) {
        D_001DC000_sda = D_L40_0024112C;
        D_001DC004_sda = 0;
    } else if (D_L40_0024112C != D_001DC000_sda) {
        func_L01_00448248(&D_001DC004_sda, 0, d >> 2);
        D_001DC000_sda = D_L40_0024112C;
    }
    n = D_L40_00248380;
    if (n >= 0xFB && D_001DC004_sda < 5) {
        c = 4;
    } else if (n >= 0xC9 && D_001DC004_sda < 10) {
        c = 3;
    } else if (n >= 0x97 && D_001DC004_sda < 15) {
        c = 2;
    } else if (n < 0x65) {
        c = 0;
    } else {
        c = D_001DC004_sda < 20;
    }
    if (c != 0) {
        mask = 0;
        D_001DC004_sda = D_001DC004_sda + c;
        switch (*(s16 *)(obj + 0xAA)) {
        case 0x1F5:
        case 0x200:
            mask = (1 << (c - 1)) - 1;
            if (!(mask < 0x10)) {
                mask = 0xF;
            }
            break;
        case 0x1FF:
        case 0x1ABA:
        case 0x1ABB:
        case 0x1ABC:
        case 0x1ABD:
        case 0x1ABE:
        case 0x1ABF:
        case 0x1AC0:
        case 0x1AC1:
        case 0x1AF2:
        case 0x1B09:
        case 0x1B0A:
        case 0x1B0B:
        case 0x1B4B:
            switch (c) {
            case 1:
                mask = 1;
                break;
            case 2:
                mask = 5;
                break;
            default:
                mask = 0x25;
                break;
            }
            break;
        }
        if (mask != 0) {
            qzero(&zero);
            func_L01_00451FE0(obj, mask, (u8 *)&zero, 0xFF, 0xB4, 0, 0, 0x23,
                              3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
        }
    }
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 1;
    func_L01_004450F0(obj, 3, -1);
    *(s32 *)(obj + 0x98) = 0;
    obj[0xBC] = 0xC;
}
/* localdecomp:end func_L40_00424540 */
