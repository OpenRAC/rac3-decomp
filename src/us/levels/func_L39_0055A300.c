#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

typedef struct { u8 pad[612]; s32 w612; } Sub_00557F78;
typedef struct { u8 pad0[104]; Sub_00557F78 *sub; u8 pad1[62]; s16 h170; } Obj_00557F78;
typedef struct { s32 n; s32 pad[3]; Obj_00557F78 *list[1]; } Tbl_00557F78;
typedef struct { u8 pad[104]; Tbl_00557F78 *tbl; } Moby_00557F78;
extern f32 fe_func_0038CE68();
typedef struct { s32 w0; u8 p0[0x74]; s32 w78; u8 p1[0xC4]; s32 w140; } V_558C78;
typedef struct { u8 p0[0x68]; V_558C78 *v; } M_558C78;
extern f32 fe_func_0038CF38(u8 *, u8 *);
extern f32 fe_func_0038CEA8(u8 *);
extern void fe_func_0038CF68(u8 *, u8 *, f32);
/* localdecomp:start func_L39_0055A300 */
extern u8 D_L39_004998A0[];
extern u8 *func_L39_0061AA60(s32);
extern void func_003BD490(u8 *);
extern void func_003BE4F0(u8 *, s32, s32, s32);

/* Copies the animation state of the linked source moby into the target when it is in animation 0x30
 * or 0x31 (via moby_anim_keys), else starts animation 0xB with moby_anim_blend; gated by a
 * checksum-style test on a globals block. */
void func_L39_0055A300(u8 *target)
{
    u8 *globals;
    u8 *p;
    u8 *source;
    s32 state;
    s32 oldState;
    s32 x;
    long t;
    s32 i;

    globals = func_L39_0061AA60(*(s32 *)(target + 0x90));
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
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
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
                func_003BD490(target);
            } else {
                func_003BE4F0(target, state, 0, 7);
            }
        } else {
            s32 old = target[0x43];
            if (old == 0xB || old == 0x13 || old == 0x12)
                func_003BE4F0(target, 1, 0, 0x11);
        }
    }
}
/* localdecomp:end func_L39_0055A300 */
