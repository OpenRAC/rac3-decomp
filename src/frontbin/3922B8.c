#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void func_003922B8(void);
extern void func_00392350(s32);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_00392440(s32, s32, s32, s32);
extern void func_00392868(s32, s32);
extern void func_003926E8(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { unsigned long v : 9; unsigned long r : 55; } FB_38CE40;
typedef struct {
    unsigned long dx : 12;
    unsigned long dy : 11;
    unsigned long magh : 4;
    unsigned long magv : 2;
    unsigned long p0 : 3;
    unsigned long dw : 12;
    unsigned long dh : 11;
    unsigned long p1 : 9;
} DI_38CE40;
typedef struct {
    unsigned long nloop : 15;
    unsigned long eop : 1;
    unsigned long p0 : 16;
    unsigned long id : 14;
    unsigned long pre : 1;
    unsigned long prim : 11;
    unsigned long flg : 2;
    unsigned long nreg : 4;
    unsigned long regs0 : 4;
    unsigned long regs : 60;
} GT_38CE40;
typedef struct {
    u8 p0[0x10];
    FB_38CE40 q10;
    DI_38CE40 q18;
    u8 p20[0x10];
    GT_38CE40 t30;
    FB_38CE40 q40;
    unsigned long q48;
    unsigned long q50;
    u8 p58[0x68];
    GT_38CE40 tC0;
    FB_38CE40 qD0;
    unsigned long qD8;
    unsigned long qE0;
    u8 pE8[0x68];
    s16 h150, h152, h154, h156, h158, h15A, h15C, h15E;
    s16 h160, h162, h164, h166, h168, h16A, h16C, h16E;
    s32 w170;
} E_38CE40;


extern u32 *D_001DA050;
extern s32 D_001D4CF8_003922B8;
extern void func_12C820(s32);
/* localdecomp:start func_003922B8 */
extern E_38CE40 D_001CFEC0_00391A58[];
extern E_38CE40 *D_001D4CF8_00391A58;
extern s32 D_001A1ED0_00391A58[];
extern s32 D_001D5520_003922B8;
extern u8 D_001D551D_003922B8;
extern s32 D_001D4D08_00391A58;
extern s32 D_001D4D0C_00391A58;
extern s32 D_001D4D10_00391A58;
extern s32 D_001D4D14_00391A58;
extern s32 D_001D4D18_00391A58;
extern s32 D_001D4D1C_00391A58;
extern s32 D_001D4D20_00391A58;
extern s32 D_001D4D24_00391A58;
extern s32 D_001D4D28_00391A58;
extern s32 D_001D4D2C_00391A58;
extern s32 D_001D4D30_00391A58;
extern s32 D_001D4D34_00391A58;
extern unsigned long D_001D02D0_00391A58[];
extern unsigned long D_001D0070_00391A58[];
extern unsigned long D_001D07B0_00391A58[];
extern unsigned long D_001D0900_00391A58[];
extern unsigned long D_00141850_00391A58[];
extern unsigned long D_00141990_00391A58[];
extern unsigned long D_00141AD0_00391A58[];
extern unsigned long D_00141DC0_00391A58[];
extern unsigned long D_001420B0_00391A58[];
extern void func_0012C138_003922B8(void *, s32, s16, s16, s16, s16);
extern void func_0012C638_003922B8(s32, s32, s32, s32, s32, s32);
extern void func_00391778(void);
extern void func_00391880(s32, s32);
extern void func_0038D068();
extern void func_11F0A0_003922B8(s32);
extern unsigned long D_001D07E8_003922B8[];
extern void func_12C4B0_003922B8(s32);
extern s32 D_001D4CF8_003922B8b[];

extern u32 *D_001DA050_003922B8;
extern s32 D_001D4CF8_003922B8_003922B8; 
extern void func_12C820_003922B8(s32);

void func_003922B8(void) {
    if (D_001DA050_003922B8 != 0) {
        D_001DA050_003922B8[0] = 0x30000009;
        D_001DA050_003922B8[1] = (D_001D4CF8_003922B8_003922B8 + 0x30) & 0xFFFFFFF;
        D_001DA050_003922B8[2] = 0;
        D_001DA050_003922B8[3] = 0x50000009;
        D_001DA050_003922B8 += 4;
    } else {
        func_12C820_003922B8(D_001D4CF8_003922B8_003922B8 + 0x30);
    }
}
/* localdecomp:end func_003922B8 */

extern u32 *D_001DA050;
extern u8 D_1D07B0[], D_1D0900[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392350);

extern u32 *D_001DA050;
extern s32 D_001D4CF8_003923D0;
/* localdecomp:start func_003923D0 */
extern u32 *D_001DA050_003923D0;
extern s32 D_001D4CF8_003923D0_003923D0;
void func_003923D0(void) {
    D_001DA050_003923D0[0] = 0x30000009;
    D_001DA050_003923D0[1] = (D_001D4CF8_003923D0_003923D0 + 0xC0) & 0xFFFFFFF;
    D_001DA050_003923D0[2] = 0;
    D_001DA050_003923D0[3] = 0x50000009;
    D_001DA050_003923D0 += 4;
}
/* localdecomp:end func_003923D0 */

typedef struct { unsigned long lo : 9; unsigned long hi : 55; } BF_38DC08;
typedef struct { u8 p0[0x160]; s16 h160; s16 h162; s16 h164; s16 h166; u8 p168[4]; u16 h16C; s16 h16E; } S_38DC08;
extern S_38DC08 D_001CFEC0_00392440[];
extern s32 D_001DA050_00392440;
extern long D_001D4C30;
extern void func_0038CBA0();
extern void func_0012C638(s32, s32, s32, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_00392440);

extern u32 *D_001DA050;
extern u8 D_001D0070[];
INCLUDE_ASM("asm/nonmatchings/text", func_003926E8);

extern u32 *D_001DA050;
extern u8 D_001D7370[];
extern u8 D_001D7390[];
extern u8 D_001D02D0[];
extern u8 D_001D7300[];
INCLUDE_ASM("asm/nonmatchings/text", func_00392748);

extern u32 *D_001DA050_00392868;
extern void func_003A9440(s32, unsigned long);
INCLUDE_ASM("asm/nonmatchings/text", func_00392868);
