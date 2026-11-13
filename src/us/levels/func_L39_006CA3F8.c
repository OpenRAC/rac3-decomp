#include "common.h"

/* localdecomp:start func_L39_006CA3F8 */
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 pad30[0x20];
} Loc_006CA3F8;
typedef struct {
    u8 pad00[0x2E];
    u8 f2E;
    u8 pad2F[0x130 - 0x2F];
    s32 f130;
} S_006CA3F8;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} G_006CA3F8;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006CA3F8;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017E708(void *, void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
void func_L39_005945F0(void *, void *, s32);
extern s32 func_L39_006D5F80(void *);
extern s32 func_L39_006CA708(void *, void *, void *);
extern s32 func_L39_006CA8B0(void *, s32);
extern u8 D_001A5E50[];
extern u8 D_00197768[];
extern u16 D_L39_00249C98[];
__asm__(".extern D_001E1FD0_sda, 4");
extern G_006CA3F8 *D_001E1FD0_sda;

s32 func_L39_006CA3F8(S_006CA3F8 *arg0, void *arg1, void *arg2) {
    Loc_006CA3F8 loc;
    G_006CA3F8 *g;
    P_006CA3F8 *p;
    s32 r;

    g = D_001E1FD0_sda;
    if (func_L39_006CA708(arg0, arg1, arg2) == 0) {
        return 0;
    }
    loc.f00 = D_L39_00249C98[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    func_L39_005945F0((u8 *)&loc + 0x26, arg2, 0x20);
    arg0->f2E = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E708(&loc, D_00197768, 0));
    p = (P_006CA3F8 *)D_001A5E50;
    while (arg0->f2E != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0xD;
            if (g->f14 == 0) {
                g->f14 = 0xD;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (func_L39_006D5F80((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f2E = 0;
    if (r != 0) {
        if (arg0->f130 != 0) {
            g->f10 = 0xD;
            if (g->f14 == 0) {
                g->f14 = 0xD;
            }
            r = 0;
        }
    }
    if (func_L39_006CA8B0(arg0, 1) == 0) {
        return 0;
    }
    if (r != 0) {
        g->f10 = 0;
        g->f14 = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006CA3F8 */
