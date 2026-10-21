#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00381080);

/* localdecomp:start func_00381140 */
extern void func_00398128(s32, s32);

void func_00381140(void) {
    func_00398128(0, 0);
}
/* localdecomp:end func_00381140 */

/* localdecomp:start func_00381160 */
extern void func_003BBB68(s32);
extern void func_003B35E0(void *);
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern u8 D_001E22C0[];

void func_00381160(void) {
    func_003BBB68(1);
    func_003B35E0(D_001E22C0);
    func_003A12C0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_00381160 */

/* localdecomp:start func_003811A0 */
extern void func_003BBB68(s32);
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);

void func_003811A0(void) {
    func_003BBB68(1);
    func_003A12C0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811D8 */
s32 func_003811D8(void) {
}
/* localdecomp:end func_003811D8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003811E0);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003811E8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00381250);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031BF60);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031BF80);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031BFD0);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2740(s32, s32);
extern void * func_003AF470();
extern s32 D_001D5C78;
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227580;
extern s32 D_00227580_00381228[];
extern s32 D_001D5C78_00381228[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003F2740(s32, s32);
extern void * func_003AF470();
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_37D200;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227600_37D200;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_37D200;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_37D200;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_37D200;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_37D200;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_318CC0_37D200;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_37D200;
typedef struct { s32 a; s32 b; } E_37D200;
typedef struct { s32 off; s32 size; } H_37D200;
extern S_1A1ED0_37D200 D_001A1ED0;
extern S_227600_37D200 D_00227580_00381280;
extern S_1CCFD0_37D200 D_001CCFD0;
extern S_160C40_37D200 D_00160C40;
extern S_143950_37D200 D_00143950;
extern S_142430_37D200 D_00142430;
extern S_318CC0_37D200 D_0031CC80_00381280;
extern u8 D_001D5BDC;
extern s32 D_001D4BB0;
extern void *D_001D4B50;
extern s32 D_001A7430[];
extern s32 D_001D5B90;
extern s32 D_001D5B94;
extern s32 D_001D5B8C;
extern s32 D_001D9D08;
extern s32 D_001D9BC8;
extern s32 D_001D5B9C;
extern s32 D_001D9D2C;
extern u8 D_0031CCD0[];
extern void *D_001D99A0;
extern s32 D_001D5B74;
extern unsigned long D_001D4AC0;
extern s32 D_001D5750;
extern s32 D_001D574C;
extern E_37D200 D_001D5758[1];
extern s32 D_001D575C[2];
extern s32 D_001D5738[2];
extern void *D_001D52FC;
extern s32 D_001D5680;
extern s32 D_001D5684;
extern s32 D_001D5688;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern s32 D_00142BA4[];
extern s32 D_001D9D04;
extern f32 D_001D9D0C;
extern u8 D_001D5570[8];
extern s32 func_003A2998(s32, s32, s32);
extern void func_00392640(s32, long, long);
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_00388348(void);
extern s32 func_12C908(s32);
extern void func_00392670(void);
extern s32 func_003A2B50(s32);
extern void func_003A0B60(u8 *, u32);
extern void func_003A15F0(s32 a, s32 idx);
extern void func_00399230(void);
extern void func_003A1148(void);
extern void func_003A9588(void);
extern void func_003A9508(void);
extern void func_003927B0(void);
extern void func_00392B28(s32);
extern void func_003A3F70(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392F00();
extern s32 func_00393058();
extern void func_0038E530(s32);
extern void func_003B3408(void);
extern void func_003B3440();
extern void func_003A9BE8_00381280(u8 *, s32, s32, s32);
extern void func_0038B200(s32, s32, s32, s32);
extern void func_003BB468(void);
extern s32 func_003E88E0(s32 arg0, s32 *arg1);
extern s32 func_003E73A0();
extern s32 func_003E8868(s32 a);
extern void *func_003B5388();
extern void func_003E7398(void *);
extern s32 func_003E87F8(s32 arg0);
extern void func_003A97F8(s32, unsigned long);
extern void func_00389620(s32);
extern void func_003B34A0(void);
extern void func_003B3510(s32);
extern void func_003B34D8(void);
extern s32 func_003823D0(s32);
extern void func_0038EBC8_00381280(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389750(void);
extern void func_003A8EC8(void);
extern void func_003A2330();
extern void func_003B3CC8(void);
extern void func_0039C7F0(void);
extern void func_0039B1C0(void);
extern void func_003A96A8(s32);
extern void func_00388518(void);

/* localdecomp:start func_00381B98 */
s32 func_00381B98(void) {
    return 0;
}
/* localdecomp:end func_00381B98 */

/* localdecomp:start func_00381BA0 */
s32 func_00381BA0(void) {
}
/* localdecomp:end func_00381BA0 */

/* localdecomp:start func_00381BA8 */
s32 func_00381BA8(void) {
}
/* localdecomp:end func_00381BA8 */

/* localdecomp:start func_00381BB0 */
s32 func_00381BB0(void) {
}
/* localdecomp:end func_00381BB0 */

/* localdecomp:start func_00381BB8 */
s32 func_00381BB8(void) {
}
/* localdecomp:end func_00381BB8 */

/* localdecomp:start func_00381BC0 */
extern u8 D_001427AB[];
u8 func_00381BC0(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_00381BC0 */

extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

/* localdecomp:start func_00381BD0 */
extern s32 func_003E7358(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9898;
extern s32 D_001D9880[2];
s32 *func_00381BD0(void) {
    if (D_001D9898 == 0) {
        func_003E7358(D_001D9880, 0, 0, 0, 0, 0);
        D_001D9898 = 1;
    }
    return D_001D9880;
}
/* localdecomp:end func_00381BD0 */

/* localdecomp:start func_00381C18 */
extern s32 * func_00381BD0();
void func_00381C18(void) {
    func_00381BD0();
}
/* localdecomp:end func_00381C18 */

LINKER_REMNANT("asm/boot_elf/remnants", func_00381C38);

/* localdecomp:start func_00381C40 */
s32 func_00381C40(void) {
}
/* localdecomp:end func_00381C40 */

/* localdecomp:start func_00381C48 */
s32 func_00381C48(void) {
}
/* localdecomp:end func_00381C48 */

/* localdecomp:start func_00381C50 */
s32 func_00381C50(void) {
}
/* localdecomp:end func_00381C50 */

/* localdecomp:start func_00381C58 */
s32 func_00381C58(void) {
    return 0;
}
/* localdecomp:end func_00381C58 */

/* localdecomp:start func_00381C60 */
s32 func_00381C60(void) {
    return 0;
}
/* localdecomp:end func_00381C60 */

/* localdecomp:start func_00381C68 */
s32 func_00381C68(void) {
}
/* localdecomp:end func_00381C68 */

/* localdecomp:start func_00381C70 */
s32 func_00381C70(void) {
}
/* localdecomp:end func_00381C70 */

/* localdecomp:start func_00381C78 */
s32 func_00381C78(void) {
}
/* localdecomp:end func_00381C78 */

/* localdecomp:start func_00381C80 */
s32 func_00381C80(void) {
}
/* localdecomp:end func_00381C80 */

/* localdecomp:start func_00381C88 */
s32 func_00381C88(void) {
    return 0;
}
/* localdecomp:end func_00381C88 */

/* localdecomp:start func_00381C90 */
s32 func_00381C90(void) {
    return 1;
}
/* localdecomp:end func_00381C90 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00381C98);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C000);

typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_381CC0;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s16 h18; u8 p1A[0x15C - 0x1A]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_381CC0;
typedef struct { u8 p0[0x1A4]; s32 f1A4; } S_1D52FC_381CC0;
extern S_143950_381CC0 D_00143950_00381CC0;
extern S_142430_381CC0 D_00142430_00381CC0;
extern S_1D52FC_381CC0 *D_001D52FC_00381CC0;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_001D5784;
extern s32 D_001D4D40;
extern s32 D_001D4BC0;
extern s32 D_00227400[];
extern void func_0038E530(s32);
extern void func_0013D3C0(s32);
extern s32 func_00392F00();
extern s32 func_00393058();
extern s32 func_003823D0(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_0038EBC8_00381CC0(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);

LINKER_REMNANT("asm/boot_elf/remnants", func_00382358);

extern void *D_001D99A0;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CC80[];
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382360);

extern s32 func_00382360(s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003823D0);

/* localdecomp:start func_00382410 */
__asm__(".extern D_001D99A0, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382410(fallback)
s32 fallback;
{
    s32 index = func_00382360(fallback);
    register s32 value __asm__("$4") = *(s16 *)((u8 *)D_001D99A0 + (index * 0x10) + 0xC);
    register s32 result __asm__("$2") = fallback;
    if (value > 0) {
        register u8 flag __asm__("$3");
        result = (s32)D_001D52FC;
        flag = *(volatile u8 *)(result + 0x550);
        result = value;
        __asm__ volatile("" : "+r"(result));
        if (flag == 0) {
            result = fallback;
        }
    }
    return result;
}
/* localdecomp:end func_00382410 */

/* localdecomp:start func_00382468 */
extern s32 func_00382410();
void func_00382468(void) {
    func_003823D0(func_00382410());
}
/* localdecomp:end func_00382468 */

/* localdecomp:start func_00382490 */
extern s32 D_001D5688;
void func_00382490(void) { D_001D5688 = 0; }
/* localdecomp:end func_00382490 */

/* US draft of func_00382498 (rac3-uya-decomp func_003824B8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s32 D_001D5680;

/* localdecomp:start func_00382498 */
extern s32 D_001D5680;
void func_00382498(void) { D_001D5680 = 8; }
/* localdecomp:end func_00382498 */

/* localdecomp:start func_003824A8 */
extern void func_003980A0();
extern u8 D_001D5790[];
 
void func_003824A8(void) {
    func_003980A0(D_001D5790, 0, 0);
}
/* localdecomp:end func_003824A8 */

typedef struct { u8 p0[8]; s16 h8; u8 pA[2]; s16 hC; u8 pE[6]; s32 f14; } Img_3824F0;
typedef struct {
    u8 *f0; u8 *f4; u8 p8[0xC]; s32 f14; s32 f18; u8 p1C[0x10]; s32 f2C; u8 p30[0xC]; s32 f3C;
    u8 p40[0xC]; s32 f4C; s32 f50;
} Tex_3824F0;
extern void func_0038CF58(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s16, s32, s32, s16, s16);
extern void func_11F0A0(s32);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003824D0);

/* localdecomp:start func_003826A8 */
typedef struct { u8 p0[0x64C]; s32 f64C; s32 f650; s32 f654; } S_160C40_3826C8;
extern S_160C40_3826C8 D_160C40_003826A8;
extern u8 D_2D2100[];
extern s32 D_1A1F0C[];
extern s32 func_003A2AF0(s32, s32, s32);
extern void func_003824D0_003826A8(void *, unsigned long *, s32, s32);
void func_003826A8(void) {
    unsigned long out[4];
    S_160C40_3826C8 *g = &D_160C40_003826A8;
    func_003A2AF0((s32)D_2D2100, g->f650 + g->f64C, g->f654);
    func_003824D0_003826A8(D_2D2100, out, D_1A1F0C[0], 0x3FFC00);
    *(unsigned long *)0x1D4D38 = out[0];
}
/* localdecomp:end func_003826A8 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00382714);

/* localdecomp:start func_00382728 */
s32 func_00382728(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382728 */
