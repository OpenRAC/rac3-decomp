/* func_0012F0B8 (Claude wave 14 r57, 2026-11-28). Replaces the earlier draft of this function (NTSC-U draft of `func_0012F0B8` (Claude wave E)). */
/* PAL near miss (wave 14 r57, 2026-11-28): func_0012F0B8, 13 words differ with 12EDD0.c's @ee29 line
 * (the previous draft, the NTSC-U port from Claude wave E, gave 14). Change: the reply slot pointer is built
 * in two steps, `q = D_15BC80[0][n]; q += ch * 32;`, which puts n << 5 in $a1 as retail does. Left: retail
 * keeps ch * 0x70 in $a3 and schedules `sll ch, 7` / `*q = 0` ahead of the req[5] load and the fC store:
 * an RTL dump (sched1) shows retail's *q store sits in the dependence chain of the slot stores
 * (f10 -> *q -> fC -> f8 -> f0), i.e. retail's q has no known base symbol for alias analysis, while ours
 * is D_15BC80 and floats free. Reusing a pointer variable for q reproduces that chain but moves q to $s0
 * (28). Tried: all 120 store orders (draft form and this form), u8 * / void * slot fields (strict aliasing
 * changes the chain, best 14), integer-address forms of q, one struct holding the slots and the reply
 * buffers (gcc then drops the kept %hi in $fp, 113), q passed in as the reused third parameter (14). */
#include "common.h"

/* localdecomp:start func_0012F0B8 */
typedef struct { u32 f0; s32 *f4; s32 f8; s32 fC; s32 f10; u8 pad14[8]; } Slot_12F0B8;
typedef struct { Slot_12F0B8 s[4]; } Chan_12F0B8;
typedef struct {
    u8 pad0[0x58];
    s32 x58;
    u8 pad5C[4];
    s32 x60;
    u8 pad64[3];
    u8 b67;
    u8 pad68[8];
    u8 b70;
    u8 b71;
    u8 pad72[0xE];
} Cmd_12F0B8;
extern Chan_12F0B8 D_15BB90[];
extern u8 D_15BB40[];
extern s32 D_15BC80[][4][8];
extern s32 D_15BD80[];
extern s32 D_0014155C;
extern char D_00151BD0[];
extern char D_00151C00[];
s32 func_0012F0B8(s32 ch, s32 n, Cmd_12F0B8 *buf) {
    s32 i;
    Cmd_12F0B8 *c;
    s32 *req;
    s32 *q;
    if ((u32)buf & 0x3F) {
        if (D_0014155C != 0) {
            func_00121760(D_00151BD0, buf);
        }
        return 0;
    }
    if (D_15BB90[ch].s[n].f10 == 1) {
        if (D_0014155C != 0) {
            func_00121760(D_00151C00, ch, n);
        }
        return 0;
    }
    c = buf;
    for (i = 0; i < 2; i++) {
        c->x58 = 0;
        c->b70 = 5;
        c->b71 = 2;
        c->b67 = 0;
        func_0011A264(c, 0xFF, 0x20);
        c->x60 = 0;
        c++;
    }
    req = D_15BD80;
    req[0] = 1;
    req[1] = ch;
    req[2] = n;
    req[4] = (s32)buf;
    if (func_00122810(D_15BB40, 1, 0, req, 0x80, req, 0x80, 0, 0) < 0) {
        return 0;
    }
    q = D_15BC80[0][n];
    q += ch * 32;
    D_15BB90[ch].s[n].f10 = 1;
    D_15BB90[ch].s[n].fC = 0;
    D_15BB90[ch].s[n].f8 = req[5];
    D_15BB90[ch].s[n].f4 = q;
    *q = 0;
    D_15BB90[ch].s[n].f0 = (u32)buf;
    return req[3];
}
/* localdecomp:end func_0012F0B8 */
