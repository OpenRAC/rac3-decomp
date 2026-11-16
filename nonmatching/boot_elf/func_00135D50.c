/* NTSC-U draft (Claude wave E): C of func_00135D50 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 7 words differ on NTSC-U with the file's flags (NTSC-U twin "func_00135D50").
 * Study aid: it uses inline asm for EE instructions (move), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: call of a callback-table entry with a swapped $gp (tbl = h->x40; e = tbl+0xC+12*idx: {fn,arg,gp}; org = ChangeGP(e->gp); r = fn(h, idx, e->arg); ChangeGP(org); return r or 0): MATCH only with Sony 2.9 `@ee29 -O2 -G0` (16-byte slots, ld $ra hoisted); with the ...
 */
#include "common.h"

/* localdecomp:start func_00135D50 */
typedef struct {
    s32 (*fn)();
    s32 arg;
    void *gp;
} E_135D50;
typedef struct {
    u8 pad[0xC];
    E_135D50 e[1];
} T_135D50;
typedef struct {
    u8 pad[0x40];
    T_135D50 *x40;
} S_135D50;

static inline void *ChangeGP_135D50(void *gp)
{
    void *org;

    __asm__ __volatile__("move %0, $28\n\tmove $28, %1" : "=&r"(org) : "r"(gp) : "memory");
    return org;
}

s32 func_00135D50(s32 h, s32 *idx)
{
    S_135D50 *s = (S_135D50 *)h;
    T_135D50 *t;
    void *org;
    s32 (*fn)();
    s32 r = 0;

    if (s != 0) {
        t = s->x40;
        if (t != 0) {
            fn = t->e[*idx].fn;
            if (fn != 0) {
                org = ChangeGP_135D50(t->e[*idx].gp);
                r = fn(h, idx, t->e[*idx].arg);
                ChangeGP_135D50(org);
            }
        }
    }
    return r;
}
/* localdecomp:end func_00135D50 */
