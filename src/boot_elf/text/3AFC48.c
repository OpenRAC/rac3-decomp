#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003AFC48(s32, s32, s32 (*)(s32, s32), s32, s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF4B8.c's earlier functions (tools/port_from_us.py) */
extern u8 D_001D8798[];
extern u8 D_001D87B0[];
extern void func_00116F98(void *, s32, void *);
extern void func_003AF420(void *, s32);
extern void func_003AC590();
typedef s32 (*FN_A9EF0)();
typedef struct { FN_A9EF0 a; s32 b; } E_A9EF0;
typedef struct { u8 pad[0x24DD0]; void (*cb24DD0)(); u8 padA[0x14]; FN_A9EF0 cb24DE8; u8 padB[4]; E_A9EF0 e1[4]; E_A9EF0 e2[3]; } P_A9EF0;
extern P_A9EF0 *D_001D5C78_003AF850;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
extern s32 func_003E17A8();
extern void func_003AF760();
extern s32 D_001D5C78;
extern s32 D_001D52F0;
typedef s32 (*FN_AA0B8)();
typedef struct { s32 a; FN_AA0B8 f; } E_AA0B8;
typedef struct { u8 pad[0x24DCC]; void (*cb24DCC)(); u8 pad2[0x1C]; FN_AA0B8 cb24DEC; E_AA0B8 e1[4]; E_AA0B8 e2[3]; } P_AA0B8;
extern P_AA0B8 *D_001D5C78_003AFA18;
extern s32 D_001D9EC0;
extern s32 D_001D5B94;
typedef struct { u8 p0[0xB0]; f32 fB0; } G_AA0B8;
extern G_AA0B8 D_00225900[];
extern void func_00397FC0();
extern s32 func_003E17A8();
extern void func_003877A0();
extern void func_003AF9E0();
extern s32 D_001D5C78;
extern s32 D_0031D050[];
extern void func_00396948();
extern void func_003AF850();

extern s32 D_001DA08C;
extern s32 D_001DA090;
extern s32 D_001DA094;
extern s32 D_001DA098;
extern s32 D_001DA0A0;
extern s32 D_001DA0A4;
extern s32 D_001DA0A8;
extern s32 D_001DA0AC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA09C_003AFC48;
extern s32 D_001DA0B0_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001DA0C0[];
extern s32 D_001D4D40;
extern void func_00391880();
extern s32 func_003AFE10();
extern void func_003B0360();
extern void func_003B0188();
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AFC48);

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFE10;
extern s32 D_001D4D40;
extern volatile s32 D_1DA0CC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern void func_003A3F70(void);
extern void func_003B04E8();
extern void func_003B29D8(void *);
extern s32 func_003B16E0(u8 *, void **);
extern s32 func_003B17F8();
extern void func_003B1710(u8 *, s32);
extern s32 func_003B1750(u8 *, u8 **);
extern s32 func_00139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B1790();
extern void func_003B0400(void);
extern s32 func_003B3020(void *);
extern s32 func_003B0160_003AFE10(void);
extern void func_003B1348(s32);
extern s32 func_003B29E8(void *);
extern s32 func_003B2A68();
extern s32 func_003B2B38(void *);
extern void func_003B1398(void);
extern void func_003B0588(s32 *);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003AFE10);

/* localdecomp:start func_003B0140 */
// Declare the external game function target matching address 0x0011ECD0
extern void func_0011ECD0(s32 parameter);

// Signature must be void to eliminate the implicit return zero instruction (0x102d)
void func_003B0140(void) {
    // Calling this function with 1 triggers the 'li $a0, 1' optimization pass, 
    // which naturally slides directly into the jal branch delay slot at offset c:
    func_0011ECD0(1);
}
/* localdecomp:end func_003B0140 */

/* localdecomp:start func_003B0160 */
extern s32 func_003B0760();
extern s32 D_001DA0B8[];

void func_003B0160(void) {
    func_003B0760(D_001DA0B8[0]);
}
/* localdecomp:end func_003B0160 */
