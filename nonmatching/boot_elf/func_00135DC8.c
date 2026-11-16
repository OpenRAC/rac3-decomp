/* NTSC-U draft (Claude wave E): C of func_00135DC8 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_00135DC8").
 * Study aid: it uses inline asm for EE instructions (move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: MATCH only with Sony 2.9 flags (16-byte save slots, $ra first; the 135CE0.c line is SN). Calls a callback table entry with a swapped $gp: needs two `__asm__ __volatile__("move %0, $28
 */
#include "common.h"
/* localdecomp:start func_00135DC8 */
typedef struct {
    u8 pad0[0x18];
    s32 (*fn)(int, s32 *, s32);
    s32 pad1C;
    s32 gp;
} T_135DC8;

int func_00135DC8(int x) {
    s32 loc[8];
    loc[0] = 1;
    if (x != 0) {
        T_135DC8 *t = *(T_135DC8 **)(x + 0x40);
        if (t != 0) {
            s32 (*fn)(int, s32 *, s32) = (s32 (*)(int, s32 *, s32))t->fn;
            if (fn != 0) {
                s32 old;
                s32 r;
                s32 cur;
                __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(old) : "r"(t->gp) : "memory");
                r = fn(x, loc, *(s32 *)((u8 *)t + loc[0] * 12 + 0x10));
                __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(cur) : "r"(old));
            }
        }
    }
    return 1;
}
/* localdecomp:end func_00135DC8 */
