#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_0055AD78 */
extern u8 D_L39_004997E0[];
extern u8 *func_L39_0061D1D8(s32);
extern void func_003C29B0(u8 *);
extern void func_003C3A10(u8 *, s32, s32, s32);

void func_L39_0055AD78(u8 *target)
{
    u8 *globals;
    u8 *p;
    u8 *source;
    s32 state;
    s32 oldState;
    s32 x;
    long t;
    s32 i;

    globals = func_L39_0061D1D8(*(s32 *)(target + 0x90));
    if (globals != 0) {
        u32 buf[2];
        u8 *b;
        p = globals + 0x19E4;
        x = 0;
        t = *p;
        if (t != 0) {
            s32 m;
            s32 k;
            s32 n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x = buf[1];
        }
        if ((x ^ 0x37) == 0) {
            source = *(u8 **)(globals + 0x2524);
            oldState = source[0x43];
            state = 0xB;
            if (oldState == 0x30) state = 0x13;
            if (oldState == 0x31) state = 0x12;
            if ((u32)(state - 0x12) < 2) {
                u8 flag;
                target[0x42] = state;
                target[0x43] = state;
                *(f32 *)(target + 0x44) = *(f32 *)(*(u8 **)(globals + 0x2524) + 0x44);
                target[0x40] = (*(u8 **)(globals + 0x2524))[0x40];
                flag = (*(u8 **)(globals + 0x2524))[0x41];
                target[0x41] = flag;
                if ((*(u8 **)(globals + 0x2524))[0x42] != (*(u8 **)(globals + 0x2524))[0x43])
                    target[0x40] = flag;
                func_003C29B0(target);
            } else {
                func_003C3A10(target, state, 0, 6);
            }
        } else {
            s32 old = target[0x43];
            if (old == 0xB || old == 0x13 || old == 0x12)
                func_003C3A10(target, 1, 0, 0xE);
        }
    }
}
/* localdecomp:end func_L39_0055AD78 */
