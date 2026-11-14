#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B6548 */
extern s32 D_001D8AA8;
extern s32 func_0039C048(void);
extern void func_0039C220(s32);
void func_003B6548(void) {
    if (func_0039C048()) func_0039C220(D_001D8AA8);
}
/* localdecomp:end func_003B6548 */

extern s32 D_001D8A40[];
/* localdecomp:start func_003B6578 */
extern s32 D_001D8A40_003B6578;
void func_003B6578(void) {
    D_001D8A40_003B6578 = 4;
}
/* localdecomp:end func_003B6578 */

typedef struct { u8 b[8]; } B8_3B10A8;
typedef struct { s32 f0, f4, f8, fC; B8_3B10A8 f10; s32 f18; } E_3B10A8;
typedef struct { u8 p0[0x30]; E_3B10A8 e[11]; u8 p1[0x17C - 0x30 - 11 * 0x1C]; s32 f17C; } S_3B10A8;
typedef struct { s32 f0; u8 p[0x2E]; u8 f32; } T_3B10A8;
extern S_3B10A8 D_00142430_003B6588;
extern T_3B10A8 D_00142660_003B6588;
extern B8_3B10A8 D_001D4BE0_003B6588;
extern s32 D_001D545C_003B6588;
extern s32 D_001D5528;
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern u8 D_001D8AB8;
extern void func_0039BEF0(s32, s32);
INCLUDE_ASM("asm/nonmatchings/text", func_003B6588);

/* localdecomp:start func_003B6638 */
extern s32 D_001D8A9C;
extern u8 D_001D8AB8;
extern void func_0039BEF0(s32, s32);
extern void func_0039C300(void);
void func_003B6638(void) {
    func_0039C300();
    if (D_001D8A9C != 0) {
        func_0039BEF0(D_001D8A9C, 1);
        D_001D8AB8 = 1;
    }
}
/* localdecomp:end func_003B6638 */

/* localdecomp:start func_003B6670 */
extern s32 D_001D8A9C;
extern u8 D_001D8AB8;
extern void func_0039BEF0(s32, s32);
void func_003B6670(void) {
    if (D_001D8A9C != 0) {
        func_0039BEF0(D_001D8A9C, 1);
        D_001D8AB8 = 1;
    }
}
/* localdecomp:end func_003B6670 */

/* Candidate for func_003B66A0 (frontbin, PAL).
   Retail reads D_001D545C / D_001D5571 with lui + lw in the same register (the
   assembler's expansion), so they are read through an alias declared sized with an `.extern X, 16` hint (docs/wiki/Matching-Patterns.md: gcc leaves the access to the assembler as one macro, which the hint makes it expand with lui, as SN's single-pass Ps2EeAs did); the US draft
   needed -mno-split-addresses for the symbol form, this wording does not.
   The flag byte comes from a 64-bit value in retail (the daddu copies), and the
   comparison is done against that 64-bit value, so it stays 64-bit too. */

/* localdecomp:start func_003B66A0 */
extern s32 D_001D545C_003B66A0;
extern u8 D_001D5571_003B66A0;
__asm__(".extern D_001D545C_003B66A0, 16");
__asm__(".extern D_001D5571_003B66A0, 16");
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern u8 D_001D8AB9;
extern void func_0039E5E0(s32);
extern void func_0039BEC0(s16);
void func_003B66A0(void)
{
  unsigned long new_var;
  u8 v;
  func_0039E5E0(D_001D8A9C);
  new_var = 0;
  v = new_var;
  if (D_001D545C_003B66A0 < 2)
  {
    new_var = (D_001D5571_003B66A0 == new_var);
    v = new_var;
  }
  D_001D8AB9 = v;
  ((void (*)(s32)) func_0039BEC0)(D_001D8AB4);
}
/* localdecomp:end func_003B66A0 */
