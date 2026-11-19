#include "common.h"

typedef struct N_65FDA0 { u32 w0; s32 w4; s32 w8; u8 p0[0x49]; u8 b55; u8 p1x; struct N_65FDA0 *next; } N_65FDA0;
typedef struct N_65FE10 { u8 pad[0x58]; struct N_65FE10 *next; } N_65FE10;
typedef void (*Fn_6600D8)(void *, void *);
typedef struct {
    u32 pad0 : 4;
    u32 cap : 6;
    u32 pad1 : 22;
} S_6601C8;

/* localdecomp:start func_L39_00665C18 */
void func_L39_00665C18(u8 *a0, s32 a1) {
    s32 off = a1 * 0x50;
    if (*(u32 *)(*(u8 **)(a0 + 0x2534) + 0x1A0) & *(u32 *)(a0 + off + 0x460)) {
        a0[off + 0x458] = 1;
    } else {
        a0[off + 0x458] = 0;
    }
}
/* localdecomp:end func_L39_00665C18 */

/* localdecomp:start func_L39_00665C50 */
#include "vu0.h"

extern void func_L39_00638458(void *);

void func_L39_00665C50(u8 *self)
{
    func_L39_00638458(self);
    self[0x4D21] = 0;
    qzero(self + 0x4D50);
    self[0x4D23] = 0;
}
/* localdecomp:end func_L39_00665C50 */

/* localdecomp:start func_L39_00665C80 */
s32 func_L39_00665C80(u8 *a0) {
    if ((a0[9567] != 255 && a0[9565] == 23) || (u32)(*(s32 *)(a0 + 19852) - 23) < 3) return 1;
    return 0;
}
/* localdecomp:end func_L39_00665C80 */

/* localdecomp:start func_L39_00665CC0 */
s32 func_L39_00665CC0(u8 *a, s32 k) {
    if ((a[9567] != 255 && a[9565] == 57) || k == *(s32 *)(a + 19852)) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00665CC0 */

/* localdecomp:start func_L39_00665CF8 */
extern u8 D_L39_004997E0[];
extern void func_L39_00629098(u8 *);
extern void func_L39_00629FE0(u8 *, s32);
extern void func_L39_00637EC8(void *, void *, void *, s32, s32, s32, s32);

void func_L39_00665CF8(u8 *o, s32 cmd) {
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x3 = buf[1];
        }
    }
    if ((x3 ^ 0x90) == 0 && *(s32 *)(o + 0x2F0) >= 0x7E) {
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
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
                *b++ = D_L39_004997E0[m + ((k + i) & 7) * 255];
            }
            buf[0] ^= (u32)p;
            buf[1] ^= buf[0];
            x7 = buf[1];
        }
    }
    if ((x7 ^ 0x7E) == 0) {
        func_L39_00629098(o);
    }
    if (cmd == 0x2B) {
        func_L39_00629FE0(o, 1);
    }
    func_L39_00637EC8(o, o + 0x4D30, o + 0x4D60, cmd, 0, 0, 0);
}
/* localdecomp:end func_L39_00665CF8 */

INCLUDE_ASM("asm/levels", func_L39_00666160);

INCLUDE_ASM("asm/levels", func_L39_00666518);

/* localdecomp:start func_L39_00666E48 */
typedef struct { u8 pad0[0x1A14]; u8 b1A14; u8 pad1[0x2524 - 0x1A15]; s32 x2524; u8 pad2[0x2558 - 0x2528]; s32 x2558; } P_00666E48;
extern P_00666E48 *D_L39_0024CE20_00666E48[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CE20_00666E48, 32");
extern u8 D_001A5CD0[];
extern s32 func_00197548(void);
extern void func_L39_006703B0_00666E48(s32);
extern void func_L39_00640698_00666E48(void *);
extern void func_L39_0061C258_00666E48(s32);
extern void func_003C2880(s32);
extern void func_L39_006683F8_00666E48(void *, s32);
extern void func_L39_0066C5B0_00666E48(void);
extern void func_L39_0066D3A8_00666E48(s32, s32);

void func_L39_00666E48(s32 *a0) {
    s32 i;
    P_00666E48 *p;
    for (i = 0; i < 8; i++) {
        if (D_L39_0024CE20_00666E48[i] == 0) continue;
        if (D_L39_0024CE20_00666E48[i]->x2558 == 0) continue;
        if (D_L39_0024CE20_00666E48[i]->x2558 != (s32)a0) continue;
        if (D_L39_0024CE20_00666E48[i]->b1A14 != 0 && func_00197548() != 0) continue;
        p = D_L39_0024CE20_00666E48[i];
        if (D_001A5CD0[0x7D5 + i] != 2) {
            D_001A5CD0[0x7D5 + i] = 2;
            func_L39_006703B0_00666E48((s32)a0 + 0x1B0);
        }
        func_L39_00640698_00666E48(p);
        func_L39_0061C258_00666E48(p->x2524);
        func_003C2880(p->x2524);
        p->x2524 = 0;
        p->x2558 = 0;
        D_L39_0024CE20_00666E48[i] = 0;
        func_L39_006683F8_00666E48(p, *a0);
        func_L39_0066C5B0_00666E48();
        func_L39_0066D3A8_00666E48(i, *a0);
        return;
    }
}
/* localdecomp:end func_L39_00666E48 */

INCLUDE_ASM("asm/levels", func_L39_00666F58);

/* localdecomp:start func_L39_00666F70 */
s32 func_L39_00666F70(u8 *a0, s32 a1) {
    return *(s32 *)(a0 + 0x32C) == a1;
}
/* localdecomp:end func_L39_00666F70 */
