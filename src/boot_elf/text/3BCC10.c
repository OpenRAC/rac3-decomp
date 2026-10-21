#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_12C908(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_13B620(void);
extern s32 func_003BD870();
/* --- end of declarations from other files --- */

/* declarations of 3BB3B8.c's earlier functions (tools/port_from_us.py) */
extern s32 D_0037FA44[];
typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
extern TargetStruct_0037BA20 D_0037F9D0;
extern s32 D_0037FA44[];
extern s8 D_001D8BF0[1];
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern S_3B5CA0 D_0037F9D0_003BB538[];
extern u8 D_002D0040[];
extern void func_0038CF58();
typedef struct { u32 a; u32 b; } E_3B5D10;
extern E_3B5D10 D_001DA1B0_003BB5A8[1];
extern u8 D_001D5BDC;
extern u8 D_00280FC0[];
extern void *D_001DA1B0[];
extern u32 D_001DA1B4[];
extern s32 func_003BB8E8(s32);
extern void func_0038CF58();
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern E_3B5F88 D_001DA1B0_003BB820[1];
extern s32 D_001DA1B4_003BB820[2];
extern s32 D_001DA1B4_003B5F88b[2];
extern S_3B5F88 D_1CCFD0_003BB820[];
extern void func_003A2958();
extern s32 D_001DA1B0_003BB8E8[];
extern s32 D_001DA1B4_003BB8E8[];
extern f32 D_001D8C2C;
extern s32 func_0038DFB8(f32, s32, s32);
extern s32 func_003E8128(s32, s32);
extern f32 D_001D8C30;
extern f32 D_001D8C2C;
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern E_3B61A0 D_0037FA58[];
extern s32 D_0037FA64[];
extern char D_001D8C40[];
extern char D_001D8C48[];
extern s32 func_003823D0();
extern void func_11B2E8();
extern u8 D_001D8CB0;
extern s32 D_001D8CEC;
extern s32 D_001D8CE8;
extern void func_13BC30(s32, void *, unsigned long);
extern void func_003A58F0();
extern void func_11F0A0();
extern s32 D_001D8CE0_003BBC00;
extern s32 D_001DA1F0_003BBC00[1];
extern s32 D_001DA218_003BBC00[1];
extern s32 D_001DA240_003BBC00[1];
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBC00();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_003BBBF0();
extern int D_001D8CE0_003BBCA8;
extern int D_001DA218[];
extern int D_001DA240[];
extern void func_13C230(int, int, int);
extern void func_0013CA20(void);
extern void func_0013BF00(s32);
extern void func_0013CA28(void);
extern s32 func_0013B620(void);
extern void func_0013BED0(void);
extern u32 D_001D8CE0;
extern s32 D_001DA1F4[];
extern s32 D_001D4B4C[];
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
extern B_3B6F28 *D_00227598_003BC7C0[];
typedef struct { s32 a[1]; } A_3B6F28;
extern s32 D_001DA218_003BC7C0[2];
extern s32 D_001DA240_003BC7C0[2];
extern s32 D_001DA1F0_003BC7C0[2];
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern S_1A30B0_3B6F28 D_001A30B0;
extern void func_003BBB80();
extern void func_11F0A0();
extern void func_13BED0();
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern P_3B70A8 *D_00227598[];
extern s32 D_0037FFE8[];
extern void func_11F0A0();
extern unsigned long func_0039B088(s32);
typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern S_225780_3B71B8 D_00225700_003BCA50;
extern S_227600_3B71B8 D_00227580;
extern s32 D_001DA058;
extern void func_0038CF58();
extern void func_003C2C38(s32 p);
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern S_B7288 D_00225700;
extern void func_003865D0(void);
extern void func_003C3178(void);
extern void func_00388348(void);
extern void func_003BCC10(void);
extern void func_00392AC8(void);
extern s32 D_001D9D1C;
extern void (*D_001D8CC0)(void);

typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BCC10;
extern s32 D_001D99A4;
extern s32 D_001D4BC4;
extern s32 D_001D9BC8;
extern f32 D_001D8CF0;
extern void func_00389620(s32);
extern void func_003A97F8(s32, unsigned long);
extern long func_00389978(s32);
extern void func_0038B8B0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_00397A18(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_00389750(void);
extern void func_0038B200(s32, s32, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BCC10);

/* localdecomp:start func_003BCE00 */
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCE00;
__asm__(".extern D_001D8CB8, 4");
__asm__(".extern D_001D8CD4, 4");
__asm__(".extern D_001D8CBC, 4");
extern s32 (*D_001D8CB8)();
extern s32 D_001D8CD4;
extern void (*D_001D8CBC)(s32);
extern s32 D_001D5B94;
extern s32 D_001D9D00;
extern void func_003CD410();
extern void func_003CD708();
s32 func_003BCE00(s32 a) {
    s32 r;
    D_001D5B94 = 6;
    D_16C580_003BCE00.f22++;
    r = D_001D8CB8(a);
    if (D_001D8CD4 & 4) { func_003CD410(); }
    if (D_001D8CD4 & 0x10) { func_003CD708(); }
    if (D_001D8CBC != 0) { D_001D8CBC(a); }
    D_001D9D00++;
    return r;
}
/* localdecomp:end func_003BCE00 */

/* localdecomp:start func_003BCEB0 */
__asm__(".extern D_001D8CD4, 4");
extern s32 D_001D9348;
extern s32 D_001D9364;
extern s32 D_001D9C10;
extern s32 D_001D9C08;
extern s32 D_001D9C0C;
extern s32 D_001A1ED0_3BCDD8[];
extern u8 D_00100AE0[];
extern u8 D_002FDC00[];
extern void func_003A97F8(s32, unsigned long);
extern void func_003BD108();
extern void func_003877A0();
extern void func_003865D0();
extern void func_003CF4A8();
extern void func_003AA028(s32);
extern void func_003A9A90();
extern void func_00389620(s32);
extern void func_0038A208();
extern void func_00389750();
extern void func_003A9A30();
extern void func_003C3C18();
extern void func_0038A190();
extern void func_11F0A0(s32);
extern void func_003CD790();
extern void func_003A9348();
extern void func_003A96A8(s32);
extern void func_003D0538();
extern void func_003CF408();
extern void func_003C3568();
extern void func_0038A348();
extern void func_003868A0(s32);
extern void func_003D8978_003BCEB0(s32);
extern void func_003D89F8();
extern void func_003D9618_003BCEB0(s32);
void func_003BCEB0(void) {
    D_001D9348 = 0;
    func_003877A0();
    func_003865D0();
    if (D_001D8CD4 & 1) func_003BD108();
    if (D_001D8CD4 & 2) {
        func_003CF4A8();
        func_003AA028(0x2010000);
    }
    if (D_001D9C10) {
        func_003A9A90();
        func_00389620(1);
        func_0038A208();
        func_00389750();
        func_003A9A30();
    }
    if (D_001D8CD4 & 0xC) {
        func_003C3C18();
        func_003AA028(0x2080000);
    }
    func_00389620(1);
    if (D_001D9C08) func_0038A190();
    func_003A9A90();
    func_003A97F8(8, 5);
    func_003A97F8(0x47, 0x53001);
    func_11F0A0(0);
    func_003CD790();
    *(volatile s32 *)&D_001D9D1C = 9;
    func_003A97F8(0x47, 0x5360B);
    func_003A9348(D_00100AE0);
    func_11F0A0(0);
    if (D_001D8CD4 & 2) {
        func_003A96A8(2);
        func_003D0538(D_002FDC00);
        func_003CF408();
    }
    if (D_001D8CD4 & 0xC) {
        func_003A96A8(0x10);
        func_003C3568();
    }
    func_00389750();
    if (D_001D9C0C) {
        func_00389620(1);
        func_003A97F8(0x4E, (D_001A1ED0_3BCDD8[2] >> 13) | 0x31000000 | 0x100000000UL);
        func_003A9A90();
        func_0038A348();
        func_003A97F8(0x4E, 0x31000000 | (D_001A1ED0_3BCDD8[2] >> 13));
        func_00389750();
    }
    func_003868A0(0);
    if (D_001D9348) {
        func_003D8978_003BCEB0(0);
        func_003D89F8();
    }
    if (D_001D9364) {
        func_003D9618_003BCEB0(0);
        D_001D9364 = 0;
    }
}
/* localdecomp:end func_003BCEB0 */

extern void func_003CE608(void);
extern void func_003CE568(void);
extern void func_003CE678(void);
extern void func_003A97F8(s32, unsigned long);
extern s32 D_001A1ED8[];
/* localdecomp:start func_003BD108 */
void func_003BD108(void) {
    func_003CE608();
    func_003CE568();
    func_003CE678();
    func_003A97F8(0x47, 0x5360B);
    func_003A97F8(0x4E, (D_001A1ED8[0] >> 13) | 0x1000000);
}
/* localdecomp:end func_003BD108 */

/* func_003BD160 (PAL, boot_elf). Based on the US draft of rac3-uya-decomp func_003BD088,
   commit 13cf5c5, names moved to PAL addresses where known. Matches with the source
   file's own flags; the only PAL difference from the US draft was the argument of
   func_0038A618 (5 here, 6 in the US). */


/* localdecomp:start func_003BD160 */
typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_001D5B94;
extern s32 D_001D9D2C;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_001D9D04;
extern u8 D_00227480[];
extern S_2276C0_3B78C8 D_00227640;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_0038CF58();
extern void func_003C3140();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_003A5830(void);
extern void func_003A2028(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_0039C7F0(void);
extern void func_0039B1C0(void);
extern s32 func_13CF40(s32);
extern void func_003A2B50(s32);
extern void func_0038A618(s32);
extern void func_0039A530(void);
extern void func_13CDF0(s32);
extern void func_003A9E88(void);
void func_003BD160(void) {
    s32 i;
    func_0038CF58(D_00227480, -1, 0x80);
    D_00227640.f10 |= 0x80000000;
    D_001D5B94 = 6;
    func_003C3140();
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620();
    func_003A5830();
    func_003A2028();
    D_1CCFD0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0.f90[i] != 0) {
            func_13BF00(D_1A30B0.f90[i]);
            func_13BED0();
            D_001D9D2C = 0;
            D_1A30B0.f90[i] = 0;
        }
    }
    while (D_142430.f15C >= 3 || D_142430.f164 >= 0) {
        func_0039C7F0();
        func_0039B1C0();
    }
    if (D_142430.f17C != 0) D_142430.f17C = 0;
    if (D_142430.f18 >= 0) D_142430.f18 = -1;
    D_001D4CEC &= ~0x200;
    func_13CF40(0);
    D_1CCFD0.f7 = 0;
    func_003A2B50(1);
    do {} while (((s32 (*)(void))func_13B620)());
    D_1CCFD0.f7 = 1;
    func_0038A618(5);
    D_001D545C = D_001D9D04;
    func_0039A530();
    func_13CDF0(0);
    D_1CCFD0.f7 = 0;
    func_003A9E88();
}
/* localdecomp:end func_003BD160 */

/* localdecomp:start func_003BD338 */
extern u8 D_001D5571;
s32 func_003A7A18_003BD338(s32);                         /* extern */
extern s32 D_001D9D04;
typedef struct { u8 pad0[0x7]; s8 f7; } S_001CCFD0_003B7AA0_003B7AA0;
extern S_001CCFD0_003B7AA0_003B7AA0 D_001CCFD0[];

void func_003BD338(void) {
    if (D_001D9D04 == 1) {
        if (D_001D5571 == 0) {
            D_001CCFD0->f7 = 0;
            if ((func_003A7A18_003BD338(1) == 0) && (func_003A7A18_003BD338(2) == 0) && (func_003A7A18_003BD338(3) == 0) && (func_003A7A18_003BD338(4) == 0) && (func_003A7A18_003BD338(5) == 0)) {
                func_003A7A18_003BD338(6);
            }
            D_001CCFD0->f7 = 1;
        }
    }
}
/* localdecomp:end func_003BD338 */

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003BD3E8);

/* localdecomp:start func_003BD748 */
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7EB0;
typedef struct { u8 p0[7]; u8 f7; } S_1CCFD0_3B7EB0;
__asm__(".extern D_001D8CD1, 1");
__asm__(".extern D_001DA1F0, 4");
__asm__(".extern D_001D8CC4, 4");
extern u8 D_001D8CD1;
extern s32 D_001DA1F0;
extern void (*D_001D8CC4)(void);
extern S_142430_3B7EB0 D_142430_003BD748;
extern S_1CCFD0_3B7EB0 D_1CCFD0_003BD748;
extern void func_11F0A0();
extern void func_0039C7F0(void);
extern void func_0039B1C0(void);
extern s32 func_0039A5C0(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_003A9E88(void);
extern void func_003882D0(void);
void func_003BD748(void) {
    s32 r;
    *(s32 *)0x1D4B4C = 0;
    if (D_001D8CD1 == 0) {
        do {
            func_11F0A0(0);
            func_12C908(0);
            func_0039C7F0();
            func_0039B1C0();
            r = D_001D8CD1 = func_0039A5C0() != 0;
        } while (r == 0);
    }
    while (D_142430_003BD748.f15C != 2 || D_142430_003BD748.f164 >= 0) {
        func_11F0A0(0);
        func_12C908(0);
        func_0039C7F0();
        func_0039B1C0();
    }
    if (D_001DA1F0 != 0) func_13BF00(D_001DA1F0);
    do {} while (func_13B620());
    func_13BED0();
    func_13CF40(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    ((s32 (*)(s32))func_13CDF0)(0);
    { S_1CCFD0_3B7EB0 *c = &D_1CCFD0_003BD748; c->f7 = 0; }
    func_003A9E88();
    if (D_001D8CC4 != 0) D_001D8CC4();
    func_003882D0();
}
/* localdecomp:end func_003BD748 */

/* localdecomp:start func_003BD870 */
__asm__(".extern D_001D8CD0, 1");
__asm__(".extern D_001D8CD1, 1");
__asm__(".extern D_001D9D54, 4");
__asm__(".extern D_001D8CF4, 1");
__asm__(".extern D_001D8CF0, 4");
extern u8 D_001D5BDC;
extern s32 D_001D9D04;
extern u8 D_001D8CD0;
extern u8 D_001D8CD1;
extern s32 D_001D9D54;
extern s32 D_001D9BC8;
extern s32 D_001D6E90;
extern s32 D_001D4B48;
extern u8 D_001D8CF4;
extern f32 D_001D8CF0;
extern void func_0039F008(s32, s32);
extern void func_003BD160_003BD870(void);
extern void func_003BD3E8(void);
extern void func_003882D0(void);
extern void func_003A3F70(void);
extern s32 func_003BCE00(s32);
extern void func_003875F8(void);
extern void func_003BCBB8(void);
extern void func_0039C7F0(void);
extern void func_0039B1C0(void);
extern void func_003A96A8(s32);
extern s32 func_0039A5C0(void);
extern void func_003A9588(void);
extern void func_003A9508(void);
extern void func_003927B0(void);
extern void func_003BE5B8(void);
extern void func_00392B28(s32);
extern void func_00392698(void);
extern void func_00392730(s32);
extern void func_0038A618(s32);
extern void func_003BD748(void);
s32 func_003BD870(void) {
    s32 r;
    if (D_001D5BDC == 0) func_0039F008(0, D_001D9D04);
    if (D_001D9D04 < 0) {
        func_003BD160_003BD870();
        return 1;
    }
    r = 0;
    func_003BD3E8();
    D_001D8CD0 = 0;
    D_001D8CD1 = 0;
    for (;;) {
        func_003A9588();
        func_003A9508();
        func_003927B0();
        if (D_001D8CF4 != 0) func_003BE5B8();
        else func_00392B28(1);
        func_00392698();
        func_00392730(0);
        if (r != 0) break;
        func_003882D0();
        func_003A3F70();
        r = func_003BCE00(D_001D8CD0);
        D_001D9D54 = 0;
        func_003875F8();
        func_003BCBB8();
        func_0039C7F0();
        func_0039B1C0();
        func_003A96A8(1);
        func_12C908(0);
        D_001D9BC8++;
        if (D_001D6E90 == 0) D_001D8CD1 = func_0039A5C0() != 0;
        D_001D8CD0 = D_001D4B48 >= 2;
    }
    func_003A96A8(1);
    func_12C908(0);
    if (D_001D8CF0 > 0.0f) func_0038A618(2);
    func_003BD748();
    return 1;
}
/* localdecomp:end func_003BD870 */
