#include "common.h"

/* NTSC-U counterpart of func_L03_003307D0 (src/levels/03_starship_phoenix/L03_0032FBA8.c) */
#include "vu0.h"

/* localdecomp:start func_L03_00330100 */
#include "vu0.h"
/* the quad descriptor of func_003CD830, laid out as in func_L05_003B27F8 */
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_003307D0;
typedef struct { u8 pad0[0xE0]; f32 scroll[2]; u8 padE8[0xFC - 0xE8]; u8 bFC; } S_003307D0;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003307D0 *p68; } A_003307D0;
extern f32 D_001DD150_sda[2];
__asm__(".extern D_001DD150_sda, 8");
extern long func_00384EC0(s32);
extern void func_003A3EF0(s32, unsigned long);
extern void func_003CD830(void *, s32, s32);

/* corner i of the quad: 0 and 1 on the left, 1 and 3 at the top */
static __inline__ s32 left_003307D0(s32 i) { return i < 2; }
static __inline__ s32 top_003307D0(s32 i) { return i & 1; }

void func_L03_00330100(void *arg) {
    A_003307D0 *a = arg;
    S_003307D0 *s = a->p68;
    vu0_v4 pos;
    Q_003307D0 q;
    f32 off[4];
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    for (i = 0; i < 2; i++) {
        s->scroll[i] = s->scroll[i] + D_001DD150_sda[i];
        if (s->scroll[i] > 1.0f) s->scroll[i] = s->scroll[i] - 1.0f;
    }
    pos = a->pos;
    q.x78 = func_00384EC0(s->bFC + 0x64);
    q.x80 = 0xFF9000000260L;
    q.x88 = 0x800000006AL;
    q.x70 = 0;
    q.color[3] = (s32)0xFFFF8040;
    q.color[2] = (s32)0xFFFF8040;
    q.color[1] = (s32)0xFFFF8040;
    q.color[0] = (s32)0xFFFF8040;
    for (j = 0; j < 4; j++) {
        if (left_003307D0(j)) q.uv[j][0] = -7.0f; else q.uv[j][0] = 7.0f;
        if (top_003307D0(j)) q.uv[j][1] = -7.0f; else q.uv[j][1] = 7.0f;
    }
    for (k = 0; k < 4; k++) {
        qzero(off);
        {
            s32 axis = (u32)(k - 1) < 2;
            f32 sign = left_003307D0(k) ? 1.0f : -1.0f;
            off[axis] = sign * 75.0f;
        }
        vec_add_ab(&q.v[k], &pos, off);
    }
    func_003A3EF0(0x47, 0x51001);
    func_003CD830(&q, 0, 0);
    q.x78 = func_00384EC0(s->bFC + 0x64);
    q.x88 = 0x8000000058L;
    for (m = 0; m < 4; m++) {
        q.uv[m][0] = s->scroll[0] + (left_003307D0(m) ? -6.0f : 6.0f);
        q.uv[m][1] = s->scroll[1] + (top_003307D0(m) ? -6.0f : 6.0f);
    }
    func_003CD830(&q, 0, 0);
    func_003A3EF0(0x47, 0x5360B);
}
/* localdecomp:end func_L03_00330100 */
