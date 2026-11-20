#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* localdecomp:start func_0013CC10 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC10(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2D, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC10 */

/* localdecomp:start func_0013CC40 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC40(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x2E, 4, buf, 0, 0);
}
/* localdecomp:end func_0013CC40 */

/* localdecomp:start func_0013CC70 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CC70(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x30, 4, buf, b, c);
}
/* localdecomp:end func_0013CC70 */

/* localdecomp:start func_0013CCA0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CCA0(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x32, 4, buf, b, c);
}
/* localdecomp:end func_0013CCA0 */

/* localdecomp:start func_0013CCD0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CCD0(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x4F, 4, buf, b, c);
}
/* localdecomp:end func_0013CCD0 */

/* localdecomp:start func_0013CD00 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013CD00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C348(0x36, 4, buf);
}
/* localdecomp:end func_0013CD00 */

extern s32 D_001D4DAC;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
extern s32 D_1D4980;
extern s32 D_1D4990_0013CD28;
extern u8 D_1D49BF;
extern s32 func_0012BA20(void);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_0013C578();
/* localdecomp:start func_0013CD28 */
/* Ported from rac2-decomp/src/core/001334B8-g8.c (CdStartRead). */
extern s32 D_001D4DAC;
extern s32 D_001D4DB4;
extern s32 D_001D4DB8;
/* Sound-server read status, updated through the IOP transfer and polled by func_0013CDF0. */
extern volatile s32 D_1D4980_0013CD28;
extern volatile s32 D_001D4990_0013CD28;
extern u8 D_1D49BF;
__asm__(".extern D_1D4980_0013CD28, 16");
__asm__(".extern D_001D4990_0013CD28, 16");
__asm__(".extern D_1D49BF, 16");
int func_0013CD28(int lba, int sectors, void *buf, unsigned char *mode) {
    extern s32 func_0012BA20(void);
    extern s32 func_0013CDF0(s32);
    extern void func_0011F698(void *, void *);
    extern s32 func_0013C578(s32, s32, void *, s32, long);
    int payload[4];

    if (D_001D4DAC == 0) {
        /* Preserve the owning file's no-argument declaration of the SDK entry. */
        return ((s32 (*)(s32, s32, void *, u8 *))func_0012BA20)(lba, sectors, buf, mode);
    }
    if (func_0013CDF0(1) == 1) {
        return 0;
    }
    D_1D4980_0013CD28 = 1;
    D_001D4990_0013CD28 = 0;
    func_0011F698((void *)&D_1D4980_0013CD28, &D_1D49BF);
    payload[0] = lba;
    payload[1] = sectors;
    payload[2] = (int)buf;
    D_001D4DB4 = 1;
    D_001D4DB8 = 0;
    func_0013C578(0x38, 0xC, payload, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CD28 */

extern s32 D_001D4DAC;
extern s32 D_001D4DB8;
extern s32 D_1D4980;
extern u8 D_1D49BF;
extern s32 func_0012B098();
extern void func_0011F7C8(void *, void *);
extern s32 func_0013B620(void);
/* localdecomp:start func_0013CDF0 */
extern s32 D_001D4DAC;
extern s32 D_001D4DB8;
extern s32 D_1D4980 __attribute__((section(".data")));
extern u8 D_1D49BF __attribute__((section(".data")));

int func_0013CDF0(int wait_mode) {
    extern s32 func_0012B098();
    extern void func_0011F7C8(void *, void *);
    extern s32 func_0013B620(void);
    u8 *status_end;
    s32 not_ready;

    if (D_001D4DAC == 0)
        return func_0012B098(wait_mode);

    status_end = &D_1D49BF;
    func_0011F7C8(&D_1D4980, status_end);
    not_ready = (u32)D_1D4980 < 1;
    D_001D4DB8 = not_ready;
    if (not_ready == 1)
        return 0;
    if (wait_mode == 1)
        return 1;
    while (D_001D4DB8 == 0) {
        func_0013B620();
        func_0011F7C8(&D_1D4980, status_end);
        not_ready = (u32)D_1D4980 < 1;
        D_001D4DB8 = not_ready;
    }
    return 0;
}
/* localdecomp:end func_0013CDF0 */

/* localdecomp:start func_0013CEB0 */
extern s32 D_001D4DAC;
extern s32 func_0013C578(s32, s32, void *, s32, long);
extern s32 func_0012BC98(void);
s32 func_0013CEB0(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC98();
    }
    func_0013C578(0x37, 0, 0, 0, 0);
    return 1;
}
/* localdecomp:end func_0013CEB0 */

/* PAL candidate for func_0013CEF8 (boot_elf, src/boot_elf/core/13C8D0.c).
   Retail reaches D_1D4990 with one lui/lw pair in one register; the plain
   name is an unsized array, which gcc splits over two registers and lets it
   fall into a branch delay slot.  A constant address keeps gcc's pair
   together (one register, one dependency), as retail has it. */

/* localdecomp:start func_0013CEF8 */
extern s32 D_1D4990[];
extern s32 D_001D4DAC;
extern s32 func_0012BC00(void);
s32 func_0013CEF8(void) {
    if (D_001D4DAC == 0) {
        return func_0012BC00();
    }
    return *(s32 *)0x1D4990;
}
/* localdecomp:end func_0013CEF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF30);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF38);

/* localdecomp:start func_0013CF40 */
extern s32 D_001D4DAC;
extern s32 D_001D4DB0;
extern s32 func_0012AA78(s32);
s32 func_0013CF40(s32 a) {
    s32 old;
    if (D_001D4DAC == 0) {
        return func_0012AA78(a);
    }
    old = D_001D4DB0;
    D_001D4DB0 = a;
    return old;
}
/* localdecomp:end func_0013CF40 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF70);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013CF78);

/* localdecomp:start func_0013CF80 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CF80(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C578(0x50, 0x14, buf, 0, 0);
}
/* localdecomp:end func_0013CF80 */

/* localdecomp:start func_0013CFC0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CFC0(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x51, 8, buf, 0, 0);
}
/* localdecomp:end func_0013CFC0 */

/* localdecomp:start func_0013CFF8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013CFF8(s32 a, s32 b, s32 c, s32 d) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    return func_0013C578(0x10, 0x10, buf, 0, 0);
}
/* localdecomp:end func_0013CFF8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D038);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D078);

/* localdecomp:start func_0013D080 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D080(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C348(0x3B, 0x18, buf);
}
/* localdecomp:end func_0013D080 */

/* localdecomp:start func_0013D0C0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0C0(void) {
    return func_0013C348(0x3D, 0, 0);
}
/* localdecomp:end func_0013D0C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0E8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D0F0);

/* localdecomp:start func_0013D0F8 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D0F8(void) {
    return func_0013C348(0x3C, 0, 0);
}
/* localdecomp:end func_0013D0F8 */

/* localdecomp:start func_0013D120 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D120(s32 a, s32 b, s32 c, s32 d, s32 e) {
    s32 buf[5];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    return func_0013C348(0x3E, 0x14, buf);
}
/* localdecomp:end func_0013D120 */

/* localdecomp:start func_0013D158 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D158(void) {
    return func_0013C348(0x40, 0, 0);
}
/* localdecomp:end func_0013D158 */

/* localdecomp:start func_0013D180 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D180(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C348(0x5A, 8, buf);
}
/* localdecomp:end func_0013D180 */

/* localdecomp:start func_0013D1B0 */
extern s32 func_0013C348(s32, s32, void *);
s32 func_0013D1B0(void) {
    return func_0013C348(0x5B, 0, 0);
}
/* localdecomp:end func_0013D1B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1D8);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D1E0);

/* localdecomp:start func_0013D1E8 */
s32 func_0013D1E8(s32 a) {
    return a * 0x5F4 / 0x2E5;
}
/* localdecomp:end func_0013D1E8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0013D208);

/* localdecomp:start func_0013D258 */
void func_0013D258(u8 *d, u8 *s, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        d[i] = s[i];
    }
}
/* localdecomp:end func_0013D258 */

extern u8 D_001D52E0[];
extern s32 func_0013CD28(s32, s32, void *, u8 *);
extern s32 func_0013B620(void);
extern s32 func_0013CDF0(s32);
/* localdecomp:start func_0013D290 */
extern u8 D_001D52E0_0013D290;
__asm__(".extern D_001D52E0_0013D290, 16");
s32 func_0013D290(s32 lba, s32 sectors, void *buf) {
    u8 mode[4];
    mode[0] = 0x20;
    mode[1] = D_001D52E0_0013D290;
    mode[2] = 0;
    mode[3] = 0;
    func_0013CD28(lba, sectors, buf, mode);
    func_0013CA28();
    func_0013B620();
    return func_0013CDF0(0);
}
/* localdecomp:end func_0013D290 */

/* localdecomp:start func_0013D2E0 */
extern s32 func_0013D290(s32, s32, void *);
extern u8 D_160C40[];
s32 func_0013D2E0(void) {
    return func_0013D290(0x3E9, 0x10, D_160C40);
}
/* localdecomp:end func_0013D2E0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013D308);

typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; } E_13D310;
typedef struct { u8 p0[0x7400]; E_13D310 e[(0x79A0 - 0x7400) / 0x18]; u8 a79A0[0x60]; u8 a7A00[0x1818]; } S_13D310;
extern S_13D310 D_160C40_0013D310;
extern void func_0013D258(u8 *, u8 *, s32);
extern u8 D_169E58[];
/* localdecomp:start func_0013D310 */
void func_0013D310(s32 idx, void *buf) {
    func_0013D290(D_160C40_0013D310.e[idx].f8, 1, buf);
    func_0013D258(D_160C40_0013D310.a79A0, buf, 0x60);
    func_0013D290(D_160C40_0013D310.e[idx].f0, 4, buf);
    func_0013D258(D_160C40_0013D310.a7A00, buf, 0x1818);
    func_0013D290(D_160C40_0013D310.e[idx].f10, 5, buf);
    func_0013D258(D_169E58, buf, 0x26F0);
}
/* localdecomp:end func_0013D310 */

/* localdecomp:start func_0013D3C0 */
extern s32 D_001D5458;
void func_0013D3C0(s32 a) {
    D_001D5458 = a;
}
/* localdecomp:end func_0013D3C0 */

/* localdecomp:start func_0013D3C8 */
extern s32 D_001D5458;
s32 func_0013D3C8(void) {
    return D_001D5458;
}
/* localdecomp:end func_0013D3C8 */

ASM_FUNC("asm/boot_elf/handwritten", func_0013D3D0);

ASM_FUNC("asm/boot_elf/handwritten", func_0013D3E0);
