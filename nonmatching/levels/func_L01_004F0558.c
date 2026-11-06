/* near miss: matches only with inline asm (sq $0), which is not allowed in matched C.
 * From PR #5 (open-rac-engine names). */
#include "common.h"

/* localdecomp:start func_L01_004F0558 */
typedef int s128_4F0558 __attribute__((mode(TI)));
typedef struct { u8 pad[0x9E0]; s128_4F0558 v; f32 x, y, z; } H_4F0558;
/* aliases: the file's declarations of these come later, with types not defined yet here */
extern u8 D_001A4BE0_004F0558[];
extern void func_0038CE20_004F0558(void *, void *, f32);
extern void func_00382760(void *, f32, f32, f32);
extern f32 func_0038CEA8(void *);
extern void func_0038CF68(void *, void *, f32);
void func_L01_004F0558(f32 a, f32 b) {
    s128_4F0558 *p = &((H_4F0558 *)D_001A4BE0_004F0558)->v;
    f32 len;
    func_00382760(p, ((H_4F0558 *)D_001A4BE0_004F0558)->x, ((H_4F0558 *)D_001A4BE0_004F0558)->z,
                  ((H_4F0558 *)D_001A4BE0_004F0558)->y);
    func_0038CE20_004F0558(p, p, a);
    len = func_0038CEA8(p);
    if (len <= b) {
        /* the compiler never stores a quadword zero directly (docs/wiki/Matching-Patterns.md) */
        __asm__("sq $0,%0" : "=m"(*p));
    } else {
        func_0038CF68(p, p, len - b);
    }
}
/* localdecomp:end func_L01_004F0558 */
