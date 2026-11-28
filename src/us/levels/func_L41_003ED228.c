#include "common.h"
/* localdecomp:start func_L41_003ED228 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003ED748;
typedef struct {
    f32 x, y, z, w;
    s32 a2;
    s32 uid;
    s32 x18;
    s32 x1C;
    s32 a5;
    s32 a6;
    s32 index;
} Msg_003ED748;
typedef struct { u8 pad[0x100]; } M_003ED748;

extern s16 *D_L41_0028ECE0[];
extern s32 D_L41_00248818;
extern M_003ED748 *D_L41_002487DC;
typedef struct { u8 pad[0x128]; s32 time; } G_003ED748;
extern G_003ED748 D_001A5E50;
extern u8 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32 type, s32 uid, s32 time, s32 kind, u8 *msg);
extern s32 func_00197588(s32 n);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern void func_L41_0053D1A8(s32, s32, s32 *);

void func_L41_003ED228(V_003ED748 *pos, s32 idx, s32 a2, s32 *out, s32 a4, s32 a5, s32 a6) {
    V_003ED748 tmp;
    s32 ids[5];
    s32 list[8];
    V_003ED748 v;
    u8 *msg;
    s16 *s;
    M_003ED748 *m;
    s32 n;
    s32 i;
    s32 uid;
    s32 second;
    s32 off;
    f32 ang;
    Msg_003ED748 *q;
    V_003ED748 *p;
    s32 *w;

    tmp = *pos;
    p = &tmp;
    msg = func_L39_006699B0();
    n = 0;
    s = D_L41_0028ECE0[idx];
    while ((idx & 0xFF) != 0xFF && idx <= D_L41_00248818 && s != 0
           && (s[-1] >= 0 || s == D_L41_0028ECE0[idx])) {
        m = &D_L41_002487DC[*s & 0x7FFF];
        if (m == 0) break;
        list[n++] = m - D_L41_002487DC;
        s++;
    }
    if (msg == 0) return;
    ang = 3.1415927f;
    uid = func_00197588(2);
    second = func_00197588(2);
    ids[0] = uid;
    off = func_L39_00669978(0, uid, D_001A5E50.time + 0x1F4, 0x109D, msg);
    q = (Msg_003ED748 *)(msg + off);
    q->x = p->x;
    q->y = p->y;
    q->z = p->z;
    q->w = p->w;
    w = (s32 *)&q->a2;
    w[0] = a2;
    w[1] = second;
    w[2] = 0x539;
    w[3] = 0;
    w[4] = a5;
    w[5] = a6;
    w[6] = list[0];
    *(s32 *)msg = off + 0x2C;
    out[0] = uid;
    for (i = 1; i < 5; i++) {
        s32 noff;
        Msg_003ED748 *r;

        v.x = func_00388960(ang) * 2.0f;
        v.y = func_00388978(ang) * 2.0f;
        v.z = 0.0f;
        ang = func_00389380(ang, 0.5235988f);
        vec_add_ab(&v, &v, p);
        msg = func_L39_006699B0();
        if (msg == 0) return;
        uid = func_00197588(2);
        noff = func_L39_00669978(0, uid, D_001A5E50.time + 0x1F4, 0x109D, msg);
        r = (Msg_003ED748 *)(msg + noff);
        r->x = v.x;
        r->y = v.y;
        r->z = v.z;
        r->w = v.w;
        r->a2 = a2;
        r->uid = second;
        r->x18 = 0;
        r->x1C = 0;
        r->a5 = a5;
        r->a6 = a6;
        r->index = list[i];
        ids[i] = uid;
        out[i] = uid;
        *(s32 *)msg = noff + 0x2C;
    }
    func_L41_0053D1A8(second, i, ids);
}
/* localdecomp:end func_L41_003ED228 */
