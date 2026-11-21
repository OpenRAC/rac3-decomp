#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 3B3750.c's earlier functions */
extern void func_003A0760(u8 *, u32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_003A0760(u8 *, u32);

/* localdecomp:start func_003B4470 */
s32 func_003B4470(s32 *p) {
    *p = 8;
    return 1;
}
/* localdecomp:end func_003B4470 */

/* localdecomp:start func_003B4480 */
extern s32 func_003A2598(s32, s32, s32);
extern s16 D_001CCFD4[];
s32 func_003B4480(void *arg0, s32 arg1)
{
  s32 temp_3;
  s32 temp_4;
  s32 temp_6;
  u8 *new_var2;
  char var_7;
  int new_var;
  void *temp_6_2;
  temp_6 = *((s32 *) (((u8 *) arg0) + 0x14));
  var_7 = 0;
  if (temp_6 != 0)
  {
    temp_4 = *((s32 *) (((u8 *) arg0) + 0xC));
    if (temp_4 != 0)
    {
      temp_3 = *((s32 *) (((u8 *) arg0) + 0));
      if (((temp_3 ^ 4) != 0) && ((temp_3 ^ 8) != 0))
      {
        if (D_001CCFD4[0] == 0)
        {
          new_var = 8;
 do { temp_6_2 = (arg1 * new_var) + temp_6; if ((*((s32 *) (((u8 *) temp_6_2) + 4))) > 0) { new_var2 = (u8 *) arg0; *((s32 *) (new_var2 + 0x1C)) = arg1; ((s32 (*)(s32, s32, s32, s32))func_003A2598)(temp_4, (*((s32 *) (((u8 *) temp_6_2) + 0))) + (*((s32 *) (((u8 *) arg0) + 0x18))), *((s32 *) (((u8 *) temp_6_2) + 4)), 0); var_7 = 1; *((s32 *) (((u8 *) arg0) + 0)) = 4; } } while (0);
        }
        else
        {
          *((s32 *) (((u8 *) arg0) + 0x1C)) = arg1;
          *((s32 *) (((u8 *) arg0) + 0)) = 0x10;
          var_7 = 1;
        }
      }
    }
  }
  return var_7;
}
/* localdecomp:end func_003B4480 */

typedef struct { s32 type; s8 pad4[8]; s32 fC; s32 f10; s32 f14; s32 f18; } S_3AEF70;
/* localdecomp:start func_003B4528 */
s32 func_003B4528(S_3AEF70 *a, s32 b, s32 c, s32 d, s32 e) {
    s32 result = 0;
    s32 t = a->type;
    if ((t ^ 2) == 0 || (t ^ 1) == 0 || (t ^ 8) == 0) {
        a->fC = b;
        a->f10 = c;
        a->f18 = d;
        a->f14 = e;
        result = 1;
    }
    return result;
}
/* localdecomp:end func_003B4528 */

/* localdecomp:start func_003B4568 */
s32 func_003B4568(s32 *arg0) {
    s32 val = arg0[4]; // offset 0x10 (4 * 4 bytes)
    
    if (val != 0) {
        return val;
    }
    
    return arg0[3]; // offset 0x0C (3 * 4 bytes)
}
/* localdecomp:end func_003B4568 */

/* localdecomp:start func_003B4588 */
s32 func_003B4588(s32 *p) {
    s32 s = p[0];
    if ((s ^ 0x10) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 *e = (s32 *)(p[7] * 8 + p[5]);
            func_003A2598(p[3], e[0] + p[6], e[1]);
            p[0] = 4;
        }
    } else if ((s ^ 8) == 0) {
        if (D_001CCFD4[0] == 0) {
            p[0] = 1;
        }
    } else if ((s ^ 4) == 0) {
        if (D_001CCFD4[0] == 0) {
            s32 v = 2;
            if (p[4] != 0) {
                func_003A0760((u8 *)p[3], p[4]);
            }
            p[0] = v;
        }
    }
    return 1;
}
/* localdecomp:end func_003B4588 */
