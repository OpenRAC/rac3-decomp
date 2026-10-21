#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
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
   assembler's expansion), so they are read through an alias declared sized and again with a section attribute (gcc leaves the access to the assembler as one macro, and without gcc's `.extern` size hint the assembler does not know the global is small and expands it with lui, as SN's single-pass Ps2EeAs did); the US draft
   needed -mno-split-addresses for the symbol form, this wording does not.
   The flag byte comes from a 64-bit value in retail (the daddu copies), and the
   comparison is done against that 64-bit value, so it stays 64-bit too. */

/* localdecomp:start func_003B66A0 */
extern s32 D_001D545C_003B66A0;
extern u8 D_001D5571_003B66A0;
extern s32 D_001D545C_003B66A0 __attribute__((section(".bss")));
extern u8 D_001D5571_003B66A0 __attribute__((section(".bss")));
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
extern u8 D_001D5638_003B67A8_lui __attribute__((section(".bss")));
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
       sized and again with a section attribute (no `.extern` size hint for the
       assembler) keeps the lui + offset form (as in func_003B66A0's D_001D5571). */
    D_001D5638_003B67A8_lui = 1;
    D_0022CF90[0] = 0;
}
/* localdecomp:end func_003B67A8 */

/* localdecomp:start func_003B6848 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *); // Ensure this prototype matches exactly
extern void func_0039BD08(void (*)(), s32, void (*)());
extern void func_003B6638();
extern void func_003B6510();

void func_003B6848(void) {
    func_003B3228((void *)(s32)D_001D8A9C);
    
    // Explicit sequence point
    *(volatile s32 *)&D_001D8A40_g = 1; 
    
    func_0039BD08(func_003B6638, D_001D8AB4, func_003B6510);
}
/* localdecomp:end func_003B6848 */

/* localdecomp:start func_003B6888 */
extern void func_0039BE70(void);
extern s32 D_001D8A40_g;
void func_003B6888(void) {
    func_0039BE70();
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6888 */

/* localdecomp:start func_003B68B0 */
extern s32 func_0039BC70(s32, void *);
extern void func_003B6578();
extern s32 D_001D8A40_g;
s32 func_003B68B0(void) {
    s32 r = func_0039BC70(0, func_003B6578);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B68B0 */

/* localdecomp:start func_003B68E0 */
extern s32 func_0039BC70(s32, void *);
extern void func_003B6578();
extern s32 D_001D8A40_g;
s32 func_003B68E0(void) {
    s32 r = func_0039BC70(0, func_003B6578);
    D_001D8A40_g = 1;
    return r;
}
/* localdecomp:end func_003B68E0 */

extern unsigned char D_001D5BDC;
extern int D_001D8AB4;
extern int D_001D8A40_g;
extern void func_0039BDC0(int, int, int);
extern void func_003B66A0(void);
extern void func_003B66F0(void);
extern void func_003B67A8(void);
INCLUDE_ASM("asm/nonmatchings/text", func_003B6910);

/* localdecomp:start func_003B6970 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *);
extern void func_0039BD08();
extern void func_003B6588();
void func_003B6970(void) {
    func_003B3228((void *)D_001D8A9C);
    func_0039BD08(func_003B6588, D_001D8AB4, 0);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B6970 */

/* localdecomp:start func_003B69B0 */
extern s32 D_001D8A9C;
extern s32 D_001D8AB4;
extern s32 D_001D8A40_g;
extern void func_003B3228(void *);
extern void func_003B8A38(s32);
extern void func_0039BD08();
extern void func_003B6670();
extern void func_003B6548();
void func_003B69B0(void) {
    func_003B3228((void *)D_001D8A9C);
    func_003B8A38(D_001D8AB4);
    func_0039BD08(func_003B6670, D_001D8AB4, func_003B6548);
    D_001D8A40_g = 1;
}
/* localdecomp:end func_003B69B0 */
