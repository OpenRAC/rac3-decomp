#include "common.h"

/* localdecomp:start func_L05_003DB758 */
typedef struct { u8 p0[0x31]; u8 b31; u8 p32[0x36]; void *w68; } M_3D9760;
extern s32 func_0038CAD0(void *);
extern void func_L05_003DB5C0(M_3D9760 *);

void func_L05_003DB758(M_3D9760 *m) {
    if (func_0038CAD0(m->w68) && m->b31) {
        func_L05_003DB5C0(m);
    }
}
/* localdecomp:end func_L05_003DB758 */
