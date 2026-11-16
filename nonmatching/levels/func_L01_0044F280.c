/* PAL near miss (Codex wave 8): near miss: 29 words differ with the file's flags.
 * Worker's note: 29 positional word differences, 220 vs 232 bytes; complete xyzw VU sequences reproduce first block but compiler merges transform calls and cannot share partial VU tails. Three control-flow forms unchanged. Best log ...
 */
#include "common.h"
/* localdecomp:start func_L01_0044F280 */
#include "vu0.h"
/* Retail adds all four components; the shared helpers add xyz only. */
static __inline__ void add_xyzw_0044F280(void *d, void *a, void *b) {
    vu0_q qa, qb;
    __asm__("lqc2 %2, %3\n\tlqc2 %1, %4\n\tvadd.xyzw %2, %2, %1\n\tsqc2 %2, %0"
        : "=m"(*(vu0_v4 *)d), "=&j"(qb), "=&j"(qa)
        : "m"(*(vu0_v4 *)a), "m"(*(vu0_v4 *)b));
}
void func_L01_0044F280(void *dst, u8 *obj, void *offset, void *mat, void *other) {
    extern void func_0038D000(void *, void *, void *);
    vu0_v4 temp;
    func_0038D000(&temp, obj + 0x30, mat);
    add_xyzw_0044F280(dst, offset, &temp);
    if (*(u8 **)(obj + 0x40)) {
        switch (obj[0x4C] & 0x30) {
        case 0x10:
            func_0038D000(&temp, *(u8 **)(obj + 0x40) + 0x10, mat);
            add_xyzw_0044F280(dst, dst, &temp);
            break;
        case 0x20:
            func_0038D000(&temp, *(u8 **)(obj + 0x40) + 0x10, other);
            add_xyzw_0044F280(dst, dst, &temp);
            break;
        default:
            add_xyzw_0044F280(dst, dst, *(u8 **)(obj + 0x40) + 0x10);
            break;
        }
    }
}
/* localdecomp:end func_L01_0044F280 */
