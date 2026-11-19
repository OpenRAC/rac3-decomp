#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 392F68.c's earlier functions */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad[0x58]; s32 w; s32 h; union { s32 flags; u8 c; } u; } S_38EDE8;
extern s32 D_001D5CAC;
extern u8 D_001425C0[];
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);

typedef struct {
    u8 pad0[0x64];
    s32 f64;
    u8 pad68[4];
    s32 f6C;
    u8 st[4];
    s32 f74;
    s32 f78;
    s32 f7C;
} O_38F3F8;
typedef struct {
    u8 pad0[0x148];
    f32 f148;
    f32 f14C;
    u8 pad150[0x1C0 - 0x150];
    s32 f1C0;
    volatile s32 f1C4;
    u8 pad1C8[4];
    s32 f1CC;
    u8 pad1D0[8];
    s32 f1D8;
} PAD_38F3F8;
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
} E_38F3F8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    u8 pad14[0x84 - 0x14];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[0xF0 - 0x8C];
} T_38F3F8;
typedef struct { u8 pad[0xB6]; u8 b; } B6_38F3F8;
typedef struct { u8 pad0[0x1228]; s32 f1228; u8 pad122C[0x25F8 - 0x122C]; s32 f25F8; } W_38F3F8;
typedef struct { u8 pad0[0xF0]; u16 fF0; u8 padF2[2]; u32 fF4; s32 fF8; } X_38F3F8;
extern s32 D_0031D050[];
extern u8 D_00143950_b[];
extern s32 D_001D5C98;
extern s32 D_001D5D5C;
extern u8 D_001D5D58;
extern f32 D_001D5D54;
extern s32 D_001D5CAC;
extern PAD_38F3F8 *D_001D52FC;
extern u8 D_1A745E[];
extern s32 D_001D9EE8_0038F3F8;
extern s32 D_001D9EF0_0038F3F8;
extern volatile s32 D_001D5D00;
extern volatile s32 D_001D5D04;
extern volatile s32 D_001D5D08;
extern volatile s32 D_001D5D0C;
extern u8 D_1425C0[];
extern T_38F3F8 D_001DAA40_0038F3F8[];
extern s16 D_001CCFD4[];
extern u8 D_1A4BE0[];
extern u8 D_1A7C10[];
extern s32 D_1427F0[];
extern u32 D_001D4C38;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern s32 D_001D9BC8_0038F3F8;
extern s32 func_003E3DF0(void);
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern void func_003AEB48(void *, s32);
extern s32 func_003A3BB8(s32, s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_0038CB00(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038DB48(f32);
extern void func_003A2558(void);
extern s32 func_0039AC08(s32);
extern void func_0039AA38(s32);
extern void func_00381CA8(s32);
extern void func_00381D70(s32);
extern s32 func_003934B8(s32);
#define ROW_38F3F8 ((E_38F3F8 *)((s32 *)D_001D9EF0_0038F3F8)[D_001D5CAC])
INCLUDE_ASM("asm/nonmatchings/text", func_00394620);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0A0);
