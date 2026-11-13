/* near miss (level 3, Starship Phoenix): 19 differences, register allocation in two of the four small loops: the third loop's `slti` is scheduled before the -1.0f constant in retail, and in the last uv loop retail keeps the v pointer in $a2 with a copy in $v1 for the store (counter $a0, u pointer $a1), the C uses $a0/$a1 for the pointers and $a2 for the counter. Found: f32 off[4] with qzero, the index through an int (`(u32)(i - 1) < 2`, which otherwise becomes movn), func_003A9440(s32, unsigned long), one counter for the uv loops and separate ones for the others (all 15 groupings tried), if/else stores in the last loop */
#include "common.h"

/* localdecomp:start func_L03_003307D0 */
#include "vu0.h"
typedef struct {
    vu0_v4 v[4];
    s32 color[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} Q_003307D0;
typedef struct { u8 pad0[0xE0]; f32 scroll[2]; u8 padE8[0xFC - 0xE8]; u8 bFC; } S_003307D0;
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 pad20[0x48]; S_003307D0 *p68; } A_003307D0;
extern f32 D_001DD110_sda[2];
__asm__(".extern D_001DD110_sda, 8");
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D2DA0(void *, s32, s32);

void func_L03_003307D0(void *arg) {
    A_003307D0 *a = arg;
    S_003307D0 *s = a->p68;
    vu0_v4 pos;
    Q_003307D0 q;
    f32 off[4];
    int i;
    int j;
    int k2;
    for (i = 0; i < 2; i++) {
        s->scroll[i] = s->scroll[i] + D_001DD110_sda[i] * 1.2f;
        if (s->scroll[i] > 1.0f) s->scroll[i] = s->scroll[i] - 1.0f;
    }
    pos = a->pos;
    q.x78 = func_00389598(s->bFC + 0x64);
    q.x80 = 0xFF9000000260L;
    q.x88 = 0x800000006AL;
    q.x70 = 0;
    q.color[3] = (s32)0xFFFF8040;
    q.color[2] = (s32)0xFFFF8040;
    q.color[1] = (s32)0xFFFF8040;
    q.color[0] = (s32)0xFFFF8040;
    for (j = 0; j < 4; j++) {
        if (j < 2) q.uv[j][0] = -7.0f; else q.uv[j][0] = 7.0f;
        if (j & 1) q.uv[j][1] = -7.0f; else q.uv[j][1] = 7.0f;
    }
    for (k2 = 0; k2 < 4; k2++) {
        qzero(off);
        {
            int jx = (u32)(k2 - 1) < 2;
            f32 k = -1.0f;
            if (k2 < 2) k = 1.0f;
            off[jx] = k * 75.0f;
        }
        vec_add_ab(&q.v[k2], &pos, off);
    }
    func_003A9440(0x47, 0x51001);
    func_003D2DA0(&q, 0, 0);
    q.x78 = func_00389598(s->bFC + 0x64);
    q.x88 = 0x8000000058L;
    for (j = 0; j < 4; j++) {
        if (j < 2) q.uv[j][0] = s->scroll[0] + -6.0f; else q.uv[j][0] = s->scroll[0] + 6.0f;
        if (j & 1) q.uv[j][1] = s->scroll[1] + -6.0f; else q.uv[j][1] = s->scroll[1] + 6.0f;
    }
    func_003D2DA0(&q, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L03_003307D0 */
