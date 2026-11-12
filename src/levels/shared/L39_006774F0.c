#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006774F0);

INCLUDE_ASM("asm/levels", func_L39_006775B8);

/* localdecomp:start func_L39_006775E8 */
/* shaped after func_L39_0055AD78 in L39_005598D8.c (same 0x19E4 check-byte scramble) */
extern u8 D_L39_004997E0[];
extern u8 *func_L39_0061BF50(s32);
extern void func_0038CC88(void *, void *, s32);

s32 func_L39_006775E8(s32 a0, s32 a1, s32 a2, u8 *a3) {
    u8 *globals;
    u8 *p;
    s32 x;
    s16 flag;
    s32 i;
    long t;

    globals = func_L39_0061BF50(*a3);
    flag = 0;
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
        func_0038CC88(globals + 0x255C, a3, 28);
    }
    return 28;
}
/* localdecomp:end func_L39_006775E8 */

/* localdecomp:start func_L39_006776D8 */
typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
    s32 w16;
    s32 w20;
    s32 w24;
    u8 b28;
    u8 pad[3];
} S_00674CF0;
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_0053BED0(void *);
extern void func_L39_0066E100(s32, s32, s32, s32, s32, s32, s32, void *);
s32 func_L39_006776D8(s32 a0, s32 a1, s32 a2, void *a3) {
    S_00674CF0 buf;
    func_0038CC88(&buf, a3, 32);
    if (buf.b28 == 13) {
        func_L39_0053BED0(&buf);
    } else {
        func_L39_0066E100(buf.w16, buf.w20, buf.b28, 0, buf.w24, buf.w12, 0, &buf);
    }
    return 32;
}
/* localdecomp:end func_L39_006776D8 */

/* localdecomp:start func_L39_00677740 */
/* same check-byte scramble as func_L39_006775E8 */
extern u8 D_L39_004997E0[];
extern void func_0038CC88(void *, void *, s32);
extern u8 *func_L39_0061BED0(void *, s32);
extern s32 func_L39_0066F260(s32, void *);
extern void func_0019AF90(void *, void *);

s32 func_L39_00677740(s32 a0, s32 a1, void *a2, u8 *a3) {
    u8 buf[0x98];
    u8 *globals;
    u8 *p;
    s32 x;
    s16 flag;
    s32 i;
    long t;
    s32 ret = 0x18;

    if ((u32)a3 & 3) {
        func_0038CC88(buf, a3, 0x98);
        a3 = buf;
    }
    globals = func_L39_0061BED0(a2, (*(u32 *)(a3 + 0x14) >> 25) & 1);
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
        s32 r = func_L39_0066F260(*(u32 *)(a3 + 0x14) >> 28, a3 + 0x18);
        ret = r + 0x18;
        if (*(u32 *)(a3 + 0x14) & 0x1000000) {
            ret = r + 0x29;
        }
        func_0019AF90(q, a3);
    }
    return ret;
}
/* localdecomp:end func_L39_00677740 */

INCLUDE_ASM("asm/levels", func_L39_006778A0);

/* localdecomp:start func_L39_006779A8 */
extern u8 *D_L39_0024BF5C;
extern void func_0038CC88(void *dst, void *src, s32 n);
s32 func_L39_006779A8(s32 a0, s32 a1, s32 a2, void *a3) {
    s32 buf[2];
    u8 *m;
    s32 *q;
    func_0038CC88(buf, a3, 8);
    if (buf[0] >= 0) {
        m = D_L39_0024BF5C + (buf[0] << 8);
        if (m != 0 && m[32] != 254 && m[32] != 253) {
            q = *(s32 **)(m + 104);
            if (q != 0 && *q == -1) {
                *q = buf[1];
            }
        }
    }
    return 8;
}
/* localdecomp:end func_L39_006779A8 */

INCLUDE_ASM("asm/levels", func_L39_00677A20);

/* localdecomp:start func_L39_00677B40 */
extern void func_0038CC88(void *dst, void *src, s32 n);
extern void func_L39_006684A0(void *a0);
s32 func_L39_00677B40(s32 a0, s32 a1, s32 a2, s32 a3) {
    u8 buf[36];
    ((void (*)(void *a0, s32 a1, s32 a2))func_0038CC88)(buf, a3, 36);
    if ((buf[31] & 0xF) == 3) {
        func_L39_006684A0(buf);
    }
    return 36;
}
/* localdecomp:end func_L39_00677B40 */

/* localdecomp:start func_L39_00677B88 */
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_00670AE0(void *);
s32 func_L39_00677B88(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 buf[12];
    func_0038CC88(buf, a3, 12);
    func_L39_00670AE0(buf);
    return 12;
}
/* localdecomp:end func_L39_00677B88 */

INCLUDE_ASM("asm/levels", func_L39_00677BB8);

/* localdecomp:start func_L39_00677CB8 */
extern void func_0038CC88(void *, void *, s32);
extern void func_L39_0066FA90(void *);
s32 func_L39_00677CB8(s32 a0, s32 a1, s32 a2, void *a3) {
    u8 buf[104];
    func_0038CC88(buf, a3, 104);
    func_L39_0066FA90(buf);
    return 104;
}
/* localdecomp:end func_L39_00677CB8 */
