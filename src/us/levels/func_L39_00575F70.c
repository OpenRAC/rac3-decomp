#include "common.h"

/* localdecomp:start func_L39_00575F70 */
extern s32 D_001A5990[];
extern s8 D_L39_0025D021[];
extern s32 D_L39_0024BAC8;
extern void func_L01_0045E370(void);
extern void func_L39_005F9EF0(void);
extern void func_L39_00577308(void);
extern s32 func_00139E08(s32);

s32 func_L39_00575F70(void) {
    s32 limit = 9600;
    s32 r;

    if (D_001A5990[0] != 0) {
        limit = 11520;
    }
    if (limit < *(volatile s32 *)0x10000800 && D_L39_0025D021[0] == 0) {
        func_L01_0045E370();
        func_L39_005F9EF0();
    }
    func_L39_00577308();
    r = func_00139E08(0);
    D_L39_0024BAC8++;
    return r;
}
/* localdecomp:end func_L39_00575F70 */
