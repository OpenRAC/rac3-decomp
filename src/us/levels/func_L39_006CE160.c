#include "common.h"

/* NTSC-U counterpart of func_L39_006D08E8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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

/* localdecomp:start func_L39_006CE160 */
typedef struct S_006D08E8 {
    u16 f0;
    u8 pad2[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    u8 f30[16];
} S_006D08E8;
extern u16 D_L39_00249D58[];
extern u8 D_00197A10[];
void func_0014B008(void *);
s32 func_0017D990(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);

s32 func_L39_006CE160(u8 *arg0) {
    S_006D08E8 buf;
    s32 r = 1;

    if (arg0[0x3B4] != 0) {
        buf.f0 = D_L39_00249D58[0];
        buf.f18 = *(s32 *)arg0;
        arg0[0x3BC] = 1;
        buf.f1C = 0;
        buf.f20 = 0;
        *(s32 *)(arg0 + 0x3C0) = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf.f30);
        func_001962D8(func_0017D990(&buf, D_00197A10, 0));
        if (func_001962E8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CE160 */
