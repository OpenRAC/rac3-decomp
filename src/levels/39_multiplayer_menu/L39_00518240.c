#include "common.h"

/* localdecomp:start func_L39_00518240 */
typedef struct N_00518240 {
    char _p0[0x18];
    u32 f18;
    u32 f1C;
    u32 f20;
    s32 f24;
} N_00518240;

typedef struct S_00518240 {
    u32 count;
    u32 cap;
    N_00518240 *data;
    s32 flags;
} S_00518240;

extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BEF00(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_00518240(S_00518240 *p, u32 n) {
    N_00518240 *new;
    s32 moved;
    N_00518240 *old;
    N_00518240 *end;
    u32 i;
    s32 idx;

    if (p->count >= n) {
        return 0;
    }
    if (p->flags & 2) {
        if (p->data == 0) {
            moved = 0;
            new = func_L39_004BEED8(n * sizeof(N_00518240));
            func_0011D534(new, 0, n * sizeof(N_00518240));
        } else {
            moved = 1;
            new = func_L39_004BEF00(p->data, n * sizeof(N_00518240), p->cap * sizeof(N_00518240));
            func_0011D534(new + p->cap, 0, (n - p->cap) * sizeof(N_00518240));
        }
        if (new == 0) {
            return 5;
        }
        old = p->data;
        if (old != new) {
            if (moved) {
                end = old + p->count;
                for (i = 0; i < p->count; i++) {
                    if (new[i].f18 >= (u32)old && new[i].f18 <= (u32)end) {
                        idx = (N_00518240 *)new[i].f18 - old;
                        new[i].f18 = (u32)&new[idx];
                    }
                    if (new[i].f1C >= (u32)old && new[i].f1C <= (u32)end) {
                        idx = (N_00518240 *)new[i].f1C - old;
                        new[i].f1C = (u32)&new[idx];
                    }
                    if (new[i].f20 >= (u32)old && new[i].f20 <= (u32)end) {
                        idx = (N_00518240 *)new[i].f20 - old;
                        new[i].f20 = (u32)&new[idx];
                    }
                }
            }
        }
        p->cap = n;
        p->data = new;
        return 0;
    }
    return 6;
}
/* localdecomp:end func_L39_00518240 */
