#include "common.h"

/* NTSC-U counterpart of func_L39_00588CE0 (src/levels/shared/L39_00588CE0.c) */
/* localdecomp:start func_L39_00587B70 */
typedef struct { u8 pad[4]; s16 h4; } S0_00588CE0;
typedef struct { u8 pad[0x450]; s32 f450; u8 pad2[0xC]; } S1_00588CE0;
extern S0_00588CE0 *D_L39_0024CA20;
__asm__(".extern D_L39_0024CA20, 16");
extern s32 D_L39_0024BAC4;
__asm__(".extern D_L39_0024BAC4, 16");
extern s32 D_L39_0024BC58;
__asm__(".extern D_L39_0024BC58, 16");
extern s32 D_L39_00245D30;
__asm__(".extern D_L39_00245D30, 16");
extern s32 D_L39_00245D34;
__asm__(".extern D_L39_00245D34, 16");
extern s32 D_L39_0024BB10;
__asm__(".extern D_L39_0024BB10, 16");
extern s32 D_L39_0024BB14;
__asm__(".extern D_L39_0024BB14, 16");
extern u8 D_L39_002426A0;
__asm__(".extern D_L39_002426A0, 4");
extern s32 D_L39_002412A8;
__asm__(".extern D_L39_002412A8, 16");
extern s32 D_L39_0024BB08;
__asm__(".extern D_L39_0024BB08, 16");
extern s32 D_L39_0024BB0C;
__asm__(".extern D_L39_0024BB0C, 16");
extern s32 D_L39_0024BB38;
__asm__(".extern D_L39_0024BB38, 16");
extern s32 D_L39_00245D4C;
__asm__(".extern D_L39_00245D4C, 16");
extern s32 D_L39_00245D50;
__asm__(".extern D_L39_00245D50, 16");
typedef struct { void *f0; void *f4; void *f8; u8 padC[0xC]; s32 f18; } S2_00588CE0;
extern S2_00588CE0 D_L39_0024BE00 __attribute__((section(".sdata")));
extern s32 D_L39_00241298_00587B70;
__asm__(".extern D_L39_00241298_00587B70, 16");
extern S1_00588CE0 D_L39_0024DF80[];
extern u8 D_L39_00245040;
__asm__(".extern D_L39_00245040, 16");
extern u8 D_L39_00245041;
__asm__(".extern D_L39_00245041, 16");
extern u8 D_L39_00245042;
__asm__(".extern D_L39_00245042, 16");
extern u8 D_L39_00245043;
__asm__(".extern D_L39_00245043, 16");
extern f32 D_L39_0024BAD0;
__asm__(".extern D_L39_0024BAD0, 16");
extern f32 D_L39_0024BAD8_00587B70[] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024BAD8_00587B70, 16");
extern s32 D_L39_00242A94;
__asm__(".extern D_L39_00242A94, 4");
extern u8 D_L39_00242624;
__asm__(".extern D_L39_00242624, 4");
extern s32 D_L39_00242688;
__asm__(".extern D_L39_00242688, 4");
extern u8 D_00100AE0[];
extern s32 D_001A5990[];
extern f32 D_L39_0024BC4C;
__asm__(".extern D_L39_0024BC4C, 16");
extern int D_L39_002BA140[];
extern char D_L39_002B86A0[];
extern u64 D_L39_0025D960[];
extern u64 D_L39_0049A920[];
extern s32 D_L39_0024BC90;
__asm__(".extern D_L39_0024BC90, 16");

extern void func_0038DB18(s32);
extern void func_00381F18(void);
extern void func_003BD8A0(void);
extern void func_00382F40(void);
extern void func_L39_00586D40(void);
extern void func_L39_0058BC80(void);
extern void func_L39_005F1EF8(void);
extern void func_003A4720(s32);
extern void func_L39_005F3A08(void);
extern void func_L01_004C2280(void);
extern void func_L39_005883C8(s32);
extern void func_L01_004025B0(void);
extern void func_00384C98(void);
extern void func_L01_004C2220(void);
extern void func_L39_005EB8B8(void);
extern void func_L39_00589F08(u8 *);
extern void func_L01_00402628(void);
extern void func_L39_00587458(void);
extern void func_003BE340(void);
extern void func_L01_004024E8(void);
extern void func_003A3EF0(s32, unsigned long);
extern void func_00380D48(void);
extern void func_00385980(void);
extern void func_001264E0(s32);
extern void func_003C7E68(void);
extern void func_L01_004026F0(void);
extern void func_003D3050(s32);
extern void func_003D30D0(void);
extern void func_003D3CF0(s32);
extern void func_00385908(void);
extern void func_L39_0057B530(s32);
extern void func_L01_004130D8(void);
extern s32 func_0039BEA8(s32);
extern void func_L39_00589B10(void);
extern void func_L01_0042D280(s32);
extern void func_L39_005A7250(void);
extern void func_00391FD8(void);
extern void func_L39_0061A940(void);
extern void func_L01_00475248(void);
extern void func_003ADBB0(s32);
extern void func_L01_00475280(void);
extern void func_L39_0059A090(void);
extern void func_L39_00589740(void);
extern void func_L39_00589FE8(s32, s32, s32, s32);
extern void func_00386488(void);
extern void func_003A3A40(void *);
extern void func_003A3DA0(s32);
extern void func_003CAC10(void *);
extern void func_003C9AE0(void);
extern void func_003D8218(void);
extern void func_003D46E0(void);
extern void func_003DB5C0(void *);
extern void func_003D98D0(void);
extern void func_003BDC90(void);
extern void func_003821E8(s32);

/* true when bit 0 of a flags byte is clear */
static __inline__ s32 flagOff_00588CE0(u8 flags) { return !(flags & 1); }
void func_L39_00587B70(s32 a0) {
    s32 t;
    f32 d;

    if (D_L39_0024CA20 == 0 || D_L39_0024CA20->h4 != 0 || flagOff_00588CE0(D_L39_0024BAC4)) {
        func_0038DB18(0);
    }
    func_00381F18();
    func_003BD8A0();
    func_00382F40();
    func_L39_00586D40();
    D_L39_0024BC58 = -1;
    D_L39_00245D30 = 0;
    D_L39_00245D34 = 0;
    if (D_L39_0024CA20 != 0 && (D_L39_0024BAC4 & 1)) {
        func_L39_0058BC80();
    }
    if ((D_L39_0024BAC4 & 2)) {
        func_L39_005F1EF8();
    }
    func_003A4720(0x2010000);
    if ((D_L39_0024BAC4 & 4)) {
        func_L39_005F3A08();
    }
    func_003A4720(0x2020000);
    if ((D_L39_0024BAC4 & 0x20) && D_L39_0024BB10) {
        func_L01_004C2280();
        func_L39_005883C8(1);
        func_L01_004025B0();
        func_00384C98();
        func_L01_004C2220();
    }
    if ((D_L39_0024BAC4 & 8)) {
        func_L39_005EB8B8();
    }
    func_003A4720(0x2040000);
    if (D_L39_002426A0) {
        func_L39_00589F08(&D_L39_002426A0);
    }
    if ((D_L39_0024BAC4 & 0x20) && D_L39_0024BB14) {
        func_L01_004C2280();
        func_L39_005883C8(1);
        func_L01_00402628();
        func_00384C98();
        func_L01_004C2220();
    }
    if ((D_L39_0024BAC4 & 0x10)) {
        if (D_L39_002412A8 == 2) {
            func_L39_00587458();
        } else {
            func_003BE340();
        }
    }
    func_003A4720(0x2080000);
    func_L39_005883C8(0);
    if ((D_L39_0024BAC4 & 0x20)) {
        func_L01_004C2280();
        if (D_L39_0024BB08) {
            func_L01_004024E8();
        }
        func_003A3EF0(0x42, 0x8000000048UL);
        func_00380D48();
        func_L01_004C2280();
        func_00385980();
        func_003A3EF0(8, 5);
        func_L01_004C2280();
        func_003A3EF0(0x47, 0x53001);
        func_001264E0(0);
        func_003C7E68();
        D_L39_0024BC58 = 9;
        func_003A3EF0(0x47, 0x5360B);
        if (D_L39_0024BB0C) {
            func_L01_004C2280();
            func_L01_004026F0();
        }
        func_00384C98();
        if (D_L39_00245D30) {
            func_003D3050(0);
            if (D_L39_00245D30) {
                func_003D30D0();
            }
        }
        if (D_L39_00245D4C) {
            func_003D3CF0(0);
        }
        D_L39_00245D50 = D_L39_00245D4C;
        D_L39_00245D4C = 0;
        func_L39_005883C8(0);
        if (D_L39_0024BB38) {
            func_L01_004C2280();
            func_00385908();
        }
        func_003A3EF0(0x42, 0x8000000044UL);
        func_L39_0057B530(a0);
        func_00384C98();
    }
    func_L01_004130D8();
    func_L39_005883C8(0);
    func_L01_004C2280();
    if ((D_L39_0024BAC4 & 0x180) && func_0039BEA8(3) == 0) {
        func_003A3EF0(0x47, 0x33001);
        func_L39_00589B10();
        if ((D_L39_0024BAC4 & 0x80)) {
            func_L01_0042D280(0);
            func_L39_005A7250();
            t = D_L39_0024BE00.f18;
            func_00391FD8();
            D_L39_0024BE00.f18 = t;
            func_L39_0061A940();
            func_L01_00475248();
            func_003ADBB0(D_L39_00241298_00587B70);
            func_L01_00475280();
            func_L39_0059A090();
        }
    }
    if (D_L39_002412A8 == 2) {
        func_L39_00589740();
    }
    func_00384C98();
    if ((D_L39_0024BAC4 & 0x40)) {
        func_003A3EF0(0x42, 0x8000000044UL);
        if ((D_L39_0024DF80 + a0)->f450) {
            func_L39_00589FE8(D_L39_00245040, D_L39_00245041, D_L39_00245042, D_L39_00245043);
        }
        if (D_L39_0024BAD0 > 0.0f && D_L39_00242A94 == 0) {
            if (D_L39_0024BAD0 > 1.0f) {
                D_L39_0024BAD0 = 1.0f;
            }
            func_L39_00589FE8(0, 0, 0, D_L39_0024BAD0 * 128.0f);
        }
        if (D_L39_0024BAD8_00587B70[0] > 0.0f && D_L39_00242A94 == 0) {
            if (D_L39_0024BAD8_00587B70[0] > 1.0f) {
                D_L39_0024BAD8_00587B70[0] = 1.0f;
            }
            func_L39_00589FE8(0xFF, 0xFF, 0xFF, D_L39_0024BAD8_00587B70[a0] * 128.0f);
        }
        if (D_L39_00242624 && D_L39_00242688) {
            func_00386488();
        }
    }
    func_003A3A40(D_00100AE0);
    func_001264E0(0);
    d = (f32)*(volatile u32 *)0x10000800;
    D_L39_0024BC4C = d / (D_001A5990[0] ? 11520.0f : 9600.0f);
    func_003A3DA0(2);
    if ((D_L39_0024BAC4 & 2)) {
        func_003CAC10(D_L39_002BA140);
        func_003C9AE0();
    }
    func_003A3DA0(4);
    if ((D_L39_0024BAC4 & 4)) {
        D_L39_0049A920[0] = D_L39_0025D960[0];
        D_L39_0049A920[1] = D_L39_0025D960[-1];
        D_L39_0049A920[2] = D_L39_0025D960[2];
        func_003D8218();
        func_003D46E0();
    }
    func_003A3DA0(8);
    if ((D_L39_0024BAC4 & 8)) {
        func_003DB5C0(D_L39_002B86A0);
        func_003D98D0();
    }
    func_003A3DA0(0x10);
    if ((D_L39_0024BAC4 & 0x10)) {
        func_003BDC90();
    }
    func_003821E8(a0);
    D_L39_0024BC90 = 0;
}
/* localdecomp:end func_L39_00587B70 */
