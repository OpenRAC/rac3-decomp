#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003AC0F0 */
extern void func_00121760();
extern void func_003AA070();
extern char D_001D8230[];
extern char D_001D8270[];
extern char D_001D82A0[];
extern s32 D_001D5C84;
void func_003AC0F0(s32 *arg0)
{
  s32 *p;
  s32 n;
  s32 *new_var;
  new_var = arg0 + 7;
  func_00121760(D_001D8230);
  p = new_var;
  n = arg0[6];
  func_00121760(D_001D8270, p, n);
  if (n > 0)
  {
    do
    {
      p[1] += (s32) arg0;
      func_003AA070(p[1]);
      p += 2;
      D_001D5C84 = D_001D5C84 + 1;
      n--;
    }
    while (n != 0);
  }
  func_00121760(D_001D82A0);
}
/* localdecomp:end func_003AC0F0 */
