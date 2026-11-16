/* NTSC-U draft (Claude wave E): C of func_00125A70 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 42 words differ on NTSC-U with the file's flags (NTSC-U twin "func_00125A70").
 * Study aid: it uses register pin, which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: timer alarm re-arm (id = (node>>6)<<10 / seq: node = ((u32)id >> 10) << 6, seq check against node+8 -> 0x80008002, id of the running alarm D_0013F288+0x1C -> 0x80000010, unlink if queued (func_00125540), set handler/time/$gp/arg, relink (func_001254B8) if ...
 */
#include "common.h"

/* localdecomp:start func_00125A70 */
typedef struct {
    u8 pad0[8];
    s32 f8;
    u32 fC;
    u8 pad10[0x20 - 0x10];
    long f20;
    s32 f28;
    s32 f2C;
    s32 f30;
} Alarm_125A70;
extern void func_00125540();
extern void func_001254B8();
extern s32 func_00125820(void);
extern void func_00125328(s32);

s32 func_00125A70(s32 id, long time, s32 handler, s32 arg)
{
    register void *gp __asm__("$28");
    Alarm_125A70 *p;
    u8 *q;

    p = (Alarm_125A70 *)(((u32)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != p->f8) {
        return 0x80008002;
    }
    q = (u8 *)&D_0013F288;
    if (*(s32 *)(q + 0x1C) == id) {
        return 0x80000010;
    }
    if (p->fC & 2) {
        func_00125540(p);
    }
    p->f28 = handler;
    if (handler == 0) {
        p->fC &= ~2;
    } else {
        p->f20 = time;
        p->fC |= 2;
        p->f2C = (s32)gp;
        if (p->fC & 1) {
            func_001254B8(p);
        }
        p->f30 = arg;
    }
    func_00125328(func_00125820());
    return 0;
}
/* localdecomp:end func_00125A70 */
