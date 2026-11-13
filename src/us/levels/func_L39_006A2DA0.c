#include "common.h"

/* NTSC-U counterpart of func_L39_006A55B0 (src/levels/39_multiplayer_menu/L39_006A4510.c) */
/* localdecomp:start func_L39_006A2DA0 */
typedef struct S_006A55B0_item {
    char pad0[0x18];
    s32 f18;
    u8 f1C[4];
} S_006A55B0_item;

typedef struct S_006A55B0_list {
    s32 f0;
    s32 f4;
    S_006A55B0_item **f8;
} S_006A55B0_list;

typedef struct S_006A55B0_net {
    u8 f0;
    char pad1[0xC];
    u8 fD;
    char padE[6];
    S_006A55B0_list f14;
} S_006A55B0_net;

typedef struct S_006A55B0_g {
    char pad0[0x4C];
    void *f4C;
    char pad50[0x28];
    S_006A55B0_net *f78;
} S_006A55B0_g;

extern S_006A55B0_g *D_L39_0024D860;
extern u8 D_L39_00248790[];
extern u8 D_L39_00248798[];
extern u8 *func_L39_006D8BF8(void *);
extern s32 func_001200E0(void *, void *, ...);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_L39_006D4888(S_006A55B0_net *);
extern void func_00195500(void);
extern void func_L39_006D6030(S_006A55B0_g *);

u8 *func_L39_006A2DA0(void)
{
    s32 x;
    s32 y;
    S_006A55B0_net *net;
    S_006A55B0_list *list;
    u8 *r;
    u8 *name;
    s32 id;
    s32 start;
    s32 i;
    u8 c;
    s32 *px;
    s32 *py;

    net = D_L39_0024D860->f78;
    list = net->fD ? &net->f14 : 0;
    r = func_L39_006D8BF8(D_L39_0024D860->f4C);
    if (r == 0) {
        return 0;
    }
    name = r + 0x1C;
    px = &x;
    py = &y;
    if (name[0] == 'C') {
        c = name[1];
        if (c == 'Y' || c == 'R') {
            func_001200E0(r + 0x1E, D_L39_00248790, px, py);
        } else if (c == 'C') {
            func_001200E0(r + 0x1E, D_L39_00248798, px);
        }
    } else if (name[0] == 'H') {
        func_001200E0(r + 0x1E, D_L39_00248790, px, py);
    }
    id = x + 0x28;
    start = func_00130760(func_0012DCB0(), 0x24000);
    while (list == 0) {
        func_L39_006D4888(net);
        c = net->f0;
        if (c) {
            do {
                func_00195500();
                if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                    return 0;
                }
                if (D_L39_0024D860 != 0) {
                    func_L39_006D6030(D_L39_0024D860);
                }
            } while (net->f0);
        }
        list = net->fD ? &net->f14 : 0;
    }
    for (i = 0; i < list->f4; i++) {
        if (list->f8[i]->f18 == id) {
            return list->f8[i]->f1C;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_006A2DA0 */
