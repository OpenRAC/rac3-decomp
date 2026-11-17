#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

/* localdecomp:start func_L12_003E6160 */

extern S_3E40A0 *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L12_003E6160(u8 *m, s32 b) {
    if (*(s32 *)(*(u8 **)(m + 0x68) + 0x30) != 0) {
        S_3E40A0 *v = func_L01_0043B548(6625, 108);
        v->f0(m);
        if (b) {
            v->f4(m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L12_003E6160 */
