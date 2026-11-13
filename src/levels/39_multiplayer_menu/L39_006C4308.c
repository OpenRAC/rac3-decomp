#include "common.h"

/* localdecomp:start func_L39_006C4308 */
__asm__(".extern D_L39_00240640, 16");

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
extern S_1A5CD0_006C4308 D_001A5CD0;
extern s32 D_L39_00240640;

void func_L39_006C4308(u8 *p, s32 a1, s32 a2) {
    S_006C4308 s;

    *(s32 *)(p + 0x2B8) = a1;
    s.f0 = a2;
    s.b6 = 1;
    s.b5 = 0;
    s.b4 = 0;
    func_0014AD08(0x50, D_001A5CD0.w4, D_001A5CD0.w16C, D_L39_00240640, 0x20, &s);
}
/* localdecomp:end func_L39_006C4308 */

/* localdecomp:start func_L39_006C4360 */
__asm__(".extern D_L39_00240640_006C4360, 16");
extern s32 D_L39_00240640_006C4360;
__asm__(".extern D_L39_00241640_006C4360, 16");
extern u8 *D_L39_00241640_006C4360;
typedef struct { u8 p0[4]; s32 w4; u8 p8[0x160]; u8 b168; } S_1A5CD0_006C4360;
extern S_1A5CD0_006C4360 D_001A5CD0_006C4360;
extern s32 func_L39_006C46F0(void *, s32);

typedef struct {
    s32 w0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad[0x19];
} S_006C4360;

void func_L39_006C4360(void *a, s32 n) {
    S_006C4360 loc;
    s16 *p;
    s16 *q;
    s32 same;
    s32 cnt;
    s32 i;
    s32 e;
    s32 k;
    s16 *list;
    if (D_001A5CD0_006C4360.b168 == 0) {
        return;
    }
    if (D_L39_00241640_006C4360 == 0) {
        return;
    }
    k = func_L39_006C46F0(a, n);
    list = (s16 *)(D_L39_00241640_006C4360 + 0xE0);
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
    func_0014AD08(0x50, D_001A5CD0_006C4360.w4, *q, D_L39_00240640_006C4360, 0x20, &loc);
}
/* localdecomp:end func_L39_006C4360 */
