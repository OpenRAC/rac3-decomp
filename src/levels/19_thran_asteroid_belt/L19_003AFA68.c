#include "common.h"

/* localdecomp:start func_L19_003AFA68 */
s32 func_L19_003AFA68(void *arg0, void *arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((*(u8 *)((u8 *)arg0 + 0xBC)) == 0) {
        var_v1 = (*(s32 *)((u8 *)arg1 + 0x38C)) == 0;
    }
    return var_v1;
}
/* localdecomp:end func_L19_003AFA68 */

/* localdecomp:start func_L19_003AFA88 */
extern s32 D_001DF758;
extern void *D_0021C260[];
extern void func_L01_00445BE0(s32, s32);

void func_L19_003AFA88(u8 *obj) {
    s32 id = obj[0x21];

    if (id < D_001DF758 && D_0021C260[id] != 0) {
        func_L01_00445BE0(id, 1);
        obj[0xBC] = 0;
    }
}
/* localdecomp:end func_L19_003AFA88 */
