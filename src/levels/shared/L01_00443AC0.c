#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00443AC0 */
extern float func_L01_00443AC0(float scale);
extern int func_0013D3E0(void);

/* from rac2-decomp's func_L02_0031E918, renamed */
float func_L01_00443AC0(float scale)
{
  float r = ((float) (0xFFF & (func_0013D3E0() >> 16))) * (1.0f / 4096.0f);
  float new_var;
  new_var = r * r;
  new_var = 1.0f - new_var;
  return new_var * scale;
}
/* localdecomp:end func_L01_00443AC0 */

/* localdecomp:start func_L01_00443B18 */
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00443B18(f32 *arg0, f32 arg1) {
    f32 a = func_00382538();
    f32 b = func_L01_00443AC0(arg1);
    qzero(arg0);
    arg0[0] = func_0038D098(a) * b;
    arg0[1] = func_0038D0B0(a) * b;
}
/* localdecomp:end func_L01_00443B18 */

/* localdecomp:start func_L01_00443B88 */
extern f32 func_003824E0(void);
extern f32 func_00382538(void);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);

void func_L01_00443B88(f32 *out) {
    f32 r;
    f32 a;
    f32 b;

    r = func_003824E0();
    a = func_00382538();
    b = func_00382538();
    out[0] = func_0038D098(a) * func_0038D0B0(b) * r;
    out[1] = func_0038D0B0(a) * func_0038D0B0(b) * r;
    out[2] = func_0038D098(b) * r;
}
/* localdecomp:end func_L01_00443B88 */
