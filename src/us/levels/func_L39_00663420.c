#include "common.h"

/* NTSC-U counterpart of func_L39_00665CF8 (src/levels/shared/L39_00662678.c): 126 -> 151 */
/* localdecomp:start func_L39_00663420 */
extern u8 D_L39_004998A0[];
extern void func_L39_006268C0(u8 *);
extern void func_L39_00627808(u8 *, s32);
extern void func_L39_00635680(void *, void *, void *, s32, s32, s32, s32);

void func_L39_00663420(u8 *o, s32 cmd) {
    u32 buf[2];
    s32 x1, x2, x3, x4, x5, x6, x7;
    u8 c = o[0x4D24];

    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x1 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x1 = buf[1];
        }
    }
    if (c != x1) {
        return;
    }
    {
        u8 *p = o + 0x19E6;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x2 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x2 = buf[1];
        }
    }
    if ((x2 ^ 0x14) == 0 && cmd == 0x76) {
        return;
    }
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x3 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x3 = buf[1];
        }
    }
    if ((x3 ^ 0x90) == 0 && *(s32 *)(o + 0x2F0) >= 0x97) {
        goto act;
    }
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x4 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x4 = buf[1];
        }
    }
    if ((x4 ^ 0x7E) == 0 && *(s32 *)(o + 0x2F0) >= 0xB) {
        goto act;
    }
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x5 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x5 = buf[1];
        }
    }
    if ((x5 ^ 0x7A) == 0 && *(s32 *)(o + 0x2F0) >= 0xB) {
        goto act;
    }
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x6 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x6 = buf[1];
        }
    }
    if ((x6 ^ 0x76) != 0) {
        return;
    }
act:
    {
        u8 *p = o + 0x19E4;
        u8 *b;
        s32 m;
        s32 k;
        s32 n;
        s32 i;

        if (*p == 0) {
            x7 = 0;
        } else {
            n = *p;
            m = n + 1;
            k = ((s32)p - n) & 7;
            b = (u8 *)buf;
            for (i = 0; i < 40; i += 5) {
                *b++ = D_L39_004998A0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x7 = buf[1];
        }
    }
    if ((x7 ^ 0x7E) == 0) {
        func_L39_006268C0(o);
    }
    if (cmd == 0x2B) {
        func_L39_00627808(o, 1);
    }
    func_L39_00635680(o, o + 0x4D30, o + 0x4D60, cmd, 0, 0, 0);
}
/* localdecomp:end func_L39_00663420 */
