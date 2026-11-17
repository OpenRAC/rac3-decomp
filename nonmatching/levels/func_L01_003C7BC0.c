/* PAL near miss (b8-s4): one missing move (about 2 words, 37 listed because the rest shifts): in the idx == n - 2 case retail copies the element pointer into $a0 (move $a0,$v1) and loads the second quadword through that copy; this C loads both from one register. All other cases match; about 12 compiles (pointer types, base as an integer, copies, store orders) did not give the copy.
 */
#include "common.h"
/* localdecomp:start func_L01_003C7BC0 */
typedef int s128 __attribute__((mode(TI)));
extern void func_L01_0040E398(u8 *, s128 *, s128 *);

void func_L01_003C7BC0(u8 *a0, s32 *a1, s32 idx, u8 *out) {
    s128 a;
    s128 b;
    s32 n = a1[0];
    if (idx >= n) {
        a = *(s128 *)(a0 + 0x150);
        b = *(s128 *)(a0 + 0x160);
    } else if (idx == n - 2) {
        u8 *p = (u8 *)(idx * 16 + (s32)a1);
        a = *(s128 *)(p + 0x10);
        b = *(s128 *)(p + 0x20);
    } else if (idx == n - 1) {
        u8 *p = (u8 *)(idx * 16 + (s32)a1);
        a = *(s128 *)(p + 0x10);
        b = *(s128 *)(a0 + 0x150);
    } else {
        if (idx < 0) {
            a = *(s128 *)(a0 + 0x140);
            idx = idx << 4;
        } else {
            u8 *p = (u8 *)(idx * 16 + (s32)a1);
            a = *(s128 *)(p + 0x10);
            idx = idx * 16;
        }
        b = *(s128 *)((u8 *)(idx + (s32)a1) + 0x20);
    }
    func_L01_0040E398(out, &a, &b);
}
/* localdecomp:end func_L01_003C7BC0 */
