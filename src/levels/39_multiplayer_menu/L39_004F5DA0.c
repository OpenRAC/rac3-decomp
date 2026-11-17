#include "common.h"

/* declared by functions of L39_004F4E58.c, which this file was cut from */
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

/* localdecomp:start func_L39_004F5DA0 */
extern s32 D_L39_0046EE90[];
extern s32 D_L39_0046EEE0[];
extern s32 D_L39_0046EF30[];
struct S_004F5DA0;
typedef struct V_004F5DA0 V_004F5DA0;
typedef struct {
    s32 (*f0)(V_004F5DA0 *, struct S_004F5DA0 *);
    s32 (*f4)(V_004F5DA0 *, struct S_004F5DA0 *);
} VT_004F5DA0;
struct V_004F5DA0 { VT_004F5DA0 *vt; };
typedef struct S_004F5DA0 { u8 pad0[0xC]; s32 c; u8 pad10[0x18]; s32 r; s32 flags; } S_004F5DA0;

s32 func_L39_004F5DA0(S_004F5DA0 *a0, V_004F5DA0 *a1) {
    s32 r;

    if (a0->c != 0
        && (!(a0->flags & 2) || a1 != (V_004F5DA0 *)D_L39_0046EE90)
        && (!(a0->flags & 4) || a1 != (V_004F5DA0 *)D_L39_0046EEE0)
        && (!(a0->flags & 8) || a1 != (V_004F5DA0 *)D_L39_0046EF30)) {
        return 0x200;
    }
    r = a1->vt->f0(a1, a0);
    if (r != 0) {
        return r;
    }
    if (a1->vt->f4 != 0) {
        r = a1->vt->f4(a1, a0);
        a0->r = r;
        if (r == 0) {
            return 0x206;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004F5DA0 */

/* localdecomp:start func_L39_004F5E70 */
extern void func_L39_004F5F80(void *);
extern void func_L39_004F74E8(void *, s32, s32);

void func_L39_004F5E70(u8 *p) {
    func_L39_004F5F80(p);
    func_L39_004F74E8(p + 0xC, 0, 8);
}
/* localdecomp:end func_L39_004F5E70 */
