#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_00351C58);

INCLUDE_ASM("asm/levels", func_L07_00352510);

INCLUDE_ASM("asm/levels", func_L07_00352758);

/* localdecomp:start func_L07_00352A58 */
void func_L07_00334740();
void func_L07_00352AC8(s32, s32);

void func_L07_00352A58(s32 arg0) {
    func_L07_00334740();
    func_L07_00352AC8(arg0, 1);
}
/* localdecomp:end func_L07_00352A58 */

/* localdecomp:start func_L07_00352A88 */
void func_L07_00352AC8(s32, s32);
void func_L07_00334800();

void func_L07_00352A88(s32 arg0) {
    *(f32 *)(arg0 + 0x2C) = *(f32 *)(*(s32 *)(arg0 + 0x24) + 0x24);
    func_L07_00334800();
    func_L07_00352AC8(arg0, 2);
}
/* localdecomp:end func_L07_00352A88 */

INCLUDE_ASM("asm/levels", func_L07_00352AC8);

/* localdecomp:start func_L07_00352E88 */
extern f32 func_L07_00353D60(u8 *);
extern void func_L07_00352AC8(s32, s32);
extern void func_L07_00352F30(u8 *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0045AA10(u8 *);
extern u8 D_L07_001DD604[];

void func_L07_00352E88(u8 *self) {
    u8 *o;
    f32 r;
    f32 t;
    f32 *p;

    o = *(u8 **)(self + 0x68);
    t = func_L07_00353D60(self);
    p = (f32 *)(D_L07_001DD604 + (s32)o[0x464] * 8);
    r = *p - 0.5f;
    if (r > t) {
        f32 d;
        func_L07_00352AC8((s32)self, 8);
        d = func_0038D160(*(f32 *)(o + 0x130) - *(f32 *)(self + 0x10),
                          *(f32 *)(o + 0x134) - *(f32 *)(self + 0x14));
        ((void (*)(u8 *, f32))func_L01_0045AA10)(self, d);
    } else {
        func_L07_00352F30(self, r);
    }
}
/* localdecomp:end func_L07_00352E88 */

/* localdecomp:start func_L07_00352F30 */
extern s32 D_L07_001DEF40[1];
extern void func_L03_0032FAF0(f32 *, f32 *, f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_L07_00332CF0(s32, void *, f32 *, f32);
extern void func_L07_00333DB8(s32, void *, s32, s32, f32);
extern s32 func_L01_0045A7A8(void *, f32 *, f32);

void func_L07_00352F30(u8 *arg0, f32 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    f32 buf[4];
    f32 d;
    s32 g;
    s32 b;

    func_L03_0032FAF0(buf, (f32 *)(p + 0x130), *(f32 *)(p + 0x254), arg1);
    g = D_L07_001DEF40[0] & 7;
    b = ((s32)arg0 >> 8) & 7;
    if (g == b) {
        d = func_0038DB00(*(f32 *)(p + 0x250), *(f32 *)(p + 0x254));
        *(f32 *)(p + 0x258) = func_L07_00332CF0(*(s32 *)(p + 0x240), arg0, buf,
                                               d * 0.15f);
        func_L07_00333DB8(*(s32 *)(p + 0x240), arg0, 0, 0, arg1);
    }
    func_L01_0045A7A8(arg0, buf, *(f32 *)(p + 0x258));
}
/* localdecomp:end func_L07_00352F30 */

INCLUDE_ASM("asm/levels", func_L07_00352FF0);

INCLUDE_ASM("asm/levels", func_L07_00353178);

/* localdecomp:start func_L07_003532D0 */
extern f32 func_L07_00353D60(u8 *);
void func_L07_00352AC8(s32, s32);

void func_L07_003532D0(u8 *arg0) {
    u8 *p;
    f32 t;

    p = *(u8 **)(arg0 + 0x68);
    t = func_L07_00353D60(arg0) - *(f32 *)(D_L07_001DD604 + p[0x464] * 8);
    if (t < 4.0f) {
        func_L07_00352AC8((s32)arg0, 8);
    } else if (t < 8.0f) {
        func_L07_00352AC8((s32)arg0, 9);
    } else {
        func_L07_00352AC8((s32)arg0, 10);
    }
}
/* localdecomp:end func_L07_003532D0 */

/* localdecomp:start func_L07_00353378 */
extern f32 func_L07_00353D60(u8 *);
extern s32 func_00382498(s32, s32);
extern f32 D_L07_001DD600;
extern u8 D_L07_001DD604_sdata[] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DD600, 4");

s32 func_L07_00353378(u8 *arg0, u8 arg1) {
    u8 bits;
    u8 *o;
    f32 t;
    s32 i;

    o = *(u8 **)(arg0 + 0x68);
    t = func_L07_00353D60(arg0);
    bits = 0;
    i = 4;
    do {
        u8 n = func_00382498(0, --i);
        s32 k;

        do {
            for (k = 0; k < 4; k++) {
                if (n < k)
                    continue;
                if ((bits >> k) & 1)
                    n = n + 1;
            }
        } while (0);
        if (*(f32 *)((u8 *)&D_L07_001DD600 + n * 8) <= t) {
            if (arg1 == 0)
                return n;
            if (n != o[0x464] && t <= *(f32 *)(D_L07_001DD604_sdata + n * 8))
                return n;
        }
        bits |= 1 << n;
    } while (i > 0);
    return -1;
}
/* localdecomp:end func_L07_00353378 */

/* localdecomp:start func_L07_00353498 */
extern s32 func_00382498(s32, s32);
extern s32 func_L07_00353820(s32, s32, s32, f32);
extern void func_L07_00352AC8(s32, s32);

s32 func_L07_00353498(s32 arg0) {
    u8 used = 0;
    s32 count;
    s32 slot;
    s32 i;
    s32 kind;
    s32 dir;
    f32 delay;

    for (count = 3; count > 0; count--) {
        slot = func_00382498(0, count - 1);
        for (i = 0; i < 3; i++) {
            if (slot < i) continue;
            slot += (used >> i) & 1;
        }
        if (slot == 2) {
            delay = 1.5f;
            kind = 0;
            dir = -1;
        } else {
            dir = slot == 1 ? -1 : 1;
            delay = 1.8f;
            kind = 1;
        }
        if (func_L07_00353820(arg0, kind, dir, delay) != 0) {
            func_L07_00352AC8(arg0, slot + 0x12);
            return 1;
        }
        used = (used | (1 << slot)) & 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L07_00353498 */

/* localdecomp:start func_L07_003535B0 */
extern s32 func_00382498(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003535B0(s32 arg0) {
    func_L07_00352AC8(arg0, func_00382498(0, 1) + 0x15);
}
/* localdecomp:end func_L07_003535B0 */

INCLUDE_ASM("asm/levels", func_L07_003535E8);

/* localdecomp:start func_L07_00353730 */
s32 func_L07_00331008(s32, s32);
void func_L07_003535B0(s32);
void func_L07_00352AC8(s32, s32);

void func_L07_00353730(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x60) & 2) {
        if (handle[0x466] != 0) {
            func_L07_003535B0(arg0);
            handle[0x466] = 0;
        } else {
            if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
                func_L07_00352AC8(arg0, 6);
            } else {
                func_L07_00352AC8(arg0, 7);
            }
        }
    }
}
/* localdecomp:end func_L07_00353730 */

/* localdecomp:start func_L07_003537B0 */
extern s32 func_L01_0045A9F0(void *);
extern s32 func_L07_00331008(s32, s32);
extern void func_L07_00352AC8(s32, s32);

void func_L07_003537B0(s32 arg0) {
    u8 *handle = *(u8 **)(arg0 + 0x68);

    func_L01_0045A9F0((void *)arg0);
    if (*(u8 *)(arg0 + 0x60) & 2) {
        handle[0x467] = 0;
        if (func_L07_00331008(*(s32 *)(handle + 0x240), arg0) == 0) {
            func_L07_00352AC8(arg0, 6);
        } else {
            func_L07_00352AC8(arg0, 7);
        }
    }
}
/* localdecomp:end func_L07_003537B0 */

INCLUDE_ASM("asm/levels", func_L07_00353820);

/* localdecomp:start func_L07_003538A0 */
extern s32 func_L01_004468C8(u8 *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L07_00353D20(s32);

void func_L07_003538A0(u8 *arg0) {
    u8 *h = *(u8 **)(arg0 + 0x68);

    if (func_L07_00353D20(func_L01_004468C8(arg0, 4, 0x10001, 0, 1, 0, 0.3f, (f32)h[0x44], 1.0f)) != 0) {
        h[0x466]++;
    } else if (func_L07_00353D20(func_L01_004468C8(arg0, 5, 0x10001, 0, 1, 0, 0.5f, (f32)h[0x44], 1.0f)) != 0) {
        h[0x466]++;
    }
}
/* localdecomp:end func_L07_003538A0 */

INCLUDE_ASM("asm/levels", func_L07_00353980);

INCLUDE_ASM("asm/levels", func_L07_00353AB0);

/* localdecomp:start func_L07_00353D20 */
extern s32 D_001A71A0[];
extern s32 D_L07_001ECC80[];

s32 func_L07_00353D20(s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        if (D_L07_001ECC80[i] == D_001A71A0[0]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L07_00353D20 */

/* localdecomp:start func_L07_00353D60 */
void func_0038CF38(void *, s32);

void func_L07_00353D60_00353D60(void *arg0) __asm__("func_L07_00353D60");
void func_L07_00353D60_00353D60(void *arg0) {
    func_0038CF38(arg0 + 0x10, (*(s32 *)((u8 *)arg0 + 0x68)) + 0x130);
}
/* localdecomp:end func_L07_00353D60 */

/* localdecomp:start func_L07_00353D88 */
typedef struct {
    u8 pad[0x68];
    u8 *p68;
} S_353D88;

void func_L07_00353D88(S_353D88 *a0) {
    u8 *p = a0->p68;

    p[0x468] = 0;
    p[0x469] = 0;
}
/* localdecomp:end func_L07_00353D88 */

INCLUDE_ASM("asm/levels", func_L07_00353D98);

INCLUDE_ASM("asm/levels", func_L07_00353E10);

INCLUDE_ASM("asm/levels", func_L07_00353FF0);
