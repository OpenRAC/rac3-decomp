#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_00381140 */
extern void func_00397D48(s32, s32);

void func_00381140(void) {
    func_00397D48(0, 0);
}
/* localdecomp:end func_00381140 */

/* localdecomp:start func_00381160 */
extern void func_003BB7B0(s32);
extern void func_003B3228(void *);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern u8 D_001E22C0[];

void func_00381160(void) {
    func_003BB7B0(1);
    func_003B3228(D_001E22C0);
    func_003A0EC0(0x12, 1, 7, 0, 0);
}
/* localdecomp:end func_00381160 */

/* localdecomp:start func_003811A0 */
extern void func_003BB7B0(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);

void func_003811A0(void) {
    func_003BB7B0(1);
    func_003A0EC0(0x12, 1, 8, 0, 0);
}
/* localdecomp:end func_003811A0 */

/* localdecomp:start func_003811D8 */
s32 func_003811D8(void) {
}
/* localdecomp:end func_003811D8 */

LINKER_REMNANT("asm/remnants", func_003811E0);

INCLUDE_ASM("asm/nonmatchings/text", func_003811E8);

INCLUDE_ASM("asm/nonmatchings/text", func_00381250);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031BF60);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031BF80);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031BFD0);

extern s32 func_0011A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void * func_003AF0B8();
extern s32 D_001D5C78;
typedef struct {
    u8 pad[0x84];
    s32 f84;
} Struct227600;
extern Struct227600 D_00227580;
extern s32 D_00227580_0037D1A8[];
extern s32 D_001D5C78_0037D1A8[];
extern void func_11A264(s32, s32, s32);
extern s32 func_003F2388(s32, s32);
extern void * func_003AF0B8();
typedef struct { u8 p0[4]; s32 f4; u8 p8[4]; s32 fC; u8 p10[0x14]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_37D200;
typedef struct { u8 p0[0x18]; u8 *f18; u8 p1C[0x5C]; s32 f78; } S_227600_37D200;
typedef struct { u8 p0[7]; u8 f7; u8 p8[0x1C]; s32 f24; u8 p28[0x14]; s16 f3C; u8 p3E[2]; u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; u8 p48[6]; s16 f4E; u8 p50[0x1C]; s32 f6C; u8 p70[6]; s16 f76; u8 p78[0x44]; s32 fBC; u8 pC0[6]; s16 fC6; } S_1CCFD0_37D200;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_37D200;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[0x38]; s32 f688; s32 f68C; } S_160C40_37D200;
typedef struct { s32 f0; u8 p4[0xB3]; u8 fB7; } S_143950_37D200;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; } S_142430_37D200;
typedef struct { u8 p0[0x2C]; s32 f2C; } S_318CC0_37D200;
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } S_pad_37D200;
typedef struct { s32 a; s32 b; } E_37D200;
typedef struct { s32 off; s32 size; } H_37D200;
extern S_1A1ED0_37D200 D_001A1ED0;
extern S_227600_37D200 D_00227580_0037D200;
extern S_1CCFD0_37D200 D_001CCFD0;
extern S_16C580_37D200 D_0016C580;
extern S_160C40_37D200 D_00160C40;
extern S_143950_37D200 D_00143950;
extern S_142430_37D200 D_00142430;
extern S_318CC0_37D200 D_0031CC80_0037D200;
extern u8 D_001D5BDC;
extern s32 D_001D4BB4;
extern s32 D_001D4BB0;
extern s32 D_001D4B64;
extern s32 D_001D4B60;
extern s32 D_001D4B90;
extern s32 D_001D4BA0;
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
extern void func_003A8630(void);
extern void func_003A1330(void);
extern void func_003A9050(void);
extern void func_00397EA8(void);
extern void func_00387268(void);
extern void func_003A9108(void);
extern void func_003A9A40(void);
extern void func_0039A6E0(void);
extern s32 func_003A2598(s32, s32, s32);
extern void func_00392260(s32, long, long);
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_00387F68(void);
extern s32 func_12C908(s32);
extern void func_00392290(void);
extern s32 func_003A2750(s32);
extern void func_003A0760(u8 *, u32);
extern void func_003A11F0(s32 a, s32 idx);
extern void func_00398E50(void);
extern void func_003A0D48(void);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_003A3B70(void);
extern void func_00381D88(void);
extern s32 func_13D3C8(void);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern void func_0038E150(s32);
extern void func_003B3050(void);
extern void func_003B3088();
extern void func_003A9830_0037D200(u8 *, s32, s32, s32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003BB0B0(void);
extern s32 func_003E8528(s32 arg0, s32 *arg1);
extern s32 func_003E6FE8();
extern s32 func_003E84B0(s32 a);
extern void *func_003B4FD0();
extern void func_003E6FE0(void *);
extern s32 func_003E8440(s32 arg0);
extern void func_003A9440(s32, unsigned long);
extern void func_00389240(s32);
extern void func_003B30E8(void);
extern void func_003B3158(s32);
extern void func_003B3120(void);
extern s32 func_00381FF0(s32);
extern void func_0038E7E8_0037D200(f32, f32, f32, unsigned long, s32, s32, f32, s32, s32, unsigned long, f32, f32);
extern void func_00389370(void);
extern void func_003A8B10(void);
extern void func_003A1F30();
extern void func_003B3910(void);
extern void func_0039C410(void);
extern void func_0039ADE0(void);
extern void func_003A92F0(s32);
extern void func_00388138(void);

/* localdecomp:start func_00381C88 */
s32 func_00381C88(void) {
    return 0;
}
/* localdecomp:end func_00381C88 */

/* localdecomp:start func_00381C90 */
s32 func_00381C90(void) {
}
/* localdecomp:end func_00381C90 */

/* localdecomp:start func_00381C98 */
s32 func_00381C98(void) {
}
/* localdecomp:end func_00381C98 */

/* localdecomp:start func_00381CA0 */
s32 func_00381CA0(void) {
}
/* localdecomp:end func_00381CA0 */

/* localdecomp:start func_00381CA8 */
s32 func_00381CA8(void) {
}
/* localdecomp:end func_00381CA8 */

/* localdecomp:start func_00381CB0 */
extern u8 D_001427AB[];
u8 func_00381CB0(void) {
    return D_001427AB[0];
}
/* localdecomp:end func_00381CB0 */

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
/* localdecomp:start func_00381CC0 */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_001D9898;
extern s32 D_001D9880[2];
s32 *func_00381CC0(void) {
    if (D_001D9898 == 0) {
        func_003E6FA0(D_001D9880, 0, 0, 0, 0, 0);
        D_001D9898 = 1;
    }
    return D_001D9880;
}
/* localdecomp:end func_00381CC0 */

/* localdecomp:start func_00381D08 */
extern s32 * func_00381CC0();
void func_00381D08(void) {
    func_00381CC0();
}
/* localdecomp:end func_00381D08 */

LINKER_REMNANT("asm/remnants", func_00381D28);

/* localdecomp:start func_00381D30 */
s32 func_00381D30(void) {
}
/* localdecomp:end func_00381D30 */

/* localdecomp:start func_00381D38 */
s32 func_00381D38(void) {
}
/* localdecomp:end func_00381D38 */

/* localdecomp:start func_00381D40 */
s32 func_00381D40(void) {
}
/* localdecomp:end func_00381D40 */

/* localdecomp:start func_00381D48 */
s32 func_00381D48(void) {
    return 0;
}
/* localdecomp:end func_00381D48 */

/* localdecomp:start func_00381D50 */
s32 func_00381D50(void) {
    return 0;
}
/* localdecomp:end func_00381D50 */

/* localdecomp:start func_00381D58 */
s32 func_00381D58(void) {
}
/* localdecomp:end func_00381D58 */

/* localdecomp:start func_00381D60 */
s32 func_00381D60(void) {
}
/* localdecomp:end func_00381D60 */

/* localdecomp:start func_00381D68 */
s32 func_00381D68(void) {
}
/* localdecomp:end func_00381D68 */

/* localdecomp:start func_00381D70 */
s32 func_00381D70(void) {
}
/* localdecomp:end func_00381D70 */

/* localdecomp:start func_00381D78 */
s32 func_00381D78(void) {
    return 0;
}
/* localdecomp:end func_00381D78 */

/* localdecomp:start func_00381D80 */
s32 func_00381D80(void) {
    return 1;
}
/* localdecomp:end func_00381D80 */

typedef struct { u8 p0[0xAD]; u8 bAD; } S_143950_37DD30;
typedef struct { u8 p0[0x15C]; s32 f15C; u8 p160[4]; s32 f164; s32 f168; } S_142430_37DD30;
extern S_143950_37DD30 D_00143950_00381D88;
extern S_142430_37DD30 D_00142430_00381D88;
extern s32 D_001D568C;
extern s32 D_001D5690;
extern s32 D_001D5694;
extern s32 D_00227400[];
extern s32 D_001D4D40;
extern void func_0038E150(s32);
extern void func_13D3C0(s32);
extern s32 func_00392B20();
extern s32 func_00392C78();
extern s32 func_00381FF0(s32);
extern void func_003910C0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
INCLUDE_ASM("asm/nonmatchings/text", func_00381D88);

LINKER_REMNANT("asm/remnants", func_00381F78);

extern void *D_001D99A0;
typedef struct { u8 pad0[0x2C]; s32 f2C; } S_00318CC0_0037DF28;
extern S_00318CC0_0037DF28 D_0031CC80[];
INCLUDE_ASM("asm/nonmatchings/text", func_00381F80);

extern s32 func_00381F80(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00381FF0);

/* localdecomp:start func_00382030 */
__asm__(".extern D_001D99A0, 16");
__asm__(".extern D_001D52FC, 16");
extern void *D_001D52FC;
s32 func_00382030(fallback)
s32 fallback;
{
    s32 index = func_00381F80(fallback);
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
/* localdecomp:end func_00382030 */

/* localdecomp:start func_00382088 */
extern s32 func_00382030();
void func_00382088(void) {
    func_00381FF0(func_00382030());
}
/* localdecomp:end func_00382088 */

/* localdecomp:start func_003820B0 */
extern s32 D_001D5688;
void func_003820B0(void) { D_001D5688 = 0; }
/* localdecomp:end func_003820B0 */

/* US draft of func_003820B8 (rac3-uya-decomp func_0037E060, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


extern s32 D_001D5680;
/* localdecomp:start func_003820B8 */
extern s32 D_001D5680;
void func_003820B8(void) { D_001D5680 = 8; }
/* localdecomp:end func_003820B8 */

/* localdecomp:start func_003820C8 */
extern void func_00397CC0();
extern u8 D_001D5790[];
 
void func_003820C8(void) {
    func_00397CC0(D_001D5790, 0, 0);
}
/* localdecomp:end func_003820C8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003820F0);

INCLUDE_ASM("asm/nonmatchings/text", func_003822C8);

INCLUDE_ASM("asm/nonmatchings/text", func_00382338);

/* localdecomp:start func_00382348 */
s32 func_00382348(u8 *p) {
    s32 *q;
    if (p == 0 || (q = *(s32 **)(p + 0x68)) == 0 || !(*(u16 *)(p + 0x34) & 0x20)) {
        return 0;
    }
    return *q;
}
/* localdecomp:end func_00382348 */
