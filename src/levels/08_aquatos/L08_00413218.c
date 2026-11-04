#include "common.h"

/* localdecomp:start func_L08_00413218 */
extern int func_L01_004308B0(int);
extern struct { int a, b, c; char *p; } D_L08_001F2020 __attribute__((section(".data")));

/* from rac2-decomp's func_L00_00308408, renamed */
void func_L08_00413218(int x, int y0, int w, int h) {
    int y = y0;
    for (; y < y0 + h; y++) {
        int rowbase = (y >> 5) << 4;
        int i;
        for (i = x; i < x + w; i++) {
            unsigned char *p = (unsigned char *)D_L08_001F2020.p + (y << 6) + i / 8;
            if (*p != 0) {
                int bit = 1 << (i & 7);
                if (*p & bit) {
                    func_L01_004308B0((i >> 5) + rowbase);
                    *p = *p & ~bit;
                }
            }
        }
    }
}
/* localdecomp:end func_L08_00413218 */
