#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B64A8(void);
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003B6508(s32);
extern void func_003B6438(void);


/* func_003B6438: from the US C of func_003B0F58 (rac3-uya-decomp, commit 13cf5c5), matched here with
   this file's flags. */


/* localdecomp:start func_003B6438 */
extern void func_003A92F0(s32);
extern void func_00391328(void);
extern s32 D_001D5520[];
extern void func_00391678(s32, s32, s32, s32, s32, s32);
void func_003B6438(void)
{
  unsigned int new_var;
  if (new_var)
  {
    func_003A92F0(1);
    func_00391328();
    new_var = D_001D5520[0];
  }
  else
  {
    func_003A92F0(1);
    func_00391328();
    new_var = D_001D5520[0];
  }
  if (new_var != 0)
  {
    func_00391678(0x200, 0x1A0, 0x280, 0x1C0, 0, 0);
  }
  else
  {
    func_00391678(0x200, 0x1A0, 0x200, 0x1C0, 0, 0);
  }
}
/* localdecomp:end func_003B6438 */

/* localdecomp:start func_003B64A8 */
/* First C switch: its jump table comes from gcc now (tools/migrate_jtbls.py). */
extern u8 D_00143A07[];
s32 func_003B64A8(void) {
    switch (D_00143A07[0]) {
    case 2: return 0x151;
    case 3: return 0x153;
    case 4: return 0x152;
    case 5: return 0x154;
    case 6: case 7: return 0x150;
    case 0: case 1: default: return 0x150;
    }
}
/* localdecomp:end func_003B64A8 */

/* localdecomp:start func_003B6508 */
extern s32 D_001D8A18;
void func_003B6508(s32 a) { D_001D8A18 = a; }
/* localdecomp:end func_003B6508 */

/* localdecomp:start func_003B6510 */
extern s32 func_0039C048(void);
extern void func_0013D3C0(s32);
extern s32 D_001D8A40_g;
void func_003B6510(void) {
    if (func_0039C048()) D_001D8A40_g = 5;
    else func_0013D3C0(1);
}
/* localdecomp:end func_003B6510 */
