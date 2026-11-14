#include "common.h"

/* NTSC-U counterpart of func_L39_006DD860 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
extern void *D_L39_0024D860;
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
s32 func_00183CCC(void);
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
void func_001962D8(s32);
extern void *D_L39_0024D860;
void func_001962D8(s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_001962E8();
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
s32 func_001962E8();
void func_001962D8(s32);
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();

/* localdecomp:start func_L39_006DAD00 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0x40 - 0x2C];
} Loc_006DD860;
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x50 - 0x18];
    s32 f50;
} G_006DD860;
typedef struct {
    char _p0[0x2F89];
    u8 f2F89;
    u8 f2F8A;
    char _p2F8B;
    s32 f2F8C;
} S_006DD860;

__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
void func_0014B008(void *);
s32 func_0017F248(void *, void *, s32);
s32 func_0017F1C8(void *, void *, s32);
void func_00198078(void);

s32 func_L39_006DAD00(void *arg0, s32 arg1) {
    S_006DD860 *a = arg0;
    Loc_006DD860 loc;
    G_006DD860 *g;
    s32 r;
    s32 t;

    g = D_L39_0024D860;
    t = g->f50;
    a->f2F89 = 1;
    a->f2F8A = arg1;
    r = 1;
    if (arg1 != 0) {
        loc.f00 = D_L39_0024A120[0];
        func_001206F4((u8 *)&loc + 0x15, t);
        loc.f28 = func_00183CCC();
        a->f2F8C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008((u8 *)&loc + 0x30);
        func_001962D8(func_0017F248(&loc, func_00198078, 0));
    } else {
        loc.f00 = D_L39_0024A120[0];
        func_001206F4((u8 *)&loc + 0x15, t);
        loc.f28 = func_00183CCC();
        a->f2F8C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008((u8 *)&loc + 0x34);
        func_001962D8(func_0017F1C8(&loc, func_00198078, 0));
    }
    if (func_001962E8() != 0) {
        g->f10 = 0x53;
        if (g->f14 == 0) {
            g->f14 = 0x53;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006DAD00 */
