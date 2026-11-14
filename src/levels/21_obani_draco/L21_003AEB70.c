#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L21_003AEB70);

INCLUDE_ASM("asm/levels", func_L21_003AF758);

/* localdecomp:start func_L21_003AF988 */
extern u8 D_L21_001E1700[];
extern s32 D_L21_001DE8C0;
extern u8 D_L21_001DCF40;
extern f32 D_L21_001DCF50;
__asm__(".extern D_L21_001DE8C0, 4");
__asm__(".extern D_L21_001DCF50, 4");
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern s32 func_L01_00452860(void *, void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L21_003AFBA8(void *);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_00451DF8(u8 *, void *, s32, s32, f32);

void func_L21_003AF988(u8 *m)
{
    u8 *p = *(u8 **)(m + 0x68);

    if (m[0x31] != 0) {
        if (func_L01_0040E548(D_L21_001E1700, m + 0x10) < 1024.0f) {
            func_L01_004472C0(m);
            m[0x6F] = 0x1E;
        }
    }
    func_L01_00452860(m, p + 0x30, 0);
    func_L01_00452FB0(m, p + 0xD0, 0, 0, 0);
    if (p[0x3E] == 2) {
        func_L21_003AFBA8(m);
    }
    if ((*(unsigned long *)(m + 0x30) & ((unsigned long)0x8208 << 29)) != ((unsigned long)0x8200 << 23) || *(s32 *)(m + 0x98) != 0) {
        if (0.0f < *(f32 *)(p + 0x30)) {
            if (p[0x5F] != 0) {
                func_L01_00456BD0(m, 5);
            } else {
                func_L01_00456BD0(m, 3);
            }
        }
    }
    if (m[0x20] == 4 && (*(s16 *)(m + 0xB2) + 8) % 8 == D_L21_001DE8C0 % 8) {
        if (p[0x5F] != 0) {
            func_L01_00456C98(m, -1, (s32)&D_L21_001DCF40, 0, 0, 0, 3, 0, 0, 0, D_L21_001DCF50, 10.0f, 1.0f);
        } else {
            func_L01_00456C98(m, -1, (s32)&D_L21_001DCF40, 0, 0, 0, 2, 0, 0, 0, D_L21_001DCF50, 10.0f, 1.0f);
        }
    }
    func_L01_00451DF8(m, p + 0x280, 2, 1, 2.5f);
}
/* localdecomp:end func_L21_003AF988 */

INCLUDE_ASM("asm/levels", func_L21_003AFBA8);

INCLUDE_ASM("asm/levels", func_L21_003AFCF0);

/* localdecomp:start func_L21_003AFED0 */
extern u8 D_L21_002C4408[];

/* from rac4-decomp's func_L01_003CC6B0 */
s32 func_L21_003AFED0(s32 arg0, s32 arg1, u32 *arg2) {
    if (arg1 == 0) {
        *arg2 = 68;
        return (u32)D_L21_002C4408;
    }
    return 0;
}
/* localdecomp:end func_L21_003AFED0 */

/* localdecomp:start func_L21_003AFEF0 */
void func_L01_004450F0(s32, s32, s32);

s32 func_L21_003AFEF0(void *arg0, s32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    if (*(u8 *)((u8 *)arg0 + 0x20) == 9) {
        return 0;
    }
    if (*(u8 *)((u8 *)arg0 + 0x95) == 2) {
        return 1;
    }
    *(s8 *)(s + 0x303) = arg1;
    func_L01_004450F0((s32)arg0, 4, 2);
    return 1;
}
/* localdecomp:end func_L21_003AFEF0 */

/* localdecomp:start func_L21_003AFF40 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003AFF40(void *arg0) {
    if (((*(u8 *)((u8 *)arg0 + 0x95)) != 1) && ((*(u8 *)((u8 *)arg0 + 0x20)) != 9)) {
        func_L01_004450F0((s32) arg0, 3, 1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L21_003AFF40 */

/* localdecomp:start func_L21_003AFF88 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003AFF88(void *arg0, s8 arg1) {
    u8 *obj = (u8 *)arg0;
    *(s8 *)(*(u8 **)(obj + 0x68) + 0x301) = arg1;
    if (obj[0x20] == 9) {
        return 0;
    }
    if (obj[0x95] != 3) {
        func_L01_004450F0((s32)obj, 7, 3);
    }
    return 1;
}
/* localdecomp:end func_L21_003AFF88 */

/* localdecomp:start func_L21_003AFFE0 */
s32 func_L21_003AFFE0(u8 *obj, u8 flag, u8 *a, u8 *b) {
    *(u8 *)(*(u8 **)(obj + 0x68) + 0x301) = flag;
    if (obj[0x20] == 9) {
        return 0;
    }
    if (obj[0x95] != 3) {
        func_L01_004450F0(obj, 8, 3);
        *(u128_t *)(obj + 0x10) = *(u128_t *)a;
        *(u128_t *)(obj + 0xF0) = *(u128_t *)b;
    }
    return 1;
}
/* localdecomp:end func_L21_003AFFE0 */

/* localdecomp:start func_L21_003B0068 */
void func_L21_003B0068(void *arg0, s32 arg1) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    if (arg1 != 0) {
        *(f32 *)(p + 0xEC) = 0.3f;
        *(f32 *)(p + 0xF0) = 0.0200000014f;
    } else {
        *(s32 *)(p + 0xEC) = 0;
        *(s32 *)(p + 0xF0) = 0;
    }
}
/* localdecomp:end func_L21_003B0068 */

/* localdecomp:start func_L21_003B00A0 */
void func_L21_003B00A0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300) = arg1;
}
/* localdecomp:end func_L21_003B00A0 */

/* localdecomp:start func_L21_003B00B0 */
s8 func_L21_003B00B0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x300));
}
/* localdecomp:end func_L21_003B00B0 */

/* localdecomp:start func_L21_003B00C0 */
void func_L21_003B00C0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301) = arg1;
}
/* localdecomp:end func_L21_003B00C0 */

/* localdecomp:start func_L21_003B00D0 */
s8 func_L21_003B00D0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x301));
}
/* localdecomp:end func_L21_003B00D0 */

/* localdecomp:start func_L21_003B00E0 */
void func_L21_003B00E0(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302) = arg1;
}
/* localdecomp:end func_L21_003B00E0 */

/* localdecomp:start func_L21_003B00F0 */
s8 func_L21_003B00F0(void *arg0) {
    return (*(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x302));
}
/* localdecomp:end func_L21_003B00F0 */

/* localdecomp:start func_L21_003B0100 */
void func_L01_004450F0(s32, s32, s32);
s32 func_L21_003B0100(void *arg0) {
    if ((*(u8 *)((u8 *)arg0 + 0x95)) == 4) {
        if ((*(u8 *)((u8 *)arg0 + 0x20)) == 9) {
            func_L01_004450F0((s32) arg0, 1, -1);
        }
    }
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 4;
}
/* localdecomp:end func_L21_003B0100 */

/* localdecomp:start func_L21_003B0158 */
s32 func_L21_003B0158(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 3;
}
/* localdecomp:end func_L21_003B0158 */

/* localdecomp:start func_L21_003B0168 */
s32 func_L21_003B0168(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 1;
}
/* localdecomp:end func_L21_003B0168 */

/* localdecomp:start func_L21_003B0178 */
s32 func_L21_003B0178(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 2;
}
/* localdecomp:end func_L21_003B0178 */

/* localdecomp:start func_L21_003B0188 */
s32 func_L21_003B0188(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x95)) == 0;
}
/* localdecomp:end func_L21_003B0188 */
