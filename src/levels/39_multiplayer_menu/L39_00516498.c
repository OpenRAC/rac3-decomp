#include "common.h"

/* localdecomp:start func_L39_00516498 */
typedef struct Type1 S_00516498;
extern void func_0011D534(void *, s32, s32);
extern void func_L39_00517678(S_00516498 *, s32, s32, s32);

void func_L39_00516498(s32 *p, s32 v) {
    func_0011D534(p, 0, 0xE8);
    func_L39_00517678((S_00516498 *)(p + 2), 0, 0, 0);
    *p = v;
}
/* localdecomp:end func_L39_00516498 */

/* localdecomp:start func_L39_005164E8 */
typedef struct S_005164E8 {
    s32 f0;
    s32 f4;
    char f8[0x30];
    void *f38;
    void *f3C;
    void *f40;
    char _p44[0x9C];
    s64 fE0;
} S_005164E8;
extern void func_L39_005176A0(S_00516498 *);
extern void func_L39_004BEF28(void *);

void func_L39_005164E8(S_005164E8 *p) {
    func_L39_005176A0((S_00516498 *)p->f8);
    if (p->f3C != 0) {
        func_L39_004BEF28(p->f3C);
    }
    if (p->f40 != 0) {
        func_L39_004BEF28(p->f40);
    }
    if (p->f38 != 0) {
        func_L39_004BEF28(p->f38);
    }
    if (p->fE0 & 1) {
        func_L39_004BEF28(p);
    }
}
/* localdecomp:end func_L39_005164E8 */

/* localdecomp:start func_L39_00516570 */
extern void func_L39_005176A0(S_00516498 *);

void func_L39_00516570(void *arg0) {
    S_00516498 *q = (S_00516498 *)((u8 *)arg0 + 0x8);

    func_L39_005176A0(q);
    func_L39_00517678(q, 0, 0, 0);
    *(s32 *)((u8 *)arg0 + 0x30) = 0;
    *(s32 *)((u8 *)arg0 + 0xD0) = -1;
    func_0011D534((u8 *)arg0 + 0x48, 0, 0x80);
}
/* localdecomp:end func_L39_00516570 */

/* localdecomp:start func_L39_005165D0 */
typedef struct {
    char pad0[8];
    s32 f8;
    char padC[0xC4];
    s32 fD0;
} S_005165D0;
extern s32 func_L39_00517888(void *);

/* from rac4-decomp's func_L00_005523E0 */
s32 func_L39_005165D0(S_005165D0 *p) {
    s32 old = p->f8;
    s32 r = func_L39_00517888(&p->f8);
    if (r == 0 && old != p->f8) {
        p->fD0 = old;
    }
    return r;
}
/* localdecomp:end func_L39_005165D0 */
