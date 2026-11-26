#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B3CC8(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B3D90(void);
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
extern s32 D_001D888C;
extern s8 D_001D9FA0[];
extern s32 D_001D888C;
extern void func_0039C0E8();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern s32 D_001D888C;
extern void func_0039C170();
extern void func_003B35E8();
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_0039C0E8();
extern void func_003B4218(void);
extern void func_0013D3C0(s32);
extern s32 D_001D888C;
extern s32 D_001D8894;
extern s32 D_001D4CE8;
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE098;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 func_003A12C0(s32, s32, s32, s32, u8 *);
extern void func_003A43E0(void);
extern void func_0013BFE0(s32);
extern void func_003A9308(void);
extern s32 D_001425AC[];
extern s32 D_00143958[];
extern s32 D_001D545C_gp_003AE120;
extern s32 D_001D545C;
extern u8 D_001D5571;
extern s32 D_001D5B74;
extern s32 D_001D9D04;
extern void func_003A43E0(void);
extern s32 func_003A2B50(s32);
extern void func_0013BFE0(s32);
extern void func_003A9308(void);

/* localdecomp:start func_003B3B08 */
extern void func_0039C1A0();
extern void func_003B39C8();
extern void func_003B39F8();
extern s32 D_001D888C;
void func_003B3B08(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D888C;
  new_var2 = &D_001D888C;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_003B39C8;
      func_0039C1A0(new_var, 0, &func_003B39F8);

    case 1:
      func_003A12C0(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D888C = temp_3;
      return;

    case 2:
      func_003B3D90();
      break;

  }

}
/* localdecomp:end func_003B3B08 */

/* PAL draft of func_003B3BA0 (from the US draft of rac3-uya-decomp func_003B3A00, commit 13cf5c5),
   names moved to PAL addresses where known. The US call target func_003B3BF8 is func_003B3D98 in
   PAL (src/boot_elf/text/3B3B08.c has INCLUDE_ASM for it). */


/* localdecomp:start func_003B3BA0 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_0039C1A0();
extern void func_003B39C8();
extern void func_003B3A80();
extern void func_003B3D98(void);
extern void func_003B4218(void);
extern void func_003B3D90(void);
void func_003B3BA0(void) {
    switch (D_001D888C) {
    case 0:
        func_0039C1A0(func_003B39C8, 0, func_003B3A80);
        func_003B3D98();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003B3D98();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003B4218(); }
        break;
    case 2:
        func_003B3D90();
        break;
    }
}
/* localdecomp:end func_003B3BA0 */

/* localdecomp:start func_003B3C60 */
extern s32 D_001D888C;
extern void func_003B3D90(void);
void func_003B3C60(void) {
    switch (D_001D888C) {
    case 0: D_001D888C = 1; break;
    case 1: D_001D888C = 2; break;
    case 2: func_003B3D90(); break;
    }
}
/* localdecomp:end func_003B3C60 */

/* localdecomp:start func_003B3CC8 */
__asm__(".extern D_001D8888, 4");
extern s32 D_001D8888;
extern void func_003B3858(void);
extern void func_003B37C8(void);
extern void func_003B3B08(void);
extern void func_003B38E8(void);
extern void func_003B3BA0_003B3CC8(void);
extern void func_003B3C60(void);
extern void func_003B3730(void);
extern void func_003B3690(void);
extern void func_003A1398(s32, s32);
void func_003B3CC8(void) {
    switch (D_001D8888) {
    case 1:
        func_003B3858();
        break;
    case 2:
        func_003B37C8();
        break;
    case 3:
        func_003B3B08();
        break;
    case 7:
        func_003B38E8();
        break;
    case 8:
        func_003B3BA0_003B3CC8();
        break;
    case 5:
        func_003B3C60();
        break;
    case 4:
        func_003B3730();
        break;
    case 6:
        func_003B3690();
        break;
    case 0:
    default:
        func_003A1398(0, 0);
        break;
    }
}
/* localdecomp:end func_003B3CC8 */

/* localdecomp:start func_003B3D90 */
extern s32 D_001D8888;
void func_003B3D90(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003B3D90 */
