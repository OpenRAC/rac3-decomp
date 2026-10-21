#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void func_003AF660(void);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003AF890(s32, s32, s32 (*)(s32, s32), s32, s32);
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

INCLUDE_ASM("asm/nonmatchings/text", func_003AF878);

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AF890;
extern s32 D_001DA09C_003AF890;
extern s32 D_001DA0B0_003AF890;
extern s32 D_001DA0B4_003AF890;
extern s32 D_001DA0B8_003AF890;
extern s32 D_001DA0C0[];
extern s32 D_001D4D40;
extern void func_003914A0();
extern s32 func_003AFA58();
extern void func_003AFFA8();
extern void func_003AFDD0();
INCLUDE_ASM("asm/nonmatchings/text", func_003AF890);

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFA58;
extern s32 D_001D4D40;
extern volatile s32 D_001DA0CC;
extern s32 D_001DA088_003AF890;
extern s32 D_001DA0B4_003AF890;
extern s32 D_001DA0B8_003AF890;
extern void func_003A3B70(void);
extern void func_003B0130();
extern void func_003B2620(void *);
extern s32 func_003B1328(u8 *, void **);
extern s32 func_003B1440();
extern void func_003B1358(u8 *, s32);
extern s32 func_003B1398(u8 *, u8 **);
extern s32 func_139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B13D8();
extern void func_003B0048(void);
extern s32 func_003B2C68(void *);
extern s32 func_003AFDA8_003AFA58(void);
extern void func_003B0F90(s32);
extern s32 func_003B2630(void *);
extern s32 func_003B26B0();
extern s32 func_003B2780(void *);
extern void func_003B0FE0(void);
extern void func_003B01D0(s32 *);
INCLUDE_ASM("asm/nonmatchings/text", func_003AFA58);

/* localdecomp:start func_003AFD88 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003AFD88(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003AFD88 */

/* localdecomp:start func_003AFDA8 */
extern s32 func_003B03A8();
extern s32 D_001DA0B8[];

void func_003AFDA8(void) {
    func_003B03A8(D_001DA0B8[0]);
}
/* localdecomp:end func_003AFDA8 */

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA088_003AFDD0;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA09C_003AFDD0;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA0B0_003AFDD0;
extern s32 D_001DA0B4_003AFDD0;
extern s32 D_001DA0B8_003AFDD0;
extern s32 D_001DA0C8_003AFDD0;
extern u8 D_001DC8B0[1];
extern void func_003B1308();
extern void func_135B50();
extern s32 func_003B2478(s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003B0070_003AFDD0();
extern void func_003B2580_003AFDD0();
extern void func_003B0FF0_003AFDD0();
extern void func_003B1108_003AFDD0();
extern void func_003B2BF8();
extern void func_003B27C8();
extern s32 func_11EC20();
extern void func_11FD40();
extern void func_003B1400_003AFDD0();
extern void func_12D4D8();
extern void func_003B0D60();
extern s32 func_11EB30();
extern void func_003B0F50();
extern void func_11F9A8();
typedef struct { s32 f0; void *f4; s32 f8; s32 fC; void *f10; s32 f14; s32 f18; s32 f1C; s32 f20; s32 pad[3]; } S_3AA828;
INCLUDE_ASM("asm/nonmatchings/text", func_003AFDD0);

typedef struct { u8 pad[0xB0]; s32 wB0; } S_AAA00;
extern void *D_001DA09C;
extern void *D_001DA088;
extern void *D_001DA0C8;
extern S_AAA00 *D_001DA0B4;
extern void *D_001DA0B8_003AFFA8;
extern void *D_001DA0B0;
extern u8 D_0013D208[];
extern s32 func_003B1320();
extern s32 func_003B2C50();
extern void func_11EC70(void *);
extern void func_11EC30(void *);
extern void func_11EB50(s32, s32);
extern void func_12D4D8(u8 *);
extern s32 func_003B25E8();
extern s32 func_003B0108();
extern s32 func_003B1418();
INCLUDE_ASM("asm/nonmatchings/text", func_003AFFA8);

/* localdecomp:start func_003B0040 */
s32 func_003B0040(void) {
}
/* localdecomp:end func_003B0040 */
