#include "common.h"

/* localdecomp:start func_L39_00530DE0 */
typedef int Q_00530798 __attribute__((mode(TI)));

extern void func_003C2EC0();

typedef struct {
    char pad[48];
    Q_00530798 q;
} S_00530798;

void func_L39_00530DE0(int a0, Q_00530798 *a1) {
    S_00530798 s;
    func_003C2EC0(a0, 14, &s);
    *a1 = s.q;
}
/* localdecomp:end func_L39_00530DE0 */
