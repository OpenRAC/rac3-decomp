/* PAL draft (2026-11-21, Promises): written from level 3's assembly. 10 words differ with its file's
 * flags (src/levels/shared/L03_003A4900.c): the float registers of the four shared UV sums.
 * Retail gives hi+cs $f2, hi+sn $f3, lo-cs $f4, lo-sn $f5; ours $f4, $f2, $f3, $f5, and the
 * colour stores 0x48/0x44 come later. Tried: five store orders, explicit temporaries (15-17 diff). */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_003A5388 */
typedef struct {
    vu0_v4 v[4];
} V4x4_003A5388;

typedef struct {
    V4x4_003A5388 v;
    u32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_003A5388;

typedef struct {
    s32 i0;
    f32 f4;
    u8 pad8[0x8];
    f32 f10;
    u8 pad14[0x8];
    u8 b1C;
    u8 b1D;
    u8 b1E;
} S_003A5388;

typedef struct {
    u8 pad0[0x68];
    S_003A5388 *p68;
} A_003A5388;

extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern long func_00389598(s32);
extern void func_003D2DA0(void *, void *, s32);

void func_L03_003A5388(A_003A5388 *a) {
    S_003A5388 *s = a->p68;
    u8 *e = D_L03_001DFA80 + (s->i0 << 7);
    Q_003A5388 q;
    vu0_v4 m[4];
    f32 scale;
    f32 h;
    f32 sn;
    f32 cs;
    f32 lo;
    f32 hi;
    u32 color;
    s32 i;

    func_0038D570(m, e);
    *(vu0_q *)&m[3] = *(vu0_q *)(e + 0x30);
    m[3].w = 1.0f;
    scale = s->f4;
    color = ((s32)(scale * 20.0f) << 24) | (s->b1E << 16) | (s->b1D << 8) | s->b1C;
    h = scale * scale * 0.2f;
    sn = func_0038D098(s->f10) * 0.08f;
    cs = func_0038D0B0(s->f10) * 0.08f;
    q.x78 = func_00389598(0x1E);
    q.x80 = 0xFF9000000260L;
    q.x70 = 4;
    q.x88 = 0x8000000048L;
    lo = 0.5f - h;
    hi = h + 0.5f;
    q.color[3] = color;
    q.color[2] = color;
    q.color[1] = color;
    q.color[0] = color;
    q.uv[0][0] = lo + sn;
    q.uv[0][1] = hi + cs;
    q.uv[1][0] = hi - cs;
    q.uv[1][1] = hi + sn;
    q.uv[2][0] = lo - sn;
    q.uv[2][1] = lo - cs;
    q.uv[3][0] = hi + cs;
    q.uv[3][1] = lo - sn;
    for (i = 0; i < 6; i++) {
        q.v = *(V4x4_003A5388 *)D_L03_002BA370[i];
        func_003D2DA0(&q, m, 0);
    }
}
/* localdecomp:end func_L03_003A5388 */
