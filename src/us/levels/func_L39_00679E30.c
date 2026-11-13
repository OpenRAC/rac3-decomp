#include "common.h"

/* NTSC-U counterpart of func_L39_0067C8E8 (src/levels/39_multiplayer_menu/L39_0067BC58.c) */
typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_00679E30 */
typedef struct { u8 pad[0x25C]; T t; } S_0067C8E8;
extern S_0067C8E8 D_L39_0025D7C0;
extern void func_L39_0067C220(void);
extern void func_L39_006834D0(void);
extern void func_L39_006D4DA0(void);
extern void func_00392260(s32, s32, s32);

void func_L39_00679E30(void) {
    func_L39_0067C220();
    func_00392260(D_L39_0025D7C0.t.a, D_L39_0025D7C0.t.b, D_L39_0025D7C0.t.c);
    func_L39_0067E950();
    func_L39_006834D0();
    func_L39_006D4DA0();
    func_001954A8(0);
    func_001954C0(0);
}
/* localdecomp:end func_L39_00679E30 */
