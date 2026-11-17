#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B39D8(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;
extern S_003ADCB0 D_00142430;


/* func_003B3378 (US draft rac3-uya-decomp func_003ADDD0).
   The byte store to the global at 0x001D9FA0: gcc splits an unsized global's
   address into a register of its own (lui $v1 / sb ...,%lo(sym)($v1)), while
   retail has the assembler's expansion, in $at with the low half folded into
   the store; so it goes through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did). */

/* localdecomp:start func_003B3378 */
extern s8 D_001D9FA0_003B3378;
__asm__(".extern D_001D9FA0_003B3378, 16");
extern s32 D_001D888C;
void func_003B3378(void) {
    s32 temp_3;

    temp_3 = D_001D888C;
    switch (temp_3) {                               /* irregular */
    case 0:
        func_0039BE70();
        D_001D9FA0_003B3378 = 1;
        /* fallthrough */
    case 1:
        func_003A0EC0(4, 1, 1, 0, 0);
        D_001D888C = (s32) (D_001D888C + 1);
        return;
    case 2:
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B3378 */

/* localdecomp:start func_003B3410 */
extern s32 D_001D888C;
extern void func_0039BD08();
extern void func_003B3230();
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003B39D8(void);
void func_003B3410(void) {
    switch (D_001D888C) {
    case 0:
        func_0039BD08(func_003B3230, 0, 0);
    case 1:
        func_003A0EC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B3410 */

/* localdecomp:start func_003B34A0 */
extern s32 D_001D888C;
extern void func_0039BD90();
extern void func_003B3230();
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003B39D8(void);
void func_003B34A0(void) {
    switch (D_001D888C) {
    case 0:
        func_0039BD90(func_003B3230, 0, 0);
    case 1:
        func_003A0EC0(4, 1, 1, 0, 0);
        D_001D888C++;
        break;
    case 2:
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B34A0 */

extern void func_0039BD08();
extern void func_003B3E60(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
INCLUDE_ASM("asm/nonmatchings/text", func_003B3530);

/* localdecomp:start func_003B3610 */
void func_003B3610(void) {
    u8 *b = (u8 *)&D_00142430;
    s32 t = *(s32 *)(b + 0x164);
    *(s16 *)(b + 0x18) = 0;
    *(s32 *)(b + 0x148) = 0;
    if (t < 0) {
        *(s32 *)(b + 0x168) = 0;
        *(s32 *)(b + 0x164) = 0xD;
    }
}
/* localdecomp:end func_003B3610 */
