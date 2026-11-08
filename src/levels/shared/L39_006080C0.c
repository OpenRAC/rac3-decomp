#include "common.h"

/* localdecomp:start func_L39_006080C0 */
typedef u32 _DWORD;
int func_00194CC8(unsigned int arg0, int arg1, int arg2, unsigned int arg3, int arg4, unsigned int arg5);

/* from rac4-decomp's func_004EF6D0, renamed, constants adapted */
int func_L39_006080C0(_DWORD *a1, int a2, int a3, int a4)
{
  int v6;
  a1[13] = a2;
  a1[16] = a3;
  *a1 = 0;
  a1[1] = a4;
  a1[12] = 0;
  a1[14] = 0;
  a1[15] = 0;
  a1[17] = 0;
  a1[20] = 0;
  a1[22] = 0;
  a1[23] = 0;
  if (a4 == 2)
  {
    a1[19] = 24576;
  }
  else
    if (a4 == 3)
  {
    a1[19] = 1024;
  }
  else
  {
    a1[19] = 49152;
  }
  v6 = func_00194CC8((int) a1[19], 4096, 1024, 0, 2, (int) a1[1]);
  a1[18] = v6;
  if (v6 < 0)
    return 0;
  return 1;
}
/* localdecomp:end func_L39_006080C0 */

/* localdecomp:start func_L39_00608158 */
void func_00194D40();

s32 func_L39_00608158(void) {
    func_00194D40();
    return 1;
}
/* localdecomp:end func_L39_00608158 */
