#include "common.h"

/* localdecomp:start func_L39_005C0AC8 */
extern s16 D_002257E0[];
extern void func_L39_005C0100(void);
extern void func_00194760(void);
extern void func_00193680(void);
extern void func_00194758(void);
extern void func_L39_0058F078(s32);

/* Runs a fixed sequence of four calls (func_L39_005C0100 and three SDK-range functions), looping
 * with func_L39_0058F078(10000) while the status in D_002257E0[2] is nonzero if arg0 is set;
 * returns that status. */
s16 func_L39_005C0AC8(s32 arg0) {
    s16 *q;
    if (arg0 != 0) {
        while (1) {
            func_L39_005C0100();
            func_00194760();
            func_00193680();
            func_00194758();
            if (D_002257E0[2] == 0) {
                break;
            }
            func_L39_0058F078(10000);
            if (D_002257E0[2] == 0) {
                break;
            }
        }
    } else {
        func_L39_005C0100();
        func_00194760();
        func_00193680();
        func_00194758();
    }
    q = D_002257E0;
    return q[2];
}
/* localdecomp:end func_L39_005C0AC8 */
