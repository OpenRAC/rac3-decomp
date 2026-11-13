#include "common.h"

/* NTSC-U counterpart of func_L39_006B22B0 (src/levels/39_multiplayer_menu/L39_006B2120.c) */
/* localdecomp:start func_L39_006AF948 */
typedef struct {
    u8 pad0[0x199];
    u8 f199;
} P_006B22B0;
typedef struct {
    u8 pad0[0x4C];
    P_006B22B0 *f4C;
} G_006B22B0;

__asm__(".extern D_L39_0024D860, 16");
extern G_006B22B0 *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_00195500(void);
void func_L39_006D95F0(s32, s32);
s32 func_L39_006D8470(P_006B22B0 *);
s32 func_L39_006D8DF0(P_006B22B0 *, s32, s32, s32, s32);
void func_L04_0051FB50(P_006B22B0 *);

s32 func_L39_006AF948(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 ok = 1;
    P_006B22B0 *p = D_L39_0024D860->f4C;
    s32 i;

    {
        s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
        while (p->f199 != 0) {
            func_00195500();
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) {
        ok = ((s32 (*)(P_006B22B0 *, s32))func_L39_006D95F0)(p, arg3);
    }
    for (i = 2; i != 0; i--) {
        if (ok) {
            ok = func_L39_006D8470(p);
            if (ok) {
                s32 start = (s32)func_00130760(func_0012DCB0(), 0x24000);
                while (p->f199 != 0) {
                    func_00195500();
                    if ((s32)func_00130760(func_0012DCB0(), 0x24000) - start > 15000) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    ok = func_L39_006D8DF0(p, arg3, arg2, -1, 0);
                    if (ok) {
                        break;
                    }
                }
            }
        }
    }
    func_L04_0051FB50(p);
    return ok;
}
/* localdecomp:end func_L39_006AF948 */
