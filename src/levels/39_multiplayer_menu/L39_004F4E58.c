#include "common.h"

/* localdecomp:start func_L39_004F4E58 */
extern s32 D_L39_0046D814[];
typedef struct S_004F4E58 { u8 pad[0x30]; s32 *a; struct S_004F4E58 *b; } S_004F4E58;
extern S_004F4E58 *func_L39_004F7590(s32 n);
extern void func_L39_004F5CB0(S_004F4E58 *p);

s32 func_L39_004F4E58(S_004F4E58 **pp) {
    S_004F4E58 *p;
    *pp = p = func_L39_004F7590(0x38);
    if (p != 0) {
        func_L39_004F5CB0(p);
        p->b = p;
        p->a = D_L39_0046D814;
        return 0;
    }
    return 0x206;
}
/* localdecomp:end func_L39_004F4E58 */

/* localdecomp:start func_L39_004F4EB8 */
extern void func_004F7410(void *);

void func_L39_004F4EB8(u8 *p) {
    if (p) {
        func_004F7410(p + 8);
    }
}
/* localdecomp:end func_L39_004F4EB8 */

/* localdecomp:start func_L39_004F4EE8 */
typedef struct S_004F4EE8 { s32 a; s32 pad; u8 sub[8]; } S_004F4EE8;
extern void func_L39_004F73F0(void *p);

void func_L39_004F4EE8(S_004F4EE8 *p) {
    func_L39_004F73F0(p->sub);
    p->a = 0;
}
/* localdecomp:end func_L39_004F4EE8 */

/* localdecomp:start func_L39_004F4F18 */
typedef struct S_004F4F18 { u8 pad[0x34]; s32 x; } S_004F4F18;
extern s32 func_L39_004F4FD8(S_004F4F18 *p);
extern void func_L39_004F5CE8(S_004F4F18 *p);
extern void func_L39_004F7620(S_004F4F18 *p);

void func_L39_004F4F18(S_004F4F18 **pp) {
    S_004F4F18 *p = *pp;
    if (func_L39_004F4FD8(p) == 0) {
        p->x = 0;
        func_L39_004F5CE8(p);
        func_L39_004F7620(p);
    }
    *pp = 0;
}
/* localdecomp:end func_L39_004F4F18 */

/* localdecomp:start func_L39_004F4F68 */
s32 func_L39_004F5DA0(void *, s32, s32);

s32 func_L39_004F4F68(void *a, s32 (*fn)(s32 *), s32 x) {
    s32 buf;
    s32 r;

    r = func_L39_004F4FD8(a);
    if (r != 0) {
        return r;
    }
    if (fn(&buf) != 0) {
        return 0x213;
    }
    return func_L39_004F5DA0(a, buf, x);
}
/* localdecomp:end func_L39_004F4F68 */
