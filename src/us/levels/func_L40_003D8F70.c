#include "common.h"

/* NTSC-U counterpart of func_L40_003D9160 (src/levels/shared/L40_003D8FB0.c) */
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);
extern s32 *func_L39_006699B0(void);
extern void func_L40_003D8F70(u8 *);
extern u8 D_001A5E50[];

/* localdecomp:start func_L40_003D8F70 */
typedef struct { u8 pad[0x88]; s32 a[1]; } S_003D9160;
extern void *D_L40_003575EC[];
extern u8 D_001A5E50[];
extern s32 func_L40_0053B8F8(u8 *m, s32 team, s32 a2, f32 range, f32 b, f32 c, void *a3);
extern u8 *func_L39_0061AA60(s32);
extern void func_003BDA38(void *, s32, void *);
extern s32 func_L40_003EB788(void *, s32, s32, s32);
extern s32 *func_L39_006699B0(void);
extern s32 func_L39_00669978(s32, void *, s32, void *, void *);
extern s32 func_L39_006698E8(s32);

void func_L40_003D8F70(u8 *a0) {
    u8 *r;
    s32 w;
    s32 id;
    u8 *t;
    u8 *e;
    u8 *x;
    s32 *n;
    s32 v;
    f32 buf[4] __attribute__((aligned(16)));

    r = *(u8 **)(a0 + 0x68);
    w = **(s32 **)(a0 + 0x90);
    switch (*(s32 *)(r + 0x1B4)) {
    case 0:
        *(s32 *)(r + 0x1B4) = 1;
        break;
    case 1:
        t = *(u8 **)(r + 0x1A8);
        id = -1;
        if (t == 0 || t[0x31] == 0 || *(s16 *)(*(u8 **)(t + 0x1C) + 0xAA) != 0x109A) {
            id = -1;
            if (++*(s32 *)(r + 0x1D4) >= 11) {
                id = func_L40_0053B8F8(a0, ((S_003D9160 *)D_L40_003575EC[0])->a[*(s32 *)(r + 0x1A0)], 0,
                                       *(f32 *)(r + 0x1C8), -1.0f, 10.0f, 0);
                if (id == -1) {
                    return;
                }
                e = func_L39_0061AA60(id);
                if (e != 0 && (e[3] & 0xF) == 0 && (x = *(u8 **)(e + 0x2528)) != 0 &&
                    *(s16 *)(*(u8 **)(x + 0x2D0) + 0xAA) == 0x107E) {
                    id = -1;
                }
                if (id == -1) {
                    return;
                }
                *(s32 *)(r + 0x1D4) = 0;
            }
        }
        if (id != -1) {
            func_003BDA38(a0, 0, buf);
            v = func_L40_003EB788(buf, *(s32 *)(r + 0x1A0), *(s32 *)(r + 0x1D0), -1);
            *(s32 *)(r + 0x1B8) = 0;
            *(s32 *)(r + 0x1B4) = 2;
            *(s32 *)(r + 0x1AC) = v;
            n = func_L39_006699B0();
            if (n != 0) {
                *n = func_L39_00669978(1, (void *)w, *(s32 *)(D_001A5E50 + 0x128) + 500, 0, n);
            }
        }
        break;
    case 2:
        if (*(s32 *)(r + 0x1CC) < ++*(s32 *)(r + 0x1B8)) {
            *(s32 *)(r + 0x1B4) = 1;
            *(s32 *)(r + 0x1A8) = func_L39_006698E8(*(s32 *)(r + 0x1AC));
        }
        break;
    }
}
/* localdecomp:end func_L40_003D8F70 */
