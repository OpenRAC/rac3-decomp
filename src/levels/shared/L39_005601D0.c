#include "common.h"

/* localdecomp:start func_L39_005601D0 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_005601D0(s32 a0) {
    return func_L39_0066DD30(a0, 0, 0) != 0;
}
/* localdecomp:end func_L39_005601D0 */

/* localdecomp:start func_L39_005601F8 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_005601F8(s32 a0) {
    return func_L39_0066DD30(a0, 1, 0) != 0;
}
/* localdecomp:end func_L39_005601F8 */

/* localdecomp:start func_L39_00560220 */
extern s32 func_L39_0066DD30(s32, s32, s32);
s32 func_L39_00560220(s32 a0) {
    return func_L39_0066DD30(a0, 2, 0) != 0;
}
/* localdecomp:end func_L39_00560220 */

/* localdecomp:start func_L39_00560248 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
void func_L39_00560248(s32 a0, s32 a1) {
    s32 x;
    s32 r = func_L39_0066DCC8(a0, 0, 0, 250);
    x = a1;
    func_L39_00662AA0(r, &x, 4);
}
/* localdecomp:end func_L39_00560248 */

/* localdecomp:start func_L39_00560290 */
extern void func_L39_00662AA0(s32 a0, void *a1, s32 a2);
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L39_00560290(u8 *a0) {
    u16 buf;
    void *h = ((void * (*)(void *a0, s32 a1, s32 a2, s32 a3))func_L39_0066DCC8)(a0, 1, 0, 250);
    u8 *s = *(u8 **)(a0 + 104);
    buf = *(u16 *)(s + 8);
    ((void (*)(void *a0, void *a1, s32 a2))func_L39_00662AA0)(h, &buf, 2);
    buf = *(u16 *)(s + 10);
    ((void (*)(void *a0, void *a1, s32 a2))func_L39_00662AA0)(h, &buf, 2);
}
/* localdecomp:end func_L39_00560290 */

/* localdecomp:start func_L39_00560308 */
extern s32 func_L39_0066DCC8(s32 a0, s32 a1, s32 a2, s32 a3);
void func_L39_00560308(s32 a0) {
    ((void (*)(s32, s32, s32, s32))func_L39_0066DCC8)(a0, 2, 0, 250);
}
/* localdecomp:end func_L39_00560308 */

/* localdecomp:start func_L39_00560330 */
typedef union {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_00560330;
extern u8 D_L39_004997E0[];
extern u8 D_L39_00483A00[];
/* func_L39_005601D0 in level 39; levels 40-53 call a copy with the same code (func_L40_004279D8 in 40-45 and 50-53, func_L40_0041E458 in 46-49) */
extern s32 func_L39_005601D0_00560330(s32);

static __inline__ u32 dec5_00560330(u8 *p) {
    Buf_00560330 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

static __inline__ u16 dec3_00560330(u8 *p) {
    Buf_00560330 buf;
    u8 *d;
    s32 i;
    s32 n;
    s32 m;
    s32 k;
    u32 a;
    u32 b2;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_00483A00[((k + i) & 7) * 209 + m];
    }
    a = buf.w[0] ^ (u32)p;
    b2 = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b2 >> 16) / (((b2 ^ (b2 >> 16)) << 16) + 1);
    return buf.h[2];
}

s32 func_L39_00560330(u8 *a0, u8 *a1) {
    u8 *s = *(u8 **)(a1 + 104);
    u8 *q;
    u8 host;
    s32 flag;

    flag = 0;
    q = *(u8 **)(a0 + 0x2530);
    if (!(host = q != 0 ? (q[0x27B] != 0 && (dec5_00560330(a0 + 0x19E4) ^ 0x31) == 0) : 0)) {
        if ((dec5_00560330(a0 + 0x19E6) ^ 0x14) != 0) {
            flag = func_L39_005601D0_00560330((s32)a1) == 0;
        }
    }
    if (flag != 0) {
        if ((((s16)dec3_00560330(a0 + 0x1A41) ^ *(u16 *)(s + 10)) & *(u16 *)(s + 10)) != 0) {
            return 1;
        }
        if ((((s16)dec3_00560330(a0 + 0x1A40) ^ *(u16 *)(s + 8)) & *(u16 *)(s + 8)) != 0) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00560330 */

/* localdecomp:start func_L39_00560618 */
typedef union {
    u8 b[8];
    u32 w[2];
} Buf_00560618;
extern u8 D_L39_004997E0[];
/* func_L39_005601D0 in level 39; levels 40-53 call a copy with the same code (func_L40_004279D8 in 40-45 and 50-53, func_L40_0041E458 in 46-49) */
extern s32 func_L39_005601D0_00560618(s32);

static __inline__ u32 dec5_00560618(u8 *p) {
    Buf_00560618 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*p == 0) {
        return 0;
    }
    n = *p;
    k = ((u32)p - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 40; i += 5) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)p;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = b;
    return b;
}

s32 func_L39_00560618(u8 *a0, u8 *a1, s32 a2) {
    s32 ret = 0;
    u8 *q;
    u8 host;

    if ((dec5_00560618(a0 + 0x19E6) ^ 0x14) != 0) {
        q = *(u8 **)(a0 + 0x2530);
        if (!(host = q != 0 ? (q[0x27B] != 0 && (dec5_00560618(a0 + 0x19E4) ^ 0x31) == 0) : 0) && *(s32 *)(a0 + 0x350) >= 0x1F) {
            if (a2 == 0 || func_L39_005601D0_00560618((s32)a1) == 0) {
                ret = 1;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_00560618 */
