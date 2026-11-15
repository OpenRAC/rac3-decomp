#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* declared by functions of L20_003FB630.c, which this file was cut from */
extern void func_L20_003FE9C0(u8 *, s32);
extern void func_003C2880(void *);

/* localdecomp:start func_L20_003FE9C0 */
typedef struct { u8 pad0[0x30]; f32 x30; u8 pad1[0x368]; s32 x39C; u8 pad2[0x4C]; void *x3EC; } T_003FE9C0;
extern s16 *D_L20_0021CFE0[];
extern u8 *D_L20_001E029C;
__asm__(".extern D_L20_001E029C, 16");
extern s32 D_L20_001E02D8;
extern s32 D_L20_001E02D8_003FE9C0;
__asm__(".extern D_L20_001E02D8_003FE9C0, 16");
extern u8 D_L20_001D66B0[8];
__asm__(".extern D_L20_001D66B0, 16");
extern s32 func_L03_0043FC00(s32, s32, u8 *, s32, s32, f32, f32, f32, f32, s32, f32, f32, s32, s32, f32);
extern void func_L01_004443E8(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_00445BE0(s32, s32);

void func_L20_003FE9C0(u8 *a0, s32 a1) {
    T_003FE9C0 *s = *(T_003FE9C0 **)(a0 + 0x68);
    s16 *q;
    s16 *p;
    u8 *b;
    s32 i;

    if (a1 == 0) {
        func_L03_0043FC00((s32)a0, 0x7FFF, D_L20_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        if (s->x3EC != 0) {
            func_L03_0043FC00((s32)s->x3EC, 0x7FFF, D_L20_001D66B0, 2, 3, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 1.0f);
        }
        if (s->x30 <= 0.0f) {
            func_L01_004443E8(a0, 0, 3);
        }
        i = a0[0x21];
        p = D_L20_0021CFE0[i];
        if (p != 0 && i < D_L20_001E02D8) {
            u8 *b = D_L20_001E029C;
            q = p;
            do {
                (*(T_003FE9C0 **)&b[((*(u16 *)q & 0x7FFF) << 8) + 0x68])->x39C++;
            } while (*q++ >= 0);
        }
    }
    if (s->x3EC != 0) {
        func_003C2880(s->x3EC);
        s->x3EC = 0;
    }
    if (a0[0xBC] == 0) {
        s32 j = a0[0x21];
        if (j < D_L20_001E02D8_003FE9C0 && D_L20_0021CFE0[j] != 0) {
            func_L01_00445BE0(j, 0);
        }
    }
}
/* localdecomp:end func_L20_003FE9C0 */
