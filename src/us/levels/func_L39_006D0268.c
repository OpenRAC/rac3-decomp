#include "common.h"

/* NTSC-U counterpart of func_L39_006D29F0 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern s32 func_001962E8(void);
extern u16 D_L39_00249D58[];

/* localdecomp:start func_L39_006D0268 */
typedef struct S_6D29F0 {
    s32 f0;
    u8 pad4[0x510];
    u8 f514;
    u8 f515;
    u8 pad516[6];
    u8 f51C;
    u8 pad51D[3];
    s32 f520;
    u8 pad524[4];
    s32 f528;
} S_6D29F0;
typedef struct S_6D29F0_G {
    u8 pad0[0x50];
    void *f50;
} S_6D29F0_G;
extern u16 D_L39_00249D58[];
extern u8 D_001979C0[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D800(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006D0268(S_6D29F0 *arg0, s32 arg1) {
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; s32 b; s32 c; s32 d; u8 pad3[8]; u8 e[0x10]; } l;

    if (arg0->f515 != 0) {
        void *name = ((S_6D29F0_G *)D_L39_0024D860)->f50;
        arg0->f514 = arg1;
        l.x[0] = D_L39_00249D58[0];
        func_001206F4(l.buf, name);
        arg0->f51C = 1;
        l.a = arg0->f0;
        l.b = arg0->f514;
        l.c = 1;
        l.d = arg0->f528;
        arg0->f520 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(l.e);
        func_001962D8(func_0017D800(&l, D_001979C0, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D0268 */
