#include "common.h"

/* NTSC-U counterpart of func_L39_00677740 (src/levels/shared/L39_006774F0.c) */
extern s32 func_L39_006775E8_00674D58(s32, s32, s32, u8 *);
extern s32 func_L39_00674D58(s32, s32, void *, u8 *);
extern u8 D_L39_004998A0[];
extern void func_0038CC88_00674D58(void *, void *, s32);
extern void func_0038CC88_00674D58(void *, void *, s32);

/* localdecomp:start func_L39_00674D58 */
/* same check-byte scramble as func_L39_006775E8_00674D58 */
extern u8 D_L39_004998A0[];
extern void func_0038CC88_00674D58(void *, void *, s32);
extern u8 *func_L39_00619758(void *, s32);
extern s32 func_L39_0066C910(s32, void *);
extern void func_0019B0D0(void *, void *);

s32 func_L39_00674D58(s32 a0, s32 a1, void *a2, u8 *a3) {
    u8 buf[0x98];
    u8 *globals;
    u8 *p;
    s32 x;
    s16 flag;
    s32 i;
    long t;
    s32 ret = 0x18;

    if ((u32)a3 & 3) {
        func_0038CC88_00674D58(buf, a3, 0x98);
        a3 = buf;
    }
    globals = func_L39_00619758(a2, (*(u32 *)(a3 + 0x14) >> 25) & 1);
    flag = 0;
    if (globals != 0) {
        u32 sb[2];
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
            b = (u8 *)sb;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            sb[0] ^= (u32)p;
            sb[1] ^= sb[0];
            x = sb[1];
        }
        if ((x ^ 0x92) != 0) {
            s32 *q = *(s32 **)(globals + 0x2558);
            if (q != 0) {
                if (q[1] != 0) {
                    flag++;
                }
            }
        }
    }
    if ((u8)flag) {
        void *q = *(void **)(globals + 0x2558);
        s32 r = func_L39_0066C910(*(u32 *)(a3 + 0x14) >> 28, a3 + 0x18);
        ret = r + 0x18;
        if (*(u32 *)(a3 + 0x14) & 0x1000000) {
            ret = r + 0x29;
        }
        func_0019B0D0(q, a3);
    }
    return ret;
}
/* localdecomp:end func_L39_00674D58 */
