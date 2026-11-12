#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00353EA0);

/* localdecomp:start func_L01_00355D88 */
extern s32 func_L01_00356050(void *);
extern void func_L01_00356588(void *);
extern void func_L01_00356668(void *);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern void func_L01_0044FD88(void *, s32, s32, s32);
extern void func_L01_00452860(void *, void *, s32);
extern s32 func_L01_00452FB0(void *, void *, s32, s32, s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, s32, f32, void *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
extern u8 D_L01_001E2A40[];
extern s32 D_001DD61C_sda;
__asm__(".extern D_001DD61C_sda, 4");
s32 func_L01_00355D88(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 0) {
        if (func_L01_00356050(a0) != 0) return 1;
    }
    if (p[0x3e] == 2) goto L68;
    if (a0[0x31] != 0) {
        if (func_L01_0040E548(D_L01_001E2A40, a0 + 0x10) < 576.0f) {
            func_L01_004472C0(a0);
            a0[0x6f] = 0x16;
        }
    }
    if (*(s32 *)(p + 0x360) != 0) func_L01_0044FD88(a0, *(s32 *)(p + 0x360), 1, D_001DD61C_sda);
    func_L01_00452860(a0, p + 0x30, 0);
    if (func_L01_00452FB0(a0, p + 0x160, 0, 0, 0) != 0) func_L01_00356668(a0);
    if (p[0x5e] != 0) {
L68:
        func_L01_00356588(a0);
        return 1;
    }
    if (p[0x5f] != 0) {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 5);
        }
        if (a0[0x95] == 1) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 3, 0, 10.0f, 1.0f, 0, 0);
        }
    } else {
        if ((*(unsigned long *)(a0 + 0x30) & 0x104100000000ul) != 0x4100000000ul || *(s32 *)(a0 + 0x98) != 0) {
            if (0.0f < *(f32 *)(p + 0x30)) func_L01_00456BD0(a0, 3);
        }
        if (a0[0x95] == 1 || a0[0x95] == 4) {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E0), *(f32 *)(p + 0x2E4), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        } else {
            func_L01_00456C98(a0, *(s32 *)(p + 0x2E8), *(f32 *)(p + 0x2EC), p + 0x320, 0, 0, 0, 1, 0, 10.0f, 1.0f, 0, 0);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_00355D88 */

/* localdecomp:start func_L01_00356050 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_356050;
typedef struct { void (*fn0)(void *); } Vt_356050;
extern s32 func_00443948(s32);
extern s32 func_00443978(s32, s32);
extern f32 func_L01_00443A18(f32, f32);
extern void func_L01_00459218(void *, void *, s32, void *);
extern void func_L01_0045BD78(void *, f32, f32, f32, f32);
extern void *func_L01_0043B548(s32, s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, void *);

extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_001D545C_lui;
__asm__(".extern D_001D545C_lui, 16");
extern u8 *D_001E001C_sda;
__asm__(".extern D_001E001C_sda, 4");

s32 func_L01_00356050(void *arg) {
    u8 *obj = arg;
    u8 *p = *(u8 **)(obj + 0x68);
    s32 one;
    s32 flag;
    s32 x;
    f32 a, b;
    Vt_356050 *t;
    if (func_00443948(2)) *(u16 *)(obj + 0x34) |= 0x8000;
    one = 1;
    *(f32 *)(obj + 0x2C) = *(f32 *)(*(u8 **)(obj + 0x24) + 0x24);
    *(V4_356050 *)(p + 0x300) = *(V4_356050 *)(obj + 0x10);
    *(V4_356050 *)(p + 0x320) = *(V4_356050 *)(obj + 0x10);
    *(f32 *)(p + 0x318) = func_L01_00443A18(0.0f, 20.0f) * 0.01745329238474369f;
    func_L01_00459218(obj, p + 0x3F0, 12, p + 0x36C);
    p[0x1D7] = one;
    p[0x170] = 0x1B;
    p[0x1A8] = 7;
    *(f32 *)(p + 0x190) = 0.5f;
    *(f32 *)(p + 0x194) = 0.5f;
    *(f32 *)(p + 0x19C) = 0.15000000596046448f;
    if (func_00443948(2)) {
        p[0x1D3] = 0x11;
        p[0x1D2] = 0xB;
        p[0x176] = 0;
    } else {
        p[0x176] = one;
        p[0x1D3] = 0x13;
        p[0x1D2] = 0xA;
    }
    *(f32 *)(p + 0x17C) = 0.30000001192092896f;
    *(f32 *)(p + 0x180) = 0.020000001415610313f;
    *(f32 *)(p + 0x184) = 0.010000000707805157f;
    *(f32 *)(p + 0x188) = 0.014000000432133675f;
    *(f32 *)(p + 0x18C) = 0.000800000037997961f;
    p[0x1DB] = 0xFF;
    p[0x1D8] = 0;
    p[0x1D9] = 0;
    p[0x1DA] = 0;
    a = 1.0f;
    b = 0.5f;
    *(f32 *)(p + 0x1A0) = *(f32 *)(obj + 0x18) - 10.0f;
    *(f32 *)(p + 0x70) = 0.44999998807907104f;
    *(f32 *)(p + 0x74) = 0.25f;
    *(f32 *)(p + 0x80) = 1.3089969158172607f;
    *(f32 *)(p + 0xA0) = 0.3490658402442932f;
    *(f32 *)(p + 0x9C) = 0.0020000000949949026f;
    *(f32 *)(p + 0x78) = b;
    *(f32 *)(p + 0x7C) = a;
    *(f32 *)(p + 0x210) = a;
    func_L01_0045BD78(obj, 0.003200000151991844f, 0.10000000894069672f, 0.005026548635214567f, 0.12566371262073517f);
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    if (*(s16 *)(p + 0x34) == 0) {
        *(f32 *)(p + 0x30) = a;
        *(s16 *)(p + 0x34) = 1;
    }
    *(f32 *)(p + 0x40) = b;
    flag = 0;
    p[0x38] = 0;
    p[0x39] = 1;
    p[0x3E] = 1;
    p[0x5E] = 0;
    p[0x5F] = 0;
    *(s32 *)(p + 0x2F0) = 0;
    *(s16 *)(p + 0x2F4) = 0;
    *(s32 *)(p + 0x2F8) = 0;
    *(s32 *)(p + 0x340) = 0;
    *(s32 *)(p + 0x35C) = 0;
    if (*(s32 *)(p + 0x250) > 0) {
        t = func_L01_0043B548(0x19E1, 0x6C);
        *(s32 *)(p + 0x250) = -1;
        flag = 1;
        if (obj[0x43] != 5) func_003C3A10(obj, 5, 0, 0);
        do { p[0x25E] = 0x1A; p[0x25F] = 6; } while (0);
        t->fn0(obj);
        x = D_001D545C_sda;
    } else if (*(s32 *)(p + 0x350) != 0) {
        func_L01_004450F0(obj, 0x18, 5);
        *(u16 *)(obj + 0x34) = (*(u16 *)(obj + 0x34) | 0x41) & 0xEFFF;
        *(s32 *)(obj + 0x98) = 0;
        func_L01_004AA7E8(obj, 1);
        if (*(u8 **)(p + 0x360) != 0) {
            *(u16 *)(*(u8 **)(p + 0x360) + 0x34) |= 0x41;
            *(u16 *)(*(u8 **)(p + 0x360) + 0x34) &= 0xEFFF;
            *(s32 *)(*(u8 **)(p + 0x360) + 0x98) = 0;
            func_L01_004AA7E8(*(u8 **)(p + 0x360), 1);
            x = D_001D545C_sda;
        } else {
            x = D_001D545C_lui;
        }
    } else {
        s32 id = *(s32 *)(p + 0x344);
        if (id != -1) {
            s32 h = *(s16 *)(D_001E001C_sda + (id << 8) + 0xAA);
            if (h == 0x19B1 || h == 0x1AB4) flag = 1;
            func_L01_004450F0(obj, 3, 0);
            if (obj[0x43] != 5) {
                func_003C3A10(obj, 5, func_00443978(0, 5), 0);
                x = D_001D545C_sda;
            } else {
                x = D_001D545C_lui;
            }
        } else {
            func_L01_004450F0(obj, 7, 1);
            if (obj[0x43] != 0x12) {
                func_003C3A10(obj, 0x12, func_00443978(0, 10), 0);
            }
            x = D_001D545C_lui;
        }
    }
    if ((x == 1 || x == 0x60) && flag == 0) {
        void *q = func_003C24B0(0x1AA2, 0x80);
        *(void **)(p + 0x360) = q;
        func_L01_00456160(q, obj);
        *(void **)(p + 0x240) = *(void **)(p + 0x360);
    }
    return 0;
}
/* localdecomp:end func_L01_00356050 */

/* localdecomp:start func_L01_003564D0 */
typedef struct {
    void (*fn0)(void *);
    void (*fn1)(void *);
} Vt_003564D0;

extern void *func_L01_0043B548(s32, s32);
extern void func_003C2880(void *);

void func_L01_003564D0(u8 *obj, s32 a1) {
    u8 *p = *(u8 **)(obj + 0x68);

    if (*(void **)(p + 0x360) != 0) {
        func_003C2880(*(void **)(p + 0x360));
        *(void **)(p + 0x360) = 0;
        *(s32 *)(p + 0x240) = 0;
    }
    if (*(s32 *)(p + 0x250) != 0) {
        Vt_003564D0 *t = func_L01_0043B548(6625, 108);
        t->fn0(obj);
        if (a1 != 0) {
            t->fn1(obj);
        }
    } else {
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003564D0 */
