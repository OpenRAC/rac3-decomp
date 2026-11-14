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


extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003B66F0;
extern s32 D_001D545C_003B66F0;
extern u8 D_001D5571_003B66F0;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern u8 D_001D5638;
extern s32 D_0022CF90[];
extern s32 D_001D8A9C;
extern s32 D_001D8A40_003B66F0;
extern s32 func_0039C048();
extern void func_0039C220();
extern void func_003A3FE0(void);
extern s32 func_003A2750(s32);
extern void func_0013BFE0(s32);
extern void func_003A8F50(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B66F0);

/* func_003B67A8: from the US C of func_003B12C8 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003B67A8 */
extern u8 D_001D5638_003B67A8_lui;
__asm__(".extern D_001D5638_003B67A8_lui, 16");
__asm__(".extern D_001D8A9C, 4");
__asm__(".extern D_001D8A40_003B67A8, 4");
__asm__(".extern D_001D8AB9, 1");
__asm__(".extern D_001D545C_003B67A8, 4");
extern s32 func_0039C048(void);
extern void func_0039C220(s32);
extern void func_003BB0D8(void);
extern void func_003BB0E8(s32);
extern void func_003A3FE0(void);
extern void func_0013BFE0(s32);
extern s32 D_001D8A9C;
extern s32 D_001D8A40_003B67A8;
extern u8 D_001D8AB9;
extern s32 D_001D545C_003B67A8;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s8 D_001D5638_003B67A8;
extern s32 D_0022CF90[];
void func_003B67A8(void) {
    if (func_0039C048() != 0) {
        func_0039C220(D_001D8A9C);
        D_001D8A40_003B67A8 = 5;
        return;
    }
    D_001425AC[0] = 1;
    func_003A3FE0();
    ((s32 (*)(s32))func_003A2750)(1);
    func_0013BFE0(D_00143958[0] == 0);
    if (D_001D8AB9 != 0) {
        func_003BB0D8();
    } else {
        func_003BB0E8(D_001D545C_003B67A8);
    }
    D_001D8A40_003B67A8 = 6;
    /* Retail reaches 0x001D5638 with a lui/lo pair, not through $gp: a sized
       global is small data and would be stored through $gp. An alias declared
       sized with an `.extern X, 16` hint
       (docs/wiki/Matching-Patterns.md) keeps the lui + offset form (as in func_003B66A0's D_001D5571). */
    D_001D5638_003B67A8_lui = 1;
    D_0022CF90[0] = 0;
}
/* localdecomp:end func_003B67A8 */
