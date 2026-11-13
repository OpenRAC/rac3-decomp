#include "common.h"

/* NTSC-U counterpart of func_L39_006D2030 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern u16 D_L39_00249D58[];
void func_0014B008(void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void func_0014B008(void *);
extern u16 D_L39_00249D58[];
extern void func_0014B008(void *);

/* localdecomp:start func_L39_006CF8A8 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Loc_006D2030;
typedef struct {
    u8 pad0[0x494];
    s32 f494;
    s32 f498;
    u8 f49C;
    u8 pad49D[7];
    u8 f4A4;
    u8 pad4A5[3];
    s32 f4A8;
    u8 pad4AC[4];
    s32 f4B0;
} S_006D2030;
extern u16 D_L39_00249D58[];
extern u8 D_00197A88[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern s32 func_0017D908(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006CF8A8(S_006D2030 *p, s32 a, s32 b, s32 c) {
    s32 r = 1;
    Loc_006D2030 loc;
    u8 buf[0x10];

    if (p->f49C != 0) {
        p->f498 = b;
        p->f494 = a;
        loc.f00 = D_L39_00249D58[0];
        loc.f18 = a;
        loc.f1C = b;
        loc.f20 = c;
        loc.f24 = p->f4B0;
        p->f4A4 = 1;
        p->f4A8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001962D8(func_0017D908(&loc, D_00197A88, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CF8A8 */
