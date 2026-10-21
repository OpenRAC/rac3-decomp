#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3B3068.c's earlier functions (tools/port_from_us.py) */
extern void *func_003E6FC0();
extern void func_003E6DB0(void *);
extern u8 D_001DA938[];
extern u8 D_001D8880;
extern void func_003E86B0();
extern void *func_003E6FC0();
extern void func_003E6E18();
extern s32 func_003E68D0();
extern s32 func_003E72D0();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6E50();
extern u8 D_001DA938[];
extern void *func_003E6FC0();
extern void func_003E6EE0(void *);
extern void func_003AA060();
extern void func_003E71C8_003B3510();
extern void func_003E6F70();
extern void *func_003E6FC0();
extern s32 D_001D9EC0;
extern s32 D_001D9BDC;
extern u8 D_001D8881;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003ADBB0;
extern S_003ADBB0 D_001DA938_003B3510;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern s32 D_001D8888;
extern s32 D_001D888C;
extern void *D_001D8890;
extern void *D_001D8890;
extern void func_003B3610(void *, s32);
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;
extern u8 D_001D4BE0;
extern u8 D_001D4BE0_b_003ADCB0;
extern void func_0012BE28();
extern void func_0013AD58();
extern void func_0039E9C0();
extern s32 D_001D888C;
extern void (*D_001DA100)();
extern void func_003A1398(s32, s32);
extern void func_003B3D90(void);
extern s32 D_001D888C;
extern s8 D_001D9FA0[];

/* localdecomp:start func_003B37C8 */
extern s32 D_001D888C;
extern void func_0039C0E8();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_003B3D90(void);
void func_003B37C8(void) {
    switch (D_001D888C) {
    case 0:
        func_0039C0E8(func_003B35E8, 0, 0);
    case 1:
        func_003A12C0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B37C8 */

/* localdecomp:start func_003B3858 */
extern s32 D_001D888C;
extern void func_0039C170();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_003B3D90(void);
void func_003B3858(void) {
    switch (D_001D888C) {
    case 0:
        func_0039C170(func_003B35E8, 0, 0);
    case 1:
        func_003A12C0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B3858 */

extern void func_0039C0E8();
extern void func_003B3D90(void);
extern void func_003B4218(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B38E8);

/* localdecomp:start func_003B39C8 */
void func_003B39C8(void) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = 0;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003B39C8 */
