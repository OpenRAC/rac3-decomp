#include "common.h"

/* localdecomp:start func_L39_0063EE68 */
void func_L39_0063EE68(void) {

}
/* localdecomp:end func_L39_0063EE68 */

/* localdecomp:start func_L39_0063EE70 */
void func_L39_0063EE70(void) {

}
/* localdecomp:end func_L39_0063EE70 */

/* localdecomp:start func_L39_0063EE78 */
extern u8 D_L39_004997E0[];
typedef struct { u8 pad[0xA4]; u8 bA4[4]; } G_0063EE78;
extern G_0063EE78 D_001A5810;
extern void func_L39_0063FDA8(u8 *);
extern void func_L39_00643F50(u8 *, u8 *);
extern void func_L39_00643B98(u8 *);
extern void func_L39_00672C30(u8 *);
extern void func_L39_006439E0(u8 *);

void func_L39_0063EE78(u8 *a) {
    u32 buf[2];
    if ((({
        u8 *p = a + 0x19E4;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 0x31) == 0 ||
        (({
        u8 *p = a + 0x19E4;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 0x8F) == 0 ||
        (({
        u8 *p = a + 0x19E6;
        s32 x;
        if (*p == 0) {
            x = 0;
        } else {
            u8 *b;
            s32 i, n, m, k;
            n = *p;
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
        x;
    }) ^ 3) == 0)
        a[0x1A10] = 1;
    else
        a[0x1A10] = 0;
    func_L39_0063FDA8(a);
    if (*(s32 *)(a + 0x478) != 10) {
        if (D_001A5810.bA4[*(s32 *)(a + 0x2544)] != 0) {
            *(s32 *)(a + 0x460) |= 8;
        } else if (*(s32 *)(a + 0x460) & 8) {
            *(s32 *)(a + 0x460) &= ~8;
        }
    }
    func_L39_00643F50(a, *(u8 **)(a + 0x2524));
    if ((*(u8 **)(a + 0x2524))[0x31] != 0) {
        func_L39_00643B98(a);
    }
    func_L39_00672C30(a + 0x1A40);
    func_L39_006439E0(a);
}
/* localdecomp:end func_L39_0063EE78 */

/* localdecomp:start func_L39_0063F0C0 */
void func_L39_0063F0C0(void) {

}
/* localdecomp:end func_L39_0063F0C0 */

INCLUDE_ASM("asm/levels", func_L39_0063F0C8);

/* localdecomp:start func_L39_0063FC90 */
/* from the Dec2 pattern of func_L39_0065D0A0 (same decode, table D_L39_004997E0, stride 255) */
typedef union Buf_0063FC90 {
    u8 b[8];
    u32 w[2];
    u16 h[4];
} Buf_0063FC90;

extern u8 D_L39_004997E0[];
extern void func_L39_00563370(void);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_L01_0043B9E8(s32, s32, s32, s32);

static __inline__ s16 Dec2_0063FC90(u8 *q) {
    Buf_0063FC90 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 m;
    s32 i;
    u8 *d;

    if (*q == 0) {
        return 0;
    }
    n = *q;
    k = ((u32)q - n) & 7;
    m = n + 1;
    d = buf.b;
    for (i = 0; i < 24; i += 3) {
        *d++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
    }
    a = buf.w[0] ^ (u32)q;
    b = buf.w[1] ^ a;
    buf.w[0] = a;
    buf.w[1] = (b >> 16) / (((b ^ (b >> 16)) << 16) + 1);
    return buf.h[2];
}

void func_L39_0063FC90(u8 *s) {
    s32 r;

    if (s[0x1A16] != 0) {
        func_L39_00563370();
        s[0x1A16] = 0;
    }
    if (Dec2_0063FC90(s + 0x316) != 0) {
        r = func_L39_005B43C8(0x7F, 0xFF);
        func_L01_0043B9E8(*(s32 *)(s + 0x2524), r, *(s32 *)(s + 0x24E0), r);
    } else {
        func_L01_0043B9E8(*(s32 *)(s + 0x2524), *(s32 *)(s + 0x24DC), *(s32 *)(s + 0x24E0), *(s32 *)(s + 0x24E4));
    }
}
/* localdecomp:end func_L39_0063FC90 */

INCLUDE_ASM("asm/levels", func_L39_0063FDA8);

/* localdecomp:start func_L39_00640698 */
extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L01_0044E740(void *);
extern void func_003C2880(void *);

void func_L39_00640698(u8 *a)
{
    s32 i;
    for (i = 5; i >= 0; i--) {
        u8 *p = a + (5 - i) * 0x50;
        if (*(void **)(p + 0x450) != 0) {
            if (func_L39_0063BDE0(a, *(void **)(p + 0x450)) != 0) {
                p[0x46A] = 0;
                func_L01_0044E740(a + 0x1780);
            }
            func_003C2880(*(void **)(p + 0x450));
            *(void **)(p + 0x450) = 0;
        }
        if (*(void **)(p + 0x454) != 0) {
            func_003C2880(*(void **)(p + 0x454));
            *(void **)(p + 0x454) = 0;
        }
    }
}
/* localdecomp:end func_L39_00640698 */

LINKER_REMNANT("asm/levels", func_L39_00640728);

INCLUDE_ASM("asm/levels", func_L39_00640738);

INCLUDE_ASM("asm/levels", func_L39_006439E0);

INCLUDE_ASM("asm/levels", func_L39_00643B98);

INCLUDE_ASM("asm/levels", func_L39_00643F50);

/* localdecomp:start func_L39_00644448 */
typedef struct {
    u8 pad0[0x20];
    u8 type20;
} Obj_00644448;

typedef struct {
    u8 pad0[0x450];
    Obj_00644448 *obj;
    void *obj2;
    u8 b8;
    u8 pad459[0xB];
    s32 x14;
    u8 pad468[2];
    u8 b1A;
    u8 pad46B[9];
    s32 x24;
    s32 x28;
} V_00644448;

extern s32 func_L39_0063BDE0(void *, void *);
extern void func_L01_0044E740(void *);
extern void func_003C2880(void *);
extern void func_L01_0040E388(void *);

void func_L39_00644448(u8 *a0, s32 a1, s32 a2) {
    s32 prev;
    s32 v;

    ((V_00644448 *)(a0 + a1 * 0x50))->x14 = a2;
    prev = ((V_00644448 *)(a0 + a1 * 0x50))->x28;
    if (((V_00644448 *)(a0 + a1 * 0x50))->x24 != 3) {
        Obj_00644448 *obj = ((V_00644448 *)(a0 + a1 * 0x50))->obj;
        ((V_00644448 *)(a0 + a1 * 0x50))->x24 = 3;
        if (obj != 0) {
            if (obj->type20 != 0xFE) {
                if (obj->type20 != 0xFD) {
                    void (*fn)(Obj_00644448 *) = *(void (**)(Obj_00644448 *))((u8 *)obj + 0x64);
                    if (fn != 0) {
                        fn(obj);
                    }
                }
            }
        }
    }
    ((V_00644448 *)(a0 + a1 * 0x50))->x24 = 0;
    ((V_00644448 *)(a0 + a1 * 0x50))->x28 = 0;
    ((V_00644448 *)(a0 + a1 * 0x50))->b8 = 0;
    if (a0[0x1A14] != 0) {
        if (a1 == 0) {
            *(s16 *)(a0 + 0x1DAC) = 0;
        }
    }
    if (((V_00644448 *)(a0 + a1 * 0x50))->obj != 0) {
        if (func_L39_0063BDE0(a0, ((V_00644448 *)(a0 + a1 * 0x50))->obj) != 0) {
            ((V_00644448 *)(a0 + a1 * 0x50))->b1A = 0;
            func_L01_0044E740(a0 + 0x1780);
        }
        func_003C2880(((V_00644448 *)(a0 + a1 * 0x50))->obj);
        ((V_00644448 *)(a0 + a1 * 0x50))->obj = 0;
    }
    if (((V_00644448 *)(a0 + a1 * 0x50))->obj2 != 0) {
        if (a1 != 3) {
            func_003C2880(((V_00644448 *)(a0 + a1 * 0x50))->obj2);
            ((V_00644448 *)(a0 + a1 * 0x50))->obj2 = 0;
        }
    }
    if (a1 == 0) {
        s32 hit;
        v = prev;
        if (v == -1) {
            s32 t = -1;
            if (((V_00644448 *)a0)->x24 == 2) {
                t = ((V_00644448 *)a0)->x28;
            }
            v = t;
        }
        if (v == 6 || v == 0xC) {
            hit = 1;
        } else {
            hit = 0;
        }
        if (hit) {
            func_L01_0040E388(a0 + 0xF10);
            return;
        }
    }
    if (a1 == 1) {
        func_L01_0040E388(a0 + 0xA40);
        func_L01_0040E388(a0 + 0xAF0);
    }
}
/* localdecomp:end func_L39_00644448 */
