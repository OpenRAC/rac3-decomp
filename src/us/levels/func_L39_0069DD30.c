#include "common.h"

/* NTSC-U counterpart of func_L39_006A0540 (src/levels/39_multiplayer_menu/L39_006A04F8.c) */
/* localdecomp:start func_L39_0069DD30 */
typedef struct S_006A0540 {
    s32 f0;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7[0x11];
} S_006A0540;

typedef struct G_006A0540 {
    s32 f0;
    s32 f4;
    u8 pad8[0x160];
    u8 f168;
    u8 pad169[0x4DB];
    s32 f644[8];
} G_006A0540;

extern G_006A0540 D_001A5E50;
extern s32 D_L39_002417C0;
__asm__(".extern D_L39_002417C0, 16");
extern s32 D_L39_002407C0;
__asm__(".extern D_L39_002407C0, 16");
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

void func_L39_0069DD30(void) {
    S_006A0540 s;
    s32 i;

    if (D_L39_002417C0 != 0) {
        if (D_001A5E50.f168 != 0) {
            for (i = 0; i < 7; i++) {
                s32 *p = &D_001A5E50.f644[i];

                if (*p != -1) {
                    s.f6 = *(u8 *)(p + 8);
                    s.f0 = 0;
                    s.f5 = 0;
                    s.f4 = 0;
                    func_0014AD08(0x50, D_001A5E50.f4, *p, D_L39_002407C0, 0x20, &s);
                    *p = -1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_0069DD30 */
