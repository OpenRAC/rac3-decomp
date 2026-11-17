#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B8430(void);
extern void func_003B7FD8(void);


typedef struct {
    s16 f0;
    u16 f2;
    s16 f4, f6, f8, fA, fC, fE;
    s16 f10;
    u16 f12;
    s16 f14, f16, f18, f1A;
} T_3B2AF8;
extern s32 D_001D4CE8_003B7FD8;
extern u8 D_001D9FA0_003B7FD8;
extern u8 D_001D5BDC_003B7FD8;
extern u8 D_001D5BDD;
extern u16 D_001D4BC4;
extern char D_001D8B48[];
extern char D_001D8B50[];
extern char D_00280AF0[];
extern char *func_00382088(s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_003AF408(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern void func_11B2E8();
INCLUDE_ASM("asm/nonmatchings/text", func_003B7FD8);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C800);

typedef struct { u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1, b7:1, b8:1, b9:1, b10:1, rest:21; } F_003B2F50;
typedef struct { u8 pad[0x1A4]; s32 f1A4; } P_003B2F50;
extern F_003B2F50 D_001D4CEC;
extern u8 D_001D9FA0_003B8430;
extern s32 D_001D8AA8;
extern u8 D_001D5BDC_003B8430;
extern s32 D_001D4CE8_003B8430;
extern P_003B2F50 *D_001D52FC_003B8430;
extern u8 D_001D5BDD;
extern void func_0039BFD8(void);
extern void func_0039BFF0(void);
extern void func_0039BE90(void);
extern void func_0039C220(s32);
extern void func_003C0CC0(void);
extern u8 func_0039BEA8(void);
extern void func_0039C060(void);
extern s32 func_0039BC70(s32, s32);
extern void func_003A8F50(void);
extern void func_003B6510();
extern s32 D_00142438[];
INCLUDE_ASM("asm/nonmatchings/text", func_003B8430);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C880);
