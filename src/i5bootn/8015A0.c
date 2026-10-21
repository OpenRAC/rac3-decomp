#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 8010A8.c's earlier functions (tools/port_from_us.py) */
extern int func_00801080(void);
extern void func_00801090(void);
extern void func_00801138(void);
extern int func_008014A0(int);

/* localdecomp:start func_008015A0 */
typedef int (*putc_fn_8015A0)(void *, int *, int);
extern int func_008024B8_008015A0(void *, void *, int *, const char *, ...);
extern int func_00801510_008015A0(unsigned long);
int func_008015A0(putc_fn_8015A0 out, void *ctx, int *n, double x) {
    int count = 0;
    int e = 0;
    int m;
    if (*n == 0) return 0;
    if (x < 0.0) {
        x = -x;
        count = 1;
        out(ctx, n, '-');
        (*n)--;
    }
    if (x < 0.1) {
        while (x < 0.1) {
            x = x * 10.0;
            e--;
        }
    } else if (x >= 1.0) {
        while (x >= 1.0) {
            x = x / 10.0;
            e++;
        }
    }
    m = func_00801510_008015A0((unsigned long)(x * 1000000.0));
    count += func_008024B8_008015A0(out, ctx, n, "0.%d", m);
    if (e >= 0)
        count += func_008024B8_008015A0(out, ctx, n, "e+%d", e);
    else
        count += func_008024B8_008015A0(out, ctx, n, "e%d", e);
    return count;
}
/* localdecomp:end func_008015A0 */
