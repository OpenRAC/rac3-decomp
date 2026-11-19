#include "common.h"

/* localdecomp:start func_L39_005F05E8 */
typedef struct E_005F05E8 {
    u8 pad[0x10];
    u8 *base;
    s16 h14;
    s16 h16;
    s16 h18;
    s16 h1A;
    s16 h1C;
    s16 h1E;
} E_005F05E8;

typedef struct S_005F05E8 {
    s16 count;
    u16 flags;
    u8 pad4[0xC];
    E_005F05E8 e[1];
} S_005F05E8;

extern u32 *D_L39_0024CAD0;
extern u8 D_001A4300[];
extern u8 D_001A4370[];
extern u32 D_L39_00245BB0;
extern void func_003CED08(void *, s32, u8 *);
extern void func_003CE780(void);
extern s32 func_003CE828(u8 *, u8 *, s32);
extern s32 func_003CEA20(s32, u8 *, u8 *, u8 *, s32);

void func_L39_005F05E8(S_005F05E8 *a0) {
    E_005F05E8 *p;
    u8 *vis;
    s32 i;
    s32 prev;
    s32 any;
    s32 bit;

    if (a0->count != 0) {
        func_003CED08(a0->e, a0->count, (u8 *)0x70003F00); /* scratchpad */
        func_003CE780();
        vis = (u8 *)0x70003F00; /* scratchpad */
        bit = (a0->flags >> 1) & 1;
        D_L39_0024CAD0[0] = 0x30000007;
        any = 0;
        D_L39_0024CAD0[2] = 0;
        D_L39_0024CAD0[3] = 0x50000007;
        if (bit != 0) {
            D_L39_0024CAD0[1] = (u32)D_001A4370;
        } else {
            D_L39_0024CAD0[1] = (u32)D_001A4300;
        }
        prev = -1;
        D_L39_0024CAD0 += 4;
        for (i = 0, p = a0->e; i < a0->count; i++, p++, vis++) {
            if (*vis == 0) {
                u8 *base = p->base;
                u8 *b = base + p->h1C;
                u8 *a = base + p->h18;
                u8 *c = base + p->h1A;

                if (func_003CE828(a, (u8 *)0x70000000, p->h14) == 0) {
                    any = 1;
                    prev = func_003CEA20(p->h16, b, c, (u8 *)0x70000000, prev);
                }
            }
        }
        if (bit != 0 && any != 0) {
            D_L39_00245BB0 |= 4;
        }
    }
}
/* localdecomp:end func_L39_005F05E8 */
