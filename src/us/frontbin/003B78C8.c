#include "common.h"

/* NTSC-U counterpart of func_003BCDA8 (frontbin). */
extern s32 func_0013B620(void);

/* localdecomp:start func_U_003B78C8 */
/* func_U_003B78C8 (PAL, boot_elf). Based on the US draft of rac3-uya-decomp func_003BD088,
   commit 13cf5c5, names moved to PAL addresses where known. Matches with the source
   file's own flags; the only PAL difference from the US draft was the argument of
   func_U_00385B60_003B78C8 (5 here, 6 in the US). */


typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8_003BCDA8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8_003BCDA8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8_003BCDA8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8_003BCDA8;
extern s32 D_U_001D5B94_003B78C8;
extern s32 D_U_001D9DAC_003B78C8;
extern s32 D_001D4CEC_003B78C8;
extern s32 D_001D545C_003B78C8;
extern s32 D_U_001D9D84_003B78C8;
extern u8 D_U_00227500_003B78C8[];
extern S_2276C0_3B78C8_003BCDA8 D_U_002276C0_003B78C8;
extern S_1A30B0_3B78C8_003BCDA8 D_001A30B0_003B78C8;
extern S_142430_3B78C8_003BCDA8 D_00142430_003B78C8;
extern S_1CCFD0_3B78C8_003BCDA8 D_001CCFD0_003B78C8;
extern void func_U_00388440_003B78C8();
extern void func_U_003BD868_003B78C8();
extern void func_0011F0A0_003B78C8();
extern void func_0013CF80_003B78C8(s32, s32, s32, s32, s32);
extern void func_0013CA28_003B78C8(void);
extern void func_U_003A0010_003B78C8(void);
extern void func_U_0039CBA0_003B78C8(void);
extern void func_0013BF00_003B78C8(s32);
extern void func_0013BED0_003B78C8(void);
extern void func_U_00397490_003B78C8(void);
extern void func_U_00395FF0_003B78C8(void);
extern s32 func_0013CF40_003B78C8(s32);
extern void func_U_0039D6C8_003B78C8(s32);
extern void func_U_00385B60_003B78C8(s32);
extern void func_U_00395360_003B78C8(void);
extern void func_0013CDF0_003B78C8(s32);
extern void func_U_003A4580_003B78C8(void);
void func_U_003B78C8(void) {
    s32 i;
    func_U_00388440_003B78C8(D_U_00227500_003B78C8, -1, 0x80);
    D_U_002276C0_003B78C8.f10 |= 0x80000000;
    D_U_001D5B94_003B78C8 = 6;
    func_U_003BD868_003B78C8();
    func_0011F0A0_003B78C8(0);
    func_0013CF80_003B78C8(2, 0, 0, 0, 0);
    func_0013CA28_003B78C8();
    func_0013B620();
    func_U_003A0010_003B78C8();
    func_U_0039CBA0_003B78C8();
    D_001CCFD0_003B78C8.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_001A30B0_003B78C8.f90[i] != 0) {
            func_0013BF00_003B78C8(D_001A30B0_003B78C8.f90[i]);
            func_0013BED0_003B78C8();
            D_U_001D9DAC_003B78C8 = 0;
            D_001A30B0_003B78C8.f90[i] = 0;
        }
    }
    while (D_00142430_003B78C8.f15C >= 3 || D_00142430_003B78C8.f164 >= 0) {
        func_U_00397490_003B78C8();
        func_U_00395FF0_003B78C8();
    }
    if (D_00142430_003B78C8.f17C != 0) D_00142430_003B78C8.f17C = 0;
    if (D_00142430_003B78C8.f18 >= 0) D_00142430_003B78C8.f18 = -1;
    D_001D4CEC_003B78C8 &= ~0x200;
    func_0013CF40_003B78C8(0);
    D_001CCFD0_003B78C8.f7 = 0;
    func_U_0039D6C8_003B78C8(1);
    do {} while (((s32 (*)(void))func_0013B620)());
    D_001CCFD0_003B78C8.f7 = 1;
    func_U_00385B60_003B78C8(6);
    D_001D545C_003B78C8 = D_U_001D9D84_003B78C8;
    func_U_00395360_003B78C8();
    func_0013CDF0_003B78C8(0);
    D_001CCFD0_003B78C8.f7 = 0;
    func_U_003A4580_003B78C8();
}
/* localdecomp:end func_U_003B78C8 */
