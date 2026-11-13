#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L31_003A5958 */

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3A5958;
typedef struct {
    char _p0[0x24];
    f32 f24;
} C_3A5958;
typedef struct {
    f32 f0;
    s16 s4;
    char _p6[0x14 - 6];
    u8 f14;
    char _p15[0x4C - 0x15];
    s16 s4C;
    s16 s4E;
    char _p50[0x170 - 0x50];
    s32 i170;
    char _p174[0x180 - 0x174];
    V4_3A5958 v180;
    char _p190[0x1B0 - 0x190];
    s32 i1B0;
    char _p1B4[4];
    s32 i1B8;
    char _p1BC[4];
    s32 i1C0;
    char _p1C4[4];
    s32 i1C8;
    char _p1CC[0x1D4 - 0x1CC];
    s32 i1D4;
} X_3A5958;
typedef struct {
    char _p0[0x10];
    V4_3A5958 v10;
    char _p20[4];
    C_3A5958 *f24;
    char _p28[4];
    f32 f2C;
    u8 f30;
    char _p31;
    s16 s32;
    char _p34[0x68 - 0x34];
    X_3A5958 *f68;
} M_3A5958;

extern M_3A5958 *func_003C24B0(s32, s32);
extern void func_L31_003A55A0(M_3A5958 *, s32);

M_3A5958 *func_L31_003A5958(V4_3A5958 *pos, s32 a1) {
    M_3A5958 *m;
    X_3A5958 *x;

    m = func_003C24B0(0x1A9A, 0x1E0);
    if (m == 0) {
        return 0;
    }
    m->f30 = 0xFF;
    m->s32 = 0x40;
    m->v10 = *pos;
    x = m->f68;
    m->f2C = m->f24->f24 * 1.4f;
    if ((f32)x->s4 <= 0.0f) {
        x->s4 = 3;
    }
    x->f0 = x->s4;
    if ((f32)x->f14 <= 0.0f) {
        x->f14 = 10;
    }
    x->i1D4 = 1;
    x->s4C = 4;
    qzero(&x->v180);
    x->s4E = 0xF;
    x->i170 = 3;
    x->i1B8 = a1;
    x->i1B0 = -1;
    x->i1C8 = 0;
    x->i1C0 = 0;
    func_L31_003A55A0(m, 0);
    return m;
}
/* localdecomp:end func_L31_003A5958 */
