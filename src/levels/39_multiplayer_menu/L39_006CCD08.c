#include "common.h"

/* localdecomp:start func_L39_006CCD08 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
    s32 f54;
} G_006CCD08;
typedef struct {
    u8 pad0[4];
    u8 f4[0x20];
    u8 f24;
    u8 pad25[0xB];
    u8 f30;
    u8 f31;
    u8 pad32[0x3A];
    s32 f6C;
    u8 pad70[0xC];
    u8 f7C[4];
} S_006CCD08;
extern G_006CCD08 *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern void func_00120D28(void *, void *, s32);
extern s32 func_L39_006CCE90(S_006CCD08 *, u8 *, s32);
extern s32 func_L39_006CD038(S_006CCD08 *, s32);
extern s32 func_L39_006DD340(void *);
extern s32 func_L39_006DD060(void *, void *);
extern void func_L39_006DDDE8(void);

s32 func_L39_006CCD08(S_006CCD08 *arg0, void *arg1, s32 arg2) {
    G_006CCD08 *g = D_L39_0024D760;
    void *n;
    u8 *p;
    u8 buf[0x21];

    n = g->f50;
    func_00120D28(buf, arg1, 0x20);
    buf[0x20] = 0;
    if (func_L39_006CCE90(arg0, buf, arg2) == 0) {
        if (arg0->f6C == -0x3DF) {
            func_L39_006CD038(arg0, 0);
        fail:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            return 0;
        } else if (arg0->f6C == -0x3E5) {
            if (func_L39_006CD038(arg0, 0) == 0) {
                goto fail;
            }
            if (func_L39_006CCE90(arg0, buf, arg2) == 0) {
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (func_L39_006DD340(n) == 0) {
        return 0;
    }
    p = 0;
    if (arg0->f30 == 0) {
        if (arg0->f31 == 0) {
            p = arg0->f7C;
        }
    }
    if (func_L39_006DD060(n, p) == 0) {
        return 0;
    }
    func_00120D28(arg0->f4, buf, 0x20);
    arg0->f24 = 0;
    func_00120D28(D_001A5CD0 + 0x5E, buf, 0xE);
    D_001A5CD0[0x6C] = 0;
    D_001A5CD0[0x80] = 0;
    g->f10 = 0;
    g->f14 = 0;
    ((void (*)(s32))func_L39_006DDDE8)(D_L39_0024D760->f54);
    return 1;
}
/* localdecomp:end func_L39_006CCD08 */
