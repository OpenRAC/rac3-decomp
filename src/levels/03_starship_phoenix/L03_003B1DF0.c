#include "common.h"

/* localdecomp:start func_L03_003B1DF0 */
void func_L01_00445130(s32, s32, s32);
void func_L03_003B1DF0(s32 arg0) {
    func_L01_00445130(arg0, 5, -1);
}
/* localdecomp:end func_L03_003B1DF0 */

/* localdecomp:start func_L03_003B1E10 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { char pad[0x270]; u128_t v; char pad2[0x294-0x280]; s32 flag; } S_003B1E10;
typedef struct { char pad[0x68]; S_003B1E10 *p; } A_003B1E10;
void func_L03_003B1E10(A_003B1E10 *a, u128_t *src) {
    S_003B1E10 *o = a->p;
    if (src == 0) {
        o->flag = 0;
    } else {
        o->flag = 1;
        o->v = src[1];
    }
}
/* localdecomp:end func_L03_003B1E10 */
