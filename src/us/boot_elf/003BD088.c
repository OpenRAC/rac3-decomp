#include "common.h"

/* NTSC-U version of func_003BD160 (boot_elf): 5 -> 6 */

extern s32 func_12C908(s32);
extern s32 func_13B620(void);

typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
extern void func_U_0038CEA0();
typedef struct { u32 a; u32 b; } E_3B5D10;
extern void func_U_0038CEA0();
typedef struct { s32 id; s32 fl; } E_3B5F88;
typedef struct { u8 pad[4]; s16 f4; } S_3B5F88;
extern S_3B5F88 D_1CCFD0_003BB820[];
typedef struct { s32 f0; s32 f4; } E_3B61A0;
extern void func_11B2E8();
extern void func_13BC30(s32, void *, unsigned long);
extern void func_11F0A0();
extern void func_13CA20();
extern void func_13CA28();
extern void func_13B620_003BBC00();
extern void func_13C0B8(s32, s32, s32, s32, s32, s32, void *, long);
extern void func_13C230(int, int, int);
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x90]; s32 tbl[1]; } B_3B6F28;
typedef struct { s32 a[1]; } A_3B6F28;
typedef struct { u8 pad[0xA4]; u32 fA4; } S_1A30B0_3B6F28;
extern void func_11F0A0();
extern void func_13BED0();
typedef struct { u8 p0[0xC]; s32 fC; } P_3B70A8;
extern void func_11F0A0();
typedef struct { s32 off; s32 sz; } E_3B71B8;
typedef struct { u8 pad0[0x68]; s32 f68; s32 f6C; u8 pad70[0x20]; s32 f90[0x44]; } S_225780_3B71B8;
typedef struct { u8 pad0[8]; s32 f8; u8 pad1[0x60]; s32 tbl[1]; } H_3B71B8;
typedef struct { u8 pad0[0xC]; s32 fC; s32 f10; u8 *f14; H_3B71B8 *f18; } S_227600_3B71B8;
extern void func_U_0038CEA0();
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BCC10;
typedef struct { u8 pad[0x22]; u16 f22; } S_16C580c;
extern S_16C580c D_16C580_003BCE00;
extern s32 D_U_001D5B94;
extern void func_11F0A0(s32);
/* localdecomp:start func_U_003BD088 */
typedef struct { u8 p0[0x18]; s16 f18; u8 p1A[0x142]; s32 f15C; s32 f160; s32 f164; u8 p168[0x14]; s32 f17C; } S_142430_3B78C8;
typedef struct { u8 p0[7]; u8 f7; u8 p8[8]; } S_1CCFD0_3B78C8;
typedef struct { u8 p0[0x10]; u32 f10; } S_2276C0_3B78C8;
typedef struct { u8 p0[0x90]; s32 f90[6]; } S_1A30B0_3B78C8;
extern s32 D_U_001D5B94;
extern s32 D_U_001D9DAC;
extern s32 D_001D4CEC;
extern s32 D_001D545C;
extern s32 D_U_001D9D84;
extern u8 D_U_00227500[];
extern S_2276C0_3B78C8 D_U_002276C0;
extern S_1A30B0_3B78C8 D_1A30B0;
extern S_142430_3B78C8 D_142430;
extern S_1CCFD0_3B78C8 D_1CCFD0;
extern void func_U_0038CEA0();
extern void func_U_003C3028();
extern void func_11F0A0();
extern void func_13CF80(s32, s32, s32, s32, s32);
extern void func_13CA28(void);
extern void func_U_003A56F0(void);
extern void func_U_003A1EE8(void);
extern void func_13BF00(s32);
extern void func_13BED0(void);
extern void func_U_0039C6D8(void);
extern void func_U_0039B0A8(void);
extern s32 func_13CF40(s32);
extern void func_U_003A2A10(s32);
extern void func_U_0038A5C0(s32);
extern void func_U_0039A418(void);
extern void func_13CDF0(s32);
extern void func_U_003A9D40(void);
void func_U_003BD088(void) {
    s32 i;
    func_U_0038CEA0(D_U_00227500, -1, 0x80);
    D_U_002276C0.f10 |= 0x80000000;
    D_U_001D5B94 = 6;
    func_U_003C3028();
    func_11F0A0(0);
    func_13CF80(2, 0, 0, 0, 0);
    func_13CA28();
    func_13B620();
    func_U_003A56F0();
    func_U_003A1EE8();
    D_1CCFD0.f7 = 1;
    for (i = 0; i < 6; i++) {
        if (D_1A30B0.f90[i] != 0) {
            func_13BF00(D_1A30B0.f90[i]);
            func_13BED0();
            D_U_001D9DAC = 0;
            D_1A30B0.f90[i] = 0;
        }
    }
    while (D_142430.f15C >= 3 || D_142430.f164 >= 0) {
        func_U_0039C6D8();
        func_U_0039B0A8();
    }
    if (D_142430.f17C != 0) D_142430.f17C = 0;
    if (D_142430.f18 >= 0) D_142430.f18 = -1;
    D_001D4CEC &= ~0x200;
    func_13CF40(0);
    D_1CCFD0.f7 = 0;
    func_U_003A2A10(1);
    do {} while (((s32 (*)(void))func_13B620)());
    D_1CCFD0.f7 = 1;
    func_U_0038A5C0(6);
    D_001D545C = D_U_001D9D84;
    func_U_0039A418();
    func_13CDF0(0);
    D_1CCFD0.f7 = 0;
    func_U_003A9D40();
}
/* localdecomp:end func_U_003BD088 */
