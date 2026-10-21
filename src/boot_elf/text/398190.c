#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 398040.c's earlier functions (tools/port_from_us.py) */
extern s32 D_001D5F00[];
extern s32 D_001D5EE8[];
extern s32 D_001D9F4C;
extern s32 D_001D9F48;
extern void func_13B0C8();
extern void func_003980A0();
typedef struct { u8 pad[0x10]; s32 a; u16 b; u8 pad2[0x1A]; } S_3934E8;

LINKER_REMNANT("asm/boot_elf/remnants", func_00398190);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003981A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003981AC);

/* localdecomp:start func_003981B0 */
extern void func_00123C90(void);
extern void func_00123C20(void);

void func_003981B0(void) {
    func_00123C90();
    func_00123C20();
}
/* localdecomp:end func_003981B0 */

/* localdecomp:start func_003981D8 */
extern s32 func_11F1E0();
extern s32 func_11F1C0();
extern s32 func_001240E0();
extern void func_003981B0(void);
s32 func_003981D8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 s[4];
    s32 h;
    s32 r;
    r = -1;
    s[0] = a;
    s[1] = c;
    s[2] = b;
    s[3] = 0;
    h = func_11F1E0(s, 1);
    if (h != 0) {
        do {} while (func_11F1C0(h) >= 0);
        r = func_001240E0(c, d, e);
    }
    func_003981B0();
    return r;
}
/* localdecomp:end func_003981D8 */

extern u8 D_00227580_00398288[];
extern u8 D_3F3777[];
extern u8 D_01FF8000[];
extern u8 D_01FFC000[];
extern u32 D_001DA058;
extern s32 func_0011A264(s32, s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00398288);

LINKER_REMNANT("asm/boot_elf/remnants", func_003983A8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003983C8);
INCLUDE_RODATA("asm/boot_elf/nonmatchings/text/rodata", jtbl_0031C120);

typedef struct { s32 f0; u8 p4[0xA9]; u8 fAD; u8 pAE[9]; u8 fB7; } S_143950_3982E0;
typedef struct { u8 p0[0x64C]; s32 f64C; u8 p650[8]; s32 f658; s32 f65C; } S_160C40_3982E0;
typedef struct { u8 p0[0x78]; s32 f78; } S_227600_3982E0;
typedef struct { u8 p0[0x24]; s32 f24; s32 f28; s32 f2C; s32 f30; s32 f34; s32 f38; s32 f3C; s32 f40; } S_1A1ED0_3982E0;
typedef struct { u8 p0[0x18]; s32 f18; u8 p1C[0x14]; s32 f30; } S_16C580_3982E0;
extern S_143950_3982E0 D_00143950_003982E0;
extern S_160C40_3982E0 D_160C40_003982E0;
extern S_227600_3982E0 D_227580_003982E0;
extern S_1A1ED0_3982E0 D_1A1ED0_003982E0;
extern S_16C580_3982E0 D_16C580_003982E0;
extern u8 D_001D551D;
extern s32 D_001D5520;
extern u8 D_001D5F08[];
extern u8 D_1FF8000[];
extern u8 D_2276C0[];
extern u8 D_227400[];
extern s32 D_1D4B64;
extern s32 D_1D4B60;
extern s32 D_1D4B90;
extern s32 D_1D4BA0;
extern void func_0012A950(void);
extern s32 func_0012D678(s32);
extern void func_00391708(void);
extern void func_003A0658(void);
extern void func_00387EF8(s32);
extern void func_0013D208();
extern void func_0012D4D8(void *);
extern void func_003A9408(void);
extern void func_00398288(void);
extern void func_003A94C0(void);
extern void func_003A9DF8(void);
extern void func_00388348(void);
extern void func_0012B300(s32);
extern void func_0012B800(s32);
extern s32 func_00124308(void *);
extern s32 func_001242B8(void);
extern void func_00121FE8(s32);
extern void func_00124920(void);
extern void func_00123B10(void);
extern void func_00124970(void);
extern s32 func_00123EA0(void);
extern void func_003983A8(void);
extern s32 func_001233F8(void);
extern s32 func_0013D290(s32, s32, void *);
extern void func_11F0A0(s32);
extern void func_0039C458_003982E0(void *);
extern void func_003A9348(u32);
extern void func_0013D2E0_003982E0(void *);
extern void func_003A0B60(u8 *, u32);
extern s32 func_00123B98(s32, s32, s32);
extern void func_003A8900(void);
extern void func_003A2FC0(void);
extern void func_0039EA68(void);
extern void func_00387648(void);
extern void func_003877A0();
extern void func_003A44D0(void);
extern void func_003A16D0(void);
extern void func_0039AAC0(void);
extern s32 func_0013A880(void);
extern s32 func_0013A8E8(void);
extern void func_0038CF58(void *, s32, s32);
extern void func_12C9A0(void *, s16, s16, s32, s32, s32, s16, s16);
extern void func_12CCC8(void *, void *);
extern s32 func_12A9F0(s32, s32);
extern void func_003826A8(void);
extern void func_00392E18(void *);

/* localdecomp:start func_00398850 */
extern void func_0038E4C8();
s32 func_00398850(s32 p) {
    func_0038E4C8(p);
    return p;
}
/* localdecomp:end func_00398850 */

extern u8 D_002FD0F0[];
extern s32 D_002FCE98[];
typedef struct { s32 a, b; } P_3936A8;
extern P_3936A8 D_002FC840[];
extern s32 D_001DA5D4;
extern void func_0038D068();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_00398878);

ASM_FUNC("asm/boot_elf/handwritten", func_00398998);
