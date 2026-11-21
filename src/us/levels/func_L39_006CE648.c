#include "common.h"

/* NTSC-U counterpart of func_L39_006D0DD0 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern u16 D_L39_00249D58[];
void func_0014B008(void *);
void func_001962D8(s32);
s32 func_001962E8(void);

/* localdecomp:start func_L39_006CE648 */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
} A_006D0DD0;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    s32 f30;
} B_006D0DD0;
typedef struct {
    s32 f0;
    u8 pad4[0x30];
    u8 f34;
    u8 pad35[0x3B7];
    u8 f3EC;
    u8 pad3ED[7];
    u8 f3F4;
    u8 pad3F5[3];
    s32 f3F8;
    u8 pad3FC[4];
    s32 f400;
} T_006D0DD0;
__asm__(".extern D_L39_0024D860, 16");
extern u16 D_L39_00249D58[];
extern u8 D_00197948[];
extern u8 D_00197A38[];
extern s32 func_0017D780(void *, u8 *, s32);
extern s32 func_0017D2F8(void *, u8 *, s32);

s32 func_L39_006CE648(u8 *arg0) {
    T_006D0DD0 *p = (T_006D0DD0 *)arg0;
    s32 r = 1;
    A_006D0DD0 a;
    B_006D0DD0 b;
    u8 buf[0x10];

    if (p->f3EC != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D860 + 0x50);
        p->f3F4 = 1;
        ((s32 (*)(void *))func_0014B008)(buf);
        if (p->f34 != 0) {
            a.f0 = D_L39_00249D58[0];
            func_001206F4(a.f15, n);
            a.f28 = 1;
            a.f2C = p->f400;
            p->f3F8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
            func_001962D8(func_0017D780(&a, D_00197948, 0));
            if (func_001962E8() != 0) {
                r = 0;
            }
        } else {
            b.f0 = D_L39_00249D58[0];
            func_001206F4(b.f15, n);
            b.f2C = 1;
            b.f28 = p->f0;
            b.f30 = p->f400;
            p->f3F8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
            func_001962D8(func_0017D2F8(&b, D_00197A38, 0));
            if (func_001962E8() != 0) {
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CE648 */
