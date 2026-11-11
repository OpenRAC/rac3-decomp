#include "common.h"

/* localdecomp:start func_L39_00519388 */
typedef struct S_00519388 S_00519388;
struct S_00519388 {
    S_00519388 *next;
    s32 _p4;
    s32 key;
};
extern S_00519388 *D_0046F550 __attribute__((section(".data")));

S_00519388 *func_L39_00519388(s32 arg0) {
    S_00519388 *p;
    for (p = D_0046F550; p != 0; p = p->next) {
        if (arg0 == p->key) {
            return p;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00519388 */
