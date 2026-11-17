#include "common.h"

/* localdecomp:start func_L30_0034EDE0 */
typedef struct { u8 pad[0x10]; u8 x10[0x9A]; s16 xAA; } M_34EDE0;
typedef struct { u8 pad[0x10]; u8 x10[0x10]; } O_34EDE0;
__asm__(".extern D_L30_001DD5E8, 4");
__asm__(".extern D_L30_001DF2C0, 4");
extern f32 D_L30_001DD5E8;
extern s32 D_L30_001DF2C0;
extern M_34EDE0 *D_L30_001E1280[4] __attribute__((section(".sdata")));
extern s32 D_L30_001E1290[4] __attribute__((section(".sdata")));
extern M_34EDE0 *D_L30_001ED080[];
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(s32, s32, f32, s32, s32);

M_34EDE0 *func_L30_0034EDE0(O_34EDE0 *o) {
    f32 best = D_L30_001DD5E8;
    M_34EDE0 *res = 0;
    s32 found = 0;
    s32 i;
    s32 j;
    s32 n;
    M_34EDE0 *m;

    for (i = 0; i < 4; i++) {
        if (D_L30_001E1280[i] != 0
            && func_0038CF00(o->x10, D_L30_001E1280[i]->x10) < best
            && D_L30_001E1290[i] >= D_L30_001DF2C0 - 10
            && func_003D3CB0(o->x10, D_L30_001E1280[i]->x10, 2, o, 0) == 0) {
            res = D_L30_001E1280[i];
            found = 1;
            best = func_0038CF00(o->x10, res->x10);
        }
    }
    if (found) {
        return res;
    }
    {
        n = func_003D4D00((s32)o->x10, 1, D_L30_001DD5E8, (s32)o, 0);
        for (j = 0; j < n; j++) {
            m = D_L30_001ED080[j];
            if (m != 0 && m->xAA == 0x1946
                && func_0038CF00(o->x10, m->x10) < best
                && func_003D3CB0(o->x10, m->x10, 2, o, 0) == 0) {
                res = m;
                best = func_0038CF00(o->x10, m->x10);
                found = 1;
            }
        }
    }
    return found ? res : 0;
}
/* localdecomp:end func_L30_0034EDE0 */
