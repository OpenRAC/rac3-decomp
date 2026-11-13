#include "common.h"

/* localdecomp:start func_L39_0060EE98 */
/* from the frontbin copy func_003E59C8 */
extern u8 D_L39_002E54E0_0060EE98[];
extern s32 D_L39_0024CC90;
extern void func_003E6670(void *);
extern void func_003E5928(void);
extern void func_00118ED0(void (*)(void));

void *func_L39_0060EE98(s32 idx) {
    u8 *q;
    s32 *w;
    s32 n, j;
    if (D_L39_0024CC90 == 0) {
        q = D_L39_002E54E0_0060EE98;
        n = 4;
        do {
            w = (s32 *)(q + 0x50);
            for (j = 0x22; j != -1; j--) *w++ = 0;
            func_003E6670(q + 0x1C4);
            func_003E6670(q + 0x21CC);
            q += 0x41DC;
            n--;
        } while (n != -1);
        D_L39_0024CC90 = 1;
        func_00118ED0(func_003E5928);
    }
    return D_L39_002E54E0_0060EE98 + idx * 0x41DC;
}
/* localdecomp:end func_L39_0060EE98 */
