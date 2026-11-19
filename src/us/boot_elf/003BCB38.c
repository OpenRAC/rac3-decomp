#include "common.h"

/* NTSC-U version of func_003BCC10 (boot_elf): 25 -> 30; 25 -> 30 */
#include "common.h"


extern s32 func_12C908(s32);
extern s32 func_13B620(void);



typedef struct {
    char pad_0[0x74];
    s32 field_74;      
    s32 field_78;       
} TargetStruct_0037BA20;
typedef struct { u8 pad[0xC]; u8 *buf[4]; } S_3B5CA0;
typedef struct { u32 a; u32 b; } E_3B5D10;
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
typedef struct { u8 p0[0x44]; s16 n; u8 p1[0x15A]; void *slot[1]; } S_B7288;
typedef struct { u8 p0[0xC]; u8 c; u8 p1[0x3B]; s32 q[1]; } I_B7288;
typedef struct { u8 p0[0x24]; I_B7288 *in; } O_B7288;
extern void func_U_003BCB38(void);
typedef struct { u8 p0[0x15C]; s32 f15C; s32 f160; s32 f164; } S_142430_3B7378;
extern S_142430_3B7378 D_142430_003BCC10;
extern s32 D_U_001D9A24;
extern s32 D_001D4BC4;
extern s32 D_U_001D9C48;
extern f32 D_U_001D8D20;
extern void func_U_003895C8(s32);
extern void func_U_003A96B0(s32, unsigned long);
extern long func_U_00389920(s32);
extern void func_U_0038B7F8(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_U_00397930(f32, f32, f32, f32, f32, s32, s32, long);
extern void func_U_003896F8(void);
extern void func_U_0038B148(s32, s32, s32, s32);
/* localdecomp:start func_U_003BCB38 */
__asm__(".extern D_U_001D8D20, 4");
void func_U_003BCB38(void) {
    f32 rotation, y, size;
    if ((D_142430_003BCC10.f15C == 15 || D_142430_003BCC10.f15C == 16) ||
        D_142430_003BCC10.f164 == 15 || D_U_001D9A24 != 0) {
        size = 272.0f;
        func_U_003895C8(1);
        func_U_003A96B0(0x42, 0x8000000044UL);
        func_U_003A96B0(0x47, 0x3004B);
        func_U_0038B7F8(0x2C, D_001D4BC4 - 96, 64, 64, 0, 0, 64, 64, 0x80808080UL, func_U_00389920(3));
        rotation = (f32)(D_U_001D9C48 % 55) * -6.2831855f / 55.0f;
        y = (f32)((D_001D4BC4 - 64) << 4);
        func_U_00397930(1216.0f, y, size, size, rotation, 64, 64, func_U_00389920(4));
        func_U_003896F8();
        if ((D_142430_003BCC10.f15C == 15 || D_142430_003BCC10.f15C == 16) ||
            D_142430_003BCC10.f164 == 15) {
            D_U_001D9A24 = 30;
        } else {
            D_U_001D9A24--;
        }
    }
    func_U_003A96B0(0x42, 0x8000000044UL);
    func_U_0038B148(0, 0, 0, (s32)(D_U_001D8D20 * 128.0f));
}
/* localdecomp:end func_U_003BCB38 */
