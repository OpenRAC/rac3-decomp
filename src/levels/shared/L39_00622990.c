#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 b0;
    u8 b1;
    u8 b2;
} S_00627EF8;

INCLUDE_ASM("asm/levels", func_L39_00622990);

INCLUDE_ASM("asm/levels", func_L39_00622C28);

INCLUDE_ASM("asm/levels", func_L39_006233A8);

INCLUDE_ASM("asm/levels", func_L39_00623FB8);

INCLUDE_ASM("asm/levels", func_L39_006244E0);

INCLUDE_ASM("asm/levels", func_L39_00624658);

/* localdecomp:start func_L39_00626910 */
extern void func_L39_006323B8(void *, void *, void *, f32);
extern void func_L39_00632328(void *, void *, void *, f32);
extern void func_L39_00632298(void *, void *, void *, f32);
extern void func_L39_00632558(void *, void *, void *, f32);

void func_L39_00626910(void *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4)
{
    if (arg2 != 0) {
        func_L39_006323B8(arg0, arg1, arg1, arg3);
        func_L39_00632328(arg0, arg1, arg1, arg4);
    } else {
        func_L39_00632298(arg0, arg1, arg1, arg3);
        func_L39_00632558(arg0, arg1, arg1, arg4);
    }
}
/* localdecomp:end func_L39_00626910 */

INCLUDE_ASM("asm/levels", func_L39_00626998);

/* localdecomp:start func_L39_00626D18 */
void func_L39_00626D18(u8 *p) {
    *(s32 *)(p + 9424) = -1;
    *(u32 *)(p + 9420) = 0xFFFFFFFFU;
    *(s32 *)(p + 9308) = 0;
}
/* localdecomp:end func_L39_00626D18 */

INCLUDE_ASM("asm/levels", func_L39_00626D38);

/* localdecomp:start func_L39_00627EF8 */
extern void func_14AD08(s32, s32, s32, s32, s32, void *);
extern u8 D_001A5CD0[];

void func_L39_00627EF8(u8 *s, f32 *v, s32 flag) {
    S_00627EF8 loc;
    u8 *p;
    u8 *d;

    loc.b1 = s[0x2544];
    p = *(u8 **)(s + 0x2558);
    loc.b0 = p[0xC34];
    loc.b2 = p[0xC31];
    if (flag != 0) {
        loc.b2 |= 0x40;
    }
    d = D_001A5CD0;
    loc.x = v[0];
    loc.y = v[1];
    loc.z = v[2];
    if (*(s32 *)(d + 0x170) == 0) {
        s32 a = *(s32 *)(d + 4);
        u8 b = d[0x7D4];
        func_14AD08(b | 0x80, a, -1, *(s32 *)0x2405E4, 16, &loc);
    }
}
/* localdecomp:end func_L39_00627EF8 */

/* localdecomp:start func_L39_00627F88 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0[2];
    u8 flags;
} Msg6257B0;

extern void func_0038CC88(void *, void *, s32);
extern void func_003C4A40(s32, void *);

void func_L39_00627F88(u8 *s, Msg6257B0 *m) {
    if (s[6676] != 0) {
        return;
    }
    if (s[9468] == 0) {
        s[9468] = 1;
        func_0038CC88(s + 9452, m, 16);
    } else {
        s[9466] |= m->flags;
        *(f32 *)(s + 9452) += m->x;
        *(f32 *)(s + 9456) += m->y;
        *(f32 *)(s + 9460) += m->z;
    }
    if ((*(s8 *)(s + 9465) & 0xF0) == 0) {
        func_003C4A40(*(s32 *)(s + 9508), s + 9476);
    }
}
/* localdecomp:end func_L39_00627F88 */

INCLUDE_ASM("asm/levels", func_L39_00628038);

INCLUDE_ASM("asm/levels", func_L39_00628428);

INCLUDE_ASM("asm/levels", func_L39_00628760);

INCLUDE_ASM("asm/levels", func_L39_00629098);

INCLUDE_ASM("asm/levels", func_L39_00629290);

INCLUDE_ASM("asm/levels", func_L39_00629550);

INCLUDE_ASM("asm/levels", func_L39_00629958);
