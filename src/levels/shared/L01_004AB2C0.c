#include "common.h"

/* localdecomp:start func_L01_004AB2C0 */
extern int func_00133350(int, int, int, int, int, int, int, int, int, int,
                         void (*)(int, long), unsigned long);
extern void func_001325E8(int, void (*)(int, long), unsigned long);
extern void func_001336D0(void (*)(s32));

/* from rac2-decomp's func_002B6770, renamed */
void func_L01_004AB2C0(int arg0, long arg1) {
    int *p = (int *)(int)arg1;
    if (p != 0) {
        *p = arg0;
    }
}
/* localdecomp:end func_L01_004AB2C0 */
