#include "common.h"

/* localdecomp:start func_L39_005F3B18 */
#include "vu0.h"

typedef struct {
    u8 f0;
    s8 s[3];
    char _p4[4];
    f32 f8;
    char _pC[4];
    s32 f10;
    char *f14;
    s32 f18;
    char _p1C[0x40 - 0x1C];
    vu0_q f40;
    vu0_q f50;
} S_005F3B18;

extern u8 D_001FE020[];
extern u8 D_L39_0024DE80[];
s32 func_L39_005F3488(s32, s32, char *, s32);
s32 func_L39_005F33E0(s32, s32, char *);
void func_L39_005F3088(s32);
s32 func_L39_005F3760(u32, s32);
void func_L01_004464C8(void *, void *, void *, void *);
f32 func_L01_0040E548(void *, void *);

void func_L39_005F3B18(S_005F3B18 *arg0) {
    vu0_q v;
    f32 d;
    f32 t;
    f32 vol;
    s32 i;
    s32 n;
    s8 *p;
    s8 *q;

    q = &arg0->s[0];
    for (i = 0, p = q; i < 3; i++, p++) {
        if (*p != -1) {
            u8 *g = D_001FE020 + (*p << 7);
            if (*(char **)(g + 0xDC) == arg0->f14 && g[0xD0] != 0) {
                continue;
            }
        }
        if (arg0->f18 != -1) {
            *p = func_L39_005F3488(arg0->f10, 0x1C, arg0->f14, arg0->f18);
        } else {
            *p = func_L39_005F33E0(arg0->f10, 0x1C, arg0->f14);
        }
    }
    func_L01_004464C8(&v, &arg0->f40, &arg0->f50, D_L39_0024DE80);
    d = func_L01_0040E548(&v, D_L39_0024DE80);
    if (arg0->f8 * arg0->f8 < d) {
        s8 none = -1;
        for (i = 0, p = q; i < 3; i++, p++) {
            if (*p != none) {
                u8 *g = D_001FE020 + (*p << 7);
                if (*(char **)(g + 0xDC) == arg0->f14 && g[0xD0] != 0) {
                    func_L39_005F3088(*p);
                }
            }
            *p = -1;
        }
        return;
    }
    t = sqrt_asm(d) * (1.0f / arg0->f8);
    vol = 0.0f;
    if (t < 1.0f) {
        vol = 1.0f - t;
    }
    n = (s32)(vol * 1024.0f);
    if (arg0->s[0] != -1) {
        u8 *g = D_001FE020 + (arg0->s[0] << 7);
        if (*(char **)(g + 0xDC) == arg0->f14 && g[0xD0] != 0) {
            func_L39_005F3760(arg0->s[0], n);
            *(vu0_q *)(D_001FE020 + (arg0->s[0] << 7) + 0xE0) = v;
        }
    }
    if (arg0->s[1] != -1) {
        u8 *g = D_001FE020 + (arg0->s[1] << 7);
        if (*(char **)(g + 0xDC) == arg0->f14 && g[0xD0] != 0) {
            func_L39_005F3760(arg0->s[1], n);
            *(vu0_q *)(D_001FE020 + (arg0->s[1] << 7) + 0xE0) = arg0->f40;
        }
    }
    if (arg0->s[2] != -1) {
        u8 *g = D_001FE020 + (arg0->s[2] << 7);
        if (*(char **)(g + 0xDC) == arg0->f14 && g[0xD0] != 0) {
            func_L39_005F3760(arg0->s[2], n);
            *(vu0_q *)(D_001FE020 + (arg0->s[2] << 7) + 0xE0) = arg0->f50;
        }
    }
}
/* localdecomp:end func_L39_005F3B18 */
