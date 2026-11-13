#include "common.h"

/* NTSC-U counterpart of func_L39_006C4360 (src/levels/39_multiplayer_menu/L39_006C40A8.c) */
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);

/* localdecomp:start func_L39_006C1848 */
__asm__(".extern D_L39_002407C0, 16");
extern s32 D_L39_002407C0;
__asm__(".extern D_L39_002417C0, 16");
extern u8 *D_L39_002417C0;
typedef struct { u8 p0[4]; s32 w4; u8 p8[0x160]; u8 b168; } S_1A5CD0_006C4360;
extern S_1A5CD0_006C4360 D_001A5E50;
extern s32 func_L39_006C1BD8(void *, s32);

typedef struct {
    s32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad[0x19];
} S_006C4360;

void func_L39_006C1848(void *a, s32 n) {
    S_006C4360 loc;
    s16 *p;
    s16 *q;
    s32 same;
    s32 cnt;
    s32 i;
    s32 e;
    s32 k;
    s16 *list;
    if (D_001A5E50.b168 == 0) {
        return;
    }
    if (D_L39_002417C0 == 0) {
        return;
    }
    k = func_L39_006C1BD8(a, n);
    list = (s16 *)(D_L39_002417C0 + 0xE0);
    q = list + k;
    p = list;
    e = *q;
    same = -1;
    cnt = -1;
    i = 0;
    do {
        if (*p == e) {
            same++;
        }
        if (*p >= 0) {
            cnt++;
        }
        if (cnt == n) {
            break;
        }
        p++;
    } while (++i < 8);
    loc.w0 = same;
    loc.b6 = 4;
    loc.b5 = 0;
    loc.b4 = 0;
    func_0014AD08(0x50, D_001A5E50.w4, *q, D_L39_002407C0, 0x20, &loc);
}
/* localdecomp:end func_L39_006C1848 */
