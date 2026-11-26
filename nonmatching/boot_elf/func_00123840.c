/* k6-a3 2026-11-26: 9 raw rows with the file's flags (was 16): the semaphore id read once into a local
 * (sema = D_0013DC94[0] after func_0011EE60, func_0011EE40(sema)) gives async its register. Left: retail keeps
 * flags & 0x8000 in $s0 and copies it to async ($s2) inside the loop's first test; ours computes the andi
 * straight into $s2, and retail reloads the semaphore id for func_0011EE40 where we keep it in $t0. */
/* NTSC-U draft (Claude wave E): C of func_00123840 as NTSC-U has it, with NTSC-U names and addresses.
 * near miss: 16 words differ on NTSC-U with the file's flags (NTSC-U twin "func_00123840").
 * Worker's note: 16 diff with `@ee29 -O2 -G0` (Sony 2.9-ee: 16-byte save slots, $ra restored first; 152 diff with the file's SN line), same shape as the matched siblings func_001236C0 (close) and func_00123430 (open) of 123430.c (file I/O RPC, libkernl 'SceStdioReadSema'): ...
 */
#include "common.h"

/* localdecomp:start func_00123840 */
typedef struct {
    s32 x0;
    void *x4;
    s32 x8;
    s32 xC;
    void *x10;
    s32 x14;
    s32 x18;
    s32 x1C;
} P_123840;
typedef struct {
    s32 count;
    s32 max;
    s32 init;
    s32 wait;
    u32 attr;
    void *option;
} Q_123840;
extern s32 func_0011EE20_00123840(Q_123840 *);
extern s32 func_001230D8_00123840(s32);
extern P_123840 D_154C00_00123840;
extern s32 D_0013DC00_00123840[];
extern s32 D_0013DC94_00123840[];
extern s32 D_155840_00123840[];
extern char D_00150B38[];

s32 func_00123840(s32 fd, void *buf, s32 size) {
    F_1236C0 *f;
    Q_123840 q;
    s32 res;
    s32 s;
    s32 r;
    s32 flags;
    s32 async;
    s32 i;
    s32 t;
    s32 sema;
    P_123840 *p = &D_154C00_00123840;

    f = func_00122C58(fd);
    func_001230D8_00123840(2);
    if (D_0013DC84[0] == 0 || f == 0 || (flags = f->x4) == 0) {
        func_00123108();
        return -9;
    }
    p->xC = f->x0;
    p->x1C = f - D_156100_001236C0;
    q.max = 1;
    q.option = D_00150B38;
    p->x10 = buf;
    p->x14 = size;
    q.init = 0;
    s = func_0011EE20_00123840(&q);
    p->x4 = &res;
    p->x8 = 4;
    p->x0 = s;
    if (flags & 0x8000) {
        func_0011EE60(D_0013DC94_00123840[0]);
        sema = D_0013DC94_00123840[0];
        async = flags & 0x8000;
        for (i = 0; i < 0x20; i++) {
            if (D_0013DC00_00123840[i] == -1) {
                t = p->x0;
                D_0013DC00_00123840[i] = t;
                p->x0 = -t;
                break;
            }
        }
        func_0011EE40(sema);
    } else {
        async = 0;
    }
    if (!(flags & 0x20000000)) {
        func_00121F38(buf, size);
    }
    func_00121F38(p, 0x20);
    if (func_00122B68(D_156300, 2, 0, &D_154C00_00123840, 0x20, D_155840_00123840, 4, 0, 0, async) < 0) {
        func_0011EE30(s);
        func_00123108();
        return -11;
    }
    r = *(s32 *)((u32)D_155840_00123840 | 0x20000000);
    func_00123108();
    if (r == 0) {
        func_0011EE30(s);
        return -11;
    }
    if (async) {
        func_0011EE30(s);
        return 0;
    }
    func_0011EE60(s);
    func_0011EE30(s);
    return res;
}
/* localdecomp:end func_00123840 */
