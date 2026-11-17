#include "common.h"

/* declared by functions of L39_00629DE0.c, which this file was cut from */
typedef int q128 __attribute__((mode(TI)));

/* localdecomp:start func_L39_0062B4A8 */
typedef struct { u8 pad[17]; u8 b11; } Info_0062B4A8;
typedef struct { u8 pad[72]; Info_0062B4A8 *info[1]; } Tbl_0062B4A8;
typedef struct {
    u8 pad0[36];
    Tbl_0062B4A8 *tbl;
    u8 pad28[0x40 - 0x28];
    u8 b40; u8 b41; u8 b42; u8 b43;
    f32 f44;
    u8 pad48[0x6C - 0x48];
    u8 b6C;
    u8 pad6D[0x7E - 0x6D];
    u8 b7E;
    u8 pad7F[0xA9 - 0x7F];
    u8 bA9;
} Sub_0062B4A8;
typedef struct {
    u8 pad0[0x610];
    f32 f610;
    f32 f614;
    s32 w618;
    s32 w61C;
    s32 w620;
    s32 w624;
    u8 pad628[0x1A05 - 0x628];
    u8 b1A05;
    u8 pad1A06[0x2448 - 0x1A06];
    s32 w2448;
    u8 pad244C[0x2524 - 0x244C];
    Sub_0062B4A8 *sub;
} Obj_0062B4A8;
extern q128 D_L39_00271500[];
extern s32 func_003C2D30(void *);
extern void func_003C8B18(void *, s32);
extern void func_001264E0(s32);
extern void func_003C29B0(void *);
extern void func_003C6EA0(void *, s32, u16);
extern void func_L39_0062B718(void *);
extern void func_L39_00622288(void *);

void func_L39_0062B4A8(Obj_0062B4A8 *o, s32 a1, s32 a2, s32 a3, f32 f) {
    Sub_0062B4A8 *s = o->sub;
    s32 idx;
    if (o->w618 & 2) {
        s->f44 = 0;
    }
    idx = func_003C2D30(s);
    if (idx >= 0) {
        func_003C8B18(s, idx | 0x300);
        func_001264E0(0);
        D_L39_00271500[idx] = *(q128 *)s;
        if (s->b42 != 0xFF) {
            s->bA9 = s->b42;
        }
        D_L39_00271500[idx] = *(q128 *)((u8 *)s + 0x80);
        s->b42 = 0xFF;
        s->b40 = idx;
    }
    s->b41 = a2;
    s->b43 = a1;
    func_003C29B0(s);
    if ((u32)(a2 - 1) < 11 && !(a3 & 8)) {
        func_003C6EA0(s, a1, a2);
    }
    o->f610 = 1.0f;
    if (f > 0.0f) {
        o->f614 = 1.0f / f;
        s->f44 = 0;
        o->w620 = -1;
    } else {
        o->f614 = 1.0f;
        o->w624 = 0;
        o->w620 = (s32)-f - 1;
        s->f44 = 0;
    }
    func_L39_0062B718(o);
    s->b6C = s->tbl->info[a1]->b11;
    if (a3 & 0x10) {
        s->b7E |= 4;
    } else {
        s->b7E &= ~4;
    }
    o->w61C = 1;
    if (o->b1A05 == 0 && a1 != o->w2448) {
        func_L39_00622288(o);
    }
}
/* localdecomp:end func_L39_0062B4A8 */
