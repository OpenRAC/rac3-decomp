#include "common.h"

/* NTSC-U counterpart of func_L39_006D5AB8 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
extern u16 D_L39_00249E28[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249E28[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_L39_006D3328(u8 *);

/* localdecomp:start func_L39_006D3328 */
typedef struct {
    u16 f0;
    u8 pad2[0x16 - 2];
    u16 f16;
    u16 f18;
} S_006D5AB8;
extern u16 D_L39_00249E28[];
extern u8 D_00197CE0[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F9C0(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);

s32 func_L39_006D3328(u8 *arg0) {
    S_006D5AB8 buf;
    s32 ret;

    buf.f0 = D_L39_00249E28[0];
    buf.f18 = *(u16 *)(arg0 + 0x28);
    buf.f16 = 1;
    arg0[0x1C] = 1;
    *(s32 *)(arg0 + 0x20) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    ret = func_0017F9C0(&buf, D_00197CE0, 0);
    func_001962D8(ret);
    return func_001962E8() == 0;
}
/* localdecomp:end func_L39_006D3328 */
