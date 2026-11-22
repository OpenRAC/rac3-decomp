#include "common.h"

typedef struct { u8 pad0[0xF4]; u8 *p; } O_A;

/* localdecomp:start func_L39_006873F0 */
extern void func_L39_006A5F28(void *, s32, s32);
extern void func_L39_00687268(void *, s32);
s32 func_L39_006873F0(u8 *self, s32 a1, s32 a2, s32 val) {
    u8 *child = *(u8 **)(self + 0xA8);
    if (child != 0) {
        func_L39_006A5F28(child, a1, a2);
        child[0x2B0] = val;
        func_L39_00687268(self, 0x11);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_006873F0 */

/* localdecomp:start func_L39_00687450 */
typedef struct { u8 pad[0x394]; int f394; } S_Inner;
typedef struct { u8 pad[0xB0]; S_Inner *fB0; } S_Outer;
extern void func_L39_006AB6D0(S_Inner *, int);
extern void func_L39_006AB700(S_Inner *, int);
extern void func_L39_006AB778(S_Inner *, int);
extern void func_L39_006AB6F8(S_Inner *, int);
extern void func_L39_00687268(void *, s32);
int func_L39_00687450(S_Outer *o, int a1, int a2, int a3, int a4, int a5, int a6)
{
    S_Inner *p = o->fB0;
    int t;
    if (p != 0) {
        func_L39_006AB6D0(p, a1);
        func_L39_006AB700(p, a2);
        func_L39_006AB778(p, a5);
        t = a4 - 1; p->f394 = (t < 200) ? t : 199;
        func_L39_006AB6F8(p, a6);
        func_L39_00687268(o, 0x13);
        return a2;
    }
    return 0;
}
/* localdecomp:end func_L39_00687450 */
