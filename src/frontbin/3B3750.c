#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void func_003B39D8(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern void func_003A0760(u8 *, u32);
extern void func_003B3910(void);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0760(u8 *, u32);
extern s32 *func_003B42C0();
extern s32 *func_003B4380();
typedef struct { u8 pad0[0x18]; u16 h18; u8 pad1a[0x12E]; s32 f148; u8 pad14c[0x18]; s32 f164; s32 f168; u8 pad16c[8]; s32 f174; } S_003ADCB0;


/* localdecomp:start func_003B3750 */
extern void func_0039BDC0();
extern void func_003B3610();
extern void func_003B3640_003B3750();
extern s32 D_001D888C;
void func_003B3750(void)
{
  s32 (*new_var)();
  s32 *new_var2;
  s32 temp_3;
  temp_3 = D_001D888C;
  new_var2 = &D_001D888C;
  switch (*new_var2)
  {
    case 0:
      new_var = &func_003B3610;
      func_0039BDC0(new_var, 0, &func_003B3640_003B3750);

    case 1:
      func_003A0EC0(4, 1, 1, 0, 0);
 do { } while (0);
      temp_3 = *new_var2;
      temp_3 = (s32) (temp_3 + 1);
      D_001D888C = temp_3;
      return;

    case 2:
      func_003B39D8();
      break;

  }

}
/* localdecomp:end func_003B3750 */

/* localdecomp:start func_003B37E8 */
extern s32 D_001D888C;
extern s32 D_001D8898;
extern void func_0039BDC0();
extern void func_003B3610();
extern void func_003B36C8();
extern void func_003B39E0(void);
extern void func_003B3E60(void);
extern void func_003B39D8(void);
void func_003B37E8(void) {
    switch (D_001D888C) {
    case 0:
        func_0039BDC0(func_003B3610, 0, func_003B36C8);
        func_003B39E0();
        D_001D8898 = 30;
        D_001D888C++;
        break;
    case 1:
        func_003B39E0();
        { s32 t = D_001D8898; if (t > 0) { t--; D_001D8898 = t; } D_001D8898 = t; if (t == 0) func_003B3E60(); }
        break;
    case 2:
        func_003B39D8();
        break;
    }
}
/* localdecomp:end func_003B37E8 */

/* localdecomp:start func_003B38A8 */
extern s32 D_001D888C;
extern void func_003B39D8(void);
void func_003B38A8(void) {
    switch (D_001D888C) {
    case 0: D_001D888C = 1; break;
    case 1: D_001D888C = 2; break;
    case 2: func_003B39D8(); break;
    }
}
/* localdecomp:end func_003B38A8 */

/* localdecomp:start func_003B3910 */
__asm__(".extern D_001D8888, 4");
extern s32 D_001D8888;
extern void func_003B34A0(void);
extern void func_003B3410(void);
extern void func_003B3750(void);
extern void func_003B3530(void);
extern void func_003B37E8_003B3910(void);
extern void func_003B38A8(void);
extern void func_003B3378_003B3910(void);
extern void func_003B32D8_003B3910(void);
extern void func_003A0F98(s32, s32);
void func_003B3910(void) {
    switch (D_001D8888) {
    case 1:
        func_003B34A0();
        break;
    case 2:
        func_003B3410();
        break;
    case 3:
        func_003B3750();
        break;
    case 7:
        func_003B3530();
        break;
    case 8:
        func_003B37E8_003B3910();
        break;
    case 5:
        func_003B38A8();
        break;
    case 4:
        func_003B3378_003B3910();
        break;
    case 6:
        func_003B32D8_003B3910();
        break;
    case 0:
    default:
        func_003A0F98(0, 0);
        break;
    }
}
/* localdecomp:end func_003B3910 */

/* localdecomp:start func_003B39D8 */
extern s32 D_001D8888;
void func_003B39D8(void) {
    D_001D8888 = 0;
}
/* localdecomp:end func_003B39D8 */

INCLUDE_ASM("asm/nonmatchings/text", func_003B39E0);
INCLUDE_RODATA("asm/nonmatchings/text/rodata", jtbl_0031C660);
