#include "common.h"


/* localdecomp:start func_L39_005B4510 */
extern float func_L39_005B4510(float scale);
extern int func_0019D510(void);

/* from rac2-decomp's func_L02_0031E918, renamed */
float func_L39_005B4510(float scale)
{
  float r = ((float) (0xFFF & (func_0019D510() >> 16))) * (1.0f / 4096.0f);
  float new_var;
  new_var = r * r;
  new_var = 1.0f - new_var;
  return new_var * scale;
}
/* localdecomp:end func_L39_005B4510 */
