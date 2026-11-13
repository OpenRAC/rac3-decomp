#include "common.h"

/* NTSC-U counterpart of func_L39_006D1B40 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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

/* localdecomp:start func_L39_006CF3B8 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0x10];
} S_006D1B40;
typedef struct {
    u8 pad0[0x45C];
    u8 f45C;
    u8 pad45D[7];
    u8 f464;
    u8 pad465[3];
    s32 f468;
    u8 pad46C[4];
    s32 f470;
} T_006D1B40;
extern u16 D_L39_00249D58[];
extern u8 D_001979E8[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D0F8(void *, u8 *, s32);

s32 func_L39_006CF3B8(u8 *arg0) {
    T_006D1B40 *p = (T_006D1B40 *)arg0;
    s32 r = 1;
    S_006D1B40 x;

    if (p->f45C != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D860 + 0x50);
        x.f0 = D_L39_00249D58[0];
        func_001206F4(x.f15, n);
        p->f464 = 1;
        x.f28 = 1;
        x.f2C = p->f470;
        p->f468 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(x.f30);
        func_001962D8(func_0017D0F8(&x, D_001979E8, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CF3B8 */
