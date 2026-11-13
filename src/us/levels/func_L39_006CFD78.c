#include "common.h"

/* NTSC-U counterpart of func_L39_006D2500 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
extern u16 D_L39_00249D58[];
void func_0014B008(void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern u16 D_L39_00249D58[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

/* localdecomp:start func_L39_006CFD78 */
typedef struct {
    u8 pad0[0x4D4];
    u8 f4D4;
    u8 pad1[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad2[7];
    u8 f4E4;
    u8 pad3[3];
    s32 f4E8;
    s32 f4EC_unused;
    s32 f4F0;
} S_006D2500;
typedef struct {
    u8 pad0[0x50];
    s32 f50;
} G_006D2500;
typedef struct {
    s32 f00;
    u8 pad[0x24];
} Pad_006D2500;
typedef struct {
    u16 f00;
    u8 pad02[0x13];
    u8 name[0x10];
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} Loc_006D2500;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void *func_0017D678(void *, void *, s32);
extern s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern u8 D_00197998[];
__asm__(".extern D_L39_0024D860, 16");

s32 func_L39_006CFD78(S_006D2500 *arg0, s32 arg1, s32 arg2) {
    s32 r = 1;
    Loc_006D2500 loc;
    u8 buf[0x10];
    s32 x;

    if (arg0->f4DC != 0) {
        x = ((G_006D2500 *)D_L39_0024D860)->f50;
        arg0->f4D8 = arg2;
        arg0->f4D4 = arg1;
        loc.f00 = D_L39_00249D58[0];
        func_001206F4((u8 *)&loc + 0x15, (void *)x);
        loc.f28 = *(s32 *)arg0;
        loc.f30 = arg0->f4F0;
        loc.f34 = arg0->f4D8;
        arg0->f4E4 = 1;
        loc.f2C = 1;
        loc.f38 = arg1;
        arg0->f4E8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001962D8((s32)func_0017D678(&loc, D_00197998, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CFD78 */
