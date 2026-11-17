#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003AE5F8 */

extern S_3AC810 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L13_003AE5F8(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x260) != 0) {
        S_3AC810 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L13_003AE5F8 */

/* localdecomp:start func_L13_003AE678 */
extern void func_L13_003AE5F8_003AE678(u8 *, s32);

/* from rac2-decomp's func_0012B3C0, renamed (constants adapted) */
void func_L13_003AE678(u8 *m)
{
    func_L13_003AE5F8_003AE678(m, 1);
}
/* localdecomp:end func_L13_003AE678 */
