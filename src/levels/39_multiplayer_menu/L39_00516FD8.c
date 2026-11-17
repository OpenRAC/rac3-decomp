#include "common.h"

/* localdecomp:start func_L39_00516FD8 */
typedef struct O_00516FD8 O_00516FD8;
typedef struct {
    char _p0[0xC];
    s32 (*fC)(O_00516FD8 *, s32, s32, s32);
} V_00516FD8;
struct O_00516FD8 {
    char _p0[0xC];
    V_00516FD8 *vt;
};
typedef struct {
    char _p0[0x28];
    O_00516FD8 *obj;
} S_00516FD8;

extern void func_L39_00517068();
extern s32 func_L39_004F5D60(void *, void (*)());

s32 func_L39_00516FD8(S_00516FD8 *p, s32 a1, s32 a2, s32 a3) {
    s32 e;

    if (p == 0) {
        return 0x21B;
    }
    e = func_L39_004F5D60(p, func_L39_00517068);
    if (e != 0) {
        return (e == 0x202) ? 0x21A : e;
    }
    return p->obj->vt->fC(p->obj, a1, a2, a3);
}
/* localdecomp:end func_L39_00516FD8 */
