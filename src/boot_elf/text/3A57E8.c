#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_003A5830(void);
/* --- end of declarations from other files --- */

/* localdecomp:start func_003A57E8 */
extern u8 D_001A30B0[];
s32 func_003A57E8(u32 a0, s32 a1) {
    if (a0 < 0x34) {
        u8 *p = (u8 *)&D_001A30B0[0] + a0 * 0x80;
        *(u16 *)(p + 0xcc) = a1;
    }
    return 1;
}
/* localdecomp:end func_003A57E8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5810);

/* localdecomp:start func_003A5830 */
/* sq $zero has no C form (the compiler always emits por+sq from a zero); this is the inline-asm macro the original used */
#define QZERO(p) __asm__ __volatile__("sq $0,0x0(%0)" : : "r"(p))
extern s32 D_001D6E1C;
extern u8 D_1A3100[];
extern void func_13CA28(void);
extern s32 func_13B620(void);
extern void func_13C170(void);
extern s32 func_12C908(s32);
extern void func_003A5A20(void);
void func_003A5830(void) {
    s32 c;
    s32 i;
    u8 *p;
    func_13CA28();
    func_13B620();
    func_13C170();
    D_001D6E1C = 0xB4;
    while (func_13B620() != 0) {
        func_12C908(0);
        c = D_001D6E1C;
        if (c == 0) break;
        D_001D6E1C = c - 1;
    }
    for (i = 3; i >= 0; i--) {
        QZERO(D_1A3100 + i * 0x10);
    }
    p = D_001A30B0;
    *(s32 *)(p + 0x48) = 0;
    for (i = 0x33; i >= 0; i--) {
        *(s32 *)(p + 0xC0) = 0;
        *(u8 *)(p + 0xD0) = 0;
        p += 0x80;
    }
    func_003A5A20();
}
/* localdecomp:end func_003A5830 */

/* localdecomp:start func_003A58F0 */
void func_003A58F0(s32 a0, long a1) {
    s32 *p = (s32 *)(u32)a1;
    if (p != 0) {
        *p = a0;
    }
}
/* localdecomp:end func_003A58F0 */

/* localdecomp:start func_003A5908 */
void func_003A5908(s32 a0, long a1) {
    u8 *p = (u8 *)(s32)a1;
    if (p != 0) {
        *(s32 *)p = a0;
        if (a0 != 0) {
            if (p[0x10] == 1) {
                p[0x10] = 2;
            }
        } else {
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x40) = 0;
    p[0x10] = 0;
        }
    }
}
/* localdecomp:end func_003A5908 */

/* localdecomp:start func_003A5950 */
void func_003A5950(s32 a, long l) {
    u8 *p = (u8 *)(u32)l;
    if (p == 0) return;
    if (p[0x13] != *(s32 *)(p + 0x4C)) return;
    *(s32 *)p = a;
    if (a == 0) {
        *(s32 *)(p + 0x1C) = 0;
        *(s32 *)(p + 0x40) = 0;
        p[0x10] = 0;
    }
    p[0x13] = 0;
}
/* localdecomp:end func_003A5950 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5990);

/* localdecomp:start func_003A5998 */
void func_003A5998(u8 *p, s32 i, s32 *v) {
    switch (i) {
    case 3:
        *(s32 *)(p + 0xC) = *v;
        break;
    case 0:
        *(u128_t *)(p + 0x40) = *(u128_t *)v;
        break;
    case 1:
        *(u128_t *)(p + 0x50) = *(u128_t *)v;
        break;
    case 2:
        *(f32 *)(p + 8) = *(f32 *)v;
        break;
    case 4:
        *(s32 *)(p + 0x10) = *v;
        break;
    case 5:
        *(s32 **)(p + 0x14) = v;
        break;
    case 6:
        *(s32 *)(p + 0x18) = *v;
        break;
    }
}
/* localdecomp:end func_003A5998 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5A18);

/* localdecomp:start func_003A5A20 */
typedef struct { u8 x0; s8 x1; s8 x2; s8 x3; u16 x4; u16 x6; s32 x8; s32 xC; u32 x10; s32 x14; s32 x18; u8 pad[0x60-0x1C]; } S_3A0200;
extern S_3A0200 D_0022D430[];
void func_003A5A20(void) {
    s32 i;
    for (i = 0; i < 12; i++) {
        S_3A0200 *p = &D_0022D430[i];
        p->x0 = 0;
        p->x1 = -1;
        p->x2 = -1;
        p->x3 = -1;
        p->xC = 0;
        p->x8 = 0;
        p->x4 = 0xFFFF;
        p->x10 = 0xFFFFFFFF;
        p->x14 = 0;
        p->x18 = -1;
    }
}
/* localdecomp:end func_003A5A20 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003A5A88);

/* localdecomp:start func_003A5AA0 */
extern s32 D_0022D8B0[];
extern void func_003C2C38(s32 p);
void func_003A5AA0(void) {
    s32 *p = D_0022D8B0;
    s32 i;
    for (i = 19; i >= 0; i--) {
        if (*p) func_003C2C38(*p);
        *p = 0;
        p++;
    }
}
/* localdecomp:end func_003A5AA0 */

typedef struct O2_3A02D8 { u8 pad[8]; void *f8; } O2_3A02D8;
typedef struct { u8 pad[0x30]; u8 f30; u8 pad31; s16 f32; u16 f34; u8 pad36[0x63 - 0x36]; u8 f63; u8 pad64[4]; O2_3A02D8 *f68; } O_3A02D8;
typedef struct { O_3A02D8 *f0; u8 pad[0x40]; } S_16C580_3A02D8;
extern S_16C580_3A02D8 D_0016C580_003A5AF8;
extern u32 D_001D54D0;
extern s16 D_001D5BB0[4];
extern s16 D_001D5BB6;
extern s16 D_001D5BB8;
extern s16 D_001D5BBA;
extern s16 D_001D5BBC;
extern O_3A02D8 *func_003C2868_003A5AF8(s32, s32);
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A5AF8);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003A5CC0);

LINKER_REMNANT("asm/boot_elf/remnants", func_003A6540);
