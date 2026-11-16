#include "common.h"

/* NTSC-U counterpart of func_L39_004BA760 (src/levels/39_multiplayer_menu/L39_004B9160.c) */
extern s32 func_L39_004D0A78(void);
extern s32 func_001205B0(char *, char *);

/* localdecomp:start func_L39_004BA560 */
#include "dnas.h"

extern void *func_L39_004CC600(void);
extern void func_L39_004CC610(void *, void *, s32);
extern s32 func_L39_004BBD08_004BA560(void *);
extern void *func_L39_004BBD50_004BA560(void *, s32);
extern s32 func_L39_004BBD98_004BA560(void *, s32, s32 *, s64 *, s32 *, char **, s32 *);
extern char *func_L39_004BC2F8(s32, s64, s32);
extern void func_L39_004BD150(s32, s32, s32, u32);
extern s32 func_001205B0(char *, char *);
extern void func_00120D28(void *, void *, s32);
extern char D_L39_004751A8[];
extern char D_L39_004751B8[];

static __inline__ void fill_random_004BA760(u8 *p, u32 size) {
    u32 i;

    for (i = 0; i < size; i++) {
        p[i] = func_L39_004D0A78() / 2147483647.0f * 256.0f;
    }
}

s32 func_L39_004BA560(void) {
    u8 buf[0x2000];
    u8 host[0x100];
    s32 a;
    s64 b;
    s32 c;
    char *d;
    s32 e;
    void *ctx;
    s32 n;
    s32 i;
    s32 ret;
    char *name;

    ctx = func_L39_004CC600();
    func_L39_004CC610(ctx, buf, 0x2000);
    n = func_L39_004BBD08_004BA560(ctx);
    for (i = 0; i < n; i++) {
        if (func_L39_004BBD98_004BA560(func_L39_004BBD50_004BA560(ctx, i), 0, &a, &b, &c, &d, &e)) {
            name = func_L39_004BC2F8(a, b, 0);
            if (func_001205B0(name ? name : D_L39_004751A8, D_L39_004751B8) == 0) {
                break;
            }
        }
    }
    if (i == n) {
        ret = -1;
    } else {
        DNAS_BEGIN(func_L39_004BA560, 0, func_L39_004BD150);
        func_00120D28(host, DNAS_STRING("gate1.us.dnas.playstation.org"), 0x100);
        DNAS_END(func_L39_004BA560, 0, func_L39_004BD150);
        ret = 0;
        if (func_001205B0(d, (char *)host) != 0) {
            ret = -1;
        }
    }
    fill_random_004BA760(buf, 0x2000);
    fill_random_004BA760(host, 0x100);
    return ret;
}
/* localdecomp:end func_L39_004BA560 */
