#include "common.h"

/* NTSC-U counterpart of func_L39_005DD3C0 (src/levels/shared/L39_005DD3C0.c) */
extern u8 *D_L39_0024C05C;
extern void func_L01_0044E108(u8 *, s32 *, s32 *);
typedef struct {
    u8 pad[136];
    s32 f88[2];
} S_005DD258;
extern S_005DD258 *D_L39_00352C4C[];
typedef struct {
    u8 pad40[0x40];
    s32 f40[8];
    s32 f60[8];
    u8 pad80[0x28];
    s32 fA8[8];
} S_005DD290_e;
typedef struct {
    u8 pad[0x20C];
    S_005DD290_e *f20C;
} S_005DD290_t;
typedef struct {
    u8 pad[0xC60];
    s32 fC60;
    s32 fC64;
} S_005DD290_g;
extern S_005DD290_t D_L39_00352A40;
extern long func_L39_005DACB0(u8 *);

/* localdecomp:start func_L39_005DAE18 */
#include "vu0.h"

typedef struct V4_005DD3C0 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_005DD3C0;

__asm__(".extern D_L39_0024C500_005DAE18, 16");
extern s32 D_L39_0024C500_005DAE18[2];
extern s32 func_L08_004EA298_005DAE18(s32);
extern f32 func_00388730(void *, void *);
extern f32 func_00388990(f32);
extern f32 func_L01_0040C018(void *, void *);
extern void func_00388830(void *, void *, f32);

void func_L39_005DAE18(u8 *p)
{
    V4_005DD3C0 dir;
    V4_005DD3C0 pos;
    V4_005DD3C0 tgt;
    V4_005DD3C0 d;
    s32 flag;
    s32 i;
    s32 best;
    s32 alt;
    f32 bestScore;
    u32 b;

    qzero(&dir);
    b = *(u32 *)(*(u8 **)(p + 0x2534) + 0x1C4);
    if (b & 0x4000) {
        dir.y = 1.0f;
    } else if (b & 0x1000) {
        dir.y = -1.0f;
    }
    b = *(u32 *)(*(u8 **)(p + 0x2534) + 0x1C4);
    if (b & 0x8000) {
        dir.x = -1.0f;
    } else if (b & 0x2000) {
        dir.x = 1.0f;
    }
    flag = 0;
    if (dir.x != 0.0f || dir.y != 0.0f) {
        flag = 1;
    }
    qzero(&pos);
    func_L39_005DACE8(p, (s32 *)&pos.x, (s32 *)&pos.y);
    if (flag) {
        D_L39_0024C500_005DAE18[p[0x24C9]] = 12;
    }
    if (!flag && func_L08_004EA298_005DAE18((*(S_005DD290_g **)(p + 0x2558))->fC64) == 0) {
        return;
    }
    if (flag) {
        func_00388830(&dir, &dir, 1.0f);
    }
    bestScore = 100000.0f;
    best = -1;
    alt = -1;
    for (i = 0; i < 8; i++) {
        S_005DD290_e *e;
        s32 k;
        u8 *m;
        if (i == (*(S_005DD290_g **)(p + 0x2558))->fC64) {
            continue;
        }
        e = D_L39_00352A40.f20C;
        k = e->f60[i];
        if (k < 0) {
            continue;
        }
        if (e->fA8[i] != *(s32 *)(p + 0x2548)) {
            continue;
        }
        m = D_L39_0024C05C + (k << 8);
        if (func_L08_004EA298_005DAE18(i) != 0) {
            continue;
        }
        qzero(&tgt);
        func_L01_0044E108(m, (s32 *)&tgt.x, (s32 *)&tgt.y);
        vec_sub_ab(&d, &tgt, &pos);
        func_00388830(&d, &d, 1.0f);
        {
            f32 dot = func_00388730(&dir, &d);
            if (dot > 0.0f || !flag) {
                f32 a = fabs_asm(1.5707964f - func_00388990(dot));
                f32 dist = func_L01_0040C018(&pos, &tgt);
                f32 score;
                dist *= 100.0f;
                a *= 100.0f;
                score = dist + dist * a;
                if (best == -1 || score < bestScore) {
                    bestScore = score;
                    best = i;
                }
            }
        }
    }
    if ((*(S_005DD290_g **)(p + 0x2558))->fC60 == -1) {
        s32 j = ((s32 (*)(u8 *))func_L39_005DACB0)(p);
        u8 *m = D_L39_0024C05C + (((S_005DD290_e *)D_L39_00352C4C[0])->f40[j] << 8);
        qzero(&tgt);
        func_L01_0044E108(m, (s32 *)&tgt.x, (s32 *)&tgt.y);
        vec_sub_ab(&d, &tgt, &pos);
        func_00388830(&d, &d, 1.0f);
        {
            f32 dot = func_00388730(&dir, &d);
            if (dot > 0.0f) {
                f32 a = fabs_asm(1.5707964f - func_00388990(dot));
                f32 dist = func_L01_0040C018(&pos, &tgt);
                f32 score;
                dist *= 100.0f;
                a *= 100.0f;
                score = dist + dist * a;
                if (best == -1 || score < bestScore) {
                    alt = j;
                    best = -1;
                }
            }
        }
    }
    if (func_L08_004EA298_005DAE18((*(S_005DD290_g **)(p + 0x2558))->fC64) != 0) {
        (*(S_005DD290_g **)(p + 0x2558))->fC64 = -1;
        (*(S_005DD290_g **)(p + 0x2558))->fC60 = alt;
    }
    if (best != -1) {
        (*(S_005DD290_g **)(p + 0x2558))->fC64 = best;
        (*(S_005DD290_g **)(p + 0x2558))->fC60 = -1;
    } else if (alt != best) {
        (*(S_005DD290_g **)(p + 0x2558))->fC64 = best;
        (*(S_005DD290_g **)(p + 0x2558))->fC60 = alt;
    }
}
/* localdecomp:end func_L39_005DAE18 */
