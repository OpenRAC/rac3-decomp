#include "common.h"

/* localdecomp:start func_L39_005BD300 */
typedef struct { s32 w0; s32 w4; s32 w8; s32 wC; u8 pad[0xC]; } E_005BD300;
extern E_005BD300 D_L39_004840A0[];
void func_L39_005BD300(void) {
    s32 i;
    E_005BD300 *e;
    for (i = 0; i < 8; i++) {
        e = &D_L39_004840A0[i];
        if (e->w0 == 0) {
            e->wC++;
            if (e->wC > 10) e->wC = 10;
        } else {
            e->wC = 0;
        }
        if (e->w8 != 0) {
            e->w8--;
            if (e->w8 == 0) e->w0 = 0;
        }
    }
}
/* localdecomp:end func_L39_005BD300 */

/* localdecomp:start func_L39_005BD368 */
typedef struct S_005BD368 {
    s32 f00;
    s32 f04;
    s32 f08;
    s32 f0C;
    s32 f10;
    s32 f14;
    s32 f18;
} S_005BD368;

s32 func_L39_005BD368(s32 idx, s32 a, s32 b, s32 c, s32 unused, s32 d, s32 e) {
    S_005BD368 *p = (S_005BD368 *)&D_L39_004840A0[idx];

    if (p->f00 == a && p->f14 == d && p->f18 == e && p->f04 == b) {
        p->f08 = c;
        p->f04 = b;
        p->f14 = d;
        p->f18 = e;
        return 2;
    }
    if (p->f00 == 0) {
        p->f08 = c;
        p->f00 = a;
        p->f04 = b;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_005BD368 */
