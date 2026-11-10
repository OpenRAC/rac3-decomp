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

/* localdecomp:start func_L39_0067AB38 */
__asm__(".extern D_L39_0024D0C0, 16");
__asm__(".extern D_L39_0024D0F4, 16");
extern s32 D_L39_0024D0C0;
extern s32 D_L39_0024D0F4;
extern s32 D_001E19B0_sda;
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_L39_004B3B18(void);
extern void func_L01_004126A8(s32);
extern void func_L39_006121B0(s32);
extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern void func_L39_00681470(void);
extern void func_L39_005C1A60(s32, s32, s32);

void func_L39_0067AB38(void) {
    s32 v;

    if (D_L39_0024D0C0 > 0) {
        func_L39_004B3B18();
    }
    v = func_00126150();
    func_L01_004126A8(v);
    func_001260F0(v, D_L39_0024D0F4);
    D_001E19B0_sda = 0;
    func_L39_006121B0(1);
    func_L39_005DBEE8(func_003B43B0(1), 0, 0);
    func_L39_00681470();
    func_L39_005C1A60(0, 0, 0x400);
}
/* localdecomp:end func_L39_0067AB38 */

INCLUDE_ASM("asm/levels", func_L39_0067ABC8);
