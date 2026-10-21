#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00517830);

/* localdecomp:start func_L01_005178A0 */
typedef struct { s32 a; s32 b; } S_5138B0;
extern S_5138B0 D_L01_001E15E0[];
extern void *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E5CC0(s32);
s32 func_L01_005178A0(s32 *a) {
    S_5138B0 *p = D_L01_001E15E0;
    s32 q;
    s32 r = 0;
    { S_5138B0 *t; if (p->b != 0) t = p; else t = func_003E6C08(p); q = func_003E6DE8(t); }
    if (q) { r = 1; *a = func_003E5CC0(q); }
    return r;
}
/* localdecomp:end func_L01_005178A0 */

LINKER_REMNANT("asm/levels", func_L01_00517910);

/* localdecomp:start func_L01_00517918 */
extern S_5138B0 D_L01_001E15E0[];
extern s32 func_L01_00517918();
extern s32 func_003E6DE8(void *);
extern void *func_003E6C08();
extern s32 func_003E6DE8();

typedef struct { s32 a; s32 b; } S_3E3040;
extern void func_003E5DC0(void *, s32);
s32 func_L01_00517918(s32 a) {
    S_3E3040 *p = ((S_3E3040 *)&D_L01_001E15E0);
    void *q;
    s32 r = 0;
    { S_3E3040 *t; if (p->b != 0) t = p; else t = func_003E6C08(); q = func_003E6DE8(t); }
    if (q) { func_003E5DC0(q, a); r = 1; }
    return r;
}
/* localdecomp:end func_L01_00517918 */
