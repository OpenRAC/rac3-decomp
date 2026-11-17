#include "common.h"

/* localdecomp:start func_L39_0062B740 */
typedef struct { u8 pad[16]; u8 b16; } Info_0062B740;
typedef struct { u8 pad[72]; Info_0062B740 *info[1]; } Tbl_0062B740;
typedef struct { u8 pad0[36]; Tbl_0062B740 *tbl; u8 pad1[27]; u8 b67; u8 pad2[0x5C - 0x44]; f32 *p5C; } Sub_0062B740;
typedef struct {
    u8 pad[0x610];
    f32 f610;
    f32 f614;
    u8 pad2[4];
    s32 w61C;
    u8 pad3[8];
    f32 f628;
    u8 pad4[0x2524 - 0x62C];
    Sub_0062B740 *sub;
} Obj_0062B740;
extern f32 func_003C4138(f32 *, f32, f32);
void func_L39_0062B740(Obj_0062B740 *o, f32 a, f32 b, f32 c, f32 d) {
    f32 t;
    f32 v;
    if (o->f628 < a) {
        t = a - o->f628;
    } else {
        v = 2.0f;
        if (o->w61C == 0) {
            v = 0.5f / o->f614;
        }
        t = a + (v * o->sub->tbl->info[o->sub->b67]->b16 - o->f628);
    }
    if (b > 0.0f) {
        f32 w = o->f614;
        f32 r;
        if (o->w61C != 0) {
            w = *o->sub->p5C;
        }
        r = (c * t) / (b * w);
        if (d == -1.0f) {
            o->f610 = r;
        } else {
            func_003C4138(&o->f610, r, d);
        }
    }
}
/* localdecomp:end func_L39_0062B740 */
