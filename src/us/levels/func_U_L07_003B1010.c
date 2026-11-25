#include "common.h"
#include "structs/moby.h"

extern void func_003BE4F0(void *, s32, s32, s32);

/* localdecomp:start func_U_L07_003B1010 */
#include "vu0.h"
extern void func_L07_003B1768(u8 *);
extern void func_L07_003B18A0(u8 *);
extern s32 func_00382468(s32);
extern s32 func_L07_003A0BC0(u8, s32, u8, s16);
extern void func_L07_003B1ED8(u8 *, u8);
extern void func_L01_004576E8(void *);
extern s32 func_0038CB00(void *);
extern void func_L07_003B1F10(u8 *, s32);
extern void func_L01_00457440(void *, void *);
extern void func_L07_003B2B80(u8 *, vu0_v4 *);
extern f32 func_L01_0040C040(void *, void *);
extern void func_L07_003B2A80(u8 *);
extern void func_L07_003B2388(void *);
extern void func_L07_003B3278(void *, s16, f32);
extern void func_L07_003B2198(struct Moby *, f32);
extern s32 func_L01_00452F60(void *);
extern void func_L01_00452F40(void *, s32);
extern s32 func_L01_00452EC8(void *);
extern void func_L07_003B2960(u8 *);
extern s32 func_L01_00443790(void *, s32, f32, s32, f32, f32, s32, s32, s32);
extern s32 func_L01_0044E1B8(void *, f32);
extern void func_L07_003B2A18(u8 *);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
void func_U_L07_003B1010(u8 *self) {
    vu0_q stack[6];
    vu0_q *dst, *src;
    u8 *p;
    u8 *position;
    s32 i;
    if (self[0x20] == 0) func_L07_003B1768(self);
    func_L07_003B18A0(self);
    p = *(u8 **)(self + 0x68);
    switch (self[0x95]) {
    case 0:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.8f) {
            if (func_00382468(2)) {
                func_L07_003A0BC0(18, (s32)self, 0, 120);
                p[0x66B] |= 1;
            } else {
                func_L07_003A0BC0(19, (s32)self, 0, 120);
                p[0x66B] |= 2;
            }
            func_L07_003B1ED8(self, 1);
            p[0x668] = 255;
        }
        break;
    case 1:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.5f) {
            func_L07_003A0BC0(21, (s32)self, 0, 120);
            func_L07_003B1ED8(self, 2);
            p[0x668] = 255;
        }
        break;
    case 2:
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * 0.25f) {
            if (p[0x66B] & 1) {
                func_L07_003A0BC0(19, (s32)self, 0, 120);
                p[0x66B] |= 2;
            } else {
                func_L07_003A0BC0(18, (s32)self, 0, 120);
                p[0x66B] |= 1;
            }
            func_L07_003B1ED8(self, 3);
            p[0x668] = 255;
        }
        break;
    }
    switch (self[0x20]) {
    case 1: break;
    case 2:
        func_L01_004576E8(self);
        if (func_0038CB00(p + 0x19E)) func_L07_003B1F10(self, 3);
        break;
    case 3:
        func_L07_003B1F10(self, 4);
        break;
    case 4:
        position = self + 0x10;
        dst = stack;
        src = (vu0_q *)(p + 0x330);
        i = 5;
        do {
            *dst++ = *src++;
        } while (--i >= 0);
        func_L01_00457440(self, *(u8 **)(p + 0x190) + 0x10);
        func_L07_003B2B80(self, (vu0_v4 *)stack);
        if (func_L01_0040C040(position, *(u8 **)(p + 0x190) + 0x10) < 484.0f) {
            p[0x1AE] = 1;
            func_L07_003B1F10(self, 5);
        }
        break;
    case 5:
        func_L07_003B2A80(self);
        break;
    case 6:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040C040(self + 0x10, p + 0x80) < 196.0f) {
                func_L07_003B1F10(self, 7);
                break;
            }
        }
        func_L07_003B2198((struct Moby *)self, 13.0f);
        break;
    case 7:
        func_L07_003B2388(self);
        func_L07_003B3278(self, *(s16 *)(self + 0x96), 1.0f);
        ++*(u16 *)(self + 0x96);
        func_L07_003B2198((struct Moby *)self, 8.0f);
        if (func_L01_00452F60(self)) {
            if (!*(s16 *)(p + 0x66E)) {
                if (func_00382468(20)) func_L07_003A0BC0(22, (s32)self, 0, 120);
                else func_L07_003A0BC0(26, (s32)self, 0, 120);
                *(s16 *)(p + 0x66E) = func_00382468(200) + 400;
            }
            func_L07_003B1F10(self, 8);
        } else {
            if (*(s16 *)(p + 0x660) == -1 || !func_0038CB00(p + 0x660)) break;
            if (self[0x95] == 3) func_L01_00452F40(self, 1);
            func_L07_003B1F10(self, 8);
        }
        break;
    case 8:
        func_L07_003B2388(self);
        func_L07_003B3278(self, -1, (f32)*(s16 *)(p + 0x660) / 50.0f);
        if (func_0038CB00(p + 0x660)) {
            if (func_L01_00452F60(self)) func_L07_003B1F10(self, 12);
            else func_L07_003B1F10(self, 5);
        }
        break;
    case 9:
        if (func_0038CB00(p + 0x664)) {
            if (func_0038CB00(p + 0x660) ||
                func_L01_0040C040(self + 0x10, p + 0x80) > 144.0f) {
                func_L07_003B1F10(self, 10);
                break;
            }
        }
        func_L07_003B2198((struct Moby *)self, 13.0f);
        break;
    case 10:
        if (func_L01_00452EC8(self)) {
            if (!*(s16 *)(p + 0x66C)) {
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0xC000000)
                    p[0x66B] &= 0xF3;
                if ((*(unsigned long *)(p + 0x668) & 0xC000000) == 0x4000000 ||
                    func_00382468(2)) {
                    func_L07_003A0BC0(24, (s32)self, 0, 120);
                    p[0x66B] |= 8;
                } else {
                    func_L07_003A0BC0(23, (s32)self, 0, 120);
                    p[0x66B] |= 4;
                }
                *(s16 *)(p + 0x66C) = func_00382468(300) + 600;
            }
            if (p[0x667] == 2) p[0x667] = 1;
            else if (p[0x667] == 1) p[0x667] = 2;
        }
        func_L01_004576E8(self);
        func_L07_003B2960(self);
        func_L01_00443790(self, 13, 1.5f, 1, (f32)p[0x45], 1.5f, 0, 1, 0);
        if (self[0x60] & 2) {
            func_L07_003B2A18(self);
            --p[0x666];
            func_L07_003B1F10(self, 11);
        }
        break;
    case 11: {
        f32 size, range;
        func_L01_004576E8(self);
        func_L07_003B2960(self);
        size = 1.5f;
        range = 1.5f;
        func_L01_00443790(self, 13, size, 1, (f32)p[0x45], range, 0, 1, 0);
        if (self[0x60] & 2) {
            if (!p[0x666]) {
                ++p[0x668];
                func_L07_003B1F10(self, 5);
            } else if (func_L01_00452F60(self)) {
                ++p[0x668];
                func_L07_003B1F10(self, 12);
            } else {
                if (self[0x43] != 4) func_003C3A10(self, 4, 0, 0);
                func_L01_00441FB8(self, 10, -1);
            }
        }
        break;
    }
    case 12:
        func_L07_003B2198((struct Moby *)self, 17.0f);
        func_L07_003B2960(self);
        if (self[0x60] & 2) func_L07_003B1F10(self, 5);
        break;
    }
}
/* localdecomp:end func_U_L07_003B1010 */
