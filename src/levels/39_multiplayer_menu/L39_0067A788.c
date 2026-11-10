#include "common.h"

typedef struct { int a, b, c; } T;

/* localdecomp:start func_L39_0067A788 */
extern void func_L39_00595628(u8 *, u8 *);

void func_L39_0067A788(u8 *arg0) {
    u8 buf[0x200];
    u8 *d = buf;
    u8 *s = arg0;
    while (*s != 0) {
        *d++ = 0;
        *d++ = *s++;
    }
    *d++ = 0;
    *d++ = 0;
    func_L39_00595628(buf, arg0);
}
/* localdecomp:end func_L39_0067A788 */

/* localdecomp:start func_L39_0067A7E0 */
typedef struct S_0067A7E0 {
    u8 pad[0x10];
    s32 ***f10;
} S_0067A7E0;

extern u8 D_001A5E72[];
s32 func_L01_003EC898(s32);
S_0067A7E0 *func_L01_004127C0(u8 *);
s32 func_L01_00412810(s32);
void func_L01_004126A8(s32);
s32 func_001206F4(void *, s32);
void func_001260A0(void);

void func_L39_0067A7E0(void) {
    S_0067A7E0 *e;
    u8 *base;

    func_L01_003EC898(0);
    base = D_001A5E72;
    e = func_L01_004127C0(base);
    if (e != 0) {
        func_001206F4(base - 0x20, func_L01_00412810(**e->f10));
        func_001206F4(base + 0x100, (s32)(base - 0x20));
    }
    e = func_L01_004127C0(base + 0xC0);
    if (e != 0) {
        func_001206F4(base + 0xA0, func_L01_00412810(**e->f10));
    }
    func_L01_004126A8(0);
    func_001260A0();
}
/* localdecomp:end func_L39_0067A7E0 */

INCLUDE_ASM("asm/levels", func_L39_0067A888);

INCLUDE_ASM("asm/levels", func_L39_0067AB38);

INCLUDE_ASM("asm/levels", func_L39_0067ABC8);
