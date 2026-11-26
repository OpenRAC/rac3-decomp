/* PAL near miss: 20 differing words (35 before) with -mvu0-use-vf0-vf2 added to the
 * file's flag line and a divs_nops row "func_L14_0035DBA8 2" (neither is applied: with the
 * file's current line and no row it is 73). Prerequisites as before: the real two-argument
 * declaration void func_L14_0035DBA8(void *, void *) and DE68 forwarding its second argument.
 * Round 30 (W23b): the threshold walk is a goto loop with the byte offset k = i * 4 kept for
 * both the threshold and the table read. With no loop notes loop.c leaves it alone, so there is
 * no strength reduction, retail's top-tested shape, the sll in the beqz slot and both bc1f back
 * edges with i++ in the slot. The back edges are conditional gotos, so no BARRIER sits before
 * the j loop: an unconditional `goto loop` lets loop.c move the j loop's call/return block out
 * of the loop, which costs 48+ words. The table is read as table.p directly (no tab pointer).
 * Still differs:
 *  - table pointer stores: retail sw p[2], p[0], p[3] before the vec block, ours p[0], p[2],
 *    then p[3] after it. 24 explicit store orders through a copied temporary: 63-69.
 *  - sel/d/mask registers (a3/t0/a2 in retail, a2/a3/t0 here) and the mask lhu, which retail
 *    issues after the d subu. gcse PRE puts the load at the end of the preheader, after the
 *    subu as in retail, but haifa sched1 (forward) issues it at t=5 in the div.s stall. With the
 *    lhu early, mask's priority (3 refs / 35) falls below d (3/30) and sel (4/78). Retail needs
 *    something that keeps the lhu after the subu (a barrier or a dependence). Not found: all
 *    120 orders of the d / f / sel / mask / i statements give 20; mask as u32/s32, read inline in
 *    the j loop, or read after loop 1: 20; real while/for/do forms of the walk: 73 (biv
 *    eliminated, strength reduced).
 */
#include "common.h"
/* localdecomp:start func_L14_0035DBA8 */
#include "vu0.h"
typedef struct {
    f32 v[5];
} S_35DBA8_f;
typedef struct {
    u8 b[4];
} S_35DBA8_b;
typedef struct {
    u8 *p[4];
} S_35DBA8_p;
typedef struct {
    u8 pad[0x44];
    s32 time;
    s32 choice;
} Choice_35DBA8;
extern S_35DBA8_f D_L14_001DD720;
extern S_35DBA8_b D_L14_001DD738[];
extern S_35DBA8_b D_L14_001DD740[];
extern S_35DBA8_b D_L14_001DD748[];
extern S_35DBA8_b D_L14_001DD750[];
__asm__(".extern D_L14_001DD6E4, 4");
extern s32 D_L14_001DD6E4;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern f32 func_0038D0C8(f32);
extern void func_L14_0035DA48(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L14_0035DBA8(void *arg0, void *target) {
    u8 *a0 = arg0;
    S_35DBA8_f thr = D_L14_001DD720;
    S_35DBA8_b l0 = D_L14_001DD738[0];
    S_35DBA8_b l1 = D_L14_001DD740[0];
    S_35DBA8_b l2 = D_L14_001DD748[0];
    S_35DBA8_b l3 = D_L14_001DD750[0];
    S_35DBA8_p table = { { l0.b, l1.b, l2.b, l3.b } };
    vu0_v4 v;
    u8 *s;
    u8 *sel;
    f32 f;
    s32 i;
    s32 k;
    s32 j;
    s32 d;
    s32 b;
    u16 mask;
    s = *(u8 **)(a0 + 0x68);
    vec_sub_ba(&v, target, a0 + 0x10);
    v.z = 0.0f;
    func_0038CF68(&v, &v, 1.0f);
    f = fabs_asm(func_0038D0C8(func_0038CE68(&v, a0 + 0xD0)) - 1.5707964f);
    if (0.0f < func_0038CE68(&v, a0 + 0xC0)) {
        f = 6.2831855f - f;
    }
    d = 4 - (s32)(*(f32 *)s / (f32)*(s16 *)(s + 4) * 4.0f);
    f += 0.7853982f;
    sel = l1.b;
    mask = *(u16 *)(a0 + 0x7C);
    i = 0;
loop:
    if (i < 4) {
        k = i * 4;
        i++;
        if (!(*(f32 *)((u8 *)thr.v + k) < f)) goto loop;
        if (!(f <= thr.v[i])) goto loop;
        sel = *(u8 **)((u8 *)table.p + k);
    }
    for (j = 0; j < 4; j++) {
        b = sel[j];
        if ((mask >> b) & 1) {
            if (d + *(s16 *)(s + 0x36) >= 5) {
                func_L14_0035DA48(a0, b);
                func_L01_004450F0(a0, 2, -1);
                ((Choice_35DBA8 *)s)->choice = b;
                ((Choice_35DBA8 *)s)->time = (D_L14_001DD6E4 * 5 + 2) / 6;
                return;
            }
        }
    }
}
/* localdecomp:end func_L14_0035DBA8 */
