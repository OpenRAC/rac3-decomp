#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations of 13AFF8.c's earlier functions */
extern void func_0011F0A0(s32);
extern s32 D_001D4E18;
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern s32 D_1D4A00;
extern void func_0011AF48();
extern s32 *D_001D4DA0;
extern s32 func_0013B818(void);
extern void func_11F0A0(s32);
extern s32 func_0013CDF0(s32);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B808);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B810);

/* PAL candidate for func_0013B818 (boot_elf, src/boot_elf/core/13ADA8.c).
   Retail builds the address of D_1D4900 with lui/addiu (one macro, adjacent,
   same register), while the sized alias D_1D4900_0013B818 (s32[2]) would be
   reached through $gp.  The per-function alias plus a size hint over 8 keeps
   retail's lui/addiu under the file's own flags (no @ps2as), and the single
   macro also keeps gcc from splitting the pair over two delay slots, which is
   what made it emit bnel instead of retail's beqz. */

/* localdecomp:start func_0013B818 */
__asm__(".extern D_001D4DA0, 4");
__asm__(".extern D_001D4DA4, 4");
__asm__(".extern D_001D4E18, 4");
/* the size hint over 8 keeps the assembler from making this small data:
   retail builds the address with lui/addiu (one macro), not with $gp */
__asm__(".extern D_1D4900_0013B818_l, 16");
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern s32 D_001D4E18;
extern s32 D_1D4900_0013B818_l[2];
extern char D_00152290[];
extern void func_0011F0A0(s32);
extern s32 func_00122A10(void *);
extern s32 func_0011AF48_0013B818(const char *, ...);
s32 func_0013B818(void) {
    s32 *p;
    func_0011F0A0(0);
    if (D_001D4DA0 == 0) return 1;
    if (func_00122A10(D_1D4900_0013B818_l) != 0) return 0;
    p = D_001D4DA0;
    if ((u32)p[0] == 0xFFFFFFFF && p[D_001D4DA4 + 1] == p[0]) {
        D_001D4DA0 = 0;
        return 1;
    }
    if (D_001D4E18 == 0) func_0011AF48_0013B818(D_00152290);
    return 0;
}
/* localdecomp:end func_0013B818 */

/* localdecomp:start func_0013B8B0 */
extern s32 D_001D4DA4;
extern s32 *D_001D4DA0;
extern void func_0011F698(void *, void *);
void func_0013B8B0(s32 *p, s32 n) {
    D_001D4DA4 = n;
    D_001D4DA0 = p;
    p[n + 1] = 0;
    p[0] = 0;
    func_0011F698(p, (u8 *)p + 3);
    p = &p[n + 1];
    func_0011F698(p, (u8 *)p + 3);
}
/* localdecomp:end func_0013B8B0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013B910);

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
/* localdecomp:start func_0013B918 */
__asm__(".extern D_1D4A00_l, 16");
__asm__(".extern D_1D4A04_l, 16");
__asm__(".extern D_1D4A40_l, 16");
__asm__(".extern D_1D49C0_0013BAB8, 16");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A40;
extern s32 D_1D4A44;
extern u32 D_1D4A00_g;
extern u32 D_1D4A00_l[2];
extern s32 D_1D4A04_l[2];
extern s32 D_1D4A40_l[2];
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
s32 func_0013B918(s32 a, s32 b) {
    u32 busy;
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F20);
        return 0;
    }
    if (func_0013CDF0(1) == 1) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F50);
        return 0;
    }
    D_1D4A00_l[0] = -1u;
    func_0011F698(D_1D4A00_l, D_1D4A04_l);
    D_1D4A40_l[0] = a;
    D_1D4A40_l[1] = b;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4E98);
        func_0013B620();
        func_11F0A0(0);
    }
    if (func_00122810(D_1D49C0_0013BAB8, 3, 1, D_1D4A40_l, 8, D_1D4A00_l, 4, 0, 0) < 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F70);
        D_001D4DA8 = 0x106;
        return 0;
    }
    if (D_1D4A00 != -1u)
        return D_1D4A00_g;
    busy = -1u;
    for (;;) {
        func_11F0A0(0);
        if (D_1D4A00_l[0] != busy)
            return D_1D4A00_l[0];
    }
}
/* localdecomp:end func_0013B918 */

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_001D4DF0;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern s32 D_1D4A44;
extern u8 D_1D49C0_0013BAB8[8];
extern char D_001D4F20[];
extern char D_001D4F50[];
extern char D_001D4F70[];
extern char D_001D4E98[];
extern void func_0011AF48_0013BAB8(char *);
extern s32 func_0013CDF0(s32);
extern void func_0011F698(void *, void *);
extern s32 func_00122A10(void *);
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_11F0A0(s32);
/* localdecomp:start func_0013BAB8 */
__asm__(".extern D_1D4A00_0013BAB8, 16");
__asm__(".extern D_1D4A04_0013BAB8, 16");
__asm__(".extern D_1D4A40_0013BAB8, 16");
__asm__(".extern D_1D4A44_0013BAB8, 16");
__asm__(".extern D_001D4DF0_0013BAB8, 16");
extern u32 D_1D4A00_0013BAB8;
extern s32 D_1D4A04_0013BAB8;
extern s32 D_1D4A40_0013BAB8;
extern s32 D_1D4A44_0013BAB8;
extern long D_001D4DF0_0013BAB8[1];
void func_0013BAB8(s32 a, s32 b, void (*cb)(s32, long), long arg) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F20);
        return;
    }
    if (func_0013CDF0(1) == 1) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4F50);
        return;
    }
    D_1D4A00_0013BAB8 = -1u;
    func_0011F698(&D_1D4A00_0013BAB8, &D_1D4A04_0013BAB8);
    D_1D4A40_0013BAB8 = a;
    D_1D4A44_0013BAB8 = b;
    D_001D4DF0 = (s32)cb;
    D_001D4DF0_0013BAB8[1] = arg;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48_0013BAB8(D_001D4E98);
        func_0013B620();
        func_11F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(D_1D49C0_0013BAB8, 3, 1, &D_1D4A40_0013BAB8, 8, &D_1D4A00_0013BAB8, 4, 0, 0);
}
/* localdecomp:end func_0013BAB8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BC28);

extern s32 D_001D4DA8;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5018[];
extern void func_0011F698(void *, void *);
extern char D_001D4E98[];
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
/* localdecomp:start func_0013BC30 */
/* func_0013BC30: D_001D4DF0 is the callback slot {fn, pad, long arg} (the layout of E_13B620).  The arg
 store goes through a per-function struct alias in .sdata: gcc sees D_001D4DF0_0013BC30+8 (a CONST,
 address of a small-data symbol), so it neither splits it nor counts it one insn long, and reorg leaves
 the loop-entry b + nop as retail (a plain long scalar was put in the delay slot). */
__asm__(".extern D_1D4A00_l, 16");
__asm__(".extern D_1D4A04_l, 16");
__asm__(".extern D_1D4A40_l, 16");
__asm__(".extern D_1D49C0_0013BAB8, 16");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_001D4DF0;
extern u32 D_1D4A00_l[2];
extern s32 D_1D4A04_l[2];
extern s32 D_1D4A40_l[2];
extern u8 D_1D49C0_0013BAB8[8];
typedef struct { s32 fn; s32 pad; long arg; } E_0013BC30;
extern E_0013BC30 D_001D4DF0_0013BC30 __attribute__((section(".sdata")));
extern char D_001D5018[];
extern char D_001D4E98[];
extern void func_0011AF48();
extern void func_0011F698(void *, void *);
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
void func_0013BC30(s32 a, void *b, unsigned long c) {
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5018);
        return;
    }
    D_1D4A00_l[0] = -1u;
    func_0011F698(D_1D4A00_l, D_1D4A04_l);
    D_1D4A40_l[0] = a;
    D_001D4DF0 = (s32)b;
    D_001D4DF0_0013BC30.arg = c;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    D_001D4DE8 = 1;
    func_00122810(D_1D49C0_0013BAB8, 0x57, 1, D_1D4A40_l, 4, D_1D4A00_l, 4, 0, 0);
}
/* localdecomp:end func_0013BC30 */

extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A04;
extern s32 D_1D4A40;
extern char D_001D5050[];
extern char D_001D5080[];
extern char D_001D4E98[];
extern void func_0011AF48();
extern void func_0011F698(void *, void *);
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
/* localdecomp:start func_0013BD58 */
__asm__(".extern D_1D4A00_l, 16");
__asm__(".extern D_1D4A04_l, 16");
__asm__(".extern D_1D4A40_l, 16");
__asm__(".extern D_1D49C0_0013BAB8, 16");
extern s32 D_001D4DA8;
extern s32 D_001D4DE8;
extern s32 D_001D4E18;
extern s32 D_1D4A00;
extern s32 D_1D4A40;
extern u32 D_1D4A00_g;
extern u32 D_1D4A00_l[2];
extern s32 D_1D4A04_l[2];
extern s32 D_1D4A40_l[2];
extern char D_001D5050[];
extern char D_001D5080[];
extern char D_001D4E98[];
extern void func_0011AF48();
extern void func_0011F698(void *, void *);
extern s32 func_00122A10();
extern s32 func_00122810();
extern s32 func_0013B620(void);
extern void func_0011F0A0(s32);
s32 func_0013BD58(s32 a) {
    u32 reply;
    u32 busy;
    D_001D4DA8 = 0;
    if (D_001D4DE8 != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5050);
        return 0;
    }
    D_1D4A00_l[0] = -1u;
    func_0011F698(D_1D4A00_l, D_1D4A04_l);
    D_1D4A40 = a;
    while (func_00122A10(D_1D49C0_0013BAB8) != 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D4E98);
        func_0013B620();
        func_0011F0A0(0);
    }
    if (func_00122810(D_1D49C0_0013BAB8, 0x59, 1, D_1D4A40_l, 4, D_1D4A00_l, 4, 0, 0) < 0) {
        if (D_001D4E18 == 0) func_0011AF48(D_001D5080);
        D_001D4DA8 = 0x106;
        return 0;
    }
    if (D_1D4A00 != -1u)
        return D_1D4A00_g;
    busy = -1u;
    for (;;) {
        func_0011F0A0(0);
        reply = D_1D4A00_l[0];
        if (reply != busy)
            return reply;
    }
}
/* localdecomp:end func_0013BD58 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEB0);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013BEC8);

/* localdecomp:start func_0013BED0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BED0(void) {
    return func_0013C578(0x8, 0, 0, 0, 0);
}
/* localdecomp:end func_0013BED0 */

/* localdecomp:start func_0013BF00 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF00(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x6, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BF00 */

/* localdecomp:start func_0013BF30 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF30(s32 a, s32 b) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    return func_0013C578(0x9, 8, buf, 0, 0);
}
/* localdecomp:end func_0013BF30 */

/* localdecomp:start func_0013BF68 */
typedef struct { u8 b[0x18]; } V_13BF68;
typedef struct { s32 a; V_13BF68 v; } B_13BF68;
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BF68(s32 a, V_13BF68 *p) {
    B_13BF68 buf;
    buf.a = a;
    if (p != 0) {
        buf.v = *p;
    } else {
        *(s32 *)&buf.v = -1;
    }
    return func_0013C578(0x60, 0x1C, &buf, 0, 0);
}
/* localdecomp:end func_0013BF68 */

/* localdecomp:start func_0013BFE0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013BFE0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0xB, 4, buf, 0, 0);
}
/* localdecomp:end func_0013BFE0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C010);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C020);

/* localdecomp:start func_0013C028 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C028(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x4E, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C028 */

/* localdecomp:start func_0013C068 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C068(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x64, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C068 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C098);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C0B0);

/* localdecomp:start func_0013C0B8 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C0B8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x11, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C0B8 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C100);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C110);

/* localdecomp:start func_0013C118 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C118(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x15, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C118 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C148);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C168);

/* localdecomp:start func_0013C170 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C170(void) {
    return func_0013C578(0x18, 0, 0, 0, 0);
}
/* localdecomp:end func_0013C170 */

/* localdecomp:start func_0013C1A0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1A0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x16, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1A0 */

/* localdecomp:start func_0013C1D0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C1D0(s32 a) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x17, 4, buf, 0, 0);
}
/* localdecomp:end func_0013C1D0 */

/* localdecomp:start func_0013C200 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C200(s32 a, s32 b, long c) {
    s32 buf[4];
    buf[0] = a;
    return func_0013C578(0x19, 4, buf, b, c);
}
/* localdecomp:end func_0013C200 */

/* localdecomp:start func_0013C230 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C230(s32 a, s32 b, s32 c) {
    s32 buf[4];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    return func_0013C578(0x1B, 0xC, buf, 0, 0);
}
/* localdecomp:end func_0013C230 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C270);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C298);

/* localdecomp:start func_0013C2A0 */
extern s32 func_0013C2C0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0013C2A0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    return func_0013C2C0(a, b, c, d, e, f, 0, 0);
}
/* localdecomp:end func_0013C2A0 */

/* localdecomp:start func_0013C2C0 */
extern s32 func_0013C578(s32, s32, void *, s32, long);
s32 func_0013C2C0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h) {
    s32 buf[6];
    buf[0] = a;
    buf[1] = b;
    buf[2] = c;
    buf[3] = d;
    buf[4] = e;
    buf[5] = f;
    return func_0013C578(0x21, 0x18, buf, g, h);
}
/* localdecomp:end func_0013C2C0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C308);

LINKER_REMNANT("asm/boot_elf/remnants", func_0013C340);
