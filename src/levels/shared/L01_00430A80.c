#include "common.h"

/* localdecomp:start func_L01_00430A80 */
extern void func_L01_00430D28(u8 *dst, u8 *src);
extern s32 D_L01_001F3FC8[];
extern void func_L01_00431808_00430A80(s32 a0, u8 *a1, s32 a2);
extern void func_L01_00430AF8(s32 a0, u8 *a1, s32 a2);
void func_L01_00430A80(s32 a0, u8 *a1, s32 a2) {
    func_L01_00431808_00430A80(a0, a1, a2);
    if (D_L01_001F3FC8[0] != 0) {
        if (a1[0] & 1) {
            func_L01_00430AF8(a0, a1, a2);
        } else {
            ((void (*)(s32 a0, u8 *a1))func_L01_00430D28)(a0, a1);
        }
    }
}
/* localdecomp:end func_L01_00430A80 */

/* localdecomp:start func_L01_00430AF8 */
extern void func_0038CB78(void *, s32, s32);
extern void func_0038CD28(u8 *, u32 *, s32);

void func_L01_00430AF8(s32 a0, u8 *ctrl, s32 a2) {
    u8 *dst = (u8 *)a0;
    u8 *spans = (u8 *)a2;
    u8 *dst_end;
    u8 *end;
    u8 *cursor;
    u8 *next_dst;
    u8 *next;
    u8 *wrapped;
    u8 *r;
    u8 *w;
    u8 *from;
    u8 *to;
    s32 count;
    s32 n;
    s32 bit;

    dst_end = dst + 0x8000;
    end = (u8 *)0x70002000;
    count = *ctrl >> 1;
    ctrl++;
    func_0038CB78((void *)0x70000000, 0, 0x2400);
    bit = 1;
    cursor = (u8 *)0x70000000;
    for (;;) {
        next_dst = dst + 0x400;
        do {
            cursor += *spans++;
            n = *spans++;
            if (n != 0) {
                do {
                    n--;
                    next = cursor + 1;
                    if (count == 0) {
                        do {
                            count = *ctrl++;
                            bit = !bit;
                        } while (count == 0);
                    }
                    *cursor = bit;
                    count--;
                    cursor = next;
                } while (n != 0);
            }
        } while (cursor < end);
        r = (u8 *)0x70000000;
        w = (u8 *)0x70000000;
        do {
            *w = *r++;
            *w |= *r++ << 1;
            *w |= *r++ << 2;
            *w |= *r++ << 3;
            *w |= *r++ << 4;
            *w |= *r++ << 5;
            *w |= *r++ << 6;
            *w |= *r++ << 7;
            w++;
        } while (r < end);
        func_0038CD28(dst, (u32 *)0x70000000, 0x400);
        dst = next_dst;
        if (next_dst == dst_end) {
            return;
        }
        func_0038CB78((void *)0x70000000, 0, 0x2000);
        wrapped = cursor - 0x2000;
        from = (u8 *)0x70002000;
        to = (u8 *)0x70000000;
        if (cursor > end) {
            do {
                *to++ = *from++;
            } while (from < cursor);
        }
        func_0038CB78((void *)0x70002000, 0, 0x400);
        cursor = wrapped;
    }
}
/* localdecomp:end func_L01_00430AF8 */

/* localdecomp:start func_L01_00430D28 */
extern void func_0038CD28(u8 *, u32 *, s32);

void func_L01_00430D28(u8 *dst, u8 *src) {
    u32 table[256];
    u32 buf[16];
    s32 k;
    s32 i;
    s32 j;

    for (i = 0; i < 256; i++) {
        table[i] = 0;
        if (i & 1) table[i] = 0xF;
        if (i & 2) table[i] |= 0xF0;
        if (i & 4) table[i] |= 0xF00;
        if (i & 8) table[i] |= 0xF000;
        if (i & 0x10) table[i] |= 0xF0000;
        if (i & 0x20) table[i] |= 0xF00000;
        if (i & 0x40) table[i] |= 0xF000000;
        if (i & 0x80) table[i] |= 0xF0000000;
    }
    for (k = 0; k < 128; k++) {
        u32 *q = buf;
        for (j = 0; j < 16; j++) {
            *q++ = table[*src++];
        }
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
        func_0038CD28(dst, buf, 64);
        dst += 64;
    }
}
/* localdecomp:end func_L01_00430D28 */

LINKER_REMNANT("asm/levels", func_L01_00430EF8);
