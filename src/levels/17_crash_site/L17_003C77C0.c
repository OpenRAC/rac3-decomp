#include "common.h"

INCLUDE_ASM("asm/levels", func_L17_003C77C0);

/* localdecomp:start func_L17_003C7A18 */
typedef struct { u8 p0[0x10]; s32 f10; u8 p14[0xC]; } S_7A18_T;
typedef struct { u8 p0[0x1C]; struct S_7A18_E *f1C; } S_7A18_R;
typedef struct S_7A18_E { u8 p0[0x24]; s32 f24; u8 p28[0x14]; u8 b3C; } S_7A18_E;
typedef struct { u8 p0[0x7E]; s16 h7E; u8 p80[4]; s16 h84; s16 h86; } S_7A18_O;
typedef struct { u8 p0[0x5D0]; s32 f5D0; u8 p5D4[0xC]; s32 f5E0; u8 p5E4[0xAC]; s32 f690; u8 p694[0xC]; s32 f6A0; u8 p6A4[0x2168]; s32 f280C; } S_7A18_G;
extern S_7A18_R *D_L17_001DE884_a;
__asm__(".extern D_L17_001DE884_a, 16");
extern S_7A18_G D_001A4BE0_7A18;
extern S_7A18_T *D_L17_001DED10;
void func_L17_003C7A18(S_7A18_O *a0) {
    S_7A18_E *e = D_L17_001DE884_a[a0->h84].f1C;
    s32 a, b;
    if (e->b3C) {
        b = D_001A4BE0_7A18.f690;
        a = D_001A4BE0_7A18.f6A0;
    } else {
        b = D_001A4BE0_7A18.f5D0;
        a = D_001A4BE0_7A18.f5E0;
    }
    if (D_001A4BE0_7A18.f280C == a0->h86) {
        if (e->f24 < 0) return;
        if (b == D_L17_001DED10[e->f24].f10 && a == 0) return;
    }
    a0->h7E = 3;
}
/* localdecomp:end func_L17_003C7A18 */
