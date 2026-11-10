#include "common.h"

/* localdecomp:start func_L39_00699668 */
typedef struct S3_699668 S3_699668;
typedef struct {
    char _p0[0xB8];
    void (*fB8)(S3_699668 *arg0);
} S2_699668;
struct S3_699668 {
    char _p0[0x60];
    S2_699668 *f60;
};
typedef struct {
    char _p0[0x110];
    S3_699668 *f110;
} S1_699668;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_00699668(S1_699668 *arg0) {
    S3_699668 *o = arg0->f110;
    o->f60->fB8(o);
}
/* localdecomp:end func_L39_00699668 */
