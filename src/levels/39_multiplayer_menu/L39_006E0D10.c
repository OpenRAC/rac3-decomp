#include "common.h"

/* localdecomp:start func_L39_006E0D10 */
__asm__(".extern D_L39_0024A0BC, 16");
extern void *D_L39_0024A0BC;
double func_001321C8(f32);
double func_00136CB0(double);
double func_001319E8(double, double);
void func_00131ED8(double);

void func_L39_006E0D10(f32 arg0) {
    f32 t = ((f32 (*)(f32))D_L39_0024A0BC)(arg0);
    double v = func_001321C8(t * 3.0f * (arg0 * arg0) / 9.869605f + 1.0f);
    v = func_00136CB0(v);
    v = func_001319E8(1.0, v);
    func_00131ED8(v);
}
/* localdecomp:end func_L39_006E0D10 */
