/* NTSC-U draft (Claude wave C4): C of func_L07_003B87F8, the NTSC-U twin of func_L07_003BA0E8, with NTSC-U names and addresses (the two versions' code differs).
 * flags: byte-exact on NTSC-U only with "-O2 -G8 -fopt-stack -mno-check-zero-division" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L07_003B87F8", whose code is not the PAL one).
 * Worker's note: flags: needs @ps2as (the 0.08f constant is lui/ori/mtc1; the PAL file's flag line has no @ps2as); 15 aligned words differ with @ps2as: only the 3 bit-test sequences '(D_001A8018[0] & (1 << D_001D545C))' have hi/value registers a0/v1 vs retail's v1/a0 (retail ...
 */
#include "common.h"

typedef struct {
    s32 w00[8];
    s32 w20[8];
    s32 w40[2];
    s32 w48;
    u8 pad4C[0x90 - 0x4C];
    s32 w90;
    u8 pad94[0x9C - 0x94];
    f32 f9C;
    s16 hA0;
    u8 padA2[0xAE - 0xA2];
    u8 bAE;
    u8 bAF;
    u8 bB0;
    u8 padB1[0xBC - 0xB1];
    s32 wBC;
} Priv_003B87F8;

/* localdecomp:start func_L07_003B87F8 */
extern u8 *D_001DE548_sda;
__asm__(".extern D_001DE548_sda, 4");
extern f32 D_L07_001DED50;
extern s32 D_L07_001F2140[];
extern s32 D_001D545C;
extern s32 D_001A8018[];
extern u16 D_001A7D00[];
extern u8 D_001A4C60[];
extern u16 D_001A7DA8[];
extern s32 D_001A8060[];
extern s32 D_001D4C38;
extern s32 D_L07_001D7B20;
extern s32 D_L07_001DF518;
extern f32 D_L07_001E0540;
extern s32 D_001A7430[];
extern s32 D_001A7F4C[];
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_004FC518(s32, s32);
extern void func_L01_0045BE58(s32, s32);
extern void func_L01_00475A28(void);
extern void func_L01_00477BD0(void);
extern void func_L01_00478140(void);
extern s32 func_L01_00452EC8(void *);
extern void func_0039FE80(s32, s32, void *);
extern void func_L07_003B9A70(void *);
extern void func_L07_003B9B20(void *);
extern void func_L01_00417F60(s32, s32);
extern s32 func_L01_0050FF18(void);
extern s32 func_0037E0F0(void *, s32, s32);
extern s32 func_0037E1D8(s32);
extern void func_L07_003A0BC0(s32, void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_L07_003B9080(void *);

void func_L07_003B87F8(u8 *obj) {
    Priv_003B87F8 *p;
    s32 i;
    s32 bit;
    s32 val;
    f32 f;

    p = *(Priv_003B87F8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0:
        D_001DE548_sda = obj;
        obj[0x30] = 0xFF;
        p->bAE = 0xFF;
        p->bAF = 0;
        *(u16 *)(obj + 0x34) |= 1;
        func_L01_00441FB8(obj, 1, -1);
        break;
    case 1:
        break;
    case 2:
        if (D_L07_001DED50 <= 0.0f) {
            D_L07_001DED50 = 0.0f;
            func_L01_004FC518(0, 1);
            p->bB0 = 1;
            func_L01_0045BE58(p->w90, -1);
            func_L01_00475A28();
            func_L01_00477BD0();
            func_L01_00478140();
            func_L01_00441FB8(obj, 3, -1);
        } else {
            D_L07_001DED50 = D_L07_001DED50 - 0.08f;
        }
        break;
    case 3:
        if (D_L07_001F2140[0] == 0) {
            if (func_L01_00452EC8(obj) != 0) {
                func_0039FE80(0, 4, obj);
                func_0039FE80(1, 4, obj);
            }
        }
        func_L07_003B9A70(obj);
        func_L07_003B9B20(obj);
        *(u16 *)(obj + 0x96) += 1;
        if (*(u16 *)(obj + 0x96) >= 0x385) {
            val = D_001A8018[0];
            bit = 1 << D_001D545C;
            if (!(val & bit) && D_001A7D00[0] == 0) {
                func_L01_00417F60(0xB87, 0x2A);
            }
        }
        if (func_L01_0050FF18() == 0) {
            if (func_0037E0F0(D_001A4C60, p->w48, 0) != 0) {
                if (D_001A7DA8[0] == 0) {
                    val = D_001A8060[0];
                    bit = 1 << D_001D545C;
                    if (!(val & bit)) {
                        func_L01_00417F60(0xB8D, 0x30);
                    }
                }
            }
        }
        D_L07_001D7B20 = p->bAE + 0x21;
        D_L07_001DF518 = D_001D4C38;
        for (i = 0; i < 8; i++) {
            if (p->w00[i] == -1) {
                continue;
            }
            if (p->w20[i] == -1) {
                continue;
            }
            if (func_0037E0F0(D_001A4C60, p->w00[i], 0) != 0) {
                p->bAF = p->bAF | (1 << i);
            } else {
                p->bAF = p->bAF & ~(1 << i);
            }
        }
        if (p->bB0 == 1) {
            f = (f32)D_001A7430[0] + D_L07_001E0540;
            if (p->f9C < f) {
                p->f9C = f;
            } else if (f < p->f9C) {
                p->bB0 = 0;
            }
        }
        if (func_L01_0050FF18() == 0) {
            if (p->wBC != -1) {
                if (func_0037E0F0(D_001A4C60, p->wBC, 0) != 0) {
                    val = D_001A7F4C[0];
                    bit = 1 << D_001D545C;
                    if (!(val & bit)) {
                        func_L01_00417F60(0xB76, 0x19);
                    }
                }
            }
        }
        if (p->hA0 & 0x8080) {
            switch (func_0037E1D8(4)) {
            case 0:
                func_L07_003A0BC0(0x4F, obj, 0, 0x78);
                break;
            case 1:
                func_L07_003A0BC0(0x50, obj, 0, 0x78);
                break;
            default:
                func_L07_003A0BC0((u8)func_0037E208(0x67, 0x69), obj, 0, 0x78);
                break;
            }
            func_L07_003B9080(obj);
        }
        break;
    }
}
/* localdecomp:end func_L07_003B87F8 */
