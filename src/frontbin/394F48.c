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
extern void func_00393808(void *);
extern s32 D_001D5CAC;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern s32 D_001D9F28;
extern void func_003E3E08(void);
extern void func_003E3DC0(void);
extern s32 func_003A5348(s32, s32, s32);
extern f32 func_0038D160(f32, f32);
extern s32 func_003934B8(s32);
extern s32 func_00393620(S_38EDE8 *p, s32 *x, s32 *y);
extern void func_00393808(void *arg);

/* US draft of func_00394F48 (rac3-uya-decomp func_003906E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_00394F48 */
extern s32 D_001D9EE8[];
extern s32 D_001D9EF0[];
extern s32 D_001D5D38;
extern s32 D_001D5CAC;
void func_00394F48(u8 *p) {
    D_001D9EE8[0] = 4;
    D_001D9EF0[0] = (s32)&D_001D5D38;
    *(s32 *)(p + 0x58) = 0xD2;
    *(s32 *)(p + 0x5C) = 0xC8;
    *(s32 *)(p + 0x74) = -2;
    *(s16 *)(p + 0x48) = 0;
    *(s16 *)(p + 0x4A) = 0;
    *(s32 *)(p + 0x78) = 0x19;
    D_001D5CAC = 0;
}
/* localdecomp:end func_00394F48 */

typedef struct { u8 p0[0x64]; s32 f64; u8 p68[4]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_390730;
typedef struct { u8 p0[0x148]; f32 f148; f32 f14C; u8 p150[0x70]; s32 f1C0; s32 f1C4; s32 f1C8; s32 f1CC; } P_390730;
typedef struct { u8 p0[8]; s32 f8; s32 fC; s32 f10; s32 f14; s32 f18; } T_390730;
typedef struct { u8 p0[0x286C]; s32 f286C; } G_390730;
extern P_390730 *D_001D52FC_00394F90;
extern s16 D_001D9EB4;
extern s16 D_001D9EB8;
extern s16 D_001D9EBA;
extern s16 D_001D9EBC;
extern s32 D_001D9EE8_00394F90;
extern s32 D_001D9EF0_00394F90;
extern s32 D_001D9BC8_00394F90;
extern volatile s32 D_001D5D20;
extern volatile s32 D_001D5D24;
extern volatile s32 D_001D5D28;
extern volatile s32 D_001D5D2C;
extern s32 D_001D9F28;
extern s32 D_001D9F2C;
extern s32 D_001D9F30;
extern u8 D_00143A06[];
extern G_390730 D_001A4BE0_00394F90;
extern void func_003E3E08(void);
extern f32 func_0038D160(f32, f32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003E3DC0(void);
extern s32 func_003934B8(s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00394F90);

INCLUDE_ASM("asm/nonmatchings/text", func_00395478);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C0C0);

LINKER_REMNANT("asm/remnants", func_00396240);

typedef struct { u8 p0[8]; s32 w8; u8 pC[0x44]; s32 w50; s32 w54; s32 w58; s32 w5C; u8 p60[0xC]; s32 w6C; u8 p70[4]; s32 w74; } O_91A18;
extern void func_00396C60();
extern void func_003970D8();
extern void func_00393690();
extern s16 D_001A666A[];
INCLUDE_ASM("asm/nonmatchings/text", func_00396278);

/* PAL candidate for func_00396390 (frontbin).
   Same shape as the US draft; the constant stored at offset 0x7C is 0x82 in PAL
   retail (0x96 in the US build). */

/* localdecomp:start func_00396390 */
extern void func_00393808(void *);
 
void func_00396390(void *p) {
    *(s32 *)((u8 *)p + 0x7C) = 0x82;
    *(s32 *)((u8 *)p + 0x58) = 0x20;
    *(s32 *)((u8 *)p + 0x5C) = 0x20;
    func_00393808(p);
}
/* localdecomp:end func_00396390 */

/* localdecomp:start func_003963C0 */
s32 func_003963C0(void) {
    return 0;
}
/* localdecomp:end func_003963C0 */

LINKER_REMNANT("asm/remnants", func_003963C8);
