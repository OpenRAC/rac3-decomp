#include "common.h"

/* localdecomp:start func_L39_005C2960 */
typedef struct S_005C2960 {
    s16 pad0;
    s16 pad2;
    s16 f4;
    u8 f6;
} S_005C2960;
extern S_005C2960 D_00225660[];
extern s32 func_00194AF8(void);

void func_L39_005C2960(void)
{
    S_005C2960 *s = D_00225660;
    if (s->f4 != 0) {
        func_00194AF8();
        s->f6 = 1;
    }
}
/* localdecomp:end func_L39_005C2960 */
