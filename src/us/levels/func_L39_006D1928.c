#include "common.h"

/* NTSC-U counterpart of func_L39_006D40B0 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *func_001206F4(void *, void *);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
void func_0019B6F8(s32);
void func_0019B8D8(s32);

/* localdecomp:start func_L39_006D1928 */
typedef struct S_6D40B0_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} S_6D40B0_G;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
extern void func_00196128(void);
extern void func_0019B8D8(s32);
extern void func_0019B6F8(s32);
extern s32 func_0017E310(void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006D1928(void) {
    S_6D40B0_G *g = (S_6D40B0_G *)D_L39_0024D860;
    void *name = g->f50;
    s32 r = 1;
    struct { u8 pad[0x14]; s32 mode; } l;

    func_00196128();
    func_0019B8D8(0);
    func_0019B6F8(-1);
    func_001206F4(&l, name);
    l.mode = 2;
    func_001962D8(func_0017E310(&l));
    if (func_001962E8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    l.mode = 1;
    func_001962D8(func_0017E310(&l));
    if (func_001962E8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D1928 */
