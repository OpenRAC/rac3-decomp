#include "common.h"

/* NTSC-U counterpart of func_L39_006C4308 (src/levels/39_multiplayer_menu/L39_006C40A8.c) */
/* localdecomp:start func_L39_006C17F0 */
__asm__(".extern D_L39_002407C0, 16");

typedef struct {
    char pad0[4];
    s32 w4;
    char pad8[0x164];
    s32 w16C;
} S_1A5CD0_006C4308;

typedef struct {
    s32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    char pad[0x11];
} S_006C4308;

extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern S_1A5CD0_006C4308 D_001A5E50;
extern s32 D_L39_002407C0;

void func_L39_006C17F0(u8 *p, s32 a1, s32 a2) {
    S_006C4308 s;

    *(s32 *)(p + 0x2B8) = a1;
    s.f0 = a2;
    s.b6 = 1;
    s.b5 = 0;
    s.b4 = 0;
    func_0014AD08(0x50, D_001A5E50.w4, D_001A5E50.w16C, D_L39_002407C0, 0x20, &s);
}
/* localdecomp:end func_L39_006C17F0 */
