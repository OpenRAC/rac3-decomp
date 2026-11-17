#include "common.h"

typedef struct {
    u8 p00[0x34];
    u16 f34;
    u8 p36[0x49];
    u8 f7F;
    u8 p80[0x18];
    s32 f98;
    u8 p9C[0xC];
    u8 fA8;
} S_00334740;
typedef struct {
    f32 f0;
    s16 h4;
    u8 p6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 pA[0x2E];
    s16 f38;
} R_00334740;

/* localdecomp:start func_L07_003346D8 */
extern void *func_L07_00333918();
extern s32 D_L07_001DCE98[2];
s32 func_L07_003346D8(u8 *arg0) {
    u8 *o = func_L07_00333918(arg0);
    s32 v = D_L07_001DCE98[o[0x1D]];
    s32 h;
    if (v == -1) {
        return 1;
    }
    if ((u8)(o[0x1C] - 2) < 2) {
        return 1;
    }
    h = *(s16 *)(o + 0xC);
    if (h == -1) {
        return 0;
    }
    return h < v;
}
/* localdecomp:end func_L07_003346D8 */

/* localdecomp:start func_L07_00334740 */
extern R_00334740 *func_00382348(S_00334740 *);
extern R_00334740 *func_L01_00448FF0(S_00334740 *);
extern void *func_L07_00333918(S_00334740 *);
extern void func_L01_004AA7E8(S_00334740 *, s32);
extern void func_L03_0032F600(S_00334740 *);
extern void func_L03_0032DA08(S_00334740 *);
extern void func_L07_003310E8(s32, S_00334740 *);

void func_L07_00334740(S_00334740 *o) {
    R_00334740 *r;
    R_00334740 *q;
    void *p;

    o->f7F = 0;
    r = func_00382348(o);
    r->f0 = (f32)r->h4;
    q = func_L01_00448FF0(o);
    if (q != 0) {
        q->f38 = 0;
        q->f7 = 0;
        q->f9 = 0;
        q->f8 = 0;
    }
    p = func_L07_00333918(o);
    o->fA8 = 0xFF;
    o->f98 = 0;
    o->f34 = (o->f34 | 0x41) & 0xEFFF;
    func_L01_004AA7E8(o, 1);
    o->f34 = o->f34 | 6;
    func_L03_0032F600(o);
    func_L03_0032DA08(o);
    func_L07_003310E8(*(s32 *)p, o);
}
/* localdecomp:end func_L07_00334740 */

/* localdecomp:start func_L07_00334800 */
#include "vu0.h"
extern R_00334740 *func_00382348(S_00334740 *);

void func_L07_00334800(u8 *obj) {
    u8 *r = (u8 *)func_00382348((S_00334740 *)obj);

    r[0x2E] = 0;
    r[0x30] = 0;
    r[0x2F] = 0;
    if (r[0xE] != 3) {
        r[0xE] = 1;
    }
    *(u16 *)(obj + 0x34) &= 0xBFB8;
    *(s32 *)(obj + 0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
    qzero(obj + 0xF0);
}
/* localdecomp:end func_L07_00334800 */

/* localdecomp:start func_L07_00334868 */
u8 func_L07_00334868(void *arg0) {
    return (*(u8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0xA8));
}
/* localdecomp:end func_L07_00334868 */

/* localdecomp:start func_L07_00334878 */
typedef struct P_00334878 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    s32 w4;
    s32 w8;
} P_00334878;

extern s32 func_L07_00333460(s32, s32);

void func_L07_00334878(s32 idx, s32 *out0, s32 *out1, s32 *out2) {
    P_00334878 *p = (P_00334878 *)func_L07_00333460(idx, -1);

    if (p != 0) {
        *out0 = p->b1 != 0 ? 0xEC54 : 0;
        *out1 = p->b0 == 0 ? 0xEC56 : (p->b2 != 0 ? 0xEC57 : (p->w4 == -1 ? 0 : 0xEC5A));
        *out2 = p->w8 != -1 ? 0xEC58 : (p->b3 != 0 ? 0xEC59 : 0);
    } else {
        *out0 = *out1 = *out2 = 0xEC5B;
    }
}
/* localdecomp:end func_L07_00334878 */
