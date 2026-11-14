#include "common.h"

/* localdecomp:start func_L39_006CA580 */
typedef struct {
    u8 p0[0x24];
    u8 f24;
    u8 p25[0x30 - 0x25];
    u8 f30;
    u8 f31;
    u8 p32[0x6C - 0x32];
    s32 f6C;
} M_L39_006CA580;
typedef struct {
    u8 p0[0x10];
    s32 f10;
    s32 f14;
    u8 p18[0x38];
    s32 f50;
    s32 f54;
} G_L39_006CA580;

extern G_L39_006CA580 *D_L39_0024D860;
__asm__(".extern D_L39_0024D860, 16");
extern u8 D_001A5E50[];
extern void func_00120D28(void *, void *, s32);
extern s32 func_L39_006CA708(void *, void *, void *);
extern s32 func_L39_006CA8B0(void *, s32);
extern s32 func_L39_006DA7E0(s32);
extern s32 func_L39_006DA500(s32, void *);
extern void func_L39_006DB288(s32);

s32 func_L39_006CA580(M_L39_006CA580 *a0, void *a1, void *a2) {
    u8 buf[0x21];
    G_L39_006CA580 *g = D_L39_0024D860;
    s32 h = g->f50;
    void *sel;

    func_00120D28(buf, a1, 0x20);
    buf[0x20] = 0;
    if (func_L39_006CA708(a0, buf, a2) == 0) {
        if (a0->f6C == -0x3DF) {
            func_L39_006CA8B0(a0, 0);
        reset:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            return 0;
        }
        if (a0->f6C != -0x3E5) {
            return 0;
        }
        if (func_L39_006CA8B0(a0, 0) == 0) {
            goto reset;
        }
        if (func_L39_006CA708(a0, buf, a2) == 0) {
            return 0;
        }
    }
    if (func_L39_006DA7E0(h) == 0) {
        return 0;
    }
    sel = 0;
    if (a0->f30 == 0) {
        if (a0->f31 == 0) {
            sel = (u8 *)a0 + 0x7C;
        }
    }
    if (func_L39_006DA500(h, sel) == 0) {
        return 0;
    }
    func_00120D28((u8 *)a0 + 4, buf, 0x20);
    a0->f24 = 0;
    func_00120D28(D_001A5E50 + 0x5E, buf, 0xE);
    D_001A5E50[0x6C] = 0;
    D_001A5E50[0x80] = 0;
    g->f10 = 0;
    g->f14 = 0;
    func_L39_006DB288(D_L39_0024D860->f54);
    return 1;
}
/* localdecomp:end func_L39_006CA580 */
