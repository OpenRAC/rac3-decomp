/* func_L39_00519910 (Claude wave 13 second pass r39, 2026-11-28). Replaces the earlier draft of this function (PAL draft (k6 a6, 2026-11-26), written from retail). */
/* PAL near miss (k6 a6, 2026-11-26): func_L39_00519910 (328 B, level 39), written from retail;
 * 2 diff with its file's line (@ee29 @eeas -O2 -G8 -fno-strict-aliasing). The new node is
 * memset, filled, and pushed on the head of the D_L39_0046F550/D_L39_0046F554 list. What differs:
 * retail stores the new head (sw $s0, %lo(D_L39_0046F550)($a1)) before n->prev = 0; this C
 * gives the opposite order. With n->prev = 0 written after the head store the order is right but
 * the %hi goes to $a0 and the final call's argument moves swap (5). Tried: the five field stores
 * in all 120 orders, the list push in all 24 statement orders, a head pointer local, the head
 * read directly instead of through t (all 2-30). permuter_setup.py does not take @eeas files. */
#include "common.h"
/* localdecomp:start func_L39_00519910 */
typedef struct N_00519910 {
    struct N_00519910 *next;
    struct N_00519910 *prev;
    s32 f8;
    s32 pC[2];
    s32 f14;
    s32 p18[0x13];
    s32 f64;
    s32 f68;
    s32 f6C;
} N_00519910;
extern N_00519910 *D_L39_0046F550 __attribute__((section(".data")));
extern N_00519910 *D_L39_0046F554 __attribute__((section(".data")));
extern N_00519910 *func_L39_00518FE0(s32);
extern void func_0011D534(void *, s32, s32);
s32 func_L39_00519910(s32 arg0, s32 arg1) {
    P_00519600 *p;
    N_00519910 *n;
    N_00519910 *t;
    s32 r;

    p = func_L39_005190E8(0);
    if (p == 0) return -1;
    if (arg0 != 2) return func_L39_005192A8(p, 0x60);
    r = func_L39_00519568();
    switch (arg1) {
    case 2:
        arg1 = 0;
        break;
    case 1:
    case 3:
        break;
    default:
        return func_L39_005192A8(p, 0x6B);
    }
    n = func_L39_00518FE0(0x70);
    if (n == 0) return func_L39_005192A8(p, 0xC);
    func_0011D534(n, 0, 0x70);
    n->f14 = arg1;
    n->f8 = r;
    n->f64 = -1;
    n->f68 = -1;
    n->f6C = -1;
    t = D_L39_0046F550;
    n->next = t;
    if (t != 0) {
        t->prev = n;
    } else {
        D_L39_0046F554 = n;
    }
    n->prev = 0;
    D_L39_0046F550 = n;
    func_L39_005192A8(p, 0);
    return r;
}
/* localdecomp:end func_L39_00519910 */
