#include "common.h"

typedef struct { u8 pad[0x5C0]; } S_00461818;

/* localdecomp:start func_L01_00461818 */
extern S_00461818 D_L01_001CD0C0[];
extern void func_003A3740(S_00461818 *);

void func_L01_00461818(void) {
    S_00461818 *p = D_L01_001CD0C0;
    S_00461818 *end = D_L01_001CD0C0 + 8;
    do {
        func_003A3740(p);
        p++;
    } while ((s32)p < (s32)end);
}
/* localdecomp:end func_L01_00461818 */
