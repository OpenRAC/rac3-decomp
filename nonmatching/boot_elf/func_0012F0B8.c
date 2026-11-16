/* NTSC-U draft (Claude wave E): C of func_0012F0B8 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 18 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_0012F0B8").
 * Worker's note: 18 diff on 12EDD0.c's @ee29 line (@eeas same), k87's opus draft unchanged on master c84e91b4. C: near/func_0012F0B8.opus.c
 */
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
extern u8 D_15BC80[];
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
    for (i = 1; i >= 0; i--) {
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
    q = (s32 *)(D_15BC80 + ch * 0x80 + n * 0x20);
    D_15BB90[ch].s[n].f10 = 1;
    D_15BB90[ch].s[n].fC = 0;
    D_15BB90[ch].s[n].f8 = req[5];
    D_15BB90[ch].s[n].f4 = q;
    *q = 0;
    D_15BB90[ch].s[n].f0 = (u32)buf;
    return req[3];
}
/* localdecomp:end func_0012F0B8 */
