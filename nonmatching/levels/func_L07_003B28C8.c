/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 3 positional differences; preserves checked iteration 07.
 * Attempts: 250, 250, 240, 10, 3, 225, 3 differences.
 * Remaining: the second collision call's f14 argument move is scheduled
 * after t0/t1 setup rather than before it. Constants shared before calls
 * add an unwanted saved FP register; separate local constants do not help.
 * No full build or US carry; marker retained.
 */
#include "common.h"
#include "vu0.h"
extern void func_L07_003B3028(void *);
extern void func_L07_003B3160(u8 *);
extern s32 func_00382468(s32);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern void func_L07_003B3798(u8 *, u8);
extern void func_L01_0045A9F0(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B37D0(u8 *, s32);
extern void func_L01_0045A748(void *, void *);
extern void func_L07_003B4470(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L07_003B4370(void *);
extern void func_L07_003B3C78(void *);
extern void func_L07_003B4B68(void *, s32, f32);
extern void func_L07_003B3A88(void *, f32);
extern s32 func_L01_00456250(void *);
extern void func_L01_00456230(void *, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L07_003B4250(void *);
extern s32 func_L01_004468C8(void *, s32, s32, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L07_003B4308(void *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003B28C8(u8 *self) {
    vu0_q stack[6];
    vu0_q *dst, *src;
    u8 *p;
    u8 *position;
    s32 i;
    if (self[0x20] == 0) func_L07_003B3028(self);
    func_L07_003B3160(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x95]) {
    case 0:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.8f) {
            if (func_00382468(2)) {
                func_L07_003A2380(18, (s32)self, 0, 100);
                p[0x66B] |= 1;
            } else {
                func_L07_003A2380(19, (s32)self, 0, 100);
                p[0x66B] |= 2;
            }
            func_L07_003B3798(self, 1);
            p[0x668] = 255;
        }
        break;
    case 1:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.5f) {
            func_L07_003A2380(21, (s32)self, 0, 100);
            func_L07_003B3798(self, 2);
            p[0x668] = 255;
        }
        break;
    case 2:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.25f) {
            if (p[0x66B] & 1) {
                func_L07_003A2380(19, (s32)self, 0, 100);
                p[0x66B] |= 2;
            } else {
                func_L07_003A2380(18, (s32)self, 0, 100);
                p[0x66B] |= 1;
            }
            func_L07_003B3798(self, 3);
            p[0x668] = 255;
        }
        break;
    }
    switch (self[0x20]) {
    case 1: break;
    case 2:
        func_L01_0045A9F0(self);
        if (func_0038CB00(p + 0x19E)) func_L07_003B37D0(self, 3);
        break;
    case 3:
        func_L07_003B37D0(self, 4);
        break;
    case 4:
        position = self + 0x10;
        dst = stack;
        src = (vu0_q *)(p + 0x330);
        i = 5;
        do {
            *dst++ = *src++;
        } while (--i >= 0);
        func_L01_0045A748(self, *(u8 **)(p + 0x190) + 0x10);
        func_L07_003B4470(self, stack);
        if (func_L01_0040E570(position, *(u8 **)(p + 0x190) + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B37D0(self, 5);
        }
        break;
    case 5:
        func_L07_003B4370(self);
        break;
    case 6:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040E570(self + 0x10, p + 0x80) < 196.0f) {
                func_L07_003B37D0(self, 7);
                break;
            }
        }
        func_L07_003B3A88(self, 13.0f);
        break;
    case 7:
        func_L07_003B3C78(self);
        func_L07_003B4B68(self, *(s16 *)(self + 0x96), 1.0f);
        ++*(u16 *)(self + 0x96);
        func_L07_003B3A88(self, 8.0f);
        if (func_L01_00456250(self)) {
            if (!*(s16 *)(p + 0x66E)) {
                if (func_00382468(20)) func_L07_003A2380(22, (s32)self, 0, 100);
                else func_L07_003A2380(26, (s32)self, 0, 100);
                *(s16 *)(p + 0x66E) = func_00382468(167) + 333;
            }
            func_L07_003B37D0(self, 8);
        } else {
            if (*(s16 *)(p + 0x660) == -1 || !func_0038CB00(p + 0x660)) break;
            if (self[0x95] == 3) func_L01_00456230(self, 1);
            func_L07_003B37D0(self, 8);
        }
        break;
    case 8:
        func_L07_003B3C78(self);
        func_L07_003B4B68(self, -1, (f32)*(s16 *)(p + 0x660) / 42.0f);
        if (func_0038CB00(p + 0x660)) {
            if (func_L01_00456250(self)) func_L07_003B37D0(self, 12);
            else func_L07_003B37D0(self, 5);
        }
        break;
    case 9:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040E570(self + 0x10, p + 0x80) > 144.0f) {
                func_L07_003B37D0(self, 10);
                break;
            }
        }
        func_L07_003B3A88(self, 13.0f);
        break;
    case 10:
        if (func_L01_004561B8(self)) {
            if (!*(s16 *)(p + 0x66C)) {
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0xC000000)
                    p[0x66B] &= 0xF3;
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0x4000000 ||
                    func_00382468(2)) {
                    func_L07_003A2380(24, (s32)self, 0, 100);
                    p[0x66B] |= 8;
                } else {
                    func_L07_003A2380(23, (s32)self, 0, 100);
                    p[0x66B] |= 4;
                }
                *(s16 *)(p + 0x66C) = func_00382468(250) + 500;
            }
            if (p[0x667] == 2) p[0x667] = 1;
            else if (p[0x667] == 1) p[0x667] = 2;
        }
        func_L01_0045A9F0(self);
        func_L07_003B4250(self);
        func_L01_004468C8(self, 13, 1, 0, 1, 0, 1.5f, (f32)p[0x45], 1.5f);
        if (func_L01_0044E1B8(self, 19.0f)) {
            func_L07_003B4308(self);
            --p[0x666];
            func_L07_003B37D0(self, 11);
        }
        break;
    case 11: {
        f32 size, range;
        func_L01_0045A9F0(self);
        func_L07_003B4250(self);
        size = 1.5f;
        range = 1.5f;
        func_L01_004468C8(self, 13, 1, 0, 1, 0, size, (f32)p[0x45], range);
        if (self[0x60] & 2) {
            if (!p[0x666]) {
                ++p[0x668];
                func_L07_003B37D0(self, 5);
            } else if (func_L01_00456250(self)) {
                ++p[0x668];
                func_L07_003B37D0(self, 12);
            } else {
                if (self[0x43] != 4) func_003C3A10(self, 4, 0, 0);
                func_L01_004450F0(self, 10, -1);
            }
        }
        break;
    }
    case 12:
        func_L07_003B3A88(self, 17.0f);
        func_L07_003B4250(self);
        if (self[0x60] & 2) func_L07_003B37D0(self, 5);
        break;
    }
}
