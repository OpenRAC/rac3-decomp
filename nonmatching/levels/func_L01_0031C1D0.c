/* PAL near miss (Codex wave 6): near miss: 46 words differ with the file's flags.
 * Worker's note: 6 diff with injected divs 2, w265/func_L01_0031C1D0.best.log: initial byte/halfword constant allocation and stores differ (-1 vs retail255); unsigned byte merges retail duplicate255 and loses one instruction. Remaining body matches. divs 2 tested only, no ...
 */
#include "common.h"
/* localdecomp:start func_L01_0031C1D0 */
typedef int Q_0031C1D0 __attribute__((mode(TI)));
typedef struct {
    s32 life;
    f32 reciprocal;
    s32 elapsed;
    s32 unused;
    f32 x, y, z, w;
    s32 a, b, c, d;
    f32 velocity[3];
    s32 e;
} P_0031C1D0;
typedef struct {
    u8 pad0[0x10];
    Q_0031C1D0 pos;
    u8 state;
    u8 pad21[0xF];
    s8 opacity;
    u8 enabled;
    u16 alpha;
    u16 flags;
    u8 pad36[0x32];
    P_0031C1D0 *p;
} M_0031C1D0;
static __inline__ void copy_0031C1D0(f32 *d, f32 *s) {
    d[0] = s[0]; d[1] = s[1]; d[2] = s[2];
}
u8 *func_L01_0031C1D0(Q_0031C1D0 *pos, f32 *velocity, s32 life,
                      s32 a, s32 b, s32 c, s32 d, s32 e,
                      f32 x, f32 y, f32 z, f32 w) {
    extern u8 *func_003C24B0(s32, s32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0031C398();
    u8 *m = func_003C24B0(0xDC1, 128);
    P_0031C1D0 *p;
    M_0031C1D0 *mob = (M_0031C1D0 *)m;
    if (m != 0) {
        mob->flags |= 0x41;
        mob->alpha = 255;
        mob->enabled = 1;
        mob->opacity = 255;
        mob->state = 0;
        p = mob->p;
        mob->pos = *pos;
        copy_0031C1D0(p->velocity, velocity);
        p->w = w;
        p->reciprocal = 1.0f / life;
        p->a = a;
        p->b = b;
        p->c = c;
        p->d = d;
        p->e = e;
        p->x = x;
        p->y = y;
        p->z = z;
        p->life = life;
        p->elapsed = 0;
        func_L01_00404A10(func_L01_0031C398, m);
    }
    return m;
}
/* localdecomp:end func_L01_0031C1D0 */
