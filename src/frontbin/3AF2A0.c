#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void func_003AF660(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern f32 func_003AF2A0(f32, f32, f32, f32, f32);
/* --- end of declarations from other files --- */

extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);
INCLUDE_ASM("asm/nonmatchings/text", func_003AF2A0);

LINKER_REMNANT("asm/remnants", func_003AF388);

extern void func_003AF068(void *, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003AF3A8);

extern void func_003AC1D8();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF408);

typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF498;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
extern s32 func_003E13F0();
extern void func_003AF3A8();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF498);

extern s32 D_001D5C78;
extern s32 D_001D52F0;
INCLUDE_ASM("asm/nonmatchings/text", func_003AF628);

typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AF660;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225900[];
extern void func_00397BE0();
extern s32 func_003E13F0();
extern void func_003873C0();
extern void func_003AF628();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF660);

LINKER_REMNANT("asm/remnants", func_003AF820);

extern s32 D_001D5C78;
extern s32 D_0031D050[];
extern void func_00396568();
extern void func_003AF498();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF838);
