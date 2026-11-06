/* near miss: matches only with inline asm (sq $0), which is not allowed in matched C.
 * From PR #5 (open-rac-engine names). */
#include "common.h"

/* localdecomp:start func_L01_004F05F0 */
typedef int s128_4F05F0 __attribute__((mode(TI)));
extern void func_L01_00511178(s128_4F05F0 *, s128_4F05F0 *, f32);
extern f32 func_0038CE68(void *, void *);
f32 func_L01_004F05F0(s128_4F05F0 *v) {
    s128_4F05F0 a;
    s128_4F05F0 b;
    s128_4F05F0 *pa = &a;
    s128_4F05F0 *pb = &b;
    *pa = *v;
    /* the compiler never stores a quadword zero directly (docs/wiki/Matching-Patterns.md) */
    __asm__("sq $0,%0" : "=m"(*pb));
    func_L01_00511178(pb, pb, 1.0f);
    return func_0038CE68(pa, pb);
}
/* localdecomp:end func_L01_004F05F0 */
