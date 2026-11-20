#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* localdecomp:start func_L13_003ADA98 */
extern void func_L13_003AE698(u8 *a);

void func_L13_003ADA98(u8 *a, u8 *b) {
    if (b[939] != 0) {
        a[149] = 0;
    } else {
        a[149] = 1;
    }
    b[943] = 0;
    func_L13_003AE698(a);
}
/* localdecomp:end func_L13_003ADA98 */
