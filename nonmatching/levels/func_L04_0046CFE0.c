/* Level 4 (Marcadia), file L04_0046CFE0.c (its flags line without @ps2as; the two float constants 0.5 and 0.85 are built inline with lui/ori/mtc1, so the file needs @ps2as for this function, the only one in it). check.py: 90 diff with @ps2as. The first branch (class 0x1BDC) keeps two identical arms, each calling func_0038CF38 (the copy at 0x41F260 in every one of the 16 levels), selected by st->flags & 0x400 and joined before the threshold compare; every wording tried merges them (if/else, ternary, differently spelled arguments, an inline wrapper for one arm, separate result variables), and the merge also shifts the second branch. Stopped per AGENTS.md (more than ten compiles).
 * 2026-11-21 (Promises fleet): 89 differences (tools/check.py) at level 04 with the file's flags, 90 with `tools/check.py --as ps2as`. Three more wordings, counted with --as ps2as: the moby position in a local before the if (91), a goto join (90), and `thr = 0.5f` / `thr = 0.85f` inside the arms with `d <= thr` (87: both arms stay, but the constant is loaded in each arm where retail re-tests the flags after the join). */
#include "common.h"

/* localdecomp:start func_L04_0046CFE0 */
typedef struct {
    u8 pad0[0x38];
    s32 flags;
    u8 pad3C[0xC4 - 0x3C];
    void *path;
    s16 cur;
    s16 target;
} PathState_L04_0046CFE0;

typedef struct {
    u8 pad0[0x10];
    u8 pos[0x10];
    u8 pad20[0xAA - 0x20];
    s16 oClass;
} Moby_L04_0046CFE0;

typedef struct {
    u8 pad0[0x10];
    f32 pts[1][4];
} Path_L04_0046CFE0;

extern PathState_L04_0046CFE0 *func_L01_0045B958(Moby_L04_0046CFE0 *moby);
extern void func_L01_0045C150(Moby_L04_0046CFE0 *moby, Path_L04_0046CFE0 *path, s32 a2, s32 a3);
extern void func_L01_0045D218(Moby_L04_0046CFE0 *moby, f32 *pt);
extern f32 func_0038CF38(void *a, void *b);

s32 func_L04_0046CFE0(Moby_L04_0046CFE0 *moby, Path_L04_0046CFE0 *path) {
    PathState_L04_0046CFE0 *st;
    f32 d;
    f32 thr;

    if (moby->oClass == 0x1BDC) {
        st = func_L01_0045B958(moby);
        if (st == 0) {
            return 0;
        }
        if (path != st->path) {
            func_L01_0045C150(moby, path, -1, 0);
        }
        func_L01_0045D218(moby, path->pts[st->cur]);
        if (st->flags & 0x400) {
            d = func_0038CF38(moby->pos, path->pts[st->cur]);
        } else {
            d = func_0038CF38(moby->pos, path->pts[st->cur]);
        }
        if (!(d <= ((st->flags & 0x400) ? 0.5f : 0.85f))) {
            return 0;
        }
    } else {
        st = func_L01_0045B958(moby);
        if (st == 0) {
            return 0;
        }
        if (path != st->path) {
            func_L01_0045C150(moby, path, -1, 0);
        }
        func_L01_0045D218(moby, path->pts[st->target]);
        if (st->flags & 0x400) {
            d = func_0038CF38(moby->pos, path->pts[st->target]);
        } else {
            d = func_0038CF38(moby->pos, path->pts[st->target]);
        }
        if (!(d <= 0.5f)) {
            return 0;
        }
    }
    if (st->target == st->cur) {
        return 1;
    }
    if (st->target < st->cur) {
        st->cur--;
    } else {
        st->cur++;
    }
    return 0;
}
/* localdecomp:end func_L04_0046CFE0 */
