#include "common.h"

/* localdecomp:start func_L39_0060FDB0 */
extern u8 D_L39_0024CD10[8];
extern s32 D_L39_0024CD48;
extern void func_003F2208(void *);
extern void func_00118ED0(void *);
extern void func_003E68C0(void);

void *func_L39_0060FDB0(s32 n)
{
    s32 i;
    if (D_L39_0024CD48 == 0) {
        u8 *p = D_L39_0024CD10;
        for (i = 1; i != -1; i--) {
            func_003F2208(p);
            p += 0x1C;
        }
        D_L39_0024CD48 = 1;
        func_00118ED0(func_003E68C0);
    }
    return D_L39_0024CD10 + n * 0x1C;
}
/* localdecomp:end func_L39_0060FDB0 */
