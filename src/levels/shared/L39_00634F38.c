#include "common.h"

/* localdecomp:start func_L39_00634F38 */
extern u8 func_L39_00635270[];
extern void func_L01_00404A10(void *a0, s32 a1);
void func_L39_00634F38(u8 *a0) {
    if (a0[6676] && *(s16 *)(a0 + 6626) == 0) {
        *(s16 *)(a0 + 6626) = 1;
        func_L01_00404A10(func_L39_00635270, *(s32 *)(a0 + 9508));
    }
}
/* localdecomp:end func_L39_00634F38 */

INCLUDE_ASM("asm/levels", func_L39_00634F80);

INCLUDE_ASM("asm/levels", func_L39_00635270);

INCLUDE_ASM("asm/levels", func_L39_00635DE8);

/* localdecomp:start func_L39_00636F30 */
extern u8 D_L39_004997E0[];
extern u8 D_L39_004814A8[];

s32 func_L39_00636F30(u8 *o, s32 id, s32 limit) {
    u32 buf[2];
    s32 i;
    s32 sum;
    s32 cnt;
    s32 v;

    i = 0;
    sum = *(s32 *)(o + 0x2F0);
    for (;;) {
        {
            u8 *p = o + 0x1A04;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;
            long t;

            t = *p;
            if (t == 0) {
                cnt = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                cnt = buf[1];
            }
        }
        if (i >= cnt) {
            break;
        }
        if (limit < sum) {
            return 0;
        }
        {
            u8 *q = (u8 *)(i + (s32)o);
            s32 x;
            u8 *p;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;

            q += 0x19EC;
            p = q;
            if (*p == 0) {
                v = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    x = m + ((k + j) & 7) * 193;
                    *b++ = D_L39_004814A8[x];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                v = buf[1];
            }
        }
        if (v != id) {
            {
                u8 *p = o + i + 0x19FC;
                s32 x;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 j;

                if (*p == 0) {
                    v = 0;
                } else {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (j = 0; j < 40; j += 5) {
                        x = m + ((k + j) & 7) * 193;
                        *b++ = D_L39_004814A8[x];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    v = buf[1];
                }
            }
            sum += v;
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00636F30 */

/* localdecomp:start func_L39_00637120 */
extern u8 D_L39_004997E0[];
extern u8 D_L39_004814A8[];

s32 func_L39_00637120(u8 *o, s32 id, s32 limit) {
    u32 buf[2];
    s32 i;
    s32 sum;
    s32 cnt;
    s32 v;

    i = 0;
    sum = *(s32 *)(o + 0x2F0);
    for (;;) {
        {
            u8 *p = o + 0x1A04;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;
            long t;

            t = *p;
            if (t == 0) {
                cnt = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    *b++ = D_L39_004997E0[m + ((k + j) & 7) * 255];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                cnt = buf[1];
            }
        }
        if (i >= cnt) {
            break;
        }
        if (limit < sum) {
            return 0;
        }
        {
            u8 *q = (u8 *)(i + (s32)o);
            s32 x;
            u8 *p;
            u8 *b;
            s32 m;
            s32 k;
            s32 n;
            s32 j;

            q += 0x19F4;
            p = q;
            if (*p == 0) {
                v = 0;
            } else {
                n = *p;
                m = n + 1;
                k = ((s32)p - n) & 7;
                b = (u8 *)buf;
                for (j = 0; j < 40; j += 5) {
                    x = m + ((k + j) & 7) * 193;
                    *b++ = D_L39_004814A8[x];
                }
                buf[0] ^= (u32)p;
                buf[1] ^= buf[0];
                v = buf[1];
            }
        }
        if (v != id) {
            {
                u8 *p = o + i + 0x19FC;
                s32 x;
                u8 *b;
                s32 m;
                s32 k;
                s32 n;
                s32 j;

                if (*p == 0) {
                    v = 0;
                } else {
                    n = *p;
                    m = n + 1;
                    k = ((s32)p - n) & 7;
                    b = (u8 *)buf;
                    for (j = 0; j < 40; j += 5) {
                        x = m + ((k + j) & 7) * 193;
                        *b++ = D_L39_004814A8[x];
                    }
                    buf[0] ^= (u32)p;
                    buf[1] ^= buf[0];
                    v = buf[1];
                }
            }
            sum += v;
            i++;
        } else {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00637120 */
